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
 * Header file for the system controller debug functionality.
 */
/*==========================================================================*/

#ifndef DEBUG_H
#define DEBUG_H

/* Includes */

/* Debug Switches */

/*! This define sets the global debug level:
* - 0=Nothing
* - 1=+Banners
* - 2=+Data Dumps
* - 3=+Function entry/exit
* - 4=+Internal inline data
* - 5=All
*/
#define DEBUG_LEVEL         2

#define DEBUG_BOOT
//#define DEBUG_DRV
//#define DEBUG_SS
//#define DEBUG_IRQ
//#define DEBUG_MISC
//#define DEBUG_PAD
//#define DEBUG_PM
//#define DEBUG_RM
//#define DEBUG_TIMER
#define DEBUG_BOARD
#define DEBUG_TEST
//#define DEBUG_DDRC
#define DEBUG_PMIC
//#define DEBUG_SOC
//#define DEBUG_SECO
//#define DEBUG_V2X

#define DEBUG_RM_DUMP       4
#define DEBUG_SS_DUMP(args...)      ss_print(2, args)
#define DEBUG_SS_DSC_PM(args...)    ss_print(2, args)
#define DEBUG_DRV_DSC(args...)      drv_print(2, args)
#define DEBUG_DRV_DSC_DUMP(args...) drv_print(4, args)
#define DEBUG_DRV_XRDC2(args...)    drv_print(5, args)
#define DEBUG_AI_DUMP(args...)      debug_print(2, args)

#ifndef HAS_TEST
    #if 0
        #define DEBUG_RPC
    #endif
#endif

/* SIMU Debug */

#ifndef RD
    #ifdef SIMU
        #undef  DEBUG_LEVEL
        #define DEBUG_LEVEL         3
        #define DEBUG_BOOT
        #define DEBUG_DRV
        #define DEBUG_SS
        #define DEBUG_IRQ
        #define DEBUG_MISC
        #define DEBUG_PAD
        #define DEBUG_PM
        #define DEBUG_RM
        #define DEBUG_TIMER
        #define DEBUG_BOARD
        #define DEBUG_TEST
        #undef  DEBUG_RM_DUMP
        #define DEBUG_RM_DUMP       3
        #undef  DEBUG_SS_DUMP
        #define DEBUG_SS_DUMP(args...)      ss_print(3, args)
        #undef  DEBUG_SS_DSC_PM
        #define DEBUG_SS_DSC_PM(args...)    ss_print(2, args)
        #undef  DEBUG_DRV_DSC
        #define DEBUG_DRV_DSC(args...)      drv_print(2, args)
        #undef  DEBUG_DRV_DSC_DUMP
        #define DEBUG_DRV_DSC_DUMP(args...) drv_print(3, args)
        #undef  DEBUG_DRV_XRDC2
        #define DEBUG_DRV_XRDC2(args...)    drv_print(5, args)
        #undef  DEBUG_AI_DUMP
        #define DEBUG_AI_DUMP(args...)      debug_print(2, args)
    #endif
#endif

#ifdef MONITOR
    #define DEBUG_DRV
    #define DEBUG_SS
    #undef  DEBUG_SS_DUMP
    #define DEBUG_SS_DUMP(args...)      ss_print(0, args)
    #undef  DEBUG_DRV_DSC_DUMP
    #define DEBUG_DRV_DSC_DUMP(args...) drv_print(0, args)
    #undef  DEBUG_LEVEL
    #define DEBUG_LEVEL         1
#endif

#ifdef DL
    #undef  DEBUG_LEVEL
    #define DEBUG_LEVEL         DL
#endif

#ifdef TL
    #define TL1                  TL
    #define TL2                  TL
    #define TL3                  3
#else
    #define TL1                  1
    #define TL2                  2
    #define TL3                  3
#endif

/* Defines */

#ifdef DEBUG
    #define debug0_print(...) \
               board_printf(__VA_ARGS__);
#else
    #define debug0_print(args...) \
        NOP
#endif

#if 1 <= DEBUG_LEVEL
    #define debug1_print(...) \
               board_printf(__VA_ARGS__);
#else
    #define debug1_print(args...) \
        NOP
#endif

#if 2 <= DEBUG_LEVEL
    #define debug2_print(...) \
               board_printf(__VA_ARGS__);
#else
    #define debug2_print(args...) \
        NOP
#endif

#if 3 <= DEBUG_LEVEL
    #define debug3_print(...) \
               board_printf(__VA_ARGS__);
#else
    #define debug3_print(args...) \
        NOP
#endif

#if 4 <= DEBUG_LEVEL
    #define debug4_print(...) \
               board_printf(__VA_ARGS__);
#else
    #define debug4_print(args...) \
        NOP
#endif

#if 5 <= DEBUG_LEVEL
    #define debug5_print(...) \
               board_printf(__VA_ARGS__);
#else
    #define debug5_print(args...) \
        NOP
#endif

#ifdef DEBUG
    #define debug_print(dl, args...) \
        debug##dl##_print(args)
#else
    #define debug_print(args...) \
        NOP
#endif

#ifdef DEBUG_BOOT
    #define boot_print(dl, args...) \
        debug_print(dl, args)
#else
    #define boot_print(args...) \
        NOP
#endif

#ifdef DEBUG_DRV
    #define drv_print(dl, args...) \
        debug_print(dl, args)
#else
    #define drv_print(args...) \
        NOP
#endif

#ifdef DEBUG_SOC
    #define soc_print(dl, args...) \
        debug_print(dl, args)
#else
    #define soc_print(args...) \
        NOP
#endif

#ifdef DEBUG_SS
    #define ss_print(dl, args...) \
        debug_print(dl, args)
#else
    #define ss_print(args...) \
        NOP
#endif

#ifdef DEBUG_IRQ
    #define irq_print(dl, args...) \
        debug_print(dl, args)
#else
    #define irq_print(args...) \
        NOP
#endif

#ifdef DEBUG_MISC
    #define misc_print(dl, args...) \
        debug_print(dl, args)
#else
    #define misc_print(args...) \
        NOP
#endif

#ifdef DEBUG_PAD
    #define pad_print(dl, args...) \
        debug_print(dl, args)
#else
    #define pad_print(args...) \
        NOP
#endif

#ifdef DEBUG_PM
    #define pm_print(dl, args...) \
        debug_print(dl, args)
#else
    #define pm_print(args...) \
        NOP
#endif

#ifdef DEBUG_RM
    #define rm_print(dl, args...) \
        debug_print(dl, args)
#else
    #define rm_print(args...) \
        NOP
#endif

#ifdef DEBUG_TIMER
    #define timer_print(dl, args...) \
        debug_print(dl, args)
#else
    #define timer_print(args...) \
        NOP
#endif

#ifdef DEBUG_BOARD
    #define board_print(dl, args...) \
        debug_print(dl, args)
#else
    #define board_print(args...) \
        NOP
#endif

#ifdef DEBUG_TEST
    #define test_print(dl, args...) \
        debug_print(dl, args)
#else
    #define test_print(args...) \
        NOP
#endif

#ifdef DEBUG_RPC
    #define rpc_print(dl, args...) \
        debug_print(dl, args)
#else
    #define rpc_print(args...) \
        NOP
#endif

#ifdef DEBUG_DDRC
    #define ddrc_print(dl, args...)\
        debug_print(dl, args)
#else
    #define ddrc_print(args...) \
        NOP
#endif

#ifdef DEBUG_PMIC
    #define pmic_print(dl, args...)\
        debug_print(dl, args)
#else
    #define pmic_print(...) \
        NOP
#endif

#ifdef DEBUG_SECO
    #define seco_print(dl, args...) \
        debug_print(dl, args)
#else
    #define seco_print(args...) \
        NOP
#endif

#ifdef DEBUG_V2X
    #define v2x_print(dl, args...) \
        debug_print(dl, args)
#else
    #define v2x_print(args...) \
        NOP
#endif

#define debug_print_pk(dl, args...) \
    if (debug_level >= (dl)) \
    { \
        debug_print(0, args); \
    }

#define error_print(...) \
    debug_print(0, __VA_ARGS__)

#define always_print(...) \
    debug_print(0, __VA_ARGS__)

#endif /* DEBUG_H */

