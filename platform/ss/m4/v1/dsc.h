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
 * @file
 *
 * File containing the subsystem specific DSC header info.
 *
 * @addtogroup M4_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_M4_DSC_H
#define SC_SS_M4_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_SS_POR                  REGBIT(0, 2)
#define RST_CORE                    REGBIT(0, 3)
#define RST_DEBUG                   REGBIT(0, 4)
/** @} */

/*!
 * @name SS GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_CM4_HCLK_MUX_SEL        REGBIT(0, 8)
#define GPR_CM4_HCLK_MUX_IN0        REGBIT(0, 9)
#define GPR_CM4_AXBS_STALL_REQUEST  REGBIT(0, 10)
#define GPR_CM4_REF_CLK_GATE        REGBIT(0, 11)
#define GPR_CM4_DBG_REQ             REGBIT(0, 12)
#define GPR_CM4_TX_EVENT_ENB        REGBIT(0, 13)
#define GPR_CM4_HCLK_ENB            REGBIT(0, 14)
#define GPR_SIM_BBS_LP_RUN_ACK_3V   REGBIT(0, 24)
#define GPR_SIM_BBS_HS_RUN_ACK_3V   REGBIT(0, 25)
#define GPR_SIM_SYS_RST_SRSL_WDOG   REGBIT(0, 26)
#define GPR_SIM_SYS_RST_SRSH_LOCKUP REGBIT(0, 27)
#define GPR_SIM_SYS_RST_SRSH_SW     REGBIT(0, 28)
#define GPR_SIM_SYS_RST_SRSH_UECC   REGBIT(0, 29)
#define GPR_SIM_RCM_VLLS_DETECT     REGBIT(0, 30)
#define GPR_SLEEP_HOLD_REQ          REGBIT(0, 31)
/** @} */

/*!
 * @name SS GPR Control 1 Bit Definitions
 */
/** @{ */
#define GPR_DBGPWRUPREQ             REGBIT(1, 45)
#define GPR_SYSPWRUPREQ             REGBIT(1, 46)
#define GPR_LPI2C1_IPG_STOP         REGBIT(1, 50)
#define GPR_LPI2C1_IPG_STOP_MODE    REGBIT(1, 51)
#define GPR_WDOG1_IPG_STOP          REGBIT(1, 53)
#define GPR_TPM1_IPG_STOP           REGBIT(1, 57)
#define GPR_LPUART1_IPG_STOP        REGBIT(1, 59)
#define GPR_LPUART1_IPG_STOP_MODE   REGBIT(1, 60)
/** @} */

/*!
 * @name SS GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_LP_STOP_MODE_LOWV_BBS0  REGBIT(0, 24)
#define GPS_LP_STOP_MODE_LOWV_BBS1  REGBIT(0, 25)
#define GPS_LP_STOP_MODE_LOWV_BBS2  REGBIT(0, 26)
#define GPS_LP_STOP_OPTION_BBS0     REGBIT(0, 28)
#define GPS_LP_STOP_OPTION_BBS1     REGBIT(0, 29)
#define GPS_CPU_SLEEP_DEEP_HOLD_ACK REGBIT(0, 31)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_CM4_CPU_SLEEPING        REGBIT64(1, 4)
#define IRQ_CM4_CPU_SLEEP_DEEP      REGBIT64(1, 5)
#define IRQ_CM4_AXBS_STALL_ACK      REGBIT64(1, 6)
#define IRQ_CM4_CPU_SYS_RESET_REQ   REGBIT64(1, 7)
#define IRQ_WDOG1_WDG_RSTO          REGBIT64(1, 8)
#define IRQ_CM4_CPU_LOCKUP          REGBIT64(1, 9)
#define IRQ_AWIC_REQ                REGBIT64(1, 10)
#define IRQ_CM4_UECC_ERR            REGBIT64(1, 11)
#define IRQ_BBS_SIM_BBS_LP_RUN_REQ  REGBIT64(1, 12)
#define IRQ_BBS_SIM_BBS_HS_RUN_REQ  REGBIT64(1, 13)
#define IRQ_LPI2C1_IPG_STOP_ACK     REGBIT64(1, 20)
#define IRQ_LPUART1_IPG_STOP_ACK    REGBIT64(1, 21)
#define IRQ_INTMUX_INT_OUT_ASYNC    REGBIT64(1, 24)
#define IRQ_MU_SIDEB                REGBIT64(1, 27)
/** @} */

#endif /* SC_SS_M4_DSC_H */

/** @} */

