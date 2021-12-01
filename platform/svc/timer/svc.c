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
 * @file  svc/timer/svc.c
 *
 * File containing the implementation of the System Controller (SC) Timer
 * function.
 *
 * @addtogroup TIMER_SVC
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "main/board.h"
#include "svc/timer/svc.h"
#include "svc/rm/svc.h"
#include "ss/inf/inf.h"
#include "drivers/snvs/fsl_snvs.h"
#ifdef HAS_SECO
#include "drivers/seco/fsl_seco.h"
#endif
#include "drivers/sysctr/fsl_sysctr.h"

/* Local Defines */

#define MAX_TIMEOUT     (UINT32_MAX - 1U)    //!< Max Timeout

#define EPOCH           1970U
#define LEAP_YEAR(X)    ((!U2B((X) % 4U) && U2B((X) % 100U)) || !U2B((X) % 400U))
#define MIN_SECS        60U
#define HOUR_SECS       (60U * MIN_SECS)
#define DAY_SECS        (24U * HOUR_SECS)
#define YEAR_DAYS(X)    (LEAP_YEAR(X) ? 366U : 365U)

/* Local Types */

/*!
 * This type is used to store dynamic info needed to track partition
 * specific data for the watchdog service.
 */
typedef struct
{
    uint64_t sysctr_alarm;
    uint64_t sysctr_period;
    sc_timer_wdog_time_t wdog_time;
    sc_timer_wdog_time_t wdog_timeout;
    sc_timer_wdog_time_t wdog_window;
    sc_timer_wdog_time_t wdog_pre_timeout;
    uint32_t rtc_alarm;
    uint32_t rtc_period;
    sc_timer_wdog_action_t action       : SC_TIMER_ACTION_W;
    sc_bool_t wdog_enabled              : SC_BOOL_W;
    sc_bool_t wdog_locked               : SC_BOOL_W;
} timer_part_data_t;

/* Local Functions */

static void update_alarm(void);
static void update_sysctr(void);
static uint32_t epoc2secs(uint16_t year, uint8_t mon, uint8_t day,
    uint8_t hour, uint8_t min, uint8_t sec);
static void notify_wdog_children(sc_rm_pt_t pt);

/* Local Variables */

/*! Array of days in months */
static const uint8_t days_in_month[2][12] =
{
    { 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U },
    { 31U, 29U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U }
};

#if defined(SC_FAKE_RTC)
    /*! Fake RTC seconds */
    static uint32_t rtc_seconds;
    /*! Fake RTC milliseconds */
    static uint32_t rtc_mseconds;
    /*! Fake RTC seconds */
#endif

/*!
 * @name Local Variables (not initialized)
 *
 * @{
 */
static timer_part_data_t timer_part_data[SC_RM_NUM_PARTITION];
/** @} */

/*--------------------------------------------------------------------------*/
/* Init the timer service                                                   */
/*--------------------------------------------------------------------------*/
void timer_init(sc_bool_t api_phase)
{
    if (api_phase != SC_FALSE)
    {
        sc_rm_pt_t p;

        /* All partitions disabled */
        for (p = 0; p < SC_RM_NUM_PARTITION; p++)
        {
            timer_init_part(SC_PT, p);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Initialize a new partition                                               */
/*--------------------------------------------------------------------------*/
void timer_init_part(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    /* Init partition wdog data */
    timer_part_data[pt].wdog_enabled = SC_FALSE;
    timer_part_data[pt].wdog_locked= SC_FALSE;
    timer_part_data[pt].wdog_timeout = MAX_TIMEOUT;
    timer_part_data[pt].wdog_window = 0U;
    timer_part_data[pt].wdog_pre_timeout = MAX_TIMEOUT;

    /* Init partition RTC data */
    timer_part_data[pt].rtc_alarm = UINT32_MAX;
    timer_part_data[pt].rtc_period = 0U;

    /* Init partition system counter data */
    timer_part_data[pt].sysctr_alarm = UINT64_MAX;
    timer_part_data[pt].sysctr_period = 0ULL;

    /* Check for SCU PT */
    if (pt == SC_PT)
    {
        /* Action is to reboot partition */
        timer_part_data[pt].action = SC_TIMER_WDOG_ACTION_PARTITION;
    }
    else
    {
        sc_rm_pt_t parent = rm_get_partition_parent(pt);

        /* Action defaults to that of parent */
        timer_part_data[pt].action = timer_part_data[parent].action;
    }
}

/*--------------------------------------------------------------------------*/
/* Set the timeout in mS (if not locked)                                    */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_wdog_timeout(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t timeout)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check permissions */
    ASRT_ERR(timer_part_data[caller_pt].wdog_locked == SC_FALSE,
        SC_ERR_LOCKED)

    if (err == SC_ERR_NONE)
    {
        /* Update */
        timer_part_data[caller_pt].wdog_timeout = timeout;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the pre-timeout in mS (if not locked)                                */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_wdog_pre_timeout(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t pre_timeout)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(pre_timeout <= MAX_TIMEOUT, SC_ERR_PARM)

    if (err == SC_ERR_NONE)
    {
        /* Update */
        timer_part_data[caller_pt].wdog_pre_timeout = pre_timeout;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the timeout in mS (if not locked)                                    */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_wdog_window(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t window)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check permissions */
    ASRT_ERR(timer_part_data[caller_pt].wdog_locked == SC_FALSE,
        SC_ERR_LOCKED)

    if (err == SC_ERR_NONE)
    {
        /* Update */
        timer_part_data[caller_pt].wdog_window = window;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Start the watchdog                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t timer_start_wdog(sc_rm_pt_t caller_pt, sc_bool_t lock)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check permissions */
    ASRT_ERR(rm_is_partition_isolated(caller_pt) != SC_FALSE,
        SC_ERR_NOACCESS);
    ASRT_ERR(timer_part_data[caller_pt].wdog_enabled == SC_FALSE,
        SC_ERR_BUSY);

    if (err == SC_ERR_NONE)
    {
        /* Update */
        timer_part_data[caller_pt].wdog_time = 0U;
        timer_part_data[caller_pt].wdog_enabled = SC_TRUE;
        timer_part_data[caller_pt].wdog_locked = lock;
    }

     return err;
}

/*--------------------------------------------------------------------------*/
/* Stop the watchdog (if not locked)                                        */
/*--------------------------------------------------------------------------*/
sc_err_t timer_stop_wdog(sc_rm_pt_t caller_pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check permissions */
    ASRT_ERR(timer_part_data[caller_pt].wdog_locked == SC_FALSE,
        SC_ERR_LOCKED)

    if (err == SC_ERR_NONE)
    {
        /* Update */
        timer_part_data[caller_pt].wdog_enabled = SC_FALSE;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Halt and reset watchdog even if locked                                   */
/*--------------------------------------------------------------------------*/
void timer_halt_wdog(sc_rm_pt_t pt)
{
    /* Reset wdog */
    timer_part_data[pt].wdog_enabled = SC_FALSE;
    timer_part_data[pt].wdog_time = 0U;
    timer_part_data[pt].wdog_timeout = MAX_TIMEOUT;
    timer_part_data[pt].wdog_window = 0U;
    timer_part_data[pt].wdog_pre_timeout = MAX_TIMEOUT;
    timer_part_data[pt].wdog_locked = SC_FALSE;

    /* Reset wdog action */
    timer_part_data[pt].action = SC_TIMER_WDOG_ACTION_PARTITION;
}

/*--------------------------------------------------------------------------*/
/* Ping (kick) the watchdog                                                 */
/*--------------------------------------------------------------------------*/
sc_err_t timer_ping_wdog(sc_rm_pt_t caller_pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Reboot/notify if timeout expired */
        if (timer_part_data[caller_pt].wdog_time 
            < timer_part_data[caller_pt].wdog_window)
        {
            timer_part_data[caller_pt].wdog_enabled = SC_FALSE;
        
            err = timer_take_wdog_action(caller_pt);
        }

        /* Ping virtual timer */
        timer_part_data[caller_pt].wdog_time = 0U;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the watchdog status (all times in mS)                                */
/*--------------------------------------------------------------------------*/
sc_err_t timer_get_wdog_status(sc_rm_pt_t caller_pt,
    sc_timer_wdog_time_t *timeout, sc_timer_wdog_time_t *max_timeout,
    sc_timer_wdog_time_t *remaining_time)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Return data */
        if (timeout != NULL)
        {
            *timeout = timer_part_data[caller_pt].wdog_timeout;
        }

        if (max_timeout != NULL)
        {
            *max_timeout = MAX_TIMEOUT;
        }

        if (remaining_time != NULL)
        {
            *remaining_time = timer_part_data[caller_pt].wdog_timeout 
            - timer_part_data[caller_pt].wdog_time;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get a partition watchdog status (all times in mS)                        */
/*--------------------------------------------------------------------------*/
sc_err_t timer_pt_get_wdog_status(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_bool_t *enb, sc_timer_wdog_time_t *timeout,
    sc_timer_wdog_time_t *remaining_time)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    if (err == SC_ERR_NONE)
    {
        /* Return data */
        if (enb != NULL)
        {
            *enb = timer_part_data[pt].wdog_enabled;
        }

        if (timeout != NULL)
        {
            *timeout = timer_part_data[pt].wdog_timeout;
        }

        if (remaining_time != NULL)
        {
            *remaining_time = timer_part_data[pt].wdog_timeout 
            - timer_part_data[pt].wdog_time;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Configure the action to be taken when a watchdog expires                 */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_wdog_action(sc_rm_pt_t caller_pt, 
    sc_rm_pt_t pt, sc_timer_wdog_action_t action)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    ASRT_ERR(action <= SC_TIMER_WDOG_ACTION_IRQ, SC_ERR_PARM)

    /* Check permissions */
    SYSTEM(caller_pt);
    ASRT_ERR((pt != SC_PT) || (caller_pt == SC_PT), SC_ERR_NOACCESS)

    /* Check if locked */
    ASRT_ERR(timer_part_data[pt].wdog_locked == SC_FALSE,
        SC_ERR_LOCKED)

    /* Set action */
    if (err == SC_ERR_NONE)
    {
        timer_part_data[pt].action = action;
    }
    
    return err;
}

/*--------------------------------------------------------------------------*/
/* Reboot partition or board depending on action                            */
/*--------------------------------------------------------------------------*/
sc_err_t timer_take_wdog_action(sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx;
    sc_rm_pt_t system_pt;

    switch (timer_part_data[pt].action)
    {
        case SC_TIMER_WDOG_ACTION_PARTITION :
            err = pm_reboot_part(pt, pt, SC_PM_RESET_TYPE_COLD,
                SC_PM_RESET_REASON_WDOG, SC_PM_PW_MODE_OFF);
            break;
        case SC_TIMER_WDOG_ACTION_WARM :
            err = board_reset(SC_PM_RESET_TYPE_WARM, SC_PM_RESET_REASON_WDOG,
                pt);
            break;
        case SC_TIMER_WDOG_ACTION_COLD :
            err = board_reset(SC_PM_RESET_TYPE_COLD, SC_PM_RESET_REASON_WDOG,
                pt);
            break;
        case SC_TIMER_WDOG_ACTION_BOARD :
            err = board_reset(SC_PM_RESET_TYPE_BOARD, SC_PM_RESET_REASON_WDOG,
                pt);
            break;
        case SC_TIMER_WDOG_ACTION_IRQ :
            /* Notify parent */
            ss_irq_trigger(SC_IRQ_GROUP_WDOG, 
                BIT(rm_get_partition_parent(pt)), SC_PT_ALL);
            
            /* Notify SYSTEM */
            if (rm_check_map_ridx(SC_R_SYSTEM, &idx) != SC_FALSE)
            {
                rm_get_ridx_owner(idx, &system_pt);
                if (system_pt != rm_get_partition_parent(pt))
                {
                    ss_irq_trigger(SC_IRQ_GROUP_WDOG,
                        BIT(system_pt), SC_PT_ALL);
                }
            }
            break;
        default :
            ; /* Intentional empty default */
            break;                    
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the RTC time                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_rtc_time(sc_rm_pt_t caller_pt, uint16_t year, uint8_t mon,
    uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(year >= EPOCH, SC_ERR_PARM)
    ASRT_ERR((mon >= 1U) && (mon <= 12U), SC_ERR_PARM)
    ASRT_ERR((day >= 1U) && (day <= 31U), SC_ERR_PARM)
    ASRT_ERR(hour < 24U, SC_ERR_PARM)
    ASRT_ERR(min < 60U, SC_ERR_PARM)
    ASRT_ERR(sec < 60U, SC_ERR_PARM)

    /* Check permissions */
    SYSTEM(caller_pt);

    /* Convert to seconds since epoc */
    if (err == SC_ERR_NONE)
    {
        uint32_t seconds;
        uint32_t secs = 0U;

        seconds = epoc2secs(year, mon, day, hour, min, sec);

        /* Dump for debug */
        timer_print(3, "Time = %u\n", seconds);

        /* Read from the RTC */
        #if defined(SC_FAKE_RTC)
            secs = rtc_seconds;
        #else
            SNVS_GetRtc(&secs);
        #endif

        /* Update periodic alarms */
        for (sc_rm_pt_t p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            if (timer_part_data[p].rtc_period != 0U)
            {
                timer_part_data[p].rtc_alarm =
                    timer_part_data[p].rtc_alarm
                    - secs + seconds;
            }
        }

        /* Program into the RTC */
        #if defined(SC_FAKE_RTC)
            rtc_seconds = seconds;
            rtc_mseconds = 0U;
        #else
            SNVS_SetRtc(seconds);
            err = snvs_err;
            if (err == SC_ERR_NONE)
            {
                SNVS_Functional_IRQHandler();
            }
        #endif
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the RTC time                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t timer_get_rtc_time(sc_rm_pt_t caller_pt, uint16_t *year,
    uint8_t *mon, uint8_t *day, uint8_t *hour, uint8_t *min, uint8_t *sec)
{
    sc_err_t err = SC_ERR_NONE;
    uint32_t secs;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Read from the RTC */
    if (err == SC_ERR_NONE)
    {
        #if defined(SC_FAKE_RTC)
            secs = rtc_seconds;
        #else
            SNVS_GetRtc(&secs);
            err = snvs_err;
        #endif
    }

    if (err == SC_ERR_NONE)
    {
        uint32_t days;
        uint32_t daytime;

        /* Figure out time */
        daytime = secs % DAY_SECS;
        *hour = U8(daytime / HOUR_SECS);
        *min = U8((daytime % HOUR_SECS) / MIN_SECS);
        *sec = U8(daytime % MIN_SECS);

        /* Figure out year */
        days = secs / DAY_SECS;
        *year = EPOCH;
        while (days >= YEAR_DAYS((*year)))
        {
            days -= YEAR_DAYS((*year));
            (*year)++;
        }

        /* Figure out month */
        *mon = 0U;
        while (days >= days_in_month[B2U16(LEAP_YEAR(*year))][*mon])
        {
            days -= days_in_month[B2U16(LEAP_YEAR(*year))][*mon];
            (*mon)++;
        }
        *mon += 1U;
        *day = U8(days) + 1U;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the RTC alarm                                                        */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_rtc_alarm(sc_rm_pt_t caller_pt, uint16_t year,
    uint8_t mon, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(year >= EPOCH, SC_ERR_PARM)
    ASRT_ERR((mon >= 1U) && (mon <= 12U), SC_ERR_PARM)
    ASRT_ERR((day >= 1U) && (day <= 31U), SC_ERR_PARM)
    ASRT_ERR(hour < 24U, SC_ERR_PARM)
    ASRT_ERR(min < 60U, SC_ERR_PARM)
    ASRT_ERR(sec < 60U, SC_ERR_PARM)

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        uint32_t seconds;

        /* Convert to seconds since epoc */
        seconds = epoc2secs(year, mon, day, hour, min, sec);

        /* Dump for debug */
        timer_print(3, "Set RTC alarm = %u\n", seconds);

        /* Program into the RTC alarm */
        timer_part_data[caller_pt].rtc_alarm = seconds;
        timer_part_data[caller_pt].rtc_period = 0U;

        /* Update alarm */
        update_alarm();
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the RTC periodic alarm                                               */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_rtc_periodic_alarm(sc_rm_pt_t caller_pt, uint32_t sec)
{
    sc_err_t err = SC_ERR_NONE;
    uint32_t secs;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(sec != 0U, SC_ERR_PARM);

    if (err == SC_ERR_NONE)
    {
        /* Dump for debug */
        timer_print(3, "Set RTC periodic alarm = %u\n", sec);

        /* Read from the RTC */
        #if defined(SC_FAKE_RTC)
            secs = rtc_seconds;
        #else
            SNVS_GetRtc(&secs);
            err = snvs_err;
        #endif
    }

    if (err == SC_ERR_NONE)
    {
        uint32_t seconds;

        /* Program into the RTC alarm */
        seconds = secs + sec; 
        timer_part_data[caller_pt].rtc_alarm = seconds;
        timer_part_data[caller_pt].rtc_period = sec;

        update_alarm();
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Cancel RTC alarm                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t timer_cancel_rtc_alarm(sc_rm_pt_t caller_pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Program into the RTC alarm */
        timer_part_data[caller_pt].rtc_alarm = UINT32_MAX;
        timer_part_data[caller_pt].rtc_period = 0U;

        update_alarm();
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Query RTC alarm                                                          */
/*--------------------------------------------------------------------------*/
void timer_query_rtc_alarm(sc_rm_pt_t pt, uint32_t *alarm, 
    uint32_t *period)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(pt);

    if (err == SC_ERR_NONE)
    {
        /* Return RTC alarm data for the partition */
        *alarm = timer_part_data[pt].rtc_alarm;
        *period = timer_part_data[pt].rtc_period;
    }
}

/*--------------------------------------------------------------------------*/
/* Restore RTC alarm                                                        */
/*--------------------------------------------------------------------------*/
void timer_restore_rtc_alarm(sc_rm_pt_t pt, uint32_t alarm, 
    uint32_t period)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(pt);

    if (err == SC_ERR_NONE)
    {
        /* Restore RTC alarm data for the partition */
        timer_part_data[pt].rtc_alarm = alarm;
        timer_part_data[pt].rtc_period = period;

        update_alarm();
    }
}

/*--------------------------------------------------------------------------*/
/* Get the RTC time in seconds since 1/1/1970                               */
/*--------------------------------------------------------------------------*/
sc_err_t timer_get_rtc_sec1970(sc_rm_pt_t caller_pt, uint32_t *sec)
{
    /* Read from the RTC */
    #if defined(SC_FAKE_RTC)
        *sec = rtc_seconds;

        return SC_ERR_NONE;
    #else
        SNVS_GetRtc(sec);

        return snvs_err;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Set the RTC calibration                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_rtc_calb(sc_rm_pt_t caller_pt, int8_t count)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    ASRT_ERR(count >= -16, SC_ERR_PARM)
    ASRT_ERR(count <= 15, SC_ERR_PARM)

    /* Check permissions */
    SYSTEM(caller_pt);

    if (err == SC_ERR_NONE)
    {
        #if !defined(SC_FAKE_RTC)
            SNVS_SetRtcCalb(count);    
            SNVS_SetSecureRtcCalb(count);
            err = snvs_err;
        #else
            err = SC_ERR_UNAVAILABLE;
        #endif
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Tick timer services                                                      */
/*--------------------------------------------------------------------------*/
void timer_tick(uint16_t msec)
{
    sc_rm_pt_t p;

    #if defined(SC_FAKE_RTC)
        uint32_t sec;

        /* Tick fake RTC */
        rtc_mseconds += msec;
        sec = rtc_mseconds / 1000U;
        rtc_mseconds -= (sec * 1000U);
        rtc_seconds += sec;

        for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            if (rtc_seconds >= timer_part_data[p].rtc_alarm)
            {
                if (timer_part_data[p].rtc_period == 0U)
                {
                    timer_part_data[p].rtc_alarm = UINT32_MAX;
                }
                else
                {
                    timer_part_data[p].rtc_alarm = rtc_seconds
                        + timer_part_data[p].rtc_period;
                }
                ss_irq_trigger(SC_IRQ_GROUP_RTC, BIT(p), p);
                if (p == SC_PT)
                {
#ifdef HAS_SECO
                    SECO_KickWdog();
#endif
                }
            }
        }
    #endif

    /* Tick watchdogs */
    for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
    {
        if (timer_part_data[p].wdog_enabled != SC_FALSE)
        {
            timer_part_data[p].wdog_time += msec;

            /* Generate IRQ if pre-timeout expired */
            if (timer_part_data[p].wdog_time 
                >= timer_part_data[p].wdog_pre_timeout)
            {
                timer_part_data[p].wdog_pre_timeout = UINT32_MAX;
                notify_wdog_children(p);
            }

            /* Reboot/notify if timeout expired */
            if (timer_part_data[p].wdog_time 
                >= timer_part_data[p].wdog_timeout)
            {
                timer_part_data[p].wdog_enabled = SC_FALSE;

                (void) timer_take_wdog_action(p);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
/* RTC alarm ISR                                                            */
/*--------------------------------------------------------------------------*/
#if !defined(SC_FAKE_RTC)
    void SNVS_Functional_IRQHandler(void)
    {
        uint32_t seconds = UINT32_MAX;
        sc_rm_pt_t p;

        SNVS_GetRtc(&seconds);

        /* Notify users of alarm */
        for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            /* Alarm time expired? */
            if (seconds >= timer_part_data[p].rtc_alarm)
            {
                /* Handle one-shot alarm */
                if (timer_part_data[p].rtc_period == 0U)
                {
                    timer_part_data[p].rtc_alarm = UINT32_MAX;
                }
                else
                {
                    timer_part_data[p].rtc_alarm = seconds
                        + timer_part_data[p].rtc_period;
                }
                /* Trigger user interrupt */
                ss_irq_trigger(SC_IRQ_GROUP_RTC, BIT(p), p);
                if (p == SC_PT)
                {
#ifdef HAS_SECO
                    /* Service SECO watchdog */
                    SECO_KickWdog();
#endif
                }
            }
        }

        /* Configure next alarm (and clear) */
        update_alarm();
    }
#endif

/*--------------------------------------------------------------------------*/
/* Set the sysctr alarm                                                     */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_sysctr_alarm(sc_rm_pt_t caller_pt,  uint64_t ticks)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Program into the RTC alarm */
        timer_part_data[caller_pt].sysctr_alarm = ticks;
        timer_part_data[caller_pt].sysctr_period = 0ULL;

        update_sysctr();
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the periodic sysctr alarm                                            */
/*--------------------------------------------------------------------------*/
sc_err_t timer_set_sysctr_periodic_alarm(sc_rm_pt_t caller_pt, 
    uint64_t ticks)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(ticks != 0ULL, SC_ERR_PARM);

    if (err == SC_ERR_NONE)
    {
        /* Program into the SYSCTR alarm */
        timer_part_data[caller_pt].sysctr_alarm = SYSCTR_GetCounter64() +
            ticks;
        timer_part_data[caller_pt].sysctr_period = ticks;

        update_sysctr();
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Cancel the sysctr alarm                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t timer_cancel_sysctr_alarm(sc_rm_pt_t caller_pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Program into the RTC alarm */
        timer_part_data[caller_pt].sysctr_alarm = UINT64_MAX;
        timer_part_data[caller_pt].sysctr_period = 0ULL;

        update_sysctr();
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* SYSCTR alarm ISR                                                         */
/*--------------------------------------------------------------------------*/
void SYSCTR_CMP1_IRQHandler(void)
{
    uint64_t ticks;
    sc_rm_pt_t p;
    
    ticks = SYSCTR_GetCounter64();
    
    /* Notify users of alarm */
    for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
    {
        if (ticks >= timer_part_data[p].sysctr_alarm)
        {
            if (timer_part_data[p].sysctr_period == 0ULL)
            {
                timer_part_data[p].sysctr_alarm = UINT64_MAX;
            }
            else
            {
                timer_part_data[p].sysctr_alarm = ticks
                    + timer_part_data[p].sysctr_period;
            }
            if (p != SC_PT)
            {
                ss_irq_trigger(SC_IRQ_GROUP_SYSCTR, BIT(p), p);
            }
            else
            {
                pm_reboot_continue_all();
            }
        }
    }
    
    /* Configure next alarm (and clear) */
    #ifndef NO_DEVICE_ACCESS
        SYSCTR_Compare1Disable();
    #endif
    update_sysctr();
}

/*--------------------------------------------------------------------------*/
/* Dump timer state for debug                                               */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG) && defined(DEBUG_TIMER)
    void timer_dump(sc_rm_pt_t pt)
    {
        sc_err_t err = SC_ERR_NONE;

        /* Check if partition enabled */
        USED_PT(pt);

        if ((debug != SC_FALSE) && (err == SC_ERR_NONE))
        {
            /* Dump data */
            #if defined(SC_FAKE_RTC)
                if (pt == 0U)
                {
                    timer_print(2, "    RTC (fake): %u.%03u\n", rtc_seconds,
                        rtc_mseconds);
                }
            #endif
            timer_print(2, "    Partition: %u\n", pt);
            timer_print(2, "        Wdog time: %u\n",
                timer_part_data[pt].wdog_time);
            timer_print(2, "        Wdog timeout: %u\n",
                timer_part_data[pt].wdog_timeout);
            timer_print(2, "        Wdog pre-timeout: %u\n",
                timer_part_data[pt].wdog_pre_timeout);
            timer_print(2, "        Wdog flags:\n");
            if (timer_part_data[pt].wdog_enabled != SC_FALSE)
            {
                timer_print(2, "            Enabled\n");
            }
            if (timer_part_data[pt].wdog_locked != SC_FALSE)
            {
                timer_print(2, "            Locked\n");
            }
        }
    }
#endif

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Update RTC alarm                                                         */
/*--------------------------------------------------------------------------*/
static void update_alarm(void)
{
    #if !defined(SC_FAKE_RTC)
        sc_rm_pt_t p;
        uint32_t secs;
        uint32_t seconds = UINT32_MAX;

        /* Get current RTC */
        SNVS_GetRtc(&secs);
        
        /* Search for next time */
        for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            /* Alarm time passed? */
            if (timer_part_data[p].rtc_alarm <= secs)
            {
                /* Periodic? */
                if (timer_part_data[p].rtc_period == 0U)
                {
                    /* Cancel */
                    timer_part_data[p].rtc_alarm = UINT32_MAX;
                }
                else
                {
                    /* Next period */
                    timer_part_data[p].rtc_alarm = seconds
                        + timer_part_data[p].rtc_period;
                }

                /* Trigger interrupt */
                ss_irq_trigger(SC_IRQ_GROUP_RTC, BIT(p), p);                
            }
            else
            {
                /* Earlier time? */
                seconds = MIN(seconds, timer_part_data[p].rtc_alarm);
            }
        }

        SNVS_SetRtcAlarm(seconds);
    #endif
}

/*--------------------------------------------------------------------------*/
/* Update sysctr alarm                                                      */
/*--------------------------------------------------------------------------*/
static void update_sysctr(void)
{
    sc_rm_pt_t p;
    uint64_t ticks = UINT64_MAX;
    
    /* Search for next time */
    for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
    {
        /* Earlier time? */
        ticks = MIN(ticks, timer_part_data[p].sysctr_alarm);
    }

#ifndef NO_DEVICE_ACCESS
    /* Found a time? */
    if (ticks != UINT64_MAX)
    {
        /* Enable counter compare */
        SYSCTR_Compare1Enable(ticks);
    }
    else
    {
        /* Disable counter compare */
        SYSCTR_Compare1Disable();
    }
#endif
}

/*--------------------------------------------------------------------------*/
/* Convert date/time to seconds since epoc                                  */
/*--------------------------------------------------------------------------*/
static uint32_t epoc2secs(uint16_t year, uint8_t mon, uint8_t day,
    uint8_t hour, uint8_t min, uint8_t sec)
{
    uint32_t secs = 0U;
    uint8_t new_mon = mon;
    uint16_t new_year = year;

    /* Add time */
    secs += U32(hour) * HOUR_SECS;
    secs += U32(min) * MIN_SECS;
    secs += U32(sec);

    /* Add month */
    new_mon--;
    while (new_mon > 0U)
    {
        secs += days_in_month[B2U16(LEAP_YEAR(new_year))][new_mon - 1U]
            * DAY_SECS;
        new_mon--;
    }

    /* Add day */
    secs += (U32(day) - 1U) * DAY_SECS;

    /* Add year */
    new_year--;
    while (new_year >= EPOCH)
    {
        secs += YEAR_DAYS(new_year) * DAY_SECS;
        new_year--;
    }

    return secs;
}

/*--------------------------------------------------------------------------*/
/* Generate a WDOG IRQ to a partition and all children                      */
/*--------------------------------------------------------------------------*/
static void notify_wdog_children(sc_rm_pt_t pt)
{
    sc_rm_pt_t p;

    /* Notify children */
    for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
    {
        if (rm_get_partition_parent(p) == pt)
        {
            notify_wdog_children(p);
        }
    }

    /* Notify parent */
    ss_irq_trigger(SC_IRQ_GROUP_WDOG, BIT(pt),
        SC_PT_ALL);
}

/** @} */

