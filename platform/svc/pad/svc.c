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
 * @file  svc/pad/svc.c
 *
 * File containing the implementation of the System Controller (SC) Pad
 * Control (PAD) function.
 *
 * @addtogroup PAD_SVC
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "main/soc.h"
#include "main/boot.h"
#include "svc/pad/svc.h"
#include "svc/rm/svc.h"
#include "ss/inf/inf.h"
#include "drivers/pad/fsl_pad.h"
#include "pad_priority.h"

/* Local Defines */

/*! Define to fill in a pad_priority_info_t variable */
#define PNFO(PAD, PAD_MUX, PAD_RSRC)    \
{                                       \
    .pad = SC_P_##PAD,                  \
    .mux = (PAD_MUX),                   \
    .resource = SC_R_##PAD_RSRC         \
}

/*!
 * @name Parameter checking macros
 */
/** @{ */
#define PAD_OWNED(X)        ASRT_ERR(rm_is_pad_owned(caller_pt, (X)) != SC_FALSE, SC_ERR_NOACCESS)
#define PAD_OWNED_C(X)      ASRT_C(rm_is_pad_owned(caller_pt, (X)) != SC_FALSE)
#define MUX_OKAY(X,Y)       ASRT_ERR(pad_mux_okay(caller_pt, (X), (Y)) != SC_FALSE, SC_ERR_NOACCESS)
#define MUX_OKAY_C(X,Y)     ASRT_C(pad_mux_okay(caller_pt, (X), (Y)) != SC_FALSE)
/** @} */

/* Local Types */

/*!
 * This type is used store static constant info about resources in a
 * subsystem. A pointer to this structure can be found in the
 * ss_base_info_t type.
 */
typedef struct
{
    sc_pad_t pad                        : SC_PAD_W;     //!< Pad
    uint8_t mux                         : SC_PAD_MUX_W; //!< Mux
    sc_rsrc_t resource                  : SC_RSRC_W;    //!< Resource
} pad_priority_info_t;

/* Local Functions */

static sc_bool_t pad_mux_okay(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t mux);

/* Local Variables */

/*!
 * Constant array to hold pad mapping info.
 */
static const uint16_t pad_map[SC_NUM_PAD] =
{
    SC_SVC_PAD_INIT
};

/*--------------------------------------------------------------------------*/
/* Init the pad service                                                     */
/*--------------------------------------------------------------------------*/
void pad_init(sc_bool_t api_phase)
{
    static const pad_priority_info_t pad_init_info[] =
    {
        SC_PAD_INIT_INIT
    };
    
    if (api_phase == SC_FALSE)
    {
        sc_rsrc_t boot_dev;
        const pad_priority_info_t *p = pad_init_info;
        
        /* Get boot device */
        boot_dev = boot_get_dev(SC_PT, SC_FALSE);

        /* Loop through pad priority */
        while ((p->pad != 0U) || (p->mux != 0U) || (p->resource != 0U))
        {
            /* Unused for boot? */
            if (p->resource != boot_dev)
            {
                uint8_t mux = 0U;
                sc_pad_config_t config = SC_PAD_CONFIG_NORMAL;
                sc_pad_iso_t iso = SC_PAD_ISO_OFF;

                /* Get current state */
                if (pad_get_mux(SC_PT, p->pad, &mux, &config, &iso) == SC_ERR_NONE)
                {
                    /* Check if not already configured by ROM */
                    if (mux == 0U)
                    {
                        pad_force_mux(p->pad, p->mux,
                            SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF);
                    }
                }
            }

            p++;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Set the pad                                                              */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t val)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;
    uint8_t mux;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Extract the mux setting */
    mux = PAD_ExtractMux(val);

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

        /* Check ownership */
        PAD_OWNED(pad);
        MUX_OKAY(pad, mux);

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
                PAD_OWNED_C(p);
                MUX_OKAY_C(p, mux);
            }

            /* Configure */
            PAD_Set(U32(pad_map[p]) << 4U, val);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the pad mux                                                          */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set_mux(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t mux,
    sc_pad_config_t config, sc_pad_iso_t iso)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(config <= SC_PAD_CONFIG_OUT_IN, SC_ERR_PARM);
    ASRT_ERR(iso <= SC_PAD_ISO_ON, SC_ERR_PARM);

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

        /* Check ownership */
        PAD_OWNED(pad);
        MUX_OKAY(pad, mux);

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
                PAD_OWNED_C(p);
                MUX_OKAY_C(p, mux);
            }

            /* Configure mux */
            PAD_SetMux(U32(pad_map[p]) << 4U, mux, config, iso);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Force the pad mux                                                        */
/*--------------------------------------------------------------------------*/
void pad_force_mux(sc_pad_t pad, uint8_t mux, sc_pad_config_t config,
    sc_pad_iso_t iso)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check parameters */
    BOUND_PAD(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure mux */
        PAD_SetMux(U32(pad_map[pad]) << 4U, mux, config, iso);
    }
}

/*--------------------------------------------------------------------------*/
/* Set the pad control                                                      */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set_gp(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t ctrl)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;

    /* Bounds check */
    BOUND_PT(caller_pt);

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
        PAD_OWNED(pad);

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
                PAD_OWNED_C(p);
            }

            /* Configure GP */
            PAD_SetGP(U32(pad_map[p]) << 4U, ctrl);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the pad wakeup control                                               */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set_wakeup(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_wakeup_t wakeup)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(wakeup <= SC_PAD_WAKEUP_HIGH_LVL, SC_ERR_PARM);

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

        /* Check ownership */
        PAD_OWNED(pad);

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
                PAD_OWNED_C(p);
            }

            /* Configure wakeup */
            PAD_SetWakeup(U32(pad_map[p]) << 4U, wakeup);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the pad config                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set_all(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t mux,
    sc_pad_config_t config, sc_pad_iso_t iso, uint32_t ctrl,
    sc_pad_wakeup_t wakeup)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(config <= SC_PAD_CONFIG_OUT_IN, SC_ERR_PARM);
    ASRT_ERR(iso <= SC_PAD_ISO_ON, SC_ERR_PARM);
    ASRT_ERR(wakeup <= SC_PAD_WAKEUP_HIGH_LVL, SC_ERR_PARM);

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

        /* Check ownership */
        PAD_OWNED(pad);
        MUX_OKAY(pad, mux);

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
                PAD_OWNED_C(p);
                MUX_OKAY_C(p, mux);
            }

            /* Configure all */
            PAD_SetAll(U32(pad_map[p]) << 4U, mux, config, iso, ctrl,
                wakeup);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad                                                              */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t *val)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure mux */
        PAD_Get(U32(pad_map[pad]) << 4U, val);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad mux                                                          */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get_mux(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t *mux,
    sc_pad_config_t *config, sc_pad_iso_t *iso)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);
 
    if (err == SC_ERR_NONE)
    {
        /* Get mux */
        PAD_GetMux(U32(pad_map[pad]) << 4U, mux, config, iso);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad control                                                      */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get_gp(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t *ctrl)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Get GP */
        PAD_GetGP(U32(pad_map[pad]) << 4U, ctrl);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad wakeup control                                               */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get_wakeup(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_wakeup_t *wakeup)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Get mux */
        PAD_GetWakeup(U32(pad_map[pad]) << 4U, wakeup);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad config                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get_all(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t *mux,
    sc_pad_config_t *config, sc_pad_iso_t *iso, uint32_t *ctrl,
    sc_pad_wakeup_t *wakeup)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure all */
        PAD_GetAll(U32(pad_map[pad]) << 4U, mux, config, iso, ctrl,
            wakeup);
    }

    return err;
}

#ifdef API_HAS_28FDSOI
/*--------------------------------------------------------------------------*/
/* Set the pad control specific to 28FDSOI                                  */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set_gp_28fdsoi(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t dse, sc_pad_28fdsoi_ps_t ps)
{
    sc_err_t err = SC_ERR_NONE;
    sc_pad_t p0, pN;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(dse <= SC_PAD_28FDSOI_DSE_18V_HS, SC_ERR_PARM);
    ASRT_ERR(ps <= SC_PAD_28FDSOI_PS_NONE, SC_ERR_PARM);

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

        /* Check ownership */
        PAD_OWNED(pad);

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
                PAD_OWNED_C(p);
            }

            /* Configure GP */
            PAD_SetGP28Fdsoi(U32(pad_map[p]) << 4U, dse, ps);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad control specific to 28FDSOI                                  */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get_gp_28fdsoi(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t *dse, sc_pad_28fdsoi_ps_t *ps)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    /* Configure GP */
    if (err == SC_ERR_NONE)
    {
        PAD_GetGP28Fdsoi(U32(pad_map[pad]) << 4U, dse, ps);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the pad control specific to 28FDSOI HSIC                             */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set_gp_28fdsoi_hsic(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t dse, sc_bool_t hyp, sc_pad_28fdsoi_pus_t pus,
    sc_bool_t pke, sc_bool_t pue)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    ASRT_ERR(dse <= SC_PAD_28FDSOI_DSE_18V_HS, SC_ERR_PARM);
    ASRT_ERR(pus <= SC_PAD_28FDSOI_PUS_30K_PU, SC_ERR_PARM);

    /* Check parameters */
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure GP */
        PAD_SetGP28FdsoiHsic(U32(pad_map[pad]) << 4U, dse, hyp,
            pus, pke, pue);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad control specific to 28FDSOI HSIC                             */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get_gp_28fdsoi_hsic(sc_rm_pt_t caller_pt, sc_pad_t pad,
    sc_pad_28fdsoi_dse_t *dse, sc_bool_t *hyp, sc_pad_28fdsoi_pus_t *pus,
    sc_bool_t *pke, sc_bool_t *pue)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure GP */
        PAD_GetGP28FdsoiHsic(U32(pad_map[pad]) << 4U, dse, hyp, pus, pke,
            pue);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Set the compensation control specific to 28FDSOI                         */
/*--------------------------------------------------------------------------*/
sc_err_t pad_set_gp_28fdsoi_comp(sc_rm_pt_t caller_pt, sc_pad_t pad,
    uint8_t compen, sc_bool_t fastfrz, uint8_t rasrcp, uint8_t rasrcn,
    sc_bool_t nasrc_sel, sc_bool_t psw_ovr)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure GP */
        PAD_SetGP28FdsoiComp(U32(pad_map[pad]) << 4U, compen, fastfrz,
            rasrcp, rasrcn, nasrc_sel, psw_ovr);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get the pad compensation specific to 28FDSOI                             */
/*--------------------------------------------------------------------------*/
sc_err_t pad_get_gp_28fdsoi_comp(sc_rm_pt_t caller_pt, sc_pad_t pad,
    uint8_t *compen, sc_bool_t *fastfrz, uint8_t *rasrcp, uint8_t *rasrcn,
    sc_bool_t *nasrc_sel, sc_bool_t *compok, uint8_t *nasrc,
    sc_bool_t *psw_ovr)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure GP */
        PAD_GetGP28FdsoiComp(U32(pad_map[pad]) << 4U, compen, fastfrz,
            rasrcp, rasrcn, nasrc_sel, compok, nasrc, psw_ovr);
    }

    return err;
}
#endif

/*--------------------------------------------------------------------------*/
/* Set a config value                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t pad_config(sc_rm_pt_t caller_pt, sc_pad_t pad, uint32_t val)
{
    sc_err_t err = SC_ERR_NONE;

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check parameters */
    BOUND_PAD(pad);

    /* Check ownership */
    PAD_OWNED(pad);

    if (err == SC_ERR_NONE)
    {
        /* Configure */
        PAD_Set(U32(pad_map[pad]) << 4U, val);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Map pad irq and index to pad resource                                    */
/*--------------------------------------------------------------------------*/
sc_pad_t pad_map_irq(uint8_t irq, uint8_t idx)
{
    /*!
     * Constant array to hold pad grouping info.
     */
    static const sc_pad_t pad_irq[SC_NUM_PAD_IRQS] =
    {
        SC_SVC_PAD_IRQ_INIT
    };

    /* Init pad */
    sc_pad_t pad = SC_NUM_PAD;

    /* Calculate pad from pending IRQ */
    if (irq < SC_NUM_PAD_IRQS)
    {
        pad = pad_irq[irq] + idx;
    }
    
    return pad;
}

/*--------------------------------------------------------------------------*/
/* Dump PAD state for debug                                                 */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG) && defined(DEBUG_PAD)
    void pad_dump(sc_rm_pt_t pt)
    {
    }
#endif

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Get priority conflict info                                               */
/*--------------------------------------------------------------------------*/
static sc_bool_t pad_mux_okay(sc_rm_pt_t caller_pt, sc_pad_t pad, uint8_t mux)
{
    static const pad_priority_info_t pad_priority[SC_NUM_PAD_PRIORITY + 1] =
    {
        SC_PAD_PRIORITY_INIT
    };
    static const pad_priority_info_t * const p = pad_priority;
    int16_t top = SC_NUM_PAD_PRIORITY - 1;
    uint32_t search = (U32(pad) << 16U) | U32(mux);
    sc_bool_t rtn = SC_TRUE;

    /* Skip check for SCFW */
    if (caller_pt != SC_PT)
    {
        int16_t bottom = 0;

        /* Perform binary search */
        while (bottom <= top)
        {
            int16_t mid;
            uint32_t item;

            /* Next middle to check */
            mid = bottom + ((top - bottom) / 2);

            /* Generate item */
            item = (U32(p[mid].pad) << 16U) | U32(p[mid].mux);

            if (item < search)
            {
                /* Next search section */
                bottom = mid + 1;
            }
            else if (item > search)
            {
                /* Next search section */
                top = mid - 1;
            }
            else
            {
                /* Found so return it */
                rtn = rm_is_resource_access_allowed(caller_pt, p[mid].resource);

                break;
            }
        }
    }

    return rtn; 
}

/** @} */

