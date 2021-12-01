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
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file stc.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for stc
 *
 * CMSIS Peripheral Access Layer for stc
 */

#ifndef STC_H
#define STC_H                                  /**< Symbol preventing repeated inclusion */


/* ----------------------------------------------------------------------------
   -- STC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STC_Peripheral_Access_Layer STC Peripheral Access Layer
 * @{
 */

/** STC - Register Layout Typedef */
typedef struct {
  __IO uint32_t INTERLEAVE_SEL;                    /**< Interleave Select, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __I  uint32_t RVSD_HPR_ENABLE;                   /**< Highest Priority Request scheduler enable, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t UD_ENABLE;                         /**< Underrun Detection Enable, offset: 0x20 */
       uint8_t RESERVED_2[12];
  __IO uint32_t TDM_ENABLE;                        /**< TDM Function Enable, offset: 0x30 */
       uint8_t RESERVED_3[12];
  __IO uint32_t TDM_ALWAYS_ALLOW;                  /**< TDM Always Allow, offset: 0x40 */
       uint8_t RESERVED_4[12];
  __IO uint32_t GLB_CSCHED_WAIT_COUNT;             /**< Global Completion Scheduler Wait Count, offset: 0x50 */
       uint8_t RESERVED_5[12];
  __IO uint32_t MASK_ID[8];                        /**< MASK for the AxID Hash Function, array offset: 0x60, array step: 0x4 */
  __IO uint32_t COMPARE_ID[8];                     /**< COMPARE ID for the AxID Hash Function, array offset: 0x80, array step: 0x4 */
  __IO uint32_t MIN_QOS[8];                        /**< Minimum QoS Clamp, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t MAX_QOS[8];                        /**< Maximum QOS Clamp, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_6[32];
  __IO uint32_t PANIC_QOS_OFFSET[8];               /**< Panic QoS Offset value, array offset: 0x100, array step: 0x4 */
  __IO uint32_t HPR_QOS_OFFSET[8];                 /**< Highest Priority QoS Offset value, array offset: 0x120, array step: 0x4 */
  __IO uint32_t UD_QOS_OFFSET[8];                  /**< Underrun Detect QoS Offset value, array offset: 0x140, array step: 0x4 */
  __IO uint32_t UD_COUNT_DECR_VALUE[8];            /**< Decrement value of under run counter., array offset: 0x160, array step: 0x4 */
  __IO uint32_t UD_COUNT_THRESH_1[8];              /**< Underrun counter threshold 1, array offset: 0x180, array step: 0x4 */
       uint8_t RESERVED_7[96];
  __IO uint32_t UD_COUNT_THRESH_2[8];              /**< Underrun counter threshold 2, array offset: 0x200, array step: 0x4 */
  __IO uint32_t CSCHED_WAIT_COUNT[8];              /**< Category Completion Scheduler wait count for completion returns, array offset: 0x220, array step: 0x4 */
       uint8_t RESERVED_8[32];
  __IO uint32_t TDM_QOS_OFFSET[8];                 /**< TDM QoS OFFSET, array offset: 0x260, array step: 0x4 */
       uint8_t RESERVED_9[128];
  __IO uint32_t TDM_START0_COUNT[8];               /**< Time Division Multiplexed Start0 count, array offset: 0x300, array step: 0x4 */
  __IO uint32_t TDM_STOP0_COUNT[8];                /**< Time Division Multiplexed stop0 count, array offset: 0x320, array step: 0x4 */
  __IO uint32_t TDM_START1_COUNT[8];               /**< Time Division Multiplexed start1 count, array offset: 0x340, array step: 0x4 */
  __IO uint32_t TDM_STOP1_COUNT[8];                /**< Time Division Multiplexed stop1 count, array offset: 0x360, array step: 0x4 */
  __IO uint32_t TDM_START2_COUNT[8];               /**< Time Division Multiplexed start2 count, array offset: 0x380, array step: 0x4 */
  __IO uint32_t TDM_STOP2_COUNT[8];                /**< Time Division Multiplexed stop2 count, array offset: 0x3A0, array step: 0x4 */
  __IO uint32_t TDM_START3_COUNT[8];               /**< Time Division Multiplexed start3 count, array offset: 0x3C0, array step: 0x4 */
  __IO uint32_t TDM_STOP3_COUNT[8];                /**< Time Division Multiplexed stop3 count, array offset: 0x3E0, array step: 0x4 */
} STC_Type;

/* ----------------------------------------------------------------------------
   -- STC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STC_Register_Masks STC Register Masks
 * @{
 */

/*! @name INTERLEAVE_SEL - Interleave Select */
#define STC_INTERLEAVE_SEL_INTERLEAVE_SEL_MASK   (0x3U)
#define STC_INTERLEAVE_SEL_INTERLEAVE_SEL_SHIFT  (0U)
#define STC_INTERLEAVE_SEL_INTERLEAVE_SEL(x)     (((uint32_t)(((uint32_t)(x)) << STC_INTERLEAVE_SEL_INTERLEAVE_SEL_SHIFT)) & STC_INTERLEAVE_SEL_INTERLEAVE_SEL_MASK)

/*! @name UD_ENABLE - Underrun Detection Enable */
#define STC_UD_ENABLE_UD_ENABLE_MASK             (0xFFU)
#define STC_UD_ENABLE_UD_ENABLE_SHIFT            (0U)
#define STC_UD_ENABLE_UD_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << STC_UD_ENABLE_UD_ENABLE_SHIFT)) & STC_UD_ENABLE_UD_ENABLE_MASK)

/*! @name TDM_ENABLE - TDM Function Enable */
#define STC_TDM_ENABLE_TDM_ENABLE_MASK           (0xFFU)
#define STC_TDM_ENABLE_TDM_ENABLE_SHIFT          (0U)
#define STC_TDM_ENABLE_TDM_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << STC_TDM_ENABLE_TDM_ENABLE_SHIFT)) & STC_TDM_ENABLE_TDM_ENABLE_MASK)

/*! @name TDM_ALWAYS_ALLOW - TDM Always Allow */
#define STC_TDM_ALWAYS_ALLOW_TDM_ALWAYS_ALLOW_MASK (0xFFU)
#define STC_TDM_ALWAYS_ALLOW_TDM_ALWAYS_ALLOW_SHIFT (0U)
#define STC_TDM_ALWAYS_ALLOW_TDM_ALWAYS_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << STC_TDM_ALWAYS_ALLOW_TDM_ALWAYS_ALLOW_SHIFT)) & STC_TDM_ALWAYS_ALLOW_TDM_ALWAYS_ALLOW_MASK)

/*! @name GLB_CSCHED_WAIT_COUNT - Global Completion Scheduler Wait Count */
#define STC_GLB_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_MASK (0x7U)
#define STC_GLB_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_SHIFT (0U)
#define STC_GLB_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << STC_GLB_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_SHIFT)) & STC_GLB_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_MASK)

/*! @name MASK_ID - MASK for the AxID Hash Function */
#define STC_MASK_ID_MASK_ID_MASK                 (0xFFFU)
#define STC_MASK_ID_MASK_ID_SHIFT                (0U)
#define STC_MASK_ID_MASK_ID(x)                   (((uint32_t)(((uint32_t)(x)) << STC_MASK_ID_MASK_ID_SHIFT)) & STC_MASK_ID_MASK_ID_MASK)

/* The count of STC_MASK_ID */
#define STC_MASK_ID_COUNT                        (8U)

/*! @name COMPARE_ID - COMPARE ID for the AxID Hash Function */
#define STC_COMPARE_ID_COMPARE_ID_MASK           (0xFFFU)
#define STC_COMPARE_ID_COMPARE_ID_SHIFT          (0U)
#define STC_COMPARE_ID_COMPARE_ID(x)             (((uint32_t)(((uint32_t)(x)) << STC_COMPARE_ID_COMPARE_ID_SHIFT)) & STC_COMPARE_ID_COMPARE_ID_MASK)

/* The count of STC_COMPARE_ID */
#define STC_COMPARE_ID_COUNT                     (8U)

/*! @name MIN_QOS - Minimum QoS Clamp */
#define STC_MIN_QOS_MIN_QOS_MASK                 (0xFU)
#define STC_MIN_QOS_MIN_QOS_SHIFT                (0U)
#define STC_MIN_QOS_MIN_QOS(x)                   (((uint32_t)(((uint32_t)(x)) << STC_MIN_QOS_MIN_QOS_SHIFT)) & STC_MIN_QOS_MIN_QOS_MASK)

/* The count of STC_MIN_QOS */
#define STC_MIN_QOS_COUNT                        (8U)

/*! @name MAX_QOS - Maximum QOS Clamp */
#define STC_MAX_QOS_MAX_QOS_MASK                 (0xFU)
#define STC_MAX_QOS_MAX_QOS_SHIFT                (0U)
#define STC_MAX_QOS_MAX_QOS(x)                   (((uint32_t)(((uint32_t)(x)) << STC_MAX_QOS_MAX_QOS_SHIFT)) & STC_MAX_QOS_MAX_QOS_MASK)

/* The count of STC_MAX_QOS */
#define STC_MAX_QOS_COUNT                        (8U)

/*! @name PANIC_QOS_OFFSET - Panic QoS Offset value */
#define STC_PANIC_QOS_OFFSET_PANIC_QOS_OFFSET_MASK (0xFU)
#define STC_PANIC_QOS_OFFSET_PANIC_QOS_OFFSET_SHIFT (0U)
#define STC_PANIC_QOS_OFFSET_PANIC_QOS_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << STC_PANIC_QOS_OFFSET_PANIC_QOS_OFFSET_SHIFT)) & STC_PANIC_QOS_OFFSET_PANIC_QOS_OFFSET_MASK)

/* The count of STC_PANIC_QOS_OFFSET */
#define STC_PANIC_QOS_OFFSET_COUNT               (8U)

/*! @name HPR_QOS_OFFSET - Highest Priority QoS Offset value */
#define STC_HPR_QOS_OFFSET_HPR_QOS_OFFSET_MASK   (0xFU)
#define STC_HPR_QOS_OFFSET_HPR_QOS_OFFSET_SHIFT  (0U)
#define STC_HPR_QOS_OFFSET_HPR_QOS_OFFSET(x)     (((uint32_t)(((uint32_t)(x)) << STC_HPR_QOS_OFFSET_HPR_QOS_OFFSET_SHIFT)) & STC_HPR_QOS_OFFSET_HPR_QOS_OFFSET_MASK)

/* The count of STC_HPR_QOS_OFFSET */
#define STC_HPR_QOS_OFFSET_COUNT                 (8U)

/*! @name UD_QOS_OFFSET - Underrun Detect QoS Offset value */
#define STC_UD_QOS_OFFSET_UD_QOS_OFFSET_MASK     (0xFU)
#define STC_UD_QOS_OFFSET_UD_QOS_OFFSET_SHIFT    (0U)
#define STC_UD_QOS_OFFSET_UD_QOS_OFFSET(x)       (((uint32_t)(((uint32_t)(x)) << STC_UD_QOS_OFFSET_UD_QOS_OFFSET_SHIFT)) & STC_UD_QOS_OFFSET_UD_QOS_OFFSET_MASK)

/* The count of STC_UD_QOS_OFFSET */
#define STC_UD_QOS_OFFSET_COUNT                  (8U)

/*! @name UD_COUNT_DECR_VALUE - Decrement value of under run counter. */
#define STC_UD_COUNT_DECR_VALUE_UD_COUNT_DECR_VALUE_MASK (0x7FU)
#define STC_UD_COUNT_DECR_VALUE_UD_COUNT_DECR_VALUE_SHIFT (0U)
#define STC_UD_COUNT_DECR_VALUE_UD_COUNT_DECR_VALUE(x) (((uint32_t)(((uint32_t)(x)) << STC_UD_COUNT_DECR_VALUE_UD_COUNT_DECR_VALUE_SHIFT)) & STC_UD_COUNT_DECR_VALUE_UD_COUNT_DECR_VALUE_MASK)

/* The count of STC_UD_COUNT_DECR_VALUE */
#define STC_UD_COUNT_DECR_VALUE_COUNT            (8U)

/*! @name UD_COUNT_THRESH_1 - Underrun counter threshold 1 */
#define STC_UD_COUNT_THRESH_1_UD_COUNT_THRESH_1_MASK (0x7FU)
#define STC_UD_COUNT_THRESH_1_UD_COUNT_THRESH_1_SHIFT (0U)
#define STC_UD_COUNT_THRESH_1_UD_COUNT_THRESH_1(x) (((uint32_t)(((uint32_t)(x)) << STC_UD_COUNT_THRESH_1_UD_COUNT_THRESH_1_SHIFT)) & STC_UD_COUNT_THRESH_1_UD_COUNT_THRESH_1_MASK)

/* The count of STC_UD_COUNT_THRESH_1 */
#define STC_UD_COUNT_THRESH_1_COUNT              (8U)

/*! @name UD_COUNT_THRESH_2 - Underrun counter threshold 2 */
#define STC_UD_COUNT_THRESH_2_UD_COUNT_THRESH_2_MASK (0x7FU)
#define STC_UD_COUNT_THRESH_2_UD_COUNT_THRESH_2_SHIFT (0U)
#define STC_UD_COUNT_THRESH_2_UD_COUNT_THRESH_2(x) (((uint32_t)(((uint32_t)(x)) << STC_UD_COUNT_THRESH_2_UD_COUNT_THRESH_2_SHIFT)) & STC_UD_COUNT_THRESH_2_UD_COUNT_THRESH_2_MASK)

/* The count of STC_UD_COUNT_THRESH_2 */
#define STC_UD_COUNT_THRESH_2_COUNT              (8U)

/*! @name CSCHED_WAIT_COUNT - Category Completion Scheduler wait count for completion returns */
#define STC_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_MASK (0x3FU)
#define STC_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_SHIFT (0U)
#define STC_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << STC_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_SHIFT)) & STC_CSCHED_WAIT_COUNT_CSCHED_WAIT_COUNT_MASK)

/* The count of STC_CSCHED_WAIT_COUNT */
#define STC_CSCHED_WAIT_COUNT_COUNT              (8U)

/*! @name TDM_QOS_OFFSET - TDM QoS OFFSET */
#define STC_TDM_QOS_OFFSET_TDM_QOS_OFFSET_MASK   (0xFU)
#define STC_TDM_QOS_OFFSET_TDM_QOS_OFFSET_SHIFT  (0U)
#define STC_TDM_QOS_OFFSET_TDM_QOS_OFFSET(x)     (((uint32_t)(((uint32_t)(x)) << STC_TDM_QOS_OFFSET_TDM_QOS_OFFSET_SHIFT)) & STC_TDM_QOS_OFFSET_TDM_QOS_OFFSET_MASK)

/* The count of STC_TDM_QOS_OFFSET */
#define STC_TDM_QOS_OFFSET_COUNT                 (8U)

/*! @name TDM_START0_COUNT - Time Division Multiplexed Start0 count */
#define STC_TDM_START0_COUNT_TDM_START_COUNT_MASK (0x7FU)
#define STC_TDM_START0_COUNT_TDM_START_COUNT_SHIFT (0U)
#define STC_TDM_START0_COUNT_TDM_START_COUNT(x)  (((uint32_t)(((uint32_t)(x)) << STC_TDM_START0_COUNT_TDM_START_COUNT_SHIFT)) & STC_TDM_START0_COUNT_TDM_START_COUNT_MASK)

/* The count of STC_TDM_START0_COUNT */
#define STC_TDM_START0_COUNT_COUNT               (8U)

/*! @name TDM_STOP0_COUNT - Time Division Multiplexed stop0 count */
#define STC_TDM_STOP0_COUNT_TDM_STOP_COUNT_MASK  (0x7FU)
#define STC_TDM_STOP0_COUNT_TDM_STOP_COUNT_SHIFT (0U)
#define STC_TDM_STOP0_COUNT_TDM_STOP_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << STC_TDM_STOP0_COUNT_TDM_STOP_COUNT_SHIFT)) & STC_TDM_STOP0_COUNT_TDM_STOP_COUNT_MASK)

/* The count of STC_TDM_STOP0_COUNT */
#define STC_TDM_STOP0_COUNT_COUNT                (8U)

/*! @name TDM_START1_COUNT - Time Division Multiplexed start1 count */
#define STC_TDM_START1_COUNT_TDM_START_COUNT_MASK (0x7FU)
#define STC_TDM_START1_COUNT_TDM_START_COUNT_SHIFT (0U)
#define STC_TDM_START1_COUNT_TDM_START_COUNT(x)  (((uint32_t)(((uint32_t)(x)) << STC_TDM_START1_COUNT_TDM_START_COUNT_SHIFT)) & STC_TDM_START1_COUNT_TDM_START_COUNT_MASK)

/* The count of STC_TDM_START1_COUNT */
#define STC_TDM_START1_COUNT_COUNT               (8U)

/*! @name TDM_STOP1_COUNT - Time Division Multiplexed stop1 count */
#define STC_TDM_STOP1_COUNT_TDM_STOP_COUNT_MASK  (0x7FU)
#define STC_TDM_STOP1_COUNT_TDM_STOP_COUNT_SHIFT (0U)
#define STC_TDM_STOP1_COUNT_TDM_STOP_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << STC_TDM_STOP1_COUNT_TDM_STOP_COUNT_SHIFT)) & STC_TDM_STOP1_COUNT_TDM_STOP_COUNT_MASK)

/* The count of STC_TDM_STOP1_COUNT */
#define STC_TDM_STOP1_COUNT_COUNT                (8U)

/*! @name TDM_START2_COUNT - Time Division Multiplexed start2 count */
#define STC_TDM_START2_COUNT_TDM_START_COUNT_MASK (0x7FU)
#define STC_TDM_START2_COUNT_TDM_START_COUNT_SHIFT (0U)
#define STC_TDM_START2_COUNT_TDM_START_COUNT(x)  (((uint32_t)(((uint32_t)(x)) << STC_TDM_START2_COUNT_TDM_START_COUNT_SHIFT)) & STC_TDM_START2_COUNT_TDM_START_COUNT_MASK)

/* The count of STC_TDM_START2_COUNT */
#define STC_TDM_START2_COUNT_COUNT               (8U)

/*! @name TDM_STOP2_COUNT - Time Division Multiplexed stop2 count */
#define STC_TDM_STOP2_COUNT_TDM_STOP_COUNT_MASK  (0x7FU)
#define STC_TDM_STOP2_COUNT_TDM_STOP_COUNT_SHIFT (0U)
#define STC_TDM_STOP2_COUNT_TDM_STOP_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << STC_TDM_STOP2_COUNT_TDM_STOP_COUNT_SHIFT)) & STC_TDM_STOP2_COUNT_TDM_STOP_COUNT_MASK)

/* The count of STC_TDM_STOP2_COUNT */
#define STC_TDM_STOP2_COUNT_COUNT                (8U)

/*! @name TDM_START3_COUNT - Time Division Multiplexed start3 count */
#define STC_TDM_START3_COUNT_TDM_START_COUNT_MASK (0x7FU)
#define STC_TDM_START3_COUNT_TDM_START_COUNT_SHIFT (0U)
#define STC_TDM_START3_COUNT_TDM_START_COUNT(x)  (((uint32_t)(((uint32_t)(x)) << STC_TDM_START3_COUNT_TDM_START_COUNT_SHIFT)) & STC_TDM_START3_COUNT_TDM_START_COUNT_MASK)

/* The count of STC_TDM_START3_COUNT */
#define STC_TDM_START3_COUNT_COUNT               (8U)

/*! @name TDM_STOP3_COUNT - Time Division Multiplexed stop3 count */
#define STC_TDM_STOP3_COUNT_TDM_STOP_COUNT_MASK  (0x7FU)
#define STC_TDM_STOP3_COUNT_TDM_STOP_COUNT_SHIFT (0U)
#define STC_TDM_STOP3_COUNT_TDM_STOP_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << STC_TDM_STOP3_COUNT_TDM_STOP_COUNT_SHIFT)) & STC_TDM_STOP3_COUNT_TDM_STOP_COUNT_MASK)

/* The count of STC_TDM_STOP3_COUNT */
#define STC_TDM_STOP3_COUNT_COUNT                (8U)


/*!
 * @}
 */ /* end of group STC_Register_Masks */


/** Peripheral STC0 base pointer */
#define STC0                                     ((STC_Type *)STC0_BASE)
/** Peripheral STC1 base pointer */
#define STC1                                     ((STC_Type *)STC1_BASE)
/** Peripheral STC2 base pointer */
#define STC2                                     ((STC_Type *)STC2_BASE)
/** Peripheral STC3 base pointer */
#define STC3                                     ((STC_Type *)STC3_BASE)
/** Peripheral STC4 base pointer */
#define STC4                                     ((STC_Type *)STC4_BASE)
/** Peripheral STC5 base pointer */
#define STC5                                     ((STC_Type *)STC5_BASE)
/** Peripheral STC6 base pointer */
#define STC6                                     ((STC_Type *)STC6_BASE)
/** Peripheral STC7 base pointer */
#define STC7                                     ((STC_Type *)STC7_BASE)
/** Peripheral STC8 base pointer */
#define STC8                                     ((STC_Type *)STC8_BASE)
/** Peripheral STC9 base pointer */
#define STC9                                     ((STC_Type *)STC9_BASE)
/** Peripheral STC10 base pointer */
#define STC10                                    ((STC_Type *)STC10_BASE)
/** Peripheral STC11 base pointer */
#define STC11                                    ((STC_Type *)STC11_BASE)
/** Peripheral STC12 base pointer */
#define STC12                                    ((STC_Type *)STC12_BASE)
/** Peripheral STC13 base pointer */
#define STC13                                    ((STC_Type *)STC13_BASE)
/** Peripheral STC14 base pointer */
#define STC14                                    ((STC_Type *)STC14_BASE)
/** Peripheral STC15 base pointer */
#define STC15                                    ((STC_Type *)STC15_BASE)
/** Peripheral STC15 base pointer */
#define STC16                                    ((STC_Type *)STC16_BASE)
/** Peripheral STC15 base pointer */
#define STC17                                    ((STC_Type *)STC17_BASE)
/** Peripheral STC15 base pointer */
#define STC18                                    ((STC_Type *)STC18_BASE)
/** Peripheral STC15 base pointer */
#define STC19                                    ((STC_Type *)STC19_BASE)
/** Peripheral STC15 base pointer */
#define STC20                                    ((STC_Type *)STC20_BASE)
/** Peripheral STC15 base pointer */
#define STC21                                    ((STC_Type *)STC21_BASE)
/** Peripheral STC15 base pointer */
#define STC22                                    ((STC_Type *)STC22_BASE)
/** Peripheral STC15 base pointer */
#define STC23                                    ((STC_Type *)STC23_BASE)


/** Array initializer of STC peripheral base addresses */
#define STC_BASE_ADDRS                           { STC0_BASE, STC1_BASE,   \
                                                   STC2_BASE, STC3_BASE,   \
                                                   STC2_BASE, STC3_BASE,   \
                                                   STC4_BASE, STC5_BASE,   \
                                                   STC6_BASE, STC7_BASE,   \
                                                   STC8_BASE, STC9_BASE,   \
                                                   STC10_BASE, STC11_BASE, \
                                                   STC12_BASE, STC13_BASE, \
                                                   STC14_BASE, STC15_BASE, \
                                                   STC16_BASE, STC17_BASE, \
                                                   STC18_BASE, STC19_BASE, \
                                                   STC20_BASE, STC21_BASE, \
                                                   STC22_BASE, STC23_BASE }
/** Array initializer of STC peripheral base pointers */
#define STC_BASE_PTRS                            { STC0, STC1, STC2, STC3,     \
                                                   STC4, STC5, STC6, STC7,     \
                                                   STC8, STC9, STC10, STC11,   \
                                                   STC12, STC13, STC14, STC15, \
                                                   STC16, STC17, STC18, STC19, \
                                                   STC20, STC21, STC22, STC23 } 

/*!
 * @}
 */ /* end of group STC_Peripheral_Access_Layer */


#endif  /* STC_H */

