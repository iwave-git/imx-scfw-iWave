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
 * Header file for the system controller main. Contains defines, macros,
 * and types shared by main and test implementations.
 */
/*==========================================================================*/

#ifndef SC_MAIN_H
#define SC_MAIN_H

/* Includes */

#include "main/scfw.h"
#include "main/types.h"
#include "main/ipc.h"
#include "main/rpc.h"
#include "board/board_common.h"
#include "config/config.h"
#include "main/debug.h"
#include "ss/inf/inf.h"

/* Defines */

#define SC_NA               0U
#define SC_SW               0U

#define SC_NUM_SS_GRP       (SC_SS_GRP_LAST + 1U)
#define SC_NUM_RESOURCE     (SC_R_LAST)
#define SC_NUM_SUBSYS       ((sc_sub_t) (((uint8_t) SC_SUBSYS_LAST) + 1U))
#define SC_NUM_DSC          ((sc_dsc_t) (((uint8_t) SC_DSC_LAST) + 1U))

#define SC_MSIZE_W          5U
#define SC_MSLOT_W          2U
#define SC_MSLOT_SHF        30U
#define SC_SSLOT_W          6U
#define SC_SSLOT_SHF        28U
#define SC_SSPROT_W         2U

#define NOP                 {}

#ifndef SIMU
    #define ENTER_CS        SystemEnterCS()
    #define EXIT_CS         SystemExitCS()
#else
    #define ENTER_CS        NOP
    #define EXIT_CS         NOP
#endif

#define DONT_TOUCH_RSRC       0U
#define LEAVE_RSRC_ON         1U
#define TURN_RSRC_OFF         2U
#define SET_RSRC_STBY         3U

#define PLL_VER13       (13U)
#define PLL_VER18       (18U)


/*! Macro to get minimum */
#if !defined(MIN)
    #define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#if !defined(MAX)
    /*! Macro to get maximum */
    #define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

/*! Macro to get absolute value */
#define ABS(X)              ((X) < 0 ? -(X) : (X))

/*! Macro to create bit field */
#define BIT(X)              (U32(1U) << (U32(X) % U32(32U)))

/*! Macro to return bit position */
#define BIT_POS(X)          (U32(X) % U32(32U))

/*! Macro to create bit field */
#define BIT8(X)             (U8(1U) << (U8(X) % U8(8U)))

/*! Macro to create bit field */
#define BIT16(X)            (U16(1U) << (U16(X) % U16(16U)))

/*! Macro to create bit field */
#define BIT32(X)            (U32(1U) << (U32(X) % U32(32U)))

/*! Macro to create bit field */
#define BIT64(X)            (U64(1U) << (U64(X) % U64(64U)))

/*! Macro to extract from field */
#define MASK(X)             ((U32(1U) << U32(X)) - U32(1U))

/*! Macro to extract from bit field */
#define EX_BIT(X, Y)        ((U32(X) >> (U32(Y) % 32U)) & U32(1U))

/*! Macro to extract from bool field */
#define EX_BOOL(X, Y)        (U2B32(EX_BIT((X), (Y))))

/*! Macro to extract from field */
#define EX_FIELD(X, Y, Z)   (((X) >> (U32(Y) % 32U)) & MASK(Z))

/*! Macro to create clear field */
#define CLR_FIELD(X, Y)     (MASK(Y) << (U32(X) % U32(32U)))

/*! Macro to create field */
#define INS_FIELD(X, Y, Z)  ((U32(Z) & MASK(Y)) << (U32(X) % 32U))

/*! Macro to create register index */
#define REG(X)              (U32(X) / U32(32U))

/*! Macro to create 8-bit index from register and bit */
#define REGBIT8(X, Y)       ((U8(X) * U8(32U)) + (U8(Y) % 32U))

/*! Macro to create 32-bit index from register and bit */
#define REGBIT(X, Y)        ((U32(X) * U32(32U)) + (U32(Y) % 32U))

/*! Macro to create 64-bit index from register and bit */
#define REGBIT64(X, Y)      ((U64(X) * U64(32U)) + (U64(Y) % 32U))

/*! Macro to get upper 32 bits of a 64-bit value */
#define UINT64_H(X)         (U32((U64(X) >> 32U) & U64(0x0FFFFFFFFU)))

/*! Macro to get lower 32 bits of a 64-bit value */
#define UINT64_L(X)         (U32(U64(X) & U64(0x0FFFFFFFFU)))

/*! Macro to get upper 16 bits of a 32-bit value */
#define UINT32_H(X)         (U16((U32(X) >> 16U) & U32(0xFFFFU)))

/*! Macro to get lower 16 bits of a 32-bit value */
#define UINT32_L(X)         (U16(U32(X) & U32(0xFFFFU)))

/*! Macro to declare a bit array */
#define BITARRAY_DEC(X, Y)  uint32_t (X)[(((Y) - 1U) / 32U) + 1U]

/*! Macro to set a bit in a bit array */
#define BITARRAY_SET(X, Y)  (X)[REG(Y)] |= BIT(Y)

/*! Macro to clear a bit in a bit array */
#define BITARRAY_CLR(X, Y)  (X)[REG(Y)] &= ~BIT(Y)

/*! Macro to get a bit in a bit array */
#define BITARRAY_GET(X, Y)  ((X)[REG(Y)] & BIT(Y))

#define ASRT(X)                         \
    if (!(X))                           \
    {                                   \
        return;                         \
    }

#define ASRT_ERR(X,ERROR)               \
    if (err == SC_ERR_NONE)             \
    {                                   \
        if (!(X))                       \
        {                               \
            err = (ERROR);              \
        }                               \
    }

#define ASRT_C(X)                       \
    if (!(X))                           \
    {                                   \
        continue;                       \
    }

#define FUNC_ERR(X)                     \
    if (err == SC_ERR_NONE)             \
    {                                   \
        err = (X);                      \
    }

#ifdef SIMU
#define SIMU_ASRT(X, STR)               \
    if (!(X))                           \
    {                                   \
        error_print("error: %s\n", STR);\
        board_exit(-1);                 \
    }
#else
    #define SIMU_ASRT(X, STR)           \
        NOP
#endif

#define HALT                            \
    do                                  \
    {                                   \
    }                                   \
    while(true)

/*!
 * @name Defines for memory sizes
 */
/** @{ */
#define SC_4KB           0x1000UL    /*!< 4KB */
#define SC_64KB         0x10000UL    /*!< 64KB */
#define SC_128KB        0x20000UL    /*!< 128KB */
#define SC_256KB        0x40000UL    /*!< 256KB */
#define SC_1MB         0x100000UL    /*!< 1MB */
#define SC_16MB       0x1000000UL    /*!< 16MB */
#define SC_64MB       0x4000000UL    /*!< 64MB */
#define SC_256MB     0x10000000UL    /*!< 256MB */
#define SC_512MB     0x20000000UL    /*!< 512MB */
#define SC_1GB       0x40000000UL    /*!< 1GB */
#define SC_1P5GB     0x60000000UL    /*!< 1.5GB */
#define SC_2GB       0x80000000UL    /*!< 2GB */
#define SC_3GB       0xC0000000UL    /*!< 3GB */
#define SC_4GB      0x100000000ULL   /*!< 4GB */
#define SC_6GB      0x180000000ULL   /*!< 6GB */
#define SC_8GB      0x200000000ULL   /*!< 8GB */
#define SC_16GB     0x400000000ULL   /*!< 16GB */
/** @} */
    
/*!
 * @name Parameter checking macros
 */
/** @{ */
#define BOUND_PT(X)           ASRT_ERR((X) < SC_RM_NUM_PARTITION, SC_ERR_PARM)
#define BOUND_RSRC(X,I)       ASRT_ERR(rm_check_map_ridx((X), &(I)) != SC_FALSE, SC_ERR_PARM)
#define BOUND_RSRC_C(X,I)     ASRT_C(rm_check_map_ridx((X), &(I)) != SC_FALSE)
#define BOUND_MR(X)           ASRT_ERR((X) < SC_RM_NUM_MEMREG, SC_ERR_PARM)
#define BOUND_PAD(X)          ASRT_ERR((X) < SC_NUM_PAD, SC_ERR_PARM)
#define BOUND_SS(X)           ASRT_ERR((X) <= SC_SUBSYS_LAST, SC_ERR_PARM)
#define USED_PT(X)            ASRT_ERR(rm_is_partition_used(X) != SC_FALSE, SC_ERR_PARM)
#define ANCESTOR(X)           ASRT_ERR(rm_check_ancestor(caller_pt, (X)) != SC_FALSE, SC_ERR_NOACCESS)
#define ANCESTOR_C(X)         ASRT_C(rm_check_ancestor(caller_pt, (X)) != SC_FALSE)
#define OWNED(X)              ASRT_ERR(rm_is_resource_owned(caller_pt, (X)) != SC_FALSE, SC_ERR_NOACCESS)
#define OWNER(X,Y)            ASRT_ERR(rm_is_resource_owned((X), (Y)) != SC_FALSE, SC_ERR_NOACCESS)
#define SYSTEM(X)             ASRT_ERR(rm_is_sys_access(X) != SC_FALSE, SC_ERR_NOACCESS)
#define NOT_SC_PT(X)          ASRT_ERR((X) != SC_PT, SC_ERR_NOACCESS)
#define MASTER(X)             ASRT_ERR(rm_is_ridx_master(X) != SC_FALSE, SC_ERR_PARM)
#define MASTER_C(X)           ASRT_C(rm_is_ridx_master(X) != SC_FALSE)
#define PERIPHERAL(X)         ASRT_ERR(rm_is_ridx_peripheral(X) != SC_FALSE, SC_ERR_PARM)
#define PERIPHERAL_C(X)       ASRT_C(rm_is_ridx_peripheral(X) != SC_FALSE)
#define ACCESS_ALLOWED(X,I)   ASRT_ERR(rm_is_ridx_access_allowed((X), (I)) != SC_FALSE, SC_ERR_NOACCESS)
#define ACCESS_ALLOWED_C(X,I) ASRT_C(rm_is_ridx_access_allowed((X), (I)) != SC_FALSE)
/** @} */

/* Types */

/*!
 * Boot init phase types.
 */
typedef enum
{
    BOOT_PHASE_SYS_INIT        = 6,    /*!< Init system (no HW access yet) */
    BOOT_PHASE_API_INIT        = 0,    /*!< Init API (no HW access yet) */
    BOOT_PHASE_HW_INIT         = 1,    /*!< Init HW (API can be used) */
    BOOT_PHASE_EARLY_INIT      = 4,    /*!< Pre-start early CPUs */
    BOOT_PHASE_LATE_INIT       = 5,    /*!< Pre-start late CPUs */
    BOOT_PHASE_FINAL_INIT      = 2,    /*!< All done */
    BOOT_PHASE_TEST_INIT       = 3     /*!< Init HW required for unit tests */
} boot_phase_t;

typedef uint8_t sc_msize_t;
typedef uint8_t sc_mslot_t;
typedef uint8_t sc_sslot_t;

typedef const char * const strings[];

typedef union
{
    int8_t with_sign;
    uint8_t no_sign;
} cint8_t;

typedef union
{
    int16_t with_sign;
    uint16_t no_sign;
} cint16_t;

typedef union
{
    int32_t with_sign;
    uint32_t no_sign;
} cint32_t;

typedef union
{
    int64_t with_sign;
    uint64_t no_sign;
} cint64_t;

/*!
 * This type is used to declare constant subsystem information.
 */
typedef struct
{
    uint8_t present    : SC_BOOL_W;      //!< 1 if SS present
    sc_ss_inst_t inst  : SC_SS_INST_W;   //!< Instance number
    sc_sub_t db_ssi    : SC_PGP_W;       //!< DB SSI this subsystem uses
    sc_sub_t parent    : SC_SUBSYS_W;    //!< Parent SS if this is a sub-SS
    sc_rm_idx_t r_ofs  : SC_RM_IDX_W;    //!< Offset into parent's resources
    sc_rm_idx_t r2_ofs : SC_RM_IDX_W;    //!< Second offset into parent's resources
    sc_dsc_t dsc       : SC_DSC_W;       //!< Primary DSC this subsystem uses
} sc_ss_info_t;

/*!
 * This type is used to declare constant memmap information. The
 * address range is the top-level memory map as seen by the AP cores.
 */
typedef struct
{
    sc_faddr_t start;                    //!< Start of subsystem address range
    sc_faddr_t len;                      //!< Length of of subsystem address range
    uint8_t mem        : SC_BOOL_W;      //!< Contains memory
    uint8_t ss_prot    : SC_SSPROT_W;    //!< Protection 0=DB, 1=SS, 2=none
    sc_msize_t size    : SC_MSIZE_W;     //!< ZADDR size
    sc_mslot_t slot    : SC_MSLOT_W;     //!< ZADDR slot
    sc_sslot_t subslot : SC_SSLOT_W;     //!< ZADDR subslot
    sc_sub_t ss        : SC_SUBSYS_W;    //!< Associated subsystem
} sc_memmap_t;

/*!
 * This type is used to declare constant DB information.
 */
typedef struct
{
    sc_rsrc_t rsrc : SC_RSRC_W;         //!< DB resource
    sc_sub_t ss    : SC_SUBSYS_W;       //!< DB subsystem
    sc_db_connect_t connect;            //!< DB connections
} sc_db_list_t;

/*!
 * This type declares all the memory areas that can be used for boot.
 */
 typedef struct
{
    sc_faddr_t start;                   //!< Start of  memory address range
    sc_faddr_t len;                     //!< End of  memory address range
    sc_rsrc_t  rsrc   : SC_RSRC_W;      //!< Resource associated with memory.
    sc_sub_t   ss     : SC_SUBSYS_W;    //!< Subsystem associated with resource.
}sc_boot_mem_t;

/* Functions */

void main_banners(void);
sc_err_t main_drv_test(void);
void main_init(void);
sc_err_t main_sc_test(void);
void main_config(sc_rm_pt_t *pt_boot,  sc_bool_t *early);
sc_err_t main_ddr(sc_bool_t early);
uint32_t main_dcd(void);
void main_prep_cpu(sc_rsrc_t boot_cpu, sc_rsrc_t boot_mu);
void main_dump(void);
#if defined(DEBUG) && !defined(SIMU)
    /*!
     * This function configures the specified UART to be used for debug output.
     *
     * @param[in]     base        base of the UART to configure 
     * @param[in]     rate        rate of the source clock to the UART
     *
     * Calls board_get_debug_uart() to get the instance number and the baud
     * rate. If that returns 0 then will do nothing. Does not configure the pads
     * power state, or clock source. Sets SCFW_DBG_READY to 1U.
     */
    void main_config_debug_uart(LPUART_Type *base, uint32_t rate);
#endif
void main_pll_debug(void);
sc_err_t main_get_mem_ss(sc_faddr_t start_addr, uint32_t *ss);
#ifdef TEST_BOOTTIME
void test_save_time(uint32_t bootTicksRom, uint32_t bootTicksBanner,
    uint32_t bootTicksEarly);
#endif
#ifdef ENABLE_IDLE
void idle_tick(uint16_t msec);
#endif

/* Externs */

extern sc_bool_t rom_loaded;
extern const sc_db_list_t sc_db_info[SC_NUM_DB];
#ifdef DEBUG
    extern const char * const rnames[SC_NUM_RSRC];
    extern const char * const pnames[SC_NUM_PAD];
    extern const char * const snames[SC_SUBSYS_LAST + 1U];
#endif
extern const sc_ss_info_t sc_ss_info[SC_SUBSYS_LAST + 1U];
extern const sc_memmap_t sc_memmap[];
extern const ss_base_info_t * const ss_base_info[SC_SUBSYS_LAST + 1U];
extern volatile sc_bool_t rpc_debug;
extern sc_rm_idx_t rom_boot_rsrc[SC_NUM_RSRC];
extern const sc_boot_mem_t rom_boot_addr[];

#ifdef DEBUG
char term_emul_getc(void);
void term_emul_putc(char c);
#endif

#ifdef NO_DEVICE_ACCESS
    extern uint32_t temp_fuses[16 * 1024];
#endif

#endif /* SC_MAIN_H */

