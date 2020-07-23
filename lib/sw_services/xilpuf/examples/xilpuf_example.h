/******************************************************************************
* Copyright (c) 2020 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
 ******************************************************************************/

 /*****************************************************************************/
 /**
 *
 * @file xilpuf_example.h.
 * This file contains macros which needs to configured by user for
 * xilpuf_example.cand based on the options selected by user operations will be
 * performed.
 *
 * <pre>
 * MODIFICATION HISTORY:
 *
 * Ver   Who     Date     Changes
 * ----- ------  -------- ------------------------------------------------------
 * 1.0   har     01/31/20 First release
 * 1.1   har     01/31/20 Updated file version to 1.1 to sync with library version
 *
 * </pre>
 *
 * User configurable parameters for PUF
 *------------------------------------------------------------------------------
 * #define XPUF_RED_KEY
 * 	      "0000000000000000000000000000000000000000000000000000000000000000"
 * Red Key to be encrypted by PUF KEY should be provided in string format.It
 * should be either 32 or 64 characters long as only 128 bit and 256 bit key
 * are supported.
 *
 * #define XPUF_RED_KEY_LEN				(XPUF_RED_KEY_SIZE_256)
 *							(or)
 *						(XPUF_RED_KEY_SIZE_128)
 * XPUF_RED_KEY_LEN can be configured as one of the two provided options. This
 * configuration should be done on the basis of the length of the red key in bits.
 * Only 128 bit and 256 bit key are supported. By default the length of red key is
 * configured as 256 bit.
 *
 * #define XPUF_IV				"000000000000000000000000"
 * IV should be provided in string format.It should be 24 characters long, valid
 * characters are 0-9,a-f,A-F. Any other character is considered as invalid
 * string.The value mentioned here will be converted to hex buffer.It is used
 * with the AES-GCM cryptographic hardware in order to encrypt red key.

 * #define XPUF_KEY_GENERATE_OPTION		(XPUF_REGISTRATION)
 *							(or)
 *						(XPUF_REGEN_ON_DEMAND)
 * PUF helper data can be generated by PUF registration or PUF on-demand
 * regeneration.The user can configure XPUF_KEY_GENERATE_OPTION as either
 * XPUF_REGISTRATION or XPUF_REGEN_ON_DEMAND to select the mode of PUF operation
 * to generate helper data
 *
 * #define XPUF_READ_HD_OPTION			(XPUF_READ_FROM_RAM)
 *							(or)
 *						(XPUF_READ_FROM_EFUSE_CACHE)
 * This selects the location from where the helper data must be read by the
 * application. This option must be configured if XPUF_KEY_GENERATE_OPTION
 * is configured as XPUF_REGEN_ON_DEMAND.
 *
  #define XPUF_CHASH				(0x00000000)
 * CHASH value should be supplied if XPUF_READ_HD_OPTION is configured as
 * XPUF_READ_FROM_RAM.The length of CHASH should be 24 bits This can be obtained
 * by performing PUF registration and writing the helper data on the UART.
 *
 * #define XPUF_AUX				(0x00000000)
 * AUX value should be supplied if XPUF_READ_HD_OPTION is configured as
 * XPUF_READ_FROM_RAM.The length of AUX should be 32 bits This can be obtained
 * by performing PUF registration and writing the helper data on the UART.
 *
 * #define XPUF_SYN_DATA_ADDRESS		(0x00000000)
 * Address of syndrome data should be supplied if XPUF_READ_HD_OPTION is
 * configured as XPUF_READ_FROM_RAM.
 *
 * #define XPUF_WRITE_HD_IN_EFUSE		(FALSE)
 * If this option is configured as TRUE then PUF helper data is written into the
 * eFUSE.
 *
 * #define XPUF_WRITE_BLACK_KEY_OPTION		(FALSE)
 *							(or)
 *						(XPUF_EFUSE_AES_KEY)
 *							(or)
 *						(XPUF_BBRAM_AES_KEY)
 *							(or)
 *						(XPUF_EFUSE_USER_0_KEY)
 *							(or)
 *						(XPUF_EFUSE_USER_1_KEY)
 * This selects the location where the black key must be programmed.

 * #define XPUF_READ_SEC_CTRL_BITS		(FALSE)
 * This option should be configured as TRUE to read secure control eFUSE bits
 * of PUF
 *
 * #define XPUF__SEC_CTRL_BITS		(FALSE)
 * This option should be configured as TRUE to program secure control eFUSE bits
 * of PUF
 *
 * #define PUF_DIS				(FALSE)
 * This option should be configured as TRUE to program the PUF_DIS eFUSE bit
 *
 * #define PUF_REGEN_DIS			(FALSE)
 * This option should be configured as TRUE to program the PUF_REGEN_DIS eFUSE bit
 *
 * #define PUF_HD_INVLD				(FALSE)
 * This option should be configured as TRUE to program the PUF_HD_INVLD eFUSE bit
 *
 * #define PUF_SYN_LK				(FALSE)
 * This option should be configured as TRUE to program the PUF_SYN_LK eFUSE bit
 *
 ******************************************************************************/
#ifndef XILPUF_EXAMPLE_H
#define XILPUF_EXAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xil_types.h"

/************************** Constant Definitions *****************************/
/* For reading Secure control eFUSE bits of PUF */
#define XPUF_READ_SEC_CTRL_BITS			(FALSE)

#define XPUF_RED_KEY	\
	"0000000000000000000000000000000000000000000000000000000000000000"

/*
 * Below macro values should match with enum XSecure_AesKeySize.
 * As preprocessor can't handle enums at preprocessing stage of compilation,
 * these macros are defined.
 */
#define XPUF_RED_KEY_SIZE_128		(0U)
#define XPUF_RED_KEY_SIZE_256		(2U)

#define XPUF_RED_KEY_LEN			(XPUF_RED_KEY_SIZE_256)

#if (XPUF_RED_KEY_LEN == XPUF_RED_KEY_SIZE_256)
#define XPUF_RED_KEY_LEN_IN_BYTES 		(32U)
#elif (XPUF_RED_KEY_LEN == XPUF_RED_KEY_SIZE_128)
#define XPUF_RED_KEY_LEN_IN_BYTES 		(16U)
#endif

#define XPUF_IV					"000000000000000000000000"
#define XPUF_KEY_GENERATE_OPTION		(XPUF_REGISTRATION)

#if (XPUF_KEY_GENERATE_OPTION == XPUF_REGEN_ON_DEMAND)
#define XPUF_READ_HD_OPTION			(XPUF_READ_FROM_RAM)
#define XPUF_CHASH				(0x00000000U)
#define XPUF_AUX				(0x00000000U)
#define XPUF_SYN_DATA_ADDRESS			(0x00000000U)
#elif (XPUF_KEY_GENERATE_OPTION == XPUF_REGISTRATION)
#define XPUF_WRITE_HD_IN_EFUSE 			(FALSE)
#endif

#define XPUF_WRITE_BLACK_KEY_OPTION		(FALSE)

/* For programming Secure control eFUSE bits of PUF */
#define XPUF_WRITE_SEC_CTRL_BITS			(FALSE)
#if (XPUF_WRITE_SEC_CTRL_BITS == TRUE)
#define PUF_DIS					(FALSE)
#define PUF_REGEN_DIS				(FALSE)
#define PUF_HD_INVLD				(FALSE)
#define PUF_SYN_LK				(FALSE)
#endif

/**************************** Type Definitions *******************************/
typedef enum {
	XPUF_EFUSE_AES_KEY = 1U,
	XPUF_BBRAM_AES_KEY,
	XPUF_EFUSE_USER_0_KEY,
	XPUF_EFUSE_USER_1_KEY
} XPuf_WriteBlackKeyOption;

/***************** Macros (Inline Functions) Definitions *********************/

#ifdef __cplusplus
}
#endif

#endif /* XILPUF_EXAMPLE_H_ */
