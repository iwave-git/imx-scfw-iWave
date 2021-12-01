/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright (c) 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
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

#ifndef FSL_DEVICE_REGISTERS_H
#define FSL_DEVICE_REGISTERS_H

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if defined(CPU_MX8QM)

    #define MX8_SERIES

    /* CPU specific feature definitions */
    #include "MX8QM/MX8QM_features.h"
    /* CMSIS-style register definitions */
    #include "MX8QM/MX8QM.h"
    #include "MX8/MX8_dsc.h"
    #include "MX8/MX8_dsc_ai.h"
    #include "MX8/MX8_csr.h"
    #include "MX8/MX8_xrdc2.h"
    #include "MX8/MX8_mu.h"
    #include "MX8/MX8_lmem_cache.h"
    #include "MX8/MX8_lpuart.h"
    #include "MX8/MX8_lpit.h"
    #include "MX8/MX8_sysctr.h"
    #include "MX8/MX8_wdog.h"
    #include "MX8/MX8_pad.h"
    #include "MX8/MX8_lpcg.h"
    #include "MX8/MX8_lpi2c.h"
    #include "MX8/MX8_gpio.h"
    #include "MX8/MX8_igpio.h"
    #include "MX8/MX8_mcm.h"
    #include "MX8/MX8_dma3.h"
    #include "MX8/MX8_snvs.h"
    #include "MX8/MX8_asmc.h"
    #include "MX8/MX8_lpc.h"
    #include "MX8QM/MX8QM_otp.h"
    #include "MX8/MX8_stc.h"
    #include "MX8/MX8_rep2.h"
    #include "MX8/MX8_mbist.h"
    #include "MX8/MX8_isi.h"
    #include "MX8/MX8_adm.h"
    #include "MX8/MX8_jpgdec.h"
    #include "MX8/MX8_jpgenc.h"
    #include "MX8/MX8_drc.h"
    #include "MX8/MX8_ddrc.h"
    #include "MX8/MX8_ddr_phy.h"
    #include "MX8/MX8_drc_perf.h"
    #include "MX8/MX8_flexspi.h"
    /* Register access macros */
    #include "MX8/fsl_bitaccess.h"
    #include "MX8QM/MX8QM_fuse_map.h"
    
#elif defined(CPU_MX8QX)

    #define MX8_SERIES

    /* CPU specific feature definitions */
    #include "MX8QX/MX8QX_features.h"
    /* CMSIS-style register definitions */
    #include "MX8QX/MX8QX.h"
    #include "MX8/MX8_dsc.h"
    #include "MX8/MX8_dsc_ai.h"
    #include "MX8/MX8_csr.h"
    #include "MX8/MX8_xrdc2.h"
    #include "MX8/MX8_mu.h"
    #include "MX8/MX8_lmem_cache.h"
    #include "MX8/MX8_lpuart.h"
    #include "MX8/MX8_lpit.h"
    #include "MX8/MX8_sysctr.h"
    #include "MX8/MX8_wdog.h"
    #include "MX8/MX8_pad.h"
    #include "MX8/MX8_lpcg.h"
    #include "MX8/MX8_lpi2c.h"
    #include "MX8/MX8_gpio.h"
    #include "MX8/MX8_igpio.h"
    #include "MX8/MX8_mcm.h"
    #include "MX8/MX8_dma3.h"
    #include "MX8/MX8_snvs.h"
    #include "MX8/MX8_asmc.h"
    #include "MX8/MX8_lpc.h"
    #include "MX8QX/MX8QX_otp.h"
    #include "MX8/MX8_stc.h"
    #include "MX8/MX8_rep2.h"
    #include "MX8/MX8_mbist.h"
    #include "MX8/MX8_isi.h"
    #include "MX8/MX8_adm.h"
    #include "MX8/MX8_jpgdec.h"
    #include "MX8/MX8_jpgenc.h"
    #include "MX8/MX8_drc.h"
    #include "MX8/MX8_ddrc.h"
    #include "MX8/MX8_ddr_phy.h"
    #include "MX8/MX8_drc_perf.h"
    #include "MX8/MX8_flexspi.h"
    /* Register access macros */
    #include "MX8/fsl_bitaccess.h"
    #include "MX8QX/MX8QX_fuse_map.h"

#elif defined(CPU_MX8DXL)

    #define MX8_SERIES

    /* CPU specific feature definitions */
    #include "MX8DXL/MX8DXL_features.h"
    /* CMSIS-style register definitions */
    #include "MX8DXL/MX8DXL.h"
    #include "MX8/MX8_dsc.h"
    #include "MX8/MX8_dsc_ai.h"
    #include "MX8/MX8_csr.h"
    #include "MX8/MX8_ecsr_reset.h"
    #include "MX8/MX8_xrdc2.h"
    #include "MX8/MX8_mu.h"
    #include "MX8/MX8_lmem_cache.h"
    #include "MX8/MX8_lpuart.h"
    #include "MX8/MX8_lpit.h"
    #include "MX8/MX8_sysctr.h"
    #include "MX8/MX8_wdog.h"
    #include "MX8/MX8_pad.h"
    #include "MX8/MX8_lpcg.h"
    #include "MX8/MX8_lpi2c.h"
    #include "MX8/MX8_gpio.h"
    #include "MX8/MX8_igpio.h"
    #include "MX8/MX8_mcm.h"
    #include "MX8/MX8_dma3.h"
    #include "MX8/MX8_snvs.h"
    #include "MX8/MX8_asmc.h"
    #include "MX8/MX8_lpc.h"
    #include "MX8DXL/MX8DXL_otp.h"
    #include "MX8/MX8_rep2.h"
    #include "MX8/MX8_mbist.h"
    #include "MX8/MX8_isi.h"
    #include "MX8/MX8_adm.h"
    #include "MX8/MX8_drc.h"
    #include "MX8/MX8_ddrc.h"
    #include "MX8/MX8_ddr_phy.h"
    #include "MX8/MX8_drc_perf.h"
    #include "MX8/MX8_flexspi.h"
    /* Register access macros */
    #include "MX8/fsl_bitaccess.h"
    #include "MX8DXL/MX8DXL_fuse_map.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* FSL_DEVICE_REGISTERS_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
