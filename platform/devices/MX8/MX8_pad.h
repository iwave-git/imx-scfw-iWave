/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright 2018-2021 NXP
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
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file MX8_pad.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for PAD
 *
 * CMSIS Peripheral Access Layer for PAD
 */

#ifndef HW_PAD_REGISTERS_H
#define HW_PAD_REGISTERS_H

#define IOMUXD_REG_BASE     0UL
#define REG32(X)            ((uint32_t) (X))

#include "iomuxd.h"

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma push
  #pragma anon_unions
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PAD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PAD_Peripheral_Access_Layer PAD Peripheral Access Layer
 * @{
 */

/** PAD - Register Layout Typedef */
typedef struct {
    __IO uint32_t RW;
    __IO uint32_t SET;
    __IO uint32_t CLR;
    __IO uint32_t TOG;
    uint32_t reserved[12];
} PAD_Type;

/** PADRING - Register Layout Typedef */
typedef struct {
    struct {
        struct {
            PAD_Type PAD[16];
            __I uint32_t GLOBAL;
            uint32_t reserved[767];
        } GROUP[32];
    } RING[4];
} PADRING_Type;

/* ----------------------------------------------------------------------------
   -- PAD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PAD_Register_Masks PAD Register Masks
 * @{
 */

/*! @name IOMUX - Register */
#define IOMUX_REG_PAD_CTL_MASK          (0x7FFFFU)
#define IOMUX_REG_PAD_CTL_SHIFT         (0U)
#define IOMUX_REG_PAD_CTL(x)            (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_PAD_CTL_SHIFT)) & IOMUX_REG_PAD_CTL_MASK)
#define IOMUX_REG_WAKEUP_CTRL_MASK      (0x380000U)
#define IOMUX_REG_WAKEUP_CTRL_SHIFT     (19U)
#define IOMUX_REG_WAKEUP_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_WAKEUP_CTRL_SHIFT)) & IOMUX_REG_WAKEUP_CTRL_MASK)
#define IOMUX_REG_WAKEUP_MASK_MASK      (0x400000U)
#define IOMUX_REG_WAKEUP_MASK_SHIFT     (22U)
#define IOMUX_REG_WAKEUP_MASK(x)        (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_WAKEUP_MASK_SHIFT)) & IOMUX_REG_WAKEUP_MASK_MASK)
#define IOMUX_REG_LP_CONFIG_MASK        (0x1800000U)
#define IOMUX_REG_LP_CONFIG_SHIFT       (23U)
#define IOMUX_REG_LP_CONFIG(x)          (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_LP_CONFIG_SHIFT)) & IOMUX_REG_LP_CONFIG_MASK)
#define IOMUX_REG_SW_CONFIG_MASK        (0x6000000U)
#define IOMUX_REG_SW_CONFIG_SHIFT       (25U)
#define IOMUX_REG_SW_CONFIG(x)          (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_SW_CONFIG_SHIFT)) & IOMUX_REG_SW_CONFIG_MASK)
#define IOMUX_REG_MUX_MODE_MASK         (0x38000000U)
#define IOMUX_REG_MUX_MODE_SHIFT        (27U)
#define IOMUX_REG_MUX_MODE(x)           (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_MUX_MODE_SHIFT)) & IOMUX_REG_MUX_MODE_MASK)
#define IOMUX_REG_UPDATE_PAD_CTL_MASK   (0x40000000U)
#define IOMUX_REG_UPDATE_PAD_CTL_SHIFT  (30U)
#define IOMUX_REG_UPDATE_PAD_CTL(x)     (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_UPDATE_PAD_CTL_SHIFT)) & IOMUX_REG_UPDATE_PAD_CTL_MASK)
#define IOMUX_REG_UPDATE_MUX_MODE_MASK  (0x80000000U)
#define IOMUX_REG_UPDATE_MUX_MODE_SHIFT (31U)
#define IOMUX_REG_UPDATE_MUX_MODE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_UPDATE_MUX_MODE_SHIFT)) & IOMUX_REG_UPDATE_MUX_MODE_MASK)

/*! @name 28FDSOI_IOMUX - Register */
#define IOMUX_REG_28FDSOI_PDRV_MASK             (0x7U)
#define IOMUX_REG_28FDSOI_PDRV_SHIFT            (0U)
#define IOMUX_REG_28FDSOI_PDRV(x)               (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_PDRV_SHIFT)) & IOMUX_REG_28FDSOI_PDRV_MASK)
#define IOMUX_REG_28FDSOI_PULL_MASK             (0x60U)
#define IOMUX_REG_28FDSOI_PULL_SHIFT            (5U)
#define IOMUX_REG_28FDSOI_PULL(x)               (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_PULL_SHIFT)) & IOMUX_REG_28FDSOI_PULL_MASK)
#define IOMUX_REG_28FDSOI_WAKEUP_CTRL_MASK      (0x380000U)
#define IOMUX_REG_28FDSOI_WAKEUP_CTRL_SHIFT     (19U)
#define IOMUX_REG_28FDSOI_WAKEUP_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_WAKEUP_CTRL_SHIFT)) & IOMUX_REG_28FDSOI_WAKEUP_CTRL_MASK)
#define IOMUX_REG_28FDSOI_WAKEUP_MASK_MASK      (0x400000U)
#define IOMUX_REG_28FDSOI_WAKEUP_MASK_SHIFT     (22U)
#define IOMUX_REG_28FDSOI_WAKEUP_MASK(x)        (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_WAKEUP_MASK_SHIFT)) & IOMUX_REG_28FDSOI_WAKEUP_MASK_MASK)
#define IOMUX_REG_28FDSOI_LP_CONFIG_MASK        (0x1800000U)
#define IOMUX_REG_28FDSOI_LP_CONFIG_SHIFT       (23U)
#define IOMUX_REG_28FDSOI_LP_CONFIG(x)          (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_LP_CONFIG_SHIFT)) & IOMUX_REG_28FDSOI_LP_CONFIG_MASK)
#define IOMUX_REG_28FDSOI_SW_CONFIG_MASK        (0x6000000U)
#define IOMUX_REG_28FDSOI_SW_CONFIG_SHIFT       (25U)
#define IOMUX_REG_28FDSOI_SW_CONFIG(x)          (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_SW_CONFIG_SHIFT)) & IOMUX_REG_28FDSOI_SW_CONFIG_MASK)
#define IOMUX_REG_28FDSOI_MUX_MODE_MASK         (0x38000000U)
#define IOMUX_REG_28FDSOI_MUX_MODE_SHIFT        (27U)
#define IOMUX_REG_28FDSOI_MUX_MODE(x)           (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_MUX_MODE_SHIFT)) & IOMUX_REG_28FDSOI_MUX_MODE_MASK)
#define IOMUX_REG_28FDSOI_UPDATE_PAD_CTL_MASK   (0x40000000U)
#define IOMUX_REG_28FDSOI_UPDATE_PAD_CTL_SHIFT  (30U)
#define IOMUX_REG_28FDSOI_UPDATE_PAD_CTL(x)     (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_UPDATE_PAD_CTL_SHIFT)) & IOMUX_REG_28FDSOI_UPDATE_PAD_CTL_MASK)
#define IOMUX_REG_28FDSOI_UPDATE_MUX_MODE_MASK  (0x80000000U)
#define IOMUX_REG_28FDSOI_UPDATE_MUX_MODE_SHIFT (31U)
#define IOMUX_REG_28FDSOI_UPDATE_MUX_MODE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_UPDATE_MUX_MODE_SHIFT)) & IOMUX_REG_28FDSOI_UPDATE_MUX_MODE_MASK)

/*! @name 28FDSOI_HSIC - Register */
#define IOMUX_REG_28FDSOI_HSIC_DSE_MASK        (0x7U)
#define IOMUX_REG_28FDSOI_HSIC_DSE_SHIFT       (0U)
#define IOMUX_REG_28FDSOI_HSIC_DSE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_DSE_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_DSE_MASK)
#define IOMUX_REG_28FDSOI_HSIC_HYS_MASK        (0x8U)
#define IOMUX_REG_28FDSOI_HSIC_HYS_SHIFT       (3U)
#define IOMUX_REG_28FDSOI_HSIC_HYS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_HYS_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_HYS_MASK)
#define IOMUX_REG_28FDSOI_HSIC_PS_MASK         (0x30U)
#define IOMUX_REG_28FDSOI_HSIC_PS_SHIFT        (4U)
#define IOMUX_REG_28FDSOI_HSIC_PS(x)           (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_PS_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_PS_MASK)
#define IOMUX_REG_28FDSOI_HSIC_PKE_MASK        (0x40U)
#define IOMUX_REG_28FDSOI_HSIC_PKE_SHIFT       (6U)
#define IOMUX_REG_28FDSOI_HSIC_PKE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_PKE_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_PKE_MASK)
#define IOMUX_REG_28FDSOI_HSIC_PE_MASK         (0x80U)
#define IOMUX_REG_28FDSOI_HSIC_PE_SHIFT        (7U)
#define IOMUX_REG_28FDSOI_HSIC_PE(x)           (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_PE_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_PE_MASK)
#define IOMUX_REG_28FDSOI_HSIC_WAKEUP_CTRL_MASK (0x380000U)
#define IOMUX_REG_28FDSOI_HSIC_WAKEUP_CTRL_SHIFT (19U)
#define IOMUX_REG_28FDSOI_HSIC_WAKEUP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_WAKEUP_CTRL_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_WAKEUP_CTRL_MASK)
#define IOMUX_REG_28FDSOI_HSIC_WAKEUP_MASK_MASK (0x400000U)
#define IOMUX_REG_28FDSOI_HSIC_WAKEUP_MASK_SHIFT (22U)
#define IOMUX_REG_28FDSOI_HSIC_WAKEUP_MASK(x)  (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_WAKEUP_MASK_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_WAKEUP_MASK_MASK)
#define IOMUX_REG_28FDSOI_HSIC_LP_CONFIG_MASK  (0x1800000U)
#define IOMUX_REG_28FDSOI_HSIC_LP_CONFIG_SHIFT (23U)
#define IOMUX_REG_28FDSOI_HSIC_LP_CONFIG(x)    (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_LP_CONFIG_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_LP_CONFIG_MASK)
#define IOMUX_REG_28FDSOI_HSIC_SW_CONFIG_MASK  (0x6000000U)
#define IOMUX_REG_28FDSOI_HSIC_SW_CONFIG_SHIFT (25U)
#define IOMUX_REG_28FDSOI_HSIC_SW_CONFIG(x)    (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_SW_CONFIG_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_SW_CONFIG_MASK)
#define IOMUX_REG_28FDSOI_HSIC_MUX_MODE_MASK   (0x38000000U)
#define IOMUX_REG_28FDSOI_HSIC_MUX_MODE_SHIFT  (27U)
#define IOMUX_REG_28FDSOI_HSIC_MUX_MODE(x)     (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_MUX_MODE_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_MUX_MODE_MASK)
#define IOMUX_REG_28FDSOI_HSIC_UPDATE_PAD_CTL_MASK (0x40000000U)
#define IOMUX_REG_28FDSOI_HSIC_UPDATE_PAD_CTL_SHIFT (30U)
#define IOMUX_REG_28FDSOI_HSIC_UPDATE_PAD_CTL(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_UPDATE_PAD_CTL_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_UPDATE_PAD_CTL_MASK)
#define IOMUX_REG_28FDSOI_HSIC_UPDATE_MUX_MODE_MASK (0x80000000U)
#define IOMUX_REG_28FDSOI_HSIC_UPDATE_MUX_MODE_SHIFT (31U)
#define IOMUX_REG_28FDSOI_HSIC_UPDATE_MUX_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_HSIC_UPDATE_MUX_MODE_SHIFT)) & IOMUX_REG_28FDSOI_HSIC_UPDATE_MUX_MODE_MASK)

/*! @name 28FDSOI_COMP - Register */
#define IOMUX_REG_28FDSOI_COMP_COMP_MASK (0x7U)
#define IOMUX_REG_28FDSOI_COMP_COMP_SHIFT (0U)
#define IOMUX_REG_28FDSOI_COMP_COMP(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_COMP_SHIFT)) & IOMUX_REG_28FDSOI_COMP_COMP_MASK)
#define IOMUX_REG_28FDSOI_COMP_FASTFRZ_EN_MASK (0x8U)
#define IOMUX_REG_28FDSOI_COMP_FASTFRZ_EN_SHIFT (3U)
#define IOMUX_REG_28FDSOI_COMP_FASTFRZ_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_FASTFRZ_EN_SHIFT)) & IOMUX_REG_28FDSOI_COMP_FASTFRZ_EN_MASK)
#define IOMUX_REG_28FDSOI_COMP_PSW_OVR_MASK (0x10U)
#define IOMUX_REG_28FDSOI_COMP_PSW_OVR_SHIFT (4U)
#define IOMUX_REG_28FDSOI_COMP_PSW_OVR(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_PSW_OVR_SHIFT)) & IOMUX_REG_28FDSOI_COMP_PSW_OVR_MASK)
#define IOMUX_REG_28FDSOI_COMP_RASRCP_MASK (0x1E0U)
#define IOMUX_REG_28FDSOI_COMP_RASRCP_SHIFT (5U)
#define IOMUX_REG_28FDSOI_COMP_RASRCP(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_RASRCP_SHIFT)) & IOMUX_REG_28FDSOI_COMP_RASRCP_MASK)
#define IOMUX_REG_28FDSOI_COMP_RASRCN_MASK (0x1E00U)
#define IOMUX_REG_28FDSOI_COMP_RASRCN_SHIFT (9U)
#define IOMUX_REG_28FDSOI_COMP_RASRCN(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_RASRCN_SHIFT)) & IOMUX_REG_28FDSOI_COMP_RASRCN_MASK)
#define IOMUX_REG_28FDSOI_COMP_SELECT_NASRC_MASK (0x2000U)
#define IOMUX_REG_28FDSOI_COMP_SELECT_NASRC_SHIFT (13U)
#define IOMUX_REG_28FDSOI_COMP_SELECT_NASRC(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_SELECT_NASRC_SHIFT)) & IOMUX_REG_28FDSOI_COMP_SELECT_NASRC_MASK)
#define IOMUX_REG_28FDSOI_COMP_COMPOK_MASK (0x4000U)
#define IOMUX_REG_28FDSOI_COMP_COMPOK_SHIFT (14U)
#define IOMUX_REG_28FDSOI_COMP_COMPOK(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_COMPOK_SHIFT)) & IOMUX_REG_28FDSOI_COMP_COMPOK_MASK)
#define IOMUX_REG_28FDSOI_COMP_READ_NASRC_MASK (0x78000U)
#define IOMUX_REG_28FDSOI_COMP_READ_NASRC_SHIFT (15U)
#define IOMUX_REG_28FDSOI_COMP_READ_NASRC(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_READ_NASRC_SHIFT)) & IOMUX_REG_28FDSOI_COMP_READ_NASRC_MASK)
#define IOMUX_REG_28FDSOI_COMP_SLEEP_MASK (0x1800000U)
#define IOMUX_REG_28FDSOI_COMP_SLEEP_SHIFT (23U)
#define IOMUX_REG_28FDSOI_COMP_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_SLEEP_SHIFT)) & IOMUX_REG_28FDSOI_COMP_SLEEP_MASK)
#define IOMUX_REG_28FDSOI_COMP_UPDATE_PAD_CTL_MASK (0x40000000U)
#define IOMUX_REG_28FDSOI_COMP_UPDATE_PAD_CTL_SHIFT (30U)
#define IOMUX_REG_28FDSOI_COMP_UPDATE_PAD_CTL(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_UPDATE_PAD_CTL_SHIFT)) & IOMUX_REG_28FDSOI_COMP_UPDATE_PAD_CTL_MASK)
#define IOMUX_REG_28FDSOI_COMP_UPDATE_MUX_MODE_MASK (0x80000000U)
#define IOMUX_REG_28FDSOI_COMP_UPDATE_MUX_MODE_SHIFT (31U)
#define IOMUX_REG_28FDSOI_COMP_UPDATE_MUX_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUX_REG_28FDSOI_COMP_UPDATE_MUX_MODE_SHIFT)) & IOMUX_REG_28FDSOI_COMP_UPDATE_MUX_MODE_MASK)

/*!
 * @}
 */ /* end of group PAD_Register_Masks */


/*!
 * @name Constants and macros for entire PAD_IOMUX register
 */
/** @{ */
#define HW_PAD_IOMUX_ADDR(x, y)   ((uintptr_t)(x) + (y))
#define HW_PAD_IOMUX(x, y)        (*(__IO PAD_Type *) HW_PAD_IOMUX_ADDR(x, y))
#define HW_PAD_IOMUX_RD(x, y)     (HW_PAD_IOMUX(x, y).RW)
#define HW_PAD_IOMUX_WR(x, y)     (HW_PAD_IOMUX(x, y).RW)
/** @} */

/*!
 * @}
 */ /* end of group XRDC2_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* XRDC2_H */

