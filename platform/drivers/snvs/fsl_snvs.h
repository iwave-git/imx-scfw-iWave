/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
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

#ifndef DRV_SNVS_H
#define DRV_SNVS_H

/*!
 * @addtogroup snvs_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"

/* Defines */

/*!
 * @name Defines for snvs_btn_config_t
 *
 * Used to configure which feature of the button (BTN) input signal
 * constitutes "active".
 *
 * BTN_CONFIG field in the SNVS_HP register. See the SNVS section
 * of the SRM.
 */
/** @{ */
#define SNVS_DRV_BTN_CONFIG_ACTIVELOW       0U      /*!< Button signal is active low */
#define SNVS_DRV_BTN_CONFIG_ACTIVEHIGH      1U      /*!< Button signal is active high */
#define SNVS_DRV_BTN_CONFIG_RISINGEDGE      2U      /*!< Button signal is active on the rising edge */
#define SNVS_DRV_BTN_CONFIG_FALLINGEDGE     3U      /*!< Button signal is active on the falling edge */
#define SNVS_DRV_BTN_CONFIG_ANYEDGE         4U      /*!< Button signal is active on any edge */
/** @} */

/*!
 * @name Defines for snvs_btn_on_time_t
 *
 * Used to configure the period of time after BTN is asserted before
 * SoC power is turned on.
 *
 * ON_TIME field in the SNVS_LP register. See the SNVS section
 * of the SRM.
 */
/** @{ */
#define SNVS_DRV_BTN_ON_50MS                0U      /*!< 500 msec off->on transition time */
#define SNVS_DRV_BTN_ON_100MS               1U      /*!< 50 msec off->on transition time */
#define SNVS_DRV_BTN_ON_500MS               2U      /*!< 100 msec off->on transition time */
#define SNVS_DRV_BTN_ON_0MS                 3U      /*!< 0 msec off->on transition time */
/** @} */

/*!
 * @name Defines for snvs_btn_debounce_t
 *
 * Use to configure the amount of debounce time for the BTN input signal.
 *
 * DEBOUNCE field in the SNVS_LP register. See the SNVS section
 * of the SRM.
 */
/** @{ */
#define SNVS_DRV_BTN_DEBOUNCE_50MS          0U      /*!< 50 msec debounce */
#define SNVS_DRV_BTN_DEBOUNCE_100MS         1U      /*!< 100 msec debounce */
#define SNVS_DRV_BTN_DEBOUNCE_500MS         2U      /*!< 500 msec debounce */
#define SNVS_DRV_BTN_DEBOUNCE_0MS           3U      /*!< 0 msec debounce */
/** @} */

/*!
 * @name Defines for snvs_btn_press_time_t
 *
 * Used to configure the button press time out values for the PMIC logic.
 *
 * BTN_PRESS_TIME field in the SNVS_LP register. See the SNVS section
 * of the SRM.
 */
/** @{ */
#define SNVS_DRV_BTN_PRESS_5S               0U      /*!< 5 secs */
#define SNVS_DRV_BTN_PRESS_10S              1U      /*!< 10 secs */
#define SNVS_DRV_BTN_PRESS_15S              2U      /*!< 15 secs */
#define SNVS_DRV_BTN_PRESS_OFF              3U      /*!< Long press disabled */
/** @} */

/* Types */

/*!
 * This type is used configure the button active state.
 */
typedef uint8_t snvs_btn_config_t;

/*!
 * This type is used configure the button on time.
 */
typedef uint8_t snvs_btn_on_time_t;

/*!
 * This type is used configure the button debounce time.
 */
typedef uint8_t snvs_btn_debounce_t;

/*!
 * This type is used configure the button press time.
 */
typedef uint8_t snvs_btn_press_time_t;

/* SNVS Functions */

/*!
 * @name Initialization Functions
 * @{
 */

/*!
 * @brief Initialize SNVS driver.
 *
 * This function initializes the SNVS driver.
 *
 * @param phase    init phase
 */
void SNVS_Init(boot_phase_t phase);

/** @} */

/*!
 * @name SRTC Functions
 * @{
 */

/*!
 * @brief Power off system.
 *
 * This function asserts the signal to the PMIC to force a power off.
 */
void SNVS_PowerOff(void);

/*!
 * @brief Set the secure RTC.
 *
 * This function sets the secure RTC.
 *
 * @param seconds   time to set
 */
void SNVS_SetSecureRtc(uint32_t seconds);

/*!
 * @brief Get the secure RTC.
 *
 * This function returns the secure RTC time.
 *
 * @param seconds   pointer to return seconds
 */
void SNVS_GetSecureRtc(uint32_t *seconds);

/*!
 * @brief Set the secure RTC calibration value.
 *
 * This function sets the secure RTC calibration value.
 * See the SNVS section of the SRM for more info.
 *
 * @param count   counts to add/subtract per 32768 ticks
 */
void SNVS_SetSecureRtcCalb(int8_t count);

/*!
 * @brief Get the secure RTC calibration value.
 *
 * This function returns the secure RTC calibration value.
 * See the SNVS section of the SRM for more info.
 *
 * @param count   pointer to return count
 */
void SNVS_GetSecureRtcCalb(int8_t *count);

/*!
 * @brief Set secure RTC alarm.
 *
 * This function sets the secure RTC alarm and enables it.
 *
 * @param seconds   alarm to set
 *
 * If seconds=UINT32_MAX then disable alarm.
 */
void SNVS_SetSecureRtcAlarm(uint32_t seconds);

/*!
 * @brief Get secure RTC alarm.
 *
 * This function returns the secure RTC alarm.
 *
 * @param seconds   pointer to return alarm
 */
void SNVS_GetSecureRtcAlarm(uint32_t *seconds);

/*!
 * @brief Set the RTC.
 *
 * This function sets the RTC.
 *
 * @param seconds   time to set
 */
void SNVS_SetRtc(uint32_t seconds);

/*!
 * @brief Get the RTC.
 *
 * This function returns the RTC time.
 *
 * @param seconds   pointer to return seconds
 */
void SNVS_GetRtc(uint32_t *seconds);

/*!
 * @brief Set the RTC calibration value.
 *
 * This function sets the RTC calibration value.
 * See the SNVS section of the SRM for more info.
 *
 * @param count   counts to add/subtract per 32768 ticks
 */
void SNVS_SetRtcCalb(int8_t count);

/*!
 * @brief Set RTC alarm.
 *
 * This function sets the RTC alarm and enables it.
 *
 * @param seconds   alarm to set
 *
 * If seconds=UINT32_MAX then disable alarm.
 */
void SNVS_SetRtcAlarm(uint32_t seconds);

/*!
 * @brief Get RTC alarm.
 *
 * This function returns the RTC alarm.
 *
 * @param seconds   pointer to return alarm
 */
void SNVS_GetRtcAlarm(uint32_t *seconds);

/*!
 * @brief Configure the ON/OFF button.
 *
 * This function configures the button detection and IRQ.
 * See the SNVS section of the SRM for more info.
 *
 * @param config   button configuration (see BTN_CONFIG in SRM)
 * @param enable   button IRQ enable (see BTN_MASK in SRM)
 *
 * For info on the arguments, see the SNVS section of the SRM.
 */
void SNVS_ConfigButton(snvs_btn_config_t config, sc_bool_t enable);

/*!
 * @brief Configure the ON/OFF button timing parameters.
 *
 * This function configures the button timing parameters.
 * See the SNVS section of the SRM for more info.
 *
 * @param on       button turn on time (see ON_TIME in SRM)
 * @param debounce button debounce time (see DEBOUNCE in SRM)
 * @param press    button turn off time (see BTN_PRESS_TIME in SRM)
 *
 * For info on the arguments, see the SNVS section of the SRM.
 */
void SNVS_ButtonTime(snvs_btn_on_time_t on, snvs_btn_debounce_t debounce,
    snvs_btn_press_time_t press);

/*!
 * @brief Get button status.
 *
 * This function returns the status of the button.
 * See the SNVS section of the SRM for more info. BTN in HPSR.
 *
 * @return Returns the button status.
 */
sc_bool_t SNVS_GetButtonStatus(void);

/*!
 * @brief Clear button IRQ.
 *
 * This function clears a pending button IRQ.
 */
void SNVS_ClearButtonIRQ(void);

/*!
 * @brief Enter low power mode.
 *
 * This function prepares the SNVS for low power mode. It copies various data
 * from the HP section to the LP section.
 */
void SNVS_EnterLPM(void);

/*!
 * @brief Exit low power mode.
 *
 * This function restores SNVS data from the LP section to the HP section.
 */
void SNVS_ExitLPM(void);

/*!
 * @brief Get the SNVS System Security Monitor State (SSM). 
 *
 * This function returns the System Security Monitor State (SSM).
 * See the SNVS section of the SRM for more info. SSM_ST in HPSR.
 *
 * @return Returns the state of the monitor.
 */
uint32_t SNVS_GetState(void);

/*!
 * @brief Enable SNVS Security Violation Interrupt.
 *
 * This function is used to re-enable the security violation interrupt. The
 * interrupt is automatically masked when the interrupt occurs.
 */
void SNVS_SecurityViolation_Enable(void);

/*!
 * @brief SNVS security violation IRQ handler.
 *
 * This function is called when the security violation IRQ is asserted. It
 * automatically masks the security violation interrupt which must then be
 * re-enabled using SNVS_SecurityViolation_Enable().
 */
void SNVS_SecurityViolation_IRQHandler(void);

/*!
 * @brief SNVS power off IRQ handler.
 *
 * This function is called when the power off IRQ is asserted.
 */
void SNVS_PowerOff_IRQHandler(void);

/*!
 * @brief Read a GP register.
 *
 * This function is called to read one of the four LPGPR[0-3]. Note that
 * SECO and SCFW may use some of these so only a limited number may be available
 * for cusotmer use. See the [Porting Guide](@ref PORT_SNVS).
 *
 * @param idx      index of register to read (0-3)
 *
 * @return Returns the stored value.
 */
uint32_t SNVS_ReadGP(uint8_t idx);

/*!
 * @brief Write a GP register.
 *
 * @param idx      index of register to write (0-3)
 * @param val      value to write
 *
 * This function is called write to one of the four LPGPR[0-3]. Note that
 * SECO and SCFW may use some of these so only a limited number may be available
 * for cusotmer use. See the [Porting Guide](@ref PORT_SNVS).
 */
void SNVS_WriteGP(uint8_t idx, uint32_t val);

/*!
 * @brief Manage security violation and tamper.
 *
 * @param id       index of register(s) to access
 * @param access   read or write
 * @param data0    value 0 to read or write
 * @param data1    value 1 to read or write
 * @param data2    value 2 to read or write
 * @param data3    value 3 to read or write
 * @param data4    value 4 to read or write
 * @param size     number of value to access
 *
 * Set dataX to NULL if not used.
 *
 * This function is called to read/write security violation and
 * tamper registers. See the SECO API Reference Guide for more info.
 */
void SNVS_SecVio(uint8_t id, uint8_t access, uint32_t *data0,
    uint32_t *data1, uint32_t *data2, uint32_t *data3,  uint32_t *data4,
    uint8_t size);

/*!
 * @brief Manage security violation and tamper of DGO.
 *
 * @param id       index of register to access
 * @param access   read or write
 * @param data     value to read or write
 *
 * This function is called to read/write security violation and
 * tamper DGO registers. See the SECO API Reference Guide for more info.
 */
void SNVS_SecVioDgo(uint8_t id, uint8_t access, uint32_t *data);

#ifdef SIMU
/*!
 * @brief Simulation function to increment time.
 *
 * @param secs  seconds to increment
 */
void SNVS_IncTime(uint32_t secs);
#endif

/* Externs */

/*! SNVS error return */
extern sc_err_t snvs_err;

/** @} */

#endif /* DRV_SNVS_H */

/** @} */

