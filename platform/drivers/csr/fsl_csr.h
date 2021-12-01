/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DRV_CSR_H
#define DRV_CSR_H

/*!
 * @addtogroup csr_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"
#include "fsl_device_registers.h"

/* Defines */

#if (defined(FSL_FEATURE_CSR_HAS_CSR) && FSL_FEATURE_CSR_HAS_CSR)
/*!
 * This define is used to access CSR registers.
 */
#define CSR_BASE_ADDR(X) ((CSR_Type*) (((sc_saddr_t) DSC_BASE_ADDR(X)) \
    + 0x9000U))
#endif

#if (defined(FSL_FEATURE_CSR_HAS_CSR2) && FSL_FEATURE_CSR_HAS_CSR2)
/*!
 * This define is used to access CSR2 registers.
 */
#define CSR2_BASE_ADDR(X) ((CSR2_Type*) (((sc_saddr_t) DSC_BASE_ADDR(X)) \
    + 0xF000U))

#endif

#if (defined(FSL_FEATURE_CSR_HAS_CSR3) && FSL_FEATURE_CSR_HAS_CSR3)
/*!
 * This define is used to access CSR3 registers.
 */
#define CSR3_BASE_ADDR(X) ((CSR2_Type*) (((sc_saddr_t) DSC_BASE_ADDR(X)) \
    + 0x9000U))
#endif

/* Types */

/* Functions */

#if (defined(FSL_FEATURE_CSR_HAS_CSR) && FSL_FEATURE_CSR_HAS_CSR)
void CSR_SetCSR(sc_dsc_t dsc, uint32_t csr_num, uint32_t csr_val,
    sc_bool_t enable);
uint32_t CSR_GetCSR(sc_dsc_t dsc, uint32_t csr_num);
#endif

#if (defined(FSL_FEATURE_CSR_HAS_CSR2) && FSL_FEATURE_CSR_HAS_CSR2)
void CSR_SetCSR2(sc_dsc_t dsc, uint32_t csr_num, uint32_t csr_val,
    sc_bool_t enable);
uint32_t CSR_GetCSR2(sc_dsc_t dsc, uint32_t csr_num);
#endif

#if (defined(FSL_FEATURE_CSR_HAS_CSR3) && FSL_FEATURE_CSR_HAS_CSR3)
void CSR_SetCSR3(sc_dsc_t dsc, uint32_t csr_num, uint32_t csr_val,
    sc_bool_t enable);
uint32_t CSR_GetCSR3(sc_dsc_t dsc, uint32_t csr_num);
#endif

#if (defined(FSL_FEATURE_CSR_HAS_LPCG) && FSL_FEATURE_CSR_HAS_LPCG)
void CSR_SetLPPG(sc_dsc_t dsc, uint32_t pg_num, uint32_t pg_val,
    sc_bool_t enable);
uint32_t CSR_GetLPPG(sc_dsc_t dsc, uint32_t pg_num);
#endif

#endif /* DRV_CSR_H */

/** @} */

