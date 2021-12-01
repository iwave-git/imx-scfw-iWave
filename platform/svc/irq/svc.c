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
 * @file  svc/irq/svc.c
 *
 * File containing the implementation of the System Controller (SC)
 * Interrupt (IRQ) function.
 *
 * @addtogroup IRQ_SVC
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "svc/irq/svc.h"
#include "ss/inf/inf.h"

/* Local Defines */

/* Local Types */

/* Local Functions */

/* Local Variables */

/*--------------------------------------------------------------------------*/
/* Enable/disable interrupts                                                */
/*--------------------------------------------------------------------------*/
sc_err_t irq_enable(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_irq_group_t group, uint32_t mask, sc_bool_t enable)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    ASRT_ERR(group < SC_IRQ_NUM_GROUP, SC_ERR_PARM);

    /* Check ownership */
    ACCESS_ALLOWED(caller_pt, idx);

    if (err == SC_ERR_NONE)
    {
        uint32_t new_mask = mask;

        /* Convert partition-based IRQs */
        if ((group == SC_IRQ_GROUP_WDOG)
            || (group == SC_IRQ_GROUP_RTC)
            || (group == SC_IRQ_GROUP_SYSCTR))
        {
            new_mask = BIT(caller_pt);
        }

        /* Enable/disable interrupt */
        err = ss_irq_enable(idx, group, new_mask, enable);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get and clear interrupt status                                           */
/*--------------------------------------------------------------------------*/
sc_err_t irq_status(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_irq_group_t group, uint32_t *status)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    ASRT_ERR(group < SC_IRQ_NUM_GROUP, SC_ERR_PARM);

    /* Check ownership */
    ACCESS_ALLOWED(caller_pt, idx);

    /* Get and clear interrupt status */
    if (err == SC_ERR_NONE)
    {
        err =  ss_irq_status(idx, group, status);

        /* Convert partition-based IRQs */
        if (err == SC_ERR_NONE)
        {
            if ((*status != 0U) 
                && ((group == SC_IRQ_GROUP_WDOG) 
                || (group == SC_IRQ_GROUP_RTC) 
                || (group == SC_IRQ_GROUP_SYSCTR)))
            {
                *status = BIT(0);
            }
        }
    }

    return err;
}

/*==========================================================================*/

/** @} */

