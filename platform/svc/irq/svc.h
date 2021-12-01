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
 * @file  svc/irq/svc.h
 *
 * Header file containing the API for the System Controller (SC) Interrupt
 * (IRQ) function.
 *
 * @addtogroup IRQ_SVC
 * @{
 */
/*==========================================================================*/

#ifndef SC_IRQ_SVC_H
#define SC_IRQ_SVC_H

/* Includes */

#include "svc/irq/api.h"
#include "svc/rm/svc.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Internal SC function to enable/disable interrupts.
 *
 * @see sc_irq_set_control().
 */
sc_err_t irq_enable(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_irq_group_t group, uint32_t mask, sc_bool_t enable);

/*!
 * Internal SC function to get and clear interrupt status.
 *
 * @see sc_irq_get_control().
 */
sc_err_t irq_status(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_irq_group_t group, uint32_t *status);

#endif /* SC_IRQ_SVC_H */

/** @} */

