/*
** ###################################################################
**
**     Copyright 2018-2019 NXP
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
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
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
** ###################################################################
*/

#ifndef HW_DRC_PERF_REGISTERS_H
#define HW_DRC_PERF_REGISTERS_H

#define DRC_PERF_COUNTER_BASE_ADDR(X) (0x5c000000U + (((X) * 0x100000U) + 0x20000U))

#define DRC_PERF_COUNTER_0_CR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x00U)
#define DRC_PERF_COUNTER_1_CR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x04U)
#define DRC_PERF_COUNTER_2_CR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x08U)
#define DRC_PERF_COUNTER_3_CR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x0cU)
#define DRC_PERF_COUNTER_0_DR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x20U)
#define DRC_PERF_COUNTER_1_DR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x24U)
#define DRC_PERF_COUNTER_2_DR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x28U)
#define DRC_PERF_COUNTER_3_DR(X)           REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x2cU)
#define DRC_PERF_COUNTER_MRR_0_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x40U)
#define DRC_PERF_COUNTER_MRR_1_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x44U)
#define DRC_PERF_COUNTER_MRR_2_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x48U)
#define DRC_PERF_COUNTER_MRR_3_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x4cU)
#define DRC_PERF_COUNTER_MRR_4_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x50U)
#define DRC_PERF_COUNTER_MRR_5_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x54U)
#define DRC_PERF_COUNTER_MRR_6_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x58U)
#define DRC_PERF_COUNTER_MRR_7_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x5cU)
#define DRC_PERF_COUNTER_MRR_8_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x60U)
#define DRC_PERF_COUNTER_MRR_9_DATA(X)     REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x64U)
#define DRC_PERF_COUNTER_MRR_10_DATA(X)    REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x68U)
#define DRC_PERF_COUNTER_MRR_11_DATA(X)    REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x6cU)
#define DRC_PERF_COUNTER_MRR_12_DATA(X)    REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x70U)
#define DRC_PERF_COUNTER_MRR_13_DATA(X)    REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x74U)
#define DRC_PERF_COUNTER_MRR_14_DATA(X)    REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x78U)
#define DRC_PERF_COUNTER_MRR_15_DATA(X)    REG32(DRC_PERF_COUNTER_BASE_ADDR(X) + 0x7cU)

#endif

