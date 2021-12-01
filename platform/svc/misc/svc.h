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
 * @file  svc/misc/svc.h
 *
 * Header file containing the API for the System Controller (SC)
 * Miscellaneous (MISC) function.
 *
 * @addtogroup MISC_SVC
 * @{
 */
/*==========================================================================*/

#ifndef SC_MISC_SVC_H
#define SC_MISC_SVC_H

/* Includes */

#include "svc/misc/api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * @name Internal Functions
 * @{
 */

/*!
 * Internal SC function to initializes the MISC service.
 *
 * @param[in]     api_phase   init phase
 *
 * Initializes the API if /a api_phase = SC_TRUE, otherwise initializes the HW
 * managed by the MISC service. API must be initialized before anything else is
 * done with the service.
 */
void misc_init(sc_bool_t api_phase);

/*!
 * Internal SC function to set a miscellaneous control value.
 *
 * @see sc_misc_set_control().
 */
sc_err_t misc_set_control(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_ctrl_t ctrl, uint32_t val);

/*!
 * Internal SC function to get a miscellaneous control value.
 *
 * @see sc_misc_get_control().
 */
sc_err_t misc_get_control(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_ctrl_t ctrl, uint32_t *val);

/*!
 * Internal SC function to configure the ARI translation for
 * PCIe/SATA resources.
 *
 * @see sc_misc_set_ari().
 */
sc_err_t misc_set_ari(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rsrc_t resource_mst, uint16_t ari, sc_bool_t enable);

/*!
 * Internal SC function to configure max DMA channel priority
 * group for a partition.
 *
 * @see sc_misc_set_max_dma_group().
 */
sc_err_t misc_set_max_dma_group(sc_rm_pt_t caller_pt, sc_rm_pt_t pt, 
    sc_misc_dma_group_t max);

/*!
 * Internal SC function to configure the priority group for a
 * DMA channel.
 *
 * @see sc_misc_set_dma_group().
 */
sc_err_t misc_set_dma_group(sc_rm_pt_t caller_pt, sc_rsrc_t resource, 
    sc_misc_dma_group_t group);

/*!
 * Internal SC function to report boot status.
 *
 * @see sc_misc_boot_status().
 */
void misc_boot_status(sc_rm_pt_t caller_pt, sc_misc_boot_status_t status);

/*!
 * Internal SC function to report a CPU has finished initialization.
 *
 * @see sc_misc_boot_done().
 */
sc_err_t misc_boot_done(sc_rm_pt_t caller_pt, sc_rsrc_t cpu);

/*!
 * Internal SC function to wait for a CPU to be done booting.
 *
 * @param[in]     cpu         CPU to wait for
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t misc_boot_done_wait(sc_rsrc_t cpu);

/*!
 * Internal SC function to start/stop emulation waveform capture.
 *
 * @see sc_misc_waveform_capture().
 */
sc_err_t misc_waveform_capture(sc_rm_pt_t caller_pt, sc_bool_t enable);

/*!
 * Internal SC function to output a debug character.
 *
 * @see sc_misc_debug_out().
 */
void misc_debug_out(sc_rm_pt_t caller_pt, uint8_t ch);

/*!
 * Internal SC function to read otp fuse word
 *
 * @see sc_misc_otp_fuse_read().
 */
sc_err_t misc_otp_fuse_read(sc_rm_pt_t caller_pt,
    uint32_t word, uint32_t *val);

/*!
 * Internal SC function to write otp fuse word
 *
 * @see sc_misc_otp_fuse_write().
 */
sc_err_t misc_otp_fuse_write(sc_rm_pt_t caller_pt,
    uint32_t word, uint32_t val);

/*!
 * This function reports if a resource has a temp sensor.
 *
 * @param[in]     resource    resource to querry
 *
 * @return Returns SC_TRUE if the subsystem containing 
 * /a resource has a temp sensor.
 */
sc_bool_t misc_has_temp(sc_rsrc_t resource);

/*!
 * Internal SC function to set a temp sensor alarm
 *
 * @see sc_misc_set_temp().
 */
sc_err_t misc_set_temp(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_misc_temp_t temp, int16_t celsius, int8_t tenths);

/*!
 * Internal SC function to get a temp sensor value
 *
 * @see sc_misc_get_temp().
 */
sc_err_t misc_get_temp(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_misc_temp_t temp, int16_t *celsius, int8_t *tenths);

/*!
 * Internal SC function to return SCFW build info
 *
 * @see sc_misc_build_info().
 */
void misc_build_info(sc_rm_pt_t caller_pt, uint32_t *build,
    uint32_t *commit);

/*!
 * Internal SC function to return the device unique ID
 *
 * @see sc_misc_unique_id().
 */
void misc_unique_id(sc_rm_pt_t caller_pt, uint32_t *id_l,
    uint32_t *id_h);

/*!
 * Internal SC function to return the boot device
 *
 * @see sc_misc_get_boot_dev().
 */
void misc_get_boot_dev(sc_rm_pt_t caller_pt, sc_rsrc_t *dev);

/*!
 * Internal SC function to return the boot type
 *
 * @see sc_misc_get_boot_type().
 */
sc_err_t misc_get_boot_type(sc_rm_pt_t caller_pt, sc_misc_bt_t *type);

/*!
 * Internal SC function to return the boot container index
 *
 * @see sc_misc_get_boot_containere().
 */
sc_err_t misc_get_boot_container(sc_rm_pt_t caller_pt, uint8_t *idx);

/*!
 * Internal SC function to return the current status of the ON/OFF button
 *
 * @see sc_misc_get_button_status().
 */
void misc_get_button_status(sc_rm_pt_t caller_pt, sc_bool_t *status);

/*!
 * Internal SC function to return the ROM patch checksum
 *
 * @see sc_misc_rompatch_checksum().
 */
sc_err_t misc_rompatch_checksum(sc_rm_pt_t caller_pt, uint32_t *checksum);

/*!
 * Internal SC function to call board IOCTL
 *
 * @see sc_misc_board_ioctl().
 */
sc_err_t misc_board_ioctl(sc_rsrc_t mu, uint32_t *parm1,
    uint32_t *parm2, uint32_t *parm3);

/*!
 * Internal SC function to return API version info 
 *
 * @see sc_misc_api_ver().
 */
void misc_api_ver(sc_rm_pt_t caller_pt, uint16_t *cl_maj,
    uint16_t *cl_min, uint16_t *sv_maj, uint16_t *sv_min);

/** @} */

#if defined(DEBUG) && defined(DEBUG_MISC)
   /*!
     * @name Debug Functions
     * @{
     */

    /*!
     * Internal SC function to dump the internal state of the MISC service.
     *
     * @param[in]     pt          partition to dump
     */
    void misc_dump(sc_rm_pt_t pt);

    /** @} */
#endif


#endif /* SC_MISC_SVC_H */

/** @} */

