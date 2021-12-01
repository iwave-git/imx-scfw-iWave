/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright 2018-2021 NXP
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
 * Header for handlers.
 */

#ifndef HANDLERS_H
#define HANDLERS_H

/* Includes */

/* Defines */

/* Types */

/* Functions */

void sc_handlers_init(void);
void DefaultISR(void);
void NMI_IRQHandler(uint32_t *sp);
void MCM_IRQHandler(uint32_t *sp);
void DebugWake_IRQHandler(void);
void SWI_IRQHandler(void);
void SWI_DQS2DQ_Handler(void);
void LPIT_SCU_IRQHandler(uint32_t *sp);
void DSC_SCU_IRQHandler(void);
void DSC_LSIO_IRQHandler(void);
void DSC_CM4_0_IRQHandler(void);
void DSC_CA35_IRQHandler(void);
void DSC_DRC_0_IRQHandler(void);
void DSC_GPU_0_IRQHandler(void);
void DSC_VPU_IRQHandler(void);
void DSC_ADMA_IRQHandler(void);
void IOMUX_CommonHandler(uint8_t irq, uint8_t ring, uint8_t group);
void IOMUX0_IRQHandler(void);
void IOMUX1_IRQHandler(void);
void IOMUX2_IRQHandler(void);
void IOMUX3_IRQHandler(void);
void IOMUX4_IRQHandler(void);
void IOMUX5_IRQHandler(void);
void IOMUX6_IRQHandler(void);
void IOMUX7_IRQHandler(void);
void IOMUX8_IRQHandler(void);
void IOMUX9_IRQHandler(void);
void IOMUX10_IRQHandler(void);
void IOMUX11_IRQHandler(void);
void IOMUX12_IRQHandler(void);
void SYSCTR_CMP0_IRQHandler(void);
void SYSCTR_CMP1_IRQHandler(void);
void SNVS_Functional_IRQHandler(void);
void ss_earlywdog_handler_sc(void);
void ss_csreq_handler_a35(uint32_t idx, uint32_t cpwrupreq);
void ss_csreq_handler_mcu(uint32_t idx, uint32_t cpwrupreq);
void ss_csreq_handler_dbgpwrup(uint32_t idx, uint32_t cpwrupreq);
#if HAS_SS_AP_2
sc_bool_t ss_dbg_status_a35(sc_dsc_t dsc);
void ss_dbg_resume_a35(sc_dsc_t dsc);
#endif

/* Global Variables */

extern uint32_t gLPITcnt;

#endif  /* #if !defined(HANDLERS_H) */

