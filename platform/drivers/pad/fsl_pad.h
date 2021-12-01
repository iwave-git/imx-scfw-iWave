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

#ifndef DRV_PAD_H
#define DRV_PAD_H

/*!
 * @addtogroup pad_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"
#include "fsl_device_registers.h"

/* Defines */

/*!
 * This define is used to access PAD registers.
 */
#ifdef NO_DEVICE_ACCESS
    #define PAD_BASE_ADDR ((PADRING_Type*) (temp_pad))
#else
    #define PAD_BASE_ADDR ((PADRING_Type*) (PAD_BASE))
#endif

/* Types */

/* Externs */

#ifdef NO_DEVICE_ACCESS
    /*!
     * This variable is used to access fake pads.
     */
    extern uint8_t temp_pad[];
#endif

/* Functions */

void PAD_Init(void);
uint8_t PAD_ExtractMux(uint32_t val);
void PAD_Set(sc_saddr_t ofs, uint32_t val);
void PAD_Get(sc_saddr_t ofs, uint32_t *val);
void PAD_SetMux(sc_saddr_t ofs, uint8_t mux, uint8_t config,
    uint8_t iso);
void PAD_GetMux(sc_saddr_t ofs, uint8_t *mux, uint8_t *config,
    uint8_t *iso);
void PAD_SetGP(sc_saddr_t ofs, uint32_t ctrl);
void PAD_GetGP(sc_saddr_t ofs, uint32_t *ctrl);
#if FSL_FEATURE_PAD_HAS_28FDSOI
void PAD_SetGP28Fdsoi(sc_saddr_t ofs, uint8_t dse, uint8_t ps);
void PAD_GetGP28Fdsoi(sc_saddr_t ofs, uint8_t *dse, uint8_t *ps);
void PAD_SetGP28FdsoiHsic(sc_saddr_t ofs, uint8_t dse, sc_bool_t hys,
    uint8_t pus, sc_bool_t pke, sc_bool_t pue);
void PAD_GetGP28FdsoiHsic(sc_saddr_t ofs, uint8_t *dse, sc_bool_t *hys,
    uint8_t *pus, sc_bool_t *pke, sc_bool_t *pue);
void PAD_SetGP28FdsoiComp(sc_saddr_t ofs, uint8_t compen, sc_bool_t fastfrz,
    uint8_t rasrcp, uint8_t rasrcn, sc_bool_t nasrc_sel, sc_bool_t psw_ovr);
void PAD_GetGP28FdsoiComp(sc_saddr_t ofs, uint8_t *compen, sc_bool_t *fastfrz,
    uint8_t *rasrcp, uint8_t *rasrcn, sc_bool_t *nasrc_sel,  sc_bool_t *compok,
    uint8_t *nasrc, sc_bool_t *psw_ovr);
#endif
void PAD_SetWakeup(sc_saddr_t ofs, uint8_t wakeup);
void PAD_GetWakeup(sc_saddr_t ofs, uint8_t *wakeup);
void PAD_SetAll(sc_saddr_t ofs, uint8_t mux, uint8_t config,
    uint8_t iso, uint32_t ctrl, uint8_t wakeup);
void PAD_GetAll(sc_saddr_t ofs, uint8_t *mux, uint8_t *config,
    uint8_t *iso, uint32_t *ctrl, uint8_t *wakeup);

#ifdef DEBUG
    /*!
     * @name Debug Functions
     * @{
     */

    /*!
    * This function dumps the pads. It's only used for debug. Should
    * only be called if the power domain containing the PAD is powered on.
    */
    void PAD_Dump(void);

    /** @} */
#endif

#endif /* DRV_PAD_H */

/** @} */

