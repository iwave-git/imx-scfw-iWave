/*
 * Copyright 2019-2021 NXP
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

#ifndef DRV_V2X_H
#define DRV_V2X_H

/*!
 * @addtogroup v2x_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"

/* Defines */

/*!
 * @name Macros for version parsing
 */
/** @{ */
#define V2X_PROD_VER(X)      (((X) >> 16) & 0x7FFFUL)
#define V2X_MAJOR_VER(X)     (((X) >> 4) & 0xFFFUL)
#define V2X_MINOR_VER(X)     ((X) & 0xFUL)
/** @} */

/* Types */

/*!
 * This type is used to return the RNG initialization status.
 */
typedef uint32_t sc_v2x_rng_stat_t;

/* Functions */

/*!
 * @name Initialization Functions
 * @{
 */

/*!
 * This function initializes the V2X driver.
 *
 * Called when DB is powered up.
 */
void V2X_Init(void);

/*!
 * This function deinitializes the V2X driver.
 *
 * Called before DB is powered down.
 */
void V2X_Deinit(void);

/** @} */

/*!
 * @name Debug Functions
 * @{
 */

/*!
 * This function is used to return the V2X FW build info.
 *
 * @param[out]    version     pointer to return build number
 * @param[out]    commit      pointer to return commit ID (git SHA-1)
 * @param[out]    dirty       pointer to return dirty flag
 *
 * See the SECO API Reference Guide for more info.
 */
void V2X_Version(uint32_t *version, uint32_t *commit, sc_bool_t *dirty);

/*!
 * This function dumps low-level V2X debug info to the SCU debug
 * UART.
 *
 * @param[in]     mask        bit(0): logs from V2X primary core / bit(1): logs from secondary core
 */
void V2X_DumpDebug(uint32_t log_bitmap);
#define LOG_BITMAP_V2XP         0x1
#define LOG_BITMAP_V2XS         0x2

/** @} */

/*!
 * @name Miscellaneous Functions
 * @{
 */

/*!
 * This function sends a ping to V2X.
 *
 * See the V2X API Reference Guide for more info.
 */
void V2X_Ping(void);

/*!
 * This function configures the V2X ID ownership.
 *
 * @param[in]     id          index of ID 
 * @param[in]     sa          secure state
 * @param[in]     did         XRDC2 Domain ID
 *
 * Called by the Resource Manager to configure V2X ID parameters.
 *
 * See the SECO API Reference Guide for more info.
 */
void V2X_ID_Config(uint8_t id, sc_rm_spa_t sa, sc_rm_did_t did);

/*!
 * This function configures V2X MU ownership.
 *
 * @param[in]     mu          index of MU
 * @param[in]     sa          secure state
 * @param[in]     did         XRDC2 Domain ID
 *
 * Called by the Resource Manager to configure V2X MU access.
 *
 * See the SECO API Reference Guide for more info.
 */
void V2X_MU_Config(uint8_t mu, sc_rm_spa_t sa, sc_rm_did_t did);

/*!
 * This function notifies V2X of an MU power off.
 *
 * @param[in]     mu          index of MU
 *
 * Called by the Resource Manager to tell V2X MU is being powered off.
 *
 * See the SECO API Reference Guide for more info.
 */
void V2X_MU_PowerDown(uint8_t mu);

/*!
 * This function starts the random number generators.
 *
 * @return Returns the state of RNGs.
 *
 * See the SECO API Reference Guide for more info.
 */
sc_v2x_rng_stat_t V2X_StartRNG(void);

/*!
 * @brief V2X MU IRQ handler.
 *
 * This function is called when the V2X SCU/DEBUG MU asserts an interrupt.
 */
void V2X_MU_IRQHandler(void);

/** @} */

/* Externs */

/*! V2X error return */
extern sc_err_t v2x_err;

#endif /* DRV_V2X_H */

/** @} */

