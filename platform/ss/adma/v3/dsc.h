/*
** ###################################################################
**
**     Copyright 2018-2020 NXP
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
 * @addtogroup ADMA_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_ADMA_DSC_H
#define SC_SS_ADMA_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_SS_DSP              REGBIT(0, 2)
#define RST_SS_DSP_CORE         REGBIT(0, 3)
#define RST_SS_DSP_DEBUG        REGBIT(0, 4)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_OBS_SEL0                REGBIT(0, 8)
#define GPR_OBS_SEL1                REGBIT(0, 9)
#define GPR_OBS_SEL2                REGBIT(0, 10)
#define GPR_OBS_SEL3                REGBIT(0, 11)
#define GPR_ADB_GIC_PWRDNREQN       REGBIT(0, 24)
#define GPR_ADB_DSP_PWRDNREQN0      REGBIT(0, 25)
#define GPR_ADB_DSP_PWRDNREQN1      REGBIT(0, 26)
#define GPR_LCDIF_CACHEABLE         REGBIT(0, 29)
#define GPR_AUDIO_EDMA_CACHEABLE    REGBIT(0, 30)
#define GPR_PERIPH_EDMA_CACHEABLE   REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Control 1 Bit Definitions
 */
/** @{ */
#define GPR_DMA_CLOCK_RATIO0        REGBIT(1, 32)
#define GPR_DMA_CLOCK_RATIO1        REGBIT(1, 33)
#define GPR_DMA_CLOCK_RATIO_ENB     REGBIT(1, 34)
#define GPR_DSP_DMA_BYPASS          REGBIT(1, 35)
#define GPR_DMA01_DSP_BYPASS        REGBIT(1, 36)
#define GPR_DMA23_DSP_BYPASS        REGBIT(1, 37)
#define GPR_PIXEL_RATE_CORR         REGBIT(1, 38)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_ADB_GIC_PWRDNACKN       REGBIT(0, 16)
#define GPS_ADB_GIC_CACTIVES        REGBIT(0, 17)
#define GPS_ADB_GIC_CACTIVEM        REGBIT(0, 18)
#define GPS_ADB_DSP_PWRDNACKN0      REGBIT(0, 25)
#define GPS_ADB_DSP_CACTIVES0       REGBIT(0, 26)
#define GPS_ADB_DSP_CACTIVEM0       REGBIT(0, 27)
#define GPS_ADB_DSP_PWRDNACKN1      REGBIT(0, 29)
#define GPS_ADB_DSP_CACTIVES1       REGBIT(0, 30)
#define GPS_ADB_DSP_CACTIVEM1       REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Status 1 Bit Definitions
 */
/** @{ */
#define GPS_OBS_OUT                 REGBIT(1, 32)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_GIC_WAKE00              REGBIT64(1, 0)
#define IRQ_GIC_WAKE01              REGBIT64(1, 1)
#define IRQ_GIC_WAKE02              REGBIT64(1, 2)
#define IRQ_GIC_WAKE03              REGBIT64(1, 3)
#define IRQ_IRQSTR_CTI0             REGBIT64(1, 8)
#define IRQ_IRQSTR_CTI1             REGBIT64(1, 9)
#define IRQ_IRQSTR_CTI2             REGBIT64(1, 10)
#define IRQ_IRQSTR_CTI3             REGBIT64(1, 11)
#define IRQ_IRQSTR_CTI4             REGBIT64(1, 12)
#define IRQ_GIC_ECC_FATAL           REGBIT64(1, 13)
#define IRQ_LPI2C0                  REGBIT64(1, 15)
#define IRQ_LPI2C1                  REGBIT64(1, 16)
#define IRQ_LPI2C2                  REGBIT64(1, 17)
#define IRQ_LPI2C3                  REGBIT64(1, 18)
#define IRQ_LPSPI0                  REGBIT64(1, 19)
#define IRQ_LPSPI1                  REGBIT64(1, 20)
#define IRQ_LPSPI2                  REGBIT64(1, 21)
#define IRQ_LPSPI3                  REGBIT64(1, 22)
#define IRQ_LPUART0                 REGBIT64(1, 23)
#define IRQ_LPUART1                 REGBIT64(1, 24)
#define IRQ_LPUART2                 REGBIT64(1, 25)
#define IRQ_LPUART3                 REGBIT64(1, 26)
#define IRQ_ADC0                    REGBIT64(1, 27)
/** @} */

/*!
 * @name CSR2 0x00 Bit Definitions
 */
/** @{ */
#define CSR2_DSP_EXPSTATE           REGBIT(0x0, 0)
/** @} */

/*!
 * @name CSR2 0x01 Bit Definitions
 */
/** @{ */
#define CSR2_DSP_IMPWIRE            REGBIT(0x1, 0)
/** @} */

/*!
 * @name CSR2 0x02 Bit Definitions
 */
/** @{ */
#define CSR2_DSP_PRID               REGBIT(0x2, 0)
/** @} */

/*!
 * @name CSR2 0x30 Bit Definitions
 */
/** @{ */
#define CSR2_DSP_OCDHALTONRESET     REGBIT(0x3, 0)
#define CSR2_DSP_RUNSTALL           REGBIT(0x3, 1)
#define CSR2_DSP_STATVECTORSEL      REGBIT(0x3, 2)
/** @} */

/*!
 * @name CSR2 0x40 Bit Definitions
 */
/** @{ */
/** @} */

/*!
 * @name CSR3 0x00 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA2_IPG_DEBUG        REGBIT(0x0, 0)
#define CSR3_EDMA3_IPG_DEBUG        REGBIT(0x0, 1)
#define CSR3_SPI0_IPG_DEBUG         REGBIT(0x0, 3)
#define CSR3_SPI1_IPG_DEBUG         REGBIT(0x0, 4)
#define CSR3_SPI2_IPG_DEBUG         REGBIT(0x0, 5)
#define CSR3_SPI3_IPG_DEBUG         REGBIT(0x0, 6)
#define CSR3_I2C0_IPG_DEBUG         REGBIT(0x0, 17)
#define CSR3_I2C1_IPG_DEBUG         REGBIT(0x0, 18)
#define CSR3_I2C2_IPG_DEBUG         REGBIT(0x0, 19)
#define CSR3_I2C3_IPG_DEBUG         REGBIT(0x0, 20)
#define CSR3_FTM0_IPG_DEBUG         REGBIT(0x0, 26)
#define CSR3_FTM1_IPG_DEBUG         REGBIT(0x0, 27)
#define CSR3_CAN0_IPG_DEBUG         REGBIT(0x0, 29)
#define CSR3_CAN1_IPG_DEBUG         REGBIT(0x0, 30)
#define CSR3_CAN2_IPG_DEBUG         REGBIT(0x0, 31)
/** @} */

/*!
 * @name CSR3 0x10 Bit Definitions
 */
/** @{ */
#define CSR3_SPI0_IPG_DOZE          REGBIT(0x1, 3)
#define CSR3_SPI1_IPG_DOZE          REGBIT(0x1, 4)
#define CSR3_SPI2_IPG_DOZE          REGBIT(0x1, 5)
#define CSR3_SPI3_IPG_DOZE          REGBIT(0x1, 6)
#define CSR3_UART0_IPG_DOZE         REGBIT(0x1, 8)
#define CSR3_UART1_IPG_DOZE         REGBIT(0x1, 9)
#define CSR3_UART2_IPG_DOZE         REGBIT(0x1, 10)
#define CSR3_UART3_IPG_DOZE         REGBIT(0x1, 11)
#define CSR3_I2C0_IPG_DOZE          REGBIT(0x1, 17)
#define CSR3_I2C1_IPG_DOZE          REGBIT(0x1, 18)
#define CSR3_I2C2_IPG_DOZE          REGBIT(0x1, 19)
#define CSR3_I2C3_IPG_DOZE          REGBIT(0x1, 20)
#define CSR3_ADC0_IPG_DOZE          REGBIT(0x1, 23)
#define CSR3_CAN0_IPG_DOZE          REGBIT(0x1, 29)
#define CSR3_CAN1_IPG_DOZE          REGBIT(0x1, 30)
#define CSR3_CAN2_IPG_DOZE          REGBIT(0x1, 31)
/** @} */

/*!
 * @name CSR3 0x20 Bit Definitions
 */
/** @{ */
#define CSR3_SPI0_IPG_STOP_MODE     REGBIT(0x2, 3)
#define CSR3_SPI1_IPG_STOP_MODE     REGBIT(0x2, 4)
#define CSR3_SPI2_IPG_STOP_MODE     REGBIT(0x2, 5)
#define CSR3_SPI3_IPG_STOP_MODE     REGBIT(0x2, 6)
#define CSR3_UART0_IPG_STOP_MODE    REGBIT(0x2, 8)
#define CSR3_UART1_IPG_STOP_MODE    REGBIT(0x2, 9)
#define CSR3_UART2_IPG_STOP_MODE    REGBIT(0x2, 10)
#define CSR3_UART3_IPG_STOP_MODE    REGBIT(0x2, 11)
#define CSR3_I2C0_IPG_STOP_MODE     REGBIT(0x2, 17)
#define CSR3_I2C1_IPG_STOP_MODE     REGBIT(0x2, 18)
#define CSR3_I2C2_IPG_STOP_MODE     REGBIT(0x2, 19)
#define CSR3_I2C3_IPG_STOP_MODE     REGBIT(0x2, 20)
/** @} */

/*!
 * @name CSR3 0x30 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA2_IPG_STOP         REGBIT(0x3, 0)
#define CSR3_EDMA3_IPG_STOP         REGBIT(0x3, 1)
#define CSR3_SPI0_IPG_STOP          REGBIT(0x3, 3)
#define CSR3_SPI1_IPG_STOP          REGBIT(0x3, 4)
#define CSR3_SPI2_IPG_STOP          REGBIT(0x3, 5)
#define CSR3_SPI3_IPG_STOP          REGBIT(0x3, 6)
#define CSR3_UART0_IPG_STOP         REGBIT(0x3, 8)
#define CSR3_UART1_IPG_STOP         REGBIT(0x3, 9)
#define CSR3_UART2_IPG_STOP         REGBIT(0x3, 10)
#define CSR3_UART3_IPG_STOP         REGBIT(0x3, 11)
#define CSR3_I2C0_IPG_STOP          REGBIT(0x3, 17)
#define CSR3_I2C1_IPG_STOP          REGBIT(0x3, 18)
#define CSR3_I2C2_IPG_STOP          REGBIT(0x3, 19)
#define CSR3_I2C3_IPG_STOP          REGBIT(0x3, 20)
#define CSR3_ADC0_IPG_STOP          REGBIT(0x3, 23)
#define CSR3_CAN0_IPG_STOP          REGBIT(0x3, 29)
#define CSR3_CAN1_IPG_STOP          REGBIT(0x3, 30)
#define CSR3_CAN2_IPG_STOP          REGBIT(0x3, 31)
/** @} */

/*!
 * @name CSR3 0x40 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA2_IPG_STOP_ACK     REGBIT(0x4, 0)
#define CSR3_EDMA3_IPG_STOP_ACK     REGBIT(0x4, 1)
#define CSR3_SPI0_IPG_STOP_ACK      REGBIT(0x4, 3)
#define CSR3_SPI1_IPG_STOP_ACK      REGBIT(0x4, 4)
#define CSR3_SPI2_IPG_STOP_ACK      REGBIT(0x4, 5)
#define CSR3_SPI3_IPG_STOP_ACK      REGBIT(0x4, 6)
#define CSR3_UART0_IPG_STOP_ACK     REGBIT(0x4, 8)
#define CSR3_UART1_IPG_STOP_ACK     REGBIT(0x4, 9)
#define CSR3_UART2_IPG_STOP_ACK     REGBIT(0x4, 10)
#define CSR3_UART3_IPG_STOP_ACK     REGBIT(0x4, 11)
#define CSR3_I2C0_IPG_STOP_ACK      REGBIT(0x4, 17)
#define CSR3_I2C1_IPG_STOP_ACK      REGBIT(0x4, 18)
#define CSR3_I2C2_IPG_STOP_ACK      REGBIT(0x4, 19)
#define CSR3_I2C3_IPG_STOP_ACK      REGBIT(0x4, 20)
#define CSR3_ADC0_IPG_STOP_ACK      REGBIT(0x4, 23)
#define CSR3_CAN0_IPG_STOP_ACK      REGBIT(0x4, 29)
#define CSR3_CAN1_IPG_STOP_ACK      REGBIT(0x4, 30)
#define CSR3_CAN2_IPG_STOP_ACK      REGBIT(0x4, 31)
/** @} */

/*!
 * @name CSR3 0x80 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA0_IPG_DEBUG        REGBIT(0x8, 0)
#define CSR3_EDMA1_IPG_DEBUG        REGBIT(0x8, 1)
#define CSR3_GPT0_IPG_DEBUG         REGBIT(0x8, 2)
#define CSR3_GPT1_IPG_DEBUG         REGBIT(0x8, 3)
#define CSR3_GPT2_IPG_DEBUG         REGBIT(0x8, 4)
#define CSR3_GPT3_IPG_DEBUG         REGBIT(0x8, 5)
#define CSR3_GPT4_IPG_DEBUG         REGBIT(0x8, 6)
#define CSR3_GPT5_IPG_DEBUG         REGBIT(0x8, 7)
#define CSR3_SAI0_IPG_DEBUG         REGBIT(0x8, 8)
#define CSR3_SAI1_IPG_DEBUG         REGBIT(0x8, 9)
#define CSR3_SAI2_IPG_DEBUG         REGBIT(0x8, 10)
#define CSR3_SAI3_IPG_DEBUG         REGBIT(0x8, 11)
#define CSR3_SAI4_IPG_DEBUG         REGBIT(0x8, 12)
#define CSR3_SAI5_IPG_DEBUG         REGBIT(0x8, 13)
#define CSR3_PWM_IPG_DEBUG          REGBIT(0x8, 16)
/** @} */

/*!
 * @name CSR3 0x90 Bit Definitions
 */
/** @{ */
#define CSR3_GPT0_IPG_DOZE          REGBIT(0x9, 2)
#define CSR3_GPT1_IPG_DOZE          REGBIT(0x9, 3)
#define CSR3_GPT2_IPG_DOZE          REGBIT(0x9, 4)
#define CSR3_GPT3_IPG_DOZE          REGBIT(0x9, 5)
#define CSR3_GPT4_IPG_DOZE          REGBIT(0x9, 6)
#define CSR3_GPT5_IPG_DOZE          REGBIT(0x9, 7)
#define CSR3_PWM_IPG_DOZE           REGBIT(0x9, 16)
/** @} */

/*!
 * @name CSR3 0xA0 Bit Definitions
 */
/** @{ */
#define CSR3_GPT0_IPG_WAIT          REGBIT(0xA, 2)
#define CSR3_GPT1_IPG_WAIT          REGBIT(0xA, 3)
#define CSR3_GPT2_IPG_WAIT          REGBIT(0xA, 4)
#define CSR3_GPT3_IPG_WAIT          REGBIT(0xA, 5)
#define CSR3_GPT4_IPG_WAIT          REGBIT(0xA, 6)
#define CSR3_GPT5_IPG_WAIT          REGBIT(0xA, 7)
#define CSR3_SAI0_IPG_STOP_MODE     REGBIT(0xA, 8)
#define CSR3_SAI1_IPG_STOP_MODE     REGBIT(0xA, 9)
#define CSR3_SAI2_IPG_STOP_MODE     REGBIT(0xA, 10)
#define CSR3_SAI3_IPG_STOP_MODE     REGBIT(0xA, 11)
#define CSR3_SAI4_IPG_STOP_MODE     REGBIT(0xA, 12)
#define CSR3_SAI5_IPG_STOP_MODE     REGBIT(0xA, 13)
#define CSR3_PWM_IPG_WAIT           REGBIT(0xA, 16)
/** @} */

/*!
 * @name CSR3 0xB0 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA0_IPG_STOP         REGBIT(0xB, 0)
#define CSR3_EDMA1_IPG_STOP         REGBIT(0xB, 1)
#define CSR3_GPT0_IPG_STOP          REGBIT(0xB, 2)
#define CSR3_GPT1_IPG_STOP          REGBIT(0xB, 3)
#define CSR3_GPT2_IPG_STOP          REGBIT(0xB, 4)
#define CSR3_GPT3_IPG_STOP          REGBIT(0xB, 5)
#define CSR3_GPT4_IPG_STOP          REGBIT(0xB, 6)
#define CSR3_GPT5_IPG_STOP          REGBIT(0xB, 7)
#define CSR3_SAI0_IPG_STOP          REGBIT(0xB, 8)
#define CSR3_SAI1_IPG_STOP          REGBIT(0xB, 9)
#define CSR3_SAI2_IPG_STOP          REGBIT(0xB, 10)
#define CSR3_SAI3_IPG_STOP          REGBIT(0xB, 11)
#define CSR3_SAI4_IPG_STOP          REGBIT(0xB, 12)
#define CSR3_SAI5_IPG_STOP          REGBIT(0xB, 13)
#define CSR3_PWM_IPG_STOP           REGBIT(0xB, 16)
/** @} */

/*!
 * @name CSR3 0xC0 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA0_IPG_STOP_ACK     REGBIT(0xC, 0)
#define CSR3_EDMA1_IPG_STOP_ACK     REGBIT(0xC, 1)
#define CSR3_SAI0_IPG_STOP_ACK      REGBIT(0xC, 8)
#define CSR3_SAI1_IPG_STOP_ACK      REGBIT(0xC, 9)
#define CSR3_SAI2_IPG_STOP_ACK      REGBIT(0xC, 10)
#define CSR3_SAI3_IPG_STOP_ACK      REGBIT(0xC, 11)
#define CSR3_SAI4_IPG_STOP_ACK      REGBIT(0xC, 12)
#define CSR3_SAI5_IPG_STOP_ACK      REGBIT(0xC, 13)
/** @} */

#if (defined(FSL_FEATURE_DSC_HAS_PER_RESET) && FSL_FEATURE_DSC_HAS_PER_RESET)
/*!
 * @name ECSR 0x00 Reset Bit Definitions
 */
/** @{ */
#define CSR_GIC_RESET               REGBIT(0x0, 0)
/** @} */
#endif

#endif /* SC_SS_ADMA_DSC_H */

/** @} */

