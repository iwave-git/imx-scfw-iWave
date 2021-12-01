/*
 * Copyright 2019-2020 NXP
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

#ifndef DRV_DRC_DERATE_H
#define DRV_DRC_DERATE_H

/*!
 * @addtogroup drc_driver
 * @{
 */

/*! @file */

/* Includes */

#include "fsl_device_registers.h"

/* Defines */

/* Types */

/* Externs */

/* Functions */

/*!
 * This function initializes the DDR derate mechanism.
 *
 * @param[in]   total_num_drc   number of DDR controllers used
 */
void ddrc_lpddr4_derate_init(uint32_t total_num_drc);

/*!
 * This function performs periodic DDR derate training.
 *
 * @param[in]   total_num_drc   number of DDR controllers used
 *
 * @return  Returns SC_TRUE if timer is suppose to continue polling,
 *          otherwise SC_FALSE.
 */
sc_bool_t ddrc_lpddr4_derate_periodic(uint32_t total_num_drc);

#endif /* DRV_DRC_DERATE_H */

/** @} */

