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

#ifndef DRV_SYSTICK_H
#define DRV_SYSTICK_H

/*!
 * @addtogroup systick_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_device_registers.h"
#include "fsl_clock.h"

/* Defines */
#define SYSTICK_TICKS_PER_USEC  (SC_MCU_STARTUP_FREQ_MHZ)
#define SYSTICK_MAX_TICKS       (SysTick_VAL_CURRENT_Msk)
#define SYSTICK_MAX_DELAY_USEC  (50U*1000U)   // 50 msec

#if ((SYSTICK_MAX_DELAY_USEC*SYSTICK_TICKS_PER_USEC) > SYSTICK_MAX_TICKS)
#error "SYSTICK_MAX_DELAY_USEC exceeds SYSTICK_MAX_TICKS"
#endif


/* Types */


/* Externs */


/* Functions */


/*!
 * @name System Timer (SysTick) Functions
 * @{
 */

void SYSTICK_Init(void);
void SYSTICK_CycleDelay(uint32_t cycles);
void SYSTICK_TimeDelay(uint32_t usec);
void SYSTICK_TimeDelayVar(uint32_t usec, uint32_t ticksPerUsec);
uint32_t SYSTICK_GetCounter32(void);
uint32_t SYSTICK_TickDiff32(uint32_t cntStart, uint32_t cntEnd);
uint32_t SYSTICK_NsecDiff(uint32_t cntStart, uint32_t cntEnd, uint32_t tickPsec);


/** @} */


#endif /* DRV_SYSTICK_H */

/** @} */

