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
 * Header file containing the SoC API. This abstracts SoC-specific
 * functionality such as init, info, analog, power, HPM, and DDR.
 *
 * @addtogroup SOC SOC: SoC Interface
 *
 * Module for the SoC Interface.
 *
 * @{
 */
/*==========================================================================*/

#ifndef SC_SOC_API_H
#define SC_SOC_API_H

/* Includes */

#include "main/board.h"

/*! Macro to configure an STC category */
#define STC_RCAT_SETCAT(SS, CAT, CATMASK, CMP)              \
    STC_RCAT_SetCategorization(base_ptrs[                   \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, CATMASK, CMP)

/*! Macro to set an STC TDM */
#define STC_RCAT_SETSTARTSTOPTDM(SS, CAT, TDM, START, STOP)	\
    STC_RCAT_SetStartStopTDM(base_ptrs[		                \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],	                    \
    CAT, TDM, START, STOP)

/*! Macro to get an STC HPR */
#define STC_RCAT_GETHPR(SS, CAT)                            \
    STC_RCAT_GetHPR(base_ptrs[                              \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi], CAT)

/*! Macro to set an STC HPR */
#define STC_RCAT_SETHPR(SS, CAT, HPR)                       \
	STC_RCAT_SetHPR(base_ptrs[sc_ss_info[                   \
	SC_SUBSYS_##SS].db_ssi], CAT, HPR)

/*! Macro to set an STC QoS panic */
#define STC_QOS_PANIC(SS, CAT, QOS)                         \
    STC_QOS_Panic(base_ptrs[                                \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, QOS)

/*! Macro to set an STC threshold */
#define STC_UD_THRESHOLD1(SS, CAT, TH, QOS)                 \
    STC_UD_EnableThreshold1(base_ptrs[                      \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, TH, QOS)

/*! Macro to set an STC threshold 2 */
#define STC_UD_THRESHOLD2(SS, CAT, TH, QOS)                 \
    STC_UD_EnableThreshold2(base_ptrs[                      \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, TH, QOS)

/*! Macro to disable an STC underrun detect */
#define STC_UD_DIS(SS)                                      \
    STC_UD_DisableAll(base_ptrs[                            \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi])

/* Indicator for system interface resources to manage power
 * mode directly (i.e. no save/restore).
 */
#define SOC_SYS_IF_NO_SAVE      (SC_PM_PW_MODE_ON + 1U)

/*! Reset reason SNVS persistent storage register */
#define SOC_RR                  1U

/*! Macro to check if reset reason is valid */
#define SOC_RR_CHECK(X)         ((((X) >> 24U) & 0xFFUL) == 0xCCUL)

/*! Macro to set the reset reason */
#define SOC_RR_INFO(R, P)       ((0xCCUL << 24U) | (U32(R) << 8U) | U32(P))

/*! Macro to extract the reset reason */
#define SOC_RR_REASON(X)        (((X) >> 8U) & 0xFFUL)

/*! Macro to extract the resetting partition */
#define SOC_RR_PT(X)            (((X) >> 0U) & 0xFFUL)

/*!
 * @name Defines for patch ID
 */
/** @{ */
#define SC_PATCH_ID_NONE            0x00U   /* Non patch - end marker */
#define SC_PATCH_ID_SCU             0x55U   /* SCU ROM patch */
#define SC_PATCH_ID_SECO            0x45U   /* SECO ROM patch */
#define SC_PATCH_ID_V2X             0x57U   /* V2X primary ROM patch */
#define SC_PATCH_ID_V2X2            0x59U   /* V2X secondary ROM patch */
#define SC_PATCH_ID_C2XS            0x5AU   /* V2X ROM patch SHA value */
#define SC_PATCH_ID_CTRL            0x5BU   /* Patch control */
#define SC_PATCH_ID_ALL             0xFFU   /* All patch IDs */
/** @} */

typedef struct
{
    const uint16_t offset;
    const uint16_t len;
} soc_patch_area_list_t;

typedef struct
{
    uint32_t freq;
    uint32_t volt;
    uint8_t bias;
} soc_freq_volt_tbl_t;

typedef struct
{
    uint32_t shader_clk;
    uint32_t core_clk;
    uint32_t ahb_clk;
    uint32_t axi_ssi_clk;
} soc_gpu_clks_opp_t;

/*!
 * Stores CPU power state info
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    sc_pm_power_mode_t req_mode;
    sc_bool_t lpm_active;
    sc_bool_t rst_req;
    sc_bool_t early_wake;
    uint8_t wake_idx;
    sc_pm_wake_src_t wake_src;
    sc_faddr_t resume_addr;
} soc_cpu_state_t;

/*!
 * Stores cluster power state info
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    uint8_t num_cpu;
    soc_cpu_state_t *cpu_state;
    sc_pm_power_mode_t req_mode;
} soc_cluster_state_t;

/*!
 * Stores multi-cluster power state info
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    soc_cluster_state_t *cluster_state;
    sc_pm_power_mode_t req_mode;
} soc_multicluster_state_t;

/*!
 * Stores MCU sleep state info
 */
typedef struct
{
    sc_rm_idx_t wic_rm_idx;
    sc_rm_idx_t sc_mu_rm_idx;
    sc_bool_t    dsm_req;
    sc_bool_t    dsm_active;
    sc_bool_t    rst_req;
    uint8_t stopm;
    uint8_t pstopo;
    sc_faddr_t resume_addr;
} soc_mcu_state_t;

/*!
 * Stores auxiliary core power state info
 */
typedef struct
{
    sc_bool_t   active;
    sc_bool_t   fw_loading;
    sc_saddr_t  fw_addr;
    sc_pm_sys_if_t fw_sys_if;
} soc_aux_state_t;

/*!
 * Stores system interface node resource info
 */
typedef struct
{
    sc_rm_idx_t num_rm_idx;             /*!< Number of resources in the node */
    const sc_rsrc_t *rsrc;              /*!< Resource array for node */
    sc_rm_idx_t *rm_idx;                /*!< Resource index array for node */
    sc_pm_power_mode_t *saved_pm;       /*!< Saved power mode array for node */
} soc_sys_if_node_t;

/*!
 * Stores system interface power mode request info
 */
typedef struct
{
    sc_pm_power_mode_t hpm;     /*!< High-power mode for system interface */
    sc_pm_power_mode_t lpm;     /*!< Low-power mode for system interface */
} soc_sys_if_req_t;

/*!
 * Stores HMP node power mode info
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    soc_sys_if_req_t *sys_if_req;       /*!< System interface mode request array */
} soc_hmp_node_t;

/*!
 * Stores HMP FSPI retention info
 */
typedef struct
{
    sc_pm_power_mode_t pm;              /*!< FSPI power mode to restore */
    uint32_t clk_rate;                  /*!< FSPI clock rate to restore */
} soc_fspi_ret_info_t;

/*!
 * Stores HMP system power mode info
 */
typedef struct
{
    uint8_t num_hmp;                    /*!< Number of HMP nodes */
    soc_hmp_node_t *hmp_node;           /*!< HMP node array */
    uint8_t num_sys_if;                 /*!< Number of system interface nodes */
    soc_sys_if_node_t *sys_if_node;     /*!< System interface node array */
    sc_bool_t sys_if_mgmt;              /*!< System interface management flag */
    sc_rm_idx_t ap_gic_rm_idx;          /*!< AP GIC resource index */
    sc_rm_idx_t ap_irqstr_rm_idx;       /*!< AP IRQSTR resource index */
    uint8_t ap_resume_cluster_idx;      /*!< AP resume cluster index */
    uint8_t ap_resume_cpu_idx;          /*!< AP resume cpu index */
    sc_pm_power_mode_t ocmem_mode;      /*!< On-chip memory mode for SoC */
    soc_fspi_ret_info_t fspi_ret_info;  /*!< FSPI retention info */
    sc_pm_power_mode_t ddr_mode;        /*!< DDR mode for SoC */
    sc_bool_t ddr_active;               /*!< DDR active (initialized) boolean */
    sc_bool_t lpm_active;               /*!< LPM active boolean */
} soc_hmp_t;

/*
 * Stores DDR retention region info
 */
typedef struct
{
    const uint32_t addr;                /*!< Address of DDR region to be retained */
    const uint32_t size;                /*!< Size of DDR region to be retained */
    uint32_t * const buf;               /*!< Pointer to SCFW buffer for DDR retention */
} soc_ddr_ret_region_t;

/*!
 * Stores DDR retention info
 */
typedef struct
{
    const uint32_t num_drc;                     /*!< Number of DRCs to retain */
    ddrc * const drc_inst;                      /*!< Buffer for DRC register retention */
    ddr_phy * const drc_phy_inst;               /*!< Buffer for DRC PHY register retention */
    const uint32_t num_region;                  /*!< Number of DDR retention regions */
    const soc_ddr_ret_region_t * const region;  /*!< Retention region array */
    uint32_t drc0_clk_rate;                     /*!< Clock rate to restore after retention */
#if HAS_SS_DRC_1
    uint32_t drc1_clk_rate;                     /*!< Clock rate to restore after retention */
#endif
} soc_ddr_ret_info_t;


#ifdef SWI_DQS2DQ_IRQn
/*!
 * Stores DQS2DQ synchronization info
 */
typedef struct
{
    const sc_rsrc_t isi_rsrc;                   /*!< ISI channel used for sync */
    ISI_Type * const isi_regs;                  /*!< ISI peripheral registers */ 
    uint32_t timeout_usec;                      /*!< Sync search timeout */
} soc_dqs2dq_sync_info_t;
#endif

/*!
 * Stores MSI ring usecount
 */
typedef struct
{
    const sc_rsrc_t rsrc;
    uint16_t count;
    uint16_t ss_count;
} soc_msi_ring_usecount_t;

#ifndef NO_DEVICE_ACCESS
// Define to enable self-hosted debug
#if 0
#define SOC_SELFHOSTED_DEBUG
#endif
#endif

#ifdef SOC_SELFHOSTED_DEBUG
#define LAR_OFFSET          (0xFB0U)
#define LAR_KEY             (0xC5ACCE55U)

#define DBGDTRRX_OFFSET     (0x080U)
#define EDITR_OFFSET        (0x084U)
#define EDSCR_OFFSET        (0x088U)
#define DBGDTRTX_OFFSET     (0x08CU)
#define EDPRSR_OFFSET       (0x314U)

#define CTICONTROL_OFFSET   (0x000U)
#define CTIAPPPULSE_OFFSET  (0x01CU)
#define CTIOUTEN0_OFFSET    (0x0A0U)

#define MSR_OP_CODE(op0, op1, CRn, CRm, op2, Rt) \
    (0xD5000000U | (op0 << 19U) | (op1 << 16U) | \
    (CRn << 12U) | (CRm << 8U) | (op2 << 5U) | (Rt << 0U))

#define MRS_OP_CODE(op0, op1, CRn, CRm, op2, Rt) \
    (0xD5200000U | (op0 << 19U) | (op1 << 16U) | \
    (CRn << 12U) | (CRm << 8U) | (op2 << 5U) | (Rt << 0U))

#define SYS_OP_CODE(op1, CRn, CRm, op2, Rt) \
    (0xD5000000U | (0x1U << 19U) | (op1 << 16U) | \
    (CRn << 12U) | (CRm << 8U) | (op2 << 5U) | (Rt << 0U))

typedef struct
{
    const uint32_t dbg_base;
    const uint32_t cti_base;
} soc_dbgapb_cpu_info_t;

typedef struct
{
    const uint8_t num_way;      // Number of ways
    const uint16_t num_set;     // Number of sets
    const uint8_t way_shift;    // Shift for way encoding
    const uint8_t set_shift;    // Shift for set encoding
    const uint8_t ofs_shift;    // Shift for cache offset encoding
    const uint8_t data_ramid;   // L1 data RAM identifier
    const uint8_t tag_ramid;    // L1 tag RAM identifier
    const uint32_t CDBGDR0;     // Data register 0
    const uint32_t CDBGDR1;     // Data register 1
    const uint32_t CDBGxCT;     // D-Cache tag read operation
    const uint32_t CDBGxCD;     // D-Cache data read operation
} soc_dbgapb_cache_info_t;

typedef struct
{
    const uint8_t num_cpu;                  // Number of CPUs in cluster
    const sc_rsrc_t cpu0_rsrc;              // First CPU resource
    soc_dbgapb_cache_info_t const *dc_info; // D-cache info
    soc_dbgapb_cache_info_t const *ic_info; // I-cache info
} soc_dbgapb_cluster_info_t;

#endif

/* External variables */

/*! Global variable to hold resetting partition */
extern sc_rm_pt_t soc_reset_pt;

/*! Global variable to hold reset reason */
extern sc_pm_reset_reason_t soc_reset_rsn;

/* ! Global variable to hold the dco-pc values for table 0 */
extern uint32_t soc_dpll_tbl_0[];

/* ! Global variable to hold the dco-pc values for table 1 */
extern uint32_t soc_dpll_tbl_1[];

/*!Global variable to store the state of clocks during power transition */
extern sc_bool_t soc_clk_off_trans;

/*! Global variable to hold the SCU standalone repeater trim. */
#ifdef OTP_SCU_REG_TRIM
extern uint32_t soc_scu_srut;
#endif

/*! Global variable to hold the VPU standalone repeater1 trim. */
#ifdef OTP_VPU_REG0_TRIM
extern uint32_t soc_vpu_srut1;
#endif

/*! Global variable to hold the VPU standalone repeater2 trim. */
#ifdef OTP_VPU_REG1_TRIM
extern uint32_t soc_vpu_srut2;
#endif

#if HAS_SS_GPU_0 || HAS_SS_GPU_1
/*! Global variable to hold the maximum GPU freq dictated by the fuse. */
extern uint32_t soc_max_gpu_freq;
#endif

#if HAS_SS_AP_0
/*! Global variable to hold the maximum AP0 freq dictated by the fuse. */
extern uint32_t soc_max_ap0_freq;
#endif

#if HAS_SS_AP_1
/*! Global variable to hold the maximum AP1 freq dictated by the fuse. */
extern uint32_t soc_max_ap1_freq;
#endif

#if HAS_SS_AP_2
/*! Global variable to hold the maximum AP2 freq dictated by the fuse. */
extern uint32_t soc_max_ap2_freq;
#endif

#if (HAS_SS_GPU_0 || HAS_SS_GPU_1) && !defined(NO_GPU_CLKS)
/*! 
 * Global variable to hold the GPU clock frequency and voltage for the
 * various operating points.
 */
extern soc_gpu_clks_opp_t gpu_clks[NUM_GPU_OPP];
#endif

extern soc_hmp_t soc_hmp;
extern soc_sys_if_req_t soc_sys_if_req[SOC_NUM_HMP_NODES][SOC_NUM_SYS_IF];
extern soc_mcu_state_t soc_mcu_state[SOC_NUM_MCU];
#if defined(SOC_NUM_AUX) && (SOC_NUM_AUX >= 1)
extern soc_aux_state_t soc_aux_state[SOC_NUM_AUX];
#endif
extern soc_cluster_state_t soc_cluster_state[SOC_NUM_CLUSTER];

#if (SOC_NUM_CLUSTER > 1U)
    extern soc_multicluster_state_t soc_multicluster_state;
#endif

#ifdef SWI_DQS2DQ_IRQn
extern soc_dqs2dq_sync_info_t *soc_dqs2dq_sync_info;
#endif

#if FSL_FEATURE_PCIE_DPLL_SS
extern uint32_t ss_step;
extern uint32_t ss_stop;
extern uint32_t ss_denom;
#endif

/*! Global variable to track if boot resources should not be reset. */
extern sc_bool_t soc_no_reset;

/* Functions */

/*!
 * @name Initialization Functions
 * @{
 */

/*!
 * This function initializes the parts of the SoC.
 *
 * @param[in]     phase       flag indicating phase
 *
 */
void soc_init_common(boot_phase_t phase);

/*!
 * This function initializes the SoC specific parts of the chip.
 *
 * @param[in]     phase       flag indicating phase
 *
 */
void soc_init(boot_phase_t phase);

/*!
 * This function configures SCU resources.
 *
 * @param[in]     pt_sc       SCU partition
 * @param[in]     pt_boot     boot partition
 */
void soc_config_sc(sc_rm_pt_t pt_sc, sc_rm_pt_t pt_boot);

/*!
 * This function configures SECO resources.
 */
void soc_config_seco(void);

/*!
 * Configure QoS in the DB when it is powered up.
 */
void soc_qos_config(void);

#ifdef AUTOCAL
/*!
 * Calibrate REFGEN tree.
 */
void soc_autocal_refgen_tree(void);
#endif

/*!
 * This function returns the pointer to fuse availability array.
 */
uint32_t *soc_get_fuse_avail(void);

/*!
 * This function fills in a bit array with info about disabled
 * resources.
 */
void soc_init_fused_rsrc(void);

/*!
 * This function configures a subsystem as not available.
 *
 * @param[in]     ss          subsystem not available
 */
void soc_ss_notavail(sc_sub_t ss);

/*!
 * This function initializes the refgen trims from the fuses.
 */
void soc_init_refgen(void);

/*!
 * This function initialize regulator, repeater and osc trims
 * from the fuses.
 */
void soc_analog_fuse_init(void);

#if HAS_SS_GPU_0 || HAS_SS_GPU_1
/*!
 * This function initializes the maximum GPU core, shader
 * and AXI clock based on the fuse.
 *
 * @param[in]     gpu_fuse   GPU Frequency fuse
 */
uint32_t soc_gpu_freq_config(uint32_t gpu_fuse);
#endif

#if defined(HAS_V2X) && HAS_SS_V2X
/*!
 * This function enables/disables V2X.
 *
 * @param[in]     enb        enable/disable
 */
void soc_v2x_enable(sc_bool_t enb);
#endif

/** @} */

/*!
 * @name Info Functions
 * @{
 */

/*!
 * This function saves reset info into persistent storage.
 *
 * @param[in]     reason      reason for reset
 * @param[in]     pt          partition that caused reset
 *
 */
void soc_set_reset_info(sc_pm_reset_reason_t reason, sc_rm_pt_t pt);

/*!
 * Return reset reason.
 */
sc_pm_reset_reason_t soc_reset_reason(void);

/*!
 * Return partition causing reset.
 */
sc_rm_pt_t soc_reset_part(void);

/*!
 * This function returns if a resource is available.
 *
 * @param[in]     rsrc        resource to check
 *
 * @return Returns SC_TRUE if the resource is available.
 */
sc_bool_t soc_rsrc_avail(sc_rsrc_t rsrc);

/*!
 * This function returns the trim value for a temp sensor.
 *
 * @param[in]     dsc         DSC to check
 *
 * @return Returns trim value.
 */
uint32_t soc_get_temp_trim(sc_dsc_t dsc);

/*!
 * This function returns the offset value for a temp sensor.
 *
 * @param[in]     dsc         DSC to check
 *
 * @return Returns the offset value.
 */
int8_t soc_get_temp_ofs(sc_dsc_t dsc);

/*!
 * This function returns temp interrupt to use.
 *
 * @param[in]     dsc         DSC alarm came from
 * @param[in]     alarm       alarm (0=panic, 1=low, 2=high)
 *
 * @return Returns the interrupt.
 */
uint32_t soc_get_temp_trigger(sc_dsc_t dsc, uint32_t alarm);

/*!
 * This function returns the maximum frequency limited by
 * the fuses for the GPU and AP cores
 *
 * @param[in]     dsc_id        DSC to check
 *
 * @return Returns the maximum frequency limited by fuse
 */
uint32_t soc_get_max_freq(sc_dsc_t dsc_id);

/*!
 * This function checks if the frequency is limited by
 * fuse.
 *
 * @param[in]     enet_rsrc      ethernet resource to check
 *
 * @return SC_TRUE is frequency is limited
 */
sc_bool_t soc_enet_get_freq_limit(sc_rsrc_t enet_rsrc);

/*!
 * Initialize the maximum frequency of certain resources based
  * on fuses.
 */
void soc_get_max_freq_fuse(void);

/*!
 * This function identifies if the given pd has internal
 * or external switches.
 *
 *@param[in]      dsc            DSC to affect
 *@param[in]      pd             pd to affect
 *
 * @return    Returns SC_TRUE if the pd is internally switched,
 *            SC_FALSE if externally switched.
 */
sc_bool_t soc_pd_switchable(sc_dsc_t dsc, uint32_t pd);

#ifdef SELECTIVE_SRPG_DISCARD
/*!
 * This function selectively discards the SRPG contents
 * for a pd.
 *
 *@param[in]      dsc            DSC to affect
 *@param[in]      pd             pd to affect
 */
void soc_pd_retention_discard(sc_dsc_t dsc, uint32_t pd);
#endif

/*!
 * This function checks if the given power domain of the given
 * dsc supports retention.
 *
 *@param[in]      dsc            DSC to affect
 *@param[in]      pd             pd to affect
 *
 * @return    Returns SC_TRUE if the pd supports retention
 */
sc_bool_t soc_pd_retention(sc_dsc_t dsc, uint32_t pd);

/*!
 * This function checks if the given subsystem has forward
 * body-bias.
 *
 *@param[in]      ss            subsystem to affect
 *
 * @return    Returns SC_TRUE if the pd supports forward body-bias
 */
sc_bool_t soc_ss_has_bias(sc_sub_t ss);

/*!
 * This function returns the subsystem AI type, mainly used to
 * identify if an SS has temp sensor.
 *
 * @param[in]     ss          subsystem to check
 *
 * @return  Type of Analog Interface in the SS
 */
dsc_ai_type_t soc_ss_ai_type(sc_sub_t ss);

/*!
 * Return the type of memory used in the given PD of 
 * the DSC.
 *
 *@param[in]      dsc            DSC to affect
 *@param[in]      pd             pd to affect
 *
 * @return     Type of memory (ESilicon or Normal) used in the SS
 */
uint32_t soc_mem_type(sc_dsc_t dsc, uint32_t pd);

/*!
 * This function returns the uniquely defined memory power plane 
 * for the given dsc id
 *
 * @param[in]     dsc_id          DSC to check
 *
 * @return      memory plane for the dsc_id
 */
uint8_t soc_mem_pwr_plane(sc_dsc_t dsc_id);

/*!
 * This function returns the change state of a resource during reboot.
 *
 * @param[in]     idx             idx to check
 *
 * @return      SC_TRUE if not to be reset
 */
sc_bool_t soc_reboot_no_reset(sc_rm_idx_t idx);

/*!
 * Return the DSCMIX clock slice index and type.
 *
 * @param[out]       clk_type          DSC clock slice type
 * @param[out]       idx               DSC clock slice index
 * @param[out]       parent            DSC clock slice parent
 */
void soc_dsc_clock_info(dsc_clk_type_t *clk_type, uint32_t *idx,
    sc_pm_clk_parent_t *parent);

/*!
 * Return HW limited clock dividers.
 *
 * @param[in]        dsc           DSC to affect
 * @param[in]        clkinfo       Pointer to clock whose info is requested
 * @param[out]       pll_div       Pll divided output
 *
 * @return      DSCMIX clock slice divider
 */
uint32_t soc_get_clock_div(sc_dsc_t dsc, const dsc_clk_info_t *clkinfo, uint8_t *pll_div);

/*!
 * Checks if the given clock slice is the DSCMIX slice.
 *
 * @param[in]        clk_info      pointer to the clock data structure
 *
 * @return  SC_TRUE if the slice is a DSCMIX slice
 */
sc_bool_t soc_slice_is_dsc(const dsc_clk_info_t *clk_info);

#ifdef USE_AVPLL_FOR_DC
/*!
 * This function returns parameters required to setup the AVPLLs used by
 * DC subsystem.
 *
 * @param[in]        pll_rsrc     DC PLL resource ID
 * @param[out]       ai_toggle    AI toggle to which the replacement AVPLL
 *                                  is connected
 * @param[out]       ssc_enable   SC_TRUE if spread spectrum should be
 *                                  enabled for the PLL
 *
 * @return  DSC_ID of the subsystem in which the AVPLLs reside
 */
sc_dsc_t soc_get_dc_avpll_info(sc_rsrc_t pll_rsrc, uint8_t *ai_toggle,
    sc_bool_t *ssc_enable);
#endif

/*!
 * This function returns spread spectrum info required to setup the AVPLL
 *
 * @param[in]        dsc        dsc to affect
 * @param[in]        pll_index  PLL index to affect
 *
 * @return           Spread spectrum PPM for the PLL
 */
uint8_t soc_get_avpll_ssc_n(sc_dsc_t dsc, uint8_t pll_index);

/*!
 * This function checks if the GPU frequency is HW limited based on fuses.
 *
 * @return  SC_TRUE if the frequency is HW limited
 */
sc_bool_t soc_gpu_freq_hw_limited(void);

/*!
 * Calculate and return the ROM patch checksum.
 *
 * @param[out]       checksum          pointer to return checksum
 * @param[in]        len               length of fuse area to sum
 */
void soc_rompatch_checksum(uint32_t *checksum, uint16_t len);

#ifdef ROM_PATCH_HEADER
/*!
 * Return info for the first ROM patch.
 *
 * @param[in]        id               ID of patches to find
 * @param[out]       desc             pointer to return patch descriptor
 * @param[out]       len              pointer to return patch length
 * @param[out]       type             pointer to return patch type
 * @param[out]       checksum         pointer to return patch checksum
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NONE patch found,
 * - SC_ERR_NOTFOUND if no patch found
 */
sc_err_t soc_patch_info_1(uint8_t id, uint8_t *desc, uint8_t *len,
    uint8_t *type, uint32_t *checksum);

/*!
 * Return info for the next ROM patch.
 *
 * @param[in]        id               ID of patches to find
 * @param[out]       desc             pointer to return patch descriptor
 * @param[out]       len              pointer to return patch length
 * @param[out]       type             pointer to return patch type
 * @param[out]       checksum         pointer to return patch checksum
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NONE patch found,
 * - SC_ERR_NOTFOUND if no additional patch found
 */
sc_err_t soc_patch_info_n(uint8_t id, uint8_t *desc, uint8_t *len,
    uint8_t *type, uint32_t *checksum);
#endif

/** @} */

/*!
 * @name Analog Functions
 * @{
 */

/*!
 * Enable/Disable anamix in some SS during init and low power mode.
 */
void soc_setup_anamix(sc_bool_t enable);

/*!
 * This function powers up the DSC anamix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerup_anamix(sc_dsc_t dsc);

/*!
 * This function powers up the DSC phymix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerup_phymix(sc_dsc_t dsc);

/*!
 * This function powers down the DSC anamix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerdown_anamix(sc_dsc_t dsc);

/*!
 * This function powers down the DSC phymix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerdown_phymix(sc_dsc_t dsc);

/*!
 * Setup HSIO repeaters for internal or external PCIE clock
 *
 * @param[in]     internal_clk      SC_TRUE if using internal clock
 * @param[in]     enable            SC_TRUE if powering up SS
 */
void soc_setup_hsio_repeater(board_parm_rtn_t internal_clk, sc_bool_t enable);

/*!
 * Setup the Forward body-bias for the given subsystem
 *
 * @param[in]   ss          Subsystem to affect
 * @param[in]   bias_mask   IP within SS to enable/disable
 * @param[in]   enable      SC_TRUE if enabling forward body-bias
 * @param[in]   delay       time to wait when disabling forward body-bias
 */
void soc_set_bias(sc_sub_t ss, uint8_t bias_mask, sc_bool_t enable,
    uint32_t delay);

/*!
 * Return the DPLL DCO-P trim value
 *
 * @param[in]   dsc         Subsystem to affect
 * @param[in]   pll_index   PLL index within the SS
 * @param[in]   rate        PLL lock rate
 *
 * @return    DCO-PC trim value (default if fuse is 0)
 */
uint32_t soc_dpll_dco_pc(sc_dsc_t dsc, uint8_t pll_index, uint32_t rate);

/*!
 * Populate the DPLL DCO-PC values based on fuses
 */
void soc_dpll_populate_tbl(void);

/** @} */

/*!
 * @name Power Functions
 * @{
 */

/*!
 * Set the voltage based on the frequency for SS controlled by
 * PMIC rail.
 *
 * @param[in]       ss            Subsystem to affect
 * @param[in]       old_freq      Freq associated with current voltage
 * @param[in]       new_freq      Freq associated with new voltage
 * @param[in]       pmic_change   SC_TRUE is pmic voltage should be changed
 *
 * @return      SC_ERR_NONE on successful voltage change else error code
 */
sc_err_t soc_set_freq_voltage(sc_sub_t ss, uint32_t old_freq,
    uint32_t *new_freq, sc_bool_t pmic_change);

/*!
 * Handle SoC and board level power transitions required to power up
 * or down a power domain.
 *
 * @param[in]    ss         Subsystem to affect
 * @param[in]    pd         Power domain within the SS transitioning
 * @param[in]    from_mode  Current power mode of the pd
 * @param[in]    to_mode    New power mode of the pd
 */
void soc_trans_pd(sc_sub_t ss, uint8_t pd,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);

/*!
 * Check if the Forward body bias is enabled for the cluster, this
 * function is only valid for the AP clusters.
 *
 * @param[in]    ss         Subsystem to affect
 *
 * @return      SC_TRUE if forward body-bias is enabled.
 */
sc_bool_t soc_bias_enabled(sc_sub_t ss);


/*!
 * Check if the new PLL rate is below the max freq vd-detect in the SS 
 * can support.
 * 
 * @param[in]    dsc        DSC of subsystem to affect
 * @param[in]    rate       New pll rate
 *
 * @return      SC_TRUE if new pll rate is below the max vd-detect frequency
 */
sc_bool_t soc_ss_has_vd_detect(sc_dsc_t dsc,  sc_pm_clock_rate_t rate);

/*!
 * Transition internal SOC level bandgap
 *
 * @param[in]   ss          Subsystem to affect
 * @param[in]   rsrc_idx    Resource to affect
 * @param[in]   from_mode   Current power mode of the resource
 * @param[in]   to_mode     New power mode of the resource.
 */
void soc_trans_bandgap(sc_sub_t ss, sc_rsrc_t rsrc_idx,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);

void soc_fabric_force_on(sc_sub_t ss, sc_bool_t enb);
void soc_post_ss_reset(sc_dsc_t dsc, DSC_Type *dsc_base);
void soc_gicr_quiesce(uint8_t cluster_idx, uint32_t cpu_idx);
void soc_pause_ddr_traffic(sc_bool_t pause);
sc_bool_t soc_cluster_link_off(sc_rsrc_t resource, sc_rm_pt_t pt);

/*!
 * Check if the FlexSPI0 module is accessible.
 *
 * @return      SC_ERR_NONE if FlexSPI0 is accessible
 */
sc_err_t soc_fspi0_accessible(void);

/** @} */

/*!
 * @name HPM Functions
 * @{
 */

void soc_init_hmp(boot_phase_t phase);
sc_err_t soc_set_cpu_resume(uint8_t cluster_idx, uint8_t cpu_idx,
    sc_bool_t isPrimary, sc_faddr_t resume_addr);
sc_err_t soc_set_mcu_resume(uint8_t mcu_idx,sc_faddr_t resume_addr);
sc_err_t soc_set_multicluster_power_mode(sc_pm_power_mode_t mode);
sc_err_t soc_set_cluster_power_mode(uint8_t cluster_idx,
    sc_pm_power_mode_t mode);
sc_err_t soc_set_cpu_power_mode(uint8_t cluster_idx, uint8_t cpu_idx,
    sc_pm_power_mode_t mode, sc_pm_wake_src_t wake_src);
void soc_set_cpu_rst_mode(uint8_t cluster_idx, uint8_t cpu_idx,
    sc_bool_t rst);
void soc_set_mcu_sleep_mode(uint8_t mcu_idx, sc_bool_t dsm,
    uint8_t stopm, uint8_t pstopo);
sc_bool_t soc_get_mcu_sleep_mode_active(uint8_t mcu_idx);
void soc_set_mcu_rst_mode(uint8_t mcu_idx, sc_bool_t rst);
sc_err_t soc_req_sys_if_power_mode(uint8_t hmp_idx, sc_pm_sys_if_t sys_if,
    sc_pm_power_mode_t hpm, sc_pm_power_mode_t lpm);
void soc_trans_sys_if_hpm(uint8_t hmp_idx);
void soc_trans_sys_if_lpm(void);
void soc_sync_sys_if_pm(void);
void soc_trans_cpu_power_mode(uint8_t cluster_idx, uint8_t cpu_idx);
void soc_trans_mcu_power_mode(uint8_t mcu_idx);
void soc_prewake_cpu(void);
void soc_wake_cpu(uint8_t cluster_idx, uint8_t cpu_idx);
void soc_wake_mcu(uint8_t mcu_idx);
void soc_wake_lsio_mu(void);
void soc_wake_mcu_mu(uint8_t mcu_idx);
void soc_wake_sys_if_interconnect(void);
sc_pm_power_mode_t soc_get_hmp_sys_power_mode(void);
void soc_dump_hmp_power_state(void);
sc_bool_t soc_can_hmp_enter_lpm(void);
void soc_update_hmp_sys_power_mode(void);
void soc_update_hmp_boot_mem(void);

/** @} */

/*!
 * @name Auxiliary Core Functions
 * @{
 */

#if defined(SOC_NUM_AUX) && (SOC_NUM_AUX >= 1)
/*!
 * Get firmware address for auxiliary core
 *
 * @param[in]   aux_idx     Auxiliary core index
 * @param[out]  fw_addr     Firmware address
 *
 * @return      SC_ERR_NONE if firmware address could be retrieved.
 */
sc_err_t soc_aux_get_fw_addr(uint8_t aux_idx, sc_saddr_t *fw_addr);

/*!
 * This function enables the system interfaces needed to load an auxiliary
 * core firmware image.
 *
 * @param[in]   aux_idx     Auxiliary core index
 * @param[in]   fw_addr     Address of FW image
 *
 * @return      SC_ERR_NONE if successful.
 */
sc_err_t soc_aux_enable_fw_load(uint8_t aux_idx, sc_faddr_t fw_addr);

/*!
 * This function disables the system interfaces needed to load an auxiliary
 * core firmware image.
 *
 * @param[in]   aux_idx     Auxiliary core index
 */
void soc_aux_disable_fw_load(uint8_t aux_idx);

/*!
 * This function checks if auxiliary core firmware load is in progress.
 *
 * @param[in]   aux_idx     Auxiliary core index
 *
 * @return      SC_TRUE if firmware load is in progress.
 */
sc_bool_t soc_aux_check_fw_load(uint8_t aux_idx);

/*!
 * This function retrieves the system interface associated with the
 * subsystem that contains the auxiliary core firmware.
 *
 * @param[in]   ss          Subsystem containing the firmware
 * @param[out]  sys_if      System interface containing the firmware
 *
 * @return      SC_ERR_NONE if mapping to system interface is found.
 */
sc_err_t soc_aux_get_fw_sys_if(sc_sub_t ss, sc_pm_sys_if_t *sys_if);
#endif

/** @} */

/*!
 * @name DDR Functions
 * @{
 */

/*!
 * This function initializes DDR.
 *
 * @param[in]     early       boolean for early init
 *
 * @return Returns the sc_err_t.
 *
 */
sc_err_t soc_init_ddr(sc_bool_t early);

/*!
 * This function places the DDR in SRPD (self-refresh power down) and
 * disables DDR clocks.
 */
void soc_self_refresh_power_down_clk_disable_entry(void);

/*!
 * This function enables DDR clocks and exits the DDR from SRPD (self-refresh 
 * power down).
 */
void soc_refresh_power_down_clk_disable_exit(void);

/*!
 * This function configures parameters for DDR low-power retention (SRPD with
 * DRC powered down).
 *
 * @param[in]       ddr_ret_info        pointer to retention info struct
 */
void soc_ddr_config_retention(soc_ddr_ret_info_t *ddr_ret_info);

/*!
 * This function places the DDR into low-power retention (SRPD with
 * DRC powered down).
 */
void soc_ddr_enter_retention(void);

/*!
 * This function exits the DDR from low-power retention (SRPD with
 * DRC powered down).
 */
void soc_ddr_exit_retention(void);

/*!
 * This function initializes LPDDR4 DQS2DQ training.
 */
void soc_ddr_dqs2dq_init(void);

/*!
 * This function does DDR bit deskew training.
 */
void soc_ddr_bit_deskew(void);

/*!
 * This function invokes LPDDR4 DQS2DQ periodic training.
 */
void soc_ddr_dqs2dq_periodic(void);

#ifdef SWI_DQS2DQ_IRQn
/*!
 * This function configures parameters of LPDDR4 DQS2DQ periodic training.
 *
 * @param[in]       dqs2dq_sync_info    pointer to DQS2DQ info struct
 */
void soc_ddr_dqs2dq_config(soc_dqs2dq_sync_info_t *dqs2dq_sync_info);

/*!
 * This function sychronizes LPDDR4 DQS2DQ periodic training to 
 * DDR traffic events (i.e. ISI frame completion).
 */
void soc_ddr_dqs2dq_sync(void);
#endif

/*!
 * This function enables DDR LPCG clock gating.
 */
void soc_drc_lpcg_setup(void);

/** @} */

/*!
 * @name Misc Functions
 * @{
 */

/*!
 * This function ticks the temp sensor processing.
 *
 * @param[in]     msec        milliseconds that have expired
 */
void soc_temp_sensor_tick(uint16_t msec);

void soc_setup_msi_slave_ring(sc_sub_t cur_ss, sc_sub_t parent,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);
void soc_msi_ring_workaround(sc_pm_power_mode_t from_mode,
    sc_pm_power_mode_t to_mode, soc_msi_ring_usecount_t *msi_slv_ring,
    uint32_t num_msi_slaves, MSI_MSTR_Type *msi_reg, sc_sub_t cur_ss);

#ifdef ERR050601_WORKAROUND
void soc_block_ap_set(sc_rm_pt_t pt, sc_rsrc_t resource);
void soc_block_ap_memreg(sc_rm_mr_t mr, sc_rm_perm_t *perms);
#endif

/** @} */

/*!
 * @name Debug Functions
 * @{
 */

/*!
 * Dumps registers of single analog module.
 *
 * @param[in]     dsc         DSC to dump
 * @param[in]     tog         toggle to dump
 * @param[in]     ai          AI type
 */
void soc_dsc_ai_dumpmodule(sc_dsc_t dsc, uint8_t tog, sc_ai_t ai);

/*!
 * Dumps registers of analog modules in a subsystem.
 *
 * @param[in]     dsc         DSC to dump
 */
void soc_dsc_ai_dump(sc_dsc_t dsc);

/*!
 * Allows for muxing out analog clocks and voltage levels.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_anamix_test_out(sc_dsc_t dsc);

/** @} */

#ifdef SOC_SELFHOSTED_DEBUG
soc_dbgapb_cluster_info_t *soc_dbgapb_get_cluster_info(sc_rsrc_t cpu_rsrc);
soc_dbgapb_cluster_info_t *soc_dbgapb_get_indexed_cluster_info(uint8_t idx);
soc_dbgapb_cpu_info_t *soc_dbgapb_get_cpu_info(sc_rsrc_t cpu_rsrc);

sc_bool_t soc_dbgapb_halt(void);
sc_bool_t soc_dbgapb_get_reg(sc_rsrc_t cpu_rsrc, uint8_t reg_idx, 
    uint32_t *reg_upper, uint32_t *reg_lower);
sc_bool_t soc_dbgapb_get_L1line(sc_rsrc_t cpu_rsrc, sc_bool_t dcache,
    uint8_t way, uint16_t set,uint32_t *tag_upper,uint32_t *tag_lower,
    uint32_t line[ ], uint32_t num_words);
#endif

/*!
 * Tune the RC-OSC to the requested frequency
 *
 * @param[in]   dsc         DSC in which the RC-OSC resides
 * @param[in]   freq_mhz    frequency to tune (normally 200Mhz)
 */
void soc_rc200_tune(sc_dsc_t dsc, uint32_t freq_mhz);

/*!
 * Retune the 24MHz Osc with the new CL_TUNE value.
 * @param[in]   cl_tune   new capacitor value
 */
void soc_XtalCL_Tune(uint32_t cl_tune);

/*!
 * Check if a resource is an AP (workaround for ERR050812)
 *
 * @param[in]   rsrc        resource to check
 *
 * @return Returns SC_TRUE if the resource is an AP.
 */
sc_bool_t soc_rsrc_is_ap(sc_rsrc_t rsrc);

/*!
 * Check if a DSC has a timestamp (workaround for ERR050812)
 *
 * @param[in]   dsc         DSC to check
 * @param[in]   clk_index   pointer to return clock index
 *
 * @return Returns SC_TRUE if has a timestamp.
 */
sc_bool_t soc_ss_has_timestamp(sc_dsc_t dsc, ss_clock_t *clk_index);

#endif /* SC_SOC_API_H */

/** @} */

