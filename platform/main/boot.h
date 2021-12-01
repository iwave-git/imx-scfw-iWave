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
 * @file
 *
 * Header file for interaction with the ROM.
 */
/*==========================================================================*/

#ifndef SC_BOOT_H
#define SC_BOOT_H

/* Includes */

#include "main/types.h"

/* Defines */

#define SC_BOOT_DATA_BARKER         0xC0FFEE16U
#define SC_BOOT_DATA_VER            0x01U

#define SC_IMG_TYPE_EXEC            0x03U   /* Executable image type */
#define SC_IMG_TYPE_DATA            0x04U   /* Data image type */
#define SC_IMG_TYPE_DDR_INIT        0x05U   /* DDR init image type */
#define SC_IMG_TYPE_SECO            0x06U   /* SECO image type */
#define SC_IMG_TYPE_PROVSN          0x07U   /* Provisioning image type */
#define SC_IMG_TYPE_DEK             0x08U   /* DEK image type */
#define SC_IMG_TYPE_V2X_PRI_FW      0x0BU   /* Primary V2X FW */
#define SC_IMG_TYPE_V2X_SND_FW      0x0CU   /* Secondary V2X FW */
#define SC_IMG_TYPE_V2X_PATCH       0x0DU   /* V2X patch */
#define SC_IMG_TYPE_V2X_DUMMY       0x0EU   /* A dummy image entity in SCU CTNR, provides loading space */
#define SC_IMG_TYPE_DEBUG           0x10U   /* Signed debug enable message */
#define SC_IMG_TYPE_SECFUSE         0x11U   /* Signed secure fuse message */
#define SC_IMG_TYPE_RETURN          0x12U   /* Signed field return message */
#define SC_IMG_TYPE_PATCH           0x13U   /* Signed patch message */
#define SC_IMG_TYPE_FIPSZERO        0x14U   /* FIPS zero message */
#define SC_IMG_TYPE_ALL             0xFFU   /* All images */

#define SC_BD_FLAGS_NOT_SECURE      16U
#define SC_BD_FLAGS_NOT_ISOLATED    17U
#define SC_BD_FLAGS_RESTRICTED      18U
#define SC_BD_FLAGS_GRANT           19U
#define SC_BD_FLAGS_NOT_COHERENT    20U
#define SC_BD_FLAGS_ALT_CONFIG      21U
#define SC_BD_FLAGS_EARLY_CPU_START 22U
#define SC_BD_FLAGS_DDRTEST         23U
#define SC_BD_FLAGS_NO_AP           24U
#define SC_BD_FLAGS_ALT_CONFIG2     25U

/* Types */

/*!
 * This type is used to indicate boot type.
 */
typedef enum
{
    SC_BT_TYPE_PRIMARY      = 1,
    SC_BT_TYPE_SECONDARY    = 2,
    SC_BT_TYPE_RECOVERY     = 3,
    SC_BT_TYPE_SERIAL       = 0xFF
} sc_bt_type_t;

/*!
 * This type is used to indicate boot device.
 */
typedef enum
{
    SC_BT_DEV_TYPE_SD           = 1,
    SC_BT_DEV_TYPE_MMC          = 2,
    SC_BT_DEV_TYPE_NAND         = 3,
    SC_BT_DEV_TYPE_FLEXSPINOR   = 4,
    SC_BT_DEV_TYPE_SATA_DISK    = 7,
    SC_BT_DEV_TYPE_USB          = 14
} sc_bt_dev_type_t;

/*!
 * This type is used to store a CPU start request.
 */
typedef struct
{
    sc_faddr_t addr;                        //!< 64-bit address to boot from
    uint16_t cpu;                           //!< CPU to start
    uint16_t mu;                            //!< MU associated with this CPU
    uint8_t part;                           //!< Partition to start
    uint8_t resv[3];                        //!< Reserved
} sc_boot_list_t;

/*!
 * This type is used pass data from the ROM to the SCFW.
 */
typedef struct
{
    uint32_t barker;                        //!< Barker code
    uint16_t ver;                           //!< Version
    uint16_t size;                          //!< Size
    uint8_t num;                            //!< Number images in list
    uint8_t resv0[3];                       //!< Reserved
    uint32_t bd_flags;                      //!< Boot data flags
    sc_boot_list_t img[SC_BOOT_MAX_LIST];   //!< image list
    uint32_t resv1[4];                      //!< was SCD address
} sc_boot_data_t;

/*!
 * This type is used store handoff header info.
 */
typedef struct
{
    uint16_t barker;                        //!< Barker code
    uint16_t len;                           //!< Size
} sc_handoff_header_t;

/*!
 * This type is used pass boot device info from the ROM to the SCFW.
 */
typedef struct
{
    sc_bt_type_t bt_type;                   //!< Boot type
    uint8_t instance;                       //!< Instance number
    sc_bt_dev_type_t dev_type;              //!< Device type
    uint8_t resv2;
} sc_bt_dev_info_t;

/*!
 * This type is used pass extended data from the ROM to the SCFW.
 */
typedef struct
{
    sc_handoff_header_t header;             //!< Barker/size info
    uint32_t bringup_flags;                 //!< SS bring up flags
    union
    {
        sc_bt_dev_info_t bt_dev_info;       //!< Boot device
        uint32_t u;                         //!< Force 32 bits
    };
    uint32_t core_freq;
    uint32_t axi_freq;
    uint32_t ddr_freq;
    uint32_t rom_tick_freq;
    uint8_t ver;
    uint8_t rsv1[3];
    uint32_t bringup_flags2;                //!< SS bring up expansion
    uint32_t rsv2;
} sc_boot_data2_t;

/*!
 * This type is used pass passover data from the ROM to the AP.
 */
typedef struct
{
    uint16_t tag;                           //!< Tag
    uint8_t  len;                           //!< Fixed value of 0x20
    uint8_t  ver;                           //!< Version
    uint32_t boot_mode;                     //!< Boot mode
    uint32_t card_addr_mode;                //!< SD card address mode
    uint32_t bad_blks_of_img_set0;          //!< NAND bad block count skipped 1
    uint32_t ap_mu_id;                      //!< AP MU ID
    uint32_t bad_blks_of_img_set1;          //!< NAND bad block count skipped 1
    uint8_t  boot_stage;                    //!< Boot stage
    uint8_t  img_set_sel;                   //!< Image set booted from
    uint8_t  rsv[2];                        //!< Reserved
    uint32_t img_set_end;                   //!< Offset of Image End
} sc_passover_t;

#ifdef SC_ROM_FUNC_ADDR
    /*!
     * This type is used make calls to the ROM.
     */
    typedef struct
    {
        uint16_t ver;
        uint16_t tag;
        uint32_t (*dsc_ai_read)(uint8_t dsc_id, uint8_t src_sel,
            uint16_t address);
        int32_t (*dsc_ai_write)(uint8_t dsc_id, uint8_t src_sel,
            uint16_t address, uint32_t data);
    } sc_rom_functions_t;
#endif

/* Functions */

sc_err_t boot_init(sc_bool_t allow);

/*!
 * This function returns flags passed to the SCFW from the ROM. These
 * come from the boot container (bd_flags).
 *
 * @param[out]    flag         pointer to return raw flag value
 * @param[out]    not_secure   pointer to return secure flag
 * @param[out]    not_isolated pointer to return isolated flag
 * @param[out]    restricted   pointer to return restricted flag
 * @param[out]    grant        pointer to return grant flag
 * @param[out]    not_coherent pointer to return coherent flag
 * @param[out]    alt_config   pointer to return alt_config flag
 * @param[out]    early        pointer to return early flag
 * @param[out]    ddrtest      pointer to return ddrtest flag
 * @param[out]    no_ap        pointer to return no_ap flag
 * @param[out]    alt_config2  pointer to return alt_config 2 flag
 *
 * For all pointers, NULL will result in no return of that value.
 *
 * See the [Boot Flags](@ref BOOT_FLAGS) section for definition
 * of these flags.
 *
 * Many of the flags (some inverted) are used to create the
 * boot partition by calling sc_rm_partition_alloc().
 */
void boot_get_data(uint32_t *flag, sc_bool_t *not_secure,
    sc_bool_t *not_isolated, sc_bool_t *restricted, sc_bool_t *grant,
    sc_bool_t *not_coherent, sc_bool_t *alt_config, sc_bool_t *early,
    sc_bool_t *ddrtest, sc_bool_t *no_ap, sc_bool_t *alt_config2);

sc_err_t boot_get_img_1(uint8_t type, sc_rsrc_t *cpu, sc_faddr_t *addr,
    sc_rsrc_t *mu, sc_rm_pt_t *pt, sc_bool_t force_ap);
sc_err_t boot_get_img_n(uint8_t type, sc_rsrc_t *cpu, sc_faddr_t *addr,
    sc_rsrc_t *mu, sc_rm_pt_t *pt, sc_bool_t force_ap);
sc_err_t boot_get_bring_up(sc_sub_t ss, sc_bool_t *flag);
sc_err_t boot_get_boot_dev(sc_bt_dev_type_t *dev_type, uint8_t *inst,
    sc_bt_type_t *bt_type);
sc_err_t boot_get_container_idx(uint8_t *idx);
uint8_t boot_get_img_num(void);
sc_err_t boot_get_img_start_addr(uint16_t img, sc_faddr_t *addr);

/*!
 * This function checks to see if a partition will be booting.
 *
 * @param[in]     pt          partition
 *
 * @return Returns SC_TRUE if the partition will boot.
 */
sc_bool_t boot_is_booting(sc_rm_pt_t pt);

/*!
 * This function returns the boot device resource associate with
 * the specified partition.
 *
 * @param[in]     pt          partition
 * @param[in]     check_pt    Boolean to verify if boot device needs
 *                              to be associated with the partition.
 *
 * @return Returns the boot device.
 */
sc_rsrc_t boot_get_dev(sc_rm_pt_t pt, sc_bool_t check_pt);

void boot_check_rom_data(void);

#ifdef FLEXSPI_V2X_ADDR
/*!
 * Return info from parsed FlexSPI container headers.
 *
 * @param[out]    v2x_fw_addr  pointer to return the V2X FW address
 * @param[out]    v2x_fw_size  pointer to return the V2X FW size
 * @param[out]    dummy_addr   pointer to return the dummy address
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t boot_get_flexspi_v2x_info(sc_saddr_t *v2x_fw_addr,
    uint32_t *v2x_fw_size, sc_saddr_t *dummy_addr);
#endif

#endif /* SC_BOOT_H */

