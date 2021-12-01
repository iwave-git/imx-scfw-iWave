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
 * @file MX8_jpegenc.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for JPGENC
 *
 * CMSIS Peripheral Access Layer for JPGENC
 */

#ifndef JPGENC_H
#define JPGENC_H            /**< Symbol preventing repeated inclusion */


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
   -- JPGENC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPGENC_Peripheral_Access_Layer JPGENC Peripheral Access Layer
 * @{
 */

/** JPGENC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GLB_CTRL;                          /**< Global Control, offset: 0x0 */
  __I  uint32_t COM_STATUS;                        /**< Common Status, offset: 0x4 */
  __I  uint32_t RSVD_COM_IRQ_EN;                   /**< RSVD, offset: 0x8 */
  __I  uint32_t RSVD_CUR_DESCPT_PTR;               /**< RSVD, offset: 0xC */
  __I  uint32_t RSVD_NXT_DESCPT_PTR;               /**< RSVD, offset: 0x10 */
  __IO uint32_t IN_BUF_BASE0;                      /**< Input Image Frame Buffer0 Base Address, offset: 0x14 */
  __IO uint32_t IN_BUF_BASE1;                      /**< Input Image Frame Buffer1 Base Address, offset: 0x18 */
  __IO uint32_t IN_LINE_PITCH;                     /**< Image Input Buffer Line Pitch, offset: 0x1C */
  __IO uint32_t STM_BUFBASE;                       /**< Output JPEG Stream Buffer Base Address, offset: 0x20 */
  __IO uint32_t STM_BUFSIZE;                       /**< Output JPEG Stream Buffer Size, offset: 0x24 */
  __IO uint32_t IMGSIZE;                           /**< Image Resolution, offset: 0x28 */
  __IO uint32_t STM_CTRL;                          /**< Bit Stream Switch and Control, offset: 0x2C */
       uint8_t RESERVED_0[65488];
  struct {                                         /* offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_STATUS;                       /**< Bit Stream SLOT Status, array offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_IRQ_EN;                       /**< Bit Stream Interrupt Enable Register, array offset: 0x10004, array step: 0x10000 */
    __I  uint32_t SLOT_BUF_PTR;                      /**< Bit Stream Buffer Pointer, array offset: 0x10008, array step: 0x10000 */
    __I  uint32_t SLOT_CUR_DESCPT_PTR;               /**< Current Encoding Descriptor Pointer, array offset: 0x1000C, array step: 0x10000 */
    __IO uint32_t SLOT_NXT_DESCPT_PTR;               /**< Next Encoding Descriptor Pointer, array offset: 0x10010, array step: 0x10000 */
         uint8_t RESERVED_0[65516];
  } BITSTRM_SLOT_REGS[4];
} JPGENC_Type;

/* ----------------------------------------------------------------------------
   -- JPGENC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPGENC_Register_Masks JPGENC Register Masks
 * @{
 */

/*! @name GLB_CTRL - Global Control */
#define JPGENC_GLB_CTRL_JPG_ENC_EN_MASK       (0x1U)
#define JPGENC_GLB_CTRL_JPG_ENC_EN_SHIFT      (0U)
#define JPGENC_GLB_CTRL_JPG_ENC_EN(x)         (((uint32_t)(((uint32_t)(x)) << JPGENC_GLB_CTRL_JPG_ENC_EN_SHIFT)) & JPGENC_GLB_CTRL_JPG_ENC_EN_MASK)
#define JPGENC_GLB_CTRL_SFTRST_MASK           (0x2U)
#define JPGENC_GLB_CTRL_SFTRST_SHIFT          (1U)
#define JPGENC_GLB_CTRL_SFTRST(x)             (((uint32_t)(((uint32_t)(x)) << JPGENC_GLB_CTRL_SFTRST_SHIFT)) & JPGENC_GLB_CTRL_SFTRST_MASK)
#define JPGENC_GLB_CTRL_ENC_GO_MASK           (0x4U)
#define JPGENC_GLB_CTRL_ENC_GO_SHIFT          (2U)
#define JPGENC_GLB_CTRL_ENC_GO(x)             (((uint32_t)(((uint32_t)(x)) << JPGENC_GLB_CTRL_ENC_GO_SHIFT)) & JPGENC_GLB_CTRL_ENC_GO_MASK)
#define JPGENC_GLB_CTRL_L_ENDIAN_MASK         (0x8U)
#define JPGENC_GLB_CTRL_L_ENDIAN_SHIFT        (3U)
#define JPGENC_GLB_CTRL_L_ENDIAN(x)           (((uint32_t)(((uint32_t)(x)) << JPGENC_GLB_CTRL_L_ENDIAN_SHIFT)) & JPGENC_GLB_CTRL_L_ENDIAN_MASK)
#define JPGENC_GLB_CTRL_SLOT_EN_MASK          (0xF0U)
#define JPGENC_GLB_CTRL_SLOT_EN_SHIFT         (4U)
#define JPGENC_GLB_CTRL_SLOT_EN(x)            (((uint32_t)(((uint32_t)(x)) << JPGENC_GLB_CTRL_SLOT_EN_SHIFT)) & JPGENC_GLB_CTRL_SLOT_EN_MASK)

/*! @name COM_STATUS - Common Status */
#define JPGENC_COM_STATUS_CUR_SLOT_MASK       (0x60000000U)
#define JPGENC_COM_STATUS_CUR_SLOT_SHIFT      (29U)
#define JPGENC_COM_STATUS_CUR_SLOT(x)         (((uint32_t)(((uint32_t)(x)) << JPGENC_COM_STATUS_CUR_SLOT_SHIFT)) & JPGENC_COM_STATUS_CUR_SLOT_MASK)
#define JPGENC_COM_STATUS_ENC_ONGOING_MASK    (0x80000000U)
#define JPGENC_COM_STATUS_ENC_ONGOING_SHIFT   (31U)
#define JPGENC_COM_STATUS_ENC_ONGOING(x)      (((uint32_t)(((uint32_t)(x)) << JPGENC_COM_STATUS_ENC_ONGOING_SHIFT)) & JPGENC_COM_STATUS_ENC_ONGOING_MASK)

/*! @name IN_BUF_BASE0 - Input Image Frame Buffer0 Base Address */
#define JPGENC_IN_BUF_BASE0_IN_BUF_BASE0_MASK (0xFFFFFFF0U)
#define JPGENC_IN_BUF_BASE0_IN_BUF_BASE0_SHIFT (4U)
#define JPGENC_IN_BUF_BASE0_IN_BUF_BASE0(x)   (((uint32_t)(((uint32_t)(x)) << JPGENC_IN_BUF_BASE0_IN_BUF_BASE0_SHIFT)) & JPGENC_IN_BUF_BASE0_IN_BUF_BASE0_MASK)

/*! @name IN_BUF_BASE1 - Input Image Frame Buffer1 Base Address */
#define JPGENC_IN_BUF_BASE1_IN_BUF_BASE1_MASK (0xFFFFFFF0U)
#define JPGENC_IN_BUF_BASE1_IN_BUF_BASE1_SHIFT (4U)
#define JPGENC_IN_BUF_BASE1_IN_BUF_BASE1(x)   (((uint32_t)(((uint32_t)(x)) << JPGENC_IN_BUF_BASE1_IN_BUF_BASE1_SHIFT)) & JPGENC_IN_BUF_BASE1_IN_BUF_BASE1_MASK)

/*! @name IN_LINE_PITCH - Image Input Buffer Line Pitch */
#define JPGENC_IN_LINE_PITCH_IN_LINE_PITCH_MASK (0xFFFFU)
#define JPGENC_IN_LINE_PITCH_IN_LINE_PITCH_SHIFT (0U)
#define JPGENC_IN_LINE_PITCH_IN_LINE_PITCH(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_IN_LINE_PITCH_IN_LINE_PITCH_SHIFT)) & JPGENC_IN_LINE_PITCH_IN_LINE_PITCH_MASK)

/*! @name STM_BUFBASE - Output JPEG Stream Buffer Base Address */
#define JPGENC_STM_BUFBASE_STM_BUFBASE_MASK   (0xFFFFFFF0U)
#define JPGENC_STM_BUFBASE_STM_BUFBASE_SHIFT  (4U)
#define JPGENC_STM_BUFBASE_STM_BUFBASE(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_STM_BUFBASE_STM_BUFBASE_SHIFT)) & JPGENC_STM_BUFBASE_STM_BUFBASE_MASK)

/*! @name STM_BUFSIZE - Output JPEG Stream Buffer Size */
#define JPGENC_STM_BUFSIZE_STM_BUFSIZE_MASK   (0xFFFFFC00U)
#define JPGENC_STM_BUFSIZE_STM_BUFSIZE_SHIFT  (10U)
#define JPGENC_STM_BUFSIZE_STM_BUFSIZE(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_STM_BUFSIZE_STM_BUFSIZE_SHIFT)) & JPGENC_STM_BUFSIZE_STM_BUFSIZE_MASK)

/*! @name IMGSIZE - Image Resolution */
#define JPGENC_IMGSIZE_IMG_HEIGHT_MASK        (0x3FFFU)
#define JPGENC_IMGSIZE_IMG_HEIGHT_SHIFT       (0U)
#define JPGENC_IMGSIZE_IMG_HEIGHT(x)          (((uint32_t)(((uint32_t)(x)) << JPGENC_IMGSIZE_IMG_HEIGHT_SHIFT)) & JPGENC_IMGSIZE_IMG_HEIGHT_MASK)
#define JPGENC_IMGSIZE_IMG_WIDTH_MASK         (0x3FFF0000U)
#define JPGENC_IMGSIZE_IMG_WIDTH_SHIFT        (16U)
#define JPGENC_IMGSIZE_IMG_WIDTH(x)           (((uint32_t)(((uint32_t)(x)) << JPGENC_IMGSIZE_IMG_WIDTH_SHIFT)) & JPGENC_IMGSIZE_IMG_WIDTH_MASK)

/*! @name STM_CTRL - Bit Stream Switch and Control */
#define JPGENC_STM_CTRL_PIXEL_PRECISION_MASK  (0x4U)
#define JPGENC_STM_CTRL_PIXEL_PRECISION_SHIFT (2U)
#define JPGENC_STM_CTRL_PIXEL_PRECISION(x)    (((uint32_t)(((uint32_t)(x)) << JPGENC_STM_CTRL_PIXEL_PRECISION_SHIFT)) & JPGENC_STM_CTRL_PIXEL_PRECISION_MASK)
#define JPGENC_STM_CTRL_IMAGE_FORMAT_MASK     (0x78U)
#define JPGENC_STM_CTRL_IMAGE_FORMAT_SHIFT    (3U)
#define JPGENC_STM_CTRL_IMAGE_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << JPGENC_STM_CTRL_IMAGE_FORMAT_SHIFT)) & JPGENC_STM_CTRL_IMAGE_FORMAT_MASK)
#define JPGENC_STM_CTRL_BITBUF_PTR_CLR_MASK   (0x80U)
#define JPGENC_STM_CTRL_BITBUF_PTR_CLR_SHIFT  (7U)
#define JPGENC_STM_CTRL_BITBUF_PTR_CLR(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_STM_CTRL_BITBUF_PTR_CLR_SHIFT)) & JPGENC_STM_CTRL_BITBUF_PTR_CLR_MASK)
#define JPGENC_STM_CTRL_AUTO_START_MASK       (0x100U)
#define JPGENC_STM_CTRL_AUTO_START_SHIFT      (8U)
#define JPGENC_STM_CTRL_AUTO_START(x)         (((uint32_t)(((uint32_t)(x)) << JPGENC_STM_CTRL_AUTO_START_SHIFT)) & JPGENC_STM_CTRL_AUTO_START_MASK)
#define JPGENC_STM_CTRL_CONFIG_MOD_MASK       (0x200U)
#define JPGENC_STM_CTRL_CONFIG_MOD_SHIFT      (9U)
#define JPGENC_STM_CTRL_CONFIG_MOD(x)         (((uint32_t)(((uint32_t)(x)) << JPGENC_STM_CTRL_CONFIG_MOD_SHIFT)) & JPGENC_STM_CTRL_CONFIG_MOD_MASK)

/*! @name SLOT_STATUS - Bit Stream SLOT Status */
#define JPGENC_SLOT_STATUS_STMBUF_HALF_MASK   (0x1U)
#define JPGENC_SLOT_STATUS_STMBUF_HALF_SHIFT  (0U)
#define JPGENC_SLOT_STATUS_STMBUF_HALF(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_STMBUF_HALF_SHIFT)) & JPGENC_SLOT_STATUS_STMBUF_HALF_MASK)
#define JPGENC_SLOT_STATUS_STMBUF_RTND_MASK   (0x2U)
#define JPGENC_SLOT_STATUS_STMBUF_RTND_SHIFT  (1U)
#define JPGENC_SLOT_STATUS_STMBUF_RTND(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_STMBUF_RTND_SHIFT)) & JPGENC_SLOT_STATUS_STMBUF_RTND_MASK)
#define JPGENC_SLOT_STATUS_SWITCHED_IN_MASK   (0x4U)
#define JPGENC_SLOT_STATUS_SWITCHED_IN_SHIFT  (2U)
#define JPGENC_SLOT_STATUS_SWITCHED_IN(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_SWITCHED_IN_SHIFT)) & JPGENC_SLOT_STATUS_SWITCHED_IN_MASK)
#define JPGENC_SLOT_STATUS_FRMDONE_MASK       (0x8U)
#define JPGENC_SLOT_STATUS_FRMDONE_SHIFT      (3U)
#define JPGENC_SLOT_STATUS_FRMDONE(x)         (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_FRMDONE_SHIFT)) & JPGENC_SLOT_STATUS_FRMDONE_MASK)
#define JPGENC_SLOT_STATUS_ENC_CONFG_ERR_MASK (0x100U)
#define JPGENC_SLOT_STATUS_ENC_CONFG_ERR_SHIFT (8U)
#define JPGENC_SLOT_STATUS_ENC_CONFG_ERR(x)   (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_ENC_CONFG_ERR_SHIFT)) & JPGENC_SLOT_STATUS_ENC_CONFG_ERR_MASK)
#define JPGENC_SLOT_STATUS_DES_RD_ERR_MASK    (0x200U)
#define JPGENC_SLOT_STATUS_DES_RD_ERR_SHIFT   (9U)
#define JPGENC_SLOT_STATUS_DES_RD_ERR(x)      (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_DES_RD_ERR_SHIFT)) & JPGENC_SLOT_STATUS_DES_RD_ERR_MASK)
#define JPGENC_SLOT_STATUS_BIT_WT_ERR_MASK    (0x400U)
#define JPGENC_SLOT_STATUS_BIT_WT_ERR_SHIFT   (10U)
#define JPGENC_SLOT_STATUS_BIT_WT_ERR(x)      (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_BIT_WT_ERR_SHIFT)) & JPGENC_SLOT_STATUS_BIT_WT_ERR_MASK)
#define JPGENC_SLOT_STATUS_IMG_RD_ERR_MASK    (0x800U)
#define JPGENC_SLOT_STATUS_IMG_RD_ERR_SHIFT   (11U)
#define JPGENC_SLOT_STATUS_IMG_RD_ERR(x)      (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_IMG_RD_ERR_SHIFT)) & JPGENC_SLOT_STATUS_IMG_RD_ERR_MASK)
#define JPGENC_SLOT_STATUS_CUR_SLOT_MASK      (0x60000000U)
#define JPGENC_SLOT_STATUS_CUR_SLOT_SHIFT     (29U)
#define JPGENC_SLOT_STATUS_CUR_SLOT(x)        (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_CUR_SLOT_SHIFT)) & JPGENC_SLOT_STATUS_CUR_SLOT_MASK)
#define JPGENC_SLOT_STATUS_ENC_ONGOING_MASK   (0x80000000U)
#define JPGENC_SLOT_STATUS_ENC_ONGOING_SHIFT  (31U)
#define JPGENC_SLOT_STATUS_ENC_ONGOING(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_STATUS_ENC_ONGOING_SHIFT)) & JPGENC_SLOT_STATUS_ENC_ONGOING_MASK)

/* The count of JPGENC_SLOT_STATUS */
#define JPGENC_SLOT_STATUS_COUNT              (4U)

/*! @name SLOT_IRQ_EN - Bit Stream Interrupt Enable Register */
#define JPGENC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK (0x1U)
#define JPGENC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT (0U)
#define JPGENC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK)
#define JPGENC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK (0x2U)
#define JPGENC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT (1U)
#define JPGENC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK)
#define JPGENC_SLOT_IRQ_EN_SWITHCED_IN_IRQ_EN_MASK (0x4U)
#define JPGENC_SLOT_IRQ_EN_SWITHCED_IN_IRQ_EN_SHIFT (2U)
#define JPGENC_SLOT_IRQ_EN_SWITHCED_IN_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_SWITHCED_IN_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_SWITHCED_IN_IRQ_EN_MASK)
#define JPGENC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK (0x8U)
#define JPGENC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT (3U)
#define JPGENC_SLOT_IRQ_EN_FRMDONE_IRQ_EN(x)  (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK)
#define JPGENC_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_MASK (0x100U)
#define JPGENC_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_SHIFT (8U)
#define JPGENC_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_MASK)
#define JPGENC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK (0x200U)
#define JPGENC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT (9U)
#define JPGENC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK)
#define JPGENC_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_MASK (0x400U)
#define JPGENC_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_SHIFT (10U)
#define JPGENC_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_MASK)
#define JPGENC_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_MASK (0x800U)
#define JPGENC_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_SHIFT (11U)
#define JPGENC_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_SHIFT)) & JPGENC_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_MASK)

/* The count of JPGENC_SLOT_IRQ_EN */
#define JPGENC_SLOT_IRQ_EN_COUNT              (4U)

/*! @name SLOT_BUF_PTR - Bit Stream Buffer Pointer */
#define JPGENC_SLOT_BUF_PTR_STMBUF_PTR_MASK   (0xFFFFFFFFU)
#define JPGENC_SLOT_BUF_PTR_STMBUF_PTR_SHIFT  (0U)
#define JPGENC_SLOT_BUF_PTR_STMBUF_PTR(x)     (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_BUF_PTR_STMBUF_PTR_SHIFT)) & JPGENC_SLOT_BUF_PTR_STMBUF_PTR_MASK)

/* The count of JPGENC_SLOT_BUF_PTR */
#define JPGENC_SLOT_BUF_PTR_COUNT             (4U)

/*! @name SLOT_CUR_DESCPT_PTR - Current Encoding Descriptor Pointer */
#define JPGENC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK (0xFFFFFFFCU)
#define JPGENC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT (2U)
#define JPGENC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT)) & JPGENC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK)

/* The count of JPGENC_SLOT_CUR_DESCPT_PTR */
#define JPGENC_SLOT_CUR_DESCPT_PTR_COUNT      (4U)

/*! @name SLOT_NXT_DESCPT_PTR - Next Encoding Descriptor Pointer */
#define JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_MASK (0x1U)
#define JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_SHIFT (0U)
#define JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_SHIFT)) & JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_MASK)
#define JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_MASK (0xFFFFFFFCU)
#define JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_SHIFT (2U)
#define JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT(x) (((uint32_t)(((uint32_t)(x)) << JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_SHIFT)) & JPGENC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_MASK)

/* The count of JPGENC_SLOT_NXT_DESCPT_PTR */
#define JPGENC_SLOT_NXT_DESCPT_PTR_COUNT      (4U)


/*!
 * @}
 */ /* end of group JPGENC_Register_Masks */


/* JPGENC - Peripheral instance base addresses */
/** Peripheral JPGENCWRP base address */
#define JPGENC_BASE                           (0u)
/** Peripheral JPGENCWRP base pointer */
#define JPGENC                                ((JPGENC_Type *)JPGENC_BASE)
/** Array initializer of JPGENC peripheral base addresses */
#define JPGENC_BASE_ADDRS                     { JPGENC_BASE }
/** Array initializer of JPGENC peripheral base pointers */
#define JPGENC_BASE_PTRS                      { JPGENC }

/*!
 * @}
 */ /* end of group JPGENC_Peripheral_Access_Layer */


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


#endif  /* JPGENC_H */

