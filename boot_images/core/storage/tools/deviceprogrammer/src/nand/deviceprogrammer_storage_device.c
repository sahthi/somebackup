/*==================================================================
 *
 * FILE:        deviceprogrammer_storage_device.c
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
 *   $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/deviceprogrammer/src/nand/deviceprogrammer_storage_device.c#1 $
 *   $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $
 *
 * YYYY-MM-DD   who     what, where, why
 * ----------   ---     ----------------------------------------------
 * 2014-03-03   dks     Added MMC FFU Support
 * 2013-07-15   ah      Removed warning
 * 2013-06-03   ah      Added legal header
 * 2013-05-31   ab      Initial checkin
 */
#include "../nand/deviceprogrammer_firehose.h"
#include "deviceprogrammer_storage_device.h"
#include "DalDevice.h"
#include "DALDeviceId.h"
#include "../../../../flash/tools/src/nand/nand_core.h"
#include "../../../../flash/tools/src/nand/nand_wrapper.h"
//#include "../../../../flash/tools/src/nand/nand_tools.h"


//static const int BLOCK_SIZE = 512;


extern struct parti_ctl mibib;
extern firehose_protocol_t fh;
extern flash_prog_img_prg_table_t flash_prog_function_tbl;
//--------------------------------------------------------------------------
// Type Declarations
//--------------------------------------------------------------------------

//extern probe_code_type flash_dev_type;
//flash_dev_type = FLASH_DEVICE_NOT_PROBED;
probe_code_type flash_dev_type = FLASH_DEVICE_NOT_PROBED;


//extern flash_param_t *nand_device_params;
//flash_param_t *nand_device_params;




size_t storageDeviceGetPageSize(storage_device_t *storedev) {
    return storedev->nand_device_params->page_size;
}

size_t storageDeviceGetPagesInBlock(storage_device_t *storedev) {
    return storedev->nand_device_params->pages_in_block;
}

size_t storageDeviceGetTotalBlockCount(storage_device_t *storedev) {
	return storedev->nand_device_params->num_blocks;
}

size_t storageDeviceGetTotalPageSize()
{
	parti_ctl_t pctl = &mibib;

	if (pctl->flash_handle == NULL)
	{
		  if (FLASH_DEVICE_DONE == flash_get_info(pctl->flash_handle,
			FLASH_DEVICE_INFO, &pctl->flash_info))
		  {
			debugMessage("Device Initialization: flash_get_info successful");
			return pctl->flash_info.partition.total_page_size_bytes;
		  }
		  else
		  {
			logMessage("- flash_get_info error");
			//SET_ERR (ERR_DEV_MISSING);
			return FLASH_PROG_FAIL;
		  }

	}
	else
	{
		return pctl->flash_info.partition.total_page_size_bytes;

	}


}

int storageDeviceGetBlockState(uint32 block, enum flash_block_state *block_state){

		return flash_block_get_state(mibib.flash_handle,block,block_state);
}


/*===========================================================================

  This function erases flash blocks starting from start_block till last_block
===========================================================================*/

boolean storageDeviceErase(uint32 start_block,uint32 last_block) {

int blockno;
int erase_result_data;
struct flash_block_vector block_vector;
enum flash_block_state blk_state;
int total_num_blocks = -1;


total_num_blocks = storageDeviceGetTotalBlockCount(&fh.store_dev);

if(total_num_blocks == 0 || total_num_blocks == -1)
{
	return FALSE;

}

if(start_block > total_num_blocks || last_block > total_num_blocks) {
	logMessage("Block erase request exceeding total number of blocks");
	logMessage("start_block:%d,last_block:%d,total_block_count:%d",start_block,last_block,total_num_blocks);
	return FALSE;

}

/* Open the device if it has not already been opened */
debugMessage ("Probing flash device:");

/* Probe will fill values in structure if it succeeds.
  * Currently, which_flash parameter is hard coded to 0, but in
  * future this will be dynamic.
  */
flash_prog_init_for_partition_image(&mibib, "0:ALL");

if(mibib.flash_handle ==  NULL)
{
	logMessage ("Flash probing failed");
	return FALSE;

}

for (blockno=start_block; blockno<last_block;
  blockno++)
{
  //KICK_WATCHDOG();

  if (DAL_SUCCESS != flash_block_get_state(mibib.flash_handle, blockno,
	&blk_state))
  {
  	logMessage("Failed to gather block state");
	return FALSE;
  }

  if (blk_state == FLASH_BLOCK_BAD)
  {
	logMessage("Skipping:	bad block 0x%x", blockno);
	continue;
  }
  else
  {
	debugMessage("Erasing good block 0x%x", blockno);

  }

  /* erase the block */
  block_vector.start_block = blockno;
  block_vector.block_count = 1;
  block_vector.result_vector = &erase_result_data;

  if (DAL_SUCCESS != flash_erase_blocks(mibib.flash_handle, &block_vector, 1))
  {
	 logMessage("--- Error: device failed during erase of block 0x%x",blockno);

	/* Skip erase failures on block 0, which may be due to OTP protection */
	if (blockno == 0)
	{
	  logMessage("\nSkipping erase failure at block 0x%x", blockno);
	  continue;
	}

	if ((blockno % 512) == 0)
	  {
		 block_vector.block_count = blockno % 512;
	  }

	return FALSE;
  }
}


return TRUE;

}

void deviceprogrammer_flash_device_init_data (storage_device_t *storedev){
	flash_prog_status_t result;

	flash_dev_type = FLASH_DEVICE_NOT_PROBED;

	result = (*flash_prog_function_tbl.get_flash_param)(
		(void *)&(storedev->nand_device_params));


	if (FLASH_PROG_SUCCESS == result)
	{
	  flash_dev_type = FLASH_DEVICE_FOUND;
	  //logmessage("fdid: Flash paramaters retrieved successfully");
	}
	else
	{
	  flash_dev_type = FLASH_DEVICE_UNKNOWN;
	 // FLASHLOG(1, ("fdid: Failure retrieving flash paramaters\n"));
	}

	return;



}


char * storage_device_name(storage_device_t *storedev)
{
   char *storage_name={"nand"};
   return storage_name;
}
#if 0
boolean init_storage_device_hw(storage_device_t *storedev) {
   /* SDCC_STATUS rc;
    int i;
    sdcc_mem_info_type mem_info;

    for (i = PARTITION_EMMC_USER; i < PARTITION_EMMC_NONE; i++) {
        if (i != PARTITION_EMMC_RPMB) {
            //FREEZE_WATCHDOG();
            storedev->hsdev_partition_handles[i] = sdcc_handle_open (
                                                       storedev->drivenum,
                                                       i);
            if (i == PARTITION_EMMC_USER) {
                if (storedev->hsdev_partition_handles[i] == NULL) {
                    storedev->hsdev_partition_handles[i] = sdcc_handle_open (
                                                                storedev->drivenum,
                                                                i);
                    if (storedev->hsdev_partition_handles[i] == NULL)
                        return FALSE;
                }

                rc = sdcc_handle_mem_get_device_info(storedev->hsdev_partition_handles[i], &mem_info);
                if (rc != SDCC_NO_ERROR)
                    return FALSE;
                if (mem_info.card_size_in_sectors > 0)
                    storedev->sector_size = mem_info.block_len;
            }

        }
    }

    //FREEZE_WATCHDOG();
    // TODO: Can we ignore the return value of this call ?
    rc = sdcc_handle_set_active_bootable_partition(
            storedev->hsdev_partition_handles[PARTITION_EMMC_USER]);
    if (rc != SDCC_NO_ERROR) {

    }*/
    return TRUE;
}
/*
static boolean
deinit_storage_device_hw(storage_device_t *storedev, int *errno) {
 SDCC_STATUS rc;
    uint32 i;

    for (i = PARTITION_EMMC_USER; i < PARTITION_EMMC_NONE; i++) {
        if (storedev->hsdev_partition_handles[i] != NULL)   {
            rc = sdcc_handle_close (storedev->hsdev_partition_handles[i]);
            if (rc != SDCC_NO_ERROR)  {
                if (*errno != NULL)
                    *errno = rc;
                return FALSE;
            }
        }
        storedev->hsdev_partition_handles[i] = NULL;
    }

    rc = SDCC_NO_ERROR; // HACK - until SD code is updated
    //rc = sdcc_deinit_device (0);
    if (rc != SDCC_NO_ERROR)  {
        if (*errno != NULL)
            *errno = rc;
        return FALSE;
    }

    return TRUE;
}*/


boolean storage_device_open_partition(storage_device_t *storedev, byte partition) {
   /* sdcc_mem_info_type mem_info;
    SDCC_STATUS rc;
	*/
   // if (/* partition < (byte) PARTITION_EMMC_USER || */
      /*  partition >= (byte) PARTITION_EMMC_NONE ||
        partition == (byte) PARTITION_EMMC_RPMB)
        return FALSE;

    rc = sdcc_handle_mem_get_device_info(storedev->hsdev_partition_handles[0], &mem_info);
    if (rc != SDCC_NO_ERROR)
        return FALSE;

    if (partition > mem_info.num_phy_partition_created - 1)
        return FALSE;

    storedev->current_open_partition = (open_partition_type)partition;*/
    return TRUE;
}

boolean storageDeviceClosePartition(storage_device_t *storedev) {
   /* if (storedev->current_open_partition == PARTITION_EMMC_NONE)
        return FALSE;
    storedev->current_open_partition = PARTITION_EMMC_NONE;*/
    return TRUE;
}

boolean storageDeviceSetBootableStorageDrive(storage_device_t *storedev) {
    /*SDCC_STATUS rc;
    struct sdcc_device *hsdev_handle =
        storedev->hsdev_partition_handles[storedev->current_open_partition];

    if (hsdev_handle == NULL)
        return FALSE;

    rc = sdcc_handle_set_active_bootable_partition(hsdev_handle);
    if (rc != SDCC_NO_ERROR) {
        return FALSE;
    }*/
    return TRUE;
}

boolean storageDeviceCreateStorageDrives(storage_device_t *storedev,
                               SIZE_T *drive_sector_sizes,
                               SIZE_T array_length) {
    /*SDCC_STATUS rc = SDCC_NO_ERROR;
    sdcc_emmc_gpp_enh_desc_type desc;
    SIZE_T i;
    struct sdcc_device *hsdev_handle =
        storedev->hsdev_partition_handles[storedev->current_open_partition];

    if (hsdev_handle == NULL)
        return FALSE;

    // Fill out as many values as we can
    for (i = 0; i < MIN(array_length, 4); i++) {
        desc.GPP_size[i] = drive_sector_sizes[i];
    }

    // Fill the rest with zeros
    for (; i < 4; i++) {
        desc.GPP_size[i] = drive_sector_sizes[i];
    }

    desc.ENH_size = 0;
    desc.ENH_start_addr = 0;
    desc.GPP_enh_flag = 0;
    logMessage("gpp1 %d gpp2 %d gpp3 %d gpp4 %d.",
               desc.GPP_size[0],
               desc.GPP_size[1],
               desc.GPP_size[2],
               desc.GPP_size[3]);

    rc = sdcc_config_emmc_gpp_enh (hsdev_handle, &desc);
    if (rc != SDCC_NO_ERROR) {
        return FALSE;
    }*/
    return TRUE;
}
#endif

boolean storageDeviceGetStorageInfo(storage_device_t *storedev)
{

  uint32 block_no=0;
  uint32 bad_block_count =0;
  enum flash_block_state block_state;

  bsp_kick_wdog();

  logMessage("[FLASH_INFO]");
  logMessage(";This section provides flash info");
  logMessage("FLASH_NAME=%s", storedev->nand_device_params->flash_name);
  logMessage("SECTOR_SIZE_IN_BYTES = %d", storedev->nand_device_params->page_size);
  logMessage("NUM_PARTITION_SECTORS = %d", storedev->nand_device_params->pages_in_block*storedev->nand_device_params->num_blocks);
  logMessage("num_physical_partitions = 1");
  logMessage("TOTAL_SECTOR_SIZE_IN_BYTES= %d", storageDeviceGetTotalPageSize());
 // logMessage("PAGES_IN_BLOCK = %d", storedev->nand_device_params->pages_in_block);
 // logMessage("TOTAL_BLOCK_COUNT= %d", storedev->nand_device_params->num_blocks);

  logMessage("\n");
  logMessage("[BAD_BLOCK_LIST]");
  logMessage(";This section provides bad block list");

  for (block_no =0;block_no < storedev->nand_device_params->num_blocks ; block_no++)
  {
  		storageDeviceGetBlockState(block_no, &block_state);
		if (FLASH_BLOCK_BAD == block_state)
		{
			logMessage("BAD_BLOCK=%d",block_no);
			bad_block_count += 1;
		}
  }
  logMessage("TOTAL_BAD_BLOCK=%d",bad_block_count);

  return TRUE;
}

#if TARGET_HAS_EMMC 
SIZE_T storageDeviceGetPartitionSizeSectors(storage_device_t *storedev) {
    SDCC_STATUS rc;
    sdcc_mem_info_type mem_info;
    struct sdcc_device *hsdev_handle =
        storedev->hsdev_partition_handles[storedev->current_open_partition];

    if (hsdev_handle == NULL)
        return FALSE;

    rc = sdcc_handle_mem_get_device_info(hsdev_handle, &mem_info);
    if (rc != SDCC_NO_ERROR) {
        return FALSE;
    }
    return mem_info.card_size_in_sectors;

	return 0;
}

SIZE_T storageDeviceGetLowerBoundSector(storage_device_t *storedev) {

    return 0;
}

SIZE_T storageDeviceGetUpperBoundSector(storage_device_t *storedev) {

	return 0xFFFFFFFF;  
#endif

boolean storageDeviceRead(storage_device_t *storedev,
                          byte* buffer,
                    	  uint32 read_type,
                          SIZE_T sector_address,
                          SIZE_T sector_length
                          ) {


int result = FLASH_DEVICE_DONE;
SIZE_T page_count = 0;
byte* current_page;
SIZE_T sector_size_in_bytes;

if(read_type == FLASH_READ_RAW || read_type == FLASH_READ_MAIN_SPARE)
{
	sector_size_in_bytes = storageDeviceGetTotalPageSize();
}
else
{
	sector_size_in_bytes = storageDeviceGetPageSize(&fh.store_dev);
}
bsp_kick_wdog();

while(sector_length > 0)
{

	current_page = (byte * )(buffer + (page_count * sector_size_in_bytes));
	result = flash_prog_read_page(mibib.flash_handle, &mibib.flash_info,
	  sector_address+page_count, read_type, current_page);

	if (FLASH_DEVICE_DONE != result)
    {
      if(FLASH_DEVICE_FAIL_PAGE_ERASED == result)
      {
	      memset(current_page,NAND_FILL_CHAR,sector_size_in_bytes);
		  sector_length -= 1;
		  page_count += 1;
		  result = FLASH_DEVICE_DONE;
      }
      else
      {
      	result = FLASH_DEVICE_FAIL;
  	  	break;
      }
    }
	else
	{
		sector_length -= 1;
		page_count += 1;
	}

}
return (result == FLASH_DEVICE_DONE) ? TRUE : FALSE;


}

boolean storageDeviceWrite(storage_device_t *storedev,
                           byte* buffer,
                           SIZE_T sector_address,
                           SIZE_T *new_sector_address,
                           SIZE_T sector_length,
                           int *errno)
{

	int result = 0;
	enum flash_block_state block_state;

	if (NULL != errno)
		   *errno = 0;

   	bsp_kick_wdog();

	flash_prog_init_for_partition_image(&mibib, "0:ALL");

	if(mibib.flash_handle ==  NULL)
	{
		logMessage ("Flash probing failed");
		return FALSE;

	}

	mibib.current_block = sector_address / mibib.flash_info.partition.pages_per_block;
	mibib.current_page = sector_address;

	if(sector_address % mibib.flash_info.partition.pages_per_block == 0)
		mibib.avail_pages_in_block = mibib.flash_info.partition.pages_per_block;
	else
		mibib.avail_pages_in_block =  sector_address % mibib.flash_info.partition.pages_per_block;


	result = flash_prog_write_current_page(&mibib, (unsigned char *)buffer, NULL);
	if (FLASH_DEVICE_DONE != result) {
	  logMessage("flash write failed at sector address %lld till %lld",sector_address,mibib.current_page);
	  return FALSE;
	}

	/* check if current page has changed
	 * if it has then we need to bump the start_address*/
	*new_sector_address = mibib.current_page;


	return TRUE;

}


#if TARGET_HAS_EMMC 
boolean storageDeviceFWUpdate(storage_device_t *storedev,
                              byte* fw_bin,
                              SIZE_T num_sectors,
                              int *errno)
{
	return TRUE;
}


boolean storage_device_disk_write(storage_device_t *storedev, byte* buffer, uint32 address, uint32 length) {

    return TRUE;
}

boolean storageDeviceSetExtras(storage_device_t *storedev,
                            const char* attribute_name,
                            const char* attribute_value) {
    return TRUE;
}

void storageDeviceGetExtras(storage_device_t *storedev) {

}

boolean storageDeviceExtrasCommit(storage_device_t *storedev,
                                  int *errno) {

    return TRUE;
}
#endif
