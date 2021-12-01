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

#ifndef DRV_PMIC_PF100_H
#define DRV_PMIC_PF100_H

/*!
 * @addtogroup pf100_driver
 * @{
 */

/*! @file */

/*!
 * @name Defines for pf100_vol_regs_t
 */
/** @{ */
#define SW1AB		0x20U	/*!<  Base register for SW1AB control */
#define SW1C		0x2EU	/*!<  Base register for SW1C  control */
#define SW2			0x35U	/*!<  Base register for SW2   control */
#define SW3A		0x3cU	/*!<  Base register for SW3A  control */
#define SW3B		0x43U	/*!<  Base register for SW3B  control */
#define SW4			0x4AU	/*!<  Base register for SW4   control */
#define VGEN1		0x6CU	/*!<  Base register for VGEN1 control */
#define VGEN2		0x6DU	/*!<  Base register for VGEN2 control */
#define VGEN3		0x6EU	/*!<  Base register for VGEN3 control */
#define VGEN4		0x6FU	/*!<  Base register for VGEN4 control */
#define VGEN5		0x70U	/*!<  Base register for VGEN5 control */
#define VGEN6		0x71U	/*!<  Base register for VGEN6 control */
/** @} */

/*!
 * @name Defines for sw_pmic_mode_t
 */
/** @{ */
#define SW_MODE_OFF_STBY_OFF	0x0U	/*!< Normal Mode: OFF,  Standby Mode: OFF  */
#define SW_MODE_PWM_STBY_OFF	0x1U	/*!< Normal Mode: PWM,  Standby Mode: OFF  */
#define SW_MODE_PFM_STBY_OFF	0x3U	/*!< Normal Mode: PFM,  Standby Mode: OFF  */
#define SW_MODE_APS_STBY_OFF	0x4U	/*!< Normal Mode: APS,  Standby Mode: OFF  */
#define SW_MODE_PWM_STBY_PWM	0x5U	/*!< Normal Mode: PWM,  Standby Mode: PWM  */
#define SW_MODE_PWM_STBY_APS	0x6U	/*!< Normal Mode: PWM,  Standby Mode: APS  */
#define SW_MODE_APS_STBY_APS	0x8U	/*!< Normal Mode: APS,  Standby Mode: APS  */
#define SW_MODE_APS_STBY_PFM	0xCU	/*!< Normal Mode: APS,  Standby Mode: PFM  */
#define SW_MODE_PWM_STBY_PFM	0xDU	/*!< Normal Mode: PWM,  Standby Mode: PFM  */
/** @} */


/*!
 * @name Defines for vgen_pmic_mode_t
 */
/** @{ */
#define VGEN_MODE_OFF			(0x0U << 4U) /*!< VGEN always OFF */
#define VGEN_MODE_ON			(0x1U << 4U) /*!< VGEN always ON  */
#define VGEN_MODE_STBY_OFF		(0x3U << 4U) /*!< VGEN Run: ON STBY: OFF */
#define VGEN_MODE_LP			(0x5U << 4U) /*!< VGEN Run: LPWR STBY: LPWR */
#define VGEN_MODE_LP2			(0x7U << 4U) /*!< VGEN Run: LPWR STBY: LPWR */
/** @} */


/*!
 * @name Defines for sw_vmode_reg_t
 */
/** @{ */
#define SW_RUN_MODE		0U /*!< SW run mode voltage   */
#define SW_STBY_MODE	1U /*!< SW standby mode voltage */
#define SW_OFF_MODE		2U /*!< SW off/sleep mode voltage */
/** @} */

/*!
 * This type is used to indicate which register to address.
 *
 * Refer to the PF100 Datasheet for the description of register.
 */
typedef uint8_t pf100_vol_regs_t;
/*!
 * This type is used to indicate a switching regulator mode.
 *
 * Refer to the PF100 Datasheet for the description of each mode.
 */
typedef uint8_t sw_pmic_mode_t;
/*!
 * This type is used to indicate a VGEN (LDO) regulator mode.
 *
 * Refer to the LDO control register description in the PF100 Datasheet
 * for possible mode combinations.
 */
typedef uint8_t vgen_pmic_mode_t;
/*!
 * This type encodes which voltage mode register to set when calling 
 * [pf100_pmic_set_voltage()](@ref pf100_pmic_set_voltage).
 *
 *  Possible modes are Run, Standby and Off/Sleep.
 */
typedef uint8_t sw_vmode_reg_t;

/*! 
 * This function returns the device ID and revision for the PF100 PMIC.
 *
 *  @param[in]    id            I2C address of PMIC device
 *
 *  @return Returns a structure with the device ID and revision.
 */
pmic_version_t pf100_get_pmic_version( pmic_id_t id);

/*!
 * This function sets the voltage of a corresponding voltage regulator for the
 * PF100 PMIC.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator; 
 *                              see [pf100_vol_regs_t](@ref pf100_vol_regs_t)
 * @param[in]     vol_mv        New voltage setpoint for the regulator in millivolts
 * @param[in]     mode_to_set   Mode to set the voltage for run, standby and off;
 *                              only applicable to switching regulators, ignored
 *                              otherwise; see [sw_vmode_reg_t](@ref sw_vmode_reg_t)
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t pf100_pmic_set_voltage(pmic_id_t id, uint32_t pmic_reg, uint32_t vol_mv,
    uint32_t mode_to_set);

/*!
 * This function gets the voltage on a corresponding voltage regulator for the
 * PF100 PMIC.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator;
 *                              see [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[out]    vol_mv        pointer to return voltage in millivolts
 * @param[in]     mode_to_get   Mode to get the voltage for run, standby and off;
 *                              only applicable to switching regulators, ignored
 *                              otherwise; see [sw_vmode_reg_t](@ref sw_vmode_reg_t)
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 */
sc_err_t pf100_pmic_get_voltage(pmic_id_t id, uint32_t pmic_reg, uint32_t *vol_mv, 
		uint32_t mode_to_get);

/*!
 * This function sets the mode of the specified regulator.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator; 
                                see [pf100_vol_regs_t](@ref pf100_vol_regs_t)
 * @param[in]     mode          mode to set the regulator; 
 *                              see [vgen_pmic_mode_t](@ref vgen_pmic_mode_t)
 *                              and [sw_pmic_mode_t](@ref sw_pmic_mode_t)
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t pf100_pmic_set_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t mode);

/*!
 * This function gets the current PMIC temperature as sensed by the 
 * PMIC temperature sensor.
 *
 * @param[in]     id            I2C address of PMIC device
 *
 * @return returns the temp sensed by the PMIC in a UINT32 in Celsius
 *
 * Return errors:
 * - SC_ERR_CONFIG if temperature monitor is not enabled
 *
 * Note PMIC PF100 temp is returned as the highest temp sensor enabled.
 */
uint32_t pf100_get_pmic_temp(pmic_id_t id);

/*!
 * This function sets the temp alarm for the PMIC in Celsius
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     temp          Temperature to set the alarm
 *
 * Note the granularity for PF100 PMIC only allows the following
 * values:
 * 110
 * 120
 * 125
 * 130
 * 135
 *
 * @return Returns the temperature that the alarm is set to in Celsius
 */
uint32_t pf100_set_pmic_temp_alarm(pmic_id_t id, uint32_t temp);

/*
 * This function allows access to individual registers of the PF100
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
 *
 */
sc_err_t pf100_pmic_register_access(pmic_id_t id, uint32_t address,
    sc_bool_t read_write, uint8_t* value);

/*!
 * This function services the interrupt for the temp alarm
 *
 * @param[in]     id            I2C address of PMIC device
 *
 * @return Returns SC_TRUE if there was a temperature interrupt to be cleared
 */
sc_bool_t pf100_pmic_irq_service(pmic_id_t id);

#endif

/** @} */

