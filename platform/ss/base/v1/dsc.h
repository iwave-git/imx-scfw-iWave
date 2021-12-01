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
 * File containing the generic DSC header info defined by the standards
 * doc.
 *
 * @addtogroup BASE_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_BASE_DSC_H
#define SC_SS_BASE_DSC_H

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_DSCMIX                  REGBIT(0, 0)
#define RST_SS                      REGBIT(0, 1)
#define RST_SS_PD2                  REGBIT(0, 2)
#define RST_SS_PD3                  REGBIT(0, 3)
#define RST_SS_PD4                  REGBIT(0, 4)
#define RST_SS_PD5                  REGBIT(0, 5)
#define RST_SS_PD6                  REGBIT(0, 6)
#define RST_SS_MEM_REPAIR           REGBIT(0, 7)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_SSI0_PM                 REGBIT(0, 0)
#define GPR_SSI0_BHM                REGBIT(0, 1)
#define GPR_SSI0_ISO_CONTROL        REGBIT(0, 2)
#define GPR_SSI0_POWER_CONTROL      REGBIT(0, 3)
#define GPR_SSI1_PM                 REGBIT(0, 4)
#define GPR_SSI1_BHM                REGBIT(0, 5)
#define GPR_SSI1_ISO_CONTROL        REGBIT(0, 6)
#define GPR_SSI1_POWER_CONTROL      REGBIT(0, 7)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_SSI0_SI                 REGBIT(0, 0)
#define GPS_SSI0_RI                 REGBIT(0, 1)
#define GPS_SSI1_SI                 REGBIT(0, 2)
#define GPS_SSI1_RI                 REGBIT(0, 3)
#define GPS_SSI0_PM_DATA_PEND       REGBIT(0, 4)
#define GPS_SSI1_PM_DATA_PEND       REGBIT(0, 5)
/** @} */

/*!
 * @name DSC IRQ Mask Definitions
 */
/** @{ */
#define IRQ_TEMP_PANIC              REGBIT64(0, 0)
#define IRQ_TEMP_LOW                REGBIT64(0, 1)
#define IRQ_TEMP_HIGH               REGBIT64(0, 2)
#define IRQ_MSI_ERR                 REGBIT64(0, 3)
#define IRQ_MSI_OVFL                REGBIT64(0, 4)
#define IRQ_MSI_AHB_OVFL            REGBIT64(0, 5)
#define IRQ_BIST                    REGBIT64(0, 6)
#define IRQ_PWRCTRL_PFET_LF_ACK     REGBIT64(0, 16)
#define IRQ_PWRCTRL_PFET_HF_ACK     REGBIT64(0, 24)
/** @} */

/*!
 * @name AI Toggle Mask Definitions
 */
/** @{ */
#define AI_ANA_PLL0                 REGBIT(0, 0)
#define AI_ANA_PLL1                 REGBIT(0, 1)
#define AI_ANA_PLL2                 REGBIT(0, 2)
#define AI_ANA_OSC24M               REGBIT(0, 3)
#define AI_ANA_RC200OSC             REGBIT(0, 4)
#define AI_ANA_VDROP_PROCMON        REGBIT(0, 5)
#define AI_ANA_TEMP_SENSE           REGBIT(0, 6)
#define AI_ANA_LVDS_TRANSCEIVER     REGBIT(0, 7)
#define AI_ANA_NEG_CHARGE_PUMP      REGBIT(0, 8)
#define AI_ANA_WELL_LEVEL_SOURCE    REGBIT(0, 9)
#define AI_ANA_BANDGAP_REFERENCE    REGBIT(0, 10)
#define AI_ANA_VA_REF_GEN           REGBIT(0, 11)
#define AI_ANA_DIFF_CLOCK_REPEATER  REGBIT(0, 12)
#define AI_ANA_DIFF_ROOT_CLK_BUFFER REGBIT(0, 13)
#define AI_ANA_DIFF_CLOCK_TERM      REGBIT(0, 14)
#define AI_PHY_PHY_LDO              REGBIT(0, 17)
#define AI_PHY_LVDS_TRANSCEIVER     REGBIT(0, 18)
#define AI_PHY_BANDGAP_REFERENCE    REGBIT(0, 19)
#define AI_PHY_VA_REF_GEN           REGBIT(0, 20)
#define AI_PHY_DIFF_CLOCK_REPEATER  REGBIT(0, 21)
#define AI_PHY_DIFF_ROOT_CLK_BUF0   REGBIT(0, 22)
#define AI_PHY_DIFF_ROOT_CLK_BUF1   REGBIT(0, 23)
#define AI_PHY_DIFF_ROOT_CLK_BUF2   REGBIT(0, 24)
#define AI_PHY_DIFF_CLOCK_TERM0     REGBIT(0, 25)
#define AI_PHY_DIFF_CLOCK_TERM1     REGBIT(0, 26)
#define AI_PHY_DIFF_CLOCK_TERM2     REGBIT(0, 27)
#define AI_PHY_DIFF_CLOCK_TERM3     REGBIT(0, 28)
/** @} */

#endif /* SC_SS_BASE_DSC_H */

/** @} */

