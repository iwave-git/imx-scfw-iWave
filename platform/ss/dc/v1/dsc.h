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
 * @addtogroup DC_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_DC_DSC_H
#define SC_SS_DC_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_DSP0                    REGBIT(0, 2)
#define RST_DSP1                    REGBIT(0, 3)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_OBS_SEL0                REGBIT(0, 8)
#define GPR_OBS_SEL1                REGBIT(0, 9)
#define GPR_OBS_SEL2                REGBIT(0, 10)
#define GPR_PXL_LINK_MST1_ADDR      REGBIT(0, 24)
#define GPR_PXL_LINK_MST2_ADDR      REGBIT(0, 26)
#define GPR_IRIS_MVP_PANIC          REGBIT(0, 28)
#define GPR_PXL_LINK_MST1_ENB       REGBIT(0, 30)
#define GPR_PXL_LINK_MST2_ENB       REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Control 1 Bit Definitions
 */
/** @{ */
#define GPR_DC_SYNC_MODE            REGBIT(1, 32)
#define GPR_PXL_LINK_MST1_VLD       REGBIT(1, 33)
#define GPR_PXL_LINK_MST2_VLD       REGBIT(1, 34)
#define GPR_DIV_LINK_CLK_BY_2       REGBIT(1, 35)
#define GPR_KACHUNK_FRAC0           REGBIT(1, 36)
#define GPR_KACHUNK_VID0            REGBIT(1, 37)
#define GPR_KACHUNK_VID1            REGBIT(1, 38)
#define GPR_KACHUNK_WRAP0           REGBIT(1, 39)
#define GPR_PL_SYNC_CTRL0           REGBIT(1, 40)
#define GPR_PL_SYNC_CTRL1           REGBIT(1, 41)
#define GPR_PRG0_SEL                REGBIT(1, 42)
#define GPR_PL_DSP0_CLK             REGBIT(1, 43)
#define GPR_PL_DSP1_CLK             REGBIT(1, 44)
#define GPR_KACHUNK_CNT_NUM0        REGBIT(1, 48)
#define GPR_KACHUNK_CNT_NUM1        REGBIT(1, 49)
#define GPR_KACHUNK_CNT_NUM2        REGBIT(1, 50)
#define GPR_KACHUNK_CNT_NUM3        REGBIT(1, 51)
#define GPR_KACHUNK_CNT_NUM4        REGBIT(1, 52)
#define GPR_KACHUNK_CNT_NUM5        REGBIT(1, 53)
#define GPR_KACHUNK_CNT_NUM6        REGBIT(1, 54)
#define GPR_KACHUNK_CNT_NUM7        REGBIT(1, 55)
#define GPR_KACHUNK_CNT_NUM8        REGBIT(1, 56)
#define GPR_KACHUNK_CNT_NUM9        REGBIT(1, 57)
#define GPR_KACHUNK_CNT_NUM10       REGBIT(1, 58)
#define GPR_KACHUNK_CNT_NUM11       REGBIT(1, 59)
#define GPR_KACHUNK_CNT_NUM12       REGBIT(1, 60)
#define GPR_KACHUNK_CNT_NUM13       REGBIT(1, 61)
#define GPR_KACHUNK_CNT_NUM14       REGBIT(1, 62)
#define GPR_KACHUNK_CNT_NUM15       REGBIT(1, 63)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_GPRCTRL16               REGBIT(0, 16)
#define GPS_GPRCTRL17               REGBIT(0, 17)
/** @} */

#endif /* SC_SS_DC_DSC_H */

/** @} */

