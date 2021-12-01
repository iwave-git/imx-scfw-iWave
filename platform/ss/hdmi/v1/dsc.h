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
 * @addtogroup HDMI_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_HDMI_DSC_H
#define SC_SS_HDMI_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_PHY                     REGBIT(0, 2)
#define RST_HPD_FILTER              REGBIT(0, 4)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_PWM0_IPG_DEBUG          REGBIT(0, 8)
#define GPR_PWM0_IPG_DOZE           REGBIT(0, 9)
#define GPR_PWM0_IPG_WAIT           REGBIT(0, 10)
#define GPR_PWM0_IPG_STOP           REGBIT(0, 11)
#define GPR_I2C0_IPG_DEBUG          REGBIT(0, 12)
#define GPR_I2C0_IPG_DOZE           REGBIT(0, 13)
#define GPR_I2C0_IPG_STOP           REGBIT(0, 14)
#define GPR_I2C0_IPG_STOP_MODE      REGBIT(0, 15)
#define GPR_PHY_ISO_ENABLE          REGBIT(0, 17)
#define GPR_PLL_REF_CLK_SELECT      REGBIT(0, 18)
#define GPR_PD_PAD                  REGBIT(0, 24)
#define GPR_LNK_BID6                REGBIT(0, 25)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_I2C0_STOP_ACK           REGBIT(0, 4)
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
/** @} */

#endif /* SC_SS_HDMI_DSC_H */

/** @} */

