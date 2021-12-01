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
 * @file  svc/seco/svc.c
 *
 * File containing the implementation of the System Controller (SC)
 * Security (SECO) function.
 *
 * @addtogroup SECO_SVC
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "main/board.h"
#include "svc/seco/svc.h"
#include "svc/rm/svc.h"
#include "ss/inf/inf.h"
#ifdef HAS_SECO
#include "drivers/seco/fsl_seco.h"
#endif
#ifdef HAS_V2X
#include "drivers/v2x/fsl_v2x.h"
#endif
#include "drivers/snvs/fsl_snvs.h"

/* Local Defines */

/* Local Types */

/* Local Functions */

/* Local Variables */

/*--------------------------------------------------------------------------*/
/* Load a SECO image                                                        */
/*--------------------------------------------------------------------------*/
sc_err_t seco_image_load(sc_rm_pt_t caller_pt, sc_faddr_t addr_src,
    sc_faddr_t addr_dst, uint32_t len, sc_bool_t fw)
{
    #ifdef HAS_SECO
        SECO_Image_Load(addr_src, addr_dst, len, fw);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Authenticate a SECO image or command                                     */
/*--------------------------------------------------------------------------*/
sc_err_t seco_authenticate(sc_rm_pt_t caller_pt,
    sc_seco_auth_cmd_t cmd, sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_Authenticate(cmd, addr, 0U, 0U);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Authenticate a SECO image or command (enhanced version)                  */
/*--------------------------------------------------------------------------*/
sc_err_t seco_enh_authenticate(sc_rm_pt_t caller_pt,
    sc_seco_auth_cmd_t cmd, sc_faddr_t addr,
    uint32_t mask1, uint32_t mask2)
{
    #ifdef HAS_SECO
        SECO_Authenticate(cmd, addr, mask1, mask2);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Load a SECO key                                                          */
/*--------------------------------------------------------------------------*/
sc_err_t seco_load_key(sc_rm_pt_t caller_pt, uint32_t id,
    sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_LoadKey(id, addr);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Generate key blob                                                        */
/*--------------------------------------------------------------------------*/
sc_err_t seco_gen_key_blob(sc_rm_pt_t caller_pt, uint32_t id,
    sc_faddr_t load_addr, sc_faddr_t export_addr, uint16_t max_size)
{
    #ifdef HAS_SECO
        SECO_GenKeyBlob(id, load_addr, export_addr, max_size);
    
        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Secure fuse write command                                                */
/*--------------------------------------------------------------------------*/
sc_err_t seco_fuse_write(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_SecureWriteFuse(addr);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Secure patch                                                             */
/*--------------------------------------------------------------------------*/
sc_err_t seco_patch(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_ScuPatch(addr);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

#ifdef API_HAS_NO_V2X
/*--------------------------------------------------------------------------*/
/* Partition the monotonic counter w/o V2X HSM                              */
/*--------------------------------------------------------------------------*/
sc_err_t seco_set_mono_counter_partition(sc_rm_pt_t caller_pt, uint16_t *she)
{
    #ifdef HAS_SECO
        sc_err_t err = SC_ERR_NONE;
        uint16_t hsm = 0U;

        /* Check access permissions */
        SYSTEM(caller_pt);

        if (err == SC_ERR_NONE)
        {
            SECO_SetMonoCounterPartition(she, &hsm);
            err = seco_err;
        }

        return err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}
#endif

#ifdef API_HAS_V2X
/*--------------------------------------------------------------------------*/
/* Partition the monotonic counter with V2X HSM                             */
/*--------------------------------------------------------------------------*/
sc_err_t seco_set_mono_counter_partition_hsm(sc_rm_pt_t caller_pt,
    uint16_t *she, uint16_t *hsm)
{
    #ifdef HAS_SECO
        sc_err_t err = SC_ERR_NONE;

        /* Check access permissions */
        SYSTEM(caller_pt);

        if (err == SC_ERR_NONE)
        {
            SECO_SetMonoCounterPartition(she, hsm);
            err = seco_err;
        }

        return err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}
#endif

/*--------------------------------------------------------------------------*/
/* Set FIPS mode                                                            */
/*--------------------------------------------------------------------------*/
sc_err_t seco_set_fips_mode(sc_rm_pt_t caller_pt, uint8_t mode,
    uint32_t *reason)
{
    #ifdef HAS_SECO
        sc_err_t err = SC_ERR_NONE;
        
        /* Check access permissions */
        SYSTEM(caller_pt);
        
        if (err == SC_ERR_NONE)
        {
            *reason = SECO_SetFipsMode(mode);
            err = seco_err;
        }

        return err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* zeroize all plaintext secret and private cryptographic keys              */
/*--------------------------------------------------------------------------*/
sc_err_t seco_fips_key_zero(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_FipsKeyZero(addr);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Start RNG                                                                */
/*--------------------------------------------------------------------------*/
sc_err_t seco_start_rng(sc_rm_pt_t caller_pt, sc_seco_rng_stat_t *status)
{
    #ifdef HAS_SECO
        *status = SECO_StartRNG();

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Enabled debug                                                            */
/*--------------------------------------------------------------------------*/
sc_err_t seco_enable_debug(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_EnableDebug(addr);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Move SECO lifecycle forward                                              */
/*--------------------------------------------------------------------------*/
sc_err_t seco_forward_lifecycle(sc_rm_pt_t caller_pt, uint32_t change)
{
    #ifdef HAS_SECO
        SECO_ForwardLifecycle(change);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Return SECO lifecycle                                                    */
/*--------------------------------------------------------------------------*/
sc_err_t seco_return_lifecycle(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_ReturnLifecycle(addr);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Return SECO FW build info                                                */
/*--------------------------------------------------------------------------*/
void seco_build_info(sc_rm_pt_t caller_pt, uint32_t *version,
    uint32_t *commit)
{
    #ifdef HAS_SECO
        sc_bool_t dirty;

        /* Return info */
        SECO_Version(version, commit, &dirty);

        if (seco_err != SC_ERR_NONE)
        {
            *version = 0U;
            *commit = 0U;
        }
    #else
        *version = 0U;
        *commit = 0U;    
    #endif
}

#ifdef API_HAS_V2X
/*--------------------------------------------------------------------------*/
/* Return V2X FW build info                                                */
/*--------------------------------------------------------------------------*/
sc_err_t seco_v2x_build_info(sc_rm_pt_t caller_pt, uint32_t *version,
    uint32_t *commit)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t dirty;
    sc_pm_power_mode_t mode = SC_PM_PW_MODE_OFF;

    /* Get V2X power state */
    err = pm_get_resource_power_mode(SC_PT, SC_R_V2X, &mode);
    
    /* Error? */
    if (err == SC_ERR_NONE)
    {
        /* V2X on? */
        if (mode > SC_PM_PW_MODE_STBY)
        {
            V2X_Version(version, commit, &dirty);
            if (v2x_err != SC_ERR_NONE)
            {
                err = v2x_err;
            }
        }
        else
        {
            /* No power so error */
            err = SC_ERR_NOPOWER;
        }
    }

    /* Return 0 version on error */
    if (err != SC_ERR_NONE)
    {
        *version = 0U;
        *commit = 0U;
    }

    return err;
}
#endif

/*--------------------------------------------------------------------------*/
/* Return SECO chip info                                                    */
/*--------------------------------------------------------------------------*/
sc_err_t seco_chip_info(sc_rm_pt_t caller_pt, uint16_t *lc, 
    uint16_t *monotonic, uint32_t *uid_l, uint32_t *uid_h)
{
    #ifdef HAS_SECO
        /* Return info */
        SECO_ChipInfo(lc, monotonic, uid_l, uid_h);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif   
}

/*--------------------------------------------------------------------------*/
/* Return SECO event                                                        */
/*--------------------------------------------------------------------------*/
sc_err_t seco_get_event(sc_rm_pt_t caller_pt, uint8_t idx,
    uint32_t *event)
{
    #ifdef HAS_SECO
        /* Return event */
        *event = SECO_GetEvent(idx);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif   
}

/*--------------------------------------------------------------------------*/
/* Set the attestation mode                                                 */
/*--------------------------------------------------------------------------*/
sc_err_t seco_attest_mode(sc_rm_pt_t caller_pt, uint32_t mode)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Check permissions */
    OWNED(SC_R_ATTESTATION);

    #ifdef HAS_SECO
        /* Return info */
        if (err == SC_ERR_NONE)
        {
            SECO_AttestMode(mode);
            err = seco_err;
        }
    #else
        err = SC_ERR_UNAVAILABLE;
    #endif   

    return err;
}

/*--------------------------------------------------------------------------*/
/* Request atestation                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t seco_attest(sc_rm_pt_t caller_pt, uint64_t nonce)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check permissions */
    OWNED(SC_R_ATTESTATION);

    #ifdef HAS_SECO
        /* Return info */
        if (err == SC_ERR_NONE)
        {
            SECO_Attest(nonce);
            err = seco_err;
        }
    #else
        err = SC_ERR_UNAVAILABLE;
    #endif   

    return err;
}

/*--------------------------------------------------------------------------*/
/* Retrieve attestation public key                                          */
/*--------------------------------------------------------------------------*/
sc_err_t seco_get_attest_pkey(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check permissions */
    OWNED(SC_R_ATTESTATION);

    #ifdef HAS_SECO
        /* Return info */
        if (err == SC_ERR_NONE)
        {
            SECO_GetAttestPublicKey(addr);
            err = seco_err;
        }
    #else
        err = SC_ERR_UNAVAILABLE;
    #endif   

    return err;
}

/*--------------------------------------------------------------------------*/
/* Retrieve attestation signature and parameters                            */
/*--------------------------------------------------------------------------*/
sc_err_t seco_get_attest_sign(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check permissions */
    OWNED(SC_R_ATTESTATION);

    #ifdef HAS_SECO
        /* Return info */
        if (err == SC_ERR_NONE)
        {
            SECO_GetAttestSign(addr);
            err = seco_err;
        }
    #else
        err = SC_ERR_UNAVAILABLE;
    #endif   

    return err;
}

/*--------------------------------------------------------------------------*/
/* Verify attestation                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t seco_attest_verify(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check permissions */
    OWNED(SC_R_ATTESTATION);

    #ifdef HAS_SECO
        /* Return info */
        if (err == SC_ERR_NONE)
        {
            SECO_AttestVerify(addr);
            err = seco_err;
        }
    #else
        err = SC_ERR_UNAVAILABLE;
    #endif   

    return err;
}

/*--------------------------------------------------------------------------*/
/* Commit SRK/FW info                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t seco_commit(sc_rm_pt_t caller_pt, uint32_t *info)
{
    #ifdef HAS_SECO
        /* Return info */
        SECO_Commit(info);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif   
}

/*--------------------------------------------------------------------------*/
/* Get manufacturing protection public key                                  */
/*--------------------------------------------------------------------------*/
sc_err_t seco_get_mp_key(sc_rm_pt_t caller_pt, sc_faddr_t dst_addr,
    uint16_t dst_size)
{
    #ifdef HAS_SECO
        /* Return info */
        SECO_GetMPKey(dst_addr, dst_size);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif   
}

/*--------------------------------------------------------------------------*/
/* Update manufacturing protection message register                         */
/*--------------------------------------------------------------------------*/
sc_err_t seco_update_mpmr(sc_rm_pt_t caller_pt, sc_faddr_t addr,
    uint8_t size, uint8_t lock)
{
    #ifdef HAS_SECO
        /* Return info */
        SECO_UpdateMPMR(addr, size, lock);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif   
}

/*--------------------------------------------------------------------------*/
/* Get manufacturing protection signature                                   */
/*--------------------------------------------------------------------------*/
sc_err_t seco_get_mp_sign(sc_rm_pt_t caller_pt, sc_faddr_t msg_addr,
    uint16_t msg_size, sc_faddr_t dst_addr, uint16_t dst_size)
{
    #ifdef HAS_SECO
        /* Return info */
        SECO_GetMPSign(msg_addr, msg_size, dst_addr, dst_size);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif   
}

/*--------------------------------------------------------------------------*/
/* Send a generic signed message to the SECO SHE/HSM components              */
/*--------------------------------------------------------------------------*/
sc_err_t seco_sab_msg(sc_rm_pt_t caller_pt, sc_faddr_t addr)
{
    #ifdef HAS_SECO
        SECO_SABSignedMesg(addr);

        return seco_err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Configure a CAAM job ring to allow it to make trusted descriptors        */
/*--------------------------------------------------------------------------*/
sc_err_t seco_caam_td_config(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_bool_t allow, sc_bool_t lock)
{
    #ifdef HAS_SECO
        sc_err_t err = SC_ERR_NONE;

        /* Bounds check */
        BOUND_PT(caller_pt);

        /* Check parameters */
        ASRT_ERR((resource >= SC_R_CAAM_JR1) 
            && (resource <= SC_R_CAAM_JR3), SC_ERR_PARM);

        /* Check access rights */
        OWNED(resource);

        /* Check for error? */
        if (err == SC_ERR_NONE)
        {
            SECO_CAAM_Config_TD(resource - SC_R_CAAM_JR1 + 1U,
                allow, lock);
            err = seco_err;
        }

        return err;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* Enable security violation and tamper interrupts                          */
/*--------------------------------------------------------------------------*/
sc_err_t seco_secvio_enable(sc_rm_pt_t caller_pt)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check permissions */
    OWNED(SC_R_SECVIO);

    /* Return info */
    if (err == SC_ERR_NONE)
    {
        #if defined(FSL_FEATURE_SOC_SNVS_COUNT) && FSL_FEATURE_SOC_SNVS_COUNT
            SNVS_SecurityViolation_Enable();
            err = snvs_err;
        #else
            err = SC_ERR_UNAVAILABLE;
        #endif
    }
    
    return err;
}

/*--------------------------------------------------------------------------*/
/* Send a message to SECO to read/write SNVS secvio and tamper registers    */
/*--------------------------------------------------------------------------*/
sc_err_t seco_secvio_config(sc_rm_pt_t caller_pt, uint8_t id, uint8_t access,
    uint32_t *data0, uint32_t *data1, uint32_t *data2, uint32_t *data3,
    uint32_t *data4, uint8_t size)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check parameters */
    ASRT_ERR(access <= SECO_SNVS_WRITE, SC_ERR_PARM);
    ASRT_ERR(size <= 5U, SC_ERR_PARM);
    
    /* Check permissions */
    OWNED(SC_R_SECVIO);

    /* Return info */
    if (err == SC_ERR_NONE)
    {
        #if defined(FSL_FEATURE_SOC_SNVS_COUNT) && FSL_FEATURE_SOC_SNVS_COUNT
            SNVS_SecVio(id, access, data0, data1, data2, data3, data4, size);
            err = snvs_err;
        #else
            err = SC_ERR_UNAVAILABLE;
        #endif
    }
    
    return err;
}

/*--------------------------------------------------------------------------*/
/* Send a message to SECO to read/write SNVS secvio and tamper DGO regs     */
/*--------------------------------------------------------------------------*/
sc_err_t seco_secvio_dgo_config(sc_rm_pt_t caller_pt, uint8_t id,
    uint8_t access, uint32_t *data)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check parameters */
    ASRT_ERR(access <= SECO_SNVS_WRITE, SC_ERR_PARM);

    /* Check permissions */
    OWNED(SC_R_SECVIO);

    /* Return info */
    if (err == SC_ERR_NONE)
    {
        #if defined(FSL_FEATURE_SOC_SNVS_COUNT) && FSL_FEATURE_SOC_SNVS_COUNT
            SNVS_SecVioDgo(id, access, data);
            err = seco_err;
        #else
            err = SC_ERR_UNAVAILABLE;
        #endif
    }

    return err;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Dump SECO state for debug                                                */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG) && defined(DEBUG_SECO)
     void seco_dump(sc_rm_pt_t pt)
    {
    }
#endif

/** @} */

