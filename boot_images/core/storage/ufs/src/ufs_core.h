#ifndef __UFS_CORE_H
#define __UFS_CORE_H
/**********************************************************************
 *
 *   UFS core header file
 *   Contain function definition and data structure required by the 
 *   UFS core and UFS_UTP layer
 *
 * Copyright (c) 2012-2013 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 *
 **********************************************************************/

/*======================================================================

                        EDIT HISTORY FOR MODULE

  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/ufs_core.h#1 $
  $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $

when         who     what, where, why
----------   ---     ---------------------------------------------------
2013-09-10   rh      Adding generic UPIU write passthrough
2013-09-06   rh      Increase the size of the debug log buffer
2013-09-04   rh      Adding enhanced area capacity adjustment factor
2012-12-18   rh      Initial creation
=======================================================================*/

#define UFS_WLUN_REPORT_LUNS           0x81
#define UFS_WLUN_UFS_DEVICE            0xD0
#define UFS_WLUN_BOOT                  0xB0
#define UFS_WLUN_RPMB                  0xC4

// UPIU transaction specific defines

// FLAGS for indication of read or write
#define UPIU_FLAGS_READ                0x40
#define UPIU_FLAGS_WRITE               0x20
#define UPIU_FLAGS_ATTR_SIMPLE         0x00
#define UPIU_FLAGS_ATTR_ORDERED        0x01
#define UPIU_FLAGS_ATTR_HOQ            0x02

// Redefine the name for higher layer use
#define UFS_XFER_FLAGS_READ            UPIU_FLAGS_READ                
#define UFS_XFER_FLAGS_WRITE           UPIU_FLAGS_WRITE               
#define UFS_XFER_FLAGS_ATTR_SIMPLE     UPIU_FLAGS_ATTR_SIMPLE         
#define UFS_XFER_FLAGS_ATTR_ORDERED    UPIU_FLAGS_ATTR_ORDERED        
#define UFS_XFER_FLAGS_ATTR_HOQ        UPIU_FLAGS_ATTR_HOQ            

#define UPIU_FLAGS_OVERFLOW            0x40
#define UPIU_FLAGS_UNDERFLOW           0x20
#define UPIU_FLAGS_DATAMISMATCH        0x10

#define UPIU_CMDTYPE_SCSI              0x0
#define UPIU_CMDTYPE_NATIVE_UFS        0x1

#define UPIU_QUERY_OP_NOP              0x0
#define UPIU_QUERY_OP_READ_DESCRIPTOR  0x1
#define UPIU_QUERY_OP_WRITE_DESCRIPTOR 0x2
#define UPIU_QUERY_OP_READ_ATTRIBUTE   0x3
#define UPIU_QUERY_OP_WRITE_ATTRIBUTE  0x4
#define UPIU_QUERY_OP_READ_FLAG        0x5
#define UPIU_QUERY_OP_SET_FLAG         0x6
#define UPIU_QUERY_OP_CLEAR_FLAG       0x7
#define UPIU_QUERY_OP_TOGGLE_FLAG      0x8

// Query Response Code
#define UPIU_RESP_SUCCESS              0x0
#define UPIU_RESP_NOT_READABLE         0xf6
#define UPIU_RESP_NOT_WRITEABLE        0xf7
#define UPIU_RESP_ALREADY_WRITTEN      0xf8
#define UPIU_RESP_INVALID_LEN          0xf9
#define UPIU_RESP_INVALID_VAL          0xfa
#define UPIU_RESP_INVALID_SELECTOR     0xfb
#define UPIU_RESP_INVALID_INDEX        0xfc
#define UPIU_RESP_INVALID_IDN          0xfd
#define UPIU_RESP_INVALID_OPC          0xfe
#define UPIU_RESP_FAILED               0xff

// Query function define
#define UPIU_FNC_STD_READ              0x01
#define UPIU_FNC_STD_WRITE             0x81

// UFS device flag operation code
#define UPIU_FLAG_OP_READ              0x00
#define UPIU_FLAG_OP_SET               0x01
#define UPIU_FLAG_OP_CLEAR             0x02
#define UPIU_FLAG_OP_TOGGLE            0x04

#define DEFAULT_SECTOR_SIZE            4096

// DME attribute defines
// L1 - M-TX PHY 
#define TX_HSMODE_Capability                    0x01
#define TX_HSGEAR_Capability                    0x02
#define TX_PWMGEAR_Capability                   0x04
#define TX_PHY_MajorMinor_Release_Capability    0x0d

#define TX_MODE                                 0x21
#define TX_HSRATE_Series                        0x22
#define TX_HSGEAR                               0x23
#define TX_PWMGEAR                              0x24
#define TX_Amplitude                            0x25
#define TX_HS_SlewRate                          0x26
#define TX_SYNC_Source                          0x27
#define TX_HS_SYNC_LENGTH                       0x28
#define TX_HS_PREPARE_LENGTH                    0x29
#define TX_LS_PREPARE_LENGTH                    0x2a
#define TX_HIBERN8_Control                      0x2b
#define TX_LCC_Enable                           0x2c
#define TX_PWM_BURST_Closure_Extension          0x2d
#define TX_BYPASS_8B10B_Enable                  0x2e
#define TX_DRIVER_POLARITY                      0x2f
#define TX_LCC_Sequencer                        0x32
#define TX_Min_Active_Time                      0x33

#define TX_FSM_State                            0x41

#define DME_L1_TX_ITM {0x01,0x02,0x04,0x0d,0x21,0x22,0x23,0x24,0x25, \
                       0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e, \
                       0x2f,0x32,0x33,0x41}

// L1 - M-RX PHY
#define RX_HSMODE_Capability                    0x81
#define RX_HSGEAR_Capability                    0x82
#define RX_PWMG0_Capability                     0x83
#define RX_PWMGEAR_Capability                   0x84
#define RX_HS_SYNC_LENGTH_Capability            0x8b
#define RX_HS_PREPARE_LENGTH_Capability         0x8c
#define RX_LS_PREPARE_LENGTH_Capability         0x8b
#define RX_PWM_Burst_Closure_Length_Capability  0x8e
#define RX_PHY_MajorMinor_Release_Capability    0x90

#define RX_MODE                                 0xA1
#define RX_HSRATE_Series                        0xA2
#define RX_HSGEAR                               0xA3
#define RX_PWMGEAR                              0xA4
#define RX_LS_Terminated_Enable                 0xA5
#define RX_HS_Unterminated_Enable               0xA6
#define RX_Enter_HIBERN8                        0xA7
#define RX_BYPASS_8B10B_Enable                  0xA8

#define RX_FSM_State                            0xC1

#define DME_L1_TX_ITEM {0x81,0x82,0x83,0x84,0x8b,0x8c,0x8b,0x8e,0x90, \
                        0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xC1}

// L1.5 - PHY Adapter
#define PA_ActiveTxDataLanes                    0x1560
#define PA_ActiveRxDataLanes                    0x1580
#define PA_TxTrailingClocks                     0x1564
#define PA_PHY_Type                             0x1500
#define PA_AvailTxDataLanes                     0x1520
#define PA_AvailRxDataLanes                     0x1540
#define PA_MinRxTrailingClocks                  0x1543

#define PA_TxPWRStatus                          0x1567
#define PA_RxPWRStatus                          0x1582
#define PA_TxForceClock                         0x1562
#define PA_TxPWRMode                            0x1563

#define PA_MaxTxSpeedFast                       0x1521
#define PA_MaxTxSpeedSlow                       0x1522
#define PA_MaxRxSpeedFast                       0x1541
#define PA_MaxRxSpeedSlow                       0x1542
#define PA_TxLinkStartupHS                      0x1544

#define PA_TxSpeedFast                          0x1565
#define PA_TxSpeedSlow                          0x1566
#define PA_remoteVerInfo                        0x15A0

#define PA_TxGear                               0x1568
#define PA_TxTermination                        0x1569
#define PA_HSSeries                             0x156a
#define PA_PWRMode                              0x1571
#define PA_RxGear                               0x1583
#define PA_RxTermination                        0x1584
#define PA_MaxRxPWMGear                         0x1586
#define PA_MaxRxHSGear                          0x1587
#define PA_RxHSUnterminationCapability          0x15a5
#define PA_RxLSUnterminationCapability          0x15a6
#define PA_Hivern8Time                          0x15a7
#define PA_TActivate                            0x15a8
#define PA_PACPFrameCount                       0x15c0
#define PA_PACPErrorCount                       0x15c1
#define PA_PHYTestControl                       0x15c2
#define PA_ConnectedTxDataLanes                 0x1561
#define PA_ConnectedRxDataLanes                 0x1581
#define PA_LogicalLaneMap                       0x15a1

#define PA_SleepNoConfigTime                    0x15a2
#define PA_StallNoConfigTime                    0x15a3
#define PA_SaveConfigTime                       0x15a4
#define PA_TActive                              0x15a8

#define DME_L1x5_ITEM {0x1560,0x1580,0x1564,0x1500,0x1520, \
                       0x1540,0x1543,0x1567,0x1582,0x1562, \
                       0x1563,0x1521,0x1522,0x1541,0x1542, \
                       0x1544,0x1565,0x1566,0x15A0,0x1568, \
                       0x1569,0x156a,0x1571,0x1583,0x1584, \
                       0x1586,0x1587,0x15a5,0x15a6,0x15a7, \
                       0x15a8,0x15c0,0x15c1,0x15c2,0x1561, \
                       0x1581,0x15a1}

// L2 - DataLink layer

// L3 - Network Layer
#define N_DeviceID                              0x3000
#define N_DeviceID_valid                        0x3001

// L4 - Transport Layer
#define T_PeerDeviceID                          0x4021
#define T_PeerCPortID                           0x4022
#define T_TrafficClass                          0x4023
#define T_ConnectionState                       0x4020

#define UIC_ARG0_MIBattr(x,s)    (((x << 16) & 0xffff0000) | (s & 0xffff))

typedef struct ufs_lun_configuration {
   uint8_t        bLUEnable;
   uint8_t        bBootLunID;
   uint8_t        bLUWriteProtect;
   uint8_t        bMemoryType;
   uint32_t       dNumAllocUnits;
   uint8_t        bDataReliability;
   uint8_t        bLogicalBlockSize;
   uint8_t        bProvisioningType;
   uint16_t       wContextCapabilities;
   uint64_t       qLogicalBlockCount;
   uint32_t       dEraseBlockSize;
} lun_conf_t;

typedef struct ufs_dev_configuration {
   uint8_t        bNumberLU;
   uint8_t        bBootEnable;
   uint8_t        bDescrAccessEn;
   uint8_t        bInitPowerMode;
   uint8_t        bHighPriorityLUN;
   uint8_t        bSecureRemovalType;
   uint8_t        bInitActiveICCLevel;
   uint16_t       wPeriodicRTCUpdate;
   uint8_t        bBootLunEn;
} dev_conf_t;

typedef struct ufs_host_info {
   uint8_t        ufs_core_id;
   uint8_t        is_initialized;      /* Is the device intialized */
   uint32_t       ufs_hci_addr;
   uint64_t       ufs_req_list_phy;    /* Base addr of xfer request list */
   uint64_t       ufs_mgr_list_phy;    /* Base addr of management req list */
   uint8_t       *ufs_req_list_ptr;    /* Pointer to xfer request list */
   uint8_t       *ufs_mgr_list_ptr;    /* Pointer to management req list */
   uint32_t       ufs_last_uic_cmd;    /* Last UIC command sent */
   uint32_t       ufs_uic_arg[3];      /* Result of the UIC command */
   uint32_t       ufs_task_cnt;        /* Counter for the task tag generation */
   uint8_t        has_device_desc;     /* Got device descriptor already? */
   uint8_t        has_config_desc;     /* Got config descriptor already? */
   uint8_t        has_geometry_desc;   /* Got geometry descriptor already? */
   uint8_t        has_boot_en_attr;    /* Got BootEn attribute already? */
   uint8_t        has_scsi_inquiry;    /* Got SCSI inquiry already? */

   /* Device parameter inforamtion */
   uint8_t        lun_cnt;             /* Number of LUNs in the device */
   uint8_t        lun_enable[8];       /* Is the current LUN in use? */
   uint8_t        iManufacturerName;   /* Index for descriptor string */
   uint8_t        iProductName;
   uint8_t        iSerialNumber;
   uint8_t        iOemID;
   uint8_t        fDeviceInit;         /* Remember fDevicInit across LUs */
   uint16_t       wManufacturerID;     /* Manufacturer ID */
   uint8_t        bBootEnable;         /* Is the device enable for boot */
   uint8_t        bDescrAccessEn;      /* Descriptor can be read in boot mode */
   uint32_t       dSegmentSize;        /* Total segment size in 512 bytes unit */
   uint8_t        bAllocationUnitSize; /* Expressed in units of segment size */
   uint64_t       qTotalRawDeviceCapacity; /* Total raw capacity in 512 bytes unit */
   uint32_t       bMinAddrBlockSize;   /* Addressable block size in 512 bytes unit */
   uint32_t       bRPMB_ReadWriteSize; /* Max number of RPMB frames (256 bytes) */
   uint16_t       wSupportedMemoryTypes; /* Types of memory supported by device */
   uint32_t       dEnhanced1MaxNAllocU;/* Max allocation for Enhanced memory type 1 */
   uint16_t       wEnhanced1CapAdjFac; /* Capacity adjustment factor, Enh Memory type 1 */
   uint32_t       dEnhanced2MaxNAllocU;/* Max allocation for Enhanced memory type 2 */
   uint16_t       wEnhanced2CapAdjFac; /* Capacity adjustment factor, Enh Memory type 2 */
   dev_conf_t     dev_cfg;             /* Device configuration */
   lun_conf_t     lun_cfg[8];          /* Configuration of each of the LUN */

   /* SCSI inquiry output */
   uint8_t        inquiry_vid[28];     /* Vendor ID string from INQUIRY */

   /* Debugging registers */
   uint32_t       last_failure;        /* Remember the last failed point */
   uint32_t       last_fail_id[8];     /* A debug code for last failure */
   uint32_t       failure_cnt;         /* Count number of failure since init */
   uint8_t        last_scsi_status;    /* Status field for the last SCSI cmd */
   uint32_t       rpmb_last_status;    /* Status of the last RPMB operation */
} ufs_host_t;

// A data structure contain all the required information for 
// performing a command quest with or without data 
// Use with Command UPIU request
typedef struct ufs_command_request_info {
   struct ufs_host_info *phc;
   uint8_t        lun;              // Target LUN to issue xfer to
   uint8_t        flags;            // Read or write

   uint32_t       expected_len;     // Expected total length
   uint32_t       residual_len;     // Residual data count
   uint64_t       data_buf_phy;     // Physical buffer address
   uint8_t        status;           // SCSI command status
} ufs_cmd_req_t;

// For Querry UPIU request 
typedef struct ufs_attr_query_request {
   struct ufs_host_info *phc;
   uint8_t        idn;              // Identification field, input
   uint8_t        idx;              // Index field, input
   uint8_t        sel;              // Selection field, input
   uint32_t       val;              // Value field, in/out
   uint32_t       req_data_len;     // Request Length, used for descriptor
   uint8_t        *req_data_buf;    // Request Data, used for descriptor
   uint32_t       resp_data_len;    // Response Length, used for descriptor
   uint8_t        *resp_data_buf;   // Response Data, used for descriptor
} ufs_attr_req_t;


// Exposed function definition
// Issue a SCSI command 
int32_t ufs_do_scsi_command (ufs_cmd_req_t *cmdreq, uint8_t *cdb);

// Record the error code in the debugging buffer
void ufs_error_log(ufs_host_t *hba, uint32_t eid);

// Read UFS device descriptor, output stored in dest_buf
int32_t ufs_read_dev_descriptor (ufs_attr_req_t *preq);

// Send NOP UPIU to check if the device is ready
int32_t ufs_send_nop_ping (ufs_attr_req_t *preq);

// Write UFS attributes
int32_t ufs_write_attributes (ufs_attr_req_t *preq);

// Read UFS attributes
int32_t ufs_read_attributes (ufs_attr_req_t *preq);

// UFS device flag operation
int32_t ufs_dev_flag_op (ufs_attr_req_t *preq, uint8_t op);

// Write UFS device descriptor
int32_t ufs_write_dev_descriptor (ufs_attr_req_t *preq);

// Generic query request with write data payload
int32_t ufs_generic_write_query (ufs_attr_req_t *preq, uint8_t *osf);



#endif /* __UFS_CORE_H */
