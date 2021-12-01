/*
 * Copyright 2017-2021 NXP
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
#ifndef FSL_STC_H
#define FSL_STC_H

#include "fsl_common.h"

/*!
 * @addtogroup stc_driver
 * @{
 */

/*! @file*/

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/** @{ */
/*! @brief STC driver version 2.2.1. */
#define FSL_STC_DRIVER_VERSION (MAKE_VERSION(2, 2, 1))
/** @} */

/*! @brief STC interleave mode. */
typedef enum
{
    kSTC_Interleave4K = 0x0U,   /*!< 4K interleave */
    kSTC_Interleave8K = 0x1U,   /*!< 8K interleave */
    kSTC_Interleave16K = 0x2U,  /*!< 16K interleave */
    kSTC_InterleaveNone = 0x3U, /*!< No interleave */
} stc_interleave_mode_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!
 * @brief Set STC interleave.
 */
void STC_RIL_SetInterleave(STC_Type *base, stc_interleave_mode_t interleave);

/*!
 * @brief Set STC RCAT.
 */
void STC_RCAT_SetCategorization(STC_Type *base, uint8_t cat, uint32_t mask,
    uint32_t compare);

/*!
 * @brief Set STC RCAT.
 */
void STC_RCAT_SetStartStopTDM(STC_Type *base, uint8_t cat, uint8_t tdm,
    uint32_t start, uint32_t stop);

/*!
 * @brief Set STC RCAT.
 */
uint32_t STC_RCAT_GetHPR(const STC_Type *base, uint8_t cat);

/*!
 * @brief Set STC RCAT.
 */
void STC_RCAT_SetHPR(STC_Type *base, uint8_t cat, uint8_t hpr_qos_offset);

/*!
 * @brief Set STC panic QOS.
 */
void STC_QOS_Panic(STC_Type *base, uint8_t cat, uint8_t qos);

/*!
 * @brief Set STC UD disable.
 */
void STC_UD_DisableAll(STC_Type *base);

/*!
 * @brief Set STC UD enable threshold 1.
 */
void STC_UD_EnableThreshold1(STC_Type *base, uint8_t cat, uint8_t threshold, uint8_t qos);

/*!
 * @brief Set STC UD enable threshold 2.
 */
void STC_UD_EnableThreshold2(STC_Type *base, uint8_t cat, uint8_t threshold, uint8_t qos);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_STC_H */
