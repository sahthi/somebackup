#ifndef __UFS_MEMORY_H
#define __UFS_MEMORY_H
/******************************************************************************
 * ufs_memory.h
 *
 * This file provides UFS storage device description data structure and
 * SCSI related data structure
 *
 * Copyright (c) 2012-2013 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 *
 *****************************************************************************/
/*=============================================================================

                        EDIT HISTORY FOR MODULE

  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/ufs_memory.h#1 $
  $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $

when         who     what, where, why
----------   ---     ---------------------------------------------------
2013-09-10   rh      Adding define for WRITE/READ buffer SCSI command
2012-12-18   rh      Initial creation

=============================================================================*/

// Define SCSI commands
#define SCSI_CMD_TEST_UNIT_RDY      0x00
#define SCSI_CMD_INQUIRY            0x12
#define SCSI_CMD_READ10             0x28
#define SCSI_CMD_READ_CAP10         0x25     // Read Capacity
#define SCSI_CMD_SYNC_CACHE10       0x35
#define SCSI_CMD_UNMAP              0x42
#define SCSI_CMD_WRITE10            0x2A
#define SCSI_CMD_SECPROT_IN         0xA2     // Security Protocal in
#define SCSI_CMD_SECPROT_OUT        0xB5     // Security Protocal out
#define SCSI_CMD_REPORT_LUNS        0xA0
#define SCSI_CMD_WRITE_BUFFER       0x3B
#define SCSI_CMD_READ_BUFFER        0x3C

#define SCSI_STATUS_GOOD            0x00
#define SCSI_STATUS_CHK_COND        0x02
#define SCSI_STATUS_BUSY            0x08
#define SCSI_STATUS_TASK_SET_FULL   0x08

#define SCSI_FLAG_FUA               0x08

// UFS descriptor type ident value
#define UFS_DESC_IDN_DEVICE         0x00
#define UFS_DESC_IDN_CONFIGURATION  0x01
#define UFS_DESC_IDN_UNIT           0x02
#define UFS_DESC_IDN_INTERCONNECT   0x04
#define UFS_DESC_IDN_STRING         0x05
#define UFS_DESC_IDN_GEOMETRY       0x07
#define UFS_DESC_IDN_POWER          0x08

// Attributes definitions
#define UFS_IDX_bBootLunEn          0x00
#define UFS_IDX_bCurrentPowerMode   0x01
#define UFS_IDX_bActiveICCLevel     0x03
#define UFS_IDX_bRefClkFreq         0x0a
#define UFS_IDX_bConfigDescrLock    0x0b

// Flags definitions
#define UFS_IDX_fDeviceInit         0x01
#define UFS_IDX_fPowerOnWPEn        0x03

// Commonly used WLUN value
#define UFS_I_WLUN_REPORT           0x81
#define UFS_I_WLUN_UFS_DEVICE       0xD0
#define UFS_I_WLUN_BOOT             0x80
#define UFS_I_WLUN_RPMB             0xC4

// Placement of the message byte is determined by if 
// this is a request or a response
// For request, the message is in bit [7:0] while bit [15:8] is zero
// For response, the message is in bit [15:8] while bit [7:0] is zero
#define RPMB_REQ_KEY_PROG           0x01
#define RPMB_REQ_READ_WR_CNT        0x02
#define RPMB_REQ_DATA_WRITE         0x03
#define RPMB_REQ_DATA_READ          0x04
#define RPMB_REQ_RESULT_READ        0x05

#define RPMB_RESULT_OK              0x00
#define RPMB_RESULT_FAILURE         0x01
#define RPMB_RESULT_AUTH_FAILURE    0x02
#define RPMB_RESULT_CNT_FAILURE     0x03
#define RPMB_RESULT_ADDR_FAILURE    0x04
#define RPMB_RESULT_WR_FAILURE      0x05
#define RPMB_RESULT_RD_FAILURE      0x06
#define RPMB_RESULT_NO_KEY          0x07

// A data stucture used by the caller of the UFS driver as 
// a handle to access the APIs
typedef struct ufs_handle {
   struct ufs_host_info *phc;
   uint8_t        is_inuse;               // Inuse flag must be fist
   uint8_t        ufs_core_id;            // For this design, id = 0
   uint8_t        lun;
   uint32_t       id_magic;               // Magic # must be last

} ufs_handle_t;

// Function definitions

/* 
 * Initialize UFS memory device
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success ENODEV when detection failed
 * */
int32_t ufs_mem_init (struct ufs_handle *hufs);

/* 
 * Read multiple blocks of data from UFS memory device
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Output: buf  - Pointer to memory buffer for read operation
 * Input:  lba  - Logical block address for the first block
 * Input:  blocks - Number of blocks to read
 * Return: EOK for success EIO when read failed
 * */
int32_t ufs_scsi_read (struct ufs_handle *hufs, uint8_t *buf, 
                       uint32_t lba, uint32_t blocks);

/* 
 * Write mutiple blocks of data from UFS memory device
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Input:  buf  - Pointer to memory buffer for write operation
 * Input:  lba  - Logical block address for the first block
 * Input:  blocks - Number of blocks to write
 * Return: EOK for success EIO when write failed
 * */
int32_t ufs_scsi_write (struct ufs_handle *hufs, uint8_t *buf, 
                        uint32_t lba, uint32_t blocks);

/* 
 * Erase memory blocks from UFS memory device
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Input:  lba  - Logical block address for the first block
 * Input:  blocks - Number of blocks to erase
 * Return: EOK for success EIO when erase failed
 * */
int32_t ufs_scsi_unmap (struct ufs_handle *hufs, 
                        uint32_t lba, uint32_t blocks);

/* 
 * Test and see if the memory device is ready for operation
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EBUSY if the device is busy and
 *         EIO if IO error is encountered
 * */
int32_t ufs_scsi_unit_rdy (struct ufs_handle *hufs);

/* 
 * Get a list of all the active LUNs 
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_scsi_report_lun (struct ufs_handle *hufs);

/* 
 * Check the LUN supplied to see if it is one of the active LUN
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, ENOENT if LUN is not valid 
 * */
int32_t ufs_check_valid_lun (struct ufs_handle *hufs, uint8_t lun);

/* 
 * Get one of the string dscriptors from the UFS device
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Input:  id - ID of the descriptor to get
 * Output: buf - Pointer to memory buffer to hold the descriptor info
 * Input:  size - Size of the memory buffer
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_get_descriptor_str (struct ufs_handle *hufs, uint32_t id,
                                char *buf, uint32_t size);

/* 
 * Get one of the unit dscriptors from the UFS device
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Input:  id - ID of the descriptor to get
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_get_descriptor_unit (struct ufs_handle *hufs, uint32_t id);


/* 
 * Get the device descriptor
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_get_descriptor_device (struct ufs_handle *hufs);


/* 
 * Get the device configuration descriptor
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_get_descriptor_config (struct ufs_handle *handle);


/* 
 * Get the geometry descriptor
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_get_descriptor_geometry (struct ufs_handle *hufs);

/* 
 * Wait until device is responding to NOP UPIU requests
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_wait_device_awake (struct ufs_handle *handle);

/* 
 * Get the BOOT LUN configuration from the UFS device attribute
 * structure and store the value in the ufs_host_t data structure
 * The bBootLunEn flag identify which BOOT LUN (A or B) is mapped
 * to BOOT WLUN 
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_get_bBootLunEn (struct ufs_handle *hufs);

/* 
 * Set the boot LUN configuration for UFS device.  
 *
 * Input:  hufs - Pointer to the UFS handle structure
 *         id - which boot LUN to use: 
 *             0 : Disable BOOT WLUN
 *             1 : Set BOOT for A
 *             2 : Set BOOT for B
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_set_bBootLunEn (struct ufs_handle *hufs, uint8_t id);

/* 
 * Set the fDeviceInit flag.  Setting this flag exits
 * the partial init mode for UFS device
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_set_fDeviceInit (struct ufs_handle *hufs);

/* 
 * Set the fPowerOnWPEn flag.  Setting this flag enable
 * the Power On Write Protect fucntion.  The flag can not be
 * cleared without a power cycle
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_set_fPowerOnWPEn (struct ufs_handle *hufs);

/* 
 * Set the bLUWriteProtect field in the unit descriptor. 
 * Setting this field following by setting the fPowerOnWPEn 
 * flag enable the write protect feature
 *
 * Input:  hufs - Pointer to the UFS handle structure
 *         wp_setting - 0 : Not writeprotected
 *                      1 : Power on write protect
 *                      2 : Permanently write protected
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_set_bLUWriteProtect (struct ufs_handle *hufs, uint8_t wp_setting);

/* 
 * Send the scsi inquiry command and decode the returned value.
 * Result stored in the ufs_host_t data structure
 *
 * Input:  hufs - Pointer to the UFS handle structure
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_scsi_inquiry (struct ufs_handle *hufs);

/* 
 * Function used to get the UFS device information, fill
 * in the ufs_info_type data structure
 *
 * Input:  hufs - Pointer to the UFS handle structure
 *         info - UFS device information
 * Return: EOK for success, EIO if IO error is encountered
 * */
void ufs_fill_in_device_info (struct ufs_handle *hufs, 
                             struct ufs_info_type *info);

/* 
 * Main function used for the initial provisioning of the UFS device
 * and configuration of the LU layout
 *
 * Input:  hufs - Pointer to the UFS handle structure
 *         cfg - LU configuration information
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_do_config_device( struct ufs_handle *hufs, 
                              struct ufs_config_descr *cfg );

/* 
 * Set the value of the bRefClkFreq
 *
 * Input:  hufs - Pointer to the UFS handle structure
 *         freq - RefClk frequency in Hz
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_set_bRefClkFreq (struct ufs_handle *hufs, uint32_t freq);

/* 
 * Send the scsi write buffer command 
 *
 * Input:  hufs - Pointer to the UFS handle structure
 *         buf - Pointer to data to write
 *         mode - Mode field in the SCSI CDB
 *         buf_id - Bufer ID field in the SCSI CDB
 *         offset - Buffer Offset field in the SCSI CDB
 *         len - Data transfer length in bytes
 * Return: EOK for success, EIO if IO error is encountered
 * */
int32_t ufs_scsi_write_buf (struct ufs_handle *hufs, uint8_t *buf, 
									 uint8_t mode, uint8_t buf_id, 
									 uint32_t offset, uint32_t len);


#endif /* UFS_MEMORY_H */
