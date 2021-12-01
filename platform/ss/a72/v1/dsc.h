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
 * @addtogroup A72_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_A72_DSC_H
#define SC_SS_A72_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/** @{ */
#define RST_CORE0_POR               REGBIT(0, 2)
#define RST_CORE1_POR               REGBIT(0, 3)
#define RST_DEBUG                   REGBIT(0, 6)

/** @} */

/*!
 * @name GPR Control 0 Bit Definitions
 */
/** @{ */
#define GPR_BROADCAST_INNER         REGBIT(0, 16)
#define GPR_RESET_VECTOR            REGBIT(0, 17)
#define GPR_L2_REQ                  REGBIT(0, 20)
#define GPR_L2_FLUSH_REQ            REGBIT(0, 21)
#define GPR_L2_RST_INV_DISABLE      REGBIT(0, 22)
#define GPR_DBG_L1_RST_DIS          REGBIT(0, 23)
#define GPR_EDBG_RQ0                REGBIT(0, 24)
#define GPR_EDBG_RQ1                REGBIT(0, 25)
#define GPR_CLUSTERIDAFF1_0         REGBIT(0, 28)
#define GPR_CLUSTERIDAFF1_1         REGBIT(0, 29)
#define GPR_SYSBARDENABLE           REGBIT(0, 30)
#define GPR_ADBGIC_PWRDNREQN        REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Control 1 Bit Definitions
 */
/** @} */
#define GPR_ADB_PWRDNREQN           REGBIT(1, 32)
#define GPR_ACINACTM                REGBIT(1, 33)
#define GPR_EVENTO_RESET            REGBIT(1, 36)
#define GPR_CPUQ_REQ0               REGBIT(1, 44)
#define GPR_CPUQ_REQ1               REGBIT(1, 45)
#define GPR_RST_CORE0               REGBIT(1, 48)
#define GPR_RST_CORE1               REGBIT(1, 49)
#define GPR_DBG_PWRD_UP0            REGBIT(1, 52)
#define GPR_DBG_PWRD_UP1            REGBIT(1, 53)
#define GPR_EVENTI                  REGBIT(1, 63)
/** @} */

/*!
 * @name GPR Status 0 Bit Definitions
 */
/** @{ */
#define GPS_L2_ACTIVE_A72           REGBIT(0, 24)
#define GPS_L2_DENY_A72             REGBIT(0, 25)
#define GPS_L2_ACCEPT_B_A72         REGBIT(0, 26)
#define GPS_L2_FLUSHDONE_A72        REGBIT(0, 27)
#define GPS_ADBGIC_PWRDNACKN        REGBIT(0, 28)
#define GPS_ADBACE_PWRDNACKN        REGBIT(0, 29)
#define GPS_EVENTO                  REGBIT(0, 31)
/** @} */

/*!
 * @name GPR Status 1 Bit Definitions
 */
/** @{ */
#define GPS_CPUQ_DENY0              REGBIT(1, 32)
#define GPS_CPUQ_DENY1              REGBIT(1, 33)
#define GPS_CPUQ_ACCEPT_B0          REGBIT(1, 36)
#define GPS_CPUQ_ACCEPT_B1          REGBIT(1, 37)
#define GPS_CPUQ_ACTIVE0            REGBIT(1, 52)
#define GPS_CPUQ_ACTIVE1            REGBIT(1, 53)
#define GPS_STANDBYWFI0             REGBIT(1, 56)
#define GPS_STANDBYWFI1             REGBIT(1, 57)
#define GPS_STANDBYWFE0             REGBIT(1, 60)
#define GPS_STANDBYWFE1             REGBIT(1, 61)
/** @} */

/*!
 * @name GPR Status 2 Bit Definitions
 */
/** @{ */
#define GPS_DBG_RST_REQ0            REGBIT(2, 64)
#define GPS_DBG_RST_REQ1            REGBIT(2, 65)
#define GPS_DBG_NOPWRDWN0           REGBIT(2, 68)
#define GPS_DBG_NOPWRDWN1           REGBIT(2, 69)
#define GPS_DBG_PWR_UP_REQ0         REGBIT(2, 72)
#define GPS_DBG_PWR_UP_REQ1         REGBIT(2, 73)
#define GPS_DBG_ACK0                REGBIT(2, 76)
#define GPS_DBG_ACK1                REGBIT(2, 77)
#define GPS_WARM_RESET_REQ0         REGBIT(2, 80)
#define GPS_WARM_RESET_REQ1         REGBIT(2, 81)
#define GPS_STANDBYWFIL2_A72        REGBIT(2, 84)
#define GPS_CACTIVES_A72_GIC        REGBIT(2, 85)
#define GPS_CACTIVEM_A72_GIC        REGBIT(2, 86)
#define GPS_CACTIVES_ACE            REGBIT(2, 87)
#define GPS_SMPEN0                  REGBIT(2, 88)
#define GPS_SMPEN1                  REGBIT(2, 89)
/** @} */

/*!
 * @name SS IRQ Mask Definitions
 */
/** @{ */
#define IRQ_EVENTO                  REGBIT64(1, 0)
#define IRQ_CLREXMONACK             REGBIT64(1, 1)
#define IRQ_L2_FLUSHDONE            REGBIT64(1, 2)
#define IRQ_CPUQ_DENY               REGBIT64(1, 5)
#define IRQ_CPUQ_ACCEPT_B           REGBIT64(1, 6)
#define IRQ_L2_DENY                 REGBIT64(1, 7)
#define IRQ_L2_ACCEPT_B             REGBIT64(1, 8)
#define IRQ_STANDBYWFI              REGBIT64(1, 9)
#define IRQ_STANDBYWFIL2            REGBIT64(1, 13)
#define IRQ_DBG_ACK                 REGBIT64(1, 14)
#define IRQ_CA72_COMM_IRQ_B         REGBIT64(1, 15)
#define IRQ_DBG_RST_REQ             REGBIT64(1, 16)
#define IRQ_DBG_PWR_UP_REQ          REGBIT64(1, 17)
#define IRQ_PWR_DN_ACKN_TO_GIC_SLV  REGBIT64(1, 18)
#define IRQ_ADBACE_PWRDNACKN        REGBIT64(1, 19)
/** @} */

#endif /* SC_SS_A72_DSC_H */

/** @} */
