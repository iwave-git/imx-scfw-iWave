/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright (c) 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
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

/*!
 * @file MX8QM.h
 * @version 1.7
 * @date 2015-05-16
 * @brief CMSIS Peripheral Access Layer for MX8QM
 *
 * CMSIS Peripheral Access Layer for MX8QM
 */

#ifndef MX8QM_H
#define MX8QM_H                        /**< Symbol preventing repeated inclusion */

/* Check for valid CPU versions */
#if !defined(SREV_B0)
    #error "Invalid SOC revision!\n"
#endif

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0007U


/* ----------------------------------------------------------------------------
   -- Memory Map (SC perspective)
   ---------------------------------------------------------------------------- */

#define LSIO_SS_BASE1           0x00000000U                     /* LSIO SS - slot 1 */
#define OCRAM_ALIAS_BASE        (LSIO_SS_BASE1+0x000000U)       /* OCRAM alias */
#define SC_ROM_BASE             0x00000000U                     /* SC ROM */
#define OCRAM_BASE              (LSIO_SS_BASE1+0x100000U)       /* OCRAM */
#define FSPI0_MEM_BASE          (LSIO_SS_BASE1+0x8000000U)      /* FlexSPI0 Memory */
#define FSPI0_MEM_END           (FSPI0_MEM_BASE+0x0FFFFFFFU)    /* Top of FlexSPI0 Memory */
#define TCML_BASE               0x1FFE0000U                     /* SC TCML */
#define TCMU_BASE               0x20000000U                     /* SC TCMU */
#define CAAM_BASE               0x20400000U                     /* SC CAAM */
#define ADM_BASE                0x20520000U                     /* SC ADM */
#define OTP_BASE                0x20530000U                     /* SC OTP */
#define SNVS_BASE               0x20540000U                     /* SC SNVS */
#define MU0_BASE                0x20550000U                     /* SECO MU 1 */
#define VPU_SS_BASE1            0x2C000000U                     /* VPU SS - slot 1 */
#define VPU_SCB_BASE            (VPU_SS_BASE1+0x0070000U)       /* VPU SCB */
#define VPU_MFD_BASE            (VPU_SS_BASE1+0x01B0000U)       /* VPU Decoder */
#define LPUART1_BASE            (VPU_SS_BASE1+0x0200000U)       /* VPU LPUART */
#define MU7_BASE                (VPU_SS_BASE1+0x1010000U)       /* VPU MU 0 */
#define MU8_BASE                (VPU_SS_BASE1+0x1030000U)       /* VPU MU 1 */
#define SCU_SS_BASE0            0x30000000U                     /* SCU SS - slot 0 */
#define TCML0_BASE              (SCU_SS_BASE0+0x00FE0000U)      /* SCU TCML */
#define TCMU0_BASE              (SCU_SS_BASE0+0x01000000U)      /* SCU TCMU */
#define MCU_0_SS_BASE0          0x34000000U                     /* MCU 0 SS - slot 0 */
#define TCML1_BASE              (MCU_0_SS_BASE0+0x0FE0000U)     /* MCU 0 TCML */
#define TCMU1_BASE              (MCU_0_SS_BASE0+0x1000000U)     /* MCU 0 TCMU */
#define RGPIOB_BASE             (MCU_0_SS_BASE0+0x30F0000U)     /* MCU 0 RGPIO */
#define LPUART2_BASE            (MCU_0_SS_BASE0+0x3220000U)     /* MCU 0 LPUART */
#define LPI2C1_BASE             (MCU_0_SS_BASE0+0x3230000U)     /* MCU 0 LPI2C */
#define WDOG1_BASE              (MCU_0_SS_BASE0+0x3420000U)     /* MCU 0 WDOG */
#define MU9_BASE                (MCU_0_SS_BASE0+0x3480000U)     /* MCU 0 MU 1A */
#define MCU_1_SS_BASE0          0x38000000U                     /* MCU 1 SS - slot 0 */
#define TCML2_BASE              (MCU_1_SS_BASE0+0x0FE0000U)     /* MCU 1 TCML */
#define TCMU2_BASE              (MCU_1_SS_BASE0+0x1000000U)     /* MCU 1 TCMU */
#define RGPIOC_BASE             (MCU_1_SS_BASE0+0x30F0000U)     /* MCU 1 RGPIO */
#define LPUART3_BASE            (MCU_1_SS_BASE0+0x3220000U)     /* MCU 1 LPUART */
#define LPI2C2_BASE             (MCU_1_SS_BASE0+0x3230000U)     /* MCU 1 LPI2C */
#define WDOG2_BASE              (MCU_1_SS_BASE0+0x3420000U)     /* MCU 1 WDOG */
#define MU10_BASE               (MCU_1_SS_BASE0+0x3480000U)     /* MCU 1 MU 1A */
#define SYSCTR_CTRL_BASE        0x40000000U                     /* SC SYSCTR Control */
#define SYSCTR_RD_BASE          0x40010000U                     /* SC SYSCTR Read */
#define SYSCTR_CMP_BASE         0x40020000U                     /* SC SYSCTR Compare 0 */
#define SYSCTR_CMP1_BASE        0x40020100U                     /* SC SYSCTR Compare 1 */
#define LPC_BASE                0x40070000U                     /* SC LPC */
#define CSGPR_BASE              0x40470000U                     /* CoreSight GPR */
#define AP_1_DEBUG_APB_BASE     0x40600000U                     /* AP_1 Debug APB */
#define AP_0_DEBUG_APB_BASE     0x40800000U                     /* AP_0 Debug APB */
#define AP_2_DEBUG_APB_BASE     0x40800000U                     /* AP_2 Debug APB */
#define RGPIOA_BASE             0x410F0000U                     /* SC RGPIO */
#define LPIT0_BASE              0x41210000U                     /* SC LPIT */
#define LPUART0_BASE            0x41220000U                     /* SC LPUART */
#define LPI2C0_BASE             0x41230000U                     /* SC LPI2C */
#define ASMC_BASE               0x41410000U                     /* SC ASMC */
#define WDOG0_BASE              0x41420000U                     /* SC WDOG */
#define MU1_BASE                0x41430000U                     /* SC MU 0B */
#define MU2_BASE                0x41440000U                     /* SC MU 0A0 */
#define MU3_BASE                0x41450000U                     /* SC MU 0A1 */
#define MU4_BASE                0x41460000U                     /* SC MU 0A2 */
#define MU5_BASE                0x41470000U                     /* SC MU 0A3 */
#define MU6_BASE                0x41480000U                     /* SC MU 1A */
#define MSI0_BASE               0x41800000U                     /* SC DSC MSI Ring 0 */
#define DSC1_BASE               0x41820000U                     /* SC SC DSC */
#define REP2_BASE               0x4182B000U                     /* SC MBIST MTR */
#define MSI1_BASE               0x41A00000U                     /* SC DSC MSI Ring 1 */
#define DSC17_BASE              0x41A20000U                     /* SC MCU_0 DSC */
#define DSC18_BASE              0x41A40000U                     /* SC DRC_0 DSC */
#define DSC19_BASE              0x41A60000U                     /* SC DC_1 DSC */
#define DSC20_BASE              0x41A80000U                     /* SC MCU_1 DSC */
#define DSC21_BASE              0x41AA0000U                     /* SC GPU_1 DSC */
#define DSC22_BASE              0x41AC0000U                     /* SC CONN DSC */
#define DSC23_BASE              0x41AE0000U                     /* SC VPU DSC */
#define DSC25_BASE              0x41B20000U                     /* SC CCI DSC */
#define MSI2_BASE               0x41C00000U                     /* SC DSC MSI Ring 2 */
#define DSC33_BASE              0x41C20000U                     /* SC AP_1 DSC */
#define DSC34_BASE              0x41C40000U                     /* SC DB DSC */
#define DSC35_BASE              0x41C60000U                     /* SC AP_0 DSC */
#define DSC36_BASE              0x41C80000U                     /* SC HSIO DSC */
#define DSC37_BASE              0x41CA0000U                     /* SC LSIO DSC */
#define DSC38_BASE              0x41CC0000U                     /* SC GPU_0 DSC */
#define DSC39_BASE              0x41CE0000U                     /* SC DC_0 DSC */
#define DSC40_BASE              0x41D00000U                     /* SC DRC_1 DSC */
#define DSC41_BASE              0x41D20000U                     /* SC DMA DSC */
#define MSI3_BASE               0x41E00000U                     /* SC DSC MSI Ring 3 */
#define DSC49_BASE              0x41E20000U                     /* SC DBLOG DSC */
#define DSC50_BASE              0x41E40000U                     /* SC IMG DSC */
#define DSC51_BASE              0x41E60000U                     /* SC AUDIO DSC */
#define DSC52_BASE              0x41E80000U                     /* SC HDMI DSC */
#define DSC53_BASE              0x41EA0000U                     /* SC HDMI_RX DSC */
#define DSC54_BASE              0x41EC0000U                     /* SC CSI_1 DSC */
#define DSC55_BASE              0x41EE0000U                     /* SC CSI_0 DSC */
#define DSC56_BASE              0x41F00000U                     /* SC MIPI_1 DSC */
#define DSC57_BASE              0x41F20000U                     /* SC MIPI_0 DSC */
#define DSC58_BASE              0x41F40000U                     /* SC LVDS_1 DSC */
#define DSC59_BASE              0x41F60000U                     /* SC LVDS_0 DSC */
#define PAD_BASE                0x41F80000U                     /* SC Pad */
#define MSI4_BASE               0x41F9F000U                     /* SC Pad MSI Ring 0 */
#define MSI5_BASE               0x41FBF000U                     /* SC Pad MSI Ring 1 */
#define MSI6_BASE               0x41FDF000U                     /* SC Pad MSI Ring 2 */
#define MSI7_BASE               0x41FFF000U                     /* SC Pad MSI Ring 3 */
#define DBLOG_SS_BASE0          0x51000000U                     /* DBLOGIC SS - slot 0 */
#define IRQSTR_SCU_BASE         (DBLOG_SS_BASE0+0x060000U)      /* IRQSTR.SCU1 */
#define SMMU0_BASE              (DBLOG_SS_BASE0+0x400000U)      /* SMMU 0 */
#define GIC0_BASE               (DBLOG_SS_BASE0+0xA00000U)      /* GIC 0 */
#define AP_SS_BASE0             0x52000000U                     /* AP SS - slot 0 */
#define CCI_BASE                (AP_SS_BASE0+0x90000U)          /* CCI */
#define GPU_0_SS_BASE0          0x53000000U                     /* GPU 0 SS - slot 0 */
#define GPU_1_SS_BASE0          0x54000000U                     /* GPU 1 SS - slot 0 */
#define VPU_SS_BASE0            0x55000000U                     /* VPU SS - slot 0 */
#define DSP_DRAM_BASE           (VPU_SS_BASE0+0x6E8000U)        /* DSP DRAM */
#define DSP_DRAM1_BASE          (VPU_SS_BASE0+0x6F0000U)        /* DSP DRAM 1 */
#define DSP_IRAM_BASE           (VPU_SS_BASE0+0x6F8000U)        /* DSP IRAM */
#define DSP_OCRAM_BASE          (VPU_SS_BASE0+0x700000U)        /* DSP OCRAM */
#define DC_0_SS_BASE0           0x56000000U                     /* DC 0 SS - slot 0 */
#define DC_0_ADDR_0             (DC_0_SS_BASE0+0x00000U)        /* DC 0 test addr 0 */
#define DC_0_ADDR_1             (DC_0_SS_BASE0+0x10000U)        /* DC 0 test addr 1 */
#define DC_0_MSI_BASE           (DC_0_SS_BASE0+0x200000U)       /* DC_0 MSI CTRL */
#define MIPI_0_SS_BASE          (DC_0_SS_BASE0+0x220000U)       /* MIPI 0 */
#define LPI2C3_BASE             (MIPI_0_SS_BASE+0x6000U)        /* MIPI 0 LPI2C 0 */
#define LPI2C4_BASE             (MIPI_0_SS_BASE+0x7000U)        /* MIPI 0 LPI2C 1 */
#define LVDS_0_SS_BASE          (DC_0_SS_BASE0+0x240000U)       /* LVDS 0 */
#define LPI2C5_BASE             (LVDS_0_SS_BASE+0x6000U)        /* LVDS 0 LPI2C 0 */
#define LPI2C6_BASE             (LVDS_0_SS_BASE+0x7000U)        /* LVDS 0 LPI2C 1 */
#define HDMI_SS_BASE            (DC_0_SS_BASE0+0x260000U)       /* HDMI */
#define LPI2C7_BASE             (HDMI_SS_BASE+0x6000U)          /* HDMI LPI2C */
#define DC_1_SS_BASE0           0x57000000U                     /* DC 1 SS - slot 0 */
#define DC_1_ADDR_0             (DC_1_SS_BASE0+0x00000U)        /* DC 1 test addr 0 */
#define DC_1_ADDR_1             (DC_1_SS_BASE0+0x10000U)        /* DC 1 test addr 1 */
#define DC_1_MSI_BASE           (DC_1_SS_BASE0+0x200000U)       /* DC_1 MSI CTRL */
#define MIPI_1_SS_BASE          (DC_1_SS_BASE0+0x220000U)       /* MIPI 1 */
#define LPI2C8_BASE             (MIPI_1_SS_BASE+0x6000U)        /* MIPI 1 LPI2C 0 */
#define LPI2C9_BASE             (MIPI_1_SS_BASE+0x7000U)        /* MIPI 1 LPI2C 1 */
#define LVDS_1_SS_BASE          (DC_1_SS_BASE0+0x240000U)       /* LVDS 1 */
#define LPI2C10_BASE            (LVDS_1_SS_BASE+0x6000U)        /* LVDS 1 LPI2C 0 */
#define LPI2C11_BASE            (LVDS_1_SS_BASE+0x7000U)        /* LVDS 1 LPI2C 1 */
#define IMG_SS_BASE0            0x58000000U                     /* IMG SS - slot 0 */
#define IMG_0_GPIO_BASE         (IMG_SS_BASE0+0x000000U)        /* IMG GPIO */
#define ISI0_BASE               (IMG_SS_BASE0+0x100000U)        /* IMG CH0 */
#define ISI1_BASE               (IMG_SS_BASE0+0x110000U)        /* IMG CH1 */
#define ISI2_BASE               (IMG_SS_BASE0+0x120000U)        /* IMG CH2 */
#define ISI3_BASE               (IMG_SS_BASE0+0x130000U)        /* IMG CH3 */
#define ISI4_BASE               (IMG_SS_BASE0+0x140000U)        /* IMG CH4 */
#define ISI5_BASE               (IMG_SS_BASE0+0x150000U)        /* IMG CH5 */
#define ISI6_BASE               (IMG_SS_BASE0+0x160000U)        /* IMG CH6 */
#define ISI7_BASE               (IMG_SS_BASE0+0x170000U)        /* IMG CH7 */
#define IMG_0_MSI_BASE          (IMG_SS_BASE0+0x200000U)        /* IMG MSI CTRL */
#define CSI_0_SS_BASE           (IMG_SS_BASE0+0x220000U)        /* CSI 0 */
#define LPI2C12_BASE            (CSI_0_SS_BASE+0x6000U)         /* CSI 0 LPI2C 0 */
#define CSI_1_SS_BASE           (IMG_SS_BASE0+0x240000U)        /* CSI 1 */
#define LPI2C13_BASE            (CSI_1_SS_BASE+0x6000U)         /* CSI 1 LPI2C 0 */
#define HDMI_RX_SS_BASE         (IMG_SS_BASE0+0x260000U)        /* HDMI RX */
#define LPI2C14_BASE            (HDMI_RX_SS_BASE+0x6000U)       /* HDMI RX LPI2C */
#define AUDIO_SS_BASE0          0x59000000U                     /* AUDIO SS - slot 0 */
#define DMA0_BASE               (AUDIO_SS_BASE0+0x1F0000U)      /* Audio eDMA 0 MP */
#define DMA1_BASE               (AUDIO_SS_BASE0+0x9F0000U)      /* Audio eDMA 1 MP */
#define DMA_SS_BASE0            0x5A000000U                     /* DMA SS - slot 0 */
#define LPUART4_BASE            (DMA_SS_BASE0+0x060000U)        /* DMA LPUART 0 */
#define LPUART5_BASE            (DMA_SS_BASE0+0x070000U)        /* DMA LPUART 1 */
#define LPUART6_BASE            (DMA_SS_BASE0+0x080000U)        /* DMA LPUART 2 */
#define LPUART7_BASE            (DMA_SS_BASE0+0x090000U)        /* DMA LPUART 3 */
#define LPUART8_BASE            (DMA_SS_BASE0+0x0A0000U)        /* DMA LPUART 4 */
#define DMA2_BASE               (DMA_SS_BASE0+0x1F0000U)        /* DMA eDMA 0 MP */
#define LPI2C15_BASE            (DMA_SS_BASE0+0x800000U)        /* DMA LPI2C 0 */
#define LPI2C16_BASE            (DMA_SS_BASE0+0x810000U)        /* DMA LPI2C 1 */
#define LPI2C17_BASE            (DMA_SS_BASE0+0x820000U)        /* DMA LPI2C 2 */
#define LPI2C18_BASE            (DMA_SS_BASE0+0x830000U)        /* DMA LPI2C 3 */
#define LPI2C19_BASE            (DMA_SS_BASE0+0x840000U)        /* DMA LPI2C 4 */
#define DMA3_BASE               (DMA_SS_BASE0+0x9F0000U)        /* DMA eDMA 1 MP */
#define CONN_SS_BASE0           0x5B000000U                     /* CONN SS - slot 0 */
#define SDHC0_BASE              (CONN_SS_BASE0+0x010000U)       /* CONN SDHC 0 */
#define SDHC1_BASE              (CONN_SS_BASE0+0x020000U)       /* CONN SDHC 1 */
#define SDHC2_BASE              (CONN_SS_BASE0+0x030000U)       /* CONN SDHC 2 */
#define ENET0_BASE              (CONN_SS_BASE0+0x040000U)       /* CONN ENET 0 */
#define ENET1_BASE              (CONN_SS_BASE0+0x050000U)       /* CONN ENET 1 */
#define DMA4_BASE               (CONN_SS_BASE0+0x070000U)       /* CONN eDMA MP */
#define USB_0_BASE              (CONN_SS_BASE0+0x0D0000U)       /* CONN USB 0 */
#define USB_1_BASE              (CONN_SS_BASE0+0x0E0000U)       /* CONN USB 1 */
#define USB_0_PHY_BASE          (CONN_SS_BASE0+0x100000U)       /* CONN USB 0 PHY */
#define USB_1_PHY_BASE          (CONN_SS_BASE0+0x110000U)       /* CONN USB 1 PHY */
#define ENET0_LPCG              (CONN_SS_BASE0+0x230000U)       /* CONN ENET 0 LPCG */
#define NAND_BASE               (CONN_SS_BASE0+0x810000U)       /* CONN NAND */
#define DB_SS_BASE0             0x5C000000U                     /* DB SS - slot 0 */
#define DRC_0_LPCG_0            (DB_SS_BASE0+0x0C0000U)         /* DRC 0 LPCG 0 */
#define DRC_0_LPCG_1            (DB_SS_BASE0+0x0D0000U)         /* DRC 0 LPCG 1 */
#define DRC_0_LPCG_2            (DB_SS_BASE0+0x0E0000U)         /* DRC 0 LPCG 2 */
#define DRC_0_LPCG_3            (DB_SS_BASE0+0x0F0000U)         /* DRC 0 LPCG 3 */
#define DRC_1_LPCG_0            (DB_SS_BASE0+0x1C0000U)         /* DRC 1 LPCG 0 */
#define DRC_1_LPCG_1            (DB_SS_BASE0+0x1D0000U)         /* DRC 1 LPCG 1 */
#define DRC_1_LPCG_2            (DB_SS_BASE0+0x1E0000U)         /* DRC 1 LPCG 2 */
#define DRC_1_LPCG_3            (DB_SS_BASE0+0x1F0000U)         /* DRC 1 LPCG 3 */
#define STC0_BASE               (DB_SS_BASE0+0x400000U)         /* DB PG0 STC 0 */
#define STC1_BASE               (DB_SS_BASE0+0x410000U)         /* DB PG0 STC 1 */
#define STC2_BASE               (DB_SS_BASE0+0x420000U)         /* DB PG0 STC 2 */
#define STC3_BASE               (DB_SS_BASE0+0x430000U)         /* DB PG0 STC 3 */
#define DB_LPCG_PG0_BASE        (DB_SS_BASE0+0x4F0000U)         /* DB PG0 LPCG */
#define STC4_BASE               (DB_SS_BASE0+0x500000U)         /* DB PG1 STC 0 */
#define STC5_BASE               (DB_SS_BASE0+0x510000U)         /* DB PG1 STC 1 */
#define STC6_BASE               (DB_SS_BASE0+0x520000U)         /* DB PG1 STC 2 */
#define STC7_BASE               (DB_SS_BASE0+0x530000U)         /* DB PG1 STC 3 */
#define DB_LPCG_PG1_BASE        (DB_SS_BASE0+0x5F0000U)         /* DB PG1 LPCG */
#define STC8_BASE               (DB_SS_BASE0+0x600000U)         /* DB PG2 STC 0 */
#define STC9_BASE               (DB_SS_BASE0+0x610000U)         /* DB PG2 STC 1 */
#define STC10_BASE              (DB_SS_BASE0+0x620000U)         /* DB PG2 STC 2 */
#define STC11_BASE              (DB_SS_BASE0+0x630000U)         /* DB PG2 STC 3 */
#define DB_LPCG_PG2_BASE        (DB_SS_BASE0+0x6F0000U)         /* DB PG2 LPCG */
#define STC12_BASE              (DB_SS_BASE0+0x700000U)         /* DB PG3 STC 0 */
#define STC13_BASE              (DB_SS_BASE0+0x710000U)         /* DB PG3 STC 1 */
#define STC14_BASE              (DB_SS_BASE0+0x720000U)         /* DB PG3 STC 2 */
#define STC15_BASE              (DB_SS_BASE0+0x730000U)         /* DB PG3 STC 3 */
#define DB_LPCG_PG3_BASE        (DB_SS_BASE0+0x7F0000U)         /* DB PG3 LPCG */
#define DB_LPCG_BN_BASE         (DB_SS_BASE0+0xAF0000U)         /* DB BN LPCG */
#define LSIO_SS_BASE0           0x5D000000U                     /* LSIO SS - slot 0 */
#define PWM0_BASE               (LSIO_SS_BASE0+0x000000U)       /* LSIO PWM 0 */
#define PWM1_BASE               (LSIO_SS_BASE0+0x010000U)       /* LSIO PWM 1 */
#define PWM2_BASE               (LSIO_SS_BASE0+0x020000U)       /* LSIO PWM 2 */
#define PWM3_BASE               (LSIO_SS_BASE0+0x030000U)       /* LSIO PWM 3 */
#define PWM4_BASE               (LSIO_SS_BASE0+0x040000U)       /* LSIO PWM 4 */
#define PWM5_BASE               (LSIO_SS_BASE0+0x050000U)       /* LSIO PWM 5 */
#define PWM6_BASE               (LSIO_SS_BASE0+0x060000U)       /* LSIO PWM 6 */
#define PWM7_BASE               (LSIO_SS_BASE0+0x070000U)       /* LSIO PWM 7 */
#define GPIO0_BASE              (LSIO_SS_BASE0+0x080000U)       /* LSIO GPIO 0 */
#define GPIO1_BASE              (LSIO_SS_BASE0+0x090000U)       /* LSIO GPIO 1 */
#define GPIO2_BASE              (LSIO_SS_BASE0+0x0A0000U)       /* LSIO GPIO 2 */
#define GPIO3_BASE              (LSIO_SS_BASE0+0x0B0000U)       /* LSIO GPIO 3 */
#define GPIO4_BASE              (LSIO_SS_BASE0+0x0C0000U)       /* LSIO GPIO 4 */
#define GPIO5_BASE              (LSIO_SS_BASE0+0x0D0000U)       /* LSIO GPIO 5 */
#define GPIO6_BASE              (LSIO_SS_BASE0+0x0E0000U)       /* LSIO GPIO 6 */
#define GPIO7_BASE              (LSIO_SS_BASE0+0x0F0000U)       /* LSIO GPIO 7 */
#define FSPI0_BASE              (LSIO_SS_BASE0+0x120000U)       /* FSPI0 */
#define FSPI1_BASE              (LSIO_SS_BASE0+0x130000U)       /* FSPI1 */
#define GPT0_BASE               (LSIO_SS_BASE0+0x140000U)       /* LSIO GPT 0 */
#define GPT1_BASE               (LSIO_SS_BASE0+0x150000U)       /* LSIO GPT 1 */
#define GPT2_BASE               (LSIO_SS_BASE0+0x160000U)       /* LSIO GPT 2 */
#define GPT3_BASE               (LSIO_SS_BASE0+0x170000U)       /* LSIO GPT 3 */
#define GPT4_BASE               (LSIO_SS_BASE0+0x180000U)       /* LSIO GPT 4 */
#define KPP_BASE                (LSIO_SS_BASE0+0x1A0000U)       /* LSIO KPP */
#define MU11_BASE               (LSIO_SS_BASE0+0x1B0000U)       /* LSIO MU 0A */
#define MU12_BASE               (LSIO_SS_BASE0+0x1C0000U)       /* LSIO MU 1A */
#define MU13_BASE               (LSIO_SS_BASE0+0x1D0000U)       /* LSIO MU 2A */
#define MU14_BASE               (LSIO_SS_BASE0+0x1E0000U)       /* LSIO MU 3A */
#define MU15_BASE               (LSIO_SS_BASE0+0x1F0000U)       /* LSIO MU 4A */
#define IEE_BASE                (LSIO_SS_BASE0+0x320000U)       /* IEE */
#define IEE_R0_BASE             (LSIO_SS_BASE0+0x330000U)       /* IEE R0 */
#define IEE_R1_BASE             (LSIO_SS_BASE0+0x340000U)       /* IEE R1 */
#define FSPI0_LPCG              (LSIO_SS_BASE0+0x520000U)       /* FSPI0 LPCG */
#define HSIO_0_SS_BASE0         0x5F000000U                     /* HSIO 0 SS - slot 0 */
#define HSIO_0_LPCG_GPIO        (HSIO_0_SS_BASE0+0x100000U)     /* HSIO 0 GPIO LPCG */
#define HSIO_0_SS_BASE1         0x60000000U                     /* HSIO 0 SS - slot 1 */
#define HSIO_0_SS_BASE2         0x70000000U                     /* HSIO 0 SS - slot 2 */
#define DDR_BASE0               0x80000000U                     /* DDR */
#define MCM_BASE                0xE0080000U                     /* SC MCM */
#define LMEM_BASE               0xE0082000U                     /* SC LMEM */
#define DDR_BASE0_END           0xFFFFFFFFU                     /* Top of DDR 0 */
#define LSIO_SS_BASE2           0x400000000ULL                  /* LSIO SS - slot 2 */
#define FSPI1_MEM_BASE          (LSIO_SS_BASE2+0x0U)            /* FlexSPI1 Memory */
#define DDR_BASE1               0x880000000ULL                  /* DDR - Hi */
#define DDR_BASE1_END           0xFFFFFFFFFULL                  /* Top of DDR 1 */

/* Unused */

#define DSC2_BASE               0
#define DSC3_BASE               0
#define DSC4_BASE               0
#define DSC5_BASE               0
#define DSC6_BASE               0
#define DSC7_BASE               0
#define DSC8_BASE               0
#define DSC9_BASE               0
#define DSC10_BASE              0
#define DSC11_BASE              0
#define DSC12_BASE              0
#define DSC13_BASE              0
#define DSC14_BASE              0
#define DSC15_BASE              0
#define DSC24_BASE              0
#define DSC26_BASE              0
#define DSC27_BASE              0
#define DSC28_BASE              0
#define DSC29_BASE              0
#define DSC30_BASE              0
#define DSC31_BASE              0
#define DSC42_BASE              0
#define DSC43_BASE              0
#define DSC44_BASE              0
#define DSC45_BASE              0
#define DSC46_BASE              0
#define DSC47_BASE              0
#define DSC60_BASE              0
#define DSC61_BASE              0
#define DSC62_BASE              0
#define DSC63_BASE              0
#define LPI2C20_BASE            0
#define LPI2C21_BASE            0
#define LPI2C22_BASE            0
#define LPI2C23_BASE            0
#define LPI2C24_BASE            0
#define LPI2C25_BASE            0
#define DMA5_BASE               0
#define DMA6_BASE               0
#define ISI8_BASE               0
#define ISI9_BASE               0
#define ISI10_BASE              0
#define ISI11_BASE              0
#define ISI12_BASE              0
#define ISI13_BASE              0
#define ISI14_BASE              0
#define ISI15_BASE              0
#define ISI16_BASE              0
#define ISI17_BASE              0
#define ISI18_BASE              0
#define ISI19_BASE              0
#define ISI20_BASE              0
#define ISI21_BASE              0
#define ISI22_BASE              0
#define ISI23_BASE              0
#define MU16_BASE               0
#define MU17_BASE               0
#define MU18_BASE               0
#define MU19_BASE               0
#define MU20_BASE               0
#define MU21_BASE               0
#define MU22_BASE               0
#define MU23_BASE               0
#define MU24_BASE               0
#define STC16_BASE              0
#define STC17_BASE              0
#define STC18_BASE              0
#define STC19_BASE              0
#define STC20_BASE              0
#define STC21_BASE              0
#define STC22_BASE              0
#define STC23_BASE              0


/* ----------------------------------------------------------------------------
   -- Device Mapping
   ---------------------------------------------------------------------------- */

#define DMA_AUDIO0              DMA0
#define DMA_AUDIO1              DMA1
#define DMA_PERIPH0             DMA2
#define DMA_PERIPH1             DMA3
#define DMA_CONN                DMA4
#define DSC_SC                  DSC1
#define DSC_MCU_0               DSC17
#define DSC_DRC_0               DSC18
#define DSC_DC_1                DSC19
#define DSC_MCU_1               DSC20
#define DSC_GPU_1               DSC21
#define DSC_CONN                DSC22
#define DSC_VPU                 DSC23
#define DSC_CCI                 DSC25
#define DSC_AP_1                DSC33
#define DSC_DB                  DSC34
#define DSC_AP_0                DSC35
#define DSC_HSIO                DSC36
#define DSC_LSIO                DSC37
#define DSC_GPU_0               DSC38
#define DSC_DC_0                DSC39
#define DSC_DRC_1               DSC40
#define DSC_DMA                 DSC41
#define DSC_DBLOG               DSC49
#define DSC_IMG                 DSC50
#define DSC_AUDIO               DSC51
#define DSC_HDMI                DSC52
#define DSC_HDMI_RX             DSC53
#define DSC_CSI_1               DSC54
#define DSC_CSI_0               DSC55
#define DSC_MIPI_1              DSC56
#define DSC_MIPI_0              DSC57
#define DSC_LVDS_1              DSC58
#define DSC_LVDS_0              DSC59
#define GPIO_SC                 RGPIOA
#define GPIO_MCU_0              RGPIOB
#define GPIO_MCU_1              RGPIOC
#define ISI_IMG_0_CH0           ISI0
#define ISI_IMG_0_CH1           ISI1
#define ISI_IMG_0_CH2           ISI2
#define ISI_IMG_0_CH3           ISI3
#define ISI_IMG_0_CH4           ISI4
#define ISI_IMG_0_CH5           ISI5
#define ISI_IMG_0_CH6           ISI6
#define ISI_IMG_0_CH7           ISI7
#define LPI2C_SC                LPI2C0
#define LPI2C_MCU_0             LPI2C1
#define LPI2C_MCU_1             LPI2C2
#define LPI2C_MIPI0_0           LPI2C3
#define LPI2C_MIPI0_1           LPI2C4
#define LPI2C_LVDS0_0           LPI2C5
#define LPI2C_LVDS0_1           LPI2C6
#define LPI2C_HDMI              LPI2C7
#define LPI2C_MIPI1_0           LPI2C8
#define LPI2C_MIPI1_1           LPI2C9
#define LPI2C_LVDS1_0           LPI2C10
#define LPI2C_LVDS1_1           LPI2C11
#define LPI2C_CSI0_0            LPI2C12
#define LPI2C_CSI1_0            LPI2C13
#define LPI2C_HDMI_RX           LPI2C14
#define LPI2C_0                 LPI2C15
#define LPI2C_1                 LPI2C16
#define LPI2C_2                 LPI2C17
#define LPI2C_3                 LPI2C18
#define LPI2C_4                 LPI2C19
#define LPIT_SC                 LPIT0
#define LPUART_SC               LPUART0
#define LPUART_VPU_0            LPUART1
#define LPUART_MCU_0            LPUART2
#define LPUART_MCU_1            LPUART3
#define LPUART_0                LPUART4
#define LPUART_1                LPUART5
#define LPUART_2                LPUART6
#define LPUART_3                LPUART7
#define LPUART_4                LPUART8
#define MU_SECO                 MU0
#define MU_SC_0B                MU1
#define MU_SC_0A0               MU2
#define MU_SC_0A1               MU3
#define MU_SC_0A2               MU4
#define MU_SC_0A3               MU5
#define MU_SC_1A                MU6
#define MU_VPU_0                MU7
#define MU_VPU_1                MU8
#define MU_MCU_0_1A             MU9
#define MU_MCU_1_1A             MU10
#define MU_LSIO_0A              MU11
#define MU_LSIO_1A              MU12
#define MU_LSIO_2A              MU13
#define MU_LSIO_3A              MU14
#define MU_LSIO_4A              MU15
#define STC_PG0_0               STC0
#define STC_PG0_1               STC1
#define STC_PG0_2               STC2
#define STC_PG0_3               STC3
#define STC_PG1_0               STC4
#define STC_PG1_1               STC5
#define STC_PG1_2               STC6
#define STC_PG1_3               STC7
#define STC_PG2_0               STC8
#define STC_PG2_1               STC9
#define STC_PG2_2               STC10
#define STC_PG2_3               STC11
#define STC_PG3_0               STC12
#define STC_PG3_1               STC13
#define STC_PG3_2               STC14
#define STC_PG3_3               STC15
#define TCMU_SC                 TCMU0_BASE
#define TCMU_MCU_0              TCMU1_BASE
#define TCMU_MCU_1              TCMU2_BASE
#define TCML_SC                 TCML0_BASE
#define TCML_MCU_0              TCML1_BASE
#define TCML_MCU_1              TCML2_BASE
#define WDOG_SC                 WDOG0
#define WDOG_MCU_0              WDOG1
#define WDOG_MCU_1              WDOG2

/* ----------------------------------------------------------------------------
   -- CoreSight Granular Power Requestor Mappings
   ---------------------------------------------------------------------------- */
#define CSGPR_CPWRUPREQ         (CSGPR_BASE+0x000U)
#define CSGPR_CPWRUPACK         (CSGPR_BASE+0x004U)
#define CSGPR_CLAIMSET          (CSGPR_BASE+0xFA0U)
#define CSGPR_CLAIMCLR          (CSGPR_BASE+0xFA4U)
#define CSGPR_LAR               (CSGPR_BASE+0xFB0U)
#define CSGPR_LSR               (CSGPR_BASE+0xFB4U)

#define CSGPR_IDX_A72           4U
#define CSGPR_IDX_A53           5U
#define CSGPR_IDX_MCU_0         6U
#define CSGPR_IDX_MCU_1         7U
#define CSGPR_IDX_VPU           8U

#define CSGPR_XOR_DSC_REG       1U
#define CSGPR_XOR_DSC_MASK      0x0000FFFFU
#define CSGPR_ACK_DSC_REG       2U
#define CSGPR_ACK_DSC_MASK      0xFFFF0000U

/* ----------------------------------------------------------------------------
   -- GIC Mappings
   ---------------------------------------------------------------------------- */
#define GICD_BASE               (GIC0_BASE+0x000000U)
#define GICR_BASE               (GIC0_BASE+0x100000U)

#define GICD_CTLR_OFS           (0x0000U)
#define GICD_CTLR_RWP_MASK      (0x80000000U)

#define GICR_WAKER_OFS          (0x0014U)
#define GICR_WAKER_PA_MASK      (0x00000002U)
#define GICR_WAKER_CA_MASK      (0x00000004U)

/* ----------------------------------------------------------------------------
   -- FSPI Definitions
   ---------------------------------------------------------------------------- */
#define FSPI0_LPCG_EN_MASK      (0x02220002U)

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 256                /**< Number of interrupts in the Vector table */

/* Auxiliary constants */
#define NotAvail_IRQn                 -128              /**< Not available device specific interrupt */

/* Core interrupts */
#define NonMaskableInt_IRQn           -14               /**< Non Maskable Interrupt */
#define HardFault_IRQn                -13               /**< Cortex-M4 SV Hard Fault Interrupt */
#define MemoryManagement_IRQn         -12               /**< Cortex-M4 Memory Management Interrupt */
#define BusFault_IRQn                 -11               /**< Cortex-M4 Bus Fault Interrupt */
#define UsageFault_IRQn               -10               /**< Cortex-M4 Usage Fault Interrupt */
#define SVCall_IRQn                   -5                /**< Cortex-M4 SV Call Interrupt */
#define DebugMonitor_IRQn             -4                /**< Cortex-M4 Debug Monitor Interrupt */
#define PendSV_IRQn                   -2                /**< Cortex-M4 Pend SV Interrupt */
#define SysTick_IRQn                  -1                /**< Cortex-M4 System Tick Interrupt */

/* Device specific interrupts */
#define Reserved0_IRQn                0                 /**< Reserved interrupt */
#define Reserved1_IRQn                1                 /**< Reserved interrupt */
#define Reserved2_IRQn                2                 /**< Reserved interrupt */
#define Reserved3_IRQn                3                 /**< Reserved interrupt */
#define Reserved4_IRQn                4                 /**< Reserved interrupt */
#define MCM_IRQn                      5                 /**< MCM interrupt */
#define DebugWake_IRQn                6                 /**< Debug wake interrupt */
#define OCOTP_Bank0_IRQn              7                 /**< OCOTP bank0 interrupt */
#define OCOTP_Bank1_IRQn              8                 /**< OCOTP bank1 interrupt */
#define Reserved9_IRQn                9                 /**< Reserved interrupt */
#define INTMUX0_8_IRQn                10                /**< INTMUX0_8 interrupt */
#define INTMUX0_9_IRQn                11                /**< INTMUX0_9 interrupt */
#define INTMUX0_10_IRQn               12                /**< INTMUX0_10 interrupt */
#define INTMUX0_11_IRQn               13                /**< INTMUX0_11 interrupt */
#define INTMUX0_12_IRQn               14                /**< INTMUX0_12 interrupt */
#define INTMUX0_13_IRQn               15                /**< INTMUX0_13 interrupt */
#define INTMUX0_14_IRQn               16                /**< INTMUX0_14 interrupt */
#define INTMUX0_15_IRQn               17                /**< INTMUX0_15 interrupt */
#define Reserved18_IRQn               18                /**< Reserved interrupt */
#define TPM0_IRQn                     19                /**< TPM0 interrupt */
#define Reserved20_IRQn               20                /**< Reserved interrupt */
#define Reserved21_IRQn               21                /**< Reserved interrupt */
#define LPIT0_IRQn                    22                /**< LPIT0 interrupt */
#define Reserved23_IRQn               23                /**< Reserved interrupt */
#define Reserved24_IRQn               24                /**< Reserved interrupt */
#define LPUART0_IRQn                  25                /**< LPUART0 interrupt */
#define Reserved26_IRQn               26                /**< Reserved interrupt */
#define LPI2C0_IRQn                   27                /**< LPI2C0 interrupt */
#define Reserved28_IRQn               28                /**< Reserved interrupt */
#define MU0_B0_IRQn                   29                /**< MU0_B0 interrupt */
#define SECO_MU_NMI_IRQn              30                /**< SECO_MU_NMI interrupt */
#define SECO_MU_IRQn                  31                /**< SECO_MU interrupt */
#define INTMUX0_0_IRQn                32                /**< INTMUX0_0 interrupt */
#define INTMUX0_1_IRQn                33                /**< INTMUX0_1 interrupt */
#define INTMUX0_2_IRQn                34                /**< INTMUX0_2 interrupt */
#define INTMUX0_3_IRQn                35                /**< INTMUX0_3 interrupt */
#define INTMUX0_4_IRQn                36                /**< INTMUX0_4 interrupt */
#define INTMUX0_5_IRQn                37                /**< INTMUX0_5 interrupt */
#define INTMUX0_6_IRQn                38                /**< INTMUX0_6 interrupt */
#define INTMUX0_7_IRQn                39                /**< INTMUX0_7 interrupt */
#define SYSCTR_CMP3_IRQn              40                /**< SYSCTR_CMP3 interrupt */
#define SYSCTR_CMP2_IRQn              41                /**< SYSCTR_CMP2 interrupt */
#define SYSCTR_CMP1_IRQn              42                /**< SYSCTR_CMP1 interrupt */
#define SYSCTR_CMP0_IRQn              43                /**< SYSCTR_CMP0 interrupt */
#define MU0_B1_IRQn                   44                /**< MU0_B1 interrupt */
#define MU0_B2_IRQn                   45                /**< MU0_B2 interrupt */
#define MU0_B3_IRQn                   46                /**< MU0_B3 interrupt */
#define PMIC_INT_IRQn                 47                /**< PMIC_INT interrupt */
#define PMIC_EarlyWarning_IRQn        48                /**< PMIC_EarlyWarning interrupt */
#define MU1_A_IRQn                    49                /**< MU1_A interrupt */
#define SWI_IRQn                      50                /**< Software interrupt */
#define SWI_DQS2DQ_IRQn               51                /**< DQS2DQ Software interrupt */
#define CAAM_IRQ0_IRQn                52                /**< CAAM_IRQ0 interrupt */
#define CAAM_IRQ1_IRQn                53                /**< CAAM_IRQ1 interrupt */
#define CAAM_IRQ2_IRQn                54                /**< CAAM_IRQ2 interrupt */
#define CAAM_IRQ3_IRQn                55                /**< CAAM_IRQ3 interrupt */
#define CAAM_RTIC_IRQn                56                /**< CAAM_RTIC interrupt */
#define CAAM_Error_IRQn               57                /**< CAAM_Error interrupt */
#define SNVS_Functional_IRQn          58                /**< SNVS_Functional interrupt */
#define SNVS_SecurityViolation_IRQn   59                /**< SNVS_SecurityViolation interrupt */
#define SNVS_Periodic_IRQn            60                /**< SNVS_Periodic interrupt */
#define SNVS_Button_IRQn              61                /**< SNVS_Button interrupt */
#define SNVS_Alarm_IRQn               62                /**< Reserved interrupt */
#define SNVS_PowerOff_IRQn            63                /**< Reserved interrupt */
#define DSC00_IRQn                    64                /**< DSC0 interrupt */
#define DSC_SCU_IRQn                  64                /**< DSC0 interrupt */
#define DSC_DB_IRQn                   65                /**< DSC1 interrupt */
#define DSC_DRC_1_IRQn                66                /**< DSC2 interrupt */
#define DSC03_IRQn                    67                /**< DSC3 interrupt */
#define DSC_HSIO_IRQn                 68                /**< DSC4 interrupt */
#define DSC_CA72_IRQn                 69                /**< DSC5 interrupt */
#define DSC_CCI_IRQn                  70                /**< DSC6 interrupt */
#define DSC_CM4_0_IRQn                71                /**< DSC7 interrupt */
#define DSC_CM4_1_IRQn                72                /**< DSC8 interrupt */
#define DSC_GPU_1_IRQn                73                /**< DSC9 interrupt */
#define DSC_LSIO_IRQn                 74                /**< DSC10 interrupt */
#define DSC_GPU_0_IRQn                75                /**< DSC11 interrupt */
#define DSC_CA53_IRQn                 76                /**< DSC12 interrupt */
#define DSC_DBLOG_IRQn                77                /**< DSC13 interrupt */
#define DSC_DC_1_IRQn                 78                /**< DSC14 interrupt */
#define DSC_VPUCORE_IRQn              79                /**< DSC15 interrupt */
#define DSC_Connectivity_IRQn         80                /**< DSC16 interrupt */
#define DSC_DI_LVDS_0_IRQn            81                /**< DSC17 interrupt */
#define DSC_DI_LVDS_1_IRQn            82                /**< DSC18 interrupt */
#define DSC_DMA_IRQn                  83                /**< DSC19 interrupt */
#define DSC_VPU_IRQn                  84                /**< DSC20 interrupt */
#define DSC21_IRQn                    85                /**< DSC21 interrupt */
#define DSC_DRC_0_IRQn                86                /**< DSC22 interrupt */
#define DSC_DC_0_IRQn                 87                /**< DSC23 interrupt */
#define DSC_MIPI_CSI_0_IRQn           88                /**< DSC24 interrupt */
#define DSC_MIPI_CSI_1_IRQn           89                /**< DSC25 interrupt */
#define DSC_RX_HDMI_IRQn              90                /**< DSC26 interrupt */
#define DSC_Imaging_IRQn              91                /**< DSC27 interrupt */
#define DSC_Audio_IRQn                92                /**< DSC28 interrupt */
#define DSC_DI_HDMI_IRQn              93                /**< DSC29 interrupt */
#define DSC_DI_MIPI_0_IRQn            94                /**< DSC30 interrupt */
#define DSC_DI_MIPI_1_IRQn            95                /**< DSC31 interrupt */
#define DSC31_IRQn                    95                /**< DSC31 interrupt */
#define IOMUX31_IRQn                  96                /**< IOMUX31 interrupt */
#define IOMUX30_IRQn                  97                /**< IOMUX30 interrupt */
#define IOMUX29_IRQn                  98                /**< IOMUX29 interrupt */
#define IOMUX28_IRQn                  99                /**< IOMUX28 interrupt */
#define IOMUX27_IRQn                  100               /**< IOMUX27 interrupt */
#define IOMUX26_IRQn                  101               /**< IOMUX26 interrupt */
#define IOMUX25_IRQn                  102               /**< IOMUX25 interrupt */
#define IOMUX24_IRQn                  103               /**< IOMUX24 interrupt */
#define IOMUX23_IRQn                  104               /**< IOMUX23 interrupt */
#define IOMUX22_IRQn                  105               /**< IOMUX22 interrupt */
#define IOMUX21_IRQn                  106               /**< IOMUX21 interrupt */
#define IOMUX20_IRQn                  107               /**< IOMUX20 interrupt */
#define IOMUX19_IRQn                  108               /**< IOMUX19 interrupt */
#define IOMUX18_IRQn                  109               /**< IOMUX18 interrupt */
#define IOMUX17_IRQn                  110               /**< IOMUX17 interrupt */
#define IOMUX16_IRQn                  111               /**< IOMUX16 interrupt */
#define IOMUX15_IRQn                  112               /**< IOMUX15 interrupt */
#define IOMUX14_IRQn                  113               /**< IOMUX14 interrupt */
#define IOMUX13_IRQn                  114               /**< IOMUX13 interrupt */
#define IOMUX12_IRQn                  115               /**< IOMUX12 interrupt */
#define IOMUX11_IRQn                  116               /**< IOMUX11 interrupt */
#define IOMUX10_IRQn                  117               /**< IOMUX10 interrupt */
#define IOMUX9_IRQn                   118               /**< IOMUX9 interrupt */
#define IOMUX8_IRQn                   119               /**< IOMUX8 interrupt */
#define IOMUX7_IRQn                   120               /**< IOMUX7 interrupt */
#define IOMUX6_IRQn                   121               /**< IOMUX6 interrupt */
#define IOMUX5_IRQn                   122               /**< IOMUX5 interrupt */
#define IOMUX4_IRQn                   123               /**< IOMUX4 interrupt */
#define IOMUX3_IRQn                   124               /**< IOMUX3 interrupt */
#define IOMUX2_IRQn                   125               /**< IOMUX2 interrupt */
#define IOMUX1_IRQn                   126               /**< IOMUX1 interrupt */
#define IOMUX0_IRQn                   127               /**< IOMUX0 interrupt */
#define NUM_NVIC_IRQn                 128               /**< Number of NVIC interrupts */

typedef int IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex-M Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex-M Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm4.h"                  /* Core Peripheral Access Layer */
#include "system_MX8QM.h"              /* Device specific configuration file */

__attribute__( ( always_inline ) ) __STATIC_INLINE uint64_t LDRD (const __IO uint32_t *addr)
{
    union
    {
        uint32_t w32[2];
        uint64_t w64;
    } llr;

  __ASM volatile ("ldrd %0, %1, %2" : "=r" (llr.w32[0]), "=r" (llr.w32[1]) : "Q" (*addr) );

  return(llr.w64);
}

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */

#endif  /* MX8QM_H */

/* MX8QM.h, eof. */
