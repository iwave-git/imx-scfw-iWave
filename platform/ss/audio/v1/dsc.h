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
 * File containing the subsystem specific DSC header info.
 *
 * @addtogroup AUDIO_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_AUDIO_DSC_H
#define SC_SS_AUDIO_DSC_H

/* Includes */

#include "ss/base/v1/dsc.h"

/*!
 * @name GPR Control 1 Bit Definitions
 */
/** @{ */
#define GPR_EDMA_IPDA_CHICKEN_OUT0  REGBIT(1, 32)
#define GPR_EDMA_IPDA_CHICKEN_OUT1  REGBIT(1, 33)
#define GPR_EDMA_IPDA_CHICKEN_OUT2  REGBIT(1, 34)
#define GPR_EDMA_IPDA_CHICKEN_OUT3  REGBIT(1, 35)
#define GPR_EDMA_IPDA_CHICKEN_OUT4  REGBIT(1, 36)
#define GPR_EDMA_IPDA_CHICKEN_OUT5  REGBIT(1, 37)
#define GPR_EDMA_IPDA_CHICKEN_OUT6  REGBIT(1, 38)
#define GPR_EDMA_IPDA_CHICKEN_OUT7  REGBIT(1, 39)
#define GPR_EDMA_IPDA_CHICKEN_OUT8  REGBIT(1, 40)
#define GPR_EDMA_IPDA_CHICKEN_OUT9  REGBIT(1, 41)
#define GPR_EDMA_IPDA_CHICKEN_OUT10 REGBIT(1, 42)
#define GPR_EDMA_IPDA_CHICKEN_OUT11 REGBIT(1, 43)
#define GPR_EDMA_IPDA_CHICKEN_OUT12 REGBIT(1, 44)
#define GPR_EDMA_IPDA_CHICKEN_OUT13 REGBIT(1, 45)
#define GPR_EDMA_IPDA_CHICKEN_OUT14 REGBIT(1, 46)
#define GPR_EDMA_IPDA_CHICKEN_OUT15 REGBIT(1, 47)
#define GPR_EDMA_IPDA_CHICKEN_OUT16 REGBIT(1, 48)
#define GPR_EDMA_IPDA_CHICKEN_OUT17 REGBIT(1, 49)
#define GPR_EDMA_IPDA_CHICKEN_OUT18 REGBIT(1, 50)
#define GPR_EDMA_IPDA_CHICKEN_OUT19 REGBIT(1, 51)
#define GPR_EDMA_IPDA_CHICKEN_OUT20 REGBIT(1, 52)
#define GPR_EDMA_IPDA_CHICKEN_OUT21 REGBIT(1, 53)
#define GPR_EDMA_IPDA_CHICKEN_OUT22 REGBIT(1, 54)
#define GPR_EDMA_IPDA_CHICKEN_OUT23 REGBIT(1, 55)
#define GPR_EDMA_IPDA_CHICKEN_OUT24 REGBIT(1, 56)
#define GPR_EDMA_IPDA_CHICKEN_OUT25 REGBIT(1, 57)
#define GPR_EDMA_IPDA_CHICKEN_OUT26 REGBIT(1, 58)
#define GPR_EDMA_IPDA_CHICKEN_OUT27 REGBIT(1, 59)
#define GPR_EDMA_IPDA_CHICKEN_OUT28 REGBIT(1, 60)
#define GPR_EDMA_IPDA_CHICKEN_OUT29 REGBIT(1, 61)
#define GPR_EDMA_IPDA_CHICKEN_OUT30 REGBIT(1, 62)
#define GPR_EDMA_IPDA_CHICKEN_OUT31 REGBIT(1, 63)
/** @} */

/*!
 * @name GPR Status 1 Bit Definitions
 */
/** @{ */
#define GPS_DMA0_IPG_STOP_ACK       REGBIT(1, 0)
#define GPS_DMA1_IPG_STOP_ACK       REGBIT(1, 1)
/** @} */

#endif /* SC_SS_AUDIO_DSC_H */

/** @} */

