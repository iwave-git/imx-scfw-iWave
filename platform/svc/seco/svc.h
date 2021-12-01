/*
** ###################################################################
**
**     Copyright 2019-2021 NXP
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
 * @file  svc/seco/svc.h
 *
 * Header file containing the API for the System Controller (SC)
 * Security (SECO) function.
 *
 * @addtogroup SECO_SVC
 * @{
 */
/*==========================================================================*/

#ifndef SC_SECO_SVC_H
#define SC_SECO_SVC_H

/* Includes */

#include "svc/seco/api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * @name Internal Functions
 * @{
 */

/*!
 * Internal SC function to load a SECO image.
 *
 * @see sc_seco_image_load().
 */
sc_err_t seco_image_load(sc_rm_pt_t caller_pt,
    sc_faddr_t addr_src, sc_faddr_t addr_dst, uint32_t len, sc_bool_t fw);

/*!
 * Internal SC function to authenticate a SECO image or command.
 *
 * @see sc_seco_authenticate().
 */
sc_err_t seco_authenticate(sc_rm_pt_t caller_pt,
    sc_seco_auth_cmd_t cmd, sc_faddr_t addr);

/*!
 * Internal SC function to authenticate a SECO image or command
 ( (enhanced version).
 *
 * @see sc_seco_enh_authenticate().
 */
sc_err_t seco_enh_authenticate(sc_rm_pt_t caller_pt,
    sc_seco_auth_cmd_t cmd, sc_faddr_t addr,
    uint32_t mask1, uint32_t mask2);

/*!
 * Internal SC function to load a SECO key.
 *
 * @see sc_seco_load_key().
 */
sc_err_t seco_load_key(sc_rm_pt_t caller_pt,
    uint32_t id, sc_faddr_t addr);

/*!
 * Internal SC function to generate a key blob.
 *
 * @see sc_seco_gen_key_blob().
 */
sc_err_t seco_gen_key_blob(sc_rm_pt_t caller_pt, uint32_t id,
    sc_faddr_t load_addr, sc_faddr_t export_addr, uint16_t max_size);

/*!
 * Internal SC function to securely write a group of fuse words.
 *
 * @see sc_seco_fuse_write().
 */
sc_err_t seco_fuse_write(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to apply a patch.
 *
 * @see sc_seco_patch().
 */
sc_err_t seco_patch(sc_rm_pt_t caller_pt, sc_faddr_t addr);

#ifdef API_HAS_NO_V2X
/*!
 * Internal SC function to partition the monotonic counter w/o V2X HSM.
 *
 * @see sc_seco_set_mono_counter_partition().
 */
sc_err_t seco_set_mono_counter_partition(sc_rm_pt_t caller_pt,
    uint16_t *she);
#endif

#ifdef API_HAS_V2X
/*!
 * Internal SC function to partition the monotonic counter with V2X HSM.
 *
 * @see sc_seco_set_mono_counter_partition_hsm().
 */
sc_err_t seco_set_mono_counter_partition_hsm(sc_rm_pt_t caller_pt,
    uint16_t *she, uint16_t *hsm);
#endif

/*!
 * Internal SC function to set FIPS mode.
 *
 * @see sc_seco_set_fips_mode().
 */
sc_err_t seco_set_fips_mode(sc_rm_pt_t caller_pt, uint8_t mode,
    uint32_t *reason);

/*!
 * Internal SC function to securely zeroize all plaintext secret and private
 * cryptographic keys and CSPs within the module.
 *
 * @see sc_seco_fips_key_zero().
 */
sc_err_t seco_fips_key_zero(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to start the RNG.
 *
 * @see sc_seco_start_rng().
 */
sc_err_t seco_start_rng(sc_rm_pt_t caller_pt, sc_seco_rng_stat_t *status);

/*!
 * Internal SC function to securely enable debug.
 *
 * @see sc_seco_enabled_debug().
 */
sc_err_t seco_enable_debug(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to update the lifecycle.
 *
 * @see sc_seco_forward_lifecycle().
 */
sc_err_t seco_forward_lifecycle(sc_rm_pt_t caller_pt, uint32_t change);

/*!
 * Internal SC function to securely reverse the lifecycle.
 *
 * @see sc_seco_return_lifecycle().
 */
sc_err_t seco_return_lifecycle(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to return SECO FW version info.
 *
 * @see sc_seco_build_info().
 */
void seco_build_info(sc_rm_pt_t caller_pt, uint32_t *version,
    uint32_t *commit);

#ifdef API_HAS_V2X
/*!
 * Internal SC function to return V2X FW version info.
 *
 * @see sc_seco_v2x_build_info().
 */
sc_err_t seco_v2x_build_info(sc_rm_pt_t caller_pt, uint32_t *version,
    uint32_t *commit);
#endif

/*!
 * Internal SC function to return SECO chip info.
 *
 * @see sc_seco_chip_info().
 */
sc_err_t seco_chip_info(sc_rm_pt_t caller_pt, uint16_t *lc, 
    uint16_t *monotonic, uint32_t *uid_l, uint32_t *uid_h);

/*!
 * Internal SC function to return an event from the SECO error log.
 *
 * @see sc_seco_get_event().
 */
sc_err_t seco_get_event(sc_rm_pt_t caller_pt, uint8_t idx,
    uint32_t *event);

/*!
 * Internal SC function to set the attestation mode.
 *
 * @see sc_seco_attest_mode().
 */
sc_err_t seco_attest_mode(sc_rm_pt_t caller_pt, uint32_t mode);

/*!
 * Internal SC function to request atestation.
 *
 * @see sc_seco_attest().
 */
sc_err_t seco_attest(sc_rm_pt_t caller_pt, uint64_t nonce);

/*!
 * Internal SC function to retrieve attestation public key.
 *
 * @see sc_seco_get_attest_pkey().
 */
sc_err_t seco_get_attest_pkey(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to retrieve attestation signature and parameters.
 *
 * @see sc_seco_get_attest_sign().
 */
sc_err_t seco_get_attest_sign(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to verify attestation.
 *
 * @see sc_seco_attest_verify().
 */
sc_err_t seco_attest_verify(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to commit SRK/FW changes.
 *
 * @see sc_seco_commit().
 */
sc_err_t seco_commit(sc_rm_pt_t caller_pt, uint32_t *info);

/** @} */

/*!
 * Internal SC function to get manufacturing protection public key.
 *
 * @see sc_seco_get_mp_key().
 */
sc_err_t seco_get_mp_key(sc_rm_pt_t caller_pt, sc_faddr_t dst_addr,
    uint16_t dst_size);

/*!
 * Internal SC function to update manufacturing protection message register.
 *
 * @see sc_seco_update_mpmr().
 */
sc_err_t seco_update_mpmr(sc_rm_pt_t caller_pt, sc_faddr_t addr,
    uint8_t size, uint8_t lock);

/*!
 * Internal SC function to get manufacturing protection signature.
 *
 * @see sc_seco_get_mp_sign().
 */
sc_err_t seco_get_mp_sign(sc_rm_pt_t caller_pt, sc_faddr_t msg_addr,
    uint16_t msg_size, sc_faddr_t dst_addr, uint16_t dst_size);

/*!
 * Internal SC function to send a generic signed message to the
 * SECO SHE/HSM components.
 *
 * @see sc_seco_sab_msg().
 */
sc_err_t seco_sab_msg(sc_rm_pt_t caller_pt, sc_faddr_t addr);

/*!
 * Internal SC function to configure a CAAM job ring to allow it to make
 * trusted descriptors.
 *
 * @see sc_seco_caam_td_config().
 */
sc_err_t seco_caam_td_config(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_bool_t allow, sc_bool_t lock);

/*!
 * Internal SC function to enable the security violation interrupt.
 *
 * @see sc_seco_secvio_enable().
 */
sc_err_t seco_secvio_enable(sc_rm_pt_t caller_pt);

/*!
 * Internal SC function to read/write SNVS security violation
 * and tamper registers.
 *
 * @see sc_seco_secvio_config().
 */
sc_err_t seco_secvio_config(sc_rm_pt_t caller_pt, uint8_t id, uint8_t access,
    uint32_t *data0, uint32_t *data1, uint32_t *data2, uint32_t *data3,
    uint32_t *data4, uint8_t size);

/*!
 * Internal SC function to read/write SNVS security violation
 * and tamper DGO registers.
 *
 * @see sc_seco_secvio_dgo_config().
 */
sc_err_t seco_secvio_dgo_config(sc_rm_pt_t caller_pt, uint8_t id,
    uint8_t access, uint32_t *data);

#if defined(DEBUG) && defined(DEBUG_SECO)
   /*!
     * @name Debug Functions
     * @{
     */

    /*!
     * Internal SC function to dump the internal state of the SECO service.
     *
     * @param[in]     pt          partition to dump
     */
    void seco_dump(sc_rm_pt_t pt);

    /** @} */
#endif

#endif /* SC_SECO_SVC_H */

/** @} */

