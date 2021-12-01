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
 * @file
 *
 * Header file containing the base subsystem API.
 *
 * @addtogroup BASE_SS BASE: Base Subsystem
 *
 * Module for Base subsystem access.
 *
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_BASE_H
#define SC_SS_BASE_H

/* Includes */

#include "main/types.h"
#include "ss/inf/inf.h"
#include "svc/pm/svc.h"
#include "drivers/xrdc2/fsl_xrdc2.h"
#include "main/sched.h"

/* Defines */

#define PD_DSC      0U
#define PD_SS       1U

#define CLKOFFTRANS()   ((from_mode <= SC_PM_PW_MODE_STBY) && (to_mode <= SC_PM_PW_MODE_STBY))
#define CLK2OFF()       ((from_mode > SC_PM_PW_MODE_STBY) && (to_mode <= SC_PM_PW_MODE_STBY))
#define CLK2ON()        ((from_mode <= SC_PM_PW_MODE_STBY) && (to_mode > SC_PM_PW_MODE_STBY))
#define PWR2OFF()       (to_mode == SC_PM_PW_MODE_OFF)
#define HSCLK()         ((from_mode <= SC_PM_PW_MODE_LP) && (to_mode > SC_PM_PW_MODE_LP))
#define LSCLK()         ((from_mode > SC_PM_PW_MODE_LP) && (to_mode == SC_PM_PW_MODE_LP))
#define PWR2ON()        (from_mode == SC_PM_PW_MODE_OFF)
#define RUN2CLKOFF()    ((from_mode > SC_PM_PW_MODE_STBY) && (to_mode == SC_PM_PW_MODE_STBY))

#define SS_RESET_NONE 0x7FFFU
#define SS_RESET_LINK 0x8000U

/* Types */

/*!
 * This type is used store static constant info on the signals for
 * a P-channel interface.
 */
typedef struct
{
    uint8_t pstate;
    uint8_t pstate_width;
    uint8_t preq;
    uint8_t paccept;
    uint8_t pdeny;
    uint8_t pactive;
    uint8_t pactive_width;
} ss_pchannel_t;

/*!
 * This type is used store static constant info on the signals for
 * a Q-channel interface.
 */
typedef struct
{
    uint8_t qreqn;
    uint8_t qacceptn;
    uint8_t qdeny;
    uint8_t qactive;
} ss_qchannel_t;

typedef uint16_t ss_reset_list_t;

/* Functions */

SS_FUNC_PROTO_BASE

#if (defined(FSL_FEATURE_DSC_HAS_PER_RESET) && FSL_FEATURE_DSC_HAS_PER_RESET)
void ss_reset_resource(ECSR_Reset_Type *csr_base, sc_sub_t ss, ss_idx_t ss_idx,
    const ss_reset_list_t *reset_list, sc_bool_t old_sequence);
void ss_setup_reset_clk(sc_sub_t ss, ss_idx_t ss_idx, sc_pm_clk_t clk,
    sc_bool_t enable);
void ss_setup_reset_plls(sc_sub_t ss, sc_bool_t enable);
#endif
void ss_init_boot_base(sc_sub_t ss, ss_idx_t ss_idx, sc_pm_power_mode_t to_mode);
sc_bool_t ss_is_powered(sc_sub_t ss);
void ss_set_rsrc_clks(sc_sub_t ss, ss_idx_t ss_idx,
        sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);
void ss_trans_pd(sc_sub_t ss, dsc_pdom_t pd,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);
uint8_t ss_pchannel_get_activity(sc_dsc_t dsc, const ss_pchannel_t channel);
uint8_t ss_pchannel_set_state(sc_dsc_t dsc, const ss_pchannel_t channel,
    uint8_t new_state);
sc_bool_t ss_qchannel_set_state(sc_dsc_t dsc, const ss_qchannel_t channel,
    sc_bool_t new_state);
void ss_ssi_link(sc_sub_t local, sc_sub_t remote, uint8_t local_port,
    uint8_t remote_port, sc_bool_t enable);
void ss_ssi_po_link(sc_sub_t local, sc_sub_t remote, uint8_t port,
    sc_bool_t enable);
void ss_adb_link(sc_sub_t local, sc_sub_t remote, sc_bool_t enable);
void ss_adb_enb(sc_sub_t ss, uint32_t adb, sc_bool_t enable);
void ss_adb_x2_enb(sc_sub_t ss, uint32_t adb1, uint32_t adb2, sc_bool_t enable);
void ss_adb_wt(sc_sub_t ss, uint32_t adb, sc_bool_t enable);
void ss_adb_x2_wt(sc_sub_t ss, uint32_t adb1, uint32_t adb2, sc_bool_t enable);
sc_err_t ss_check_pll_rate(sc_sub_t ss, ss_clock_t clk_index,
    const sc_pm_clock_rate_t *rate, sc_bool_t rom_boot);
void ss_config_pll_rate(sc_sub_t ss, ss_clock_t clk_index,
    sc_pm_clock_rate_t *rate, sc_bool_t rom_boot);
sc_err_t ss_config_clk_rate(sc_sub_t ss, ss_clock_t clk_index, 
    sc_pm_clock_rate_t *rate, sc_bool_t rom_boot);
void ss_config_pll_mode(sc_sub_t ss, ss_clock_t clk_index,
    sc_pm_clk_mode_t mode, sc_bool_t rom_boot);
sc_err_t ss_config_clk_mode(sc_sub_t ss, ss_clock_t clk_index,
    sc_pm_clk_mode_t mode, sc_bool_t rom_boot);
sc_err_t ss_ap_reset_vector(sc_faddr_t addr, uint32_t cpu, sc_bool_t *vector);
void ss_populate_boot_dev_info(ss_idx_t ss_idx, sc_sub_t ss, 
    sc_bool_t fix_pll_rate);
sc_err_t ss_get_clk_rate_by_index(sc_sub_t ss, ss_clock_t clk_index,
    sc_pm_clock_rate_t *rate);
sc_pm_clk_parent_t ss_get_parent_index(sc_sub_t ss, ss_clock_t clk_index);
void ss_set_parent_by_index(sc_sub_t ss, ss_clock_t clk_index,
    sc_pm_clk_parent_t new_parent_index);
sc_err_t ss_refactor_clks(sc_sub_t ss, ss_idx_t ss_idx, sc_pm_clk_t clk,
    const sc_pm_clock_rate_t *cur_rate, sc_pm_clock_rate_t *rate);
void ss_active_bias_domains(sc_sub_t ss, uint8_t *active_mask, uint8_t *idle_mask);
void ss_config_max_core_freq(sc_sub_t ss, ss_clock_t pll_index, ss_clock_t cpu_clk_index,
    dsc_clk_type_t pll_type, sc_pm_clock_rate_t max_rate);
void ss_trans_power_mode_noxrdc(sc_sub_t ss, ss_idx_t ss_idx, ss_ridx_t
    rsrc_idx, sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);
sc_err_t ss_setup_bypass_parent(sc_sub_t ss, ss_clock_t clk_index,
    ss_clock_t clk_index1, sc_pm_clk_parent_t parent_index1, sc_pm_clk_parent_t parent_index2);

#ifdef XRDC_SUPPORT
    void ss_rdc_enable_check(void);
    void ss_rdc_power_down(sc_sub_t ss, dsc_pdom_t pd);
    void ss_rdc_set_custom_master(sc_sub_t ss, ss_idx_t ss_idx, ss_ridx_t
        rsrc_idx, sc_bool_t valid, sc_bool_t lock, sc_rm_spa_t sa, sc_rm_spa_t pa,
        sc_rm_did_t did, sc_rm_sid_t sid, xrdc_match_t match,
        xrdc_match_t mask, uint8_t cid);
    void ss_rdc_set_custom_mda(sc_sub_t ss, sc_rm_idx_t xrdc_master_idx,
        sc_bool_t valid, sc_bool_t lock, sc_rm_spa_t sa, sc_rm_spa_t pa, sc_rm_did_t did,
        sc_rm_sid_t sid, xrdc_match_t match, xrdc_match_t mask, uint8_t cid);
#endif /* XRDC_SUPPORT */
void ss_dsc_irq_handler_base(sc_dsc_t dsc, 
    const ss_dsc_l2irq_handler *ss_dsc_l2irq_handlers,
    const ss_dsc_l2irq_handler *ss_l2irq_handlers);
sc_bool_t ss_dsc_handler_default(sc_dsc_t dsc, uint32_t irqIndex);

/* Debug Functions */

#if defined(DEBUG) || defined(GCOV)
    void ss_dump_header_base(sc_sub_t ss);
    void ss_dump_master_counts_base(sc_sub_t ss);
    void ss_dump_xrdc_base(sc_sub_t ss, sc_dsc_t dsc,
        const ss_base_info_t *base);
    void ss_dump_clocks(sc_sub_t ss);
#endif

/* External variables */

extern const ss_dsc_l2irq_handler ss_dsc_l2irq_handlers_base[];
extern const ss_dsc_l2irq_handler ss_l2irq_handlers_base[];
extern sc_bool_t xrdc_enable;
extern sc_bool_t base_noflushl2;
extern sc_bool_t base_nopoweroff;
extern sc_bool_t base_gic_noblock;

#endif /* SC_SS_BASE_H */

/** @} */

