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
 * @file  svc/misc/svc.c
 *
 * File containing the implementation of the System Controller (SC)
 * Miscellaneous (MISC) function.
 *
 * @addtogroup MISC_SVC
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/scfw.h"
#include "main/main.h"
#include "main/board.h"
#include "main/boot.h"
#include "main/soc.h"
#include "main/build_info.h"
#include "svc/misc/svc.h"
#include "svc/rm/svc.h"
#include "ss/inf/inf.h"
#include "drivers/analog/fsl_analog.h"
#include "drivers/otp/fsl_otp.h"

/* Local Defines */

/*! Number of CPU waits */
#define NUM_WAIT_CPU            2

/* Local Types */

/*!
 * This type is used to store dynamic info needed to track partition
 * specific data for the watchdog service.
 */
typedef struct
{
    sc_misc_dma_group_t max_dma_group : SC_MISC_DMA_GRP_W;
} misc_part_data_t;

/* Local Functions */

/* Local Variables */

/*! State of CPU waits */
static volatile sc_bool_t cpu_wait[NUM_WAIT_CPU];

/*!
 * @name Local Variables (not initialized)
 *
 * @{
 */
static misc_part_data_t misc_part_data[SC_RM_NUM_PARTITION];
/** @} */

/*--------------------------------------------------------------------------*/
/* Init the power management service                                        */
/*--------------------------------------------------------------------------*/
void misc_init(sc_bool_t api_phase)
{
    if (api_phase != SC_FALSE)
    {
        sc_rm_pt_t pt;
  
        /* Init partition data */
        for (pt = 0; pt < SC_RM_NUM_PARTITION; pt++)
        {
            misc_part_data[pt].max_dma_group = SC_MISC_DMA_GRP_MAX;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Set a miscellaneous control value                                        */
/*--------------------------------------------------------------------------*/
sc_err_t misc_set_control(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_ctrl_t ctrl, uint32_t val)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_sub_t ss;
    ss_idx_t ss_idx;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Check parameters */
    ACCESS_ALLOWED(caller_pt, idx);

    if (err == SC_ERR_NONE)
    {
        /* Convert RM index to SS info */
        rm_get_ridx_ss_info(idx, &ss, &ss_idx);

        if (ss > SC_SUBSYS_LAST)
        {
            /* Handle board */
            err = board_set_control(resource, ss_idx, idx, ctrl, val);
        }
        else
        {
            /* Set control value */
            err = ss_set_control(idx, ctrl, val);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get a miscellaneous control value                                        */
/*--------------------------------------------------------------------------*/
sc_err_t misc_get_control(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_ctrl_t ctrl, uint32_t *val)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_sub_t ss;
    ss_idx_t ss_idx;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        /* Convert RM index to SS info */
        rm_get_ridx_ss_info(idx, &ss, &ss_idx);

        if (ss > SC_SUBSYS_LAST)
        {
            /* Handle board */
            err = board_get_control(resource, ss_idx, idx, ctrl, val);
        }
        else
        {
            /* Get control value */
            err = ss_get_control(idx, ctrl, val);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Configure the ARI translation for PCIe/SATA resources                    */
/*--------------------------------------------------------------------------*/
sc_err_t misc_set_ari(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_rsrc_t resource_mst, uint16_t ari, sc_bool_t enable)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    sc_rm_idx_t midx = 0;
    sc_sub_t ss;
    ss_idx_t ss_idx;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);
    BOUND_RSRC(resource_mst, midx);

    /* Check parameters */
    ACCESS_ALLOWED(caller_pt, idx);
    ACCESS_ALLOWED(caller_pt, midx);

    if (err == SC_ERR_NONE)
    {
        uint32_t val;

        /* Convert RM index to SS info */
        rm_get_ridx_ss_info(midx, &ss, &ss_idx);

        /* Set using the control interface */
        val = U32(ari);
        if (enable != SC_FALSE)
        {
            val |= BIT(31);
        }
        
        err = ss_set_control(idx, ss_idx, val);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Configure the max DMA channel priority group for a partition             */
/*--------------------------------------------------------------------------*/
sc_err_t misc_set_max_dma_group(sc_rm_pt_t caller_pt, sc_rm_pt_t pt, 
    sc_misc_dma_group_t max)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_PT(pt);

    /* Check parameters */
    ASRT_ERR(rm_is_partition_used(pt), SC_ERR_PARM);
    ASRT_ERR(max <= misc_part_data[caller_pt].max_dma_group, SC_ERR_PARM);
    ASRT_ERR(rm_is_parent(caller_pt, pt), SC_ERR_NOACCESS);

    if (err == SC_ERR_NONE)
    {
        /* Set max */
        misc_part_data[pt].max_dma_group = max;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Configure priority group for a DMA channel                               */
/*--------------------------------------------------------------------------*/
sc_err_t misc_set_dma_group(sc_rm_pt_t caller_pt, sc_rsrc_t resource, 
    sc_misc_dma_group_t group)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Check parameters */
    ACCESS_ALLOWED(caller_pt, idx);
    ASRT_ERR(group <= misc_part_data[caller_pt].max_dma_group, SC_ERR_PARM);

    if (err == SC_ERR_NONE)
    {
        /* Set using the control interface */
        err = ss_set_control(idx, SC_C_PRIORITY_GROUP, group);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Start/stop emulation waveform capture                                    */
/*--------------------------------------------------------------------------*/
sc_err_t misc_waveform_capture(sc_rm_pt_t caller_pt, sc_bool_t enable)
{
    #if defined(EMUL) && !defined(SIMU)
        if (enable != SC_FALSE)
        {
            SystemEventTrigger(SC_ENV_TRIG_DUMP);
        }
        else
        {
            SystemEventTrigger(SC_ENV_TRIG_KILL);
        }

        return SC_ERR_NONE;
    #else
        return SC_ERR_UNAVAILABLE;
    #endif    
}

/*--------------------------------------------------------------------------*/
/* Report boot status                                                       */
/*--------------------------------------------------------------------------*/
void misc_boot_status(sc_rm_pt_t caller_pt, sc_misc_boot_status_t status)
{
    sc_err_t err = SC_ERR_NONE;
    
    misc_print(3, "misc_boot_status(%d, %d)\n", caller_pt, status);

    /* Bounds check */
    BOUND_PT(caller_pt);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        switch (status)
        {
            /* Success */
            case SC_MISC_BOOT_STATUS_SUCCESS :
                {
                    misc_print(4, "    boot success from %d\n", caller_pt);
                    pm_set_booted(caller_pt, SC_TRUE);
                    break;
                }
            /* Security issue (bad authentication) */
            case SC_MISC_BOOT_STATUS_SECURITY:
                {
                    error_print("    boot security violation from %d\n", caller_pt);
                    pm_set_booted(caller_pt, SC_FALSE);
                    break;
                }
            /* Unknown */
            default :
                {
                    misc_print(4, "    unknown boot reason from %d\n", caller_pt);
                    pm_set_booted(caller_pt, SC_FALSE);
                    break;
                }
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Exit early boot                                                          */
/*--------------------------------------------------------------------------*/
sc_err_t misc_boot_done(sc_rm_pt_t caller_pt, sc_rsrc_t cpu)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx;

    misc_print(3, "misc_boot_done(%d, %d)\n", caller_pt, cpu);

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(cpu, idx);

    /* Check parameters */
    ASRT_ERR(rm_is_ridx_owned(caller_pt, idx), SC_ERR_NOACCESS);

    if (err == SC_ERR_NONE)
    {
        /* Calculate CPU index */
        if (cpu == SC_R_MCU_0_PID0)
        {
            cpu_wait[0U] = SC_TRUE;
        }
        else if (cpu == SC_R_MCU_1_PID0)
        {
            cpu_wait[1U] = SC_TRUE;
        }
        else
        {
            err = SC_ERR_PARM;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Wait for CPU boot to be done                                             */
/*--------------------------------------------------------------------------*/
sc_err_t misc_boot_done_wait(sc_rsrc_t cpu)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx;

    misc_print(3, "misc_boot_done_wait(%d)\n", cpu);

    /* Calculate CPU index */
    if (cpu == SC_R_MCU_0_PID0)
    {
        idx = 0U;
    }
    else if (cpu == SC_R_MCU_1_PID0)
    {
        idx = 1U;
    }
    else
    {
        err = SC_ERR_PARM;
    }

    if (err == SC_ERR_NONE)
    {
        /* Wait for CPU to finish */
        while (cpu_wait[idx] == SC_FALSE)
        {
            ; /* Intentional empty while */
        }

        /* Clear flag */
        cpu_wait[idx]= SC_FALSE;
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Output a debug character                                                 */
/*--------------------------------------------------------------------------*/
void misc_debug_out(sc_rm_pt_t caller_pt, uint8_t ch)
{
    always_print("%c", ch);
}

/*--------------------------------------------------------------------------*/
/* OTP MISC read fuse                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t misc_otp_fuse_read(sc_rm_pt_t caller_pt, uint32_t word,
    uint32_t *val)
{
    #ifndef NO_DEVICE_ACCESS
        return (OTP_Get_Fuse(word, val));
    #else
        return SC_ERR_NONE;
    #endif
}

/*--------------------------------------------------------------------------*/
/* OTP MISC write fuse                                                      */
/*--------------------------------------------------------------------------*/
sc_err_t misc_otp_fuse_write(sc_rm_pt_t caller_pt, uint32_t word,
    uint32_t val)
{
    sc_err_t err = SC_ERR_NONE;

    /* Check access permissions */
    SYSTEM(caller_pt);

    if (err == SC_ERR_NONE)
    {
        #ifndef NO_DEVICE_ACCESS
            err = OTP_Write(OTP, word, &val);
        #endif
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Return temp sensor availability                                           */
/*--------------------------------------------------------------------------*/
sc_bool_t misc_has_temp(sc_rsrc_t resource)
{
    sc_err_t err = SC_ERR_NONE;
    sc_bool_t rtn = SC_FALSE;
    sc_rm_idx_t idx = 0;
    sc_sub_t ss;
    ss_idx_t ss_idx;
    uint32_t val;

    /* Bounds check */
    BOUND_RSRC(resource, idx);

    if (err == SC_ERR_NONE)
    {
        /* Convert RM index to SS info */
        rm_get_ridx_ss_info(idx, &ss, &ss_idx);

        if (ss > SC_SUBSYS_LAST)
        {
            /* Handle board */
            rtn = (board_get_control(resource, ss_idx, idx, SC_C_TEMP, &val)
                == SC_ERR_NONE);
        }
        else
        {
            /* Call subsystem interface */
            rtn = ss_temp_sensor(idx);
        }
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Set a temp sensor alarm                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t misc_set_temp(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_misc_temp_t temp, int16_t celsius, int8_t tenths)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    uint32_t val = 0;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Check parameters */
    ACCESS_ALLOWED(caller_pt, idx);

    if (err == SC_ERR_NONE)
    {
        /* Convert temp */
        if ((resource == SC_R_PMIC_0) || (resource == SC_R_PMIC_1)
             || (resource == SC_R_PMIC_2))
        {
            val = U32(celsius);
        }
        else
        {
            sc_sub_t ss = 0;
            ss_idx_t ss_idx = 0;

            /* Convert RM index to SS info */
            rm_get_ridx_ss_info(idx, &ss, &ss_idx);
            ANA_Temp2Val(sc_ss_info[ss].dsc, celsius, tenths, &val);
        }

        /* Set temp */
        switch (temp)
        {
            case SC_MISC_TEMP :
                err = misc_set_control(caller_pt, resource, SC_C_TEMP,
                    val);
                break;
            case SC_MISC_TEMP_HIGH :
                err = misc_set_control(caller_pt, resource, SC_C_TEMP_HI,
                    val);
                break;
            case SC_MISC_TEMP_LOW :
                err = misc_set_control(caller_pt, resource, SC_C_TEMP_LOW,
                    val);
                break;
            default :
                err = SC_ERR_PARM;
                break;
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Get a temp sensor value                                                  */
/*--------------------------------------------------------------------------*/
sc_err_t misc_get_temp(sc_rm_pt_t caller_pt, sc_rsrc_t resource,
    sc_misc_temp_t temp, int16_t *celsius, int8_t *tenths)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_idx_t idx = 0;
    uint32_t val;

    /* Bounds check */
    BOUND_PT(caller_pt);
    BOUND_RSRC(resource, idx);

    /* Get temp */
    if (err == SC_ERR_NONE)
    {
        switch (temp)
        {
            /* Sensor temp */
            case SC_MISC_TEMP : 
                err = misc_get_control(caller_pt, resource, SC_C_TEMP,
                    &val);
                break;
            /* High temp alarm */
            case SC_MISC_TEMP_HIGH : 
                err = misc_get_control(caller_pt, resource, SC_C_TEMP_HI,
                    &val);
                break;
            /* Low temp alarm */
            case SC_MISC_TEMP_LOW : 
                err = misc_get_control(caller_pt, resource, SC_C_TEMP_LOW,
                    &val);
                break;
            /* Bad control */
            default :
                err = SC_ERR_PARM;
                break;
        }
    }

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Convert temp */
        if ((resource == SC_R_PMIC_0) || (resource == SC_R_PMIC_1)
             || (resource == SC_R_PMIC_2))
        {
            *celsius = I16(val);
            *tenths = 0;
        }
        else
        {
            sc_sub_t ss = 0;
            ss_idx_t ss_idx = 0;

            /* Convert RM index to SS info */
            rm_get_ridx_ss_info(idx, &ss, &ss_idx);
            ANA_Val2Temp(sc_ss_info[ss].dsc, val, celsius, tenths);
        }
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Return SCFW build info                                                   */
/*--------------------------------------------------------------------------*/
void misc_build_info(sc_rm_pt_t caller_pt, uint32_t *build,
    uint32_t *commit)
{
    /* Return info */
    *build = SCFW_BUILD;
    *commit = SCFW_COMMIT;    
}

/*--------------------------------------------------------------------------*/
/* Return unique ID                                                         */
/*--------------------------------------------------------------------------*/
void misc_unique_id(sc_rm_pt_t caller_pt, uint32_t *id_l,
    uint32_t *id_h)
{
    *id_l = OTP_UNIQUE_ID_L;    
    *id_h = OTP_UNIQUE_ID_H;    
}

/*--------------------------------------------------------------------------*/
/* Return boot device                                                       */
/*--------------------------------------------------------------------------*/
void misc_get_boot_dev(sc_rm_pt_t caller_pt, sc_rsrc_t *dev)
{
    sc_err_t err = SC_ERR_NONE;
    
    /* Bounds check */
    BOUND_PT(caller_pt);

    if (err == SC_ERR_NONE)
    {
        *dev = boot_get_dev(caller_pt, SC_FALSE);
    }
}

/*--------------------------------------------------------------------------*/
/* Return boot type                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t misc_get_boot_type(sc_rm_pt_t caller_pt, sc_misc_bt_t *type)
{
    sc_err_t err;
    sc_bt_dev_type_t dev_type;
    uint8_t inst;
    sc_bt_type_t bt_type;

    /* Get boot device */
    err = boot_get_boot_dev(&dev_type, &inst, &bt_type);

    /* Check for error */
    if (err == SC_ERR_NONE)
    {
        /* Translate ROM type */
        switch (bt_type)
        {
            case SC_BT_TYPE_PRIMARY :
                *type = SC_MISC_BT_PRIMARY;
                break;
            case SC_BT_TYPE_RECOVERY:
                *type = SC_MISC_BT_RECOVERY;
                break;
            case SC_BT_TYPE_SECONDARY:
                *type = SC_MISC_BT_SECONDARY;
                break;
            case SC_BT_TYPE_SERIAL:
                *type = SC_MISC_BT_SERIAL;
                break;
            /* Not found */
            default :
                err = SC_ERR_UNAVAILABLE;
                break;
        }
    }

    return err;   
}

/*--------------------------------------------------------------------------*/
/* Return the boot container index                                          */
/*--------------------------------------------------------------------------*/
sc_err_t misc_get_boot_container(sc_rm_pt_t caller_pt, uint8_t *idx)
{
    return boot_get_container_idx(idx);
}

/*--------------------------------------------------------------------------*/
/* Return the current status of the ON/OFF button                           */
/*--------------------------------------------------------------------------*/
void misc_get_button_status(sc_rm_pt_t caller_pt, sc_bool_t *status)
{
    *status = board_get_button_status();
}

/*--------------------------------------------------------------------------*/
/* Return the ROM patch checksum                                            */
/*--------------------------------------------------------------------------*/
sc_err_t misc_rompatch_checksum(sc_rm_pt_t caller_pt, uint32_t *checksum)
{
    soc_rompatch_checksum(checksum, OTP_ROM_PATCH_SIZE
        + OTP_V2X_PATCH_SIZE);

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Call board IOCTL                                                         */
/*--------------------------------------------------------------------------*/
sc_err_t misc_board_ioctl(sc_rsrc_t mu, uint32_t *parm1,
    uint32_t *parm2, uint32_t *parm3)
{
    sc_err_t err = SC_ERR_NONE;
    sc_rm_pt_t caller_pt;

    err = rm_get_resource_owner(SC_PT, mu, &caller_pt);

    if (err == SC_ERR_NONE)
    {
        err = board_ioctl(caller_pt, mu, parm1, parm2, parm3);
    }

    return err;
}

/*--------------------------------------------------------------------------*/
/* Return API version info                                                  */
/*--------------------------------------------------------------------------*/
void misc_api_ver(sc_rm_pt_t caller_pt, uint16_t *cl_maj,
    uint16_t *cl_min, uint16_t *sv_maj, uint16_t *sv_min)
{
    *cl_maj = 0U;
    *cl_min = 0U;
    *sv_maj = SCFW_API_VERSION_MAJOR;
    *sv_min = SCFW_API_VERSION_MINOR;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Dump MISC state for debug                                                */
/*--------------------------------------------------------------------------*/
#if defined(DEBUG) && defined(DEBUG_MISC)
     void misc_dump(sc_rm_pt_t pt)
    {
        sc_err_t err = SC_ERR_NONE;
        
        USED_PT(pt);

        if ((debug != SC_FALSE) && (err == SC_ERR_NONE))
        {
            /* Dump data */
            misc_print(2, "    Partition: %u\n", pt);
            misc_print(2, "        Max DMA priority group: %u\n",
                misc_part_data[pt].max_dma_group);
        }
    }
#endif

/** @} */

