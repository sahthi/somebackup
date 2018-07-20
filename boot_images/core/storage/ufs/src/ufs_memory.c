/**********************************************************************
 *
 * UFS memory layer - 
 * Main UFS memory interface layer, contain the code to initialize
 * a UFS memory device, formation of SCSI command to read/write to 
 * memory device and decoding device descriptor strings
 * This layer work on the data structures to read/write data or to 
 * get the device descriptor
 *
 * Copyright (c) 2012-2013 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 *
 **********************************************************************/

/*======================================================================

                        EDIT HISTORY FOR MODULE

  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/ufs_memory.c#1 $
  $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $

when         who     what, where, why
----------   ---     ---------------------------------------------------
2013-09-09   rh      Adding a bitfield to indicate which LUN is enabled
2013-09-05   rh      Fix a translation mistake on WLUN BOOT ID 
2013-09-04   rh      Adding enhanced area capacity adjustment factor
2013-09-03   rh      Add more debug message
2013-08-20   rh      64k limitation should be block, not byte
2013-08-12   rh      Unit descriptor is one byte short
2013-01-10   rh      Initial creation
=======================================================================*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ufs_api.h"
#include "ufs_memory.h"
#include "ufs_core.h"
#include "ufs_errno.h"
#include "ufs_utp_core.h"

// Define the number of HCI controller
// Current hardware only have one UFS HCI
#define MAX_UFS_HCI_ID              1
#define MAX_UFS_NOP_PING_RETRY      10       // How many time to retry the NOP UPIU
#define MAX_UFS_WAIT_DEV_INIT_FLAG  100

// RPMB message specific defines
#define RPMB_MSG_SIZE               512
#define RPMB_SECTOR_SIZE            256

// Use a static buffer for storage of RPMB messages
static uint8_t rpmb_msg_buf[RPMB_MSG_SIZE];

ufs_host_t ufs_host_info_array[MAX_UFS_HCI_ID]; 
#define UFS_DESCRIPTOR_BUF_SIZE        256
static uint8_t ufs_is_inited = 0;            // Has the system been intialized?

// Some helper macro
#define GET_PHYADDR(x) ((uint64_t)x)

int32_t ufs_mem_init (struct ufs_handle *hufs)
{
   ufs_host_t *hba;
   int32_t rc = EOK;

   // Check the validation of the core
   if (hufs == NULL) {
      return -ENODEV;
   }

   if (hufs->ufs_core_id >= MAX_UFS_HCI_ID) {
      return -ENODEV;
   }

   hba = &ufs_host_info_array[hufs->ufs_core_id];
   hba->ufs_core_id = hufs->ufs_core_id;

   // Do card detection and init if UFS driver have not gone through 
   // the init process
   if (!ufs_is_inited) {
      // Clear the device info array
      memset (ufs_host_info_array, 0, sizeof(ufs_host_t) * MAX_UFS_HCI_ID);
      ufs_is_inited = 1;
   }

   if (!hba->is_initialized) {
      // Call BSP for initialization of Phy
      
      // Call init for UTP layer
      rc = ufs_utp_init (hba);

      // Get the device info structure and update SCM transfer handle
      hba->is_initialized = 1;
   }

   hufs->phc = hba;

   return rc;
}


int32_t ufs_scsi_read (struct ufs_handle *hufs, uint8_t *buf, 
                       uint32_t lba, uint32_t blocks)
{
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   int32_t rc = EOK;
   ufs_host_t *hba;

   // Maximum size of transfer supported by CMD_READ 10 is 16k blocks
   if (blocks > 65535) {
      return -EINVAL;
   }

   // Fill in the CDB with SCSI command structure
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_READ10;        // Command
   cdb[1] = 0;    
   cdb[2] = (lba >> 24) & 0xff;     // LBA
   cdb[3] = (lba >> 16) & 0xff;
   cdb[4] = (lba >> 8) & 0xff;
   cdb[5] = (lba) & 0xff;
   cdb[6] = 0;    // Group Number
   cdb[7] = (blocks >> 8) & 0xff;   // Transfer Len
   cdb[8] = (blocks) & 0xff;  
   cdb[9] = 0;                      // Control

   hba = hufs->phc;
   req.phc = hufs->phc;
   req.lun = hufs->lun;
   req.flags = UFS_XFER_FLAGS_READ;
   req.expected_len = blocks * DEFAULT_SECTOR_SIZE;
   req.data_buf_phy = (uint64_t)buf;      // Address of the destination buffer

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0280);
      return rc;
   }

   // Verify SCSI transfer status
   hufs->phc->last_scsi_status = req.status;
   if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x0281);
      return -EIO;
   }

   return rc;
}


int32_t ufs_scsi_write (struct ufs_handle *hufs, uint8_t *buf, 
                        uint32_t lba, uint32_t blocks)
{
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   int32_t rc = EOK;
   ufs_host_t *hba;

   // Maximum size of transfer supported by CMD_READ 10 is 16k blocks
   if (blocks > 65535) {
      return -EINVAL;
   }

   // Fill in the CDB with SCSI command structure
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_WRITE10;       // Command
   cdb[1] = SCSI_FLAG_FUA;          // flags
   cdb[2] = (lba >> 24) & 0xff;     // LBA
   cdb[3] = (lba >> 16) & 0xff;
   cdb[4] = (lba >> 8) & 0xff;
   cdb[5] = (lba) & 0xff;
   cdb[6] = 0;                      // Group Number
   cdb[7] = (blocks >> 8) & 0xff;   // Transfer Len
   cdb[8] = (blocks) & 0xff;  
   cdb[9] = 0;                      // Control

   hba = hufs->phc;
   req.phc = hufs->phc;
   req.lun = hufs->lun;
   req.flags = UFS_XFER_FLAGS_WRITE;
   req.expected_len = blocks * DEFAULT_SECTOR_SIZE;
   req.data_buf_phy = (uint64_t)buf;      // Address of the source buffer

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0284);
      return rc;
   }

   // Verify SCSI transfer status
   hufs->phc->last_scsi_status = req.status;
   if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x0285);
      return -EIO;
   }

   return rc;
}


int32_t ufs_scsi_unmap (struct ufs_handle *hufs, 
                        uint32_t lba, uint32_t blocks)
{
   uint8_t cdb[16];
   uint8_t param[24];               // Unmap parameter list, 1 item used only
   ufs_cmd_req_t req;
   int32_t rc = EOK;
   ufs_host_t *hba;

   // Create the parameter list with a single entry
   memset (param, 0, sizeof(param));
   param[0] = 0;                       // n = 24
   param[1] = 23;                      // n - 1
   param[2] = 0;                       // n - 7
   param[3] = 16;                      // n - 7
   param[8]  = (lba >> 24) & 0xff;     // LBA
   param[9]  = (lba >> 16) & 0xff;
   param[10] = (lba >> 8) & 0xff;
   param[11] = (lba) & 0xff;
   param[12] = (blocks >> 24) & 0xff;  // Blocks
   param[13] = (blocks >> 16) & 0xff;
   param[14] = (blocks >> 8) & 0xff;
   param[15] = (blocks) & 0xff;

   // Fill in the CDB with SCSI command structure
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_UNMAP;         // Command
   cdb[1] = 0;                      // Anchor
   cdb[6] = 0;                      // Group Number
   cdb[7] = 0;                      // Transfer Len = n
   cdb[8] = 24;      
   cdb[9] = 0;                      // Control

   hba = hufs->phc;
   req.phc = hufs->phc;
   req.lun = hufs->lun;
   req.flags = UFS_XFER_FLAGS_WRITE;
   req.expected_len = 24;
   req.data_buf_phy = GET_PHYADDR(param);    // Address of the param buffer

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0288);
      return rc;
   }

   // Verify SCSI transfer status
   hufs->phc->last_scsi_status = req.status;
   if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x0289);
      return -EIO;
   }

   return rc;
}

int32_t ufs_scsi_write_buf (struct ufs_handle *hufs, uint8_t *buf, 
									 uint8_t mode, uint8_t buf_id, 
									 uint32_t offset, uint32_t len)
{
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   int32_t rc = EOK;
   ufs_host_t *hba;

   // SCSI write buffer command has a limit on block size of up to 2^24 bytes
   if (len > 0xffffff) {
      return -EINVAL;
   }

   // Fill in the CDB with SCSI command structure
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_WRITE_BUFFER;  // Command
   cdb[1] = mode;
   cdb[2] = (offset >> 16) & 0xff;
   cdb[3] = (offset >> 8) & 0xff;
   cdb[4] = (offset) & 0xff;			// Transfer Offset
   cdb[6] = (len >> 16) & 0xff;  
   cdb[7] = (len >> 8) & 0xff;   
   cdb[8] = (len) & 0xff;        // Transfer Len
   cdb[9] = 0;                      // Control

   hba = hufs->phc;
   req.phc = hufs->phc;
   req.lun = hufs->lun;
   req.flags = UFS_XFER_FLAGS_WRITE;
   req.expected_len = len;
   req.data_buf_phy = (uint64_t)buf;      // Address of the source buffer

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0294);
      return rc;
   }

   // Verify SCSI transfer status
   hufs->phc->last_scsi_status = req.status;
   if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x0295);
      return -EIO;
   }

   return rc;
}


// Test Unit Ready command
int32_t ufs_scsi_unit_rdy (struct ufs_handle *hufs)
{
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   int32_t rc = EOK;
   ufs_host_t *hba;

   // Fill in the CDB with SCSI command structure
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_TEST_UNIT_RDY; // Command
   cdb[9] = 0;                      // Control

   hba = hufs->phc;
   req.phc = hufs->phc;
   req.lun = hufs->lun;
   req.flags = 0;                // No data transfer expected
   req.expected_len = 0;
   req.data_buf_phy = 0;      // Address of the param buffer

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x028c);
      return rc;
   }

   // Verify SCSI transfer status
   hufs->phc->last_scsi_status = req.status;
   if (req.status == SCSI_STATUS_BUSY) {
      ufs_error_log(hba, 0x028d);
      return -EBUSY;
   }
   else if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x028e);
      return -EIO;            // TODO: Use a different return if the device is busy?
   }

   return rc;
}


// Get list of active LUNs
int32_t ufs_scsi_inquiry (struct ufs_handle *hufs)
{
   uint8_t cdb[16];
   uint8_t param[96];
   ufs_host_t *hba;
   ufs_cmd_req_t req;
   int32_t rc = EOK;

   hba = hufs->phc;

   if (hba->has_scsi_inquiry) {
      return EOK;
   }

   // Create the parameter list with a single entry
   memset (param, 0, sizeof(param));

   // Fill in the CDB with SCSI command structure
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_INQUIRY; // Command
   cdb[1] = 0;                      // EVPD
   cdb[3] = 0;                      // Pagecode
   cdb[4] = sizeof(param);          // Transfer Len = param array size
   cdb[5] = 0;                      // Control

   req.phc = hufs->phc;
   req.lun = hufs->lun;
   req.flags = UFS_XFER_FLAGS_READ;
   req.expected_len = sizeof(param);
   req.data_buf_phy = GET_PHYADDR(param);    // Address of the param buffer

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0201);
      return rc;
   }

   // Verify SCSI transfer status
   hba->last_scsi_status = req.status;
   if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x0202);
      return -EIO;
   }

   // Copy the Vendor ID and store it
   memcpy (hba->inquiry_vid, param + 8, 27);
   hba->has_scsi_inquiry = 1;
   
   return rc;
}


int32_t ufs_check_valid_lun (struct ufs_handle *hufs, uint8_t lun)
{
   ufs_host_t *hba = hufs->phc;
   // Check the list of enabled LUs
   if (hba->lun_enable[lun]) {
      return EOK;
   }
   // Check the default always enabled LUs
   if (lun == UFS_WLUN_REPORT ||
       lun == UFS_WLUN_DEVICE  ||
       lun == UFS_WLUN_RPMB) {
      return EOK;
   }
   // If it is boot LU, check to see if the BootLU is enabled
   if (lun == UFS_WLUN_BOOT && hba->dev_cfg.bBootLunEn != 0) {
      return EOK;
   }

   ufs_error_log(hba, 0x0203);
   return -ENOENT;
}


// Get the device descriptor string
int32_t ufs_get_descriptor_str (struct ufs_handle *hufs, uint32_t id,
                                char *buf, uint32_t size)
{
   ufs_attr_req_t req;
   int32_t rc = EOK;
   uint32_t xsize;

   memset (&req, 0, sizeof (ufs_attr_req_t));

   // Limit the read size to 512 bytes
   xsize = size;
   if (xsize > 512) {
      xsize = 512;
   }

   req.phc = hufs->phc;
   req.req_data_len = 0;
   req.req_data_buf = NULL;
   req.resp_data_len = xsize;
   req.resp_data_buf = (uint8_t *)buf;
   req.idn = UFS_DESC_IDN_STRING;
   req.idx = id;

   rc = ufs_read_dev_descriptor (&req);
   return rc;
}

// Get device size, LUN size, Number of LUN activated, store in dev_t 
int32_t ufs_get_descriptor_unit (struct ufs_handle *hufs, uint32_t id)
{
   ufs_host_t *hba;
   ufs_attr_req_t req;
   int32_t rc = EOK;
   uint8_t buf[0x22];
   uint8_t *pt;
   uint64_t qLogicalBlockCount;
   uint32_t dEraseBlockSize;

   // LUN ID can be from 0 to 7 for UFS device
   if (id > 7) {
      return -EINVAL;
   }

   memset (&req, 0, sizeof (ufs_attr_req_t));

   hba = hufs->phc;
   req.phc = hufs->phc;
   req.req_data_len = 0;
   req.req_data_buf = NULL;
   req.resp_data_len = sizeof(buf);
   req.resp_data_buf = buf;
   req.idn = UFS_DESC_IDN_UNIT;
   req.idx = id;

   rc = ufs_read_dev_descriptor (&req);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0210);
      return rc;
   }

   // Check if the content of unit descriptor is reasonable
   if (buf[1] != 0x02) {
      ufs_error_log(hba, 0x0211);
      return -EIO;
   }

   // Record the LUN in use flag and size
   pt = &buf[0xb];
   qLogicalBlockCount =  (uint64_t)*pt++ << 56;
   qLogicalBlockCount |= (uint64_t)*pt++ << 48;
   qLogicalBlockCount |= (uint64_t)*pt++ << 40;
   qLogicalBlockCount |= (uint64_t)*pt++ << 32;
   qLogicalBlockCount |= (uint64_t)*pt++ << 24;
   qLogicalBlockCount |= (uint64_t)*pt++ << 16;
   qLogicalBlockCount |= (uint64_t)*pt++ << 8;
   qLogicalBlockCount |= (uint64_t)*pt++;

   hba->lun_cfg[id].qLogicalBlockCount = qLogicalBlockCount;

   pt = &buf[0x13];
   dEraseBlockSize = *pt++ << 24;
   dEraseBlockSize |= *pt++ << 16;
   dEraseBlockSize |= *pt++ << 8;
   dEraseBlockSize |= *pt++;
   
   hba->lun_cfg[id].dEraseBlockSize = dEraseBlockSize;

   return rc;
}

// Get device descriptor (1st configuration)
int32_t ufs_get_descriptor_device (struct ufs_handle *hufs)
{
   ufs_host_t *hba;
   ufs_attr_req_t req;
   int32_t rc = EOK;
   uint8_t buf[0x20];

   hba = hufs->phc;
   if (hba->has_device_desc) {
      return EOK;
   }

   memset (&req, 0, sizeof (ufs_attr_req_t));
   memset (buf, 0, 0x1C);

   req.phc = hufs->phc;
   req.req_data_len = 0;
   req.req_data_buf = NULL;
   req.resp_data_len = 0x1C;
   req.resp_data_buf = buf;
   req.idn = UFS_DESC_IDN_DEVICE;

   rc = ufs_read_dev_descriptor (&req);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0212);
      return rc;
   }

   // Decode the buffer content
   if (buf[1] != 0x00) {
      // Device descriptor has bDescriptorType of 0x00
      ufs_error_log(hba, 0x0213);
      return -EIO;
   }

   // Record the LUN in use flag and size
   hba->lun_cnt = buf[0x06];
   hba->bBootEnable = buf[0x08];
   hba->bDescrAccessEn = buf[0x09];
   hba->iManufacturerName = buf[0x14];
   hba->iProductName = buf[0x15];
   hba->iSerialNumber = buf[0x16];
   hba->iOemID = buf[0x17];
   hba->wManufacturerID = (buf[0x18] << 8) | buf[0x19];
   hba->has_device_desc = 1;
   return rc;
}


// Get configuration descriptor
int32_t ufs_get_descriptor_config (struct ufs_handle *hufs)
{
   ufs_host_t *hba;
   ufs_attr_req_t req;
   int32_t rc = EOK;
   uint8_t buf[144];
   uint8_t *pt;
   dev_conf_t *p_dev;
   lun_conf_t *p_lun;
   int i;

   hba = hufs->phc;
   if (hba->has_config_desc) {
      return EOK;
   }

   memset (&req, 0, sizeof (ufs_attr_req_t));
   memset (buf, 0xAA, sizeof (buf));

   req.phc = hufs->phc;
   req.req_data_len = 0;
   req.req_data_buf = NULL;
   req.resp_data_len = sizeof(buf);
   req.resp_data_buf = buf;
   req.idn = UFS_DESC_IDN_CONFIGURATION;

   rc = ufs_read_dev_descriptor (&req);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0220);
      return rc;
   }

   // Verify the content of the buffer is configuration descriptor
   if (buf[1] != 0x01) {
      // Configuration descriptor have identifier of 1
      ufs_error_log(hba, 0x0221);
      return -EIO;
   }

   // Decode the device configuration
   pt = &buf[2];
   p_dev = &hba->dev_cfg;
   p_dev->bNumberLU = *pt++;
   p_dev->bBootEnable = *pt++;
   p_dev->bDescrAccessEn = *pt++;
   p_dev->bInitPowerMode = *pt++;
   p_dev->bHighPriorityLUN = *pt++;
   p_dev->bSecureRemovalType = *pt++;
   p_dev->bInitActiveICCLevel = *pt++;
   p_dev->wPeriodicRTCUpdate = *pt++ << 8;
   p_dev->wPeriodicRTCUpdate |= *pt++;

   for (i = 0; i < 8; i++) {
      pt = &buf[0x10 * i + 0x10];
      p_lun = &hba->lun_cfg[i];

      p_lun->bLUEnable = *pt++;
      p_lun->bBootLunID = *pt++;
      p_lun->bLUWriteProtect = *pt++;
      p_lun->bMemoryType = *pt++;
      p_lun->dNumAllocUnits = *pt++ << 24;
      p_lun->dNumAllocUnits |= *pt++ << 16;
      p_lun->dNumAllocUnits |= *pt++ << 8;
      p_lun->dNumAllocUnits |= *pt++;
      p_lun->bDataReliability = *pt++;
      p_lun->bLogicalBlockSize = *pt++;
      p_lun->bProvisioningType = *pt++;
      p_lun->wContextCapabilities = *pt++ << 8;
      p_lun->wContextCapabilities |= *pt++;

      hba->lun_enable[i] = p_lun->bLUEnable;    // Quick access list
   }

   hba->has_config_desc = 1;

   return rc;
}


int32_t ufs_get_descriptor_geometry (struct ufs_handle *hufs)
{
   ufs_host_t *hba;
   ufs_attr_req_t req;
   int32_t rc = EOK;
   uint8_t buf[0x44];

   hba = hufs->phc;
   if (hba->has_geometry_desc) {
      return EOK;
   }

   memset (&req, 0, sizeof (ufs_attr_req_t));

   req.phc = hufs->phc;
   req.req_data_len = 0;
   req.req_data_buf = NULL;
   req.resp_data_len = sizeof(buf);
   req.resp_data_buf = buf;
   req.idn = UFS_DESC_IDN_GEOMETRY;

   rc = ufs_read_dev_descriptor (&req);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0222);
      return rc;
   }

   // Geometry descriptor have identifier of 7
   if (buf[1] != 0x07) {
      ufs_error_log(hba, 0x0223);
      return -EIO;
   }

   // Record the LUN in use flag and size
   hba->dSegmentSize =  (uint32_t)buf[0x10] | 
                        ((uint32_t)buf[0x0f] << 8) | 
                        ((uint32_t)buf[0x0e] << 16) | 
                        ((uint32_t)buf[0x0d] << 24);
   hba->qTotalRawDeviceCapacity =  
           (uint64_t)buf[0x0b] | ((uint64_t)buf[0x0a] << 8) | 
           ((uint64_t)buf[0x09] << 16) | ((uint64_t)buf[0x08] << 24) |
           ((uint64_t)buf[0x07] << 32) | ((uint64_t)buf[0x06] << 40) |
           ((uint64_t)buf[0x05] << 48) | ((uint64_t)buf[0x04] << 56);
   hba->bAllocationUnitSize = buf[0x11];
   hba->bMinAddrBlockSize = buf[0x12];
   hba->bRPMB_ReadWriteSize = buf[0x17];

   hba->wSupportedMemoryTypes = (uint16_t)buf[0x1f] | 
                                ((uint16_t)buf[0x1e] << 8) ;
   hba->dEnhanced1MaxNAllocU =  (uint32_t)buf[0x2f] | 
                                ((uint32_t)buf[0x2e] << 8) | 
                                ((uint32_t)buf[0x2d] << 16) | 
                                ((uint32_t)buf[0x2c] << 24);
   hba->wEnhanced1CapAdjFac = (uint16_t)buf[0x31] | 
                              ((uint16_t)buf[0x30] << 8) ;
   hba->dEnhanced2MaxNAllocU =  (uint32_t)buf[0x35] | 
                                ((uint32_t)buf[0x34] << 8) | 
                                ((uint32_t)buf[0x33] << 16) | 
                                ((uint32_t)buf[0x32] << 24);
   hba->wEnhanced2CapAdjFac = (uint16_t)buf[0x37] | 
                              ((uint16_t)buf[0x36] << 8) ;

   hba->has_geometry_desc = 1;

   return rc;
}


// Wait until device is responding to NOP UPIU pings
int32_t ufs_wait_device_awake (struct ufs_handle *hufs)
{
   ufs_attr_req_t req;
   int32_t rc = EOK;
   int32_t i;

   memset (&req, 0, sizeof (ufs_attr_req_t));
   req.phc = hufs->phc;

   for (i = 0; i < MAX_UFS_NOP_PING_RETRY; i++) {
      // Ping using NOP_OUT UPIU each try
      rc = ufs_send_nop_ping (&req);
      if (rc == EOK) {
         return rc;
      }
   }
   
   ufs_error_log(req.phc, 0x0228);
   return rc;
}

// Get the bBootLunEn field in the attributes
int32_t ufs_get_bBootLunEn (struct ufs_handle *hufs)
{
   ufs_attr_req_t req;
   int32_t rc = EOK;

   if (hufs->phc->has_boot_en_attr) {
      return EOK;
   }

   req.phc = hufs->phc;
   req.idn = 0;
   req.idx = UFS_IDX_bBootLunEn;
   req.val = 0;

   rc = ufs_read_attributes (&req);

   hufs->phc->dev_cfg.bBootLunEn = req.val;
   hufs->phc->has_boot_en_attr = 1;
   return rc;
}

// Set the bBootLunEn field in the attributes
int32_t ufs_set_bBootLunEn (struct ufs_handle *hufs, uint8_t id)
{
   ufs_attr_req_t req;
   int32_t rc = EOK;

   req.phc = hufs->phc;
   req.idn = 0;
   req.idx = UFS_IDX_bBootLunEn;
   req.val = id;

   rc = ufs_write_attributes (&req);
   return rc;
}

// Set the bRefClkFreq field in the attributes 
int32_t ufs_set_bRefClkFreq (struct ufs_handle *hufs, uint32_t freq)
{
   ufs_attr_req_t req;
   int32_t rc = EOK;

   req.phc = hufs->phc;
   req.idn = 0;
   req.idx = UFS_IDX_bRefClkFreq;

   switch (freq) {
      case 19200000:
         req.val = 0;
         break;
      case 26000000:
         req.val = 1;
         break;
      case 38400000:
         req.val = 2;
         break;
      case 52000000:
         req.val = 3;
         break;
      default:
         return -EINVAL;
   }

   rc = ufs_write_attributes (&req);
   return rc;
}

// Set the fDeviceInit field in the flags and wait for the bit to set
int32_t ufs_set_fDeviceInit (struct ufs_handle *hufs)
{
   ufs_attr_req_t req;
   int32_t rc = EOK;
   int32_t i;
   ufs_host_t *hba;

   hba = hufs->phc;

   // Check if the internal fDevicInit flag is set, skip the entire function
   if (hba->fDeviceInit) {
      return EOK;
   }

   req.phc = hufs->phc;
   req.idn = UFS_IDX_fDeviceInit;
   req.idx = 0;
   req.val = 0;

   rc = ufs_dev_flag_op (&req, UPIU_FLAG_OP_READ);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0230);
      return rc;
   }
   // If fDeviceInit is already set, return immidiately
   if (req.val == 1) {
      hba->fDeviceInit = 1;
      return EOK;
   }

   // Loop until flag is set
   i = MAX_UFS_WAIT_DEV_INIT_FLAG;
   do {
      // fDeviceInit is not set, sent set flag UPIU
      rc = ufs_dev_flag_op (&req, UPIU_FLAG_OP_SET);
      if (rc != EOK) {
         return rc;
      }

      rc = ufs_dev_flag_op (&req, UPIU_FLAG_OP_READ);
      if (rc != EOK) {
         return rc;
      }
      if (req.val == 1) {
         hba->fDeviceInit = 1;
         return EOK;
      }
   } while (i--);

   ufs_error_log(hba, 0x0231);
   // TIMEOUT
   return -ETIME;
}

// Set the fPowerOnWPEn field in the flags 
int32_t ufs_set_fPowerOnWPEn (struct ufs_handle *hufs)
{
   ufs_attr_req_t req;
   int32_t rc = EOK;

   req.phc = hufs->phc;
   req.idn = 0;
   req.idx = UFS_IDX_fPowerOnWPEn;
   req.val = 0;

   rc = ufs_dev_flag_op (&req, UPIU_FLAG_OP_SET);
   return rc;
}


// Set the LUN write protect by updating the unit device configuration
int32_t ufs_set_bLUWriteProtect (struct ufs_handle *hufs, uint8_t wp_setting)
{
   ufs_host_t *hba;
   ufs_attr_req_t req;
   int32_t rc = EOK;
   uint8_t buf[16 * 8 + 16];     
   // 8 LUN (Each 16 bytes) + Configuration descriptor (16 bytes)

   // LUN ID can be from 0 to 7 for UFS device
   if (hufs->lun > 7) {
      return -EINVAL;
   }

   // WP setting can be either 0, 1, or 2
   if (wp_setting > 2) {
      return -EINVAL;
   }

   hba = hufs->phc;
   req.phc = hufs->phc;
   req.req_data_len = 0;
   req.req_data_buf = NULL;
   req.resp_data_len = sizeof (buf);
   req.resp_data_buf = buf;
   req.idn = UFS_DESC_IDN_CONFIGURATION;
   req.idx = hufs->lun;

   rc = ufs_read_dev_descriptor (&req);
   if (rc != EOK) {
      return rc;
   }

   // Decode the buffer content
   if (buf[0] != 0x22) {
      // Unit descriptor is always 0x22 bytes long
      ufs_error_log(hba, 0x0232);
      return -EIO;
   }

   // Update the bLUWriteProtect field
   buf[16 + hufs->lun * 16 + 2] = wp_setting;

   // Write the updated data back
   req.phc = hba;
   req.req_data_len = sizeof (buf);
   req.req_data_buf = buf;
   req.resp_data_len = 0;
   req.resp_data_buf = NULL;
   req.idn = UFS_DESC_IDN_CONFIGURATION;
   req.idx = hufs->lun;
   rc = ufs_write_dev_descriptor (&req);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0233);
   }
   return rc;
}

// Write the RPMB message buffer out using security protocal out operation
static int32_t ufs_rpmb_msg_out (struct ufs_handle *hufs)
{
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   int32_t rc = EOK;
   const uint32_t len = RPMB_MSG_SIZE;
   ufs_host_t *hba;

   // Fill in the CDB with SCSI command structure
   memset (&req, 0, sizeof(ufs_cmd_req_t));
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_SECPROT_OUT;   // Command
   cdb[1] = 0xEC;                   // Security Protocal
   cdb[2] = 0x00;                   // 
   cdb[3] = 0x01;                   // Security Protocal Specific
   cdb[4] = 0x00;                   // Reserved
   cdb[5] = 0x00;                   // Reserved
   cdb[6] = (len >> 24) & 0xff;     // 
   cdb[7] = (len >> 16) & 0xff;     // 
   cdb[8] = (len >> 8) & 0xff;      // 
   cdb[9] = (len) & 0xff;           // Transfer Length
   cdb[10] = 0;                     // Reserve
   cdb[11] = 0;                     // Control

   req.phc = hufs->phc;
   hba = hufs->phc;
   req.lun = UFS_I_WLUN_RPMB;
   req.flags = UFS_XFER_FLAGS_WRITE;
   req.expected_len = RPMB_MSG_SIZE;
   req.data_buf_phy = GET_PHYADDR(rpmb_msg_buf);   

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0240);
      return rc;
   }

   // Verify SCSI transfer status
   hufs->phc->last_scsi_status = req.status;
   if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x0241);
      return -EIO;
   }

   return rc;
}

// Read the RPMB message buffer in using security protocal in operation
static int32_t ufs_rpmb_msg_in (struct ufs_handle *hufs)
{
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   int32_t rc = EOK;
   const uint32_t len = RPMB_MSG_SIZE;
   ufs_host_t *hba;

   // Fill in the CDB with SCSI command structure
   memset (&req, 0, sizeof(ufs_cmd_req_t));
   memset (cdb, 0, sizeof(cdb));
   cdb[0] = SCSI_CMD_SECPROT_IN;    // Command
   cdb[1] = 0xEC;                   // Security Protocal
   cdb[2] = 0x00;                   // 
   cdb[3] = 0x01;                   // Security Protocal Specific
   cdb[4] = 0x00;                   // Reserved
   cdb[5] = 0x00;                   // Reserved
   cdb[6] = (len >> 24) & 0xff;     // 
   cdb[7] = (len >> 16) & 0xff;     // 
   cdb[8] = (len >> 8) & 0xff;      // 
   cdb[9] = (len) & 0xff;           // Transfer Length
   cdb[10] = 0;                     // Reserve
   cdb[11] = 0;                     // Control

   req.phc = hufs->phc;
   hba = hufs->phc;
   req.lun = UFS_I_WLUN_RPMB;
   req.flags = UFS_XFER_FLAGS_READ;
   req.expected_len = RPMB_MSG_SIZE;
   req.data_buf_phy = GET_PHYADDR(rpmb_msg_buf);   

   rc = ufs_do_scsi_command (&req, cdb);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0248);
      return rc;
   }

   // Verify SCSI transfer status
   hufs->phc->last_scsi_status = req.status;
   if (req.status != SCSI_STATUS_GOOD) {
      ufs_error_log(hba, 0x0249);
      return -EIO;
   }

   return rc;
}

int32_t ufs_rpmb_read_write_cnt (struct ufs_handle *hufs, uint32_t *write_cnt)
{
   int32_t rc = EOK;
   uint16_t rst;
   ufs_host_t *hba;

   hba = hufs->phc;

   // Fill in the RPMB message buffer
   memset (rpmb_msg_buf, 0, RPMB_MSG_SIZE);
   rpmb_msg_buf[510] = 0x00;
   rpmb_msg_buf[511] = RPMB_REQ_READ_WR_CNT;

   rc = ufs_rpmb_msg_out (hufs);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0250);
      return rc;
   }

   // Get the STATUS by issue a security protocal in message
   memset (rpmb_msg_buf, 0, RPMB_MSG_SIZE);

   rc = ufs_rpmb_msg_in (hufs);

   // Check the mesage type to make sure it is good
   if (rpmb_msg_buf[510] != RPMB_REQ_READ_WR_CNT ||
       rpmb_msg_buf[511] != 0x00) {
      ufs_error_log(hba, 0x0251);
      return -EIO;
   }

   // Check the return status to make sure it is good
   rst = (rpmb_msg_buf[508] << 8) | rpmb_msg_buf[509];
   hufs->phc->rpmb_last_status = rst;
   if (rst != RPMB_RESULT_OK) {
      ufs_error_log(hba, 0x0252);
      return -EIO;
   }

   // Return the count value
   *write_cnt = (rpmb_msg_buf[500] << 24) | (rpmb_msg_buf[501] << 16) | 
                (rpmb_msg_buf[502] << 8)  | (rpmb_msg_buf[503]);

   return rc;
}

int32_t ufs_rpmb_write_key (struct ufs_handle *hufs, uint8_t *key)
{
   int32_t rc = EOK;
   uint16_t rst;
   ufs_host_t *hba;

   hba = hufs->phc;

   // Fill in the RPMB message buffer
   memset (rpmb_msg_buf, 0, RPMB_MSG_SIZE);
   rpmb_msg_buf[510] = 0x00;
   rpmb_msg_buf[511] = RPMB_REQ_READ_WR_CNT;

   rc = ufs_rpmb_msg_out (hufs);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0258);
      return rc;
   }

   // Get the STATUS by issue a security protocal in message
   memset (rpmb_msg_buf, 0, RPMB_MSG_SIZE);

   rc = ufs_rpmb_msg_in (hufs);

   // Check the mesage type to make sure it is good
   if (rpmb_msg_buf[510] != RPMB_REQ_READ_WR_CNT ||
       rpmb_msg_buf[511] != 0x00) {
      ufs_error_log(hba, 0x0259);
      return -EIO;
   }

   // Check the return status to make sure it is good
   rst = (rpmb_msg_buf[508] << 8) | rpmb_msg_buf[509];
   hufs->phc->rpmb_last_status = rst;
   if (rst != RPMB_RESULT_OK) {
      ufs_error_log(hba, 0x025a);
      return -EIO;
   }

   return rc;
}

int32_t ufs_rpmb_write_data (struct ufs_handle *hufs, uint32_t blocks, 
                             uint8_t *cmdbuf, uint8_t *databuf)
{
   int32_t rc = EOK;
   ufs_host_t *hba = hufs->phc;
   uint16_t rst;
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   uint32_t len;
   uint32_t current_bl;
   uint32_t total_bl;

   total_bl = blocks;
   while (total_bl) {
      current_bl = total_bl > hba->bRPMB_ReadWriteSize ? 
                   hba->bRPMB_ReadWriteSize : total_bl;
      total_bl -= current_bl;

      // Fill in the RPMB message buffer
      memcpy (rpmb_msg_buf, cmdbuf, RPMB_MSG_SIZE);
      rpmb_msg_buf[510] = 0x00;
      rpmb_msg_buf[511] = RPMB_REQ_DATA_WRITE;

      rc = ufs_rpmb_msg_out (hufs);
      if (rc != EOK) {
         ufs_error_log(hba, 0x0260);
         return rc;
      }

      // Write the actual data in a SECPROTO out packet
      len = current_bl * 512;          // Length is 512 bytes per block to transfer

      // Fill in the CDB with SCSI command structure
      memset (cdb, 0, sizeof(cdb));
      cdb[0] = SCSI_CMD_SECPROT_OUT;   // Command
      cdb[1] = 0xEC;                   // Security Protocal
      cdb[2] = 0x00;                   // 
      cdb[3] = 0x01;                   // Security Protocal Specific
      cdb[4] = 0x00;                   // Reserved
      cdb[5] = 0x00;                   // Reserved
      cdb[6] = (len >> 24) & 0xff;     // 
      cdb[7] = (len >> 16) & 0xff;     // 
      cdb[8] = (len >> 8) & 0xff;      // 
      cdb[9] = (len) & 0xff;           // Transfer Length
      cdb[10] = 0;                     // Reserve
      cdb[11] = 0;                     // Control

      req.phc = hufs->phc;
      req.lun = UFS_I_WLUN_RPMB;
      req.flags = UFS_XFER_FLAGS_WRITE;
      req.expected_len = RPMB_MSG_SIZE * blocks;
      req.data_buf_phy = GET_PHYADDR(rpmb_msg_buf);   

      rc = ufs_do_scsi_command (&req, cdb);
      if (rc != EOK) {
         ufs_error_log(hba, 0x0261);
         return rc;
      }

      // Verify SCSI transfer status
      hufs->phc->last_scsi_status = req.status;
      if (req.status != SCSI_STATUS_GOOD) {
         ufs_error_log(hba, 0x0262);
         return -EIO;
      }

      // Get the STATUS by issue a security protocal in message
      memset (rpmb_msg_buf, 0, RPMB_MSG_SIZE);

      rc = ufs_rpmb_msg_in (hufs);

      // Check the mesage type to make sure it is good
      if (rpmb_msg_buf[510] != RPMB_REQ_DATA_WRITE ||
          rpmb_msg_buf[511] != 0x00) {
         ufs_error_log(hba, 0x0263);
         return -EIO;
      }

      // Check the return status to make sure it is good
      rst = (rpmb_msg_buf[508] << 8) | rpmb_msg_buf[509];
      hufs->phc->rpmb_last_status = rst;
      if (rst != RPMB_RESULT_OK) {
         ufs_error_log(hba, 0x0264);
         return -EIO;
      }
   }

   return rc;
}

int32_t ufs_rpmb_read_data (struct ufs_handle *hufs, uint32_t blocks, 
                            uint32_t *buf)
{
   int32_t rc = EOK;
   uint8_t cdb[16];
   ufs_cmd_req_t req;
   ufs_host_t *hba = hufs->phc;
   uint32_t len;
   uint32_t current_bl;
   uint32_t total_bl;

   total_bl = blocks;
   while (total_bl) {
      current_bl = total_bl > hba->bRPMB_ReadWriteSize ? 
                   hba->bRPMB_ReadWriteSize : total_bl;
      total_bl -= current_bl;

      // Fill in the RPMB message buffer
      memcpy (rpmb_msg_buf, buf, RPMB_MSG_SIZE);
      rc = ufs_rpmb_msg_out (hufs);
      if (rc != EOK) {
         return rc;
      }

      // Write the actual data in a SECPROTO out packet
      len = current_bl * 512;             // Length is 512 bytes per block to transfer

      // Fill in the CDB with SCSI command structure
      memset (cdb, 0, sizeof(cdb));
      cdb[0] = SCSI_CMD_SECPROT_IN;    // Command
      cdb[1] = 0xEC;                   // Security Protocal
      cdb[2] = 0x00;                   // 
      cdb[3] = 0x01;                   // Security Protocal Specific
      cdb[4] = 0x00;                   // Reserved
      cdb[5] = 0x00;                   // Reserved
      cdb[6] = (len >> 24) & 0xff;     // 
      cdb[7] = (len >> 16) & 0xff;     // 
      cdb[8] = (len >> 8) & 0xff;      // 
      cdb[9] = (len) & 0xff;           // Transfer Length
      cdb[10] = 0;                     // Reserve
      cdb[11] = 0;                     // Control

      req.phc = hufs->phc;
      req.lun = UFS_I_WLUN_RPMB;
      req.flags = UFS_XFER_FLAGS_READ;
      req.expected_len = RPMB_MSG_SIZE * blocks;
      req.data_buf_phy = GET_PHYADDR(rpmb_msg_buf);   

      rc = ufs_do_scsi_command (&req, cdb);
      if (rc != EOK) {
         ufs_error_log(hba, 0x0268);
         return rc;
      }

      // Verify SCSI transfer status
      hufs->phc->last_scsi_status = req.status;
      if (req.status != SCSI_STATUS_GOOD) {
         ufs_error_log(hba, 0x0269);
         return -EIO;
      }

      // TODO: Do we need to check each of the packet for good data?
      // Copy the resulting data to buffer pointer supplied
   }

   return rc;
}

int32_t ufs_do_config_device( struct ufs_handle *hufs, 
                              struct ufs_config_descr *cfg )
{
   ufs_host_t *hba;
   ufs_attr_req_t req;
   int32_t rc = EOK;
   uint8_t buf[0x90];
   uint8_t *pt;
   int i;

   memset (&req, 0, sizeof (ufs_attr_req_t));

   hba = hufs->phc;
   req.phc = hba;
   req.req_data_len = sizeof(buf);
   req.req_data_buf = buf;
   req.resp_data_len = 0;
   req.resp_data_buf = NULL;
   req.idn = UFS_DESC_IDN_CONFIGURATION;
   req.idx = 0;

   // Fill in the buffer with configuration data
   pt = buf;
   *pt++ = 0x90;        // bLength
   *pt++ = 0x01;        // bDescriptorType
   *pt++ = cfg->bNumberLU;
   *pt++ = cfg->bBootEnable;
   *pt++ = cfg->bDescrAccessEn;
   *pt++ = cfg->bInitPowerMode;
   *pt++ = cfg->bHighPriorityLUN;
   *pt++ = cfg->bSecureRemovalType;
   *pt++ = cfg->bInitActiveICCLevel;
   *pt++ = (cfg->wPeriodicRTCUpdate >> 8) & 0xff;
   *pt++ = cfg->wPeriodicRTCUpdate & 0xff;
   *pt++ = 0;           // Reserved fields
   *pt++ = 0;
   *pt++ = 0;
   *pt++ = 0;
   *pt++ = 0;

   for (i = 0; i < 8; i++) {
      *pt++ = cfg->unit[i].bLUEnable;
      *pt++ = cfg->unit[i].bBootLunID;
      *pt++ = cfg->unit[i].bLUWriteProtect;
      *pt++ = cfg->unit[i].bMemoryType;
      *pt++ = (cfg->unit[i].dNumAllocUnits >> 24) & 0xff;
      *pt++ = (cfg->unit[i].dNumAllocUnits >> 16) & 0xff;
      *pt++ = (cfg->unit[i].dNumAllocUnits >> 8) & 0xff;
      *pt++ = (cfg->unit[i].dNumAllocUnits) & 0xff;
      *pt++ = cfg->unit[i].bDataReliability;
      *pt++ = cfg->unit[i].bLogicalBlockSize;
      *pt++ = cfg->unit[i].bProvisioningType;
      *pt++ = (cfg->unit[i].wContextCapabilities >> 8) & 0xff;
      *pt++ = cfg->unit[i].wContextCapabilities;
      *pt++ = 0;        // Reserved fields
      *pt++ = 0;
      *pt++ = 0;
   }

   rc = ufs_write_dev_descriptor (&req);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0270);
      return rc;
   }

   return rc;
}

void ufs_fill_in_device_info (struct ufs_handle *hufs, 
                             struct ufs_info_type *info)
{
   ufs_host_t *hba = hufs->phc;
   uint8_t lun;
   uint8_t bBootLunEn;
   int i;

   lun = hufs->lun;
   if (lun > 7 && lun == UFS_WLUN_BOOT && hba->bBootEnable) {
      bBootLunEn = hba->dev_cfg.bBootLunEn;
      if (bBootLunEn == 1 || bBootLunEn == 2) {
         for (i = 0; i < 8; i++) {
            if (hba->lun_cfg[i].bBootLunID == bBootLunEn) {
               lun = i;
            }
         }
      }
   }

   info->fInitialized = hba->is_initialized;
   info->bLUN = lun;
   info->bNumberLu = hba->dev_cfg.bNumberLU;
   info->wManufacturerID = hba->wManufacturerID;
   info->bBootEnable = hba->bBootEnable;
   info->qTotalRawDeviceCapacity = hba->qTotalRawDeviceCapacity;
   info->bMinAddrBlockSize = hba->bMinAddrBlockSize;
   info->dSegmentSize = hba->dSegmentSize; 
   info->bAllocationUnitSize = hba->bAllocationUnitSize;
   info->bRPMB_ReadWriteSize = hba->bRPMB_ReadWriteSize;
   info->wSupportedMemoryTypes = hba->wSupportedMemoryTypes;
   info->dEnhanced1MaxNAllocU = hba->dEnhanced1MaxNAllocU;
   info->wEnhanced1CapAdjFac = hba->wEnhanced1CapAdjFac;
   info->dEnhanced2MaxNAllocU = hba->dEnhanced2MaxNAllocU;
   info->wEnhanced2CapAdjFac = hba->wEnhanced2CapAdjFac;

   // Populate the LUN enabled bit field
   info->dLunEnabled = 0;
   for (i = 0; i < 8; i++) {
      info->dLunEnabled |= (hba->lun_enable[i] ? 1 : 0) << i;
   }

   if (lun <= 7) {
      // LUN specific area
      info->dNumAllocUnits = hba->lun_cfg[lun].dNumAllocUnits;
      info->bLogicalBlockSize = hba->lun_cfg[lun].bLogicalBlockSize;
      info->bProvisioningType = hba->lun_cfg[lun].bProvisioningType;
      info->bLUWriteProtect = hba->lun_cfg[lun].bLUWriteProtect;
      info->bBootLunID = hba->lun_cfg[lun].bBootLunID;
      info->bMemoryType = hba->lun_cfg[lun].bMemoryType;
   }
}

