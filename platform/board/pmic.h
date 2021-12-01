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
 * PMIC include for PMIC interface layer. This API is used to abstract the
 * PMIC driver. It also supports dynamic PMIC identification and function
 * binding (normally only used for dev boards).
 *
 * @addtogroup pmic_driver
 * @{
 */
/*==========================================================================*/

#ifndef SC_PMIC_H
#define SC_PMIC_H

/* Includes */

#include "main/main.h"
#include "drivers/pmic/fsl_pmic.h"
#include "drivers/pmic/pf100/fsl_pf100.h"
#include "drivers/pmic/pf8100/fsl_pf8100.h"

/* Defines */

/*!
 * @name Defines for supported PMIC devices
 */
/** @{ */
#define PMIC_NONE   0U
#define PF100       1U
#define PF8100      2U
#define PF8200      3U
/** @} */

/*!
 * @name Defines for PMIC configuration
 */
/** @{ */
#define PF100_DEV_ID            0x10U
#define PF8100_DEV_ID           0x40U
#define PF8200_DEV_ID           0x48U
#define PF8X00_FAM_ID           0x40U
#define PF7X00_FAM_ID           0x80U
#define PF8100_A0_REV           0x10U
/* IWG27M: PMIC: Defining B0 PMIC Version */
#define PF8100_B0_REV           0x20U
#define FAM_ID_MASK             0xF0U
/** @} */

/*! Global PMIC type identifier */
extern uint8_t PMIC_TYPE;

/* Table for dynamic PMIC functionality */
#ifdef PMIC /* Replace function prefix with defined PMIC */
    #define FUNC_PRE(name, function)            FUNC_PREPRE(name,function)
    #define FUNC_PREPRE(name, function)         name ## function
    #define PMIC_SET_MODE           FUNC_PRE(PMIC, _pmic_set_mode)
    #define PMIC_GET_MODE           FUNC_PRE(PMIC, _pmic_get_mode)
    #define PMIC_SET_VOLTAGE        FUNC_PRE(PMIC, _pmic_set_voltage)
    #define PMIC_GET_VOLTAGE        FUNC_PRE(PMIC, _pmic_get_voltage)
    #define PMIC_IRQ_SERVICE        FUNC_PRE(PMIC, _pmic_irq_service)
    #define PMIC_REGISTER_ACCESS    FUNC_PRE(PMIC, _pmic_register_access)
    #define GET_PMIC_VERSION        FUNC_PRE(PMIC, _get_pmic_version)
    #define GET_PMIC_TEMP           FUNC_PRE(PMIC, _get_pmic_temp)
    #define SET_PMIC_TEMP_ALARM     FUNC_PRE(PMIC, _set_pmic_temp_alarm)
#else /* Point MACROS at the dynamic function for run time decision */
    #define PMIC_SET_VOLTAGE        dynamic_pmic_set_voltage
    #define PMIC_GET_VOLTAGE        dynamic_pmic_get_voltage
    #define PMIC_SET_MODE           dynamic_pmic_set_mode
    #define PMIC_GET_MODE           dynamic_pmic_get_mode
    #define PMIC_IRQ_SERVICE        dynamic_pmic_irq_service
    #define PMIC_REGISTER_ACCESS    dynamic_pmic_register_access
    #define GET_PMIC_VERSION        dynamic_get_pmic_version
    #define GET_PMIC_TEMP           dynamic_get_pmic_temp
    #define SET_PMIC_TEMP_ALARM     dynamic_set_pmic_temp_alarm
#endif

/*!
 * This function sets the voltage of a corresponding voltage regulator for the
 * supported PMIC types
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator
 *                              e.g [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[in]     vol_mv        New voltage setpoint for the regulator in millivolts
 * @param[in]     mode_to_set   Which mode to change setpoint for. Refer to each
 *                              PMIC for valid modes
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t dynamic_pmic_set_voltage(pmic_id_t id, uint32_t pmic_reg, uint32_t vol_mv,
                    uint32_t mode_to_set);

/*!
 * This function gets the voltage on a corresponding voltage regulator of the
 * PMIC
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator
 *                              e.g [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[out]    vol_mv        pointer to return voltage in millivolts
 * @param[in]     mode_to_get   Mode for which to get the voltage. Refer to each
 *                              PMIC for valid modes.
 *
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 */
sc_err_t dynamic_pmic_get_voltage(pmic_id_t id, uint32_t pmic_reg, uint32_t *vol_mv,
		uint32_t mode_to_get);

/*!
 * This function sets the mode of the specified regulator.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator;
                                e.g [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[in]     mode          mode to set the regulator; Refer to each
 *                              PMIC for valid modes.
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t dynamic_pmic_set_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t mode);

/*!
 * This function gets the mode of the specified regulator.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator;
                                e.g [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[in]     mode          pointer to return mode in raw hex form
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t dynamic_pmic_get_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t *mode);

/*!
 * This function services the interrupt for the temp alarm
 *
 * @param[in]     id            I2C address of PMIC device
 *
 * @return Returns SC_TRUE if there was a temperature interrupt to be cleared
 */
sc_bool_t dynamic_pmic_irq_service(pmic_id_t id);

/*!
 * This function allows access to individual registers of the PMIC
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     address       register address to access
 * @param[in]     read_write    bool indicating read(SC_FALSE/0) or write(SC_TRUE/1)
 * @param[in,out] value         value to read or to set
 *
 * @return Returns ar error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 */
sc_err_t dynamic_pmic_register_access(pmic_id_t id, uint32_t address,
                                      sc_bool_t read_write, uint8_t* value);

/*!
 * This function returns the device ID and revision for the PMIC.
 *
 *  @param[in]    id            I2C address of PMIC device
 *
 *  @return Returns a structure with the device ID and revision.
 */
pmic_version_t dynamic_get_pmic_version(pmic_id_t id);

/*!
 * This function gets the current PMIC temperature as sensed by the
 * PMIC temperature sensor.
 *
 * @param[in]     id            I2C address of PMIC device
 *
 * @return returns the temp sensed by the PMIC in a UINT32 in Celsius
 *
 * Note: Refer to Refer to each PMIC for temperature details
 *
 * Return errors:
 * - SC_ERR_CONFIG if temperature monitor is not enabled
 *
 */
uint32_t dynamic_get_pmic_temp(pmic_id_t id);

/*!
 * This function sets the temp alarm for the PMIC in Celsius
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     temp          Temperature to set the alarm
 *
 * Note: Refer to Refer to each PMIC for temperature details
 *
 * @return Returns the temperature that the alarm is set to in Celsius
 */
 uint32_t dynamic_set_pmic_temp_alarm(pmic_id_t id, uint32_t temp);

 /** @} */

 #endif /* SC_PMIC_H */

