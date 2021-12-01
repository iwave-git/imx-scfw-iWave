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
 * @addtogroup DRC_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_DRC_DSC_H
#define SC_SS_DRC_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_DDR_CRESETN         REGBIT(0, 2)
#define RST_PHY_RSTN            REGBIT(0, 3)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_PRF1_AXI_ID         REGBIT(0, 4)
#define GPR_SSI_IDLE_STRAP_DRC  REGBIT(0, 9)
#define GPR_QCHAN_QEN           REGBIT(0, 10)
#define GPR_PRF1_AXI_ID_MASK    REGBIT(0, 11)
#define GPR_PRF2_AXI_ID         REGBIT(0, 16)
#define GPR_PHY_MODE_0          REGBIT(0, 22)
#define GPR_PHY_MODE_1          REGBIT(0, 23)
#define GPR_RET_EN_I            REGBIT(0, 27)
#define GPR_EXT_EN_I            REGBIT(0, 28)
/** @} */

/*!
 * @name GPR Control 1 Bit Definitions
 */
/** @{ */
#define GPR_PRF2_AXI_ID_MASK    REGBIT(1, 16)
#define GPR_PRF3_AXI_ID         REGBIT(1, 21)
#define GPR_PRF3_AXI_ID_MASK    REGBIT(1, 26)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_DFI_INIT_COMP       REGBIT(0, 17)
#define GPS_CSYSACK_0           REGBIT(0, 19)
#define GPS_CSYSACK_DDRC        REGBIT(0, 21)
#define GPS_PHY_BYP_MODE        REGBIT(0, 22)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_CSYSACK_0           REGBIT64(1, 0)
#define IRQ_CSYSACK_DDRC        REGBIT64(1, 1)
/** @} */

#endif /* SC_SS_DRC_DSC_H */

/** @} */

