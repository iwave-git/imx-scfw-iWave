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
#include "ss/drc/v1/dsc.h"

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
#define SC_DSC_SC        	DSC_IDX(DSC_SC)         /* 0x01 */
#define SC_DSC_MCU_0     	DSC_IDX(DSC_MCU_0)      /* 0x11 */
#define	SC_DSC_DRC_0	 	DSC_IDX(DSC_DRC_0)      /* 0x12 */
#define	SC_DSC_DC_1		 	DSC_IDX(DSC_DC_1)       /* 0x13 */
#define	SC_DSC_MCU_1	 	DSC_IDX(DSC_MCU_1)      /* 0x14 */
#define	SC_DSC_GPU_1	 	DSC_IDX(DSC_GPU_1)      /* 0x15 */
#define	SC_DSC_CONN		 	DSC_IDX(DSC_CONN)       /* 0x16 */
#define	SC_DSC_VPU		 	DSC_IDX(DSC_VPU)        /* 0x17 */
#define	SC_DSC_CCI		 	DSC_IDX(DSC_CCI)        /* 0x19 */
#define	SC_DSC_AP_1		 	DSC_IDX(DSC_AP_1)       /* 0x21 */
#define	SC_DSC_DB		 	DSC_IDX(DSC_DB)         /* 0x22 */
#define	SC_DSC_AP_0		 	DSC_IDX(DSC_AP_0)       /* 0x23 */
#define	SC_DSC_HSIO		 	DSC_IDX(DSC_HSIO)       /* 0x24 */
#define	SC_DSC_LSIO		 	DSC_IDX(DSC_LSIO)       /* 0x25 */
#define	SC_DSC_GPU_0	 	DSC_IDX(DSC_GPU_0)      /* 0x26 */
#define	SC_DSC_DC_0		 	DSC_IDX(DSC_DC_0)       /* 0x27 */
#define	SC_DSC_DRC_1	 	DSC_IDX(DSC_DRC_1)      /* 0x28 */
#define	SC_DSC_DMA		 	DSC_IDX(DSC_DMA)        /* 0x29 */
#define	SC_DSC_DBLOG	 	DSC_IDX(DSC_DBLOG)      /* 0x31 */
#define	SC_DSC_IMG		 	DSC_IDX(DSC_IMG)        /* 0x32 */
#define	SC_DSC_AUDIO	 	DSC_IDX(DSC_AUDIO)      /* 0x33 */
#define	SC_DSC_DI_HDMI	 	DSC_IDX(DSC_HDMI)       /* 0x34 */
#define	SC_DSC_RX_HDMI	 	DSC_IDX(DSC_HDMI_RX)    /* 0x35 */
#define	SC_DSC_CSI_1 		DSC_IDX(DSC_CSI_1)      /* 0x36 */
#define	SC_DSC_CSI_0		DSC_IDX(DSC_CSI_0)      /* 0x37 */
#define	SC_DSC_DI_MIPI_1	DSC_IDX(DSC_MIPI_1)     /* 0x38 */
#define	SC_DSC_DI_MIPI_0	DSC_IDX(DSC_MIPI_0)     /* 0x39 */
#define	SC_DSC_DI_LVDS_1	DSC_IDX(DSC_LVDS_1)     /* 0x3A */
#define	SC_DSC_DI_LVDS_0	DSC_IDX(DSC_LVDS_0)     /* 0x3B */
#define SC_DSC_LAST      	0x3FU
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
 * Subsystem Type. This type is used to indicate a subsystem.
 */
/** @{ */
#define SC_SUBSYS_SC        0U
#define SC_SUBSYS_MCU_0     1U
#define SC_SUBSYS_MCU_1     2U
#define SC_SUBSYS_CCI       3U
#define SC_SUBSYS_A53       4U
#define SC_SUBSYS_A72       5U
#define SC_SUBSYS_GPU_0     6U
#define SC_SUBSYS_GPU_1     7U
#define SC_SUBSYS_VPU       8U
#define SC_SUBSYS_DC_0      9U
#define SC_SUBSYS_DC_1      10U
#define SC_SUBSYS_IMG       11U
#define SC_SUBSYS_AUDIO     12U
#define SC_SUBSYS_DMA       13U
#define SC_SUBSYS_CONN      14U
#define SC_SUBSYS_DB        15U
#define SC_SUBSYS_DBLOGIC   16U
#define SC_SUBSYS_DRC_0     17U
#define SC_SUBSYS_DRC_1     18U
#define SC_SUBSYS_LSIO      19U
#define SC_SUBSYS_HSIO      20U
#define SC_SUBSYS_LVDS_0    21U
#define SC_SUBSYS_LVDS_1    22U
#define SC_SUBSYS_CSI_0     23U
#define SC_SUBSYS_CSI_1     24U
#define SC_SUBSYS_HDMI_RX   25U
#define SC_SUBSYS_HDMI      26U
#define SC_SUBSYS_MIPI_0    27U
#define SC_SUBSYS_MIPI_1    28U
#define SC_SUBSYS_LAST      SC_SUBSYS_MIPI_1
#define SC_SUBSYS_W         5U
#define SC_SUBSYS_NA        31U
/** @} */

/*!
 * Subsystem Type. This type is used to indicate a subsystem.
 */
typedef uint8_t sc_sub_t;

#define SC_PGP_00           0U
#define SC_PGP_01           1U
#define SC_PGP_02           2U
#define SC_PGP_03           3U
#define SC_PGP_10           4U
#define SC_PGP_11           5U
#define SC_PGP_12           6U
#define SC_PGP_13           7U
#define SC_PGP_20           8U
#define SC_PGP_21           9U
#define SC_PGP_22           10U
#define SC_PGP_23           11U
#define SC_PGP_30           12U
#define SC_PGP_31           13U
#define SC_PGP_32           14U
#define SC_PGP_33           15U

#define SC_PGP_W            5U
#define SC_PGP_NA           16U

#define  MTR_PWR_PLAN_SEL_SCU               0U
#define  MTR_PWR_PLAN_SEL_MCU_0             1U
#define  MTR_PWR_PLAN_SEL_MCU_1             2U
#define  MTR_PWR_PLAN_SEL_GPU3D_1           3U
#define  MTR_PWR_PLAN_SEL_LSIO              4U
#define  MTR_PWR_PLAN_SEL_GPU3D_0           5U
#define  MTR_PWR_PLAN_SEL_CA53              6U
#define  MTR_PWR_PLAN_SEL_DBLOG             7U
#define  MTR_PWR_PLAN_SEL_CA72              8U
#define  MTR_PWR_PLAN_SEL_HSIO              9U
#define  MTR_PWR_PLAN_SEL_DRC_0             10U
#define  MTR_PWR_PLAN_SEL_DB                11U
#define  MTR_PWR_PLAN_SEL_DC_1              12U
#define  MTR_PWR_PLAN_SEL_CONNECTIVITY      13U
#define  MTR_PWR_PLAN_SEL_DMA               14U
#define  MTR_PWR_PLAN_SEL_MIPI_CSI_0        15U
#define  MTR_PWR_PLAN_SEL_MIPI_CSI_1        16U
#define  MTR_PWR_PLAN_SEL_DRC_1             17U
#define  MTR_PWR_PLAN_SEL_DC_0              18U
#define  MTR_PWR_PLAN_SEL_RX_HDMI           19U
#define  MTR_PWR_PLAN_SEL_IMAGING           20U
#define  MTR_PWR_PLAN_SEL_AUDIO             21U
#define  MTR_PWR_PLAN_SEL_DI_HDMI           22U
#define  MTR_PWR_PLAN_SEL_DI_MIPI_0         23U
#define  MTR_PWR_PLAN_SEL_DI_MIPI_1         24U
#define  MTR_PWR_PLAN_SEL_VPU               25U

#define SC_SS_INFO_INIT                                                                                 \
    {HAS_SS_SC,      0, SC_PGP_32,   SC_SUBSYS_NA,  0,  0, SC_DSC_SC},          /* SC_SUBSYS_SC */      \
    {HAS_SS_MCU_0,   0, SC_PGP_33,   SC_SUBSYS_NA,  0,  0, SC_DSC_MCU_0},       /* SC_SUBSYS_MCU_0 */   \
    {HAS_SS_MCU_1,   1, SC_PGP_03,   SC_SUBSYS_NA,  0,  0, SC_DSC_MCU_1},       /* SC_SUBSYS_MCU_1 */   \
    {HAS_SS_CCI,     0, SC_PGP_31,   SC_SUBSYS_NA,  0,  0, SC_DSC_CCI},         /* SC_SUBSYS_CCI */     \
    {HAS_SS_AP_0,    0, SC_PGP_31,   SC_SUBSYS_NA,  0,  0, SC_DSC_AP_0},        /* SC_SUBSYS_A53 */     \
    {HAS_SS_AP_1,    0, SC_PGP_31,   SC_SUBSYS_NA,  0,  0, SC_DSC_AP_1},        /* SC_SUBSYS_A72 */     \
    {HAS_SS_GPU_0,   0, SC_PGP_10,   SC_SUBSYS_NA,  0,  0, SC_DSC_GPU_0},       /* SC_SUBSYS_GPU_0 */   \
    {HAS_SS_GPU_1,   1, SC_PGP_00,   SC_SUBSYS_NA,  0,  0, SC_DSC_GPU_1},       /* SC_SUBSYS_GPU_1 */   \
    {HAS_SS_VPU,     0, SC_PGP_01,   SC_SUBSYS_NA,  0,  0, SC_DSC_VPU},         /* SC_SUBSYS_VPU */     \
    {HAS_SS_DC_0,    0, SC_PGP_20,  SC_SUBSYS_IMG, 24,  0, SC_DSC_DC_0},        /* SC_SUBSYS_DC_0 */    \
    {HAS_SS_DC_1,    1, SC_PGP_30,  SC_SUBSYS_IMG, 25,  0, SC_DSC_DC_1},        /* SC_SUBSYS_DC_1 */    \
    {HAS_SS_IMG_0,   0, SC_PGP_21,   SC_SUBSYS_NA,  0,  0, SC_DSC_IMG},         /* SC_SUBSYS_IMG */     \
    {HAS_SS_AUDIO,   0, SC_PGP_23,   SC_SUBSYS_NA,  0,  0, SC_DSC_AUDIO},       /* SC_SUBSYS_AUDIO */   \
    {HAS_SS_DMA,     0, SC_PGP_22,   SC_SUBSYS_NA,  0,  0, SC_DSC_DMA},         /* SC_SUBSYS_DMA */     \
    {HAS_SS_CONN,    0, SC_PGP_02,   SC_SUBSYS_NA,  0,  0, SC_DSC_CONN},        /* SC_SUBSYS_CONN */    \
    {HAS_SS_DB,      0, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DB},          /* SC_SUBSYS_DB */      \
    {HAS_SS_DBLOGIC, 0, SC_PGP_13,   SC_SUBSYS_NA,  0,  0, SC_DSC_DBLOG},       /* SC_SUBSYS_DBLOGIC */ \
    {HAS_SS_DRC_0,   0, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DRC_0},       /* SC_SUBSYS_DRC_0 */   \
    {HAS_SS_DRC_1,   1, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DRC_1},       /* SC_SUBSYS_DRC_1 */   \
    {HAS_SS_LSIO,    0, SC_PGP_12,   SC_SUBSYS_NA,  0,  0, SC_DSC_LSIO},        /* SC_SUBSYS_LSIO */    \
    {HAS_SS_HSIO_0,  0, SC_PGP_11,   SC_SUBSYS_NA,  0,  0, SC_DSC_HSIO},        /* SC_SUBSYS_HSIO */    \
    {HAS_SS_LVDS_0,  0, SC_PGP_NA, SC_SUBSYS_DC_0, 12,  0, SC_DSC_DI_LVDS_0},   /* SC_SUBSYS_LVDS_0 */  \
    {HAS_SS_LVDS_1,  1, SC_PGP_NA, SC_SUBSYS_DC_1, 12,  0, SC_DSC_DI_LVDS_1},   /* SC_SUBSYS_LVDS_1 */  \
    {HAS_SS_CSI_0,   0, SC_PGP_NA,  SC_SUBSYS_IMG, 21, 18, SC_DSC_CSI_0},       /* SC_SUBSYS_CSI_0 */   \
    {HAS_SS_CSI_1,   1, SC_PGP_NA,  SC_SUBSYS_IMG, 22, 19, SC_DSC_CSI_1},       /* SC_SUBSYS_CSI_1 */   \
    {HAS_SS_HDMI_RX, 0, SC_PGP_NA,  SC_SUBSYS_IMG, 23, 20, SC_DSC_RX_HDMI},     /* SC_SUBSYS_HDMI_RX */ \
    {HAS_SS_HDMI,    0, SC_PGP_NA, SC_SUBSYS_DC_0, 13,  0, SC_DSC_DI_HDMI},     /* SC_SUBSYS_HDMI */    \
    {HAS_SS_MIPI_0,  0, SC_PGP_NA, SC_SUBSYS_DC_0, 11,  0, SC_DSC_DI_MIPI_0},   /* SC_SUBSYS_MIPI_0 */  \
    {HAS_SS_MIPI_1,  1, SC_PGP_NA, SC_SUBSYS_DC_1, 11,  0, SC_DSC_DI_MIPI_1}    /* SC_SUBSYS_MIPI_1 */

/*! Number of DB */
#define SC_NUM_DB           1U

/*!
 * DB Connect Type. Stores a subsystem connection mask.
 */
typedef uint32_t sc_db_connect_t;

/*! DB connect mask */
#define SC_DB_CONNECT           \
    ( BIT(SC_SUBSYS_SC)         \
    | BIT(SC_SUBSYS_MCU_0)      \
    | BIT(SC_SUBSYS_MCU_1)      \
    | BIT(SC_SUBSYS_CCI)        \
    | BIT(SC_SUBSYS_GPU_0)      \
    | BIT(SC_SUBSYS_GPU_1)      \
    | BIT(SC_SUBSYS_VPU)        \
    | BIT(SC_SUBSYS_DC_0)       \
    | BIT(SC_SUBSYS_DC_1)       \
    | BIT(SC_SUBSYS_IMG)        \
    | BIT(SC_SUBSYS_AUDIO)      \
    | BIT(SC_SUBSYS_DMA)        \
    | BIT(SC_SUBSYS_CONN)       \
    | BIT(SC_SUBSYS_DBLOGIC)    \
    | BIT(SC_SUBSYS_DRC_0)      \
    | BIT(SC_SUBSYS_DRC_1)      \
    | BIT(SC_SUBSYS_LSIO)       \
    | BIT(SC_SUBSYS_HSIO))

/*! Init order of DB (SCU outward) */
#define SC_DB_INIT \
    {SC_R_DB, SC_SUBSYS_DB, SC_DB_CONNECT}

#define SC_SS_EP_INIT                             \
    SS_EP_INIT_SC,        /* SC_SUBSYS_SC */      \
    SS_EP_INIT_M4,        /* SC_SUBSYS_MCU_0 */   \
    SS_EP_INIT_M4,        /* SC_SUBSYS_MCU_1 */   \
    SS_EP_INIT_CCI,       /* SC_SUBSYS_CCI */     \
    SS_EP_INIT_A53,       /* SC_SUBSYS_A53 */     \
    SS_EP_INIT_A72,       /* SC_SUBSYS_A72 */     \
    SS_EP_INIT_GPU,       /* SC_SUBSYS_GPU_0 */   \
    SS_EP_INIT_GPU,       /* SC_SUBSYS_GPU_1 */   \
    SS_EP_INIT_VPU,       /* SC_SUBSYS_VPU */     \
    SS_EP_INIT_DC,        /* SC_SUBSYS_DC_0 */    \
    SS_EP_INIT_DC,        /* SC_SUBSYS_DC_1 */    \
    SS_EP_INIT_IMG,       /* SC_SUBSYS_IMG */     \
    SS_EP_INIT_AUDIO,     /* SC_SUBSYS_AUDIO */   \
    SS_EP_INIT_DMA,       /* SC_SUBSYS_DMA */     \
    SS_EP_INIT_CONN,      /* SC_SUBSYS_CONN */    \
    SS_EP_INIT_DB,        /* SC_SUBSYS_DB */      \
    SS_EP_INIT_DBLOGIC,   /* SC_SUBSYS_DBLOGIC */ \
    SS_EP_INIT_DRC,       /* SC_SUBSYS_DRC_0 */   \
    SS_EP_INIT_DRC,       /* SC_SUBSYS_DRC_1 */   \
    SS_EP_INIT_LSIO,      /* SC_SUBSYS_LSIO */    \
    SS_EP_INIT_HSIO,      /* SC_SUBSYS_HSIO */    \
    SS_EP_INIT_LVDS,      /* SC_SUBSYS_LVDS_0 */  \
    SS_EP_INIT_LVDS,      /* SC_SUBSYS_LVDS_1 */  \
    SS_EP_INIT_CSI,       /* SC_SUBSYS_CSI_0 */   \
    SS_EP_INIT_CSI,       /* SC_SUBSYS_CSI_1 */   \
    SS_EP_INIT_HDMI_RX,   /* SC_SUBSYS_HDMI_RX */ \
    SS_EP_INIT_HDMI,      /* SC_SUBSYS_HDMI */    \
    SS_EP_INIT_MIPI,      /* SC_SUBSYS_MIPI_0 */  \
    SS_EP_INIT_MIPI       /* SC_SUBSYS_MIPI_1 */

#define SC_SS_BASE_INFO_INIT                        \
    &ss_base_info_sc,       /* SC_SUBSYS_SC */      \
    &ss_base_info_m4,       /* SC_SUBSYS_MCU_0 */   \
    &ss_base_info_m4,       /* SC_SUBSYS_MCU_1 */   \
    &ss_base_info_cci,      /* SC_SUBSYS_CCI */     \
    &ss_base_info_a53,      /* SC_SUBSYS_A53 */     \
    &ss_base_info_a72,      /* SC_SUBSYS_A72 */     \
    &ss_base_info_gpu,      /* SC_SUBSYS_GPU_0 */   \
    &ss_base_info_gpu,      /* SC_SUBSYS_GPU_1 */   \
    &ss_base_info_vpu,      /* SC_SUBSYS_VPU */     \
    &ss_base_info_dc,       /* SC_SUBSYS_DC_0 */    \
    &ss_base_info_dc,       /* SC_SUBSYS_DC_1 */    \
    &ss_base_info_img,      /* SC_SUBSYS_IMG */     \
    &ss_base_info_audio,    /* SC_SUBSYS_AUDIO */   \
    &ss_base_info_dma,      /* SC_SUBSYS_DMA */     \
    &ss_base_info_conn,     /* SC_SUBSYS_CONN */    \
    &ss_base_info_db,       /* SC_SUBSYS_DB */      \
    &ss_base_info_dblogic,  /* SC_SUBSYS_DBLOGIC */ \
    &ss_base_info_drc,      /* SC_SUBSYS_DRC_0 */   \
    &ss_base_info_drc,      /* SC_SUBSYS_DRC_1 */   \
    &ss_base_info_lsio,     /* SC_SUBSYS_LSIO */    \
    &ss_base_info_hsio,     /* SC_SUBSYS_HSIO */    \
    &ss_base_info_lvds,     /* SC_SUBSYS_LVDS_0 */  \
    &ss_base_info_lvds,     /* SC_SUBSYS_LVDS_1 */  \
    &ss_base_info_csi,      /* SC_SUBSYS_CSI_0 */   \
    &ss_base_info_csi,      /* SC_SUBSYS_CSI_1 */   \
    &ss_base_info_hdmi_rx,  /* SC_SUBSYS_HDMI_RX */ \
    &ss_base_info_hdmi,     /* SC_SUBSYS_HDMI */    \
    &ss_base_info_mipi,     /* SC_SUBSYS_MIPI_0 */  \
    &ss_base_info_mipi      /* SC_SUBSYS_MIPI_1 */

#ifdef DEBUG
    #define SNAME_INIT  \
        "SC",           \
        "M4_0",         \
        "M4_1",         \
        "CCI",          \
        "A53",          \
        "A72",          \
        "GPU_0",        \
        "GPU_1",        \
        "VPU",          \
        "DC_0",         \
        "DC_1",         \
        "IMG",          \
        "AUDIO",        \
        "DMA",          \
        "CONN",         \
        "DB",           \
        "DBLOGIC",      \
        "DRC_0",        \
        "DRC_1",        \
        "LSIO",         \
        "HSIO",         \
        "LVDS_0",       \
        "LVDS_1",       \
        "CSI_0",        \
        "CSI_1",        \
        "HDMI_RX",      \
        "HDMI",         \
        "MIPI_0",       \
        "MIPI_1"

    #define RNAME_INIT          \
        RNAME_INIT_SC_0         \
        RNAME_INIT_M4_0         \
        RNAME_INIT_M4_1         \
        RNAME_INIT_CCI_0        \
        RNAME_INIT_A53_0        \
        RNAME_INIT_A72_0        \
        RNAME_INIT_GPU_0        \
        RNAME_INIT_GPU_1        \
        RNAME_INIT_VPU_0        \
        RNAME_INIT_DC_0         \
        RNAME_INIT_DC_1         \
        RNAME_INIT_IMG_0        \
        RNAME_INIT_AUDIO_0      \
        RNAME_INIT_DMA_0        \
        RNAME_INIT_CONN_0       \
        RNAME_INIT_DB_0         \
        RNAME_INIT_DBLOGIC_0    \
        RNAME_INIT_DRC_0        \
        RNAME_INIT_DRC_1        \
        RNAME_INIT_LSIO_0       \
        RNAME_INIT_HSIO_0       \
        RNAME_INIT_LVDS_0       \
        RNAME_INIT_LVDS_1       \
        RNAME_INIT_CSI_0        \
        RNAME_INIT_CSI_1        \
        RNAME_INIT_HDMI_RX_0    \
        RNAME_INIT_HDMI_0       \
        RNAME_INIT_MIPI_0       \
        RNAME_INIT_MIPI_1       \
        RNAME_INIT_BRD

#endif

#define SC_R_DDR        SC_R_DRC_0
#define SC_R_DDR_PLL    SC_R_DRC_0_PLL

/*! Chip versions */
#define CHIP_VER_B0     0x1U

/*! Macro to get JTAG ID */
#ifndef SIMU
    #define JTAG_ID     (DSC_SC->GPR_STAT[2].RW & 0x1FFU)
#else
    #define JTAG_ID     ((CHIP_VER_B0 << 5U) | CHIP_ID_QM)
#endif

/*! Macros to get chip ID and version */
#define CHIP_ID         ((JTAG_ID >> 0U) & 0x1FU)
#define CHIP_VER        ((JTAG_ID >> 5U) & 0xFU)

/* Define IMG DSSCMIX rate */
#define SC_IMGMIX           SC_400MHZ

/* Configure Top Level Memory Map */

#define SC_MEMMAP_INIT                                                          \
    {  LSIO_SS_BASE1,    0x1C000000U, 1, 1, 30, 1, 0x00, SC_SUBSYS_LSIO},       \
    {   SCU_SS_BASE0,     0x4000000U, 0, 1, 26, 0, 0x00, SC_SUBSYS_SC},         \
    { MCU_0_SS_BASE0,     0x4000000U, 1, 1, 26, 0, 0x00, SC_SUBSYS_MCU_0},      \
    { MCU_1_SS_BASE0,     0x4000000U, 1, 1, 26, 0, 0x00, SC_SUBSYS_MCU_1},      \
    {HSIO_0_SS_BASE1,    0x10000000U, 1, 1, 28, 1, 0x00, SC_SUBSYS_HSIO},       \
    {HSIO_0_SS_BASE2,    0x10000000U, 1, 1, 28, 2, 0x00, SC_SUBSYS_HSIO},       \
    {      DDR_BASE0,    0x80000000U, 1, 0,  0, 0, 0x00, SC_SUBSYS_DB},         \
    {  LSIO_SS_BASE2,    0x40000000U, 1, 1, 30, 2, 0x00, SC_SUBSYS_LSIO},       \
    {      DDR_BASE1, 0x780000000ULL, 1, 0,  0, 0, 0x00, SC_SUBSYS_DB},         \
    {          SC_NA,          SC_NA, 0, 0,  0, 0,    0, 0}

#define SC_BOOT_ADDR_INIT                                                      \
    {OCRAM_ALIAS_BASE,       0x17FFFU, SC_R_OCRAM,      SC_SUBSYS_LSIO},       \
    {      OCRAM_BASE,       0x3FFFFU, SC_R_OCRAM,      SC_SUBSYS_LSIO},       \
    {  FSPI0_MEM_BASE,    0x10000000U, SC_R_FSPI_0,     SC_SUBSYS_LSIO},       \
    {      TCML_MCU_0,     0x4000000U, SC_R_MCU_0_PID0, SC_SUBSYS_MCU_0},      \
    {      TCML_MCU_1,     0x4000000U, SC_R_MCU_1_PID0, SC_SUBSYS_MCU_1},      \
    {       DDR_BASE0,    0x80000000U, SC_R_DRC_0,      SC_SUBSYS_DRC_0},      \
    {  FSPI1_MEM_BASE,    0x40000000U, SC_R_FSPI_1,     SC_SUBSYS_LSIO},       \
    { HSIO_0_SS_BASE0,     0x1000000U, SC_R_SATA_0,     SC_SUBSYS_HSIO},       \
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
#define DIV_FACTOR_NUM          2
#define DIV_FACTOR_DEN          3

/*! Define to indicate that AV PLL should be used for DC */
#define USE_AVPLL_FOR_DC

/*! Define for DB clock gating issue. */
#define TKT309042_WORKAROUND

/*! Has 28FDSOI in SCFW API */
#define API_HAS_28FDSOI

/*! Does not have V2X in SCFW API */
#define API_HAS_NO_V2X

#ifdef SIMU
/*! Support partitioning naming for debug */
#define HAS_PARTITION_NAMES
#endif

#if defined(LTO) || defined (SIMU)
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
#endif

/*! Define to use SECO FW */
#define HAS_SECO_FW

/*! Define for FW version */
#define SECO_FW_VERSION ((3UL << 16) | (7UL << 4) | 4UL)

/*! Define to use MIPI DSI/CSI trim */
#define HAS_DSI_VOH_TRIM

/*! Define DDR DATX8 Lanes */
#define DWC_NO_OF_BYTES	    4U

/*! Define to support ROM function calls */
#define SC_ROM_FUNC_ADDR    0x00000580U
#define SC_ROM_FUNC_TAG     0xEA90U
#define SC_ROM_FUNC_VER     0x0001U

/*! Defines for AI temp sensor */
#define AI_TEMP_RATE            1000U
#define AI_TEMP_NP              1915
#define AI_TEMP_NT              25
#define AI_TEMP_PANIC           127

/*!
 * Define operating points for A53, A72 and GPU.
 */
#define NUM_GPU_OPP         3
#define NUM_A53_OPP         4
#define NUM_A72_OPP         4

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
    #define BOOT_CPU            SC_R_AP_0_0
    #define BOOT_ADDR           0x080000000UL
    #define BOOT_MU             SC_R_MU_0A
    #define BOOT_CPU_STARTS     1U
    #define BOOT_FLAGS          0x00000000U
#endif

/* Boot data address */
#define SC_BOOT_DATA_ADDR_PTR   0x000005F0U
#define SC_BOOT_DATA_ADDR       0x2001FC00U
#define SC_BOOT_DATA2_ADDR      0x2001FD00U

/*! Rom boot device mappings */
/** @{ */
#define ROM_SDHC_0              SC_R_SDHC_0
#define ROM_SDHC_1              SC_R_SDHC_1
#define ROM_SDHC_2              SC_R_SDHC_2
#define ROM_FSPI_0              SC_R_FSPI_0
#define ROM_FSPI_1              SC_R_FSPI_1
#define ROM_USB_0               SC_R_USB_0
#define ROM_USB_1               SC_R_USB_0
#define ROM_USB_2               SC_R_USB_2
/** @} */

/* Config IROB */
#define SC_IROB_CONFIG          SC_IROB_4K

/* Configure Tests */
#define TEST_HSIO0_PCIE         SC_R_PCIE_A
#define TEST_HSIO0_SERDES       SC_R_SERDES_0
#define TEST_HSIO0_MATCH_0      SC_R_MATCH_0
#define SC_P_TEST_PAD           SC_P_UART1_RX
#define SC_P_TEST_PAD_HSIC      SC_P_USB_HSIC0_DATA
#define SC_P_TEST_PAD_COMP      SC_P_COMP_CTL_GPIO_3V3_USB3IO
#define SC_P_TEST_PAD_CONFIG    SC_P_CALIBRATION_0_HSIC
#define TEST_LSIO               HAS_SS_LSIO
#define TEST_DMA                HAS_SS_DMA
#define TEST_BOARD_ALT2         SC_FALSE

/* Max MRC regions */
#define SC_MAX_NUM_MEMREG   \
(                           \
      16U   /* DB */        \
    + 32U   /* HSIO */      \
    + 48U   /* LSIO */      \
    + 4U    /* MCU 0 */     \
    + 4U    /* MCU 1 */     \
    + 4U    /* SC */        \
)

/*! Define to indicate number of CAAM job rings */
#define SC_CAAM_JR              4U

/*! Define to indicate number of MU */
#define SC_SECO_MU              4U

/* Configure Resources */
#define SC_NO_DTCP

/* Define CPU topology */
#define SOC_NUM_CLUSTER         2U
#define SOC_IDX_AP_0            0U
#define SOC_IDX_AP_1            1U
#define SOC_NUM_AP_0            4U
#define SOC_NUM_AP_1            2U
#define SOC_NUM_DIG_AUD_PLL     2U

/* Define MCU topology */
#define SOC_NUM_MCU             2U
#define SOC_IDX_MCU_0           0U
#define SOC_IDX_MCU_1           1U

/* Define HMP topology */
#define SOC_NUM_HMP_NODES       5U
#define SOC_HMP_IDX_SCU         0U                  /* SCU must be index 0 */
#define SOC_HMP_IDX_MCU_0       1U                  /* MCU order must follow topology above */
#define SOC_HMP_IDX_MCU_1       2U
#define SOC_HMP_IDX_AP_0        3U                  /* AP order must follow topology above */
#define SOC_HMP_IDX_AP_1        4U
#define SOC_HMP_IDX_MCU         SOC_HMP_IDX_MCU_0
#define SOC_HMP_IDX_AP          SOC_HMP_IDX_AP_0

/* Define system-level interface topology */
#define SOC_NUM_SYS_IF          4U                  /* Number of system-level interfaces */
#define SOC_SYS_IF_MU_RSRC      5U                  /* Number of AP -> SCU message unit resources */
#define SOC_SYS_IF_ICN_RSRC     3U                  /* Number of interconnect resources */
#define SOC_SYS_IF_OCMEM_RSRC   3U                  /* Number of on-chip memory resources */
#define SOC_SYS_IF_DDR_RSRC     2U                  /* Number of DDR resources */
#define SOC_SYS_IF_CPU_HPM      SC_PM_PW_MODE_LP    /* CPU power mode threshold for HPM */

/* Define wakeup bindings */
#define SOC_GIC_DSC             SC_DSC_DBLOG        /* DSC for GIC wakeups */
#define SOC_IRQSTEER_DSC        SC_DSC_DBLOG        /* DSC for IRQSTEER wakeup */
#define SOC_GIC_WAKEUP00        REGBIT64(1, 0)      /* DSC IRQ for GIC wakeups */
#define SOC_IRQSTEER_AP_WAKEUP  REGBIT64(1, 11)     /* DSC IRQ for AP IRQSTEER wakeup */
#define SOC_IRQSTEER_MCU_WAKEUP REGBIT64(1, 9)      /* DSC IRQ for MCU IRQSTEER wakeup */
#define SOC_WAKEUP_PW_MODE      SC_PM_PW_MODE_STBY  /* CPU power mode limit for GIC wakeup */
#define SOC_RESUME_PW_MODE      SC_PM_PW_MODE_ON    /* CPU power mode for resume */
#define SOC_MCU_STOPM_PDN       3U                  /* STOPM >= 3 will power down MCU core */
#define SOC_MCU_STOPM_MEMSR     3U                  /* STOPM == 3 will retain memories */

/* Defines for DDR training */
#define DQS_TIMER_DURATION_512  1U    /* 512 * tCK = 2048 * (1/1600) = 1 us (round up) */
#define DQS_TIMER_DURATION_1008 1U    /* 1008 * tCK = 1008 * (1/1600) = 1 us (round up) */
#define DQS_TIMER_DURATION_2048 2U    /* 2048 * tCK = 2048 * (1/1600) = 2 us (round up) */
#define DQS_TIMER_DURATION_8192 6U    /* 8192 * tCK = 8192 * (1/1600) = 6 us (round up) */

/* Include SS configs */

#include "all_config.h"
#include "board/config.h"
#include "handlers_MX8QM.h"            /* Device specific handlers */

/* Configure Resources */

#define SC_NUM_RSRC             \
     (SS_NUM_RSRC_SC            \
    + SS_NUM_RSRC_M4            \
    + SS_NUM_RSRC_M4            \
    + SS_NUM_RSRC_CCI           \
    + SS_NUM_RSRC_A53           \
    + SS_NUM_RSRC_A72           \
    + SS_NUM_RSRC_GPU           \
    + SS_NUM_RSRC_GPU           \
    + SS_NUM_RSRC_VPU           \
    + SS_NUM_RSRC_DC            \
    + SS_NUM_RSRC_DC            \
    + SS_NUM_RSRC_IMG           \
    + SS_NUM_RSRC_AUDIO         \
    + SS_NUM_RSRC_DMA           \
    + SS_NUM_RSRC_CONN          \
    + SS_NUM_RSRC_DB            \
    + SS_NUM_RSRC_DBLOGIC       \
    + SS_NUM_RSRC_DRC           \
    + SS_NUM_RSRC_DRC           \
    + SS_NUM_RSRC_LSIO          \
    + SS_NUM_RSRC_HSIO          \
    + SS_NUM_RSRC_LVDS          \
    + SS_NUM_RSRC_LVDS          \
    + SS_NUM_RSRC_CSI           \
    + SS_NUM_RSRC_CSI           \
    + SS_NUM_RSRC_HDMI_RX       \
    + SS_NUM_RSRC_HDMI          \
    + SS_NUM_RSRC_MIPI          \
    + SS_NUM_RSRC_MIPI          \
    + BRD_NUM_RSRC_BRD)

#define SC_PAD_INIT_INIT                    \
    {SC_P_SIM0_POWER_EN, 3, 0},             \
    {SC_P_SIM0_GPIO0_00, 3, 0},             \
    {SC_P_UART1_RTS_B,   3, 0},             \
    {SC_P_UART1_CTS_B,   3, 0},             \
    {SC_P_PMIC_I2C_SDA,  3, 0},             \
    {SC_P_PMIC_I2C_SCL,  3, 0},             \
    {SC_P_SPI3_SCK,      3, 0},             \
    {SC_P_SPI3_SDO,      3, 0},             \
    {SC_P_SPI3_SDI,      3, 0},             \
    {SC_P_SPI3_CS0,      3, 0},             \
    {SC_P_SAI1_RXC,      3, 0},             \
    {SC_P_SAI1_RXFS,     3, 0},             \
    {SC_P_USB_SS3_TC0,   3, 0},             \
    {SC_P_USB_SS3_TC1,   3, 0},             \
    {SC_P_USB_SS3_TC2,   3, 0},             \
    {SC_P_USB_SS3_TC3,   3, 0},             \
    {0, 0, 0}

#define SC_ROM_SS_INIT              \
    0,      /* SC_SUBSYS_SC */      \
    1,      /* SC_SUBSYS_MCU_0 */   \
    2,      /* SC_SUBSYS_MCU_1 */   \
    3,      /* SC_SUBSYS_CCI */     \
    4,      /* SC_SUBSYS_A53 */     \
    5,      /* SC_SUBSYS_A72 */     \
    6,      /* SC_SUBSYS_GPU_0 */   \
    7,      /* SC_SUBSYS_GPU_1 */   \
    8,      /* SC_SUBSYS_VPU */     \
    10,     /* SC_SUBSYS_DC_0 */    \
    11,     /* SC_SUBSYS_DC_1 */    \
    12,     /* SC_SUBSYS_IMG */     \
    13,     /* SC_SUBSYS_AUDIO */   \
    14,     /* SC_SUBSYS_DMA */     \
    15,     /* SC_SUBSYS_CONN */    \
    16,     /* SC_SUBSYS_DB */      \
    17,     /* SC_SUBSYS_DBLOGIC */ \
    18,     /* SC_SUBSYS_DRC_0 */   \
    19,     /* SC_SUBSYS_DRC_1 */   \
    20,     /* SC_SUBSYS_LSIO */    \
    21,     /* SC_SUBSYS_HSIO */    \
    22,     /* SC_SUBSYS_LVDS_0 */  \
    23,     /* SC_SUBSYS_LVDS_1 */  \
    24,     /* SC_SUBSYS_CSI_0 */   \
    25,     /* SC_SUBSYS_CSI_1 */   \
    26,     /* SC_SUBSYS_HDMI_RX */ \
    27,     /* SC_SUBSYS_HDMI */    \
    28,     /* SC_SUBSYS_MIPI_0 */  \
    29      /* SC_SUBSYS_MIPI_1 */

#endif /* SC_SOC_H */

