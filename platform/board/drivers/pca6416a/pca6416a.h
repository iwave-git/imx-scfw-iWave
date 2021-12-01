/*
** ###################################################################
**
**     Copyright 2020-2021 NXP
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
 * @brief Functions for PCA6416A.
 *
 * @addtogroup pca6416a_driver PCA6416A: PCA6416A Driver
 * @{
 */
/*==========================================================================*/

#ifndef SC_PCA6416A_H
#define SC_PCA6416A_H

/* Includes */

#include "drivers/pmic/fsl_pmic.h"

/* Functions */

/*!
 * This function writes the pin direction register.
 *
 * @param[in]     device_addr   I2C address
 * @param[in]     port          expander port
 * @param[in]     dir           direction (0=output, 1=input)
 *
 * @return Returns the I2C status.
 */
status_t PCA6416A_WritePinDirection(uint8_t device_addr, uint8_t port,
    uint8_t dir);

/*!
 * This function reads the pin direction register.
 *
 * @param[in]     device_addr   I2C address
 * @param[in]     port          expander port
 * @param[out]    dir           pointer to return the direction (0=output, 1=input)
 *
 * @return Returns the I2C status.
 */
status_t PCA6416A_ReadPinDirection(uint8_t device_addr, uint8_t port,
    uint8_t *dir);

/*!
 * This function writes the pin polarity register.
 *
 * @param[in]     device_addr   I2C address
 * @param[in]     port          expander port
 * @param[in]     pol           polarity (1=invert)
 *
 * @return Returns the I2C status.
 */
status_t PCA6416A_WritePinPolarity(uint8_t device_addr, uint8_t port,
    uint8_t pol);

/*!
 * This function reads the pin polarity register.
 *
 * @param[in]     device_addr   I2C address
 * @param[in]     port          expander port
 * @param[out]    pol           pointer to return the polarity (1=invert)
 *
 * @return Returns the I2C status.
 */
status_t PCA6416A_ReadPinPolarity(uint8_t device_addr, uint8_t port,
    uint8_t *pol);

/*!
 * This function writes the pin output register.
 *
 * @param[in]     device_addr   I2C address
 * @param[in]     port          expander port
 * @param[in]     out           output value
 *
 * @return Returns the I2C status.
 */
status_t PCA6416A_WritePinOutput(uint8_t device_addr, uint8_t port,
    uint8_t out);

/*!
 * This function reads the pin output register.
 *
 * @param[in]     device_addr   I2C address
 * @param[in]     port          expander port
 * @param[out]    out           pointer to return the output
 *
 * @return Returns the I2C status.
 */
status_t PCA6416A_ReadPinOutput(uint8_t device_addr, uint8_t port,
    uint8_t *out);

/*!
 * This function reads the pin input register.
 *
 * @param[in]     device_addr   I2C address
 * @param[in]     port          expander port
 * @param[out]    in            input
 *
 * @return Returns the I2C status.
 */
status_t PCA6416A_ReadPinInput(uint8_t device_addr, uint8_t port,
    uint8_t *in);

 /** @} */

 #endif /* SC_PCA6416A_H */

