/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright (c) 1997 - 2016 Freescale Semiconductor, Inc.
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

/*!
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef SYSTEM_H
#define SYSTEM_H                        /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

/* Defines */

/* Reset requires 32 cycles of xtal24M to propagate.  SysTick clocked from
   ROSC will be used for delay.

   ROSC @ 200 MHz
*/
#define RESET_WAIT_ROSC_CYCLES   (((SC_ROSC_FREQ_HZ / SC_XTAL24M_FREQ_HZ) + 1U) * 32U)

/*  Define delay for top-level top-level SSI power switch chains.  
  */
#define SYSCTR_NSEC_TO_CYCLES(nsec)     ((((nsec) * SC_MCU_STARTUP_FREQ_MHZ) + 999U) / 1000U)
#define SSI_CHAIN_LF_CYCLES             (SYSCTR_NSEC_TO_CYCLES(500U))
#define SSI_CHAIN_HF_CYCLES             (SYSCTR_NSEC_TO_CYCLES(2000U))

/* OSC24M lock spec unknown, use conservative 4ms */
#define OSC24M_WAIT_ROSC_CYCLES  (4*SC_ROSC_FREQ_HZ/1000U)

/* Address for environment event trigger */
#define SC_ENV_TRIG_ADDR        0x2000FFF0U

/* Query to determine if firmware loaded by ROM */
#ifndef SIMU
#define SCFW_LOADED_BY_ROM      ((DSC_SC->GPR_CTRL[0].RW & BIT(31)))
#else
#define SCFW_LOADED_BY_ROM      (0x80000000U)
#endif

/* Query to determine boot mode
 * BOOT_MODE[7:0] tied to DSC.GPR_STAT[0] bits [23:16] 
 */
#define SC_BOOT_MODE            ((DSC_SC->GPR_STAT[0].RW & 0x00FF0000U) >> 16U)

/* BOOT_MODE = Infinite loop mode = bXXXX1110 = 0x0E */
#define SC_BOOT_MODE_INF_LOOP   0x0EU

/* Margin to wake system early from LLS for WDOG servicing */
#define SC_WAKE_MARGIN_MSEC     5U

#ifdef DEBUG
extern uint32_t __DEBUG_DATA[];
#define SCFW_DBG_READY      (__DEBUG_DATA[0])
#define SCFW_DBG_SKIPS      (__DEBUG_DATA[1])
#define SCFW_DBG_DUMP_PTR   (&(__DEBUG_DATA[2]))
#define SCFW_DBG_DUMP_R0    (__DEBUG_DATA[2])
#define SCFW_DBG_DUMP_R1    (__DEBUG_DATA[3])
#define SCFW_DBG_DUMP_R2    (__DEBUG_DATA[4])
#define SCFW_DBG_DUMP_R3    (__DEBUG_DATA[5])
#define SCFW_DBG_DUMP_R12   (__DEBUG_DATA[6])
#define SCFW_DBG_DUMP_LR    (__DEBUG_DATA[7])
#define SCFW_DBG_DUMP_PC    (__DEBUG_DATA[8])
#define SCFW_DBG_DUMP_PSR   (__DEBUG_DATA[9])
#define SCFW_DBG_SCTR_TICKS (__DEBUG_DATA[10])
#define SCFW_DBG_RSVD0      (__DEBUG_DATA[11])
#define SCFW_DBG_TX_PTR     (&__DEBUG_DATA[12])
#define SCFW_DBG_RX_PTR     (&__DEBUG_DATA[13])
#endif

#define SC_ENV_TRIG_DUMP 0xc0ffee10U   //!< Start dump
#define SC_ENV_TRIG_KILL 0xc0ffee20U   //!< Kill execution

/* Types */

/*!
 * This type is used to indicate the trigger event.
 */
typedef uint32_t sc_env_trig_event_t;

/**
 * @brief Generate environment event trigger
 *
 */
void SystemEventTrigger (sc_env_trig_event_t event);

/**
 * @brief Enter firmware critical section.
 *
 */
void SystemEnterCS(void);

/**
 * @brief Exit firmware critical section.
 *
 */
void SystemExitCS(void);

/**
 * @brief Get active exception.
 *
 */
uint32_t SystemGetActiveException(void);

/**
 * @brief Setup the microcontroller system.
 *
 * Typically this function configures the oscillator (PLL) that is part of the
 * microcontroller device. For systems with variable clock speed it also updates
 * the variable SystemCoreClock. SystemInit is called from startup_device file.
 */
void SystemInit(void);

void SystemInitPostCRT(void);

/**
 * @brief Prepares to enter Low-Power Mode (LPM)
 *
 */
void SystemPrepareLPM(void);

void SystemEnterLPM(void);

/**
 * @brief Delays the specified number of usec
 *
 */
void SystemTimeDelay(uint32_t usec);

void SystemDebugWaitAttach(void);

void CommonFault_Handler(uint32_t *sp);

void SystemDebugHalt(void);

void SystemExit(void);

void HardFault_Handler(uint32_t *sp);

void MemManage_Handler(uint32_t *sp);

void BusFault_Handler(uint32_t *sp);

void UsageFault_Handler(uint32_t *sp);

void SystemDebugResume(void);

#if defined(DEBUG) || defined(HAS_TEST)
uint32_t SystemMemoryProbe(void *addr, void *val, uint8_t width);
#endif

#ifdef __cplusplus
}
#endif

#endif  /* #if !defined(SYSTEM_H_) */
