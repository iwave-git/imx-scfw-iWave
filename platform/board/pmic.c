/*
** ###################################################################
**
**     Copyright 2018-2021 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @file
 *
 * Implementation of the system controller PMIC interface layer including
 * dynamic PMIC handling
 */
/*==========================================================================*/

/* Includes */

#include "main/main.h"
#include "test/common/test.h"
#include "board/pmic.h"

/* Declare a Global PMIC identifier for dynamic functions */
uint8_t PMIC_TYPE = PMIC_NONE;

/* Initialize PMIC_TYPE if not done from board file */
static sc_err_t get_pmic_type(pmic_id_t id);

/*--------------------------------------------------------------------------*/
/* Set PMIC Regulator Voltage                                               */
/*--------------------------------------------------------------------------*/
sc_err_t dynamic_pmic_set_voltage(pmic_id_t id, uint32_t pmic_reg,
    uint32_t vol_mv, uint32_t mode_to_set)
{
    sc_err_t rtn = SC_ERR_NONE;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = SC_ERR_FAIL;
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == SC_ERR_NONE)
    {
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_pmic_set_voltage(id, pmic_reg, vol_mv,
                    mode_to_set);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_pmic_set_voltage(id, pmic_reg, vol_mv,
                    mode_to_set);
                break;
            default :
                rtn = SC_ERR_NOTFOUND;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC Regulator Voltage                                               */
/*--------------------------------------------------------------------------*/
sc_err_t dynamic_pmic_get_voltage(pmic_id_t id, uint32_t pmic_reg, uint32_t *vol_mv,
        uint32_t mode_to_get)
{
    sc_err_t rtn = SC_ERR_NONE;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = SC_ERR_FAIL;
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == SC_ERR_NONE)
    {
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_pmic_get_voltage(id, pmic_reg, vol_mv, mode_to_get);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_pmic_get_voltage(id, pmic_reg, vol_mv, mode_to_get);
                break;
            default :
                rtn = SC_ERR_NOTFOUND;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC Regulator Mode                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t dynamic_pmic_set_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t mode)
{
    sc_err_t rtn = SC_ERR_NONE;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = SC_ERR_FAIL;
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == SC_ERR_NONE)
    {
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_pmic_set_mode(id, pmic_reg, mode);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_pmic_set_mode(id, pmic_reg, mode);
                break;
            default :
                rtn = SC_ERR_NOTFOUND;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC Regulator Mode                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t dynamic_pmic_get_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t *mode)
{
    sc_err_t rtn = SC_ERR_NONE;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = SC_ERR_FAIL;
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == SC_ERR_NONE)
    {
        switch (PMIC_TYPE)
        {
            case PF100 : /* get mode not supported for pf100 */
                rtn = SC_ERR_NOTFOUND;
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_pmic_get_mode(id, pmic_reg, mode);
                break;
            default :
                rtn = SC_ERR_NOTFOUND;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Service PMIC IRQ                                                         */
/*--------------------------------------------------------------------------*/
sc_bool_t dynamic_pmic_irq_service(pmic_id_t id)
{
    sc_bool_t rtn = SC_TRUE;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = SC_FALSE;
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == SC_TRUE)
    {
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_pmic_irq_service(id);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_pmic_irq_service(id);
                break;
            default :
                rtn = SC_FALSE;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Access PMIC register                                                     */
/*--------------------------------------------------------------------------*/
sc_err_t dynamic_pmic_register_access(pmic_id_t id, uint32_t address,
                                      sc_bool_t read_write, uint8_t* value)
{
    sc_err_t rtn = SC_ERR_NONE;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = SC_ERR_FAIL;
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == SC_ERR_NONE)
    {
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_pmic_register_access(id, address, read_write, value);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_pmic_register_access(id, address, read_write, value);
                break;
            default :
                rtn = SC_ERR_NOTFOUND;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC version                                                         */
/*--------------------------------------------------------------------------*/
pmic_version_t dynamic_get_pmic_version(pmic_id_t id)
{
    pmic_version_t rtn = {0, 0}; /* initialize to empty as err return */
    sc_bool_t set = SC_TRUE;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            set = SC_FALSE;
        }
    }

	/* skip switch statement if PMIC type not detected */
    if (set != SC_FALSE)
    {
		/* Call specific function based on established PMIC_TYPE */
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_get_pmic_version(id);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_get_pmic_version(id);
                break;
            default :
                /* default case leaves rtn as empty version */
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC temperature                                                     */
/*--------------------------------------------------------------------------*/
uint32_t dynamic_get_pmic_temp(pmic_id_t id)
{
    uint32_t rtn = 0U;
    uint32_t default_temp = 25U;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = default_temp; /* default to room temp */
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == 0U)
    {
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_get_pmic_temp(id);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_get_pmic_temp(id);
                break;
            default :
                rtn = default_temp;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Set PMIC Temperature Alarm                                               */
/*--------------------------------------------------------------------------*/
uint32_t dynamic_set_pmic_temp_alarm(pmic_id_t id, uint32_t temp)
{
    uint32_t rtn = 0U;

    if (PMIC_TYPE == PMIC_NONE)
    {
        /* Initialize PMIC_TYPE if not already */
        if(get_pmic_type(id) != SC_ERR_NONE)
        {
            rtn = temp; /* return temp called with */
        }
    }

    /* Call specific function based on established PMIC_TYPE */
    if (rtn == 0U)
    {
        switch (PMIC_TYPE)
        {
            case PF100 :
                rtn = pf100_set_pmic_temp_alarm(id, temp);
                break;
            case PF8100 :
            case PF8200 :
                rtn = pf8100_set_pmic_temp_alarm(id, temp);
                break;
            default :
                rtn = temp;
                break;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Determine PMIC type at address                                           */
/*--------------------------------------------------------------------------*/
static sc_err_t get_pmic_type(pmic_id_t id)
{
    uint8_t dev_id = pmic_get_device_id(id);
    sc_err_t rtn = SC_ERR_NONE;

    switch (dev_id)
    {
        case PF100_DEV_ID :
            PMIC_TYPE = PF100;
            break;
        case PF8100_DEV_ID :
            PMIC_TYPE = PF8100;
            break;
        case PF8200_DEV_ID :
            PMIC_TYPE = PF8200;
            break;
        default :
            PMIC_TYPE = PMIC_NONE;
            rtn = SC_ERR_NOTFOUND;
            break;
    }

    return rtn;
}
