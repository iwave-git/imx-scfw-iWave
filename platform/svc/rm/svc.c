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
 * @file  svc/rm/svc.c
 *
 * File containing the implementation of the System Controller (SC) Resource
 * Management (RM) function. This includes functions for partitioning
 * resources, pads, and memory regions.
 *
 * @addtogroup  RM_SVC
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "main/soc.h"
#include "main/board.h"
#include "svc/rm/svc.h"
#include "svc/pm/svc.h"
#include "svc/timer/svc.h"
#include "ss/inf/inf.h"
#include "ss_ver.h"
#if SS_VER_BASE == 1
#include "ss/base/v1/ss.h"
#endif
#include "drivers/sysctr/fsl_sysctr.h"

/* Local Defines */

#if 0
    /*! Define to enable RM timing */
    #define PROF_RM
#endif

/*! Define for MRC alignment */
#define MRC_ALIGN           0xFFFULL

/*!
 * @name Parameter checking macros
 */
/** @{ */
#define USED_MR(X)          ASRT_ERR(rm_mreg_data[(X)].used != SC_FALSE, SC_ERR_PARM)
#define USED_MR_C(X)        ASRT_C(rm_mreg_data[(X)].used != SC_FALSE)
#define NOT_RESTRICTED(X)   ASRT_ERR(rm_part_data[(X)].restricted == SC_FALSE, SC_ERR_NOACCESS)
#define NOT_LOCKED(X)       ASRT_ERR(rm_part_data[(X)].locked == SC_FALSE, SC_ERR_LOCKED)
#define NOT_LOCKED_C(X)     ASRT_C(rm_part_data[(X)].locked == SC_FALSE)
#define PARENT(X)           ASRT_ERR(caller_pt == rm_part_data[(X)].parent, SC_ERR_NOACCESS)
/** @} */

#ifdef PROF_RM
    #define START_TIMER(X) \
        uint32_t (X) = SYSCTR_GetCounter32()
#else
    #define START_TIMER(X) NOP
#endif

#ifdef PROF_RM
    #define STOP_TIMER(X) \
        (X) = SYSCTR_GetCounter32() - (X)
#else
    #define STOP_TIMER(X) NOP
#endif

/* Local Types */

/*!
 * This type is used to store compressed permissions.
 */
typedef uint8_t permz_t;

/*!
 * This type is used to store dynamic info needed to track partition
 * specific data for the resource management service.
 */
typedef struct
{
    sc_rm_pt_t parent        : SC_RM_PARTITION_W;
    sc_rm_pt_t control       : SC_RM_PARTITION_W;
    sc_rm_did_t did          : SC_RM_DID_W;
    sc_bool_t used           : SC_BOOL_W;
    sc_bool_t secure         : SC_BOOL_W;
    sc_bool_t restricted     : SC_BOOL_W;
    sc_bool_t isolated       : SC_BOOL_W;
    sc_bool_t locked         : SC_BOOL_W;
    sc_bool_t confidential   : SC_BOOL_W;
    sc_bool_t grant          : SC_BOOL_W;
    sc_bool_t sys_access     : SC_BOOL_W;
} rm_part_data_t;

/*!
 * This type is used to store dynamic info needed to track
 * resource state.
 */
typedef struct
{
    permz_t perms[SC_RM_NUM_DOMAIN / 2];
    sc_rm_sid_t sid     : SC_RM_SID_W;
    sc_ss_idx_t ss_idx  : SC_SS_IDX_W;
    sc_sub_t ss         : SC_SUBSYS_W;
    sc_rm_spa_t sa      : SC_RM_PERM_W;
    sc_rm_spa_t pa      : SC_RM_PERM_W;
    sc_rm_pt_t owner    : SC_RM_PARTITION_W;
    sc_bool_t movable   : SC_BOOL_W;
    sc_bool_t block     : SC_BOOL_W;
} rm_rsrc_data_t;

/*!
 * This type is used to store dynamic info needed to track
 * pad state.
 */
typedef struct
{
    sc_rm_pt_t owner    : SC_RM_PARTITION_W;
    sc_bool_t movable   : SC_BOOL_W;
} rm_pad_data_t;

/*!
 * This type is used to store dynamic info needed to track
 * memory region state.
 */
typedef struct
{
    sc_faddr_t start;
    sc_faddr_t end;
    sc_rm_mr_t parent   : SC_RM_MEMREG_W; 
    sc_rm_pt_t owner    : SC_RM_PARTITION_W;
    sc_rm_rmsg_t rmsg   : SC_RM_RMSG_W;
    sc_rm_det_t det     : SC_RM_DET_W;
    sc_bool_t used      : SC_BOOL_W;
    permz_t perms[SC_RM_NUM_DOMAIN / 2];
} rm_mreg_data_t;

/* Local Functions */

/*!
 * @name Private Functions
 * @{
 */
static void clear_perms(permz_t *perms);
static void copy_perms(sc_rm_mr_t mr_src, sc_rm_mr_t mr_dst);
static void set_perms(permz_t *perms, sc_rm_did_t did,
    sc_rm_perm_t perm);
static void get_perms(const permz_t *perms, sc_rm_did_t did,
        sc_rm_perm_t *perm);
static void update_rdc_resource(sc_rm_idx_t idx, sc_bool_t master,
    sc_bool_t peripheral);
static sc_err_t update_rdc_memreg(sc_rm_mr_t mr, sc_faddr_t old_start,
    sc_faddr_t old_end, sc_faddr_t new_start, sc_faddr_t new_end);
/** @} */

/*!
 * @name Local Variables
 *
 * @{
 */
static rm_part_data_t rm_part_data[SC_RM_NUM_PARTITION];
static sc_rm_idx_t rm_rsrc_map_data[SC_NUM_RESOURCE];
static sc_rm_idx_t rm_ss_map_data[SC_NUM_SUBSYS];
static rm_rsrc_data_t rm_rsrc_data[SC_NUM_RSRC];
static rm_pad_data_t rm_pad_data[SC_NUM_PAD];
static rm_mreg_data_t rm_mreg_data[SC_RM_NUM_MEMREG];
static sc_rm_mr_t rm_mreg_list[SC_RM_NUM_MEMREG];
static sc_rm_mr_t rm_mreg_list_count = 0U;
static sc_bool_t did_used[SC_RM_NUM_DOMAIN];
static sc_rm_pt_t dynamic_pt_first;
static sc_rm_did_t dynamic_did_first;
static sc_bool_t blocking = SC_FALSE;
/** @} */

/* Global Variables */

/*! Max domain used */
uint8_t rm_max_did = SC_DID;

#if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
    /*! Partition name pointers */
    const char *rm_part_names[SC_RM_NUM_PARTITION];
#endif

/*--------------------------------------------------------------------------*/
/* Init the resource management service                                     */
/*--------------------------------------------------------------------------*/
void rm_init(sc_bool_t api_phase)
{
    if (api_phase != SC_FALSE)
    {
        sc_sub_t s;
        sc_rm_idx_t r;
        uint8_t loop;
        sc_pad_t n;

        /* Init index mapping info */
        for (r = 0; r < (sc_rm_idx_t) SC_NUM_RESOURCE; r++)
        {
            rm_rsrc_map_data[r] = SC_NUM_RSRC;
        }

        /* Allocate SC DID */
        did_used[SC_DID] = SC_TRUE;

        /* Partition SC_PT allocated to SC */
        rm_part_data[SC_PT].used = SC_TRUE;
        #if SC_PT != 0
            rm_part_data[SC_PT].parent = SC_PT;
            rm_part_data[SC_PT].control = SC_PT;
        #endif
        rm_part_data[SC_PT].secure = SC_TRUE;
        rm_part_data[SC_PT].isolated = SC_TRUE;
        #if SC_DID != 0
            rm_part_data[SC_PT].did = SC_DID;
        #endif
        rm_part_data[SC_PT].sys_access = SC_FALSE;

        /* All resources owned by SC */
        for (r = 0; r < SC_NUM_RSRC; r++)
        {
            #if SC_PT != 0
                rm_rsrc_data[r].owner = SC_PT;
            #endif
            #if SC_BYPASS_SID != 0
                rm_rsrc_data[r].sid = SC_BYPASS_SID;
            #endif
            rm_rsrc_data[r].sa = SC_SA;
            rm_rsrc_data[r].pa = SC_PA;
            rm_rsrc_data[r].movable = SC_TRUE;
            rm_rsrc_data[r].block = SC_TRUE;
            set_perms(rm_rsrc_data[r].perms, SC_DID, SC_RM_PERM_SEC_RW);
        }

        /* Fill in SS mapping info */
        r = 0;
        for (s = 0; s < SC_NUM_SUBSYS; s++)
        {
            sc_ss_inst_t inst = sc_ss_info[s].inst;

            rm_ss_map_data[s] = r;

            #ifdef SIMU
                if (r >= SC_NUM_RSRC)
                {
                    error_print("error: Rsrc map ovfl: %s\n",
                        snames[s]);
                    break;
                }
            #endif

            for (loop = 0; loop < ss_base_info[s]->num_rsrc; loop++)
            {
                sc_rm_idx_t idx = (inst * ss_base_info[s]->num_rsrc) + loop;

                /* Check for mapping error */
                #ifdef SIMU
                    if (rm_rsrc_map_data[ss_base_info[s]->rsrc_map[idx].resource]
                        != SC_NUM_RSRC)
                    {
                        error_print("error: Rsrc map: %s #%d\n",
                            snames[s], loop);
                        break;
                    }
                #endif

                /* Fill in resource to index info */
                rm_rsrc_map_data[ss_base_info[s]->rsrc_map[idx].resource]
                    = r;

                /* Fill in index to ss info */
                rm_rsrc_data[r].ss = s;
                rm_rsrc_data[r].ss_idx = loop;
                r++;
            }
        }

        /* Fill in board mapping info */
        for (loop = 0; loop < board_num_rsrc; loop++)
        {
            #ifdef SIMU
                if (r >= SC_NUM_RSRC)
                {
                    error_print("error: Rsrc map ovfl: board\n");
                    break;
                }
            #endif

            /* Check for mapping error */
            #ifdef SIMU
                if (rm_rsrc_map_data[board_rsrc_map[loop].resource]
                    != SC_NUM_RSRC)
                {
                    error_print("error: Rsrc map: BOARD #%d\n",
                        loop);
                }
            #endif

            /* Fill in resource to index info */
            rm_rsrc_map_data[board_rsrc_map[loop].resource]
                = r;

            /* Fill in index to board info */
            rm_rsrc_data[r].ss = SC_SUBSYS_NA;
            rm_rsrc_data[r].ss_idx = loop;
            r++;
        }

        /* All pads owned by SC */
        for (n = 0; n < SC_NUM_PAD; n++)
        {
            #if SC_PT != 0
                rm_pad_data[n].owner = SC_PT;
            #endif
            rm_pad_data[n].movable = SC_TRUE;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Define number of static partitions                                       */
/*--------------------------------------------------------------------------*/
sc_err_t rm_reserve_static_pt(sc_rm_pt_t num)
{
    /* Set first dynamic */
    dynamic_pt_first = num;

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Define number of static domains                                          */
/*--------------------------------------------------------------------------*/
sc_err_t rm_reserve_static_did(sc_rm_did_t num)
{
    SIMU_ASRT(num < SC_RM_NUM_PARTITION,
        "bad pt");

    /* Set first dynamic */
    dynamic_did_first = num;

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Allocate a new resource partition and return a handle                    */
/*--------------------------------------------------------------------------*/
sc_err_t rm_partition_alloc(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt,
    sc_bool_t secure, sc_bool_t isolated, sc_bool_t restricted, sc_bool_t grant,
    sc_bool_t coherent)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    NOT_LOCKED(caller_pt);
    NOT_RESTRICTED(caller_pt);
    ASRT_ERR((secure == SC_FALSE) || (rm_part_data[caller_pt].secure != SC_FALSE),
        SC_ERR_NOACCESS);

    if (err == SC_ERR_NONE)
    {
        sc_rm_pt_t p;

        /* Find unallocated partition */
        err = SC_ERR_UNAVAILABLE;
        for (p = dynamic_pt_first; p < SC_RM_NUM_PARTITION; p++)
        {
            if (rm_part_data[p].used == SC_FALSE)
            {
                /* Init parameters */
                rm_part_data[p].used = SC_TRUE;
                rm_part_data[p].parent = caller_pt;
                rm_part_data[p].secure = secure;
                rm_part_data[p].isolated = isolated;
                rm_part_data[p].restricted = restricted;
                rm_part_data[p].grant = grant;
                rm_part_data[p].locked = SC_FALSE;
                rm_part_data[p].sys_access = SC_FALSE;
                rm_part_data[p].control = SC_PT;               
                #if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
                    rm_part_names[p] = NULL;
                #endif
                /* Init power and timer state */
                pm_init_part(caller_pt, p);
                timer_init_part(caller_pt, p);

                /* Allocate a DID */
                if (isolated != SC_FALSE)
                {
                    /* Coherent? */
                    if (coherent != SC_FALSE)
                    {
                        /* Use DID 0 if available */
                        if (did_used[0] == SC_FALSE)
                        {
                            did_used[0] = SC_TRUE;
                            rm_part_data[p].did = 0;
                            err = SC_ERR_NONE;
                        }
                    }
                    else
                    {
                        sc_rm_did_t d;

                        /* Search for an unused DID */
                        for (d = dynamic_did_first; d < SC_RM_NUM_DOMAIN; d++)
                        {
                            /* Found unused? */
                            if (did_used[d] == SC_FALSE)
                            {
                                did_used[d] = SC_TRUE;
                                rm_part_data[p].did = d;
                                rm_max_did = MAX(rm_max_did, d);
                                err = SC_ERR_NONE;

                                break;
                            }
                        }
                    }
                }
                else
                {
                    /* Reuse caller DID */
                    rm_part_data[p].did = rm_part_data[caller_pt].did;
                    err = SC_ERR_NONE;
                }

                if (err == SC_ERR_NONE)
                {
                    *pt = p;
                }
                else
                {
                    /* No DID found so unallocate */
                    rm_part_data[p].used = SC_FALSE;
                }

                break;
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Make partition confidential                                              */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_confidential(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_bool_t retro)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    USED_PT(pt);
    NOT_LOCKED(pt);
    PARENT(pt);

    if (err == SC_ERR_NONE)
    {
        /* Mark partition */
        rm_part_data[pt].confidential= SC_TRUE;

        /* Remove permissions */
        if (retro != SC_FALSE)
        {
            sc_rm_idx_t r;
            sc_rm_mr_t m;

            /* Loop through all resources */
            for (r = 0; r < SC_NUM_RSRC; r++)
            {
                if (rm_rsrc_data[r].owner != pt)
                {
                    set_perms(rm_rsrc_data[r].perms, rm_part_data[pt].did,
                        SC_RM_PERM_NONE);
                }
            }
            
            /* Loop through all memory regions */
            for (m = 0; m < SC_RM_NUM_MEMREG; m++)
            {
                if (rm_mreg_data[m].owner != pt)
                {
                    set_perms(rm_mreg_data[m].perms, rm_part_data[pt].did,
                        SC_RM_PERM_NONE);
                }
            }        
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Free a resource partition and return resources to the parent partition   */
/*--------------------------------------------------------------------------*/
sc_err_t rm_partition_free(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    USED_PT(pt);
    NOT_SC_PT(pt);

    /* Check more parameters if caller not SC */
    if (caller_pt != SC_PT)
    {
        NOT_LOCKED(caller_pt);
        NOT_LOCKED(pt);
        NOT_RESTRICTED(caller_pt);
        PARENT(pt);
    }

    if (err == SC_ERR_NONE)
    {
        sc_rm_idx_t r;
        sc_pad_t n;
        sc_rm_mr_t m;
        sc_rm_pt_t p;

        /* Call timer service to stop wdog */
        timer_halt_wdog(pt);

        /* Free all child partitions */
        for (p = 0; p < SC_RM_NUM_PARTITION; p++)
        {
            /* Used and belongs to this partition? */
            if ((rm_part_data[p].used != SC_FALSE) && (rm_part_data[p].parent == pt))
            {
                rm_part_data[p].locked = SC_FALSE;
                (void) rm_partition_free(rm_part_data[p].parent, p);
            }
        }

        /* Return all resources to parent */
        for (r = 0; r < SC_NUM_RSRC; r++)
        {
            /* Is available? */
            if (rm_is_ridx_avail(r) == SC_FALSE)
            {
                continue;
            }

            /* Owned by this partition? */
            if (rm_rsrc_data[r].owner == pt)
            {
                /* Return attributes to the default */
                rm_rsrc_data[r].owner = rm_part_data[pt].parent;
                pm_update_ridx(r);
                rm_rsrc_data[r].pa = SC_RM_SPA_PASSTHRU;
                rm_rsrc_data[r].movable = SC_TRUE;
                clear_perms(rm_rsrc_data[r].perms);
                SIMU_ASRT(rm_rsrc_data[r].owner < SC_RM_NUM_PARTITION,
                    "bad owner pt");
                if (rm_part_data[rm_rsrc_data[r].owner].secure != SC_FALSE)
                {
                    /* Make secure when returned */
                    rm_rsrc_data[r].sa = SC_RM_SPA_ASSERT;
                    set_perms(rm_rsrc_data[r].perms,
                        rm_part_data[rm_rsrc_data[r].owner].did,
                        SC_RM_PERM_SEC_RW);
                }
                else
                {
                    /* Make not-secure when returned */
                    rm_rsrc_data[r].sa = SC_RM_SPA_NEGATE;
                    set_perms(rm_rsrc_data[r].perms,
                        rm_part_data[rm_rsrc_data[r].owner].did,
                        SC_RM_PERM_FULL);
                }

                /* Update the resource */
                update_rdc_resource(r, SC_TRUE, SC_TRUE);
            }
        }

        /* Return all pads to parent */
        for (n = 0; n < SC_NUM_PAD; n++)
        {
            /* Owned by this partition? */
            if (rm_pad_data[n].owner == pt)
            {
                rm_pad_data[n].owner = rm_part_data[pt].parent;
                rm_pad_data[n].movable = SC_TRUE;
            }
        }

        /* Delete child memory regions */
        for (m = 0; m < SC_RM_NUM_MEMREG; m++)
        {
            /* Owned by this partition? */
            if (rm_mreg_data[m].owner == pt)
            {
                sc_rm_mr_t m_parent = rm_mreg_data[m].parent;

                /* Check parms */
                SIMU_ASRT(m_parent < SC_RM_NUM_PARTITION,
                    "bad parent pt");

                if (rm_mreg_data[m].parent == m)
                {
                    continue;
                }
                
                if (rm_mreg_data[m_parent].owner == pt)
                {
                    (void) rm_memreg_free(SC_PT, m);
                }
                if (rm_mreg_data[m_parent].owner == rm_part_data[pt].parent)
                {
                    (void) rm_memreg_free(SC_PT, m);
                }           
            }
        }    

        /* Return all remaining memory regions */
        for (m = 0; m < SC_RM_NUM_MEMREG; m++)
        {
            /* Owned by this partition? */
            if (rm_mreg_data[m].owner == pt)
            {
                (void) rm_assign_memreg(SC_PT, rm_part_data[pt].parent, m);
            }
        }

        /* Free DID */        
        SIMU_ASRT(rm_part_data[pt].did < SC_RM_NUM_DOMAIN,
            "bad DID");
        if (rm_part_data[pt].isolated != SC_FALSE)
        {
            did_used[rm_part_data[pt].did] = SC_FALSE;
        }

        /* Free partition */
        rm_part_data[pt].used = SC_FALSE;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get partition of caller                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t rm_get_partition(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt)
{
    sc_err_t err = SC_ERR_NONE;
    
     /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        *pt = caller_pt;

        SIMU_ASRT(*pt < SC_RM_NUM_PARTITION,
            "bad pt");
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get enable state of a partition                                          */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_partition_used(sc_rm_pt_t pt)
{
    SIMU_ASRT(pt < SC_RM_NUM_PARTITION,
        "bad pt");

    return rm_part_data[pt].used;
}

/*--------------------------------------------------------------------------*/
/* Get security state of a partition                                        */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_secure_partition(sc_rm_pt_t caller_pt)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        rtn = rm_part_data[caller_pt].secure;
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Get isolation state of a partition                                       */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_partition_isolated(sc_rm_pt_t pt)
{
    SIMU_ASRT(pt < SC_RM_NUM_PARTITION,
        "bad pt");

    return rm_part_data[pt].isolated;
}

/*--------------------------------------------------------------------------*/
/* Get system access state of a partition                                   */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_sys_access(sc_rm_pt_t pt)
{
    sc_bool_t rtn;

    /* Check parms */
    SIMU_ASRT(pt < SC_RM_NUM_PARTITION,
        "bad pt");

    /* Is SC? */
    if (pt == SC_PT)
    {
        rtn = SC_TRUE;
    }
    /* Own SYSTEM? */
    else if (rm_is_resource_owned(pt, SC_R_SYSTEM) != SC_FALSE)
    {
        rtn = SC_TRUE;
    }
    /* Access to SYSTEM? */
    else
    {
        rtn = rm_part_data[pt].sys_access;
    }
    
    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Set partition that can control a partition                               */
/*--------------------------------------------------------------------------*/
void rm_set_control_partition(sc_rm_pt_t pt, sc_rm_pt_t control)
{
    /* Check parms */
    SIMU_ASRT(pt < SC_RM_NUM_PARTITION,
        "bad pt");
    SIMU_ASRT(control < SC_RM_NUM_PARTITION,
        "bad pt");

    rm_part_data[pt].control = control;
}

/*--------------------------------------------------------------------------*/
/* Get control partition                                                    */
/*--------------------------------------------------------------------------*/
sc_rm_pt_t rm_get_control_partition(sc_rm_pt_t pt)
{
    return rm_part_data[pt].control;
}

/*--------------------------------------------------------------------------*/
/* Get parent of a partition                                                */
/*--------------------------------------------------------------------------*/
sc_rm_pt_t rm_get_partition_parent(sc_rm_pt_t pt)
{
    SIMU_ASRT(pt < SC_RM_NUM_PARTITION,
        "bad pt");

    SIMU_ASRT(rm_part_data[pt].parent < SC_RM_NUM_PARTITION,
        "bad pt");

    return rm_part_data[pt].parent;
}

/*--------------------------------------------------------------------------*/
/* Get resource domain of caller                                            */
/*--------------------------------------------------------------------------*/
sc_rm_did_t rm_get_did(sc_rm_pt_t caller_pt)
{
    sc_rm_did_t did = SC_DID;

    SIMU_ASRT(caller_pt < SC_RM_NUM_PARTITION,
        "bad caller_pt");

    if (caller_pt < SC_RM_NUM_PARTITION)
    {
        did = rm_part_data[caller_pt].did;
    }

    SIMU_ASRT(did < SC_RM_NUM_DOMAIN,
        "bad did");

    return did;
}

/*--------------------------------------------------------------------------*/
/* Force a partition onto a static DID (assumes no assigned resources       */
/* or mem regions)                                                          */
/*--------------------------------------------------------------------------*/
sc_err_t rm_partition_static(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_rm_did_t did)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    ASRT_ERR(did < dynamic_did_first, SC_ERR_PARM);

    /* Check parameters */
    USED_PT(pt);
    NOT_LOCKED(pt);
    NOT_RESTRICTED(caller_pt);

    /* Check access rights */
    PARENT(pt);
    ASRT_ERR(did_used[did] == SC_FALSE, SC_ERR_UNAVAILABLE);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Check parms */
        SIMU_ASRT(rm_part_data[pt].did < SC_RM_NUM_DOMAIN,
            "bad DID");

        /* Swap DIDs */
        did_used[rm_part_data[pt].did] = SC_FALSE;
        rm_part_data[pt].did = did;
        rm_max_did = MAX(rm_max_did, did);
        did_used[rm_part_data[pt].did] = SC_TRUE;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Lock a partition                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t rm_partition_lock(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    PARENT(pt);

    if (err == SC_ERR_NONE)
    {
        /* Lock partition */
        rm_part_data[pt].locked = SC_TRUE;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set new parent for partition                                             */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_parent(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_rm_pt_t pt_parent)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_pt_t p;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);
    BOUND_PT(pt_parent);

    /* Check parameters */
    USED_PT(pt);
    USED_PT(pt_parent);
    NOT_LOCKED(pt);
    NOT_LOCKED(pt_parent);
    NOT_RESTRICTED(caller_pt);
    PARENT(pt);
    NOT_SC_PT(pt);

    /* Check for circular relationship */
    p = pt_parent;
    while ((err == SC_ERR_NONE) && (p != SC_PT))
    {
        if (rm_part_data[p].parent == pt)
        {
            err = SC_ERR_PARM;
        }

        p = rm_part_data[p].parent;
    }

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        sc_rm_idx_t r;
        sc_rm_mr_t m;

        /* Update parent */
        rm_part_data[pt].parent = pt_parent;

        /* Update all resources */
        for (r = 0; r < SC_NUM_RSRC; r++)
        {
            /* Resource owned by this partition? */
            if (rm_rsrc_data[r].owner == pt)
            {
                /* Update resource */
                update_rdc_resource(r, SC_FALSE, SC_TRUE);
            }
        }

        /* Update all memory regions */
        for (m = 0; m < SC_RM_NUM_MEMREG; m++)
        {
            /* Mem region owned by this partition? */
            if ((rm_mreg_data[m].used != SC_FALSE) 
                && (rm_mreg_data[m].owner == pt))
            {
                /* Update memory region */
                (void) update_rdc_memreg(m, rm_mreg_data[m].start,
                    rm_mreg_data[m].end, rm_mreg_data[m].start,
                    rm_mreg_data[m].end);
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Check if caller is the parent of a partition                             */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_parent(sc_rm_pt_t caller_pt, sc_rm_pt_t pt)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    if (err == SC_ERR_NONE)
    {
        /* Check parent */
        rtn = (caller_pt == rm_part_data[pt].parent);
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check if caller is an ancestor of owner                                  */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_check_ancestor(sc_rm_pt_t caller_pt, sc_rm_pt_t pt_owner)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt_owner);

    if (err == SC_ERR_NONE)
    {
        sc_rm_pt_t pt;

        /* SCU always ancestor */
        if (caller_pt == SC_PT)
        {
            rtn = SC_TRUE;
        }

        /* Loop looking for ancestor */
        pt = pt_owner;
        while ((rtn == SC_FALSE) && (pt != SC_PT))
        {
            if (caller_pt == pt)
            {
                rtn = SC_TRUE;
            }

            pt = rm_part_data[pt].parent;
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Move all resources/pads owned by src partition to dst partition          */
/*--------------------------------------------------------------------------*/
sc_err_t rm_move_all(sc_rm_pt_t caller_pt, sc_rm_pt_t pt_src,
    sc_rm_pt_t pt_dst, sc_bool_t move_rsrc, sc_bool_t move_pads)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt_src);
    BOUND_PT(pt_dst);

    /* Check parameters */
    USED_PT(pt_src);
    USED_PT(pt_dst);
    NOT_LOCKED(pt_src);
    NOT_LOCKED(pt_dst);
    NOT_RESTRICTED(caller_pt);
    ASRT_ERR(pt_src != pt_dst, SC_ERR_PARM);
    ANCESTOR(pt_src);

    if (err == SC_ERR_NONE)
    {
        /* Move all resources from src to dst */
        if (move_rsrc != SC_FALSE)
        {
            sc_rm_idx_t r;
            sc_rm_idx_t jr1 = SC_NUM_RESOURCE, jr3 = SC_NUM_RESOURCE;

            /* Get CAAM indexes */
            rm_check_map_ridx_v(SC_R_CAAM_JR1_OUT, &jr1);
            rm_check_map_ridx_v(SC_R_CAAM_JR3_OUT, &jr3);

            /* Loop over all resources */
            for (r = 0; r < SC_NUM_RSRC; r++)
            {
                /* Check if available */
                if (rm_is_ridx_avail(r) == SC_FALSE)
                {
                    continue;
                }

                /* Is movable? */
                if ((rm_rsrc_data[r].movable != SC_FALSE) 
                    && ((rm_rsrc_data[r].owner == pt_src)
                    || (caller_pt == SC_PT)))
                {
                    /* Only allow JR_OUT resources to be assigned to child */
                    if ((r >= jr1)
                        && (r <= jr3))
                    {
                        ANCESTOR_C(pt_dst);
                    }

                    /* Update owner */
                    rm_rsrc_data[r].owner = pt_dst;
                    pm_update_ridx(r);

                    /* Update attributes */
                    rm_rsrc_data[r].pa = SC_RM_SPA_PASSTHRU;
                    clear_perms(rm_rsrc_data[r].perms);
                    if (rm_part_data[pt_dst].secure != SC_FALSE)
                    {
                        /* Secure */
                        rm_rsrc_data[r].sa = SC_RM_SPA_ASSERT;
                        set_perms(rm_rsrc_data[r].perms,
                            rm_part_data[pt_dst].did, SC_RM_PERM_SEC_RW);
                    }
                    else
                    {
                        /* Not secure */
                        rm_rsrc_data[r].sa = SC_RM_SPA_NEGATE;
                        set_perms(rm_rsrc_data[r].perms,
                            rm_part_data[pt_dst].did, SC_RM_PERM_FULL);
                    }

                    /* Update SID */
                    rm_rsrc_data[r].sid = SC_BYPASS_SID;
                    update_rdc_resource(r, SC_TRUE, SC_TRUE);
                }
            }

            /* Update memory regions that might now be in different MRCs */
            rm_load_memrg();
        }

        /* Move all pads from src to dst */
        if (move_pads != SC_FALSE)
        {
            sc_pad_t n;

            for (n = 0; n < SC_NUM_PAD; n++)
            {
                /* Is movable? */
                if ((rm_pad_data[n].movable  != SC_FALSE)
                    && ((rm_pad_data[n].owner == pt_src)
                    || (caller_pt == SC_PT)))
                {
                    rm_pad_data[n].owner = pt_dst;
                }
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Assign a resource to a resource partition                                */
/*--------------------------------------------------------------------------*/
sc_err_t rm_assign_resource(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_rsrc_t r0, rN;
    sc_bool_t sync_mem = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    USED_PT(pt);
    NOT_LOCKED(caller_pt);
    NOT_LOCKED(pt);
    NOT_RESTRICTED(caller_pt);

    /* Is one or all resources? */
    if (resource == SC_R_ALL)
    {
        /* Set range to cover all resources */
        r0 = 0;
        rN = SC_NUM_RESOURCE - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_RSRC(resource, idx);
        ANCESTOR(rm_rsrc_data[idx].owner);
        NOT_LOCKED(rm_rsrc_data[idx].owner);

        /* Only allow JR_OUT resources to be assigned to child */
        if ((resource >= SC_R_CAAM_JR1_OUT)
            && (resource <= SC_R_CAAM_JR3_OUT))
        {
            ANCESTOR(pt);
        }

        /* Set range to cover only the specified resource */
        r0 = resource;
        rN = resource;
    }

    if (err == SC_ERR_NONE)
    {
        sc_rsrc_t r;

        /* Process range of resources */
        for (r = r0; r <= rN; r++)
        {
            sc_rm_did_t old_did;

            if (resource == SC_R_ALL)
            {
                /* Check parameters */
                BOUND_RSRC_C(r, idx);

                /* Check ownership */
                ANCESTOR_C(rm_rsrc_data[idx].owner);

                /* Check permissions */
                NOT_LOCKED_C(rm_rsrc_data[idx].owner);

                /* Only allow JR_OUT resources to be assigned to child */
                if ((r >= SC_R_CAAM_JR1_OUT)
                    && (r <= SC_R_CAAM_JR3_OUT))
                {
                    ANCESTOR_C(pt);
                }
            }

            /* Keep old DID */
            SIMU_ASRT(rm_rsrc_data[idx].owner < SC_RM_NUM_PARTITION,
                "bad owner");
            old_did = rm_part_data[rm_rsrc_data[idx].owner].did;

            /* Assign resource */
            rm_rsrc_data[idx].owner = pt;
            pm_update_ridx(idx);

            /* Default access permissions */
            rm_rsrc_data[idx].pa = SC_RM_SPA_PASSTHRU;
            clear_perms(rm_rsrc_data[idx].perms);
            if (rm_part_data[pt].secure != SC_FALSE)
            {
                rm_rsrc_data[idx].sa = SC_RM_SPA_ASSERT;
                set_perms(rm_rsrc_data[idx].perms, rm_part_data[pt].did,
                    SC_RM_PERM_SEC_RW);
            }
            else
            {
                rm_rsrc_data[idx].sa = SC_RM_SPA_NEGATE;
                set_perms(rm_rsrc_data[idx].perms, rm_part_data[pt].did,
                    SC_RM_PERM_FULL);
            }
            rm_rsrc_data[idx].movable = SC_TRUE;

            /* Set SID */
            rm_rsrc_data[idx].sid = SC_BYPASS_SID;

            /* Update resource */
            update_rdc_resource(idx, SC_TRUE, SC_TRUE);

            /* Check if MRC might change */
            if ((rm_is_ridx_master(idx) != SC_FALSE) 
                && (old_did != rm_part_data[pt].did))
            {
                sync_mem = SC_TRUE;
            }
        }
    }

    /* Update memory regions that might now be in different MRCs */
    if ((err == SC_ERR_NONE) && (sync_mem != SC_FALSE))
    {
        rm_load_memrg();
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Flag resource as movable or not                                          */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_resource_movable(sc_rm_pt_t caller_pt,
    sc_rsrc_t resource_fst, sc_rsrc_t resource_lst, sc_bool_t movable)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_rsrc_t r0, rN;
    sc_rsrc_t new_resource_fst = resource_fst;
    sc_rsrc_t new_resource_lst = resource_lst;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Is one or all resources? */
    if ((new_resource_fst == SC_R_ALL) || (new_resource_lst == SC_R_ALL))
    {
        /* Set range to cover all resources */
        r0 = 0;
        rN = SC_NUM_RESOURCE - 1U;
    }
    else
    {
        if (new_resource_fst > new_resource_lst)
        {
            sc_rsrc_t temp = new_resource_fst;
            new_resource_fst = new_resource_lst;
            new_resource_lst = temp;
        }

        /* Check parameters */
        if (new_resource_lst >= SC_NUM_RESOURCE)
        {
            err = SC_ERR_PARM;
        }
        else if (new_resource_fst > new_resource_lst)
        {
            err = SC_ERR_PARM;
        }
        else
        {
            ; /* Intentional empty else */
        }

        /* Set range to cover only the specified resource */
        r0 = new_resource_fst;
        rN = new_resource_lst;
    }

    if (err == SC_ERR_NONE)
    {
        sc_rsrc_t r;

        /* Process range of resources */
        for (r = r0; r <= rN; r++)
        {
            /* Check parameters */
            BOUND_RSRC_C(r, idx);

            /* Check ownership */
            ANCESTOR_C(rm_rsrc_data[idx].owner);

            /* Check permissions */
            NOT_LOCKED_C(rm_rsrc_data[idx].owner);

            /* Set flag */
            rm_rsrc_data[idx].movable = movable;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Flag resource group as movable or not                                    */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_subsys_rsrc_movable(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_bool_t movable)
{
    sc_err_t err = SC_ERR_NONE;
    sc_sub_t ss;
    sc_ss_idx_t ss_idx;
    sc_rm_idx_t idx;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        /* Get subsystem */
        rm_get_ridx_ss_info(idx, &ss, &ss_idx);

        /* Loop through all resources and flag */
        for (idx = 0; idx < SC_NUM_RSRC; idx++)
        {
            ANCESTOR_C(rm_rsrc_data[idx].owner);

            if (rm_rsrc_data[idx].ss == ss)
            {
                rm_rsrc_data[idx].movable = movable;
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set attributes for a master resource                                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_master_attributes(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_spa_t sa, sc_rm_spa_t pa, sc_bool_t smmu_bypass)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_rsrc_t r0, rN;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    NOT_RESTRICTED(caller_pt);
    ASRT_ERR(sa <= SC_RM_SPA_NEGATE, SC_ERR_PARM);
    ASRT_ERR(pa <= SC_RM_SPA_NEGATE, SC_ERR_PARM);

    /* Is one or all resources? */
    if (resource == SC_R_ALL)
    {
        /* Set range to cover all resources */
        r0 = 0;
        rN = SC_NUM_RESOURCE - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_RSRC(resource, idx);
        MASTER(idx);
        ANCESTOR(rm_rsrc_data[idx].owner);
        if ((err == SC_ERR_NONE) && (caller_pt != SC_PT) && (caller_pt 
            == rm_rsrc_data[idx].owner))
        {
            err = SC_ERR_NOACCESS;
        }

        /* Check permissions */
        NOT_LOCKED(rm_rsrc_data[idx].owner);

        /* Set range to cover only the specified resource */
        r0 = resource;
        rN = resource;
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
                MASTER_C(idx);

                /* Check ownership */
                ANCESTOR_C(rm_rsrc_data[idx].owner);
                ASRT_C((caller_pt == SC_PT) || (caller_pt != rm_rsrc_data[idx].owner));

                /* Check permissions */
                NOT_LOCKED_C(rm_rsrc_data[idx].owner);
            }

            /* Change attributes */
            if (rm_part_data[caller_pt].secure != SC_FALSE)
            {
                rm_rsrc_data[idx].sa = sa;
            }
            rm_rsrc_data[idx].pa = pa;

            if (smmu_bypass != SC_FALSE)
            {
                rm_rsrc_data[idx].sid = SC_BYPASS_SID;
            }

            update_rdc_resource(idx, SC_TRUE, SC_FALSE);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set streamID for a master resource                                       */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_master_sid(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_sid_t sid)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_rsrc_t r0, rN;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    NOT_RESTRICTED(caller_pt);
    ASRT_ERR((sid != 0U) && ((sid & ~SC_RM_SID_MASK) == 0U), SC_ERR_PARM);

    /* Is one or all resources? */
    if (resource == SC_R_ALL)
    {
        /* Set range to cover all resources */
        r0 = 0;
        rN = SC_NUM_RESOURCE - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_RSRC(resource, idx);
        MASTER(idx);
        ANCESTOR(rm_rsrc_data[idx].owner);
        NOT_LOCKED(rm_rsrc_data[idx].owner);

        /* Set range to cover only the specified resource */
        r0 = resource;
        rN = resource;
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
                MASTER_C(idx);

                /* Check ownership */
                ANCESTOR_C(rm_rsrc_data[idx].owner);

                /* Check permissions */
                NOT_LOCKED_C(rm_rsrc_data[idx].owner);
            }

            /* Update resource */
            rm_rsrc_data[idx].sid = sid;
            update_rdc_resource(idx, SC_TRUE, SC_FALSE);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Update master                                                            */
/*--------------------------------------------------------------------------*/
sc_err_t rm_update_master(sc_rm_idx_t idx)
{
    SIMU_ASRT(idx < SC_NUM_RSRC, "bad rsrc idx")

    update_rdc_resource(idx, SC_TRUE, SC_FALSE);

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Set access permissions for a peripheral resource                         */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_peripheral_permissions(sc_rm_pt_t caller_pt,
    sc_rsrc_t resource, sc_rm_pt_t pt, sc_rm_perm_t perm)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_rsrc_t r0, rN;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    ASRT_ERR((pt < SC_RM_NUM_PARTITION) || (pt == SC_RM_PT_ALL), SC_ERR_PARM);
    ASRT_ERR((pt >= SC_RM_NUM_PARTITION) || (rm_part_data[pt].used != SC_FALSE),
        SC_ERR_PARM);
    ASRT_ERR(perm <= SC_RM_PERM_FULL, SC_ERR_PARM);

    /* Check permissions */
    ASRT_ERR((pt >= SC_RM_NUM_PARTITION) || (rm_part_data[pt].confidential 
        == SC_FALSE) || (pt == caller_pt), SC_ERR_LOCKED);

    /* Is one or all resources? */
    if (resource == SC_R_ALL)
    {
        /* Set range to cover all resources */
        r0 = 0;
        rN = SC_NUM_RESOURCE - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_RSRC(resource, idx);

        /* Check permissions */
        ANCESTOR(rm_rsrc_data[idx].owner);
        NOT_LOCKED(rm_rsrc_data[idx].owner);      

        /* Update SYSTEM */
        if ((err == SC_ERR_NONE) && (resource == SC_R_SYSTEM))
        {
            sc_bool_t access;

            /* Grant access if permission is not none */
            if (perm == SC_RM_PERM_NONE)
            {
                access = SC_FALSE;
            }
            else
            {
                access = SC_TRUE;
            }
            
            /* Do one or all partitions? */
            if (pt == SC_RM_PT_ALL)
            {
                sc_rm_pt_t p;
            
                /* Loop through all partitions */
                for (p = 0; p < SC_RM_NUM_PARTITION; p++)
                {
                    rm_part_data[p].sys_access = access;
                }
            }
            else
            {
                rm_part_data[pt].sys_access = access;
            }
        }
        else
        {
            /* Check parameters */
            PERIPHERAL(idx);
        }

        /* Set range to cover only the specified resource */
        r0 = resource;
        rN = resource;
    }

    if ((err == SC_ERR_NONE) && (resource != SC_R_SYSTEM))
    {
        sc_rsrc_t r;

        /* Process range of resources */
        for (r = r0; r <= rN; r++)
        {
            if (resource == SC_R_ALL)
            {
                /* Check parameters */
                BOUND_RSRC_C(r, idx);
                PERIPHERAL_C(idx);

                /* Check ownership */
                ANCESTOR_C(rm_rsrc_data[idx].owner);

                /* Check permissions */
                NOT_LOCKED_C(rm_rsrc_data[idx].owner);
            }

            /* Do one or all partitions? */
            if (pt == SC_RM_PT_ALL)
            {
                sc_rm_did_t d;

                /* Loop through all domains */
                for (d = 0; d < SC_RM_NUM_DOMAIN; d++)
                {
                    (void) set_perms(rm_rsrc_data[idx].perms, d, perm);
                }
            }
            else
            {
                (void) set_perms(rm_rsrc_data[idx].perms, rm_part_data[pt].did,
                    perm);
            }

            (void) update_rdc_resource(idx, SC_FALSE, SC_TRUE);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Update peripheral                                                        */
/*--------------------------------------------------------------------------*/
sc_err_t rm_update_peripheral(sc_rm_idx_t idx)
{
    SIMU_ASRT(idx < SC_NUM_RSRC, "bad rsrc idx")

    update_rdc_resource(idx, SC_FALSE, SC_TRUE);

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Update resoruce                                                          */
/*--------------------------------------------------------------------------*/
void rm_update_resource(sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;

    /* Check parameters */
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        update_rdc_resource(idx, SC_TRUE, SC_TRUE);
    }
}

/*--------------------------------------------------------------------------*/
/* Get resource subsystem info                                              */
/*--------------------------------------------------------------------------*/
void rm_get_ridx_ss_info(sc_rm_idx_t idx, sc_sub_t *ss,
    sc_ss_idx_t *ss_idx)
{
    SIMU_ASRT(idx < SC_NUM_RSRC, "bad rsrc idx");

    *ss = rm_rsrc_data[idx].ss;
    *ss_idx = rm_rsrc_data[idx].ss_idx;

    SIMU_ASRT(*ss <= SC_SUBSYS_NA, "bad ss")
}

/*--------------------------------------------------------------------------*/
/* Check resource range and return the unified resource index               */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_check_map_ridx(sc_rsrc_t resource, sc_rm_idx_t *idx)
{
    sc_bool_t rtn;
    
    /* Check parameters */
    if (resource >= SC_NUM_RESOURCE)
    {
        rtn = SC_FALSE;
    }
    else if (rm_rsrc_map_data[resource] == SC_NUM_RSRC)
    {
        rtn = SC_FALSE;
    }

    /* Check if available */
    else if (soc_rsrc_avail(resource) == SC_FALSE)
    {
        rtn = SC_FALSE;
    }
    else
    {
        /* Return index */
        if (idx != NULL)
        {
            *idx = rm_rsrc_map_data[resource];

            SIMU_ASRT(*idx < SC_NUM_RSRC,
                "bad rsrc idx");

        }
        rtn = SC_TRUE;
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check resource range and return the unified resource index               */
/*--------------------------------------------------------------------------*/
void rm_check_map_ridx_v(sc_rsrc_t resource, sc_rm_idx_t *idx)
{
    /* Check parameters */
    if ((resource < SC_NUM_RESOURCE) && (rm_rsrc_map_data[resource]
        != SC_NUM_RSRC))
    {
        /* Return index */
        *idx = rm_rsrc_map_data[resource];

        SIMU_ASRT(*idx < SC_NUM_RSRC,
            "bad rsrc idx");        
    }
}

/*--------------------------------------------------------------------------*/
/* Check if resource owned                                                  */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_resource_owned(sc_rm_pt_t caller_pt, sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;
    sc_rm_idx_t idx = 0;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        rtn = rm_is_ridx_owned(caller_pt, idx);
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check if resource index owned                                            */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_ridx_owned(sc_rm_pt_t caller_pt, sc_rm_idx_t idx)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        SIMU_ASRT(idx < SC_NUM_RSRC,
            "bad rsrc idx");
        
        /* Check availability */
        if (rm_is_ridx_avail(idx) != SC_FALSE)
        {
            rtn = (rm_rsrc_data[idx].owner == caller_pt);
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check if resource available                                              */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_resource_avail(sc_rsrc_t resource)
{
    sc_bool_t rtn = SC_FALSE;
    sc_rm_idx_t idx = 0U;

    if (resource < SC_NUM_RESOURCE)
    {
        rtn = rm_check_map_ridx(resource, &idx);
    }

    /* Check table */
    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Convert resource index to resource                                       */
/*--------------------------------------------------------------------------*/
sc_rsrc_t rm_get_resource(sc_rm_idx_t idx)
{
    sc_sub_t ss = 0U;
    ss_idx_t ss_idx = 0U;

    SIMU_ASRT(idx < SC_NUM_RSRC, "bad rsrc idx");

    /* Convert RM index to SS info */
    rm_get_ridx_ss_info(idx, &ss, &ss_idx);

    /* Convert to resource */
    return ss_get_resource(ss, ss_idx);
}

/*--------------------------------------------------------------------------*/
/* Check if resource index available                                        */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_ridx_avail(sc_rm_idx_t idx)
{
    /* Check if available */
    return soc_rsrc_avail(rm_get_resource(idx));
}

/*--------------------------------------------------------------------------*/
/* Check if resource access allowed                                         */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_resource_access_allowed(sc_rm_pt_t caller_pt,
    sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;
    sc_rm_idx_t idx = 0;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        rtn = rm_is_ridx_access_allowed(caller_pt, idx);
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check if resource index access allowed                                   */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_ridx_access_allowed(sc_rm_pt_t caller_pt, sc_rm_idx_t idx)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    SIMU_ASRT(idx < SC_NUM_RSRC,
        "bad rsrc idx");
    SIMU_ASRT(rm_rsrc_data[idx].owner < SC_RM_NUM_PARTITION,
        "bad owner pt");

    if (err == SC_ERR_NONE)
    {
        /* Check if available */
        if (rm_is_ridx_avail(idx) == SC_FALSE)
        {
            rtn = SC_FALSE;
        }
        /* Check parent grant */
        else if ((rm_part_data[rm_rsrc_data[idx].owner].grant != SC_FALSE)
            && (rm_part_data[rm_rsrc_data[idx].owner].parent == caller_pt))
        {
            rtn = SC_TRUE;
        }
        else
        {
            rtn = (rm_rsrc_data[idx].owner == caller_pt);
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Return the owner partition for a resource                                */
/*--------------------------------------------------------------------------*/
sc_err_t rm_get_resource_owner(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_pt_t *pt)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;

    /* Check parameters */
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        rm_get_ridx_owner(idx, pt);

        SIMU_ASRT(*pt < SC_RM_NUM_PARTITION, "bad pt");
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Return the owner partition for a rsrc                                    */
/*--------------------------------------------------------------------------*/
void rm_get_ridx_owner(sc_rm_idx_t idx, sc_rm_pt_t *pt)
{
    SIMU_ASRT(idx < SC_NUM_RSRC,
        "bad rsrc idx");

    if (idx < SC_NUM_RSRC)
    {
        *pt=  rm_rsrc_data[idx].owner;
    }
    else
    {
        *pt = SC_PT;
    }

    SIMU_ASRT(*pt < SC_RM_NUM_PARTITION, "bad pt");
}

/*--------------------------------------------------------------------------*/
/* Check if resource is a master                                            */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_resource_master(sc_rm_pt_t caller_pt, sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;
    sc_rm_idx_t idx = 0;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        if (rm_is_ridx_owned(caller_pt, idx) != SC_FALSE)
        {
            rtn = rm_is_ridx_master(idx);
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check if resource is a master                                            */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_ridx_master(sc_rm_idx_t idx)
{
    sc_bool_t rtn; 
        
    SIMU_ASRT(idx < SC_NUM_RSRC,
        "bad rsrc idx");

    /* Check if board */
    if (rm_rsrc_data[idx].ss > SC_SUBSYS_LAST)
    {
        rtn = SC_FALSE;
    }

    /* Check if available */
    else if (rm_is_ridx_avail(idx) == SC_FALSE)
    {
        rtn = SC_FALSE;
    }
    else
    {
        SIMU_ASRT(rm_rsrc_data[idx].ss < SC_NUM_SUBSYS,
            "bad ss");

        rtn = ss_base_info[rm_rsrc_data[idx].ss]
            ->rsrc[rm_rsrc_data[idx].ss_idx].master;
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check if resource is a peripheral                                        */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_resource_peripheral(sc_rm_pt_t caller_pt, sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;
    sc_rm_idx_t idx = 0;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        if (rm_is_ridx_owned(caller_pt, idx) != SC_FALSE)
        {
            rtn = rm_is_ridx_peripheral(idx);
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Check if resource is a peripheral                                        */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_ridx_peripheral(sc_rm_idx_t idx)
{
    sc_bool_t rtn;
    
    SIMU_ASRT(idx < SC_NUM_RSRC,
        "bad rsrc idx");

    /* Check if board */
    if (rm_rsrc_data[idx].ss > SC_SUBSYS_LAST)
    {
        rtn = SC_FALSE;
    }

    /* Check if available */
    else if (rm_is_ridx_avail(idx) == SC_FALSE)
    {
        rtn = SC_FALSE;
    }
    else
    {
        SIMU_ASRT(rm_rsrc_data[idx].ss < SC_NUM_SUBSYS,
            "bad ss");

        rtn = ss_base_info[rm_rsrc_data[idx].ss]->
            rsrc[rm_rsrc_data[idx].ss_idx].peripheral;
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Return resource info                                                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_get_resource_info(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_sid_t *sid)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Check parameters */
    ACCESS_ALLOWED(caller_pt, idx);

    if (err == SC_ERR_NONE)
    {
        /* Return info */
        if (sid != NULL)
        {
            *sid = rm_rsrc_data[idx].sid;

            /* Check SID */
            SIMU_ASRT((*sid & ~SC_RM_SID_MASK) == 0U, "bad sid");
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set resource block state                                                 */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_ridx_block(sc_rm_idx_t idx, sc_bool_t block)
{
    /* Check parms */
    SIMU_ASRT(idx < SC_NUM_RSRC,
        "bad rsrc idx");

    sc_bool_t rtn = rm_rsrc_data[idx].block;

    rm_rsrc_data[idx].block = block;

    /* Update resource */
    update_rdc_resource(idx, SC_FALSE, SC_TRUE);

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Allocate a memory region                                                 */
/*--------------------------------------------------------------------------*/
sc_err_t rm_memreg_alloc(sc_rm_pt_t caller_pt, sc_rm_mr_t *mr,
    sc_faddr_t addr_start, sc_faddr_t addr_end)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_mr_t m, m_found;
    sc_bool_t found = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Check parameters */
        if ((addr_start & MRC_ALIGN) != 0ULL)
        {
            err = SC_ERR_PARM;
        }
        else if ((addr_end & MRC_ALIGN) != MRC_ALIGN)
        {
            err = SC_ERR_PARM;
        }
        else
        {
            ; /* Intentional empty else */
        }
    }

    /* Check permissions */
    NOT_LOCKED(caller_pt);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Check if spanning across multiple existing regions */
        for (m = 0; m < SC_RM_NUM_MEMREG; m++)
        {
            if ((rm_mreg_data[m].used != SC_FALSE)
                && ((addr_start >= rm_mreg_data[m].start)
                && (addr_start <= rm_mreg_data[m].end))
                && !((addr_end >= rm_mreg_data[m].start)
                && (addr_end <= rm_mreg_data[m].end)))
            {
                err = SC_ERR_PARM;
            }
            else if ((rm_mreg_data[m].used != SC_FALSE) 
                && !((addr_start >= rm_mreg_data[m].start)
                && (addr_start <= rm_mreg_data[m].end))
                && ((addr_end >= rm_mreg_data[m].start)
                && (addr_end <= rm_mreg_data[m].end)))
            {
                err = SC_ERR_PARM;
            }
            else
            {
                ; /* Intentional empty else */
            }
        }
    }

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Find parent memory space */
        found = SC_FALSE;
        for (m = 0; m < SC_RM_NUM_MEMREG; m++)
        {
            if ((rm_mreg_data[m].used != SC_FALSE) 
                && (rm_mreg_data[m].owner == caller_pt)
                && (addr_start >= rm_mreg_data[m].start)
                && (addr_start <= rm_mreg_data[m].end))
            {
                found = SC_TRUE;
                m_found = m;
                break;
            }
        }
    }

    /* Check if found */
    ASRT_ERR((caller_pt == SC_PT) || (found != SC_FALSE), SC_ERR_NOACCESS);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Find unallocated memory region */
        err = SC_ERR_UNAVAILABLE;
        for (m = 0; m < SC_RM_NUM_MEMREG; m++)
        {
            if (rm_mreg_data[m].used == SC_FALSE)
            {
                rm_mreg_data[m].used = SC_TRUE;
                rm_mreg_data[m].owner = caller_pt;
                rm_mreg_data[m].start = addr_start;
                rm_mreg_data[m].end = addr_end;
                rm_mreg_data[m].det = 0;
                rm_mreg_data[m].rmsg = 0;

                /* Found? */
                if (found != SC_FALSE)
                {
                    rm_mreg_data[m].parent = m_found;
                    copy_perms(m_found, m);
                }
                else
                {
                    rm_mreg_data[m].parent = m;

                    /* Update perms */
                    clear_perms(rm_mreg_data[m].perms);                    
                    if (rm_part_data[caller_pt].secure != SC_FALSE)
                    {
                        /* Secure access by default */
                        set_perms(rm_mreg_data[m].perms,
                            rm_part_data[caller_pt].did, SC_RM_PERM_SEC_RW);
                    }
                    else
                    {
                        /* Full access by default */
                        set_perms(rm_mreg_data[m].perms,
                            rm_part_data[caller_pt].did, SC_RM_PERM_FULL);
                    }
                }

                /* Update mem region */
                err = update_rdc_memreg(m, rm_mreg_data[m].start,
                    rm_mreg_data[m].end, rm_mreg_data[m].start,
                    rm_mreg_data[m].end);

                /* Check for error */
                if (err == SC_ERR_NONE)
                {                   
                    if (mr != NULL)
                    {
                        /* Return memory region index */
                        *mr = m;

                        /* Update in-order memory list */
                        rm_mreg_list[rm_mreg_list_count] = m;
                        rm_mreg_list_count++;

                        /* Check mr */
                        SIMU_ASRT(*mr < SC_RM_NUM_MEMREG,
                            "bad mr");
                    }
                }
                else
                {
                    rm_mreg_data[m].used = SC_FALSE;                    
                }

                break;
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Split a memory region                                                    */
/*--------------------------------------------------------------------------*/
sc_err_t rm_memreg_split(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_rm_mr_t *mr_ret, sc_faddr_t addr_start, sc_faddr_t addr_end)
{
    sc_err_t err = SC_ERR_NONE;    
    sc_faddr_t start = 0ULL;
    uint32_t num_co = 0U;
    sc_rm_mr_t m;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_MR(mr);

    /* Check parameters */
    USED_MR(mr);

    /* Check access rights */
    if ((err == SC_ERR_NONE) && (caller_pt != SC_PT))
    {
        NOT_LOCKED(rm_mreg_data[mr].owner);
        ANCESTOR(rm_mreg_data[mr].owner);
    }

    /* Cannot split coincident region */
    for (m = 0; m < SC_RM_NUM_MEMREG; m++)
    {
        if ((rm_mreg_data[m].used) 
            && (rm_mreg_data[m].start == rm_mreg_data[mr].start) 
            && (rm_mreg_data[m].end == rm_mreg_data[mr].end))
        {
            num_co++;
        }
    }
    ASRT_ERR((caller_pt == SC_PT) || (num_co <= 1U), SC_ERR_BUSY);

    /* Check address */
    if (err == SC_ERR_NONE)
    {
        sc_faddr_t end;

        start = rm_mreg_data[mr].start;
        end = rm_mreg_data[mr].end;
        if ((addr_start == start) && (addr_end == end))
        {
            err = SC_ERR_PARM;
        }
        else if ((addr_start < start) || (addr_end > end))
        {
            err = SC_ERR_PARM;
        }
        else if ((addr_start != start) && (addr_end != end))
        {
            err = SC_ERR_PARM;
        }
        else
        {
            ; /* Intentional empty else */
        }
    }

    if (err == SC_ERR_NONE)
    {
        /* Allocate new region (also checks many parameters) */
        if (caller_pt != SC_PT)
        {
            /* Allocate as caller */
            err = rm_memreg_alloc(caller_pt, mr_ret, addr_start,
                addr_end);
        }
        else
        {
            /* Allocate as current region owner */
            err = rm_memreg_alloc(rm_mreg_data[mr].owner, mr_ret,
                addr_start, addr_end);
        }
    }

    if (err == SC_ERR_NONE)
    {
        sc_faddr_t new_start, new_end;

        if (rm_mreg_data[mr].parent == mr)
        {
            rm_mreg_data[*mr_ret].parent = *mr_ret;
        }
        else
        {
            rm_mreg_data[*mr_ret].parent = rm_mreg_data[mr].parent;
        }

        /* Copy new */
        new_start = rm_mreg_data[mr].start;
        new_end = rm_mreg_data[mr].end;

        /* Split */
        if (addr_start == start)
        {
            new_start = addr_end + 1ULL;
        }
        else
        {
            new_end = addr_start - 1ULL;
        }

        /* Update HW */
        err = update_rdc_memreg(mr, rm_mreg_data[mr].start,
            rm_mreg_data[mr].end, new_start, new_end);   

        /* Update data */
        rm_mreg_data[mr].start = new_start;
        rm_mreg_data[mr].end = new_end;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Fragment memory region                                                   */
/*--------------------------------------------------------------------------*/
sc_err_t rm_memreg_frag(sc_rm_pt_t caller_pt, sc_rm_mr_t *mr_ret, 
    sc_faddr_t addr_start, sc_faddr_t addr_end)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_mr_t mr;
    sc_faddr_t mr_start, mr_end;

    /* Find memory region */
    FUNC_ERR(rm_find_memreg(caller_pt, &mr, addr_start,
        addr_end));

    FUNC_ERR(rm_get_memreg_info(caller_pt, mr, &mr_start, &mr_end));

    if (err == SC_ERR_NONE)
    {
        /* Coincident? */
        if ((addr_start == mr_start) && (addr_end == mr_end))
        {
            *mr_ret = mr;
        }
        else
        {
            /* Front */
            if (addr_start == mr_start)
            {
                sc_rm_mr_t temp_mr;

                FUNC_ERR(rm_memreg_split(caller_pt, mr, &temp_mr,
                    addr_end + 1ULL, mr_end));

                if (err == SC_ERR_NONE)
                {
                    *mr_ret = mr;
                }
            }
            /* End */
            else if (addr_end == mr_end)
            {
                FUNC_ERR(rm_memreg_split(caller_pt, mr, mr_ret, addr_start,
                    addr_end));
            }
            /* Middle */
            else
            {
                sc_rm_mr_t temp_mr;

                FUNC_ERR(rm_memreg_split(caller_pt, mr, &temp_mr,
                    addr_end + 1ULL, mr_end));

                FUNC_ERR(rm_memreg_split(caller_pt, mr, mr_ret, addr_start,
                    addr_end));
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Free a memory region                                                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_memreg_free(sc_rm_pt_t caller_pt, sc_rm_mr_t mr)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_mr_t m0, mN;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Is one or all regions? */
    if (mr == SC_RM_MR_ALL)
    {
        /* Set range to cover all regions */
        m0 = 0;
        mN = SC_RM_NUM_MEMREG - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_MR(mr);
        USED_MR(mr);
        if ((err == SC_ERR_NONE) && (caller_pt != SC_PT))
        {
            NOT_LOCKED(rm_mreg_data[mr].owner);
            ANCESTOR(rm_mreg_data[mr].owner);
        }

        /* Set range to cover only the specified region */
        m0 = mr;
        mN = mr;
    }

    if (err == SC_ERR_NONE)
    {
        sc_rm_mr_t m;
        sc_rm_mr_t mi;

        /* Process range of regions */
        for (m = m0; m <= mN; m++)
        {
            if (mr != SC_RM_MR_ALL)
            {
                /* Check parameters */
                USED_MR_C(m);

                if (caller_pt != SC_PT)
                {
                    /* Check ownership */
                    ANCESTOR_C(rm_mreg_data[m].owner);

                    /* Check permissions */
                    NOT_LOCKED_C(rm_mreg_data[m].owner);
                }
            }

            /* Free region */
            rm_mreg_data[m].used = SC_FALSE;

            /* Update RDC */
            (void) update_rdc_memreg(m, rm_mreg_data[m].start,
                rm_mreg_data[m].end, rm_mreg_data[m].start,
                rm_mreg_data[m].end);

            /* Find entry in memory list */
            for (mi = 0U; mi < rm_mreg_list_count; mi++)
            {
                if (rm_mreg_list[mi] == m)
                {
                    break;
                }
            }

            /* Roll entries down in the list */
            while ((mi + 1U) < rm_mreg_list_count)
            {
                rm_mreg_list[mi] = rm_mreg_list[mi + 1U];

                mi++;
            }

            /* Update the memory list count */
            rm_mreg_list_count--;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Find a memory region                                                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_find_memreg(sc_rm_pt_t caller_pt, sc_rm_mr_t *mr,
    sc_faddr_t addr_start, sc_faddr_t addr_end)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Loop over regions */
    if (err == SC_ERR_NONE)
    {
        sc_rm_mr_t m;

        err = SC_ERR_NOTFOUND;
        for (m = 0; m < SC_RM_NUM_MEMREG; m++)
        {
            if (caller_pt != SC_PT)
            {
                /* Owned? */
                ASRT_C(rm_is_memreg_owned(caller_pt, m) != SC_FALSE);
            }

            /* Region containing? */
            if ((addr_start >= rm_mreg_data[m].start) 
                && (addr_end <= rm_mreg_data[m].end))
            {
                *mr = m;
                err = SC_ERR_NONE;

                SIMU_ASRT(*mr < SC_RM_NUM_MEMREG,
                    "bad mr");

                break;
            }
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Assign a memory region to another partition                              */
/*--------------------------------------------------------------------------*/
sc_err_t rm_assign_memreg(sc_rm_pt_t caller_pt, sc_rm_pt_t pt, sc_rm_mr_t mr)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_mr_t m0, mN;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    USED_PT(pt);
    NOT_LOCKED(pt);

    /* Is one or all regions? */
    if (mr == SC_RM_MR_ALL)
    {
        /* Set range to cover all regions */
        m0 = 0;
        mN = SC_RM_NUM_MEMREG - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_MR(mr);
        USED_MR(mr);
        if ((err == SC_ERR_NONE) && (caller_pt != SC_PT))
        {
            NOT_LOCKED(rm_mreg_data[mr].owner);
            ANCESTOR(rm_mreg_data[mr].owner);
        }

        /* Set range to cover only the specified region */
        m0 = mr;
        mN = mr;
    }

    if (err == SC_ERR_NONE)
    {
        sc_rm_mr_t m;

        /* Process range of regions */
        for (m = m0; m <= mN; m++)
        {
            if (mr != SC_RM_MR_ALL)
            {
                /* Check parameters */
                USED_MR_C(m);

                /* Check ownership */
                ANCESTOR_C(rm_mreg_data[m].owner);

                /* Check permissions */
                NOT_LOCKED_C(rm_mreg_data[m].owner);
            }

            /* Assign region */
            rm_mreg_data[m].owner = pt;
            clear_perms(rm_mreg_data[m].perms);

            if (rm_part_data[pt].secure != SC_FALSE)
            {
                set_perms(rm_mreg_data[m].perms, rm_part_data[pt].did,
                    SC_RM_PERM_SEC_RW);
            }
            else
            {
                set_perms(rm_mreg_data[m].perms, rm_part_data[pt].did,
                    SC_RM_PERM_FULL);
            }

            /* Update RDC */
            (void) update_rdc_memreg(m, rm_mreg_data[m].start,
                rm_mreg_data[m].end, rm_mreg_data[m].start,
                rm_mreg_data[m].end);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set access permissions for a memory region                               */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_memreg_permissions(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_rm_pt_t pt, sc_rm_perm_t perm)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_mr_t m0, mN;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    ASRT_ERR((pt < SC_RM_NUM_PARTITION) || (pt == SC_RM_PT_ALL), SC_ERR_PARM);
    ASRT_ERR((pt >= SC_RM_NUM_PARTITION) || (rm_part_data[pt].used != SC_FALSE),
        SC_ERR_PARM);

    /* Check permissions */
    if ((err == SC_ERR_NONE) && (pt != SC_RM_PT_ALL))
    {
        if ((rm_part_data[pt].confidential != SC_FALSE) 
            && (pt != caller_pt))
        {
            err = SC_ERR_LOCKED;
        }
    }

    /* Is one or all regions? */
    if (mr == SC_RM_MR_ALL)
    {
        /* Set range to cover all regions */
        m0 = 0;
        mN = SC_RM_NUM_MEMREG - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_MR(mr);
        USED_MR(mr);
        NOT_LOCKED(rm_mreg_data[mr].owner);
        ANCESTOR(rm_mreg_data[mr].owner);

        /* Set range to cover only the specified region */
        m0 = mr;
        mN = mr;
    }

    if (err == SC_ERR_NONE)
    {
        sc_rm_mr_t m;

        /* Process range of regions */
        for (m = m0; m <= mN; m++)
        {
            if (mr != SC_RM_MR_ALL)
            {
                /* Check parameters */
                USED_MR_C(m);

                /* Check ownership */
                ANCESTOR_C(rm_mreg_data[m].owner);

                /* Check permissions */
                NOT_LOCKED_C(rm_mreg_data[m].owner);
            }

            /* Do one or all partitions? */
            if (pt == SC_RM_PT_ALL)
            {
                sc_rm_pt_t p;

                /* Loop through all partitions */
                for (p = 0; p < SC_RM_NUM_PARTITION; p++)
                {
                    /* Check access? */
                    if ((rm_part_data[p].confidential == SC_FALSE) 
                        || (p == caller_pt))
                    {
                        /* Set permissions */
                        set_perms(rm_mreg_data[m].perms, rm_part_data[p].did,
                            perm);
                    }
                }
            }
            else
            {
                set_perms(rm_mreg_data[m].perms, rm_part_data[pt].did,
                    perm);
            }

            /* Update RDC */
            (void) update_rdc_memreg(m, rm_mreg_data[m].start,
                rm_mreg_data[m].end, rm_mreg_data[m].start,
                rm_mreg_data[m].end);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set IEE parameters for memory region                                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_memreg_iee(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_rm_det_t det, sc_rm_rmsg_t rmsg)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rsrc_t resource = U16(SC_R_IEE_R0) + U16(rmsg);
    sc_rm_idx_t idx;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_MR(mr);

    /* Check parameters */
    ASRT_ERR(det <= 1U, SC_ERR_PARM);
    ASRT_ERR(rmsg <= 7U, SC_ERR_PARM);
    BOUND_RSRC(resource, idx);    
    USED_MR(mr);

    /* Check access rights */
    NOT_LOCKED(rm_mreg_data[mr].owner);
    ANCESTOR(rm_mreg_data[mr].owner);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Update data */
        rm_mreg_data[mr].det = det;
        rm_mreg_data[mr].rmsg = rmsg;

        /* Update resource */
        (void) update_rdc_memreg(mr, rm_mreg_data[mr].start,
            rm_mreg_data[mr].end, rm_mreg_data[mr].start,
            rm_mreg_data[mr].end);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Check if memory region owned                                           */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_memreg_owned(sc_rm_pt_t caller_pt, sc_rm_mr_t mr)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_MR(mr);

    if (err == SC_ERR_NONE)
    {
        /* Check parameters */
        if (rm_mreg_data[mr].used == SC_FALSE)
        {
            rtn = SC_FALSE;
        }
        else if (rm_mreg_data[mr].owner == caller_pt)
        {
            rtn = SC_TRUE;
        }
        else
        {
            ; /* Intentional empty else */
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Return memory region info                                                */
/*--------------------------------------------------------------------------*/
sc_err_t rm_get_memreg_info(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_faddr_t *addr_start, sc_faddr_t *addr_end)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_MR(mr);

    /* Check parameters */
    USED_MR(mr);

    if (err == SC_ERR_NONE)
    {
        /* Return info */
        *addr_start = rm_mreg_data[mr].start;
        *addr_end = rm_mreg_data[mr].end;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Assign a pad to a resource partition                                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_assign_pad(sc_rm_pt_t caller_pt, sc_rm_pt_t pt, sc_pad_t pad)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    USED_PT(pt);
    NOT_LOCKED(pt);
    NOT_RESTRICTED(caller_pt);

    /* Is one or all pads? */
    if (pad == SC_P_ALL)
    {
        /* Set range to cover all pads */
        p0 = 0U;
        pN = SC_NUM_PAD - 1U;
    }
    else
    {
        /* Check parameters */
        BOUND_PAD(pad);
        NOT_LOCKED(rm_pad_data[pad].owner);
        ANCESTOR(rm_pad_data[pad].owner);

        /* Set range to cover only the specified region */
        p0 = pad;
        pN = pad;
    }

    if (err == SC_ERR_NONE)
    {
        sc_pad_t p;

        /* Process range of pads */
        for (p = p0; p <= pN; p++)
        {
            if (pad == SC_P_ALL)
            {
                /* Check ownership */
                ANCESTOR_C(rm_pad_data[p].owner);

                /* Check permissions */
                NOT_LOCKED_C(rm_pad_data[p].owner);
            }

            /* Assign pad */
            rm_pad_data[p].owner = pt;
            rm_pad_data[p].movable = SC_TRUE;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Flag pad as movable or not                                               */
/*--------------------------------------------------------------------------*/
sc_err_t rm_set_pad_movable(sc_rm_pt_t caller_pt, sc_pad_t pad_first,
    sc_pad_t pad_last, sc_bool_t movable)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;
    sc_pad_t new_pad_first = pad_first;
    sc_pad_t new_pad_last = pad_last;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check permissions */
    NOT_RESTRICTED(caller_pt);

    /* Is one or all pads? */
    if ((new_pad_first == SC_P_ALL) || (new_pad_last == SC_P_ALL))
    {
        /* Set range to cover all pads */
        p0 = 0U;
        pN = SC_NUM_PAD - 1U;
    }
    else
    {
        if (new_pad_first > new_pad_last)
        {
            sc_pad_t temp = new_pad_first;
            new_pad_first = new_pad_last;
            new_pad_last = temp;
        }

        /* Check parameters */
        BOUND_PAD(new_pad_last);
        ASRT_ERR(new_pad_first <= new_pad_last, SC_ERR_PARM);

        /* Set range to cover only the specified region */
        p0 = new_pad_first;
        pN = new_pad_last;
    }

    if (err == SC_ERR_NONE)
    {
        sc_pad_t p;

        /* Process range of pads */
        for (p = p0; p <= pN; p++)
        {
            /* Check ownership */
            ANCESTOR_C(rm_pad_data[p].owner);

            /* Check permissions */
            NOT_LOCKED_C(rm_pad_data[p].owner);

            /* Set flag */
            rm_pad_data[p].movable = movable;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Check if pad owned                                                       */
/*--------------------------------------------------------------------------*/
sc_bool_t rm_is_pad_owned(sc_rm_pt_t caller_pt, sc_pad_t pad)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        /* Check parameters */
        if (pad >= SC_NUM_PAD)
        {
            rtn = SC_FALSE;
        }
        else if (rm_pad_data[pad].owner == caller_pt)
        {
            rtn = SC_TRUE;
        }
        else
        {
            ; /* Intentional empty else */
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Return the owner partition for a pad                                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_get_pad_owner(sc_pad_t pad, sc_rm_pt_t *pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check parameters */
    BOUND_PAD(pad);

    if (err == SC_ERR_NONE)
    {
        *pt = rm_pad_data[pad].owner;

        SIMU_ASRT(*pt < SC_RM_NUM_PARTITION,
            "bad pt");
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Create a new resource partition and assign resources                     */
/*--------------------------------------------------------------------------*/
sc_err_t rm_partition_create(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt,
    sc_bool_t secure, sc_bool_t isolated, sc_bool_t restricted,
    sc_bool_t grant, sc_bool_t coherent, sc_rsrc_t resource, 
    const sc_rsrc_t *rsrc_lst, uint32_t rsrc_cnt,
    const sc_pad_t *pad_lst, uint32_t pad_cnt,
    const sc_rm_mem_list_t *mem_lst, uint32_t mem_cnt)
{
    sc_err_t err = SC_ERR_NONE;
    uint32_t idx;

    /* Allocate partition */
    FUNC_ERR(rm_partition_alloc(caller_pt, pt, secure, isolated,
        restricted, grant, coherent));

    /* Mark all resources and pads as not movable */
    FUNC_ERR(rm_set_resource_movable(caller_pt, SC_R_ALL, SC_R_ALL,
        SC_FALSE));
    FUNC_ERR(rm_set_pad_movable(caller_pt, SC_P_ALL, SC_P_ALL,
        SC_FALSE));

    /* Mark all subsystem resources as movable */
    if (resource < SC_NUM_RESOURCE)
    {
        FUNC_ERR(rm_set_subsys_rsrc_movable(caller_pt, resource,
            SC_TRUE));
    }

    /* Mark all resources in list as movable */
    idx = 0U;
    while (idx < rsrc_cnt)
    {
        sc_rsrc_t first = rsrc_lst[idx];

        /* Check for subsystem */
        if ((first & RM_SS_MASK) != 0U)
        {
            FUNC_ERR(rm_set_subsys_rsrc_movable(caller_pt,
                first & ~RM_SS_MASK, SC_TRUE));
        }
        else
        {
            sc_rsrc_t last;

            /* Check for range */
            if ((first & RM_RANGE_MASK) != 0U)
            {
                first &= ~RM_RANGE_MASK;
                idx++;
            }
            last = rsrc_lst[idx];
            
            FUNC_ERR(rm_set_resource_movable(caller_pt, first, last,
                SC_TRUE));
        }

        idx++;
    }

    /* Mark all pads in list as movable */
    idx = 0U;
    while (idx < pad_cnt)
    {
        sc_pad_t first = pad_lst[idx];
        sc_pad_t last;

        /* Check for range */
        if ((first & RM_RANGE_MASK) != 0U)
        {
            first &= ~RM_RANGE_MASK;
            idx++;
        }
        last = pad_lst[idx];
        
        FUNC_ERR(rm_set_pad_movable(caller_pt, first, last,
            SC_TRUE));

        idx++;
    }

    /* Move everything flagged as movable */
    FUNC_ERR(rm_move_all(caller_pt, caller_pt, *pt, SC_TRUE, SC_TRUE));

    /* Create and assign all memory in list */
    for (idx = 0U; idx < mem_cnt; idx++)
    {
        sc_rm_mr_t mr;

        /* Fragment memory */
        FUNC_ERR(rm_memreg_frag(caller_pt, &mr,
            mem_lst[idx].addr_start, mem_lst[idx].addr_end));

        /* Assign to new partition */
        FUNC_ERR(rm_assign_memreg(caller_pt, *pt, mr));
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Enable blocking                                                          */
/*--------------------------------------------------------------------------*/
void rm_enable_blocking(void)
{
    blocking = SC_TRUE;

    (void) rm_init_subsys(SC_SUBSYS_SC, SC_TRUE);
}

/*--------------------------------------------------------------------------*/
/* Reload subsystem after a power on                                        */
/*--------------------------------------------------------------------------*/
sc_err_t rm_init_subsys(sc_sub_t ss, sc_bool_t block_enb)
{
    #ifdef XRDC_SUPPORT
        sc_rm_idx_t r;

        SIMU_ASRT(ss < SC_NUM_SUBSYS,
            "bad ss");
        
        /* Enable RDC master (if powered) */
        ss_rdc_enable(ss, SC_TRUE);

        /* Load resource info */
        for (r = rm_ss_map_data[ss]; r < SC_NUM_RSRC; r++)
        {
            if ((block_enb != SC_FALSE) && (rm_rsrc_data[r].owner 
                == SC_SUBSYS_SC))
            {
                continue;
            }

            if (rm_rsrc_data[r].ss == ss)
            {
                (void) update_rdc_resource(r, SC_TRUE, SC_TRUE);
            }
            else
            {
                break;
            }
        }

        /* Load memory region info */
        if (block_enb == SC_FALSE)
        {
            rm_load_memrg();
        }

        /* Enable RDC and load XRDC defaults (if powered) */
        ss_rdc_enable(ss, SC_FALSE);

        /* Load child subsystems */
        for (sc_sub_t css = 0U; css < SC_NUM_SUBSYS; css++)
        {
            if ((sc_ss_info[css].parent == ss) 
                && (ss_is_powered(css) == SC_TRUE))
            {
                (void) rm_init_subsys(css, block_enb);
            }
        }
    #endif /* XRDC_SUPPORT */

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Reload memory region info                                                */
/*--------------------------------------------------------------------------*/
void rm_load_memrg(void)
{
    sc_rm_mr_t m;

    /* Loop over all memory regions in list */
    for (m = 0U; m < rm_mreg_list_count; m++)
    {
        /* Get region from ordered list */
        sc_rm_mr_t mr = rm_mreg_list[m];

        /* Update region */
        (void) update_rdc_memreg(mr, rm_mreg_data[mr].start,
            rm_mreg_data[mr].end, rm_mreg_data[mr].start,
            rm_mreg_data[mr].end);
    }
}

/*--------------------------------------------------------------------------*/
/* Dump RM state for debug                                                  */
/*--------------------------------------------------------------------------*/
void rm_dump(sc_rm_pt_t caller_pt)
{
    #ifdef DEBUG
        sc_rm_pt_t p;

        debug_print(0, "\n*** Partitions **********************************\n");
        for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            rm_dump_partition(p);
        }

        debug_print(0, "\n*** Resources ***********************************\n");
        for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            rm_dump_resources(p);
        }

        debug_print(0, "\n*** Memory Regions ******************************\n");
        for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            rm_dump_memregs(p);
        }

        debug_print(0, "\n*** Pads ****************************************\n");
        for (p = 0U; p < SC_RM_NUM_PARTITION; p++)
        {
            rm_dump_pads(p);
        }
    #endif   
}

/*--------------------------------------------------------------------------*/
/* Dump RM resource state for debug                                         */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG)
    void rm_dump_partition(sc_rm_pt_t pt)
    {
        SIMU_ASRT(pt < SC_RM_NUM_PARTITION,
            "bad pt");
        
        /* Check if partition enabled */
        if (rm_is_partition_used(pt) != SC_FALSE)
        {
            /* Dump data */
            #if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
                always_print("    Partition: %u", pt);
                if (rm_part_names[pt] != NULL)
                {
                    always_print(" (%s)", rm_part_names[pt]);
                }
                always_print("\n");
            #else
                always_print("    Partition: %u\n", pt);
            #endif
            #if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
                always_print("        Parent: %u",
                    rm_part_data[pt].parent);
                if (rm_part_names[rm_part_data[pt].parent] != NULL)
                {
                    always_print(" (%s)",
                        rm_part_names[rm_part_data[pt].parent]);
                }
                always_print("\n");
            #else
            always_print("        Parent: %u\n",
                rm_part_data[pt].parent);
            #endif
            always_print("        DID: %u\n", rm_part_data[pt].did);
            always_print("        Flags:\n");
            if (rm_part_data[pt].used != SC_FALSE)
            {
                always_print("            Used\n");
            }
            if (rm_part_data[pt].secure != SC_FALSE)
            {
                always_print("            Secure\n");
            }
            if (rm_part_data[pt].restricted != SC_FALSE)
            {
                always_print("            Restricted\n");
            }
            if (rm_part_data[pt].isolated != SC_FALSE)
            {
                always_print("            Isolated\n");
            }
            if (rm_part_data[pt].confidential != SC_FALSE)
            {
                always_print("            Confidential\n");
            }
            if (rm_part_data[pt].locked != SC_FALSE)
            {
                always_print("            Locked\n");
            }
            if (rm_part_data[pt].grant != SC_FALSE)
            {
                always_print("            Grant\n");
            }
            if (rm_is_sys_access(pt))
            {
                always_print("            System Access\n");
            }
        }
    }
#endif

/*--------------------------------------------------------------------------*/
/* Dump RM resource state for debug                                         */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG)
    void rm_dump_resources(sc_rm_pt_t pt)
    {
        /* Check if partition enabled */
        if (rm_is_partition_used(pt) != SC_FALSE)
        {
            sc_rm_idx_t r;

            /* Dump data */
            #if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
                always_print("    Partition: %u", pt);
                if (rm_part_names[pt] != NULL)
                {
                    always_print(" (%s)", rm_part_names[pt]);
                }
                always_print("\n");
            #else
                always_print("    Partition: %u\n", pt);
            #endif
            for (r = 0; r < SC_NUM_RSRC; r++)
            {
                if ((rm_rsrc_data[r].owner == pt) 
                    && (rm_is_ridx_avail(r) != SC_FALSE))
                {
                    always_print("        %s\n", rnames[r]);

                    if ((rm_is_ridx_master(r) != SC_FALSE) 
                        && (rm_rsrc_data[r].sid != SC_BYPASS_SID))
                    {
                        always_print("            SID: 0x%X\n",
                            rm_rsrc_data[r].sid);
                    }
                }
            }
        }
    }
#endif

/*--------------------------------------------------------------------------*/
/* Dump RM memreg state for debug                                           */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG)
    void rm_dump_memregs(sc_rm_pt_t pt)
    {
        /* Check if partition enabled */
        if (rm_is_partition_used(pt) != SC_FALSE)
        {
            sc_rm_mr_t m;

            /* Dump data */
            #if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
                always_print("    Partition: %u", pt);
                if (rm_part_names[pt] != NULL)
                {
                    always_print(" (%s)", rm_part_names[pt]);
                }
                always_print("\n");
            #else
                always_print("    Partition: %u\n", pt);
            #endif
            for (m = 0; m < SC_RM_NUM_MEMREG; m++)
            {
                if ((rm_mreg_data[m].used != SC_FALSE) 
                    && (rm_mreg_data[m].owner == pt))
                {
                    sc_faddr_t start, end;
                    sc_rm_pt_t p;

                    start = rm_mreg_data[m].start;
                    end = rm_mreg_data[m].end;
                    always_print("        %03d: 0x%01X", m,
                        UINT64_H(start));
                    always_print("%08X",
                        UINT64_L(start));
                    always_print(" - 0x%01X",
                        UINT64_H(end));
                    always_print("%08X\n",
                        UINT64_L(end));
                    always_print("            ");
                    always_print("Perms: ");
                    for (p = 0; p < SC_RM_NUM_PARTITION; p++)
                    {
                        sc_rm_did_t d = rm_part_data[p].did;
                        sc_rm_perm_t perm;

                        if (rm_part_data[p].used == SC_FALSE)
                        {
                            always_print("x");                            
                        }
                        else
                        {
                            get_perms(rm_mreg_data[m].perms, d, &perm);
                            always_print("%d", perm);
                        }
                    }
                    always_print("\n");
                    if (rm_mreg_data[m].parent != m)
                    {
                        always_print("            ");
                        always_print("Parent: %u\n", rm_mreg_data[m].parent);
                    }
                    if (rm_mreg_data[m].rmsg != 0U)
                    {
                        always_print("            ");
                        always_print("RMSG: %u\n", rm_mreg_data[m].rmsg);
                    }
                    if (rm_mreg_data[m].det != 0U)
                    {
                        always_print("            ");
                        always_print("DET: %u\n", rm_mreg_data[m].det);
                    }
                }
            }
        }
    }
#endif

/*--------------------------------------------------------------------------*/
/* Dump RM pad state for debug                                              */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG)
    void rm_dump_pads(sc_rm_pt_t pt)
    {
        /* Check if partition enabled */
        if (rm_is_partition_used(pt) != SC_FALSE)
        {
            sc_pad_t n;

            /* Dump data */
            #if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
                always_print("    Partition: %u", pt);
                if (rm_part_names[pt] != NULL)
                {
                    always_print(" (%s)", rm_part_names[pt]);
                }
                always_print("\n");
            #else
                always_print("    Partition: %u\n", pt);
            #endif
            for (n = 0; n < SC_NUM_PAD; n++)
            {
                if (rm_pad_data[n].owner == pt)
                {
                    always_print("        %s\n", pnames[n]);
                }
            }
        }
    }
#endif

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Clear all resource permissions                                           */
/*--------------------------------------------------------------------------*/
static void clear_perms(permz_t *perms)
{
    sc_rm_did_t d;

    for (d = 0; d < (SC_RM_NUM_DOMAIN / 2U); d++)
    {
        perms[d] = 0;
    }
}

/*--------------------------------------------------------------------------*/
/* Copy memory region permissions                                           */
/*--------------------------------------------------------------------------*/
static void copy_perms(sc_rm_mr_t mr_src, sc_rm_mr_t mr_dst)
{
    sc_rm_did_t d;

    SIMU_ASRT(mr_src < SC_RM_NUM_MEMREG,
        "bad mr");
    SIMU_ASRT(mr_dst < SC_RM_NUM_MEMREG,
        "bad mr");

    for (d = 0; d < (SC_RM_NUM_DOMAIN / 2U); d++)
    {
        rm_mreg_data[mr_dst].perms[d] = rm_mreg_data[mr_src].perms[d];
    }
}

/*--------------------------------------------------------------------------*/
/* Set resource permission for a domain                                     */
/*--------------------------------------------------------------------------*/
static void set_perms(permz_t *perms, sc_rm_did_t did,
    sc_rm_perm_t perm)
{
    uint8_t byte = did / 2U;
    uint8_t bit = (did % 2U) * 4U;
    permz_t data;

    /* Check parms */
    SIMU_ASRT(did < SC_RM_NUM_DOMAIN,
        "bad did");

    /* Encode perm */
    data = perms[byte];
    data &= ~(0x7U << bit);
    data |= perm << bit;
    perms[byte] = data;
}

/*--------------------------------------------------------------------------*/
/* Get permissions for a domain                                             */
/*--------------------------------------------------------------------------*/
static void get_perms(const permz_t *perms, sc_rm_did_t did,
    sc_rm_perm_t *perm)
{
    uint8_t byte = did / 2U;
    uint8_t bit = (did % 2U) * 4U;

    /* Check parms */
    SIMU_ASRT(did < SC_RM_NUM_DOMAIN,
        "bad did");

    /* Extract perm */
    *perm = (perms[byte] >> bit) & 0x7U;
}

/*--------------------------------------------------------------------------*/
/* Update RDC resource                                                      */
/*--------------------------------------------------------------------------*/
static void update_rdc_resource(sc_rm_idx_t idx, sc_bool_t master,
    sc_bool_t peripheral)
{
    #ifdef XRDC_SUPPORT
        sc_bool_t is_master = SC_FALSE;
        sc_bool_t is_peripheral = SC_FALSE;

        SIMU_ASRT(idx < SC_NUM_RSRC,
            "bad rsrc idx");
        SIMU_ASRT(rm_rsrc_data[idx].owner < SC_RM_NUM_PARTITION,
            "bad owner pt");

        if (rm_rsrc_data[idx].ss <= SC_SUBSYS_LAST)
        {
            is_master = ss_base_info[rm_rsrc_data[idx].ss]
                ->rsrc[rm_rsrc_data[idx].ss_idx].master;
            is_peripheral = ss_base_info[rm_rsrc_data[idx].ss]
                ->rsrc[rm_rsrc_data[idx].ss_idx].peripheral;
        }

        /* Update Master */
        if ((is_master != SC_FALSE) && (master != SC_FALSE))
        {
            sc_rm_spa_t sa = rm_rsrc_data[idx].sa;
            sc_rm_spa_t pa = rm_rsrc_data[idx].pa;
            sc_rm_did_t did = rm_part_data[rm_rsrc_data[idx].owner].did;
            sc_rm_sid_t sid = rm_rsrc_data[idx].sid;

            ss_rdc_set_master(idx, SC_TRUE, SC_FALSE, sa, pa, did, sid, 0xFF);
        }

        /* Update Peripheral */
        if ((is_peripheral != SC_FALSE) && (peripheral != SC_FALSE))
        {
            sc_rm_did_t d;
            sc_rm_perm_t perms[SC_RM_NUM_DOMAIN];

            /* Extract compressed access perms */
            for (d = 0; d < SC_RM_NUM_DOMAIN; d++)
            {
                get_perms(rm_rsrc_data[idx].perms, d, &(perms[d]));
            }

            /* SC always needs access */
            perms[SC_DID] = SC_RM_PERM_SEC_RW;

            /* Grant parent access */
            if (rm_part_data[rm_rsrc_data[idx].owner].grant != SC_FALSE)
            {
                sc_rm_did_t did = rm_part_data[rm_rsrc_data[idx].owner].did;
                sc_rm_did_t pdid 
                    = rm_part_data[rm_part_data[rm_rsrc_data[idx].owner].parent].did;

                perms[pdid] = MAX(perms[pdid], perms[did]);
            }

            /* Block access */
            if ((blocking != SC_FALSE) && (rm_rsrc_data[idx].block != SC_FALSE))
            {
                for (d = 0; d < SC_RM_NUM_DOMAIN; d++)
                {
                    perms[d] = SC_RM_PERM_NONE;
                }
            }

            ss_rdc_set_peripheral(idx, SC_TRUE, SC_FALSE, perms, SC_FALSE);
        }
    #endif /* XRDC_SUPPORT */
}

/*--------------------------------------------------------------------------*/
/* Update RDC memory region                                                 */
/*--------------------------------------------------------------------------*/
static sc_err_t update_rdc_memreg(sc_rm_mr_t mr, sc_faddr_t old_start,
    sc_faddr_t old_end, sc_faddr_t new_start, sc_faddr_t new_end)
{
    #ifdef XRDC_SUPPORT
        sc_rm_did_t d;
        sc_rm_perm_t perms[SC_RM_NUM_DOMAIN];
        sc_rm_mr_t m;
        sc_bool_t used;

        SIMU_ASRT(mr < SC_RM_NUM_MEMREG,
            "bad mr");
        SIMU_ASRT(rm_mreg_data[mr].owner < SC_RM_NUM_PARTITION,
            "bad owner pt");

        /* Prep */
        used = SC_FALSE;
        for (d = 0U; d < SC_RM_NUM_DOMAIN; d++)
        {
            perms[d] = 0U;
        }

        /* Extract permissions for all coincident regions */
        for (m = 0U; m < SC_RM_NUM_MEMREG; m++)
        {
            /* Coincident? */
            if ((rm_mreg_data[m].used != SC_FALSE)
                && (rm_mreg_data[m].start == old_start)
                && (rm_mreg_data[m].end == old_end))
            {
                /* Extract compressed access perms */
                for (d = 0U; d < SC_RM_NUM_DOMAIN; d++)
                {
                    sc_rm_perm_t p;

                    /* Get permissions */
                    get_perms(rm_mreg_data[m].perms, d, &p);

                    /* Take max */
                    perms[d] = MAX(perms[d], p);
                }

                if (rm_mreg_data[m].used != SC_FALSE)
                {
                    used = SC_TRUE;
                }
            }
        }

        /* SC always needs access */
        perms[SC_DID] = SC_RM_PERM_SEC_RW;

        /* Give SECO access if monitor in use */
        if (has_monitor != SC_FALSE)
        {
            perms[SECO_DID] = MAX(perms[SECO_DID], SC_RM_PERM_SEC_RW);
        }

        /* Grant parent access */
        if (rm_part_data[rm_mreg_data[mr].owner].grant != SC_FALSE)
        {
            sc_rm_did_t did = rm_part_data[rm_mreg_data[mr].owner].did;
            sc_rm_did_t pdid 
                = rm_part_data[rm_part_data[rm_mreg_data[mr].owner].parent].did;
        
            perms[pdid] = MAX(perms[pdid], perms[did]);
        }

#ifdef ERR050601_WORKAROUND
        /* Update perms to block AP */
        soc_block_ap_memreg(mr, perms);
#endif

        return ss_rdc_set_memory(rm_mreg_data[mr].start, rm_mreg_data[mr].end,
            used, perms, rm_mreg_data[mr].det, rm_mreg_data[mr].rmsg,
            new_start, new_end);
    #else
        return SC_ERR_NONE;
    #endif /* XRDC_SUPPORT */
}

/** @} */

