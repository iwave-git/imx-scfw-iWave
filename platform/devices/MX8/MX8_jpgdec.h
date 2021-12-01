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
 * @file MX8_jpegdec.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer JPGDEC
 *
 * CMSIS Peripheral Access Layer for JPGDEC
 */

#ifndef JPGDEC_H
#define JPGDEC_H            /**< Symbol preventing repeated inclusion */


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
   -- JPGDEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPGDEC_Peripheral_Access_Layer JPGDEC Peripheral Access Layer
 * @{
 */

/** JPGDEC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GLB_CTRL;                          /**< Global Control, offset: 0x0 */
  __I  uint32_t COM_STATUS;                        /**< Common Status, offset: 0x4 */
  __I  uint32_t RSVD_COM_IRQ_EN;                   /**< RSVD, offset: 0x8 */
  __I  uint32_t RSVD_CUR_DESCPT_PTR;               /**< RSVD, offset: 0xC */
  __I  uint32_t RSVD_NXT_DESCPT_PTR;               /**< RSVD, offset: 0x10 */
  __IO uint32_t OUT_BUF_BASE0;                     /**< Output Image Frame Buffer0 Base Address, offset: 0x14 */
  __IO uint32_t OUT_BUF_BASE1;                     /**< Output Image Frame Buffer1 Base Address, offset: 0x18 */
  __IO uint32_t OUT_PITCH;                         /**< Image Output Buffer Pitch, offset: 0x1C */
  __IO uint32_t STM_BUFBASE;                       /**< Input JPEG Stream Buffer Base Address, offset: 0x20 */
  __IO uint32_t STM_BUFSIZE;                       /**< Input JPEG Stream Buffer Size, offset: 0x24 */
  __IO uint32_t IMGSIZE;                           /**< Image Resolution, offset: 0x28 */
  __IO uint32_t STM_CTRL;                          /**< Bit Stream and Switching Control, offset: 0x2C */
       uint8_t RESERVED_0[65488];
  struct {                                         /* offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_STATUS;                       /**< Bitstream Status, array offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_IRQ_EN;                       /**< Bitstream Interrupt Enable, array offset: 0x10004, array step: 0x10000 */
    __I  uint32_t SLOT_BUF_PTR;                      /**< Bitstream Buffer Pointer, array offset: 0x10008, array step: 0x10000 */
    __I  uint32_t SLOT_CUR_DESCPT_PTR;               /**< Current Descriptors, array offset: 0x1000C, array step: 0x10000 */
    __IO uint32_t SLOT_NXT_DESCPT_PTR;               /**< Next Descriptors, array offset: 0x10010, array step: 0x10000 */
         uint8_t RESERVED_0[65516];
  } BITSTRM_SLOT_REGS[4];
} JPGDEC_Type;

/* ----------------------------------------------------------------------------
   -- JPGDEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPGDEC_Register_Masks JPGDEC Register Masks
 * @{
 */

/*! @name GLB_CTRL - Global Control */
#define JPGDEC_GLB_CTRL_JPG_DEC_EN_MASK       (0x1U)
#define JPGDEC_GLB_CTRL_JPG_DEC_EN_SHIFT      (0U)
#define JPGDEC_GLB_CTRL_JPG_DEC_EN(x)         (((uint32_t)(((uint32_t)(x)) << JPGDEC_GLB_CTRL_JPG_DEC_EN_SHIFT)) & JPGDEC_GLB_CTRL_JPG_DEC_EN_MASK)
#define JPGDEC_GLB_CTRL_SFTRST_MASK           (0x2U)
#define JPGDEC_GLB_CTRL_SFTRST_SHIFT          (1U)
#define JPGDEC_GLB_CTRL_SFTRST(x)             (((uint32_t)(((uint32_t)(x)) << JPGDEC_GLB_CTRL_SFTRST_SHIFT)) & JPGDEC_GLB_CTRL_SFTRST_MASK)
#define JPGDEC_GLB_CTRL_DEC_GO_MASK           (0x4U)
#define JPGDEC_GLB_CTRL_DEC_GO_SHIFT          (2U)
#define JPGDEC_GLB_CTRL_DEC_GO(x)             (((uint32_t)(((uint32_t)(x)) << JPGDEC_GLB_CTRL_DEC_GO_SHIFT)) & JPGDEC_GLB_CTRL_DEC_GO_MASK)
#define JPGDEC_GLB_CTRL_L_ENDIAN_MASK         (0x8U)
#define JPGDEC_GLB_CTRL_L_ENDIAN_SHIFT        (3U)
#define JPGDEC_GLB_CTRL_L_ENDIAN(x)           (((uint32_t)(((uint32_t)(x)) << JPGDEC_GLB_CTRL_L_ENDIAN_SHIFT)) & JPGDEC_GLB_CTRL_L_ENDIAN_MASK)
#define JPGDEC_GLB_CTRL_SLOT_EN_MASK          (0xF0U)
#define JPGDEC_GLB_CTRL_SLOT_EN_SHIFT         (4U)
#define JPGDEC_GLB_CTRL_SLOT_EN(x)            (((uint32_t)(((uint32_t)(x)) << JPGDEC_GLB_CTRL_SLOT_EN_SHIFT)) & JPGDEC_GLB_CTRL_SLOT_EN_MASK)

/*! @name COM_STATUS - Common Status */
#define JPGDEC_COM_STATUS_CUR_SLOT_MASK       (0x60000000U)
#define JPGDEC_COM_STATUS_CUR_SLOT_SHIFT      (29U)
#define JPGDEC_COM_STATUS_CUR_SLOT(x)         (((uint32_t)(((uint32_t)(x)) << JPGDEC_COM_STATUS_CUR_SLOT_SHIFT)) & JPGDEC_COM_STATUS_CUR_SLOT_MASK)
#define JPGDEC_COM_STATUS_DEC_ONGOING_MASK    (0x80000000U)
#define JPGDEC_COM_STATUS_DEC_ONGOING_SHIFT   (31U)
#define JPGDEC_COM_STATUS_DEC_ONGOING(x)      (((uint32_t)(((uint32_t)(x)) << JPGDEC_COM_STATUS_DEC_ONGOING_SHIFT)) & JPGDEC_COM_STATUS_DEC_ONGOING_MASK)

/*! @name OUT_BUF_BASE0 - Output Image Frame Buffer0 Base Address */
#define JPGDEC_OUT_BUF_BASE0_OUT_BUF_BASE0_MASK (0xFFFFFFF0U)
#define JPGDEC_OUT_BUF_BASE0_OUT_BUF_BASE0_SHIFT (4U)
#define JPGDEC_OUT_BUF_BASE0_OUT_BUF_BASE0(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_OUT_BUF_BASE0_OUT_BUF_BASE0_SHIFT)) & JPGDEC_OUT_BUF_BASE0_OUT_BUF_BASE0_MASK)

/*! @name OUT_BUF_BASE1 - Output Image Frame Buffer1 Base Address */
#define JPGDEC_OUT_BUF_BASE1_OUT_BUF_BASE1_MASK (0xFFFFFFF0U)
#define JPGDEC_OUT_BUF_BASE1_OUT_BUF_BASE1_SHIFT (4U)
#define JPGDEC_OUT_BUF_BASE1_OUT_BUF_BASE1(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_OUT_BUF_BASE1_OUT_BUF_BASE1_SHIFT)) & JPGDEC_OUT_BUF_BASE1_OUT_BUF_BASE1_MASK)

/*! @name OUT_PITCH - Image Output Buffer Pitch */
#define JPGDEC_OUT_PITCH_OUT_PITCH_MASK       (0xFFFFU)
#define JPGDEC_OUT_PITCH_OUT_PITCH_SHIFT      (0U)
#define JPGDEC_OUT_PITCH_OUT_PITCH(x)         (((uint32_t)(((uint32_t)(x)) << JPGDEC_OUT_PITCH_OUT_PITCH_SHIFT)) & JPGDEC_OUT_PITCH_OUT_PITCH_MASK)

/*! @name STM_BUFBASE - Input JPEG Stream Buffer Base Address */
#define JPGDEC_STM_BUFBASE_STM_BUFBASE_MASK   (0xFFFFFFF0U)
#define JPGDEC_STM_BUFBASE_STM_BUFBASE_SHIFT  (4U)
#define JPGDEC_STM_BUFBASE_STM_BUFBASE(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_STM_BUFBASE_STM_BUFBASE_SHIFT)) & JPGDEC_STM_BUFBASE_STM_BUFBASE_MASK)

/*! @name STM_BUFSIZE - Input JPEG Stream Buffer Size */
#define JPGDEC_STM_BUFSIZE_STM_BUFSIZE_MASK   (0xFFFFFC00U)
#define JPGDEC_STM_BUFSIZE_STM_BUFSIZE_SHIFT  (10U)
#define JPGDEC_STM_BUFSIZE_STM_BUFSIZE(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_STM_BUFSIZE_STM_BUFSIZE_SHIFT)) & JPGDEC_STM_BUFSIZE_STM_BUFSIZE_MASK)

/*! @name IMGSIZE - Image Resolution */
#define JPGDEC_IMGSIZE_IMG_HEIGHT_MASK        (0x3FFFU)
#define JPGDEC_IMGSIZE_IMG_HEIGHT_SHIFT       (0U)
#define JPGDEC_IMGSIZE_IMG_HEIGHT(x)          (((uint32_t)(((uint32_t)(x)) << JPGDEC_IMGSIZE_IMG_HEIGHT_SHIFT)) & JPGDEC_IMGSIZE_IMG_HEIGHT_MASK)
#define JPGDEC_IMGSIZE_IMG_WIDTH_MASK         (0x3FFF0000U)
#define JPGDEC_IMGSIZE_IMG_WIDTH_SHIFT        (16U)
#define JPGDEC_IMGSIZE_IMG_WIDTH(x)           (((uint32_t)(((uint32_t)(x)) << JPGDEC_IMGSIZE_IMG_WIDTH_SHIFT)) & JPGDEC_IMGSIZE_IMG_WIDTH_MASK)

/*! @name STM_CTRL - Bit Stream and Switching Control */
#define JPGDEC_STM_CTRL_PIXEL_PRECISION_MASK  (0x4U)
#define JPGDEC_STM_CTRL_PIXEL_PRECISION_SHIFT (2U)
#define JPGDEC_STM_CTRL_PIXEL_PRECISION(x)    (((uint32_t)(((uint32_t)(x)) << JPGDEC_STM_CTRL_PIXEL_PRECISION_SHIFT)) & JPGDEC_STM_CTRL_PIXEL_PRECISION_MASK)
#define JPGDEC_STM_CTRL_IMAGE_FORMAT_MASK     (0x78U)
#define JPGDEC_STM_CTRL_IMAGE_FORMAT_SHIFT    (3U)
#define JPGDEC_STM_CTRL_IMAGE_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << JPGDEC_STM_CTRL_IMAGE_FORMAT_SHIFT)) & JPGDEC_STM_CTRL_IMAGE_FORMAT_MASK)
#define JPGDEC_STM_CTRL_BITBUF_PTR_CLR_MASK   (0x80U)
#define JPGDEC_STM_CTRL_BITBUF_PTR_CLR_SHIFT  (7U)
#define JPGDEC_STM_CTRL_BITBUF_PTR_CLR(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_STM_CTRL_BITBUF_PTR_CLR_SHIFT)) & JPGDEC_STM_CTRL_BITBUF_PTR_CLR_MASK)
#define JPGDEC_STM_CTRL_AUTO_START_MASK       (0x100U)
#define JPGDEC_STM_CTRL_AUTO_START_SHIFT      (8U)
#define JPGDEC_STM_CTRL_AUTO_START(x)         (((uint32_t)(((uint32_t)(x)) << JPGDEC_STM_CTRL_AUTO_START_SHIFT)) & JPGDEC_STM_CTRL_AUTO_START_MASK)

/*! @name SLOT_STATUS - Bitstream Status */
#define JPGDEC_SLOT_STATUS_STMBUF_HALF_MASK   (0x1U)
#define JPGDEC_SLOT_STATUS_STMBUF_HALF_SHIFT  (0U)
#define JPGDEC_SLOT_STATUS_STMBUF_HALF(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_STMBUF_HALF_SHIFT)) & JPGDEC_SLOT_STATUS_STMBUF_HALF_MASK)
#define JPGDEC_SLOT_STATUS_STMBUF_RTND_MASK   (0x2U)
#define JPGDEC_SLOT_STATUS_STMBUF_RTND_SHIFT  (1U)
#define JPGDEC_SLOT_STATUS_STMBUF_RTND(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_STMBUF_RTND_SHIFT)) & JPGDEC_SLOT_STATUS_STMBUF_RTND_MASK)
#define JPGDEC_SLOT_STATUS_SWITCHED_IN_MASK   (0x4U)
#define JPGDEC_SLOT_STATUS_SWITCHED_IN_SHIFT  (2U)
#define JPGDEC_SLOT_STATUS_SWITCHED_IN(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_SWITCHED_IN_SHIFT)) & JPGDEC_SLOT_STATUS_SWITCHED_IN_MASK)
#define JPGDEC_SLOT_STATUS_FRMDONE_MASK       (0x8U)
#define JPGDEC_SLOT_STATUS_FRMDONE_SHIFT      (3U)
#define JPGDEC_SLOT_STATUS_FRMDONE(x)         (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_FRMDONE_SHIFT)) & JPGDEC_SLOT_STATUS_FRMDONE_MASK)
#define JPGDEC_SLOT_STATUS_DECERR_MASK        (0x100U)
#define JPGDEC_SLOT_STATUS_DECERR_SHIFT       (8U)
#define JPGDEC_SLOT_STATUS_DECERR(x)          (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_DECERR_SHIFT)) & JPGDEC_SLOT_STATUS_DECERR_MASK)
#define JPGDEC_SLOT_STATUS_DES_RD_ERR_MASK    (0x200U)
#define JPGDEC_SLOT_STATUS_DES_RD_ERR_SHIFT   (9U)
#define JPGDEC_SLOT_STATUS_DES_RD_ERR(x)      (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_DES_RD_ERR_SHIFT)) & JPGDEC_SLOT_STATUS_DES_RD_ERR_MASK)
#define JPGDEC_SLOT_STATUS_BIT_RD_ERR_MASK    (0x400U)
#define JPGDEC_SLOT_STATUS_BIT_RD_ERR_SHIFT   (10U)
#define JPGDEC_SLOT_STATUS_BIT_RD_ERR(x)      (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_BIT_RD_ERR_SHIFT)) & JPGDEC_SLOT_STATUS_BIT_RD_ERR_MASK)
#define JPGDEC_SLOT_STATUS_PIXEL_WT_ERR_MASK  (0x800U)
#define JPGDEC_SLOT_STATUS_PIXEL_WT_ERR_SHIFT (11U)
#define JPGDEC_SLOT_STATUS_PIXEL_WT_ERR(x)    (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_PIXEL_WT_ERR_SHIFT)) & JPGDEC_SLOT_STATUS_PIXEL_WT_ERR_MASK)
#define JPGDEC_SLOT_STATUS_CUR_SLOT_MASK      (0x60000000U)
#define JPGDEC_SLOT_STATUS_CUR_SLOT_SHIFT     (29U)
#define JPGDEC_SLOT_STATUS_CUR_SLOT(x)        (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_CUR_SLOT_SHIFT)) & JPGDEC_SLOT_STATUS_CUR_SLOT_MASK)
#define JPGDEC_SLOT_STATUS_DEC_ONGOING_MASK   (0x80000000U)
#define JPGDEC_SLOT_STATUS_DEC_ONGOING_SHIFT  (31U)
#define JPGDEC_SLOT_STATUS_DEC_ONGOING(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_STATUS_DEC_ONGOING_SHIFT)) & JPGDEC_SLOT_STATUS_DEC_ONGOING_MASK)

/* The count of JPGDEC_SLOT_STATUS */
#define JPGDEC_SLOT_STATUS_COUNT              (4U)

/*! @name SLOT_IRQ_EN - Bitstream Interrupt Enable */
#define JPGDEC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK (0x1U)
#define JPGDEC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT (0U)
#define JPGDEC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK)
#define JPGDEC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK (0x2U)
#define JPGDEC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT (1U)
#define JPGDEC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK)
#define JPGDEC_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK (0x4U)
#define JPGDEC_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT (2U)
#define JPGDEC_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK)
#define JPGDEC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK (0x8U)
#define JPGDEC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT (3U)
#define JPGDEC_SLOT_IRQ_EN_FRMDONE_IRQ_EN(x)  (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK)
#define JPGDEC_SLOT_IRQ_EN_DECERR_IRQ_EN_MASK (0x100U)
#define JPGDEC_SLOT_IRQ_EN_DECERR_IRQ_EN_SHIFT (8U)
#define JPGDEC_SLOT_IRQ_EN_DECERR_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_DECERR_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_DECERR_IRQ_EN_MASK)
#define JPGDEC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK (0x200U)
#define JPGDEC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT (9U)
#define JPGDEC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK)
#define JPGDEC_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_MASK (0x400U)
#define JPGDEC_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_SHIFT (10U)
#define JPGDEC_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_MASK)
#define JPGDEC_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_MASK (0x800U)
#define JPGDEC_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_SHIFT (11U)
#define JPGDEC_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_SHIFT)) & JPGDEC_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_MASK)

/* The count of JPGDEC_SLOT_IRQ_EN */
#define JPGDEC_SLOT_IRQ_EN_COUNT              (4U)

/*! @name SLOT_BUF_PTR - Bitstream Buffer Pointer */
#define JPGDEC_SLOT_BUF_PTR_STMBUF_PTR_MASK   (0xFFFFFFFFU)
#define JPGDEC_SLOT_BUF_PTR_STMBUF_PTR_SHIFT  (0U)
#define JPGDEC_SLOT_BUF_PTR_STMBUF_PTR(x)     (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_BUF_PTR_STMBUF_PTR_SHIFT)) & JPGDEC_SLOT_BUF_PTR_STMBUF_PTR_MASK)

/* The count of JPGDEC_SLOT_BUF_PTR */
#define JPGDEC_SLOT_BUF_PTR_COUNT             (4U)

/*! @name SLOT_CUR_DESCPT_PTR - Current Descriptors */
#define JPGDEC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK (0xFFFFFFFCU)
#define JPGDEC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT (2U)
#define JPGDEC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT)) & JPGDEC_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK)

/* The count of JPGDEC_SLOT_CUR_DESCPT_PTR */
#define JPGDEC_SLOT_CUR_DESCPT_PTR_COUNT      (4U)

/*! @name SLOT_NXT_DESCPT_PTR - Next Descriptors */
#define JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_MASK (0x1U)
#define JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_SHIFT (0U)
#define JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_SHIFT)) & JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_MASK)
#define JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_MASK (0xFFFFFFFCU)
#define JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_SHIFT (2U)
#define JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT(x) (((uint32_t)(((uint32_t)(x)) << JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_SHIFT)) & JPGDEC_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PRT_MASK)

/* The count of JPGDEC_SLOT_NXT_DESCPT_PTR */
#define JPGDEC_SLOT_NXT_DESCPT_PTR_COUNT      (4U)


/*!
 * @}
 */ /* end of group JPGDEC_Register_Masks */


/* JPGDEC - Peripheral instance base addresses */
/** Peripheral JPEG_DEC base address */
#define JPEGDEC_BASE                            (0u)
/** Peripheral JPEG_DEC base pointer */
#define JPEGDEC                                 ((JPGDEC_Type *)JPEGDEC_BASE)
/** Array initializer of JPGDEC peripheral base addresses */
#define JPGDEC_BASE_ADDRS                     { JPEGDEC_BASE }
/** Array initializer of JPGDEC peripheral base pointers */
#define JPGDEC_BASE_PTRS                      { JPEGDEC }

/*!
 * @}
 */ /* end of group JPGDEC_Peripheral_Access_Layer */


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


#endif  /* JPGDEC_H */

