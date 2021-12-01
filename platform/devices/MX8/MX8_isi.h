/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
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
 * @file MX8_isi.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for ISI
 *
 * CMSIS Peripheral Access Layer for ISI
 */

#ifndef ISI_H
#define ISI_H                         /**< Symbol preventing repeated inclusion */


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

/* ----------------------------------------------------------------------------
   -- ISI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISI_Peripheral_Access_Layer ISI Peripheral Access Layer
 * @{
 */

/** ISI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CHNL_CTRL;                         /**< Channel Control Register, offset: 0x0 */
  __IO uint32_t CHNL_IMG_CTRL;                     /**< Channel Image Control Register, offset: 0x4 */
  __IO uint32_t CHNL_OUT_BUF_CTRL;                 /**< Channel Output Buffer Control Register, offset: 0x8 */
  __IO uint32_t CHNL_IMG_CFG;                      /**< Channel Image Configuration, offset: 0xC */
  __IO uint32_t CHNL_IER;                          /**< Channel Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t CHNL_STS;                          /**< Channel Status Register, offset: 0x14 */
  __IO uint32_t CHNL_SCALE_FACTOR;                 /**< Channel Scale Factor Register, offset: 0x18 */
  __IO uint32_t CHNL_SCALE_OFFSET;                 /**< Channel Scale Offset Register, offset: 0x1C */
  __IO uint32_t CHNL_CROP_ULC;                     /**< Channel Crop Upper Left Corner Coordinate Register, offset: 0x20 */
  __IO uint32_t CHNL_CROP_LRC;                     /**< Channel Crop Lower Right Corner Coordinate Register, offset: 0x24 */
  __IO uint32_t CHNL_CSC_COEFF0;                   /**< Channel Color Space Conversion Coefficient Register 0, offset: 0x28 */
  __IO uint32_t CHNL_CSC_COEFF1;                   /**< Channel Color Space Conversion Coefficient Register 1, offset: 0x2C */
  __IO uint32_t CHNL_CSC_COEFF2;                   /**< Channel Color Space Conversion Coefficient Register 2, offset: 0x30 */
  __IO uint32_t CHNL_CSC_COEFF3;                   /**< Channel Color Space Conversion Coefficient Register 3, offset: 0x34 */
  __IO uint32_t CHNL_CSC_COEFF4;                   /**< Channel Color Space Conversion Coefficient Register 4, offset: 0x38 */
  __IO uint32_t CHNL_CSC_COEFF5;                   /**< Channel Color Space Conversion Coefficient Register 5, offset: 0x3C */
  __IO uint32_t CHNL_ROI_0_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 0, offset: 0x40 */
  __IO uint32_t CHNL_ROI_0_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 0, offset: 0x44 */
  __IO uint32_t CHNL_ROI_0_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 0, offset: 0x48 */
  __IO uint32_t CHNL_ROI_1_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 1, offset: 0x4C */
  __IO uint32_t CHNL_ROI_1_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 1, offset: 0x50 */
  __IO uint32_t CHNL_ROI_1_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 1, offset: 0x54 */
  __IO uint32_t CHNL_ROI_2_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 2, offset: 0x58 */
  __IO uint32_t CHNL_ROI_2_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 2, offset: 0x5C */
  __IO uint32_t CHNL_ROI_2_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 2, offset: 0x60 */
  __IO uint32_t CHNL_ROI_3_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 3, offset: 0x64 */
  __IO uint32_t CHNL_ROI_3_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 3, offset: 0x68 */
  __IO uint32_t CHNL_ROI_3_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 3, offset: 0x6C */
  __IO uint32_t CHNL_OUT_BUF1_ADDR_Y;              /**< Channel RGB or Luma (Y) Output Buffer 1 Address, offset: 0x70 */
  __IO uint32_t CHNL_OUT_BUF1_ADDR_U;              /**< Channel Chroma (U/Cb/UV/CbCr) Output Buffer 1 Address, offset: 0x74 */
  __IO uint32_t CHNL_OUT_BUF1_ADDR_V;              /**< Channel Chroma (V/Cr) Output Buffer 1 Address, offset: 0x78 */
  __IO uint32_t CHNL_OUT_BUF_PITCH;                /**< Channel Output Buffer Pitch, offset: 0x7C */
  __IO uint32_t CHNL_IN_BUF_ADDR;                  /**< Channel Input Buffer Address, offset: 0x80 */
  __IO uint32_t CHNL_IN_BUF_PITCH;                 /**< Channel Input Buffer Pitch, offset: 0x84 */
  __IO uint32_t CHNL_MEM_RD_CTRL;                  /**< Channel Memory Read Control, offset: 0x88 */
  __IO uint32_t CHNL_OUT_BUF2_ADDR_Y;              /**< Channel RGB or Luma (Y) Output Buffer 2 Address, offset: 0x8C */
  __IO uint32_t CHNL_OUT_BUF2_ADDR_U;              /**< Channel Chroma (U/Cb/UV/CbCr) Output Buffer 2 Address, offset: 0x90 */
  __IO uint32_t CHNL_OUT_BUF2_ADDR_V;              /**< Channel Chroma (V/Cr) Output Buffer 2 Address, offset: 0x94 */
  __IO uint32_t CHNL_SCL_IMG_CFG;                  /**< Channel Scaled Image Configuration, offset: 0x98 */
} ISI_Type;

/* ----------------------------------------------------------------------------
   -- ISI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISI_Register_Masks ISI Register Masks
 * @{
 */

/*! @name CHNL_CTRL - Channel Control Register */
#define ISI_CHNL_CTRL_SRC_MASK          (0x7U)
#define ISI_CHNL_CTRL_SRC_SHIFT         (0U)
#define ISI_CHNL_CTRL_SRC(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SRC_SHIFT)) & ISI_CHNL_CTRL_SRC_MASK)
#define ISI_CHNL_CTRL_SRC_TYPE_MASK     (0x10U)
#define ISI_CHNL_CTRL_SRC_TYPE_SHIFT    (4U)
#define ISI_CHNL_CTRL_SRC_TYPE(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SRC_TYPE_SHIFT)) & ISI_CHNL_CTRL_SRC_TYPE_MASK)
#define ISI_CHNL_CTRL_MIPI_VC_ID_MASK   (0xC0U)
#define ISI_CHNL_CTRL_MIPI_VC_ID_SHIFT  (6U)
#define ISI_CHNL_CTRL_MIPI_VC_ID(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_MIPI_VC_ID_SHIFT)) & ISI_CHNL_CTRL_MIPI_VC_ID_MASK)
#define ISI_CHNL_CTRL_SEC_LB_SRC_MASK   (0x700U)
#define ISI_CHNL_CTRL_SEC_LB_SRC_SHIFT  (8U)
#define ISI_CHNL_CTRL_SEC_LB_SRC(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SEC_LB_SRC_SHIFT)) & ISI_CHNL_CTRL_SEC_LB_SRC_MASK)
#define ISI_CHNL_CTRL_BLANK_PXL_MASK    (0xFF0000U)
#define ISI_CHNL_CTRL_BLANK_PXL_SHIFT   (16U)
#define ISI_CHNL_CTRL_BLANK_PXL(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_BLANK_PXL_SHIFT)) & ISI_CHNL_CTRL_BLANK_PXL_MASK)
#define ISI_CHNL_CTRL_SW_RST_MASK       (0x1000000U)
#define ISI_CHNL_CTRL_SW_RST_SHIFT      (24U)
#define ISI_CHNL_CTRL_SW_RST(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SW_RST_SHIFT)) & ISI_CHNL_CTRL_SW_RST_MASK)
#define ISI_CHNL_CTRL_CHAIN_BUF_MASK    (0x6000000U)
#define ISI_CHNL_CTRL_CHAIN_BUF_SHIFT   (25U)
#define ISI_CHNL_CTRL_CHAIN_BUF(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHAIN_BUF_SHIFT)) & ISI_CHNL_CTRL_CHAIN_BUF_MASK)
#define ISI_CHNL_CTRL_CHNL_BYPASS_MASK  (0x20000000U)
#define ISI_CHNL_CTRL_CHNL_BYPASS_SHIFT (29U)
#define ISI_CHNL_CTRL_CHNL_BYPASS(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHNL_BYPASS_SHIFT)) & ISI_CHNL_CTRL_CHNL_BYPASS_MASK)
#define ISI_CHNL_CTRL_CLK_EN_MASK       (0x40000000U)
#define ISI_CHNL_CTRL_CLK_EN_SHIFT      (30U)
#define ISI_CHNL_CTRL_CLK_EN(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CLK_EN_SHIFT)) & ISI_CHNL_CTRL_CLK_EN_MASK)
#define ISI_CHNL_CTRL_CHNL_EN_MASK      (0x80000000U)
#define ISI_CHNL_CTRL_CHNL_EN_SHIFT     (31U)
#define ISI_CHNL_CTRL_CHNL_EN(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHNL_EN_SHIFT)) & ISI_CHNL_CTRL_CHNL_EN_MASK)

/*! @name CHNL_IMG_CTRL - Channel Image Control Register */
#define ISI_CHNL_IMG_CTRL_CSC_BYP_MASK  (0x1U)
#define ISI_CHNL_IMG_CTRL_CSC_BYP_SHIFT (0U)
#define ISI_CHNL_IMG_CTRL_CSC_BYP(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CSC_BYP_SHIFT)) & ISI_CHNL_IMG_CTRL_CSC_BYP_MASK)
#define ISI_CHNL_IMG_CTRL_CSC_MODE_MASK (0x6U)
#define ISI_CHNL_IMG_CTRL_CSC_MODE_SHIFT (1U)
#define ISI_CHNL_IMG_CTRL_CSC_MODE(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CSC_MODE_SHIFT)) & ISI_CHNL_IMG_CTRL_CSC_MODE_MASK)
#define ISI_CHNL_IMG_CTRL_YCBCR_MODE_MASK (0x8U)
#define ISI_CHNL_IMG_CTRL_YCBCR_MODE_SHIFT (3U)
#define ISI_CHNL_IMG_CTRL_YCBCR_MODE(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_YCBCR_MODE_SHIFT)) & ISI_CHNL_IMG_CTRL_YCBCR_MODE_MASK)
#define ISI_CHNL_IMG_CTRL_RSVD2_MASK    (0x10U)
#define ISI_CHNL_IMG_CTRL_RSVD2_SHIFT   (4U)
#define ISI_CHNL_IMG_CTRL_RSVD2(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_RSVD2_SHIFT)) & ISI_CHNL_IMG_CTRL_RSVD2_MASK)
#define ISI_CHNL_IMG_CTRL_HFLIP_EN_MASK (0x20U)
#define ISI_CHNL_IMG_CTRL_HFLIP_EN_SHIFT (5U)
#define ISI_CHNL_IMG_CTRL_HFLIP_EN(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_HFLIP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_HFLIP_EN_MASK)
#define ISI_CHNL_IMG_CTRL_VFLIP_EN_MASK (0x40U)
#define ISI_CHNL_IMG_CTRL_VFLIP_EN_SHIFT (6U)
#define ISI_CHNL_IMG_CTRL_VFLIP_EN(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_VFLIP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_VFLIP_EN_MASK)
#define ISI_CHNL_IMG_CTRL_CROP_EN_MASK  (0x80U)
#define ISI_CHNL_IMG_CTRL_CROP_EN_SHIFT (7U)
#define ISI_CHNL_IMG_CTRL_CROP_EN(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CROP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_CROP_EN_MASK)
#define ISI_CHNL_IMG_CTRL_DEC_Y_MASK    (0x300U)
#define ISI_CHNL_IMG_CTRL_DEC_Y_SHIFT   (8U)
#define ISI_CHNL_IMG_CTRL_DEC_Y(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEC_Y_SHIFT)) & ISI_CHNL_IMG_CTRL_DEC_Y_MASK)
#define ISI_CHNL_IMG_CTRL_DEC_X_MASK    (0xC00U)
#define ISI_CHNL_IMG_CTRL_DEC_X_SHIFT   (10U)
#define ISI_CHNL_IMG_CTRL_DEC_X(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEC_X_SHIFT)) & ISI_CHNL_IMG_CTRL_DEC_X_MASK)
#define ISI_CHNL_IMG_CTRL_DEINT_MASK    (0x7000U)
#define ISI_CHNL_IMG_CTRL_DEINT_SHIFT   (12U)
#define ISI_CHNL_IMG_CTRL_DEINT(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEINT_SHIFT)) & ISI_CHNL_IMG_CTRL_DEINT_MASK)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_MASK (0x8000U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_SHIFT (15U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_MASK)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_MASK (0xFF0000U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_SHIFT (16U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_SHIFT)) & ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_MASK)
#define ISI_CHNL_IMG_CTRL_FORMAT_MASK   (0x3F000000U)
#define ISI_CHNL_IMG_CTRL_FORMAT_SHIFT  (24U)
#define ISI_CHNL_IMG_CTRL_FORMAT(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_FORMAT_SHIFT)) & ISI_CHNL_IMG_CTRL_FORMAT_MASK)
#define ISI_CHNL_IMG_CTRL_RSVD0_MASK    (0xC0000000U)
#define ISI_CHNL_IMG_CTRL_RSVD0_SHIFT   (30U)
#define ISI_CHNL_IMG_CTRL_RSVD0(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_RSVD0_SHIFT)) & ISI_CHNL_IMG_CTRL_RSVD0_MASK)

/*! @name CHNL_OUT_BUF_CTRL - Channel Output Buffer Control Register */
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_Y_MASK (0x3U)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_Y_SHIFT (0U)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_Y(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_Y_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_Y_MASK)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_U_MASK (0x18U)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_U_SHIFT (3U)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_U(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_U_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_U_MASK)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_V_MASK (0xC0U)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_V_SHIFT (6U)
#define ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_V(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_V_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_OFLW_PANIC_SET_THD_V_MASK)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_MASK (0x4000U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_SHIFT (14U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_MASK)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_MASK (0x8000U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_SHIFT (15U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_MASK)

/*! @name CHNL_IMG_CFG - Channel Image Configuration */
#define ISI_CHNL_IMG_CFG_WIDTH_MASK     (0x1FFFU)
#define ISI_CHNL_IMG_CFG_WIDTH_SHIFT    (0U)
#define ISI_CHNL_IMG_CFG_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_WIDTH_SHIFT)) & ISI_CHNL_IMG_CFG_WIDTH_MASK)
#define ISI_CHNL_IMG_CFG_RSVD0_MASK     (0xE000U)
#define ISI_CHNL_IMG_CFG_RSVD0_SHIFT    (13U)
#define ISI_CHNL_IMG_CFG_RSVD0(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_RSVD0_SHIFT)) & ISI_CHNL_IMG_CFG_RSVD0_MASK)
#define ISI_CHNL_IMG_CFG_HEIGHT_MASK    (0x1FFF0000U)
#define ISI_CHNL_IMG_CFG_HEIGHT_SHIFT   (16U)
#define ISI_CHNL_IMG_CFG_HEIGHT(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_HEIGHT_SHIFT)) & ISI_CHNL_IMG_CFG_HEIGHT_MASK)
#define ISI_CHNL_IMG_CFG_RSVD1_MASK     (0xE0000000U)
#define ISI_CHNL_IMG_CFG_RSVD1_SHIFT    (29U)
#define ISI_CHNL_IMG_CFG_RSVD1(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_RSVD1_SHIFT)) & ISI_CHNL_IMG_CFG_RSVD1_MASK)

/*! @name CHNL_IER - Channel Interrupt Enable Register */
#define ISI_CHNL_IER_RSVD0_MASK         (0x3FFFU)
#define ISI_CHNL_IER_RSVD0_SHIFT        (0U)
#define ISI_CHNL_IER_RSVD0(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_RSVD0_SHIFT)) & ISI_CHNL_IER_RSVD0_MASK)
#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN_MASK (0x4000U)
#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN_SHIFT (14U)
#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_LATE_VSYNC_ERR_EN_SHIFT)) & ISI_CHNL_IER_LATE_VSYNC_ERR_EN_MASK)
#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_MASK (0x8000U)
#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_SHIFT (15U)
#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_SHIFT)) & ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_MASK)
#define ISI_CHNL_IER_OFLW_Y_BUF_EN_MASK (0x10000U)
#define ISI_CHNL_IER_OFLW_Y_BUF_EN_SHIFT (16U)
#define ISI_CHNL_IER_OFLW_Y_BUF_EN(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_Y_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_Y_BUF_EN_MASK)
#define ISI_CHNL_IER_EXCS_OFLW_Y_BUF_EN_MASK (0x20000U)
#define ISI_CHNL_IER_EXCS_OFLW_Y_BUF_EN_SHIFT (17U)
#define ISI_CHNL_IER_EXCS_OFLW_Y_BUF_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_EXCS_OFLW_Y_BUF_EN_SHIFT)) & ISI_CHNL_IER_EXCS_OFLW_Y_BUF_EN_MASK)
#define ISI_CHNL_IER_OFLW_PANIC_Y_BUF_EN_MASK (0x40000U)
#define ISI_CHNL_IER_OFLW_PANIC_Y_BUF_EN_SHIFT (18U)
#define ISI_CHNL_IER_OFLW_PANIC_Y_BUF_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_PANIC_Y_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_PANIC_Y_BUF_EN_MASK)
#define ISI_CHNL_IER_OFLW_U_BUF_EN_MASK (0x80000U)
#define ISI_CHNL_IER_OFLW_U_BUF_EN_SHIFT (19U)
#define ISI_CHNL_IER_OFLW_U_BUF_EN(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_U_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_U_BUF_EN_MASK)
#define ISI_CHNL_IER_EXCS_OFLW_U_BUF_EN_MASK (0x100000U)
#define ISI_CHNL_IER_EXCS_OFLW_U_BUF_EN_SHIFT (20U)
#define ISI_CHNL_IER_EXCS_OFLW_U_BUF_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_EXCS_OFLW_U_BUF_EN_SHIFT)) & ISI_CHNL_IER_EXCS_OFLW_U_BUF_EN_MASK)
#define ISI_CHNL_IER_OFLW_PANIC_U_BUF_EN_MASK (0x200000U)
#define ISI_CHNL_IER_OFLW_PANIC_U_BUF_EN_SHIFT (21U)
#define ISI_CHNL_IER_OFLW_PANIC_U_BUF_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_PANIC_U_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_PANIC_U_BUF_EN_MASK)
#define ISI_CHNL_IER_OFLW_V_BUF_EN_MASK (0x400000U)
#define ISI_CHNL_IER_OFLW_V_BUF_EN_SHIFT (22U)
#define ISI_CHNL_IER_OFLW_V_BUF_EN(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_V_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_V_BUF_EN_MASK)
#define ISI_CHNL_IER_EXCS_OFLW_V_BUF_EN_MASK (0x800000U)
#define ISI_CHNL_IER_EXCS_OFLW_V_BUF_EN_SHIFT (23U)
#define ISI_CHNL_IER_EXCS_OFLW_V_BUF_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_EXCS_OFLW_V_BUF_EN_SHIFT)) & ISI_CHNL_IER_EXCS_OFLW_V_BUF_EN_MASK)
#define ISI_CHNL_IER_OFLW_PANIC_V_BUF_EN_MASK (0x1000000U)
#define ISI_CHNL_IER_OFLW_PANIC_V_BUF_EN_SHIFT (24U)
#define ISI_CHNL_IER_OFLW_PANIC_V_BUF_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_PANIC_V_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_PANIC_V_BUF_EN_MASK)
#define ISI_CHNL_IER_AXI_RD_ERR_EN_MASK (0x2000000U)
#define ISI_CHNL_IER_AXI_RD_ERR_EN_SHIFT (25U)
#define ISI_CHNL_IER_AXI_RD_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_RD_ERR_EN_SHIFT)) & ISI_CHNL_IER_AXI_RD_ERR_EN_MASK)
#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN_MASK (0x4000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN_SHIFT (26U)
#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_Y_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_Y_EN_MASK)
#define ISI_CHNL_IER_AXI_WR_ERR_U_EN_MASK (0x8000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_U_EN_SHIFT (27U)
#define ISI_CHNL_IER_AXI_WR_ERR_U_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_U_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_U_EN_MASK)
#define ISI_CHNL_IER_AXI_WR_ERR_V_EN_MASK (0x10000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_V_EN_SHIFT (28U)
#define ISI_CHNL_IER_AXI_WR_ERR_V_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_V_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_V_EN_MASK)
#define ISI_CHNL_IER_FRM_RCVD_EN_MASK   (0x20000000U)
#define ISI_CHNL_IER_FRM_RCVD_EN_SHIFT  (29U)
#define ISI_CHNL_IER_FRM_RCVD_EN(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_FRM_RCVD_EN_SHIFT)) & ISI_CHNL_IER_FRM_RCVD_EN_MASK)
#define ISI_CHNL_IER_LINE_RCVD_EN_MASK  (0x40000000U)
#define ISI_CHNL_IER_LINE_RCVD_EN_SHIFT (30U)
#define ISI_CHNL_IER_LINE_RCVD_EN(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_LINE_RCVD_EN_SHIFT)) & ISI_CHNL_IER_LINE_RCVD_EN_MASK)
#define ISI_CHNL_IER_MEM_RD_DONE_EN_MASK (0x80000000U)
#define ISI_CHNL_IER_MEM_RD_DONE_EN_SHIFT (31U)
#define ISI_CHNL_IER_MEM_RD_DONE_EN(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_MEM_RD_DONE_EN_SHIFT)) & ISI_CHNL_IER_MEM_RD_DONE_EN_MASK)

/*! @name CHNL_STS - Channel Status Register */
#define ISI_CHNL_STS_OFLW_BYTES_MASK    (0xFFU)
#define ISI_CHNL_STS_OFLW_BYTES_SHIFT   (0U)
#define ISI_CHNL_STS_OFLW_BYTES(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_BYTES_SHIFT)) & ISI_CHNL_STS_OFLW_BYTES_MASK)
#define ISI_CHNL_STS_BUF1_ACTIVE_MASK   (0x100U)
#define ISI_CHNL_STS_BUF1_ACTIVE_SHIFT  (8U)
#define ISI_CHNL_STS_BUF1_ACTIVE(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_BUF1_ACTIVE_SHIFT)) & ISI_CHNL_STS_BUF1_ACTIVE_MASK)
#define ISI_CHNL_STS_BUF2_ACTIVE_MASK   (0x200U)
#define ISI_CHNL_STS_BUF2_ACTIVE_SHIFT  (9U)
#define ISI_CHNL_STS_BUF2_ACTIVE(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_BUF2_ACTIVE_SHIFT)) & ISI_CHNL_STS_BUF2_ACTIVE_MASK)
#define ISI_CHNL_STS_RSVD1_MASK         (0x3C00U)
#define ISI_CHNL_STS_RSVD1_SHIFT        (10U)
#define ISI_CHNL_STS_RSVD1(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_RSVD1_SHIFT)) & ISI_CHNL_STS_RSVD1_MASK)
#define ISI_CHNL_STS_LATE_VSYNC_ERR_MASK (0x4000U)
#define ISI_CHNL_STS_LATE_VSYNC_ERR_SHIFT (14U)
#define ISI_CHNL_STS_LATE_VSYNC_ERR(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_LATE_VSYNC_ERR_SHIFT)) & ISI_CHNL_STS_LATE_VSYNC_ERR_MASK)
#define ISI_CHNL_STS_EARLY_VSYNC_ERR_MASK (0x8000U)
#define ISI_CHNL_STS_EARLY_VSYNC_ERR_SHIFT (15U)
#define ISI_CHNL_STS_EARLY_VSYNC_ERR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_EARLY_VSYNC_ERR_SHIFT)) & ISI_CHNL_STS_EARLY_VSYNC_ERR_MASK)
#define ISI_CHNL_STS_OFLW_Y_BUF_MASK    (0x10000U)
#define ISI_CHNL_STS_OFLW_Y_BUF_SHIFT   (16U)
#define ISI_CHNL_STS_OFLW_Y_BUF(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_Y_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_Y_BUF_MASK)
#define ISI_CHNL_STS_EXCS_OFLW_Y_BUF_MASK (0x20000U)
#define ISI_CHNL_STS_EXCS_OFLW_Y_BUF_SHIFT (17U)
#define ISI_CHNL_STS_EXCS_OFLW_Y_BUF(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_EXCS_OFLW_Y_BUF_SHIFT)) & ISI_CHNL_STS_EXCS_OFLW_Y_BUF_MASK)
#define ISI_CHNL_STS_OFLW_PANIC_Y_BUF_MASK (0x40000U)
#define ISI_CHNL_STS_OFLW_PANIC_Y_BUF_SHIFT (18U)
#define ISI_CHNL_STS_OFLW_PANIC_Y_BUF(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_PANIC_Y_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_PANIC_Y_BUF_MASK)
#define ISI_CHNL_STS_OFLW_U_BUF_MASK    (0x80000U)
#define ISI_CHNL_STS_OFLW_U_BUF_SHIFT   (19U)
#define ISI_CHNL_STS_OFLW_U_BUF(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_U_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_U_BUF_MASK)
#define ISI_CHNL_STS_EXCS_OFLW_U_BUF_MASK (0x100000U)
#define ISI_CHNL_STS_EXCS_OFLW_U_BUF_SHIFT (20U)
#define ISI_CHNL_STS_EXCS_OFLW_U_BUF(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_EXCS_OFLW_U_BUF_SHIFT)) & ISI_CHNL_STS_EXCS_OFLW_U_BUF_MASK)
#define ISI_CHNL_STS_OFLW_PANIC_U_BUF_MASK (0x200000U)
#define ISI_CHNL_STS_OFLW_PANIC_U_BUF_SHIFT (21U)
#define ISI_CHNL_STS_OFLW_PANIC_U_BUF(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_PANIC_U_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_PANIC_U_BUF_MASK)
#define ISI_CHNL_STS_OFLW_V_BUF_MASK    (0x400000U)
#define ISI_CHNL_STS_OFLW_V_BUF_SHIFT   (22U)
#define ISI_CHNL_STS_OFLW_V_BUF(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_V_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_V_BUF_MASK)
#define ISI_CHNL_STS_EXCS_OFLW_V_BUF_MASK (0x800000U)
#define ISI_CHNL_STS_EXCS_OFLW_V_BUF_SHIFT (23U)
#define ISI_CHNL_STS_EXCS_OFLW_V_BUF(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_EXCS_OFLW_V_BUF_SHIFT)) & ISI_CHNL_STS_EXCS_OFLW_V_BUF_MASK)
#define ISI_CHNL_STS_OFLW_PANIC_V_BUF_MASK (0x1000000U)
#define ISI_CHNL_STS_OFLW_PANIC_V_BUF_SHIFT (24U)
#define ISI_CHNL_STS_OFLW_PANIC_V_BUF(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_PANIC_V_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_PANIC_V_BUF_MASK)
#define ISI_CHNL_STS_AXI_RD_ERR_MASK    (0x2000000U)
#define ISI_CHNL_STS_AXI_RD_ERR_SHIFT   (25U)
#define ISI_CHNL_STS_AXI_RD_ERR(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_RD_ERR_SHIFT)) & ISI_CHNL_STS_AXI_RD_ERR_MASK)
#define ISI_CHNL_STS_AXI_WR_ERR_Y_MASK  (0x4000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_Y_SHIFT (26U)
#define ISI_CHNL_STS_AXI_WR_ERR_Y(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_Y_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_Y_MASK)
#define ISI_CHNL_STS_AXI_WR_ERR_U_MASK  (0x8000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_U_SHIFT (27U)
#define ISI_CHNL_STS_AXI_WR_ERR_U(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_U_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_U_MASK)
#define ISI_CHNL_STS_AXI_WR_ERR_V_MASK  (0x10000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_V_SHIFT (28U)
#define ISI_CHNL_STS_AXI_WR_ERR_V(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_V_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_V_MASK)
#define ISI_CHNL_STS_FRM_STRD_MASK      (0x20000000U)
#define ISI_CHNL_STS_FRM_STRD_SHIFT     (29U)
#define ISI_CHNL_STS_FRM_STRD(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_FRM_STRD_SHIFT)) & ISI_CHNL_STS_FRM_STRD_MASK)
#define ISI_CHNL_STS_LINE_STRD_MASK     (0x40000000U)
#define ISI_CHNL_STS_LINE_STRD_SHIFT    (30U)
#define ISI_CHNL_STS_LINE_STRD(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_LINE_STRD_SHIFT)) & ISI_CHNL_STS_LINE_STRD_MASK)
#define ISI_CHNL_STS_MEM_RD_DONE_MASK   (0x80000000U)
#define ISI_CHNL_STS_MEM_RD_DONE_SHIFT  (31U)
#define ISI_CHNL_STS_MEM_RD_DONE(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_MEM_RD_DONE_SHIFT)) & ISI_CHNL_STS_MEM_RD_DONE_MASK)

/*! @name CHNL_SCALE_FACTOR - Channel Scale Factor Register */
#define ISI_CHNL_SCALE_FACTOR_X_SCALE_MASK (0x3FFFU)
#define ISI_CHNL_SCALE_FACTOR_X_SCALE_SHIFT (0U)
#define ISI_CHNL_SCALE_FACTOR_X_SCALE(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_X_SCALE_SHIFT)) & ISI_CHNL_SCALE_FACTOR_X_SCALE_MASK)
#define ISI_CHNL_SCALE_FACTOR_RSVD1_MASK (0xC000U)
#define ISI_CHNL_SCALE_FACTOR_RSVD1_SHIFT (14U)
#define ISI_CHNL_SCALE_FACTOR_RSVD1(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_RSVD1_SHIFT)) & ISI_CHNL_SCALE_FACTOR_RSVD1_MASK)
#define ISI_CHNL_SCALE_FACTOR_Y_SCALE_MASK (0x3FFF0000U)
#define ISI_CHNL_SCALE_FACTOR_Y_SCALE_SHIFT (16U)
#define ISI_CHNL_SCALE_FACTOR_Y_SCALE(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_Y_SCALE_SHIFT)) & ISI_CHNL_SCALE_FACTOR_Y_SCALE_MASK)
#define ISI_CHNL_SCALE_FACTOR_RSVD0_MASK (0xC0000000U)
#define ISI_CHNL_SCALE_FACTOR_RSVD0_SHIFT (30U)
#define ISI_CHNL_SCALE_FACTOR_RSVD0(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_RSVD0_SHIFT)) & ISI_CHNL_SCALE_FACTOR_RSVD0_MASK)

/*! @name CHNL_SCALE_OFFSET - Channel Scale Offset Register */
#define ISI_CHNL_SCALE_OFFSET_X_OFFSET_MASK (0xFFFU)
#define ISI_CHNL_SCALE_OFFSET_X_OFFSET_SHIFT (0U)
#define ISI_CHNL_SCALE_OFFSET_X_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_X_OFFSET_SHIFT)) & ISI_CHNL_SCALE_OFFSET_X_OFFSET_MASK)
#define ISI_CHNL_SCALE_OFFSET_RSVD1_MASK (0xF000U)
#define ISI_CHNL_SCALE_OFFSET_RSVD1_SHIFT (12U)
#define ISI_CHNL_SCALE_OFFSET_RSVD1(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_RSVD1_SHIFT)) & ISI_CHNL_SCALE_OFFSET_RSVD1_MASK)
#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET_MASK (0xFFF0000U)
#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET_SHIFT (16U)
#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_Y_OFFSET_SHIFT)) & ISI_CHNL_SCALE_OFFSET_Y_OFFSET_MASK)
#define ISI_CHNL_SCALE_OFFSET_RSVD0_MASK (0xF0000000U)
#define ISI_CHNL_SCALE_OFFSET_RSVD0_SHIFT (28U)
#define ISI_CHNL_SCALE_OFFSET_RSVD0(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_RSVD0_SHIFT)) & ISI_CHNL_SCALE_OFFSET_RSVD0_MASK)

/*! @name CHNL_CROP_ULC - Channel Crop Upper Left Corner Coordinate Register */
#define ISI_CHNL_CROP_ULC_Y_MASK        (0xFFFU)
#define ISI_CHNL_CROP_ULC_Y_SHIFT       (0U)
#define ISI_CHNL_CROP_ULC_Y(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_Y_SHIFT)) & ISI_CHNL_CROP_ULC_Y_MASK)
#define ISI_CHNL_CROP_ULC_RSVD1_MASK    (0xF000U)
#define ISI_CHNL_CROP_ULC_RSVD1_SHIFT   (12U)
#define ISI_CHNL_CROP_ULC_RSVD1(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_RSVD1_SHIFT)) & ISI_CHNL_CROP_ULC_RSVD1_MASK)
#define ISI_CHNL_CROP_ULC_X_MASK        (0xFFF0000U)
#define ISI_CHNL_CROP_ULC_X_SHIFT       (16U)
#define ISI_CHNL_CROP_ULC_X(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_X_SHIFT)) & ISI_CHNL_CROP_ULC_X_MASK)
#define ISI_CHNL_CROP_ULC_RSVD0_MASK    (0xF0000000U)
#define ISI_CHNL_CROP_ULC_RSVD0_SHIFT   (28U)
#define ISI_CHNL_CROP_ULC_RSVD0(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_RSVD0_SHIFT)) & ISI_CHNL_CROP_ULC_RSVD0_MASK)

/*! @name CHNL_CROP_LRC - Channel Crop Lower Right Corner Coordinate Register */
#define ISI_CHNL_CROP_LRC_Y_MASK        (0xFFFU)
#define ISI_CHNL_CROP_LRC_Y_SHIFT       (0U)
#define ISI_CHNL_CROP_LRC_Y(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_Y_SHIFT)) & ISI_CHNL_CROP_LRC_Y_MASK)
#define ISI_CHNL_CROP_LRC_RSVD1_MASK    (0xF000U)
#define ISI_CHNL_CROP_LRC_RSVD1_SHIFT   (12U)
#define ISI_CHNL_CROP_LRC_RSVD1(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_RSVD1_SHIFT)) & ISI_CHNL_CROP_LRC_RSVD1_MASK)
#define ISI_CHNL_CROP_LRC_X_MASK        (0xFFF0000U)
#define ISI_CHNL_CROP_LRC_X_SHIFT       (16U)
#define ISI_CHNL_CROP_LRC_X(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_X_SHIFT)) & ISI_CHNL_CROP_LRC_X_MASK)
#define ISI_CHNL_CROP_LRC_RSVD0_MASK    (0xF0000000U)
#define ISI_CHNL_CROP_LRC_RSVD0_SHIFT   (28U)
#define ISI_CHNL_CROP_LRC_RSVD0(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_RSVD0_SHIFT)) & ISI_CHNL_CROP_LRC_RSVD0_MASK)

/*! @name CHNL_CSC_COEFF0 - Channel Color Space Conversion Coefficient Register 0 */
#define ISI_CHNL_CSC_COEFF0_A1_MASK     (0x7FFU)
#define ISI_CHNL_CSC_COEFF0_A1_SHIFT    (0U)
#define ISI_CHNL_CSC_COEFF0_A1(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_A1_SHIFT)) & ISI_CHNL_CSC_COEFF0_A1_MASK)
#define ISI_CHNL_CSC_COEFF0_RSVD1_MASK  (0xF800U)
#define ISI_CHNL_CSC_COEFF0_RSVD1_SHIFT (11U)
#define ISI_CHNL_CSC_COEFF0_RSVD1(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF0_RSVD1_MASK)
#define ISI_CHNL_CSC_COEFF0_A2_MASK     (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF0_A2_SHIFT    (16U)
#define ISI_CHNL_CSC_COEFF0_A2(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_A2_SHIFT)) & ISI_CHNL_CSC_COEFF0_A2_MASK)
#define ISI_CHNL_CSC_COEFF0_RSVD0_MASK  (0xF8000000U)
#define ISI_CHNL_CSC_COEFF0_RSVD0_SHIFT (27U)
#define ISI_CHNL_CSC_COEFF0_RSVD0(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF0_RSVD0_MASK)

/*! @name CHNL_CSC_COEFF1 - Channel Color Space Conversion Coefficient Register 1 */
#define ISI_CHNL_CSC_COEFF1_A3_MASK     (0x7FFU)
#define ISI_CHNL_CSC_COEFF1_A3_SHIFT    (0U)
#define ISI_CHNL_CSC_COEFF1_A3(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_A3_SHIFT)) & ISI_CHNL_CSC_COEFF1_A3_MASK)
#define ISI_CHNL_CSC_COEFF1_RSVD1_MASK  (0xF800U)
#define ISI_CHNL_CSC_COEFF1_RSVD1_SHIFT (11U)
#define ISI_CHNL_CSC_COEFF1_RSVD1(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF1_RSVD1_MASK)
#define ISI_CHNL_CSC_COEFF1_B1_MASK     (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF1_B1_SHIFT    (16U)
#define ISI_CHNL_CSC_COEFF1_B1(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_B1_SHIFT)) & ISI_CHNL_CSC_COEFF1_B1_MASK)
#define ISI_CHNL_CSC_COEFF1_RSVD0_MASK  (0xF8000000U)
#define ISI_CHNL_CSC_COEFF1_RSVD0_SHIFT (27U)
#define ISI_CHNL_CSC_COEFF1_RSVD0(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF1_RSVD0_MASK)

/*! @name CHNL_CSC_COEFF2 - Channel Color Space Conversion Coefficient Register 2 */
#define ISI_CHNL_CSC_COEFF2_B2_MASK     (0x7FFU)
#define ISI_CHNL_CSC_COEFF2_B2_SHIFT    (0U)
#define ISI_CHNL_CSC_COEFF2_B2(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_B2_SHIFT)) & ISI_CHNL_CSC_COEFF2_B2_MASK)
#define ISI_CHNL_CSC_COEFF2_RSVD1_MASK  (0xF800U)
#define ISI_CHNL_CSC_COEFF2_RSVD1_SHIFT (11U)
#define ISI_CHNL_CSC_COEFF2_RSVD1(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF2_RSVD1_MASK)
#define ISI_CHNL_CSC_COEFF2_B3_MASK     (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF2_B3_SHIFT    (16U)
#define ISI_CHNL_CSC_COEFF2_B3(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_B3_SHIFT)) & ISI_CHNL_CSC_COEFF2_B3_MASK)
#define ISI_CHNL_CSC_COEFF2_RSVD0_MASK  (0xF8000000U)
#define ISI_CHNL_CSC_COEFF2_RSVD0_SHIFT (27U)
#define ISI_CHNL_CSC_COEFF2_RSVD0(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF2_RSVD0_MASK)

/*! @name CHNL_CSC_COEFF3 - Channel Color Space Conversion Coefficient Register 3 */
#define ISI_CHNL_CSC_COEFF3_C1_MASK     (0x7FFU)
#define ISI_CHNL_CSC_COEFF3_C1_SHIFT    (0U)
#define ISI_CHNL_CSC_COEFF3_C1(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_C1_SHIFT)) & ISI_CHNL_CSC_COEFF3_C1_MASK)
#define ISI_CHNL_CSC_COEFF3_RSVD1_MASK  (0xF800U)
#define ISI_CHNL_CSC_COEFF3_RSVD1_SHIFT (11U)
#define ISI_CHNL_CSC_COEFF3_RSVD1(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF3_RSVD1_MASK)
#define ISI_CHNL_CSC_COEFF3_C2_MASK     (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF3_C2_SHIFT    (16U)
#define ISI_CHNL_CSC_COEFF3_C2(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_C2_SHIFT)) & ISI_CHNL_CSC_COEFF3_C2_MASK)
#define ISI_CHNL_CSC_COEFF3_RSVD0_MASK  (0xF8000000U)
#define ISI_CHNL_CSC_COEFF3_RSVD0_SHIFT (27U)
#define ISI_CHNL_CSC_COEFF3_RSVD0(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF3_RSVD0_MASK)

/*! @name CHNL_CSC_COEFF4 - Channel Color Space Conversion Coefficient Register 4 */
#define ISI_CHNL_CSC_COEFF4_C3_MASK     (0x7FFU)
#define ISI_CHNL_CSC_COEFF4_C3_SHIFT    (0U)
#define ISI_CHNL_CSC_COEFF4_C3(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_C3_SHIFT)) & ISI_CHNL_CSC_COEFF4_C3_MASK)
#define ISI_CHNL_CSC_COEFF4_RSVD1_MASK  (0xF800U)
#define ISI_CHNL_CSC_COEFF4_RSVD1_SHIFT (11U)
#define ISI_CHNL_CSC_COEFF4_RSVD1(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF4_RSVD1_MASK)
#define ISI_CHNL_CSC_COEFF4_D1_MASK     (0x1FF0000U)
#define ISI_CHNL_CSC_COEFF4_D1_SHIFT    (16U)
#define ISI_CHNL_CSC_COEFF4_D1(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_D1_SHIFT)) & ISI_CHNL_CSC_COEFF4_D1_MASK)
#define ISI_CHNL_CSC_COEFF4_RSVD0_MASK  (0xFE000000U)
#define ISI_CHNL_CSC_COEFF4_RSVD0_SHIFT (25U)
#define ISI_CHNL_CSC_COEFF4_RSVD0(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF4_RSVD0_MASK)

/*! @name CHNL_CSC_COEFF5 - Channel Color Space Conversion Coefficient Register 5 */
#define ISI_CHNL_CSC_COEFF5_D2_MASK     (0x1FFU)
#define ISI_CHNL_CSC_COEFF5_D2_SHIFT    (0U)
#define ISI_CHNL_CSC_COEFF5_D2(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_D2_SHIFT)) & ISI_CHNL_CSC_COEFF5_D2_MASK)
#define ISI_CHNL_CSC_COEFF5_RSVD1_MASK  (0xFE00U)
#define ISI_CHNL_CSC_COEFF5_RSVD1_SHIFT (9U)
#define ISI_CHNL_CSC_COEFF5_RSVD1(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF5_RSVD1_MASK)
#define ISI_CHNL_CSC_COEFF5_D3_MASK     (0x1FF0000U)
#define ISI_CHNL_CSC_COEFF5_D3_SHIFT    (16U)
#define ISI_CHNL_CSC_COEFF5_D3(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_D3_SHIFT)) & ISI_CHNL_CSC_COEFF5_D3_MASK)
#define ISI_CHNL_CSC_COEFF5_RSVD0_MASK  (0xFE000000U)
#define ISI_CHNL_CSC_COEFF5_RSVD0_SHIFT (25U)
#define ISI_CHNL_CSC_COEFF5_RSVD0(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF5_RSVD0_MASK)

/*! @name CHNL_ROI_0_ALPHA - Channel Alpha Value Register for Region of Interest 0 */
#define ISI_CHNL_ROI_0_ALPHA_RSVD1_MASK (0xFFFFU)
#define ISI_CHNL_ROI_0_ALPHA_RSVD1_SHIFT (0U)
#define ISI_CHNL_ROI_0_ALPHA_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_RSVD1_MASK)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_MASK (0x10000U)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_SHIFT (16U)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_MASK)
#define ISI_CHNL_ROI_0_ALPHA_RSVD0_MASK (0xFE0000U)
#define ISI_CHNL_ROI_0_ALPHA_RSVD0_SHIFT (17U)
#define ISI_CHNL_ROI_0_ALPHA_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_RSVD0_MASK)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_MASK (0xFF000000U)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_SHIFT (24U)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_ALPHA_MASK)

/*! @name CHNL_ROI_0_ULC - Channel Upper Left Coordinate Register for Region of Interest 0 */
#define ISI_CHNL_ROI_0_ULC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_0_ULC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_0_ULC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_Y_SHIFT)) & ISI_CHNL_ROI_0_ULC_Y_MASK)
#define ISI_CHNL_ROI_0_ULC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_0_ULC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_0_ULC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_0_ULC_RSVD1_MASK)
#define ISI_CHNL_ROI_0_ULC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_0_ULC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_0_ULC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_X_SHIFT)) & ISI_CHNL_ROI_0_ULC_X_MASK)
#define ISI_CHNL_ROI_0_ULC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_0_ULC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_0_ULC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_0_ULC_RSVD0_MASK)

/*! @name CHNL_ROI_0_LRC - Channel Lower Right Coordinate Register for Region of Interest 0 */
#define ISI_CHNL_ROI_0_LRC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_0_LRC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_0_LRC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_Y_SHIFT)) & ISI_CHNL_ROI_0_LRC_Y_MASK)
#define ISI_CHNL_ROI_0_LRC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_0_LRC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_0_LRC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_0_LRC_RSVD1_MASK)
#define ISI_CHNL_ROI_0_LRC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_0_LRC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_0_LRC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_X_SHIFT)) & ISI_CHNL_ROI_0_LRC_X_MASK)
#define ISI_CHNL_ROI_0_LRC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_0_LRC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_0_LRC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_0_LRC_RSVD0_MASK)

/*! @name CHNL_ROI_1_ALPHA - Channel Alpha Value Register for Region of Interest 1 */
#define ISI_CHNL_ROI_1_ALPHA_RSVD1_MASK (0xFFFFU)
#define ISI_CHNL_ROI_1_ALPHA_RSVD1_SHIFT (0U)
#define ISI_CHNL_ROI_1_ALPHA_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_RSVD1_MASK)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_MASK (0x10000U)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_SHIFT (16U)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_MASK)
#define ISI_CHNL_ROI_1_ALPHA_RSVD0_MASK (0xFE0000U)
#define ISI_CHNL_ROI_1_ALPHA_RSVD0_SHIFT (17U)
#define ISI_CHNL_ROI_1_ALPHA_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_RSVD0_MASK)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_MASK (0xFF000000U)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_SHIFT (24U)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_ALPHA_MASK)

/*! @name CHNL_ROI_1_ULC - Channel Upper Left Coordinate Register for Region of Interest 1 */
#define ISI_CHNL_ROI_1_ULC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_1_ULC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_1_ULC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_Y_SHIFT)) & ISI_CHNL_ROI_1_ULC_Y_MASK)
#define ISI_CHNL_ROI_1_ULC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_1_ULC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_1_ULC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_1_ULC_RSVD1_MASK)
#define ISI_CHNL_ROI_1_ULC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_1_ULC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_1_ULC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_X_SHIFT)) & ISI_CHNL_ROI_1_ULC_X_MASK)
#define ISI_CHNL_ROI_1_ULC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_1_ULC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_1_ULC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_1_ULC_RSVD0_MASK)

/*! @name CHNL_ROI_1_LRC - Channel Lower Right Coordinate Register for Region of Interest 1 */
#define ISI_CHNL_ROI_1_LRC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_1_LRC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_1_LRC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_Y_SHIFT)) & ISI_CHNL_ROI_1_LRC_Y_MASK)
#define ISI_CHNL_ROI_1_LRC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_1_LRC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_1_LRC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_1_LRC_RSVD1_MASK)
#define ISI_CHNL_ROI_1_LRC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_1_LRC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_1_LRC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_X_SHIFT)) & ISI_CHNL_ROI_1_LRC_X_MASK)
#define ISI_CHNL_ROI_1_LRC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_1_LRC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_1_LRC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_1_LRC_RSVD0_MASK)

/*! @name CHNL_ROI_2_ALPHA - Channel Alpha Value Register for Region of Interest 2 */
#define ISI_CHNL_ROI_2_ALPHA_RSVD1_MASK (0xFFFFU)
#define ISI_CHNL_ROI_2_ALPHA_RSVD1_SHIFT (0U)
#define ISI_CHNL_ROI_2_ALPHA_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_RSVD1_MASK)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_MASK (0x10000U)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_SHIFT (16U)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_MASK)
#define ISI_CHNL_ROI_2_ALPHA_RSVD0_MASK (0xFE0000U)
#define ISI_CHNL_ROI_2_ALPHA_RSVD0_SHIFT (17U)
#define ISI_CHNL_ROI_2_ALPHA_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_RSVD0_MASK)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_MASK (0xFF000000U)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_SHIFT (24U)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_ALPHA_MASK)

/*! @name CHNL_ROI_2_ULC - Channel Upper Left Coordinate Register for Region of Interest 2 */
#define ISI_CHNL_ROI_2_ULC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_2_ULC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_2_ULC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_Y_SHIFT)) & ISI_CHNL_ROI_2_ULC_Y_MASK)
#define ISI_CHNL_ROI_2_ULC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_2_ULC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_2_ULC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_2_ULC_RSVD1_MASK)
#define ISI_CHNL_ROI_2_ULC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_2_ULC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_2_ULC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_X_SHIFT)) & ISI_CHNL_ROI_2_ULC_X_MASK)
#define ISI_CHNL_ROI_2_ULC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_2_ULC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_2_ULC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_2_ULC_RSVD0_MASK)

/*! @name CHNL_ROI_2_LRC - Channel Lower Right Coordinate Register for Region of Interest 2 */
#define ISI_CHNL_ROI_2_LRC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_2_LRC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_2_LRC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_Y_SHIFT)) & ISI_CHNL_ROI_2_LRC_Y_MASK)
#define ISI_CHNL_ROI_2_LRC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_2_LRC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_2_LRC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_2_LRC_RSVD1_MASK)
#define ISI_CHNL_ROI_2_LRC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_2_LRC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_2_LRC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_X_SHIFT)) & ISI_CHNL_ROI_2_LRC_X_MASK)
#define ISI_CHNL_ROI_2_LRC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_2_LRC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_2_LRC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_2_LRC_RSVD0_MASK)

/*! @name CHNL_ROI_3_ALPHA - Channel Alpha Value Register for Region of Interest 3 */
#define ISI_CHNL_ROI_3_ALPHA_RSVD1_MASK (0xFFFFU)
#define ISI_CHNL_ROI_3_ALPHA_RSVD1_SHIFT (0U)
#define ISI_CHNL_ROI_3_ALPHA_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_RSVD1_MASK)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_MASK (0x10000U)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_SHIFT (16U)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_EN(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_MASK)
#define ISI_CHNL_ROI_3_ALPHA_RSVD0_MASK (0xFE0000U)
#define ISI_CHNL_ROI_3_ALPHA_RSVD0_SHIFT (17U)
#define ISI_CHNL_ROI_3_ALPHA_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_RSVD0_MASK)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_MASK (0xFF000000U)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_SHIFT (24U)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_ALPHA_MASK)

/*! @name CHNL_ROI_3_ULC - Channel Upper Left Coordinate Register for Region of Interest 3 */
#define ISI_CHNL_ROI_3_ULC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_3_ULC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_3_ULC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_Y_SHIFT)) & ISI_CHNL_ROI_3_ULC_Y_MASK)
#define ISI_CHNL_ROI_3_ULC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_3_ULC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_3_ULC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_3_ULC_RSVD1_MASK)
#define ISI_CHNL_ROI_3_ULC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_3_ULC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_3_ULC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_X_SHIFT)) & ISI_CHNL_ROI_3_ULC_X_MASK)
#define ISI_CHNL_ROI_3_ULC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_3_ULC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_3_ULC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_3_ULC_RSVD0_MASK)

/*! @name CHNL_ROI_3_LRC - Channel Lower Right Coordinate Register for Region of Interest 3 */
#define ISI_CHNL_ROI_3_LRC_Y_MASK       (0xFFFU)
#define ISI_CHNL_ROI_3_LRC_Y_SHIFT      (0U)
#define ISI_CHNL_ROI_3_LRC_Y(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_Y_SHIFT)) & ISI_CHNL_ROI_3_LRC_Y_MASK)
#define ISI_CHNL_ROI_3_LRC_RSVD1_MASK   (0xF000U)
#define ISI_CHNL_ROI_3_LRC_RSVD1_SHIFT  (12U)
#define ISI_CHNL_ROI_3_LRC_RSVD1(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_3_LRC_RSVD1_MASK)
#define ISI_CHNL_ROI_3_LRC_X_MASK       (0xFFF0000U)
#define ISI_CHNL_ROI_3_LRC_X_SHIFT      (16U)
#define ISI_CHNL_ROI_3_LRC_X(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_X_SHIFT)) & ISI_CHNL_ROI_3_LRC_X_MASK)
#define ISI_CHNL_ROI_3_LRC_RSVD0_MASK   (0xF0000000U)
#define ISI_CHNL_ROI_3_LRC_RSVD0_SHIFT  (28U)
#define ISI_CHNL_ROI_3_LRC_RSVD0(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_3_LRC_RSVD0_MASK)

/*! @name CHNL_OUT_BUF1_ADDR_Y - Channel RGB or Luma (Y) Output Buffer 1 Address */
#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_MASK (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_SHIFT (0U)
#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_MASK)

/*! @name CHNL_OUT_BUF1_ADDR_U - Channel Chroma (U/Cb/UV/CbCr) Output Buffer 1 Address */
#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_MASK (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_SHIFT (0U)
#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_MASK)

/*! @name CHNL_OUT_BUF1_ADDR_V - Channel Chroma (V/Cr) Output Buffer 1 Address */
#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_MASK (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_SHIFT (0U)
#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_MASK)

/*! @name CHNL_OUT_BUF_PITCH - Channel Output Buffer Pitch */
#define ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_MASK (0xFFFFU)
#define ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_SHIFT (0U)
#define ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_SHIFT)) & ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_MASK)

/*! @name CHNL_IN_BUF_ADDR - Channel Input Buffer Address */
#define ISI_CHNL_IN_BUF_ADDR_ADDR_MASK  (0xFFFFFFFFU)
#define ISI_CHNL_IN_BUF_ADDR_ADDR_SHIFT (0U)
#define ISI_CHNL_IN_BUF_ADDR_ADDR(x)    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IN_BUF_ADDR_ADDR_SHIFT)) & ISI_CHNL_IN_BUF_ADDR_ADDR_MASK)

/*! @name CHNL_IN_BUF_PITCH - Channel Input Buffer Pitch */
#define ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_MASK (0xFFFFU)
#define ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_SHIFT (0U)
#define ISI_CHNL_IN_BUF_PITCH_LINE_PITCH(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_SHIFT)) & ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_MASK)
#define ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_MASK (0xFFFF0000U)
#define ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_SHIFT (16U)
#define ISI_CHNL_IN_BUF_PITCH_FRM_PITCH(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_SHIFT)) & ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_MASK)

/*! @name CHNL_MEM_RD_CTRL - Channel Memory Read Control */
#define ISI_CHNL_MEM_RD_CTRL_READ_MEM_MASK (0x1U)
#define ISI_CHNL_MEM_RD_CTRL_READ_MEM_SHIFT (0U)
#define ISI_CHNL_MEM_RD_CTRL_READ_MEM(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_READ_MEM_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_READ_MEM_MASK)
#define ISI_CHNL_MEM_RD_CTRL_RSVD0_MASK (0xFFFFFFEU)
#define ISI_CHNL_MEM_RD_CTRL_RSVD0_SHIFT (1U)
#define ISI_CHNL_MEM_RD_CTRL_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_RSVD0_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_RSVD0_MASK)
#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_MASK (0xF0000000U)
#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_SHIFT (28U)
#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_MASK)

/*! @name CHNL_OUT_BUF2_ADDR_Y - Channel RGB or Luma (Y) Output Buffer 2 Address */
#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_MASK (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_SHIFT (0U)
#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_MASK)

/*! @name CHNL_OUT_BUF2_ADDR_U - Channel Chroma (U/Cb/UV/CbCr) Output Buffer 2 Address */
#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_MASK (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_SHIFT (0U)
#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_MASK)

/*! @name CHNL_OUT_BUF2_ADDR_V - Channel Chroma (V/Cr) Output Buffer 2 Address */
#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_MASK (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_SHIFT (0U)
#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_MASK)

/*! @name CHNL_SCL_IMG_CFG - Channel Scaled Image Configuration */
#define ISI_CHNL_SCL_IMG_CFG_WIDTH_MASK (0x1FFFU)
#define ISI_CHNL_SCL_IMG_CFG_WIDTH_SHIFT (0U)
#define ISI_CHNL_SCL_IMG_CFG_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_WIDTH_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_WIDTH_MASK)
#define ISI_CHNL_SCL_IMG_CFG_RSVD0_MASK (0xE000U)
#define ISI_CHNL_SCL_IMG_CFG_RSVD0_SHIFT (13U)
#define ISI_CHNL_SCL_IMG_CFG_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_RSVD0_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_RSVD0_MASK)
#define ISI_CHNL_SCL_IMG_CFG_HEIGHT_MASK (0x1FFF0000U)
#define ISI_CHNL_SCL_IMG_CFG_HEIGHT_SHIFT (16U)
#define ISI_CHNL_SCL_IMG_CFG_HEIGHT(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_HEIGHT_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_HEIGHT_MASK)
#define ISI_CHNL_SCL_IMG_CFG_RSVD1_MASK (0xE0000000U)
#define ISI_CHNL_SCL_IMG_CFG_RSVD1_SHIFT (29U)
#define ISI_CHNL_SCL_IMG_CFG_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_RSVD1_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_RSVD1_MASK)


/*!
 * @}
 */ /* end of group ISI_Register_Masks */


/** Peripheral ISI base pointers */
#define ISI0                                     ((ISI_Type *)ISI0_BASE)
#define ISI1                                     ((ISI_Type *)ISI1_BASE)
#define ISI2                                     ((ISI_Type *)ISI2_BASE)
#define ISI3                                     ((ISI_Type *)ISI3_BASE)
#define ISI4                                     ((ISI_Type *)ISI4_BASE)
#define ISI5                                     ((ISI_Type *)ISI5_BASE)
#define ISI6                                     ((ISI_Type *)ISI6_BASE)
#define ISI7                                     ((ISI_Type *)ISI7_BASE)
#define ISI8                                     ((ISI_Type *)ISI8_BASE)
#define ISI9                                     ((ISI_Type *)ISI9_BASE)
#define ISI10                                    ((ISI_Type *)ISI10_BASE)
#define ISI11                                    ((ISI_Type *)ISI11_BASE)
#define ISI12                                    ((ISI_Type *)ISI12_BASE)
#define ISI13                                    ((ISI_Type *)ISI13_BASE)
#define ISI14                                    ((ISI_Type *)ISI14_BASE)
#define ISI15                                    ((ISI_Type *)ISI15_BASE)
#define ISI16                                    ((ISI_Type *)ISI16_BASE)
#define ISI17                                    ((ISI_Type *)ISI17_BASE)
#define ISI18                                    ((ISI_Type *)ISI18_BASE)
#define ISI19                                    ((ISI_Type *)ISI19_BASE)
#define ISI20                                    ((ISI_Type *)ISI20_BASE)
#define ISI21                                    ((ISI_Type *)ISI21_BASE)
#define ISI22                                    ((ISI_Type *)ISI22_BASE)
#define ISI23                                    ((ISI_Type *)ISI23_BASE)

/** Array initializer of ISI peripheral base addresses */
#define ISI_BASE_ADDRS                  {  ISI0_BASE,  ISI1_BASE, \
                                           ISI2_BASE,  ISI3_BASE, \
                                           ISI4_BASE,  ISI5_BASE, \
                                           ISI6_BASE,  ISI7_BASE, \
                                           ISI8_BASE,  ISI9_BASE, \
                                          ISI10_BASE, ISI11_BASE, \
                                          ISI12_BASE, ISI13_BASE, \
                                          ISI14_BASE, ISI15_BASE, \
                                          ISI16_BASE, ISI17_BASE, \
                                          ISI18_BASE, ISI19_BASE, \
                                          ISI20_BASE, ISI21_BASE, \
                                          ISI22_BASE, ISI23_BASE }


/** Array initializer of ISI peripheral base pointers */
#define ISI_BASE_PTRS                   {  ISI0,  ISI1,  ISI2,  ISI3, \
                                           ISI4,  ISI5,  ISI6,  ISI7, \
                                           ISI8,  ISI9, ISI10, ISI11, \
                                          ISI12, ISI13, ISI14, ISI15, \
                                          ISI16, ISI17, ISI18, ISI19, \
                                          ISI20, ISI21, ISI22, ISI23 }

/*!
 * @}
 */ /* end of group ISI_Peripheral_Access_Layer */


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


#endif  /* ISI_H */

