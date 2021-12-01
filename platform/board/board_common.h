/*
** ###################################################################
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
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @file
 *
 * Header file containing some common board functions.
 *
 * @addtogroup BRD_SVC BRD: Board Interface
 *
 * @{
 */
/*==========================================================================*/

#ifndef SC_BOARD_COMMON_H
#define SC_BOARD_COMMON_H

/* Includes */

/* Defines */

/* External variables */

/*! Shim debug variable (to allow object package config) */
extern sc_bool_t debug;

/*! Shim debug level variable (to allow object package config) */
extern int8_t debug_level;

/*! Shim has_test variable (to allow object package config) */
extern sc_bool_t has_test;

/*! Shim test_all variable (to allow object package config) */
extern sc_bool_t test_all;

/*! Shim has_monitor variable (to allow object package config) */
extern sc_bool_t has_monitor;

/*! Shim xrdc_nocheck variable (to allow object package config) */
extern sc_bool_t xrdc_nocheck;

/*! Shim pkit_dirty variable (to allow object package config) */
extern sc_bool_t pkit_dirty;

/* Functions */

/*!
 * Shim test function (to allow test inclusion from object packages)
 *
 * @param[in]     stop          flag indicating if test run should stop
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 */
sc_err_t test_drv(sc_bool_t *const stop);

/*!
 * Shim test function (to allow test inclusion from object packages)
 *
 * @param[in]     stop          flag indicating if test run should stop
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 */
sc_err_t test_sc(sc_bool_t *const stop);

/*!
 * Shim test function (to allow test inclusion from object packages)
 *
 * @param[in]     stop          flag indicating if test run should stop
 *
 * @return Returns an error code (SC_ERR_NONE = success)
 */
sc_err_t test_ap(sc_bool_t *const stop);

/*!
 * Shim monitor function (to allow monitor inclusion from object packages)
 */
void board_monitor(void);

/*!
 * Shim for exit()
 */
void board_exit(int32_t status);

/*!
 * Shim for setvbuf()
 */
void board_stdio(void);

/*!
 * Shim for watchdog disable
 *
 * @param[in]     lp            SC_TRUE = entry of KS1 LP mode
 */
void board_wdog_disable(sc_bool_t lp);

/*!
 * Shim for soc_ddr_dqs2dq_init()
 */
void board_ddr_dqs2dq_init(void);

/*!
 * Shim for soc_ddr_dqs2dq_sync()
 */
void board_ddr_dqs2dq_sync(void);

/*!
 * Conditional printf
 */
void board_printf(const char *fmt, ...);

/*!
 * Enable/disable the DDR periodic tick.
 *
 * @param[in]     enb           enable flag (SC_TRUE = on)
 */
void board_ddr_periodic_enable(sc_bool_t enb);

/*!
 * Enable/disable the DDR derate periodic tick.
 *
 * @param[in]     enb           enable flag (SC_TRUE = on)
 */
void board_ddr_derate_periodic_enable(sc_bool_t enb);

/*!
 * Common function to tick the board.
 *
 * @param[in]     msec          number of mS to increment
 */
void board_common_tick(uint16_t msec);

/** @} */

#endif /* SC_BOARD_COMMON_H */

