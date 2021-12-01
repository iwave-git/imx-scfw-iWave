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
 * @addtogroup LSIO_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_LSIO_DSC_H
#define SC_SS_LSIO_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_SWAP                    REGBIT(0, 14)
#define GPR_SWAP_MASK               REGBIT(0, 23)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_GPIO0                   REGBIT64(1, 0)
#define IRQ_GPIO1                   REGBIT64(1, 1)
#define IRQ_GPIO2                   REGBIT64(1, 2)
#define IRQ_GPIO3                   REGBIT64(1, 3)
#define IRQ_GPIO4                   REGBIT64(1, 4)
#define IRQ_GPIO5                   REGBIT64(1, 5)
#define IRQ_GPIO6                   REGBIT64(1, 6)
#define IRQ_GPIO7                   REGBIT64(1, 7)
#define IRQ_GPT0                    REGBIT64(1, 8)
#define IRQ_GPT1                    REGBIT64(1, 9)
#define IRQ_GPT2                    REGBIT64(1, 10)
#define IRQ_GPT3                    REGBIT64(1, 11)
#define IRQ_GPT4                    REGBIT64(1, 12)
#define IRQ_KPP                     REGBIT64(1, 13)
#define IRQ_PWM0                    REGBIT64(1, 14)
#define IRQ_PWM1                    REGBIT64(1, 15)
#define IRQ_PWM2                    REGBIT64(1, 16)
#define IRQ_PWM3                    REGBIT64(1, 17)
#define IRQ_PWM4                    REGBIT64(1, 18)
#define IRQ_PWM5                    REGBIT64(1, 19)
#define IRQ_PWM6                    REGBIT64(1, 20)
#define IRQ_PWM7                    REGBIT64(1, 21)
#define IRQ_MU_SIDEB                REGBIT64(1, 27)
/** @} */

/*!
 * @name CSR 0x00 Bit Definitions
 */
/** @{ */
#define CSR_GPT0_IPG_STOP           REGBIT(0x0, 0)
#define CSR_GPT1_IPG_STOP           REGBIT(0x0, 1)
#define CSR_GPT2_IPG_STOP           REGBIT(0x0, 2)
#define CSR_GPT3_IPG_STOP           REGBIT(0x0, 3)
#define CSR_GPT4_IPG_STOP           REGBIT(0x0, 4)
#define CSR_PWM0_IPG_STOP           REGBIT(0x0, 5)
#define CSR_PWM1_IPG_STOP           REGBIT(0x0, 6)
#define CSR_PWM2_IPG_STOP           REGBIT(0x0, 7)
#define CSR_PWM3_IPG_STOP           REGBIT(0x0, 8)
#define CSR_PWM4_IPG_STOP           REGBIT(0x0, 9)
#define CSR_PWM5_IPG_STOP           REGBIT(0x0, 10)
#define CSR_PWM6_IPG_STOP           REGBIT(0x0, 11)
#define CSR_PWM7_IPG_STOP           REGBIT(0x0, 12)
/** @} */


/*!
 * @name CSR 0x10 Bit Definitions
 */
/** @{ */
#define CSR_FSPI0_IPG_STOP          REGBIT(0x1, 0)
#define CSR_FSPI1_IPG_STOP          REGBIT(0x1, 1)
#define CSR_MU5A_IPG_STOP           REGBIT(0x1, 2)
#define CSR_MU6A_IPG_STOP           REGBIT(0x1, 3)
#define CSR_MU7A_IPG_STOP           REGBIT(0x1, 4)
#define CSR_MU8A_IPG_STOP           REGBIT(0x1, 5)
#define CSR_MU9A_IPG_STOP           REGBIT(0x1, 6)
#define CSR_MU10A_IPG_STOP          REGBIT(0x1, 7)
#define CSR_MU11A_IPG_STOP          REGBIT(0x1, 8)
#define CSR_MU12A_IPG_STOP          REGBIT(0x1, 9)
#define CSR_MU13A_IPG_STOP          REGBIT(0x1, 10)
#define CSR_MU5B_IPG_STOP           REGBIT(0x1, 11)
#define CSR_MU6B_IPG_STOP           REGBIT(0x1, 12)
#define CSR_MU7B_IPG_STOP           REGBIT(0x1, 13)
#define CSR_MU8B_IPG_STOP           REGBIT(0x1, 14)
#define CSR_MU9B_IPG_STOP           REGBIT(0x1, 15)
#define CSR_MU10B_IPG_STOP          REGBIT(0x1, 16)
#define CSR_MU11B_IPG_STOP          REGBIT(0x1, 17)
#define CSR_MU12B_IPG_STOP          REGBIT(0x1, 18)
#define CSR_MU13B_IPG_STOP          REGBIT(0x1, 19)
/** @} */

/*!
 * @name CSR 0x20 Bit Definitions
 */
/** @{ */
#define CSR_GPT0_IPG_WAIT           REGBIT(0x2, 0)
#define CSR_GPT1_IPG_WAIT           REGBIT(0x2, 1)
#define CSR_GPT2_IPG_WAIT           REGBIT(0x2, 2)
#define CSR_GPT3_IPG_WAIT           REGBIT(0x2, 3)
#define CSR_GPT4_IPG_WAIT           REGBIT(0x2, 4)
#define CSR_PWM0_IPG_WAIT           REGBIT(0x2, 5)
#define CSR_PWM1_IPG_WAIT           REGBIT(0x2, 6)
#define CSR_PWM2_IPG_WAIT           REGBIT(0x2, 7)
#define CSR_PWM3_IPG_WAIT           REGBIT(0x2, 8)
#define CSR_PWM4_IPG_WAIT           REGBIT(0x2, 9)
#define CSR_PWM5_IPG_WAIT           REGBIT(0x2, 10)
#define CSR_PWM6_IPG_WAIT           REGBIT(0x2, 11)
#define CSR_PWM7_IPG_WAIT           REGBIT(0x2, 12)
/** @} */

/*!
 * @name CSR 0x30 Bit Definitions
 */
/** @{ */
#define CSR_MU5A_IPG_WAIT           REGBIT(0x3, 2)
#define CSR_MU6A_IPG_WAIT           REGBIT(0x3, 3)
#define CSR_MU7A_IPG_WAIT           REGBIT(0x3, 4)
#define CSR_MU8A_IPG_WAIT           REGBIT(0x3, 5)
#define CSR_MU9A_IPG_WAIT           REGBIT(0x3, 6)
#define CSR_MU10A_IPG_WAIT          REGBIT(0x3, 7)
#define CSR_MU11A_IPG_WAIT          REGBIT(0x3, 8)
#define CSR_MU12A_IPG_WAIT          REGBIT(0x3, 9)
#define CSR_MU13A_IPG_WAIT          REGBIT(0x3, 10)
#define CSR_MU5B_IPG_WAIT           REGBIT(0x3, 11)
#define CSR_MU6B_IPG_WAIT           REGBIT(0x3, 12)
#define CSR_MU7B_IPG_WAIT           REGBIT(0x3, 13)
#define CSR_MU8B_IPG_WAIT           REGBIT(0x3, 14)
#define CSR_MU9B_IPG_WAIT           REGBIT(0x3, 15)
#define CSR_MU10B_IPG_WAIT          REGBIT(0x3, 16)
#define CSR_MU11B_IPG_WAIT          REGBIT(0x3, 17)
#define CSR_MU12B_IPG_WAIT          REGBIT(0x3, 18)
#define CSR_MU13B_IPG_WAIT          REGBIT(0x3, 19)
/** @} */

/*!
 * @name CSR 0x40 Bit Definitions
 */
/** @{ */
#define CSR_GPT0_IPG_DOZE           REGBIT(0x4, 0)
#define CSR_GPT1_IPG_DOZE           REGBIT(0x4, 1)
#define CSR_GPT2_IPG_DOZE           REGBIT(0x4, 2)
#define CSR_GPT3_IPG_DOZE           REGBIT(0x4, 3)
#define CSR_GPT4_IPG_DOZE           REGBIT(0x4, 4)
#define CSR_PWM0_IPG_DOZE           REGBIT(0x4, 5)
#define CSR_PWM1_IPG_DOZE           REGBIT(0x4, 6)
#define CSR_PWM2_IPG_DOZE           REGBIT(0x4, 7)
#define CSR_PWM3_IPG_DOZE           REGBIT(0x4, 8)
#define CSR_PWM4_IPG_DOZE           REGBIT(0x4, 9)
#define CSR_PWM5_IPG_DOZE           REGBIT(0x4, 10)
#define CSR_PWM6_IPG_DOZE           REGBIT(0x4, 11)
#define CSR_PWM7_IPG_DOZE           REGBIT(0x4, 12)
/** @} */

/*!
 * @name CSR 0x50 Bit Definitions
 */
/** @{ */
#define CSR_FSPI0_IPG_DOZE          REGBIT(0x5, 0)
#define CSR_FSPI1_IPG_DOZE          REGBIT(0x5, 1)
/** @} */

/*!
 * @name CSR 0x70 Definitions
 */
/** @{ */
#define CSR_MU5A_IPG_DSM            REGBIT(0x7, 2)
#define CSR_MU6A_IPG_DSM            REGBIT(0x7, 3)
#define CSR_MU7A_IPG_DSM            REGBIT(0x7, 4)
#define CSR_MU8A_IPG_DSM            REGBIT(0x7, 5)
#define CSR_MU9A_IPG_DSM            REGBIT(0x7, 6)
#define CSR_MU10A_IPG_DSM           REGBIT(0x7, 7)
#define CSR_MU11A_IPG_DSM           REGBIT(0x7, 8)
#define CSR_MU12A_IPG_DSM           REGBIT(0x7, 9)
#define CSR_MU13A_IPG_DSM           REGBIT(0x7, 10)
#define CSR_MU5B_IPG_DSM            REGBIT(0x7, 11)
#define CSR_MU6B_IPG_DSM            REGBIT(0x7, 12)
#define CSR_MU7B_IPG_DSM            REGBIT(0x7, 13)
#define CSR_MU8B_IPG_DSM            REGBIT(0x7, 14)
#define CSR_MU9B_IPG_DSM            REGBIT(0x7, 15)
#define CSR_MU10B_IPG_DSM           REGBIT(0x7, 16)
#define CSR_MU11B_IPG_DSM           REGBIT(0x7, 17)
#define CSR_MU12B_IPG_DSM           REGBIT(0x7, 18)
#define CSR_MU13B_IPG_DSM           REGBIT(0x7, 19)
/** @} */

/*!
 * @name CSR 0x80 Bit Definitions
 */
/** @{ */
#define CSR_GPT0_IPG_DEBUG          REGBIT(0x8, 0)
#define CSR_GPT1_IPG_DEBUG          REGBIT(0x8, 1)
#define CSR_GPT2_IPG_DEBUG          REGBIT(0x8, 2)
#define CSR_GPT3_IPG_DEBUG          REGBIT(0x8, 3)
#define CSR_GPT4_IPG_DEBUG          REGBIT(0x8, 4)
#define CSR_PWM0_IPG_DEBUG          REGBIT(0x8, 5)
#define CSR_PWM1_IPG_DEBUG          REGBIT(0x8, 6)
#define CSR_PWM2_IPG_DEBUG          REGBIT(0x8, 7)
#define CSR_PWM3_IPG_DEBUG          REGBIT(0x8, 8)
#define CSR_PWM4_IPG_DEBUG          REGBIT(0x8, 9)
#define CSR_PWM5_IPG_DEBUG          REGBIT(0x8, 10)
#define CSR_PWM6_IPG_DEBUG          REGBIT(0x8, 11)
#define CSR_PWM7_IPG_DEBUG          REGBIT(0x8, 12)
/** @} */

/*!
 * @name CSR 0xB0 Bit Definitions
 */
/** @{ */
#define CSR_FSPI0_IPG_STOP_ACK      REGBIT(0xB, 0)
#define CSR_FSPI1_IPG_STOP_ACK      REGBIT(0xB, 1)
/** @} */

/*!
 * @name CSR 0xC0 Bit Definitions
 */
/** @{ */
#define CSR_GPT0_32K_SYNC           REGBIT(0xC, 0)
#define CSR_GPT1_32K_SYNC           REGBIT(0xC, 1)
#define CSR_GPT2_32K_SYNC           REGBIT(0xC, 2)
#define CSR_GPT3_32K_SYNC           REGBIT(0xC, 3)
#define CSR_GPT4_32K_SYNC           REGBIT(0xC, 4)
#define CSR_PWM0_32K_SYNC           REGBIT(0xC, 5)
#define CSR_PWM1_32K_SYNC           REGBIT(0xC, 6)
#define CSR_PWM2_32K_SYNC           REGBIT(0xC, 7)
#define CSR_PWM3_32K_SYNC           REGBIT(0xC, 8)
#define CSR_PWM4_32K_SYNC           REGBIT(0xC, 9)
#define CSR_PWM5_32K_SYNC           REGBIT(0xC, 10)
#define CSR_PWM6_32K_SYNC           REGBIT(0xC, 11)
#define CSR_PWM7_32K_SYNC           REGBIT(0xC, 12)
/** @} */

/*!
 * @name CSR 0xD0 Bit Definitions
 */
/** @{ */
#define CSR_OCRAM_RD_ADDR_PIPE      REGBIT(0xD, 0)
#define CSR_OCRAM_RD_DATA_WAIT      REGBIT(0xD, 1)
#define CSR_OCRAM_WR_ADDR_PIPE      REGBIT(0xD, 2)
#define CSR_OCRAM_WR_DATA_PIPE      REGBIT(0xD, 3)
/** @} */

/*!
 * @name CSR 0xE0 Bit Definitions
 */
/** @{ */
#define CSR_OCRAM_RD_ADDR_PIPE_PEND REGBIT(0xE, 0)
#define CSR_OCRAM_RD_DATA_WAIT_PEND REGBIT(0xE, 1)
#define CSR_OCRAM_WR_ADDR_PIPE_PEND REGBIT(0xE, 2)
#define CSR_OCRAM_WR_DATA_PIPE_PEND REGBIT(0xE, 3)
/** @} */

#if (defined(FSL_FEATURE_DSC_HAS_PER_RESET) && FSL_FEATURE_DSC_HAS_PER_RESET)
/*!
 * @name ECSR 0x00 Reset Bit Definitions
 */
/** @{ */
#define CSR_PWM0_RESET              REGBIT8(0x0, 0)
#define CSR_PWM1_RESET              REGBIT8(0x0, 1)
#define CSR_PWM2_RESET              REGBIT8(0x0, 2)
#define CSR_PWM3_RESET              REGBIT8(0x0, 3)
#define CSR_PWM4_RESET              REGBIT8(0x0, 4)
#define CSR_PWM5_RESET              REGBIT8(0x0, 5)
#define CSR_PWM6_RESET              REGBIT8(0x0, 6)
#define CSR_PWM7_RESET              REGBIT8(0x0, 7)
#define CSR_GPIO0_RESET             REGBIT8(0x0, 8)
#define CSR_GPIO1_RESET             REGBIT8(0x0, 9)
#define CSR_GPIO2_RESET             REGBIT8(0x0, 10)
#define CSR_GPIO3_RESET             REGBIT8(0x0, 11)
#define CSR_GPIO4_RESET             REGBIT8(0x0, 12)
#define CSR_GPIO5_RESET             REGBIT8(0x0, 13)
#define CSR_GPIO6_RESET             REGBIT8(0x0, 14)
#define CSR_GPIO7_RESET             REGBIT8(0x0, 15)
#define CSR_GPT0_RESET              REGBIT8(0x0, 16)
#define CSR_GPT1_RESET              REGBIT8(0x0, 17)
#define CSR_GPT2_RESET              REGBIT8(0x0, 18)
#define CSR_GPT3_RESET              REGBIT8(0x0, 19)
#define CSR_GPT4_RESET              REGBIT8(0x0, 20)
/** @} */

/*!
 * @name ECSR 0x01 Reset Bit Definitions
 */
/** @{ */
#define CSR_MU5_RESET               REGBIT8(0x1, 0)
#define CSR_MU6_RESET               REGBIT8(0x1, 1)
#define CSR_MU7_RESET               REGBIT8(0x1, 2)
#define CSR_MU8_RESET               REGBIT8(0x1, 3)
#define CSR_MU9_RESET               REGBIT8(0x1, 4)
#define CSR_MU10_RESET              REGBIT8(0x1, 5)
#define CSR_MU11_RESET              REGBIT8(0x1, 6)
#define CSR_MU12_RESET              REGBIT8(0x1, 7)
#define CSR_MU13_RESET              REGBIT8(0x1, 8)
#define CSR_FSPI0_RESET             REGBIT8(0x1, 9)
#define CSR_IEE_RESET               REGBIT8(0x1, 10)
/** @} */
#endif

#endif /* SC_SS_LSIO_DSC_H */

/** @} */

