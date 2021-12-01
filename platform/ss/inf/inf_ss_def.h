/*
** ###################################################################
**
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
 * Default SS interface config.
 *
 * @addtogroup INF_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_INF_DEF_H
#define SC_SS_INF_DEF_H

/* Defines */

/*!
 * @name SS Configuration
 */
/** @{ */
#ifndef SS_NUM_INST
    #define SS_NUM_INST             1U
#endif
#ifndef SS_NUM_SRSRC
    #define SS_NUM_SRSRC            0U
#endif
#ifndef SS_NUM_PRSRC
    #define SS_NUM_PRSRC            0U
    #define SS_NUM_PRSRC2           0U
#else
#ifndef SS_NUM_PRSRC2
    #define SS_NUM_PRSRC2           (SS_NUM_PRSRC)
#endif
#endif
#ifndef SS_NUM_RSRC_MAP
    #define SS_NUM_RSRC_MAP         (SS_NUM_RSRC * SS_NUM_INST)
#endif
#ifndef SS_NUM_PD
    #define SS_NUM_PD               2U
#endif
#ifndef SS_PD_REBOOT_INFO
    #define SS_PD_REBOOT_INFO       NULL
#endif
#ifndef SS_LPCG_ADDR_INFO
    #define SS_LPCG_ADDR_INFO       NULL
    #define SS_NUM_LPCG             0U
#endif
#ifndef SS_AON_RESET
    #define SS_AON_RESET            BIT(RST_DSCMIX)
#endif
#ifndef SS_PD_DSC
    #define SS_PD_DSC               0U
#endif
#ifndef SS_PD_SSI
    #define SS_PD_SSI               1U
#endif
#ifndef SS_NUM_SSI
    #define SS_NUM_SSI              1U
#endif
#ifndef SS_IRQ_ENB
    #define SS_IRQ_ENB              0U
#endif
#ifndef SS_MU_IRQ
    #define SS_MU_IRQ               SC_FALSE
#endif
#ifndef SS_AI_TYPE
    #define SS_AI_TYPE              AI_COMMON
#endif
#ifndef SS_PHY_ISO
    #define SS_PHY_ISO              0U
#endif
#ifndef MTR_CLK_IDX
    #define MTR_CLK_IDX             0U
#endif
#ifndef SS_DSCMIX
    #define SS_DSCMIX               SC_TRUE
#endif
/** @} */

/*!
 * @name XRDC Configuration
 */
/** @{ */
#ifndef SS_PD_MGR
    #define SS_PD_MGR               0U
#endif
#ifndef SS_NUM_MDAC
    #define SS_NUM_MDAC             0U
#endif
#ifndef SS_MDAC_MATCH
    #define SS_MDAC_MATCH           0x00000000U
#endif
#ifndef SS_MDAC_CACHE
    #define SS_MDAC_CACHE           0U
#endif
#ifndef SS_NUM_PAC
    #define SS_NUM_PAC              0U
#endif
#ifndef SS_NUM_MSC
    #define SS_NUM_MSC              0U
#endif
#ifndef SS_NUM_MRC
    #define SS_NUM_MRC              0U
#endif
#ifndef SS_NUM_MRC_SLOTS
    #define SS_NUM_MRC_SLOTS        0U
#endif
#ifndef SS_MRC_MASK
    #define SS_MRC_MASK             0x000000000U
#endif
#ifndef SS_MRC_CACHE
    #define SS_MRC_CACHE            0U
#endif
/** @} */

/* Define Checks */

#if (SS_NUM_CLK > SS_MAX_CLK)
    #error "SS_NUM_CLK > SS_MAX_CLK"
#endif

#endif /* SC_SS_INF_DEF_H */

/** @} */


