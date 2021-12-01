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
 * Header file for the SIMU functions.
 */
/*==========================================================================*/

#ifndef SC_SIMU_H
#define SC_SIMU_H

/* Includes */

#include "main/types.h"
#include "main/boot.h"
#include "main/board.h"
#include "main/simu.h"

/* Defines */

/* Types */

/* Functions */

void main_simu_init(int argc, char * const argv[]);
void main_simu_load_fuses(void);
sc_bool_t main_simu_fuses_loaded(void);
const sc_boot_data_t *main_simu_rom_load_bd(
    const sc_boot_data_t *boot_data);
const sc_boot_data2_t * main_simu_rom_load_bd2(
    const sc_boot_data2_t *boot_data2);
const sc_passover_t * main_simu_rom_load_po(
    const sc_passover_t *passover_data);
void main_simu_load_board(void);
board_parm_rtn_t main_board_parameter(board_parm_t parm);

#endif /* SC_SIMU_H */

