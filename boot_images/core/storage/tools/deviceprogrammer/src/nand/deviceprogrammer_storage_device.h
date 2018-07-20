/*==================================================================
 *
 * FILE:        deviceprogrammer_storage_device.h
 *
 * DESCRIPTION:
 *   
 *
 *        Copyright © 2008-2013 Qualcomm Technologies Incorporated.
 *               All Rights Reserved.
 *               QUALCOMM Proprietary
 *==================================================================*/

/*===================================================================
 *
 *                       EDIT HISTORY FOR FILE
 *
 *   This section contains comments describing changes made to the
 *   module. Notice that changes are listed in reverse chronological
 *   order.
 *
 *   $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/deviceprogrammer/src/nand/deviceprogrammer_storage_device.h#1 $ 
 *   $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $
 *
 * YYYY-MM-DD   who     what, where, why
 * ----------   ---     ----------------------------------------------
 * 2014-03-03   dks     Added MMC FFU Support
 * 2013-06-03   ah      Added legal header
 * 2013-05-31   ab      Initial checkin
 */

#ifndef DEVICEPROGRAMMER_STORAGE_DEVICE_H
#define DEVICEPROGRAMMER_STORAGE_DEVICE_H

#include "deviceprogrammer_utils.h"
#include "flash.h"
#include "flash_prog.h"
#include "flash_miparti.h"



//flash/tools/src/nand/nand_core.h
//tools/deviceprogrammer/src/emmc/deviceprogrammer_storage_device.h




/* A ENUM used to mark which image is currently being programmed 
typedef enum
{
  PARTITION_EMMC_USER = 0,
  PARTITION_EMMC_BOOT1,
  PARTITION_EMMC_BOOT2,
  PARTITION_EMMC_RPMB,
  PARTITION_EMMC_GPP1,
  PARTITION_EMMC_GPP2,
  PARTITION_EMMC_GPP3,
  PARTITION_EMMC_GPP4,
  PARTITION_EMMC_NONE
} open_partition_type;*/


/* Enumerated type to see if device probed OK so we only probe once */
typedef enum
{
	  FLASH_DEVICE_FOUND,		  /* Successful probe			  */
	  FLASH_DEVICE_UNKNOWN, 	  /* Failed to probe successfully */
	  FLASH_DEVICE_NOT_PROBED	  /* Not yet probed 			  */
}
probe_code_type;


typedef struct {
    probe_code_type probe_status;
    flash_param_t *nand_device_params;
} storage_device_t;



extern const int BLOCK_SIZE;
void deviceprogrammer_flash_device_init_data (storage_device_t *storedev);
boolean storageDeviceErase(uint32 start_block,uint32 last_block);
boolean init_storage_device_hw(storage_device_t *storedev);
void init_storage_device_struct(storage_device_t *storedev);

boolean storageDeviceRead(storage_device_t *storedev,
                          byte* buffer,
                    	  uint32 read_type,
                          SIZE_T sector_address,
                          SIZE_T sector_length);
boolean storageDeviceWrite(storage_device_t *storedev,
                           byte* buffer,
                           SIZE_T sector_address,
                           SIZE_T *new_sector_address,
                           SIZE_T sector_length,
                           int *errno);

boolean storageDeviceGetStorageInfo(storage_device_t *storedev);
size_t storageDeviceGetPageSize(storage_device_t *storedev);
size_t storageDeviceGetPagesInBlock(storage_device_t *storedev);
size_t storageDeviceGetTotalPageSize(void);
size_t storageDeviceGetTotalBlockCount(storage_device_t *storedev);
int storageDeviceGetBlockState(uint32 block, enum flash_block_state *block_state);



#endif

