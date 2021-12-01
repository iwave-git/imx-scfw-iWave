/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for the DSC
**
**     Copyright (c) 1997 - 2016 Freescale Semiconductor, Inc.
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
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file MX8_dsc.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for the DSC
 *
 * CMSIS Peripheral Access Layer for the DSC
 */

#ifndef HW_DSC_REGISTERS_H
#define HW_DSC_REGISTERS_H                               /**< Symbol preventing repeated inclusion */

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma push
  #pragma anon_unions
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

#define DSC_MAX_PD            8         //!< Max number of power domains

/* ----------------------------------------------------------------------------
   -- DSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSC_Peripheral_Access_Layer DSC Peripheral Access Layer
 * @{
 */

/** DSC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Reset Control: MSlice and CSlice resetn bits, offset: 0x0 */
    __IO uint32_t SET;                               /**< Reset Control: MSlice and CSlice resetn bits, offset: 0x4 */
    __IO uint32_t CLR;                               /**< Reset Control: MSlice and CSlice resetn bits, offset: 0x8 */
    __IO uint32_t TOG;                               /**< Reset Control: MSlice and CSlice resetn bits, offset: 0xC */
  } RST_CTRL_SLICE_RSTN[3];
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Reset Control: Clock Root reset bits., offset: 0x30 */
    __IO uint32_t SET;                               /**< Reset Control: Clock Root reset bits., offset: 0x34 */
    __IO uint32_t CLR;                               /**< Reset Control: Clock Root reset bits., offset: 0x38 */
    __IO uint32_t TOG;                               /**< Reset Control: Clock Root reset bits., offset: 0x3C */
  } RST_CTRL_CR_RSTN;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< Reset Control: Subsystem resets, offset: 0x40 */
    __IO uint32_t SET;                               /**< Reset Control: Subsystem resets, offset: 0x44 */
    __IO uint32_t CLR;                               /**< Reset Control: Subsystem resets, offset: 0x48 */
    __IO uint32_t TOG;                               /**< Reset Control: Subsystem resets, offset: 0x4C */
  } RST_CTRL_SS_RSTN;
       uint8_t RESERVED_0[176];
  struct {                                         /* offset: 0x100 */
    __IO uint32_t RW;                                /**< Reset Control: MSlice and CSlice select functional clock mux bits., offset: 0x100 */
    __IO uint32_t SET;                               /**< Reset Control: MSlice and CSlice select functional clock mux bits., offset: 0x104 */
    __IO uint32_t CLR;                               /**< Reset Control: MSlice and CSlice select functional clock mux bits., offset: 0x108 */
    __IO uint32_t TOG;                               /**< Reset Control: MSlice and CSlice select functional clock mux bits., offset: 0x10C */
  } RST_CTRL_SLICE_SFCM[3];
  struct {                                         /* offset: 0x130 */
    __IO uint32_t RW;                                /**< Reset Control: Select Functional Clock mux for root clocks., offset: 0x130 */
    __IO uint32_t SET;                               /**< Reset Control: Select Functional Clock mux for root clocks., offset: 0x134 */
    __IO uint32_t CLR;                               /**< Reset Control: Select Functional Clock mux for root clocks., offset: 0x138 */
    __IO uint32_t TOG;                               /**< Reset Control: Select Functional Clock mux for root clocks., offset: 0x13C */
  } RST_CTRL_CR_SFCM;
       uint8_t RESERVED_1[192];
  struct {                                         /* offset: 0x200 */
    __IO uint32_t RW;                                /**< Reset Control: Mslice and Cslice Start Functional Clock bits, offset: 0x200 */
    __IO uint32_t SET;                               /**< Reset Control: Mslice and Cslice Start Functional Clock bits, offset: 0x204 */
    __IO uint32_t CLR;                               /**< Reset Control: Mslice and Cslice Start Functional Clock bits, offset: 0x208 */
    __IO uint32_t TOG;                               /**< Reset Control: Mslice and Cslice Start Functional Clock bits, offset: 0x20C */
  } RST_CTRL_SLICE_SFC[3];
  struct {                                         /* offset: 0x230 */
    __IO uint32_t RW;                                /**< Reset Control: Start Functional Clock bits for root clocks., offset: 0x230 */
    __IO uint32_t SET;                               /**< Reset Control: Start Functional Clock bits for root clocks., offset: 0x234 */
    __IO uint32_t CLR;                               /**< Reset Control: Start Functional Clock bits for root clocks., offset: 0x238 */
    __IO uint32_t TOG;                               /**< Reset Control: Start Functional Clock bits for root clocks., offset: 0x23C */
  } RST_CTRL_CR_SFC;
       uint8_t RESERVED_2[192];
  struct {                                         /* offset: 0x300 */
    __IO uint32_t RW;                                /**< Reset Control: Enable for the reset clock., offset: 0x300 */
    __IO uint32_t SET;                               /**< Reset Control: Enable for the reset clock., offset: 0x304 */
    __IO uint32_t CLR;                               /**< Reset Control: Enable for the reset clock., offset: 0x308 */
    __IO uint32_t TOG;                               /**< Reset Control: Enable for the reset clock., offset: 0x30C */
  } RST_CTRL_RESET_CLK_EN;
       uint8_t RESERVED_3[240];
  struct {                                         /* offset: 0x400, array step: 0x10 */
    __IO uint32_t RW;                                /**< Power domain controls, array offset: 0x400, array step: 0x10 */
    __IO uint32_t SET;                               /**< Power domain controls, array offset: 0x404, array step: 0x10 */
    __IO uint32_t CLR;                               /**< Power domain controls, array offset: 0x408, array step: 0x10 */
    __IO uint32_t TOG;                               /**< Power domain controls, array offset: 0x40C, array step: 0x10 */
  } POWER_CTRL[6];
       uint8_t RESERVED_4[160];
  struct {                                         /* offset: 0x500, array step: 0x10 */
    __IO uint32_t RW;                                /**< General purpose control register bits., array offset: 0x500, array step: 0x10 */
    __IO uint32_t SET;                               /**< General purpose control register bits., array offset: 0x504, array step: 0x10 */
    __IO uint32_t CLR;                               /**< General purpose control register bits., array offset: 0x508, array step: 0x10 */
    __IO uint32_t TOG;                               /**< General purpose control register bits., array offset: 0x50C, array step: 0x10 */
  } GPR_CTRL[FSL_FEATURE_DSC_GPR_CTRL_CNT];
       uint32_t RESERVED_5[64 - (4 * FSL_FEATURE_DSC_GPR_CTRL_CNT)];
  struct {                                         /* offset: 0x600, array step: 0x10 */
    __I  uint32_t RW;                                /**< General purpose status bits., array offset: 0x600, array step: 0x10 */
    __I  uint32_t SET;                               /**< General purpose status bits., array offset: 0x604, array step: 0x10 */
    __I  uint32_t CLR;                               /**< General purpose status bits., array offset: 0x608, array step: 0x10 */
    __I  uint32_t TOG;                               /**< General purpose status bits., array offset: 0x60C, array step: 0x10 */
  } GPR_STAT[3];
       uint8_t RESERVED_6[208];
  struct {                                         /* offset: 0x700 */
    __IO uint32_t RW;                                /**< IRQ mask register for DSC interrupts., offset: 0x700 */
    __IO uint32_t SET;                               /**< IRQ mask register for DSC interrupts., offset: 0x704 */
    __IO uint32_t CLR;                               /**< IRQ mask register for DSC interrupts., offset: 0x708 */
    __IO uint32_t TOG;                               /**< IRQ mask register for DSC interrupts., offset: 0x70C */
  } IRQ_MASK_DSC;
  struct {                                         /* offset: 0x710 */
    __IO uint32_t RW;                                /**< IRQ mask register for Subsystem interrupts., offset: 0x710 */
    __IO uint32_t SET;                               /**< IRQ mask register for Subsystem interrupts., offset: 0x714 */
    __IO uint32_t CLR;                               /**< IRQ mask register for Subsystem interrupts., offset: 0x718 */
    __IO uint32_t TOG;                               /**< IRQ mask register for Subsystem interrupts., offset: 0x71C */
  } IRQ_MASK_SUBSYS;
       uint8_t RESERVED_7[224];
  struct {                                         /* offset: 0x800 */
    __I  uint32_t RW;                                /**< IRQ masked status register for DSC interrupts., offset: 0x800 */
    __I  uint32_t SET;                               /**< IRQ masked status register for DSC interrupts., offset: 0x804 */
    __I  uint32_t CLR;                               /**< IRQ masked status register for DSC interrupts., offset: 0x808 */
    __I  uint32_t TOG;                               /**< IRQ masked status register for DSC interrupts., offset: 0x80C */
  } IRQ_MASK_STATUS_DSC;
  struct {                                         /* offset: 0x810 */
    __I  uint32_t RW;                                /**< IRQ masked status register for Subsystem interrupts., offset: 0x810 */
    __I  uint32_t SET;                               /**< IRQ masked status register for Subsystem interrupts., offset: 0x814 */
    __I  uint32_t CLR;                               /**< IRQ masked status register for Subsystem interrupts., offset: 0x818 */
    __I  uint32_t TOG;                               /**< IRQ masked status register for Subsystem interrupts., offset: 0x81C */
  } IRQ_MASK_STATUS_SUBSYS;
       uint8_t RESERVED_8[224];
  struct {                                         /* offset: 0x900 */
    __IO uint32_t RW;                                /**< IRQ non-masked status register for DSC interrupts., offset: 0x900 */
    __IO uint32_t SET;                               /**< IRQ non-masked status register for DSC interrupts., offset: 0x904 */
    __IO uint32_t CLR;                               /**< IRQ non-masked status register for DSC interrupts., offset: 0x908 */
    __IO uint32_t TOG;                               /**< IRQ non-masked status register for DSC interrupts., offset: 0x90C */
  } IRQ_NONMASK_STATUS_DSC;
  struct {                                         /* offset: 0x910 */
    __I  uint32_t RW;                                /**< IRQ non-masked status register for Subsystem interrupts., offset: 0x910 */
    __I  uint32_t SET;                               /**< IRQ non-masked status register for Subsystem interrupts., offset: 0x914 */
    __I  uint32_t CLR;                               /**< IRQ non-masked status register for Subsystem interrupts., offset: 0x918 */
    __I  uint32_t TOG;                               /**< IRQ non-masked status register for Subsystem interrupts., offset: 0x91C */
  } IRQ_NONMASK_STATUS_SUBSYS;
       uint8_t RESERVED_9[224];
  struct {                                         /* offset: 0xA00 */
    __IO uint32_t RW;                                /**< Analog Interface Control Registers, offset: 0xA00 */
    __IO uint32_t SET;                               /**< Analog Interface Control Registers, offset: 0xA04 */
    __IO uint32_t CLR;                               /**< Analog Interface Control Registers, offset: 0xA08 */
    __IO uint32_t TOG;                               /**< Analog Interface Control Registers, offset: 0xA0C */
  } AI_CTRL;
  struct {                                         /* offset: 0xA10 */
    __IO uint32_t RW;                                /**< Analog Interface Registers, offset: 0xA10 */
    __IO uint32_t SET;                               /**< Analog Interface Registers, offset: 0xA14 */
    __IO uint32_t CLR;                               /**< Analog Interface Registers, offset: 0xA18 */
    __IO uint32_t TOG;                               /**< Analog Interface Registers, offset: 0xA1C */
  } AI_WR_DATA;
  struct {                                         /* offset: 0xA20 */
    __IO uint32_t RW;                                /**< Analog Interface Registers, offset: 0xA20 */
    __IO uint32_t SET;                               /**< Analog Interface Registers, offset: 0xA24 */
    __IO uint32_t CLR;                               /**< Analog Interface Registers, offset: 0xA28 */
    __IO uint32_t TOG;                               /**< Analog Interface Registers, offset: 0xA2C */
  } AI_TOGGLE0;
  struct {                                         /* offset: 0xA30 */
    __IO uint32_t RW;                                /**< Analog Interface Registers, offset: 0xA30 */
    __IO uint32_t SET;                               /**< Analog Interface Registers, offset: 0xA34 */
    __IO uint32_t CLR;                               /**< Analog Interface Registers, offset: 0xA38 */
    __IO uint32_t TOG;                               /**< Analog Interface Registers, offset: 0xA3C */
  } AI_TOGGLE1;
  struct {                                         /* offset: 0xA40 - NOT SCT Type*/
    __I  uint32_t RW;                                /**< Analog Interface Registers, offset: 0xA40 */
    __I  uint32_t SET;                               /**< Analog Interface Registers, offset: 0xA44 */
    __I  uint32_t CLR;                               /**< Analog Interface Registers, offset: 0xA48 */
    __I  uint32_t TOG;                               /**< Analog Interface Registers, offset: 0xA4C */
  } AI_DONE_TOGGLE0;
 struct {										  /* offset: 0xA50 - NOT SCT Type*/
   __I	uint32_t RW;								/**< Analog Interface Registers, offset: 0xA50 */
   __I	uint32_t SET;								/**< Analog Interface Registers, offset: 0xA54 */
   __I	uint32_t CLR;								/**< Analog Interface Registers, offset: 0xA58 */
   __I	uint32_t TOG;								/**< Analog Interface Registers, offset: 0xA5C */
 } AI_DONE_TOGGLE1;
  struct {                                         /* offset: 0xA60 - NOT SCT Type*/
    __I  uint32_t RW;                                /**< Analog Interface Registers, offset: 0xA60 */
    __I  uint32_t SET;                               /**< Analog Interface Registers, offset: 0xA64 */
    __I  uint32_t CLR;                               /**< Analog Interface Registers, offset: 0xA68 */
    __I  uint32_t TOG;                               /**< Analog Interface Registers, offset: 0xA6C */
  } AI_RD_DATA;
  struct {                                         /* offset: 0xA70 - NOT SCT type*/
    __I  uint32_t RW;                                /**< Analog Interface Registers, offset: 0xA70 */
    __I  uint32_t SET;                               /**< Analog Interface Registers, offset: 0xA74 */
    __I  uint32_t CLR;                               /**< Analog Interface Registers, offset: 0xA78 */
    __I  uint32_t TOG;                               /**< Analog Interface Registers, offset: 0xA7C */
  } AI_BUSY0;
  struct {                                         /* offset: 0xA80 - NOT SCT type*/
    __I  uint32_t RW;                                /**< Analog Interface Registers, offset: 0xA80 */
    __I  uint32_t SET;                               /**< Analog Interface Registers, offset: 0xA84 */
    __I  uint32_t CLR;                               /**< Analog Interface Registers, offset: 0xA88 */
    __I  uint32_t TOG;                               /**< Analog Interface Registers, offset: 0xA8C */
  } AI_BUSY1;

       uint8_t RESERVED_10[112];
  struct {                                         /* offset: 0xB00 */
    __IO uint32_t RW;                                /**< LOCKOUT Register, offset: 0xB00 */
    __IO uint32_t SET;                               /**< LOCKOUT Register, offset: 0xB04 */
    __IO uint32_t CLR;                               /**< LOCKOUT Register, offset: 0xB08 */
    __IO uint32_t TOG;                               /**< LOCKOUT Register, offset: 0xB0C */
  } LOCKOUT;
       uint8_t RESERVED_11[8432];
                                                     /**< Single small clock root divider slices (divide by 31)., array offset: 0x2C00, array step: 0x4 */
  __IO uint32_t SSSLICE_CTRL[FSL_FEATURE_DSC_SSSLICE_CNT];
       uint32_t RESERVED_12[256 - FSL_FEATURE_DSC_SSSLICE_CNT];
                                                     /**< Single large clock root divider slices (divide by 255)., array offset: 0x3000, array step: 0x4 */
  __IO uint32_t SLSLICE_CTRL[FSL_FEATURE_DSC_SLSLICE_CNT];
       uint32_t RESERVED_13[256 - FSL_FEATURE_DSC_SLSLICE_CNT];
  struct {                                         /* offset: 0x3400, array step: 0x8 */
    __IO uint32_t MSLICE_CTRL__0;                    /**< Muliple synchronous clock root divider slices register., array offset: 0x3400, array step: 0x8 */
    __IO uint32_t MSLICE_CTRL__1;                    /**< Muliple synchronous clock root divider slices register., array offset: 0x3404, array step: 0x8 */
  } MSLICE_CTRL[1];
       uint8_t RESERVED_14[1016];
                                                     /**< CPU clock root divider slices., array offset: 0x3800, array step: 0x4 */
  __IO uint32_t CSLICE_CTRL[FSL_FEATURE_DSC_CSLICE_CNT];
       uint32_t RESERVED_15[256 - FSL_FEATURE_DSC_CSLICE_CNT];
  __IO uint32_t XTAL_CTRL;                         /**< Xtal control register., offset: 0x3C00 */
       uint8_t RESERVED_16[1020];
  __IO uint32_t ROSC_CTRL;                         /**< Ring oscillator control register., offset: 0x4000 */
       uint8_t RESERVED_17[14332];
  __I  uint32_t STATUS_0;                          /**< STATUS_0, offset: 0x7800 */
       uint8_t RESERVED_18[1020];
  __IO uint32_t DFT_CTRL;                          /**< DFT Control, offset: 0x7C00 */
} DSC_Type;

/* ----------------------------------------------------------------------------
   -- DSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSC_Register_Masks DSC Register Masks
 * @{
 */

/*! @name RST_CTRL_SLICE_RSTN - Reset Control: MSlice and CSlice resetn bits */
#define DSC_RST_CTRL_SLICE_RSTN_CSLICE_RSTN_MASK (0x1U)
#define DSC_RST_CTRL_SLICE_RSTN_CSLICE_RSTN_SHIFT (0U)
#define DSC_RST_CTRL_SLICE_RSTN_CSLICE_RSTN(x)   (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLICE_RSTN_CSLICE_RSTN_SHIFT)) & DSC_RST_CTRL_SLICE_RSTN_CSLICE_RSTN_MASK)
#define DSC_RST_CTRL_SLICE_RSTN_MSLICE_RSTN_MASK (0x10000U)
#define DSC_RST_CTRL_SLICE_RSTN_MSLICE_RSTN_SHIFT (16U)
#define DSC_RST_CTRL_SLICE_RSTN_MSLICE_RSTN(x)   (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLICE_RSTN_MSLICE_RSTN_SHIFT)) & DSC_RST_CTRL_SLICE_RSTN_MSLICE_RSTN_MASK)

/*! @name RST_CTRL_SLSLICE_RSTN - Reset Control: SLSlice resetn bits */
#define DSC_RST_CTRL_SLSLICE_RSTN_SLSLICE_RSTN_MASK (0x1FFFFU)
#define DSC_RST_CTRL_SLSLICE_RSTN_SLSLICE_RSTN_SHIFT (0U)
#define DSC_RST_CTRL_SLSLICE_RSTN_SLSLICE_RSTN(x) (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLSLICE_RSTN_SLSLICE_RSTN_SHIFT)) & DSC_RST_CTRL_SLSLICE_RSTN_SLSLICE_RSTN_MASK)

/*! @name RST_CTRL_SSSLICE_RSTN - Reset Control: SSSlice resetn bits */
#define DSC_RST_CTRL_SSSLICE_RSTN_SSSLICE_RSTN_MASK (0xFFU)
#define DSC_RST_CTRL_SSSLICE_RSTN_SSSLICE_RSTN_SHIFT (0U)
#define DSC_RST_CTRL_SSSLICE_RSTN_SSSLICE_RSTN(x) (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SSSLICE_RSTN_SSSLICE_RSTN_SHIFT)) & DSC_RST_CTRL_SSSLICE_RSTN_SSSLICE_RSTN_MASK)

/*! @name RST_CTRL_CR_RSTN - Reset Control: Clock Root reset bits. */
#define DSC_RST_CTRL_CR_RSTN_XTAL32K_SS_RSTN_MASK (0x1U)
#define DSC_RST_CTRL_CR_RSTN_XTAL32K_SS_RSTN_SHIFT (0U)
#define DSC_RST_CTRL_CR_RSTN_XTAL32K_SS_RSTN(x)  (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_RSTN_XTAL32K_SS_RSTN_SHIFT)) & DSC_RST_CTRL_CR_RSTN_XTAL32K_SS_RSTN_MASK)
#define DSC_RST_CTRL_CR_RSTN_XTAL24M_SS_RSTN_MASK (0x4U)
#define DSC_RST_CTRL_CR_RSTN_XTAL24M_SS_RSTN_SHIFT (2U)
#define DSC_RST_CTRL_CR_RSTN_XTAL24M_SS_RSTN(x)  (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_RSTN_XTAL24M_SS_RSTN_SHIFT)) & DSC_RST_CTRL_CR_RSTN_XTAL24M_SS_RSTN_MASK)
#define DSC_RST_CTRL_CR_RSTN_XTAL24M_ANA_RSTN_MASK (0x8U)
#define DSC_RST_CTRL_CR_RSTN_XTAL24M_ANA_RSTN_SHIFT (3U)
#define DSC_RST_CTRL_CR_RSTN_XTAL24M_ANA_RSTN(x) (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_RSTN_XTAL24M_ANA_RSTN_SHIFT)) & DSC_RST_CTRL_CR_RSTN_XTAL24M_ANA_RSTN_MASK)
#define DSC_RST_CTRL_CR_RSTN_AI_RSTN_MASK        (0xFF0U)
#define DSC_RST_CTRL_CR_RSTN_AI_RSTN_SHIFT       (4U)
#define DSC_RST_CTRL_CR_RSTN_AI_RSTN(x)          (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_RSTN_AI_RSTN_SHIFT)) & DSC_RST_CTRL_CR_RSTN_AI_RSTN_MASK)

/*! @name RST_CTRL_SS_RSTN - Reset Control: Subsystem resets */
#define DSC_RST_CTRL_SS_RSTN_SUBSYS_RSTN_MASK    (0x3FFU)
#define DSC_RST_CTRL_SS_RSTN_SUBSYS_RSTN_SHIFT   (0U)
#define DSC_RST_CTRL_SS_RSTN_SUBSYS_RSTN(x)      (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SS_RSTN_SUBSYS_RSTN_SHIFT)) & DSC_RST_CTRL_SS_RSTN_SUBSYS_RSTN_MASK)

/*! @name RST_CTRL_SLICE_SFCM - Reset Control: MSlice and CSlice select functional clock mux bits. */
#define DSC_RST_CTRL_SLICE_SFCM_CSLICE_SFCM_MASK (0x1U)
#define DSC_RST_CTRL_SLICE_SFCM_CSLICE_SFCM_SHIFT (0U)
#define DSC_RST_CTRL_SLICE_SFCM_CSLICE_SFCM(x)   (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLICE_SFCM_CSLICE_SFCM_SHIFT)) & DSC_RST_CTRL_SLICE_SFCM_CSLICE_SFCM_MASK)
#define DSC_RST_CTRL_SLICE_SFCM_MSLICE_SFCM_MASK (0x10000U)
#define DSC_RST_CTRL_SLICE_SFCM_MSLICE_SFCM_SHIFT (16U)
#define DSC_RST_CTRL_SLICE_SFCM_MSLICE_SFCM(x)   (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLICE_SFCM_MSLICE_SFCM_SHIFT)) & DSC_RST_CTRL_SLICE_SFCM_MSLICE_SFCM_MASK)

/*! @name RST_CTRL_SLSLICE_SFCM - Reset Control: SLSlice select functional clock mux bits. */
#define DSC_RST_CTRL_SLSLICE_SFCM_SLSLICE_SFCM_MASK (0x1FFFFU)
#define DSC_RST_CTRL_SLSLICE_SFCM_SLSLICE_SFCM_SHIFT (0U)
#define DSC_RST_CTRL_SLSLICE_SFCM_SLSLICE_SFCM(x) (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLSLICE_SFCM_SLSLICE_SFCM_SHIFT)) & DSC_RST_CTRL_SLSLICE_SFCM_SLSLICE_SFCM_MASK)

/*! @name RST_CTRL_SSSLICE_SFCM - Reset Control: SSSlice select functional clock mux bits. */
#define DSC_RST_CTRL_SSSLICE_SFCM_SSSLICE_SFCM_MASK (0xFFU)
#define DSC_RST_CTRL_SSSLICE_SFCM_SSSLICE_SFCM_SHIFT (0U)
#define DSC_RST_CTRL_SSSLICE_SFCM_SSSLICE_SFCM(x) (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SSSLICE_SFCM_SSSLICE_SFCM_SHIFT)) & DSC_RST_CTRL_SSSLICE_SFCM_SSSLICE_SFCM_MASK)

/*! @name RST_CTRL_CR_SFCM - Reset Control: Select Functional Clock mux for root clocks. */
#define DSC_RST_CTRL_CR_SFCM_XTAL32K_SS_SFCM_MASK (0x1U)
#define DSC_RST_CTRL_CR_SFCM_XTAL32K_SS_SFCM_SHIFT (0U)
#define DSC_RST_CTRL_CR_SFCM_XTAL32K_SS_SFCM(x)  (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_SFCM_XTAL32K_SS_SFCM_SHIFT)) & DSC_RST_CTRL_CR_SFCM_XTAL32K_SS_SFCM_MASK)
#define DSC_RST_CTRL_CR_SFCM_XTAL24M_SS_SFCM_MASK (0x4U)
#define DSC_RST_CTRL_CR_SFCM_XTAL24M_SS_SFCM_SHIFT (2U)
#define DSC_RST_CTRL_CR_SFCM_XTAL24M_SS_SFCM(x)  (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_SFCM_XTAL24M_SS_SFCM_SHIFT)) & DSC_RST_CTRL_CR_SFCM_XTAL24M_SS_SFCM_MASK)
#define DSC_RST_CTRL_CR_SFCM_XTAL24M_ANA_SFCM_MASK (0x8U)
#define DSC_RST_CTRL_CR_SFCM_XTAL24M_ANA_SFCM_SHIFT (3U)
#define DSC_RST_CTRL_CR_SFCM_XTAL24M_ANA_SFCM(x) (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_SFCM_XTAL24M_ANA_SFCM_SHIFT)) & DSC_RST_CTRL_CR_SFCM_XTAL24M_ANA_SFCM_MASK)

/*! @name RST_CTRL_SLICE_SFC - Reset Control: Mslice and Cslice Start Functional Clock bits */
#define DSC_RST_CTRL_SLICE_SFC_CSLICE_SFC_MASK   (0x1U)
#define DSC_RST_CTRL_SLICE_SFC_CSLICE_SFC_SHIFT  (0U)
#define DSC_RST_CTRL_SLICE_SFC_CSLICE_SFC(x)     (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLICE_SFC_CSLICE_SFC_SHIFT)) & DSC_RST_CTRL_SLICE_SFC_CSLICE_SFC_MASK)
#define DSC_RST_CTRL_SLICE_SFC_MSLICE_SFC_MASK   (0x10000U)
#define DSC_RST_CTRL_SLICE_SFC_MSLICE_SFC_SHIFT  (16U)
#define DSC_RST_CTRL_SLICE_SFC_MSLICE_SFC(x)     (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLICE_SFC_MSLICE_SFC_SHIFT)) & DSC_RST_CTRL_SLICE_SFC_MSLICE_SFC_MASK)

/*! @name RST_CTRL_SLSLICE_SFC - Reset Control: SSSlice Start Functional Clocks */
#define DSC_RST_CTRL_SLSLICE_SFC_SLSLICE_SFC_MASK (0x1FFFFU)
#define DSC_RST_CTRL_SLSLICE_SFC_SLSLICE_SFC_SHIFT (0U)
#define DSC_RST_CTRL_SLSLICE_SFC_SLSLICE_SFC(x)  (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SLSLICE_SFC_SLSLICE_SFC_SHIFT)) & DSC_RST_CTRL_SLSLICE_SFC_SLSLICE_SFC_MASK)

/*! @name RST_CTRL_SSSLICE_SFC - Reset Control: SSSlice start functional clocks */
#define DSC_RST_CTRL_SSSLICE_SFC_SSSLICE_SFC_MASK (0xFFU)
#define DSC_RST_CTRL_SSSLICE_SFC_SSSLICE_SFC_SHIFT (0U)
#define DSC_RST_CTRL_SSSLICE_SFC_SSSLICE_SFC(x)  (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_SSSLICE_SFC_SSSLICE_SFC_SHIFT)) & DSC_RST_CTRL_SSSLICE_SFC_SSSLICE_SFC_MASK)

/*! @name RST_CTRL_CR_SFC - Reset Control: Start Functional Clock bits for root clocks. */
#define DSC_RST_CTRL_CR_SFC_XTAL32K_SS_SFC_MASK  (0x1U)
#define DSC_RST_CTRL_CR_SFC_XTAL32K_SS_SFC_SHIFT (0U)
#define DSC_RST_CTRL_CR_SFC_XTAL32K_SS_SFC(x)    (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_SFC_XTAL32K_SS_SFC_SHIFT)) & DSC_RST_CTRL_CR_SFC_XTAL32K_SS_SFC_MASK)
#define DSC_RST_CTRL_CR_SFC_XTAL24M_SS_SFC_MASK  (0x4U)
#define DSC_RST_CTRL_CR_SFC_XTAL24M_SS_SFC_SHIFT (2U)
#define DSC_RST_CTRL_CR_SFC_XTAL24M_SS_SFC(x)    (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_SFC_XTAL24M_SS_SFC_SHIFT)) & DSC_RST_CTRL_CR_SFC_XTAL24M_SS_SFC_MASK)
#define DSC_RST_CTRL_CR_SFC_XTAL24M_ANA_SFC_MASK (0x8U)
#define DSC_RST_CTRL_CR_SFC_XTAL24M_ANA_SFC_SHIFT (3U)
#define DSC_RST_CTRL_CR_SFC_XTAL24M_ANA_SFC(x)   (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_CR_SFC_XTAL24M_ANA_SFC_SHIFT)) & DSC_RST_CTRL_CR_SFC_XTAL24M_ANA_SFC_MASK)

/*! @name RST_CTRL_RESET_CLK_EN - Reset Control: Enable for the reset clock. */
#define DSC_RST_CTRL_RESET_CLK_EN_RESET_CLK_EN_MASK (0x1U)
#define DSC_RST_CTRL_RESET_CLK_EN_RESET_CLK_EN_SHIFT (0U)
#define DSC_RST_CTRL_RESET_CLK_EN_RESET_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << DSC_RST_CTRL_RESET_CLK_EN_RESET_CLK_EN_SHIFT)) & DSC_RST_CTRL_RESET_CLK_EN_RESET_CLK_EN_MASK)

/*! @name POWER_CTRL - Power domain controls */
#define DSC_POWER_CTRL_PFET_LF_EN_MASK           (0x1U)
#define DSC_POWER_CTRL_PFET_LF_EN_SHIFT          (0U)
#define DSC_POWER_CTRL_PFET_LF_EN(x)             (((uint32_t)(((uint32_t)(x)) << DSC_POWER_CTRL_PFET_LF_EN_SHIFT)) & DSC_POWER_CTRL_PFET_LF_EN_MASK)
#define DSC_POWER_CTRL_PFET_HF_EN_MASK           (0x2U)
#define DSC_POWER_CTRL_PFET_HF_EN_SHIFT          (1U)
#define DSC_POWER_CTRL_PFET_HF_EN(x)             (((uint32_t)(((uint32_t)(x)) << DSC_POWER_CTRL_PFET_HF_EN_SHIFT)) & DSC_POWER_CTRL_PFET_HF_EN_MASK)
#define DSC_POWER_CTRL_INPUT_ISO_EN_MASK         (0x4U)
#define DSC_POWER_CTRL_INPUT_ISO_EN_SHIFT        (2U)
#define DSC_POWER_CTRL_INPUT_ISO_EN(x)           (((uint32_t)(((uint32_t)(x)) << DSC_POWER_CTRL_INPUT_ISO_EN_SHIFT)) & DSC_POWER_CTRL_INPUT_ISO_EN_MASK)
#define DSC_POWER_CTRL_OUTPUT_ISO_EN_MASK        (0x8U)
#define DSC_POWER_CTRL_OUTPUT_ISO_EN_SHIFT       (3U)
#define DSC_POWER_CTRL_OUTPUT_ISO_EN(x)          (((uint32_t)(((uint32_t)(x)) << DSC_POWER_CTRL_OUTPUT_ISO_EN_SHIFT)) & DSC_POWER_CTRL_OUTPUT_ISO_EN_MASK)
#define DSC_POWER_CTRL_MISC_MASK                 (0xFFFF00U)
#define DSC_POWER_CTRL_MISC_SHIFT                (8U)
#define DSC_POWER_CTRL_MISC(x)                   (((uint32_t)(((uint32_t)(x)) << DSC_POWER_CTRL_MISC_SHIFT)) & DSC_POWER_CTRL_MISC_MASK)
#define DSC_POWER_CTRL_PFET_LF_ACK_MASK          (0x40000000U)
#define DSC_POWER_CTRL_PFET_LF_ACK_SHIFT         (30U)
#define DSC_POWER_CTRL_PFET_LF_ACK(x)            (((uint32_t)(((uint32_t)(x)) << DSC_POWER_CTRL_PFET_LF_ACK_SHIFT)) & DSC_POWER_CTRL_PFET_LF_ACK_MASK)
#define DSC_POWER_CTRL_PFET_HF_ACK_MASK          (0x80000000U)
#define DSC_POWER_CTRL_PFET_HF_ACK_SHIFT         (31U)
#define DSC_POWER_CTRL_PFET_HF_ACK(x)            (((uint32_t)(((uint32_t)(x)) << DSC_POWER_CTRL_PFET_HF_ACK_SHIFT)) & DSC_POWER_CTRL_PFET_HF_ACK_MASK)

#define DSC_PWRCTRL_MEM_HS_MASK                 0x00000800U
#define DSC_PWRCTRL_MEM_LS_MASK                 0x00000400U

#define DSC_PWRCTRL_MAIN_RFF_MASK               0x00001000U
#define DSC_PWRCTRL_MAIN_SLEEP_MASK             0x00002000U
#define DSC_PWRCTRL_MAIN_STDBY_MASK             0x00004000U
#define DSC_PWRCTRL_MAIN_INPUT_GATE_MASK        0x00008000U

#define DSC_PWRCTRL_PSW_SMALL_MA_MASK           0x00010000U
#define DSC_PWRCTRL_PSW_LARGE_MA_MASK           0x00020000U
#define DSC_PWRCTRL_PSW_SMALL_MP_MASK           0x00040000U
#define DSC_PWRCTRL_PSW_LARGE_MP_MASK           0x00080000U
#define DSC_PWRCTRL_PSW_SMALL_MA_2_MASK         0x00040000U
#define DSC_PWRCTRL_PSW_LARGE_MA_2_MASK         0x00080000U
#define DSC_PWRCTRL_PSW_SMALL_MASK              0x00100000U
#define DSC_PWRCTRL_PSW_LARGE_MASK              0x00200000U

#define DSC_PWRCTRL_PSW_SMALL_MA_3_MASK         0x00400000U
#define DSC_PWRCTRL_PSW_LARGE_MA_3_MASK         0x00800000U

#define DSC_PWRCTRL_MEM_DEEP_SLEEP              0x00400000U
#define DSC_PWRCTRL_MEM_STANDBY                 0x00800000U


/* The count of DSC_POWER_CTRL */
#define DSC_POWER_CTRL_COUNT                     (6U)

/* The count of DSC_POWER_CTRL_SET */
#define DSC_POWER_CTRL_SET_COUNT                 (6U)

/* The count of DSC_POWER_CTRL_CLR */
#define DSC_POWER_CTRL_CLR_COUNT                 (6U)

/* The count of DSC_POWER_CTRL_TOG */
#define DSC_POWER_CTRL_TOG_COUNT                 (6U)

/*! @name GPR_CTRL - General purpose control register bits. */
#define DSC_GPR_CTRL_CTRL_MASK                   (0xFFFFFFFFU)
#define DSC_GPR_CTRL_CTRL_SHIFT                  (0U)
#define DSC_GPR_CTRL_CTRL(x)                     (((uint32_t)(((uint32_t)(x)) << DSC_GPR_CTRL_CTRL_SHIFT)) & DSC_GPR_CTRL_CTRL_MASK)

/* The count of DSC_GPR_CTRL_SET */
#define DSC_GPR_CTRL_SET_COUNT                   (3U)

/* The count of DSC_GPR_CTRL_CLR */
#define DSC_GPR_CTRL_CLR_COUNT                   (3U)

/* The count of DSC_GPR_CTRL_TOG */
#define DSC_GPR_CTRL_TOG_COUNT                   (3U)

/*! @name GPR_STAT - General purpose status bits. */
#define DSC_GPR_STAT_STATUS_MASK                 (0xFFFFFFFFU)
#define DSC_GPR_STAT_STATUS_SHIFT                (0U)
#define DSC_GPR_STAT_STATUS(x)                   (((uint32_t)(((uint32_t)(x)) << DSC_GPR_STAT_STATUS_SHIFT)) & DSC_GPR_STAT_STATUS_MASK)

/* The count of DSC_GPR_STAT */
#define DSC_GPR_STAT_COUNT                       (3U)

/* The count of DSC_GPR_STAT_SET */
#define DSC_GPR_STAT_SET_COUNT                   (3U)

/* The count of DSC_GPR_STAT_CLR */
#define DSC_GPR_STAT_CLR_COUNT                   (3U)

/* The count of DSC_GPR_STAT_TOG */
#define DSC_GPR_STAT_TOG_COUNT                   (3U)

/*! @name IRQ_MASK_DSC - IRQ mask register for DSC interrupts. */
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_PANIC_MASK   (0x1U)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_PANIC_SHIFT  (0U)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_PANIC(x)     (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_TEMPSENSOR_PANIC_SHIFT)) & DSC_IRQ_MASK_DSC_TEMPSENSOR_PANIC_MASK)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_LOW_MASK     (0x2U)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_LOW_SHIFT    (1U)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_LOW(x)       (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_TEMPSENSOR_LOW_SHIFT)) & DSC_IRQ_MASK_DSC_TEMPSENSOR_LOW_MASK)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_HIGH_MASK    (0x4U)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_HIGH_SHIFT   (2U)
#define DSC_IRQ_MASK_DSC_TEMPSENSOR_HIGH(x)      (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_TEMPSENSOR_HIGH_SHIFT)) & DSC_IRQ_MASK_DSC_TEMPSENSOR_HIGH_MASK)
#define DSC_IRQ_MASK_DSC_MSI_SLV_ERROR_IRQ_MASK  (0x8U)
#define DSC_IRQ_MASK_DSC_MSI_SLV_ERROR_IRQ_SHIFT (3U)
#define DSC_IRQ_MASK_DSC_MSI_SLV_ERROR_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_MSI_SLV_ERROR_IRQ_SHIFT)) & DSC_IRQ_MASK_DSC_MSI_SLV_ERROR_IRQ_MASK)
#define DSC_IRQ_MASK_DSC_MSI_SLV_WR_OVFL_IRQ_MASK (0x10U)
#define DSC_IRQ_MASK_DSC_MSI_SLV_WR_OVFL_IRQ_SHIFT (4U)
#define DSC_IRQ_MASK_DSC_MSI_SLV_WR_OVFL_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_MSI_SLV_WR_OVFL_IRQ_SHIFT)) & DSC_IRQ_MASK_DSC_MSI_SLV_WR_OVFL_IRQ_MASK)
#define DSC_IRQ_MASK_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_MASK (0x20U)
#define DSC_IRQ_MASK_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_SHIFT (5U)
#define DSC_IRQ_MASK_DSC_MSI_SLV_AHB_WR_OVFL_IRQ(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_SHIFT)) & DSC_IRQ_MASK_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_MASK)
#define DSC_IRQ_MASK_DSC_BIST_IRQ_MASK           (0x40U)
#define DSC_IRQ_MASK_DSC_BIST_IRQ_SHIFT          (6U)
#define DSC_IRQ_MASK_DSC_BIST_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_BIST_IRQ_SHIFT)) & DSC_IRQ_MASK_DSC_BIST_IRQ_MASK)
#define DSC_IRQ_MASK_DSC_PWRCTRL_PFET_LF_ACK_MASK (0x3F0000U)
#define DSC_IRQ_MASK_DSC_PWRCTRL_PFET_LF_ACK_SHIFT (16U)
#define DSC_IRQ_MASK_DSC_PWRCTRL_PFET_LF_ACK(x)  (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_PWRCTRL_PFET_LF_ACK_SHIFT)) & DSC_IRQ_MASK_DSC_PWRCTRL_PFET_LF_ACK_MASK)
#define DSC_IRQ_MASK_DSC_PWRCTRL_PFET_HF_ACK_MASK (0x3F000000U)
#define DSC_IRQ_MASK_DSC_PWRCTRL_PFET_HF_ACK_SHIFT (24U)
#define DSC_IRQ_MASK_DSC_PWRCTRL_PFET_HF_ACK(x)  (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_DSC_PWRCTRL_PFET_HF_ACK_SHIFT)) & DSC_IRQ_MASK_DSC_PWRCTRL_PFET_HF_ACK_MASK)

/*! @name IRQ_MASK_SUBSYS - IRQ mask register for Subsystem interrupts. */
#define DSC_IRQ_MASK_SUBSYS_SUBSYS_MASK          (0xFFFFFFFU)
#define DSC_IRQ_MASK_SUBSYS_SUBSYS_SHIFT         (0U)
#define DSC_IRQ_MASK_SUBSYS_SUBSYS(x)            (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_SUBSYS_SUBSYS_SHIFT)) & DSC_IRQ_MASK_SUBSYS_SUBSYS_MASK)

/*! @name IRQ_MASK_STATUS_DSC - IRQ masked status register for DSC interrupts. */
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_PANIC_MASK (0x1U)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_PANIC_SHIFT (0U)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_PANIC(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_PANIC_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_PANIC_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_LOW_MASK (0x2U)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_LOW_SHIFT (1U)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_LOW(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_LOW_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_LOW_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_HIGH_MASK (0x4U)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_HIGH_SHIFT (2U)
#define DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_HIGH(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_HIGH_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_TEMPSENSOR_HIGH_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_MASK (0x8U)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_SHIFT (3U)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_ERROR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_MASK (0x10U)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_SHIFT (4U)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_MASK (0x20U)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_SHIFT (5U)
#define DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_BIST_IRQ_MASK    (0x40U)
#define DSC_IRQ_MASK_STATUS_DSC_BIST_IRQ_SHIFT   (6U)
#define DSC_IRQ_MASK_STATUS_DSC_BIST_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_BIST_IRQ_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_BIST_IRQ_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_MASK (0x3F0000U)
#define DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_SHIFT (16U)
#define DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_MASK)
#define DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_MASK (0x3F000000U)
#define DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_SHIFT (24U)
#define DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_SHIFT)) & DSC_IRQ_MASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_MASK)

/*! @name IRQ_MASK_STATUS_SUBSYS - IRQ masked status register for Subsystem interrupts. */
#define DSC_IRQ_MASK_STATUS_SUBSYS_SUBSYS_MASK   (0xFFFFFFFU)
#define DSC_IRQ_MASK_STATUS_SUBSYS_SUBSYS_SHIFT  (0U)
#define DSC_IRQ_MASK_STATUS_SUBSYS_SUBSYS(x)     (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_MASK_STATUS_SUBSYS_SUBSYS_SHIFT)) & DSC_IRQ_MASK_STATUS_SUBSYS_SUBSYS_MASK)

/*! @name IRQ_NONMASK_STATUS_DSC - IRQ non-masked status register for DSC interrupts. */
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_PANIC_MASK (0x1U)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_PANIC_SHIFT (0U)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_PANIC(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_PANIC_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_PANIC_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_LOW_MASK (0x2U)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_LOW_SHIFT (1U)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_LOW(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_LOW_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_LOW_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_HIGH_MASK (0x4U)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_HIGH_SHIFT (2U)
#define DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_HIGH(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_HIGH_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_TEMPSENSOR_HIGH_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_MASK (0x8U)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_SHIFT (3U)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_ERROR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_ERROR_IRQ_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_MASK (0x10U)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_SHIFT (4U)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_WR_OVFL_IRQ_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_MASK (0x20U)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_SHIFT (5U)
#define DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_MSI_SLV_AHB_WR_OVFL_IRQ_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_BIST_IRQ_MASK (0x40U)
#define DSC_IRQ_NONMASK_STATUS_DSC_BIST_IRQ_SHIFT (6U)
#define DSC_IRQ_NONMASK_STATUS_DSC_BIST_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_BIST_IRQ_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_BIST_IRQ_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_MASK (0x3F0000U)
#define DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_SHIFT (16U)
#define DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_LF_ACK_MASK)
#define DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_MASK (0x3F000000U)
#define DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_SHIFT (24U)
#define DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK(x) (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_SHIFT)) & DSC_IRQ_NONMASK_STATUS_DSC_PWRCTRL_PFET_HF_ACK_MASK)

/*! @name IRQ_NONMASK_STATUS_SUBSYS - IRQ non-masked status register for Subsystem interrupts. */
#define DSC_IRQ_NONMASK_STATUS_SUBSYS_SUBSYS_MASK (0xFFFFFFFU)
#define DSC_IRQ_NONMASK_STATUS_SUBSYS_SUBSYS_SHIFT (0U)
#define DSC_IRQ_NONMASK_STATUS_SUBSYS_SUBSYS(x)  (((uint32_t)(((uint32_t)(x)) << DSC_IRQ_NONMASK_STATUS_SUBSYS_SUBSYS_SHIFT)) & DSC_IRQ_NONMASK_STATUS_SUBSYS_SUBSYS_MASK)

/*! @name AI_CTRL - Analog Interface Control Registers */
#define DSC_AI_CTRL_ADDR_MASK                    (0xFFFFU)
#define DSC_AI_CTRL_ADDR_SHIFT                   (0U)
#define DSC_AI_CTRL_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DSC_AI_CTRL_ADDR_SHIFT)) & DSC_AI_CTRL_ADDR_MASK)
#define DSC_AI_CTRL_SRC_SEL_MASK                 (0x1F0000U)
#define DSC_AI_CTRL_SRC_SEL_SHIFT                (16U)
#define DSC_AI_CTRL_SRC_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << DSC_AI_CTRL_SRC_SEL_SHIFT)) & DSC_AI_CTRL_SRC_SEL_MASK)
#define DSC_AI_CTRL_RWB_MASK                     (0x80000000U)
#define DSC_AI_CTRL_RWB_SHIFT                    (31U)
#define DSC_AI_CTRL_RWB(x)                       (((uint32_t)(((uint32_t)(x)) << DSC_AI_CTRL_RWB_SHIFT)) & DSC_AI_CTRL_RWB_MASK)

/*! @name AI_WR_DATA - Analog Interface Registers */
#define DSC_AI_WR_DATA_WR_DATA_MASK              (0xFFFFFFFFU)
#define DSC_AI_WR_DATA_WR_DATA_SHIFT             (0U)
#define DSC_AI_WR_DATA_WR_DATA(x)                (((uint32_t)(((uint32_t)(x)) << DSC_AI_WR_DATA_WR_DATA_SHIFT)) & DSC_AI_WR_DATA_WR_DATA_MASK)

/*! @name AI_TOGGLE - Analog Interface Registers */
#define DSC_AI_TOGGLE_TOGGLE_MASK                (0xFFFFFFFFU)
#define DSC_AI_TOGGLE_TOGGLE_SHIFT               (0U)
#define DSC_AI_TOGGLE_TOGGLE(x)                  (((uint32_t)(((uint32_t)(x)) << DSC_AI_TOGGLE_TOGGLE_SHIFT)) & DSC_AI_TOGGLE_TOGGLE_MASK)

/*! @name AI_DONE_TOGGLE - Analog Interface Registers */
#define DSC_AI_DONE_TOGGLE_DONE_TOGGLE_MASK      (0xFFFFFFFFU)
#define DSC_AI_DONE_TOGGLE_DONE_TOGGLE_SHIFT     (0U)
#define DSC_AI_DONE_TOGGLE_DONE_TOGGLE(x)        (((uint32_t)(((uint32_t)(x)) << DSC_AI_DONE_TOGGLE_DONE_TOGGLE_SHIFT)) & DSC_AI_DONE_TOGGLE_DONE_TOGGLE_MASK)

/*! @name AI_RD_DATA - Analog Interface Registers */
#define DSC_AI_RD_DATA_RD_DATA_MASK              (0xFFFFFFFFU)
#define DSC_AI_RD_DATA_RD_DATA_SHIFT             (0U)
#define DSC_AI_RD_DATA_RD_DATA(x)                (((uint32_t)(((uint32_t)(x)) << DSC_AI_RD_DATA_RD_DATA_SHIFT)) & DSC_AI_RD_DATA_RD_DATA_MASK)

/*! @name AI_BUSY - Analog Interface Registers */
#define DSC_AI_BUSY_BUSY_MASK                    (0xFFFFFFFFU)
#define DSC_AI_BUSY_BUSY_SHIFT                   (0U)
#define DSC_AI_BUSY_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << DSC_AI_BUSY_BUSY_SHIFT)) & DSC_AI_BUSY_BUSY_MASK)

/*! @name LOCKOUT - LOCKOUT Register */
#define DSC_LOCKOUT_LOCKOUT_MASK                 (0xFFU)
#define DSC_LOCKOUT_LOCKOUT_SHIFT                (0U)
#define DSC_LOCKOUT_LOCKOUT(x)                   (((uint32_t)(((uint32_t)(x)) << DSC_LOCKOUT_LOCKOUT_SHIFT)) & DSC_LOCKOUT_LOCKOUT_MASK)
#define DSC_LOCKOUT_LOCKOUT_EN_MASK              (0x80000000U)
#define DSC_LOCKOUT_LOCKOUT_EN_SHIFT             (31U)
#define DSC_LOCKOUT_LOCKOUT_EN(x)                (((uint32_t)(((uint32_t)(x)) << DSC_LOCKOUT_LOCKOUT_EN_SHIFT)) & DSC_LOCKOUT_LOCKOUT_EN_MASK)

/*! @name SSSLICE_CTRL - Single small clock root divider slices (divide by 31). */
#define DSC_SSSLICE_CTRL_SSDIV_MASK              (0x1FU)
#define DSC_SSSLICE_CTRL_SSDIV_SHIFT             (0U)
#define DSC_SSSLICE_CTRL_SSDIV(x)                (((uint32_t)(((uint32_t)(x)) << DSC_SSSLICE_CTRL_SSDIV_SHIFT)) & DSC_SSSLICE_CTRL_SSDIV_MASK)
#define DSC_SSSLICE_CTRL_SRC_SEL_MASK            (0x1C000000U)
#define DSC_SSSLICE_CTRL_SRC_SEL_SHIFT           (26U)
#define DSC_SSSLICE_CTRL_SRC_SEL(x)              (((uint32_t)(((uint32_t)(x)) << DSC_SSSLICE_CTRL_SRC_SEL_SHIFT)) & DSC_SSSLICE_CTRL_SRC_SEL_MASK)
#define DSC_SSSLICE_CTRL_HW_SEL_MASK             (0x20000000U)
#define DSC_SSSLICE_CTRL_HW_SEL_SHIFT            (29U)
#define DSC_SSSLICE_CTRL_HW_SEL(x)               (((uint32_t)(((uint32_t)(x)) << DSC_SSSLICE_CTRL_HW_SEL_SHIFT)) & DSC_SSSLICE_CTRL_HW_SEL_MASK)
#define DSC_SSSLICE_CTRL_FW_SEL_MASK             (0xC0000000U)
#define DSC_SSSLICE_CTRL_FW_SEL_SHIFT            (30U)
#define DSC_SSSLICE_CTRL_FW_SEL(x)               (((uint32_t)(((uint32_t)(x)) << DSC_SSSLICE_CTRL_FW_SEL_SHIFT)) & DSC_SSSLICE_CTRL_FW_SEL_MASK)

/* The count of DSC_SSSLICE_CTRL */
#define DSC_SSSLICE_CTRL_COUNT                   (8U)

/*! @name SLSLICE_CTRL - Single large clock root divider slices (divide by 255). */
#define DSC_SLSLICE_CTRL_SLDIV_MASK              (0xFFU)
#define DSC_SLSLICE_CTRL_SLDIV_SHIFT             (0U)
#define DSC_SLSLICE_CTRL_SLDIV(x)                (((uint32_t)(((uint32_t)(x)) << DSC_SLSLICE_CTRL_SLDIV_SHIFT)) & DSC_SLSLICE_CTRL_SLDIV_MASK)
#define DSC_SLSLICE_CTRL_SRC_SEL_MASK            (0x1C000000U)
#define DSC_SLSLICE_CTRL_SRC_SEL_SHIFT           (26U)
#define DSC_SLSLICE_CTRL_SRC_SEL(x)              (((uint32_t)(((uint32_t)(x)) << DSC_SLSLICE_CTRL_SRC_SEL_SHIFT)) & DSC_SLSLICE_CTRL_SRC_SEL_MASK)
#define DSC_SLSLICE_CTRL_HW_SEL_MASK             (0x20000000U)
#define DSC_SLSLICE_CTRL_HW_SEL_SHIFT            (29U)
#define DSC_SLSLICE_CTRL_HW_SEL(x)               (((uint32_t)(((uint32_t)(x)) << DSC_SLSLICE_CTRL_HW_SEL_SHIFT)) & DSC_SLSLICE_CTRL_HW_SEL_MASK)
#define DSC_SLSLICE_CTRL_FW_SEL_MASK             (0xC0000000U)
#define DSC_SLSLICE_CTRL_FW_SEL_SHIFT            (30U)
#define DSC_SLSLICE_CTRL_FW_SEL(x)               (((uint32_t)(((uint32_t)(x)) << DSC_SLSLICE_CTRL_FW_SEL_SHIFT)) & DSC_SLSLICE_CTRL_FW_SEL_MASK)

/* The count of DSC_SLSLICE_CTRL */
#define DSC_SLSLICE_CTRL_COUNT                   (17U)

/*! @name MSLICE_CTRL__0 - Muliple synchronous clock root divider slices register. */
#define DSC_MSLICE_CTRL__0_DIV_ROOT0_MASK        (0x1FU)
#define DSC_MSLICE_CTRL__0_DIV_ROOT0_SHIFT       (0U)
#define DSC_MSLICE_CTRL__0_DIV_ROOT0(x)          (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__0_DIV_ROOT0_SHIFT)) & DSC_MSLICE_CTRL__0_DIV_ROOT0_MASK)
#define DSC_MSLICE_CTRL__0_DIV_ROOT1_MASK        (0x3E0U)
#define DSC_MSLICE_CTRL__0_DIV_ROOT1_SHIFT       (5U)
#define DSC_MSLICE_CTRL__0_DIV_ROOT1(x)          (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__0_DIV_ROOT1_SHIFT)) & DSC_MSLICE_CTRL__0_DIV_ROOT1_MASK)

/* The count of DSC_MSLICE_CTRL__0 */
#define DSC_MSLICE_CTRL__0_COUNT                 (1U)

/*! @name MSLICE_CTRL__1 - Muliple synchronous clock root divider slices register. */
#define DSC_MSLICE_CTRL__1_DIV_ROOT2_MASK        (0x1FU)
#define DSC_MSLICE_CTRL__1_DIV_ROOT2_SHIFT       (0U)
#define DSC_MSLICE_CTRL__1_DIV_ROOT2(x)          (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__1_DIV_ROOT2_SHIFT)) & DSC_MSLICE_CTRL__1_DIV_ROOT2_MASK)
#define DSC_MSLICE_CTRL__1_DIV_ROOT3_MASK        (0x3E0U)
#define DSC_MSLICE_CTRL__1_DIV_ROOT3_SHIFT       (5U)
#define DSC_MSLICE_CTRL__1_DIV_ROOT3(x)          (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__1_DIV_ROOT3_SHIFT)) & DSC_MSLICE_CTRL__1_DIV_ROOT3_MASK)
#define DSC_MSLICE_CTRL__1_SYS_CTR_CLK_SEL_MASK  (0x2000000U)
#define DSC_MSLICE_CTRL__1_SYS_CTR_CLK_SEL_SHIFT (25U)
#define DSC_MSLICE_CTRL__1_SYS_CTR_CLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__1_SYS_CTR_CLK_SEL_SHIFT)) & DSC_MSLICE_CTRL__1_SYS_CTR_CLK_SEL_MASK)
#define DSC_MSLICE_CTRL__1_SRC_SEL_MASK          (0x1C000000U)
#define DSC_MSLICE_CTRL__1_SRC_SEL_SHIFT         (26U)
#define DSC_MSLICE_CTRL__1_SRC_SEL(x)            (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__1_SRC_SEL_SHIFT)) & DSC_MSLICE_CTRL__1_SRC_SEL_MASK)
#define DSC_MSLICE_CTRL__1_HW_SEL_MASK           (0x20000000U)
#define DSC_MSLICE_CTRL__1_HW_SEL_SHIFT          (29U)
#define DSC_MSLICE_CTRL__1_HW_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__1_HW_SEL_SHIFT)) & DSC_MSLICE_CTRL__1_HW_SEL_MASK)
#define DSC_MSLICE_CTRL__1_FW_SEL_MASK           (0xC0000000U)
#define DSC_MSLICE_CTRL__1_FW_SEL_SHIFT          (30U)
#define DSC_MSLICE_CTRL__1_FW_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DSC_MSLICE_CTRL__1_FW_SEL_SHIFT)) & DSC_MSLICE_CTRL__1_FW_SEL_MASK)

/* The count of DSC_MSLICE_CTRL__1 */
#define DSC_MSLICE_CTRL__1_COUNT                 (1U)

/*! @name CSLICE_CTRL - CPU clock root divider slices. */
#define DSC_CSLICE_CTRL_SRC_SEL_MASK             (0x1C000000U)
#define DSC_CSLICE_CTRL_SRC_SEL_SHIFT            (26U)
#define DSC_CSLICE_CTRL_SRC_SEL(x)               (((uint32_t)(((uint32_t)(x)) << DSC_CSLICE_CTRL_SRC_SEL_SHIFT)) & DSC_CSLICE_CTRL_SRC_SEL_MASK)
#define DSC_CSLICE_CTRL_HW_SEL_MASK              (0x20000000U)
#define DSC_CSLICE_CTRL_HW_SEL_SHIFT             (29U)
#define DSC_CSLICE_CTRL_HW_SEL(x)                (((uint32_t)(((uint32_t)(x)) << DSC_CSLICE_CTRL_HW_SEL_SHIFT)) & DSC_CSLICE_CTRL_HW_SEL_MASK)
#define DSC_CSLICE_CTRL_FW_SEL_MASK              (0xC0000000U)
#define DSC_CSLICE_CTRL_FW_SEL_SHIFT             (30U)
#define DSC_CSLICE_CTRL_FW_SEL(x)                (((uint32_t)(((uint32_t)(x)) << DSC_CSLICE_CTRL_FW_SEL_SHIFT)) & DSC_CSLICE_CTRL_FW_SEL_MASK)

/* The count of DSC_CSLICE_CTRL */
#define DSC_CSLICE_CTRL_COUNT                    (1U)

/*! @name XTAL_CTRL - Xtal control register. */
#define DSC_XTAL_CTRL_GLBL_ANA_XTAL24M_EN_MASK   (0x1U)
#define DSC_XTAL_CTRL_GLBL_ANA_XTAL24M_EN_SHIFT  (0U)
#define DSC_XTAL_CTRL_GLBL_ANA_XTAL24M_EN(x)     (((uint32_t)(((uint32_t)(x)) << DSC_XTAL_CTRL_GLBL_ANA_XTAL24M_EN_SHIFT)) & DSC_XTAL_CTRL_GLBL_ANA_XTAL24M_EN_MASK)
#define DSC_XTAL_CTRL_DSC_AON_XTAL24M_EN_MASK    (0x2U)
#define DSC_XTAL_CTRL_DSC_AON_XTAL24M_EN_SHIFT   (1U)
#define DSC_XTAL_CTRL_DSC_AON_XTAL24M_EN(x)      (((uint32_t)(((uint32_t)(x)) << DSC_XTAL_CTRL_DSC_AON_XTAL24M_EN_SHIFT)) & DSC_XTAL_CTRL_DSC_AON_XTAL24M_EN_MASK)
#define DSC_XTAL_CTRL_DSC_PG_XTAL24M_EN_MASK     (0x4U)
#define DSC_XTAL_CTRL_DSC_PG_XTAL24M_EN_SHIFT    (2U)
#define DSC_XTAL_CTRL_DSC_PG_XTAL24M_EN(x)       (((uint32_t)(((uint32_t)(x)) << DSC_XTAL_CTRL_DSC_PG_XTAL24M_EN_SHIFT)) & DSC_XTAL_CTRL_DSC_PG_XTAL24M_EN_MASK)
#define DSC_XTAL_CTRL_ANALOG_XTAL24M_EN_MASK     (0x8U)
#define DSC_XTAL_CTRL_ANALOG_XTAL24M_EN_SHIFT    (3U)
#define DSC_XTAL_CTRL_ANALOG_XTAL24M_EN(x)       (((uint32_t)(((uint32_t)(x)) << DSC_XTAL_CTRL_ANALOG_XTAL24M_EN_SHIFT)) & DSC_XTAL_CTRL_ANALOG_XTAL24M_EN_MASK)
#define DSC_XTAL_CTRL_OSC_XTAL24M_EN_MASK        (0x100U)
#define DSC_XTAL_CTRL_OSC_XTAL24M_EN_SHIFT       (8U)
#define DSC_XTAL_CTRL_OSC_XTAL24M_EN(x)          (((uint32_t)(((uint32_t)(x)) << DSC_XTAL_CTRL_OSC_XTAL24M_EN_SHIFT)) & DSC_XTAL_CTRL_OSC_XTAL24M_EN_MASK)
#define DSC_XTAL_CTRL_OSC_XTAL32K_SFC_SEL_MASK   (0x10000U)
#define DSC_XTAL_CTRL_OSC_XTAL32K_SFC_SEL_SHIFT  (16U)
#define DSC_XTAL_CTRL_OSC_XTAL32K_SFC_SEL(x)     (((uint32_t)(((uint32_t)(x)) << DSC_XTAL_CTRL_OSC_XTAL32K_SFC_SEL_SHIFT)) & DSC_XTAL_CTRL_OSC_XTAL32K_SFC_SEL_MASK)
#define DSC_XTAL_CTRL_XTAL32K_SYNC_SEL_MASK      (0x80000000U)
#define DSC_XTAL_CTRL_XTAL32K_SYNC_SEL_SHIFT     (31U)
#define DSC_XTAL_CTRL_XTAL32K_SYNC_SEL(x)        (((uint32_t)(((uint32_t)(x)) << DSC_XTAL_CTRL_XTAL32K_SYNC_SEL_SHIFT)) & DSC_XTAL_CTRL_XTAL32K_SYNC_SEL_MASK)

/*! @name ROSC_CTRL - Ring oscillator control register. */
#define DSC_ROSC_CTRL_ROSC_START_EN_MASK         (0x1U)
#define DSC_ROSC_CTRL_ROSC_START_EN_SHIFT        (0U)
#define DSC_ROSC_CTRL_ROSC_START_EN(x)           (((uint32_t)(((uint32_t)(x)) << DSC_ROSC_CTRL_ROSC_START_EN_SHIFT)) & DSC_ROSC_CTRL_ROSC_START_EN_MASK)
#define DSC_ROSC_CTRL_ROSC_STOP_EN_MASK          (0x2U)
#define DSC_ROSC_CTRL_ROSC_STOP_EN_SHIFT         (1U)
#define DSC_ROSC_CTRL_ROSC_STOP_EN(x)            (((uint32_t)(((uint32_t)(x)) << DSC_ROSC_CTRL_ROSC_STOP_EN_SHIFT)) & DSC_ROSC_CTRL_ROSC_STOP_EN_MASK)

/*! @name STATUS_0 - STATUS_0 */
#define DSC_STATUS_0_DSC_HM_TYPE_MASK            (0xFU)
#define DSC_STATUS_0_DSC_HM_TYPE_SHIFT           (0U)
#define DSC_STATUS_0_DSC_HM_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << DSC_STATUS_0_DSC_HM_TYPE_SHIFT)) & DSC_STATUS_0_DSC_HM_TYPE_MASK)

/*! @name DFT_CTRL - DFT Control */
#define DSC_DFT_CTRL_TCU_RSTN_MASK               (0x1U)
#define DSC_DFT_CTRL_TCU_RSTN_SHIFT              (0U)
#define DSC_DFT_CTRL_TCU_RSTN(x)                 (((uint32_t)(((uint32_t)(x)) << DSC_DFT_CTRL_TCU_RSTN_SHIFT)) & DSC_DFT_CTRL_TCU_RSTN_MASK)
#define DSC_DFT_CTRL_BI_BIST_MODE_MASK           (0x2U)
#define DSC_DFT_CTRL_BI_BIST_MODE_SHIFT          (1U)
#define DSC_DFT_CTRL_BI_BIST_MODE(x)             (((uint32_t)(((uint32_t)(x)) << DSC_DFT_CTRL_BI_BIST_MODE_SHIFT)) & DSC_DFT_CTRL_BI_BIST_MODE_MASK)
#define DSC_DFT_CTRL_BI_DC_SCAN_MODE_MASK        (0x4U)
#define DSC_DFT_CTRL_BI_DC_SCAN_MODE_SHIFT       (2U)
#define DSC_DFT_CTRL_BI_DC_SCAN_MODE(x)          (((uint32_t)(((uint32_t)(x)) << DSC_DFT_CTRL_BI_DC_SCAN_MODE_SHIFT)) & DSC_DFT_CTRL_BI_DC_SCAN_MODE_MASK)
#define DSC_DFT_CTRL_BI_IO_EN_MASK               (0x8U)
#define DSC_DFT_CTRL_BI_IO_EN_SHIFT              (3U)
#define DSC_DFT_CTRL_BI_IO_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DSC_DFT_CTRL_BI_IO_EN_SHIFT)) & DSC_DFT_CTRL_BI_IO_EN_MASK)

/*!
 * @}
 */ /* end of group DSC_Register_Masks */

/* DSC - Peripheral instance base addresses */
/** Peripheral dsc base pointer */
#define DSC1                                     ((DSC_Type *)DSC1_BASE)
/** Peripheral dsc base pointer */
#define DSC2                                     ((DSC_Type *)DSC2_BASE)
/** Peripheral dsc base pointer */
#define DSC3                                     ((DSC_Type *)DSC3_BASE)
/** Peripheral dsc base pointer */
#define DSC4                                     ((DSC_Type *)DSC4_BASE)
/** Peripheral dsc base pointer */
#define DSC5                                     ((DSC_Type *)DSC5_BASE)
/** Peripheral dsc base pointer */
#define DSC6                                     ((DSC_Type *)DSC6_BASE)
/** Peripheral dsc base pointer */
#define DSC7                                     ((DSC_Type *)DSC7_BASE)
/** Peripheral dsc base pointer */
#define DSC8                                     ((DSC_Type *)DSC8_BASE)
/** Peripheral dsc base pointer */
#define DSC9                                     ((DSC_Type *)DSC9_BASE)
/** Peripheral dsc base pointer */
#define DSC10                                    ((DSC_Type *)DSC10_BASE)
/** Peripheral dsc base pointer */
#define DSC11                                    ((DSC_Type *)DSC11_BASE)
/** Peripheral dsc base pointer */
#define DSC12                                    ((DSC_Type *)DSC12_BASE)
/** Peripheral dsc base pointer */
#define DSC13                                    ((DSC_Type *)DSC13_BASE)
/** Peripheral dsc base pointer */
#define DSC14                                    ((DSC_Type *)DSC14_BASE)
/** Peripheral dsc base pointer */
#define DSC15                                    ((DSC_Type *)DSC15_BASE)
/** Peripheral dsc base pointer */
#define DSC17                                    ((DSC_Type *)DSC17_BASE)
/** Peripheral dsc base pointer */
#define DSC18                                    ((DSC_Type *)DSC18_BASE)
/** Peripheral dsc base pointer */
#define DSC19                                    ((DSC_Type *)DSC19_BASE)
/** Peripheral dsc base pointer */
#define DSC20                                    ((DSC_Type *)DSC20_BASE)
/** Peripheral dsc base pointer */
#define DSC21                                    ((DSC_Type *)DSC21_BASE)
/** Peripheral dsc base pointer */
#define DSC22                                    ((DSC_Type *)DSC22_BASE)
/** Peripheral dsc base pointer */
#define DSC23                                    ((DSC_Type *)DSC23_BASE)
/** Peripheral dsc base pointer */
#define DSC24                                    ((DSC_Type *)DSC24_BASE)
/** Peripheral dsc base pointer */
#define DSC25                                    ((DSC_Type *)DSC25_BASE)
/** Peripheral dsc base pointer */
#define DSC26                                    ((DSC_Type *)DSC26_BASE)
/** Peripheral dsc base pointer */
#define DSC27                                    ((DSC_Type *)DSC27_BASE)
/** Peripheral dsc base pointer */
#define DSC28                                    ((DSC_Type *)DSC28_BASE)
/** Peripheral dsc base pointer */
#define DSC29                                    ((DSC_Type *)DSC29_BASE)
/** Peripheral dsc base pointer */
#define DSC30                                    ((DSC_Type *)DSC30_BASE)
/** Peripheral dsc base pointer */
#define DSC31                                    ((DSC_Type *)DSC31_BASE)
/** Peripheral dsc base pointer */
#define DSC33                                    ((DSC_Type *)DSC33_BASE)
/** Peripheral dsc base pointer */
#define DSC34                                    ((DSC_Type *)DSC34_BASE)
/** Peripheral dsc base pointer */
#define DSC35                                    ((DSC_Type *)DSC35_BASE)
/** Peripheral dsc base pointer */
#define DSC36                                    ((DSC_Type *)DSC36_BASE)
/** Peripheral dsc base pointer */
#define DSC37                                    ((DSC_Type *)DSC37_BASE)
/** Peripheral dsc base pointer */
#define DSC38                                    ((DSC_Type *)DSC38_BASE)
/** Peripheral dsc base pointer */
#define DSC39                                    ((DSC_Type *)DSC39_BASE)
/** Peripheral dsc base pointer */
#define DSC40                                    ((DSC_Type *)DSC40_BASE)
/** Peripheral dsc base pointer */
#define DSC41                                    ((DSC_Type *)DSC41_BASE)
/** Peripheral dsc base pointer */
#define DSC42                                    ((DSC_Type *)DSC42_BASE)
/** Peripheral dsc base pointer */
#define DSC43                                    ((DSC_Type *)DSC43_BASE)
/** Peripheral dsc base pointer */
#define DSC44                                    ((DSC_Type *)DSC44_BASE)
/** Peripheral dsc base pointer */
#define DSC45                                    ((DSC_Type *)DSC45_BASE)
/** Peripheral dsc base pointer */
#define DSC46                                    ((DSC_Type *)DSC46_BASE)
/** Peripheral dsc base pointer */
#define DSC47                                    ((DSC_Type *)DSC47_BASE)
/** Peripheral dsc base pointer */
#define DSC49                                    ((DSC_Type *)DSC49_BASE)
/** Peripheral dsc base pointer */
#define DSC50                                    ((DSC_Type *)DSC50_BASE)
/** Peripheral dsc base pointer */
#define DSC51                                    ((DSC_Type *)DSC51_BASE)
/** Peripheral dsc base pointer */
#define DSC52                                    ((DSC_Type *)DSC52_BASE)
/** Peripheral dsc base pointer */
#define DSC53                                    ((DSC_Type *)DSC53_BASE)
/** Peripheral dsc base pointer */
#define DSC54                                    ((DSC_Type *)DSC54_BASE)
/** Peripheral dsc base pointer */
#define DSC55                                    ((DSC_Type *)DSC55_BASE)
/** Peripheral dsc base pointer */
#define DSC56                                    ((DSC_Type *)DSC56_BASE)
/** Peripheral dsc base pointer */
#define DSC57                                    ((DSC_Type *)DSC57_BASE)
/** Peripheral dsc base pointer */
#define DSC58                                    ((DSC_Type *)DSC58_BASE)
/** Peripheral dsc base pointer */
#define DSC59                                    ((DSC_Type *)DSC59_BASE)
/** Peripheral dsc base pointer */
#define DSC60                                    ((DSC_Type *)DSC60_BASE)
/** Peripheral dsc base pointer */
#define DSC61                                    ((DSC_Type *)DSC61_BASE)
/** Peripheral dsc base pointer */
#define DSC62                                    ((DSC_Type *)DSC62_BASE)
/** Peripheral dsc base pointer */
#define DSC63                                    ((DSC_Type *)DSC63_BASE)
/** Array initializer of DSC peripheral base addresses */
#define DSC_BASE_ADDRS                           { DSC1_BASE, DSC2_BASE, DSC3_BASE, DSC4_BASE, DSC5_BASE, DSC6_BASE, DSC7_BASE, DSC8_BASE, DSC9_BASE, DSC10_BASE, DSC11_BASE, DSC12_BASE, DSC13_BASE, DSC14_BASE, DSC15_BASE, DSC17_BASE, DSC18_BASE, DSC19_BASE, DSC20_BASE, DSC21_BASE, DSC22_BASE, DSC23_BASE, DSC24_BASE, DSC25_BASE, DSC26_BASE, DSC27_BASE, DSC28_BASE, DSC29_BASE, DSC30_BASE, DSC31_BASE, DSC33_BASE, DSC34_BASE, DSC35_BASE, DSC36_BASE, DSC37_BASE, DSC38_BASE, DSC39_BASE, DSC40_BASE, DSC41_BASE, DSC42_BASE, DSC43_BASE, DSC44_BASE, DSC45_BASE, DSC46_BASE, DSC47_BASE, DSC49_BASE, DSC50_BASE, DSC51_BASE, DSC52_BASE, DSC53_BASE, DSC54_BASE, DSC55_BASE, DSC56_BASE, DSC57_BASE, DSC58_BASE, DSC59_BASE, DSC60_BASE, DSC61_BASE, DSC62_BASE, DSC63_BASE }
/** Array initializer of DSC peripheral base pointers */
#define DSC_BASE_PTRS                            { DSC1, DSC2, DSC3, DSC4, DSC5, DSC6, DSC7, DSC8, DSC9, DSC10, DSC11, DSC12, DSC13, DSC14, DSC15, DSC17, DSC18, DSC19, DSC20, DSC21, DSC22, DSC23, DSC24, DSC25, DSC26, DSC27, DSC28, DSC29, DSC30, DSC31, DSC33, DSC34, DSC35, DSC36, DSC37, DSC38, DSC39, DSC40, DSC41, DSC42, DSC43, DSC44, DSC45, DSC46, DSC47, DSC49, DSC50, DSC51, DSC52, DSC53, DSC54, DSC55, DSC56, DSC57, DSC58, DSC59, DSC60, DSC61, DSC62, DSC63 }

/*!
 * @}
 */ /* end of group DSC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MSI_MSTR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSI_MSTR_Peripheral_Access_Layer MSI_MSTR Peripheral Access Layer
 * @{
 */

/** MSI_MSTR - Register Layout Typedef */
typedef struct {
  __IO uint32_t DEBUG0;                            /**< AHB address of last transaction from AHB error response, offset: 0x0 */
  __IO uint32_t DEBUG1;                            /**< AHB command of last transaction from AHB error response, offset: 0x4 */
  __IO uint32_t CTRL0;                             /**< MSI Master Control, offset: 0x8 */
  __IO uint32_t CTRL1;                             /**< MSI Master Control, offset: 0xC */
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< MSI IRQ Mask, offset: 0x10 */
    __IO uint32_t SET;                               /**< MSI IRQ Mask, offset: 0x14 */
    __IO uint32_t CLR;                               /**< MSI IRQ Mask, offset: 0x18 */
    __IO uint32_t TOG;                               /**< MSI IRQ Mask, offset: 0x1C */
  } IRQ_MASK;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< MSI IRQ, offset: 0x20 */
    __IO uint32_t SET;                               /**< MSI IRQ, offset: 0x24 */
    __IO uint32_t CLR;                               /**< MSI IRQ, offset: 0x28 */
    __IO uint32_t TOG;                               /**< MSI IRQ, offset: 0x2C */
  } IRQ;
  struct {                                         /* offset: 0x30 */
    __I  uint32_t RW;                                /**< MSI IRQ Masked Status, offset: 0x30 */
    __I  uint32_t SET;                               /**< MSI IRQ Masked Status, offset: 0x34 */
    __I  uint32_t CLR;                               /**< MSI IRQ Masked Status, offset: 0x38 */
    __I  uint32_t TOG;                               /**< MSI IRQ Masked Status, offset: 0x3C */
  } IRQ_MASK_STATUS;
  __I  uint32_t STATUS;                            /**< MSI Master Control STATUS, offset: 0x40 */
} MSI_MSTR_Type;

/* ----------------------------------------------------------------------------
   -- MSI_MSTR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSI_MSTR_Register_Masks MSI_MSTR Register Masks
 * @{
 */

/*! @name DEBUG0 - AHB address of last transaction from AHB error response */
#define MSI_MSTR_DEBUG0_HADDR_MASK               (0xFFFFFFFFU)
#define MSI_MSTR_DEBUG0_HADDR_SHIFT              (0U)
#define MSI_MSTR_DEBUG0_HADDR(x)                 (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_DEBUG0_HADDR_SHIFT)) & MSI_MSTR_DEBUG0_HADDR_MASK)

/*! @name DEBUG1 - AHB command of last transaction from AHB error response */
#define MSI_MSTR_DEBUG1_HBURST_MASK              (0x7U)
#define MSI_MSTR_DEBUG1_HBURST_SHIFT             (0U)
#define MSI_MSTR_DEBUG1_HBURST(x)                (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_DEBUG1_HBURST_SHIFT)) & MSI_MSTR_DEBUG1_HBURST_MASK)
#define MSI_MSTR_DEBUG1_HSIZE_MASK               (0x38U)
#define MSI_MSTR_DEBUG1_HSIZE_SHIFT              (3U)
#define MSI_MSTR_DEBUG1_HSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_DEBUG1_HSIZE_SHIFT)) & MSI_MSTR_DEBUG1_HSIZE_MASK)
#define MSI_MSTR_DEBUG1_HWRITE_MASK              (0x40U)
#define MSI_MSTR_DEBUG1_HWRITE_SHIFT             (6U)
#define MSI_MSTR_DEBUG1_HWRITE(x)                (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_DEBUG1_HWRITE_SHIFT)) & MSI_MSTR_DEBUG1_HWRITE_MASK)

/*! @name CTRL0 - MSI Master Control */
#define MSI_MSTR_CTRL0_RESET_KICK_MASK           (0x1U)
#define MSI_MSTR_CTRL0_RESET_KICK_SHIFT          (0U)
#define MSI_MSTR_CTRL0_RESET_KICK(x)             (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_CTRL0_RESET_KICK_SHIFT)) & MSI_MSTR_CTRL0_RESET_KICK_MASK)
#define MSI_MSTR_CTRL0_WR_BURST_CONVERT_MASK     (0x2U)
#define MSI_MSTR_CTRL0_WR_BURST_CONVERT_SHIFT    (1U)
#define MSI_MSTR_CTRL0_WR_BURST_CONVERT(x)       (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_CTRL0_WR_BURST_CONVERT_SHIFT)) & MSI_MSTR_CTRL0_WR_BURST_CONVERT_MASK)
#define MSI_MSTR_CTRL0_RD_BURST_CONVERT_MASK     (0x4U)
#define MSI_MSTR_CTRL0_RD_BURST_CONVERT_SHIFT    (2U)
#define MSI_MSTR_CTRL0_RD_BURST_CONVERT(x)       (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_CTRL0_RD_BURST_CONVERT_SHIFT)) & MSI_MSTR_CTRL0_RD_BURST_CONVERT_MASK)
#define MSI_MSTR_CTRL0_POST_WR_LIMIT_MASK        (0x1FF8U)
#define MSI_MSTR_CTRL0_POST_WR_LIMIT_SHIFT       (3U)
#define MSI_MSTR_CTRL0_POST_WR_LIMIT(x)          (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_CTRL0_POST_WR_LIMIT_SHIFT)) & MSI_MSTR_CTRL0_POST_WR_LIMIT_MASK)

/*! @name CTRL1 - MSI Master Control */
#define MSI_MSTR_CTRL1_TIMEOUT_COUNT_MASK        (0xFFFFFU)
#define MSI_MSTR_CTRL1_TIMEOUT_COUNT_SHIFT       (0U)
#define MSI_MSTR_CTRL1_TIMEOUT_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_CTRL1_TIMEOUT_COUNT_SHIFT)) & MSI_MSTR_CTRL1_TIMEOUT_COUNT_MASK)

/*! @name IRQ_MASK - MSI IRQ Mask */
#define MSI_MSTR_IRQ_MASK_MSI_MSTR_ERROR_MASK    (0x1U)
#define MSI_MSTR_IRQ_MASK_MSI_MSTR_ERROR_SHIFT   (0U)
#define MSI_MSTR_IRQ_MASK_MSI_MSTR_ERROR(x)      (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_IRQ_MASK_MSI_MSTR_ERROR_SHIFT)) & MSI_MSTR_IRQ_MASK_MSI_MSTR_ERROR_MASK)
#define MSI_MSTR_IRQ_MASK_AHB_TIMEOUT_MASK       (0x2U)
#define MSI_MSTR_IRQ_MASK_AHB_TIMEOUT_SHIFT      (1U)
#define MSI_MSTR_IRQ_MASK_AHB_TIMEOUT(x)         (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_IRQ_MASK_AHB_TIMEOUT_SHIFT)) & MSI_MSTR_IRQ_MASK_AHB_TIMEOUT_MASK)

/*! @name IRQ - MSI IRQ */
#define MSI_MSTR_IRQ_MSI_MSTR_ERROR_MASK         (0x1U)
#define MSI_MSTR_IRQ_MSI_MSTR_ERROR_SHIFT        (0U)
#define MSI_MSTR_IRQ_MSI_MSTR_ERROR(x)           (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_IRQ_MSI_MSTR_ERROR_SHIFT)) & MSI_MSTR_IRQ_MSI_MSTR_ERROR_MASK)
#define MSI_MSTR_IRQ_AHB_TIMEOUT_MASK            (0x2U)
#define MSI_MSTR_IRQ_AHB_TIMEOUT_SHIFT           (1U)
#define MSI_MSTR_IRQ_AHB_TIMEOUT(x)              (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_IRQ_AHB_TIMEOUT_SHIFT)) & MSI_MSTR_IRQ_AHB_TIMEOUT_MASK)

/*! @name IRQ_MASK_STATUS - MSI IRQ Masked Status */
#define MSI_MSTR_IRQ_MASK_STATUS_MSI_MSTR_ERROR_MASK (0x1U)
#define MSI_MSTR_IRQ_MASK_STATUS_MSI_MSTR_ERROR_SHIFT (0U)
#define MSI_MSTR_IRQ_MASK_STATUS_MSI_MSTR_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_IRQ_MASK_STATUS_MSI_MSTR_ERROR_SHIFT)) & MSI_MSTR_IRQ_MASK_STATUS_MSI_MSTR_ERROR_MASK)
#define MSI_MSTR_IRQ_MASK_STATUS_AHB_TIMEOUT_MASK (0x2U)
#define MSI_MSTR_IRQ_MASK_STATUS_AHB_TIMEOUT_SHIFT (1U)
#define MSI_MSTR_IRQ_MASK_STATUS_AHB_TIMEOUT(x)  (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_IRQ_MASK_STATUS_AHB_TIMEOUT_SHIFT)) & MSI_MSTR_IRQ_MASK_STATUS_AHB_TIMEOUT_MASK)

/*! @name STATUS - MSI Master Control STATUS */
#define MSI_MSTR_STATUS_OTC_CNT_GT0_MASK         (0x1U)
#define MSI_MSTR_STATUS_OTC_CNT_GT0_SHIFT        (0U)
#define MSI_MSTR_STATUS_OTC_CNT_GT0(x)           (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_STATUS_OTC_CNT_GT0_SHIFT)) & MSI_MSTR_STATUS_OTC_CNT_GT0_MASK)
#define MSI_MSTR_STATUS_AHB_WR_OTC_CNT_MASK      (0xFFEU)
#define MSI_MSTR_STATUS_AHB_WR_OTC_CNT_SHIFT     (1U)
#define MSI_MSTR_STATUS_AHB_WR_OTC_CNT(x)        (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_STATUS_AHB_WR_OTC_CNT_SHIFT)) & MSI_MSTR_STATUS_AHB_WR_OTC_CNT_MASK)
#define MSI_MSTR_STATUS_POST_WR_TIMEOUT_ERROR_MASK (0x1000U)
#define MSI_MSTR_STATUS_POST_WR_TIMEOUT_ERROR_SHIFT (12U)
#define MSI_MSTR_STATUS_POST_WR_TIMEOUT_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MSI_MSTR_STATUS_POST_WR_TIMEOUT_ERROR_SHIFT)) & MSI_MSTR_STATUS_POST_WR_TIMEOUT_ERROR_MASK)


/*!
 * @}
 */ /* end of group MSI_MSTR_Register_Masks */


/* MSI_MSTR - Peripheral instance base addresses */
/** Peripheral msi_mstr base pointer */
#define MSI0                                     ((MSI_MSTR_Type *)MSI0_BASE)
/** Peripheral msi_mstr base pointer */
#define MSI1                                     ((MSI_MSTR_Type *)MSI1_BASE)
/** Peripheral msi_mstr base pointer */
#define MSI2                                     ((MSI_MSTR_Type *)MSI2_BASE)
/** Peripheral msi_mstr base pointer */
#define MSI3                                     ((MSI_MSTR_Type *)MSI3_BASE)
/** Peripheral msi_mstr base pointer */
#define MSI4                                     ((MSI_MSTR_Type *)MSI4_BASE)
/** Peripheral msi_mstr base pointer */
#define MSI5                                     ((MSI_MSTR_Type *)MSI5_BASE)
/** Peripheral msi_mstr base pointer */
#define MSI6                                     ((MSI_MSTR_Type *)MSI6_BASE)
/** Peripheral msi_mstr base pointer */
#define MSI7                                     ((MSI_MSTR_Type *)MSI7_BASE)
/** Array initializer of MSI_MSTR peripheral base addresses */
#define MSI_MSTR_BASE_ADDRS                      { MSI0_BASE, MSI1_BASE, MSI2_BASE, MSI3_BASE, MSI4_BASE, MSI5_BASE, MSI6_BASE, MSI7_BASE }
/** Array initializer of MSI_MSTR peripheral base pointers */
#define MSI_MSTR_BASE_PTRS                       { MSI0, MSI1, MSI2, MSI3, MSI4, MSI5, MSI6, MSI7 }

/*!
 * @}
 */ /* end of group MSI_MSTR_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* HW_DSC_REGISTERS_H */

