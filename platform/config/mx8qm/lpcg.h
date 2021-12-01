/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2017-2019 NXP
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

#ifndef LPCG_H
#define LPCG_H

// NOTE:  Content below comes from cprog file of the SCU design database

//      LPCG__<SS>__<CLK>__REG                                                                     
#define LPCG__SS_SCU__CM0P__CM0P_HCLK__REG                           0x0000 // IPS_SLOT=CLK_SECO
#define LPCG__SS_SCU__CM0P__CM0P_HCLK__BIT                                0                               
#define LPCG__SS_SCU__CM0P__CM0P_HCLK__HWEN                               0                               
#define LPCG__SS_SCU__CM0P__CM0P_HCLK__SWEN                               1                               
#define LPCG__SS_SCU__CM0P__CM0P_HCLK__RSVD                               2                               
#define LPCG__SS_SCU__CM0P__CM0P_HCLK__STOP                               3                               

#define LPCG__SS_SCU__CM0P__DEBUG_CLK__REG                           0x0004 // IPS_SLOT=CLK_SECO
#define LPCG__SS_SCU__CM0P__DEBUG_CLK__BIT                                0                               
#define LPCG__SS_SCU__CM0P__DEBUG_CLK__HWEN                               0                               
#define LPCG__SS_SCU__CM0P__DEBUG_CLK__SWEN                               1                               
#define LPCG__SS_SCU__CM0P__DEBUG_CLK__RSVD                               2                               
#define LPCG__SS_SCU__CM0P__DEBUG_CLK__STOP                               3                               

#define LPCG__SS_SCU__CM4__MMCAU_HCLK__REG                           0x0000 // IPS_SLOT=CLK_MMCAU_HCLK
#define LPCG__SS_SCU__CM4__MMCAU_HCLK__BIT                                0                               
#define LPCG__SS_SCU__CM4__MMCAU_HCLK__HWEN                               0                               
#define LPCG__SS_SCU__CM4__MMCAU_HCLK__SWEN                               1                               
#define LPCG__SS_SCU__CM4__MMCAU_HCLK__RSVD                               2                               
#define LPCG__SS_SCU__CM4__MMCAU_HCLK__STOP                               3                               

#define LPCG__SS_SCU__CM4__TCMC_HCLK__REG                            0x0000 // IPS_SLOT=CLK_TCMC_HCLK
#define LPCG__SS_SCU__CM4__TCMC_HCLK__BIT                                 0                               
#define LPCG__SS_SCU__CM4__TCMC_HCLK__HWEN                                0                               
#define LPCG__SS_SCU__CM4__TCMC_HCLK__SWEN                                1                               
#define LPCG__SS_SCU__CM4__TCMC_HCLK__RSVD                                2                               
#define LPCG__SS_SCU__CM4__TCMC_HCLK__STOP                                3                               

#define LPCG__SS_SCU__LPI2C1__IPG_CLK__REG                           0x0000 // IPS_SLOT=CLK_LPI2C
#define LPCG__SS_SCU__LPI2C1__IPG_CLK__BIT                                4                               
#define LPCG__SS_SCU__LPI2C1__IPG_CLK__HWEN                               4                               
#define LPCG__SS_SCU__LPI2C1__IPG_CLK__SWEN                               5                               
#define LPCG__SS_SCU__LPI2C1__IPG_CLK__RSVD                               6                               
#define LPCG__SS_SCU__LPI2C1__IPG_CLK__STOP                               7                               

#define LPCG__SS_SCU__LPI2C1__LPI2C_CLK__REG                         0x0000 // IPS_SLOT=CLK_LPI2C
#define LPCG__SS_SCU__LPI2C1__LPI2C_CLK__BIT                              0                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_CLK__HWEN                             0                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_CLK__SWEN                             1                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_CLK__RSVD                             2                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_CLK__STOP                             3                               

#define LPCG__SS_SCU__LPI2C1__LPI2C_DIV_CLK__REG                     0x0000 // IPS_SLOT=CLK_LPI2C
#define LPCG__SS_SCU__LPI2C1__LPI2C_DIV_CLK__BIT                          0                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_DIV_CLK__HWEN                         0                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_DIV_CLK__SWEN                         1                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_DIV_CLK__RSVD                         2                               
#define LPCG__SS_SCU__LPI2C1__LPI2C_DIV_CLK__STOP                         3                               

#define LPCG__SS_SCU__LPIT1__IPG_CLK__REG                            0x0000 // IPS_SLOT=CLK_LPIT
#define LPCG__SS_SCU__LPIT1__IPG_CLK__BIT                                 4                               
#define LPCG__SS_SCU__LPIT1__IPG_CLK__HWEN                                4                               
#define LPCG__SS_SCU__LPIT1__IPG_CLK__SWEN                                5                               
#define LPCG__SS_SCU__LPIT1__IPG_CLK__RSVD                                6                               
#define LPCG__SS_SCU__LPIT1__IPG_CLK__STOP                                7                               

#define LPCG__SS_SCU__LPIT1__IPG_PER_CLK__REG                        0x0000 // IPS_SLOT=CLK_LPIT
#define LPCG__SS_SCU__LPIT1__IPG_PER_CLK__BIT                             0                               
#define LPCG__SS_SCU__LPIT1__IPG_PER_CLK__HWEN                            0                               
#define LPCG__SS_SCU__LPIT1__IPG_PER_CLK__SWEN                            1                               
#define LPCG__SS_SCU__LPIT1__IPG_PER_CLK__RSVD                            2                               
#define LPCG__SS_SCU__LPIT1__IPG_PER_CLK__STOP                            3                               

#define LPCG__SS_SCU__LPIT1__IPG_UNGATED_PER_CLK__REG                0x0000 // IPS_SLOT=CLK_LPIT
#define LPCG__SS_SCU__LPIT1__IPG_UNGATED_PER_CLK__BIT                     0                               
#define LPCG__SS_SCU__LPIT1__IPG_UNGATED_PER_CLK__HWEN                    0                               
#define LPCG__SS_SCU__LPIT1__IPG_UNGATED_PER_CLK__SWEN                    1                               
#define LPCG__SS_SCU__LPIT1__IPG_UNGATED_PER_CLK__RSVD                    2                               
#define LPCG__SS_SCU__LPIT1__IPG_UNGATED_PER_CLK__STOP                    3                               

#define LPCG__SS_SCU__LPUART1__IPG_CLK__REG                          0x0000 // IPS_SLOT=CLK_LPUART
#define LPCG__SS_SCU__LPUART1__IPG_CLK__BIT                               4                               
#define LPCG__SS_SCU__LPUART1__IPG_CLK__HWEN                              4                               
#define LPCG__SS_SCU__LPUART1__IPG_CLK__SWEN                              5                               
#define LPCG__SS_SCU__LPUART1__IPG_CLK__RSVD                              6                               
#define LPCG__SS_SCU__LPUART1__IPG_CLK__STOP                              7                               

#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_CLK__REG                  0x0000 // IPS_SLOT=CLK_LPUART
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_CLK__BIT                       0                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_CLK__HWEN                      0                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_CLK__SWEN                      1                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_CLK__RSVD                      2                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_CLK__STOP                      3                               

#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_GATED_CLK__REG            0x0000 // IPS_SLOT=CLK_LPUART
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_GATED_CLK__BIT                 0                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_GATED_CLK__HWEN                0                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_GATED_CLK__SWEN                1                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_GATED_CLK__RSVD                2                               
#define LPCG__SS_SCU__LPUART1__LPUART_BAUD_GATED_CLK__STOP                3                               

#define LPCG__SS_SCU__TPM1__IPG_CLK__REG                             0x0000 // IPS_SLOT=CLK_TPM
#define LPCG__SS_SCU__TPM1__IPG_CLK__BIT                                  4                               
#define LPCG__SS_SCU__TPM1__IPG_CLK__HWEN                                 4                               
#define LPCG__SS_SCU__TPM1__IPG_CLK__SWEN                                 5                               
#define LPCG__SS_SCU__TPM1__IPG_CLK__RSVD                                 6                               
#define LPCG__SS_SCU__TPM1__IPG_CLK__STOP                                 7                               

#define LPCG__SS_SCU__TPM1__LPTPM_CLK__REG                           0x0000 // IPS_SLOT=CLK_TPM
#define LPCG__SS_SCU__TPM1__LPTPM_CLK__BIT                                0                               
#define LPCG__SS_SCU__TPM1__LPTPM_CLK__HWEN                               0                               
#define LPCG__SS_SCU__TPM1__LPTPM_CLK__SWEN                               1                               
#define LPCG__SS_SCU__TPM1__LPTPM_CLK__RSVD                               2                               
#define LPCG__SS_SCU__TPM1__LPTPM_CLK__STOP                               3                               

#endif

