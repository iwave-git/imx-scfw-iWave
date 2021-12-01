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
 * @file  svc/pad/svc.h
 *
 * Header file containing the API for the System Controller (SC) Pad
 * Control (PAD) function.
 *
 * @addtogroup PAD_SVC
 * @{
 */
/*==========================================================================*/

#ifndef SC_PAD_SVC_H
#define SC_PAD_SVC_H

/* Includes */

#include "svc/pad/api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * @name Internal Functions
 * @{
 */

/*!
 * Internal SC function to initializes the PAD service.
 *
 * @param[in]     api_phase   init phase
 *
 * Initializes the API if /a api_phase = SC_TRUE, otherwise initializes the HW
 * managed by the PAD service. API must be initialized before anything else is
 * done with the service.
 */
void pad_init(sc_bool_t api_phase);

/*!
 * Internal SC function to set the pad value.
 *
 * @see sc_pad_set().
 */
sc_err_t pad_set(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t val);

/*!
 * Internal SC function to set the pad mux.
 *
 * @see sc_pad_set_mux().
 */
sc_err_t pad_set_mux(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t mux,
    sc_pad_config_t config, sc_pad_iso_t iso);

/*
 * This internal function configures the mux settings for a pad. This
 * includes the signal mux, pad config, and low-power isolation mode.
 *
 * @param[in]     pad         pad to configure
 * @param[in]     mux         mux setting
 * @param[in]     config      pad config
 * @param[in]     iso         low-power isolation mode
 *
 * No error returned. Just fails silently.
 */
void pad_force_mux(sc_pad_t pad, uint8_t mux, sc_pad_config_t config,
    sc_pad_iso_t iso);

/*!
 * Internal SC function to set the pad control.
 *
 * @see sc_pad_set_gp().
 */
sc_err_t pad_set_gp(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t ctrl);

/*!
 * Internal SC function to set the pad wakeup control.
 *
 * @see sc_pad_set_wakeup().
 */
sc_err_t pad_set_wakeup(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_wakeup_t wakeup);

/*!
 * Internal SC function to configure a pad.
 *
 * @see sc_pad_set_all().
 */
sc_err_t pad_set_all(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t mux,
    sc_pad_config_t config, sc_pad_iso_t iso, uint32_t ctrl,
    sc_pad_wakeup_t wakeup);

/*!
 * Internal SC function to get the pad value.
 *
 * @see sc_pad_get().
 */
sc_err_t pad_get(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t *val);

/*!
 * Internal SC function to get the pad mux.
 *
 * @see sc_pad_get_mux().
 */
sc_err_t pad_get_mux(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t *mux,
    sc_pad_config_t *config, sc_pad_iso_t *iso);

/*!
 * Internal SC function to get the pad control.
 *
 * @see sc_pad_get_gp().
 */
sc_err_t pad_get_gp(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t *ctrl);

/*!
 * Internal SC function to get the pad wakeup control.
 *
 * @see sc_pad_get_wakeup().
 */
sc_err_t pad_get_wakeup(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_wakeup_t *wakeup);

/*!
 * Internal SC function to get a pad's configuration.
 *
 * @see sc_pad_get_all().
 */
sc_err_t pad_get_all(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t *mux,
    sc_pad_config_t *config, sc_pad_iso_t *iso, uint32_t *ctrl,
    sc_pad_wakeup_t *wakeup);

#ifdef API_HAS_28FDSOI
/*!
 * Internal SC function to set the pad control specific to 28FDSOI.
 *
 * @see sc_pad_set_gp_28fdsoi().
 */
sc_err_t pad_set_gp_28fdsoi(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t dse, sc_pad_28fdsoi_ps_t ps);

/*!
 * Internal SC function to get the pad control specific to 28FDSOI.
 *
 * @see sc_pad_get_gp_28fdsoi().
 */
sc_err_t pad_get_gp_28fdsoi(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t *dse, sc_pad_28fdsoi_ps_t *ps);

/*!
 * Internal SC function to set the pad control specific to 28FDSOI.
 *
 * @see sc_pad_set_gp_28fdsoi_hsic().
 */
sc_err_t pad_set_gp_28fdsoi_hsic(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t dse, sc_bool_t hyp, sc_pad_28fdsoi_pus_t pus,
    sc_bool_t pke, sc_bool_t pue);

/*!
 * Internal SC function to get the pad control specific to 28FDSOI.
 *
 * @see sc_pad_get_gp_28fdsoi_hsic().
 */
sc_err_t pad_get_gp_28fdsoi_hsic(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t *dse, sc_bool_t *hyp, sc_pad_28fdsoi_pus_t *pus,
    sc_bool_t *pke, sc_bool_t *pue);

/*!
 * Internal SC function to set the pad compensation specific to 28FDSOI.
 *
 * @see sc_pad_set_gp_28fdsoi_comp().
 */
sc_err_t pad_set_gp_28fdsoi_comp(sc_rm_pt_t caller_pt, sc_pad_t pad,
    uint8_t compen, sc_bool_t fastfrz, uint8_t rasrcp, uint8_t rasrcn,
    sc_bool_t nasrc_sel, sc_bool_t psw_ovr);

/*!
 * Internal SC function to get the compensation control specific to 28FDSOI.
 *
 * @see sc_pad_get_gp_28fdsoi_comp().
 */
sc_err_t pad_get_gp_28fdsoi_comp(sc_rm_pt_t caller_pt, sc_pad_t pad,
    uint8_t *compen, sc_bool_t *fastfrz, uint8_t *rasrcp, uint8_t *rasrcn,
    sc_bool_t *nasrc_sel, sc_bool_t *compok, uint8_t *nasrc, sc_bool_t *psw_ovr);
#endif

/*!
 * Internal SC function to set a config value.
 *
 * @see sc_pad_config().
 */
sc_err_t pad_config(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t val);

/*!
 * Internal function to map pad irq and index to pad resource.
 *
 * @param[in]     irq         irq of pad
 * @param[out]    idx         index within irq
 *
 * @return Returns the pad mapping.
 *
 * If invalid irq or idx then return is >= SC_NUM_PAD.
 */
sc_pad_t pad_map_irq(uint8_t irq, uint8_t idx);

/** @} */

#if defined(DEBUG) && defined(DEBUG_PAD)
   /*!
     * @name Debug Functions
     * @{
     */

    /*!
     * Internal SC function to dump the internal state of the PAD service.
     *
     * @param[in]     pt          partition to dump
     */
    void pad_dump(sc_rm_pt_t pt);

    /** @} */
#endif

#endif /* SC_PAD_SVC_H */

/** @} */

