/*
** ###################################################################
**     Processors:          MX8
**
**     Compilers:           GNU C Compiler
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MX8
**
**     Copyright (c) 1997 - 2016 Freescale Semiconductor, Inc.
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

/*!
 * @file
 *
 * Header file containing register access macros.
 *
 * \addtogroup Peripheral_access_layer (HAL) Device Peripheral Access Layer
 *
 * @{
 */

#ifndef FSL_BITACCESS_H
#define FSL_BITACCESS_H

/*!
 * @addtogroup SCF Register Access Macros
 * @{
 */

#include <stdint.h>
#include <stdlib.h>

/*******************************************************************************
 * Macros for generic register access
 ******************************************************************************/

#define wr_l(a,v)       (*(volatile uint32_t *)(a) = (v))
#define rd_l(a)         (*(volatile uint32_t *)(a))

#define WRITE32(a,v)    (*(volatile uint32_t *)(a) = (v))
#define READ32(a)       (*(volatile uint32_t *)(a))

/*
 * Macros for single instance registers
 */

#define BF_SET(reg, field)       HW_##reg##_SET(BM_##reg##_##field)
#define BF_CLR(reg, field)       HW_##reg##_CLR(BM_##reg##_##field)
#define BF_TOG(reg, field)       HW_##reg##_TOG(BM_##reg##_##field)

#define BF_SETV(reg, field, v)   HW_##reg##_SET(BF_##reg##_##field(v))
#define BF_CLRV(reg, field, v)   HW_##reg##_CLR(BF_##reg##_##field(v))
#define BF_TOGV(reg, field, v)   HW_##reg##_TOG(BF_##reg##_##field(v))

#define BV_FLD(reg, field, sym)  BF_##reg##_##field(BV_##reg##_##field##__##sym)
#define BV_VAL(reg, field, sym)  BV_##reg##_##field##__##sym

#define BF_RD(reg, field)        HW_##reg.B.field
#define BF_WR(reg, field, v)     BW_##reg##_##field(v)


/*******************************************************************************
 * Macros to create bitfield mask, shift, and width from CMSIS definitions
 ******************************************************************************/

/* Bitfield Mask */
#define SCF_BMSK(bitfield) (bitfield ## _MASK)

/* Bitfield Left Shift */
#define SCF_BLSH(bitfield) (bitfield ## _SHIFT)

/* Bitfield Value */
#define SCF_BVAL(bitfield, val) ((val) << (SCF_BLSH(bitfield)))


/*******************************************************************************
 * Macros to set, clear, extract, and insert bitfields into register structures
 * or local variables
 ******************************************************************************/

/* Bitfield Set */
#define SCF_BSET(var, bitfield) ((var) |= (SCF_BMSK(bitfield)))

/* Bitfield Clear */
#define SCF_BCLR(var, bitfield) ((var) &= (~(SCF_BMSK(bitfield))))

/* Multi Bitfield Set */
#define SCF_MSET(var, bitfield) ((var) |= (bitfield))

/* Multi Bitfield Clear */
#define SCF_MCLR(var, bitfield) ((var) &= ~(bitfield))

/* Bitfield Extract */
#define SCF_BEXR(var, bitfield) (((var) & (SCF_BMSK(bitfield))) >> (SCF_BLSH(bitfield)))

/* Bitfield Insert */
#define SCF_BINS(var, bitfield, val) ((var) = ((var) & (~(SCF_BMSK(bitfield)))) | SCF_BVAL(bitfield, (val)))

/* Clear bit using write-1-to-clear */
#define SCF_W1C(var, bitfield) ((var) = (SCF_BMSK(bitfield)))

#define BSET32(X,Y) \
    *((volatile uint32_t *)(X)) = ((*((volatile uint32_t *)(X))) | (Y))
#define BCLR32(X,Y) \
    *((volatile uint32_t *)(X)) = ((*((volatile uint32_t *)(X))) & ~(Y))
#define CAST32(X) (*( volatile uint32_t *)(X))

static inline void WAIT_REM32(uint32_t regis, uint32_t val, uint32_t mask,
    uint16_t read_attempts)
{
    /* Loop until value */
    while((*((volatile uint32_t *)regis) & mask) != val)
    {
        ; /* Intentional empty while */        
    }
} 

static inline void WRM32(uint32_t address, uint32_t write_data, uint32_t mask)
{
    /* Write long */
    wr_l(address, ((rd_l(address) & ~mask) | (write_data & mask)));
}

/*******************************************************************************
 * Macros to set, clear, extract, and insert bitfields into register structures
 * that support SCT
 ******************************************************************************/

#ifdef NO_DEVICE_ACCESS
/* Simulation does not have SCT hardware and must fallback to non-SCT definitions */

/* SCT Bitfield Set */
#define SCF_SCT_BSET(var, bitfield) (SCF_BSET((var).RW, bitfield))

/* SCT Bitfield Clear */
#define SCF_SCT_BCLR(var, bitfield) (SCF_BCLR((var).RW, bitfield))

/* SCT Multi Bitfield Set */
#define SCF_SCT_MSET(var, bitfield) (SCF_MSET((var).RW, bitfield))

/* SCT Multi Bitfield Set */
#define SCF_SCT_MCLR(var, bitfield) (SCF_MCLR((var).RW, bitfield))

/* SCT Bitfield Insert */
#define SCF_SCT_BINS(var, bitfield, val) (SCF_BINS((var).RW, (bitfield), (val)))

#else
/* SCT Bitfield Set */
#define SCF_SCT_BSET(var, bitfield) ((var).SET = SCF_BMSK(bitfield))

/* SCT Bitfield Clear */
#define SCF_SCT_BCLR(var, bitfield) ((var).CLR = SCF_BMSK(bitfield))

/* SCT Multi Bitfield Set */
#define SCF_SCT_MSET(var, bitfield) ((var).SET = (bitfield))

/* SCT Multi Bitfield Set */
#define SCF_SCT_MCLR(var, bitfield) ((var).CLR = (bitfield))

/* SCT Bitfield Insert */
#define SCF_SCT_BINS(var, bitfield, val) (SCF_BINS((var).RW, (bitfield), (val)))

#endif /* NO_DEVICE_ACCESS */

/*!
 * @}
 */ /* end of group SCF */

/*!
 * @}
 */ /* end of group Peripheral_access_layer */

#endif /* FSL_BITACCESS_H */

/******************************************************************************/
