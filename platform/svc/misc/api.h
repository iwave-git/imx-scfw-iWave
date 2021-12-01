/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2017-2020 NXP
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
 * @file svc/misc/api.h
 *
 * Header file containing the public API for the System Controller (SC)
 * Miscellaneous (MISC) function.
 *
 * @addtogroup MISC_SVC MISC: Miscellaneous Service
 *
 * @brief Module for the Miscellaneous (MISC) service.
 *
 * @{
 */
/*==========================================================================*/

#ifndef SC_MISC_API_H
#define SC_MISC_API_H

/* Includes */

#include "main/types.h"
#include "svc/rm/api.h"

/* Defines */

/*!
 * @name Defines for type widths
 */
/** @{ */
#define SC_MISC_DMA_GRP_W       5U      /*!< Width of sc_misc_dma_group_t */
/** @} */

/*! Max DMA channel priority group */
#define SC_MISC_DMA_GRP_MAX     31U

/*!
 * @name Defines for sc_misc_boot_status_t
 */
/** @{ */
#define SC_MISC_BOOT_STATUS_SUCCESS     0U   /*!< Success */
#define SC_MISC_BOOT_STATUS_SECURITY    1U   /*!< Security violation */
/** @} */

/*!
 * @name Defines for sc_misc_temp_t
 */
/** @{ */
#define SC_MISC_TEMP                    0U   /*!< Temp sensor */
#define SC_MISC_TEMP_HIGH               1U   /*!< Temp high alarm */
#define SC_MISC_TEMP_LOW                2U   /*!< Temp low alarm */
/** @} */

/*!
 * @name Defines for sc_misc_bt_t
 */
/** @{ */
#define SC_MISC_BT_PRIMARY              0U   /*!< Primary boot */
#define SC_MISC_BT_SECONDARY            1U   /*!< Secondary boot */
#define SC_MISC_BT_RECOVERY             2U   /*!< Recovery boot */
#define SC_MISC_BT_MANUFACTURE          3U   /*!< Manufacture boot */
#define SC_MISC_BT_SERIAL               4U   /*!< Serial boot */
/** @} */

/* Types */

/*!
 * This type is used to store a DMA channel priority group.
 */
typedef uint8_t sc_misc_dma_group_t;

/*!
 * This type is used report boot status.
 */
typedef uint8_t sc_misc_boot_status_t;

/*!
 * This type is used report boot status.
 */
typedef uint8_t sc_misc_temp_t;

/*!
 * This type is used report the boot type.
 */
typedef uint8_t sc_misc_bt_t;

/* Functions */

/*!
 * @name Control Functions
 * @{
 */

/*!
 * This function sets a miscellaneous control value.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource the control is associated with
 * @param[in]     ctrl        control to change
 * @param[in]     val         value to apply to the control
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the resource owner or parent
 *   of the owner
 *
 * Refer to the [Control List](@ref CONTROLS) for valid control values.
 */
/* IDL: E8 SET_CONTROL(UI16 resource, UI32 ctrl, UI32 val) #1 */
sc_err_t sc_misc_set_control(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_ctrl_t ctrl, uint32_t val);

/*!
 * This function gets a miscellaneous control value.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource the control is associated with
 * @param[in]     ctrl        control to get
 * @param[out]    val         pointer to return the control value
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the resource owner or parent
 *   of the owner
 *
 * Refer to the [Control List](@ref CONTROLS) for valid control values.
 */
/* IDL: E8 GET_CONTROL(UI16 resource, UI32 ctrl, UO32 val) #2 */
sc_err_t sc_misc_get_control(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_ctrl_t ctrl, uint32_t *val);

/** @} */

/*!
 * @name DMA Functions
 * @{
 */

/*!
 * This function configures the max DMA channel priority group for a
 * partition.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition to assign \a max
 * @param[in]     max         max priority group (0-31)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the parent
 *   of the affected partition
 *
 * Valid \a max range is 0-31 with 0 being the lowest and 31 the highest.
 * Default is the max priority group for the parent partition of \a pt.
 */
/* IDL: E8 SET_MAX_DMA_GROUP(UI8 pt, UI8 max) #4 */
sc_err_t sc_misc_set_max_dma_group(sc_ipc_t ipc, sc_rm_pt_t pt,
    sc_misc_dma_group_t max);

/*!
 * This function configures the priority group for a DMA channel.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    DMA channel resource
 * @param[in]     group       priority group (0-31)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the owner or parent
 *   of the owner of the DMA channel
 *
 * Valid \a group range is 0-31 with 0 being the lowest and 31 the highest.
 * The max value of \a group is limited by the partition max set using
 * sc_misc_set_max_dma_group().
 */
/* IDL: E8 SET_DMA_GROUP(UI16 resource, UI8 group) #5 */
sc_err_t sc_misc_set_dma_group(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_misc_dma_group_t group);

/** @} */

/*!
 * @name Debug Functions
 * @{
 */

/*!
 * This function is used output a debug character from the SCU UART.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     ch          character to output
 */
/* IDL: R0 DEBUG_OUT(UI8 ch) #10 */
void sc_misc_debug_out(sc_ipc_t ipc, uint8_t ch);

/*!
 * This function starts/stops emulation waveform capture.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     enable      flag to enable/disable capture
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_UNAVAILABLE if not running on emulation
 */
/* IDL: E8 WAVEFORM_CAPTURE(IB enable) #6 */
sc_err_t sc_misc_waveform_capture(sc_ipc_t ipc, sc_bool_t enable);

/*!
 * This function is used to return the SCFW build info.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    build       pointer to return build number
 * @param[out]    commit      pointer to return commit ID (git SHA-1)
 */
/* IDL: R0 BUILD_INFO(UO32 build, UO32 commit) #15 */
void sc_misc_build_info(sc_ipc_t ipc, uint32_t *build,
    uint32_t *commit);

/*!
 * This function is used to return the SCFW API versions.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    cl_maj      pointer to return major part of client version
 * @param[out]    cl_min      pointer to return minor part of client version
 * @param[out]    sv_maj      pointer to return major part of SCFW version
 * @param[out]    sv_min      pointer to return minor part of SCFW version
 *
 * Client version is the version of the API ported to and used by the caller.
 * SCFW version is the version of the SCFW binary running on the CPU.
 *
 * Note a major version difference indicates a break in compatibility.
 */
/* IDL: R0 API_VER(UO16 cl_maj, UO16 cl_min, UO16 sv_maj, UO16 sv_min) #35 */
void sc_misc_api_ver(sc_ipc_t ipc, uint16_t *cl_maj,
    uint16_t *cl_min, uint16_t *sv_maj, uint16_t *sv_min);

/*!
 * This function is used to return the device's unique ID.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    id_l        pointer to return lower 32-bit of ID [31:0]
 * @param[out]    id_h        pointer to return upper 32-bits of ID [63:32]
 */
/* IDL: R0 UNIQUE_ID(UO32 id_l, UO32 id_h) #19 */
void sc_misc_unique_id(sc_ipc_t ipc, uint32_t *id_l,
    uint32_t *id_h);

/** @} */

/*!
 * @name Other Functions
 * @{
 */

/*!
 * This function configures the ARI match value for PCIe/SATA resources.
 *
 * @param[in]     ipc           IPC handle
 * @param[in]     resource      match resource
 * @param[in]     resource_mst  PCIe/SATA master to match
 * @param[in]     ari           ARI to match
 * @param[in]     enable        enable match or not
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the owner or parent
 *   of the owner of the resource and translation
 *
 * For PCIe, the ARI is the 16-bit value that includes the bus number,
 * device number, and function number. For SATA, this value includes the
 * FISType and PM_Port.
 */
/* IDL: E8 SET_ARI(UI16 resource, UI16 resource_mst, UI16 ari, IB enable) #3 */
sc_err_t sc_misc_set_ari(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_rsrc_t resource_mst, uint16_t ari, sc_bool_t enable);

/*!
 * This function reports boot status.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     status      boot status
 *
 * This is used by SW partitions to report status of boot. This is
 * normally used to report a boot failure.
 */
/* IDL: RN BOOT_STATUS(UI8 status) #7 */
void sc_misc_boot_status(sc_ipc_t ipc, sc_misc_boot_status_t status);

/*!
 * This function tells the SCFW that a CPU is done booting.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     cpu         CPU that is done booting
 *
 * This is called by early booting CPUs to report they are done with
 * initialization. After starting early CPUs, the SCFW halts the
 * booting process until they are done. During this time, early
 * CPUs can call the SCFW with lower latency as the SCFW is idle.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the CPU owner
 */
/* IDL: E8 BOOT_DONE(UI16 cpu) #14 */
sc_err_t sc_misc_boot_done(sc_ipc_t ipc, sc_rsrc_t cpu);

/*!
 * This function reads a given fuse word index.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     word        fuse word index
 * @param[out]    val         fuse read value
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 *
 * Return errors codes:
 * - SC_ERR_PARM if word fuse index param out of range or invalid
 * - SC_ERR_NOACCESS if read operation failed
 * - SC_ERR_LOCKED if read operation is locked
 */
/* IDL: E8 OTP_FUSE_READ(UI32 word, UO32 val) #11 */
sc_err_t sc_misc_otp_fuse_read(sc_ipc_t ipc, uint32_t word, uint32_t *val);

/*!
 * This function writes a given fuse word index. Only the owner of the
 * SC_R_SYSTEM resource or a partition with access permissions to
 * SC_R_SYSTEM can do this.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     word        fuse word index
 * @param[in]     val         fuse write value
 *
 * The command is passed as is to SECO. SECO uses part of the
 * \a word parameter to indicate if the fuse should be locked
 * after programming. See the "Write common fuse" section of
 * the SECO API Reference Guide for more info.
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 *
 * Return errors codes:
 * - SC_ERR_PARM if word fuse index param out of range or invalid
 * - SC_ERR_NOACCESS if caller does not have SC_R_SYSTEM access
 * - SC_ERR_NOACCESS if write operation failed
 * - SC_ERR_LOCKED if write operation is locked
 */
/* IDL: E8 OTP_FUSE_WRITE(UI32 word, UI32 val) #17 */
sc_err_t sc_misc_otp_fuse_write(sc_ipc_t ipc, uint32_t word, uint32_t val);

/*!
 * This function sets a temp sensor alarm.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource with sensor
 * @param[in]     temp        alarm to set
 * @param[in]     celsius     whole part of temp to set
 * @param[in]     tenths      fractional part of temp to set
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 *
 * This function will enable the alarm interrupt if the temp requested is
 * not the min/max temp. This enable automatically clears when the alarm
 * occurs and this function has to be called again to re-enable.
 *
 * Return errors codes:
 * - SC_ERR_PARM if parameters invalid
 * - SC_ERR_NOACCESS if caller does not own the resource
 * - SC_ERR_NOPOWER if power domain of resource not powered
 */
/* IDL: E8 SET_TEMP(UI16 resource, UI8 temp, I16 celsius, I8 tenths) #12 */
sc_err_t sc_misc_set_temp(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_misc_temp_t temp, int16_t celsius, int8_t tenths);

/*!
 * This function gets a temp sensor value.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource with sensor
 * @param[in]     temp        value to get (sensor or alarm)
 * @param[out]    celsius     whole part of temp to get
 * @param[out]    tenths      fractional part of temp to get
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 *
 * Return errors codes:
 * - SC_ERR_PARM if parameters invalid
 * - SC_ERR_BUSY if temp not ready yet (time delay after power on)
 * - SC_ERR_NOPOWER if power domain of resource not powered
 */
/* IDL: E8 GET_TEMP(UI16 resource, UI8 temp, O16 celsius, O8 tenths) #13 */
sc_err_t sc_misc_get_temp(sc_ipc_t ipc, sc_rsrc_t resource,
    sc_misc_temp_t temp, int16_t *celsius, int8_t *tenths);

/*!
 * This function returns the boot device.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    dev         pointer to return boot device
 */
/* IDL: R0 GET_BOOT_DEV(UO16 dev) #16 */
void sc_misc_get_boot_dev(sc_ipc_t ipc, sc_rsrc_t *dev);

/*!
 * This function returns the boot type.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    type        pointer to return boot type
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 *
 * Return errors code:
 * - SC_ERR_UNAVAILABLE if type not passed by ROM
 */
/* IDL: E8 GET_BOOT_TYPE(UO8 type) #33 */
sc_err_t sc_misc_get_boot_type(sc_ipc_t ipc, sc_misc_bt_t *type);

/*!
 * This function returns the boot container index.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    idx         pointer to return index
 *
 * Return \a idx = 1 for first container, 2 for second.
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 *
 * Return errors code:
 * - SC_ERR_UNAVAILABLE if index not passed by ROM
 */
/* IDL: E8 GET_BOOT_CONTAINER(UO8 idx) #36 */
sc_err_t sc_misc_get_boot_container(sc_ipc_t ipc, uint8_t *idx);

/*!
 * This function returns the current status of the ON/OFF button.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    status      pointer to return button status
 */
/* IDL: R0 GET_BUTTON_STATUS(OB status) #18 */
void sc_misc_get_button_status(sc_ipc_t ipc, sc_bool_t *status);

/*!
 * This function returns the ROM patch checksum.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    checksum    pointer to return checksum
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 */
/* IDL: E8 ROMPATCH_CHECKSUM(UO32 checksum) #26 */
sc_err_t sc_misc_rompatch_checksum(sc_ipc_t ipc, uint32_t *checksum);

/*!
 * This function calls the board IOCTL function.
 *
 * @param[in]      ipc         IPC handle
 * @param[in,out]  parm1       pointer to pass parameter 1
 * @param[in,out]  parm2       pointer to pass parameter 2
 * @param[in,out]  parm3       pointer to pass parameter 3
 *
 * @return Returns and error code (SC_ERR_NONE = success).
 */
/* IDL: E8 BOARD_IOCTL(UIO32 parm1, UIO32 parm2, UIO32 parm3) #34 */
sc_err_t sc_misc_board_ioctl(sc_ipc_t ipc, uint32_t *parm1,
    uint32_t *parm2, uint32_t *parm3);

/** @} */

#endif /* SC_MISC_API_H */

/** @} */

