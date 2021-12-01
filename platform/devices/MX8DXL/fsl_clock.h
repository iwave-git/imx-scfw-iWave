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

#ifndef HW_CLOCKS_H
#define HW_CLOCKS_H

#include <stdbool.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define SC_XTAL32K_FREQ_HZ              32768U
#define SC_XTAL24M_FREQ_HZ              24000000U
#define SC_ROSC_FREQ_HZ                 200000000U
#define SC_PLL0_STARTUP_FREQ_HZ         1056000000U

#define SC_MSLICE_ROOT0_RESET_DIV       1U   // 200 MHz / 1 = 200 MHz (CM4, BUS)
#define SC_MSLICE_ROOT1_RESET_DIV       2U   // 200 MHz / 2 = 100 MHz (SECO, IPG)
#define SC_MSLICE_ROOT2_RESET_DIV       2U   // 200 MHz / 2 = 100 MHz (CAAM)
#define SC_MSLICE_ROOT3_RESET_DIV       1U   // 200 MHz / 1 = 200 MHz (MSI)

#define SC_MSLICE_ROOT0_STARTUP_DIV     4U   // 1056 MHz / 4 = 264 MHz (CM4, BUS)
#define SC_MSLICE_ROOT1_STARTUP_DIV     8U   // 1056 MHz / 8 = 132 MHz (SECO, IPG)
#define SC_MSLICE_ROOT2_STARTUP_DIV     3U   // 1056 MHz / 3 = 352 MHz (CAAM)
#define SC_MSLICE_ROOT3_STARTUP_DIV     5U   // 1056 MHz / 5 = 211 MHz (MSI)

#define SC_MCU_STARTUP_FREQ_HZ          (SC_PLL0_STARTUP_FREQ_HZ/SC_MSLICE_ROOT0_STARTUP_DIV)
#define SC_MCU_STARTUP_FREQ_MHZ         (SC_MCU_STARTUP_FREQ_HZ/1000000U)
#define SC_MCU_LPM_FREQ_HZ              (SC_ROSC_FREQ_HZ/SC_MSLICE_ROOT0_STARTUP_DIV)
#define SC_MCU_LPM_FREQ_MHZ             (SC_MCU_LPM_FREQ_HZ/1000000U)
#define SC_SYSTICK_NSEC_TO_TICKS(nsec)  ((SC_MCU_STARTUP_FREQ_MHZ * (nsec)) / 1000U)

#define SC_LPIT_ROOT_FREQ_HZ            24000000U
#define SC_LPIT_ROOT_DIV                3U
#define SC_LPIT_FREQ_HZ                 (SC_LPIT_ROOT_FREQ_HZ / SC_LPIT_ROOT_DIV)
#define SC_LPIT_MSEC_TO_TICKS(msec)     (SC_LPIT_FREQ_HZ * (msec) / 1000U)

#define SC_BG_SVC_MSEC                  10U     // Background service interval in msec
#define SC_WDOG_SVC_MSEC                5U      // WDOG service interval in msec
#define SC_BG_TIMEOUT_MSEC              100U    // Background timeout in msec
#define SC_BG_TIMEOUT                   (SC_BG_TIMEOUT_MSEC / SC_WDOG_SVC_MSEC)

/*! @brief Clock ip name array for LPUART. */

/* Note:  This array should have FSL_FEATURE_SOC_LPUART_COUNT entries.
 *        Unused/unsupported entries are marked as invalid.
 */
#define LPUART_CLOCKS {kCLOCK_LPUART_SC, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                       kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid}

/*! @brief Clock ip name array for LPI2C. */

/* Note:  This array should have FSL_FEATURE_SOC_LPI2C_COUNT entries.
 *        Unused/unsupported entries are marked as invalid.
 */
#define LPI2C_CLOCKS {kCLOCK_LPI2C_SC, kCLOCK_IpInvalid, kCLOCK_IpInvalid,  \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid}

/* Note:  This array should have FSL_FEATURE_SOC_IGPIO_COUNT entries.
 *        Unused/unsupported entries are marked as invalid.
 */
#define GPIO_CLOCKS  {kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid}

/* Note:  This array should have FSL_FEATURE_SOC_MU_COUNT entries.
 *        Unused/unsupported entries are marked as invalid.
 */
#define MU_CLOCKS    {kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid,  \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                      kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
                      kCLOCK_IpInvalid}

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_NmInvalid = 0U,
} clock_name_t;

/*!
 * @brief Clock source for peripherals that support various clock selections.
 */
typedef enum _clock_ip_src
{
    kCLOCK_SrcInvalid = 0U,
} clock_ip_src_t;

/*!
 * @brief Peripheral clock name definition used for clock gate, clock source
 * and clock divider setting. It is defined as the corresponding register address.
 */
typedef enum _clock_ip_name
{
    kCLOCK_IpInvalid = 0U,
    kCLOCK_TCMC_SC = LPCG__SS_SCU__CM4__TCMC_HCLK__BASE,
    kCLOCK_MMCAU_SC = LPCG__SS_SCU__CM4__MMCAU_HCLK__BASE,
    kCLOCK_TPM_SC = LPCG__SS_SCU__TPM1__IPG_CLK__BASE,
    kCLOCK_LPIT_SC = LPCG__SS_SCU__LPIT1__IPG_CLK__BASE,
    kCLOCK_LPUART_SC = LPCG__SS_SCU__LPUART1__IPG_CLK__BASE,
    kCLOCK_LPI2C_SC = LPCG__SS_SCU__LPI2C1__IPG_CLK__BASE
} clock_ip_name_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*!
 * @brief Enable the clock for specific IP.
 *
 * @param name  Which clock to enable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_EnableClock(clock_ip_name_t name)
{
#ifndef SIMU
    if (name != kCLOCK_IpInvalid)
    {
        /* Enable IPG and BAUD clocks */
        volatile uint32_t lpcgVal = (1UL << LPCG__SS_SCU__IPG_CLK__SWEN) |
                                    (1UL << LPCG__SS_SCU__PER_CLK__SWEN);
            
        *((volatile uint32_t *) (uint32_t) name) = lpcgVal;

        /* Wait for clocks to start */
        uint32_t stopMask = (1UL << LPCG__SS_SCU__IPG_CLK__STOP) |
                            (1UL << LPCG__SS_SCU__PER_CLK__STOP);

        while ((*((volatile uint32_t *) (uint32_t) name) & stopMask) != 0U)
        {           
            ; /* Intentional empty while */
        }

        /* Perform extra write as workaround for TKT322331 */
        *((volatile uint32_t *) (uint32_t) name) = lpcgVal;
    }
#endif
}

/*!
 * @brief Enable the hardware clock gating for specific IP.
 *
 * @param name  Which clock to enable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_EnableHWCG(clock_ip_name_t name)
{
#ifndef SIMU
    if (name != kCLOCK_IpInvalid)
    {
        /* Enable IPG and BAUD clocks */
        uint32_t lpcgVal = (1UL << LPCG__SS_SCU__PER_CLK__HWEN);
            
        *((volatile uint32_t *) (uint32_t) name) |= lpcgVal;
    }
#endif
}

/*!
 * @brief Enable the clock for specific IP using exclusive access.
 *
 * @param name  Which clock to enable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_EnableClockEx(clock_ip_name_t name)
{
#ifndef SIMU
    if (name != kCLOCK_IpInvalid)
    {
        /* Use exclusive access to enable IPG and BAUD clocks */
        uint32_t volatile lpcgVal = (1UL << LPCG__SS_SCU__IPG_CLK__SWEN) |
                                    (1UL << LPCG__SS_SCU__PER_CLK__SWEN);
            
        do
        {
            lpcgVal |= __LDREXW((volatile uint32_t *) (uint32_t) name);
        } while (__STREXW(lpcgVal, ((volatile uint32_t *) (uint32_t) name)) != 0U);

        /* Wait for clocks to start */
        uint32_t stopMask = (1UL << LPCG__SS_SCU__IPG_CLK__STOP) |
                            (1UL << LPCG__SS_SCU__PER_CLK__STOP);

        while ((*((volatile uint32_t *) (uint32_t) name) & stopMask) != 0U)
        {           
            ; /* Intentional empty while */
        }

        /* Perform extra write as workaround for TKT322331 */
        *((volatile uint32_t *) (uint32_t) name) = lpcgVal;

    }
#endif
}

/*!
 * @brief Disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_DisableClock(clock_ip_name_t name)
{
#ifndef SIMU
    if (name != kCLOCK_IpInvalid)
    {
        /* Disable IPG and BAUD clocks */
        uint32_t lpcgVal = 0U;
            
        *((volatile uint32_t *) (uint32_t) name) = lpcgVal;
    }
#endif
}

/*!
 * @brief Enter exclusive attempt to disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_ip_name_t.
 */
static inline uint32_t CLOCK_DisableClockExEnter(clock_ip_name_t name)
{
#ifndef SIMU
    /* Use exclusive access to disable IPG and BAUD clocks */
    uint32_t lpcgVal = ~((1UL << LPCG__SS_SCU__IPG_CLK__SWEN) |
                         (1UL << LPCG__SS_SCU__PER_CLK__SWEN));

    if (name != kCLOCK_IpInvalid)
    {
        lpcgVal = __LDREXW((volatile uint32_t *) (uint32_t) name);
    }

    return lpcgVal;
#else
    return 0U;
#endif
}

/*!
 * @brief Leave exclusive attempt to disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_DisableClockExLeave(clock_ip_name_t name, 
                                             uint32_t lpcgVal)
{
#ifndef SIMU
    if (name != kCLOCK_IpInvalid)
    {
        (void)__STREXW(lpcgVal, ((volatile uint32_t *) (uint32_t) name));
    }
#endif
}

/*!
 * @brief Check whether the clock is already enabled and configured by
 * any other core.
 *
 * @param name Which peripheral to check, see \ref clock_ip_name_t.
 * @return True if clock is already enabled, otherwise false.
 */
static inline bool CLOCK_IsEnabledByOtherCore(clock_ip_name_t name)
{
    return false;
}

/*!
 * @brief Set the clock source for specific IP module.
 *
 * Set the clock source for specific IP, not all modules need to set the
 * clock source, should only use this function for the modules need source
 * setting.
 *
 * @param name Which peripheral to check, see \ref clock_ip_name_t.
 * @param src Clock source to set.
 */
static inline void CLOCK_SetIpSrc(clock_ip_name_t name, clock_ip_src_t src)
{
}

/*!
 * @brief Set the clock source and divider for specific IP module.
 *
 * Set the clock source and divider for specific IP, not all modules need to
 * set the clock source and divider, should only use this function for the
 * modules need source and divider setting.
 *
 * Divider output clock = Divider input clock x [(fracValue+1)/(divValue+1)]).
 *
 * @param name Which peripheral to check, see \ref clock_ip_name_t.
 * @param src Clock source to set.
 * @param divValue  The divider value.
 * @param fracValue The fraction multiply value.
 */
static inline void CLOCK_SetIpSrcDiv(clock_ip_name_t name, clock_ip_src_t src, uint8_t divValue, uint8_t fracValue)
{
}

/*!
 * @brief Gets the clock frequency for a specific clock name.
 *
 * This function checks the current clock configurations and then calculates
 * the clock frequency for a specific clock name defined in clock_name_t.
 *
 * @param clockName Clock names defined in clock_name_t
 * @return Clock frequency value in hertz
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

/*!
 * @brief Gets the clock frequency for a specific IP module.
 *
 * This function gets the IP module clock frequency based on PCC registers. It is
 * only used for the IP modules which could select clock source by PCC[PCS].
 *
 * @param name Which peripheral to get, see \ref clock_ip_name_t.
 * @return Clock frequency value in hertz
 */
uint32_t CLOCK_GetIpFreq(clock_ip_name_t name);

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* HW_CLOCKS_H */

/* EOF */

