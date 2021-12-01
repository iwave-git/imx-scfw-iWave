/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
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
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @file
 *
 * Header file used to configure the top-level SCFW.
 *
 */
/*==========================================================================*/

#ifndef SC_CONFIG_H
#define SC_CONFIG_H

/* Includes */

#include "main/debug.h"
#include "soc.h"
#include "board.h"
#include "pads.h"
#include "pad_data.h"

/* Test Switches */

#if DEBUG_LEVEL > 1
    #define HAS_CHECK_CONFIG
#endif
#if 0
    #define HAS_TEST_PTIM
    #define HAS_TEST_PCNT
#endif

/* Hardware Switches */

#define HAS_XRDC_HW
#define HAS_PAD_HW

/* Configure Debugging & Profiling */

#ifdef SIMU
    #define TEST_PROF_THRESH_NS 2000U
#else
    #define TEST_PROF_THRESH_NS 10000U
#endif

/* Configure Addressing */

#define SC_SADDR_W              32U

typedef uintptr_t sc_saddr_t;

/* Configure System Controller */

#define SC_PT                   0U
#define SC_DID                  2U
#define SECO_PT                 2U
#define SECO_DID                1U
#define BOOT_PT                 1U
#define BOOT_DID                0U
#define SC_STATIC_PT            0U
#define SC_STATIC_DID           2U
#define SC_BYPASS_SID           0U
#define SC_SA                   SC_RM_SPA_ASSERT
#define SC_PA                   SC_RM_SPA_PASSTHRU
#define SC_MAX_SS_CLKS          32U

/* Configure IPC */

#define SC_IPC_LOOPBACK         SC_IPC_AP_CH0

/* Configure Resource Manager */

#define SC_RM_IDX_W             16U     //!< Width of sc_rm_idx_t
typedef uint16_t sc_rm_idx_t;           //!< Unified resource index

#define SC_RMS_IDX_W            8U      //!< Width of sc_rms_idx_t
typedef uint8_t sc_rms_idx_t;           //!< Unified small resource index

#define SC_RM_MATCH_W           16U     //!< Width of sc_rm_match_t
typedef uint16_t sc_rm_match_t;         //!< RDC match value

#define SC_RM_SID_MASK          0x3FU   //!< Mask for StreamID

#endif /* SC_CONFIG_H */

