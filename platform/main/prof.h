/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2017-2020 NXP
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
 * Header file for the profiler implementation.
 */
/*==========================================================================*/

#ifndef SC_PROF_H
#define SC_PROF_H

/* Includes */

#ifdef SIMU
    #include <time.h>
    typedef struct timespec sc_prof_time_t;
#else
    #include "drivers/sysctr/fsl_sysctr.h"
    #include "drivers/systick/fsl_systick.h"
    typedef uint32_t sc_prof_time_t;
#endif

/*--------------------------------------------------------------------------*/
/* Time Duration Profiling Macros                                           */
/*--------------------------------------------------------------------------*/

#ifdef SIMU
#define SC_PTIM_DECLARE(context)    sc_prof_time_t context ## startTime;    \
                                    sc_prof_time_t context ## endTime;      \
                                    const char *context ## fileName;        \
                                    uint32_t context ## lineNum

#define SC_PTIM_EXTERN(context)     extern sc_prof_time_t context ## startTime; \
                                    extern sc_prof_time_t context ## endTime;   \
                                    extern const char *context ## fileName;     \
                                    extern uint32_t context ## lineNum
#else
#define SC_PTIM_DECLARE(context)    sc_prof_time_t context ## startTime;            \
                                    sc_prof_time_t context ## endTime;              \
                                    sc_prof_time_t context ## HPstartTime;          \
                                    sc_prof_time_t context ## HPendTime;            \
                                    const char *context ## fileName;                \
                                    uint32_t context ## lineNum

#define SC_PTIM_EXTERN(context)     extern sc_prof_time_t context ## startTime;     \
                                    extern sc_prof_time_t context ## endTime;       \
                                    extern sc_prof_time_t context ## HPstartTime;   \
                                    extern sc_prof_time_t context ## HPendTime;     \
                                    extern const char *context ## fileName;         \
                                    extern uint32_t context ## lineNum
#endif // SIMU


#define SC_PTIM_SETREF(context, file, line) context ## lineNum = line;  \
                                            context ## fileName = file

#define SC_PTIM_CLRREF(context)     SC_PTIM_SETREF(context, NULL, 0)

#define SC_PTIM_FILEREF(context)    context ## fileName == NULL ? __FILE__ : context ## fileName
#define SC_PTIM_LINEREF(context)    context ## fileName == NULL ? __LINE__ : context ## lineNum

#ifdef SIMU
#define SC_PTIM_GET_TIME(context, timeVar)  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &(context ## timeVar))
#define SC_PTIM_TIME_DIFF(context)          ((uint32_t)((context ## endTime.tv_nsec - context ## startTime.tv_nsec)))
#define SC_PTIM_HP_GET_TIME(context, timeVar)  SC_PTIM_GET_TIME(context, timeVar)
#define SC_PTIM_HP_TIME_DIFF(context)          SC_PTIM_TIME_DIFF(context)
#else
#define SC_PTIM_GET_TIME(context, timeVar)  context ## timeVar = SYSCTR_GetCounter32()
#define SC_PTIM_TIME_DIFF(context)          (SYSCTR_TICKS_TO_USEC(context ## endTime - context ## startTime) * 1000)
#define SC_PTIM_HP_GET_TIME(context, timeVar)   context ## HP ## timeVar = SysTick->VAL;
#define SC_PTIM_HP_TIME_DIFF(context)           SYSTICK_NsecDiff(context ## HP ## startTime, context ## HP ## endTime, 3750)
#endif // SIMU

#define SC_PTIM_BEGIN(context)      SC_PTIM_GET_TIME(context, startTime)
#define SC_PTIM_END(context)        SC_PTIM_GET_TIME(context, endTime)
#define SC_PTIM_REPORT(context)     debug_print(1, "PROF:  time = %u ns (%s:%d)\n",     \
                                        SC_PTIM_TIME_DIFF(context),                     \
                                        SC_PTIM_FILEREF(context),                       \
                                        SC_PTIM_LINEREF(context))

#define SC_PTIM_REPORT_N(context, n)    debug_print(1, "PROF:  n = %u, time / iter = %u ns (%s:%d)\n",  \
                                            n,                                                          \
                                            SC_PTIM_TIME_DIFF(context) / n,                             \
                                            SC_PTIM_FILEREF(context),                                   \
                                            SC_PTIM_LINEREF(context))

#define SC_PTIM_REPORT_GE_THRESH(context, nsec) if (SC_PTIM_TIME_DIFF(context) >= nsec) SC_PTIM_REPORT(context)

#define SC_PTIM_HP_BEGIN(context)      SC_PTIM_HP_GET_TIME(context, startTime)
#define SC_PTIM_HP_END(context)        SC_PTIM_HP_GET_TIME(context, endTime)
#define SC_PTIM_HP_REPORT(context)  debug_print(1, "PROF:  time = %u ns (%s:%d)\n",     \
                                        SC_PTIM_HP_TIME_DIFF(context),                  \
                                        SC_PTIM_FILEREF(context),                       \
                                        SC_PTIM_LINEREF(context))

#define SC_PTIM_HP_REPORT_N(context, n) debug_print(1, "PTIM:  n = %u, time / iter = %u ns (%s:%d)\n",  \
                                            n,                                                          \
                                            SC_PTIM_HP_TIME_DIFF(context) / n,                          \
                                            SC_PTIM_FILEREF(context),                                   \
                                            SC_PTIM_LINEREF(context))

#define SC_PTIM_HP_REPORT_GE_THRESH(context, nsec)  if (SC_PTIM_HP_TIME_DIFF(context) >= nsec) SC_PTIM_HP_REPORT(context)

/*--------------------------------------------------------------------------*/
/* Access Count Profiling Macros                                            */
/*--------------------------------------------------------------------------*/

#define SC_PCNT_DECLARE()   uint32_t dscCountR;     \
                            uint32_t dscCountW;     \
                            uint32_t csrCountR;     \
                            uint32_t csrCountW;     \
                            uint32_t xrdcCountR;    \
                            uint32_t xrdcCountW;

#define SC_PCNT_EXTERN()    extern uint32_t dscCountR;  \
                            extern uint32_t dscCountW;  \
                            extern uint32_t csrCountR;  \
                            extern uint32_t csrCountW;  \
                            extern uint32_t xrdcCountR; \
                            extern uint32_t xrdcCountW;

#ifdef HAS_TEST_PCNT
#define SC_PCNT_BEGIN()     dscCountR = 0;  \
                            dscCountW = 0;  \
                            csrCountR = 0;  \
                            csrCountW = 0;  \
                            xrdcCountR = 0; \
                            xrdcCountW = 0;
#else
#define SC_PCNT_BEGIN()     ;
#endif

#define SC_PCNT_DSC_R(X)    dscCountR += (X)
#define SC_PCNT_DSC_W(X)    dscCountW += (X)
#define SC_PCNT_DSC_RW(X)   dscCountR += (X); \
                            dscCountW += (X);
#define SC_PCNT_CSR_R(X)    csrCountR += (X)
#define SC_PCNT_CSR_W(X)    csrCountW += (X)
#define SC_PCNT_CSR_RW(X)   csrCountR += (X); \
                            csrCountW += (X);
#define SC_PCNT_XRDC_R(X)   xrdcCountR += (X)
#define SC_PCNT_XRDC_W(X)   xrdcCountW += (X)

#ifdef HAS_TEST_PCNT
#define SC_PCNT_REPORT(X)   debug_print(1, "%s PCNT(R/W):  dsc=%u/%u, csr=%u/%u, xrdc=%u/%u\n", \
                                X, dscCountR, dscCountW, csrCountR, csrCountW, xrdcCountR,      \
                                xrdcCountW)
#else
#define SC_PCNT_REPORT(X)   ;
#endif

#endif /* SC_PROF_H */

