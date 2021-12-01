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
 * @addtogroup CSI_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_CSI_DSC_H
#define SC_SS_CSI_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_MIPI                    REGBIT(0, 2)
#define RST_BUS                     REGBIT(0, 3)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_PWM0_IPG_DEBUG          REGBIT(0, 0)
#define GPR_PWM0_IPG_DOZE           REGBIT(0, 1)
#define GPR_PWM0_IPG_WAIT           REGBIT(0, 2)
#define GPR_PWM0_IPG_STOP           REGBIT(0, 3)
#define GPR_I2C0_IPG_DEBUG          REGBIT(0, 4)
#define GPR_I2C0_IPG_DOZE           REGBIT(0, 5)
#define GPR_I2C0_IPG_STOP           REGBIT(0, 6)
#define GPR_I2C0_IPG_STOP_MODE      REGBIT(0, 7)
#define GPR_PHY_ISO                 REGBIT(0, 16)
#define GPR_DISPLAY_CTRL_LINK_SLV   REGBIT(0, 25)
#define GPR_RX_RCAL                 REGBIT(0, 26)
#define GPR_RXLPRP0                 REGBIT(0, 28)
#define GPR_RXLPRP1                 REGBIT(0, 29)
#define GPR_RXCDRP0                 REGBIT(0, 30)
#define GPR_RXCDRP1                 REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_I2C0_STOP_ACK           REGBIT(0, 0)
#define GPS_LANES_STOPPED           REGBIT(0, 1)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_GPIO                    REGBIT64(1, 0)
#define IRQ_LPI2C0                  REGBIT64(1, 1)
/** @} */

#endif /* SC_SS_CSI_DSC_H */

/** @} */

