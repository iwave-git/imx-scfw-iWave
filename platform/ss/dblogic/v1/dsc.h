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
 * @addtogroup DBLOGIC_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_DBLOGIC_DSC_H
#define SC_SS_DBLOGIC_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_SSI0_TBU_PM             (0xFUL << 4)
#define GPR_SSI1_TBU_PM             (0xFUL << 8)
#define GPR_SSI2_TBU_PM             (0xFUL << 12)
#define GPR_SSI3_TBU_PM             (0xFUL << 16)
#define GPR_ADB_PWRDNREQN0          REGBIT(0, 26)
#define GPR_STM_NSGUAREN_B          REGBIT(0, 27)
#define GPR_ADB_PWRDNREQN1          REGBIT(0, 28)
#define GPR_SSI_IDLE_STRAP          REGBIT(0, 29)
#define GPR_TCU_QREQN               REGBIT(0, 30)
#define GPR_TCU_SPF_BYPASS          REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#undef  GPS_SSI0_PM_DATA_PEND
#define GPS_SSI0_PM_DATA_PEND       REGBIT(0, 3)
#define GPS_SSI0_TBU_IDLE           REGBIT(0, 4)
#define GPS_SSI0_TBU_PM_DATA_PEND   REGBIT(0, 5)
#define GPS_SSI1_TBU_IDLE           REGBIT(0, 6)
#define GPS_SSI1_TBU_PM_DATA_PEND   REGBIT(0, 7)
#define GPS_SSI2_TBU_IDLE           REGBIT(0, 8)
#define GPS_SSI2_TBU_PM_DATA_PEND   REGBIT(0, 9)
#define GPS_SSI3_TBU_IDLE           REGBIT(0, 10)
#define GPS_SSI3_TBU_PM_DATA_PEND   REGBIT(0, 11)
#define GPS_STM_QACCEPTN            REGBIT(0, 12)
#define GPS_STM_QDENY               REGBIT(0, 13)
#define GPS_ADB_PWRDNACKN0          REGBIT(0, 24)
#define GPS_ADB_PWRDNACKN1          REGBIT(0, 25)
#define GPS_ADB_CACTIVE_S0          REGBIT(0, 26)
#define GPS_ADB_CACTIVE_S1          REGBIT(0, 27)
#define GPS_ADB_CACTIVE_M0          REGBIT(0, 28)
#define GPS_ADB_CACTIVE_M1          REGBIT(0, 29)
#define GPS_AWAKEUP_PTW             REGBIT(0, 31)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_GIC_WAKE00              REGBIT64(1, 0)
#define IRQ_GIC_WAKE01              REGBIT64(1, 1)
#define IRQ_GIC_WAKE02              REGBIT64(1, 2)
#define IRQ_GIC_WAKE03              REGBIT64(1, 3)
#define IRQ_GIC_WAKE10              REGBIT64(1, 4)
#define IRQ_GIC_WAKE11              REGBIT64(1, 5)
#define IRQ_IRQSTR_CTI0             REGBIT64(1, 8)
#define IRQ_IRQSTR_CTI1             REGBIT64(1, 9)
#define IRQ_IRQSTR_CTI2             REGBIT64(1, 10)
#define IRQ_IRQSTR_CTI3             REGBIT64(1, 11)
#define IRQ_IRQSTR_CTI4             REGBIT64(1, 12)
#define IRQ_GIC_ECC_FATAL           REGBIT64(1, 13)
#define IRQ_GIC_AXI_ERR             REGBIT64(1, 14)
/** @} */

#endif /* SC_SS_DBLOGIC_DSC_H */

/** @} */

