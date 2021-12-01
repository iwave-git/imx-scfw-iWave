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

#ifndef DRV_SYSCTR_H
#define DRV_SYSCTR_H

/*!
 * @addtogroup sysctr_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_device_registers.h"

/* Defines */
#define SYSCTR_CNTCV_MARGIN             50U

/* SYSCTR counts at a rate of 8 MHz (125 nsec period).  Conversions
   to/from usec can be calculated using a shift:

    1 tick = 1/8 usec  --> ticks >> 3 = usec
    1 usec = 8 ticks --> usec << 3 = ticks
*/
#define SYSCTR_TICKS_TO_USEC(ticks)     ((ticks) >> 3U)
#define SYSCTR_USEC_TO_TICKS(usec)      ((usec) << 3U)
#define SYSCTR_TICKS_TO_USEC64(ticks)   (U64(ticks) >> 3ULL)
#define SYSCTR_USEC_TO_TICKS64(usec)    (U64(usec) << 3ULL)

/* Types */

/* Externs */

/* Functions */

/*!
 * @name System Counter Functions
 * @{
 */

/*!
 * This function initializes and enables the system counter.
 */
void SYSCTR_Init(void);

/*!
 * This function returns the system counter value as a 64-bit clock
 * cycle count.
 *
 * @return Returns the system counter value.
 */
uint64_t SYSCTR_GetCounter64(void);

/*!
 * This function returns the system counter value as a 32-bit clock
 * cycle count.
 *
 * @return Returns the system counter value.
 */
uint32_t SYSCTR_GetCounter32(void);

/*!
 * This function returns the system counter time in uS. The return
 * value is 64 bits.
 *
 * @return Returns the system counter value in uS.
 */
uint64_t SYSCTR_GetUsec64(void);

/*!
 * This function returns the system counter time in uS. The return
 * value is 32 bits.
 *
 * @return Returns the system counter value in uS.
 */
uint32_t SYSCTR_GetUsec32(void);

/*!
 * This function delays the indicated number of uS.
 *
 * @param[in]     usec        number of microseconds to delay
 */
void SYSCTR_TimeDelay(uint32_t usec);

/*!
 * This function configures the frequency mode of the system
 * counter.  The system counter supports high-frequency (8 MHz)
 * and low-frequency (32768 Hz) modes with a variable 
 * increment to maintain an effective 8 MHz counting rate.
 *
 * @param[in]     bLowFreq    flag to indicate low-frequency mode (SC_TRUE = low-frequency operation)     
 * @param[in]     bWaitAck    flag to wait for mode change (SC_TRUE = wait for mode change)      
 */
void SYSCTR_FreqMode(sc_bool_t bLowFreq, sc_bool_t bWaitAck);

/*!
 * This function waits for a pending frequency mode change
 * of the system counter.
 *
 * @param[in]     bLowFreq    flag to indicate low-frequency mode (SC_TRUE = low-frequency operation)     
 */
void SYSCTR_FreqModeWaitAck(sc_bool_t bLowFreq);

/*!
 * This function configures the system counter compare frame0 
 * to generate an IRQ (wake) event after the specified number of
 * microseconds.
 *
 * @param[in]     usec        number of microseconds until wake event
 */
void SYSCTR_WakeEnable(uint32_t usec);

/*!
 * This function configures the system counter compare frame1 
 * to generate an IRQ event after the specified number of
 * system counter ticks.
 *
 * @param[in]     usec        number of system counter ticks until the event
 */
void SYSCTR_Compare1Enable(uint64_t ticks);

/*!
 * This function clears and disables the system counter compare frame1 
 * IRQ event.
 */
void SYSCTR_Compare1Disable(void);

/** @} */

#endif /* DRV_SYSCTR_H */

/** @} */

