/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017-2021 NXP
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

/* This driver meets SRS requirements PMIC_00010, PMIC_00020, PMIC_00030,
   and PMIC_00040 */

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "fsl_device_registers.h"
#include "drivers/pmic/fsl_pmic.h"
#include "drivers/lpi2c/fsl_lpi2c.h"
#include "drivers/pmic/pf8100/fsl_pf8100.h"
#include "fsl_common.h"

/* Local Defines */

/*!
 * @name Defines for PF8100 masks
 */
#define SW_VOLT_MASK        0x3FU
#define LDO_VOLT_MASK       0xFU
#define MODE_MASK           0xFU
#define TMP_MON_EN_MSK      0x10U
#define THERM_I_MSK         0x3FU

#define NOT_DETECTED        0xE0U
#define A0_SI_REV           0x10U
#define B0_SI_REV           0x20U
#define C0_SI_REV           0x30U

/* Local Functions */

static inline sc_err_t check_si_rev(uint8_t address);

/* Local Variables */

/* variable to keep track of silicon revision
 * 0xE0 is not detected
 * 0x00 is A0
 * 0x01 is B0     */
static uint8_t si_rev = NOT_DETECTED;

/*!
 * Defines for pf8100_ctl_regs_t
 */
/** @{ */
#define PF8100_DEVICEID         0x00U
#define PF8100_SILICONREVID     0x01U
#define PF8100_THERMINT         0x07U
#define PF8100_THERMMASK        0x08U
#define PF8100_THERMSENSE       0x09U
#define PF8100_VMONEN1          0x35U
#define PF8100_VMONEN2          0x36U
#define PF8100_CTRL1            0x37U
#define PF8100_CTRL2            0x38U
#define PF8100_CTRL3            0x39U
#define PF8100_PWRUPCTRL        0x3AU
#define PF8100_VSNVS            0x9DU
#define PF8100_PG_SEL           0x9FU
#define PF8100_RANDOM_GEN       0x33U
#define PF8100_RANDOM_CHK       0x34U
#define PF8100_WD_CONFIG        0x43U
#define PF8100_WD_CLEAR         0x44U

/* Below are all secure register definitions */
#define PF8100_FSOB_FLAGS       0x2AU
#define PF8100_ABIST_OV1        0x2CU
#define PF8100_ABIST_OV2        0x2DU
#define PF8100_ABIST_UV1        0x2EU
#define PF8100_ABIST_UV2        0x2FU
#define PF8100_ABIST_RUN        0x31U
#define PF8100_VMONEN1          0x35U
#define PF8100_VMONEN2          0x36U
#define PF8100_CTRL1            0x37U

/** @} */


/*!
 * Defines for sw_regs_t
 */
/** @{ */
#define sw_config1          0x00U
#define sw_config2          0x01U
#define sw_pwrup            0x02U
#define sw_mode1            0x03U
#define sw_run_volt         0x04U
#define sw_stby_volt        0x05U
/** @} */

/*!
 * Defines for ldo_regs_t
 */
/** @{ */
#define ldo_config1         0x00U
#define ldo_config2         0x01U
#define ldo_pwrup           0x02U
#define ldo_run_volt        0x03U
#define ldo_stby_volt       0x04U
/** @} */

/*!
 * Defines for temp_msk_t
 */
/** @{ */
#define THERM80     BIT(0U)
#define THERM95     BIT(1U)
#define THERM110    BIT(2U)
#define THERM125    BIT(3U)
#define THERM140    BIT(4U)
#define THERM155    BIT(5U)
/** @} */

/*!
 * This type is used to declare control register offsets in
 * a readable manner for the PF8100/PF8200
 */
typedef uint8_t pf8100_ctl_regs_t;

/*!
 * This type is used to model the register structure of switching
 * regulators in the PF8100
 */
typedef uint8_t sw_regs_t;

/*!
 * This type is used to model the register structure of LDOs
 * in the PF8100
 */
typedef uint8_t ldo_regs_t;

/*!
 * This type is used to define the different temperature masks
 */
typedef uint8_t temp_msk_t;

#ifdef PMIC_SECURE_WRITE
/* listing of secure registers */
static const uint32_t secure_reg_list[] =
{
    PF8100_FSOB_FLAGS,
    PF8100_ABIST_OV1,
    PF8100_ABIST_OV2,
    PF8100_ABIST_UV1,
    PF8100_ABIST_UV2,
    PF8100_ABIST_RUN,
    PF8100_VMONEN1,
    PF8100_VMONEN2,
    PF8100_CTRL1
};
#endif

static const uint32_t sw7v_lookup[32] =
{
    1000U,   /* value in mV for VSW7 arranged by index */
    1100U,
    1200U,
    1250U,
    1300U,
    1350U,
    1500U,
    1600U,
    1800U,
    1850U,
    2000U,
    2100U,
    2150U,
    2250U,
    2300U,
    2400U,
    2500U,
    2800U,
    3150U,
    3200U,
    3250U,
    3300U,
    3350U,
    3400U,
    3500U,
    3800U,
    4000U,
    4100U,
    4100U,
    4100U,
    4100U,
    4100U
};

static const uint32_t ldo_table_a0[16] =
{
    1500U, /* lookup for LDO values A0*/
    1800U,
    1850U,
    2500U,
    2750U,
    2800U,
    2850U,
    3000U,
    3100U,
    3150U,
    3200U,
    3300U,
    3350U,
    4000U,
    4900U,
    5000U
};

static const uint32_t ldo_table_b0[16] =
{
    1500U, /* lookup for LDO values  B0*/
    1600U,
    1800U,
    1850U,
    2150U,
    2500U,
    2800U,
    3000U,
    3100U,
    3150U,
    3200U,
    3300U,
    3350U,
    4000U,
    4900U,
    5000U
};

static const uint32_t ldo_table[16] =
{
    1500U, /* lookup for LDO values  in C0 going forward*/
    1600U,
    1800U,
    1850U,
    2150U,
    2500U,
    2800U,
    3000U,
    3100U,
    3150U,
    3200U,
    3300U,
    3350U,
    1650U,
    1700U,
    5000U
};

/*--------------------------------------------------------------------------*/
/* Get PMIC version                                                         */
/*--------------------------------------------------------------------------*/
pmic_version_t pf8100_get_pmic_version(pmic_id_t id)
{
    pmic_version_t ver;

    /* Read device ID */
    if (((status_t) kStatus_Success) != I2C_READ(id, PF8100_DEVICEID,
        &ver.device_id, 1U))
    {
        ver.device_id = 0U;
    }

    /* Read PMIC version */
    if (((status_t) kStatus_Success) != I2C_READ(id, PF8100_SILICONREVID,
        &ver.si_rev, 1U))
    {
        ver.si_rev = 0U;
    }

    /* Mask results */
    ver.device_id &= 0xFFU;
    ver.si_rev &= 0xFFU;

    /* Return results */
    if(ver.si_rev != 0U)
    {
        si_rev = ver.si_rev;
    }

    return ver;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC Regulator Voltage                                               */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_set_voltage(pmic_id_t id, uint32_t pmic_reg,
    uint32_t vol_mv, uint32_t mode_to_set)
{
    sc_err_t err = SC_ERR_NONE;
    uint8_t val = 0U;
    uint8_t pmic_reg8 = U8(pmic_reg);

    /* Check parameters */
    ASRT_ERR(pmic_reg < 0x100U, SC_ERR_PARM);

    /* Check PMIC version */
    ASRT_ERR(check_si_rev(id) == SC_ERR_NONE, SC_ERR_FAIL);

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        const uint32_t *ldo_lookup = ldo_table;

        /* Select table based on PMIC rev */
        if(si_rev == A0_SI_REV)
        {
            ldo_lookup = ldo_table_a0;
        }
        else if ((si_rev == B0_SI_REV) || (si_rev == C0_SI_REV))
        {
            ldo_lookup = ldo_table_b0;
        }
        else
        {
            ; /* Intentional empty else */
        }

        /* Select supply */
        switch (pmic_reg8)
        {
            /* Switcher */
            case PF8100_SW1:
            case PF8100_SW2:
            case PF8100_SW3:
            case PF8100_SW4:
            case PF8100_SW5:
            case PF8100_SW6:
                if (vol_mv == 1800U)
                {
                    val = 0xB1U;
                }
                else if((vol_mv > 1500U) || (vol_mv < 400U))
                {
                    err = SC_ERR_PARM;
                }
                /* Shift 3 for floating math */
                else
                {
                    val = (uint8_t)(((vol_mv * 1000U) - 400000U) / 6250U);
                }

                if (err == SC_ERR_NONE)
                {
                    pmic_reg8 = U2B(mode_to_set) ? (pmic_reg8 + sw_run_volt)
                        : (pmic_reg8 + sw_stby_volt);
                }
                break;
            case PF8100_SW7:
                if ((vol_mv < 1000U) || (vol_mv > 4100U))
                {
                    err = SC_ERR_PARM;
                }
                else
                {
                    /* Use lookup table to get near requested V */
                    val = 0U;
                    while ((val < 32U) && (sw7v_lookup[val] < vol_mv))
                    {
                        val++;
                    }
                    pmic_reg8 = pmic_reg8 + sw_run_volt;
                }
                break;
            /* LDO */
            case PF8100_LDO1:
            case PF8100_LDO2:
            case PF8100_LDO3:
            case PF8100_LDO4:
                if ((vol_mv < 1500U) || (vol_mv > 5000U))
                {
                    err = SC_ERR_PARM;
                }
                else
                {
                    /* Use lookup table to step through possible voltages */
                    val = 0U;
                    for (val = 0U; val < 16U; val ++)
                    {
                        if (ldo_lookup[val] == vol_mv)
                        {
                            break;
                        }
                    }
                    if (val == 16U)
                    {
                        /* Return unavailable if not found in LDO values */
                        err = SC_ERR_UNAVAILABLE;
                    }
                    else
                    {
                        pmic_reg8 = U2B(mode_to_set)
                            ? (pmic_reg8 + ldo_run_volt)
                            : (pmic_reg8 + ldo_stby_volt);
                    }
                }
                break;
            default:
                err = SC_ERR_PARM;
                break;
        }
    }

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        status_t status;

        /* Write PMIC register */
        status = I2C_WRITE(id, pmic_reg8, &val, 1);
        if (status != (status_t) kStatus_Success)
        {
            error_print("pmic_set_voltage - Failed to wr"
                " PMIC %d, reg %u\n", id, pmic_reg8);

            /* Return error */
            err = SC_ERR_FAIL;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC Regulator Voltage                                               */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_get_voltage(pmic_id_t id, uint32_t pmic_reg,
    uint32_t* vol_mv, uint32_t mode_to_get)
{
    sc_err_t err = SC_ERR_NONE;
    const uint32_t *ldo_lookup = ldo_table;
    uint8_t pmic_reg8 = U8(pmic_reg);

    /* Check parameters */
    ASRT_ERR(pmic_reg < 0x100U, SC_ERR_PARM);

    /* Check PMIC version */
    ASRT_ERR(check_si_rev(id) == SC_ERR_NONE, SC_ERR_FAIL);

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        /* Select table based on PMIC rev */
        if (si_rev == A0_SI_REV)
        {
            ldo_lookup = ldo_table_a0;
        }
        else if ((si_rev == B0_SI_REV) || (si_rev == C0_SI_REV))
        {
            ldo_lookup = ldo_table_b0;
        }
        else
        {
            ; /* Intentional empty else */
        }

        /* Select supply */
        switch (pmic_reg8)
        {
            /* Switcher */
            case PF8100_SW1:
            case PF8100_SW2:
            case PF8100_SW3:
            case PF8100_SW4:
            case PF8100_SW5:
            case PF8100_SW6:
                /* Add offset for corresponding LDO voltage */
                pmic_reg8 = U2B(mode_to_get) ? (pmic_reg8 + sw_run_volt) :
                                           (pmic_reg8 + sw_stby_volt);
                break;
            case PF8100_SW7:
                /* Add offset for corresponding LDO voltage */
                pmic_reg8 = pmic_reg8 + sw_run_volt;
                break;
            /* LDO */
            case PF8100_LDO1:
            case PF8100_LDO2:
            case PF8100_LDO3:
            case PF8100_LDO4:
                /* Add offset for corresponding LDO voltage */
                pmic_reg8 = U2B(mode_to_get) ? (pmic_reg8 + ldo_run_volt) :
                                           (pmic_reg8 + ldo_stby_volt);
                break;
            default:
                err = SC_ERR_PARM;
                break;
        }
    }

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        uint8_t val = 0U;
        status_t status;

        /* Read voltage value from PMIC */
        status = I2C_READ(id, pmic_reg8, &val, 1U);
        if (status != (status_t) kStatus_Success)
        {
            error_print("pmic_get_voltage - Failed to rd for"
                " PMIC %d, reg %u\n", id, pmic_reg8);

            err = SC_ERR_FAIL;
        }
        else
        {
            /* Convert binary value to mV value */
            switch (pmic_reg)
            {
                case PF8100_SW1:
                case PF8100_SW2:
                case PF8100_SW3:
                case PF8100_SW4:
                case PF8100_SW5:
                case PF8100_SW6:
                    /* 0xB1 (177) == 1.8V*/
                    if (val == 0xB1U)
                    {
                        *vol_mv = 1800U;
                    }
                    /* We are in the .4V to 1.5V range */
                    *vol_mv = ((U32(val) * 6250U) + 400000U) / 1000U;
                    break;
                case PF8100_SW7:
                    /* Obtain voltage from sw7 lookup table */
                    *vol_mv = sw7v_lookup[val];
                    break;
                case PF8100_LDO1:
                case PF8100_LDO2:
                case PF8100_LDO3:
                case PF8100_LDO4:
                    /* Obtain voltage from LDO lookup table */
                    *vol_mv = ldo_lookup[val];
                    break;
                default:
                    ; /* Intentional empty default */
                    break;
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC Regulator Mode                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_set_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t mode)
{
    sc_err_t err = SC_ERR_NONE;
    uint8_t pmic_reg8 = U8(pmic_reg);

    /* Check parameters */
    ASRT_ERR(pmic_reg < 0x100U, SC_ERR_PARM);

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        /* Check to make sure a switching supply passed */
        switch (pmic_reg8)
        {
            /* Switchers */
            case PF8100_SW1:
            case PF8100_SW2:
            case PF8100_SW3:
            case PF8100_SW4:
            case PF8100_SW5:
            case PF8100_SW6:
            case PF8100_SW7:
                pmic_reg8 = pmic_reg8 + sw_mode1;
                break;
            /* LDOs */
            case PF8100_LDO1:
            case PF8100_LDO2:
            case PF8100_LDO3:
            case PF8100_LDO4:
                pmic_reg8 = pmic_reg8 + ldo_config2;
                break;
            default:
                err = SC_ERR_PARM;
                break;
        }
    }

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        uint32_t val = 0U;
        status_t status;

        /* Read from PMIC */
        status = I2C_READ(id, pmic_reg8, &val, 1U);

        /* Check for success? */
        if (status != (status_t) kStatus_Success)
        {
            error_print("pmic_set_mode - Failed to rd PMIC %d"
                ", reg %u\n", id, pmic_reg8);

            /* Return error */
            err = SC_ERR_FAIL;
        }
        else
        {
            /* Calculate value */
            val &= ~MODE_MASK;
            val |= mode & MODE_MASK;

            /* Write to PMIC */
            status = I2C_WRITE(id, pmic_reg8, &val, 1U);

            /* Check for success? */
            if (status != (status_t) kStatus_Success)
            {
                error_print("pmic_set_mode - Failed set mode %u"
                    " PMIC %d, reg %u\n", mode, id, pmic_reg8);

                /* Return error */
                err = SC_ERR_FAIL;
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC Regulator Mode                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_get_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t *mode)
{
    sc_err_t err = SC_ERR_NONE;
    uint8_t pmic_reg8= U8(pmic_reg);

    /* Check parameters */
    ASRT_ERR(pmic_reg < 0x100U, SC_ERR_PARM);

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        /* Check to make sure a switching supply passed */
        switch (pmic_reg8)
        {
            /* Switchers */
            case PF8100_SW1:
            case PF8100_SW2:
            case PF8100_SW3:
            case PF8100_SW4:
            case PF8100_SW5:
            case PF8100_SW6:
            case PF8100_SW7:
                pmic_reg8 = pmic_reg8 + sw_mode1;
                break;
            /* LDOs */
            case PF8100_LDO1:
            case PF8100_LDO2:
            case PF8100_LDO3:
            case PF8100_LDO4:
                pmic_reg8 = pmic_reg8 + ldo_config2;
                break;
            default:
                err = SC_ERR_PARM;
                break;
        }
    }

    /* Check for error? */
    if (err == SC_ERR_NONE)
    {
        uint32_t val = 0U;
        status_t status;

        /* Read from PMIC */
        status = I2C_READ(id, pmic_reg8, &val, 1U);

        /* Check for success? */
        if (status != (status_t) kStatus_Success)
        {
            error_print("pmic_get_mode - Failed to rd PMIC %d"
                ", reg %u\n", id, pmic_reg8);

            /* Return error */
            err = SC_ERR_FAIL;
        }
        else
        {
            /* Return result */
            val &= MODE_MASK;
            *mode = val;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC temp                                                            */
/*--------------------------------------------------------------------------*/
uint32_t pf8100_get_pmic_temp(pmic_id_t id)
{
    uint32_t rtn = 70U; /* return 10 degrees below lowest alarm */
    uint8_t sense = 0U, reg = 0U;

    /* Enabled monitor if off */
    (void) I2C_READ(id, PF8100_CTRL1, &reg, 1U);
    if((reg & TMP_MON_EN_MSK) == 0U)
    {
        reg |= TMP_MON_EN_MSK;
        (void) I2C_WRITE(id, PF8100_CTRL1, &reg, 1U);
    }

    /* Read temp sense */
    (void) I2C_READ(id, PF8100_THERMSENSE, &sense, 1U);

    /* Check temp 155C */
    if ((sense & THERM155) != 0U)
    {
        rtn = 155U;
    }
    /* Check temp 140C */
    else if ((sense & THERM140) != 0U)
    {
        rtn = 140U;
    }
    /* Check temp 125C */
    else if ((sense & THERM125) != 0U)
    {
        rtn = 125U;
    }
    /* Check temp 110C */
    else if ((sense & THERM110) != 0U)
    {
        rtn = 110U;
    }
    /* Check temp 95C */
    else if ((sense & THERM95) != 0U)
    {
        rtn = 95U;
    }
    /* Check temp 80C */
    else if ((sense & THERM80) != 0U)
    {
        rtn = 80U;
    }
    else
    {
        ; /* Intentional empty else */
    }

     return rtn;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC temp alarm                                                      */
/*--------------------------------------------------------------------------*/
uint32_t pf8100_set_pmic_temp_alarm(pmic_id_t id, uint32_t temp)
{
    uint8_t mask, reg = 0U;

    mask = THERM_I_MSK; /* start with all temp alarms enabled */
    if (temp > 80U) /* if less than 80 enable all alarms above 80 */
    {
        /* subtract and round temp */
        mask = (mask << ((temp - 80U) / 15U)) & THERM_I_MSK;
    }
    mask = (~mask) & THERM_I_MSK;

    /* Write new mask */
    (void) I2C_READ(id, PF8100_THERMMASK, &reg, 1U);
    reg &= U8(~THERM_I_MSK);
    reg |= mask;
    (void) I2C_WRITE(id, PF8100_THERMMASK, &reg, 1U);

    /* Enabled monitor if off */
    (void) I2C_READ(id, PF8100_CTRL1, &reg, 1U);
    if((reg & TMP_MON_EN_MSK) == 0U)
    {
        reg |= TMP_MON_EN_MSK;
        (void) I2C_WRITE(id, PF8100_CTRL1, &reg, 1U);
    }

    return temp;
}

#ifdef PMIC_SECURE_WRITE
/*--------------------------------------------------------------------------*/
/* check if register need secure write                                      */
/*--------------------------------------------------------------------------*/
bool pf8200_reg_need_secure_write(uint8_t reg_address)
{
    uint8_t i;
    sc_bool_t secure = SC_FALSE;
    for (i = 0; i < ARRAY_SIZE(secure_reg_list); i++) {
        if (secure_reg_list[i] == reg_address)
                secure = SC_TRUE;
    }
    return secure;
}
#endif

/*--------------------------------------------------------------------------*/
/* Access registers of the PF8100                                           */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_register_access(pmic_id_t id, uint32_t address,
    sc_bool_t read_write, uint8_t* value)
{
    sc_err_t err = SC_ERR_NONE;
    status_t status;

    if (read_write == SC_FALSE)
    {
        status = I2C_READ(id, U8(address), value, 1U);
        if (status != (status_t) kStatus_Success)
        {
            error_print("PMIC reg acc - Failed to rd PMIC"
                " %x, reg %x\n", id, address);

            err = SC_ERR_FAIL;
        }
    }
    else
    {
        status = I2C_WRITE(id, U8(address), value, 1U);
        if (status != (status_t) kStatus_Success)
        {
            error_print("PMIC reg acc - Failed to wr PMIC"
                " %x, reg %x\n", id, address);

            err = SC_ERR_FAIL;
        }
#ifdef PMIC_SECURE_WRITE
        uint8_t temp;
        #ifndef PMIC_CRC
            #error CRC must be defined for secure writes
        #endif

        /* do secure write if one of the protected registers */
        if (pf8200_reg_need_secure_write(address))
        {
            /* read RANDOM_GEN register */
            status |= I2C_READ(id, U8(PF8100_RANDOM_GEN), &temp, 1U);
            if (status != (status_t) kStatus_Success)
            {
                error_print("PMIC reg acc - Failed rd PMIC"
                    " %x, reg %x\n", id, address);

                err = SC_ERR_FAIL;
            }
            /* Write RANDOM_GEN value to RANDOM_CHK */
            status = I2C_WRITE(id, U8(PF8100_RANDOM_CHK), &temp, 1U);
            if (status != (status_t) kStatus_Success)
            {
                error_print("PMIC register access - Failed wr PMIC"
                    " %x, reg %x\n", id, address);

                err = SC_ERR_FAIL;
            }
        }
#endif
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Service PMIC interrupt                                                   */
/*--------------------------------------------------------------------------*/
sc_bool_t pf8100_pmic_irq_service(pmic_id_t id)
{
    sc_bool_t rtn = SC_FALSE;
    uint8_t mask = 0U;
    uint8_t therm_stat = 0U;

    /* PMIC THERM */
    (void) I2C_READ(id, PF8100_THERMINT, &therm_stat, 1U);
    (void) I2C_READ(id, PF8100_THERMMASK, &mask, 1U);
    therm_stat &= ~mask;
    if (therm_stat != 0U)
    {
        mask = THERM_I_MSK;
        /* Mask off to prevent repeat */
        (void) I2C_WRITE(id, PF8100_THERMMASK, &mask, 1U);

        /* Clear */
        (void) I2C_WRITE(id, PF8100_THERMINT, &therm_stat, 1U);

        rtn = SC_TRUE;
    }

    /*! @todo enable other interrupt sources to be cleared */

    return rtn;
}


/*--------------------------------------------------------------------------*/
/* Check for Silicon Revision                                               */
/*--------------------------------------------------------------------------*/
static inline sc_err_t check_si_rev(uint8_t address)
{
    sc_err_t err = SC_ERR_NONE;
    uint8_t buff = NOT_DETECTED;

    /* Check if already detected? */
    if (si_rev == NOT_DETECTED)
    {
        /* Read silicon rev from PMIC */
        if (I2C_READ(address, PF8100_SILICONREVID, &buff, 1U)
            == (status_t) kStatus_Success)
        {
            /* Return result */
            si_rev = buff;
        }
        else
        {
            /* Return error */
            err = SC_ERR_FAIL;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Enable PF8100 WDOG related bits                                          */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_wdog_enable(pmic_id_t id, sc_bool_t wd_en,
        sc_bool_t stby_en, sc_bool_t wdi_stby_active)
{
    uint8_t val = 0U; /* disable all bits by default */
    sc_err_t err = SC_ERR_NONE;

    /* read the CTRL1 register */
    err |= pf8100_pmic_register_access(id, PF8100_CTRL1, SC_FALSE, &val);

    /* wdog enable bit */
    if (wd_en) { val |= 0x8U;}
    /* wdog stby enable bit */
    if (stby_en) { val |= 0x4U;}
    /* wdi stby enable */
    if (wdi_stby_active) { val |= 0x2U;}

    /* write back the modified register */
    err |= pf8100_pmic_register_access(id, PF8100_CTRL1, SC_TRUE, &val);

    return err;
}

/*--------------------------------------------------------------------------*/
/* Disable PF8100 WDOG related bits                                         */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_wdog_disable(pmic_id_t id, sc_bool_t wd_dis,
        sc_bool_t stby_en, sc_bool_t wdi_stby_active)
{
    uint8_t val = 0U; /* disable all bits by default */
    sc_err_t err = SC_ERR_NONE;

    /* read the CTRL1 register */
    err |= pf8100_pmic_register_access(id, PF8100_CTRL1, SC_FALSE, &val);

    /* wdog disabled */
    if (wd_dis) { val &= 0xF7U;}
    /* wdog stby disabled */
    if (stby_en) { val &= 0xFBU;}
    /* wdi stby enable disabled */
    if (wdi_stby_active) { val &= 0xFDU;}

    /* write back the modified register */
    err |= pf8100_pmic_register_access(id, PF8100_CTRL1, SC_TRUE, &val);

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set PF8100 WDOG timeout                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_wdog_set_timeout(pmic_id_t id, uint32_t* timeout)
{
    uint8_t counter = 0;
    sc_err_t err = SC_ERR_NONE;
    if ((*timeout > 0U) && (*timeout < 32768U))
    {
        while ((*timeout < BIT32(counter)) && (counter < 0x0FU))
        {counter++;}

        counter = counter & 0x0FU; /* Mask to make sure we only write the bits we want */
        err = pf8100_pmic_register_access(id, PF8100_WD_CONFIG, SC_TRUE, &counter);
        if (err == SC_ERR_NONE)
        {
            *timeout = BIT32(counter); /* return the exact timeout in ms */
        }
    }
    else
    {
        err = SC_ERR_PARM;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Service PF8100 WDOG                                                      */
/*--------------------------------------------------------------------------*/
sc_err_t pf8100_pmic_wdog_service(pmic_id_t id)
{
    uint8_t val = 0x1U; /* write a 1 to bit 0 for the WD_CLEAR register */
    return pf8100_pmic_register_access(id, PF8100_WD_CLEAR, SC_TRUE, &val);
}

