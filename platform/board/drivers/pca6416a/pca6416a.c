/*
** ###################################################################
**
**     Copyright 2020 NXP
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
 * Implementation of PCA6416A functions
 */
/*==========================================================================*/

/* Includes */

#include "drivers/pmic/fsl_pmic.h"
#include "board/drivers/pca6416a/pca6416a.h"

/* Local Defines */

/*!
 * @name I2C Bus Expander Registers
 */
/** @{ */
#define BUS_EXP_IN_REG          0x00U
#define BUS_EXP_OUT_REG         0x02U
#define BUS_EXP_POL_REG         0x04U
#define BUS_EXP_CONF_REG        0x06U
/** @} */

/*--------------------------------------------------------------------------*/
/* Write pin direction register                                             */
/*--------------------------------------------------------------------------*/
status_t PCA6416A_WritePinDirection(uint8_t device_addr, uint8_t port,
    uint8_t dir)
{
    uint8_t temp = dir;
    
    /* Return result */
    return i2c_write(device_addr, BUS_EXP_CONF_REG + port, &temp, 1U);
}

/*--------------------------------------------------------------------------*/
/* Read pin direction register                                              */
/*--------------------------------------------------------------------------*/
status_t PCA6416A_ReadPinDirection(uint8_t device_addr, uint8_t port,
    uint8_t *dir)
{
    /* Return result */
    return i2c_read(device_addr, BUS_EXP_CONF_REG + port, dir, 1U);
}

/*--------------------------------------------------------------------------*/
/* Write pin polarity register                                              */
/*--------------------------------------------------------------------------*/
status_t PCA6416A_WritePinPolarity(uint8_t device_addr, uint8_t port,
    uint8_t pol)
{
    uint8_t temp = pol;
    
    /* Return result */
    return i2c_write(device_addr, BUS_EXP_POL_REG + port, &temp, 1U);
}

/*--------------------------------------------------------------------------*/
/* Read pin polarity register                                               */
/*--------------------------------------------------------------------------*/
status_t PCA6416A_ReadPinPolarity(uint8_t device_addr, uint8_t port,
    uint8_t *pol)
{
    /* Return result */
    return i2c_read(device_addr, BUS_EXP_POL_REG + port, pol, 1U);
}

/*--------------------------------------------------------------------------*/
/* Write pin output register                                                */
/*--------------------------------------------------------------------------*/
status_t PCA6416A_WritePinOutput(uint8_t device_addr, uint8_t port,
    uint8_t out)
{
    uint8_t temp = out;
    
    /* Return result */
    return i2c_write(device_addr, BUS_EXP_OUT_REG + port, &temp, 1U);
}

/*--------------------------------------------------------------------------*/
/* Read pin output register                                                 */
/*--------------------------------------------------------------------------*/
status_t PCA6416A_ReadPinOutput(uint8_t device_addr, uint8_t port,
    uint8_t *out)
{
    /* Return result */
    return i2c_read(device_addr, BUS_EXP_OUT_REG + port, out, 1U);
}

/*--------------------------------------------------------------------------*/
/* Read pin input register                                                  */
/*--------------------------------------------------------------------------*/
status_t PCA6416A_ReadPinInput(uint8_t device_addr, uint8_t port,
    uint8_t *in)
{
    /* Return result */
    return i2c_read(device_addr, BUS_EXP_IN_REG + port, in, 1U);
}

