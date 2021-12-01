/*
 * Copyright 2017-2021 NXP
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

#ifndef FSL_NIC400_H
#define FSL_NIC400_H

#include "fsl_common.h"

/*!
 * @addtogroup nic400_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/** @{ */
/*! @brief NIC400 driver version 1.0.0. */
#define FSL_NIC400_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/** @} */

/*! @brief NIC400 Master interface base offset. */
#define NIC400_MSTR_INTF_OFFSET 0x00002000U

/*! @brief NIC400 Slave interface base offset. */
#define NIC400_SLV_INTF_OFFSET 0x00042000U

/*! @brief NIC400 Internal interface base offset. */
#define NIC400_INT_INTF_OFFSET 0x000C2000U

/*! @brief NIC400 Slave interface size. */
#define NIC400_SLV_INTF_BLKSZ 0x00001000U

/*! @brief NIC400 Max index of Slave interface. */
#define NIC400_MAX_SLV_INTF_IDX 127U

#define NIC400_ASIB_READ_QOS_REG 0x100U
#define NIC400_ASIB_WRITE_QOS_REG 0x104U
#define NIC400_ASIB_FN_MOD_REG 0x108U

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!
 * @brief Set NIC400 ASIB register.
 */
void NIC400_Set_ASIB(uint32_t base, uint8_t slave_num,
    uint16_t register_offset, uint8_t val);

/*!
 * @brief Get NIC400 ASIB register.
 */
uint32_t NIC400_Get_ASIB(uint32_t base, uint8_t slave_num,
    uint16_t register_offset);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_NIC400_H */

