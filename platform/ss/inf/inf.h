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
 * Common functions for interfacing with the subsystems.
 *
 * @addtogroup INF_SS INF: Subsystem Interface
 *
 * @brief Module for common subsystem access.
 *
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_INF_H
#define SC_SS_INF_H

/* Includes */

#include "main/types.h"
#include "svc/rm/svc.h"
#include "svc/pm/svc.h"
#include "svc/irq/svc.h"
#include "drivers/dsc/fsl_dsc.h"
#include "drivers/xrdc2/fsl_xrdc2.h"

/* Defines */

#define SS_CLK_W        6U  //!< Width of ss_clock_t
#define SS_PLL_W        2U  //!< Width of ss_pll_t
#define SS_IO_W         4U  //!< Width of ss_io_type_t
#define SS_XEXP_W       8U  //!< Width of ss_xexp_idx_t
#define SS_FIELD_POS_W  16U //!< Width of I/O field position
#define SS_FIELD_WID_W  6U  //!< Width of I/O field width
#define SS_CID_W        4U  //!< Width of CPU ID
#define SS_IDX_W        8U  //!< Width of SS index
#define SS_NUM_SSI_W    2U  //!< Width of num SSIs

#define SS_MAX_CLK      35U //!< Max number of clocks per subsystem
#define SS_MAX_PLL      3U  //!< Max number of PLLs per subsystem

#define SS_MAX_PM_CLKS  5U

/*! Define to indicate invalid power domains and clocks */
#define NV              ((uint8_t) UINT8_MAX)

/*! Define to fill in a sc_rsrc_map_t variable */
#define RSRC(R, I, X)            \
{                                \
    .resource = U16(SC_R_##R),   \
    .inst = U8(I),               \
    .ss_idx = U8(X)              \
}

#define SS_I1           0x8001U

#define XNFO_DL         {0U, 0U}

#ifdef DISABLE_LPCG_AT_PD_PUP
#define LPCG_INFO                       \
    .num_lpcg = SS_NUM_LPCG,            \
    .lpcg_info = SS_LPCG_ADDR_INFO
#else
#define LPCG_INFO
#endif

#ifdef XRDC_SUPPORT
    /*! Define to fill in a ss_base_info_t variable (with XRDC) */
    #define BASE_INFO(XEXP_INFO, MDAC_INFO, PAC_INFO, MSC_INFO, MRC_INFO, CTRL_INFO)  \
        .num_rsrc = SS_NUM_RSRC,            \
        .num_srsrc = SS_NUM_SRSRC,          \
        .num_prsrc = SS_NUM_PRSRC,          \
        .num_prsrc2 = SS_NUM_PRSRC2,        \
        .rsrc = ss_rsrc_info,               \
        .rsrc_map = rsrc_map,               \
        .num_pd = SS_NUM_PD,                \
        .pd_info = ss_pd_info,              \
        .pd_reboot_info = SS_PD_REBOOT_INFO,\
        .num_ctrl = SS_NUM_CTRL,            \
        .ctrl_info = (CTRL_INFO),           \
        .dsc_aon_reset_mask = SS_AON_RESET, \
        .irq_enb = SS_IRQ_ENB,              \
        .pd_dsc = SS_PD_DSC,                \
        .pd_ssi = SS_PD_SSI,                \
        .num_clks = SS_NUM_CLK,             \
        .clk_info = ss_clk_info,            \
        .ss_iso_info = ss_iso_info,         \
        .num_pll = SS_NUM_PLL,              \
        .mu_irq = SS_MU_IRQ,                \
        .dscmix = SS_DSCMIX,                \
        .ai_type = SS_AI_TYPE,              \
        .ss_phy_iso = SS_PHY_ISO,           \
        .ss_num_ssi = SS_NUM_SSI,           \
        .mtr_clk_idx = MTR_CLK_IDX,         \
        .pd_mgr = SS_PD_MGR,                \
        .xexp_info = (XEXP_INFO),           \
        .num_mdac = SS_NUM_MDAC,            \
        .mdac_info = (MDAC_INFO),           \
        .mdac_match = SS_MDAC_MATCH,        \
        .mdac_cache = SS_MDAC_CACHE,        \
        .num_pac = SS_NUM_PAC,              \
        .pac_info = (PAC_INFO),             \
        .num_msc = SS_NUM_MSC,              \
        .msc_info = (MSC_INFO),             \
        .num_mrc = SS_NUM_MRC,              \
        .mrc_info = (MRC_INFO),             \
        .mrc_mask = SS_MRC_MASK,            \
        .mrc_cache = SS_MRC_CACHE,          \
         LPCG_INFO
#else
    /*! Define to fill in a ss_base_info_t variable (without XRDC) */
    #define BASE_INFO(XEXP_INFO, MDAC_INFO, PAC_INFO, MSC_INFO, MRC_INFO, CTRL_INFO)  \
        .num_rsrc = SS_NUM_RSRC,            \
        .num_srsrc = SS_NUM_SRSRC,          \
        .num_prsrc = SS_NUM_PRSRC,          \
        .num_prsrc2 = SS_NUM_PRSRC2,        \
        .rsrc = ss_rsrc_info,               \
        .rsrc_map = rsrc_map,               \
        .num_pd = SS_NUM_PD,                \
        .pd_info = ss_pd_info,              \
        .pd_reboot_info = SS_PD_REBOOT_INFO,\
        .num_ctrl = SS_NUM_CTRL,            \
        .ctrl_info = (CTRL_INFO),           \
        .dsc_aon_reset_mask = SS_AON_RESET, \
        .irq_enb = SS_IRQ_ENB,              \
        .pd_dsc = SS_PD_DSC,                \
        .pd_ssi = SS_PD_SSI,                \
        .num_clks = SS_NUM_CLK,             \
        .clk_info = ss_clk_info,            \
        .ss_iso_info = ss_iso_info,         \
        .num_pll = SS_NUM_PLL,              \
        .mu_irq = SS_MU_IRQ,                \
        .dscmix = SS_DSCMIX,                \
        .ai_type = SS_AI_TYPE,              \
        .ss_phy_iso = SS_PHY_ISO,           \
        .ss_num_ssi = SS_NUM_SSI,           \
        .mtr_clk_idx = MTR_CLK_IDX,         \
        LPCG_INFO
#endif /* XRDC_SUPPORT */

#ifdef XRDC_SUPPORT
    /*! Define to fill in a ss_rsrc_info_t variable (with XRDC) */
    #define RNFO(PWD, C1 ,C2 ,C3 ,C4, C5, M, P, X, MI, PI, MATCHF, MASKF) \
    {                                                    \
        .master = U2B(M),                                \
        .peripheral = U2B(P),                            \
        .pd = U8(PWD),                                   \
        .clk = {U8(C1), U8(C2), U8(C3), U8(C4), U8(C5)}, \
        .xexp_idx = U8(X),                               \
        .xrdc_master_idx = U16(MI),                      \
        .xrdc_peripheral_idx = U16(PI),                  \
        .xrdc_mda_match = U16(MATCHF),                   \
        .xrdc_mda_mask = U16(MASKF)                     \
    }
#else
    /*! Define to fill in a ss_rsrc_info_t variable (without XRDC) */
    #define RNFO(PWD, C1 ,C2 ,C3 ,C4, C5, M, P, X, MI, PI, MATCHF, MASKF) \
    {                                                       \
        .master = U2B(M),                                   \
        .peripheral = U2B(P),                               \
        .pd = U8(PWD),                                      \
        .clk = {U8(C1), U8(C2), U8(C3), U8(C4), U8(C5)}    \
    }
#endif /* XRDC_SUPPORT */

/*! Define to fill in a ss_xexp_info_t variable */
#define XNFO(S, N)      \
{                       \
    .start = U16(S),    \
    .num = U8(N),       \
}

/*! Define to fill in a ss_ctrl_info_t variable */
#define TNFO(R, C, IO, B, W)      \
{                                 \
    .ss_idx = U8(SS_R_##R),       \
    .ctrl = U8(SC_C_##C),         \
    .io = (SS_IO_##IO),           \
    .bit = U16(B),                \
    .width = U8(W)                \
}

/*! Define to fill in a ss_mrc_info_t variable */
#define MNFO(P, ST, EN, AJ, M, I, SL, PWD, SB, C)    \
{                                   \
    .present = U2B(P),              \
    .start = U64(ST),               \
    .end = U64(EN),                 \
    .adjust = U64(AJ),              \
    .mrc = U16(M),                  \
    .idx = U16(I),                  \
    .num_slots = U16(SL),           \
    .pd = U8(PWD),                  \
    .sub = U8(SB),                  \
    .cache = (uint32_t*) (C)        \
}

/* Types */

/*!
 * This type is used to indicate pre- or post-amble function calls.
 */
typedef enum
{
    SS_PREAMBLE,        //!< Preamble function call
    SS_POSTAMBLE        //!< Postamble function call
} ss_prepost_t;

/*!
 * This type is used to indicate type of DSC I/O.
 */
typedef enum
{
    SS_IO_GPR_CTRL,     //!< GPR Control
    SS_IO_GPR_STAT,     //!< GPR Status
    SS_IO_CSR,          //!< CSR
    SS_IO_CSR2,         //!< CSR2
    SS_IO_CSR3,         //!< CSR3
    SS_IO_AI_RW,        //!< Analog Interface (RW)
    SS_IO_AI_RO,        //!< Analog Interface (RO)
    SS_IO_RST_CTRL,     //!< Reset control
    SS_IO_BRD_CTRL,     //!< Board control
    SS_IO_SW_CTRL       //!< Software control
} ss_io_type_t;

/*! Type for a ss resource index */
typedef uint8_t ss_idx_t;

/*! Type for a resource index */
typedef sc_rm_idx_t ss_ridx_t;

/*! Type for a clock index */
typedef uint8_t ss_clock_t;

/*! Type for a PLL index */
typedef uint8_t ss_pll_t;

/*! Type for an XRDC expansion info index */
typedef uint8_t ss_xexp_idx_t;

/*!
 * This type is used to store static constant info about the PACs in a
 * subsystem.
 */
typedef xrdc_pac_info_t ss_pac_info_t;

/*!
 * This type is used store static constant info to map resources
 * to the containing subsystem.
 */
typedef struct
{
    sc_rsrc_t resource : SC_RSRC_W;
    ss_idx_t ss_idx    : SS_IDX_W;
    sc_ss_inst_t inst  : SC_SS_INST_W;
} sc_rsrc_map_t;

/*!
 * This type is used store static constant info about resources in a
 * subsystem. A pointer to this structure can be found in the
 * ss_base_info_t type.
 */
typedef struct
{
    #ifdef XRDC_SUPPORT
        sc_rm_idx_t xrdc_master_idx     : SC_RM_IDX_W;  //!< XRDC MDAC MDA index
        sc_rm_idx_t xrdc_peripheral_idx : SC_RM_IDX_W;  //!< XRDC PAC PDAC index
        sc_rm_match_t xrdc_mda_match    : SC_RM_MATCH_W;//!< XRDC MDAC match
        sc_rm_match_t xrdc_mda_mask     : SC_RM_MATCH_W;//!< XRDC MDAC mask
        ss_xexp_idx_t xexp_idx          : SS_XEXP_W;    //!< XRDC expansion index
    #endif /* XRDC_SUPPORT */
    ss_clock_t clk[SS_MAX_PM_CLKS];                     //!< Clocks
    dsc_pdom_t pd                       : DSC_PDOM_W;   //!< Power domain
    sc_bool_t master                    : SC_BOOL_W;    //!< Master flag
    sc_bool_t peripheral                : SC_BOOL_W;    //!< Slave flag
} ss_rsrc_info_t;

/*!
 * This type is used store static constant info about controls in a
 * subsystem. A pointer to this structure can be found in the
 * ss_base_info_t type.
 */
typedef struct
{
    uint16_t bit                    : SS_FIELD_POS_W;   //!< Field position
    ss_idx_t ss_idx                 : SS_IDX_W;         //!< SS resource index
    uint8_t width                   : SS_FIELD_WID_W;   //!< Field width
    sc_ctrl_t ctrl                  : SC_CTRL_W;        //!< Control
    ss_io_type_t io                 : SS_IO_W;          //!< I/O type
} ss_ctrl_info_t;

#ifdef DISABLE_LPCG_AT_PD_PUP
typedef struct
{
    volatile uint32_t * lpcg_addr;                //!< LPCG offset
    xrdc_idx_t pac_idx;
    uint8_t num_cont_addr;
    dsc_pdom_t pd;
} ss_lpcg_info_t;
#endif

/*!
 * This type is used to store static constant info about the power domains
 * in the subsystem.
 */
typedef struct
{
    uint32_t reset_mask;                //!< Resets associated with the PD
} ss_pd_info_t;

/*!
 * This type is used to store static constant info about resources to
 * keep assigned to the SCU or associated with another resource.
 */
typedef struct
{
    xrdc_idx_t start;                           //!< Start slot
    uint8_t num;                                //!< Number of slots
} ss_xexp_info_t;

/*!
 * This type is used to store static constant info about the MDACs in a
 * subsystem.
 */
typedef struct
{
    xrdc_idx_t num_slots : XRDC_NUM_W;          //!< Number of slots
    dsc_pdom_t pd        : DSC_PDOM_W;          //!< Power domain
    uint8_t cid          : SS_CID_W;            //!< CPU ID
    sc_bool_t present    : SC_BOOL_W;           //!< Present
    uint32_t *cache;                            //!< Cache pointer
} ss_mdac_info_t;

/*!
 * This type is used to store static constant info about the MSCs in a
 * subsystem.
 */
typedef struct
{
    dsc_pdom_t pd        : DSC_PDOM_W;          //!< Power domain
    sc_bool_t present    : SC_BOOL_W;           //!< Present
} ss_msc_info_t;

/*!
 * This type is used to store static constant info about the MRCs in a
 * subsystem. Start->end address range indicates memory space covered
 * by an MRC.
 */
typedef struct
{
    sc_faddr_t start;                           //!< Start address
    sc_faddr_t end;                             //!< End address
    sc_faddr_t adjust;                          //!< Sub/mask for this MRC
    uint32_t *cache;                            //!< Cache pointer
    xrdc_idx_t mrc       : XRDC_NUM_W;          //!< MRC index
    xrdc_idx_t idx       : XRDC_NUM_W;          //!< index of first entry
    xrdc_idx_t num_slots : XRDC_NUM_W;          //!< Number of slots
    dsc_pdom_t pd        : DSC_PDOM_W;          //!< Power domain
    dsc_pdom_t sub       : SC_BOOL_W;           //!< Adjust by subtraction
    sc_bool_t present    : SC_BOOL_W;           //!< Present
} ss_mrc_info_t;

/*!
 * This type is used to store static constant info about a subsystem. An
 * array for all subsystems is declared in inf.c called ss_base_info. From
 * this array info for subsystems inc. resources, XRDC components, power
 * domains, etc. can be accessed.
 */
typedef struct
{
    uint64_t irq_enb;                       //!< Initial DSC IRQ enables
    #ifdef XRDC_SUPPORT
        const sc_faddr_t mrc_mask;          //!< Range of MRCs in subsystem
    #endif /* XRDC_SUPPORT */
    const ss_rsrc_info_t *rsrc;             //!< Pointer to resource info
    const sc_rsrc_map_t *rsrc_map;          //!< Pointer to resource map
    const ss_pd_info_t *pd_info;            //!< Pointer to power domain info
    const ss_pd_info_t *pd_reboot_info;     //!< Pointer to power domain info
    const ss_ctrl_info_t *ctrl_info;        //!< Pointer to control info
    const dsc_clk_info_t *clk_info;         //!< Pointer to clock info
    #ifdef DISABLE_LPCG_AT_PD_PUP
        const ss_lpcg_info_t *lpcg_info;    //!< Pointer to LPCG info
    #endif
    const uint8_t *ss_iso_info;             //!< SS Isolation info
    uint32_t dsc_aon_reset_mask;            //!< Resets associated with DSC AON
    uint32_t ss_phy_iso;                    //!< Additional ISO control (usually phy)
    #ifdef XRDC_SUPPORT
        const ss_xexp_info_t *xexp_info;    //!< Pointer to xexp info
        const ss_mdac_info_t *mdac_info;    //!< Pointer to MDAC info
        const ss_pac_info_t *pac_info;      //!< Pointer to PAC info
        const ss_msc_info_t *msc_info;      //!< Pointer to MSC info
        const ss_mrc_info_t *mrc_info;      //!< Pointer to MRC info
        uint32_t mdac_match;                //!< MDAC match flags
        uint16_t mdac_cache;                //!< Size of MDAC cache (per inst)
        uint16_t mrc_cache;                 //!< Size of MRC cache (per inst)
    #endif /* XRDC_SUPPORT */
    sc_rm_idx_t num_rsrc  : SC_RM_IDX_W;    //!< Number of resources
    sc_rm_idx_t num_srsrc : SC_RM_IDX_W;    //!< Number of resources with children
    #ifdef XRDC_SUPPORT
        xrdc_idx_t num_mdac : XRDC_NUM_W;   //!< Number of XRDC MDACs
        xrdc_idx_t num_pac  : XRDC_NUM_W;   //!< Number of XRDC PACs
        xrdc_idx_t num_msc  : XRDC_NUM_W;   //!< Number of XRDC MSCs
        xrdc_idx_t num_mrc  : XRDC_NUM_W;   //!< Number of XRDC MRCs
    #endif /* XRDC_SUPPORT */
    sc_rms_idx_t num_prsrc : SC_RMS_IDX_W;  //!< Number of resources with parent
    sc_rms_idx_t num_prsrc2 : SC_RMS_IDX_W; //!< Number of resources with second parent
    #ifdef DISABLE_LPCG_AT_PD_PUP
        uint8_t num_lpcg : DSC_NUM_LPCG_W;  //!< Number of lpcg in the ss
    #endif
    ss_clock_t num_clks : SS_CLK_W+1;       //!< Number of clocks
    sc_ctrl_t num_ctrl  : SC_CTRL_W;        //!< Number of controls
    dsc_pdom_t num_pd   : DSC_PDOM_W+1;     //!< Number of power domains
    dsc_pdom_t pd_dsc   : DSC_PDOM_W;       //!< Power domain of the gated DSC logic
    dsc_pdom_t pd_ssi   : DSC_PDOM_W;       //!< Power domain of the SSI
    #ifdef XRDC_SUPPORT
        dsc_pdom_t pd_mgr   : DSC_PDOM_W;   //!< Power domain of XRDC manager
    #endif /* XRDC_SUPPORT */
    ss_pll_t num_pll       : SS_PLL_W+1;    //!< Number of PLLs
    dsc_ai_type_t ai_type  : DSC_AI_TYPE_W; //!< Type of AI for this SS
    uint8_t ss_num_ssi     : SS_NUM_SSI_W;  //!< Number of standard SSI
    ss_clock_t mtr_clk_idx : SS_CLK_W;      //! < Clock index of the MTR clock
    sc_bool_t mu_irq       : SC_BOOL_W;     //!< SS has interrupt trigger MU
    sc_bool_t dscmix       : SC_BOOL_W;     //!< DSCMIX clock present
} ss_base_info_t;

/*!
 * This type is used to store dynamic data about the clocks/PLLs in
 * the subsystem.
 */
typedef struct
{
    uint16_t usecount;                              //!< Count of peripherals using clock
    sc_pm_clk_mode_t cur_mode : SC_PM_CLOCK_MODE_W; //!< Current mode of the clock
    sc_pm_clk_parent_t parent;                       //!< Current parent of the clock
    union {
        uint32_t rate_div;                          //!< Current rate divider for the clock
        uint32_t parent_rate;                       //!< store rate for parent clocks (pll, byp, xtal)
    };
} ss_clk_data_t;

/*!
 * This type is used to store dynamic data about a subsystem.
 */
typedef struct
{
    ss_clk_data_t clk_data[SS_MAX_CLK];             //!< Clock/PLL data
    ss_pll_t num_pll;                               //!< number of PLLs in the SS
    uint16_t usecount[DSC_MAX_PD][SC_PM_PW_MODE_ON];//!< PD use counts
    sc_pm_power_mode_t power_mode[DSC_MAX_PD];      //!< Power mode of each power domain
    #ifdef XRDC_SUPPORT
        uint8_t master_did[SC_RM_NUM_DOMAIN];       //!< Count of masters in each resource domain
    #endif /* XRDC_SUPPORT */
} ss_base_data_t;

/*! Type for IRQ handler */
typedef sc_bool_t (*ss_dsc_l2irq_handler)(sc_dsc_t dsc, uint32_t irqIndex);

/* Include auto generated interface info */
#include "inf_ss.h"

/*!
 * @name Interface Functions
 * @{
 */

/*!
 * This function initializes a subsystem.
 *
 * @param[in]     ss          subsystem to initialize
 * @param[in]     api_phase   flag indicating phase
 *
 * There are two phases to subsystem initialization. The fist phase is
 * the API phase (\a api_phase = SC_TRUE) and initializes all of the subsystem
 * interface data structures. The second phase is the HW phase and this
 * initializes the SS hardware. Both are called from main() only.
 */
/* IDL: SS_INIT() */
void ss_init(sc_sub_t ss, sc_bool_t api_phase);

/*!
 * This function transitions a resource from one power mode to another.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     from_mode   current resource power mode
 * @param[in]     to_mode     requested new resource power mode
 *
 * This function will be dispatched to the subsystem containing
 * \a rsrc_idx. If required, the subsystem power domains will change
 * (dsc, ssi, and that containing \a rsrc_idx).
 */
/* IDL: SS_TRANS_POWER_MODE() */
void ss_trans_power_mode(ss_ridx_t rsrc_idx,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);

/*!
 * This function requests a resource be reset.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     pt          partition
 * @param[in]     pre         pre-power off reset
 *
 * If pt equals SC_PT_ALL then reset all resources belonging
 * to that partition. Otherwise, reset rsrc_idx only.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
/* IDL: SS_RSRC_RESET() */
sc_err_t ss_rsrc_reset(ss_ridx_t rsrc_idx, sc_rm_pt_t pt,
    sc_bool_t pre);

/*!
 * This function requests the power power mode to be entered
 * for some resources under certain circumstances. 
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     mode        requested low-power mode
 * @param[in]     wake_src    low-power mode wake source
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * This function will be dispatched to the subsystem containing
 * \a rsrc_idx. If required, the subsystem power domains will change
 * (dsc, ssi, and that containing \a rsrc_idx).
 */
/* IDL: SS_SET_CPU_POWER_MODE() */
sc_err_t ss_set_cpu_power_mode(ss_ridx_t rsrc_idx,
    sc_pm_power_mode_t mode, sc_pm_wake_src_t wake_src);

/*!
 * This function sets the resume address of a CPU.
 *
 * @param[in]     rsrc_idx    unified resource index of CPU
 * @param[in]     isPrimary   set SC_TRUE if primary wake CPU
 * @param[in]     addr        boot address for CPU
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
/* IDL: SS_SET_CPU_RESUME() */
sc_err_t ss_set_cpu_resume(ss_ridx_t rsrc_idx, sc_bool_t isPrimary, sc_faddr_t addr);

/*!
 * This function requests the power mode for system-level interfaces 
 * including messaging units, interconnect, and memories.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     sys_if      system-level interface to be configured
 * @param[in]     hpm         high-power mode for the system interface
 * @param[in]     lpm         low-power mode for the system interface
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 */
/* IDL: SS_REQ_SYS_IF_POWER_MODE() */
sc_err_t ss_req_sys_if_power_mode(ss_ridx_t rsrc_idx,
    sc_pm_sys_if_t sys_if, sc_pm_power_mode_t hpm, sc_pm_power_mode_t lpm);

/*!
 * This function sets a clock rate.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     clk         clk to set
 * @param[in,out] rate        pointer to rate to set (Hz)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Will return actual rate that could be achieved in \a rate.
 */
/* IDL: SS_SET_CLOCK_RATE() */
sc_err_t ss_set_clock_rate(ss_ridx_t rsrc_idx, sc_pm_clk_t clk,
    sc_pm_clock_rate_t *rate);

/*!
 * This function gets a clock rate.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     clk         clk to get
 * @param[out]    rate        pointer to return rate (Hz)
 *
 * @return Returns the rate of the clock in Hz.
 */
/* IDL: SS_GET_CLOCK_RATE() */
sc_err_t ss_get_clock_rate(ss_ridx_t rsrc_idx, sc_pm_clk_t clk,
    sc_pm_clock_rate_t *rate);

/*!
 * This function enables a clock.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     clk         clk to enable/disable
 * @param[in,out] enable      flag indicating state (SC_TRUE = enable)
 * @param[in,out] autog       flag indicating HW autogate mode
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
/* IDL: SS_CLOCK_ENABLE() */
sc_err_t ss_clock_enable(ss_ridx_t rsrc_idx, sc_pm_clk_t clk,
    sc_bool_t enable, sc_bool_t autog);

/*!
 * This function enables a clock.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     clk         clk to enable/disable
 * @param[in,out] enable      flag indicating state (SC_TRUE = enable)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * This function forces the clock to the desired state regardless of
 * any other gating input (hardware, etc.).
 */
/* IDL: SS_FORCE_CLOCK_ENABLE() */
sc_err_t ss_force_clock_enable(ss_ridx_t rsrc_idx, sc_pm_clk_t clk,
    sc_bool_t enable);

/*!
 * This function sets the parent of a resource's clock.
 * This function should only be called when the clock is disabled.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     clk         clock to affect
 * @param[in]     new_parent  New parent of the clock.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid resource or clock,
 * - SC_ERR_NOACCESS if caller's partition is not the resource owner
 *   or parent of the owner,
 * - SC_ERR_UNAVAILABLE if clock not applicable to this resource
 * - SC_ERR_BUSY if clock is currently enabled.
 *
 * Refer to the [Clock List](@ref CLOCKS) for valid clock values.
 */
/* IDL: SS_SET_CLOCK_PARENT() */
sc_err_t ss_set_clock_parent(ss_ridx_t rsrc_idx, sc_pm_clk_t clk,
    sc_pm_clk_parent_t new_parent);

/*!
 * This function gets the parent of a resource's clock.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     clk         clock to affect
 * @param[out]    parent      pointer to return parent of clock.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid resource or clock,
 * - SC_ERR_NOACCESS if caller's partition is not the resource owner
 *   or parent of the owner,
 * - SC_ERR_UNAVAILABLE if clock not applicable to this resource
 *
 * Refer to the [Clock List](@ref CLOCKS) for valid clock values.
 */
/* IDL: SS_GET_CLOCK_PARENT() */
sc_err_t ss_get_clock_parent(ss_ridx_t rsrc_idx, sc_pm_clk_t clk,
    sc_pm_clk_parent_t *parent);

/*!
 * This function returns the functional state of a resource.
 *
 * @param[in]     rsrc_idx    unified resource index
 *
 * @return Returns a boolean (SC_TRUE if resource functional).
 *
 * This checks to see if the power and clocks for a resource
 * (inc. required bus clocks) are enabled.
 */
/* IDL: SS_IS_RSRC_ACCESSIBLE() */
sc_bool_t ss_is_rsrc_accessible(ss_ridx_t rsrc_idx);

/*!
 * This function triggers an interrupt on an MU.
 *
 * @param[in]     rsrc_idx    unified resource index of MU
 * @param[in]     mask        MU interrupt to trigger
 */
/* IDL: SS_MU_IRQ() */
void ss_mu_irq(ss_ridx_t rsrc_idx, uint32_t mask);

/*!
 * This function starts or stops a subsystem CPU.
 *
 * @param[in]     rsrc_idx    unified resource index of CPU
 * @param[in]     enable      enable/disable flag (SC_TRUE = enable)
 * @param[in]     addr        boot address for CPU
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
/* IDL: SS_CPU_START() */
sc_err_t ss_cpu_start(ss_ridx_t rsrc_idx, sc_bool_t enable, sc_faddr_t addr);

#ifdef XRDC_SUPPORT
/*!
 * This function enables the subsystem hardware resource manager.
 *
 * @param[in]     ss          subsystem to affect
 * @param[in]     master      master only
 */
/* IDL: SS_RDC_ENABLE() */
void ss_rdc_enable(sc_sub_t ss, sc_bool_t master);

/*!
 * This function configures a subsystem master.
 *
 * @param[in]     rsrc_idx    unified resource index of master
 * @param[in]     valid       valid flag (SC_TRUE = valid)
 * @param[in]     lock        lock flag (SC_TRUE = lock)
 * @param[in]     sa          security attribute
 * @param[in]     pa          privilege attribute
 * @param[in]     did         domain ID
 * @param[in]     sid         StreamID
 * @param[in]     cid         CPU ID
 */
/* IDL: SS_RDC_SET_MASTER() */
void ss_rdc_set_master(ss_ridx_t rsrc_idx, sc_bool_t valid, sc_bool_t lock,
    sc_rm_spa_t sa, sc_rm_spa_t pa, sc_rm_did_t did, sc_rm_sid_t sid,
    uint8_t cid);

/*!
 * This function configures a subsystem peripheral.
 *
 * @param[in]     rsrc_idx    unified resource index of peripheral
 * @param[in]     valid       valid flag (SC_TRUE = valid)
 * @param[in]     lock        lock flag (SC_TRUE = lock)
 * @param[in]     perms       array of permissions
 * @param[in]     no_update   if true, don't update if already valid
 */
/* IDL: SS_RDC_SET_PERIPHERAL() */
void ss_rdc_set_peripheral(ss_ridx_t rsrc_idx, sc_bool_t valid, sc_bool_t lock,
    const sc_rm_perm_t *perms, sc_bool_t no_update);

/*!
 * This function configures a memory region.
 *
 * @param[in]     start       64-bit start address
 * @param[in]     end         64-bit end address
 * @param[in]     valid       valid flag (SC_TRUE = valid)
 * @param[in]     perms       array of permissions
 * @param[in]     det         detour transaction to IEE
 * @param[in]     rmsg        IEE config
 * @param[in]     new_start   new 64-bit start address
 * @param[in]     new_end     new 64-bit end address
 */
/* IDL: SS_RDC_SET_MEMORY() */
sc_err_t ss_rdc_set_memory(sc_faddr_t start, sc_faddr_t end, sc_bool_t valid,
    const sc_rm_perm_t *perms, sc_rm_det_t det, sc_rm_rmsg_t rmsg, 
    sc_faddr_t new_start, sc_faddr_t new_end);

#endif /* XRDC_SUPPORT */

/*!
 * This function sets a miscellaneous control value.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     ctrl        control to write
 * @param[in]     val         value to write
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
/* IDL: SS_SET_CONTROL() */
sc_err_t ss_set_control(ss_ridx_t rsrc_idx, uint32_t ctrl, uint32_t val);

/*!
 * This function gets a miscellaneous control value.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     ctrl        control to read
 * @param[out]    val         pointer to return value
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
/* IDL: SS_GET_CONTROL() */
sc_err_t ss_get_control(ss_ridx_t rsrc_idx, uint32_t ctrl, uint32_t *val);

/*!
 * This function enables/disables interrupts.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     group       group the interrupts are in
 * @param[in]     mask        mask of interrupts to affect
 * @param[in]     enable      state to change interrupts to
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if group invalid
 */
/* IDL: SS_IRQ_ENABLE() */
sc_err_t ss_irq_enable(ss_ridx_t rsrc_idx, sc_irq_group_t group,
    uint32_t mask, sc_bool_t enable);

/*!
 * This function returns the current interrupt status. Automatically
 * clears pending interrupts.
 *
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     group       groups the interrupts are in
 * @param[in]     status      status of interrupts
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if group invalid
 */
/* IDL: SS_IRQ_STATUS() */
sc_err_t ss_irq_status(ss_ridx_t rsrc_idx, sc_irq_group_t group,
    uint32_t *status);

/*!
 * This function triggers an interrupt.
 *
 * @param[in]     group       group the interrupt is in
 * @param[in]     irq         interrupt to trigger
 * @param[in]     pt          partition to trigger
 *
 * This function results in an interrupt being triggered on all SCFW MUs
 * owned by the specified partition that have the interrupt enabled. Use
 * SC_PT_ALL to trigger for all partitions.
 *
 * See the [RPC protocol section](@ref PROTOCOL) for more information.
 */
/* IDL: SS_IRQ_TRIGGER() */
void ss_irq_trigger(sc_irq_group_t group, uint32_t irq, sc_rm_pt_t pt);

/*!
 * This function dumps the state of a subsystem.
 */
/* IDL: SS_DUMP() */
void ss_dump(sc_sub_t ss, sc_bool_t xrdc, sc_bool_t dsc, sc_bool_t clk);

/** @} */

/*!
 * @name Helper Functions
 * @{
 */

/*!
 * This function runs manual memory repair on a subsystem.
 *
 * @param[in]     ss          subsystem to repair
 * @param[in]     pd          power domain to repair
 * @param[in]     enable      reset state of MTR HW
 *
 * This function does memory repair manually to work around HW issues.
 */
/* IDL: SS_DO_MEM_REPAIR() */
void ss_do_mem_repair(sc_sub_t ss, dsc_pdom_t pd, sc_bool_t enable);

/*!
 * This function is used to configure SS features after a SS is
 * fully powered up (SSI link enabled) or before powering down.
 *
 * @param[in]     ss          subsystem transitioning
 * @param[in]     up          SC_TRUE if powered up, SC_FALSE if powering down
 *
 * This function is used to customize subsystem power transitions.
 * It can be used to control the subsystem or wait for subsystem
 * status before/after power mode transitions.
 */
/* IDL: SS_UPDOWN() */
void ss_updown(sc_sub_t ss, sc_bool_t up);

/*!
 * This function is a pre- and post-amble for power domain power
 * mode transitions.
 *
 * @param[in]     ss          subsystem transitioning
 * @param[in]     pd          power domain transitioning
 * @param[in]     type        type of notification
 * @param[in]     from_mode   current power domain mode
 * @param[in]     to_mode     new power domain mode
 * @param[in]     rom_boot    SC_TRUE if ROM has powered up SS
 *
 * This function is used to customize subsystem power transitions.
 * It can be used to control the subsystem or wait for subsystem
 * status before/after power mode transitions.
 */
/* IDL: SS_PREPOST_POWER_MODE() */
void ss_prepost_power_mode(sc_sub_t ss, dsc_pdom_t pd,
    ss_prepost_t type, sc_pm_power_mode_t from_mode,
    sc_pm_power_mode_t to_mode, sc_bool_t rom_boot);

/*!
 * This function enables/disables the isolation in a subsystem.
 *
 * @param[in]     ss          subsystem to affect
 * @param[in]     pd          power domain to affect
 * @param[in]     enable      flag indicating new state (SC_TRUE = enable)
 */
/* IDL: ss_iso_disable() */
void ss_iso_disable(sc_sub_t ss, dsc_pdom_t pd, sc_bool_t enable);

/*!
 * This function enables/disables the interfaces in a subsystem.
 *
 * @param[in]     ss          subsystem to affect
 * @param[in]     pd          power domain to affect
 * @param[in]     enable      flag indicating new state (SC_TRUE = enable)
 */
/* IDL: ss_link_enable() */
void ss_link_enable(sc_sub_t ss, dsc_pdom_t pd, sc_bool_t enable);

/*!
 * This function enables/disables a subsystems's SSI ports.
 *
 * @param[in]     ss          subsystem to affect
 * @param[in]     enable      flag indicating new state (SC_TRUE = on)
 */
/* IDL: SS_SSI_POWER() */
void ss_ssi_power(sc_sub_t ss, sc_bool_t enable);

/*!
 * This function enables/disables black hole mode of an SSI.
 *
 * @param[in]     ss          subsystem to affect
 * @param[in]     remote      affect SSI to this subsystem
 * @param[in]     port        affect this instance of the SSI
 * @param[in]     enable      flag indicating new state (SC_TRUE = enable)
 */
/* IDL: SS_SSI_BHOLE_MODE() */
void ss_ssi_bhole_mode(sc_sub_t ss, sc_sub_t remote, uint8_t port,
    sc_bool_t enable);

/*!
 * This function enables/disables pause mode of an SSI.
 *
 * @param[in]     ss          subsystem to affect
 * @param[in]     remote      affect SSI to this subsystem
 * @param[in]     port        affect this instance of the SSI
 * @param[in]     enable      flag indicating new state (SC_TRUE = enable)
 */
/* IDL: SS_SSI_PAUSE_MODE() */
void ss_ssi_pause_mode(sc_sub_t ss, sc_sub_t remote, uint8_t port,
    sc_bool_t enable);

/*!
 * This function waits for an SSI to become idle.
 *
 * @param[in]     ss          subsystem to affect
 * @param[in]     remote      affect SSI to this subsystem
 * @param[in]     port        affect this instance of the SSI
 */
/* IDL: SS_SSI_WAIT_IDLE() */
void ss_ssi_wait_idle(sc_sub_t ss, sc_sub_t remote, uint8_t port);

/*!
 * This function setups an ADB interface between two ss.
 *
 * @param[in]     ss          local subsystem
 * @param[in]     remote      remote subsystem
 * @param[in]     enable      powerup/powerdown the ADB link
 */
/* IDL: SS_ADB_ENABLE() */
void ss_adb_enable(sc_sub_t ss, sc_sub_t remote, sc_bool_t enable);

/*!
 * This function waits for the ADB to be powered up.
 *
 * @param[in]     ss          local subsystem
 * @param[in]     remote      remote subsystem
 * @param[in]     enable      powerup/powerdown the ADB link
 */
/* IDL: SS_ADB_WAIT() */
void ss_adb_wait(sc_sub_t ss, sc_sub_t remote, sc_bool_t enable);

/*!
 * This function is a pre- and post-amble for clock mode transitions.
 *
 * @param[in]     ss          subsystem transitioning
 * @param[in]     clk         clock transitioning
 * @param[in]     type        type of notification
 * @param[in]     from_mode   current clock mode
 * @param[in]     to_mode     new clock mode
 *
 * This function is used to customize subsystem clock transitions.
 * It can be used to control the subsystem or wait for subsystem
 * status before/after clock transitions.
 */
/* IDL: SS_PREPOST_CLOCK_MODE() */
void ss_prepost_clock_mode(sc_sub_t ss, ss_clock_t clk, ss_prepost_t type,
    sc_pm_clk_mode_t from_mode, sc_pm_clk_mode_t to_mode);

#ifdef XRDC_SUPPORT
/*!
 * This function checks if a subsystem generates transactions matching
 * domains.
 *
 * @param[in]     ss          subsystem to check
 * @param[in]     perms       array of permissions
 *
 * @return Returns SC_TRUE if the subsystem has masters in domains which
 * have access in \a perms.
 */
/* IDL: SS_RDC_IS_DID_VLD() */
sc_bool_t ss_rdc_is_did_vld(sc_sub_t ss, const sc_rm_perm_t *perms);
#endif /* XRDC_SUPPORT */

/*!
 * This function returns a system-wide resource from a subsystem
 * and subsystem relative resource index.
 *
 * @param[in]     ss       subsystem containing resource
 * @param[in]     ss_idx   subsystem index of resource
 *
 * @return Returns the system-wide resource.
 */
sc_rsrc_t ss_get_resource(sc_sub_t ss, ss_idx_t ss_idx);

/*!
 * This function determines if two memory regions overlap.
 *
 * @param[in]     start1      start address for region 1
 * @param[in]     end1        end address for region 1
 * @param[in]     start2      start address for region 2
 * @param[in]     end2        end address for region 2
 *
 * @return Returns SC_TRUE if the memory regions overlap.
 */
sc_bool_t ss_overlap(sc_faddr_t start1, sc_faddr_t end1, sc_faddr_t start2,
    sc_faddr_t end2);

/*!
 * This function gets temp sensor availability of a subsystem.
 *
 * @param[in]     rsrc_idx    any resource in the subsystem
 *
 * @return Returns SC_TRUE if the associated subsystem has a temp sensor.
 */
sc_bool_t ss_temp_sensor(ss_ridx_t rsrc_idx);

/** @} */

/* Externs */

extern const sc_ss_ep_t sc_ss_ep[SC_SUBSYS_LAST + 1U];
extern ss_base_data_t sc_ss_data[SC_SUBSYS_LAST + 1U];

#endif /* SC_SS_INF_H */

/** @} */

