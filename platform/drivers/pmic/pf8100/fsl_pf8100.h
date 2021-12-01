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

#ifndef DRV_PMIC_PF8100_H
#define DRV_PMIC_PF8100_H

/*!
 * @addtogroup pf8100_driver
 * @{
 */

/*! @file */

#ifdef PMIC_CRC /* alias the crc functions if CRC is defined */
    #define I2C_WRITE       i2c_j1850_write
    #define I2C_READ        i2c_j1850_read
#else
    #define I2C_WRITE       i2c_write
    #define I2C_READ        i2c_read
#endif

/*!
 * @name Defines for pf8100_vregs_t
 */
/** @{ */
#define PF8100_CTRL1    0x37U /*!< CTRL1 register of PF8100/PF8200 */
#define PF8100_SW1		0x4DU /*!< Base register for SW1 regulator control */
#define PF8100_SW2		0x55U /*!< Base register for SW2 regulator control */
#define PF8100_SW3		0x5DU /*!< Base register for SW3 regulator control */
#define PF8100_SW4		0x65U /*!< Base register for SW4 regulator control */
#define PF8100_SW5		0x6DU /*!< Base register for SW5 regulator control */
#define PF8100_SW6		0x75U /*!< Base register for SW6 regulator control */
#define PF8100_SW7		0x7DU /*!< Base register for SW7 regulator control */
#define PF8100_LDO1		0x85U /*!< Base register for LDO1 regulator control */
#define PF8100_LDO2		0x8BU /*!< Base register for LDO2 regulator control */
#define PF8100_LDO3		0x91U /*!< Base register for LDO3 regulator control */
#define PF8100_LDO4		0x97U /*!< Base register for LDO4 regulator control */
/** @} */

/*!
 * @name Defines for sw_mode_t
 */
/** @{ */
#define SW_RUN_OFF		0x0U		    /*!< Run mode: OFF */
#define SW_RUN_PWM		0x1U		    /*!< Run mode: PWM */
#define SW_RUN_PFM		0x2U		    /*!< Run mode: PFM */
#define SW_RUN_ASM		0x3U		    /*!< Run mode: ASM */
#define SW_STBY_OFF		(0x0U << 2U)	/*!< Standby mode: OFF */
#define SW_STBY_PWM		(0x1U << 2U)	/*!< Standby mode: PWM */
#define SW_STBY_PFM		(0x2U << 2U)	/*!< Standby mode: PFM */
#define SW_STBY_ASM		(0x3U << 2U)	/*!< Standby mode: ASM */
/** @} */

/*!
 * @name Defines for ldo_mode_t
 */
/** @{ */
#define RUN_OFF_STBY_OFF	0x0U /*!< Run mode: OFF,  Standby mode: OFF */
#define RUN_OFF_STBY_EN		0x1U /*!< Run mode: OFF,  Standby mode: ON  */
#define RUN_EN_STBY_OFF		0x2U /*!< Run mode: ON,   Standby mode: OFF */
#define RUN_EN_STBY_EN		0x3U /*!< Run mode: ON,   Standby mode: ON  */
#define VSELECT_EN			0x8U /*!< Enable VSELECT input pin for LDO 2 only */
/** @} */

/*!
 * @name Defines for vmode_reg_t
 */
/** @{ */
#define REG_STBY_MODE		0U
#define REG_RUN_MODE		1U
/** @} */

/*!
 * This type is used to indicate which register to address.
 *
 * Refer to the PF8100 Datasheet for the description of register.
 */
typedef uint8_t pf8100_vregs_t;

/*!
 * This type is used to indicate a switching regulator mode.
 *
 * Refer to the PF8100 Datasheet for the description of each mode.
 *
 * These modes are used in combination to designate a run and standby mode
 * i.e. (SW_RUN_PWM | SW_STBY_OFF).
 */
typedef uint8_t sw_mode_t;

/*!
 * This type is used to indicate an LDO regulator mode.
 *
 * Refer to the PF8100 Datasheet for the description of each mode.
 */
typedef uint8_t ldo_mode_t;

/*!
 * This type is used to indicate a Switching regulator voltage setpoint
 *
 * Refer to the PF8100 Datasheet for the description of each mode.
 */
typedef uint8_t vmode_reg_t;

/* Functions prototypes */

/*!
 * This function returns the device ID and revision for the PF8100 PMIC.
 *
 *  @param[in]    id            I2C address of PMIC device
 *
 *  @return Returns a structure with the device ID and revision.
 */
pmic_version_t pf8100_get_pmic_version(pmic_id_t id);

/*!
 * This function sets the voltage of a corresponding voltage regulator for the
 * PF8100 PMIC.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator;
 *                              see [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[in]     vol_mv        New voltage setpoint for the regulator in millivolts
 * @param[in]     mode_to_set   Mode to set the voltage for run (RUN or STANDBY)
 *
 * @return Returns an error code (SC_ERR_NONE = success)

 * Note \a mode_to_set is SC_TRUE for RUN and SC_FALSE for STANDBY.
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t pf8100_pmic_set_voltage(pmic_id_t id, uint32_t pmic_reg, uint32_t vol_mv,
                    uint32_t mode_to_set);

/*!
 * This function gets the voltage on a corresponding voltage regulator for the
 * PF8100 PMIC.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator;
 *                              see [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[out]    vol_mv        pointer to return voltage in millivolts
 * @param[in]     mode_to_get   Mode to get the voltage for (RUN or STANDBY)
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Note \a mode_to_get is SC_TRUE for RUN and SC_FALSE for STANDBY.
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 */
sc_err_t pf8100_pmic_get_voltage(pmic_id_t id, uint32_t pmic_reg, uint32_t *vol_mv,
		uint32_t mode_to_get);

/*!
 * This function sets the mode of the specified regulator.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator;
                                see [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[in]     mode          mode to set the regulator;
 *                              see [sw_mode_t](@ref sw_mode_t)
 *                              and [ldo_mode_t](@ref ldo_mode_t)
 *
 * Note SW modes are used in combination to designate a run and standby mode
 * i.e. (SW_RUN_PWM | SW_STBY_OFF).
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t pf8100_pmic_set_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t mode);

/*!
 * This function gets the mode of the specified regulator.
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     pmic_reg      Register corresponding to regulator;
                                see [pf8100_vregs_t](@ref pf8100_vregs_t)
 * @param[out]     mode         pointer to return mode in raw hex form
 *
 * Note SW modes are used in combination to designate a run and standby mode
 * i.e. (SW_RUN_PWM | SW_STBY_OFF).
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 * - SC_ERR_FAIL if writing the register failed
 */
sc_err_t pf8100_pmic_get_mode(pmic_id_t id, uint32_t pmic_reg, uint32_t *mode);
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
uint32_t pf8100_get_pmic_temp(pmic_id_t id);

/*!
 * This function sets the temp alarm for the PMIC in Celsius
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in]     temp          Temperature to set the alarm
 *
 * Note the granularity for PF100 PMIC only allows the following
 * values:
 * 80
 * 95
 * 110
 * 125
 * 140
 * 155
 *
 * @return Returns the temperature that the alarm is set to in Celsius
 */
uint32_t pf8100_set_pmic_temp_alarm(pmic_id_t id, uint32_t temp);

/*
 * This function allows access to individual registers of the PF8100
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
sc_err_t pf8100_pmic_register_access(pmic_id_t id, uint32_t address,
    sc_bool_t read_write, uint8_t* value);

/*!
 * This function services the interrupt for the temp alarm
 *
 * @param[in]     id            I2C address of PMIC device
 *
 * @return Returns SC_TRUE if the temperature interrupt was cleared
 */
sc_bool_t pf8100_pmic_irq_service(pmic_id_t id);

/*
 * This function enables PF8100 internal WDOG configuration bits
 *
 * @param[in]     id                I2C address of PMIC device
 * @param[in]     wd_en             bool indicating to enable(SC_TRUE/1) or to
 *                                  ignore the wdog bit
 * @param[in]     stby_en           bool indicating whether to set(SC_TRUE/1) wdog stby en
 *                                  bit or ignore(SC_FALSE/0)
 * @param[in]     wdi_stby_active   bool indicating whether wdi stby active bit should be
 *                                  set(SC_TRUE/1) or ignored(SC_FALSE/0)
 *
 * @return Returns ar error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 *
 */
sc_err_t pf8100_pmic_wdog_enable(pmic_id_t id, sc_bool_t wd_en,
        sc_bool_t stby_en, sc_bool_t wdi_stby_active);

/*
 * This function disables PF8100 internal WDOG configuration bits
 *
 * @param[in]     id                I2C address of PMIC device
 * @param[in]     wd_dis            bool indicating to clear(SC_TRUE/1) or
 *                                  ignore wdog enable bit(SC_FALSE/0)
 * @param[in]     stby_en           bool indicating if stby enable bit will be
 *                                  cleared(SC_TRUE/1) or ignored(SC_FALSE/0)
 * @param[in]     wdi_stby_active   bool indicating whether to clear(SC_TRUE/1)
 *                                  or ignore(SC_FALSE/0) wdi_stby_active bit
 *
 * @return Returns ar error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 *
 */
sc_err_t pf8100_pmic_wdog_disable(pmic_id_t id, sc_bool_t wd_dis,
        sc_bool_t stby_en, sc_bool_t wdi_stby_active);
/*
 * This function sets the timeout of the PF8100 internal WDOG
 *
 * @param[in]     id            I2C address of PMIC device
 * @param[in,out] timeout         Desired timeout in ms. The function will
 *                              calculate next largest interval and return the
 *                              exact timeout value in ms.
 *
 * @return Returns ar error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 *
 */
sc_err_t pf8100_pmic_wdog_set_timeout(pmic_id_t id, uint32_t* timeout);

/*
 * This function services the PF8100 internal WDOG
 *
 * @param[in]     id            I2C address of PMIC device
 *
 * @return Returns ar error code (SC_ERR_NONE = success)
 *
 * Return errors:
 * - SC_ERR_PARM if invalid parameters
 *
 */
sc_err_t pf8100_pmic_wdog_service(pmic_id_t id);

#endif

/** @} */

