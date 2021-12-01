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
#define RST_MED_CORE_DEC        REGBIT(0, 3)
#define RST_MED_CORE_BISR       REGBIT(0, 7)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_SEC_ENB             REGBIT(0, 24)
#define GPR_DEC_CLK             REGBIT(0, 25)
#define GPR_ENC_CLK             REGBIT(0, 26)
#define GPR_ARCACHE             REGBIT(0, 27)
#define GPR_AWCACHE             REGBIT(0, 28)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_AVE_IRQ             REGBIT64(1, 0)
#define IRQ_AVE_FIQ             REGBIT64(1, 1)
#define IRQ_MSD_IRQ             REGBIT64(1, 2)
#define IRQ_MSD_FIQ             REGBIT64(1, 3)
#define IRQ_MSD_SIF             REGBIT64(1, 4)
/** @} */

#endif /* SC_SS_VPU_DSC_H */

/** @} */

