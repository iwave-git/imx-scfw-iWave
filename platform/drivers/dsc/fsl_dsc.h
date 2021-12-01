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

#ifndef DRV_DSC_H
#define DRV_DSC_H

/*!
 * @addtogroup dsc_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"
#include "fsl_device_registers.h"
#include "ss/inf/inf.h"

/* Defines */

#define DSC_SIZE              0x20000U  //!< Size of DSC address space

#define DSC_CLK_TYPE_W        4U        //!< Width of a clock type
#define DSC_INDEX_W           6U        //!< Width of the index
#define DSC_PDOM_W            3U        //!< Width of the power domain type
#define DSC_GPR_W             7U        //!< Width of the gpr bit type
#define DSC_PLLDIV_W          3U        //!< Width of the PLL DIV clk. 
#define DSC_CLK_SRC_W         3U        //!< Width of DSC CLK src 
#define DSC_AI_TYPE_W         2U        //!< Width of the AI type
#define DSC_CLK_MODE_W        3U        //!< Width of the DSC clock slice mode
#define DSC_NUM_LPCG_W        8U        //!< Width of the num lpcg

#define MEM_NORMAL            0U
#define MEM_ESILICON          1U

#define SLICE_SMALL_MULTI_MAX_DIV   31U
#define SLICE_LARGE_MAX_DIV         255U

/*!
 * @name Short defines for sc_pm_clk_parent_t
 */
/** @{ */
#define XTAL                           0U   /*! < Parent is XTAL. */
#define PLL0                           1U   /*! < Parent is PLL0 */
#define PLL1                           2U   /*! < Parent is PLL1 or PLL0/2 */
#define PLL2                           3U   /*! < Parent in PLL2 or PLL0/4 */
#define BYPS                           4U   /*! < Parent is a bypass clock. */
#define DUMMY                          5U   /*! < DUMMY entry               */
/** @} */

/*!
 * @name Defines for sc_pm_clk_mode_t
 */
/** @{ */
#define SC_PM_CLK_MODE_ROM_INIT        0U    /*!< Clock is initialized by ROM */
#define SC_PM_CLK_MODE_OFF             1U    /*!< Clock is disabled */
#define SC_PM_CLK_MODE_ON              2U    /*!< Clock is enabled */
#define SC_PM_CLK_MODE_AUTOGATE_SW     3U    /*!< Clock is in SW autogate mode */
#define SC_PM_CLK_MODE_AUTOGATE_HW     4U    /*!< Clock is in HW autogate mode */
#define SC_PM_CLK_MODE_AUTOGATE_SW_HW  5U    /*!< Clock is in SW-HW autogate mode */
/** @} */

/*!
 * This define is used to access DSC registers.
 */
#ifdef NO_DEVICE_ACCESS
    #define DSC_BASE_ADDR(X) ((DSC_Type*) (temp_dsc + ((X) * DSC_SIZE)))
#else
    #define DSC_BASE_ADDR(X) ((DSC_Type*) (MSI0_BASE + ((X) * DSC_SIZE)))
#endif

/*! Define to fill in a dsc_clk_info_t variable PLL_DIV set */
#define CNFO(R, S, G, RL, PD, CM, CT, I, DIV) \
    {                                         \
        .rate = (R),                          \
        .src = (S),                           \
        .sw_gate = (G),                       \
        .rate_locked = (RL),                  \
        .pd = (PD),                           \
        .clk_mode = (SC_PM_CLK_MODE_##CM),    \
        .clk_type = (DSC_##CT),               \
        .index = (I),                         \
        .pll_div = (DIV)                      \
    }

/* Types */

/*!
 * This type is used to declare a clock mode.
 */
typedef uint8_t sc_pm_clk_mode_t;

typedef uint8_t dsc_pdom_t;

#define DSC_SMALL_SINGLE_CLK_ROOT  0U
#define DSC_LARGE_SINGLE_CLK_ROOT  1U
#define DSC_MULTI_CLK_ROOT         2U
#define DSC_CPU_CLK_ROOT           3U
#define DSC_GPR_CLK_ROOT           4U
#define DSC_PLL_DUMMY              5U
#define DSC_BYPASS                 6U
#define DSC_XTAL                   7U
#define DSC_PLL_DIG                9U
#define DSC_PLL_PERF               10U
#define DSC_PLL_AV                 11U
#define DSC_PLL_DIG_AUD            12U

typedef uint8_t dsc_clk_type_t;

typedef uint32_t dsc_gpr_t;

/*!
 * This type is used to store static constant info about the clocks in
 * the subsystem. The clock indexes in the ss_rsrc_info references
 * this.
 */
typedef struct
{
    sc_pm_clock_rate_t rate;                            //!< Default clock rate
    sc_pm_clk_parent_t src      : DSC_CLK_SRC_W;        //!< Clock source for the slice
    uint8_t pll_div             : DSC_PLLDIV_W;         //!< Divided PLL is the source for the slice
    uint8_t sw_gate             : SC_BOOL_W;            //!< 0=no lpcg, 1=lpcg
    uint8_t rate_locked         : SC_BOOL_W;            //!< 0=user rated, 1=locked
    dsc_pdom_t pd               : DSC_PDOM_W;           //!< Power domain clock feeds
    sc_pm_clk_mode_t clk_mode   : SC_PM_CLOCK_MODE_W;   //!< Default clock mode when SS is powered up.
    dsc_clk_type_t clk_type     : DSC_CLK_TYPE_W;       //!< Type of clock slice
    uint8_t index               : DSC_INDEX_W;          //!< Index into clock/PLL type
} dsc_clk_info_t;

#define AI_NONE     0U
#define AI_COMMON   1U
#define AI_TEMP     2U
#define AI_TEMP_SEQ 3U

typedef uint8_t dsc_ai_type_t;

typedef struct
{
    uint32_t div0;
    uint32_t div1;
    uint32_t div2;
    uint32_t div3;
} dsc_mslice_div_t;

/* Externs */

#ifdef NO_DEVICE_ACCESS
    /*!
     * This variable is used to access fake DSCs.
     */
    extern uint8_t temp_dsc[];
    #define HAS_TEMP_DSC
    /*!
     * This variable is used to access fake DSC AIs.
     */
    extern uint32_t temp_dsc_ai[][32][32];
    extern sc_bool_t temp_ai_direct;
    #define HAS_TEMP_DSC_AI

    #define DSC_AI_DIRECT(X)    temp_ai_direct = (X)
#else
    #define DSC_AI_DIRECT(X)    NOP
#endif

/* Functions */

/*!
 * @name Initialization Functions
 * @{
 */

/*!
 * This function initializes the DSC AON HW. It's mostly used to initialize
 * fake HW for the simulation builds to have the correct reset state.
 *
 * @param[in]     dsc         DSC to initialize
 * @param[in]     ai_type     type of analog interface
 *
 * This is only called once at startup. It is not a reset and should not be
 * called when a subsystem is powered up.
 */
void DSC_Init(sc_dsc_t dsc, dsc_ai_type_t ai_type);

void DSC_Reset(uint8_t pd, sc_dsc_t dsc, uint32_t reset_mask);
void DSC_SetReset(sc_dsc_t dsc, uint32_t val, sc_bool_t enable);
uint32_t DSC_GetReset(sc_dsc_t dsc);
void DSC_SetMemTiming(sc_dsc_t dsc, sc_bool_t hs_enable,
                            sc_bool_t ls_enable, uint8_t pd);
void DSC_SetGPRControl(sc_dsc_t dsc, uint32_t gpr_num, uint32_t gpr_val,
    sc_bool_t enable);
void DSC_InsGPRControl(sc_dsc_t dsc, uint32_t gpr_num, uint32_t gpr_pos,
    uint32_t mask, uint32_t val);
uint32_t DSC_GetGPRControl(sc_dsc_t dsc, uint32_t gpr_num);
uint32_t DSC_GetGPRStatus(sc_dsc_t dsc, uint32_t gpr_num);
void DSC_WaitGPRStatus(sc_dsc_t dsc, uint32_t gpr_num, uint32_t gpr_mask,
    uint32_t gpr_val);
void DSC_EnableIrq(sc_dsc_t dsc, uint64_t mask, sc_bool_t enable);
uint64_t DSC_GetIrqPending(sc_dsc_t dsc);
uint64_t DSC_GetIrqStatus(sc_dsc_t dsc);

void DSC_EnableAnamixAI(sc_dsc_t dsc);
sc_bool_t DSC_AnamixAIEnabled(sc_dsc_t dsc);
#ifndef NO_ANAMIX
void DSC_DisableAnamixAI(sc_dsc_t dsc);
void DSC_EnablePhymixAI(sc_dsc_t dsc);
#endif

#ifdef ANAMIX_BROADCAST
void DSC_AIBroadcastWrite(sc_dsc_t dsc, uint32_t toggle, uint16_t addr,
    uint32_t data);
#endif
void DSC_AIRegisterWrite(sc_dsc_t dsc, uint8_t src_sel, uint16_t addr,
    uint32_t data);
void DSC_AIRegisterRead(sc_dsc_t dsc, uint8_t src_sel, uint16_t addr,
    uint32_t *data);

/** @} */

/*!
 * @name Power Functions
 * @{
 */
sc_bool_t DSC_PdEnabled(uint8_t pd, sc_dsc_t dsc);
void DSC_PdEnable(uint8_t pd, sc_dsc_t dsc, uint8_t ss_pd,
    uint32_t reset_mask, sc_bool_t reboot);
void DSC_PdDisable(uint8_t pd, sc_dsc_t dsc, uint8_t ss_pd,
    uint32_t reset_mask, sc_bool_t reboot);
void DSC_IsolationDisable(sc_dsc_t dsc, uint8_t pd, uint8_t misc,
    sc_bool_t enable);

/** @} */

/*!
 * @name Clock Functions
 * @{
 */
sc_bool_t DSC_SliceReset(sc_dsc_t dsc, const dsc_clk_info_t *clk_info);
sc_err_t DSC_CheckClockMode(sc_dsc_t dsc,
    const dsc_clk_info_t *clk, sc_pm_clk_mode_t mode);
void DSC_SetClockMode(sc_dsc_t dsc, const dsc_clk_info_t *clk,
    sc_pm_clk_mode_t mode);
void DSC_ClkSetRate(sc_dsc_t dsc, const dsc_clk_info_t *clk,
    uint32_t rate_div, uint32_t parent_rate);
void DSC_MSliceGetDiv(sc_dsc_t dsc, dsc_mslice_div_t *p_mslice_div);
void DSC_MSliceSetDiv(sc_dsc_t dsc, const dsc_mslice_div_t *p_mslice_div);
void DSC_ClkSetParent(sc_dsc_t dsc, const dsc_clk_info_t *clk,
    sc_pm_clk_parent_t parent);
sc_pm_clk_parent_t DSC_ClkGetParent(sc_dsc_t dsc, const dsc_clk_info_t *clk);
uint32_t DSC_ClkGetRateDiv(sc_dsc_t dsc, const dsc_clk_info_t *clk);
void DSC_FuncClkToggle(sc_dsc_t dsc, dsc_clk_type_t clk_type, uint32_t val, sc_bool_t enable);

/** @} */

/*!
 * @name AI Clock Functions
 * @{
 */
sc_bool_t DSC_AIPllEnabled(sc_dsc_t dsc, uint8_t pll_index, dsc_clk_type_t pll_type);
void DSC_AIPllEnable(sc_dsc_t dsc, uint8_t pll_index,
    dsc_clk_type_t pll_type);
uint32_t DSC_AIPllGetRate(sc_dsc_t dsc, uint8_t pll_index,
    dsc_clk_type_t pll_type);
uint32_t DSC_AIPllSetRate(sc_dsc_t dsc, uint8_t pll_index,
    dsc_clk_type_t pll_type, uint32_t rate, sc_bool_t powered, sc_bool_t ssc_enable);
void DSC_AIPllDisable(sc_dsc_t dsc, uint8_t pll_index,
    dsc_clk_type_t pll_type);
uint32_t DSC_CalcBestPllFreqParent(dsc_clk_type_t pll_type, uint32_t rate, 
    sc_pm_clk_parent_t *parent, sc_bool_t fixed_parent, uint32_t max_div);

/** @} */

/*!
 * @name AI Temp Sensor Functions
 * @{
 */

void DSC_AIPowerTemp(sc_dsc_t dsc, sc_bool_t enable, sc_bool_t run);
void DSC_AITriggerTemp(sc_dsc_t dsc);
void DSC_AISetTemp(sc_dsc_t dsc, uint32_t idx, uint16_t val);
sc_err_t DSC_AIGetTemp(sc_dsc_t dsc, uint32_t idx, uint16_t *val);
void DSC_AIClearTemp(sc_dsc_t dsc, uint32_t idx);
void DSC_AIDisablePanicTemp(sc_dsc_t dsc);

/** @} */

#if defined(DEBUG) || defined(GCOV)
    /*!
     * @name Debug Functions
     * @{
     */

    /*!
    * This function dumps the DSC. It's only used for debug. Should
    * only be called if the power domain containing the DSC is powered on.
    */
    void DSC_Dump(sc_dsc_t dsc);

    /** @} */
#endif

#endif /* DRV_DSC_H */

/** @} */

