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
 * Header file containing the board API.
 *
 * @addtogroup BRD_SVC BRD: Board Interface
 *
 * Module for the Board interface.
 *
 * @{
 */
/*==========================================================================*/

#ifndef SC_BOARD_API_H
#define SC_BOARD_API_H

/* Defines */

#define BOARD_PARM_RTN_NOT_USED             0U   /*!< Feature not used */
#define BOARD_PARM_RTN_USED                 1U   /*!< Feature used */

#define BOARD_PARM_RTN_EXTERNAL             2U   /*!< Return value for BOARD_PARM_PCIE_PLL */
#define BOARD_PARM_RTN_INTERNAL             3U   /*!< Return value for BOARD_PARM_PCIE_PLL */
#define BOARD_PARM_RTN_INTERNAL_DPLL        4U   /*!< Return value for BOARD_PARM_PCIE_PLL (DXL only) */

#define BOARD_PARM_RTN_DPLL_SS_0_5          5U   /*!< 0.5% spread of PCIE DPLL frequency. */
#define BOARD_PARM_RTN_DPLL_SS_1           10U   /*!< 1% spread of PCIE DPLL frequency. */
#define BOARD_PARM_RTN_DPLL_SS_1_5         15U   /*!< 1.5% spread of PCIE DPLL frequency. */
#define BOARD_PARM_RTN_DPLL_SS_2           20U   /*!< 2% spread of PCIE DPLL frequency. */

/* Used to specify VDD_MEMC on the board. Must match the board design.
   See the Porting Guide and i.MX8DXL Data Sheet. */
#define BOARD_PARM_RTN_VDD_MEMC_NOM         0U   /*!< VDD_MEMC nominal - 1.0v */
#define BOARD_PARM_RTN_VDD_MEMC_OD          1U   /*!< VDD_MEMC overdrive - 1.1v */

#define BOARD_PARM_KS1_RETENTION_DISABLE    0U   /*!< Disable retention during KS1 */
#define BOARD_PARM_KS1_RETENTION_ENABLE     1U   /*!< Enable retention during KS1 */

#define BOARD_PARM_KS1_ONOFF_WAKE_DISABLE   0U   /*!< Disable ONOFF wakeup during KS1 */
#define BOARD_PARM_KS1_ONOFF_WAKE_ENABLE    1U   /*!< Enable ONOFF wakeup during KS1 */

#define BOARD_PARM_KS1_WDOG_WAKE_ENABLE     0U   /*!< Enable SC WDOG service during KS1 (required for ON_OFF wakeup on some devices) */
#define BOARD_PARM_KS1_WDOG_WAKE_DISABLE    1U   /*!< Disable SC WDOG service during KS1 (SC WDOG disabled during KS1) */

#define BOARD_PARM_RNG_START_ENABLE         0U   /*!< Enable SC start of RNG */
#define BOARD_PARM_RNG_START_DISABLE        1U   /*!< Disable SC start of RNG */

/*--------------------------------------------------------------------------*/
/* Board PLL spread spectrum fspread in part per thousand                   */
/* Supported values - 0.4% (4), 1.0% (10), 1.4% (14), 2.0% (20)             */
/*--------------------------------------------------------------------------*/
#define BOARD_PARM_SSC_N_0P4                4U   /*!< Return 0.4% fspread for PLL spread spectrum */
#define BOARD_PARM_SSC_N_1P0               10U   /*!< Return 1.0% fspread for PLL spread spectrum */
#define BOARD_PARM_SSC_N_1P4               14U   /*!< Return 1.4% fspread for PLL spread spectrum */
#define BOARD_PARM_SSC_N_2P0               20U   /*!< Return 2.0% fspread for PLL spread spectrum */

/* Log mode flags */
#define BOARD_LOG_MODE_ENABLE            BIT(0)  /*!< Log enabled */
#define BOARD_LOG_MODE_FIFO              BIT(1)  /*!< FIFO mode (wrap) */

/*! Initial log mode */
#define BOARD_LOG_MODE_INIT              (BOARD_LOG_MODE_ENABLE | BOARD_LOG_MODE_FIFO)

/* Log tags */
#define BOARD_LOG_MU_RX(X)                  ((0UL << 24) | U32(X))
#define BOARD_LOG_MU_TX(X)                  ((1UL << 24) | U32(X))
#define BOARD_LOG_SECO_TX()                 (2UL << 24)
#define BOARD_LOG_SECO_RX()                 (3UL << 24)

/* Types */

/*!
 * Board config parameter types.
 */
typedef enum
{
    BOARD_PARM_PCIE_PLL          = 0,    /*!< PCIe PLL internal or external */
    BOARD_PARM_KS1_RESUME_USEC   = 1,    /*!< Supply ramp delay in usec for KS1 exit */
    BOARD_PARM_KS1_RETENTION     = 2,    /*!< Controls if retention is applied during KS1 */
    BOARD_PARM_KS1_ONOFF_WAKE    = 3,    /*!< Controls if ONOFF button can wake from KS1 */
    BOARD_PARM_REBOOT_TIME       = 4,    /*!< Partition reboot timeout in mS */
    BOARD_PARM_DC0_PLL0_SSC      = 5,    /*!< DC0 PLL0 spread spectrum config */
    BOARD_PARM_DC0_PLL1_SSC      = 6,    /*!< DC0 PLL1 spread spectrum config */
    BOARD_PARM_DC1_PLL0_SSC      = 7,    /*!< DC1 PLL0 spread spectrum config */
    BOARD_PARM_DC1_PLL1_SSC      = 8,    /*!< DC1 PLL1 spread spectrum config */
    BOARD_PARM_ISI_PIX_FREQ      = 9,    /*!< ISI pixel clock frequency override */
    BOARD_PARM_VDD_MEMC          = 10,   /*!< VDD_MEMC voltage, valid only for DXL */
    BOARD_PARM_KS1_WDOG_WAKE     = 11,   /*!< Controls if SC WDOG configuration during KS1 */
    BOARD_PARM_PCIE_DPLL_SS      = 12,   /*!< Spread Spectrum SPREAD value for PCIE DPLL (DXL ONLY) */
    BOARD_PARM_RNG_START_BOOT    = 13,   /*!< Control if SC will start the RNG at boot (default = yes) */
    BOARD_PARM_RNG_START_KS1     = 14    /*!< Control if SC will start the RNG on KS1 exit (default = yes) */
} board_parm_t;

/*!
 * Board fault types.
 */
typedef enum
{
    BOARD_BFAULT_COMMON         = 0,    /*!< Common fault handler */
    BOARD_BFAULT_CPU            = 1,    /*!< Cortex-M ECC or lockup error */
    BOARD_BFAULT_EXIT           = 2,    /*!< SCFW exit */
    BOARD_BFAULT_DDR_RET        = 3,    /*!< DDR retention request without configuration */
    BOARD_BFAULT_REBOOT         = 4,    /*!< Undetermined partition reboot failure */
    BOARD_BFAULT_BAD_CONTAINER  = 5,    /*!< Bad boot container, invalid partitions/images */
    BOARD_BFAULT_BRD_FAIL       = 6,    /*!< Board failure - RM or PMIC, etc. */
    BOARD_BFAULT_TEST_FAIL      = 7,    /*!< Unit test failure, exit */
    BOARD_BFAULT_DDR_INIT_FAIL  = 8,    /*!< board_init_ddr() returned an error */
    BOARD_BFAULT_SEC_FAIL       = 9     /*!< SECO/V2X failure */
} sc_bfault_t;

/*!
 * Security fault types.
 */
typedef enum
{
    BOARD_SFAULT_SECO_ABORT     = 0,    /*!< SECO abort */
    BOARD_SFAULT_V2X_ABORT      = 1,    /*!< V2X abort */
    BOARD_SFAULT_V2X_SER_ERR    = 2     /*!< V2X serious error */
} sc_sfault_t;

/*!
 * Board reboot timeout actions.
 */
typedef enum
{
    BOARD_REBOOT_TO_NONE        = 0,    /*!< Reboot timeout does nothing */
    BOARD_REBOOT_TO_FORCE       = 1,    /*!< Reboot timeout forces reboot continue */
    BOARD_REBOOT_TO_FAULT       = 2     /*!< Reboot timeout causes board fault */
} board_reboot_to_t;

/*!
 * Board config parameter returns.
 */
typedef uint32_t board_parm_rtn_t;

/*!
 * Board reset event types for CPUs.
 */
typedef enum
{
    BOARD_CPU_RESET_SELF        = 0,    /*!< Self requested reset */
    BOARD_CPU_RESET_WDOG        = 1,    /*!< Watchdog reset */
    BOARD_CPU_RESET_LOCKUP      = 2,    /*!< Lockup reset */
    BOARD_CPU_RESET_MEM_ERR     = 3     /*!< Memory error reset */
} board_cpu_rst_ev_t;

/*!
 * DDR actions (power state transitions, etc.)
 */
typedef enum
{
    BOARD_DDR_COLD_INIT         = 0,    /*!< Init DDR from POR */
    BOARD_DDR_PERIODIC          = 1,    /*!< Run periodic training */
    BOARD_DDR_SR_DRC_ON_ENTER   = 2,    /*!< Enter self-refresh (leave DRC on) */
    BOARD_DDR_SR_DRC_ON_EXIT    = 3,    /*!< Exit self-refresh (DRC was on) */
    BOARD_DDR_SR_DRC_OFF_ENTER  = 4,    /*!< Enter self-refresh (turn off DRC) */
    BOARD_DDR_SR_DRC_OFF_EXIT   = 5,    /*!< Exit self-refresh (DRC was off) */
    BOARD_DDR_PERIODIC_HALT     = 6,    /*!< Halt periodic training */
    BOARD_DDR_PERIODIC_RESTART  = 7,    /*!< Restart periodic training */
    BOARD_DDR_DERATE_PERIODIC   = 8,    /*!< Run periodic derate */
    BOARD_DDR0_VREF             = 9,    /*!< Run VREF training for DRC 0 */
    BOARD_DDR1_VREF             = 10    /*!< Run VREF training for DRC 1 */
} board_ddr_action_t;

/*!
 * This type is used to store a log entry.
 */
typedef struct
{
    uint32_t timestamp;                 /*!< Time of log entry */
    uint32_t data0;                     /*!< Data value 0 */
    uint32_t data1;                     /*!< Data value 1 */
} board_log_t;

/* Macros */

/*!
 * @name Macros for DCD processing
 */
/** @{ */
#define DATA4(A, V) *((volatile uint32_t*)(A)) = U32(V)
#define SET_BIT4(A, V) *((volatile uint32_t*)(A)) |= U32(V)
#define CLR_BIT4(A, V) *((volatile uint32_t*)(A)) &= ~(U32(V))
#define CHECK_BITS_SET4(A, M) while((*((volatile uint32_t*)(A))         \
    & U32(M)) != ((uint32_t)(M))){}
#define CHECK_BITS_CLR4(A, M) while((*((volatile uint32_t*)(A))         \
    & U32(M)) != U32(0U)){}
#define CHECK_ANY_BIT_SET4(A, M) while((*((volatile uint32_t*)(A))      \
    & U32(M)) == U32(0U)){}
#define CHECK_ANY_BIT_CLR4(A, M) while((*((volatile uint32_t*)(A))      \
    & U32(M)) == U32(M)){}
/** @} */

/*!
 * Macro for debug of board calls
 */
#define BRD_ERR(X)  /* Call function */                         \
                    err = (X);                                  \
                    /* Check error returned */                  \
                    if (err != SC_ERR_NONE)                     \
                    {                                           \
                        /* Print line number */                 \
                        board_print(3, "error @ line %d: %d\n", \
                            __LINE__, err);                     \
                        /* Call board function to handle */     \
                        board_fault(SC_FALSE,                   \
                            BOARD_BFAULT_BRD_FAIL, SC_PT);      \
                    }

#if defined(DEBUG) && defined(HAS_PARTITION_NAMES)
    /*!
     * Macro for naming partitions
     */
    #define PARTITION_NAME(PT, NAME) \
        rm_part_names[PT] = NAME
#else
    /*!
     * Macro for naming partitions
     */
    #define PARTITION_NAME(PT, NAME) \
        NOP
#endif

/* Functions */

/*!
 * @name Initialization Functions
 * @{
 */

/*!
 * This function initializes the board.
 *
 * @param[in]     phase       boot phase
 *
 * There are seven phases to board initialization. The first phase is system
 * init (\a phase = BOOT_PHASE_SYS_INIT). This happens before any HW access is
 * possible. The second phase is the API phase (\a phase = BOOT_PHASE_API_INIT)
 * and initializes all of the board interface data structures. The third phase
 * (\a phase = BOOT_PHASE_HW_INIT) is the HW phase and this initializes
 * the board hardware. The fourth phase (\a phase = BOOT_PHASE_EARLY_INIT)
 * is just before starting early CPU. The fifth phase (\a phase =
 * BOOT_PHASE_LATE_INIT) is just before starting the remaining CPUs.
 * The sixth phase (\a phase = BOOT_PHASE_FINAL_INIT) is the final boot
 * phase and is used to wrap up any needed init. A test phase (\a phase =
 * BOOT_PHASE_TEST_INIT) is called only when an SCFW image is built with
 * unit tests and is called just before any tests are run.
 */
void board_init(boot_phase_t phase);

/*!
 * This function returns the debug UART info.
 *
 * @param[in]     inst        UART instance
 * @param[in]     baud        UART baud rate
 *
 * @return Pointer to the debug UART type.
 */
LPUART_Type *board_get_debug_uart(uint8_t *inst, uint32_t *baud);

/*!
 * This function initializes the debug UART.
 *
 * @param[in]     early_phase flag indicating phase
 */
void board_config_debug_uart(sc_bool_t early_phase);

/*!
 * This function powers off the debug UART.
 *
 * Only called when rebooting a partition. Only needs to power
 * down the UART if it isn't the dedicated SCU UART.
 * board_get_debug_uart() will be called again after the reboot
 * completes.
 */
void board_disable_debug_uart(void);

/*!
 * This function configures SCU resources.
 *
 * @param[in]     pt_sc       SCU partition
 *
 * By default, the SCFW keeps most of the resources found in the SCU
 * subsystem. It also keeps the SCU/PMIC pads required for the main
 * code to function. Any additional resources or pads required for
 * the board code to run should be kept here. This is done by marking
 * them as not movable.
 */
void board_config_sc(sc_rm_pt_t pt_sc);

/*!
 * This function returns board configuration info.
 *
 * @param[in]     parm        parameter to return
 *
 * This function is used to return board configuration info. Parameters
 * define if various how various SoC connections are made at the
 * board-level. For example, the external PCIe clock input.
 *
 * Note this can be called at any time in the boot process. If a return
 * value is based on run-time detection (for example reading a GPIO)
 * great care must be take to insure the return value is correct and
 * that infrastructure is powered to allow this.
 *
 * See example code (board.c) for parameter/returns options.
 *
 * @return Returns the parameter value.
 */
board_parm_rtn_t board_parameter(board_parm_t parm);

/*!
 * This function returns resource availability info.
 *
 * @param[in]     rsrc        resource to check
 *
 * This function is used to return board configuration info. It reports
 * if resources are functional on this board. For example, which DDR
 * controllers are used.
 *
 * See example code (board.c) for more details.
 *
 * @return Returns SC_TRUE if available.
 */
sc_bool_t board_rsrc_avail(sc_rsrc_t rsrc);

/*!
 * This function initializes DDR.
 *
 * @param[in]     early             phase of init
 * @param[in]     ddr_initialized   True if ROM initialized the DDR
 *
 * This function may be called twice. The early parameter is SC_TRUE when
 * called prior to MCU start and SC_FALSE when called after. This
 * allows the implementation to decide when DDR init needs to be
 * done.
 *
 * Note the first call will not occur unless SC_BD_FLAGS_EARLY_CPU_START
 * is set in bd_flags of the boot container.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t board_init_ddr(sc_bool_t early, sc_bool_t ddr_initialized);

/*!
 * This function cinfigures the DDR.
 *
 * @param[in]     rom_caller  is ROM the caller?
 * @param[in]     action      perform this action on DDR
 *
 * @return Returns SC_ERR_NONE if successful.
 *
 * This function may be called from the ROM (\a rom_caller = SC_TRUE). In
 * this case, the SCFW startup has not yet run and it is not valid to call
 * most SCFW function calls. ANA_WRITE() and SYSCTR_TimeDelay()
 * are the only two functions that have are safe to call.
 */
sc_err_t board_ddr_config(bool rom_caller, board_ddr_action_t action);

/*!
 * This function allows the board file to do SCFW configuration.
 *
 * @param[in]     early       phase of init
 * @param[in]     pt_boot     boot partition
 *
 * This function may be called twice. The early parameter is SC_TRUE when
 * called prior to MCU start and SC_FALSE when called after. This allows
 * the implementation to decide when to do configuration processing.
 *
 * Note the first call will not occur unless SC_BD_FLAGS_EARLY_CPU_START
 * is set in bd_flags of the boot container.
 *
 * Typical actions here include creating a resource partition for an MCU,
 * powering up a board component, or configuring a shared clock.
 */
void board_system_config(sc_bool_t early, sc_rm_pt_t pt_boot);

/*!
 * This function returns SC_TRUE for early CPUs.
 *
 * @param[in]     cpu         CPU
 *
 * This function should return SC_TRUE if the CPU in question may
 * be started early. This early start is before power on of later
 * CPU subsystems. It would normally return SC_TRUE for MCU cores that
 * need to run early. Only SC_R_MCU_0_PID0 and SC_R_MCU_1_PID0 can
 * return SC_TRUE.
 *
 * Note CPUs will only get started early if SC_BD_FLAGS_EARLY_CPU_START
 * is set in bd_flags of the boot container.
 *
 * @return Returns SC_TRUE if CPU should start early.
 */
sc_bool_t board_early_cpu(sc_rsrc_t cpu);

/*!
 * Function to override QoS configuration.
 *
 * @param[in]     ss            subsystem with QoS controls
 *
 * This function is to allow NXP support or professional services to
 * perform such optimization for a customer or application. It is not
 * intended for direct customer use.
 */
void board_qos_config(sc_sub_t ss);

/** @} */

/*!
 * @name Power Functions
 * @{
 */

/*!
 * This function transitions the power state for an external board-
 * level supply which goes to the i.MX8.
 *
 * @param[in]     ss          subsystem using supply
 * @param[in]     pd          power domain
 * @param[in]     from_mode   power mode transitioning from
 * @param[in]     to_mode     power mode transitioning to
 *
 * This function is used to transition a board power supply that is
 * used by the SoC. It allows mapping of subsystem power domains
 * to board supplies.
 *
 * Note that the base code will enable/disable isolators after
 * changing the state of internal power domains. External supplies
 * sometimes supply a domain connected via an isolator to a domain
 * passed here. In this case, this function needs to also control the
 * connected domain's supply. For example, when LVDS SS PD (PD1) is
 * powered toggled, the external supply for the LVDS PHY must be
 * toggled here. MIPI and CSI SS PD are similar.
 */
void board_set_power_mode(sc_sub_t ss, uint8_t pd,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);

/*!
 * This function sets the voltage for a PMIC controlled SS.
 *
 * @param[in]     ss          subsystem
 * @param[in]     new_volt    voltage value to be set
 * @param[in]     old_volt    current voltage
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t board_set_voltage(sc_sub_t ss, uint32_t new_volt, uint32_t old_volt);

/*!
 * This function is used to set power supplies of the board when
 * entering and exiting low power mode.
 *
 * @param[in]     mode        power mode to apply
 *
 * Note this function is not called by sc_pm_set_sys_power_mode().
 * It is called when the system dynamically transitions power modes
 * during run-time execution.  It is normally used to manage the
 * supply for the memories (MEMC).
 */
void board_lpm(sc_pm_power_mode_t mode);

/*!
 * This function transitions the power state for an external board-
 * level supply which goes to a board component.
 *
 * @param[in]     idx         board-relative resource index
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     from_mode   power mode transitioning from
 * @param[in]     to_mode     power mode transitioning to
 *
 * This function is used to transition a board power supply that is
 * used by a board component. It allows mapping of board resources
 * (e.g. SC_R_BOARD_R0) to board supplies.
 *
 * \a idx should be used to identify the resource. It is 0-n and is
 * associated with the board resources PMIC_0 through BOARD_R7.
 *
 * \a rsrc_idx is only useful for debug output of a resource name.
 */
void board_trans_resource_power(sc_rm_idx_t idx, sc_rm_idx_t rsrc_idx,
    sc_pm_power_mode_t from_mode,sc_pm_power_mode_t to_mode);

/*!
 * This function resets a board resource.
 *
 * @param[in]     idx         board-relative resource index
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     pt          partition
 *
 * This function is used to reset resource. If pt equals SC_PT_ALL
 * then reset all resources belonging to that partition. Otherwise,
 * reset rsrc_idx only.
 *
 * It is only called when a partition is rebooted or when the
 * sc_pm_resource_reset() function is called. Is is usually empty
 * unless a resource can't be powered off but can be soft reset.
 *
 * \a idx should be used to identify the resource. It is 0-n and is
 * associated with the board resources PMIC_0 through BOARD_R7.
 *
 * \a rsrc_idx is only useful for debug output of a resource name.
 */
void board_rsrc_reset(sc_rm_idx_t idx, sc_rm_idx_t rsrc_idx, sc_rm_pt_t pt);

/** @} */

/*!
 * @name Misc Functions
 * @{
 */

/*!
 * This function is used to set the board power.
 *
 * @param[in]     mode        power mode to apply
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid mode
 *
 * This function is only called by sc_pm_set_sys_power_mode().
 * It is normally used ask the PMIC to power off the board
 * completely.
 */
sc_err_t board_power(sc_pm_power_mode_t mode);

/*!
 * This function is used to reset the system.
 *
 * @param[in]     type        reset type
 * @param[in]     reason      cause of reset
 * @param[in]     pt          partition causing reset
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if invalid type
 *
 * If this function returns, then the reset did not occur due to an
 * invalid parameter.
 */
sc_err_t board_reset(sc_pm_reset_type_t type, sc_pm_reset_reason_t reason,
    sc_rm_pt_t pt);

/*!
 * This function is called when a CPU encounters a reset
 * event.
 *
 * @param[in]     resource    CPU resource
 * @param[in]     reset_event CPU reset event
 * @param[in]     pt          partition of CPU
 */
void board_cpu_reset(sc_rsrc_t resource, board_cpu_rst_ev_t reset_event,
    sc_rm_pt_t pt);

/*!
 * This function is called when a partition reboot is requested. It allows
 * the port to override the parameters or take other action such as logging
 * or reboot the board.
 *
 * @param[in]     pt          partition being rebooted
 * @param[in,out] type        pointer to modify reset type
 * @param[in,out] reason      pointer to modify reset reason
 * @param[in,out] mode        pointer to modify power cycle mode
 * @param[out]    mask        pointer to return mask of wait partitions
 *
 * Code can modify or log the parameters. Can also take another action like
 * reset the board. After return from this function, the partition will be
 * rebooted.
 *
 * Type is cold, warm, board. Reason is SW, WDOG, etc. Reboot is accomplished
 * by reducing power and reapplying. Mode indicates the power level to reduce
 * to (usually off).
 *
 * If \a mask is non-0 mask, then the reboot will be delayed until all
 * partitions indicated in the mask (pt 1 = bit 1, etc.) have called
 * sc_pm_reboot_continue() to continue the boot.
 */
void board_reboot_part(sc_rm_pt_t pt, sc_pm_reset_type_t *type,
    sc_pm_reset_reason_t *reason, sc_pm_power_mode_t *mode,
    uint32_t *mask);

/*!
 * This function is called when a partition reboot is has powered off the
 * partition but has not yet powered it back on. It allows the boot parameters
 * to be changed. Could also bracket a change done in board_reboot_part().
 *
 * @param[in]     pt          partition being rebooted
 * @param[in,out] boot_cpu    pointer to modify the boot CPU
 * @param[in,out] boot_mu     pointer to modify the boot MU
 * @param[in,out] boot_dev    pointer to modify the boot device
 * @param[in,out] boot_addr   pointer to modify the boot address
 *
 */
void board_reboot_part_cont(sc_rm_pt_t pt, sc_rsrc_t *boot_cpu,
    sc_rsrc_t *boot_mu, sc_rsrc_t *boot_dev, sc_faddr_t *boot_addr);

/*!
 * This function is called when a partition reboot times out.
 *
 * @param[in]     pt          partition being rebooted
 *
 * @return Returns the desired action.
 */
board_reboot_to_t board_reboot_timeout(sc_rm_pt_t pt);

/*!
 * This function is called when a SS (other than SCU)  reports a
 * panic temp alarm.
 *
 * @param[in]     dsc         dsc reporting alarm
 *
 * Note this function would normally request a board reset.
 *
 * See the Porting Guide for more information.
 */
void board_panic(sc_dsc_t dsc);

/*!
 * This function is called when a fault is detected or the SCFW
 * returns from main().
 *
 * @param[in]     restarted   SC_TRUE if called on restart
 * @param[in]     reason      reason for the fault
 * @param[in]     pt          partition causing fault
 *
 * Note this function would normally request a board reset. For
 * debug builds it is common to disable the watchdog and loop.
 *
 * The \a restarted parameter is SC_TRUE if this error is pending from
 * the last restart.
 */
void board_fault(sc_bool_t restarted, sc_bfault_t reason,
    sc_rm_pt_t pt);

/*!
 * This function is called when an abort or serious error is
 * reported by SECO or V2X.
 *
 * @param[in]     abort_module  module of abort
 * @param[in]     abort_line    line number of abort
 * @param[in]     reason        reason for fault
 *
 * Note this function would normally request a board reset. For
 * debug builds it is common to display a message.
 *
 * See the SECO API Reference Guide for more info.
 */
void board_sec_fault(uint8_t abort_module, uint8_t abort_line,
    sc_sfault_t reason);

/*!
 * This function is called when a security violation is reported by
 * the SECO or SNVS.
 *
 * Note this function would normally request a board reset. For
 * debug builds it is common to do nothing.
 */
void board_security_violation(void);

/*!
 * This function is used to return the current status of the ON/OFF
 * button.
 *
 * @return Returns the status
 */
sc_bool_t board_get_button_status(void);

/*!
 * This function sets a miscellaneous control value.
 *
 * @param[in]     resource    resource
 * @param[in]     idx         board resource index
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     ctrl        control to write
 * @param[in]     val         value to write
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Note this function can be used to set voltages for both SoC
 * resources and board resources (e.g. SC_R_BOARD_R0).
 */
sc_err_t board_set_control(sc_rsrc_t resource, sc_rm_idx_t idx,
    sc_rm_idx_t rsrc_idx, uint32_t ctrl, uint32_t val);

/*!
 * This function gets a miscellaneous control value.
 *
 * @param[in]     resource    resource
 * @param[in]     idx         board resource index
 * @param[in]     rsrc_idx    unified resource index
 * @param[in]     ctrl        control to read
 * @param[out]    val         pointer to return value
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t board_get_control(sc_rsrc_t resource, sc_rm_idx_t idx,
    sc_rm_idx_t rsrc_idx, uint32_t ctrl, uint32_t *val);

/*!
 * This function is called periodically to tick the board.
 *
 * @param[in]     msec          number of mS to increment
 *
 * Can be used to implement customer watchdogs, monitor some
 * hardware, etc.
 */
void board_tick(uint16_t msec);

/*!
 * This function is called when sc_misc_board_ioctl() is called.
 *
 * @param[in]     caller_pt     handle of caller partition
 * @param[in]     mu            receiving MU via RPC/IPC
 * @param[in,out] parm1         pointer to pass parameter 1
 * @param[in,out] parm2         pointer to pass parameter 2
 * @param[in,out] parm3         pointer to pass parameter 3
 *
 * Can be used to implement customer watchdogs, monitor some
 * hardware, etc.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t board_ioctl(sc_rm_pt_t caller_pt, sc_rsrc_t mu, uint32_t *parm1,
    uint32_t *parm2, uint32_t *parm3);

#ifdef BOARD_LOG_SIZE
/*!
 * This function is called to configure or trigger logging.
 *
 * @param[in]     mode          mode flags
 */
void board_log_mode(uint32_t mode);
#endif

/*!
 * This function is called to log data.
 *
 * @param[in]     data0         first data to log
 * @param[in]     data1         second data to log
 */
void board_log_write(uint32_t data0, uint32_t data1);

/*!
 * This function is called by the monitor to dump the log.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t board_log_dump(void);

/*!
 * Interrupt handler for the PMIC.
 */
void PMIC_IRQHandler(void);

/*!
 * Interrupt handler for the SNVS button.
 */
void SNVS_Button_IRQHandler(void);

/** @} */

/* Externs */

/*!
 * External variable for accessing the number of board resources.
 */
extern const sc_rm_idx_t board_num_rsrc;

/*!
 * External variable for accessing the board resource map.
 */
extern const sc_rsrc_map_t board_rsrc_map[BRD_NUM_RSRC_BRD];

/*!
 * External variable for specing DDR periodic training.
 */
extern const uint32_t board_ddr_period_ms;

/*!
 * External variable for DDR periodic derate.
 */
extern const uint32_t board_ddr_derate_period_ms;

#endif /* SC_BOARD_API_H */

/** \example board.c
 * This is an example implementation for the i.MX8QM MEK board.
 */

/** @} */

