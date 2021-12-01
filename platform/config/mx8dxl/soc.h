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
 * Header file used to configure SoC specific features of the SCFW.
 * Includes info on memory map, DSC mapping, subsystem mapping, etc.
 *
 */
/*==========================================================================*/

#ifndef SC_SOC_H
#define SC_SOC_H

/* Includes */
#include "main/types.h"
#include "has_ss.h"
#include "fsl_device_registers.h"
#include "ss/drc/v3/dsc.h"

/* Configure DSCs */

/*! Macro to calculate DSC index */
#define DSC_IDX(X) ((sc_dsc_t) ((((uint32_t) (X)) - ((uint32_t) MSI0_BASE)) / 131072U))

/*! Macro to define AI_READ/WRITE */
#define ANA_READ(BASE_IDX, TOG, ADDRESS, RDATA) DSC_AIRegisterRead(BASE_IDX, TOG, ADDRESS, RDATA)
#define ANA_WRITE(BASE_IDX, TOG, ADDRESS, DATAWORD) DSC_AIRegisterWrite(BASE_IDX, TOG, ADDRESS, DATAWORD)
#define ANA_ENABLE_ANAMIX_AI(BASE_IDX) DSC_EnableAnamixAI(BASE_IDX)
#define ANA_ENABLE_PHYMIX_AI(BASE_IDX) DSC_EnablePhymixAI(BASE_IDX)

/*! Define for Refgen default trim in case of unfused part */
#define REFGEN_DEFAULT_TRIM     0x2BU

/*!
 * @name Defines for sc_dsc_t
 */
/** @{ */
#define SC_DSC_SC        	DSC_IDX(DSC_SC)      /* 0x01 */
#define SC_DSC_ADMA		 	DSC_IDX(DSC_ADMA)    /* 0x13 */
#define SC_DSC_MCU_0     	DSC_IDX(DSC_MCU_0)   /* 0x16 */
#define SC_DSC_CONN		 	DSC_IDX(DSC_CONN)    /* 0x19 */
#define SC_DSC_DRC_0	 	DSC_IDX(DSC_DRC_0)   /* 0x24 */
#define SC_DSC_HSIO		 	DSC_IDX(DSC_HSIO)    /* 0x26 */
#define SC_DSC_DB		 	DSC_IDX(DSC_DB)      /* 0x32 */
#define SC_DSC_AP_2		 	DSC_IDX(DSC_AP_2)    /* 0x35 */
#define SC_DSC_LSIO		 	DSC_IDX(DSC_LSIO)    /* 0x38 */
#define SC_DSC_LAST      	0x3FU
#define SC_DSC_DRC_1      	0x3FU
#define SC_DSC_NA           SC_DSC_LAST
#define SC_DSC_W            6U
/** @} */

/*!
 * DSC Type. This type is a used to indicate a Distributed Slave
 * Controller (DSC).
 */
typedef uint8_t sc_dsc_t;

/*!
 * @name Defines for sc_ai_t
 */
/** @{ */
#define SC_AI_HP_PLL            0U
#define SC_AI_DIG_PLL           1U
#define SC_AI_AV_PLL            2U
#define SC_AI_LVDS_TRANS        3U
#define SC_AI_BANDGAP_REF       4U
#define SC_AI_VA_REFGEN         5U
#define SC_AI_NEG_CHARGE_PUMP   6U
#define SC_AI_WELL_LEVEL_SOURCE 7U
#define SC_AI_DIFFCLK_ROOT      8U
#define SC_AI_DIFFCLK_RPTR      9U
#define SC_AI_DIFFCLK_TERM      10U
#define SC_AI_PHY_LDO           11U
#define SC_AI_OSC24M            12U
#define SC_AI_RC200OSC          13U
#define SC_AI_TEMP_SENSE        14U
#define SC_AI_VDROP_PROCMON     15U
#define SC_AI_LAST              16U
/** @} */

/*!
 * Analog Interface Modules Types.
 */
typedef uint8_t sc_ai_t;

/* Configure Subsystems */

typedef uint8_t sc_ss_inst_t;

#define SC_SS_INST_W        1U

/*!
 * @name Defines for sc_sub_t
 */
/** @{ */
#define SC_SUBSYS_SC        0U
#define SC_SUBSYS_MCU_0     1U
#define SC_SUBSYS_A35       2U
#define SC_SUBSYS_ADMA      3U
#define SC_SUBSYS_CONN      4U
#define SC_SUBSYS_DB        5U
#define SC_SUBSYS_DRC_0     6U
#define SC_SUBSYS_LSIO      7U
#define SC_SUBSYS_HSIO      8U
#define SC_SUBSYS_LAST      SC_SUBSYS_HSIO
#define SC_SUBSYS_W         4U
#define SC_SUBSYS_NA        15U
/** @} */

/*!
 * Subsystem Type. This type is used to indicate a subsystem.
 */
typedef uint8_t sc_sub_t;

#define SC_PGP_00           0U
#define SC_PGP_01           1U
#define SC_PGP_02           2U
#define SC_PGP_03           3U
#define SC_PGP_04           4U
#define SC_PGP_05           5U
#define SC_PGP_06           6U

#define SC_PGP_W            3U
#define SC_PGP_NA           7U

#define  MTR_PWR_PLAN_SEL_SCU0                  0U
#define  MTR_PWR_PLAN_SEL_DB                    1U
#define  MTR_PWR_PLAN_SEL_HSIO                  2U
#define  MTR_PWR_PLAN_SEL_MCU_0                 3U
#define  MTR_PWR_PLAN_SEL_LSIO                  4U
#define  MTR_PWR_PLAN_SEL_CA35                  6U
#define  MTR_PWR_PLAN_SEL_CONNECTIVITY          7U
#define  MTR_PWR_PLAN_SEL_DRC_0                 9U
#define  MTR_PWR_PLAN_SEL_ADMA                  13U

#define SC_SS_INFO_INIT                                                                                 \
    {HAS_SS_SC,      0, SC_PGP_00,   SC_SUBSYS_NA,  0,  0, SC_DSC_SC},          /* SC_SUBSYS_SC */      \
    {HAS_SS_MCU_0,   0, SC_PGP_01,   SC_SUBSYS_NA,  0,  0, SC_DSC_MCU_0},       /* SC_SUBSYS_MCU_0 */   \
    {HAS_SS_AP_2,    0, SC_PGP_06,   SC_SUBSYS_NA,  0,  0, SC_DSC_AP_2},        /* SC_SUBSYS_A35 */     \
    {HAS_SS_ADMA,    0, SC_PGP_02,   SC_SUBSYS_NA,  0,  0, SC_DSC_ADMA},        /* SC_SUBSYS_ADMA */    \
    {HAS_SS_CONN,    0, SC_PGP_03,   SC_SUBSYS_NA,  0,  0, SC_DSC_CONN},        /* SC_SUBSYS_CONN */    \
    {HAS_SS_DB,      0, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DB},          /* SC_SUBSYS_DB */      \
    {HAS_SS_DRC_0,   0, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DRC_0},       /* SC_SUBSYS_DRC_0 */   \
    {HAS_SS_LSIO,    0, SC_PGP_05,   SC_SUBSYS_NA,  0,  0, SC_DSC_LSIO},        /* SC_SUBSYS_LSIO */    \
    {HAS_SS_HSIO_0,  0, SC_PGP_04,   SC_SUBSYS_NA,  0,  0, SC_DSC_HSIO}         /* SC_SUBSYS_HSIO */

/*! Number of DB */
#define SC_NUM_DB           1U

/*!
 * DB Connect Type. Stores a subsystem connection mask.
 */
typedef uint32_t sc_db_connect_t;

/*! DB connect mask */
#define SC_DB_CONNECT       \
    ( BIT(SC_SUBSYS_SC)     \
    | BIT(SC_SUBSYS_MCU_0)  \
    | BIT(SC_SUBSYS_A35)    \
    | BIT(SC_SUBSYS_ADMA)   \
    | BIT(SC_SUBSYS_CONN)   \
    | BIT(SC_SUBSYS_DRC_0)  \
    | BIT(SC_SUBSYS_LSIO)   \
    | BIT(SC_SUBSYS_HSIO))

/*! Init order of DB (SCU outward) */
#define SC_DB_INIT \
    {SC_R_DB, SC_SUBSYS_DB, SC_DB_CONNECT}

#define SC_SS_EP_INIT                             \
    SS_EP_INIT_SC,        /* SC_SUBSYS_SC */      \
    SS_EP_INIT_M4,        /* SC_SUBSYS_MCU_0 */   \
    SS_EP_INIT_A35,       /* SC_SUBSYS_A35 */     \
    SS_EP_INIT_ADMA,      /* SC_SUBSYS_ADMA */    \
    SS_EP_INIT_CONN,      /* SC_SUBSYS_CONN */    \
    SS_EP_INIT_DB,        /* SC_SUBSYS_DB */      \
    SS_EP_INIT_DRC,       /* SC_SUBSYS_DRC_0 */   \
    SS_EP_INIT_LSIO,      /* SC_SUBSYS_LSIO */    \
    SS_EP_INIT_HSIO       /* SC_SUBSYS_HSIO */

#define SC_SS_BASE_INFO_INIT                        \
    &ss_base_info_sc,       /* SC_SUBSYS_SC */      \
    &ss_base_info_m4,       /* SC_SUBSYS_MCU_0 */   \
    &ss_base_info_a35,      /* SC_SUBSYS_A35 */     \
    &ss_base_info_adma,     /* SC_SUBSYS_ADMA */    \
    &ss_base_info_conn,     /* SC_SUBSYS_CONN */    \
    &ss_base_info_db,       /* SC_SUBSYS_DB */      \
    &ss_base_info_drc,      /* SC_SUBSYS_DRC_0 */   \
    &ss_base_info_lsio,     /* SC_SUBSYS_LSIO */    \
    &ss_base_info_hsio      /* SC_SUBSYS_HSIO */

#ifdef DEBUG
    #define SNAME_INIT  \
        "SC",           \
        "M4_0",         \
        "A35",          \
        "ADMA",         \
        "CONN",         \
        "DB",           \
        "DRC_0",        \
        "LSIO",         \
        "HSIO"

    #define RNAME_INIT          \
        RNAME_INIT_SC_0         \
        RNAME_INIT_M4_0         \
        RNAME_INIT_A35_0        \
        RNAME_INIT_ADMA_0       \
        RNAME_INIT_CONN_0       \
        RNAME_INIT_DB_0         \
        RNAME_INIT_DRC_0        \
        RNAME_INIT_LSIO_0       \
        RNAME_INIT_HSIO_0       \
        RNAME_INIT_BRD

#endif

#define SC_R_DDR        SC_R_DRC_0
#define SC_R_DDR_PLL    SC_R_DRC_0_PLL

/*! Chip versions */
#define CHIP_VER_A0     0x0U
#define CHIP_VER_A1     0x1U
#define CHIP_VER_B0     0x2U

/*! Macro to get JTAG ID */
#ifndef SIMU
    #define JTAG_ID     (DSC_SC->GPR_STAT[2].RW & 0x1FFU)
#else
    #ifdef SREV_A0
        #define JTAG_ID ((CHIP_VER_A0 << 5U) | CHIP_ID_DXL)
    #endif
    #ifdef SREV_A1
        #define JTAG_ID ((CHIP_VER_A1 << 5U) | CHIP_ID_DXL)
    #endif
    #ifdef SREV_B0
        #define JTAG_ID ((CHIP_VER_B0 << 5U) | CHIP_ID_DXL)
    #endif
#endif

/*! Macros to get chip ID and version */
#define CHIP_ID         ((JTAG_ID >> 0U) & 0x1FU)
#define CHIP_VER        ((JTAG_ID >> 5U) & 0xFU)

/* Configure Top Level Memory Map */

#define SC_MEMMAP_INIT                                                          \
    {  LSIO_SS_BASE1,    0x1C000000U, 1, 1, 30, 1, 0x00, SC_SUBSYS_LSIO},       \
    {   SCU_SS_BASE0,     0x4000000U, 0, 1, 26, 0, 0x00, SC_SUBSYS_SC},         \
    { MCU_0_SS_BASE0,     0x4000000U, 1, 1, 26, 0, 0x00, SC_SUBSYS_MCU_0},      \
    {HSIO_0_SS_BASE2,    0x10000000U, 1, 1, 28, 2, 0x00, SC_SUBSYS_HSIO},       \
    {      DDR_BASE0,    0x80000000U, 1, 0,  0, 0, 0x00, SC_SUBSYS_DB},         \
    {      DDR_BASE1, 0x780000000ULL, 1, 0,  0, 0, 0x00, SC_SUBSYS_DB},         \
    {          SC_NA,          SC_NA, 0, 0,  0, 0,    0, 0}

#define SC_BOOT_ADDR_INIT                                                      \
    {OCRAM_ALIAS_BASE,       0x17FFFU, SC_R_OCRAM,      SC_SUBSYS_LSIO},       \
    {      OCRAM_BASE,       0x3FFFFU, SC_R_OCRAM,      SC_SUBSYS_LSIO},       \
    {  FSPI0_MEM_BASE,    0x10000000U, SC_R_FSPI_0,     SC_SUBSYS_LSIO},       \
    {      TCML_MCU_0,     0x4000000U, SC_R_MCU_0_PID0, SC_SUBSYS_MCU_0},      \
    {       DDR_BASE0,    0x80000000U, SC_R_DRC_0,      SC_SUBSYS_DRC_0},      \
    {       DDR_BASE1, 0x780000000ULL, SC_R_DRC_0,      SC_SUBSYS_DRC_0},      \
    {           SC_NA,          SC_NA, 0U,              0U}

/* Configure Features */

/* Configure RM */
#define SC_RM_NUM_PARTITION     20U     //!< Number of resource partitions
#define SC_RM_NUM_MEMREG        64U     //!< Number of memory regions
#define SC_RM_NUM_DOMAIN        16U     //!< Number of resource domains

/*! PLL frequencies */
#define MIN_PLL_RATE            648000000U
#define MAX_PLL_RATE            1344000000U
#define MIN_HP_PLL_RATE         1250000000U
#define MAX_HP_PLL_RATE         2500000000U
#define MIN_HP_PLL_1P5_RATE     833333333U
#define PLL_RATE_DEN            960000U
#define DIV_FACTOR_NUM          2U
#define DIV_FACTOR_DEN          3U

/*!
 * Define operating points for A35.
 */
#define NUM_A35_OPP             1

/*! Has 28FDSOI in SCFW API */
#define API_HAS_28FDSOI

/*! Has V2X in SCFW API */
#define API_HAS_V2X

/*! Has V2X in DB */
#define V2X_IN_DB

/*! Requires V2X FW copy from FlexSPI */
#define FLEXSPI_V2X_ADDR        0x1400UL
#define FLEXSPI_DUMMY_ADDR      0x1800UL

/*! Support partitioning naming for debug */
#define HAS_PARTITION_NAMES

/*! Enhanced monitor support */
#define MONITOR_HAS_CMD_OFF
#define MONITOR_HAS_CMD_MSG
#define MONITOR_HAS_CMD_VDETECT
#define MONITOR_HAS_CMD_WDOG
#define MONITOR_HAS_CMD_PANIC
#define MONITOR_HAS_CMD_MRC
#define MONITOR_HAS_CMD_BOOT
#define MONITOR_HAS_CMD_WAKE
#define MONITOR_HAS_CMD_GRANT
#define MONITOR_HAS_CMD_LOG

/*! Define to use SECO FW */
#define HAS_SECO_FW

/*! Defines for FW versions */
#define SECO_FW_VERSION ((3UL << 16) | (8UL << 4) | 2UL) 
#define V2X_FW_VERSION ((1UL << 16) | (1UL << 4) | 1UL) 

/*! Define DDR DATX8 Lanes */
#define DWC_NO_OF_BYTES	        2U

/*! Defines for AI temp sensor */
#define FUSE_TEMP_AUTO          0x0
#define FUSE_TEMP_INDUSL        0x1
#define FUSE_TEMP_CONS          0x2
#define FUSE_TEMP_EX_CONS       0x3
#define AI_TEMP_RATE            1000U
#define AI_TEMP_NP              1915
#define AI_TEMP_NT              25
#define AI_TEMP_PANIC           127
#define AI_TEMP_PANIC_AUTO      127
#define AI_TEMP_PANIC_INDUS     107
#define AI_TEMP_PANIC_CONS      97
#define AI_TEMP_PANIC_EX_CONS   107

/*! Define to indicate timer services required */
#define HAS_TIMER_SERVICES

/*! Number of boot images supported by ROM */
#define SC_BOOT_MAX_LIST        8U

/* Define boot cpu and address based on whether or
   not we're running the DDR stress test */
#ifdef M4_BOOT
    #define BOOT_CPU            SC_R_MCU_0_PID0
    #define BOOT_ADDR           0x000000000ULL
    #define BOOT_MU             SC_R_MCU_0_MU_1A
    #define BOOT_CPU_STARTS     1U
    #define BOOT_SRC            0x00040000U
    #define BOOT_DST            0x34FE0000U
    #define BOOT_SIZE           0x20000U
    #define BOOT_FLAGS          0x00000000U
#elif defined(TEST_BOOTTIME)
    #define BOOT_CPU            SC_R_MCU_0_PID0
    #define BOOT_ADDR           0x000000000ULL
    #define BOOT_MU             SC_R_MCU_0_MU_1A
    #define BOOT_CPU_STARTS     1U
    #define BOOT_FLAGS          0x00400000U
#else
    #define BOOT_CPU            SC_R_AP_2_0
    #define BOOT_ADDR           0x080000000UL
    #define BOOT_MU             SC_R_MU_0A
    #define BOOT_CPU_STARTS     1U
    #define BOOT_FLAGS          0x00000000U
#endif

/* Boot data address */
#define SC_BOOT_DATA_ADDR_PTR   0x000005F0U
#define SC_BOOT_DATA_ADDR       0x2001FC00U
#define SC_BOOT_DATA2_ADDR      0x2001FD00U

/*! Rom uses patch headers */
#define ROM_PATCH_HEADER

/*! OTP patch areas */
#define SOC_PATCH_AREA_CNT      3U

/*! OTP patch area list */
#define SOC_PATCH_AREA_INIT                         \
    {OTP_ROM_PATCH, OTP_ROM_PATCH_SIZE},            \
    {OTP_SECO_PATCH2, OTP_SECO_PATCH2_SIZE},        \
    {OTP_SECO_PATCH, OTP_SECO_PATCH_SIZE}

/*! Rom boot device mappings */
/** @{ */
#define ROM_SDHC_0              SC_R_SDHC_0
#define ROM_SDHC_1              SC_R_SDHC_1
#define ROM_SDHC_2              SC_R_SDHC_2
#define ROM_FSPI_0              SC_R_FSPI_0
#define ROM_FSPI_1              SC_R_FSPI_1
#define ROM_USB_0               SC_R_USB_0
#define ROM_USB_1               SC_R_USB_0
#define ROM_USB_2               SC_R_USB_1
/** @} */

/* Configure Tests */
#define TEST_HSIO0_PCIE         SC_R_PCIE_B
#define TEST_HSIO0_SERDES       SC_R_SERDES_1
#define TEST_HSIO0_MATCH_0      SC_R_MATCH_0
#define SC_P_TEST_PAD           SC_P_UART1_RX
#define SC_P_TEST_PAD_COMP      SC_P_COMP_CTL_GPIO_3V3_USB3IO
#define TEST_LSIO               HAS_SS_LSIO
#define TEST_DMA                HAS_SS_ADMA
#define TEST_BOARD_ALT2         SC_FALSE

/* Max MRC regions */
#define SC_MAX_NUM_MEMREG   \
(                           \
      16U   /* DB */        \
    + 32U   /* HSIO */      \
    + 48U   /* LSIO */      \
    + 4U    /* MCU */       \
    + 4U    /* SC */        \
)

/*! Define to indicate number of CAAM job rings */
#define SC_CAAM_JR              4U

/*! Define to indicate number of MU */
#define SC_SECO_MU              4U

/*! Enable FAKE_TBU use by MCU */
#define SC_FAKE_TBU

/*! Disable AP access to LSIO memory for ERR050601 */
#define ERR050601_WORKAROUND

/* Configure Resources */
#define SC_NO_DTCP

/* Define CPU topology */
#define SOC_NUM_CLUSTER         1U
#define SOC_IDX_AP_2            0U
#define SOC_NUM_AP_2            2U
#define SOC_NUM_DIG_AUD_PLL     2U

/* Define MCU topology */
#define SOC_NUM_MCU             1U
#define SOC_IDX_MCU_0           0U

/* Define auxiliary processor topology */
#define SOC_NUM_AUX             1U
#define SOC_IDX_AUX_0           0U                  /* AUX_0 is mapped to V2X */

/* Define HMP topology */
#define SOC_NUM_HMP_NODES       4U
#define SOC_HMP_IDX_SCU         0U                  /* SCU must be index 0 */
#define SOC_HMP_IDX_MCU_0       1U                  /* MCU order must follow topology above */
#define SOC_HMP_IDX_AP_2        2U
#define SOC_HMP_IDX_AUX_0       3U
#define SOC_HMP_IDX_MCU         SOC_HMP_IDX_MCU_0
#define SOC_HMP_IDX_AP          SOC_HMP_IDX_AP_2
#define SOC_HMP_IDX_AUX         SOC_HMP_IDX_AUX_0

/* Define system-level interface topology */
#define SOC_NUM_SYS_IF          4U                  /* Number of system-level interfaces */
#define SOC_SYS_IF_MU_RSRC      5U                  /* Number of AP -> SCU message unit resources */
#define SOC_SYS_IF_ICN_RSRC     1U                  /* Number of interconnect resources */
#define SOC_SYS_IF_OCMEM_RSRC   3U                  /* Number of on-chip memory resources */
#define SOC_SYS_IF_DDR_RSRC     1U                  /* Number of DDR resources */
#define SOC_SYS_IF_CPU_HPM      SC_PM_PW_MODE_LP    /* CPU power mode threshold for HPM */

/* Define wakeup bindings */
#define SOC_GIC_DSC             SC_DSC_ADMA         /* DSC for GIC wakeups */
#define SOC_IRQSTEER_DSC        SC_DSC_ADMA         /* DSC for IRQSTEER wakeup */
#define SOC_GIC_WAKEUP00        REGBIT64(1, 0)      /* DSC IRQ for GIC wakeups */
#define SOC_IRQSTEER_AP_WAKEUP  REGBIT64(1, 11)     /* DSC IRQ for AP IRQSTEER wakeup */
#define SOC_IRQSTEER_MCU_WAKEUP REGBIT64(1, 9)      /* DSC IRQ for MCU IRQSTEER wakeup */
#define SOC_WAKEUP_PW_MODE      SC_PM_PW_MODE_STBY  /* CPU power mode limit for GIC wakeup */
#define SOC_RESUME_PW_MODE      SC_PM_PW_MODE_ON    /* CPU power mode for resume */
#define SOC_MCU_STOPM_PDN       3U                  /* STOPM >= 3 will power down MCU core */
#define SOC_MCU_STOPM_MEMSR     3U                  /* STOPM == 3 will retain memories */
#define SOC_SNVS_PWR_ON_WAKEUP  REGBIT64(1, 10)     /* DSC IRQ for SNVS_LP set_pwr_on_irq */

/* Define ADMA mbist */
#define SS_ADMA_BIST1 (((uint32_t)DSC_ADMA) + 0x8020U)
#define SS_ADMA_BIST1_START 230U
#define SS_ADMA_BIST1_END 233U

#define SS_ADMA_BIST3 (((uint32_t)DSC_ADMA) + 0x8040U)
#define SS_ADMA_BIST3_START 234U
#define SS_ADMA_BIST3_END 266U

/* Defines for DDR training */
#define DQS_TIMER_DURATION_512  1U    /* 512 * tCK = 2048 * (1/1200) = 1 us (round up) */
#define DQS_TIMER_DURATION_1008 1U    /* 1008 * tCK = 1008 * (1/1200) = 1 us (round up) */
#define DQS_TIMER_DURATION_2048 2U    /* 2048 * tCK = 2048 * (1/1200) = 2 us (round up) */
#define DQS_TIMER_DURATION_8192 7U    /* 8192 * tCK = 8192 * (1/1200) = 7 us (round up) */

/* Include SS configs */

#include "all_config.h"
#include "board/config.h"
#include "handlers_MX8DXL.h"            /* Device specific handlers */

/* Configure Resources */

#define SC_NUM_RSRC             \
     (SS_NUM_RSRC_SC            \
    + SS_NUM_RSRC_M4            \
    + SS_NUM_RSRC_A35           \
    + SS_NUM_RSRC_ADMA          \
    + SS_NUM_RSRC_CONN          \
    + SS_NUM_RSRC_DB            \
    + SS_NUM_RSRC_DRC           \
    + SS_NUM_RSRC_LSIO          \
    + SS_NUM_RSRC_HSIO          \
    + BRD_NUM_RSRC_BRD)

#define SC_PAD_INIT_INIT                        \
    {SC_P_USB_SS3_TC0,        4, 0},            \
    {SC_P_USB_SS3_TC1,        4, 0},            \
    {SC_P_USB_SS3_TC2,        4, 0},            \
    {SC_P_USB_SS3_TC3,        4, 0},            \
    {SC_P_USDHC1_RESET_B,     4, SC_R_SDHC_1},  \
    {SC_P_USDHC1_VSELECT,     4, SC_R_SDHC_1},  \
    {SC_P_USDHC1_WP,          4, SC_R_SDHC_1},  \
    {SC_P_USDHC1_CD_B,        4, SC_R_SDHC_1},  \
    {SC_P_MCLK_IN0,           4, 0},            \
    {SC_P_MCLK_OUT0,          4, 0},            \
    {SC_P_FLEXCAN0_RX,        4, SC_R_CAN_0},   \
    {SC_P_FLEXCAN0_TX,        4, SC_R_CAN_0},   \
    {SC_P_FLEXCAN1_RX,        4, SC_R_CAN_1},   \
    {SC_P_FLEXCAN1_TX,        4, SC_R_CAN_1},   \
    {0, 0, 0}

#define SC_ROM_SS_INIT              \
    0,      /* SC_SUBSYS_SC */      \
    1,      /* SC_SUBSYS_MCU_0 */   \
    2,      /* SC_SUBSYS_A35 */     \
    7,      /* SC_SUBSYS_ADMA */    \
    8,      /* SC_SUBSYS_CONN */    \
    9,      /* SC_SUBSYS_DB */      \
    10,     /* SC_SUBSYS_DRC_0 */   \
    11,     /* SC_SUBSYS_LSIO */    \
    12      /* SC_SUBSYS_HSIO */

#define DB_NIC0_AP_PORT_IDX 6

#endif /* SC_SOC_H */

