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
 * @file rep2.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for rep2
 *
 * CMSIS Peripheral Access Layer for rep2
 */

#ifndef REP2_H
#define REP2_H                               /**< Symbol preventing repeated inclusion */


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
   -- REP2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REP2_Peripheral_Access_Layer REP2 Peripheral Access Layer
 * @{
 */

/** REP2 - Register Layout Typedef */
typedef struct {
  __I  uint32_t REPSTAT;                      /**< REP status Register, offset: 0x0 */
  __IO uint32_t IR;                           /**< Instruction Register, offset: 0x4 */
       uint8_t RESERVED_0[20];
  __IO uint32_t CTRL;                         /**< Control Register, offset: 0x1C */
  __I  uint32_t ECCSTAT;                      /**< ECC status Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PPSEL;                        /**< Power plane select Register, offset: 0x30 */
       uint8_t RESERVED_2[204];
  __IO uint32_t SSR[64];                      /**< Solution Stage Register - word 0, offset: 0x100 */
} REP2_Type;

/* ----------------------------------------------------------------------------
   -- REP2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REP2_Register_Masks REP2 Register Masks
 * @{
 */

/*! @name REPSTAT - REP status Register */
#define REP2_REPSTAT_IDL_MASK                 (0x1U)
#define REP2_REPSTAT_IDL_SHIFT                (0U)
#define REP2_REPSTAT_IDL(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_IDL_SHIFT)) & REP2_REPSTAT_IDL_MASK)
#define REP2_REPSTAT_CIE_MASK                 (0x2U)
#define REP2_REPSTAT_CIE_SHIFT                (1U)
#define REP2_REPSTAT_CIE(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_CIE_SHIFT)) & REP2_REPSTAT_CIE_MASK)
#define REP2_REPSTAT_INE_MASK                 (0x4U)
#define REP2_REPSTAT_INE_SHIFT                (2U)
#define REP2_REPSTAT_INE(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_INE_SHIFT)) & REP2_REPSTAT_INE_MASK)
#define REP2_REPSTAT_IAE_MASK                 (0x8U)
#define REP2_REPSTAT_IAE_SHIFT                (3U)
#define REP2_REPSTAT_IAE(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_IAE_SHIFT)) & REP2_REPSTAT_IAE_MASK)
#define REP2_REPSTAT_FXE_MASK                 (0x10U)
#define REP2_REPSTAT_FXE_SHIFT                (4U)
#define REP2_REPSTAT_FXE(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_FXE_SHIFT)) & REP2_REPSTAT_FXE_MASK)
#define REP2_REPSTAT_EME_MASK                 (0x20U)
#define REP2_REPSTAT_EME_SHIFT                (5U)
#define REP2_REPSTAT_EME(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_EME_SHIFT)) & REP2_REPSTAT_EME_MASK)
#define REP2_REPSTAT_BXE_MASK                 (0x40U)
#define REP2_REPSTAT_BXE_SHIFT                (6U)
#define REP2_REPSTAT_BXE(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_BXE_SHIFT)) & REP2_REPSTAT_BXE_MASK)
#define REP2_REPSTAT_COFE_MASK                (0x80U)
#define REP2_REPSTAT_COFE_SHIFT               (7U)
#define REP2_REPSTAT_COFE(x)                  (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_COFE_SHIFT)) & REP2_REPSTAT_COFE_MASK)
#define REP2_REPSTAT_COWE_MASK                (0x100U)
#define REP2_REPSTAT_COWE_SHIFT               (8U)
#define REP2_REPSTAT_COWE(x)                  (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_COWE_SHIFT)) & REP2_REPSTAT_COWE_MASK)
#define REP2_REPSTAT_ISA_MASK                 (0x400U)
#define REP2_REPSTAT_ISA_SHIFT                (10U)
#define REP2_REPSTAT_ISA(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_REPSTAT_ISA_SHIFT)) & REP2_REPSTAT_ISA_MASK)

/*! @name IR - Instruction Register */
#define REP2_IR_DREG_MASK                     (0xFFU)
#define REP2_IR_DREG_SHIFT                    (0U)
#define REP2_IR_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << REP2_IR_DREG_SHIFT)) & REP2_IR_DREG_MASK)
#define REP2_IR_OPCODE_MASK                   (0xF00U)
#define REP2_IR_OPCODE_SHIFT                  (8U)
#define REP2_IR_OPCODE(x)                     (((uint32_t)(((uint32_t)(x)) << REP2_IR_OPCODE_SHIFT)) & REP2_IR_OPCODE_MASK)

/*! @name CTRL - Control Register */
#define REP2_CTRL_ECCSTATRST_MASK             (0x1U)
#define REP2_CTRL_ECCSTATRST_SHIFT            (0U)
#define REP2_CTRL_ECCSTATRST(x)               (((uint32_t)(((uint32_t)(x)) << REP2_CTRL_ECCSTATRST_SHIFT)) & REP2_CTRL_ECCSTATRST_MASK)
#define REP2_CTRL_ECCGENDIS_MASK              (0x4U)
#define REP2_CTRL_ECCGENDIS_SHIFT             (2U)
#define REP2_CTRL_ECCGENDIS(x)                (((uint32_t)(((uint32_t)(x)) << REP2_CTRL_ECCGENDIS_SHIFT)) & REP2_CTRL_ECCGENDIS_MASK)
#define REP2_CTRL_ECCCHKDIS_MASK              (0x8U)
#define REP2_CTRL_ECCCHKDIS_SHIFT             (3U)
#define REP2_CTRL_ECCCHKDIS(x)                (((uint32_t)(((uint32_t)(x)) << REP2_CTRL_ECCCHKDIS_SHIFT)) & REP2_CTRL_ECCCHKDIS_MASK)
#define REP2_CTRL_BISRWDT_MASK                (0x30U)
#define REP2_CTRL_BISRWDT_SHIFT               (4U)
#define REP2_CTRL_BISRWDT(x)                  (((uint32_t)(((uint32_t)(x)) << REP2_CTRL_BISRWDT_SHIFT)) & REP2_CTRL_BISRWDT_MASK)
#define REP2_CTRL_BISRUPDATE_MASK             (0x40U)
#define REP2_CTRL_BISRUPDATE_SHIFT            (6U)
#define REP2_CTRL_BISRUPDATE(x)               (((uint32_t)(((uint32_t)(x)) << REP2_CTRL_BISRUPDATE_SHIFT)) & REP2_CTRL_BISRUPDATE_MASK)
#define REP2_CTRL_LOADSSR_MASK                (0x80U)
#define REP2_CTRL_LOADSSR_SHIFT               (7U)
#define REP2_CTRL_LOADSSR(x)                  (((uint32_t)(((uint32_t)(x)) << REP2_CTRL_LOADSSR_SHIFT)) & REP2_CTRL_LOADSSR_MASK)

/*! @name ECCSTAT - Control Register */
#define REP2_ECCSTAT_ESE_MASK                 (0x1U)
#define REP2_ECCSTAT_ESE_SHIFT                (0U)
#define REP2_ECCSTAT_ESE(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_ECCSTAT_ESE_SHIFT)) & REP2_ECCSTAT_ESE_MASK)
#define REP2_ECCSTAT_EME_MASK                 (0x2U)
#define REP2_ECCSTAT_EME_SHIFT                (1U)
#define REP2_ECCSTAT_EME(x)                   (((uint32_t)(((uint32_t)(x)) << REP2_ECCSTAT_EME_SHIFT)) & REP2_ECCSTAT_EME_MASK)
#define REP2_ECCSTAT_SINGLEERR_MASK           (0x3FCU)
#define REP2_ECCSTAT_SINGLEERR_SHIFT          (2U)
#define REP2_ECCSTAT_SINGLEERR(x)             (((uint32_t)(((uint32_t)(x)) << REP2_ECCSTAT_SINGLEERR_SHIFT)) & REP2_ECCSTAT_SINGLEERR_MASK)
#define REP2_ECCSTAT_MULTIERR_MASK            (0x3F0000U)
#define REP2_ECCSTAT_MULTIERR_SHIFT           (16U)
#define REP2_ECCSTAT_MULTIERR(x)              (((uint32_t)(((uint32_t)(x)) << REP2_ECCSTAT_MULTIERR_SHIFT)) & REP2_ECCSTAT_MULTIERR_MASK)

/*! @name SSR - Solution Stage Register */
#define REP2_SSR_DATA_MASK                    (0x3FFU)
#define REP2_SSR_DATA_SHIFT                   (0U)
#define REP2_SSR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << REP2_SSR_DATA_SHIFT)) & REP2_SSR_DATA_MASK)
#define REP2_SSR_ADDR_MASK                    (0xFFC00U)
#define REP2_SSR_ADDR_SHIFT                   (10U)
#define REP2_SSR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << REP2_SSR_ADDR_SHIFT)) & REP2_SSR_ADDR_MASK)
#define REP2_SSR_ECC_MASK                     (0x7F00000U)
#define REP2_SSR_ECC_SHIFT                    (20U)
#define REP2_SSR_ECC(x)                       (((uint32_t)(((uint32_t)(x)) << REP2_SSR_ECC_SHIFT)) & REP2_SSR_ECC_MASK)

/*!
 * @}
 */ /* end of group REP2_Register_Masks */

/*! @name REP Instruction set */
#define OPCODE_PROG_STORAGE                   (0x1)
#define OPCODE_READ_STORAGE                   (0x2)
#define OPCODE_GET_DATA                       (0x3)
#define OPCODE_LOAD_DATA                      (0x4)
#define OPCODE_CLEAR                          (0x5)
#define OPCODE_COMPARE_DATA                   (0x6)

/*! @name REP Data Registers */
#define DREG_ECID                             (0x1)
#define DREG_SSR                              (0x2)

/* REP2 - Peripheral instance base addresses */
/** Peripheral REP2 base pointer */
#define REP2                                   ((REP2_Type *)REP2_BASE)
/** Array initializer of REP2 peripheral base addresses */
#define REP2_BASE_ADDRS                       { REP2_BASE }
/** Array initializer of REP2 peripheral base pointers */
#define REP2_BASE_PTRS                        { REP2 }

/*!
 * @}
 */ /* end of group REP2_Peripheral_Access_Layer */


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


#endif  /* REP2_H */

