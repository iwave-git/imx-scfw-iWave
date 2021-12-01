/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017-2020 NXP
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

#ifndef DRV_PMIC_H
#define DRV_PMIC_H

/*!
 * @addtogroup pmic_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"
#include "drivers/lpi2c/fsl_lpi2c.h"

/* Defines */
#define i2c_error_flags             (U32(kLPI2C_MasterArbitrationLostFlag) |        \
                                     U32(kLPI2C_MasterFifoErrFlag) |                \
                                     U32(kLPI2C_MasterPinLowTimeoutFlag) |          \
                                     U32(kLPI2C_MasterDataMatchFlag) |              \
                                     U32(kLPI2C_MasterBusyFlag) |                   \
                                     U32(kLPI2C_MasterBusBusyFlag))
/* Types */

/*!
 * This type is used to declare which PMIC to address
 */
typedef uint8_t pmic_id_t;

/*!
 * Structure for ID and Revision of PMIC
 */
typedef struct
{
    uint8_t device_id; /*!< dev ID value (reg location may differ per device) */
    uint8_t si_rev;    /*!< silicon revision value read from device           */
} pmic_version_t;

/*!
 * This function is a simple write to an i2c register on the PMIC
 *
 * @param[in]       device_addr     I2C address of device
 * @param[in]       reg             address of register on device
 * @param[in]       data            data to be written
 * @param[in]       dataLength      length of data to be written
 *
 * @return Returns the status of the write (success = kStatus_Success)
 *
 * Return errors
 * - kStatus_Fail if any of the transactions failed
 *
 * Note there is no clock management in this function
 */
status_t i2c_write_sub(uint8_t device_addr, uint8_t reg, void *data,
    uint32_t dataLength);

/*!
 * This function writes an i2c register on the PMIC device
 * with clock management
 *
 * @param[in]       device_addr     I2C address of device
 * @param[in]       reg             address of register on device
 * @param[in]       data            data to be written
 * @param[in]       dataLength      length of data to be written
 *
 * @return Returns the status of the write (success = kStatus_Success)
 *
 * Return errors
 * - kStatus_Fail if any of the transactions failed
 */

status_t i2c_write(uint8_t device_addr, uint8_t reg, void *data,
    uint32_t dataLength);

/*!
 * This function is a simple read of an i2c register on the PMIC
 *
 * @param[in]       device_addr     I2C address of device
 * @param[in]       reg             address of register on device
 * @param[out]      data            data to be read
 * @param[in]       dataLength      length of data to be read
 *
 * @returns Returns the status of the read (success = kStatus_Success)
 *
 * Return errors
 * - kStatus_Fail if any of the transactions failed
 */

status_t i2c_read_sub(uint8_t device_addr, uint8_t reg, void *data,
    uint32_t dataLength);

/*!
 * This function reads an i2c register on the PMIC device
 * with clock management
 *
 * @param[in]       device_addr     I2C address of device
 * @param[in]       reg             address of register on device
 * @param[out]      data            data to be read
 * @param[in]       dataLength      length of data to be read
 *
 * @returns Returns the status of the read (success = kStatus_Success)
 *
 * Return errors
 * - kStatus_Fail if any of the transactions failed
 */

status_t i2c_read(uint8_t device_addr, uint8_t reg, void *data,
    uint32_t dataLength);


/*!
 * This function writes an i2c register on the PMIC device
 * with j1850 CRC appended and clock management
 *
 * @param[in]       device_addr     I2C address of device
 * @param[in]       reg             address of register on device
 * @param[in]       data            data to be written
 * @param[in]       dataLength      length of data to be written
 *
 * @return Returns the status of the write (success = kStatus_Success)
 *
 * Return errors
 * - kStatus_Fail if any of the transactions failed
 */
status_t i2c_j1850_write(uint8_t device_addr, uint8_t reg, void *data,
    uint32_t dataLength);

/*!
 * This function reads an i2c register on the PMIC device with j1850 CRC
 * and clock management
 *
 * @param[in]       device_addr     I2C address of device
 * @param[in]       reg             address of register on device
 * @param[out]      data            data to be read
 * @param[in]       dataLength      length of data to be read
 *
 * @returns Returns the status of the read (success = kStatus_Success)
 *
 * Return errors
 * - kStatus_Fail if any of the transactions failed
 */
status_t i2c_j1850_read(uint8_t device_addr, uint8_t reg, void *data,
    uint32_t dataLength);

/*!
 * This function reads the register at address 0x0 for the Device ID
 *
 * @param[in]     address           I2C address of device
 *
 * @returns Returns the device ID
 *
 * Return Errors
 * - 0 if any error in the function
 */
uint8_t pmic_get_device_id(uint8_t address);

#endif

/** @} */

