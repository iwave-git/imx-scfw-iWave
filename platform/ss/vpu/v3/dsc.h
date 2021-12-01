/*
** ###################################################################
**
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
 * @addtogroup VPU_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_VPU_DSC_H
#define SC_SS_VPU_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_MED_CORE_ENC        REGBIT(0, 2)
#define RST_SS_DSP              REGBIT(0, 3)
#define RST_MED_CORE_DEC        REGBIT(0, 4)
#define RST_SS_DSP_CORE         REGBIT(0, 5)
#define RST_SS_DSP_DEBUG        REGBIT(0, 6)
#define RST_MED_CORE_BISR       REGBIT(0, 7)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_SYS_OFFSET_IRQ      REGBIT(0, 8)
#define GPR_SYS_OFFSET_AUD      REGBIT(0, 16)
#define GPR_SYS_OFFSET_SEL      REGBIT(0, 24)
#define GPR_ADB_DSP_PWRDNREQN0  REGBIT(0, 25)
#define GPR_ADB_DSP_PWRDNREQN1  REGBIT(0, 26)
#define GPR_DSP_CACHE_SEL       REGBIT(0, 27)
#define GPR_DSP_CACHEABLE       REGBIT(0, 28)
#define GPR_DSP_DMA_BYPASS      REGBIT(0, 29)
#define GPR_ARCACHE             REGBIT(0, 30)
#define GPR_AWCACHE             REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_DSP_DEBUGSTATUS         REGBIT(0, 16)
#define GPS_ADB_DSP_PWRDNACKN0      REGBIT(0, 25)
#define GPS_ADB_DSP_CACTIVES0       REGBIT(0, 26)
#define GPS_ADB_DSP_CACTIVEM0       REGBIT(0, 27)
#define GPS_ADB_DSP_PWRDNACKN1      REGBIT(0, 29)
#define GPS_ADB_DSP_CACTIVES1       REGBIT(0, 30)
#define GPS_ADB_DSP_CACTIVEM1       REGBIT(0, 31)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_AVE_IRQ0                REGBIT64(1, 0)
#define IRQ_AVE_IRQ1                REGBIT64(1, 1)
#define IRQ_MSD_IRQ                 REGBIT64(1, 2)
#define IRQ_IRQSTR                  REGBIT64(1, 7)
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
 * @name CSR2 0x04 Bit Definitions
 */
/** @{ */
/** @} */

#endif /* SC_SS_VPU_DSC_H */

/** @} */

