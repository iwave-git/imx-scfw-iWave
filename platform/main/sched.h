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
 * Header file for the SCHED implementation.
 */
/*==========================================================================*/

#ifndef SC_SCHED_H
#define SC_SCHED_H

/* Includes */

#include "fsl_device_registers.h"

/* Defines */

#define SC_SCHED_NUM_PRIO_LEV                       BIT(__NVIC_PRIO_BITS)
#define SC_SCHED_PRIO_WRAP_TO_DEFAULT               SC_SCHED_PRIO_NOPREEMPT_LOW

// Priority grouping (PRIGROUP) configured as follows:
//      1-bit group priority field
//      3-bit subgroup priority field
//
//      Note:  actual bits of priority fields are MSB of fields as defined
//             by __NVIC_PRIO_BITS
//
#define SC_SCHED_PRIGROUP                           (6U)

/* Types */
typedef enum
{
    SC_SCHED_PRIO_PREEMPT_CRITICAL                  = 0,    // Highest premptive
    SC_SCHED_PRIO_PREEMPT_VERY_HIGH                 = 1,
    SC_SCHED_PRIO_PREEMPT_HIGH                      = 2,
    SC_SCHED_PRIO_PREEMPT_ABOVE_NORMAL              = 3,
    SC_SCHED_PRIO_PREEMPT_NORMAL                    = 4,
    SC_SCHED_PRIO_PREEMPT_BELOW_NORMAL              = 5,
    SC_SCHED_PRIO_PREEMPT_LOW                       = 6,
    SC_SCHED_PRIO_PREEMPT_VERY_LOW                  = 7,    // Lowest premptive

    SC_SCHED_PRIO_NOPREEMPT_CRITICAL                = 8,    // Highest non-premptive
    SC_SCHED_PRIO_NOPREEMPT_VERY_HIGH               = 9,
    SC_SCHED_PRIO_NOPREEMPT_HIGH                    = 10,
    SC_SCHED_PRIO_NOPREEMPT_ABOVE_NORMAL            = 11,
    SC_SCHED_PRIO_NOPREEMPT_NORMAL                  = 12,
    SC_SCHED_PRIO_NOPREEMPT_BELOW_NORMAL            = 13,
    SC_SCHED_PRIO_NOPREEMPT_LOW                     = 14,
    SC_SCHED_PRIO_NOPREEMPT_VERY_LOW                = 15,   // Lowest non-premptive

} sc_sched_prio_t;

#endif /* SC_SCHED_H */

