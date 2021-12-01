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
 * @file  svc/pm/svc.h
 *
 * Header file containing the API for the System Controller (SC) Power
 * Management (PM) function. This includes functions for power state
 * control, clock control, reset control, and wake-up event control.
 *
 * @addtogroup PM_SVC
 * @{
 */
/*==========================================================================*/

#ifndef SC_PM_SVC_H
#define SC_PM_SVC_H

/* Includes */

#include "main/main.h"
#include "svc/pm/api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * @name Internal Functions
 * @{
 */

/*
 * Internal SC function that sets the boolean indicating that partition has booted.
 *
 * @param[in]     pt          handle of partition to set
 * @param[in]     booted      boolean: true indicates that partition has booted
 */
void pm_set_booted(sc_rm_pt_t pt, sc_bool_t booted);

/*
 * Internal SC function that gets boolean indicating that partition has booted.
 *
 * @param[in]     caller_pt   handle of partition to check
 *
 * @return Returns a boolean that indicates if partition has booted
 */
sc_bool_t pm_get_booted(sc_rm_pt_t pt);

/*!
 * Internal SC function to initializes the PM service.
 *
 * @param[in]     api_phase   init phase
 *
 * Initializes the API if /a api_phase = SC_TRUE, otherwise initializes the HW
 * managed by the PM service. API must be initialized before anything else is
 * done with the service.
 */
void pm_init(sc_bool_t api_phase);

/*!
 * This function initializes a new partition.
 *
 * @param[in]     caller_pt   handle of caller partition
 * @param[in]     pt          handle of partition
 *
 * Note this function should only be called by the resource manager when
 * a new partition is allocated. The default power mode is on.
 */
void pm_init_part(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/*!
 * Internal SC function to set the power mode of the system.
 *
 * @see sc_pm_set_sys_power_mode().
 */
sc_err_t pm_set_sys_power_mode(sc_rm_pt_t caller_pt, 
    sc_pm_power_mode_t mode);

/*!
 * This function initializes a partition to off.
 *
 * @param[in]     pt          handle of partition
 *
 * Note this function should only be called immediately after creating a new
 * partition that should be off (default after creating is on).
 */
void pm_init_partition_power_off(sc_rm_pt_t pt);

/*!
 * Internal SC function to set the power mode of a partition.
 *
 * @see sc_pm_set_partition_power_mode().
 */
sc_err_t pm_set_partition_power_mode(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_power_mode_t mode);

/*!
 * Internal SC function to set the power mode of a partition.
 *
 * @see sc_pm_partition_power_off().
 */
void pm_partition_power_off(sc_rm_pt_t caller_pt);

/*!
 * Internal function to updates the power mode of a partition.
 *
 * @param[in]     caller_pt   handle of partition to update
 * @param[in]     pt          handle of partition
 * @param[in]     mode        power mode to apply
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid partition or mode,
 * - SC_ERR_NOACCESS if caller's partition is not the owner or
 *   parent of \a pt
 *
 * The power mode of the partitions is a max power any resource will
 * be set to. Calling this will result in all resources owned
 * by \a pt to have their power changed to the lower of \a mode or the
 * individual resource mode set using sc_pm_set_resource_power_mode().
 */
sc_err_t pm_update_partition_power_mode(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_power_mode_t mode);

/*!
 * Internal SC function to send wake interrupt to a partition.
 *
 * @see sc_pm_partition_wake().
 */
sc_err_t pm_partition_wake(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/*!
 * Internal SC function to get the power mode of a partition.
 *
 * @see sc_pm_get_sys_power_mode().
 */
sc_err_t pm_get_sys_power_mode(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_power_mode_t *mode);

/*!
 * Internal SC function to update the power state of a resource.
 *
 * @param[in]     idx         unified resource index
 *
 * Used to update when a partition changes state or resource is moved.
 */
void pm_update_ridx(sc_rm_idx_t idx);

/*!
 * Internal SC function to get the functional state of a resource.
 *
 * @param[in]     resource    unified resource index
 *
 * @return Returns a boolean (SC_TRUE = functional).
 *
 * Used to see if a resource is ready to be used.
 */
sc_bool_t pm_is_resource_accessible(sc_rsrc_t resource);

/*!
 * Internal SC function to init the power mode of a resource just after ROM boot
 */
void pm_init_rsrc_power_mode(sc_rsrc_t rsrc, sc_pm_power_mode_t mode);

/*!
 * Internal SC function to set the power mode of a resource via MU.
 *
 * @see sc_pm_set_resource_power_mode().
 */
sc_err_t pm_set_resource_power_mode(sc_rsrc_t mu,
    sc_rsrc_t resource, sc_pm_power_mode_t mode);

/*!
 * Internal function set the power mode of a resource based via pt.
 *
 * @param[in]     pt          partition of resource
 * @param[in]     resource    ID of the resource
 * @param[in]     mode        power mode to apply
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * @see sc_pm_set_resource_power_mode().
 */
sc_err_t pm_set_resource_power_mode_pt(sc_rm_pt_t caller_pt,
    sc_rsrc_t resource, sc_pm_power_mode_t mode);

/*!
 * Internal SC function to set power mode for all resources in a child
 * partition.
 *
 * @see sc_pm_set_resource_power_mode_all().
 */
sc_err_t pm_set_resource_power_mode_all(sc_rm_pt_t caller_pt, 
    sc_rm_pt_t pt, sc_pm_power_mode_t mode, sc_rsrc_t exclude);

/*!
 * This function sets the power mode of a resource index.
 *
 * @param[in]     idx         index of the resource
 * @param[in]     mode        power mode to apply
 */
void pm_set_rsrc_power_mode(sc_rm_idx_t idx,
    sc_pm_power_mode_t mode);

/*!
 * This function updates the power mode of a resource index.
 *
 * @param[in]     idx         index of the resource
 * @param[in]     mode        power mode to apply
 */
void pm_set_active_rsrc_power_mode(sc_rm_idx_t idx,
    sc_pm_power_mode_t mode);

/*!
 * Internal SC function to force the power mode of a resource. It
 * should only be called by the SC during initial configuration.
 *
 * @param[in]     resource    ID of the resource
 * @param[in]     mode        power mode to apply
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid resource or mode
 *
 * Note only SC_PM_PW_MODE_OFF and SC_PM_PW_MODE_ON are valid. Other modes
 * will return an error. Resources set to SC_PM_PW_MODE_ON will reflect the
 * power mode of the partition and will change as that changes.
 *
 *  @see sc_pm_set_partition_power_mode().
 */
sc_err_t pm_force_resource_power_mode(sc_rsrc_t resource,
    sc_pm_power_mode_t mode);

/*!
 * Internal SC function to force the power mode of a resource. It
 * should only be called by the SC during initial configuration.
 *
 * @param[in]     resource    ID of the resource
 * @param[in]     mode        power mode to apply
 *
 *  @see sc_pm_set_partition_power_mode().
 */
void pm_force_resource_power_mode_v(sc_rsrc_t resource,
    sc_pm_power_mode_t mode);

/*!
 * Internal SC function to get the power mode of a resource.
 *
 * @see sc_pm_get_resource_power_mode().
 */
sc_err_t pm_get_resource_power_mode(sc_rm_pt_t caller_pt,
    sc_rsrc_t resource, sc_pm_power_mode_t *mode);

/*!
 * This function gets the power mode of a resource index.
 *
 * @param[in]     idx         index of the resource
 * @param[in]     mode        power mode to apply
 */
void pm_get_rsrc_power_mode(sc_rm_idx_t idx, 
    sc_pm_power_mode_t *mode);

/*!
 * This function gets the active power mode of a resource index.
 *
 * @param[in]     idx         index of the resource
 * @param[in]     mode        active power mode for the resource
 */
void pm_get_active_rsrc_power_mode(sc_rm_idx_t idx, 
    sc_pm_power_mode_t *mode);

/*!
 * Internal SC function to request the power mode a resource can enter
 * in some low power conditions.
 *
 * @see sc_pm_req_low_power_mode().
 */
sc_err_t pm_req_low_power_mode(sc_rm_pt_t caller_pt, sc_rsrc_t resource, 
    sc_pm_power_mode_t mode);

/*!
 * Internal SC function to request low-power mode for a CPU.
 *
 * @see sc_pm_req_cpu_low_power_mode().
 */
sc_err_t pm_req_cpu_low_power_mode(sc_rm_pt_t caller_pt, sc_rsrc_t resource, 
    sc_pm_power_mode_t mode, sc_pm_wake_src_t wake_src);

/*!
 * Internal SC function to set the resume address of a CPU.
 *
 * @see sc_pm_set_cpu_resume_addr().
 */
sc_err_t pm_set_cpu_resume_addr(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_faddr_t address);

/*!
 * Internal SC function to set the resume parameters of a CPU.
 *
 * @see sc_pm_set_cpu_resume().
 */
sc_err_t pm_set_cpu_resume(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_bool_t isPrimary, sc_faddr_t address);

/*!
 * Internal SC function to request power mode for system-level interfaces.
 *
 * @see pm_req_sys_if_power_mode().
 */
sc_err_t pm_req_sys_if_power_mode(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_sys_if_t sys_if, sc_pm_power_mode_t hpm, sc_pm_power_mode_t lpm);

/*!
 * Internal SC function to set the rate of a resource's clock/PLL.
 *
 * @see sc_pm_set_clock_rate().
 */
sc_err_t pm_set_clock_rate(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clock_rate_t *rate);

/*!
 * Internal SC function to get the rate of a resource's clock/PLL.
 *
 * @see sc_pm_get_clock_rate().
 */
sc_err_t pm_get_clock_rate(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clock_rate_t *rate);

/*!
 * Internal SC function to enable/disable a resource's clock.
 *
 * @see sc_pm_clock_enable().
 */
sc_err_t pm_clock_enable(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_bool_t enable, sc_bool_t autog);

/*!
 * Internal SC function to force a resource's clock to be enabled.
 *
 * @param[in]     resource    ID of the resource
 * @param[in]     clk         clock to affect
 * @param[in]     enable      enable if SC_TRUE; otherwise depends on
 *                            state from pm_clock_enable()
 *
 * Refer to the [Clock List](@ref CLOCKS) for valid clock values.
 */
void pm_force_clock_enable(sc_rsrc_t resource, sc_pm_clk_t clk,
    sc_bool_t enable);

/*!
 * Internal SC function to set a clock parent.
 *
 * @see sc_pm_set_clock_parent().
 */
sc_err_t pm_set_clock_parent(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clk_parent_t parent);

/*!
 * Internal SC function to get a clock parent.
 *
 * @see sc_pm_get_clock_parent().
 */
sc_err_t pm_get_clock_parent(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_pm_clk_t clk, sc_pm_clk_parent_t *parent);

/*!
 * Internal SC function to boot a partition.
 *
 * @see sc_pm_boot().
 */
sc_err_t pm_boot(sc_rm_pt_t caller_pt, sc_rm_pt_t pt, 
    sc_rsrc_t resource_cpu, sc_faddr_t boot_addr, 
    sc_rsrc_t resource_mu, sc_rsrc_t resource_dev);

/*!
 * Internal SC function to set a partition's boot parameters.
 *
 * @see sc_pm_set_boot_parm().
 */
sc_err_t pm_set_boot_parm(sc_rm_pt_t caller_pt, 
    sc_rsrc_t resource_cpu, sc_faddr_t boot_addr, 
    sc_rsrc_t resource_mu, sc_rsrc_t resource_dev);

/*!
 * Internal SC function used to get the boot parameters for a partition.
 *
 * @param[in]     caller_pt   calling partition
 * @param[out]    resource_cpu  pointer to return the ID of the CPU resource to start
 * @param[out]    boot_addr     pointer to return the 64-bit boot address
 * @param[out]    resource_mu   pointer to return the ID of the MU that must be powered (0=none)
 * @param[out]    resource_dev  pointer to return the ID of the boot device that must be powered (0=none)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid caller_pt
 */
sc_err_t pm_get_boot_parm(sc_rm_pt_t caller_pt, 
    sc_rsrc_t *resource_cpu, sc_faddr_t *boot_addr, 
    sc_rsrc_t *resource_mu, sc_rsrc_t *resource_dev);

/*!
 * Internal SC function to reboot the caller's partition.
 *
 * @see sc_pm_reboot().
 */
void pm_reboot(sc_rm_pt_t caller_pt, sc_pm_reset_type_t type);

/*!
 * Internal SC function to get the reset reason.
 *
 * @see sc_pm_reset_reason().
 */
sc_err_t pm_reset_reason(sc_rm_pt_t caller_pt,
    sc_pm_reset_reason_t *reason);

/*!
 * Internal SC function to get the partition that caused a reset.
 *
 * @see sc_pm_get_reset_part().
 */
sc_err_t pm_get_reset_part(sc_rm_pt_t caller_pt, sc_rm_pt_t *pt);

/*!
 * Internal SC function to start/stop a CPU.
 *
 * @see sc_pm_cpu_start().
 */
sc_err_t pm_cpu_start(sc_rm_pt_t caller_pt, sc_rsrc_t resource, 
    sc_bool_t enable, sc_faddr_t address);

/*!
 * Internal SC function to reset a CPU.
 *
 * @see sc_pm_cpu_reset().
 */
void pm_cpu_reset(sc_rm_pt_t caller_pt, sc_rsrc_t resource, 
    sc_faddr_t address);

/*!
 * Internal SC function to reset a resource.
 *
 * @see sc_pm_resource_reset().
 */
 sc_err_t pm_resource_reset(sc_rsrc_t mu, sc_rsrc_t resource);

/*!
 * Internal SC function to reboot a partition.
 *
 * @see sc_pm_reboot_partition().
 */
sc_err_t pm_reboot_partition(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_reset_type_t type);

/*!
 * Internal SC function to conntinue reboot.
 *
 * @see sc_reboot_continue().
 */
sc_err_t pm_reboot_continue(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/*!
* Internal SC function to force the conntinue of all reboots.
*/
void pm_reboot_continue_all(void);

/*!
 * Internal SC function to reset the system.
 *
 * @see sc_pm_reset().
 */
sc_err_t pm_reset(sc_rm_pt_t caller_pt, sc_pm_reset_type_t type);

/*!
 * Internal SC function used to reboot a partition.
 *
 * @param[in]     caller_pt   calling partition
 * @param[in]     pt          handle of partition to reboot
 * @param[in]     type        reset type
 * @param[in]     reason      reset reason
 * @param[in]     mode        power mode to go down to as part of reboot
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid partition or reason
 *
 * Most peripherals owned by the partition will be reset if
 * possible. SC state (partitions, power, clocks, etc.) is reset. The
 * boot SW of the booting CPU must be able to handle peripherals that
 * that are not reset.
 */
sc_err_t pm_reboot_part(sc_rm_pt_t caller_pt, sc_rm_pt_t pt,
    sc_pm_reset_type_t type, sc_pm_reset_reason_t reason,
    sc_pm_power_mode_t mode);

/*!
 * Internal SC function to get boolean indicating that a partition was
 * started.
 *
 * @see sc_pm_is_partition_started().
 */
sc_bool_t pm_is_partition_started(sc_rm_pt_t caller_pt, sc_rm_pt_t pt);

/** @} */

#if defined(DEBUG) && defined(DEBUG_PM)
   /*!
     * @name Debug Functions
     * @{
     */

    /*!
     * Internal SC function to dump the internal state of the PM service.
     *
     * @param[in]     pt          partition to dump
     */
    void pm_dump(sc_rm_pt_t pt);

    /** @} */
#endif

#endif /* SC_PM_SVC_H */

/** @} */

