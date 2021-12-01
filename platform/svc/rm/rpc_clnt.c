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
 * @file
 *
 * File containing client-side RPC functions for the RM service. These
 * functions are ported to clients that communicate to the SC.
 *
 * @addtogroup RM_SVC
 * @{
 */
/*==========================================================================*/

/* DO NOT EDIT - This file auto generated by bin/perl/rpc_clnt_c.pl */

/* Includes */

#include "main/types.h"
#include "svc/rm/api.h"
#include "../../main/rpc.h"
#include "svc/rm/rpc.h"

/* Local Defines */

/* Local Types */

/* Local Functions */

/* IDL: E8 PARTITION_ALLOC(UO8 pt, IB secure, IB isolated, IB restricted, IB grant, IB coherent) #1 */
sc_err_t sc_rm_partition_alloc(sc_ipc_t ipc, sc_rm_pt_t *pt, sc_bool_t secure,
    sc_bool_t isolated, sc_bool_t restricted, sc_bool_t grant,
    sc_bool_t coherent)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 3U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_PARTITION_ALLOC);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = B2U8(secure);
    RPC_U8(&msg, 1U) = B2U8(isolated);
    RPC_U8(&msg, 2U) = B2U8(restricted);
    RPC_U8(&msg, 3U) = B2U8(grant);
    RPC_U8(&msg, 4U) = B2U8(coherent);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (pt != NULL)
    {
        *pt = (sc_rm_pt_t) RPC_U8(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 SET_CONFIDENTIAL(UI8 pt, IB retro) #31 */
sc_err_t sc_rm_set_confidential(sc_ipc_t ipc, sc_rm_pt_t pt, sc_bool_t retro)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_CONFIDENTIAL);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(pt);
    RPC_U8(&msg, 1U) = B2U8(retro);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 PARTITION_FREE(UI8 pt) #2 */
sc_err_t sc_rm_partition_free(sc_ipc_t ipc, sc_rm_pt_t pt)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_PARTITION_FREE);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(pt);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: UR8 GET_DID() #26 */
sc_rm_did_t sc_rm_get_did(sc_ipc_t ipc)
{
    sc_rpc_msg_t msg;
    sc_rm_did_t result;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 1U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_GET_DID);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    result = (sc_rm_did_t) RPC_R8(&msg);

    /* Return result */
    return result;
}

/* IDL: E8 PARTITION_STATIC(UI8 pt, UI8 did) #3 */
sc_err_t sc_rm_partition_static(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rm_did_t did)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_PARTITION_STATIC);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(pt);
    RPC_U8(&msg, 1U) = U8(did);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 PARTITION_LOCK(UI8 pt) #4 */
sc_err_t sc_rm_partition_lock(sc_ipc_t ipc, sc_rm_pt_t pt)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_PARTITION_LOCK);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(pt);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 GET_PARTITION(UO8 pt) #5 */
sc_err_t sc_rm_get_partition(sc_ipc_t ipc, sc_rm_pt_t *pt)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 1U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_GET_PARTITION);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (pt != NULL)
    {
        *pt = (sc_rm_pt_t) RPC_U8(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 SET_PARENT(UI8 pt, UI8 pt_parent) #6 */
sc_err_t sc_rm_set_parent(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rm_pt_t pt_parent)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_PARENT);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(pt);
    RPC_U8(&msg, 1U) = U8(pt_parent);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 MOVE_ALL(UI8 pt_src, UI8 pt_dst, IB move_rsrc, IB move_pads) #7 */
sc_err_t sc_rm_move_all(sc_ipc_t ipc, sc_rm_pt_t pt_src, sc_rm_pt_t pt_dst,
    sc_bool_t move_rsrc, sc_bool_t move_pads)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_MOVE_ALL);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(pt_src);
    RPC_U8(&msg, 1U) = U8(pt_dst);
    RPC_U8(&msg, 2U) = B2U8(move_rsrc);
    RPC_U8(&msg, 3U) = B2U8(move_pads);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 ASSIGN_RESOURCE(UI8 pt, UI16 resource) #8 */
sc_err_t sc_rm_assign_resource(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rsrc_t resource)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_ASSIGN_RESOURCE);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);
    RPC_U8(&msg, 2U) = U8(pt);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_RESOURCE_MOVABLE(UI16 resource_fst, UI16 resource_lst, IB movable) #9 */
sc_err_t sc_rm_set_resource_movable(sc_ipc_t ipc, sc_rsrc_t resource_fst,
    sc_rsrc_t resource_lst, sc_bool_t movable)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 3U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_RESOURCE_MOVABLE);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource_fst);
    RPC_U16(&msg, 2U) = U16(resource_lst);
    RPC_U8(&msg, 4U) = B2U8(movable);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_SUBSYS_RSRC_MOVABLE(UI16 resource, IB movable) #28 */
sc_err_t sc_rm_set_subsys_rsrc_movable(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_bool_t movable)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_SUBSYS_RSRC_MOVABLE);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);
    RPC_U8(&msg, 2U) = B2U8(movable);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_MASTER_ATTRIBUTES(UI16 resource, UI8 sa, UI8 pa, IB smmu_bypass) #10 */
sc_err_t sc_rm_set_master_attributes(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_rm_spa_t sa, sc_rm_spa_t pa, sc_bool_t smmu_bypass)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 3U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_MASTER_ATTRIBUTES);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);
    RPC_U8(&msg, 2U) = U8(sa);
    RPC_U8(&msg, 3U) = U8(pa);
    RPC_U8(&msg, 4U) = B2U8(smmu_bypass);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_MASTER_SID(UI16 resource, UI16 sid) #11 */
sc_err_t sc_rm_set_master_sid(sc_ipc_t ipc, sc_rsrc_t resource, sc_rm_sid_t sid)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_MASTER_SID);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);
    RPC_U16(&msg, 2U) = U16(sid);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_PERIPHERAL_PERMISSIONS(UI16 resource, UI8 pt, UI8 perm) #12 */
sc_err_t sc_rm_set_peripheral_permissions(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_rm_pt_t pt, sc_rm_perm_t perm)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_PERIPHERAL_PERMISSIONS);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);
    RPC_U8(&msg, 2U) = U8(pt);
    RPC_U8(&msg, 3U) = U8(perm);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: RB IS_RESOURCE_OWNED(UI16 resource) #13 */
sc_bool_t sc_rm_is_resource_owned(sc_ipc_t ipc, sc_rsrc_t resource)
{
    sc_rpc_msg_t msg;
    sc_bool_t result;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_IS_RESOURCE_OWNED);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    result = (sc_bool_t) U2B(RPC_R8(&msg));

    /* Return result */
    return result;
}

/* IDL: E8 GET_RESOURCE_OWNER(UI16 resource, UO8 pt) #33 */
sc_err_t sc_rm_get_resource_owner(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_rm_pt_t *pt)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_GET_RESOURCE_OWNER);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (pt != NULL)
    {
        *pt = (sc_rm_pt_t) RPC_U8(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: RB IS_RESOURCE_MASTER(UI16 resource) #14 */
sc_bool_t sc_rm_is_resource_master(sc_ipc_t ipc, sc_rsrc_t resource)
{
    sc_rpc_msg_t msg;
    sc_bool_t result;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_IS_RESOURCE_MASTER);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    result = (sc_bool_t) U2B(RPC_R8(&msg));

    /* Return result */
    return result;
}

/* IDL: RB IS_RESOURCE_PERIPHERAL(UI16 resource) #15 */
sc_bool_t sc_rm_is_resource_peripheral(sc_ipc_t ipc, sc_rsrc_t resource)
{
    sc_rpc_msg_t msg;
    sc_bool_t result;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_IS_RESOURCE_PERIPHERAL);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    result = (sc_bool_t) U2B(RPC_R8(&msg));

    /* Return result */
    return result;
}

/* IDL: E8 GET_RESOURCE_INFO(UI16 resource, UO16 sid) #16 */
sc_err_t sc_rm_get_resource_info(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_rm_sid_t *sid)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_GET_RESOURCE_INFO);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(resource);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (sid != NULL)
    {
        *sid = (sc_rm_sid_t) RPC_U16(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 MEMREG_ALLOC(UO8 mr, UI64 addr_start, UI64 addr_end) #17 */
sc_err_t sc_rm_memreg_alloc(sc_ipc_t ipc, sc_rm_mr_t *mr, sc_faddr_t addr_start,
    sc_faddr_t addr_end)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 5U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_MEMREG_ALLOC);

    /* Fill in send message */
    RPC_U32(&msg, 0U) = U32(addr_start >> 32ULL);
    RPC_U32(&msg, 4U) = U32(addr_start);
    RPC_U32(&msg, 8U) = U32(addr_end >> 32ULL);
    RPC_U32(&msg, 12U) = U32(addr_end);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (mr != NULL)
    {
        *mr = (sc_rm_mr_t) RPC_U8(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 MEMREG_SPLIT(UI8 mr, UO8 mr_ret, UI64 addr_start, UI64 addr_end) #29 */
sc_err_t sc_rm_memreg_split(sc_ipc_t ipc, sc_rm_mr_t mr, sc_rm_mr_t *mr_ret,
    sc_faddr_t addr_start, sc_faddr_t addr_end)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 6U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_MEMREG_SPLIT);

    /* Fill in send message */
    RPC_U32(&msg, 0U) = U32(addr_start >> 32ULL);
    RPC_U32(&msg, 4U) = U32(addr_start);
    RPC_U32(&msg, 8U) = U32(addr_end >> 32ULL);
    RPC_U32(&msg, 12U) = U32(addr_end);
    RPC_U8(&msg, 16U) = U8(mr);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (mr_ret != NULL)
    {
        *mr_ret = (sc_rm_mr_t) RPC_U8(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 MEMREG_FRAG(UO8 mr_ret, UI64 addr_start, UI64 addr_end) #32 */
sc_err_t sc_rm_memreg_frag(sc_ipc_t ipc, sc_rm_mr_t *mr_ret,
    sc_faddr_t addr_start, sc_faddr_t addr_end)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 5U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_MEMREG_FRAG);

    /* Fill in send message */
    RPC_U32(&msg, 0U) = U32(addr_start >> 32ULL);
    RPC_U32(&msg, 4U) = U32(addr_start);
    RPC_U32(&msg, 8U) = U32(addr_end >> 32ULL);
    RPC_U32(&msg, 12U) = U32(addr_end);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (mr_ret != NULL)
    {
        *mr_ret = (sc_rm_mr_t) RPC_U8(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 MEMREG_FREE(UI8 mr) #18 */
sc_err_t sc_rm_memreg_free(sc_ipc_t ipc, sc_rm_mr_t mr)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_MEMREG_FREE);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(mr);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 FIND_MEMREG(UO8 mr, UI64 addr_start, UI64 addr_end) #30 */
sc_err_t sc_rm_find_memreg(sc_ipc_t ipc, sc_rm_mr_t *mr, sc_faddr_t addr_start,
    sc_faddr_t addr_end)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 5U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_FIND_MEMREG);

    /* Fill in send message */
    RPC_U32(&msg, 0U) = U32(addr_start >> 32ULL);
    RPC_U32(&msg, 4U) = U32(addr_start);
    RPC_U32(&msg, 8U) = U32(addr_end >> 32ULL);
    RPC_U32(&msg, 12U) = U32(addr_end);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (mr != NULL)
    {
        *mr = (sc_rm_mr_t) RPC_U8(&msg, 0U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 ASSIGN_MEMREG(UI8 pt, UI8 mr) #19 */
sc_err_t sc_rm_assign_memreg(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rm_mr_t mr)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_ASSIGN_MEMREG);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(pt);
    RPC_U8(&msg, 1U) = U8(mr);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_MEMREG_PERMISSIONS(UI8 mr, UI8 pt, UI8 perm) #20 */
sc_err_t sc_rm_set_memreg_permissions(sc_ipc_t ipc, sc_rm_mr_t mr, sc_rm_pt_t pt,
    sc_rm_perm_t perm)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_MEMREG_PERMISSIONS);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(mr);
    RPC_U8(&msg, 1U) = U8(pt);
    RPC_U8(&msg, 2U) = U8(perm);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_MEMREG_IEE(UI8 mr, UI8 det, UI8 rmsg) #34 */
sc_err_t sc_rm_set_memreg_iee(sc_ipc_t ipc, sc_rm_mr_t mr, sc_rm_det_t det,
    sc_rm_rmsg_t rmsg)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_MEMREG_IEE);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(mr);
    RPC_U8(&msg, 1U) = U8(det);
    RPC_U8(&msg, 2U) = U8(rmsg);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: RB IS_MEMREG_OWNED(UI8 mr) #21 */
sc_bool_t sc_rm_is_memreg_owned(sc_ipc_t ipc, sc_rm_mr_t mr)
{
    sc_rpc_msg_t msg;
    sc_bool_t result;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_IS_MEMREG_OWNED);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(mr);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    result = (sc_bool_t) U2B(RPC_R8(&msg));

    /* Return result */
    return result;
}

/* IDL: E8 GET_MEMREG_INFO(UI8 mr, UO64 addr_start, UO64 addr_end) #22 */
sc_err_t sc_rm_get_memreg_info(sc_ipc_t ipc, sc_rm_mr_t mr,
    sc_faddr_t *addr_start, sc_faddr_t *addr_end)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_GET_MEMREG_INFO);

    /* Fill in send message */
    RPC_U8(&msg, 0U) = U8(mr);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Copy out receive message */
    if (addr_start != NULL)
    {
        *addr_start = (sc_faddr_t) RPC_U64(&msg, 0U);
    }
    if (addr_end != NULL)
    {
        *addr_end = (sc_faddr_t) RPC_U64(&msg, 8U);
    }

    /* Return result */
    return err;
}

/* IDL: E8 ASSIGN_PAD(UI8 pt, UI16 pad) #23 */
sc_err_t sc_rm_assign_pad(sc_ipc_t ipc, sc_rm_pt_t pt, sc_pad_t pad)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_ASSIGN_PAD);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(pad);
    RPC_U8(&msg, 2U) = U8(pt);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: E8 SET_PAD_MOVABLE(UI16 pad_fst, UI16 pad_lst, IB movable) #24 */
sc_err_t sc_rm_set_pad_movable(sc_ipc_t ipc, sc_pad_t pad_fst, sc_pad_t pad_lst,
    sc_bool_t movable)
{
    sc_rpc_msg_t msg;
    sc_err_t err;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 3U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_SET_PAD_MOVABLE);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(pad_fst);
    RPC_U16(&msg, 2U) = U16(pad_lst);
    RPC_U8(&msg, 4U) = B2U8(movable);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    err = (sc_err_t) RPC_R8(&msg);

    /* Return result */
    return err;
}

/* IDL: RB IS_PAD_OWNED(UI16 pad) #25 */
sc_bool_t sc_rm_is_pad_owned(sc_ipc_t ipc, sc_pad_t pad)
{
    sc_rpc_msg_t msg;
    sc_bool_t result;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 2U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_IS_PAD_OWNED);

    /* Fill in send message */
    RPC_U16(&msg, 0U) = U16(pad);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);

    /* Copy out result */
    result = (sc_bool_t) U2B(RPC_R8(&msg));

    /* Return result */
    return result;
}

/* IDL: R0 DUMP() #27 */
void sc_rm_dump(sc_ipc_t ipc)
{
    sc_rpc_msg_t msg;

    /* Fill in header */
    RPC_VER(&msg) = SC_RPC_VERSION;
    RPC_SIZE(&msg) = 1U;
    RPC_SVC(&msg) = U8(SC_RPC_SVC_RM);
    RPC_FUNC(&msg) = U8(RM_FUNC_DUMP);

    /* Call RPC */
    sc_call_rpc(ipc, &msg, SC_FALSE);
}

/** @} */
