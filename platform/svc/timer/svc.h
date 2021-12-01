/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2017-2020 NXP
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
 * @file  svc/timer/svc.h
 *
 * Header file containing the API for the System Controller (SC) Timer
 * function.
 *
 * @addtogroup TIMER_SVC
 * @{
 */
/*==========================================================================*/

#ifndef SC_TIMER_SVC_H
#define SC_TIMER_SVC_H

/* Includes */

#include "svc/timer/api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * @name Internal Functions
 * @{
 */

/*!
 * Internal SC function to initializes the TIMER service.
 *
 * @param[in]     api_phase   init phase
 *
 * Initializes the API if /a api_phase = SC_TRUE, otherwise initializes the HW
 * managed by the timer service. API must be initialized before anything
 * else is done with the service.
 */
void timer_init(sc_bool_t api_phase);

/*!
 * This function initializes a new partition.
 *
 * @param[in]     caller_pt   handle of caller partition
 * @param[in]     pt          handle of partition
 *
 * Note this function should only be called by the resource manager when
 * a new partition is allocated.
 */
void timer_init_part(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/*!
 * Internal SC function to set the watchdog timeout in milliseconds.
 *
 * @see sc_timer_set_wdog_timeout().
 */
sc_err_t timer_set_wdog_timeout(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t timeout);

/*!
 * Internal SC function to set the watchdog pre-timeout in milliseconds.
 *
 * @see sc_timer_set_wdog_pre_timeout().
 */
sc_err_t timer_set_wdog_pre_timeout(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t pre_timeout);

/*!
 * Internal SC function to set the watchdog window in milliseconds.
 *
 * @see sc_timer_set_wdog_window().
 */
sc_err_t timer_set_wdog_window(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t window);

/*!
 * Internal SC function to start the watchdog.
 *
 * @see sc_timer_start_wdog().
 */
sc_err_t timer_start_wdog(sc_rm_pt_t caller_pt, sc_bool_t lock);

/*!
 * Internal SC function to stop the watchdog (if not locked).
 *
 * @see sc_timer_stop_wdog().
 */
sc_err_t timer_stop_wdog(sc_rm_pt_t caller_pt);

/*!
 * Internal SC function to stop halt the wdog when the partition is deleted.
 *
 * @param[in]     pt          partition whose wdog should be halted
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * This function will halt the wdog even if locked.
 */
void timer_halt_wdog(sc_rm_pt_t pt);

/*!
 * Internal SC function to ping (services, kicks) the watchdog resetting
 * the time before expiration back to the timeout.
 *
 * @see sc_timer_ping_wdog().
 */
sc_err_t timer_ping_wdog(sc_rm_pt_t caller_pt);

/*!
 * Internal SC function to get the status of the watchdog. All arguments
 * are in milliseconds.
 *
 * @see sc_timer_get_wdog_status().
 */
sc_err_t timer_get_wdog_status(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t *timeout, sc_timer_wdog_time_t *max_timeout,
    sc_timer_wdog_time_t *remaining_time);

/*!
 * Internal SC function to get the status of the watchdog of a partition.
 * All arguments are in milliseconds.
 *
 * @see sc_timer_pt_get_wdog_status().
 */
sc_err_t timer_pt_get_wdog_status(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_bool_t *enb, sc_timer_wdog_time_t *timeout,
    sc_timer_wdog_time_t *remaining_time);

/*!
 * Internal SC function to configure the action to be taken when a
 * watchdog expires.
 *
 * @see sc_timer_set_wdog_action().
 */
sc_err_t timer_set_wdog_action(sc_rm_pt_t caller_pt, 
    sc_rm_pt_t pt, sc_timer_wdog_action_t action);

/*!
 * Internal SC function to take the wdog action specified.
 *
 * @param[in]     pt          partition to affect
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Reboots the partition, board, and/or generate IRQs.
 */
sc_err_t timer_take_wdog_action(sc_rm_pt_t pt);

/*!
 * Internal SC function to set the RTC time.
 *
 * @see sc_timer_set_rtc_time().
 */
sc_err_t timer_set_rtc_time(sc_rm_pt_t caller_pt, uint16_t year, uint8_t mon,
    uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);

/*!
 * Internal SC function to get the RTC time.
 *
 * @see sc_timer_get_rtc_time().
 */
sc_err_t timer_get_rtc_time(sc_rm_pt_t caller_pt, uint16_t *year,
    uint8_t *mon, uint8_t *day, uint8_t *hour, uint8_t *min, uint8_t *sec);

/*!
 * Internal SC function to set the RTC alarm.
 *
 * @see sc_timer_set_rtc_alarm().
 */
sc_err_t timer_set_rtc_alarm(sc_rm_pt_t caller_pt, uint16_t year, uint8_t mon,
    uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);

/*!
 * Internal SC function to set a periodic RTC alarm.
 *
 * @see sc_timer_set_rtc_periodic_alarm().
 */
sc_err_t timer_set_rtc_periodic_alarm(sc_rm_pt_t caller_pt, uint32_t sec);

/*!
 * Internal SC function to cancel an RTC alarm.
 *
 * @see sc_timer_cancel_rtc_alarm().
 */
sc_err_t timer_cancel_rtc_alarm(sc_rm_pt_t caller_pt);

/*!
 * Internal SC function to query an RTC alarm.
 *
 * @param[in]     pt          partition to query
 * @param[out]    alarm       pointer to return alarm
 * @param[out]    period      pointer to return period
 *
 * Companion function to timer_restore_rtc_alarm().
 */
void timer_query_rtc_alarm(sc_rm_pt_t pt, uint32_t *alarm, 
    uint32_t *period);

/*!
 * Internal SC function to restore an RTC alarm.
 *
 * @param[in]     pt          partition to restore
 * @param[in]     alarm       alarm
 * @param[in]     period      period
 *
 * Companion function to timer_query_rtc_alarm().
 */
void timer_restore_rtc_alarm(sc_rm_pt_t pt, uint32_t alarm, 
    uint32_t period);

/*!
 * Internal SC function to get the RTC time in seconds since 1/1/1970.
 *
 * @see sc_timer_get_rtc_sec1970().
 */
sc_err_t timer_get_rtc_sec1970(sc_rm_pt_t caller_pt, uint32_t *sec);

/*!
 * Internal SC function to set the RTC calibration.
 *
 * @see sc_timer_set_rtc_calb().
 */
sc_err_t timer_set_rtc_calb(sc_rm_pt_t caller_pt, int8_t count);

/*!
 * Internal SC function to increment the RTC.
 */
void timer_tick(uint16_t msec);

/*!
 * Internal SC function to set the sysctr alarm.
 */
sc_err_t timer_set_sysctr_alarm(sc_rm_pt_t caller_pt, 
    uint64_t ticks);

/*!
 * Internal SC function to set the periodic sysctr alarm.
 */
sc_err_t timer_set_sysctr_periodic_alarm(sc_rm_pt_t caller_pt, 
    uint64_t ticks);

/*!
 * Internal SC function to cancel the sysctr alarm.
 */
sc_err_t timer_cancel_sysctr_alarm(sc_rm_pt_t caller_pt);

/** @} */

#if defined(DEBUG) && defined(DEBUG_TIMER)
   /*!
     * @name Debug Functions
     * @{
     */

    /*!
     * Internal SC function to dump the internal state of the timer service.
     *
     * @param[in]     pt          partition to dump
     */
    void timer_dump(sc_rm_pt_t pt);

    /** @} */
#endif

#endif /* SC_TIMER_SVC_H */

/** @} */

