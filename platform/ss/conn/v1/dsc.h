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
 * @addtogroup CONN_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_CONN_DSC_H
#define SC_SS_CONN_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_USB2                    REGBIT(0, 2)
#define RST_USB3_AON                REGBIT(0, 3)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_OBS_SEL0                REGBIT(0, 8)
#define GPR_OBS_SEL1                REGBIT(0, 9)
#define GPR_ENET_CTRL0              REGBIT(0, 16)
#define GPR_ENET_CTRL1              REGBIT(0, 17)
#define GPR_ISO_USB3_NONSS          REGBIT(0, 18)
#define GPR_ISO_USB3_SS             REGBIT(0, 19)
#define GPR_ISO_USB2                REGBIT(0, 20)
#define GPR_PL301_CACHE_DIS         REGBIT(0, 21)
#define GPR_PL301_M12_ID_FILTER     REGBIT(0, 22)
#define GPR_PL301_FORCE_CACHEABLE   REGBIT(0, 23)
#define GPR_ENET1_MUX               REGBIT(0, 24)
#define GPR_ENET2_MUX               REGBIT(0, 25)
#define GPR_ENET1_IPG_STOP          REGBIT(0, 26)
#define GPR_ENET2_IPG_STOP          REGBIT(0, 27)
#define GPR_ENET1_TX_CLK_SEL        REGBIT(0, 28)
#define GPR_ENET2_TX_CLK_SEL        REGBIT(0, 29)
#define GPR_USB2PHY_IPG_CLK_ACTIVE  REGBIT(0, 30)
#define GPR_USB2PHY_XTAL_VLD        REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Control 1 Bit Definitions
 */
/** @{ */
#define GPR_ENET1_CLKDIV_SEL        REGBIT(1, 33)
#define GPR_ENET2_CLKDIV_SEL        REGBIT(1, 34)
#define GPR_USB_PHY_TRIM            REGBIT(1, 35)         
#define GPR_DIS                     REGBIT(1, 57)
#define GPR_ENET1_50_DISABLE        REGBIT(1, 58)
#define GPR_ENET1_125_DISABLE       REGBIT(1, 59)
#define GPR_ENET2_50_DISABLE        REGBIT(1, 60)
#define GPR_ENET2_125_DISABLE       REGBIT(1, 61)
#define GPR_ENET1_125_SEL           REGBIT(1, 62)
#define GPR_ENET2_125_SEL           REGBIT(1, 63)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_ENET1_IPG_STOP_ACK      REGBIT(0, 6)
#define GPS_ENET2_IPG_STOP_ACK      REGBIT(0, 7)
/** @} */

/*!
 * @name IRQ Mask Definitions
 */
/** @{ */
#define IRQ_ENET1_BUF1              REGBIT(1, 3)
#define IRQ_ENET1_BUF2              REGBIT(1, 4)
#define IRQ_ENET1                   REGBIT(1, 5)
#define IRQ_ENET1_TIME              REGBIT(1, 6)
#define IRQ_ENET2_BUF1              REGBIT(1, 7)
#define IRQ_ENET2_BUF2              REGBIT(1, 8)
#define IRQ_ENET2                   REGBIT(1, 9)
#define IRQ_ENET2_TIME              REGBIT(1, 10)
#define IRQ_DTCP                    REGBIT(1, 11)
#define IRQ_USBOH_OTG               REGBIT(1, 14)
#define IRQ_USBOH_HSIC              REGBIT(1, 15)
#define IRQ_USBOH_PHY               REGBIT(1, 16)
#define IRQ_USBOH_WAKE              REGBIT(1, 17)
#define IRQ_NAND_BCH                REGBIT(1, 18)
#define IRQ_NAND_GPMI               REGBIT(1, 19)
#define IRQ_DMA_CH0                 REGBIT(1, 20)
#define IRQ_DMA_CH1                 REGBIT(1, 21)
#define IRQ_DMA_CH2                 REGBIT(1, 22)
#define IRQ_DMA_CH3                 REGBIT(1, 23)
#define IRQ_DMA_CH4                 REGBIT(1, 24)
#define IRQ_DMA_ERR                 REGBIT(1, 25)
#define IRQ_USB3                    REGBIT(1, 26)
#define IRQ_NAND_DMA                REGBIT(1, 27)
/** @} */

#endif /* SC_SS_CONN_DSC_H */

/** @} */

