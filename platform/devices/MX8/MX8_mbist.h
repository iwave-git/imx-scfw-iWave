/*
** ###################################################################
**     Processor:           mbist
**     Compiler:            Keil ARM C/C++ Compiler
**     Build:               b181128
**
**     Abstract:
**         CMSIS Peripheral Access Layer for mbist
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2018 NXP
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
 * @file MX8_mbist.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MX8_mbist
 *
 * CMSIS Peripheral Access Layer for MX8_mbist
 */

#ifndef MX8_MBIST_H
#define MX8_MBIST_H                           /**< Symbol preventing repeated inclusion */


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
   -- MBIST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MBIST_Peripheral_Access_Layer MBIST Peripheral Access Layer
 * @{
 */

/** MBIST - Register Layout Typedef */
typedef struct {
  __IO uint32_t IOR;                               /**< Internal Offset Register, offset: 0x0 */
  __IO uint32_t IAR;                               /**< Indirect Access Register, offset: 0x4 */
  __O  uint32_t DBA;                               /**< Direct BIST Access Register (Write), offset: 0x8 */
  __IO uint16_t GCR;                               /**< General Configuration, offset: 0xC */
       uint8_t RESERVED_0[2];
  __IO uint8_t ACSTA;                              /**< Address Configuration Start, offset: 0x10 */
       uint8_t RESERVED_1[3];
  __IO uint8_t ACEND;                              /**< Address Configuration End, offset: 0x14 */
       uint8_t RESERVED_2[3];
  __IO uint16_t ALG1;                              /**< Algorithm Reg1, offset: 0x18 */
       uint8_t RESERVED_3[2];
  __IO uint32_t ALG2;                              /**< Algorithm Reg2, offset: 0x1C */
  __IO uint32_t ALG3;                              /**< Algorithm Reg3, offset: 0x20 */
  __IO uint32_t ALG4;                              /**< Algorithm Reg4, offset: 0x24 */
  __IO uint32_t ALG5;                              /**< Algorithm Reg5, offset: 0x28 */
       uint8_t RESERVED_4[16];
  __IO uint8_t BGCR;                               /**< Background Configuration, offset: 0x3C */
       uint8_t RESERVED_5[3];
  __IO uint8_t MSEL;                               /**< Memory Selection 1, offset: 0x40 */
       uint8_t RESERVED_6[31];
  __IO uint16_t UDPR;                              /**< User Defined Port Control, offset: 0x60 */
       uint8_t RESERVED_7[66];
  __IO uint8_t BSTART;                             /**< BIST Start, offset: 0xA4 */
       uint8_t RESERVED_8[3];
} MBIST_Type;

/* ----------------------------------------------------------------------------
   -- MBIST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MBIST_Register_Masks MBIST Register Masks
 * @{
 */

/*! @name IOR - Internal Offset Register */
/*! @{ */
#define MBIST_IOR_OFFSET_MASK                  (0xFFFFFFFFU)
#define MBIST_IOR_OFFSET_SHIFT                 (0U)
#define MBIST_IOR_OFFSET(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_IOR_OFFSET_SHIFT)) & MBIST_IOR_OFFSET_MASK)
/*! @} */

/*! @name IAR - Indirect Access Register */
/*! @{ */
#define MBIST_IAR_VALUE_MASK                   (0xFFFFFFFFU)
#define MBIST_IAR_VALUE_SHIFT                  (0U)
#define MBIST_IAR_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << MBIST_IAR_VALUE_SHIFT)) & MBIST_IAR_VALUE_MASK)
/*! @} */

/*! @name DBA - Direct BIST Access Register (Write) */
/*! @{ */
#define MBIST_DBA_BSTART_MASK                  (0x3U)
#define MBIST_DBA_BSTART_SHIFT                 (0U)
#define MBIST_DBA_BSTART(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_BSTART_SHIFT)) & MBIST_DBA_BSTART_MASK)
#define MBIST_DBA_BRST_MASK                    (0x4U)
#define MBIST_DBA_BRST_SHIFT                   (2U)
/*! BRST - Bist Reset
 *  0b1..FSLBIST3/ARMport general soft reset.
 */
#define MBIST_DBA_BRST(x)                      (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_BRST_SHIFT)) & MBIST_DBA_BRST_MASK)
#define MBIST_DBA_SRST_MASK                    (0x8U)
#define MBIST_DBA_SRST_SHIFT                   (3U)
/*! SRST - Status Reset
 *  0b1..FSLBIST3/ARMport Status reset. This resets: DSMs; BSMs; ipt_bist_status.
 */
#define MBIST_DBA_SRST(x)                      (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_SRST_SHIFT)) & MBIST_DBA_SRST_MASK)
#define MBIST_DBA_ALGOSEL_MASK                 (0x1F0U)
#define MBIST_DBA_ALGOSEL_SHIFT                (4U)
#define MBIST_DBA_ALGOSEL(x)                   (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_ALGOSEL_SHIFT)) & MBIST_DBA_ALGOSEL_MASK)
#define MBIST_DBA_DB0_MASK                     (0x200U)
#define MBIST_DBA_DB0_SHIFT                    (9U)
#define MBIST_DBA_DB0(x)                       (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_DB0_SHIFT)) & MBIST_DBA_DB0_MASK)
#define MBIST_DBA_DB1_MASK                     (0x400U)
#define MBIST_DBA_DB1_SHIFT                    (10U)
#define MBIST_DBA_DB1(x)                       (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_DB1_SHIFT)) & MBIST_DBA_DB1_MASK)
#define MBIST_DBA_DB2_MASK                     (0x800U)
#define MBIST_DBA_DB2_SHIFT                    (11U)
#define MBIST_DBA_DB2(x)                       (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_DB2_SHIFT)) & MBIST_DBA_DB2_MASK)
#define MBIST_DBA_BISRLAT_MASK                 (0x8000U)
#define MBIST_DBA_BISRLAT_SHIFT                (15U)
#define MBIST_DBA_BISRLAT(x)                   (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_BISRLAT_SHIFT)) & MBIST_DBA_BISRLAT_MASK)
#define MBIST_DBA_UDPR_MASK                    (0xFFFF0000U)
#define MBIST_DBA_UDPR_SHIFT                   (16U)
#define MBIST_DBA_UDPR(x)                      (((uint32_t)(((uint32_t)(x)) << MBIST_DBA_UDPR_SHIFT)) & MBIST_DBA_UDPR_MASK)
/*! @} */

/*! @name GCR - General Configuration */
/*! @{ */
#define MBIST_GCR_OPM_MASK                     (0x7U)
#define MBIST_GCR_OPM_SHIFT                    (0U)
/*! OPM - Operation Mode
 *  0b000..Normal Sticky Mode - Test runs from start to end and then stops (The fail signal will be asserted as soon as an error is detected and stays asserted until reset at the end of the test).
 *  0b001..RESERVED
 *  0b010..Run-Forever Sticky Mode - Test repeats forever. The fail bit will be asserted as soon as an error is detected and it stays asserted.
 *  0b011..RESERVED
 *  0b100..Stop-On-Fail Mode - Test stops when a fail is detected and can then be resumed under user command (manual fail data upload).
 *  0b101..RESERVED
 *  0b110..Stop-On-Read Mode (just for ROM test) - Test stops on each read and can then be resumed (manual fail data uploaded)
 *  0b111..RESERVED
 */
#define MBIST_GCR_OPM(x)                       (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_OPM_SHIFT)) & MBIST_GCR_OPM_MASK)
#define MBIST_GCR_AMODE_MASK                   (0x38U)
#define MBIST_GCR_AMODE_SHIFT                  (3U)
/*! AMODE - Address Mode
 *  0b000..Natural (or Normal) Addressing - Addresses are incremented from first memory position to up.
 *  0b001..Block fast - Block address are incremented first, the other addresses are incremented as address bits were rotated making the block-bits the LSBs.
 *  0b010..Column Fast - Column address are incremented first, the other addresses are incremented as the address bits were rotated making the column-bits the LSBs.
 *  0b011..Row Fast - Row addresses are incremented first, then column; the other addresses are incremented as the address bits were rotated making the row-bits the LSBs.
 *  0b100..Gang Fast - The gang addresses are incremented first, the other addresses are incremented as the address bits were rotated making the gang-bits the LSBs.
 *  0b101..Reserved (if selected it falls back to default -Natural Addressing)
 *  0b110..Reserved (if selected it falls back to default -Natural Addressing)
 *  0b111..Anybit Fast - In this mode, the test will be run multiple times one for each address bit being the fast bit of the run. Attention! Running this mode takes a long time.
 */
#define MBIST_GCR_AMODE(x)                     (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_AMODE_SHIFT)) & MBIST_GCR_AMODE_MASK)
#define MBIST_GCR_MAM_MASK                     (0x1C0U)
#define MBIST_GCR_MAM_SHIFT                    (6U)
/*! MAM - Dual Port Test Configuration
 *  0b000..Disable both Automatic (A/B) and Dual Port stress Tests
 *  0b001..Automatic A/B Test with same address
 *  0b010..Automatic A/B Test but disable Dual Port stress Test
 *  0b011..Automatic A/B Test with adjacent address
 *  0b100..Regular Test with same address and port A as primary
 *  0b101..Regular Test with same address and port B as primary
 *  0b110..Regular Test with adjacent address and port A as primary
 *  0b111..Regular Test with adjacent address and port B as primary
 */
#define MBIST_GCR_MAM(x)                       (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_MAM_SHIFT)) & MBIST_GCR_MAM_MASK)
#define MBIST_GCR_CEN_MASK                     (0x200U)
#define MBIST_GCR_CEN_SHIFT                    (9U)
/*! CEN - Continuous Enabled
 *  0b0..Continuous Enable mode de-active.
 *  0b1..Continuous Enable mode active.
 */
#define MBIST_GCR_CEN(x)                       (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_CEN_SHIFT)) & MBIST_GCR_CEN_MASK)
#define MBIST_GCR_NOCOMP_MASK                  (0x400U)
#define MBIST_GCR_NOCOMP_SHIFT                 (10U)
/*! NOCOMP - No Compare
 *  0b0..Normal compare is performed in RAM tests.
 *  0b1..No compare is performed in RAM tests.
 */
#define MBIST_GCR_NOCOMP(x)                    (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_NOCOMP_SHIFT)) & MBIST_GCR_NOCOMP_MASK)
#define MBIST_GCR_IWEN_MASK                    (0x800U)
#define MBIST_GCR_IWEN_SHIFT                   (11U)
/*! IWEN - Bit Write Enable Test Mode
 *  0b0..Disable bit/word write enable test mode.
 *  0b1..Enable bit/word write enable test mode.
 */
#define MBIST_GCR_IWEN(x)                      (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_IWEN_SHIFT)) & MBIST_GCR_IWEN_MASK)
#define MBIST_GCR_MC_RST_MASK                  (0x1000U)
#define MBIST_GCR_MC_RST_SHIFT                 (12U)
/*! MC_RST - Memory Configuration Reset
 *  0b1..Reset memory configuration.
 */
#define MBIST_GCR_MC_RST(x)                    (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_MC_RST_SHIFT)) & MBIST_GCR_MC_RST_MASK)
#define MBIST_GCR_RDHLD_MASK                   (0x4000U)
#define MBIST_GCR_RDHLD_SHIFT                  (14U)
#define MBIST_GCR_RDHLD(x)                     (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_RDHLD_SHIFT)) & MBIST_GCR_RDHLD_MASK)
#define MBIST_GCR_BURNIN_MASK                  (0x8000U)
#define MBIST_GCR_BURNIN_SHIFT                 (15U)
#define MBIST_GCR_BURNIN(x)                    (((uint16_t)(((uint16_t)(x)) << MBIST_GCR_BURNIN_SHIFT)) & MBIST_GCR_BURNIN_MASK)
/*! @} */

/*! @name ACSTA - Address Configuration Start */
/*! @{ */
#define MBIST_ACSTA_STARTA_MASK                (0x7FFU)
#define MBIST_ACSTA_STARTA_SHIFT               (0U)
#define MBIST_ACSTA_STARTA(x)                  (((uint8_t)(((uint8_t)(x)) << MBIST_ACSTA_STARTA_SHIFT)) & MBIST_ACSTA_STARTA_MASK)
/*! @} */

/*! @name ACEND - Address Configuration End */
/*! @{ */
#define MBIST_ACEND_ENDA_MASK                  (0x7FFU)
#define MBIST_ACEND_ENDA_SHIFT                 (0U)
#define MBIST_ACEND_ENDA(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_ACEND_ENDA_SHIFT)) & MBIST_ACEND_ENDA_MASK)
/*! @} */

/*! @name ALG1 - Algorithm Reg1 */
/*! @{ */
#define MBIST_ALG1_VME_MASK                    (0x7U)
#define MBIST_ALG1_VME_SHIFT                   (0U)
/*! VME - Valid March Elements
 *  0b000..ME0
 *  0b001..ME0 Through ME1
 *  0b010..ME0 Through ME2
 *  0b011..ME0 Through ME3
 *  0b100..ME0 Through ME4
 *  0b101..ME0 Through ME5
 *  0b110..ME0 Through ME6
 *  0b111..ME0 Through ME7
 */
#define MBIST_ALG1_VME(x)                      (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_VME_SHIFT)) & MBIST_ALG1_VME_MASK)
#define MBIST_ALG1_PAUSE_0_MASK                (0x8U)
#define MBIST_ALG1_PAUSE_0_SHIFT               (3U)
#define MBIST_ALG1_PAUSE_0(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_0_SHIFT)) & MBIST_ALG1_PAUSE_0_MASK)
#define MBIST_ALG1_PAUSE_1_MASK                (0x10U)
#define MBIST_ALG1_PAUSE_1_SHIFT               (4U)
#define MBIST_ALG1_PAUSE_1(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_1_SHIFT)) & MBIST_ALG1_PAUSE_1_MASK)
#define MBIST_ALG1_PAUSE_2_MASK                (0x20U)
#define MBIST_ALG1_PAUSE_2_SHIFT               (5U)
#define MBIST_ALG1_PAUSE_2(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_2_SHIFT)) & MBIST_ALG1_PAUSE_2_MASK)
#define MBIST_ALG1_PAUSE_3_MASK                (0x40U)
#define MBIST_ALG1_PAUSE_3_SHIFT               (6U)
#define MBIST_ALG1_PAUSE_3(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_3_SHIFT)) & MBIST_ALG1_PAUSE_3_MASK)
#define MBIST_ALG1_PAUSE_4_MASK                (0x80U)
#define MBIST_ALG1_PAUSE_4_SHIFT               (7U)
#define MBIST_ALG1_PAUSE_4(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_4_SHIFT)) & MBIST_ALG1_PAUSE_4_MASK)
#define MBIST_ALG1_PAUSE_5_MASK                (0x100U)
#define MBIST_ALG1_PAUSE_5_SHIFT               (8U)
#define MBIST_ALG1_PAUSE_5(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_5_SHIFT)) & MBIST_ALG1_PAUSE_5_MASK)
#define MBIST_ALG1_PAUSE_6_MASK                (0x200U)
#define MBIST_ALG1_PAUSE_6_SHIFT               (9U)
#define MBIST_ALG1_PAUSE_6(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_6_SHIFT)) & MBIST_ALG1_PAUSE_6_MASK)
#define MBIST_ALG1_PAUSE_7_MASK                (0x400U)
#define MBIST_ALG1_PAUSE_7_SHIFT               (10U)
#define MBIST_ALG1_PAUSE_7(x)                  (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_PAUSE_7_SHIFT)) & MBIST_ALG1_PAUSE_7_MASK)
#define MBIST_ALG1_MP_REP_MASK                 (0xF800U)
#define MBIST_ALG1_MP_REP_SHIFT                (11U)
#define MBIST_ALG1_MP_REP(x)                   (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_MP_REP_SHIFT)) & MBIST_ALG1_MP_REP_MASK)
#define MBIST_ALG1_ALGSEL_MASK                 (0x1F0000U)
#define MBIST_ALG1_ALGSEL_SHIFT                (16U)
#define MBIST_ALG1_ALGSEL(x)                   (((uint16_t)(((uint16_t)(x)) << MBIST_ALG1_ALGSEL_SHIFT)) & MBIST_ALG1_ALGSEL_MASK)
/*! @} */

/*! @name ALG2 - Algorithm Reg2 */
/*! @{ */
#define MBIST_ALG2_ME0_D_MASK                  (0x1U)
#define MBIST_ALG2_ME0_D_SHIFT                 (0U)
/*! ME0_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG2_ME0_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_D_SHIFT)) & MBIST_ALG2_ME0_D_MASK)
#define MBIST_ALG2_ME0_VMP_MASK                (0xEU)
#define MBIST_ALG2_ME0_VMP_SHIFT               (1U)
/*! ME0_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG2_ME0_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_VMP_SHIFT)) & MBIST_ALG2_ME0_VMP_MASK)
#define MBIST_ALG2_ME0_MP0_MASK                (0x30U)
#define MBIST_ALG2_ME0_MP0_SHIFT               (4U)
/*! ME0_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME0_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_MP0_SHIFT)) & MBIST_ALG2_ME0_MP0_MASK)
#define MBIST_ALG2_ME0_MP1_MASK                (0xC0U)
#define MBIST_ALG2_ME0_MP1_SHIFT               (6U)
/*! ME0_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME0_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_MP1_SHIFT)) & MBIST_ALG2_ME0_MP1_MASK)
#define MBIST_ALG2_ME0_MP2_MASK                (0x300U)
#define MBIST_ALG2_ME0_MP2_SHIFT               (8U)
/*! ME0_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME0_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_MP2_SHIFT)) & MBIST_ALG2_ME0_MP2_MASK)
#define MBIST_ALG2_ME0_MP3_MASK                (0xC00U)
#define MBIST_ALG2_ME0_MP3_SHIFT               (10U)
/*! ME0_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME0_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_MP3_SHIFT)) & MBIST_ALG2_ME0_MP3_MASK)
#define MBIST_ALG2_ME0_MP4_MASK                (0x3000U)
#define MBIST_ALG2_ME0_MP4_SHIFT               (12U)
/*! ME0_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME0_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_MP4_SHIFT)) & MBIST_ALG2_ME0_MP4_MASK)
#define MBIST_ALG2_ME0_MP5_MASK                (0xC000U)
#define MBIST_ALG2_ME0_MP5_SHIFT               (14U)
/*! ME0_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME0_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME0_MP5_SHIFT)) & MBIST_ALG2_ME0_MP5_MASK)
#define MBIST_ALG2_ME1_D_MASK                  (0x10000U)
#define MBIST_ALG2_ME1_D_SHIFT                 (16U)
/*! ME1_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG2_ME1_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_D_SHIFT)) & MBIST_ALG2_ME1_D_MASK)
#define MBIST_ALG2_ME1_VMP_MASK                (0xE0000U)
#define MBIST_ALG2_ME1_VMP_SHIFT               (17U)
/*! ME1_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG2_ME1_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_VMP_SHIFT)) & MBIST_ALG2_ME1_VMP_MASK)
#define MBIST_ALG2_ME1_MP0_MASK                (0x300000U)
#define MBIST_ALG2_ME1_MP0_SHIFT               (20U)
/*! ME1_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME1_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_MP0_SHIFT)) & MBIST_ALG2_ME1_MP0_MASK)
#define MBIST_ALG2_ME1_MP1_MASK                (0xC00000U)
#define MBIST_ALG2_ME1_MP1_SHIFT               (22U)
/*! ME1_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME1_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_MP1_SHIFT)) & MBIST_ALG2_ME1_MP1_MASK)
#define MBIST_ALG2_ME1_MP2_MASK                (0x3000000U)
#define MBIST_ALG2_ME1_MP2_SHIFT               (24U)
/*! ME1_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME1_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_MP2_SHIFT)) & MBIST_ALG2_ME1_MP2_MASK)
#define MBIST_ALG2_ME1_MP3_MASK                (0xC000000U)
#define MBIST_ALG2_ME1_MP3_SHIFT               (26U)
/*! ME1_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME1_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_MP3_SHIFT)) & MBIST_ALG2_ME1_MP3_MASK)
#define MBIST_ALG2_ME1_MP4_MASK                (0x30000000U)
#define MBIST_ALG2_ME1_MP4_SHIFT               (28U)
/*! ME1_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME1_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_MP4_SHIFT)) & MBIST_ALG2_ME1_MP4_MASK)
#define MBIST_ALG2_ME1_MP5_MASK                (0xC0000000U)
#define MBIST_ALG2_ME1_MP5_SHIFT               (30U)
/*! ME1_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG2_ME1_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG2_ME1_MP5_SHIFT)) & MBIST_ALG2_ME1_MP5_MASK)
/*! @} */

/*! @name ALG3 - Algorithm Reg3 */
/*! @{ */
#define MBIST_ALG3_ME2_D_MASK                  (0x1U)
#define MBIST_ALG3_ME2_D_SHIFT                 (0U)
/*! ME2_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG3_ME2_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_D_SHIFT)) & MBIST_ALG3_ME2_D_MASK)
#define MBIST_ALG3_ME2_VMP_MASK                (0xEU)
#define MBIST_ALG3_ME2_VMP_SHIFT               (1U)
/*! ME2_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG3_ME2_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_VMP_SHIFT)) & MBIST_ALG3_ME2_VMP_MASK)
#define MBIST_ALG3_ME2_MP0_MASK                (0x30U)
#define MBIST_ALG3_ME2_MP0_SHIFT               (4U)
/*! ME2_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME2_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_MP0_SHIFT)) & MBIST_ALG3_ME2_MP0_MASK)
#define MBIST_ALG3_ME2_MP1_MASK                (0xC0U)
#define MBIST_ALG3_ME2_MP1_SHIFT               (6U)
/*! ME2_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME2_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_MP1_SHIFT)) & MBIST_ALG3_ME2_MP1_MASK)
#define MBIST_ALG3_ME2_MP2_MASK                (0x300U)
#define MBIST_ALG3_ME2_MP2_SHIFT               (8U)
/*! ME2_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME2_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_MP2_SHIFT)) & MBIST_ALG3_ME2_MP2_MASK)
#define MBIST_ALG3_ME2_MP3_MASK                (0xC00U)
#define MBIST_ALG3_ME2_MP3_SHIFT               (10U)
/*! ME2_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME2_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_MP3_SHIFT)) & MBIST_ALG3_ME2_MP3_MASK)
#define MBIST_ALG3_ME2_MP4_MASK                (0x3000U)
#define MBIST_ALG3_ME2_MP4_SHIFT               (12U)
/*! ME2_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME2_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_MP4_SHIFT)) & MBIST_ALG3_ME2_MP4_MASK)
#define MBIST_ALG3_ME2_MP5_MASK                (0xC000U)
#define MBIST_ALG3_ME2_MP5_SHIFT               (14U)
/*! ME2_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME2_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME2_MP5_SHIFT)) & MBIST_ALG3_ME2_MP5_MASK)
#define MBIST_ALG3_ME3_D_MASK                  (0x10000U)
#define MBIST_ALG3_ME3_D_SHIFT                 (16U)
/*! ME3_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG3_ME3_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_D_SHIFT)) & MBIST_ALG3_ME3_D_MASK)
#define MBIST_ALG3_ME3_VMP_MASK                (0xE0000U)
#define MBIST_ALG3_ME3_VMP_SHIFT               (17U)
/*! ME3_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG3_ME3_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_VMP_SHIFT)) & MBIST_ALG3_ME3_VMP_MASK)
#define MBIST_ALG3_ME3_MP0_MASK                (0x300000U)
#define MBIST_ALG3_ME3_MP0_SHIFT               (20U)
/*! ME3_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME3_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_MP0_SHIFT)) & MBIST_ALG3_ME3_MP0_MASK)
#define MBIST_ALG3_ME3_MP1_MASK                (0xC00000U)
#define MBIST_ALG3_ME3_MP1_SHIFT               (22U)
/*! ME3_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME3_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_MP1_SHIFT)) & MBIST_ALG3_ME3_MP1_MASK)
#define MBIST_ALG3_ME3_MP2_MASK                (0x3000000U)
#define MBIST_ALG3_ME3_MP2_SHIFT               (24U)
/*! ME3_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME3_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_MP2_SHIFT)) & MBIST_ALG3_ME3_MP2_MASK)
#define MBIST_ALG3_ME3_MP3_MASK                (0xC000000U)
#define MBIST_ALG3_ME3_MP3_SHIFT               (26U)
/*! ME3_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME3_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_MP3_SHIFT)) & MBIST_ALG3_ME3_MP3_MASK)
#define MBIST_ALG3_ME3_MP4_MASK                (0x30000000U)
#define MBIST_ALG3_ME3_MP4_SHIFT               (28U)
/*! ME3_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME3_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_MP4_SHIFT)) & MBIST_ALG3_ME3_MP4_MASK)
#define MBIST_ALG3_ME3_MP5_MASK                (0xC0000000U)
#define MBIST_ALG3_ME3_MP5_SHIFT               (30U)
/*! ME3_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG3_ME3_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG3_ME3_MP5_SHIFT)) & MBIST_ALG3_ME3_MP5_MASK)
/*! @} */

/*! @name ALG4 - Algorithm Reg4 */
/*! @{ */
#define MBIST_ALG4_ME4_D_MASK                  (0x1U)
#define MBIST_ALG4_ME4_D_SHIFT                 (0U)
/*! ME4_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG4_ME4_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_D_SHIFT)) & MBIST_ALG4_ME4_D_MASK)
#define MBIST_ALG4_ME4_VMP_MASK                (0xEU)
#define MBIST_ALG4_ME4_VMP_SHIFT               (1U)
/*! ME4_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG4_ME4_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_VMP_SHIFT)) & MBIST_ALG4_ME4_VMP_MASK)
#define MBIST_ALG4_ME4_MP0_MASK                (0x30U)
#define MBIST_ALG4_ME4_MP0_SHIFT               (4U)
/*! ME4_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME4_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_MP0_SHIFT)) & MBIST_ALG4_ME4_MP0_MASK)
#define MBIST_ALG4_ME4_MP1_MASK                (0xC0U)
#define MBIST_ALG4_ME4_MP1_SHIFT               (6U)
/*! ME4_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME4_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_MP1_SHIFT)) & MBIST_ALG4_ME4_MP1_MASK)
#define MBIST_ALG4_ME4_MP2_MASK                (0x300U)
#define MBIST_ALG4_ME4_MP2_SHIFT               (8U)
/*! ME4_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME4_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_MP2_SHIFT)) & MBIST_ALG4_ME4_MP2_MASK)
#define MBIST_ALG4_ME4_MP3_MASK                (0xC00U)
#define MBIST_ALG4_ME4_MP3_SHIFT               (10U)
/*! ME4_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME4_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_MP3_SHIFT)) & MBIST_ALG4_ME4_MP3_MASK)
#define MBIST_ALG4_ME4_MP4_MASK                (0x3000U)
#define MBIST_ALG4_ME4_MP4_SHIFT               (12U)
/*! ME4_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME4_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_MP4_SHIFT)) & MBIST_ALG4_ME4_MP4_MASK)
#define MBIST_ALG4_ME4_MP5_MASK                (0xC000U)
#define MBIST_ALG4_ME4_MP5_SHIFT               (14U)
/*! ME4_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME4_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME4_MP5_SHIFT)) & MBIST_ALG4_ME4_MP5_MASK)
#define MBIST_ALG4_ME5_D_MASK                  (0x10000U)
#define MBIST_ALG4_ME5_D_SHIFT                 (16U)
/*! ME5_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG4_ME5_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_D_SHIFT)) & MBIST_ALG4_ME5_D_MASK)
#define MBIST_ALG4_ME5_VMP_MASK                (0xE0000U)
#define MBIST_ALG4_ME5_VMP_SHIFT               (17U)
/*! ME5_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG4_ME5_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_VMP_SHIFT)) & MBIST_ALG4_ME5_VMP_MASK)
#define MBIST_ALG4_ME5_MP0_MASK                (0x300000U)
#define MBIST_ALG4_ME5_MP0_SHIFT               (20U)
/*! ME5_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME5_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_MP0_SHIFT)) & MBIST_ALG4_ME5_MP0_MASK)
#define MBIST_ALG4_ME5_MP1_MASK                (0xC00000U)
#define MBIST_ALG4_ME5_MP1_SHIFT               (22U)
/*! ME5_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME5_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_MP1_SHIFT)) & MBIST_ALG4_ME5_MP1_MASK)
#define MBIST_ALG4_ME5_MP2_MASK                (0x3000000U)
#define MBIST_ALG4_ME5_MP2_SHIFT               (24U)
/*! ME5_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME5_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_MP2_SHIFT)) & MBIST_ALG4_ME5_MP2_MASK)
#define MBIST_ALG4_ME5_MP3_MASK                (0xC000000U)
#define MBIST_ALG4_ME5_MP3_SHIFT               (26U)
/*! ME5_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME5_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_MP3_SHIFT)) & MBIST_ALG4_ME5_MP3_MASK)
#define MBIST_ALG4_ME5_MP4_MASK                (0x30000000U)
#define MBIST_ALG4_ME5_MP4_SHIFT               (28U)
/*! ME5_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME5_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_MP4_SHIFT)) & MBIST_ALG4_ME5_MP4_MASK)
#define MBIST_ALG4_ME5_MP5_MASK                (0xC0000000U)
#define MBIST_ALG4_ME5_MP5_SHIFT               (30U)
/*! ME5_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG4_ME5_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG4_ME5_MP5_SHIFT)) & MBIST_ALG4_ME5_MP5_MASK)
/*! @} */

/*! @name ALG5 - Algorithm Reg5 */
/*! @{ */
#define MBIST_ALG5_ME6_D_MASK                  (0x1U)
#define MBIST_ALG5_ME6_D_SHIFT                 (0U)
/*! ME6_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG5_ME6_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_D_SHIFT)) & MBIST_ALG5_ME6_D_MASK)
#define MBIST_ALG5_ME6_VMP_MASK                (0xEU)
#define MBIST_ALG5_ME6_VMP_SHIFT               (1U)
/*! ME6_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG5_ME6_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_VMP_SHIFT)) & MBIST_ALG5_ME6_VMP_MASK)
#define MBIST_ALG5_ME6_MP0_MASK                (0x30U)
#define MBIST_ALG5_ME6_MP0_SHIFT               (4U)
/*! ME6_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME6_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_MP0_SHIFT)) & MBIST_ALG5_ME6_MP0_MASK)
#define MBIST_ALG5_ME6_MP1_MASK                (0xC0U)
#define MBIST_ALG5_ME6_MP1_SHIFT               (6U)
/*! ME6_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME6_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_MP1_SHIFT)) & MBIST_ALG5_ME6_MP1_MASK)
#define MBIST_ALG5_ME6_MP2_MASK                (0x300U)
#define MBIST_ALG5_ME6_MP2_SHIFT               (8U)
/*! ME6_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME6_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_MP2_SHIFT)) & MBIST_ALG5_ME6_MP2_MASK)
#define MBIST_ALG5_ME6_MP3_MASK                (0xC00U)
#define MBIST_ALG5_ME6_MP3_SHIFT               (10U)
/*! ME6_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME6_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_MP3_SHIFT)) & MBIST_ALG5_ME6_MP3_MASK)
#define MBIST_ALG5_ME6_MP4_MASK                (0x3000U)
#define MBIST_ALG5_ME6_MP4_SHIFT               (12U)
/*! ME6_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME6_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_MP4_SHIFT)) & MBIST_ALG5_ME6_MP4_MASK)
#define MBIST_ALG5_ME6_MP5_MASK                (0xC000U)
#define MBIST_ALG5_ME6_MP5_SHIFT               (14U)
/*! ME6_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME6_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME6_MP5_SHIFT)) & MBIST_ALG5_ME6_MP5_MASK)
#define MBIST_ALG5_ME7_D_MASK                  (0x10000U)
#define MBIST_ALG5_ME7_D_SHIFT                 (16U)
/*! ME7_D - Address Direction
 *  0b0..Address generator is decremented from ENDA to STARTA.
 *  0b1..Address generator is incremented from STARTA to ENDA.
 */
#define MBIST_ALG5_ME7_D(x)                    (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_D_SHIFT)) & MBIST_ALG5_ME7_D_MASK)
#define MBIST_ALG5_ME7_VMP_MASK                (0xE0000U)
#define MBIST_ALG5_ME7_VMP_SHIFT               (17U)
/*! ME7_VMP - Valid March Phases
 *  0b000..MP0
 *  0b001..MP0 through MP1
 *  0b010..MP0 through MP2
 *  0b011..MP0 through MP3
 *  0b100..MP0 through MP4
 *  0b101..MP0 through MP5
 *  0b110..Illegal value
 *  0b111..March Phase Replication
 */
#define MBIST_ALG5_ME7_VMP(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_VMP_SHIFT)) & MBIST_ALG5_ME7_VMP_MASK)
#define MBIST_ALG5_ME7_MP0_MASK                (0x300000U)
#define MBIST_ALG5_ME7_MP0_SHIFT               (20U)
/*! ME7_MP0 - March Phase 0
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME7_MP0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_MP0_SHIFT)) & MBIST_ALG5_ME7_MP0_MASK)
#define MBIST_ALG5_ME7_MP1_MASK                (0xC00000U)
#define MBIST_ALG5_ME7_MP1_SHIFT               (22U)
/*! ME7_MP1 - March Phase 1
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME7_MP1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_MP1_SHIFT)) & MBIST_ALG5_ME7_MP1_MASK)
#define MBIST_ALG5_ME7_MP2_MASK                (0x3000000U)
#define MBIST_ALG5_ME7_MP2_SHIFT               (24U)
/*! ME7_MP2 - March Phase 2
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME7_MP2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_MP2_SHIFT)) & MBIST_ALG5_ME7_MP2_MASK)
#define MBIST_ALG5_ME7_MP3_MASK                (0xC000000U)
#define MBIST_ALG5_ME7_MP3_SHIFT               (26U)
/*! ME7_MP3 - March Phase 3
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME7_MP3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_MP3_SHIFT)) & MBIST_ALG5_ME7_MP3_MASK)
#define MBIST_ALG5_ME7_MP4_MASK                (0x30000000U)
#define MBIST_ALG5_ME7_MP4_SHIFT               (28U)
/*! ME7_MP4 - March Phase 4
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME7_MP4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_MP4_SHIFT)) & MBIST_ALG5_ME7_MP4_MASK)
#define MBIST_ALG5_ME7_MP5_MASK                (0xC0000000U)
#define MBIST_ALG5_ME7_MP5_SHIFT               (30U)
/*! ME7_MP5 - March Phase 5
 *  0b00..R0 - Read data background.
 *  0b01..R1 - Read inverted data background.
 *  0b10..W0 - Write data background.
 *  0b11..W1 -Write inverted data background.
 */
#define MBIST_ALG5_ME7_MP5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_ALG5_ME7_MP5_SHIFT)) & MBIST_ALG5_ME7_MP5_MASK)
/*! @} */

/*! @name BGCR - Background Configuration */
/*! @{ */
#define MBIST_BGCR_DB0_MASK                    (0x1U)
#define MBIST_BGCR_DB0_SHIFT                   (0U)
/*! DB0 - Data Background 0
 *  0b0..No checkerboard data background will be used.
 *  0b1..The checkerboard data background will be used.
 */
#define MBIST_BGCR_DB0(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB0_SHIFT)) & MBIST_BGCR_DB0_MASK)
#define MBIST_BGCR_DB1_MASK                    (0x2U)
#define MBIST_BGCR_DB1_SHIFT                   (1U)
/*! DB1 - Data Background 1
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB1(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB1_SHIFT)) & MBIST_BGCR_DB1_MASK)
#define MBIST_BGCR_DB2_MASK                    (0x4U)
#define MBIST_BGCR_DB2_SHIFT                   (2U)
/*! DB2 - Data Background 2
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB2(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB2_SHIFT)) & MBIST_BGCR_DB2_MASK)
#define MBIST_BGCR_DB3_MASK                    (0x8U)
#define MBIST_BGCR_DB3_SHIFT                   (3U)
/*! DB3 - Data Background 3
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB3(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB3_SHIFT)) & MBIST_BGCR_DB3_MASK)
#define MBIST_BGCR_DB4_MASK                    (0x10U)
#define MBIST_BGCR_DB4_SHIFT                   (4U)
/*! DB4 - Data Background 4
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB4(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB4_SHIFT)) & MBIST_BGCR_DB4_MASK)
#define MBIST_BGCR_DB5_MASK                    (0x20U)
#define MBIST_BGCR_DB5_SHIFT                   (5U)
/*! DB5 - Data Background 5
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB5(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB5_SHIFT)) & MBIST_BGCR_DB5_MASK)
#define MBIST_BGCR_DB6_MASK                    (0x40U)
#define MBIST_BGCR_DB6_SHIFT                   (6U)
/*! DB6 - Data Background 6
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB6(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB6_SHIFT)) & MBIST_BGCR_DB6_MASK)
#define MBIST_BGCR_DB7_MASK                    (0x80U)
#define MBIST_BGCR_DB7_SHIFT                   (7U)
/*! DB7 - Data Background 7
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB7(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB7_SHIFT)) & MBIST_BGCR_DB7_MASK)
#define MBIST_BGCR_DB8_MASK                    (0x100U)
#define MBIST_BGCR_DB8_SHIFT                   (8U)
/*! DB8 - Data Background 8
 *  0b0..This data background will not be used
 *  0b1..This data background will be used
 */
#define MBIST_BGCR_DB8(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_BGCR_DB8_SHIFT)) & MBIST_BGCR_DB8_MASK)
/*! @} */

/*! @name MSEL - Memory Selection 1 */
/*! @{ */
#define MBIST_MSEL_MSEL0_MASK                  (0x1U)
#define MBIST_MSEL_MSEL0_SHIFT                 (0U)
/*! MSEL0 - Memory Selection 0
 *  0b0..Ram 0 is not selected for the test.
 *  0b1..Ram 0 is selected for the test.
 */
#define MBIST_MSEL_MSEL0(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL0_SHIFT)) & MBIST_MSEL_MSEL0_MASK)
#define MBIST_MSEL_MSEL1_MASK                  (0x2U)
#define MBIST_MSEL_MSEL1_SHIFT                 (1U)
/*! MSEL1 - Memory Selection 1
 *  0b0..Ram 1 is not selected for the test.
 *  0b1..Ram 1 is selected for the test.
 */
#define MBIST_MSEL_MSEL1(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL1_SHIFT)) & MBIST_MSEL_MSEL1_MASK)
#define MBIST_MSEL_MSEL2_MASK                  (0x4U)
#define MBIST_MSEL_MSEL2_SHIFT                 (2U)
/*! MSEL2 - Memory Selection 2
 *  0b0..Ram 2 is not selected for the test.
 *  0b1..Ram 2 is selected for the test.
 */
#define MBIST_MSEL_MSEL2(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL2_SHIFT)) & MBIST_MSEL_MSEL2_MASK)
#define MBIST_MSEL_MSEL3_MASK                  (0x8U)
#define MBIST_MSEL_MSEL3_SHIFT                 (3U)
/*! MSEL3 - Memory Selection 3
 *  0b0..Ram 3 is not selected for the test.
 *  0b1..Ram 3 is selected for the test.
 */
#define MBIST_MSEL_MSEL3(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL3_SHIFT)) & MBIST_MSEL_MSEL3_MASK)
#define MBIST_MSEL_MSEL4_MASK                  (0x10U)
#define MBIST_MSEL_MSEL4_SHIFT                 (4U)
/*! MSEL4 - Memory Selection 4
 *  0b0..Ram 4 is not selected for the test.
 *  0b1..Ram 4 is selected for the test.
 */
#define MBIST_MSEL_MSEL4(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL4_SHIFT)) & MBIST_MSEL_MSEL4_MASK)
#define MBIST_MSEL_MSEL5_MASK                  (0x20U)
#define MBIST_MSEL_MSEL5_SHIFT                 (5U)
/*! MSEL5 - Memory Selection 5
 *  0b0..Ram 5 is not selected for the test.
 *  0b1..Ram 5 is selected for the test.
 */
#define MBIST_MSEL_MSEL5(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL5_SHIFT)) & MBIST_MSEL_MSEL5_MASK)
#define MBIST_MSEL_MSEL6_MASK                  (0x40U)
#define MBIST_MSEL_MSEL6_SHIFT                 (6U)
/*! MSEL6 - Memory Selection 6
 *  0b0..Ram 6 is not selected for the test.
 *  0b1..Ram 6 is selected for the test.
 */
#define MBIST_MSEL_MSEL6(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL6_SHIFT)) & MBIST_MSEL_MSEL6_MASK)
#define MBIST_MSEL_MSEL7_MASK                  (0x80U)
#define MBIST_MSEL_MSEL7_SHIFT                 (7U)
/*! MSEL7 - Memory Selection 7
 *  0b0..Ram 7 is not selected for the test.
 *  0b1..Ram 7 is selected for the test.
 */
#define MBIST_MSEL_MSEL7(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL7_SHIFT)) & MBIST_MSEL_MSEL7_MASK)
#define MBIST_MSEL_MSEL8_MASK                  (0x100U)
#define MBIST_MSEL_MSEL8_SHIFT                 (8U)
/*! MSEL8 - Memory Selection 8
 *  0b0..Ram 8 is not selected for the test.
 *  0b1..Ram 8 is selected for the test.
 */
#define MBIST_MSEL_MSEL8(x)                    (((uint8_t)(((uint8_t)(x)) << MBIST_MSEL_MSEL8_SHIFT)) & MBIST_MSEL_MSEL8_MASK)
/*! @} */

/*! @name UDPR - User Defined Port Control */
/*! @{ */
#define MBIST_UDPR_UDPR0_MASK                  (0x1U)
#define MBIST_UDPR_UDPR0_SHIFT                 (0U)
#define MBIST_UDPR_UDPR0(x)                    (((uint16_t)(((uint16_t)(x)) << MBIST_UDPR_UDPR0_SHIFT)) & MBIST_UDPR_UDPR0_MASK)
#define MBIST_UDPR_UDPR1_MASK                  (0x2U)
#define MBIST_UDPR_UDPR1_SHIFT                 (1U)
#define MBIST_UDPR_UDPR1(x)                    (((uint16_t)(((uint16_t)(x)) << MBIST_UDPR_UDPR1_SHIFT)) & MBIST_UDPR_UDPR1_MASK)
#define MBIST_UDPR_UDPR12_MASK                 (0x1000U)
#define MBIST_UDPR_UDPR12_SHIFT                (12U)
#define MBIST_UDPR_UDPR12(x)                   (((uint16_t)(((uint16_t)(x)) << MBIST_UDPR_UDPR12_SHIFT)) & MBIST_UDPR_UDPR12_MASK)
/*! @} */

/*! @name BSTART - BIST Start */
/*! @{ */
#define MBIST_BSTART_BSTART_MASK               (0x3U)
#define MBIST_BSTART_BSTART_SHIFT              (0U)
/*! BSTART - Start Command
 *  0b00..No Operation
 */
#define MBIST_BSTART_BSTART(x)                 (((uint8_t)(((uint8_t)(x)) << MBIST_BSTART_BSTART_SHIFT)) & MBIST_BSTART_BSTART_MASK)
#define MBIST_BSTART_DEAD_MASK                 (0x10U)
#define MBIST_BSTART_DEAD_SHIFT                (4U)
#define MBIST_BSTART_DEAD(x)                   (((uint8_t)(((uint8_t)(x)) << MBIST_BSTART_DEAD_SHIFT)) & MBIST_BSTART_DEAD_MASK)
#define MBIST_BSTART_LOOP_MASK                 (0xF00U)
#define MBIST_BSTART_LOOP_SHIFT                (8U)
#define MBIST_BSTART_LOOP(x)                   (((uint8_t)(((uint8_t)(x)) << MBIST_BSTART_LOOP_SHIFT)) & MBIST_BSTART_LOOP_MASK)
/*! @} */

/*! @name BRST - BIST Reset */
/*! @{ */
#define MBIST_BRST_BRST_MASK                   (0x1U)
#define MBIST_BRST_BRST_SHIFT                  (0U)
/*! BRST - Bist Soft Reset
 *  0b1..FSLBIST3/ARMport general soft reset.
 */
#define MBIST_BRST_BRST(x)                     (((uint8_t)(((uint8_t)(x)) << MBIST_BRST_BRST_SHIFT)) & MBIST_BRST_BRST_MASK)
#define MBIST_BRST_SRST_MASK                   (0x2U)
#define MBIST_BRST_SRST_SHIFT                  (1U)
/*! SRST - Bist Status Reset
 *  0b1..FSLBIST3/ARMport Status reset. This resets: DSMs; BSMs; ipt_bist_status.
 */
#define MBIST_BRST_SRST(x)                     (((uint8_t)(((uint8_t)(x)) << MBIST_BRST_SRST_SHIFT)) & MBIST_BRST_SRST_MASK)
/*! @} */

/*! @name SKIP - Programmable Skip Counter */
/*! @{ */
#define MBIST_SKIP_SCOUNTER_MASK               (0xFFFFU)
#define MBIST_SKIP_SCOUNTER_SHIFT              (0U)
#define MBIST_SKIP_SCOUNTER(x)                 (((uint16_t)(((uint16_t)(x)) << MBIST_SKIP_SCOUNTER_SHIFT)) & MBIST_SKIP_SCOUNTER_MASK)
/*! @} */

/*! @name BSTAT - BIST Status */
/*! @{ */
#define MBIST_BSTAT_BSTAT_1_0_MASK             (0x3U)
#define MBIST_BSTAT_BSTAT_1_0_SHIFT            (0U)
/*! BSTAT_1_0 - Bist Status 1 .. 0
 *  0b00..Bist has never ran (after reset state).
 *  0b01..Bist is busy running a test.
 *  0b10..Finished test with no unrepairable fails.
 *  0b11..Finished test with unrepairable fails.
 */
#define MBIST_BSTAT_BSTAT_1_0(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BSTAT_BSTAT_1_0_SHIFT)) & MBIST_BSTAT_BSTAT_1_0_MASK)
#define MBIST_BSTAT_BSTAT_2_MASK               (0x4U)
#define MBIST_BSTAT_BSTAT_2_SHIFT              (2U)
/*! BSTAT_2 - Bist Status 2
 *  0b0..No error has been detected.
 *  0b1..At least one error has been detected.
 */
#define MBIST_BSTAT_BSTAT_2(x)                 (((uint8_t)(((uint8_t)(x)) << MBIST_BSTAT_BSTAT_2_SHIFT)) & MBIST_BSTAT_BSTAT_2_MASK)
#define MBIST_BSTAT_BSTAT_3_MASK               (0x8U)
#define MBIST_BSTAT_BSTAT_3_SHIFT              (3U)
/*! BSTAT_3 - Bist Status 3
 *  0b0..Bist is not on SOF or it is running.
 *  0b1..Bist has stopped.
 */
#define MBIST_BSTAT_BSTAT_3(x)                 (((uint8_t)(((uint8_t)(x)) << MBIST_BSTAT_BSTAT_3_SHIFT)) & MBIST_BSTAT_BSTAT_3_MASK)
#define MBIST_BSTAT_HOLD_ERR_MASK              (0x20U)
#define MBIST_BSTAT_HOLD_ERR_SHIFT             (5U)
/*! HOLD_ERR - Read Hold Error
 *  0b0..No data stability error was found.
 *  0b1..At least one data stability error was found.
 */
#define MBIST_BSTAT_HOLD_ERR(x)                (((uint8_t)(((uint8_t)(x)) << MBIST_BSTAT_HOLD_ERR_SHIFT)) & MBIST_BSTAT_HOLD_ERR_MASK)
/*! @} */

/*! @name FPM - BIST Fail Per Memory 1 */
/*! @{ */
#define MBIST_FPM_FPM0_MASK                    (0x1U)
#define MBIST_FPM_FPM0_SHIFT                   (0U)
/*! FPM0 - Fail on Memory 0
 *  0b0..Memory 0 passed the test.
 *  0b1..Memory 0 failed the test.
 */
#define MBIST_FPM_FPM0(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM0_SHIFT)) & MBIST_FPM_FPM0_MASK)
#define MBIST_FPM_FPM1_MASK                    (0x2U)
#define MBIST_FPM_FPM1_SHIFT                   (1U)
/*! FPM1 - Fail on Memory 1
 *  0b0..Memory 1 passed the test.
 *  0b1..Memory 1 failed the test.
 */
#define MBIST_FPM_FPM1(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM1_SHIFT)) & MBIST_FPM_FPM1_MASK)
#define MBIST_FPM_FPM2_MASK                    (0x4U)
#define MBIST_FPM_FPM2_SHIFT                   (2U)
/*! FPM2 - Fail on Memory 2
 *  0b0..Memory 2 passed the test.
 *  0b1..Memory 2 failed the test.
 */
#define MBIST_FPM_FPM2(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM2_SHIFT)) & MBIST_FPM_FPM2_MASK)
#define MBIST_FPM_FPM3_MASK                    (0x8U)
#define MBIST_FPM_FPM3_SHIFT                   (3U)
/*! FPM3 - Fail on Memory 3
 *  0b0..Memory 3 passed the test.
 *  0b1..Memory 3 failed the test.
 */
#define MBIST_FPM_FPM3(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM3_SHIFT)) & MBIST_FPM_FPM3_MASK)
#define MBIST_FPM_FPM4_MASK                    (0x10U)
#define MBIST_FPM_FPM4_SHIFT                   (4U)
/*! FPM4 - Fail on Memory 4
 *  0b0..Memory 4 passed the test.
 *  0b1..Memory 4 failed the test.
 */
#define MBIST_FPM_FPM4(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM4_SHIFT)) & MBIST_FPM_FPM4_MASK)
#define MBIST_FPM_FPM5_MASK                    (0x20U)
#define MBIST_FPM_FPM5_SHIFT                   (5U)
/*! FPM5 - Fail on Memory 5
 *  0b0..Memory 5 passed the test.
 *  0b1..Memory 5 failed the test.
 */
#define MBIST_FPM_FPM5(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM5_SHIFT)) & MBIST_FPM_FPM5_MASK)
#define MBIST_FPM_FPM6_MASK                    (0x40U)
#define MBIST_FPM_FPM6_SHIFT                   (6U)
/*! FPM6 - Fail on Memory 6
 *  0b0..Memory 6 passed the test.
 *  0b1..Memory 6 failed the test.
 */
#define MBIST_FPM_FPM6(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM6_SHIFT)) & MBIST_FPM_FPM6_MASK)
#define MBIST_FPM_FPM7_MASK                    (0x80U)
#define MBIST_FPM_FPM7_SHIFT                   (7U)
/*! FPM7 - Fail on Memory 7
 *  0b0..Memory 7 passed the test.
 *  0b1..Memory 7 failed the test.
 */
#define MBIST_FPM_FPM7(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM7_SHIFT)) & MBIST_FPM_FPM7_MASK)
#define MBIST_FPM_FPM8_MASK                    (0x100U)
#define MBIST_FPM_FPM8_SHIFT                   (8U)
/*! FPM8 - Fail on Memory 8
 *  0b0..Memory 8 passed the test.
 *  0b1..Memory 8 failed the test.
 */
#define MBIST_FPM_FPM8(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_FPM_FPM8_SHIFT)) & MBIST_FPM_FPM8_MASK)
/*! @} */

/*! @name BFPM - BIRA Fail Per Memory 1 */
/*! @{ */
#define MBIST_BFPM_BIRA_FAIL0_MASK             (0x1U)
#define MBIST_BFPM_BIRA_FAIL0_SHIFT            (0U)
/*! BIRA_FAIL0 - Bira Fail on Memory 0
 *  0b0..Memory 0 passed the test.
 *  0b1..Memory 0 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL0(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL0_SHIFT)) & MBIST_BFPM_BIRA_FAIL0_MASK)
#define MBIST_BFPM_BIRA_FAIL1_MASK             (0x2U)
#define MBIST_BFPM_BIRA_FAIL1_SHIFT            (1U)
/*! BIRA_FAIL1 - Bira Fail on Memory 1
 *  0b0..Memory 1 passed the test.
 *  0b1..Memory 1 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL1(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL1_SHIFT)) & MBIST_BFPM_BIRA_FAIL1_MASK)
#define MBIST_BFPM_BIRA_FAIL2_MASK             (0x4U)
#define MBIST_BFPM_BIRA_FAIL2_SHIFT            (2U)
/*! BIRA_FAIL2 - Bira Fail on Memory 2
 *  0b0..Memory 2 passed the test.
 *  0b1..Memory 2 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL2(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL2_SHIFT)) & MBIST_BFPM_BIRA_FAIL2_MASK)
#define MBIST_BFPM_BIRA_FAIL3_MASK             (0x8U)
#define MBIST_BFPM_BIRA_FAIL3_SHIFT            (3U)
/*! BIRA_FAIL3 - Bira Fail on Memory 3
 *  0b0..Memory 3 passed the test.
 *  0b1..Memory 3 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL3(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL3_SHIFT)) & MBIST_BFPM_BIRA_FAIL3_MASK)
#define MBIST_BFPM_BIRA_FAIL4_MASK             (0x10U)
#define MBIST_BFPM_BIRA_FAIL4_SHIFT            (4U)
/*! BIRA_FAIL4 - Bira Fail on Memory 4
 *  0b0..Memory 4 passed the test.
 *  0b1..Memory 4 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL4(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL4_SHIFT)) & MBIST_BFPM_BIRA_FAIL4_MASK)
#define MBIST_BFPM_BIRA_FAIL5_MASK             (0x20U)
#define MBIST_BFPM_BIRA_FAIL5_SHIFT            (5U)
/*! BIRA_FAIL5 - Bira Fail on Memory 5
 *  0b0..Memory 5 passed the test.
 *  0b1..Memory 5 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL5(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL5_SHIFT)) & MBIST_BFPM_BIRA_FAIL5_MASK)
#define MBIST_BFPM_BIRA_FAIL6_MASK             (0x40U)
#define MBIST_BFPM_BIRA_FAIL6_SHIFT            (6U)
/*! BIRA_FAIL6 - Bira Fail on Memory 6
 *  0b0..Memory 6 passed the test.
 *  0b1..Memory 6 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL6(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL6_SHIFT)) & MBIST_BFPM_BIRA_FAIL6_MASK)
#define MBIST_BFPM_BIRA_FAIL7_MASK             (0x80U)
#define MBIST_BFPM_BIRA_FAIL7_SHIFT            (7U)
/*! BIRA_FAIL7 - Bira Fail on Memory 7
 *  0b0..Memory 7 passed the test.
 *  0b1..Memory 7 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL7(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL7_SHIFT)) & MBIST_BFPM_BIRA_FAIL7_MASK)
#define MBIST_BFPM_BIRA_FAIL8_MASK             (0x100U)
#define MBIST_BFPM_BIRA_FAIL8_SHIFT            (8U)
/*! BIRA_FAIL8 - Bira Fail on Memory 8
 *  0b0..Memory 8 passed the test.
 *  0b1..Memory 8 failed the test.
 */
#define MBIST_BFPM_BIRA_FAIL8(x)               (((uint8_t)(((uint8_t)(x)) << MBIST_BFPM_BIRA_FAIL8_SHIFT)) & MBIST_BFPM_BIRA_FAIL8_MASK)
/*! @} */

/*! @name FSDR - FSM State Debug Register */
/*! @{ */
#define MBIST_FSDR_OP_MASK                     (0x3U)
#define MBIST_FSDR_OP_SHIFT                    (0U)
/*! OP - Operation
 *  0b00..R0
 *  0b01..R1
 *  0b10..W0
 *  0b11..W1
 */
#define MBIST_FSDR_OP(x)                       (((uint8_t)(((uint8_t)(x)) << MBIST_FSDR_OP_SHIFT)) & MBIST_FSDR_OP_MASK)
#define MBIST_FSDR_MP_MASK                     (0x1CU)
#define MBIST_FSDR_MP_SHIFT                    (2U)
/*! MP - March Phase
 *  0b000..MP0
 *  0b001..MP1
 *  0b010..MP2
 *  0b011..MP3
 *  0b100..MP4
 *  0b101..MP5
 */
#define MBIST_FSDR_MP(x)                       (((uint8_t)(((uint8_t)(x)) << MBIST_FSDR_MP_SHIFT)) & MBIST_FSDR_MP_MASK)
#define MBIST_FSDR_ME_MASK                     (0xE0U)
#define MBIST_FSDR_ME_SHIFT                    (5U)
/*! ME - March Element
 *  0b000..ME0
 *  0b001..ME1
 *  0b010..ME2
 *  0b011..ME3
 *  0b100..ME4
 *  0b101..ME5
 *  0b110..ME6
 *  0b111..ME7
 */
#define MBIST_FSDR_ME(x)                       (((uint8_t)(((uint8_t)(x)) << MBIST_FSDR_ME_SHIFT)) & MBIST_FSDR_ME_MASK)
/*! @} */

/*! @name ADR - Address Debug Register */
/*! @{ */
#define MBIST_ADR_ADDR_MASK                    (0x7FFU)
#define MBIST_ADR_ADDR_SHIFT                   (0U)
#define MBIST_ADR_ADDR(x)                      (((uint8_t)(((uint8_t)(x)) << MBIST_ADR_ADDR_SHIFT)) & MBIST_ADR_ADDR_MASK)
/*! @} */

/*! @name DBG0 - Data Debug Register - Word 0 */
/*! @{ */
#define MBIST_DBG0_CDATA_0_MASK                (0x1U)
#define MBIST_DBG0_CDATA_0_SHIFT               (0U)
/*! CDATA_0 - Data Debug Register - Bit 0
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_0(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_0_SHIFT)) & MBIST_DBG0_CDATA_0_MASK)
#define MBIST_DBG0_CDATA_1_MASK                (0x2U)
#define MBIST_DBG0_CDATA_1_SHIFT               (1U)
/*! CDATA_1 - Data Debug Register - Bit 1
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_1(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_1_SHIFT)) & MBIST_DBG0_CDATA_1_MASK)
#define MBIST_DBG0_CDATA_2_MASK                (0x4U)
#define MBIST_DBG0_CDATA_2_SHIFT               (2U)
/*! CDATA_2 - Data Debug Register - Bit 2
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_2(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_2_SHIFT)) & MBIST_DBG0_CDATA_2_MASK)
#define MBIST_DBG0_CDATA_3_MASK                (0x8U)
#define MBIST_DBG0_CDATA_3_SHIFT               (3U)
/*! CDATA_3 - Data Debug Register - Bit 3
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_3(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_3_SHIFT)) & MBIST_DBG0_CDATA_3_MASK)
#define MBIST_DBG0_CDATA_4_MASK                (0x10U)
#define MBIST_DBG0_CDATA_4_SHIFT               (4U)
/*! CDATA_4 - Data Debug Register - Bit 4
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_4(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_4_SHIFT)) & MBIST_DBG0_CDATA_4_MASK)
#define MBIST_DBG0_CDATA_5_MASK                (0x20U)
#define MBIST_DBG0_CDATA_5_SHIFT               (5U)
/*! CDATA_5 - Data Debug Register - Bit 5
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_5(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_5_SHIFT)) & MBIST_DBG0_CDATA_5_MASK)
#define MBIST_DBG0_CDATA_6_MASK                (0x40U)
#define MBIST_DBG0_CDATA_6_SHIFT               (6U)
/*! CDATA_6 - Data Debug Register - Bit 6
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_6(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_6_SHIFT)) & MBIST_DBG0_CDATA_6_MASK)
#define MBIST_DBG0_CDATA_7_MASK                (0x80U)
#define MBIST_DBG0_CDATA_7_SHIFT               (7U)
/*! CDATA_7 - Data Debug Register - Bit 7
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_7(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_7_SHIFT)) & MBIST_DBG0_CDATA_7_MASK)
#define MBIST_DBG0_CDATA_8_MASK                (0x100U)
#define MBIST_DBG0_CDATA_8_SHIFT               (8U)
/*! CDATA_8 - Data Debug Register - Bit 8
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_8(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_8_SHIFT)) & MBIST_DBG0_CDATA_8_MASK)
#define MBIST_DBG0_CDATA_9_MASK                (0x200U)
#define MBIST_DBG0_CDATA_9_SHIFT               (9U)
/*! CDATA_9 - Data Debug Register - Bit 9
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_9(x)                  (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_9_SHIFT)) & MBIST_DBG0_CDATA_9_MASK)
#define MBIST_DBG0_CDATA_10_MASK               (0x400U)
#define MBIST_DBG0_CDATA_10_SHIFT              (10U)
/*! CDATA_10 - Data Debug Register - Bit 10
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_10(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_10_SHIFT)) & MBIST_DBG0_CDATA_10_MASK)
#define MBIST_DBG0_CDATA_11_MASK               (0x800U)
#define MBIST_DBG0_CDATA_11_SHIFT              (11U)
/*! CDATA_11 - Data Debug Register - Bit 11
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_11(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_11_SHIFT)) & MBIST_DBG0_CDATA_11_MASK)
#define MBIST_DBG0_CDATA_12_MASK               (0x1000U)
#define MBIST_DBG0_CDATA_12_SHIFT              (12U)
/*! CDATA_12 - Data Debug Register - Bit 12
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_12(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_12_SHIFT)) & MBIST_DBG0_CDATA_12_MASK)
#define MBIST_DBG0_CDATA_13_MASK               (0x2000U)
#define MBIST_DBG0_CDATA_13_SHIFT              (13U)
/*! CDATA_13 - Data Debug Register - Bit 13
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_13(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_13_SHIFT)) & MBIST_DBG0_CDATA_13_MASK)
#define MBIST_DBG0_CDATA_14_MASK               (0x4000U)
#define MBIST_DBG0_CDATA_14_SHIFT              (14U)
/*! CDATA_14 - Data Debug Register - Bit 14
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_14(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_14_SHIFT)) & MBIST_DBG0_CDATA_14_MASK)
#define MBIST_DBG0_CDATA_15_MASK               (0x8000U)
#define MBIST_DBG0_CDATA_15_SHIFT              (15U)
/*! CDATA_15 - Data Debug Register - Bit 15
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_15(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_15_SHIFT)) & MBIST_DBG0_CDATA_15_MASK)
#define MBIST_DBG0_CDATA_16_MASK               (0x10000U)
#define MBIST_DBG0_CDATA_16_SHIFT              (16U)
/*! CDATA_16 - Data Debug Register - Bit 16
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_16(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_16_SHIFT)) & MBIST_DBG0_CDATA_16_MASK)
#define MBIST_DBG0_CDATA_17_MASK               (0x20000U)
#define MBIST_DBG0_CDATA_17_SHIFT              (17U)
/*! CDATA_17 - Data Debug Register - Bit 17
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_17(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_17_SHIFT)) & MBIST_DBG0_CDATA_17_MASK)
#define MBIST_DBG0_CDATA_18_MASK               (0x40000U)
#define MBIST_DBG0_CDATA_18_SHIFT              (18U)
/*! CDATA_18 - Data Debug Register - Bit 18
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_18(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_18_SHIFT)) & MBIST_DBG0_CDATA_18_MASK)
#define MBIST_DBG0_CDATA_19_MASK               (0x80000U)
#define MBIST_DBG0_CDATA_19_SHIFT              (19U)
/*! CDATA_19 - Data Debug Register - Bit 19
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_19(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_19_SHIFT)) & MBIST_DBG0_CDATA_19_MASK)
#define MBIST_DBG0_CDATA_20_MASK               (0x100000U)
#define MBIST_DBG0_CDATA_20_SHIFT              (20U)
/*! CDATA_20 - Data Debug Register - Bit 20
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_20(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_20_SHIFT)) & MBIST_DBG0_CDATA_20_MASK)
#define MBIST_DBG0_CDATA_21_MASK               (0x200000U)
#define MBIST_DBG0_CDATA_21_SHIFT              (21U)
/*! CDATA_21 - Data Debug Register - Bit 21
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_21(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_21_SHIFT)) & MBIST_DBG0_CDATA_21_MASK)
#define MBIST_DBG0_CDATA_22_MASK               (0x400000U)
#define MBIST_DBG0_CDATA_22_SHIFT              (22U)
/*! CDATA_22 - Data Debug Register - Bit 22
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_22(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_22_SHIFT)) & MBIST_DBG0_CDATA_22_MASK)
#define MBIST_DBG0_CDATA_23_MASK               (0x800000U)
#define MBIST_DBG0_CDATA_23_SHIFT              (23U)
/*! CDATA_23 - Data Debug Register - Bit 23
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_23(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_23_SHIFT)) & MBIST_DBG0_CDATA_23_MASK)
#define MBIST_DBG0_CDATA_24_MASK               (0x1000000U)
#define MBIST_DBG0_CDATA_24_SHIFT              (24U)
/*! CDATA_24 - Data Debug Register - Bit 24
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_24(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_24_SHIFT)) & MBIST_DBG0_CDATA_24_MASK)
#define MBIST_DBG0_CDATA_25_MASK               (0x2000000U)
#define MBIST_DBG0_CDATA_25_SHIFT              (25U)
/*! CDATA_25 - Data Debug Register - Bit 25
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_25(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_25_SHIFT)) & MBIST_DBG0_CDATA_25_MASK)
#define MBIST_DBG0_CDATA_26_MASK               (0x4000000U)
#define MBIST_DBG0_CDATA_26_SHIFT              (26U)
/*! CDATA_26 - Data Debug Register - Bit 26
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_26(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_26_SHIFT)) & MBIST_DBG0_CDATA_26_MASK)
#define MBIST_DBG0_CDATA_27_MASK               (0x8000000U)
#define MBIST_DBG0_CDATA_27_SHIFT              (27U)
/*! CDATA_27 - Data Debug Register - Bit 27
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_27(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_27_SHIFT)) & MBIST_DBG0_CDATA_27_MASK)
#define MBIST_DBG0_CDATA_28_MASK               (0x10000000U)
#define MBIST_DBG0_CDATA_28_SHIFT              (28U)
/*! CDATA_28 - Data Debug Register - Bit 28
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_28(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_28_SHIFT)) & MBIST_DBG0_CDATA_28_MASK)
#define MBIST_DBG0_CDATA_29_MASK               (0x20000000U)
#define MBIST_DBG0_CDATA_29_SHIFT              (29U)
/*! CDATA_29 - Data Debug Register - Bit 29
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_29(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_29_SHIFT)) & MBIST_DBG0_CDATA_29_MASK)
#define MBIST_DBG0_CDATA_30_MASK               (0x40000000U)
#define MBIST_DBG0_CDATA_30_SHIFT              (30U)
/*! CDATA_30 - Data Debug Register - Bit 30
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_30(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_30_SHIFT)) & MBIST_DBG0_CDATA_30_MASK)
#define MBIST_DBG0_CDATA_31_MASK               (0x80000000U)
#define MBIST_DBG0_CDATA_31_SHIFT              (31U)
/*! CDATA_31 - Data Debug Register - Bit 31
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG0_CDATA_31(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG0_CDATA_31_SHIFT)) & MBIST_DBG0_CDATA_31_MASK)
/*! @} */

/*! @name DBG1 - Data Debug Register - Word 1 */
/*! @{ */
#define MBIST_DBG1_CDATA_32_MASK               (0x1U)
#define MBIST_DBG1_CDATA_32_SHIFT              (0U)
/*! CDATA_32 - Data Debug Register - Bit 32
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_32(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_32_SHIFT)) & MBIST_DBG1_CDATA_32_MASK)
#define MBIST_DBG1_CDATA_33_MASK               (0x2U)
#define MBIST_DBG1_CDATA_33_SHIFT              (1U)
/*! CDATA_33 - Data Debug Register - Bit 33
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_33(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_33_SHIFT)) & MBIST_DBG1_CDATA_33_MASK)
#define MBIST_DBG1_CDATA_34_MASK               (0x4U)
#define MBIST_DBG1_CDATA_34_SHIFT              (2U)
/*! CDATA_34 - Data Debug Register - Bit 34
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_34(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_34_SHIFT)) & MBIST_DBG1_CDATA_34_MASK)
#define MBIST_DBG1_CDATA_35_MASK               (0x8U)
#define MBIST_DBG1_CDATA_35_SHIFT              (3U)
/*! CDATA_35 - Data Debug Register - Bit 35
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_35(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_35_SHIFT)) & MBIST_DBG1_CDATA_35_MASK)
#define MBIST_DBG1_CDATA_36_MASK               (0x10U)
#define MBIST_DBG1_CDATA_36_SHIFT              (4U)
/*! CDATA_36 - Data Debug Register - Bit 36
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_36(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_36_SHIFT)) & MBIST_DBG1_CDATA_36_MASK)
#define MBIST_DBG1_CDATA_37_MASK               (0x20U)
#define MBIST_DBG1_CDATA_37_SHIFT              (5U)
/*! CDATA_37 - Data Debug Register - Bit 37
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_37(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_37_SHIFT)) & MBIST_DBG1_CDATA_37_MASK)
#define MBIST_DBG1_CDATA_38_MASK               (0x40U)
#define MBIST_DBG1_CDATA_38_SHIFT              (6U)
/*! CDATA_38 - Data Debug Register - Bit 38
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_38(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_38_SHIFT)) & MBIST_DBG1_CDATA_38_MASK)
#define MBIST_DBG1_CDATA_39_MASK               (0x80U)
#define MBIST_DBG1_CDATA_39_SHIFT              (7U)
/*! CDATA_39 - Data Debug Register - Bit 39
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_39(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_39_SHIFT)) & MBIST_DBG1_CDATA_39_MASK)
#define MBIST_DBG1_CDATA_40_MASK               (0x100U)
#define MBIST_DBG1_CDATA_40_SHIFT              (8U)
/*! CDATA_40 - Data Debug Register - Bit 40
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_40(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_40_SHIFT)) & MBIST_DBG1_CDATA_40_MASK)
#define MBIST_DBG1_CDATA_41_MASK               (0x200U)
#define MBIST_DBG1_CDATA_41_SHIFT              (9U)
/*! CDATA_41 - Data Debug Register - Bit 41
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_41(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_41_SHIFT)) & MBIST_DBG1_CDATA_41_MASK)
#define MBIST_DBG1_CDATA_42_MASK               (0x400U)
#define MBIST_DBG1_CDATA_42_SHIFT              (10U)
/*! CDATA_42 - Data Debug Register - Bit 42
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_42(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_42_SHIFT)) & MBIST_DBG1_CDATA_42_MASK)
#define MBIST_DBG1_CDATA_43_MASK               (0x800U)
#define MBIST_DBG1_CDATA_43_SHIFT              (11U)
/*! CDATA_43 - Data Debug Register - Bit 43
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_43(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_43_SHIFT)) & MBIST_DBG1_CDATA_43_MASK)
#define MBIST_DBG1_CDATA_44_MASK               (0x1000U)
#define MBIST_DBG1_CDATA_44_SHIFT              (12U)
/*! CDATA_44 - Data Debug Register - Bit 44
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_44(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_44_SHIFT)) & MBIST_DBG1_CDATA_44_MASK)
#define MBIST_DBG1_CDATA_45_MASK               (0x2000U)
#define MBIST_DBG1_CDATA_45_SHIFT              (13U)
/*! CDATA_45 - Data Debug Register - Bit 45
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_45(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_45_SHIFT)) & MBIST_DBG1_CDATA_45_MASK)
#define MBIST_DBG1_CDATA_46_MASK               (0x4000U)
#define MBIST_DBG1_CDATA_46_SHIFT              (14U)
/*! CDATA_46 - Data Debug Register - Bit 46
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_46(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_46_SHIFT)) & MBIST_DBG1_CDATA_46_MASK)
#define MBIST_DBG1_CDATA_47_MASK               (0x8000U)
#define MBIST_DBG1_CDATA_47_SHIFT              (15U)
/*! CDATA_47 - Data Debug Register - Bit 47
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_47(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_47_SHIFT)) & MBIST_DBG1_CDATA_47_MASK)
#define MBIST_DBG1_CDATA_48_MASK               (0x10000U)
#define MBIST_DBG1_CDATA_48_SHIFT              (16U)
/*! CDATA_48 - Data Debug Register - Bit 48
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_48(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_48_SHIFT)) & MBIST_DBG1_CDATA_48_MASK)
#define MBIST_DBG1_CDATA_49_MASK               (0x20000U)
#define MBIST_DBG1_CDATA_49_SHIFT              (17U)
/*! CDATA_49 - Data Debug Register - Bit 49
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_49(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_49_SHIFT)) & MBIST_DBG1_CDATA_49_MASK)
#define MBIST_DBG1_CDATA_50_MASK               (0x40000U)
#define MBIST_DBG1_CDATA_50_SHIFT              (18U)
/*! CDATA_50 - Data Debug Register - Bit 50
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_50(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_50_SHIFT)) & MBIST_DBG1_CDATA_50_MASK)
#define MBIST_DBG1_CDATA_51_MASK               (0x80000U)
#define MBIST_DBG1_CDATA_51_SHIFT              (19U)
/*! CDATA_51 - Data Debug Register - Bit 51
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_51(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_51_SHIFT)) & MBIST_DBG1_CDATA_51_MASK)
#define MBIST_DBG1_CDATA_52_MASK               (0x100000U)
#define MBIST_DBG1_CDATA_52_SHIFT              (20U)
/*! CDATA_52 - Data Debug Register - Bit 52
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_52(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_52_SHIFT)) & MBIST_DBG1_CDATA_52_MASK)
#define MBIST_DBG1_CDATA_53_MASK               (0x200000U)
#define MBIST_DBG1_CDATA_53_SHIFT              (21U)
/*! CDATA_53 - Data Debug Register - Bit 53
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_53(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_53_SHIFT)) & MBIST_DBG1_CDATA_53_MASK)
#define MBIST_DBG1_CDATA_54_MASK               (0x400000U)
#define MBIST_DBG1_CDATA_54_SHIFT              (22U)
/*! CDATA_54 - Data Debug Register - Bit 54
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_54(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_54_SHIFT)) & MBIST_DBG1_CDATA_54_MASK)
#define MBIST_DBG1_CDATA_55_MASK               (0x800000U)
#define MBIST_DBG1_CDATA_55_SHIFT              (23U)
/*! CDATA_55 - Data Debug Register - Bit 55
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_55(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_55_SHIFT)) & MBIST_DBG1_CDATA_55_MASK)
#define MBIST_DBG1_CDATA_56_MASK               (0x1000000U)
#define MBIST_DBG1_CDATA_56_SHIFT              (24U)
/*! CDATA_56 - Data Debug Register - Bit 56
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_56(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_56_SHIFT)) & MBIST_DBG1_CDATA_56_MASK)
#define MBIST_DBG1_CDATA_57_MASK               (0x2000000U)
#define MBIST_DBG1_CDATA_57_SHIFT              (25U)
/*! CDATA_57 - Data Debug Register - Bit 57
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_57(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_57_SHIFT)) & MBIST_DBG1_CDATA_57_MASK)
#define MBIST_DBG1_CDATA_58_MASK               (0x4000000U)
#define MBIST_DBG1_CDATA_58_SHIFT              (26U)
/*! CDATA_58 - Data Debug Register - Bit 58
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_58(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_58_SHIFT)) & MBIST_DBG1_CDATA_58_MASK)
#define MBIST_DBG1_CDATA_59_MASK               (0x8000000U)
#define MBIST_DBG1_CDATA_59_SHIFT              (27U)
/*! CDATA_59 - Data Debug Register - Bit 59
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_59(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_59_SHIFT)) & MBIST_DBG1_CDATA_59_MASK)
#define MBIST_DBG1_CDATA_60_MASK               (0x10000000U)
#define MBIST_DBG1_CDATA_60_SHIFT              (28U)
/*! CDATA_60 - Data Debug Register - Bit 60
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_60(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_60_SHIFT)) & MBIST_DBG1_CDATA_60_MASK)
#define MBIST_DBG1_CDATA_61_MASK               (0x20000000U)
#define MBIST_DBG1_CDATA_61_SHIFT              (29U)
/*! CDATA_61 - Data Debug Register - Bit 61
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_61(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_61_SHIFT)) & MBIST_DBG1_CDATA_61_MASK)
#define MBIST_DBG1_CDATA_62_MASK               (0x40000000U)
#define MBIST_DBG1_CDATA_62_SHIFT              (30U)
/*! CDATA_62 - Data Debug Register - Bit 62
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_62(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_62_SHIFT)) & MBIST_DBG1_CDATA_62_MASK)
#define MBIST_DBG1_CDATA_63_MASK               (0x80000000U)
#define MBIST_DBG1_CDATA_63_SHIFT              (31U)
/*! CDATA_63 - Data Debug Register - Bit 63
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG1_CDATA_63(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG1_CDATA_63_SHIFT)) & MBIST_DBG1_CDATA_63_MASK)
/*! @} */

/*! @name DBG2 - Data Debug Register - Word 2 */
/*! @{ */
#define MBIST_DBG2_CDATA_64_MASK               (0x1U)
#define MBIST_DBG2_CDATA_64_SHIFT              (0U)
/*! CDATA_64 - Data Debug Register - Bit 64
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_64(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_64_SHIFT)) & MBIST_DBG2_CDATA_64_MASK)
#define MBIST_DBG2_CDATA_65_MASK               (0x2U)
#define MBIST_DBG2_CDATA_65_SHIFT              (1U)
/*! CDATA_65 - Data Debug Register - Bit 65
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_65(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_65_SHIFT)) & MBIST_DBG2_CDATA_65_MASK)
#define MBIST_DBG2_CDATA_66_MASK               (0x4U)
#define MBIST_DBG2_CDATA_66_SHIFT              (2U)
/*! CDATA_66 - Data Debug Register - Bit 66
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_66(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_66_SHIFT)) & MBIST_DBG2_CDATA_66_MASK)
#define MBIST_DBG2_CDATA_67_MASK               (0x8U)
#define MBIST_DBG2_CDATA_67_SHIFT              (3U)
/*! CDATA_67 - Data Debug Register - Bit 67
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_67(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_67_SHIFT)) & MBIST_DBG2_CDATA_67_MASK)
#define MBIST_DBG2_CDATA_68_MASK               (0x10U)
#define MBIST_DBG2_CDATA_68_SHIFT              (4U)
/*! CDATA_68 - Data Debug Register - Bit 68
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_68(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_68_SHIFT)) & MBIST_DBG2_CDATA_68_MASK)
#define MBIST_DBG2_CDATA_69_MASK               (0x20U)
#define MBIST_DBG2_CDATA_69_SHIFT              (5U)
/*! CDATA_69 - Data Debug Register - Bit 69
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_69(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_69_SHIFT)) & MBIST_DBG2_CDATA_69_MASK)
#define MBIST_DBG2_CDATA_70_MASK               (0x40U)
#define MBIST_DBG2_CDATA_70_SHIFT              (6U)
/*! CDATA_70 - Data Debug Register - Bit 70
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_70(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_70_SHIFT)) & MBIST_DBG2_CDATA_70_MASK)
#define MBIST_DBG2_CDATA_71_MASK               (0x80U)
#define MBIST_DBG2_CDATA_71_SHIFT              (7U)
/*! CDATA_71 - Data Debug Register - Bit 71
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_71(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_71_SHIFT)) & MBIST_DBG2_CDATA_71_MASK)
#define MBIST_DBG2_CDATA_72_MASK               (0x100U)
#define MBIST_DBG2_CDATA_72_SHIFT              (8U)
/*! CDATA_72 - Data Debug Register - Bit 72
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_72(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_72_SHIFT)) & MBIST_DBG2_CDATA_72_MASK)
#define MBIST_DBG2_CDATA_73_MASK               (0x200U)
#define MBIST_DBG2_CDATA_73_SHIFT              (9U)
/*! CDATA_73 - Data Debug Register - Bit 73
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_73(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_73_SHIFT)) & MBIST_DBG2_CDATA_73_MASK)
#define MBIST_DBG2_CDATA_74_MASK               (0x400U)
#define MBIST_DBG2_CDATA_74_SHIFT              (10U)
/*! CDATA_74 - Data Debug Register - Bit 74
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_74(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_74_SHIFT)) & MBIST_DBG2_CDATA_74_MASK)
#define MBIST_DBG2_CDATA_75_MASK               (0x800U)
#define MBIST_DBG2_CDATA_75_SHIFT              (11U)
/*! CDATA_75 - Data Debug Register - Bit 75
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_75(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_75_SHIFT)) & MBIST_DBG2_CDATA_75_MASK)
#define MBIST_DBG2_CDATA_76_MASK               (0x1000U)
#define MBIST_DBG2_CDATA_76_SHIFT              (12U)
/*! CDATA_76 - Data Debug Register - Bit 76
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_76(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_76_SHIFT)) & MBIST_DBG2_CDATA_76_MASK)
#define MBIST_DBG2_CDATA_77_MASK               (0x2000U)
#define MBIST_DBG2_CDATA_77_SHIFT              (13U)
/*! CDATA_77 - Data Debug Register - Bit 77
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_77(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_77_SHIFT)) & MBIST_DBG2_CDATA_77_MASK)
#define MBIST_DBG2_CDATA_78_MASK               (0x4000U)
#define MBIST_DBG2_CDATA_78_SHIFT              (14U)
/*! CDATA_78 - Data Debug Register - Bit 78
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_78(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_78_SHIFT)) & MBIST_DBG2_CDATA_78_MASK)
#define MBIST_DBG2_CDATA_79_MASK               (0x8000U)
#define MBIST_DBG2_CDATA_79_SHIFT              (15U)
/*! CDATA_79 - Data Debug Register - Bit 79
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_79(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_79_SHIFT)) & MBIST_DBG2_CDATA_79_MASK)
#define MBIST_DBG2_CDATA_80_MASK               (0x10000U)
#define MBIST_DBG2_CDATA_80_SHIFT              (16U)
/*! CDATA_80 - Data Debug Register - Bit 80
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_80(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_80_SHIFT)) & MBIST_DBG2_CDATA_80_MASK)
#define MBIST_DBG2_CDATA_81_MASK               (0x20000U)
#define MBIST_DBG2_CDATA_81_SHIFT              (17U)
/*! CDATA_81 - Data Debug Register - Bit 81
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_81(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_81_SHIFT)) & MBIST_DBG2_CDATA_81_MASK)
#define MBIST_DBG2_CDATA_82_MASK               (0x40000U)
#define MBIST_DBG2_CDATA_82_SHIFT              (18U)
/*! CDATA_82 - Data Debug Register - Bit 82
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_82(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_82_SHIFT)) & MBIST_DBG2_CDATA_82_MASK)
#define MBIST_DBG2_CDATA_83_MASK               (0x80000U)
#define MBIST_DBG2_CDATA_83_SHIFT              (19U)
/*! CDATA_83 - Data Debug Register - Bit 83
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_83(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_83_SHIFT)) & MBIST_DBG2_CDATA_83_MASK)
#define MBIST_DBG2_CDATA_84_MASK               (0x100000U)
#define MBIST_DBG2_CDATA_84_SHIFT              (20U)
/*! CDATA_84 - Data Debug Register - Bit 84
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_84(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_84_SHIFT)) & MBIST_DBG2_CDATA_84_MASK)
#define MBIST_DBG2_CDATA_85_MASK               (0x200000U)
#define MBIST_DBG2_CDATA_85_SHIFT              (21U)
/*! CDATA_85 - Data Debug Register - Bit 85
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_85(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_85_SHIFT)) & MBIST_DBG2_CDATA_85_MASK)
#define MBIST_DBG2_CDATA_86_MASK               (0x400000U)
#define MBIST_DBG2_CDATA_86_SHIFT              (22U)
/*! CDATA_86 - Data Debug Register - Bit 86
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_86(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_86_SHIFT)) & MBIST_DBG2_CDATA_86_MASK)
#define MBIST_DBG2_CDATA_87_MASK               (0x800000U)
#define MBIST_DBG2_CDATA_87_SHIFT              (23U)
/*! CDATA_87 - Data Debug Register - Bit 87
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_87(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_87_SHIFT)) & MBIST_DBG2_CDATA_87_MASK)
#define MBIST_DBG2_CDATA_88_MASK               (0x1000000U)
#define MBIST_DBG2_CDATA_88_SHIFT              (24U)
/*! CDATA_88 - Data Debug Register - Bit 88
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_88(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_88_SHIFT)) & MBIST_DBG2_CDATA_88_MASK)
#define MBIST_DBG2_CDATA_89_MASK               (0x2000000U)
#define MBIST_DBG2_CDATA_89_SHIFT              (25U)
/*! CDATA_89 - Data Debug Register - Bit 89
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_89(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_89_SHIFT)) & MBIST_DBG2_CDATA_89_MASK)
#define MBIST_DBG2_CDATA_90_MASK               (0x4000000U)
#define MBIST_DBG2_CDATA_90_SHIFT              (26U)
/*! CDATA_90 - Data Debug Register - Bit 90
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_90(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_90_SHIFT)) & MBIST_DBG2_CDATA_90_MASK)
#define MBIST_DBG2_CDATA_91_MASK               (0x8000000U)
#define MBIST_DBG2_CDATA_91_SHIFT              (27U)
/*! CDATA_91 - Data Debug Register - Bit 91
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_91(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_91_SHIFT)) & MBIST_DBG2_CDATA_91_MASK)
#define MBIST_DBG2_CDATA_92_MASK               (0x10000000U)
#define MBIST_DBG2_CDATA_92_SHIFT              (28U)
/*! CDATA_92 - Data Debug Register - Bit 92
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_92(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_92_SHIFT)) & MBIST_DBG2_CDATA_92_MASK)
#define MBIST_DBG2_CDATA_93_MASK               (0x20000000U)
#define MBIST_DBG2_CDATA_93_SHIFT              (29U)
/*! CDATA_93 - Data Debug Register - Bit 93
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_93(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_93_SHIFT)) & MBIST_DBG2_CDATA_93_MASK)
#define MBIST_DBG2_CDATA_94_MASK               (0x40000000U)
#define MBIST_DBG2_CDATA_94_SHIFT              (30U)
/*! CDATA_94 - Data Debug Register - Bit 94
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_94(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_94_SHIFT)) & MBIST_DBG2_CDATA_94_MASK)
#define MBIST_DBG2_CDATA_95_MASK               (0x80000000U)
#define MBIST_DBG2_CDATA_95_SHIFT              (31U)
/*! CDATA_95 - Data Debug Register - Bit 95
 *  0b0..Bit compare passed.
 *  0b1..Bit compare failed.
 */
#define MBIST_DBG2_CDATA_95(x)                 (((uint32_t)(((uint32_t)(x)) << MBIST_DBG2_CDATA_95_SHIFT)) & MBIST_DBG2_CDATA_95_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MBIST_Register_Masks */

/*!
 * @}
 */ /* end of group MBIST_Peripheral_Access_Layer */


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
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


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


#endif  /* MX8_MBIST_H */

