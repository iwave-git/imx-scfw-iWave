/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2017-2021 NXP
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
 * @file  svc/pm/svc.c
 *
 * File containing the implementation of the System Controller (SC) Power
 * Management (PM) function. This includes functions for power state
 * control, clock control, reset control, and wake-up event control.
 *
 * @addtogroup PM_SVC
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "main/board.h"
#include "main/boot.h"
#include "main/soc.h"
#include "svc/pm/svc.h"
#include "svc/rm/svc.h"
#include "svc/timer/svc.h"
#include "ss/inf/inf.h"
#include "ss_ver.h"
#if SS_VER_BASE == 1
#include "ss/base/v1/ss.h"
#endif
#include "drivers/sysctr/fsl_sysctr.h"

/* Local Defines */

/*!
 * @name Parameter checking macros
 */
/** @{ */
#define BOUND_MODE(X)       ASRT_ERR((X) <= SC_PM_PW_MODE_ON, SC_ERR_PARM)
#define BOUND_CLK(X)        ASRT_ERR((X) < SS_MAX_PM_CLKS, SC_ERR_PARM)
/** @} */

/*!
 * @name Patition power flags
 */
/** @{ */
#define PM_PART_INIT        BIT32(0U)
#define PM_PART_FINAL       BIT32(1U)
#define PM_PART_REBOOT      BIT32(2U)
/** @} */

/* Local Types */

/*!
 * This type is used to store dynamic info needed to track partition
 * specific data for the power management service.
 */
typedef struct
{
    sc_faddr_t boot_addr;
    uint32_t reboot_mask;
    sc_rsrc_t boot_cpu          : SC_RSRC_W;
    sc_rsrc_t boot_mu           : SC_RSRC_W;
    sc_rsrc_t boot_dev          : SC_RSRC_W;
    sc_rm_pt_t reason_pt        : SC_RM_PARTITION_W;
    sc_pm_reset_reason_t reason : SC_PM_RESET_REASON_W;
    sc_pm_power_mode_t mode     : SC_PM_CLOCK_MODE_W;
    sc_pm_reset_type_t type     : SC_PM_RESET_TYPE_W;
    sc_pm_power_mode_t sys_mode : SC_PM_POWER_MODE_W;
    sc_bool_t booted            : SC_BOOL_W;
} pm_part_data_t;

/*!
 * This type is used to store dynamic info needed to track resource
 * specific data for the power management service.
 */
typedef struct
{
    sc_pm_power_mode_t rsrc_mode  : SC_PM_POWER_MODE_W;
    sc_pm_power_mode_t user_mode : SC_PM_POWER_MODE_W;
} pm_rsrc_data_t;

/* Local Functions */

static void ss_cpu_stop_all(sc_rm_pt_t pt);
static sc_err_t pm_reboot_cont(sc_rm_pt_t pt);
static sc_err_t pm_part_off(sc_rm_pt_t pt, uint32_t flags);
static sc_err_t check_power_mode_trans(sc_rsrc_t rsrc,
    sc_pm_power_mode_t mode);

/* Local Variables */

/*!
 * @name Local Variables
 *
 * @{
 */
static pm_part_data_t pm_part_data[SC_RM_NUM_PARTITION];
static pm_rsrc_data_t pm_rsrc_data[SC_NUM_RSRC];
/** @} */

/*--------------------------------------------------------------------------*/
/* Init the power management service                                        */
/*--------------------------------------------------------------------------*/
void pm_init(sc_bool_t api_phase)
{
    if (api_phase != SC_FALSE)
    {
        sc_rm_pt_t pt;

        /* Init partition data */
        for (pt = 0U; pt < SC_RM_NUM_PARTITION; pt++)
        {
            pm_part_data[pt].sys_mode = SC_PM_PW_MODE_ON;
            pm_part_data[pt].boot_cpu = SC_NUM_RESOURCE;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Initialize a new partition                                               */
/*--------------------------------------------------------------------------*/
void pm_init_part(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    /* Update partition power mode */
    pm_part_data[pt].sys_mode = SC_PM_PW_MODE_ON;
    pm_part_data[pt].reboot_mask = 0U;
}

/*--------------------------------------------------------------------------*/
/* Set power mode for a resource index                                      */
/*--------------------------------------------------------------------------*/
void pm_init_rsrc_power_mode(sc_rsrc_t rsrc, sc_pm_power_mode_t mode)
{
    sc_rm_idx_t idx= 0U;

    if (rm_check_map_ridx(rsrc, &idx) != SC_FALSE)
    {
        sc_sub_t ss;
        sc_ss_idx_t ss_idx;

        pm_rsrc_data[idx].rsrc_mode = SC_PM_PW_MODE_ON;

        /* Convert RM index to SS info */
        rm_get_ridx_ss_info(idx, &ss, &ss_idx);
        ss_init_boot_base(ss, ss_idx, SC_PM_PW_MODE_ON);
    }
}

/*--------------------------------------------------------------------------*/
/* Set power mode for the system                                            */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_sys_power_mode(sc_rm_pt_t caller_pt, sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_MODE(mode);

    /* Check permissions */
    SYSTEM(caller_pt);

    /* Set power mode */
    if (err == SC_ERR_NONE)
    {
        err = board_power(mode);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Init partition to off                                                    */
/*--------------------------------------------------------------------------*/
void pm_init_partition_power_off(sc_rm_pt_t pt)
{
    pm_part_data[pt].sys_mode = SC_PM_PW_MODE_OFF;
}

/*--------------------------------------------------------------------------*/
/* Set power mode for a partition                                           */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_partition_power_mode(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    ASRT_ERR(mode == SC_PM_PW_MODE_OFF, SC_ERR_PARM)

    /* Check parameters */
    USED_PT(pt);
    ASRT_ERR(caller_pt != pt, SC_ERR_PARM)

    /* Check ownership */
    if (rm_get_control_partition(pt) != caller_pt)
    {
        ANCESTOR(pt);
    }

    if (err == SC_ERR_NONE)
    {
        /* Power off partition */
        err = pm_part_off(pt, PM_PART_INIT | PM_PART_FINAL);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set power mode for calling partition                                     */
/*--------------------------------------------------------------------------*/
void pm_partition_power_off(sc_rm_pt_t caller_pt)
{
    /* Power off partition */
    (void) pm_part_off(caller_pt, PM_PART_INIT | PM_PART_FINAL);
}

/*--------------------------------------------------------------------------*/
/* Update power mode for a partition                                        */
/*--------------------------------------------------------------------------*/
sc_err_t pm_update_partition_power_mode(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    BOUND_MODE(mode);

    /* Check parameters */
    USED_PT(pt);
    ASRT_ERR((pt != SC_PT) || (mode != SC_PM_PW_MODE_OFF), SC_ERR_PARM);

    /* Check ownership */
    ANCESTOR(pt);

    if (err == SC_ERR_NONE)
    {
        sc_rm_idx_t idx = 0U;

        /* Save partition system power mode */
        pm_part_data[pt].sys_mode = mode;

        /* Update all resources */
        for (idx = SC_NUM_RSRC - 1U; idx > 0U; idx--)
        {
            pm_update_ridx(idx);
        }
        pm_update_ridx(0U);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Send wake interrupt to a partition                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pm_partition_wake(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Send interrupt */
    ss_irq_trigger(SC_IRQ_GROUP_WAKE, SC_IRQ_SW_WAKE, pt);

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get power mode for a partition                                           */
/*--------------------------------------------------------------------------*/
sc_err_t pm_get_sys_power_mode(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_power_mode_t *mode)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    USED_PT(pt);

    if (err == SC_ERR_NONE)
    {
        /* Return partition power mode */
        *mode = pm_part_data[pt].sys_mode;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Update the power state of a resource                                     */
/*--------------------------------------------------------------------------*/
void pm_update_ridx(sc_rm_idx_t idx)
{
    sc_rm_pt_t pt = 0U;
    sc_pm_power_mode_t to_mode;

    /* Get resource info */
    rm_get_ridx_owner(idx, &pt);

    /* Determine new resource power mode. New mode is the mimumum
     * of the user-specified power mode of the resource and the
     * power mode of the partition owning the resource.
     */
    to_mode = MIN(pm_rsrc_data[idx].user_mode, pm_part_data[pt].sys_mode);

    /* Resource power mode changed? */
    if (to_mode != pm_rsrc_data[idx].rsrc_mode)
    {
        sc_bool_t no_reset = SC_FALSE;

        /* Reset resource */
        if (to_mode == SC_PM_PW_MODE_OFF)
        {
            /* Will return a SC_TRUE if resource is in
             * use and power mode should remain unchanged
             */
            no_reset = soc_reboot_no_reset(idx);
        }
        
        if (no_reset == SC_FALSE)
        {
            sc_pm_power_mode_t from_mode;

            /* Block access via HW? */
            (void) rm_ridx_block(idx, to_mode < SC_PM_PW_MODE_LP);
            (void) rm_update_peripheral(idx);

            /* Call SS to transition resource power mode */
            from_mode = pm_rsrc_data[idx].rsrc_mode;

            /* 
             * Certain power state transitions require clocks so we may need to
             * do two steps to achieve it.
             */
            if (CLKOFFTRANS())
            {
                soc_clk_off_trans = SC_TRUE;
                ss_trans_power_mode(idx, from_mode, SC_PM_PW_MODE_LP);
                ss_trans_power_mode(idx, SC_PM_PW_MODE_LP, to_mode);
            }
            else
            {
                soc_clk_off_trans = SC_FALSE;
                ss_trans_power_mode(idx, from_mode, to_mode);
            }

            /* Save new resource power mode */
            pm_rsrc_data[idx].rsrc_mode = to_mode;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Set power mode for a resource                                            */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_resource_power_mode(sc_rsrc_t mu, sc_rsrc_t resource,
    sc_pm_power_mode_t mode)
{
    sc_err_t err;
    sc_rm_pt_t caller_pt = SC_PT;

    /* Get calling partition */
    err = rm_get_resource_owner(SC_PT, mu, &caller_pt);

    /* Check to insure not disabling MU we are calling on */
    ASRT_ERR((mu != resource) || (mode > SC_PM_PW_MODE_STBY), SC_ERR_PARM);

    /* Check if power mode allowed */
    FUNC_ERR(check_power_mode_trans(resource, mode));

    /* Error? */
    if (err == SC_ERR_NONE)
    {
        err = pm_set_resource_power_mode_pt(caller_pt, resource, mode);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set power mode for a resource via pt                                     */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_resource_power_mode_pt(sc_rm_pt_t caller_pt,
    sc_rsrc_t resource, sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;
    sc_rsrc_t r0, rN;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_MODE(mode);

    /* Is one or all resources? */
    if (resource == SC_R_ALL)
    {
        /* Set range to cover all resources */
        r0 = 0U;
        rN = SC_NUM_RESOURCE - 1U;
    }
    else
    {
        sc_pm_power_mode_t from_mode;

        /* Check parameters */
        BOUND_RSRC(resource, idx);

        /* Check ownership */
        if (caller_pt != SC_PT)
        {
            ACCESS_ALLOWED(caller_pt, idx);
        }

        /* Set range to cover only the specified resource */
        r0 = resource;
        rN = resource;

        from_mode = pm_rsrc_data[idx].rsrc_mode;
        if ((from_mode == SC_PM_PW_MODE_OFF) && (mode == SC_PM_PW_MODE_STBY))
        {
            err = SC_ERR_PARM;
        }
    }

    if (err == SC_ERR_NONE)
    {
        sc_rsrc_t r;

        /* Process range of resources */
        for (r = r0; r <= rN; r++)
        {
            if (resource == SC_R_ALL)
            {
                /* Check parameters */
                BOUND_RSRC_C(r, idx);

                /* Check ownership */
                ACCESS_ALLOWED_C(caller_pt, idx);
            }
            pm_set_rsrc_power_mode(idx, mode);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set power mode for all resources in a child partition                    */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_resource_power_mode_all(sc_rm_pt_t caller_pt, 
    sc_rm_pt_t pt, sc_pm_power_mode_t mode, sc_rsrc_t exclude)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    BOUND_MODE(mode);

    /* Check parameters */
    USED_PT(pt);
    
    /* Check access */
    ASRT_ERR(rm_is_parent(caller_pt, pt) != SC_FALSE,
        SC_ERR_NOACCESS);

    if (err == SC_ERR_NONE)
    {
        sc_rsrc_t r;

        /* Process range of resources */
        for (r = 0U; r <= (SC_NUM_RESOURCE - 1U); r++)
        {
            sc_rm_idx_t idx = 0U;
            sc_rm_pt_t owner = 0U;

            /* Exclude? */
            ASRT_C(r != exclude);

            /* Get resource index */
            BOUND_RSRC_C(r, idx);
            
            /* Correct partition? */
            rm_get_ridx_owner(idx, &owner);
            if (owner != pt)
            {
                continue;
            }
            pm_set_rsrc_power_mode(idx, mode);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set power mode for a resource index                                      */
/*--------------------------------------------------------------------------*/
void pm_set_rsrc_power_mode(sc_rm_idx_t idx, sc_pm_power_mode_t mode)
{
    /* Check availability */
    if (rm_is_ridx_avail(idx) != SC_FALSE)
    {
        sc_pm_power_mode_t from_mode;
        
        from_mode = pm_rsrc_data[idx].rsrc_mode;

        if ((from_mode != SC_PM_PW_MODE_OFF) 
            || (mode != SC_PM_PW_MODE_STBY))
        {
            /* Save user-specified resource power mode */
            pm_rsrc_data[idx].user_mode = mode;

            /* Update resource */
            pm_update_ridx(idx);

            /* Reflect mode achieved during update */
            pm_rsrc_data[idx].user_mode = pm_rsrc_data[idx].rsrc_mode;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Update power mode for a resource index                                   */
/*--------------------------------------------------------------------------*/
void pm_set_active_rsrc_power_mode(sc_rm_idx_t idx, sc_pm_power_mode_t mode)
{
    /* Check availability */
    if ((rm_is_ridx_avail(idx) != SC_FALSE) &&
        (check_power_mode_trans(rm_get_resource(idx), mode)
        == SC_ERR_NONE))
    {
        sc_pm_power_mode_t from_mode;

        from_mode = pm_rsrc_data[idx].rsrc_mode;

        if ((from_mode != SC_PM_PW_MODE_OFF) 
            || (mode != SC_PM_PW_MODE_STBY))
        {
            sc_rm_pt_t pt = 0U;
            sc_pm_power_mode_t sys_mode;

            /* Save user-specified resource power mode */
            pm_rsrc_data[idx].user_mode = mode;

            /* Save partition state */
            rm_get_ridx_owner(idx, &pt);
            sys_mode = pm_part_data[pt].sys_mode;
            pm_part_data[pt].sys_mode = SC_PM_PW_MODE_ON;

            /* Update resource */
            pm_update_ridx(idx);

            /* Restore partition state */
            pm_part_data[pt].sys_mode = sys_mode;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Force power mode for a resource                                          */
/*--------------------------------------------------------------------------*/
sc_err_t pm_force_resource_power_mode(sc_rsrc_t resource,
    sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_RSRC(resource, idx);

    /* Check if power mode allowed */
    FUNC_ERR(check_power_mode_trans(resource, mode));

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        sc_pm_power_mode_t from_mode;

        from_mode = pm_rsrc_data[idx].rsrc_mode;

        if ((from_mode == SC_PM_PW_MODE_OFF) && (mode == SC_PM_PW_MODE_STBY))
        {
            err = SC_ERR_PARM;
        }
        else
        {
            /* Update resource power mode */
            pm_set_rsrc_power_mode(idx, mode);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Force power mode for a resource (no return)                              */
/*--------------------------------------------------------------------------*/
void pm_force_resource_power_mode_v(sc_rsrc_t resource,
    sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_RSRC(resource, idx);

    /* Check if power mode allowed */
    FUNC_ERR(check_power_mode_trans(resource, mode));

    if (err == SC_ERR_NONE)
    {
        sc_pm_power_mode_t from_mode;

        from_mode = pm_rsrc_data[idx].rsrc_mode;

        if ((from_mode != SC_PM_PW_MODE_OFF) || (mode != SC_PM_PW_MODE_STBY))
        {
            /* Save user-specified resource power mode */
            pm_rsrc_data[idx].user_mode = mode;
            
            /* Update resource */
            pm_update_ridx(idx);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Get power mode for a resource                                            */
/*--------------------------------------------------------------------------*/
sc_err_t pm_get_resource_power_mode(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_power_mode_t *mode)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        /* Return resource power mode */
        *mode = pm_rsrc_data[idx].user_mode;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get power mode for a resource index                                      */
/*--------------------------------------------------------------------------*/
void pm_get_rsrc_power_mode(sc_rm_idx_t idx, sc_pm_power_mode_t *mode)
{
    /* Check availability */
    if (rm_is_ridx_avail(idx) == SC_FALSE)
    {
        *mode = SC_PM_PW_MODE_OFF;
    }
    else
    {
        *mode = pm_rsrc_data[idx].user_mode;
    }
}

/*--------------------------------------------------------------------------*/
/* Get active power mode for a resource index                               */
/*--------------------------------------------------------------------------*/
void pm_get_active_rsrc_power_mode(sc_rm_idx_t idx, sc_pm_power_mode_t *mode)
{
    /* Check availability */
    if (rm_is_ridx_avail(idx) == SC_FALSE)
    {
        *mode = SC_PM_PW_MODE_OFF;
    }
    else
    {
        *mode = pm_rsrc_data[idx].rsrc_mode;
    }
}

/*--------------------------------------------------------------------------*/
/* Request low power mode for a resource                                    */
/*--------------------------------------------------------------------------*/
sc_err_t pm_req_low_power_mode(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx= 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    BOUND_MODE(mode);
    
    /* Check ownership */
    ACCESS_ALLOWED(caller_pt, idx);

    if (err == SC_ERR_NONE)
    {
        /* Set CPU power mode */
        err = ss_set_cpu_power_mode(idx, mode, SC_PM_WAKE_SRC_GIC);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Request low power mode for a CPU resource                                */
/*--------------------------------------------------------------------------*/
sc_err_t pm_req_cpu_low_power_mode(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_power_mode_t mode, sc_pm_wake_src_t wake_src)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx= 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    BOUND_MODE(mode);
    ASRT_ERR(wake_src <= SC_PM_WAKE_SRC_GIC, SC_ERR_PARM);
    
    /* Check ownership */
    ACCESS_ALLOWED(caller_pt, idx);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Set CPU power mode */
        err = ss_set_cpu_power_mode(idx, mode, wake_src);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the resume address of a CPU                                          */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_cpu_resume_addr(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_faddr_t address)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_pt_t owner_pt = 0U;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Check ownership */
    if (err == SC_ERR_NONE)
    {
        rm_get_ridx_owner(idx, &owner_pt);
        ASRT_ERR(rm_is_parent(caller_pt, owner_pt) || (caller_pt == owner_pt),
            SC_ERR_NOACCESS);
    }

    /* Set the resume address of the CPU */
    if (err == SC_ERR_NONE)
    {
        err = ss_set_cpu_resume(idx, SC_FALSE, address);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the resume parameters of a CPU                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_cpu_resume(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_bool_t isPrimary, sc_faddr_t address)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_pt_t owner_pt = 0U;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Check ownership */
    if (err == SC_ERR_NONE)
    {
        rm_get_ridx_owner(idx, &owner_pt);
        ASRT_ERR(rm_is_parent(caller_pt, owner_pt) || (caller_pt == owner_pt),
            SC_ERR_NOACCESS);
    }

    /* Set the resume address of the CPU */
    if (err == SC_ERR_NONE)
    {
        err = ss_set_cpu_resume(idx, isPrimary, address);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Request power mode for system-level interfaces including messaging       */
/* units, interconnect, and memories.                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pm_req_sys_if_power_mode(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_sys_if_t sys_if, sc_pm_power_mode_t hpm, sc_pm_power_mode_t lpm)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    ASRT_ERR(sys_if <= SC_PM_SYS_IF_DDR, SC_ERR_PARM);
    ASRT_ERR((hpm <= SC_PM_PW_MODE_ON) &&
        (lpm <= SC_PM_PW_MODE_ON) &&
        (lpm <= hpm), SC_ERR_PARM);
    
    /* Check ownership */
    OWNED(resource);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Set interface power mode */
        err = ss_req_sys_if_power_mode(idx, sys_if, hpm, lpm);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get functional state of a resource                                       */
/*--------------------------------------------------------------------------*/
sc_bool_t pm_is_resource_accessible(sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_RSRC(resource, idx);

    /* Call SS to inquire about the resource */
    if (err == SC_ERR_NONE)
    {
        rtn = ss_is_rsrc_accessible(idx);
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Set rate for a resource's clock (0 = gated)                              */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_clock_rate(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clock_rate_t *rate)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    BOUND_CLK(clk);
    ASRT_ERR(*rate != 0U, SC_ERR_PARM);

    /* Check ownership */
    ASRT_ERR((caller_pt == SC_PT) || rm_is_ridx_access_allowed(caller_pt,
        idx), SC_ERR_NOACCESS);

    /* Call SS to set clock rate */
    if (err == SC_ERR_NONE)
    {
        err = ss_set_clock_rate(idx, clk, rate);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get rate for a resource's clock (0 = gated)                              */
/*--------------------------------------------------------------------------*/
sc_err_t pm_get_clock_rate(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clock_rate_t *rate)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    BOUND_CLK(clk);

    if (err == SC_ERR_NONE)
    {
        /* Call SS to get clock rates */
        err = ss_get_clock_rate(idx, clk, rate);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable for a resource's clock                                    */
/*--------------------------------------------------------------------------*/
sc_err_t pm_clock_enable(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_bool_t enable, sc_bool_t autog)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;
    sc_rsrc_t r0 = 0U;
    sc_rsrc_t rN = 0U;
    sc_pm_power_mode_t mode;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check if resource is powered */
    if (err == SC_ERR_NONE)
    {
        err = pm_get_resource_power_mode(caller_pt, resource, &mode);
    }
    if (err == SC_ERR_NONE)
    {
        if (mode == SC_PM_PW_MODE_OFF)
        {
            err = SC_ERR_NOPOWER;
        }

        /* Is one or all resources? */
        if (resource == SC_R_ALL)
        {
            /* Set range to cover all resources */
            r0 = 0U;
            rN = SC_NUM_RESOURCE - 1U;
        }
        else
        {
            /* Check parameters */
            BOUND_RSRC(resource, idx);

            /* Check ownership */
            ACCESS_ALLOWED(caller_pt, idx);

            /* Set range to cover only the specified resource */
            r0 = resource;
            rN = resource;
        }
    }

    if (err == SC_ERR_NONE)
    {
        sc_pm_clk_t c0, cN;

        /* Is one or all clock? */
        if (clk == SC_PM_CLK_ALL)
        {
            /* Set range to cover all clocks */
            c0 = 0U;
            cN = SS_MAX_PM_CLKS - 1U;
        }
        else
        {
            /* Check parameters */
            BOUND_CLK(clk);
            
            /* Set range to cover only the specified clock */
            c0 = clk;
            cN = clk;
        }

        /* Process range of resources */
        if (err == SC_ERR_NONE)
        {
            sc_rsrc_t r;
            sc_pm_clk_t c;

            for (r = r0; r <= rN; r++)
            {
                if (resource == SC_R_ALL)
                {
                    /* Check parameters */
                    BOUND_RSRC_C(r, idx);

                    /* Check ownership */
                    ACCESS_ALLOWED_C(caller_pt, idx);
                }

                /* Process range of clocks */
                for (c = c0; c <= cN; c++)
                {
                    err = ss_clock_enable(idx, c, enable, autog);
                    if (err == SC_ERR_NONE)
                    {
                        continue;
                    }
                    
                    /* For all resources, do not return an error */
                    if (resource == SC_R_ALL)
                    {
                        err = SC_ERR_NONE;
                        continue;
                    }

                    /* For all clocks, return err only if available */
                    if (clk != SC_PM_CLK_ALL)
                    {
                        break;
                    }
                    if (err != SC_ERR_UNAVAILABLE)
                    {
                        break;
                    }
                }
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Force enable of a resource's clock                                       */
/*--------------------------------------------------------------------------*/
void pm_force_clock_enable(sc_rsrc_t resource, sc_pm_clk_t clk,
    sc_bool_t enable)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_RSRC(resource, idx);
    BOUND_CLK(clk);

    if (err == SC_ERR_NONE)
    {
        /* Call SS to set clock mode */
        (void) ss_force_clock_enable(idx, clk, enable);
    }
}

/*--------------------------------------------------------------------------*/
/* Set Parent of a resource's clock                                         */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_clock_parent(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clk_parent_t parent)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    BOUND_CLK(clk);

    /* Check ownership */
    ACCESS_ALLOWED(caller_pt, idx);

    /* Workaround for ERR050812 */
    if ((parent == XTAL) && (soc_rsrc_is_ap(resource) != SC_FALSE))
    {
        err = SC_ERR_PARM;
    }

    if (err == SC_ERR_NONE)
    {
        /* Call SS to set clock mode */
        err = ss_set_clock_parent(idx, clk, parent);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set Parent of a resource's clock                                         */
/*--------------------------------------------------------------------------*/
sc_err_t pm_get_clock_parent(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clk_parent_t *parent)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0U;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    BOUND_CLK(clk);

    if (err == SC_ERR_NONE)
    {
        /* Call SS to set clock mode */
        err = ss_get_clock_parent(idx, clk, parent);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Boot a partition                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t pm_boot(sc_rm_pt_t caller_pt, sc_rm_pt_t pt, sc_rsrc_t resource_cpu,
    sc_faddr_t boot_addr, sc_rsrc_t resource_mu, sc_rsrc_t resource_dev)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t boot_cpu_idx = 0U;
    sc_rm_idx_t boot_mu_idx = 0U;
    sc_pm_power_mode_t mode = SC_PM_PW_MODE_OFF;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    BOUND_RSRC(resource_cpu, boot_cpu_idx);
    BOUND_RSRC(resource_mu, boot_mu_idx);

    /* Check ownership */
    if (rm_get_control_partition(pt) != caller_pt)
    {
        ANCESTOR(pt);
    }

    /* Check CPU and MU ownership */
    OWNER(pt, resource_cpu);
    OWNER(pt, resource_mu);

#ifdef ERR050601_WORKAROUND
    /* Block this partition if AP */
    soc_block_ap_set(pt, resource_cpu);
#endif

    /* Power on partition */
    if (err == SC_ERR_NONE)
    {
        err = pm_update_partition_power_mode(SC_PT, pt,
            SC_PM_PW_MODE_ON);
    }

    if (err == SC_ERR_NONE)
    {
        /* Prep CPU */
        main_prep_cpu(resource_cpu, resource_mu);

        /* Check power */
        (void) pm_get_rsrc_power_mode(boot_cpu_idx, &mode);
        ASRT_ERR(mode > SC_PM_PW_MODE_STBY, SC_ERR_NOPOWER);
    }

    if (err == SC_ERR_NONE)
    {
        /* Record info */
        pm_part_data[pt].boot_cpu = resource_cpu;
        pm_part_data[pt].boot_mu = resource_mu;
        pm_part_data[pt].boot_dev = resource_dev;
        pm_part_data[pt].boot_addr = boot_addr;
        pm_part_data[pt].reason = SC_PM_RESET_REASON_POR;
        pm_part_data[pt].reason_pt = SC_PT;
        pm_part_data[pt].booted = SC_FALSE;

        /* Set cold boot flag in MU */
        ss_mu_irq(boot_mu_idx, SC_RPC_MU_GIR_BOOT);

        /* Start/stop CPU */
        err = ss_cpu_start(boot_cpu_idx, SC_TRUE, boot_addr);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set partition boot parameters                                            */
/*--------------------------------------------------------------------------*/
sc_err_t pm_set_boot_parm(sc_rm_pt_t caller_pt, sc_rsrc_t resource_cpu,
    sc_faddr_t boot_addr, sc_rsrc_t resource_mu, sc_rsrc_t resource_dev)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check ownership of CPU */
    OWNED(resource_cpu);

    /* Conditionally check ownership of MU */
    if (resource_mu != 0U)
    {
        OWNED(resource_mu);
    }

    /* Conditionally check ownership of boot device */
    if (resource_dev != 0U)
    {
        OWNED(resource_dev);
    }

    if (err == SC_ERR_NONE)
    {
        /* Record info */
        pm_part_data[caller_pt].boot_cpu = resource_cpu;
        pm_part_data[caller_pt].boot_mu = resource_mu;
        pm_part_data[caller_pt].boot_dev = resource_dev;
        pm_part_data[caller_pt].boot_addr = boot_addr;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get partition boot parameters                                            */
/*--------------------------------------------------------------------------*/
sc_err_t pm_get_boot_parm(sc_rm_pt_t caller_pt, sc_rsrc_t *resource_cpu,
    sc_faddr_t *boot_addr, sc_rsrc_t *resource_mu, sc_rsrc_t *resource_dev)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Return info */
        *resource_cpu = pm_part_data[caller_pt].boot_cpu;
        *resource_mu = pm_part_data[caller_pt].boot_mu;
        *resource_dev = pm_part_data[caller_pt].boot_dev;
        *boot_addr = pm_part_data[caller_pt].boot_addr;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Reboot caller's partition                                                */
/*--------------------------------------------------------------------------*/
void pm_reboot(sc_rm_pt_t caller_pt, sc_pm_reset_type_t type)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Reboot partition */
        (void) pm_reboot_part(caller_pt, caller_pt, type,
            SC_PM_RESET_REASON_SW, SC_PM_PW_MODE_OFF);
    }
}

/*--------------------------------------------------------------------------*/
/* Get reset reason                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t pm_reset_reason(sc_rm_pt_t caller_pt, sc_pm_reset_reason_t *reason)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Return reason */
        *reason = pm_part_data[caller_pt].reason;
        if (*reason == SC_PM_RESET_REASON_POR)
        {
            *reason = soc_reset_reason();
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get partition causing reset                                              */
/*--------------------------------------------------------------------------*/
sc_err_t pm_get_reset_part(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Return part */
        *pt = pm_part_data[caller_pt].reason_pt;
        if (pm_part_data[caller_pt].reason == SC_PM_RESET_REASON_POR)
        {
            *pt = soc_reset_part();
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Start/stop a CPU                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t pm_cpu_start(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_bool_t enable, sc_faddr_t address)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_pt_t owner_pt = 0U;
    sc_rm_idx_t idx = 0U;
    sc_pm_power_mode_t mode = SC_PM_PW_MODE_OFF;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        /* Check ownership */
        rm_get_ridx_owner(idx, &owner_pt);
        ASRT_ERR(rm_is_parent(caller_pt, owner_pt) || (caller_pt == owner_pt),
            SC_ERR_NOACCESS);
    }

    if (err == SC_ERR_NONE)
    {
        /* Check power */
        pm_get_rsrc_power_mode(idx, &mode);
        if (enable)
        {
            ASRT_ERR(mode > SC_PM_PW_MODE_STBY, SC_ERR_NOPOWER);
        }
    }

    if (err == SC_ERR_NONE)
    {
        /* Start/stop CPU */
        err = ss_cpu_start(idx, enable, address);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Reset a CPU                                                              */
/*--------------------------------------------------------------------------*/
void pm_cpu_reset(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_faddr_t address)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_pt_t owner_pt = 0U;
    sc_rm_idx_t idx = 0U;
    sc_pm_power_mode_t mode = SC_PM_PW_MODE_OFF;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        /* Check ownership */
        rm_get_ridx_owner(idx, &owner_pt);
        ASRT_ERR(rm_is_parent(caller_pt, owner_pt) || (caller_pt == owner_pt)
            || rm_is_sys_access(caller_pt), SC_ERR_NOACCESS);
    }

    if (err == SC_ERR_NONE)
    {
        /* Check power */
        pm_get_rsrc_power_mode(idx, &mode);
        ASRT_ERR(mode > SC_PM_PW_MODE_STBY, SC_ERR_NOPOWER);
    }

    if (err == SC_ERR_NONE)
    {
        /* Stop and start CPU */
        (void) ss_cpu_start(idx, SC_FALSE, address);
        (void) ss_cpu_start(idx, SC_TRUE, address);
    }
}

/*--------------------------------------------------------------------------*/
/* Reset a resource                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t pm_resource_reset(sc_rsrc_t mu, sc_rsrc_t resource)
{
    sc_err_t err;
    sc_rm_idx_t idx= 0U;
    sc_rm_pt_t caller_pt;

    /* Get calling partition */
    err = rm_get_resource_owner(SC_PT, mu, &caller_pt);

    /* Check to insure not resetting MU we are calling on */
    ASRT_ERR(mu != resource, SC_ERR_PARM);

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Check ownership */
    ACCESS_ALLOWED(caller_pt, idx);

    if (err == SC_ERR_NONE)
    {
        err = ss_rsrc_reset(idx, SC_PT_ALL, SC_FALSE);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Reboot a partition                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pm_reboot_partition(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_reset_type_t type)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    ASRT_ERR(type == SC_PM_RESET_TYPE_COLD, SC_ERR_PARM);
    USED_PT(pt);

    /* Check permissions */
    if (rm_get_control_partition(pt) != caller_pt)
    {
        ASRT_ERR(rm_is_sys_access(caller_pt) || rm_is_parent(caller_pt, pt),
            SC_ERR_NOACCESS);
    }

    /* Reboot partition */
    if (err == SC_ERR_NONE)
    {
        err = pm_reboot_part(caller_pt, pt, type, SC_PM_RESET_REASON_SW,
            SC_PM_PW_MODE_OFF);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Reset system                                                             */
/*--------------------------------------------------------------------------*/
sc_err_t pm_reset(sc_rm_pt_t caller_pt, sc_pm_reset_type_t type)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(type <= SC_PM_RESET_TYPE_BOARD, SC_ERR_PARM);

    /* Check permissions */
    SYSTEM(caller_pt);

    /* Do reset */
    if (err == SC_ERR_NONE)
    {
        err = board_reset(type, SC_PM_RESET_REASON_SW, caller_pt);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Reboot a partition                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pm_reboot_part(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_reset_type_t type, sc_pm_reset_reason_t reason,
    sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t boot_cpu_idx;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    USED_PT(pt);

    /* Bounds check */
    ASRT_ERR(type == SC_PM_RESET_TYPE_COLD, SC_ERR_PARM);
    ASRT_ERR(reason <= SC_PM_RESET_REASON_SCFW_FAULT, SC_ERR_PARM);

    /* Check if booted */
    ASRT_ERR(pm_part_data[pt].boot_cpu < SC_NUM_RESOURCE, SC_ERR_FAIL);

    /* Check partition to reboot is isolated */
    ASRT_ERR(rm_is_partition_isolated(pt) != SC_FALSE,
        SC_ERR_NOACCESS);
 
    /* Get boot CPU index */
    BOUND_RSRC(pm_part_data[pt].boot_cpu, boot_cpu_idx);

    if (err == SC_ERR_NONE)
    {
        /* Prep partition for power off */
        (void) pm_part_off(pt, PM_PART_INIT | PM_PART_REBOOT);

        /* Notify about reboot */
        ss_irq_trigger(SC_IRQ_GROUP_REBOOT, BIT(pt),
            SC_PT_ALL);

        /* Call board to allow change in reset or other action */
        board_reboot_part(pt, &type, &reason, &mode,
            &pm_part_data[pt].reboot_mask);

        /* Record info */
        pm_part_data[pt].reason = reason;
        pm_part_data[pt].reason_pt = caller_pt;      
        pm_part_data[pt].type = type;
        pm_part_data[pt].mode = mode;

        if (pm_part_data[pt].reboot_mask == 0U)
        {
            /* Continue the reboot now */
            err = pm_reboot_cont(pt);
        }
        else
        {
            uint64_t to = U64(board_parameter(BOARD_PARM_REBOOT_TIME))
                * 1000ULL;

            /* Configure timer for timeout */
            err = timer_set_sysctr_alarm(SC_PT, SYSCTR_GetCounter64() 
                + SYSCTR_USEC_TO_TICKS64(to));            
        }
    }
            
    return err;
}

/*--------------------------------------------------------------------------*/
/* Indicate okay to conntinue reboot                                        */
/*--------------------------------------------------------------------------*/
sc_err_t pm_reboot_continue(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check parms */
    BOUND_PT(pt);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        pm_part_data[pt].reboot_mask &= ~(BIT32(caller_pt));

        /* Check reboot mask */
        if (pm_part_data[pt].reboot_mask == 0U)
        {
            /* Cancel timers */
            (void) timer_cancel_sysctr_alarm(SC_PT);

            /* Continue reboot */
            (void) pm_reboot_cont(pt);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Indicate okay to conntinue reboot                                        */
/*--------------------------------------------------------------------------*/
void pm_reboot_continue_all(void)
{
    sc_rm_pt_t p;
    
    (void) timer_cancel_sysctr_alarm(SC_PT);

    /* Notify users of alarm */
    for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
    {
        if (pm_part_data[p].reboot_mask != 0U)
        {
            pm_part_data[p].reboot_mask = 0U;

            switch (board_reboot_timeout(p))
            {

                case BOARD_REBOOT_TO_NONE :
                    break;
                case BOARD_REBOOT_TO_FORCE :
                    (void) pm_reboot_cont(p);
                    break;
                case BOARD_REBOOT_TO_FAULT :
                    (void) board_fault(SC_FALSE, BOARD_BFAULT_REBOOT, p);
                    break;
                default :
                    ; /* Intentional empty default */
                    break;
            }           
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Set the boolean indicating that partition has booted                     */
/* this is called by AP ROM code via MISC service                           */
/*--------------------------------------------------------------------------*/
void pm_set_booted(sc_rm_pt_t pt, sc_bool_t booted)
{
    pm_part_data[pt].booted = booted;
}

/*--------------------------------------------------------------------------*/
/* Get boolean indicating that partition has booted                         */
/*--------------------------------------------------------------------------*/
sc_bool_t pm_get_booted(sc_rm_pt_t pt)
{
    return pm_part_data[pt].booted;
}

/*--------------------------------------------------------------------------*/
/* Get boolean indicating that a partition was started                      */
/*--------------------------------------------------------------------------*/
sc_bool_t pm_is_partition_started(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;
    
    /* Bounds check */
    BOUND_PT(pt);

    if ((err == SC_ERR_NONE) && (pm_part_data[pt].boot_cpu
        < SC_NUM_RESOURCE))
    {
        rtn = SC_TRUE;
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Dump PM state for debug                                                  */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG) && defined(DEBUG_PM)
     void pm_dump(sc_rm_pt_t pt)
    {
    }
#endif

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Stop all CPUs owned by a partition                                       */
/*--------------------------------------------------------------------------*/
static void ss_cpu_stop_all(sc_rm_pt_t pt)
{
    uint8_t cpu = 15U;

    /* List of CPU resources */
    static const sc_rsrc_t cpu_list[15] =
    {
        /* AP 0 cores */
        SC_R_AP_0_0,
        SC_R_AP_0_1,
        SC_R_AP_0_2,
        SC_R_AP_0_3,
        /* AP 1 cores */
        SC_R_AP_1_0,
        SC_R_AP_1_1,
        /* AP 2 cores */
        SC_R_AP_2_0,
        SC_R_AP_2_1,
        SC_R_AP_2_2,
        SC_R_AP_2_3,
        /* MCU cores */
        SC_R_MCU_0_PID0,
        SC_R_MCU_1_PID0,
        /* Clusters */
        SC_R_AP_0, 
        SC_R_AP_1,       
        SC_R_AP_2 
    };

    /* Loop over all CPUs */
    while (cpu > 0U)
    {
        sc_rm_idx_t idx;

        cpu--;
        
        /* Check for existence */
        if (rm_check_map_ridx(cpu_list[cpu], &idx) != SC_FALSE)
        {
            sc_rm_pt_t owner_pt = SC_PT;

            /* Check ownership */
            rm_get_ridx_owner(idx, &owner_pt);
            if (owner_pt == pt)
            {
                if (soc_cluster_link_off(cpu_list[cpu], pt) == SC_FALSE)
                {
                    (void) ss_cpu_start(idx, SC_FALSE, 0ULL);
                }
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Reboot a partition                                                       */
/*--------------------------------------------------------------------------*/
static sc_err_t pm_reboot_cont(sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rsrc_t boot_cpu = pm_part_data[pt].boot_cpu;
    sc_rsrc_t boot_mu = pm_part_data[pt].boot_mu;
    sc_rsrc_t boot_dev = pm_part_data[pt].boot_dev;
    sc_faddr_t boot_addr = pm_part_data[pt].boot_addr;

    /* Check boot CPU */
    if (rm_check_map_ridx(boot_cpu, NULL) == SC_FALSE)
    {
        err = SC_ERR_PARM;
    }

    if (err == SC_ERR_NONE)
    {
        /* Allow board file to disable UART */
        board_disable_debug_uart();
    }
            
    if ((err == SC_ERR_NONE)
        && (pm_part_data[pt].type != SC_PM_RESET_TYPE_WARM))
    {
        /* Check power state */
        if (pm_part_data[pt].sys_mode != SC_PM_PW_MODE_OFF)
        {
            base_nopoweroff = SC_TRUE;

            /* Turn off */
            err = pm_part_off(pt, PM_PART_FINAL| PM_PART_REBOOT);
        }

        /* Power on partition */
        if (err == SC_ERR_NONE)
        {
            err = pm_update_partition_power_mode(SC_PT, pt,
                SC_PM_PW_MODE_ON);
        }

        /* Call board to allow change in boot or other action */
        if (err == SC_ERR_NONE)
        {
            board_reboot_part_cont(pt, &boot_cpu, &boot_mu, &boot_dev,
                &boot_addr);
        }

        /* Check for error */
        if (err == SC_ERR_NONE)
        {
            uint32_t indx;
            
            /* Power on boot peripherals */
            main_prep_cpu(boot_cpu, boot_mu);

            /* Power on boot memory (FSPI, OCRAM, TCM) */
            if (main_get_mem_ss(boot_addr, &indx) == SC_ERR_NONE)
            {
                sc_rsrc_t rsrc = rom_boot_addr[indx].rsrc;

                if (rsrc != SC_R_DRC_0)
                {
                    pm_force_resource_power_mode_v(
                        rom_boot_addr[indx].rsrc, SC_PM_PW_MODE_ON);
                }
            }
        }

        base_nopoweroff = SC_FALSE;
    }

    /* Allow board file to re-enable UART */
    board_config_debug_uart(SC_TRUE);
    board_config_debug_uart(SC_FALSE);

    if (err == SC_ERR_NONE)
    {
        sc_rm_idx_t boot_cpu_idx, boot_mu_idx;

        /* Get boot CPU index */
        BOUND_RSRC(boot_cpu, boot_cpu_idx);

        /* Set cold boot flag in MU */
        if (rm_check_map_ridx(boot_mu, &boot_mu_idx)
            != SC_FALSE)
        {
            ss_mu_irq(boot_mu_idx, SC_RPC_MU_GIR_BOOT);
        }

        ss_irq_trigger(SC_IRQ_GROUP_REBOOTED, BIT(pt),
            SC_PT_ALL);

        /* Restart CPU */
        if (err == SC_ERR_NONE)
        {
            err = ss_cpu_start(boot_cpu_idx, SC_TRUE, boot_addr);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Power off a partition                                                    */
/*--------------------------------------------------------------------------*/
static sc_err_t pm_part_off(sc_rm_pt_t pt, uint32_t flags)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check current power state */
    if (pm_part_data[pt].sys_mode != SC_PM_PW_MODE_OFF)
    {
        /* Power off init phase */
        if ((flags & PM_PART_INIT) != 0U)
        {
            /* Cancel watchdog */
            timer_halt_wdog(pt);

            /* Cancel alarms */
            (void) timer_cancel_rtc_alarm(pt);
            (void) timer_cancel_sysctr_alarm(pt);

            /* Stop all CPUs owned by this partition */
            ss_cpu_stop_all(pt);

            /* Send off notice if not rebooting */
            if ((flags & PM_PART_REBOOT) == 0U)
            {
                ss_irq_trigger(SC_IRQ_GROUP_OFF, BIT(pt),
                    SC_PT_ALL);;
            }
        }

        /* Power off final phase */
        if ((flags & PM_PART_FINAL) != 0U)
        {
            soc_no_reset = SC_TRUE;
            base_noflushl2 = SC_TRUE;
            base_gic_noblock = SC_TRUE;

            /* Reset resources that need power on */
            (void) ss_rsrc_reset(0U, pt, SC_TRUE);

            /* Power off */
            err = pm_update_partition_power_mode(SC_PT, pt, 
                SC_PM_PW_MODE_OFF);

            if (err == SC_ERR_NONE)
            {
                sc_rm_pt_t p;

                /* Free all child partitions */
                for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
                {
                    if ((rm_is_partition_used(p) != SC_FALSE) 
                        && (rm_is_parent(pt, p) != SC_FALSE))
                    {
                        /* Stop all CPUs */
                        ss_cpu_stop_all(p);

                        /* Power off partition */
                        (void) pm_update_partition_power_mode(SC_PT,
                            p, SC_PM_PW_MODE_OFF);

                        /* Free partition */
                        (void) rm_partition_free(SC_PT, p);
                    }
                }

                /* Power off all peripherals */
                (void) pm_set_resource_power_mode_pt(pt, SC_R_ALL,
                    SC_PM_PW_MODE_OFF);

                /* Reset partition resources still on */
                (void) ss_rsrc_reset(0U, pt, SC_FALSE);
            }

            soc_no_reset = SC_FALSE;
            base_noflushl2 = SC_FALSE;
            base_gic_noblock = SC_FALSE;

            if ((flags & PM_PART_REBOOT) == 0U)
            {
                /* Unless partition is rebooting, update HMP power state to
                 * remove requests for HMP nodes powered off.
                 *
                 * NOTE: must be done after soc_no_reset set FALSE to avoid
                 *       skip of OCMEM system interfaces
                 */
                soc_update_hmp_sys_power_mode();

                /* Send off complete notice if not rebooting */
                ss_irq_trigger(SC_IRQ_GROUP_OFFED, BIT(pt),
                    SC_PT_ALL);;
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Check if the requested power mode is okay                                */
/*--------------------------------------------------------------------------*/
static sc_err_t check_power_mode_trans(sc_rsrc_t rsrc,
    sc_pm_power_mode_t mode)
{
    sc_err_t err = SC_ERR_NONE;

    /*
     * Workaround for ERR050812.
     * Call SOC to check if AP is not allowed to enter LP
     */
    if ((mode == SC_PM_PW_MODE_LP) && (soc_rsrc_is_ap(rsrc) != SC_FALSE))
    {
        err = SC_ERR_PARM;
    }

    return err;
}

/** @} */

