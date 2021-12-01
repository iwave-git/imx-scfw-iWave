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

#ifndef DRV_ANALOG_H
#define DRV_ANALOG_H

#include "fsl_common.h"
#include "main/scfw.h"
#include "main/main.h"
#include "main/soc.h"

#define MAX_DRV_CUR    3U
#define MAX_TRIM       7U
#define MAX_CLKIN      3U

#define SE_XTAL_24MHZ       0x1U
#define DIFF_XTAL_24MHZ     0x2U

typedef struct
{
    uint32_t regl_lv;
    uint32_t regh_lv;
    uint32_t cl_tune_lv;
} xtalosc24_config_t;

typedef struct
{
    uint32_t drv0, drv1;
} root_config_t;

typedef struct
{
    uint32_t drv0, drv1;
    uint32_t drv_in;
    uint32_t term_res;
} rptr_config_t;

typedef struct
{
    uint32_t drv_in;
    uint32_t term_res, sqrup;
} term_config_t;

#ifndef NO_REFGEN
#ifdef AUTOCAL
uint32_t RefgenCalibrateAuto(uint8_t base_idx);
#endif
void RefgenSetup(uint8_t base_idx, uint32_t refgen, sc_bool_t anamix);
sc_bool_t RefgenEnabled(uint8_t base_idx, uint8_t tog);
sc_bool_t RefgenTrimmed(uint8_t base_idx, uint8_t tog);
void RefgenSetEn(uint8_t base_idx, uint8_t tog, sc_bool_t enable);
#endif
void BandgapSetEn(uint8_t base_idx, uint8_t tog, sc_bool_t enable);
void BandgapSetTrim(uint8_t base_idx, uint8_t tog, uint32_t trim_val);
void BandgapSelfBiasOff(uint8_t base_idx, uint8_t tog);
sc_bool_t PhyLdoEnabled(uint8_t base_idx, uint8_t tog);
void PhyLdoSetEn(uint8_t base_idx,uint8_t tog,uint32_t target,sc_bool_t enable);
sc_bool_t HPPllRegEnabled(uint8_t base_idx,uint8_t tog);
void HPPllRegSetEn(uint8_t base_idx,uint8_t tog, uint32_t target, sc_bool_t enable);
sc_bool_t AVPllRegEnabled(uint8_t base_idx, uint8_t tog);
void AVPllRegSetEn(uint8_t base_idx,uint8_t tog,uint32_t target, sc_bool_t enable);

/*!
 * Convert celsius to temp sensor value.
 *
 * @param[in]     base_idx    resource with sensor
 * @param[in]     celsius     whole part of temp
 * @param[in]     tenths      fractional part of temp
 * @param[out]    val         value to return
 */
void ANA_Temp2Val(uint8_t base_idx, int16_t celsius, int8_t tenths,
    uint32_t *val);
/*!
 * Convert temp sensor value to celsius.
 *
 * @param[in]     dsc         resource with sensor
 * @param[in]     val         value to convert
 * @param[out]    celsius     whole part of temp to return
 * @param[out]    tenths      fractional part of temp to return
 */
void ANA_Val2Temp(uint8_t base_idx, uint32_t val, int16_t *celsius,
    int8_t *tenths);

void ANA_BIAS_Calc(uint8_t bias_encoded, uint8_t *asym, uint8_t *vctrl);
sc_bool_t ANA_BIAS_Enabled(uint8_t base_idx, uint8_t bias_mask);
void ANA_BIAS_SetupEn(uint8_t base_idx, uint8_t bias_mask, sc_bool_t enable,
        uint32_t delay);
void ANA_BIAS_ClearRefVCtrl(uint8_t base_idx);
void ANA_BIAS_SetRefVCtrl(uint8_t base_idx, uint8_t vctrl);

/* Diff Clock functions */
void ANA_XtalOsc24Init (uint32_t regl_lv, uint32_t regh_lv, uint32_t cl_tune_lv);
void ANA_DiffClkRootInit (uint32_t drv0, uint32_t drv1);
void ANA_DiffClkRptrInit (uint32_t drv0, uint32_t drv1, uint32_t drv_in,
        uint32_t term_res);
void ANA_DiffClkTermInit (uint32_t drv_in, uint32_t sqrup, uint32_t term_res);
void ANA_XtalOsc24Setup (uint8_t base_idx, uint8_t tog, sc_bool_t enable);
void ANA_DiffClkRootSetup (uint8_t base_idx, uint8_t tog, uint8_t clkin,
        sc_bool_t mux_en, sc_bool_t mux_en_diff, sc_bool_t enable);
void ANA_DiffClkRptrSetup (uint8_t base_idx, uint8_t tog, sc_bool_t standalone,
        uint32_t reg_trim, sc_bool_t enable);
void ANA_DiffClkTermSetup (uint8_t base_idx, uint8_t tog, sc_bool_t enable);

/* vdetect functions*/
void ANA_vdetect_init(sc_dsc_t dsc, uint8_t status_sel);
sc_err_t ANA_vdetect_find_dly(sc_dsc_t dsc, uint8_t *adly, uint8_t *fdly);

#endif
