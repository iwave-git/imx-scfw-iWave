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

#ifndef DRV_XRDC2_H
#define DRV_XRDC2_H

/*!
 * @addtogroup xrdc2_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"

/* Defines */

#ifndef DEBUG
    #define XRDC_PAC_CHECK(X, Y)       NOP
#else    
    #define XRDC_PAC_CHECK(X, Y)       XRDC_PacCheck((X), (Y))
#endif

#define XRDC_BASE_ADDR(X) ((XRDC2_Type*) (((sc_saddr_t) DSC_BASE_ADDR(X)) \
    + 0x10000U))

#define XRDC_MAX_DOMAINS        16U

#define XRDC_MAX_PAC            8U
#define XRDC_MAX_PAC_SLOTS      256U
#define XRDC_MAX_MSC            128U
#define XRDC_MAX_MDAC           32U
#define XRDC_MAX_MDAC_SLOTS     32U
#define XRDC_MAX_MRC            32U
#define XRDC_MAX_MRC_SLOTS      32U

#define XRDC_IDX_W              16U
#define XRDC_DID_W              4U
#define XRDC_SID_W              16U
#define XRDC_MATCH_W            16U
#define XRDC_DET_W              1U
#define XRDC_RMSG_W             4U
#define XRDC_NUM_W              8U

/* Types */

typedef uint8_t xrdc_info_t;
typedef uint16_t xrdc_idx_t;
typedef uint8_t xrdc_did_t;
typedef uint16_t xrdc_match_t;
typedef uint8_t xrdc_det_t;
typedef uint8_t xrdc_rmsg_t;
typedef uint8_t xrdc_perm_t;

/*!
 * This type is used to store a XRDC SID value.
 */
typedef union
{
    uint16_t U;
    struct
    {
        uint16_t SID       : 6;
        uint16_t CID       : 4;
        uint16_t RESERVED0 : 6;
    } B;
} xrdc_sid_t;

/*!
 * This type is used to store info about a PAC.
 */
typedef struct
{
    uint32_t slot_en[XRDC_MAX_PAC_SLOTS/32];    //!< Slot enables
    dsc_pdom_t pd           : DSC_PDOM_W;       //!< Power domain
    sc_bool_t present            : SC_BOOL_W;        //!< Present
} xrdc_pac_info_t;

/* XRDC Functions */

/*!
 * @name Initialization Functions
 * @{
 */

void XRDC_Init(sc_dsc_t dsc);
sc_bool_t XRDC_Config(sc_dsc_t dsc, sc_bool_t mst_enable,
    sc_bool_t chk_enable);
void XRDC_GetConfig(sc_dsc_t dsc, sc_bool_t *mst_enable,
    sc_bool_t *chk_enable);
void XRDC_Status(sc_dsc_t dsc, xrdc_did_t *did, xrdc_info_t *hrl,
    xrdc_info_t *gclo);

/** @} */

/*!
 * @name MSC Functions
 * @{
 */

void XRDC_GetMsc(sc_dsc_t dsc, xrdc_idx_t idx, sc_bool_t *valid,
    sc_bool_t *lock, xrdc_perm_t *perms);
void XRDC_SetMsc(sc_dsc_t dsc, xrdc_idx_t idx, sc_bool_t valid, sc_bool_t lock,
    const xrdc_perm_t *perms);
void XRDC_SetMultiMsc(sc_dsc_t dsc, xrdc_idx_t start, xrdc_idx_t num,
    sc_bool_t valid, sc_bool_t lock, const xrdc_perm_t *perms);

/** @} */

/*!
 * @name MDAC Functions
 * @{
 */

void XRDC_GetMda(sc_dsc_t dsc, xrdc_idx_t idx, sc_bool_t *valid, sc_bool_t *lock,
    sc_rm_spa_t *sa, sc_rm_spa_t *pa, xrdc_did_t *did, xrdc_sid_t *sid,
    xrdc_match_t *match, xrdc_match_t *mask, sc_bool_t has_match,
    const uint32_t *cache);
void XRDC_SetMda(sc_dsc_t dsc, xrdc_idx_t idx, sc_bool_t valid, sc_bool_t lock,
    sc_rm_spa_t sa, sc_rm_spa_t pa, xrdc_did_t did, xrdc_sid_t sid,
    xrdc_match_t match, xrdc_match_t mask, sc_bool_t has_match,
    uint32_t *cache);

/** @} */

/*!
 * @name PAC Functions
 * @{
 */

void XRDC_GetPdac(sc_dsc_t dsc, xrdc_idx_t idx, sc_bool_t *valid,
    sc_bool_t *lock, xrdc_perm_t *perms);
void XRDC_SetPdac(sc_dsc_t dsc, xrdc_idx_t idx, sc_bool_t valid,
    sc_bool_t lock, const xrdc_perm_t *perms, sc_bool_t no_update);
void XRDC_SetMultiPdac(sc_dsc_t dsc, xrdc_idx_t start, xrdc_idx_t num,
    sc_bool_t valid, sc_bool_t lock, const xrdc_perm_t *perms,
    sc_bool_t no_update);

/** @} */

/*!
 * @name MRC Functions
 * @{
 */

void XRDC_GetMrc(sc_dsc_t dsc, xrdc_idx_t idx, sc_faddr_t *start,
    sc_faddr_t *end, sc_bool_t *valid, sc_bool_t *lock, xrdc_perm_t *perms,
    xrdc_det_t *det, xrdc_rmsg_t *rmsg, const uint32_t *cache);
void XRDC_SetMrc(sc_dsc_t dsc, xrdc_idx_t idx, sc_faddr_t start,
    sc_faddr_t end, sc_bool_t valid, sc_bool_t lock, const xrdc_perm_t *perms,
    xrdc_det_t det, xrdc_rmsg_t rmsg, uint32_t *cache);
void XRDC_InvalidateMrc(sc_dsc_t dsc, xrdc_idx_t idx,
    xrdc_idx_t regions, uint32_t *cache);
sc_bool_t XRDC_FindMrc(sc_dsc_t dsc, xrdc_idx_t *idx, sc_faddr_t start,
    sc_faddr_t end, xrdc_idx_t regions, uint32_t *cache);
sc_bool_t XRDC_UnusedMrc(sc_dsc_t dsc, xrdc_idx_t *idx,
    xrdc_idx_t regions, uint32_t *cache);

/** @} */

/*!
 * @name Debug Functions
 * @{
 */

#ifdef DEBUG
void XRDC_PacCheck(xrdc_idx_t num, const xrdc_pac_info_t *info);
#endif

/** @} */

#endif /* DRV_XRDC2_H */

/** @} */

