/*
 * Copyright 2017-2021 NXP
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

#ifndef DRV_SECO_H
#define DRV_SECO_H

/*!
 * @addtogroup seco_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"
#include "svc/seco/api.h"

/* Defines */

/*!
 * @name Defines for seco_lifecycle_t
 */
/** @{ */
#define SECO_LIFECYCLE_DEFAULT      BIT(0)    /*!< Default fab mode (early_fuses_pgrm not blown) */
#define SECO_LIFECYCLE_FAB          BIT(1)    /*!< Fab mode */
#define SECO_LIFECYCLE_NO_SECRETS   BIT(2)    /*!< No secrets */
#define SECO_LIFECYCLE_SECRETS      BIT(3)    /*!< With Secrets */
#define SECO_LIFECYCLE_SC_FW_CLSD   BIT(4)    /*!< SCU FW Closed */
#define SECO_LIFECYCLE_SECO_FW_CLSD BIT(5)    /*!< SECO FW Closed */
#define SECO_LIFECYCLE_CLOSED       BIT(6)    /*!< Closed */
#define SECO_LIFECYCLE_CLOSED_FW    BIT(7)    /*!< Closed with FW */
#define SECO_LIFECYCLE_PART_RTN     BIT(8,    /*!< Partial field return */
#define SECO_LIFECYCLE_RTN          BIT(9)    /*!< Field return */
#define SECO_LIFECYCLE_NO_RTN       BIT(10)   /*!< No Return */
/** @} */

/*!
 * @name Defines for seco_snvs_id_t
 */
/** @{ */
#define AHAB_SNVS_ID_INIT           0x00U     /*!< Init SNVS */
#define AHAB_SNVS_ID_POWER_OFF      0x01U     /*!< Power off the system */
#define AHAB_SNVS_ID_SRTC           0x02U     /*!< R/W the SRTC */
#define AHAB_SNVS_ID_SRTC_CALB      0x03U     /*!< R/W the SRTC calibration */
#define AHAB_SNVS_ID_SRTC_ALRM      0x04U     /*!< R/W the SRTC alarm */
#define AHAB_SNVS_ID_RTC            0x05U     /*!< R/W the RTC */
#define AHAB_SNVS_ID_RTC_CALB       0x06U     /*!< R/W the RTC calibration */
#define AHAB_SNVS_ID_RTC_ALRM       0x07U     /*!< R/W the RTC alarm */
#define AHAB_SNVS_ID_BTN_CONFIG     0x08U     /*!< R/W the button configuration */
#define AHAB_SNVS_ID_BTN_MASK       0x09U     /*!< R/W the button mask */
#define AHAB_SNVS_ID_BTN            0x0AU     /*!< R/W the button state */
#define AHAB_SNVS_ID_BTN_CLEAR      0x0BU     /*!< Clear the button IRQ */
#define AHAB_SNVS_ID_SSM_STATE      0x0CU     /*!< Read the SSM state */
#define AHAB_SNVS_ID_BTN_TIME       0x0DU     /*!< R/W the button time parameters */
#define AHAB_SNVS_ID_WAKE_UP_IT     0x0EU     /*!< Clear the wake IRQ */
/** @} */

/*!
 * @name Defines for SNVS access
 */
/** @{ */
#define SECO_SNVS_READ              0U   /*!< SNVS read operation */
#define SECO_SNVS_WRITE             1U   /*!< SNVS write operation */
/** @} */

/*!
 * @name Macros for version parsing
 */
/** @{ */
#define SECO_PROD_VER(X)      (((X) >> 16) & 0x7FFFUL)  /*!< Extract SECO production ver */
#define SECO_MAJOR_VER(X)     (((X) >> 4) & 0xFFFUL)    /*!< Extract SECO major ver */
#define SECO_MINOR_VER(X)     ((X) & 0xFUL)             /*!< Extract SECO minor ver */
/** @} */

/*!
 * @name Defines for V2X state
 */
/** @{ */
#define V2X_STATE_AUTH_RX      0x01U /*!< Authentication request received */
#define V2X_STATE_PROV_NORMAL  0x02U /*!< Provisioned successfully in normal mode */
#define V2X_STATE_PROV_DEBUG   0x04U /*!< Provisioned successfully in debug mode */
#define V2X_STATE_AUTH_IP      0x08U /*!< Authentication on going */
#define V2X_STATE_AUTH_SUCCESS 0x10U /*!< Authentication success */
#define V2X_STATE_AUTH_FAIL    0x20U /*!< Authentication failure */
#define V2X_STATE_CRYPTO_DIS   0x40U /*!< Crypto accelerators disabled */
#define V2X_STATE_HOLD_EN      0x80U /*!< V2X provisioning on hold */
/** @} */

/*!
 * @name Defines for V2X power mode and state
 */
/** @{ */
#define V2X_POWER_STATE_UNKNOWN 0U   /*!< Unknown power state */
#define V2X_POWER_STATE_ON      1U   /*!< Power on state */
#define V2X_POWER_STATE_LP      2U   /*!< Low power state */
#define V2X_POWER_STATE_STBY    3U   /*!< Standby state */
#define V2X_POWER_STATE_OFF     4U   /*!< Power off state */
/** @} */

/*!
 * @name Defines for V2X power flags
 */
/** @{ */
#define V2X_POWER_NONE       0x00U   /*!< No flags */
#define V2X_POWER_FORCE      0x01U   /*!< Force power state change */
/** @} */

/*!
 * @name Defines for V2X recovery flags
 */
/** @{ */
#define V2X_RECOVER_NONE     0x00U   /*!< No flags */
#define V2X_RECOVER_AUTH     0x01U   /*!< Send FW recovery */
/** @} */

#ifdef NO_DEVICE_ACCESS
    /*!
     * This variable is used to access fake SECO.
     */
    extern uint32_t temp_seco[];
    #define HAS_TEMP_SECO
#endif

/* Types */

/*!
 * This type is used to return the lifecycle.
 */
typedef uint16_t seco_lifecycle_t;

/*!
 * This type is used to indicate the ID of anSNVS register to access.
 */
typedef uint8_t seco_snvs_id_t;

/*!
 * This type is used to communicate SECO/V2X indication codes.
 */
typedef enum
{
    AHAB_ROM_PING_IND                   = 0x0A,
    AHAB_FW_PING_IND                    = 0x1A,
    AHAB_BAD_SIGNATURE_IND              = 0xF0,
    AHAB_BAD_HASH_IND                   = 0xF1,
    AHAB_INVALID_LIFECYCLE              = 0xF2,
    AHAB_PERMISSION_DENIED_IND          = 0xF3,
    AHAB_INVALID_MESSAGE_IND            = 0xF4,
    AHAB_BAD_VALUE_IND                  = 0xF5,
    AHAB_BAD_FUSE_ID_IND                = 0xF6,
    AHAB_BAD_CONTAINER_IND              = 0xF7,
    AHAB_BAD_VERSION_IND                = 0xF8,
    AHAB_INVALID_KEY_IND                = 0xF9,
    AHAB_BAD_KEY_HASH_IND               = 0xFA,
    AHAB_NO_VALID_CONTAINER_IND         = 0xFB,
    AHAB_BAD_CERTIFICATE_IND            = 0xFC,
    AHAB_BAD_UID_IND                    = 0xFD,
    AHAB_BAD_MONOTONIC_COUNTER_IND      = 0xFE,
    AHAB_SECO_FATAL_FAILURE_IND         = 0xFF,
    AHAB_MUST_SIGNED_IND                = 0xE0,
    AHAB_NO_AUTHENTICATION_IND          = 0xEE,
    AHAB_BAD_SRK_SET_IND                = 0xEF,
    AHAB_OOM_FOR_BLOB_IND               = 0xA0,
    AHAB_BID_COLLISION_IND              = 0xA1,
    AHAB_NO_BID_MATCHING_IND            = 0xA2,
    AHAB_UNKNOWN_BID_IND                = 0xA3,
    AHAB_BAD_BLOB_IND                   = 0xA4,
    AHAB_OOM_FOR_BLOB_EXPORT_IND        = 0xA5,
    AHAB_UNALIGNED_PAYLOAD_IND          = 0xA6,
    AHAB_WRONG_SIZE_IND                 = 0xA7,
    AHAB_ENCRYPTION_FAILURE_IND         = 0xA8,
    AHAB_DECRYPTION_FAILURE_IND         = 0xA9,
    AHAB_OTP_PROGFAIL_IND               = 0xAA,
    AHAB_OTP_LOCKED_IND                 = 0xAB,
    AHAB_OTP_DED_IND                    = 0xAC,
    AHAB_OTP_INVALID_IDX_IND            = 0xAD,
    AHAB_ADM_NOT_READY_IND              = 0xAE,
    AHAB_ADM_WRONG_LC_IND               = 0xAF,
    AHAB_TIME_OUT_IND                   = 0xB0,
    AHAB_BAD_PAYLOAD_IND                = 0xB1,
    AHAB_HDCP_DISABLED_IND              = 0xB2,
    AHAB_KMEK_GENERATION_FAIL_IND       = 0xB3,
    AHAB_WRONG_ADDRESS_IND              = 0xB4,
    AHAB_DMA_FAILURE_IND                = 0xB5,
    AHAB_DISABLED_FEATURE_IND           = 0xB6,
    AHAB_MUST_ATTEST_IND                = 0xB7,
    AHAB_RNG_NOT_STARTED_IND            = 0xB8,
    AHAB_CRC_ERROR                      = 0xB9,
    AHAB_BLOB_GENERATION_FAILURE        = 0xBA,
    AHAB_AUTH_SKIPPED_OR_FAILED_IND     = 0xBB,
    AHAB_INCONSISTENT_PAR_IND           = 0xBC,
    AHAB_RNG_INST_FAILURE_IND           = 0xBD,
    AHAB_LOCKED_REG_IND                 = 0xBE,
    AHAB_BAD_ID_IND                     = 0xBF,
    AHAB_INVALID_OPERATION_IND          = 0xC0,
    AHAB_NON_SECURE_STATE_IND           = 0xC1
} seco_msg_ind_t;

/*!
 * This type is used to communicate SECO/V2X status codes.
 */
typedef enum
{
    AHAB_SUCCESS_IND                = 0x00,
    AHAB_FAILURE_IND                = 0x29
} seco_msg_status_t;

/* Functions */

/*!
 * @name Initialization Functions
 * @{
 */

/*!
 * This function initializes the SECO driver.
 *
 * @param[in]     phase       Init phase
 *
 * Called when SCFW boots.
 */
void SECO_Init(boot_phase_t phase);

/*!
 * This function sends a message to SECO to indicate it is ready
 * to get interrupts.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_SCFW_Ready(void);

/*!
 * This function configures the CAAM MP.
 *
 * @param[in]     master      Index of job ring / out 
 * @param[in]     lock        Lock state of config
 * @param[in]     sa          Secure state
 * @param[in]     did         XRDC2 Domain ID
 * @param[in]     sid         SMMU Stream ID
 *
 * Called by the Resource Manager to configure CAAM job ring access and
 * output parameters.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_CAAM_Config(uint16_t master, sc_bool_t lock, sc_rm_spa_t sa,
    sc_rm_did_t did, sc_rm_sid_t sid);

/*!
 * This function configures the CAAM MP.
 *
 * @param[in]     jr          index of job ring 
 * @param[in]     allow       allow make trusted descriptor
 * @param[in]     lock        lock 
 *
 * Called to configure the trusted descriptor feature for the
 * CAAM job rings.
 *
 * For \a allow SC_TRUE = allow this JR to make trusted descriptors,
 * SC_FALSE = disallows.
 *
 * For \a lock SC_TRUE = lock the allow state, SC_FALSE = do not lock.
 * Once locked, it cannot be unlocked. Can be locked in the allow or
 * disallow state!
 *
 * See the SRM and the SECO API Reference Guide for more info.
 */
void SECO_CAAM_Config_TD(uint16_t jr, sc_bool_t allow, sc_bool_t lock);

/*!
 * This function clears the CAAM MP cache. It is called by the Power
 * Manager when CAAM power state is lost.
 */
void SECO_ClearCache(void);

/*!
 * This function configures MU ownership.
 *
 * @param[in]     mu          Index of MU
 * @param[in]     sa          Secure state
 * @param[in]     did         XRDC2 Domain ID
 *
 * Called by the Resource Manager to configure MU access.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_MU_Config(uint8_t mu, sc_rm_spa_t sa, sc_rm_did_t did);

/*!
 * This function partitions the monotonic counter.
 *
 * @param[in,out] she         number of SHE bits
 * @param[in,out] hsm         number of HSM bits
 *
 * SECO uses an OTP monotonic counter to protect the SHE and HSM key-stores
 * from roll-back attack. This function is used to define the number of
 * monotonic counter bits allocated to SHE and HSM use. Two monotonic counter
 * bits are used to store this information while the remaining bits are allocated
 * to the HSM user. This function must be called before any SHE or HSM key stores
 * are created in the system, otherwise the default configuration is applied.
 *
 * If the partition has been already configured, any attempt to re-configure
 * the SHE/HSM partition to a different value will result in a failure response.
 *
 * See the SECO API Reference Guide for more info.
 */
 void SECO_SetMonoCounterPartition(uint16_t *she, uint16_t *hsm);

/*!
 * This function configures the SECO in FIPS mode.
 *
 * @param[in]     mode        FIPS mode
 *
 * This function permanently configures the SECO in FIPS approved mode. When in
 * FIPS approved mode the following services will be disabled and receive a
 * failure response:
 *
 * - Encrypted boot is not supported
 * - Attestation is not supported
 * - Manufacturing protection is not supported
 * - DTCP load
 * - SHE services are not supported
 * - Assign JR is not supported (all JRs owned by SECO)
 *
 * @return Returns the failure reason.
 *
 * See the SECO API Reference Guide for more info.
 */
uint32_t SECO_SetFipsMode(uint8_t mode);

/*!
 * This function will securely zeroize all plaintext secret and private
 * cryptographic keys and CSPs within the module.
 *
 * @param[in]     addr        address of message block
 *
 * Note \a addr must be a pointer to a signed message block.
 *
 * This function is effective when the part is configured in FIPS approved
 * mode only, no effects otherwise.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_FipsKeyZero(sc_faddr_t addr);

/** @} */

/*!
 * @name Power Management Functions
 * @{
 */

/*!
 * This function notifies SECO that a subsystem power state has changed.
 *
 * @param[in]     ss          Subsystem
 * @param[in]     inst        Subsystem instance
 * @param[in]     up          Power state
 *
 * Called by the Power Manager when subsystem power state changes.
 */
void SECO_Power(sc_sub_t ss, uint32_t inst, sc_bool_t up);

/*!
 * This function notifies SECO that CAAM is powering down.
 *
 * Called by the Power Manager before powering down the CAAM.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_CAAM_PowerDown(void);

/*!
 * This function notifies SECO the system is entering low power mode.
 *
 * Called by the Power Manager before entering LPM.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_EnterLPM(void);

/*!
 * This function notifies SECO the system is has exited low power mode.
 *
 * Called by the Power Manager before after exiting LPM.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_ExitLPM(void);

/** @} */

/*!
 * @name Image Functions
 * @{
 */

/*!
 * This function loads a SECO image.
 *
 * @param[in]     addr_src    address of image source
 * @param[in]     addr_dst    address of image destination
 * @param[in]     len         length of image to load
 * @param[in]     fw          SC_TRUE = firmware load
 *
 * This is used to load images via the SECO. Examples include SECO
 * Firmware and IVT/CSF data used for authentication. These are usually
 * loaded into SECO TCM. \a addr_src is in secure memory.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_Image_Load(sc_faddr_t addr_src, sc_faddr_t addr_dst, uint32_t len,
    sc_bool_t fw);

/*!
 * This function is used to authenticate a SECO image or command.
 *
 * @param[in]     cmd         authenticate command
 * @param[in]     addr        address of/or metadata
 * @param[in]     mask1       metadata
 * @param[in]     mask2       metadata
 *
 * This is used to authenticate a SECO image or issue a security
 * command. \a addr often points to an container. It is also
 * just data (or even unused) for some commands.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_Authenticate(sc_seco_auth_cmd_t cmd, sc_faddr_t addr,
    uint32_t mask1, uint32_t mask2);

/** @} */

/*!
 * @name Lifecycle Functions
 * @{
 */

/*!
 * This function is used get the lifecycle from the ADM.
 *
 * @return Returns the lifecycle.
 */
seco_lifecycle_t SECO_Get_Lifecycle(void);

/*!
 * This function updates the lifecycle of the device.
 *
 * @param[in]     change      desired lifecycle transition
 *
 * This function is used for going from Open to NXP Closed to OEM Closed. 
 * Note \a change is NOT the new desired lifecycle. It is a lifecycle
 * transition as documented in the SECO API Reference Guide.
 *
 * If any SECO request fails or only succeeds because the part is in an
 * "OEM open" lifecycle, then a request to transition from "NXP closed"
 * to "OEM closed" will also fail. For example, booting a signed container
 * when the OEM SRK is not fused will succeed, but as it is an abnormal
 * situation, a subsequent request to transition the lifecycle will return
 * an error via seco_err.
 */
void SECO_ForwardLifecycle(uint32_t change);

/*!
 * This function updates the lifecycle to one of the return lifecycles.
 *
 * @param[in]     addr        address of message block
 *
 * Note \a addr must be a pointer to a signed message block.
 *
 * To switch back to NXP states (Full Field Return), message must be signed
 * by NXP SRK. For OEM States (Partial Field Return), must be signed by OEM
 * SRK.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_ReturnLifecycle(sc_faddr_t addr);

/*!
 * This function is used to commit into the fuses any new SRK revocation
 * and FW version information that have been found in the primary and
 * secondary containers.
 *
 * @param[in,out] info        pointer to information type to be committed
 *
 * The return \a info will contain what was actually committed.
 */
void SECO_Commit(uint32_t *info);

/** @} */

/*!
 * @name Attestation Functions
 * @{
 */

/*!
 * This function is used to set the attestation mode.
 *
 * @param[in]     mode        mode
 *
 * This is used to set the SECO attestation mode. This can be prover
 * or verfier. See the SECO API Reference Guide for more on the
 * supported modes, mode values, and mode behavior.
 */
void SECO_AttestMode(uint32_t mode);

/*!
 * This function is used to request atestation.
 *
 * @param[in]     nonce       unique value
 *
 * This is used to ask SECO to perform an attestation. The result depends
 * on the attestation mode. After this call, the signature can be
 * requested or a verify can be requested.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_Attest(uint64_t nonce);

/*!
 * This function is used to retrieve the attestation public key.
 * Mode must be verifier.
 *
 * @param[in]     addr        address to write response
 *
 * Result will be written to \a addr. The \a addr parmater must point
 * to an address SECO can access. It must be 64-bit aligned. There
 * should be 96 bytes of space. 
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_GetAttestPublicKey(sc_faddr_t addr);

/*!
 * This function is used to retrieve attestation signature and parameters.
 * Mode must be provider.
 *
 * @param[in]     addr        address to write response
 *
 * Result will be written to \a addr. The \a addr parmater must point
 * to an address SECO can access. It must be 64-bit aligned. There
 * should be 120 bytes of space. 
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_GetAttestSign(sc_faddr_t addr);

/*!
 * This function is used to verify attestation. Mode must be verifier.
 *
 * @param[in]     addr        address of signature
 *
 * The \a addr parmater must point to an address SECO can access. It must be
 * 64-bit aligned. 
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_AttestVerify(sc_faddr_t addr);

/** @} */

/*!
 * @name Key Functions
 * @{
 */

/*!
 * This function is used to generate a SECO key blob.
 *
 * @param[in]     id          key identifier
 * @param[in]     load_addr   load address
 * @param[in]     export_addr export address
 * @param[in]     max_size    max export size
 *
 * This function is used to encapsulate sensitive keys in a specific structure
 * called a blob, which provides both confidentiality and integrity protection. 
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_GenKeyBlob(uint32_t id, sc_faddr_t load_addr,
    sc_faddr_t export_addr, uint16_t max_size);

/*!
 * This function is used to load a SECO key.
 *
 * @param[in]     id          key identifier
 * @param[in]     addr        key address
 *
 * This function is used to install private cryptographic keys encapsulated
 * in a blob previously generated by SECO. The controller can be either the
 * IEE or the VPU. The blob header carries the controller type and the key
 * size, as provided by the user when generating the key blob. 
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_LoadKey(uint32_t id, sc_faddr_t addr);

/** @} */

/*!
 * @name Manufacturing Protection Functions
 * @{
 */

/*!
 * This function is used to get the manufacturing protection public key.
 *
 * @param[in]     dst_addr    destination address
 * @param[in]     dst_size    destination size
 *
 * This function is supported only in OEM-closed lifecycle. It generates
 * the mfg public key and stores it in a specific location in the secure
 * memory. 
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_GetMPKey(sc_faddr_t dst_addr, uint16_t dst_size);

/*!
 * This function is used to update the manufacturing protection message
 * register.
 *
 * @param[in]     addr        data address
 * @param[in]     size        size
 * @param[in]     lock        lock_reg
 *
 * This function is supported only in OEM-closed lifecycle. It updates the
 * content of the MPMR (Manufacturing Protection Message register of 256
 * bits). This register will be appended to the input-data message when
 * generating the signature. Please refer to the CAAM block guide for details. 
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_UpdateMPMR(sc_faddr_t addr, uint8_t size, uint8_t lock);

/*!
 * This function is used to get the manufacturing protection signature.
 *
 * @param[in]     msg_addr    message address
 * @param[in]     msg_size    message size
 * @param[in]     dst_addr    destination address
 * @param[in]     dst_size    destination size
 *
 * This function is used to generate an ECDSA signature for an input-data
 * message and to store it in a specific location in the secure memory. It
 * is only supported in OEM-closed lifecycle. In order to get the ECDSA
 * signature, the RNG must be initialized. In case it has not been started
 * an error will be returned.  
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_GetMPSign(sc_faddr_t msg_addr, uint16_t msg_size,
    sc_faddr_t dst_addr, uint16_t dst_size);

/** @} */

#ifdef HAS_V2X

/*!
 * @name V2X Functions
 * @{
 */

/*!
 * This function is used to forward a message received from V2X.
 *
 * @param[in]     buf         pointer to message buffer
 *
 * @return Returns number of words in response.
 */
uint8_t SECO_V2X_Forward(uint32_t *buf);

/*!
 * This function sends a ping to V2X through SECO.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_V2X_Ping(void);

/*!
 * This function is used to set a control variable indicating whether or not the
 * configuration of the V2X must be done as soon as possible or should be delayed
 * and left under the control of the SCU.
 *
 * @param[in]     hold_value  0=no delay, 1=delay
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_V2X_Hold(uint32_t hold_value);

/*!
 * This function is used to provision the V2X either in "normal" mode or in "debug"
 * mode. Provisioning for debug request will be accepted only in NXP open LC. In NXP
 * closed LC, the SECO_EnableDebug() function must be used instead.
 *
 * @param[in]     provision_mode  0=normal, 1=debug
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_V2X_Provision(uint32_t provision_mode);

/*!
 * This function returns the v2x_state (provisioned, successfully authenticated, etc.).
 * It should be sent after the v2x_authenticate_request in order to get the result
 * of the v2x authentication once finished.
 *
 * @param[out]    req_status      V2X authentication request status
 * @param[out]    power_state     V2X power state
 *
 * @return Returns the V2X state.
 *
 * - Bit 0: v2x authentication request received
 * - Bit 1: v2x provisioned successfully in normal mode
 * - Bit 2: v2x provisioned successfully in debug mode
 * - Bit 3: v2x authentication on going
 * - Bit 4: v2x authentication success
 * - Bit 5: v2x authentication failure
 * - Bit 6: v2x crypto disabled
 * - Bit 7: v2x hold enabled
 *
 * See the SECO API Reference Guide for more info.
 */
uint8_t SECO_V2X_GetState(uint32_t *req_status, uint8_t *power_state);

/*!
 * This function sets the V2X power state on SECO. If the request is successful,
 * the V2X power state will be updated on SECO. Otherwise, the requested power state
 * is not allowed and error will be reported via seco_err.
 *
 * @param[in]     power_mode      requested power mode
 * @param[in]     flags           flags to pass to SECO
 * @param[out]    addr            pointer to return FW address
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_V2X_Power(uint8_t power_mode, uint8_t flags, sc_saddr_t *addr);

/*!
 * This function obtains the V2X FW address.
 *
 * @param[out]    addr            pointer to return FW address
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_V2X_Get_FW_Addr(sc_saddr_t *addr);

/*!
 * This function will recover the V2X firmware after a power off. If the flag is 
 * V2X_RECOVER_AUTH, SECO will send a V2X authenticate request to V2X using the
 * V2X container header from the last V2X authenticate request.
 *
 * @param[in]     flags           flags to pass to SECO
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_V2X_FW_Recovery(uint8_t flags);

/*!
 * This function will notify SECO that the V2X images used for the last V2X
 * authentication have been/will be move to a new location given in parameter.
 * If the request is successful SECO will use the new location of the images
 * for V2X recovery.
 *
 * @param[in]     addr            new V2X FW address
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_V2X_Remap_FW(sc_saddr_t addr);

/*!
 * Interrupt handler for the SECO MU.
 */
void SECO_MU_IRQHandler(void);

/** @} */

#endif

/*!
 * @name Debug Functions
 * @{
 */

/*!
 * This function is used to return the SECO FW build info.
 *
 * @param[out]    version     pointer to return build number
 * @param[out]    commit      pointer to return commit ID (git SHA-1)
 * @param[out]    dirty       pointer to return dirty flag
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_Version(uint32_t *version, uint32_t *commit, sc_bool_t *dirty);

/*!
 * This function is used to return SECO chip info.
 *
 * @param[out]    lc          pointer to return lifecycle
 * @param[out]    monotonic   pointer to return monotonic counter
 * @param[out]    uid_l       pointer to return UID (lower 32 bits)
 * @param[out]    uid_h       pointer to return UID (upper 32 bits)
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_ChipInfo(uint16_t *lc, uint16_t *monotonic, 
    uint32_t *uid_l, uint32_t *uid_h);

/*!
 * This function notifies SECO that a JTAG connection has been made.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_AttachDebug(void);

/*!
 * This function securely enables debug.
 *
 * @param[in]     addr        address of message block
 *
 * Note \a addr must be a pointer to a signed message block.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_EnableDebug(sc_faddr_t addr);

/*!
 * This function is used to return an event from the SECO error log.
 *
 * @param[out]    idx         index of event to return
 *
 * @return Returns the event.
 *
 * Read of \a idx 0 captures events from SECO. Loop starting
 * with 0 until an error is returned to dump all events.
 *
 * See the SECO API Reference Guide for more info.
 */
uint32_t SECO_GetEvent(uint8_t idx);

/*!
 * This function dumps low-level SECO debug info to the SCU debug
 * UART.
 */
void SECO_DumpDebug(void);

/*!
 * This function return the internal SECO error number returned by
 * the last SECO function call. It is valid if seco_err != SC_R_NONE.
 *
 * See the SECO API Reference Guide for a description of these
 * internal error codes.
 *
 * @return Returns the error number.
 */
uint32_t SECO_ErrNumber(void);

/*!
 * This function translates a SECO/V2X response word into the various
 * response fields.
 *
 * @param[in]     resp           response word
 * @param[out]    status         pointer to return the status
 * @param[out]    ind            pointer to return the indication
 * @param[out]    abort_line     pointer to return the abort line number
 * @param[out]    abort_module   pointer to return the abort module
 *
 * See the SECO API Reference Guide for a description of these
 * internal error codes.
 */
void SECO_Parse_Resp(uint32_t resp, seco_msg_status_t *status,
    seco_msg_ind_t *ind, uint8_t *abort_line, uint8_t *abort_module);

/*!
 * This function translates a SECO/V2X indication code to an SCFW
 * error code.
 *
 * @param[in]     ind         indication code
 *
 * See the SECO API Reference Guide for a description of these
 * internal error codes.
 *
 * @return Returns the error number.
 */
sc_err_t SECO_Ind2Err(seco_msg_ind_t ind);

/** @} */

/*!
 * @name Miscellaneous Functions
 * @{
 */

/*!
 * This function sends a ping to SECO.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_Ping(void);

/*!
 * This function sends a a message to SECO to service the
 * 24H watchdog. SCFW sends this periodically.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_KickWdog(void);

/*!
 * This function writes a given fuse word index.
 *
 * @param[in]     word        fuse word index
 * @param[in]     val         fuse write value
 *
 * The command is passed as is to SECO. SECO uses part of the
 * \a word parameter to indicate if the fuse should be locked
 * after programming. See the "Write common fuse" section of
 * the SECO API Reference Guide for more info.
 */
void SECO_WriteFuse(uint32_t word, uint32_t val);

/*!
 * This function securely writes a group of fuse words.
 *
 * @param[in]     addr        address of message block
 *
 * Note \a addr must be a pointer to a signed message block.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_SecureWriteFuse(sc_faddr_t addr);

/*!
 * This function applies a patch.
 *
 * @param[in]     addr        address of message block
 *
 * Note \a addr must be a pointer to a signed message block.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_ScuPatch(sc_faddr_t addr);

/*!
 * This function starts the random number generator.
 *
 * @return Returns the state of RNG.
 *
 * The RNG is started automatically after all CPUs are booted. This
 * function can be used to start earlier and to check the status.
 *
 * See the SECO API Reference Guide for more info.
 */
sc_seco_rng_stat_t SECO_StartRNG(void);

/*!
 * This function is used to send a generic signed message to the
 * SECO SHE/HSM components.
 *
 * @param[in]     addr        address of message block
 *
 * Note \a addr must be a pointer to a signed message block.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_SABSignedMesg(sc_faddr_t addr);

/** @} */

/*!
 * @name SNVS Functions
 * @{
 */

/*!
 * This function write an SNVS parameter.
 *
 * @param[in]     id          ID of parameter to write
 * @param[in]     val         value to write
 *
 * This function is used by the SNVS driver. Users should
 * call that driver instead of this function.
 *
 * See the SECO API Reference Guide for more info.
 */
void SECO_WriteSNVS(seco_snvs_id_t id, uint32_t val);

/*!
 * This function reads an SNVS parameter.
 *
 * @param[in]     id          ID of parameter to read
 *
 * This function is used by the SNVS driver. Users should
 * call that driver instead of this function.
 *
 * @return Returns the value read.
 *
 * See the SECO API Reference Guide for more info.
 */
uint32_t SECO_ReadSNVS(seco_snvs_id_t id);

/*!
 * This function is used to manage the SNVS. It allows reading and
 * writing of various SNVS registers.
 *
 * @param[in]     id          ID of parameter to read
 * @param[in]     access      Access type (read or write)
 * @param[in,out] val         pointer to value to read or write
 * @param[in]     size        number of words to read or write
 *
 * For info on what the SNVS registers do, refer to the SNVS section
 * of the SRM.
 *
 * Note many aspects of the SNVS are used by SECO and not available for
 * use (e.g. LPGPR0) and this function will not allow access to those
 * registers/fields. See the SECO API Reference Guide for more info.
 */
void SECO_ManageSNVS(uint8_t id, uint8_t access, uint32_t *val, uint8_t size);

/*!
 * This function is used to manage the SNVS DGO. It allows reading and
 * writing of various privileged SNVS DGO registers.
 *
 * @param[in]     id          ID of parameter to read
 * @param[in]     access      Access type (read or write)
 * @param[in,out] val         pointer to value to read or write
 *
 * For info on what the SNVS registers do, refer to the SNVS section
 * of the SRM.
 */
void SECO_ManageSNVS_DGO(uint8_t id, uint8_t access, uint32_t *val);

/** @} */

/* Externs */

/*! SECO error return */
extern sc_err_t seco_err;

#endif /* DRV_SECO_H */

/** @} */

