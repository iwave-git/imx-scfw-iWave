/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright 2019 NXP
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
 * @file MX8_ecsr_reset.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for ESCR Peripheral Reset
 *
 * CMSIS Peripheral Access Layer for ECSR Reset
 */

#ifndef ECSR_RESET_H
#define ECSR_RESET_H                                /**< Symbol preventing repeated inclusion */

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
   -- ECSR Reset Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ECSR_Reset_Peripheral_Access_Layer ECSR Reset Peripheral Access Layer
 * @{
 */

/** ECSR Reset - Register Layout Typedef */
typedef struct {
  __IO uint32_t ECSR_PER_RESET_REQ[4];                              /**< offset: 0x00 */
  __I  uint32_t ECSR_PER_RESET_ACK[4];                              /**< offset: 0x10 */
  __IO uint32_t ECSR_PER_CLK_STOP_REQ[4];                           /**< offset: 0x20 */
  __I  uint32_t ECSR_PER_CLK_STOP_ACK[4];                           /**< offset: 0x30 */
  __IO uint32_t ECSR_PER_BUS_IDLE_REQ[4];                           /**< offset: 0x40 */
  __I  uint32_t ECSR_PER_BUS_IDLE_ACK[4];                           /**< offset: 0x50 */
  __IO uint32_t ECSR_PER_BUS_BLACK_HOLE[4];                         /**< offset: 0x60 */
} ECSR_Reset_Type;

/* ECSR Reset - Peripheral instance base addresses */
/** Peripheral ECSR Reset base address */
#define ECSR_RESET_BASE                         (0u)
/** Peripheral ECSR Reset base pointer */
#define ECSR_RESET                              ((ECSR_Reset_Type *)ECSR_RESET_BASE)
/** Array initializer of ECSR Reset peripheral base addresses */
#define ECSR_RESET_BASE_ADDRS                   { ECSR_RESET_BASE }
/** Array initializer of ECSR Reset peripheral base pointers */
#define ECSR_RESET_BASE_PTRS                    { ECSR_RESET }

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


#endif  /* ECSR_RESET_H */

