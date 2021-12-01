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
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file MX8_csr.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for CSR
 *
 * CMSIS Peripheral Access Layer for CSR
 */

#ifndef CSR_H
#define CSR_H                                /**< Symbol preventing repeated inclusion */

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
   -- CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSR_Peripheral_Access_Layer CSR Peripheral Access Layer
 * @{
 */

/** CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR_LP_PG[16];                    /**< Control and Status Registers, LP_PG0-LP_PG3 offset 0x9000 */
  __IO uint32_t CSR_PORT_CONFIG;                   /**< Control and Status Registers, PORT_CONFIG offset 0x9040 */
       uint8_t RESERVED_18[188];
  __IO uint32_t GPR_CSR_CTRL[196];                /**< Control and Status Registers, offset 0x9100 */
} CSR_Type;

/** CSR2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPR_CSR_CTRL[256];                /**< Control and Status Registers, offset 0x9100 */
} CSR2_Type;

/* CSR - Peripheral instance base addresses */
/** Peripheral CSR base address */
#define CSR_BASE                               (0u)
/** Peripheral CSR base pointer */
#define CSR                                    ((CSR_Type *)CSR_BASE)
/** Array initializer of CSR peripheral base addresses */
#define CSR_BASE_ADDRS                         { CSR_BASE }
/** Array initializer of CSR peripheral base pointers */
#define CSR_BASE_PTRS                          { CSR }

/*!
 * @}
 */ /* end of group CSR_Peripheral_Access_Layer */


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


#endif  /* CSR_H */

