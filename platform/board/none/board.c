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
 * File containing empty implementation of the board.
 *
 * @addtogroup NO_BRD BRD: No Board
 *
 * Module for no board access.
 *
 * @{
 */
/*==========================================================================*/

/* Includes */

#include "main/build_info.h"
#include "main/scfw.h"
#include "main/main.h"
#include "main/board.h"
#include "main/boot.h"
#include "main/soc.h"
#ifdef SIMU
    #include "main/simu.h"
#endif
#include "all_svc.h"
#include "drivers/lpuart/fsl_lpuart.h"
#include "pads.h"

/* Local Defines */

/*!
 * @name Board Configuration
 * DO NOT CHANGE - must match object code.
 */
/** @{ */
#define BRD_NUM_RSRC            11U
#define BRD_NUM_CTRL            6U
/** @} */

/*!
 * @name Board Resources
 * DO NOT CHANGE - must match object code.
 */
/** @{ */
#define BRD_R_BOARD_PMIC_0      0U
#define BRD_R_BOARD_PMIC_1      1U
#define BRD_R_BOARD_PMIC_2      2U
#define BRD_R_BOARD_R0          3U
#define BRD_R_BOARD_R1          4U
#define BRD_R_BOARD_R2          5U
#define BRD_R_BOARD_R3          6U
#define BRD_R_BOARD_R4          7U
#define BRD_R_BOARD_R5          8U
#define BRD_R_BOARD_R6          9U
#define BRD_R_BOARD_R7          10U
/** @} */

/*! Configure debug UART */
#define LPUART_DEBUG            LPUART_SC

/*! Configure debug UART instance */
#define LPUART_DEBUG_INST       0

#ifdef EMUL
    /*! Configure debug baud rate */
    #define DEBUG_BAUD              4000000U
#else
    /*! Configure debug baud rate */
    #define DEBUG_BAUD              115200U
#endif

/* Local Types */

/* Local Functions */

/* Local Variables */

/*!
 * This constant contains info to map resources to the board.
 * DO NOT CHANGE - must match object code.
 */
const sc_rsrc_map_t board_rsrc_map[BRD_NUM_RSRC_BRD] =
{
    RSRC(PMIC_0,   0,  0),
    RSRC(PMIC_1,   0,  1),
    RSRC(PMIC_2,   0,  2),
    RSRC(BOARD_R0, 0,  3),
    RSRC(BOARD_R1, 0,  4),
    RSRC(BOARD_R2, 0,  5),
    RSRC(BOARD_R3, 0,  6),
    RSRC(BOARD_R4, 0,  7),
    RSRC(BOARD_R5, 0,  8),
    RSRC(BOARD_R6, 0,  9),
    RSRC(BOARD_R7, 0, 10)
};

/* Block of comments that get processed for documentation
   DO NOT CHANGE - must match object code. */
#ifdef DOX
    RNFO() /* PMIC 0 */
    RNFO() /* PMIC 1 */
    RNFO() /* PMIC 2 */
    RNFO() /* Misc. board component 0 */
    RNFO() /* Misc. board component 1 */
    RNFO() /* Misc. board component 2 */
    RNFO() /* Misc. board component 3 */
    RNFO() /* Misc. board component 4 */
    RNFO() /* Misc. board component 5 */
    RNFO() /* Misc. board component 6 */
    RNFO() /* Misc. board component 7 */
    TNFO(PMIC_0, TEMP,     RO, x, 8) /* Temperature sensor temp */
    TNFO(PMIC_0, TEMP_HI,  RW, x, 8) /* Temperature sensor high limit alarm temp */
    TNFO(PMIC_1, TEMP,     RO, x, 8) /* Temperature sensor temp */
    TNFO(PMIC_1, TEMP_HI,  RW, x, 8) /* Temperature sensor high limit alarm temp */
    TNFO(PMIC_2, TEMP,     RO, x, 8) /* Temperature sensor temp */
    TNFO(PMIC_2, TEMP_HI,  RW, x, 8) /* Temperature sensor high limit alarm temp */
#endif

/* External Variables */

const sc_rm_idx_t board_num_rsrc = BRD_NUM_RSRC_BRD;

/*!
 * External variable for specing DDR periodic training.
 */
const uint32_t board_ddr_period_ms = 0U;

const uint32_t board_ddr_derate_period_ms = 0U;

/* External Functions */

/*--------------------------------------------------------------------------*/
/* Init                                                                     */
/*--------------------------------------------------------------------------*/
void board_init(boot_phase_t phase)
{
    ss_print(3, "board_init(%d)\n", phase);

#ifdef SIMU
    if (phase == BOOT_PHASE_API_INIT)
    {
        main_simu_load_board();
    }
#endif
}

/*--------------------------------------------------------------------------*/
/* Return the debug UART info                                               */
/*--------------------------------------------------------------------------*/
LPUART_Type *board_get_debug_uart(uint8_t *inst, uint32_t *baud)
{
    *inst = LPUART_DEBUG_INST;
    *baud = DEBUG_BAUD;

    return LPUART_DEBUG;
}

/*--------------------------------------------------------------------------*/
/* Configure debug UART                                                     */
/*--------------------------------------------------------------------------*/
void board_config_debug_uart(sc_bool_t early_phase)
{
    #if defined(DEBUG) && !defined(SIMU)
        /* Power up UART */
        pm_force_resource_power_mode_v(SC_R_SC_UART,
            SC_PM_PW_MODE_ON);

        /* Return if debug enabled */
        if (SCFW_DBG_READY)
        {
            return;
        }

        /* Configure SCU UART */
        main_config_debug_uart(LPUART_DEBUG, SC_24MHZ);
    #endif
}

/*--------------------------------------------------------------------------*/
/* Disable debug UART                                                       */
/*--------------------------------------------------------------------------*/
void board_disable_debug_uart(void)
{
}

/*--------------------------------------------------------------------------*/
/* Configure SCFW resource/pins                                             */
/*--------------------------------------------------------------------------*/
void board_config_sc(sc_rm_pt_t pt_sc)
{
}

/*--------------------------------------------------------------------------*/
/* Get board parameter                                                      */
/*--------------------------------------------------------------------------*/
board_parm_rtn_t board_parameter(board_parm_t parm)
{
    /* Note return values are usually static. Can be made dynamic by storing
       return in a global variable and setting using board_set_control() */

    return main_board_parameter(parm);
}

/*--------------------------------------------------------------------------*/
/* Get resource avaiability info                                            */
/*--------------------------------------------------------------------------*/
sc_bool_t board_rsrc_avail(sc_rsrc_t rsrc)
{
    /* Return SC_FALSE here if a resource isn't available due to board
       connections (typically lack of power). Examples incluse DRC_0/1
       and ADC. */

    /* The value here may be overridden by SoC fuses or emulation config */

    /* Note return values are usually static. Can be made dynamic by storing
       return in a global variable and setting using board_set_control() */

    return SC_TRUE;
}

/*--------------------------------------------------------------------------*/
/* Override QoS configuration                                               */
/*--------------------------------------------------------------------------*/
void board_qos_config(sc_sub_t ss)
{
    /* This function is to allow NXP support or professional services to
     * perform such optimization for a customer or application. It is not
     * intended for direct customer use.
     */
}

/*--------------------------------------------------------------------------*/
/* Init DDR                                                                 */
/*--------------------------------------------------------------------------*/
sc_err_t board_init_ddr(sc_bool_t early, sc_bool_t ddr_initalized)
{
    board_print(3, "board_init_ddr(%d)\n", early);

    return SC_ERR_UNAVAILABLE;
}

/*--------------------------------------------------------------------------*/
/* Take action on DDR                                                       */
/*--------------------------------------------------------------------------*/
sc_err_t board_ddr_config(bool rom_caller, board_ddr_action_t action)
{
    /* Note this is called by the ROM before the SCFW is initialized.
     * Do NOT make any unqualified calls to any other APIs.
     */

    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Configure the system (inc. additional resource partitions)               */
/*--------------------------------------------------------------------------*/
void board_system_config(sc_bool_t early, sc_rm_pt_t pt_boot)
{
    /* This function configures the system. It usually partitions
       resources according to the system design. It must be modified by
       customers. Partitions should then be specified using the mkimage
       -p option. */

    board_print(3, "board_system_config(%d)\n", early);

    /* Name default partitions */
    PARTITION_NAME(SC_PT, "SCU");
    PARTITION_NAME(SECO_PT, "SECO");
    PARTITION_NAME(pt_boot, "BOOT");
}

/*--------------------------------------------------------------------------*/
/* Early CPU query                                                          */
/*--------------------------------------------------------------------------*/
sc_bool_t board_early_cpu(sc_rsrc_t cpu)
{
    return SC_FALSE;
}

/*--------------------------------------------------------------------------*/
/* Transition external board-level SoC power domain                         */
/*--------------------------------------------------------------------------*/
void board_set_power_mode(sc_sub_t ss, uint8_t pd,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode)
{
    board_print(3, "board_set_power_mode(%s, %d, %d, %d)\n", snames[ss],
        pd, from_mode, to_mode);
}

/*--------------------------------------------------------------------------*/
/* Set the voltage for the given SS.                                        */
/*--------------------------------------------------------------------------*/
sc_err_t board_set_voltage(sc_sub_t ss, uint32_t new_volt, uint32_t old_volt)
{
    return SC_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
/* Set board power supplies when enter/exit low-power mode                  */
/*--------------------------------------------------------------------------*/
void board_lpm(sc_pm_power_mode_t mode)
{
}

/*--------------------------------------------------------------------------*/
/* Transition external board-level supply for board component               */
/*--------------------------------------------------------------------------*/
void board_trans_resource_power(sc_rm_idx_t idx, sc_rm_idx_t rsrc_idx,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode)
{
    board_print(3, "board_trans_resource_power(%d, %s, %d, %d)\n", idx,
        rnames[rsrc_idx], from_mode, to_mode);
}

/*--------------------------------------------------------------------------*/
/* Reset a board resource                                                   */
/*--------------------------------------------------------------------------*/
void board_rsrc_reset(sc_rm_idx_t idx, sc_rm_idx_t rsrc_idx, sc_rm_pt_t pt)
{
}

/*--------------------------------------------------------------------------*/
/* Set board power mode                                                     */
/*--------------------------------------------------------------------------*/
sc_err_t board_power(sc_pm_power_mode_t mode)
{
    return SC_ERR_UNAVAILABLE;
}

/*--------------------------------------------------------------------------*/
/* Reset board                                                              */
/*--------------------------------------------------------------------------*/
sc_err_t board_reset(sc_pm_reset_type_t type, sc_pm_reset_reason_t reason,
    sc_rm_pt_t pt)
{
    #ifndef SIMU
        #ifdef DEBUG
            /* Dump out caller of reset request */
            always_print("Board reset (%u, caller = 0x%08X)\n", reason,
                __builtin_return_address(0));

            /* Invoke LPUART deinit to drain TX buffers if a warm reset follows */
            LPUART_Deinit(LPUART_DEBUG);
        #endif

        /* Request a warm reset */
        soc_set_reset_info(reason, pt);
        NVIC_SystemReset();
    #endif

    return SC_ERR_UNAVAILABLE;
}

/*--------------------------------------------------------------------------*/
/* Handle CPU reset event                                                   */
/*--------------------------------------------------------------------------*/
void board_cpu_reset(sc_rsrc_t resource, board_cpu_rst_ev_t reset_event,
    sc_rm_pt_t pt)
{
    /* Note:  Production code should decide the response for each type
     *        of reset event.  Options include allowing the SCFW to
     *        reset the CPU or forcing a full system reset.  Additionally,
     *        the number of reset attempts can be tracked to determine the
     *        reset response.
     */

    /* Check for MCU reset event */
    if ((resource == SC_R_MCU_0_PID0) || (resource == SC_R_MCU_1_PID0))
    {
        always_print("MCU reset event (rsrc = %d, event = %d)\n", resource,
            reset_event);

        /* Treat lockups or parity/ECC reset events as board faults */
        if ((reset_event == BOARD_CPU_RESET_LOCKUP) ||
            (reset_event == BOARD_CPU_RESET_MEM_ERR))
        {
            board_fault(SC_FALSE, BOARD_BFAULT_CPU, pt);
        }
    }

    /* Returning from this function will result in an attempt reset the
       partition or board depending on the event and wdog action. */
}

/*--------------------------------------------------------------------------*/
/* Trap partition reboot                                                    */
/*--------------------------------------------------------------------------*/
void board_reboot_part(sc_rm_pt_t pt, sc_pm_reset_type_t *type,
    sc_pm_reset_reason_t *reason, sc_pm_power_mode_t *mode,
    uint32_t *mask)
{
    /* Code can modify or log the parameters. Can also take another action like
     * reset the board. After return from this function, the partition will be
     * rebooted.
     */
    *mask = 0UL;
}

/*--------------------------------------------------------------------------*/
/* Trap partition reboot continue                                           */
/*--------------------------------------------------------------------------*/
void board_reboot_part_cont(sc_rm_pt_t pt, sc_rsrc_t *boot_cpu,
    sc_rsrc_t *boot_mu, sc_rsrc_t *boot_dev, sc_faddr_t *boot_addr)
{
    /* Code can modify boot parameters on a reboot. Called after partition
     * is powered off but before it is powered back on and started.
     */
}

/*--------------------------------------------------------------------------*/
/* Return partition reboot timeout action                                   */
/*--------------------------------------------------------------------------*/
board_reboot_to_t board_reboot_timeout(sc_rm_pt_t pt)
{
    /* Return the action to take if a partition reboot requires continue
     * ack for others and does not happen before timeout */
    return BOARD_REBOOT_TO_FORCE;
}

/*--------------------------------------------------------------------------*/
/* Handle panic temp alarm                                                  */
/*--------------------------------------------------------------------------*/
void board_panic(sc_dsc_t dsc)
{
    /* See Porting Guide for more info on panic alarms */
    #ifdef DEBUG
        error_print("Panic temp (dsc=%d)\n", dsc);
    #endif

    board_reset(SC_PM_RESET_TYPE_BOARD, SC_PM_RESET_REASON_TEMP,
        SC_PT);
}

/*--------------------------------------------------------------------------*/
/* Handle fault or return from main()                                       */
/*--------------------------------------------------------------------------*/
void board_fault(sc_bool_t restarted, sc_bfault_t reason,
    sc_rm_pt_t pt)
{
    /* Note, delete the DEBUG case if fault behavior should be like
       typical production build even if DEBUG defined */

    #ifdef DEBUG
        /* Disable the watchdog */
        board_wdog_disable(SC_FALSE);

        board_print(1, "board fault(%u, %u, %u)\n", restarted, reason, pt);

        /* Stop so developer can see WDOG occurred */
        #ifndef SIMU
            HALT;
        #endif
    #else
        /* Was this called to report a previous WDOG restart? */
        if (restarted == SC_FALSE)
        {
            /* Fault just occurred, need to reset */
            board_reset(SC_PM_RESET_TYPE_BOARD,
                SC_PM_RESET_REASON_SCFW_FAULT, pt);

            /* Wait for reset */
            HALT;
        }
        /* Issue was before restart so just return */
    #endif
}

/*--------------------------------------------------------------------------*/
/* Handle SECO/V2X FW fault                                                 */
/*--------------------------------------------------------------------------*/
void board_sec_fault(uint8_t abort_module, uint8_t abort_line,
    sc_sfault_t reason)
{
    if (reason == BOARD_SFAULT_SECO_ABORT)
    {
        error_print("SECO Abort (mod %d, ln %d)\n", abort_module,
            abort_line);
    }
    else if (reason == BOARD_SFAULT_V2X_ABORT)
    {
        error_print("V2X Abort (mod %d, ln %d)\n", abort_module,
            abort_line);
    }
    else
    {
        error_print("V2X Serious Err\n");
    }
}

/*--------------------------------------------------------------------------*/
/* Handle SECO/SNVS security violation                                      */
/*--------------------------------------------------------------------------*/
void board_security_violation(void)
{
    always_print("SNVS security violation\n");
}

/*--------------------------------------------------------------------------*/
/* Get the status of the ON/OFF button                                      */
/*--------------------------------------------------------------------------*/
sc_bool_t board_get_button_status(void)
{
    return SC_FALSE;
}

/*--------------------------------------------------------------------------*/
/* Set control value                                                        */
/*--------------------------------------------------------------------------*/
sc_err_t board_set_control(sc_rsrc_t resource, sc_rm_idx_t idx,
    sc_rm_idx_t rsrc_idx, uint32_t ctrl, uint32_t val)
{
    sc_err_t err = SC_ERR_NOTFOUND;

    board_print(3,
        "board_set_control(%s, %u)\n", rnames[rsrc_idx], ctrl);

#ifdef SIMU
    if (resource == SC_R_PMIC_0)
    {
        err = SC_ERR_NONE;
    }
#endif

    return err;;
}

/*--------------------------------------------------------------------------*/
/* Get control value                                                        */
/*--------------------------------------------------------------------------*/
sc_err_t board_get_control(sc_rsrc_t resource, sc_rm_idx_t idx,
    sc_rm_idx_t rsrc_idx, uint32_t ctrl, uint32_t *val)
{
    sc_err_t err = SC_ERR_NOTFOUND;

    board_print(3,
        "board_get_control(%s, %u)\n", rnames[rsrc_idx], ctrl);

    #ifdef SIMU
        if (resource == SC_R_PMIC_0)
        {
            err = SC_ERR_NONE;
        }
    #endif
    
    return err;;
}

/*--------------------------------------------------------------------------*/
/* Board tick                                                               */
/*--------------------------------------------------------------------------*/
void board_tick(uint16_t msec)
{
}

/*--------------------------------------------------------------------------*/
/* Board IOCTL function                                                     */
/*--------------------------------------------------------------------------*/
sc_err_t board_ioctl(sc_rm_pt_t caller_pt, sc_rsrc_t mu, uint32_t *parm1,
    uint32_t *parm2, uint32_t *parm3)
{
    sc_err_t err = SC_ERR_NONE;

    /* For test_misc */
    if (*parm1 == 0xFFFFFFFEU)
    {
        *parm1 = *parm2 + *parm3;
        *parm2 = mu;
        *parm3 = caller_pt;
    }
    else
    {
        err = SC_ERR_PARM;
    }

    return err;
}

/** @} */

