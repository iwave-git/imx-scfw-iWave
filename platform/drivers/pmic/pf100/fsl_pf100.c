/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017-2020 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "fsl_device_registers.h"
#include "drivers/pmic/fsl_pmic.h"
#include "drivers/lpi2c/fsl_lpi2c.h"
#include "drivers/pmic/pf100/fsl_pf100.h"
#include "fsl_common.h"

/* Local Defines */
#define VGEN_EN              0x10U /*!< Voltage Generator enable mask */
#define SW_VOLT_MASK         0x3FU /*!< Switching regulator voltage mask */
#define VGEN_VOLT_MASK       0xFU  /*!< LDO regulator voltage mask */
#define SW_BIT6_MASK         0x40U /*!< Voltage Range selection bit mask */
#define SW_MODE_MASK         0xFU
#define VGEN_MODE_MASK       (0x7U << 4U)

/* Defines */

/*!
 * @name Defines for pf100_ctl_regs_t
 */
/** @{ */
#define     DEVICEID        0x00U
#define     SILICONREVID    0x03U
#define     FABID           0x04U
#define     INTSTAT0        0x05U
#define     INTMASK0        0x06U
#define     INTSENSE0       0x07U
#define     INTSTAT1        0x08U
#define     INTMASK1        0x09U
#define     INTSENSE1       0x0AU
#define     INTSTAT3        0x0EU
#define     INTMASK3        0x0FU
#define     INTSENSE3       0x10U
#define     INTSTAT4        0x11U
#define     INTMASK4        0x12U
#define     INTSENSE4       0x13U
#define     COINCTL         0x1AU
#define     PWRCTL          0x1BU
#define     MEMA            0x1CU
#define     MEMB            0x1DU
#define     MEMC            0x1EU
#define     MEMD            0x1FU
/** @} */

/*!
 * @name Defines for pmic_ints_t
 */
/** @{ */
#define     THERM110    BIT8(2U)
#define     THERM120    BIT8(3U)
#define     THERM125    BIT8(4U)
#define     THERM130    BIT8(5U)
/** @} */


/* Types */
/*!
 * This type is used to offset from a register
 */
typedef uint8_t pf100_ctl_regs_t;

/*!
 * This type is used to encode the temperature
 */
typedef uint8_t pmic_ints_t;

/* Local Functions */

/* Local Variables */

struct sw_range
{
    uint32_t sw2;       /* 0 = un-initialized */
    uint32_t sw3a;      /* 1 = low voltage range */
    uint32_t sw3b;      /* 2 = high voltage range */
    uint32_t sw4;
};

static struct sw_range switching_range = {0U, 0U, 0U, 0U};

/*--------------------------------------------------------------------------*/
/* Get PMIC version                                                         */
/*--------------------------------------------------------------------------*/
pmic_version_t pf100_get_pmic_version(pmic_id_t id)
{
    pmic_version_t ver;

    if (kStatus_Success != i2c_read(id, DEVICEID, &ver.device_id, 1U))
    {
        ver.device_id = 0U;
    }
    if (kStatus_Success != i2c_read(id, SILICONREVID, &ver.si_rev, 1U))
    {
        ver.si_rev = 0U;
    }

    ver.device_id &= 0x1FU;
    ver.si_rev &= 0xFFU;

    return ver;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC Regulator Voltage                                               */
/*--------------------------------------------------------------------------*/
sc_err_t pf100_pmic_set_voltage(pmic_id_t id, uint32_t pmic_reg,
    uint32_t vol_mv, uint32_t mode_to_set)
{
    status_t err;
    uint32_t mode_offset = 0U;
    uint32_t new_volt = 0U;
    uint8_t  val = 0U;
    uint32_t volt_mask = SW_VOLT_MASK;
    uint8_t pmic_reg8;

    if (pmic_reg >= 0x100U)
    {
        return SC_ERR_PARM;
    }
    else
    {
        pmic_reg8 = U8(pmic_reg);
    }

    switch (mode_to_set)
    {
        case SW_STBY_MODE:
            mode_offset = 1U;
            break;
        case SW_OFF_MODE:
            mode_offset = 2U;
            break;
        default:/* if not stby or off assume run mode */
            ; /* Intentional empty default */
            break;
    }

    /* Calculate step voltage */
    switch (pmic_reg8)
    {
        case SW1AB:
        case SW1C:
            if (vol_mv < 300U)
            {
                vol_mv = 300U;
            }
            new_volt = (vol_mv - 300U) / 25U;
            break;
        case SW2:/* variable step size based on operating range determined by SW2[6] */
            if (switching_range.sw2 == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val, 1U) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val &= SW_BIT6_MASK; /* mask off other bits */
                if (val != 0U)
                {
                    switching_range.sw2 = 2U;/* set high voltage range */
                }
                else
                {
                    switching_range.sw2 = 1U;/* set low voltage range */
                }
            }
            if (vol_mv < 400U * switching_range.sw2)
            {
                vol_mv = 400U * switching_range.sw2;
            }
            new_volt = (vol_mv - 400U * switching_range.sw2) / 25U * switching_range.sw2;
            break;
        case SW3A:
            if (switching_range.sw3a == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val, 1U) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val &= SW_BIT6_MASK; /* mask off other bits */
                if (val != 0U)
                {
                    switching_range.sw3a = 2U;/* set high voltage range */
                }
                else
                {
                    switching_range.sw3a = 1U;/* set low voltage range */
                }
            }
            if (vol_mv < (400U * switching_range.sw3a))
            {
                vol_mv = 400U * switching_range.sw3a;
            }
            new_volt = (vol_mv - 400U * switching_range.sw3a) / 25U * switching_range.sw3a;
            break;
        case SW3B:
            if (switching_range.sw3b == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val, 1U) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val &= SW_BIT6_MASK; /* mask off other bits */
                if (val != 0U)
                {
                    switching_range.sw3b = 2;/* set high voltage range */
                }
                else
                {
                    switching_range.sw3b = 1U;/* set low voltage range */
                }
            }
            if (vol_mv < (400U * switching_range.sw3b))
            {
                vol_mv = 400U * switching_range.sw3b;
            }
            new_volt = (vol_mv - 400U * switching_range.sw3b) / 25U * switching_range.sw3b;
            break;
        case SW4:
            if (switching_range.sw4 == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val, 1U) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val &= SW_BIT6_MASK; /* mask off other bits */
                if (val != 0U)
                {
                    switching_range.sw4 = 2U;/* set high voltage range */
                }
                else
                {
                    switching_range.sw4 = 1U;/* set low voltage range */
                }
            }
            if (vol_mv < (400U * switching_range.sw4))
            {
                vol_mv = 400U * switching_range.sw4;
            }
            new_volt = (vol_mv - 400U * switching_range.sw4) / 25U * switching_range.sw4;
            break;
        case VGEN1:
        case VGEN2:
            if (vol_mv < 800U)
            {
                vol_mv = 800U;
            }
            new_volt = ((vol_mv - 800U) / 50U);
            volt_mask = VGEN_VOLT_MASK;
            break;
        case VGEN3:
        case VGEN4:
        case VGEN5:
        case VGEN6:
            if (vol_mv < 1800U)
            {
                vol_mv = 1800U;
            }
            new_volt = ((vol_mv - 1800U) / 100U);
            volt_mask = VGEN_VOLT_MASK;
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    /* Read PMIC register */
    err = i2c_read(id, pmic_reg8 + mode_offset, &val, 1U);
    if (err != kStatus_Success)
    {
        error_print("pmic_set_volt - Fail I2C rd PMIC %d, reg %u\n",
            id, pmic_reg8);
        
        return SC_ERR_FAIL;
    }

    /* Update voltage */
    val &= ~volt_mask;
    val |= new_volt;

    /* Update PMIC register */
    err = i2c_write(id, pmic_reg8 + mode_offset, &val, 1U);
    if (err != kStatus_Success)
    {
        error_print("pmic_set_volt - Fail to wr PMIC %d, reg %u\n",
            id, pmic_reg8);
        
        return SC_ERR_FAIL;
    }
    
    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC Regulator Voltage                                               */
/*--------------------------------------------------------------------------*/
sc_err_t pf100_pmic_get_voltage(pmic_id_t id, uint32_t pmic_reg,
    uint32_t *vol_mv, uint32_t mode_to_get)
{
    status_t err;
    uint8_t mode_offset = 0U;
    uint8_t  val = 0, val2 = 0U;
    uint8_t pmic_reg8;

    if (pmic_reg >= 0x100U)
    {
        return SC_ERR_PARM;
    }
    else
    {
        pmic_reg8 = U8(pmic_reg);
    }

    switch (mode_to_get)
    {
        case SW_STBY_MODE:
            mode_offset = 1U;
            break;
        case SW_OFF_MODE:
            mode_offset = 2U;
            break;
        default:/* if not stby or off assume run mode */
            ; /* Intentional empty default */
            break;
    }

    /* Read PMIC register */
    err = i2c_read(id, pmic_reg8 + mode_offset, &val, 1U);
    if (err != kStatus_Success)
    {
        error_print("pmic_get_volt - Fail I2C rd PMIC %d, reg %u\n",
            id, pmic_reg8);
        
        return SC_ERR_FAIL;
    }

    /* Calculate voltage */
    switch (pmic_reg8)
    {
        case SW1AB:
        case SW1C:
            val &= SW_VOLT_MASK;
            *vol_mv = (U32(val) * 25UL) + 300UL;
            break;
        case SW2:/* variable step size based on operating range determined by SW2[6] */
            val &= SW_VOLT_MASK;
            if (switching_range.sw2 == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val2, 1) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val2 &= SW_BIT6_MASK; /* mask off other bits */
                if (val2 != 0U)
                {
                    switching_range.sw2 = 2U;/* set high voltage range */
                }
                else
                {
                    switching_range.sw2 = 1U;/* set low voltage range */
                }
            }
            *vol_mv = (val * 25U * switching_range.sw2) + 400U * switching_range.sw2;
            break;
        case SW3A:
            val &= SW_VOLT_MASK;
            if (switching_range.sw3a == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val2, 1) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val2 &= SW_BIT6_MASK; /* mask off other bits */
                if (val2 != 0U)
                {
                    switching_range.sw3a = 2u;/* set high voltage range */
                }
                else
                {
                    switching_range.sw3a = 1U;/* set low voltage range */
                }
            }
            *vol_mv = (val * 25U * switching_range.sw3a) + 400U * switching_range.sw3a;
            break;
        case SW3B:
            val &= SW_VOLT_MASK;
            if (switching_range.sw3b == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val2, 1) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val2 &= SW_BIT6_MASK; /* mask off other bits */
                if (val2 != 0U)
                {
                    switching_range.sw3b = 2U;/* set high voltage range */
                }
                else
                {
                    switching_range.sw3b = 1U;/* set low voltage range */
                }
            }
            *vol_mv = (val * 25U*switching_range.sw3b) + 400U*switching_range.sw3b;
            break;
        case SW4:
            val &= SW_VOLT_MASK;
            if (switching_range.sw4 == 0U)
            {
                if (i2c_read(id, pmic_reg8, &val2, 1) != kStatus_Success)
                {
                    return SC_ERR_FAIL; /* return if voltage range read failed */
                }
                val2 &= SW_BIT6_MASK; /* mask off other bits */
                if (val2 != 0U)
                {
                    switching_range.sw4 = 2U;/* set high voltage range */
                }
                else
                {
                    switching_range.sw4 = 1U;/* set low voltage range */
                }
            }
            *vol_mv = (U32(val) * 25UL * switching_range.sw4) + 400UL * switching_range.sw4;
            break;
        case VGEN1:
        case VGEN2:
            val &= VGEN_VOLT_MASK;
            *vol_mv = (U32(val) * 50UL) + 800UL;
            break;
        case VGEN3:
        case VGEN4:
        case VGEN5:
        case VGEN6:
            val &= VGEN_VOLT_MASK;
            *vol_mv = (U32(val) * 100UL) + 1800UL;
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC Regulator Mode                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t pf100_pmic_set_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t mode)
{
    status_t err;
    uint32_t val = 0U;
    uint32_t mask = VGEN_MODE_MASK;
    uint8_t pmic_reg8;

    if (pmic_reg >= 0x100U)
    {
        return SC_ERR_PARM;
    }
    else
    {
        pmic_reg8 = U8(pmic_reg);
    }

    switch (pmic_reg8)
    {
        case SW1AB:
            mask = SW_MODE_MASK;
            pmic_reg8 = 0x23U;
            break;
        case SW1C:
            mask = SW_MODE_MASK;
            pmic_reg8 = 0x31U;
            break;
        case SW2:
            mask = SW_MODE_MASK;
            pmic_reg8 = 0x38U;
            break;
        case SW3A:
            mask = SW_MODE_MASK;
            pmic_reg8 = 0x3FU;
            break;
        case SW3B:
            mask = SW_MODE_MASK;
            pmic_reg8 = 0x46U;
            break;
        case SW4:
            mask = SW_MODE_MASK;
            pmic_reg8 = 0x4DU;
            break;
        default:
            ; /* Intentional empty default */
            break;
    }
    
    /* Read PMIC register */
    err = i2c_read(id, pmic_reg8, &val, 1U);
    if (err != kStatus_Success)
     {
        error_print("pmic_set_mode - Fail read PMIC %d, reg %u\n",
            id, pmic_reg8);
        
        return SC_ERR_FAIL;
    }

    /* Update mode */
    val &= ~mask;
    val |= mode;

    /* Update PMIC register */
    (void) i2c_write(id, pmic_reg8, &val, 1U);
    if (err != kStatus_Success)
    {
        error_print("pmic_set_mode - Fail set mode %u PMIC %d, reg %u\n",
            mode, id, pmic_reg8);
        
        return SC_ERR_FAIL;
    }
    
    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC temp                                                            */
/*--------------------------------------------------------------------------*/
uint32_t pf100_get_pmic_temp(pmic_id_t id)
{
    uint8_t sense = 0U;

    (void) i2c_read(id, INTSENSE0, &sense, 1U);

    if ((sense & THERM130) != 0U)
    {
        return 130U;
    }
    else if ((sense & THERM125) != 0U)
    {
        return 125U;
    }
    else if ((sense & THERM120) != 0U)
    {
        return 120U;
    }
    else if ((sense & THERM110) != 0U)
    {
        return 110U;
    }
    else
    {
        ; /* Intentional empty else */
    }
    
    return 100U;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC temp alarm                                                      */
/*--------------------------------------------------------------------------*/
uint32_t pf100_set_pmic_temp_alarm(pmic_id_t id, uint32_t temp)
{
    uint8_t mask; 

    /* Round value and determine mask */
    if (temp <= 110U)
    {
        temp = 110U;
        mask = THERM110;
    }
    else if (temp <= 120U)
    {
        temp = 120U;
        mask = THERM120;
    }
    else if (temp <= 125U)
    {
        temp = 125U;
        mask = THERM125;
    }
    else if (temp <= 130U)
    {
        temp = 130U;
        mask = THERM130;
    }
    else
    {
        temp = 135U;
        mask = 0U;
    }

    /* Write new mask */
    mask = (~mask) & 0x3FU;
    (void) i2c_write(id, INTMASK0, &mask, 1U);        
    
    return temp;
}

/*--------------------------------------------------------------------------*/
/* Access registers of the PF100                                            */
/*--------------------------------------------------------------------------*/
sc_err_t pf100_pmic_register_access(pmic_id_t id, uint32_t address,
    sc_bool_t read_write, uint8_t* value)
{
    status_t err;

    if (read_write == SC_FALSE)
    {
        err = i2c_read(id, address, value, 1U);
        if (err != kStatus_Success)
        {
            error_print("PMIC reg acc - Fail to rd PMIC %x, reg %x\n",
                  id, address);

            return SC_ERR_FAIL;
        }
    }
    else
    {
        err = i2c_write(id, address, value, 1U);
        if (err != kStatus_Success)
        {
            error_print("PMIC reg acc - Fail to wr PMIC %x, reg %x\n",
                  id, address);

            return SC_ERR_FAIL;
        }
    }

    return SC_ERR_NONE;

};

/*--------------------------------------------------------------------------*/
/* Service PMIC interrupt                                                   */
/*--------------------------------------------------------------------------*/
sc_bool_t pf100_pmic_irq_service(pmic_id_t id)
{
    uint8_t mask = 0U;
    uint8_t status = 0U;
    
    /* PMIC pending? */
    (void) i2c_read(id, INTSTAT0, &status, 1U);
    (void) i2c_read(id, INTMASK0, &mask, 1U);
    status &= ~mask;
    if (status != kStatus_Success)
    {
        /* Mask off to prevent repeat */
        mask = 0x3F;
        (void) i2c_write(id, INTMASK0, &mask, 1U);        

        /* Clear */
        (void) i2c_write(id, INTSTAT0, &status, 1U);        

        return SC_TRUE;
    }
   
    return SC_FALSE;
}

