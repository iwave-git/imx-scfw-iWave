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
 * @file MX8_adm.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for ADM
 *
 * CMSIS Peripheral Access Layer for ADM
 */

#ifndef ADM_H
#define ADM_H                 /**< Symbol preventing repeated inclusion */

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
   -- ADM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADM_Peripheral_Access_Layer ADM Peripheral Access Layer
 * @{
 */

/** ADM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCU_GPR0[4];                       /**< GPR register for SCU Bank 0, array offset: 0x0, array step: 0x4 */
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Control register for SCU Bank 0., offset: 0x10 */
    __IO uint32_t SET;                               /**< Control register for SCU Bank 0., offset: 0x14 */
    __IO uint32_t CLR;                               /**< Control register for SCU Bank 0., offset: 0x18 */
    __IO uint32_t TOG;                               /**< Control register for SCU Bank 0., offset: 0x1C */
  } GPR0_CTRL;
  __IO uint32_t SCU_GPR1[4];                       /**< GPR register for SCU Bank 1, array offset: 0x20, array step: 0x4 */
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Control register for bank 1., offset: 0x30 */
    __IO uint32_t SET;                               /**< Control register for bank 1., offset: 0x34 */
    __IO uint32_t CLR;                               /**< Control register for bank 1., offset: 0x38 */
    __IO uint32_t TOG;                               /**< Control register for bank 1., offset: 0x3C */
  } GPR1_CTRL;
  __IO uint32_t SCU_GPR2[4];                       /**< GPR register for SCU Bank 2, array offset: 0x40, array step: 0x4 */
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< Control register for Bank 2., offset: 0x50 */
    __IO uint32_t SET;                               /**< Control register for Bank 2., offset: 0x54 */
    __IO uint32_t CLR;                               /**< Control register for Bank 2., offset: 0x58 */
    __IO uint32_t TOG;                               /**< Control register for Bank 2., offset: 0x5C */
  } GPR2_CTRL;
  __IO uint32_t SCU_GPR3[4];                       /**< GPR register for SCU Bank 3, array offset: 0x60, array step: 0x4 */
  struct {                                         /* offset: 0x70 */
    __IO uint32_t RW;                                /**< Control register for bank 3., offset: 0x70 */
    __IO uint32_t SET;                               /**< Control register for bank 3., offset: 0x74 */
    __IO uint32_t CLR;                               /**< Control register for bank 3., offset: 0x78 */
    __IO uint32_t TOG;                               /**< Control register for bank 3., offset: 0x7C */
  } GPR3_CTRL;
  __IO uint32_t SCU_GPR4[4];                       /**< GPR register for SCU Bank 4, array offset: 0x80, array step: 0x4 */
  struct {                                         /* offset: 0x90 */
    __IO uint32_t RW;                                /**< Control register for bank 4., offset: 0x90 */
    __IO uint32_t SET;                               /**< Control register for bank 4., offset: 0x94 */
    __IO uint32_t CLR;                               /**< Control register for bank 4., offset: 0x98 */
    __IO uint32_t TOG;                               /**< Control register for bank 4., offset: 0x9C */
  } GPR4_CTRL;
  __IO uint32_t SCU_GPR5[4];                       /**< GPR register for SCU Bank 5, array offset: 0xA0, array step: 0x4 */
  struct {                                         /* offset: 0xB0 */
    __IO uint32_t RW;                                /**< Control register for bank 5., offset: 0xB0 */
    __IO uint32_t SET;                               /**< Control register for bank 5., offset: 0xB4 */
    __IO uint32_t CLR;                               /**< Control register for bank 5., offset: 0xB8 */
    __IO uint32_t TOG;                               /**< Control register for bank 5., offset: 0xBC */
  } GPR5_CTRL;
  struct {                                         /* offset: 0xC0 */
    __IO uint32_t RW;                                /**< Control register for SCU., offset: 0xC0 */
    __IO uint32_t SET;                               /**< Control register for SCU., offset: 0xC4 */
    __IO uint32_t CLR;                               /**< Control register for SCU., offset: 0xC8 */
    __IO uint32_t TOG;                               /**< Control register for SCU., offset: 0xCC */
  } CTRL0;
  struct {                                         /* offset: 0xD0 */
    __IO uint32_t RW;                                /**< Control register for SCU., offset: 0xD0 */
    __IO uint32_t SET;                               /**< Control register for SCU., offset: 0xD4 */
    __IO uint32_t CLR;                               /**< Control register for SCU., offset: 0xD8 */
    __IO uint32_t TOG;                               /**< Control register for SCU., offset: 0xDC */
  } CTRL1;
  __IO uint32_t STATUS0;                           /**< Status register for SCU., offset: 0xE0 */
       uint8_t RESERVED_0[12];
  __I  uint32_t STATUS1;                           /**< Status register for SCU., offset: 0xF0 */
       uint8_t RESERVED_1[12];
  __I  uint32_t GPR0[4];                           /**< , array offset: 0x100, array step: 0x4 */
  __I  uint32_t GPR1[4];                           /**< , array offset: 0x110, array step: 0x4 */
  __I  uint32_t GPR2[4];                           /**< , array offset: 0x120, array step: 0x4 */
  __I  uint32_t GPR3[4];                           /**< , array offset: 0x130, array step: 0x4 */
  __I  uint32_t GPR4[4];                           /**< , array offset: 0x140, array step: 0x4 */
  __I  uint32_t GPR5[4];                           /**< , array offset: 0x150, array step: 0x4 */
  __I  uint32_t SECO_SUPER_ROOT_KEY_HASH[8];       /**< , array offset: 0x160, array step: 0x4 */
  __I  uint32_t HDMI_SUPER_ROOT_KEY_HASH[8];       /**< , array offset: 0x180, array step: 0x4 */
  __IO uint32_t CAAM_PWRCTRL_REF;                  /**< CAAM PWRCTRL reg for reference, offset: 0x1A0 */
       uint8_t RESERVED_2[12];
  __I  uint32_t SPARE[4];                          /**< , array offset: 0x1B0, array step: 0x4 */
} ADM_Type;

/* ----------------------------------------------------------------------------
   -- ADM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADM_Register_Masks ADM Register Masks
 * @{
 */

/*! @name SCU_GPR0 - GPR register for SCU Bank 0 */
#define ADM_SCU_GPR0_BANK0_MASK                  (0xFFFFFFFFU)
#define ADM_SCU_GPR0_BANK0_SHIFT                 (0U)
#define ADM_SCU_GPR0_BANK0(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_SCU_GPR0_BANK0_SHIFT)) & ADM_SCU_GPR0_BANK0_MASK)

/* The count of ADM_SCU_GPR0 */
#define ADM_SCU_GPR0_COUNT                       (4U)

/*! @name GPR0_CTRL - Control register for SCU Bank 0. */
#define ADM_GPR0_CTRL_CLR_ON_FAIL_MASK           (0x1U)
#define ADM_GPR0_CTRL_CLR_ON_FAIL_SHIFT          (0U)
#define ADM_GPR0_CTRL_CLR_ON_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << ADM_GPR0_CTRL_CLR_ON_FAIL_SHIFT)) & ADM_GPR0_CTRL_CLR_ON_FAIL_MASK)
#define ADM_GPR0_CTRL_PRIVATE_WR_MASK            (0x2U)
#define ADM_GPR0_CTRL_PRIVATE_WR_SHIFT           (1U)
#define ADM_GPR0_CTRL_PRIVATE_WR(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR0_CTRL_PRIVATE_WR_SHIFT)) & ADM_GPR0_CTRL_PRIVATE_WR_MASK)
#define ADM_GPR0_CTRL_PRIVATE_RD_MASK            (0x4U)
#define ADM_GPR0_CTRL_PRIVATE_RD_SHIFT           (2U)
#define ADM_GPR0_CTRL_PRIVATE_RD(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR0_CTRL_PRIVATE_RD_SHIFT)) & ADM_GPR0_CTRL_PRIVATE_RD_MASK)
#define ADM_GPR0_CTRL_SHARED_WR_MASK             (0x8U)
#define ADM_GPR0_CTRL_SHARED_WR_SHIFT            (3U)
#define ADM_GPR0_CTRL_SHARED_WR(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR0_CTRL_SHARED_WR_SHIFT)) & ADM_GPR0_CTRL_SHARED_WR_MASK)
#define ADM_GPR0_CTRL_SHARED_RD_MASK             (0x10U)
#define ADM_GPR0_CTRL_SHARED_RD_SHIFT            (4U)
#define ADM_GPR0_CTRL_SHARED_RD(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR0_CTRL_SHARED_RD_SHIFT)) & ADM_GPR0_CTRL_SHARED_RD_MASK)
#define ADM_GPR0_CTRL_LOCK_MASK                  (0x20U)
#define ADM_GPR0_CTRL_LOCK_SHIFT                 (5U)
#define ADM_GPR0_CTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_GPR0_CTRL_LOCK_SHIFT)) & ADM_GPR0_CTRL_LOCK_MASK)

/*! @name SCU_GPR1 - GPR register for SCU Bank 1 */
#define ADM_SCU_GPR1_BANK1_MASK                  (0xFFFFFFFFU)
#define ADM_SCU_GPR1_BANK1_SHIFT                 (0U)
#define ADM_SCU_GPR1_BANK1(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_SCU_GPR1_BANK1_SHIFT)) & ADM_SCU_GPR1_BANK1_MASK)

/* The count of ADM_SCU_GPR1 */
#define ADM_SCU_GPR1_COUNT                       (4U)

/*! @name GPR1_CTRL - Control register for bank 1. */
#define ADM_GPR1_CTRL_CLR_ON_FAIL_MASK           (0x1U)
#define ADM_GPR1_CTRL_CLR_ON_FAIL_SHIFT          (0U)
#define ADM_GPR1_CTRL_CLR_ON_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << ADM_GPR1_CTRL_CLR_ON_FAIL_SHIFT)) & ADM_GPR1_CTRL_CLR_ON_FAIL_MASK)
#define ADM_GPR1_CTRL_PRIVATE_WR_MASK            (0x2U)
#define ADM_GPR1_CTRL_PRIVATE_WR_SHIFT           (1U)
#define ADM_GPR1_CTRL_PRIVATE_WR(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR1_CTRL_PRIVATE_WR_SHIFT)) & ADM_GPR1_CTRL_PRIVATE_WR_MASK)
#define ADM_GPR1_CTRL_PRIVATE_RD_MASK            (0x4U)
#define ADM_GPR1_CTRL_PRIVATE_RD_SHIFT           (2U)
#define ADM_GPR1_CTRL_PRIVATE_RD(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR1_CTRL_PRIVATE_RD_SHIFT)) & ADM_GPR1_CTRL_PRIVATE_RD_MASK)
#define ADM_GPR1_CTRL_SHARED_WR_MASK             (0x8U)
#define ADM_GPR1_CTRL_SHARED_WR_SHIFT            (3U)
#define ADM_GPR1_CTRL_SHARED_WR(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR1_CTRL_SHARED_WR_SHIFT)) & ADM_GPR1_CTRL_SHARED_WR_MASK)
#define ADM_GPR1_CTRL_SHARED_RD_MASK             (0x10U)
#define ADM_GPR1_CTRL_SHARED_RD_SHIFT            (4U)
#define ADM_GPR1_CTRL_SHARED_RD(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR1_CTRL_SHARED_RD_SHIFT)) & ADM_GPR1_CTRL_SHARED_RD_MASK)
#define ADM_GPR1_CTRL_LOCK_MASK                  (0x20U)
#define ADM_GPR1_CTRL_LOCK_SHIFT                 (5U)
#define ADM_GPR1_CTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_GPR1_CTRL_LOCK_SHIFT)) & ADM_GPR1_CTRL_LOCK_MASK)

/*! @name SCU_GPR2 - GPR register for SCU Bank 2 */
#define ADM_SCU_GPR2_BANK2_MASK                  (0xFFFFFFFFU)
#define ADM_SCU_GPR2_BANK2_SHIFT                 (0U)
#define ADM_SCU_GPR2_BANK2(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_SCU_GPR2_BANK2_SHIFT)) & ADM_SCU_GPR2_BANK2_MASK)

/* The count of ADM_SCU_GPR2 */
#define ADM_SCU_GPR2_COUNT                       (4U)

/*! @name GPR2_CTRL - Control register for Bank 2. */
#define ADM_GPR2_CTRL_CLR_ON_FAIL_MASK           (0x1U)
#define ADM_GPR2_CTRL_CLR_ON_FAIL_SHIFT          (0U)
#define ADM_GPR2_CTRL_CLR_ON_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << ADM_GPR2_CTRL_CLR_ON_FAIL_SHIFT)) & ADM_GPR2_CTRL_CLR_ON_FAIL_MASK)
#define ADM_GPR2_CTRL_PRIVATE_WR_MASK            (0x2U)
#define ADM_GPR2_CTRL_PRIVATE_WR_SHIFT           (1U)
#define ADM_GPR2_CTRL_PRIVATE_WR(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR2_CTRL_PRIVATE_WR_SHIFT)) & ADM_GPR2_CTRL_PRIVATE_WR_MASK)
#define ADM_GPR2_CTRL_PRIVATE_RD_MASK            (0x4U)
#define ADM_GPR2_CTRL_PRIVATE_RD_SHIFT           (2U)
#define ADM_GPR2_CTRL_PRIVATE_RD(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR2_CTRL_PRIVATE_RD_SHIFT)) & ADM_GPR2_CTRL_PRIVATE_RD_MASK)
#define ADM_GPR2_CTRL_SHARED_WR_MASK             (0x8U)
#define ADM_GPR2_CTRL_SHARED_WR_SHIFT            (3U)
#define ADM_GPR2_CTRL_SHARED_WR(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR2_CTRL_SHARED_WR_SHIFT)) & ADM_GPR2_CTRL_SHARED_WR_MASK)
#define ADM_GPR2_CTRL_SHARED_RD_MASK             (0x10U)
#define ADM_GPR2_CTRL_SHARED_RD_SHIFT            (4U)
#define ADM_GPR2_CTRL_SHARED_RD(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR2_CTRL_SHARED_RD_SHIFT)) & ADM_GPR2_CTRL_SHARED_RD_MASK)
#define ADM_GPR2_CTRL_LOCK_MASK                  (0x20U)
#define ADM_GPR2_CTRL_LOCK_SHIFT                 (5U)
#define ADM_GPR2_CTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_GPR2_CTRL_LOCK_SHIFT)) & ADM_GPR2_CTRL_LOCK_MASK)

/*! @name SCU_GPR3 - GPR register for SCU Bank 3 */
#define ADM_SCU_GPR3_BANK3_MASK                  (0xFFFFFFFFU)
#define ADM_SCU_GPR3_BANK3_SHIFT                 (0U)
#define ADM_SCU_GPR3_BANK3(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_SCU_GPR3_BANK3_SHIFT)) & ADM_SCU_GPR3_BANK3_MASK)

/* The count of ADM_SCU_GPR3 */
#define ADM_SCU_GPR3_COUNT                       (4U)

/*! @name GPR3_CTRL - Control register for bank 3. */
#define ADM_GPR3_CTRL_CLR_ON_FAIL_MASK           (0x1U)
#define ADM_GPR3_CTRL_CLR_ON_FAIL_SHIFT          (0U)
#define ADM_GPR3_CTRL_CLR_ON_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << ADM_GPR3_CTRL_CLR_ON_FAIL_SHIFT)) & ADM_GPR3_CTRL_CLR_ON_FAIL_MASK)
#define ADM_GPR3_CTRL_PRIVATE_WR_MASK            (0x2U)
#define ADM_GPR3_CTRL_PRIVATE_WR_SHIFT           (1U)
#define ADM_GPR3_CTRL_PRIVATE_WR(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR3_CTRL_PRIVATE_WR_SHIFT)) & ADM_GPR3_CTRL_PRIVATE_WR_MASK)
#define ADM_GPR3_CTRL_PRIVATE_RD_MASK            (0x4U)
#define ADM_GPR3_CTRL_PRIVATE_RD_SHIFT           (2U)
#define ADM_GPR3_CTRL_PRIVATE_RD(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR3_CTRL_PRIVATE_RD_SHIFT)) & ADM_GPR3_CTRL_PRIVATE_RD_MASK)
#define ADM_GPR3_CTRL_SHARED_WR_MASK             (0x8U)
#define ADM_GPR3_CTRL_SHARED_WR_SHIFT            (3U)
#define ADM_GPR3_CTRL_SHARED_WR(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR3_CTRL_SHARED_WR_SHIFT)) & ADM_GPR3_CTRL_SHARED_WR_MASK)
#define ADM_GPR3_CTRL_SHARED_RD_MASK             (0x10U)
#define ADM_GPR3_CTRL_SHARED_RD_SHIFT            (4U)
#define ADM_GPR3_CTRL_SHARED_RD(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR3_CTRL_SHARED_RD_SHIFT)) & ADM_GPR3_CTRL_SHARED_RD_MASK)
#define ADM_GPR3_CTRL_LOCK_MASK                  (0x20U)
#define ADM_GPR3_CTRL_LOCK_SHIFT                 (5U)
#define ADM_GPR3_CTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_GPR3_CTRL_LOCK_SHIFT)) & ADM_GPR3_CTRL_LOCK_MASK)

/*! @name SCU_GPR4 - GPR register for SCU Bank 4 */
#define ADM_SCU_GPR4_BANK4_MASK                  (0xFFFFFFFFU)
#define ADM_SCU_GPR4_BANK4_SHIFT                 (0U)
#define ADM_SCU_GPR4_BANK4(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_SCU_GPR4_BANK4_SHIFT)) & ADM_SCU_GPR4_BANK4_MASK)

/* The count of ADM_SCU_GPR4 */
#define ADM_SCU_GPR4_COUNT                       (4U)

/*! @name GPR4_CTRL - Control register for bank 4. */
#define ADM_GPR4_CTRL_CLR_ON_FAIL_MASK           (0x1U)
#define ADM_GPR4_CTRL_CLR_ON_FAIL_SHIFT          (0U)
#define ADM_GPR4_CTRL_CLR_ON_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << ADM_GPR4_CTRL_CLR_ON_FAIL_SHIFT)) & ADM_GPR4_CTRL_CLR_ON_FAIL_MASK)
#define ADM_GPR4_CTRL_PRIVATE_WR_MASK            (0x2U)
#define ADM_GPR4_CTRL_PRIVATE_WR_SHIFT           (1U)
#define ADM_GPR4_CTRL_PRIVATE_WR(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR4_CTRL_PRIVATE_WR_SHIFT)) & ADM_GPR4_CTRL_PRIVATE_WR_MASK)
#define ADM_GPR4_CTRL_PRIVATE_RD_MASK            (0x4U)
#define ADM_GPR4_CTRL_PRIVATE_RD_SHIFT           (2U)
#define ADM_GPR4_CTRL_PRIVATE_RD(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR4_CTRL_PRIVATE_RD_SHIFT)) & ADM_GPR4_CTRL_PRIVATE_RD_MASK)
#define ADM_GPR4_CTRL_SHARED_WR_MASK             (0x8U)
#define ADM_GPR4_CTRL_SHARED_WR_SHIFT            (3U)
#define ADM_GPR4_CTRL_SHARED_WR(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR4_CTRL_SHARED_WR_SHIFT)) & ADM_GPR4_CTRL_SHARED_WR_MASK)
#define ADM_GPR4_CTRL_SHARED_RD_MASK             (0x10U)
#define ADM_GPR4_CTRL_SHARED_RD_SHIFT            (4U)
#define ADM_GPR4_CTRL_SHARED_RD(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR4_CTRL_SHARED_RD_SHIFT)) & ADM_GPR4_CTRL_SHARED_RD_MASK)
#define ADM_GPR4_CTRL_LOCK_MASK                  (0x20U)
#define ADM_GPR4_CTRL_LOCK_SHIFT                 (5U)
#define ADM_GPR4_CTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_GPR4_CTRL_LOCK_SHIFT)) & ADM_GPR4_CTRL_LOCK_MASK)

/*! @name SCU_GPR5 - GPR register for SCU Bank 5 */
#define ADM_SCU_GPR5_BANK5_MASK                  (0xFFFFFFFFU)
#define ADM_SCU_GPR5_BANK5_SHIFT                 (0U)
#define ADM_SCU_GPR5_BANK5(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_SCU_GPR5_BANK5_SHIFT)) & ADM_SCU_GPR5_BANK5_MASK)

/* The count of ADM_SCU_GPR5 */
#define ADM_SCU_GPR5_COUNT                       (4U)

/*! @name GPR5_CTRL - Control register for bank 5. */
#define ADM_GPR5_CTRL_CLR_ON_FAIL_MASK           (0x1U)
#define ADM_GPR5_CTRL_CLR_ON_FAIL_SHIFT          (0U)
#define ADM_GPR5_CTRL_CLR_ON_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << ADM_GPR5_CTRL_CLR_ON_FAIL_SHIFT)) & ADM_GPR5_CTRL_CLR_ON_FAIL_MASK)
#define ADM_GPR5_CTRL_PRIVATE_WR_MASK            (0x2U)
#define ADM_GPR5_CTRL_PRIVATE_WR_SHIFT           (1U)
#define ADM_GPR5_CTRL_PRIVATE_WR(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR5_CTRL_PRIVATE_WR_SHIFT)) & ADM_GPR5_CTRL_PRIVATE_WR_MASK)
#define ADM_GPR5_CTRL_PRIVATE_RD_MASK            (0x4U)
#define ADM_GPR5_CTRL_PRIVATE_RD_SHIFT           (2U)
#define ADM_GPR5_CTRL_PRIVATE_RD(x)              (((uint32_t)(((uint32_t)(x)) << ADM_GPR5_CTRL_PRIVATE_RD_SHIFT)) & ADM_GPR5_CTRL_PRIVATE_RD_MASK)
#define ADM_GPR5_CTRL_SHARED_WR_MASK             (0x8U)
#define ADM_GPR5_CTRL_SHARED_WR_SHIFT            (3U)
#define ADM_GPR5_CTRL_SHARED_WR(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR5_CTRL_SHARED_WR_SHIFT)) & ADM_GPR5_CTRL_SHARED_WR_MASK)
#define ADM_GPR5_CTRL_SHARED_RD_MASK             (0x10U)
#define ADM_GPR5_CTRL_SHARED_RD_SHIFT            (4U)
#define ADM_GPR5_CTRL_SHARED_RD(x)               (((uint32_t)(((uint32_t)(x)) << ADM_GPR5_CTRL_SHARED_RD_SHIFT)) & ADM_GPR5_CTRL_SHARED_RD_MASK)
#define ADM_GPR5_CTRL_LOCK_MASK                  (0x20U)
#define ADM_GPR5_CTRL_LOCK_SHIFT                 (5U)
#define ADM_GPR5_CTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_GPR5_CTRL_LOCK_SHIFT)) & ADM_GPR5_CTRL_LOCK_MASK)

/*! @name CTRL0 - Control register for SCU. */
#define ADM_CTRL0_ALLOW_SCU_NIDEN_MASK           (0x1U)
#define ADM_CTRL0_ALLOW_SCU_NIDEN_SHIFT          (0U)
#define ADM_CTRL0_ALLOW_SCU_NIDEN(x)             (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_SCU_NIDEN_SHIFT)) & ADM_CTRL0_ALLOW_SCU_NIDEN_MASK)
#define ADM_CTRL0_ALLOW_SCU_DBGEN_MASK           (0x2U)
#define ADM_CTRL0_ALLOW_SCU_DBGEN_SHIFT          (1U)
#define ADM_CTRL0_ALLOW_SCU_DBGEN(x)             (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_SCU_DBGEN_SHIFT)) & ADM_CTRL0_ALLOW_SCU_DBGEN_MASK)
#define ADM_CTRL0_ALLOW_SCU_SPNIDEN_MASK         (0x4U)
#define ADM_CTRL0_ALLOW_SCU_SPNIDEN_SHIFT        (2U)
#define ADM_CTRL0_ALLOW_SCU_SPNIDEN(x)           (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_SCU_SPNIDEN_SHIFT)) & ADM_CTRL0_ALLOW_SCU_SPNIDEN_MASK)
#define ADM_CTRL0_ALLOW_SCU_SPIDEN_MASK          (0x8U)
#define ADM_CTRL0_ALLOW_SCU_SPIDEN_SHIFT         (3U)
#define ADM_CTRL0_ALLOW_SCU_SPIDEN(x)            (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_SCU_SPIDEN_SHIFT)) & ADM_CTRL0_ALLOW_SCU_SPIDEN_MASK)
#define ADM_CTRL0_SCU_ROM_EXIT_MASK              (0x10U)
#define ADM_CTRL0_SCU_ROM_EXIT_SHIFT             (4U)
#define ADM_CTRL0_SCU_ROM_EXIT(x)                (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_SCU_ROM_EXIT_SHIFT)) & ADM_CTRL0_SCU_ROM_EXIT_MASK)
#define ADM_CTRL0_ALLOW_APPS_NIDEN_MASK          (0x1E0U)
#define ADM_CTRL0_ALLOW_APPS_NIDEN_SHIFT         (5U)
#define ADM_CTRL0_ALLOW_APPS_NIDEN(x)            (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_APPS_NIDEN_SHIFT)) & ADM_CTRL0_ALLOW_APPS_NIDEN_MASK)
#define ADM_CTRL0_ALLOW_APPS_DBGEN_MASK          (0x1E00U)
#define ADM_CTRL0_ALLOW_APPS_DBGEN_SHIFT         (9U)
#define ADM_CTRL0_ALLOW_APPS_DBGEN(x)            (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_APPS_DBGEN_SHIFT)) & ADM_CTRL0_ALLOW_APPS_DBGEN_MASK)
#define ADM_CTRL0_ALLOW_APPS_SPNIDEN_MASK        (0x1E000U)
#define ADM_CTRL0_ALLOW_APPS_SPNIDEN_SHIFT       (13U)
#define ADM_CTRL0_ALLOW_APPS_SPNIDEN(x)          (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_APPS_SPNIDEN_SHIFT)) & ADM_CTRL0_ALLOW_APPS_SPNIDEN_MASK)
#define ADM_CTRL0_ALLOW_APPS_SPIDEN_MASK         (0x1E0000U)
#define ADM_CTRL0_ALLOW_APPS_SPIDEN_SHIFT        (17U)
#define ADM_CTRL0_ALLOW_APPS_SPIDEN(x)           (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_ALLOW_APPS_SPIDEN_SHIFT)) & ADM_CTRL0_ALLOW_APPS_SPIDEN_MASK)
#define ADM_CTRL0_DISABLE_CAAM_MASK              (0x200000U)
#define ADM_CTRL0_DISABLE_CAAM_SHIFT             (21U)
#define ADM_CTRL0_DISABLE_CAAM(x)                (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_DISABLE_CAAM_SHIFT)) & ADM_CTRL0_DISABLE_CAAM_MASK)
#define ADM_CTRL0_DISABLE_IEE_MASK               (0x400000U)
#define ADM_CTRL0_DISABLE_IEE_SHIFT              (22U)
#define ADM_CTRL0_DISABLE_IEE(x)                 (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_DISABLE_IEE_SHIFT)) & ADM_CTRL0_DISABLE_IEE_MASK)
#define ADM_CTRL0_DISABLE_HDCP_MASK              (0x800000U)
#define ADM_CTRL0_DISABLE_HDCP_SHIFT             (23U)
#define ADM_CTRL0_DISABLE_HDCP(x)                (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_DISABLE_HDCP_SHIFT)) & ADM_CTRL0_DISABLE_HDCP_MASK)
#define ADM_CTRL0_DISABLE_DTCP_MASK              (0x1000000U)
#define ADM_CTRL0_DISABLE_DTCP_SHIFT             (24U)
#define ADM_CTRL0_DISABLE_DTCP(x)                (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_DISABLE_DTCP_SHIFT)) & ADM_CTRL0_DISABLE_DTCP_MASK)
#define ADM_CTRL0_DISABLE_CAU_MASK               (0x2000000U)
#define ADM_CTRL0_DISABLE_CAU_SHIFT              (25U)
#define ADM_CTRL0_DISABLE_CAU(x)                 (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_DISABLE_CAU_SHIFT)) & ADM_CTRL0_DISABLE_CAU_MASK)
#define ADM_CTRL0_EN_GLITCH_DET_MASK             (0x4000000U)
#define ADM_CTRL0_EN_GLITCH_DET_SHIFT            (26U)
#define ADM_CTRL0_EN_GLITCH_DET(x)               (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_EN_GLITCH_DET_SHIFT)) & ADM_CTRL0_EN_GLITCH_DET_MASK)
#define ADM_CTRL0_TCU_SW_RESET_MASK              (0x8000000U)
#define ADM_CTRL0_TCU_SW_RESET_SHIFT             (27U)
#define ADM_CTRL0_TCU_SW_RESET(x)                (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_TCU_SW_RESET_SHIFT)) & ADM_CTRL0_TCU_SW_RESET_MASK)
#define ADM_CTRL0_HDMI_RX_APB_MUX_MASK           (0x10000000U)
#define ADM_CTRL0_HDMI_RX_APB_MUX_SHIFT          (28U)
#define ADM_CTRL0_HDMI_RX_APB_MUX(x)             (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_HDMI_RX_APB_MUX_SHIFT)) & ADM_CTRL0_HDMI_RX_APB_MUX_MASK)
#define ADM_CTRL0_HDMI_TX_APB_MUX_MASK           (0x20000000U)
#define ADM_CTRL0_HDMI_TX_APB_MUX_SHIFT          (29U)
#define ADM_CTRL0_HDMI_TX_APB_MUX(x)             (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_HDMI_TX_APB_MUX_SHIFT)) & ADM_CTRL0_HDMI_TX_APB_MUX_MASK)
#define ADM_CTRL0_HDMI_RX_SECURED_MODE_MASK      (0x40000000U)
#define ADM_CTRL0_HDMI_RX_SECURED_MODE_SHIFT     (30U)
#define ADM_CTRL0_HDMI_RX_SECURED_MODE(x)        (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_HDMI_RX_SECURED_MODE_SHIFT)) & ADM_CTRL0_HDMI_RX_SECURED_MODE_MASK)
#define ADM_CTRL0_HDMI_TX_SECURED_MODE_MASK      (0x80000000U)
#define ADM_CTRL0_HDMI_TX_SECURED_MODE_SHIFT     (31U)
#define ADM_CTRL0_HDMI_TX_SECURED_MODE(x)        (((uint32_t)(((uint32_t)(x)) << ADM_CTRL0_HDMI_TX_SECURED_MODE_SHIFT)) & ADM_CTRL0_HDMI_TX_SECURED_MODE_MASK)

/*! @name CTRL1 - Control register for SCU. */
#define ADM_CTRL1_CAAM_DID_MASK                  (0x1FU)
#define ADM_CTRL1_CAAM_DID_SHIFT                 (0U)
#define ADM_CTRL1_CAAM_DID(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_CAAM_DID_SHIFT)) & ADM_CTRL1_CAAM_DID_MASK)
#define ADM_CTRL1_LOCK_CDID_MASK                 (0x20U)
#define ADM_CTRL1_LOCK_CDID_SHIFT                (5U)
#define ADM_CTRL1_LOCK_CDID(x)                   (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_LOCK_CDID_SHIFT)) & ADM_CTRL1_LOCK_CDID_MASK)
#define ADM_CTRL1_JTAGC_DISABLE_MASK             (0x80U)
#define ADM_CTRL1_JTAGC_DISABLE_SHIFT            (7U)
#define ADM_CTRL1_JTAGC_DISABLE(x)               (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_JTAGC_DISABLE_SHIFT)) & ADM_CTRL1_JTAGC_DISABLE_MASK)
#define ADM_CTRL1_LOCK_JTAGC_DISABLE_MASK        (0x100U)
#define ADM_CTRL1_LOCK_JTAGC_DISABLE_SHIFT       (8U)
#define ADM_CTRL1_LOCK_JTAGC_DISABLE(x)          (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_LOCK_JTAGC_DISABLE_SHIFT)) & ADM_CTRL1_LOCK_JTAGC_DISABLE_MASK)
#define ADM_CTRL1_PAR_FR_ALLOWED_MASK            (0x200U)
#define ADM_CTRL1_PAR_FR_ALLOWED_SHIFT           (9U)
#define ADM_CTRL1_PAR_FR_ALLOWED(x)              (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_PAR_FR_ALLOWED_SHIFT)) & ADM_CTRL1_PAR_FR_ALLOWED_MASK)
#define ADM_CTRL1_FR_ALLOWED_MASK                (0x400U)
#define ADM_CTRL1_FR_ALLOWED_SHIFT               (10U)
#define ADM_CTRL1_FR_ALLOWED(x)                  (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_FR_ALLOWED_SHIFT)) & ADM_CTRL1_FR_ALLOWED_MASK)
#define ADM_CTRL1_NO_RETURN_ALLOWED_MASK         (0x800U)
#define ADM_CTRL1_NO_RETURN_ALLOWED_SHIFT        (11U)
#define ADM_CTRL1_NO_RETURN_ALLOWED(x)           (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_NO_RETURN_ALLOWED_SHIFT)) & ADM_CTRL1_NO_RETURN_ALLOWED_MASK)
#define ADM_CTRL1_CNR_ALLOWED_MASK               (0x1000U)
#define ADM_CTRL1_CNR_ALLOWED_SHIFT              (12U)
#define ADM_CTRL1_CNR_ALLOWED(x)                 (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_CNR_ALLOWED_SHIFT)) & ADM_CTRL1_CNR_ALLOWED_MASK)
#define ADM_CTRL1_LOCKUP_SV_MASK                 (0x2000U)
#define ADM_CTRL1_LOCKUP_SV_SHIFT                (13U)
#define ADM_CTRL1_LOCKUP_SV(x)                   (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_LOCKUP_SV_SHIFT)) & ADM_CTRL1_LOCKUP_SV_MASK)
#define ADM_CTRL1_UERR_SV_MASK                   (0x4000U)
#define ADM_CTRL1_UERR_SV_SHIFT                  (14U)
#define ADM_CTRL1_UERR_SV(x)                     (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_UERR_SV_SHIFT)) & ADM_CTRL1_UERR_SV_MASK)
#define ADM_CTRL1_TAMPER_SV_MASK                 (0x8000U)
#define ADM_CTRL1_TAMPER_SV_SHIFT                (15U)
#define ADM_CTRL1_TAMPER_SV(x)                   (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_TAMPER_SV_SHIFT)) & ADM_CTRL1_TAMPER_SV_MASK)
#define ADM_CTRL1_GLITCH_SV_MASK                 (0x10000U)
#define ADM_CTRL1_GLITCH_SV_SHIFT                (16U)
#define ADM_CTRL1_GLITCH_SV(x)                   (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_GLITCH_SV_SHIFT)) & ADM_CTRL1_GLITCH_SV_MASK)
#define ADM_CTRL1_WDOG_SV_MASK                   (0x20000U)
#define ADM_CTRL1_WDOG_SV_SHIFT                  (17U)
#define ADM_CTRL1_WDOG_SV(x)                     (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_WDOG_SV_SHIFT)) & ADM_CTRL1_WDOG_SV_MASK)
#define ADM_CTRL1_CAAM_SV_MASK                   (0x40000U)
#define ADM_CTRL1_CAAM_SV_SHIFT                  (18U)
#define ADM_CTRL1_CAAM_SV(x)                     (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_CAAM_SV_SHIFT)) & ADM_CTRL1_CAAM_SV_MASK)
#define ADM_CTRL1_OBSERVE_VALUE_MASK             (0x380000U)
#define ADM_CTRL1_OBSERVE_VALUE_SHIFT            (19U)
#define ADM_CTRL1_OBSERVE_VALUE(x)               (((uint32_t)(((uint32_t)(x)) << ADM_CTRL1_OBSERVE_VALUE_SHIFT)) & ADM_CTRL1_OBSERVE_VALUE_MASK)

/*! @name STATUS0 - Status register for SCU. */
#define ADM_STATUS0_SCU_NIDEN_ALLOWED_MASK       (0x1U)
#define ADM_STATUS0_SCU_NIDEN_ALLOWED_SHIFT      (0U)
#define ADM_STATUS0_SCU_NIDEN_ALLOWED(x)         (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SCU_NIDEN_ALLOWED_SHIFT)) & ADM_STATUS0_SCU_NIDEN_ALLOWED_MASK)
#define ADM_STATUS0_SCU_DBGEN_ALLOWED_MASK       (0x2U)
#define ADM_STATUS0_SCU_DBGEN_ALLOWED_SHIFT      (1U)
#define ADM_STATUS0_SCU_DBGEN_ALLOWED(x)         (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SCU_DBGEN_ALLOWED_SHIFT)) & ADM_STATUS0_SCU_DBGEN_ALLOWED_MASK)
#define ADM_STATUS0_SCU_SPNIDEN_ALLOWED_MASK     (0x4U)
#define ADM_STATUS0_SCU_SPNIDEN_ALLOWED_SHIFT    (2U)
#define ADM_STATUS0_SCU_SPNIDEN_ALLOWED(x)       (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SCU_SPNIDEN_ALLOWED_SHIFT)) & ADM_STATUS0_SCU_SPNIDEN_ALLOWED_MASK)
#define ADM_STATUS0_SCU_SPIDEN_ALLOWED_MASK      (0x8U)
#define ADM_STATUS0_SCU_SPIDEN_ALLOWED_SHIFT     (3U)
#define ADM_STATUS0_SCU_SPIDEN_ALLOWED(x)        (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SCU_SPIDEN_ALLOWED_SHIFT)) & ADM_STATUS0_SCU_SPIDEN_ALLOWED_MASK)
#define ADM_STATUS0_SECO_DBGEN_ALLOWED_MASK      (0x10U)
#define ADM_STATUS0_SECO_DBGEN_ALLOWED_SHIFT     (4U)
#define ADM_STATUS0_SECO_DBGEN_ALLOWED(x)        (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SECO_DBGEN_ALLOWED_SHIFT)) & ADM_STATUS0_SECO_DBGEN_ALLOWED_MASK)
#define ADM_STATUS0_APPS_NIDEN_ALLOWED_MASK      (0x1E0U)
#define ADM_STATUS0_APPS_NIDEN_ALLOWED_SHIFT     (5U)
#define ADM_STATUS0_APPS_NIDEN_ALLOWED(x)        (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APPS_NIDEN_ALLOWED_SHIFT)) & ADM_STATUS0_APPS_NIDEN_ALLOWED_MASK)
#define ADM_STATUS0_APPS_DBGEN_ALLOWED_MASK      (0x1E00U)
#define ADM_STATUS0_APPS_DBGEN_ALLOWED_SHIFT     (9U)
#define ADM_STATUS0_APPS_DBGEN_ALLOWED(x)        (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APPS_DBGEN_ALLOWED_SHIFT)) & ADM_STATUS0_APPS_DBGEN_ALLOWED_MASK)
#define ADM_STATUS0_APPS_SPNIDEN_ALLOWED_MASK    (0x1E000U)
#define ADM_STATUS0_APPS_SPNIDEN_ALLOWED_SHIFT   (13U)
#define ADM_STATUS0_APPS_SPNIDEN_ALLOWED(x)      (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APPS_SPNIDEN_ALLOWED_SHIFT)) & ADM_STATUS0_APPS_SPNIDEN_ALLOWED_MASK)
#define ADM_STATUS0_APPS_SPIDEN_ALLOWED_MASK     (0x1E0000U)
#define ADM_STATUS0_APPS_SPIDEN_ALLOWED_SHIFT    (17U)
#define ADM_STATUS0_APPS_SPIDEN_ALLOWED(x)       (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APPS_SPIDEN_ALLOWED_SHIFT)) & ADM_STATUS0_APPS_SPIDEN_ALLOWED_MASK)
#define ADM_STATUS0_EARLY_FUSES_VALID_MASK       (0x200000U)
#define ADM_STATUS0_EARLY_FUSES_VALID_SHIFT      (21U)
#define ADM_STATUS0_EARLY_FUSES_VALID(x)         (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_EARLY_FUSES_VALID_SHIFT)) & ADM_STATUS0_EARLY_FUSES_VALID_MASK)
#define ADM_STATUS0_SCU_FUSES_VALID_MASK         (0x400000U)
#define ADM_STATUS0_SCU_FUSES_VALID_SHIFT        (22U)
#define ADM_STATUS0_SCU_FUSES_VALID(x)           (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SCU_FUSES_VALID_SHIFT)) & ADM_STATUS0_SCU_FUSES_VALID_MASK)
#define ADM_STATUS0_ALL_FUSES_VALID_MASK         (0x800000U)
#define ADM_STATUS0_ALL_FUSES_VALID_SHIFT        (23U)
#define ADM_STATUS0_ALL_FUSES_VALID(x)           (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_ALL_FUSES_VALID_SHIFT)) & ADM_STATUS0_ALL_FUSES_VALID_MASK)
#define ADM_STATUS0_HAB_ONLY_CRYPTO_MASK         (0x1000000U)
#define ADM_STATUS0_HAB_ONLY_CRYPTO_SHIFT        (24U)
#define ADM_STATUS0_HAB_ONLY_CRYPTO(x)           (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_HAB_ONLY_CRYPTO_SHIFT)) & ADM_STATUS0_HAB_ONLY_CRYPTO_MASK)
#define ADM_STATUS0_APB_GPR_ILLEGAL_RD_MASK      (0x2000000U)
#define ADM_STATUS0_APB_GPR_ILLEGAL_RD_SHIFT     (25U)
#define ADM_STATUS0_APB_GPR_ILLEGAL_RD(x)        (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APB_GPR_ILLEGAL_RD_SHIFT)) & ADM_STATUS0_APB_GPR_ILLEGAL_RD_MASK)
#define ADM_STATUS0_APB_GPR_ILLEGAL_WR_MASK      (0x4000000U)
#define ADM_STATUS0_APB_GPR_ILLEGAL_WR_SHIFT     (26U)
#define ADM_STATUS0_APB_GPR_ILLEGAL_WR(x)        (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APB_GPR_ILLEGAL_WR_SHIFT)) & ADM_STATUS0_APB_GPR_ILLEGAL_WR_MASK)
#define ADM_STATUS0_APB_SCU_GPR_ILLEGAL_RD_MASK  (0x8000000U)
#define ADM_STATUS0_APB_SCU_GPR_ILLEGAL_RD_SHIFT (27U)
#define ADM_STATUS0_APB_SCU_GPR_ILLEGAL_RD(x)    (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APB_SCU_GPR_ILLEGAL_RD_SHIFT)) & ADM_STATUS0_APB_SCU_GPR_ILLEGAL_RD_MASK)
#define ADM_STATUS0_APB_SCU_GPR_ILLEGAL_WR_MASK  (0x10000000U)
#define ADM_STATUS0_APB_SCU_GPR_ILLEGAL_WR_SHIFT (28U)
#define ADM_STATUS0_APB_SCU_GPR_ILLEGAL_WR(x)    (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_APB_SCU_GPR_ILLEGAL_WR_SHIFT)) & ADM_STATUS0_APB_SCU_GPR_ILLEGAL_WR_MASK)
#define ADM_STATUS0_SDP_DISABLE_MASK             (0x20000000U)
#define ADM_STATUS0_SDP_DISABLE_SHIFT            (29U)
#define ADM_STATUS0_SDP_DISABLE(x)               (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SDP_DISABLE_SHIFT)) & ADM_STATUS0_SDP_DISABLE_MASK)
#define ADM_STATUS0_SDP_WO_MASK                  (0x40000000U)
#define ADM_STATUS0_SDP_WO_SHIFT                 (30U)
#define ADM_STATUS0_SDP_WO(x)                    (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SDP_WO_SHIFT)) & ADM_STATUS0_SDP_WO_MASK)
#define ADM_STATUS0_SECO_FW_MASK                 (0x80000000U)
#define ADM_STATUS0_SECO_FW_SHIFT                (31U)
#define ADM_STATUS0_SECO_FW(x)                   (((uint32_t)(((uint32_t)(x)) << ADM_STATUS0_SECO_FW_SHIFT)) & ADM_STATUS0_SECO_FW_MASK)

/*! @name STATUS1 - Status register for SCU. */
#define ADM_STATUS1_CL_SV_MASK                   (0x1U)
#define ADM_STATUS1_CL_SV_SHIFT                  (0U)
#define ADM_STATUS1_CL_SV(x)                     (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_CL_SV_SHIFT)) & ADM_STATUS1_CL_SV_MASK)
#define ADM_STATUS1_UERR_SV_MASK                 (0x2U)
#define ADM_STATUS1_UERR_SV_SHIFT                (1U)
#define ADM_STATUS1_UERR_SV(x)                   (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_UERR_SV_SHIFT)) & ADM_STATUS1_UERR_SV_MASK)
#define ADM_STATUS1_TAMPER_SV_MASK               (0x4U)
#define ADM_STATUS1_TAMPER_SV_SHIFT              (2U)
#define ADM_STATUS1_TAMPER_SV(x)                 (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_TAMPER_SV_SHIFT)) & ADM_STATUS1_TAMPER_SV_MASK)
#define ADM_STATUS1_LIFE_CYCLE_MASK              (0x3FF8U)
#define ADM_STATUS1_LIFE_CYCLE_SHIFT             (3U)
#define ADM_STATUS1_LIFE_CYCLE(x)                (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_LIFE_CYCLE_SHIFT)) & ADM_STATUS1_LIFE_CYCLE_MASK)
#define ADM_STATUS1_HDCP_ENCRYPTED_MASK          (0x4000U)
#define ADM_STATUS1_HDCP_ENCRYPTED_SHIFT         (14U)
#define ADM_STATUS1_HDCP_ENCRYPTED(x)            (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_HDCP_ENCRYPTED_SHIFT)) & ADM_STATUS1_HDCP_ENCRYPTED_MASK)
#define ADM_STATUS1_NXP_SECRETS_PRESENT_MASK     (0x8000U)
#define ADM_STATUS1_NXP_SECRETS_PRESENT_SHIFT    (15U)
#define ADM_STATUS1_NXP_SECRETS_PRESENT(x)       (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_NXP_SECRETS_PRESENT_SHIFT)) & ADM_STATUS1_NXP_SECRETS_PRESENT_MASK)
#define ADM_STATUS1_SECO_HOLD_MASK               (0x10000U)
#define ADM_STATUS1_SECO_HOLD_SHIFT              (16U)
#define ADM_STATUS1_SECO_HOLD(x)                 (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_SECO_HOLD_SHIFT)) & ADM_STATUS1_SECO_HOLD_MASK)
#define ADM_STATUS1_SCU_HOLD_MASK                (0x20000U)
#define ADM_STATUS1_SCU_HOLD_SHIFT               (17U)
#define ADM_STATUS1_SCU_HOLD(x)                  (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_SCU_HOLD_SHIFT)) & ADM_STATUS1_SCU_HOLD_MASK)
#define ADM_STATUS1_SNVS_HOLD_MASK               (0x40000U)
#define ADM_STATUS1_SNVS_HOLD_SHIFT              (18U)
#define ADM_STATUS1_SNVS_HOLD(x)                 (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_SNVS_HOLD_SHIFT)) & ADM_STATUS1_SNVS_HOLD_MASK)
#define ADM_STATUS1_FIELD_IS_PROGRAMMED_MASK     (0x80000U)
#define ADM_STATUS1_FIELD_IS_PROGRAMMED_SHIFT    (19U)
#define ADM_STATUS1_FIELD_IS_PROGRAMMED(x)       (((uint32_t)(((uint32_t)(x)) << ADM_STATUS1_FIELD_IS_PROGRAMMED_SHIFT)) & ADM_STATUS1_FIELD_IS_PROGRAMMED_MASK)

/*! @name GPR0 -  */
#define ADM_GPR0_BANK0_MASK                      (0xFFFFFFFFU)
#define ADM_GPR0_BANK0_SHIFT                     (0U)
#define ADM_GPR0_BANK0(x)                        (((uint32_t)(((uint32_t)(x)) << ADM_GPR0_BANK0_SHIFT)) & ADM_GPR0_BANK0_MASK)

/* The count of ADM_GPR0 */
#define ADM_GPR0_COUNT                           (4U)

/*! @name GPR1 -  */
#define ADM_GPR1_BANK1_MASK                      (0xFFFFFFFFU)
#define ADM_GPR1_BANK1_SHIFT                     (0U)
#define ADM_GPR1_BANK1(x)                        (((uint32_t)(((uint32_t)(x)) << ADM_GPR1_BANK1_SHIFT)) & ADM_GPR1_BANK1_MASK)

/* The count of ADM_GPR1 */
#define ADM_GPR1_COUNT                           (4U)

/*! @name GPR2 -  */
#define ADM_GPR2_BANK2_MASK                      (0xFFFFFFFFU)
#define ADM_GPR2_BANK2_SHIFT                     (0U)
#define ADM_GPR2_BANK2(x)                        (((uint32_t)(((uint32_t)(x)) << ADM_GPR2_BANK2_SHIFT)) & ADM_GPR2_BANK2_MASK)

/* The count of ADM_GPR2 */
#define ADM_GPR2_COUNT                           (4U)

/*! @name GPR3 -  */
#define ADM_GPR3_BANK3_MASK                      (0xFFFFFFFFU)
#define ADM_GPR3_BANK3_SHIFT                     (0U)
#define ADM_GPR3_BANK3(x)                        (((uint32_t)(((uint32_t)(x)) << ADM_GPR3_BANK3_SHIFT)) & ADM_GPR3_BANK3_MASK)

/* The count of ADM_GPR3 */
#define ADM_GPR3_COUNT                           (4U)

/*! @name GPR4 -  */
#define ADM_GPR4_BANK4_MASK                      (0xFFFFFFFFU)
#define ADM_GPR4_BANK4_SHIFT                     (0U)
#define ADM_GPR4_BANK4(x)                        (((uint32_t)(((uint32_t)(x)) << ADM_GPR4_BANK4_SHIFT)) & ADM_GPR4_BANK4_MASK)

/* The count of ADM_GPR4 */
#define ADM_GPR4_COUNT                           (4U)

/*! @name GPR5 -  */
#define ADM_GPR5_BANK5_MASK                      (0xFFFFFFFFU)
#define ADM_GPR5_BANK5_SHIFT                     (0U)
#define ADM_GPR5_BANK5(x)                        (((uint32_t)(((uint32_t)(x)) << ADM_GPR5_BANK5_SHIFT)) & ADM_GPR5_BANK5_MASK)

/* The count of ADM_GPR5 */
#define ADM_GPR5_COUNT                           (4U)

/*! @name SECO_SUPER_ROOT_KEY_HASH -  */
#define ADM_SECO_SUPER_ROOT_KEY_HASH_VALUE_MASK  (0xFFFFFFFFU)
#define ADM_SECO_SUPER_ROOT_KEY_HASH_VALUE_SHIFT (0U)
#define ADM_SECO_SUPER_ROOT_KEY_HASH_VALUE(x)    (((uint32_t)(((uint32_t)(x)) << ADM_SECO_SUPER_ROOT_KEY_HASH_VALUE_SHIFT)) & ADM_SECO_SUPER_ROOT_KEY_HASH_VALUE_MASK)

/* The count of ADM_SECO_SUPER_ROOT_KEY_HASH */
#define ADM_SECO_SUPER_ROOT_KEY_HASH_COUNT       (8U)

/*! @name HDMI_SUPER_ROOT_KEY_HASH -  */
#define ADM_HDMI_SUPER_ROOT_KEY_HASH_VALUE_MASK  (0xFFFFFFFFU)
#define ADM_HDMI_SUPER_ROOT_KEY_HASH_VALUE_SHIFT (0U)
#define ADM_HDMI_SUPER_ROOT_KEY_HASH_VALUE(x)    (((uint32_t)(((uint32_t)(x)) << ADM_HDMI_SUPER_ROOT_KEY_HASH_VALUE_SHIFT)) & ADM_HDMI_SUPER_ROOT_KEY_HASH_VALUE_MASK)

/* The count of ADM_HDMI_SUPER_ROOT_KEY_HASH */
#define ADM_HDMI_SUPER_ROOT_KEY_HASH_COUNT       (8U)

/*! @name CAAM_PWRCTRL_REF - CAAM PWRCTRL reg for reference */
#define ADM_CAAM_PWRCTRL_REF_VALUE_MASK          (0xFFFFFFU)
#define ADM_CAAM_PWRCTRL_REF_VALUE_SHIFT         (0U)
#define ADM_CAAM_PWRCTRL_REF_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << ADM_CAAM_PWRCTRL_REF_VALUE_SHIFT)) & ADM_CAAM_PWRCTRL_REF_VALUE_MASK)
#define ADM_CAAM_PWRCTRL_REF_LOCK_PWR_REF_MASK   (0x80000000U)
#define ADM_CAAM_PWRCTRL_REF_LOCK_PWR_REF_SHIFT  (31U)
#define ADM_CAAM_PWRCTRL_REF_LOCK_PWR_REF(x)     (((uint32_t)(((uint32_t)(x)) << ADM_CAAM_PWRCTRL_REF_LOCK_PWR_REF_SHIFT)) & ADM_CAAM_PWRCTRL_REF_LOCK_PWR_REF_MASK)

/*! @name SPARE -  */
#define ADM_SPARE_VALUE_MASK                     (0xFFFFFFFFU)
#define ADM_SPARE_VALUE_SHIFT                    (0U)
#define ADM_SPARE_VALUE(x)                       (((uint32_t)(((uint32_t)(x)) << ADM_SPARE_VALUE_SHIFT)) & ADM_SPARE_VALUE_MASK)

/* The count of ADM_SPARE */
#define ADM_SPARE_COUNT                          (4U)


/*!
 * @}
 */ /* end of group ADM_Register_Masks */


/* ADM - Peripheral instance base addresses */
/** Peripheral ADM base pointer */
#define ADM                                      ((ADM_Type *)ADM_BASE)
/** Array initializer of ADM peripheral base addresses */
#define ADM_BASE_ADDRS                           { ADM_BASE }
/** Array initializer of ADM peripheral base pointers */
#define ADM_BASE_PTRS                            { ADM }

/*!
 * @}
 */ /* end of group ADM_Peripheral_Access_Layer */


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


#endif  /* ADM_H */

