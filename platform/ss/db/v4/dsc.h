/*
** ###################################################################
**
**     Copyright 2019-2021 NXP
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
 * @addtogroup DB_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_DB_DSC_H
#define SC_SS_DB_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_V2X                     REGBIT(0, 2)
/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_SSI2_PM                 REGBIT(0, 8)
#define GPR_SSI2_BHM                REGBIT(0, 9)
#define GPR_SSI3_PM                 REGBIT(0, 10)
#define GPR_SSI3_BHM                REGBIT(0, 11)
#define GPR_SSI4_PM                 REGBIT(0, 12)
#define GPR_SSI4_BHM                REGBIT(0, 13)
#define GPR_SSI5_PM                 REGBIT(0, 14)
#define GPR_SSI5_BHM                REGBIT(0, 15)
#define GPR_SSI6_PM                 REGBIT(0, 16)
#define GPR_SSI6_BHM                REGBIT(0, 17)
#define GPR_V2XDB_ADB_PWRDNREQN     REGBIT(0, 18)
#define GPR_DBV2X_ADB_PWRDNREQN     REGBIT(0, 19)
#define GPR_SSI_DRC0_PM0            REGBIT(0, 20)
#define GPR_SSI_DRC0_PM1            REGBIT(0, 21)
#define GPR_SSI_DRC0_BHM0           REGBIT(0, 22)
#define GPR_SSI_DRC0_BHM1           REGBIT(0, 23)
#define GPR_V2X_CLOCK_RUN           REGBIT(0, 30)
#define GPR_SSI_IDLE_STRAP          REGBIT(0, 31)

/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_SSI2_SI                 REGBIT(0, 4)
#define GPS_SSI2_RI                 REGBIT(0, 5)
#define GPS_SSI3_SI                 REGBIT(0, 6)
#define GPS_SSI3_RI                 REGBIT(0, 7)
#define GPS_SSI4_SI                 REGBIT(0, 8)
#define GPS_SSI4_RI                 REGBIT(0, 9)
#define GPS_SSI5_SI                 REGBIT(0, 10)
#define GPS_SSI5_RI                 REGBIT(0, 11)
#define GPS_SSI6_SI                 REGBIT(0, 12)
#define GPS_SSI6_RI                 REGBIT(0, 13)
#define GPR_V2XDB_ADB_PWRDNACKN     REGBIT(0, 14)
#define GPR_DBV2X_ADB_PWRDNACKN     REGBIT(0, 15)
#define GPS_SSI_DRC0_SI             REGBIT(0, 16)
#define GPS_SSI_DRC0_RI             REGBIT(0, 17)
#undef  GPS_SSI0_PM_DATA_PEND
#define GPS_SSI0_PM_DATA_PEND       REGBIT(0, 20)
#undef  GPS_SSI1_PM_DATA_PEND
#define GPS_SSI1_PM_DATA_PEND       REGBIT(0, 21)
#define GPS_SSI2_PM_DATA_PEND       REGBIT(0, 22)
#define GPS_SSI3_PM_DATA_PEND       REGBIT(0, 23)
#define GPS_SSI4_PM_DATA_PEND       REGBIT(0, 24)
#define GPS_SSI5_PM_DATA_PEND       REGBIT(0, 25)
#define GPS_SSI6_PM_DATA_PEND       REGBIT(0, 26)
#define GPS_SSI_DRC0_PM_DATA_PEND0  REGBIT(0, 28)
#define GPS_SSI_DRC0_PM_DATA_PEND1  REGBIT(0, 29)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_SERIOUS_ERR             REGBIT64(1, 0)
#define IRQ_V2X_MU                  REGBIT64(1, 1)
/** @} */

#endif /* SC_SS_DB_DSC_H */

/** @} */

