 /*****************************************************************************
 * ufs_api.c
 *
 * UFS device driver - public API
 *
 * This file implements the top level UFS driver APIs 
 *
 * Copyright (c) 2012-2013 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 *
 *****************************************************************************/
/*=============================================================================
                        Edit History

$Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/ufs_api.c#1 $
$DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $

when         who     what, where, why
----------   ---     ---------------------------------------------------
2013-09-13   bb      Workaround for bringup - to return error if UFS is not boot device
2013-09-10   rh      Get the device descriptor first prior to open LUs
2013-09-09   rh      Enable setting of the bRefClkFreq
2013-08-12   rh      LU size calculation is not correct
2012-12-18   rh      Initial creation
=============================================================================*/

#include "stdint.h"
#include "ufs_api.h"
#include "ufs_memory.h"
#include "ufs_errno.h"
#include <string.h>

// Allocate an array to hand out handles
#define MAX_UFS_OPEN_HANDLES        20
#define UFS_HANDLE_MAGIC_ID         0x105189ab
#define UFS_INUSE_TRUE              0xF0

ufs_handle_t ufs_handle_array[MAX_UFS_OPEN_HANDLES];

// Find the next free handle and allocate
static ufs_handle_t *ufs_get_handle ()
{
   uint32_t i;
   for (i = 0; i < MAX_UFS_OPEN_HANDLES; i++) {
      if (ufs_handle_array[i].is_inuse) {
         continue;
      }
      else {
         // Set the inuse flag in the handle
         ufs_handle_array[i].is_inuse = UFS_INUSE_TRUE;
         ufs_handle_array[i].id_magic = UFS_HANDLE_MAGIC_ID;
         return &ufs_handle_array[i];
      }
   }
   // Running out of handles, return NULL
   return NULL;
}


// Free the inuse handle
static void ufs_free_handle (ufs_handle_t *handle)
{
   handle->is_inuse = 0;
   handle->id_magic = 0;
}


/* Public API */
struct ufs_handle *ufs_open (uint32_t core_id, uint32_t lun)
{
   int32_t rc = EOK;
   uint16_t boot_cfg = 0;
   ufs_handle_t *hufs;

   /********************************************************
    WROK AROUND FOR 8084 BRINGUP - TO BE REMOVED
	HOTPLUG PROBES UFS DEVICE EVEN IN EMMC BOOT
	WILL REMOVE WHEN HOTPLUG IS READY WITH THE SOLUTION PROPOSED
	WORKAROUND STARTS HERE
	********************************************************/
   boot_cfg = *((uint16_t *) 0xFC4BE034);
   boot_cfg = (boot_cfg & 0x3E) >> 1;
   
   if (boot_cfg != 4) 
   {
     return NULL;
   }

   /********************************************************
 	WORKAROUND ENDS HERE
	********************************************************/   
   // Only a single core is supported 
   if (core_id != 0) {
      return NULL;
   }

   // First get a free handle
   hufs = ufs_get_handle();
   if (hufs == NULL) {
      // Out of available handles
      return NULL;
   }

   // Set the LUN used
   hufs->lun = lun;

   // Call memory initialization
   rc = ufs_mem_init(hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   // Wait until device is responding to NOP UPIU
   rc =  ufs_wait_device_awake (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   // Check to see if the device has fDeviceInit set, if not, set it
   rc = ufs_set_fDeviceInit (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   // Get the default device descriptor
   rc = ufs_get_descriptor_device (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   // Do not check for the DEVICE WLUN
   if (lun != UFS_WLUN_DEVICE) {
      // Check to make sure the LUN is a valid LUN 
      rc = ufs_check_valid_lun (hufs, lun & 0xff);
      if (rc != EOK) {
         ufs_free_handle (hufs);
         return NULL;
      }
   }
   
   // Start up here, send a TEST_UNIT_READY to 
   // make sure the LUN is available
   rc = ufs_scsi_unit_rdy (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   rc = ufs_scsi_inquiry (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   rc = ufs_get_descriptor_config (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   // Do not get the unit descriptor for the DEVICE WLUN
   if (lun != UFS_WLUN_DEVICE) {
      rc = ufs_get_descriptor_unit (hufs, lun);
      if (rc != EOK) {
         ufs_free_handle (hufs);
         return NULL;
      }
   }

   rc = ufs_get_bBootLunEn (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   rc = ufs_get_descriptor_geometry (hufs);
   if (rc != EOK) {
      ufs_free_handle (hufs);
      return NULL;
   }

   return hufs;
}


/* Public API */
int32_t ufs_close (struct ufs_handle *handle)
{
   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   ufs_free_handle (handle);
   return EOK;
}


/* Public API */
int32_t ufs_get_device_info (struct ufs_handle *handle, 
                             struct ufs_info_type *info)
{
   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }
   
   memset (info, 0, sizeof (struct ufs_info_type));
   ufs_fill_in_device_info (handle, info);

   // Calculate the LU size in allocation blocks
   info->dLuTotalBlocks = info->bAllocationUnitSize * info->dNumAllocUnits 
                        * info->dSegmentSize / info->bMinAddrBlockSize;

   return EOK;
}


/* Public API */
int32_t ufs_configure_device( struct ufs_handle *handle, 
                              struct ufs_config_descr *cfg )
{
   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   return ufs_do_config_device (handle, cfg);
}


/* Public API */
int32_t ufs_set_bootable (struct ufs_handle *handle, uint32_t lun)
{
   int32_t rc = EOK;
   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   // Allow only LUN 0 - Disable, 1 - Boot A or 2 - Boot B
   if (lun > UFS_LUN_BOOT_B) {
      return -EINVAL;
   }  

   // Set the boot enable flag in the attributes bBootLunEn
   rc = ufs_set_bBootLunEn (handle, lun);
   if (rc != EOK) {
      return -EIO;
   }

   return rc;
}


/* Public API */
int32_t ufs_set_pon_write_protect (struct ufs_handle *handle)
{
   int32_t rc = EOK;

   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   rc = ufs_set_fPowerOnWPEn (handle);
   return rc;
}


/* Public API */
int32_t ufs_read (struct ufs_handle *handle,
                  uint8_t           *buff,
                  uint64_t           lba,
                  uint32_t           blocks)
{
   int32_t rc = EOK;

   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   // Call the SCSI command building function
   rc = ufs_scsi_read (handle, buff, lba, blocks);
   return rc;
}


/* Public API */
int32_t ufs_write (struct ufs_handle *handle,
                   uint8_t           *buff,
                   uint64_t           lba,
                   uint32_t           blocks)
{
   int32_t rc = EOK;
   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   // Call the SCSI command building function
   rc = ufs_scsi_write (handle, buff, lba, blocks);
   return rc;
}


/* Public API */
int32_t ufs_erase (struct ufs_handle *handle,
                   uint64_t           lba,
                   uint32_t           blocks)
{
   int32_t rc = EOK;
   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   // Call the SCSI command building function
   rc = ufs_scsi_unmap (handle, lba, blocks);
   return rc;
}


/* For Tools debugging, get device descriptor string */
/* Public API */
int32_t ufs_get_device_info_str (struct ufs_handle *handle,
                                 uint32_t           id,
                                 char              *buf,
                                 uint32_t           size)
{
   int32_t rc = EOK;
   // Check input parameter
   if (handle == NULL || buf == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   // Call the SCSI command building function
   rc = ufs_get_descriptor_str (handle, id, buf, size);
   return rc;
}

int32_t ufs_set_refclk_freq( struct ufs_handle *handle, 
                             uint32_t           freq)
{
   int32_t rc = EOK;
   // Check input parameter
   if (handle == NULL) {
      return -EINVAL;
   }

   // Check inuse flag
   if (handle->is_inuse != UFS_INUSE_TRUE ||
       handle->id_magic != UFS_HANDLE_MAGIC_ID) {
      return -EINVAL;
   }

   // Make sure the host controlle interface is ready
   if (handle->phc == NULL) {
      return -EINVAL;
   }

   // Default clock is 19.2MHz
   if (freq == 0) {
      freq = 19200000;
   }

   // All current board design support 19.2MHz reference clock only
   if (freq != 19200000) {
      return -EINVAL;
   }


   // Set the bRefClkFreq
   rc = ufs_set_bRefClkFreq (handle, freq);

   return rc;
}

