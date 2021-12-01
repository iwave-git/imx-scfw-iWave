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
 * @addtogroup MIPI_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_MIPI_DSC_H
#define SC_SS_MIPI_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_MIPI_BYTE               REGBIT(0, 2)
#define RST_MIPI_DPI                REGBIT(0, 3)
#define RST_MIPI_ESC                REGBIT(0, 4)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */

#define GPR_D3_0_TM                 REGBIT(0, 0)
#define GPR_CLK_0_TM                REGBIT(0, 1)
#define GPR_CLK_1_TM                REGBIT(0, 2)
#define GPR_PWM0_IPG_DEBUG          REGBIT(0, 3)
#define GPR_PWM0_IPG_DOZE           REGBIT(0, 4)
#define GPR_PWM0_IPG_WAIT           REGBIT(0, 5)
#define GPR_PWM0_IPG_STOP           REGBIT(0, 6)
#define GPR_I2C0_IPG_DEBUG          REGBIT(0, 7)
#define GPR_I2C0_IPG_DOZE           REGBIT(0, 8)
#define GPR_I2C0_IPG_STOP           REGBIT(0, 9)
#define GPR_I2C0_IPG_STOP_MODE      REGBIT(0, 10)
#define GPR_I2C1_IPG_DEBUG          REGBIT(0, 11)
#define GPR_I2C1_IPG_DOZE           REGBIT(0, 12)
#define GPR_I2C1_IPG_STOP           REGBIT(0, 13)
#define GPR_I2C1_IPG_STOP_MODE      REGBIT(0, 14)
#define GPR_CLK_2_TM                REGBIT(0, 15)
#define GPR_PHY_ISO                 REGBIT(0, 16)
#define GPR_D3_1_TM                 REGBIT(0, 17)
#define GPR_D3_2_TM                 REGBIT(0, 18)
#define GPR_D2_TM                   REGBIT(0, 19)
#define GPR_D1_0_TM                 REGBIT(0, 22)
#define GPR_D1_1_TM                 REGBIT(0, 23)
#define GPR_TX_RCAL                 REGBIT(0, 26)
#define GPR_D1_2_TM                 REGBIT(0, 28)
#define GPR_D0_TM                   REGBIT(0, 29)

/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_I2C0_STOP_ACK           REGBIT(0, 0)
#define GPS_I2C1_STOP_ACK           REGBIT(0, 1)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_GPIO_0                  REGBIT64(1, 0)
#define IRQ_GPIO_1                  REGBIT64(1, 1)
#define IRQ_GPIO_2                  REGBIT64(1, 2)
#define IRQ_GPIO_3                  REGBIT64(1, 3)
#define IRQ_LPI2C0_HREQ             REGBIT64(1, 4)
#define IRQ_LPI2C1_HREQ             REGBIT64(1, 5)
#define IRQ_WAKE_CTI                REGBIT64(1, 6)
/** @} */

#endif /* SC_SS_MIPI_DSC_H */

/** @} */
