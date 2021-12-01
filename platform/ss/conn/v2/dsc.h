/*
** ###################################################################
**
**     Copyright 2019-2020 NXP
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
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_OBS_SEL0                REGBIT(0, 8)
#define GPR_OBS_SEL1                REGBIT(0, 9)
#define GPR_ENET_QOS_DIS_CRC_CHK    REGBIT(0, 10)
#define GPR_ENET_QOS_CLK_GEN_EN     REGBIT(0, 11)
#define GPR_ENET_QOS_INTF_SEL       REGBIT(0, 12)
#define GPR_ENET_RXC_DELAY          REGBIT(0, 16)
#define GPR_ENET_EC0_DIS            REGBIT(0, 18)
#define GPR_ISO_USB_OTG1            REGBIT(0, 19)
#define GPR_ISO_USB_OTG2            REGBIT(0, 20)
#define GPR_PL301_CACHE_DIS         REGBIT(0, 21)
#define GPR_PL301_M12_ID_FILTER     REGBIT(0, 22)
#define GPR_PL301_FORCE_CACHEABLE   REGBIT(0, 23)
#define GPR_ENET1_MUX               REGBIT(0, 24)
#define GPR_ENET2_MUX               REGBIT(0, 25)
#define GPR_ENET1_IPG_STOP          REGBIT(0, 26)
#define GPR_ENET1_TX_CLK_SEL        REGBIT(0, 28)
#define GPR_USB2PHY_IPG_CLK_ACTIVE  REGBIT(0, 30)
#define GPR_USB2PHY_XTAL_VLD        REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Control 1 Bit Definitions
 */
/** @{ */
#define GPR_ENET1_CLKDIV_SEL        REGBIT(1, 33)
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
/** @} */

/*!
 * @name IRQ Mask Definitions
 */
/** @{ */
#define IRQ_ENET1_BUF1              REGBIT(1, 3)
#define IRQ_ENET1_BUF2              REGBIT(1, 4)
#define IRQ_ENET1                   REGBIT(1, 5)
#define IRQ_ENET1_TIME              REGBIT(1, 6)
#define IRQ_ENET2_PMT               REGBIT(1, 7)
#define IRQ_ENET2                   REGBIT(1, 8)
#define IRQ_USBOH_OTG               REGBIT(1, 14)
#define IRQ_USBOH_OTG2              REGBIT(1, 15)
#define IRQ_USBOH_PHY               REGBIT(1, 16)
#define IRQ_USBOH_WAKE              REGBIT(1, 17)
#define IRQ_NAND_BCH                REGBIT(1, 18)
#define IRQ_NAND_GPMI               REGBIT(1, 19)
#define IRQ_NAND_DMA                REGBIT(1, 27)
/** @} */

#if (defined(FSL_FEATURE_DSC_HAS_PER_RESET) && FSL_FEATURE_DSC_HAS_PER_RESET)
/*!
 * @name ECSR 0x00 Reset Bit Definitions
 */
/** @{ */
#define CSR_SDHC1_RESET             REGBIT8(0x0, 0)
#define CSR_SDHC2_RESET             REGBIT8(0x0, 1)
#define CSR_SDHC3_RESET             REGBIT8(0x0, 2)
#define CSR_ENET1_RESET             REGBIT8(0x0, 3)
#define CSR_ENET2_RESET             REGBIT8(0x0, 4)
#define CSR_USB_RESET               REGBIT8(0x0, 5)
#define CSR_USB_PHY1_RESET          REGBIT8(0x0, 6)
#define CSR_USB_PHY2_RESET          REGBIT8(0x0, 7)
#define CSR_NAND_RESET              REGBIT8(0x0, 8)
/** @} */
#endif

#endif /* SC_SS_CONN_DSC_H */

/** @} */

