/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This file maps GPIO functions to RGPIO functions.  It cannot be used at the
   same time as the IGPIO driver! */

#ifndef _FSL_GPIO_H_
#define _FSL_GPIO_H_

#include "drivers/rgpio/fsl_rgpio.h"

#define kGPIO_DigitalInput              kRGPIO_DigitalInput
#define kGPIO_DigitalOutput             kRGPIO_DigitalOutput

#define gpio_pin_config_t               rgpio_pin_config_t

#define GPIO_PinInit                    RGPIO_PinInit
#define GPIO_WritePinOutput             RGPIO_WritePinOutput
#define GPIO_SetPinsOutput              RGPIO_SetPinsOutput
#define GPIO_ClearPinsOutput            RGPIO_ClearPinsOutput
#define GPIO_TogglePinsOutput           RGPIO_TogglePinsOutput
#define GPIO_ReadPinInput               RGPIO_ReadPinInput
#define GPIO_GetPinsInterruptFlags      RGPIO_GetPinsInterruptFlags
#define GPIO_ClearPinsInterruptFlags    RGPIO_ClearPinsInterruptFlags

#endif /* _FSL_GPIO_H_*/
