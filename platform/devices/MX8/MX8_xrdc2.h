/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
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
 * @file xrdc2.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for xrdc2
 *
 * CMSIS Peripheral Access Layer for xrdc2
 */

#ifndef XRDC2_H
#define XRDC2_H                                /**< Symbol preventing repeated inclusion */

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
   -- XRDC2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC2_Peripheral_Access_Layer XRDC2 Peripheral Access Layer
 * @{
 */

/** XRDC2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Control Register, offset: 0x0 */
  __I  uint32_t SR;                                /**< Status Register, offset: 0x4 */
       uint8_t RESERVED_0[4088];
  struct {                                         /* offset: 0x1000, array step: 0x8 */
    __IO uint32_t MSC_MSAC_W0;                       /**< Memory Slot Access Control, array offset: 0x1000, array step: 0x8 */
    __IO uint32_t MSC_MSAC_W1;                       /**< Memory Slot Access Control, array offset: 0x1004, array step: 0x8 */
  } MSCI_MSAC_WK[128];
       uint8_t RESERVED_1[3072];
  struct {                                         /* offset: 0x2000, array step: index*0x100, index2*0x8 */
    __IO uint32_t MDAC_MDA_W0;                       /**< Master Domain Assignment (W0), array offset: 0x2000, array step: index*0x100, index2*0x8 */
    __IO uint32_t MDAC_MDA_W1;                       /**< Master Domain Assignment (W1), array offset: 0x2004, array step: index*0x100, index2*0x8 */
  } MDACI_MDAJ[32][32];
  struct {                                         /* offset: 0x4000, array step: index*0x800, index2*0x8 */
    __IO uint32_t PAC_PDAC_W0;                       /**< Peripheral Domain Access Control, array offset: 0x4000, array step: index*0x800, index2*0x8 */
    __IO uint32_t PAC_PDAC_W1;                       /**< Peripheral Domain Access Control, array offset: 0x4004, array step: index*0x800, index2*0x8 */
  } PACI_PDACJ[8][256];
  struct {                                         /* offset: 0x8000, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W0;                       /**< Memory Region Descriptor, array offset: 0x8000, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W1;                       /**< Memory Region Descriptor, array offset: 0x8004, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W2;                       /**< Memory Region Descriptor, array offset: 0x8008, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W3;                       /**< Memory Region Descriptor, array offset: 0x800C, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W4;                       /**< Memory Region Descriptor, array offset: 0x8010, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W5;                       /**< Memory Region Descriptor, array offset: 0x8014, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W6;                       /**< Memory Region Descriptor, array offset: 0x8018, array step: index*0x400, index2*0x20 */
         uint8_t RESERVED_0[4];
  } MRCI_MRGDJ[32][32];
} XRDC2_Type;

/* ----------------------------------------------------------------------------
   -- XRDC2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC2_Register_Masks XRDC2 Register Masks
 * @{
 */

/*! @name MCR - Module Control Register */
#define XRDC2_MCR_GVLDM_MASK                     (0x1U)
#define XRDC2_MCR_GVLDM_SHIFT                    (0U)
#define XRDC2_MCR_GVLDM(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC2_MCR_GVLDM_SHIFT)) & XRDC2_MCR_GVLDM_MASK)
#define XRDC2_MCR_GVLDC_MASK                     (0x2U)
#define XRDC2_MCR_GVLDC_SHIFT                    (1U)
#define XRDC2_MCR_GVLDC(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC2_MCR_GVLDC_SHIFT)) & XRDC2_MCR_GVLDC_MASK)
#define XRDC2_MCR_GCL_MASK                       (0x30U)
#define XRDC2_MCR_GCL_SHIFT                      (4U)
#define XRDC2_MCR_GCL(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC2_MCR_GCL_SHIFT)) & XRDC2_MCR_GCL_MASK)

/*! @name SR - Status Register */
#define XRDC2_SR_DID_MASK                        (0xFU)
#define XRDC2_SR_DID_SHIFT                       (0U)
#define XRDC2_SR_DID(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC2_SR_DID_SHIFT)) & XRDC2_SR_DID_MASK)
#define XRDC2_SR_HRL_MASK                        (0xF0U)
#define XRDC2_SR_HRL_SHIFT                       (4U)
#define XRDC2_SR_HRL(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC2_SR_HRL_SHIFT)) & XRDC2_SR_HRL_MASK)
#define XRDC2_SR_GCLO_MASK                       (0xF00U)
#define XRDC2_SR_GCLO_SHIFT                      (8U)
#define XRDC2_SR_GCLO(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC2_SR_GCLO_SHIFT)) & XRDC2_SR_GCLO_MASK)

/*! @name MSC_MSAC_W0 - Memory Slot Access Control */
#define XRDC2_MSC_MSAC_W0_D0ACP_MASK             (0x7U)
#define XRDC2_MSC_MSAC_W0_D0ACP_SHIFT            (0U)
#define XRDC2_MSC_MSAC_W0_D0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D0ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D0ACP_MASK)
#define XRDC2_MSC_MSAC_W0_D1ACP_MASK             (0x38U)
#define XRDC2_MSC_MSAC_W0_D1ACP_SHIFT            (3U)
#define XRDC2_MSC_MSAC_W0_D1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D1ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D1ACP_MASK)
#define XRDC2_MSC_MSAC_W0_D2ACP_MASK             (0x1C0U)
#define XRDC2_MSC_MSAC_W0_D2ACP_SHIFT            (6U)
#define XRDC2_MSC_MSAC_W0_D2ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D2ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D2ACP_MASK)
#define XRDC2_MSC_MSAC_W0_D3ACP_MASK             (0xE00U)
#define XRDC2_MSC_MSAC_W0_D3ACP_SHIFT            (9U)
#define XRDC2_MSC_MSAC_W0_D3ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D3ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D3ACP_MASK)
#define XRDC2_MSC_MSAC_W0_D4ACP_MASK             (0x7000U)
#define XRDC2_MSC_MSAC_W0_D4ACP_SHIFT            (12U)
#define XRDC2_MSC_MSAC_W0_D4ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D4ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D4ACP_MASK)
#define XRDC2_MSC_MSAC_W0_D5ACP_MASK             (0x38000U)
#define XRDC2_MSC_MSAC_W0_D5ACP_SHIFT            (15U)
#define XRDC2_MSC_MSAC_W0_D5ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D5ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D5ACP_MASK)
#define XRDC2_MSC_MSAC_W0_D6ACP_MASK             (0x1C0000U)
#define XRDC2_MSC_MSAC_W0_D6ACP_SHIFT            (18U)
#define XRDC2_MSC_MSAC_W0_D6ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D6ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D6ACP_MASK)
#define XRDC2_MSC_MSAC_W0_D7ACP_MASK             (0xE00000U)
#define XRDC2_MSC_MSAC_W0_D7ACP_SHIFT            (21U)
#define XRDC2_MSC_MSAC_W0_D7ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D7ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D7ACP_MASK)
#define XRDC2_MSC_MSAC_W0_EALO_MASK              (0xF000000U)
#define XRDC2_MSC_MSAC_W0_EALO_SHIFT             (24U)
#define XRDC2_MSC_MSAC_W0_EALO(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_EALO_SHIFT)) & XRDC2_MSC_MSAC_W0_EALO_MASK)

/* The count of XRDC2_MSC_MSAC_W0 */
#define XRDC2_MSC_MSAC_W0_COUNT                  (128U)

/*! @name MSC_MSAC_W1 - Memory Slot Access Control */
#define XRDC2_MSC_MSAC_W1_D8ACP_MASK             (0x7U)
#define XRDC2_MSC_MSAC_W1_D8ACP_SHIFT            (0U)
#define XRDC2_MSC_MSAC_W1_D8ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D8ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D8ACP_MASK)
#define XRDC2_MSC_MSAC_W1_D9ACP_MASK             (0x38U)
#define XRDC2_MSC_MSAC_W1_D9ACP_SHIFT            (3U)
#define XRDC2_MSC_MSAC_W1_D9ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D9ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D9ACP_MASK)
#define XRDC2_MSC_MSAC_W1_D10ACP_MASK            (0x1C0U)
#define XRDC2_MSC_MSAC_W1_D10ACP_SHIFT           (6U)
#define XRDC2_MSC_MSAC_W1_D10ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D10ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D10ACP_MASK)
#define XRDC2_MSC_MSAC_W1_D11ACP_MASK            (0xE00U)
#define XRDC2_MSC_MSAC_W1_D11ACP_SHIFT           (9U)
#define XRDC2_MSC_MSAC_W1_D11ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D11ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D11ACP_MASK)
#define XRDC2_MSC_MSAC_W1_D12ACP_MASK            (0x7000U)
#define XRDC2_MSC_MSAC_W1_D12ACP_SHIFT           (12U)
#define XRDC2_MSC_MSAC_W1_D12ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D12ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D12ACP_MASK)
#define XRDC2_MSC_MSAC_W1_D13ACP_MASK            (0x38000U)
#define XRDC2_MSC_MSAC_W1_D13ACP_SHIFT           (15U)
#define XRDC2_MSC_MSAC_W1_D13ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D13ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D13ACP_MASK)
#define XRDC2_MSC_MSAC_W1_D14ACP_MASK            (0x1C0000U)
#define XRDC2_MSC_MSAC_W1_D14ACP_SHIFT           (18U)
#define XRDC2_MSC_MSAC_W1_D14ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D14ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D14ACP_MASK)
#define XRDC2_MSC_MSAC_W1_D15ACP_MASK            (0xE00000U)
#define XRDC2_MSC_MSAC_W1_D15ACP_SHIFT           (21U)
#define XRDC2_MSC_MSAC_W1_D15ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D15ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D15ACP_MASK)
#define XRDC2_MSC_MSAC_W1_EAL_MASK               (0x3000000U)
#define XRDC2_MSC_MSAC_W1_EAL_SHIFT              (24U)
#define XRDC2_MSC_MSAC_W1_EAL(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_EAL_SHIFT)) & XRDC2_MSC_MSAC_W1_EAL_MASK)
#define XRDC2_MSC_MSAC_W1_DL2_MASK               (0x60000000U)
#define XRDC2_MSC_MSAC_W1_DL2_SHIFT              (29U)
#define XRDC2_MSC_MSAC_W1_DL2(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_DL2_SHIFT)) & XRDC2_MSC_MSAC_W1_DL2_MASK)
#define XRDC2_MSC_MSAC_W1_VLD_MASK               (0x80000000U)
#define XRDC2_MSC_MSAC_W1_VLD_SHIFT              (31U)
#define XRDC2_MSC_MSAC_W1_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_VLD_SHIFT)) & XRDC2_MSC_MSAC_W1_VLD_MASK)

/* The count of XRDC2_MSC_MSAC_W1 */
#define XRDC2_MSC_MSAC_W1_COUNT                  (128U)

/*! @name MDAC_MDA_W0 - Master Domain Assignment (W0) */
#define XRDC2_MDAC_MDA_W0_MASK_MASK              (0xFFFFU)
#define XRDC2_MDAC_MDA_W0_MASK_SHIFT             (0U)
#define XRDC2_MDAC_MDA_W0_MASK(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W0_MASK_SHIFT)) & XRDC2_MDAC_MDA_W0_MASK_MASK)
#define XRDC2_MDAC_MDA_W0_MATCH_MASK             (0xFFFF0000U)
#define XRDC2_MDAC_MDA_W0_MATCH_SHIFT            (16U)
#define XRDC2_MDAC_MDA_W0_MATCH(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W0_MATCH_SHIFT)) & XRDC2_MDAC_MDA_W0_MATCH_MASK)

/* The count of XRDC2_MDAC_MDA_W0 */
#define XRDC2_MDAC_MDA_W0_COUNT                  (32U)

/* The count of XRDC2_MDAC_MDA_W0 */
#define XRDC2_MDAC_MDA_W0_COUNT2                 (32U)

/*! @name MDAC_MDA_W1 - Master Domain Assignment (W1) */
#define XRDC2_MDAC_MDA_W1_SID_MASK               (0xFFFFU)
#define XRDC2_MDAC_MDA_W1_SID_SHIFT              (0U)
#define XRDC2_MDAC_MDA_W1_SID(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_SID_SHIFT)) & XRDC2_MDAC_MDA_W1_SID_MASK)
#define XRDC2_MDAC_MDA_W1_DID_MASK               (0xF0000U)
#define XRDC2_MDAC_MDA_W1_DID_SHIFT              (16U)
#define XRDC2_MDAC_MDA_W1_DID(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_DID_SHIFT)) & XRDC2_MDAC_MDA_W1_DID_MASK)
#define XRDC2_MDAC_MDA_W1_PA_MASK                (0x3000000U)
#define XRDC2_MDAC_MDA_W1_PA_SHIFT               (24U)
#define XRDC2_MDAC_MDA_W1_PA(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_PA_SHIFT)) & XRDC2_MDAC_MDA_W1_PA_MASK)
#define XRDC2_MDAC_MDA_W1_SA_MASK                (0xC000000U)
#define XRDC2_MDAC_MDA_W1_SA_SHIFT               (26U)
#define XRDC2_MDAC_MDA_W1_SA(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_SA_SHIFT)) & XRDC2_MDAC_MDA_W1_SA_MASK)
#define XRDC2_MDAC_MDA_W1_DL_MASK                (0x40000000U)
#define XRDC2_MDAC_MDA_W1_DL_SHIFT               (30U)
#define XRDC2_MDAC_MDA_W1_DL(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_DL_SHIFT)) & XRDC2_MDAC_MDA_W1_DL_MASK)
#define XRDC2_MDAC_MDA_W1_VLD_MASK               (0x80000000U)
#define XRDC2_MDAC_MDA_W1_VLD_SHIFT              (31U)
#define XRDC2_MDAC_MDA_W1_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_VLD_SHIFT)) & XRDC2_MDAC_MDA_W1_VLD_MASK)

/* The count of XRDC2_MDAC_MDA_W1 */
#define XRDC2_MDAC_MDA_W1_COUNT                  (32U)

/* The count of XRDC2_MDAC_MDA_W1 */
#define XRDC2_MDAC_MDA_W1_COUNT2                 (32U)

/*! @name PAC_PDAC_W0 - Peripheral Domain Access Control */
#define XRDC2_PAC_PDAC_W0_D0ACP_MASK             (0x7U)
#define XRDC2_PAC_PDAC_W0_D0ACP_SHIFT            (0U)
#define XRDC2_PAC_PDAC_W0_D0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D0ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D0ACP_MASK)
#define XRDC2_PAC_PDAC_W0_D1ACP_MASK             (0x38U)
#define XRDC2_PAC_PDAC_W0_D1ACP_SHIFT            (3U)
#define XRDC2_PAC_PDAC_W0_D1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D1ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D1ACP_MASK)
#define XRDC2_PAC_PDAC_W0_D2ACP_MASK             (0x1C0U)
#define XRDC2_PAC_PDAC_W0_D2ACP_SHIFT            (6U)
#define XRDC2_PAC_PDAC_W0_D2ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D2ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D2ACP_MASK)
#define XRDC2_PAC_PDAC_W0_D3ACP_MASK             (0xE00U)
#define XRDC2_PAC_PDAC_W0_D3ACP_SHIFT            (9U)
#define XRDC2_PAC_PDAC_W0_D3ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D3ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D3ACP_MASK)
#define XRDC2_PAC_PDAC_W0_D4ACP_MASK             (0x7000U)
#define XRDC2_PAC_PDAC_W0_D4ACP_SHIFT            (12U)
#define XRDC2_PAC_PDAC_W0_D4ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D4ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D4ACP_MASK)
#define XRDC2_PAC_PDAC_W0_D5ACP_MASK             (0x38000U)
#define XRDC2_PAC_PDAC_W0_D5ACP_SHIFT            (15U)
#define XRDC2_PAC_PDAC_W0_D5ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D5ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D5ACP_MASK)
#define XRDC2_PAC_PDAC_W0_D6ACP_MASK             (0x1C0000U)
#define XRDC2_PAC_PDAC_W0_D6ACP_SHIFT            (18U)
#define XRDC2_PAC_PDAC_W0_D6ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D6ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D6ACP_MASK)
#define XRDC2_PAC_PDAC_W0_D7ACP_MASK             (0xE00000U)
#define XRDC2_PAC_PDAC_W0_D7ACP_SHIFT            (21U)
#define XRDC2_PAC_PDAC_W0_D7ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D7ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D7ACP_MASK)
#define XRDC2_PAC_PDAC_W0_EALO_MASK              (0xF000000U)
#define XRDC2_PAC_PDAC_W0_EALO_SHIFT             (24U)
#define XRDC2_PAC_PDAC_W0_EALO(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_EALO_SHIFT)) & XRDC2_PAC_PDAC_W0_EALO_MASK)

/* The count of XRDC2_PAC_PDAC_W0 */
#define XRDC2_PAC_PDAC_W0_COUNT                  (8U)

/* The count of XRDC2_PAC_PDAC_W0 */
#define XRDC2_PAC_PDAC_W0_COUNT2                 (256U)

/*! @name PAC_PDAC_W1 - Peripheral Domain Access Control */
#define XRDC2_PAC_PDAC_W1_D8ACP_MASK             (0x7U)
#define XRDC2_PAC_PDAC_W1_D8ACP_SHIFT            (0U)
#define XRDC2_PAC_PDAC_W1_D8ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D8ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D8ACP_MASK)
#define XRDC2_PAC_PDAC_W1_D9ACP_MASK             (0x38U)
#define XRDC2_PAC_PDAC_W1_D9ACP_SHIFT            (3U)
#define XRDC2_PAC_PDAC_W1_D9ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D9ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D9ACP_MASK)
#define XRDC2_PAC_PDAC_W1_D10ACP_MASK            (0x1C0U)
#define XRDC2_PAC_PDAC_W1_D10ACP_SHIFT           (6U)
#define XRDC2_PAC_PDAC_W1_D10ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D10ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D10ACP_MASK)
#define XRDC2_PAC_PDAC_W1_D11ACP_MASK            (0xE00U)
#define XRDC2_PAC_PDAC_W1_D11ACP_SHIFT           (9U)
#define XRDC2_PAC_PDAC_W1_D11ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D11ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D11ACP_MASK)
#define XRDC2_PAC_PDAC_W1_D12ACP_MASK            (0x7000U)
#define XRDC2_PAC_PDAC_W1_D12ACP_SHIFT           (12U)
#define XRDC2_PAC_PDAC_W1_D12ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D12ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D12ACP_MASK)
#define XRDC2_PAC_PDAC_W1_D13ACP_MASK            (0x38000U)
#define XRDC2_PAC_PDAC_W1_D13ACP_SHIFT           (15U)
#define XRDC2_PAC_PDAC_W1_D13ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D13ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D13ACP_MASK)
#define XRDC2_PAC_PDAC_W1_D14ACP_MASK            (0x1C0000U)
#define XRDC2_PAC_PDAC_W1_D14ACP_SHIFT           (18U)
#define XRDC2_PAC_PDAC_W1_D14ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D14ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D14ACP_MASK)
#define XRDC2_PAC_PDAC_W1_D15ACP_MASK            (0xE00000U)
#define XRDC2_PAC_PDAC_W1_D15ACP_SHIFT           (21U)
#define XRDC2_PAC_PDAC_W1_D15ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D15ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D15ACP_MASK)
#define XRDC2_PAC_PDAC_W1_EAL_MASK               (0x3000000U)
#define XRDC2_PAC_PDAC_W1_EAL_SHIFT              (24U)
#define XRDC2_PAC_PDAC_W1_EAL(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_EAL_SHIFT)) & XRDC2_PAC_PDAC_W1_EAL_MASK)
#define XRDC2_PAC_PDAC_W1_DL2_MASK               (0x60000000U)
#define XRDC2_PAC_PDAC_W1_DL2_SHIFT              (29U)
#define XRDC2_PAC_PDAC_W1_DL2(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_DL2_SHIFT)) & XRDC2_PAC_PDAC_W1_DL2_MASK)
#define XRDC2_PAC_PDAC_W1_VLD_MASK               (0x80000000U)
#define XRDC2_PAC_PDAC_W1_VLD_SHIFT              (31U)
#define XRDC2_PAC_PDAC_W1_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_VLD_SHIFT)) & XRDC2_PAC_PDAC_W1_VLD_MASK)

/* The count of XRDC2_PAC_PDAC_W1 */
#define XRDC2_PAC_PDAC_W1_COUNT                  (8U)

/* The count of XRDC2_PAC_PDAC_W1 */
#define XRDC2_PAC_PDAC_W1_COUNT2                 (256U)

/*! @name MRC_MRGD_W0 - Memory Region Descriptor */
#define XRDC2_MRC_MRGD_W0_SRTADDR_MASK           (0xFFFFF000U)
#define XRDC2_MRC_MRGD_W0_SRTADDR_SHIFT          (12U)
#define XRDC2_MRC_MRGD_W0_SRTADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W0_SRTADDR_SHIFT)) & XRDC2_MRC_MRGD_W0_SRTADDR_MASK)

/* The count of XRDC2_MRC_MRGD_W0 */
#define XRDC2_MRC_MRGD_W0_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W0 */
#define XRDC2_MRC_MRGD_W0_COUNT2                 (32U)

/*! @name MRC_MRGD_W1 - Memory Region Descriptor */
#define XRDC2_MRC_MRGD_W1_SRTADDR_MASK           (0xFU)
#define XRDC2_MRC_MRGD_W1_SRTADDR_SHIFT          (0U)
#define XRDC2_MRC_MRGD_W1_SRTADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W1_SRTADDR_SHIFT)) & XRDC2_MRC_MRGD_W1_SRTADDR_MASK)

/* The count of XRDC2_MRC_MRGD_W1 */
#define XRDC2_MRC_MRGD_W1_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W1 */
#define XRDC2_MRC_MRGD_W1_COUNT2                 (32U)

/*! @name MRC_MRGD_W2 - Memory Region Descriptor */
#define XRDC2_MRC_MRGD_W2_ENDADDR_MASK           (0xFFFFF000U)
#define XRDC2_MRC_MRGD_W2_ENDADDR_SHIFT          (12U)
#define XRDC2_MRC_MRGD_W2_ENDADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W2_ENDADDR_SHIFT)) & XRDC2_MRC_MRGD_W2_ENDADDR_MASK)

/* The count of XRDC2_MRC_MRGD_W2 */
#define XRDC2_MRC_MRGD_W2_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W2 */
#define XRDC2_MRC_MRGD_W2_COUNT2                 (32U)

/*! @name MRC_MRGD_W3 - Memory Region Descriptor */
#define XRDC2_MRC_MRGD_W3_ENDADDR_MASK           (0xFU)
#define XRDC2_MRC_MRGD_W3_ENDADDR_SHIFT          (0U)
#define XRDC2_MRC_MRGD_W3_ENDADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W3_ENDADDR_SHIFT)) & XRDC2_MRC_MRGD_W3_ENDADDR_MASK)

/* The count of XRDC2_MRC_MRGD_W3 */
#define XRDC2_MRC_MRGD_W3_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W3 */
#define XRDC2_MRC_MRGD_W3_COUNT2                 (32U)

/*! @name MRC_MRGD_W4 - Memory Region Descriptor */
#define XRDC2_MRC_MRGD_W4_RMSG_MASK              (0xFU)
#define XRDC2_MRC_MRGD_W4_RMSG_SHIFT             (0U)
#define XRDC2_MRC_MRGD_W4_RMSG(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W4_RMSG_SHIFT)) & XRDC2_MRC_MRGD_W4_RMSG_MASK)
#define XRDC2_MRC_MRGD_W4_DET_MASK               (0x10000000U)
#define XRDC2_MRC_MRGD_W4_DET_SHIFT              (28U)
#define XRDC2_MRC_MRGD_W4_DET(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W4_DET_SHIFT)) & XRDC2_MRC_MRGD_W4_DET_MASK)

/* The count of XRDC2_MRC_MRGD_W4 */
#define XRDC2_MRC_MRGD_W4_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W4 */
#define XRDC2_MRC_MRGD_W4_COUNT2                 (32U)

/*! @name MRC_MRGD_W5 - Memory Region Descriptor */
#define XRDC2_MRC_MRGD_W5_D0ACP_MASK             (0x7U)
#define XRDC2_MRC_MRGD_W5_D0ACP_SHIFT            (0U)
#define XRDC2_MRC_MRGD_W5_D0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D0ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D0ACP_MASK)
#define XRDC2_MRC_MRGD_W5_D1ACP_MASK             (0x38U)
#define XRDC2_MRC_MRGD_W5_D1ACP_SHIFT            (3U)
#define XRDC2_MRC_MRGD_W5_D1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D1ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D1ACP_MASK)
#define XRDC2_MRC_MRGD_W5_D2ACP_MASK             (0x1C0U)
#define XRDC2_MRC_MRGD_W5_D2ACP_SHIFT            (6U)
#define XRDC2_MRC_MRGD_W5_D2ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D2ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D2ACP_MASK)
#define XRDC2_MRC_MRGD_W5_D3ACP_MASK             (0xE00U)
#define XRDC2_MRC_MRGD_W5_D3ACP_SHIFT            (9U)
#define XRDC2_MRC_MRGD_W5_D3ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D3ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D3ACP_MASK)
#define XRDC2_MRC_MRGD_W5_D4ACP_MASK             (0x7000U)
#define XRDC2_MRC_MRGD_W5_D4ACP_SHIFT            (12U)
#define XRDC2_MRC_MRGD_W5_D4ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D4ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D4ACP_MASK)
#define XRDC2_MRC_MRGD_W5_D5ACP_MASK             (0x38000U)
#define XRDC2_MRC_MRGD_W5_D5ACP_SHIFT            (15U)
#define XRDC2_MRC_MRGD_W5_D5ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D5ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D5ACP_MASK)
#define XRDC2_MRC_MRGD_W5_D6ACP_MASK             (0x1C0000U)
#define XRDC2_MRC_MRGD_W5_D6ACP_SHIFT            (18U)
#define XRDC2_MRC_MRGD_W5_D6ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D6ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D6ACP_MASK)
#define XRDC2_MRC_MRGD_W5_D7ACP_MASK             (0xE00000U)
#define XRDC2_MRC_MRGD_W5_D7ACP_SHIFT            (21U)
#define XRDC2_MRC_MRGD_W5_D7ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D7ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D7ACP_MASK)
#define XRDC2_MRC_MRGD_W5_EALO_MASK              (0xF000000U)
#define XRDC2_MRC_MRGD_W5_EALO_SHIFT             (24U)
#define XRDC2_MRC_MRGD_W5_EALO(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_EALO_SHIFT)) & XRDC2_MRC_MRGD_W5_EALO_MASK)

/* The count of XRDC2_MRC_MRGD_W5 */
#define XRDC2_MRC_MRGD_W5_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W5 */
#define XRDC2_MRC_MRGD_W5_COUNT2                 (32U)

/*! @name MRC_MRGD_W6 - Memory Region Descriptor */
#define XRDC2_MRC_MRGD_W6_D8ACP_MASK             (0x7U)
#define XRDC2_MRC_MRGD_W6_D8ACP_SHIFT            (0U)
#define XRDC2_MRC_MRGD_W6_D8ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D8ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D8ACP_MASK)
#define XRDC2_MRC_MRGD_W6_D9ACP_MASK             (0x38U)
#define XRDC2_MRC_MRGD_W6_D9ACP_SHIFT            (3U)
#define XRDC2_MRC_MRGD_W6_D9ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D9ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D9ACP_MASK)
#define XRDC2_MRC_MRGD_W6_D10ACP_MASK            (0x1C0U)
#define XRDC2_MRC_MRGD_W6_D10ACP_SHIFT           (6U)
#define XRDC2_MRC_MRGD_W6_D10ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D10ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D10ACP_MASK)
#define XRDC2_MRC_MRGD_W6_D11ACP_MASK            (0xE00U)
#define XRDC2_MRC_MRGD_W6_D11ACP_SHIFT           (9U)
#define XRDC2_MRC_MRGD_W6_D11ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D11ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D11ACP_MASK)
#define XRDC2_MRC_MRGD_W6_D12ACP_MASK            (0x7000U)
#define XRDC2_MRC_MRGD_W6_D12ACP_SHIFT           (12U)
#define XRDC2_MRC_MRGD_W6_D12ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D12ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D12ACP_MASK)
#define XRDC2_MRC_MRGD_W6_D13ACP_MASK            (0x38000U)
#define XRDC2_MRC_MRGD_W6_D13ACP_SHIFT           (15U)
#define XRDC2_MRC_MRGD_W6_D13ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D13ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D13ACP_MASK)
#define XRDC2_MRC_MRGD_W6_D14ACP_MASK            (0x1C0000U)
#define XRDC2_MRC_MRGD_W6_D14ACP_SHIFT           (18U)
#define XRDC2_MRC_MRGD_W6_D14ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D14ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D14ACP_MASK)
#define XRDC2_MRC_MRGD_W6_D15ACP_MASK            (0xE00000U)
#define XRDC2_MRC_MRGD_W6_D15ACP_SHIFT           (21U)
#define XRDC2_MRC_MRGD_W6_D15ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D15ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D15ACP_MASK)
#define XRDC2_MRC_MRGD_W6_EAL_MASK               (0x3000000U)
#define XRDC2_MRC_MRGD_W6_EAL_SHIFT              (24U)
#define XRDC2_MRC_MRGD_W6_EAL(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_EAL_SHIFT)) & XRDC2_MRC_MRGD_W6_EAL_MASK)
#define XRDC2_MRC_MRGD_W6_DL2_MASK               (0x60000000U)
#define XRDC2_MRC_MRGD_W6_DL2_SHIFT              (29U)
#define XRDC2_MRC_MRGD_W6_DL2(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_DL2_SHIFT)) & XRDC2_MRC_MRGD_W6_DL2_MASK)
#define XRDC2_MRC_MRGD_W6_VLD_MASK               (0x80000000U)
#define XRDC2_MRC_MRGD_W6_VLD_SHIFT              (31U)
#define XRDC2_MRC_MRGD_W6_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_VLD_SHIFT)) & XRDC2_MRC_MRGD_W6_VLD_MASK)

/* The count of XRDC2_MRC_MRGD_W6 */
#define XRDC2_MRC_MRGD_W6_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W6 */
#define XRDC2_MRC_MRGD_W6_COUNT2                 (32U)


/*!
 * @}
 */ /* end of group XRDC2_Register_Masks */


/* XRDC2 - Peripheral instance base addresses */
/** Peripheral XRDC2 base address */
#define XRDC2_BASE                               (0u)
/** Peripheral d_ip_xrdc2_syn base pointer */
#define XRDC2                                    ((XRDC2_Type *)XRDC2_BASE)
/** Array initializer of XRDC2 peripheral base addresses */
#define XRDC2_BASE_ADDRS                         { XRDC2_BASE }
/** Array initializer of XRDC2 peripheral base pointers */
#define XRDC2_BASE_PTRS                          { XRDC2 }

/*!
 * @}
 */ /* end of group XRDC2_Peripheral_Access_Layer */


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


#endif  /* XRDC2_H */

