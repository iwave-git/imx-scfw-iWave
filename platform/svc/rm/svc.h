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
 * @file  svc/rm/svc.h
 *
 * Header file containing the API for the System Controller (SC) Resource
 * Management (RM) function. This includes functions for partitioning
 * resources, pads, and memory regions.
 *
 * @addtogroup RM_SVC
 * @{
 */
/*==========================================================================*/

#ifndef SC_RM_SVC_H
#define SC_RM_SVC_H

/* Includes */

#include "main/main.h"
#include "svc/rm/api.h"

/* Defines */

/*! Width of SS index */
#define SC_SS_IDX_W        8U

/*! Define used to indicate function should apply to all partitions */
#define SC_PT_ALL          SC_RM_NUM_PARTITION

#define RM_RANGE_MASK      U16(0x8000U)
#define RM_RANGE(X,Y)      ((X) | RM_RANGE_MASK), (Y)
#define RM_SS_MASK         U16(0x4000U)
#define RM_SS(X)           ((X) | RM_SS_MASK)

/* Types */

/*! Type for a ss resource index */
typedef uint8_t sc_ss_idx_t;

/*!
 * This type is used for a memory list.
 */
typedef struct
{
    sc_faddr_t addr_start;
    sc_faddr_t addr_end;
} sc_rm_mem_list_t;

/* Functions */

/*!
 * @name Internal Functions
 * @{
 */

/*!
 * Internal SC function to initialize the RM service.
 *
 * @param[in]     api_phase   init phase
 *
 * Initializes the API if /a api_phase = SC_TRUE, otherwise initializes the HW
 * managed by the RM service. API must be initialized before anything else is
 * done with the service.
 */
void rm_init(sc_bool_t api_phase);

/*!
 * Internal SC function to specify the number of static partitions.
 *
 * @param[in]     num         number of static partitions
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Static partitions will be skipped when a new partition is allocated.
 * The minimum possible is 0 and the max possible is SC_RM_NUM_PARTITION.
 */
sc_err_t rm_reserve_static_pt(sc_rm_pt_t num);

/*!
 * Internal SC function to specify the number of static domains.
 *
 * @param[in]     num         number of static domains
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Static domains will be skipped when a new partition is allocated.
 * The minimum possible is 0 and the max possible is SC_RM_NUM_DOMAIN.
 */
sc_err_t rm_reserve_static_did(sc_rm_did_t num);

/*!
 * Internal SC function to request that the SC create a new resource partition.
 *
 * @see sc_rm_partition_alloc().
 */
sc_err_t rm_partition_alloc(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt,
    sc_bool_t secure, sc_bool_t isolated, sc_bool_t restricted, sc_bool_t grant,
    sc_bool_t coherent);

/*!
 * Internal SC function to make a partition confidential.
 *
 * @see sc_rm_set_confidential().
 */
sc_err_t rm_set_confidential(sc_rm_pt_t caller_pt, sc_rm_pt_t pt, sc_bool_t retro);

/*!
 * Internal SC function to free a partition and assigns all resources to the caller.
 *
 * @see sc_rm_partition_free().
 */
sc_err_t rm_partition_free(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/*!
 * Internal SC function to get the partition handle of the caller.
 *
 * @see sc_rm_get_partition().
 */
sc_err_t rm_get_partition(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt);

/*!
 * Internal SC function to determine if a partition is enabled (used) or not.
 *
 * @param[in]     pt          partition to check
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_bool_t rm_is_partition_used(sc_rm_pt_t pt);

/*!
 * Internal SC function to get the security state of partition.
 *
 * @return Returns SC_TRUE if \a caller's partition is secure.
 */
sc_bool_t rm_is_secure_partition(sc_rm_pt_t caller_pt);

/*!
 * Internal SC function to get the isolation state of partition.
 *
 * @return Returns SC_TRUE if \a caller's partition is isolated.
 */
sc_bool_t rm_is_partition_isolated(sc_rm_pt_t pt);

/*!
 * Internal SC function to return if the partition has system access.
 *
 * @param[in]     pt          partition to check
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_bool_t rm_is_sys_access(sc_rm_pt_t pt);

/*!
 * Internal SC function to set the control partition.
 *
 * @param[in]     pt          partition to be controlled
 * @param[in]     control     partition that will have control
 *
 * Allows the following functions to be called by \a control for
 * partition \a pt.
 *
 * - sc_pm_boot()
 * - sc_pm_set_partition_power_mode()
 * - sc_pm_reboot_partition()
 */
void rm_set_control_partition(sc_rm_pt_t pt, sc_rm_pt_t control);

/*!
 * Internal SC function to return the control partition.
 *
 * @param[in]     pt          partition to return
 *
 * @return Returns the control partition (0 if none).
 */
sc_rm_pt_t rm_get_control_partition(sc_rm_pt_t pt);

/*!
 * Internal SC function to return the parent of a partition.
 *
 * @param[in]     pt          partition to check
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_rm_pt_t rm_get_partition_parent(sc_rm_pt_t pt);

/*!
 * Internal SC function to get the DID of the caller's partition.
 *
 * @see sc_rm_get_did().
 */
sc_rm_did_t rm_get_did(sc_rm_pt_t caller_pt);

/*!
 * Internal SC function to force a partition to use a specific static DID.
 *
 * @see sc_rm_partition_static().
 */
sc_err_t rm_partition_static(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_rm_did_t did);

/*!
 * Internal SC function to lock a partition.
 *
 * @see sc_rm_partition_lock().
 */
sc_err_t rm_partition_lock(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/*!
 * Internal SC function to set a new parent for a partition.
 *
 * @see sc_rm_set_parent().
 */
sc_err_t rm_set_parent(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_rm_pt_t pt_parent);

/*!
 * Internal SC function to check if caller is the parent of a partition.
 *
 * @param[in]     caller_pt   handle of caller partition
 * @param[in]     pt          handle of partition to check
 *
 * Returns SC_TRUE of the caller is the parent of another partition.
 * Used to check access permissions on functions that affect a partition.
 */
sc_bool_t rm_is_parent(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/*!
 * Internal SC function to check if caller is an ancestor of owner.
 *
 * @param[in]     caller_pt   handle of caller partition
 * @param[in]     pt_owner    handle of owner partition
 *
 * Returns SC_TRUE of the caller is the owner or is an ancestor of the
 * owner. Used to check access permissions on functions that affect
 * a partition.
 */
sc_bool_t rm_check_ancestor(sc_rm_pt_t caller_pt, sc_rm_pt_t pt_owner);

/*!
 * Internal SC function to move all resources/pads owned by a source partition to a
 * destination partition.
 *
 * @see sc_rm_move_all().
 */
sc_err_t rm_move_all(sc_rm_pt_t caller_pt, sc_rm_pt_t pt_src,
    sc_rm_pt_t pt_dst, sc_bool_t move_rsrc, sc_bool_t move_pads);

/*!
 * Internal SC function to assign ownership of a resource to a partition.
 *
 * @see sc_rm_assign_resource().
 */
sc_err_t rm_assign_resource(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_rsrc_t resource);

/*!
 * Internal SC function to flag resource as movable or not.
 *
 * @see sc_rm_set_resource_movable().
 */
sc_err_t rm_set_resource_movable(sc_rm_pt_t caller_pt, 
    sc_rsrc_t resource_fst, sc_rsrc_t resource_lst, sc_bool_t movable);

/*!
 * Internal SC function to flag all of a subsystem's resources as movable
 * or not.
 *
 * @see sc_rm_set_subsys_rsrc_movable().
 */
 sc_err_t rm_set_subsys_rsrc_movable(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_bool_t movable);

/*!
 * Internal SC function to set attributes for a resource which is a bus master
 * (i.e. capable of DMA).
 *
 * @see sc_rm_set_master_attributes().
 */
sc_err_t rm_set_master_attributes(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_spa_t sa, sc_rm_spa_t pa, sc_bool_t smmu_bypass);

/*!
 * Internal SC function to set the StreamID for a resource which is a
 * bus master (i.e. capable of DMA).
 *
 * @see sc_rm_set_master_sid().
 */
sc_err_t rm_set_master_sid(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_sid_t sid);

/*!
 * Internal SC function to update a master resource. It takes a
 * resource index as an argument.
 *
 * @param[in]     idx         unified resource index
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t rm_update_master(sc_rm_idx_t idx);

/*!
 * Internal SC function to set access permissions for a peripheral resource.
 *
 * @see sc_rm_set_peripheral_permissions().
 */
sc_err_t rm_set_peripheral_permissions(sc_rm_pt_t caller_pt,
    sc_rsrc_t resource, sc_rm_pt_t pt, sc_rm_perm_t perm);

/*!
 * Internal SC function to update a peripheral resource. It takes a
 * resource index as an argument.
 *
 * @param[in]     idx         unified resource index
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t rm_update_peripheral(sc_rm_idx_t idx);

/*!
 * Internal SC function to update a resource in HW.
 *
 * @param[in]     resource    resource to update
 */
void rm_update_resource(sc_rsrc_t resource);

/*!
 * Internal SC function to return subsystem specific info about a resource. It
 * takes a resource index as an argument.
 *
 * @param[in]     idx         unified resource index
 * @param[out]    ss          subsystem
 * @param[out]    ss_idx      subsystem relative resource index
 */
void rm_get_ridx_ss_info(sc_rm_idx_t idx, sc_sub_t *ss, sc_ss_idx_t *ss_idx);

/*!
 * Internal SC function to check the validity of a resource and return the
 * unified resource index.
 *
 * @param[in]     resource    resource to check
 * @param[out]    idx         unified resource index
 *
 * @return Returns SC_TRUE if \a resource is valid.
 *
 * The index can be used to index into any resource array of size
 * SC_NUM_RSRCS. It is also used for most private RM functions.
 */
sc_bool_t rm_check_map_ridx(sc_rsrc_t resource, sc_rm_idx_t *idx);

/*!
 * Internal SC function to check the validity of a resource and return the
 * unified resource index.
 *
 * @param[in]     resource    resource to check
 * @param[out]    idx         unified resource index
 *
 * The index can be used to index into any resource array of size
 * SC_NUM_RSRCS. It is also used for most private RM functions.
 */
void rm_check_map_ridx_v(sc_rsrc_t resource, sc_rm_idx_t *idx);

/*!
 * Internal SC function to get ownership status of a resource.
 *
 * @see sc_rm_is_resource_owned().
 */
sc_bool_t rm_is_resource_owned(sc_rm_pt_t caller_pt, sc_rsrc_t resource);

/*!
 * Internal SC function to check if a resource is owned by the caller. It takes a
 * resource index as an argument.
 *
 * @param[in]     caller_pt   handle of caller partition
 * @param[in]     idx         unified resource index
 *
 * @return Returns SC_TRUE if \a idx is owned.
 */
sc_bool_t rm_is_ridx_owned(sc_rm_pt_t caller_pt, sc_rm_idx_t idx);

/*!
 * Internal SC function to check if a resource is available. It takes a
 * resource as an argument. Resource availability is based in hardware,
 * fuses, and board. Not based on partition ownership.
 *
 * @param[in]     resource    resource to check
 *
 * @return Returns SC_TRUE if \a resource is available.
 */
sc_bool_t rm_is_resource_avail(sc_rsrc_t resource);

/*!
 * Internal SC function covvert a resource index to a resource.
 *
 * @param[in]     idx         unified resource index
 *
 * @return Returns resource.
*/
sc_rsrc_t rm_get_resource(sc_rm_idx_t idx);

/*!
 * Internal SC function to check if a resource is available. It takes a
 * resource index as an argument. Resource availability is based in
 * hardware, fuses, and board. Not based on partition ownership.
 *
 * @param[in]     idx         unified resource index
 *
 * @return Returns SC_TRUE if \a idx is available.
 */
sc_bool_t rm_is_ridx_avail(sc_rm_idx_t idx);

/*!
 * Internal SC function to get access rights of a resource.
 *
 * @param[in]     caller_pt   handle of caller partition
 * @param[in]     resource    resource to check
 *
 * @return Returns SC_TRUE if \a resource is accessible.
 */
sc_bool_t rm_is_resource_access_allowed(sc_rm_pt_t caller_pt, sc_rsrc_t resource);

/*!
 * Internal SC function to check if a resource is controllable by the caller.
 * It takes a resource index as an argument.
 *
 * @param[in]     caller_pt   handle of caller partition
 * @param[in]     idx         unified resource index
 *
 * @return Returns SC_TRUE if \a idx access is allowed.
 */
sc_bool_t rm_is_ridx_access_allowed(sc_rm_pt_t caller_pt, sc_rm_idx_t idx);

/*!
 * Internal SC function to return the owner partition for a resource.
 *
 * @see sc_rm_get_resource_owner().
 */
sc_err_t rm_get_resource_owner(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_pt_t *pt);

/*!
 * Internal SC function to return the ownering partition for a resource. It takes a
 * resource index as an argument.
 *
 * @param[in]     idx         unified resource index
 * @param[out]    pt          return handle for partition
 */
void rm_get_ridx_owner(sc_rm_idx_t idx, sc_rm_pt_t *pt);

/*!
 * Internal SC function used to test if a resource is a bus master.
 *
 * @see sc_rm_is_resource_master().
 */
sc_bool_t rm_is_resource_master(sc_rm_pt_t caller_pt, sc_rsrc_t resource);

/*!
 * Internal SC function to check if a resource is a master. It takes a
 * resource index as an argument.
 *
 * @param[in]     idx         unified resource index
 *
 * @return Returns SC_TRUE if \a idx is a master.
 */
sc_bool_t rm_is_ridx_master(sc_rm_idx_t idx);

/*!
 * Internal SC function used to test if a resource is a peripheral.
 *
 * @see sc_rm_is_resource_peripheral().
 */
sc_bool_t rm_is_resource_peripheral(sc_rm_pt_t caller_pt, sc_rsrc_t resource);

/*!
 * Internal SC function to check if a resource is a peripheral. It takes a
 * resource index as an argument.
 *
 * @param[in]     idx         unified resource index
 *
 * @return Returns SC_TRUE if \a idx is a peripheral.
 */
sc_bool_t rm_is_ridx_peripheral(sc_rm_idx_t idx);

/*!
 * Internal SC function used to obtain info about a resource.
 *
 * @see sc_rm_get_resource_info().
 */
sc_err_t rm_get_resource_info(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rm_sid_t *sid);

/*!
 * Internal SC function to control if a access to a resource should be
 * blocked via HW.
 *
 * @param[in]     idx         unified resource index
 * @param[in]     block       block state (SC_TRUE to block)
 *
 * @return Returns current block state.
 */
sc_bool_t rm_ridx_block(sc_rm_idx_t idx, sc_bool_t block);

/*!
 * Internal SC function to request that the SC create a new memory region.
 *
 * @see sc_rm_memreg_alloc().
 */
sc_err_t rm_memreg_alloc(sc_rm_pt_t caller_pt, sc_rm_mr_t *mr,
    sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * Internal SC function to split a memory region.
 *
 * @see sc_rm_memreg_split().
 */
sc_err_t rm_memreg_split(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_rm_mr_t *mr_ret, sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * Internal SC function to fragment a memory region.
 *
 * @see sc_rm_memreg_frag().
 */
sc_err_t rm_memreg_frag(sc_rm_pt_t caller_pt, sc_rm_mr_t *mr_ret, 
    sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * Internal SC function to free a memory region.
 *
 * @see sc_rm_memreg_free().
 */
sc_err_t rm_memreg_free(sc_rm_pt_t caller_pt, sc_rm_mr_t mr);

/*!
 * Internal SC function to find a memory region.
 *
 * @see sc_rm_find_memreg().
 */
sc_err_t rm_find_memreg(sc_rm_pt_t caller_pt, sc_rm_mr_t *mr,
    sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * Internal SC function to assign ownership of a memory region.
 *
 * @see sc_rm_assign_memreg().
 */
sc_err_t rm_assign_memreg(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_rm_mr_t mr);

/*!
 * Internal SC function to set access permissions for a memory region.
 *
 * @see sc_rm_set_memreg_permissions().
 */
sc_err_t rm_set_memreg_permissions(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_rm_pt_t pt, sc_rm_perm_t perm);

/*!
 * Internal SC function to set configure IEE parameters for a mem region.
 *
 * @see sc_rm_set_memreg_iee().
 */
sc_err_t rm_set_memreg_iee(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_rm_det_t det, sc_rm_rmsg_t rmsg);

/*!
 * Internal SC function to get ownership status of a memory region.
 *
 * @see sc_rm_is_memreg_owned().
 */
sc_bool_t rm_is_memreg_owned(sc_rm_pt_t caller_pt, sc_rm_mr_t mr);

/*!
 * Internal SC function used to obtain info about a memory region.
 *
 * @see sc_rm_get_memreg_info().
 */
sc_err_t rm_get_memreg_info(sc_rm_pt_t caller_pt, sc_rm_mr_t mr,
    sc_faddr_t *addr_start, sc_faddr_t *addr_end);

/*!
 * Internal SC function to assign ownership of a pad to a partition.
 *
 * @see sc_rm_assign_pad().
 */
sc_err_t rm_assign_pad(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pad_t pad);

/*!
 * Internal SC function to flag pad as movable or not.
 *
 * @see sc_rm_set_pad_movable().
 */
sc_err_t rm_set_pad_movable(sc_rm_pt_t caller_pt, sc_pad_t pad_first,
    sc_pad_t pad_last, sc_bool_t movable);

/*!
 * Internal SC function to get ownership status of a pad.
 *
 * @see sc_rm_is_pad_owned().
 */
sc_bool_t rm_is_pad_owned(sc_rm_pt_t caller_pt, sc_pad_t pad);

/*!
 * Internal SC function to get the owner of a pad.
 *
 * @param[in]     pad         pad to get
 * @param[out]    pt          pointer to return partition
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t rm_get_pad_owner(sc_pad_t pad, sc_rm_pt_t *pt);


/*!
 * Internal function to create a partition and assign all resources.
 *
 * @param[in]     caller_pt    handle of caller partition
 * @param[out]    pt           return handle for partition
 * @param[in]     secure       boolean indicating if this partition should be secure
 * @param[in]     isolated     boolean indicating if this partition should be HW isolated
 * @param[in]     restricted   boolean indicating if this partition should be restricted
 * @param[in]     grant        boolean indicating if this partition should always grant
 * @param[in]     coherent     boolean indicating if this partition is coherent
 * @param[in]     resource     resource in subsystem to completely assign (SC_NUM_RESOURCE for none)
 * @param[in]     rsrc_lst     pointer to resource list (NULL if none)
 * @param[in]     rsrc_cnt     number of entries in the resource list (0 if none)
 * @param[in]     pad_lst      pointer to pad list (NULL if none)
 * @param[in]     pad_cnt      number of entries in the pad list (0 if none)
 * @param[in]     mem_lst      pointer to memory list (NULL if none)
 * @param[in]     mem_cnt      number of entries in the memory list (0 if none)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * See sc_rm_partition_alloc() for info on most parameters and error returns.
 *
 * Use RM_RANGE() to specify a resource/pad range. Counts as two in the
 * count parameter.
 */
sc_err_t rm_partition_create(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt,
    sc_bool_t secure, sc_bool_t isolated, sc_bool_t restricted,
    sc_bool_t grant, sc_bool_t coherent, sc_rsrc_t resource, 
    const sc_rsrc_t *rsrc_lst, uint32_t rsrc_cnt,
    const sc_pad_t *pad_lst, uint32_t pad_cnt,
    const sc_rm_mem_list_t *mem_lst, uint32_t mem_cnt);

/*!
 * Enable blocking of resources powered off.
 */
void rm_enable_blocking(void);

/*!
 * Internal SC function to reload a subsystem's XRDC info after a power on.
 *
 * @param[in]     ss          subsystem
 * @param[in]     block_enb   flag to skip SCU, skip mem
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t rm_init_subsys(sc_sub_t ss, sc_bool_t block_enb);

/*!
 * Internal SC function to reload all memory regions.
 */
void rm_load_memrg(void);

/*!
 * Internal SC function to dump RM state for debug.
 *
 * @see sc_rm_set_pad_movable().
 */
void rm_dump(sc_rm_pt_t caller_pt);

/** @} */

#ifdef DEBUG

    /*!
     * @name Debug Functions
     * @{
     */

    /*!
     * Internal SC function to dump the internal partition state of the RM service.
     *
     * @param[in]     pt          partition to dump
     */
    void rm_dump_partition(sc_rm_pt_t pt);

    /*!
     * Internal SC function to dump the internal resource state of the RM service.
     *
     * @param[in]     pt          partition to dump
     */
    void rm_dump_resources(sc_rm_pt_t pt);

    /*!
     * Internal SC function to dump the internal memory state of the RM service.
     *
     * @param[in]     pt          partition to dump
     */
    void rm_dump_memregs(sc_rm_pt_t pt);

    /*!
     * Internal SC function to dump the internal pad state of the RM service.
     *
     * @param[in]     pt          partition to dump
     */
    void rm_dump_pads(sc_rm_pt_t pt);

    /** @} */
#endif

/*! Max domain used */
extern uint8_t rm_max_did;

#if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
    /*! Partition name pointers */
    extern const char *rm_part_names[SC_RM_NUM_PARTITION];
#endif

#endif /* SC_RM_SVC_H */

/** @} */

