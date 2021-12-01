/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
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
 * Header file containing the DB subsystem API.
 *
 * @addtogroup DB_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_DB_SS_H
#define SC_SS_DB_SS_H

#include "ss/inf/inf.h"

/* Types */

typedef enum
{
    SS_V2X_AUTH_IP,
    SS_V2X_AUTH_PASS,
    SS_V2X_AUTH_FAIL   
} ss_v2x_state_t;

/* Externs */

SS_BASE_INFO_PROTO(db)

/* Functions */

SS_FUNC_PROTO_DB

void ss_auto_clock_gate_db(sc_bool_t enable);
void ss_v2x_enable(void);
void ss_v2x_set_state(ss_v2x_state_t state);
ss_v2x_state_t ss_v2x_get_state(void);
sc_bool_t ss_v2x_clock_run(sc_bool_t enable);
void ss_v2x_auth_finish(sc_bool_t fw_load, sc_bool_t clr_irq);

/* External variables */

extern const ss_dsc_l2irq_handler ss_l2irq_handlers_db[];

#endif /* SC_SS_DB_SS_H */

/** @} */

