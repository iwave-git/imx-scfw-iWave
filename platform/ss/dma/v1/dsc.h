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
 * @addtogroup DMA_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_DMA_DSC_H
#define SC_SS_DMA_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_OBS_SEL0                REGBIT(0, 8)
#define GPR_OBS_SEL1                REGBIT(0, 9)
#define GPR_OBS_SEL2                REGBIT(0, 10)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_EMVSIM0                 REGBIT64(1, 0)
#define IRQ_EMVSIM1                 REGBIT64(1, 1)
#define IRQ_LPI2C0                  REGBIT64(1, 2)
#define IRQ_LPI2C1                  REGBIT64(1, 3)
#define IRQ_LPI2C2                  REGBIT64(1, 4)
#define IRQ_LPI2C3                  REGBIT64(1, 5)
#define IRQ_LPI2C4                  REGBIT64(1, 6)
#define IRQ_LPSPI0                  REGBIT64(1, 7)
#define IRQ_LPSPI1                  REGBIT64(1, 8)
#define IRQ_LPSPI2                  REGBIT64(1, 9)
#define IRQ_LPSPI3                  REGBIT64(1, 10)
#define IRQ_LPUART0                 REGBIT64(1, 11)
#define IRQ_LPUART1                 REGBIT64(1, 12)
#define IRQ_LPUART2                 REGBIT64(1, 13)
#define IRQ_LPUART3                 REGBIT64(1, 14)
#define IRQ_LPUART4                 REGBIT64(1, 15)
#define IRQ_ADC0                    REGBIT64(1, 16)
#define IRQ_ADC1                    REGBIT64(1, 17)
/** @} */

/*!
 * @name CSR3 0x00 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA0_IPG_DEBUG        REGBIT(0x0, 0)
#define CSR3_EDMA1_IPG_DEBUG        REGBIT(0x0, 1)
#define CSR3_SPI0_IPG_DEBUG         REGBIT(0x0, 3)
#define CSR3_SPI1_IPG_DEBUG         REGBIT(0x0, 4)
#define CSR3_SPI2_IPG_DEBUG         REGBIT(0x0, 5)
#define CSR3_SPI3_IPG_DEBUG         REGBIT(0x0, 6)
#define CSR3_UART0_IPG_DEBUG        REGBIT(0x0, 8)
#define CSR3_UART1_IPG_DEBUG        REGBIT(0x0, 9)
#define CSR3_UART2_IPG_DEBUG        REGBIT(0x0, 10)
#define CSR3_UART3_IPG_DEBUG        REGBIT(0x0, 11)
#define CSR3_UART4_IPG_DEBUG        REGBIT(0x0, 12)
#define CSR3_SIM0_IPG_DEBUG         REGBIT(0x0, 14)
#define CSR3_SIM1_IPG_DEBUG         REGBIT(0x0, 15)
#define CSR3_I2C0_IPG_DEBUG         REGBIT(0x0, 17)
#define CSR3_I2C1_IPG_DEBUG         REGBIT(0x0, 18)
#define CSR3_I2C2_IPG_DEBUG         REGBIT(0x0, 19)
#define CSR3_I2C3_IPG_DEBUG         REGBIT(0x0, 20)
#define CSR3_I2C4_IPG_DEBUG         REGBIT(0x0, 21)
#define CSR3_ADC0_IPG_DEBUG         REGBIT(0x0, 23)
#define CSR3_ADC1_IPG_DEBUG         REGBIT(0x0, 24)
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
#define CSR3_EDMA0_IPG_DOZE         REGBIT(0x1, 0)
#define CSR3_EDMA1_IPG_DOZE         REGBIT(0x1, 1)
#define CSR3_SPI0_IPG_DOZE          REGBIT(0x1, 3)
#define CSR3_SPI1_IPG_DOZE          REGBIT(0x1, 4)
#define CSR3_SPI2_IPG_DOZE          REGBIT(0x1, 5)
#define CSR3_SPI3_IPG_DOZE          REGBIT(0x1, 6)
#define CSR3_UART0_IPG_DOZE         REGBIT(0x1, 8)
#define CSR3_UART1_IPG_DOZE         REGBIT(0x1, 9)
#define CSR3_UART2_IPG_DOZE         REGBIT(0x1, 10)
#define CSR3_UART3_IPG_DOZE         REGBIT(0x1, 11)
#define CSR3_UART4_IPG_DOZE         REGBIT(0x1, 12)
#define CSR3_SIM0_IPG_DOZE          REGBIT(0x1, 14)
#define CSR3_SIM1_IPG_DOZE          REGBIT(0x1, 15)
#define CSR3_I2C0_IPG_DOZE          REGBIT(0x1, 17)
#define CSR3_I2C1_IPG_DOZE          REGBIT(0x1, 18)
#define CSR3_I2C2_IPG_DOZE          REGBIT(0x1, 19)
#define CSR3_I2C3_IPG_DOZE          REGBIT(0x1, 20)
#define CSR3_I2C4_IPG_DOZE          REGBIT(0x1, 21)
#define CSR3_ADC0_IPG_DOZE          REGBIT(0x1, 23)
#define CSR3_ADC1_IPG_DOZE          REGBIT(0x1, 24)
#define CSR3_FTM0_IPG_DOZE          REGBIT(0x1, 26)
#define CSR3_FTM1_IPG_DOZE          REGBIT(0x1, 27)
#define CSR3_CAN0_IPG_DOZE          REGBIT(0x1, 29)
#define CSR3_CAN1_IPG_DOZE          REGBIT(0x1, 30)
#define CSR3_CAN2_IPG_DOZE          REGBIT(0x1, 31)
/** @} */

/*!
 * @name CSR3 0x20 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA0_IPG_STOP_MODE    REGBIT(0x2, 0)
#define CSR3_EDMA1_IPG_STOP_MODE    REGBIT(0x2, 1)
#define CSR3_SPI0_IPG_STOP_MODE     REGBIT(0x2, 3)
#define CSR3_SPI1_IPG_STOP_MODE     REGBIT(0x2, 4)
#define CSR3_SPI2_IPG_STOP_MODE     REGBIT(0x2, 5)
#define CSR3_SPI3_IPG_STOP_MODE     REGBIT(0x2, 6)
#define CSR3_UART0_IPG_STOP_MODE    REGBIT(0x2, 8)
#define CSR3_UART1_IPG_STOP_MODE    REGBIT(0x2, 9)
#define CSR3_UART2_IPG_STOP_MODE    REGBIT(0x2, 10)
#define CSR3_UART3_IPG_STOP_MODE    REGBIT(0x2, 11)
#define CSR3_UART4_IPG_STOP_MODE    REGBIT(0x2, 12)
#define CSR3_SIM0_IPG_STOP_MODE     REGBIT(0x2, 14)
#define CSR3_SIM1_IPG_STOP_MODE     REGBIT(0x2, 15)
#define CSR3_I2C0_IPG_STOP_MODE     REGBIT(0x2, 17)
#define CSR3_I2C1_IPG_STOP_MODE     REGBIT(0x2, 18)
#define CSR3_I2C2_IPG_STOP_MODE     REGBIT(0x2, 19)
#define CSR3_I2C3_IPG_STOP_MODE     REGBIT(0x2, 20)
#define CSR3_I2C4_IPG_STOP_MODE     REGBIT(0x2, 21)
#define CSR3_ADC0_IPG_STOP_MODE     REGBIT(0x2, 23)
#define CSR3_ADC1_IPG_STOP_MODE     REGBIT(0x2, 24)
#define CSR3_FTM0_IPG_STOP_MODE     REGBIT(0x2, 26)
#define CSR3_FTM1_IPG_STOP_MODE     REGBIT(0x2, 27)
#define CSR3_CAN0_IPG_STOP_MODE     REGBIT(0x2, 29)
#define CSR3_CAN1_IPG_STOP_MODE     REGBIT(0x2, 30)
#define CSR3_CAN2_IPG_STOP_MODE     REGBIT(0x2, 31)
/** @} */

/*!
 * @name CSR3 0x30 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA0_IPG_STOP         REGBIT(0x3, 0)
#define CSR3_EDMA1_IPG_STOP         REGBIT(0x3, 1)
#define CSR3_SPI0_IPG_STOP          REGBIT(0x3, 3)
#define CSR3_SPI1_IPG_STOP          REGBIT(0x3, 4)
#define CSR3_SPI2_IPG_STOP          REGBIT(0x3, 5)
#define CSR3_SPI3_IPG_STOP          REGBIT(0x3, 6)
#define CSR3_UART0_IPG_STOP         REGBIT(0x3, 8)
#define CSR3_UART1_IPG_STOP         REGBIT(0x3, 9)
#define CSR3_UART2_IPG_STOP         REGBIT(0x3, 10)
#define CSR3_UART3_IPG_STOP         REGBIT(0x3, 11)
#define CSR3_UART4_IPG_STOP         REGBIT(0x3, 12)
#define CSR3_SIM0_IPG_STOP          REGBIT(0x3, 14)
#define CSR3_SIM1_IPG_STOP          REGBIT(0x3, 15)
#define CSR3_I2C0_IPG_STOP          REGBIT(0x3, 17)
#define CSR3_I2C1_IPG_STOP          REGBIT(0x3, 18)
#define CSR3_I2C2_IPG_STOP          REGBIT(0x3, 19)
#define CSR3_I2C3_IPG_STOP          REGBIT(0x3, 20)
#define CSR3_I2C4_IPG_STOP          REGBIT(0x3, 21)
#define CSR3_ADC0_IPG_STOP          REGBIT(0x3, 23)
#define CSR3_ADC1_IPG_STOP          REGBIT(0x3, 24)
#define CSR3_FTM0_IPG_STOP          REGBIT(0x3, 26)
#define CSR3_FTM1_IPG_STOP          REGBIT(0x3, 27)
#define CSR3_CAN0_IPG_STOP          REGBIT(0x3, 29)
#define CSR3_CAN1_IPG_STOP          REGBIT(0x3, 30)
#define CSR3_CAN2_IPG_STOP          REGBIT(0x3, 31)

/** @} */

/*!
 * @name CSR3 0x40 Bit Definitions
 */
/** @{ */
#define CSR3_EDMA0_IPG_STOP_ACK     REGBIT(0x4, 0)
#define CSR3_EDMA1_IPG_STOP_ACK     REGBIT(0x4, 1)
#define CSR3_SPI0_IPG_STOP_ACK      REGBIT(0x4, 3)
#define CSR3_SPI1_IPG_STOP_ACK      REGBIT(0x4, 4)
#define CSR3_SPI2_IPG_STOP_ACK      REGBIT(0x4, 5)
#define CSR3_SPI3_IPG_STOP_ACK      REGBIT(0x4, 6)
#define CSR3_UART0_IPG_STOP_ACK     REGBIT(0x4, 8)
#define CSR3_UART1_IPG_STOP_ACK     REGBIT(0x4, 9)
#define CSR3_UART2_IPG_STOP_ACK     REGBIT(0x4, 10)
#define CSR3_UART3_IPG_STOP_ACK     REGBIT(0x4, 11)
#define CSR3_UART4_IPG_STOP_ACK     REGBIT(0x4, 12)
#define CSR3_SIM0_IPG_STOP_ACK      REGBIT(0x4, 14)
#define CSR3_SIM1_IPG_STOP_ACK      REGBIT(0x4, 15)
#define CSR3_I2C0_IPG_STOP_ACK      REGBIT(0x4, 17)
#define CSR3_I2C1_IPG_STOP_ACK      REGBIT(0x4, 18)
#define CSR3_I2C2_IPG_STOP_ACK      REGBIT(0x4, 19)
#define CSR3_I2C3_IPG_STOP_ACK      REGBIT(0x4, 20)
#define CSR3_I2C4_IPG_STOP_ACK      REGBIT(0x4, 21)
#define CSR3_ADC0_IPG_STOP_ACK      REGBIT(0x4, 23)
#define CSR3_ADC1_IPG_STOP_ACK      REGBIT(0x4, 24)
#define CSR3_FTM0_IPG_STOP_ACK      REGBIT(0x4, 26)
#define CSR3_FTM1_IPG_STOP_ACK      REGBIT(0x4, 27)
#define CSR3_CAN0_IPG_STOP_ACK      REGBIT(0x4, 29)
#define CSR3_CAN1_IPG_STOP_ACK      REGBIT(0x4, 30)
#define CSR3_CAN2_IPG_STOP_ACK      REGBIT(0x4, 31)
/** @} */

#endif /* SC_SS_DMA_DSC_H */

/** @} */

