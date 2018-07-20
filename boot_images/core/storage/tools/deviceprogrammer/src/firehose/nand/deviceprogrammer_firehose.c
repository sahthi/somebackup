/*==================================================================
 *
 * FILE:        deviceprogrammer_firehose.c
 *
 * DESCRIPTION:
 *
 *
 *        Copyright © 2008-2014 Qualcomm Technologies Incorporated.
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
 *   $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/deviceprogrammer/src/firehose/nand/deviceprogrammer_firehose.c#1 $
 *   $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $
 *
 * YYYY-MM-DD   who     what, where, why
 * ----------   ---     ----------------------------------------------
 * 2014-10-15   sb      Updated for 8909
 * 2014-03-03   dks     Added MMC FFU Support
 * 2013-06-03   ah      Added legal header
 * 2013-05-31   ab      Initial checkin
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "crc.h"
#include "stringl.h"
#include "deviceprogrammer_utils.h"
#include "deviceprogrammer_storage_device.h"



#include "deviceprogrammer_xml.h"
#include "deviceprogrammer_security.h"
#include "deviceprogrammer_bsp.h"
#include "deviceprogrammer_firehose.h"
//#include "qhsusb_al_bulk.h"
#include "qusb_al_bulk.h"
#include "qusb_common.h"
#include "boot_sahara.h"
//#include "CeTL_sha2_sw.h"

//extern uint32 flash_prog_erase_chip (void);
//extern flash_param_t *nand_device_params;


void CloseTXBuffer(void);
//void AppendToTXBuffer(char *buf);
void AppendToBuffer(byte *MyBuffer, char *buf, SIZE_T MaxBufferSize);
//char * CleanStringForPC(char *p, SIZE_T  Length);
char * RemoveBannedChars(char *p);

#define MAX_TAG_NAME_LENGTH 30
#define MAX_TAG_ATTR_LENGTH 80

char NewTagName[MAX_TAG_NAME_LENGTH+1];
char CurrentTagName[MAX_TAG_NAME_LENGTH+1];
char ParseAttributes = 1; // this changes from 0 to 1 during the program



//#define FIREHOSE_TEMP_BUFFER_SIZE 512
extern void kick_watchdog(void);



typedef enum response_t {
    NAK,
    ACK
} response_t;



// These buffers are being allocated separately so as to make them easy to relocate
// because these are currently accessed directly by the hardware
//byte main_channel_buffer_A[FIREHOSE_CHANNEL_BUFFER_SIZE]  __attribute__ ((section (".bss.CHANNEL_BUFFER_A_SECTION"))) = {0};
//byte main_channel_buffer_B[FIREHOSE_CHANNEL_BUFFER_SIZE]  __attribute__ ((section (".bss.CHANNEL_BUFFER_B_SECTION"))) = {0};
//byte transmit_buffer[FIREHOSE_TX_BUFFER_SIZE]  __attribute__ ((section (".bss.TRANSMIT_BUFFER_SECTION"))) = {0};
char temp_buffer[FIREHOSE_TEMP_BUFFER_SIZE];

firehose_protocol_t fh;	// this can be a big structure


byte main_channel_buffer_A[FIREHOSE_CHANNEL_BUFFER_SIZE]  __attribute__ ((section ("CHANNEL_BUFFER_A_SECTION"), zero_init));
byte main_channel_buffer_B[FIREHOSE_CHANNEL_BUFFER_SIZE]  __attribute__ ((section ("CHANNEL_BUFFER_B_SECTION"), zero_init));
byte transmit_buffer[FIREHOSE_TX_BUFFER_SIZE]  __attribute__ ((section ("TRANSMIT_BUFFER_SECTION"), zero_init));


#ifdef USE_FIRMWARE_BUFFER
#define BIG_FW_BUFFER_SIZE (1024*512)
byte BigFWBuffer[BIG_FW_BUFFER_SIZE];//  __attribute__ ((section (".bss.CHANNEL_BUFFER_A_SECTION"))) = {0};
SIZE_T BigFWBufferCount = 0, BigFWBufferExpected = 0;
#endif


SIZE_T ConfigureCommandNotReceivedYet = 1;  // allow VERBOSE until user turns it off

struct Error_Struct
{
    unsigned int ErrorNum;
    char *pErrorMessage;
};

struct Error_Struct AllErrorsStruct[] =
{
    { FAILURE_CHIP_SERIAL_NUMBER,       "FAILURE_CHIP_SERIAL_NUMBER"},
    { AUTHENTICATE_IMAGE_FAILURE,       "AUTHENTICATE_IMAGE_FAILURE"},
    { UFS_COMMIT_EXTRAS_FAILURE,        "UFS_COMMIT_EXTRAS_FAILURE"},
    { SET_BOOTABLE_PARTITION_FAILURE,   "SET_BOOTABLE_PARTITION_FAILURE"},
    { STORAGE_READ_FAILURE,             "STORAGE_READ_FAILURE"},
    { STORAGE_WRITE_FAILURE,            "STORAGE_WRITE_FAILURE"},
    { STORAGE_DEVICE_ERASE_FAILURE,     "STORAGE_DEVICE_ERASE_FAILURE"},
    { EMMC_COMMIT_EXTRAS_FAILURE,       "EMMC_COMMIT_EXTRAS_FAILURE"},
    { EMMC_FW_UPDATE_FAILURE,           "EMMC_FW_UPDATE_FAILURE"},
    { USB_READ_FAILURE,                 "USB_READ_FAILURE"},
    { USB_WRITE_FAILURE,                "USB_WRITE_FAILURE"},
    { DIGITAL_SIGNATURE_DID_NOT_PASS,   "DIGITAL_SIGNATURE_DID_NOT_PASS"},
    { PACKET_HASH_MISMATCH,             "PACKET_HASH_MISMATCH"},
    { HANDLE_CONFIGURE_FAILURE,         "HANDLE_CONFIGURE_FAILURE"},
    { HANDLE_STORAGE_INFO_FAILURE,      "HANDLE_STORAGE_INFO_FAILURE"},
    { HANDLE_PEEK_FAILURE,              "HANDLE_PEEK_FAILURE"},
    { HANDLE_POKE_FAILURE,              "HANDLE_POKE_FAILURE"},
    { HANDLE_ERASE_FAILURE,             "HANDLE_ERASE_FAILURE"},
    { HANDLE_FIRMWARE_PROGRAM_FAILURE,  "HANDLE_FIRMWARE_PROGRAM_FAILURE"},
    { HANDLE_PATCH_FAILURE,             "HANDLE_PATCH_FAILURE"},
    { HANDLE_GET_DIGEST_FAILURE,        "HANDLE_GET_DIGEST_FAILURE"},
    { HANDLE_PROGRAM_FAILURE,           "HANDLE_PROGRAM_FAILURE"},
    { XML_PACKET_TOO_LARGE,             "XML_PACKET_TOO_LARGE"},
    { SERIAL_NUM_OF_DEVICE_INCORRECT,   "SERIAL_NUM_OF_DEVICE_INCORRECT"},
};

#define MAX_ATTR_NAME_SIZE 32
#define MAX_ATTR_RAW_SIZE 64

struct Attributes_Struct
{
        char    Name[MAX_ATTR_NAME_SIZE];				// i.e. "MaxPayloadSizeToTargetInBytes"
        char    Raw[MAX_ATTR_RAW_SIZE];   // i.e. "8192"
        void   *pValue;
        SIZE_T  Min;
        SIZE_T  Max;
        SIZE_T  MultipleOf;
	SIZE_T  SizeOfpStr;
        char    *pStr;
        char    Type;           // i.e. "i" for integer, "s" for string, "x" for special, "t" for SIZE_T
        char    Assigned;       // i.e. Flag indicating if it was just assigned
};


// Declare the variables we care about

#ifdef TARGET_HAS_UFS
storage_device_extras_t storage_extras;

struct UFS_LUN_Var
{
    SIZE_T LUNum;
    SIZE_T bLUEnable;
    SIZE_T bBootLunID;
    SIZE_T bLUWriteProtect;
    SIZE_T bMemoryType;
    SIZE_T size_in_KB;
    SIZE_T bDataReliability;
    SIZE_T bLogicalBlockSize;
    SIZE_T bProvisioningType;
    SIZE_T wContextCapabilities;
};

struct UFS_LUN_Var UFS_LUN_Var_Struct;
#endif

struct Attributes_Struct AllAttributes[] = {
        {"Verbose",                             "", (SIZE_T *)&fh.attrs.Verbose,                       0,0,1,0, NULL, 'i', 0 },
        {"MaxPayloadSizeToTargetInBytes",       "", (SIZE_T *)&fh.attrs.MaxPayloadSizeToTargetInBytes, 0,0,512,0, NULL, 'i', 0 },
        {"MaxDigestTableSizeInBytes",           "", (SIZE_T *)&fh.attrs.MaxDigestTableSizeInBytes,     0,0,512,0, NULL, 'i', 0 },
        {"AckRawDataEveryNumPackets",           "", (SIZE_T *)&fh.attrs.AckRawDataEveryNumPackets,     0,0,1,0, NULL, 'i', 0 },
        {"delayinseconds",                      "", (SIZE_T *)&fh.attrs.delayinseconds,                0,0,1,0, NULL, 'i', 0 },
        {"address64",                           "", (SIZE_T *)&fh.attrs.address64,                     0,0,1,0, NULL, 'i', 0 },
        {"value64",                             "", (SIZE_T *)&fh.attrs.value64,                       0,0,1,0, NULL, 'i', 0 },
        //{"storagedrive",                        "", (SIZE_T *)&fh.attrs.storagedrive,                  0,0,1,0, NULL, 'i', 0 },
        {"storagedrive",                        "", (SIZE_T *)&fh.attrs.physical_partition_number,     0,0,1,0, NULL, 'i', 0 },
        {"SECTOR_SIZE_IN_BYTES",                "", (SIZE_T *)&fh.attrs.SECTOR_SIZE_IN_BYTES,          0,0,512,0, NULL, 'i', 0 },
        {"byte_offset",                         "", (SIZE_T *)&fh.attrs.byte_offset,                   0,0,1,0, NULL, 'i', 0 },
        {"physical_partition_number",           "", (SIZE_T *)&fh.attrs.physical_partition_number,     0,0,1,0, NULL, 'i', 0 },
        {"size_in_bytes",                       "", (SIZE_T *)&fh.attrs.size_in_bytes,                 0,0,1,0, NULL, 'i', 0 },
        {"num_partition_sectors",               "", (SIZE_T *)&fh.attrs.num_partition_sectors,         0,0,1,0, NULL, 'i', 0 },
        {"PAGES_PER_BLOCK",                     "", (SIZE_T *)&fh.attrs.PAGES_PER_BLOCK,               0,0,1,0, NULL, 'i', 0 },  //for nand deviceprogrammer
        {"file_sector_offset",                  "", (SIZE_T *)&fh.attrs.file_sector_offset,            0,0,1,0, NULL, 'i', 0 },   // 14

        {"ZlpAwareHost",                        "", (SIZE_T *)&fh.attrs.ZlpAwareHost,                  0,0,1,0, NULL, 'i', 0 },
        {"SkipWrite",                           "", (SIZE_T *)&fh.attrs.SkipWrite,                     0,0,1,0, NULL, 'i', 0 },
        {"BufferWrites",                        "", (SIZE_T *)&fh.attrs.BufferWrites,                     0,0,1,0, NULL, 'i', 0 },
        //{"AckRawData",                          "", (SIZE_T *)&fh.attrs.AckRawData,                    0,0,1,0, NULL, 'i', 0 },
        {"AlwaysValidate",                      "", (SIZE_T *)&fh.attrs.AlwaysValidate,                0,0,1,0, NULL, 'i', 0 },
        {"commit",                              "", NULL,                                       0,0,1,sizeof(fh.attrs.Commit), (char *)fh.attrs.Commit, 'x', 0 }, // string convert to fh.attrs.commit
        //{"display",                             "", (SIZE_T *)&fh.attrs.display,                       0,0,1,0, NULL, 'i', 0 },
        //{"read_back_verify",                    "", (SIZE_T *)&fh.attrs.read_back_verify,              0,0,1,0, NULL, 'i', 0 },
        {"TestWritePerformance",                "", (SIZE_T *)&fh.attrs.TestWritePerformance,          0,0,1,0, NULL, 'i', 0 },
        {"TestReadPerformance",                 "", (SIZE_T *)&fh.attrs.TestReadPerformance,           0,0,1,0, NULL, 'i', 0 },
        {"TestDigestPerformance",               "", (SIZE_T *)&fh.attrs.TestDigestPerformance,         0,0,1,0, NULL, 'i', 0 },   // 20
        {"SkipStorageInit",                     "", (SIZE_T *)&fh.attrs.SkipStorageInit,               0,0,1,0, NULL, 'i', 0 },	// <configure SkipStorageInit="1"
        {"SkipSettingMinClocks",                "", (SIZE_T *)&fh.attrs.SkipSettingMinClocks,          0,0,1,0, NULL, 'i', 0 },	// <configure SkipSettingMinClocks="1"
        {"SkipSettingMaxClocks",                "", (SIZE_T *)&fh.attrs.SkipSettingMaxClocks,          0,0,1,0, NULL, 'i', 0 },	// <configure SkipSettingMaxClocks="1"
        {"actual_size_in_bytes",                "", (SIZE_T *)&fh.attrs.actual_size_in_bytes,          0,0,1,0, NULL, 'i', 0 },	// <configure actual_size_in_bytes="1234"
        {"ecc_enabled",                  		"", (SIZE_T *)&fh.attrs.ecc_enabled,            0,0,1,0, NULL, 'i', 0 },	//for nand deviceprogrammer
        {"get_spare",                  			"", (SIZE_T *)&fh.attrs.get_spare,            0,0,1,0, NULL, 'i', 0 },	//for nand deviceprogrammer
        {"bad_block_at_end",                  	"", (SIZE_T *)&fh.attrs.bad_block_at_end,            0,0,1,0, NULL, 'i', 0 },	//for nand deviceprogrammer

#ifdef TARGET_HAS_EMMC

        // eMMC GPP creation
        {"DRIVE4_SIZE_IN_KB",                   "", (SIZE_T *)&storage_extras.emmc_extras.GPP_size[0], 	0,0,512,0, NULL, 'w', 0 },    // 24
        {"DRIVE5_SIZE_IN_KB",                   "", (SIZE_T *)&storage_extras.emmc_extras.GPP_size[1], 	0,0,512,0, NULL, 'w', 0 },
        {"DRIVE6_SIZE_IN_KB",                   "", (SIZE_T *)&storage_extras.emmc_extras.GPP_size[2], 	0,0,512,0, NULL, 'w', 0 },
        {"DRIVE7_SIZE_IN_KB",                   "", (SIZE_T *)&storage_extras.emmc_extras.GPP_size[3], 	0,0,512,0, NULL, 'w', 0 },
        {"ENH_SIZE",                            "", (SIZE_T *)&storage_extras.emmc_extras.ENH_size,    	0,0,1,0,   NULL, 'w', 0 },
        {"ENH_START_ADDR",                      "", (SIZE_T *)&storage_extras.emmc_extras.ENH_start_addr, 0,0,1,0,   NULL, 'w', 0 },
        {"GPP_ENH_FLAG",                        "", (SIZE_T *)&storage_extras.emmc_extras.GPP_enh_flag, 	0,0,1,0,   NULL, 'b', 0 },    // 30
#endif

#ifdef TARGET_HAS_UFS
        // UFS LUN creation
        {"bNumberLU",                   		"", (byte *)&storage_extras.ufs_extras.bNumberLU, 	    0,0,1,0,   NULL, 'b', 0 },
        {"bBootEnable",                   		"", (byte *)&storage_extras.ufs_extras.bBootEnable,	    0,0,1,0,   NULL, 'b', 0 },
        {"bDescrAccessEn",                 		"", (byte *)&storage_extras.ufs_extras.bDescrAccessEn,  0,0,1,0,   NULL, 'b', 0 },
        {"bInitPowerMode",                 		"", (byte *)&storage_extras.ufs_extras.bInitPowerMode,  0,0,1,0,   NULL, 'b', 0 },
        {"bHighPriorityLUN",               		"", (byte *)&storage_extras.ufs_extras.bHighPriorityLUN,	0,0,1,0,   NULL, 'b', 0 },
        {"bSecureRemovalType",             		"", (byte *)&storage_extras.ufs_extras.bSecureRemovalType, 	0,0,1,0,   NULL, 'b', 0 },
        {"bInitActiveICCLevel",            		"", (byte *)&storage_extras.ufs_extras.bInitActiveICCLevel, 0,0,1,0,   NULL, 'b', 0 },
        {"wPeriodicRTCUpdate",            		"", (short *)&storage_extras.ufs_extras.wPeriodicRTCUpdate, 	0,0,1,0,   NULL, 'n', 0 },
        {"bConfigDescrLock",            		"", (byte *)&storage_extras.ufs_extras.bConfigDescrLock, 	0,0,1,0,   NULL, 'b', 0 },    // 39

        // These vars are handled in ParseComplicatedAttributes when (CurrentHandlerFunction==handleStorageExtras)
        {"LUNum",            					"", (byte *)&UFS_LUN_Var_Struct.LUNum, 					0,7,1,0,   NULL, 'i', 0 },
        {"bLUEnable",            				"", (byte *)&UFS_LUN_Var_Struct.bLUEnable, 				0,0,1,0,   NULL, 'b', 0 },
        {"bBootLunID",            				"", (byte *)&UFS_LUN_Var_Struct.bBootLunID, 			0,0,1,0,   NULL, 'b', 0 },
        {"bLUWriteProtect",            			"", (byte *)&UFS_LUN_Var_Struct.bLUWriteProtect, 		0,0,1,0,   NULL, 'b', 0 },
        {"bMemoryType",            				"", (byte *)&UFS_LUN_Var_Struct.bMemoryType, 			0,0,1,0,   NULL, 'b', 0 },
        {"size_in_KB",            				"", (SIZE_T *)&UFS_LUN_Var_Struct.size_in_KB, 			0,0,1,0,   NULL, 'i', 0 },
        {"bDataReliability",           			"", (byte *)&UFS_LUN_Var_Struct.bDataReliability, 		0,0,1,0,   NULL, 'b', 0 },
        {"bLogicalBlockSize",            		"", (byte *)&UFS_LUN_Var_Struct.bLogicalBlockSize, 		0,0,1,0,   NULL, 'b', 0 },
        {"bProvisioningType",            		"", (byte *)&UFS_LUN_Var_Struct.bProvisioningType, 		0,0,1,0,   NULL, 'b', 0 },
        {"wContextCapabilities",            	"", (short *)&UFS_LUN_Var_Struct.wContextCapabilities, 	0,0,1,0,   NULL, 'n', 0 },    // 49
#endif
        {"MemoryName",                          "", NULL,                                       0,0,1,sizeof(fh.attrs.MemoryName), (char *)fh.attrs.MemoryName, 's', 0 },
        {"TargetName",                          "", NULL,                                       0,0,1,sizeof(fh.attrs.TargetName), (char *)fh.attrs.TargetName, 's', 0 },
        {"filename",                            "", NULL,                                       0,0,1,sizeof(fh.attrs.filename), (char *)fh.attrs.filename,   's', 0 },
        {"value",                               "", NULL,                                       0,0,1,sizeof(fh.attrs.value), (char *)fh.attrs.value,      's', 0 },   // 53

        // x means it needs special processing later, as in start_sector="NUM_DISK_SECTORS-33."
        {"start_sector",                        "", (SIZE_T *)&fh.attrs.start_sector,                  0,0,1,0, NULL, 'x', 0 },   // 54
};




//#define XML_HEADER_LENGTH 47  // 47 does NOT include null
#define XML_HEADER_LENGTH 40    // 40 does NOT include null
#define XML_TAIL_LENGTH 9               // 9 DOES include null

static const char xml_header[XML_HEADER_LENGTH] = "<\?xml version=\"1.0\" encoding=\"UTF-8\" \?>\n";
// static const char xml_tail[XML_TAIL_LENGTH]     = "\n</data>"; unused

//extern uint32 Image$$SBL1_DEVICEPROGRAMMER_USB_ZI$$Base;

//extern uint32 USB_ZI_START_ADDR;  
//extern uint32 Image$$SBL1_DEVICEPROGRAMMER_USB_ZI$$ZI$$Length;


/* Temporary bringup function to clear the USB Buffers. */
void deviceprogrammer_zi_buffers (void) {
#ifdef FEATURE_BOOT_EXTERN_DEVICEPROGRAMMER_DDR_COMPLETED
        // Since we don't know size or start of USB ZI, zero from known positions DLOAD to SCL_DDR_BOOT_LOG_META_INFO_BASE
    // This would be zeroed next anyway on regular SBL loading
        void *buf_start = (void *)SCL_DLOAD_BUFFERS_BASE;
        SIZE_T  size = SCL_DDR_BOOT_LOG_META_INFO_BASE - SCL_DLOAD_BUFFERS_BASE;
#else
        //void *buf_start = (void *)SBL1_DEVICEPROGRAMMER_USB_ZI_BASE;
        //void *buf_start = (void *)&Image$$SBL1_DEVICEPROGRAMMER_USB_ZI$$Base;
        void *buf_start =  (void*)USB_ZI_START_ADDR;
        // HACK -- We don't know size of USB ZI, .map file says 0xa284, pick 0x10000 to be safe.
        //SIZE_T  size = 0x10000;
        SIZE_T  size = 2 * FIREHOSE_CHANNEL_BUFFER_SIZE; 
        //SIZE_T  size = (unsigned int)&Image$$SBL1_DEVICEPROGRAMMER_USB_ZI$$ZI$$Length;
#endif

        memset (buf_start, 0, size);
}

static void firehoseResetValidationVariables() {
    fh.num_packets_received = 0;

    fh.validation_hash_buffer_num_hashes = 0;
    fh.validation_hash_buffer_capacity = sizeof(fh.validation_hash_buffer) /
                        sizeof(fh.validation_hash_value);
    fh.validation_hash_buffer_new_capacity = fh.validation_hash_buffer_capacity;

    fh.validation_hash_buffer_index = 0;
    fh.validation_table_count = 0;
    fh.validation_signed_hash_received = FALSE;
}

boolean initFirehoseStorage(void){

	kick_watchdog();

    deviceprogrammer_flash_device_init_data(&(fh.store_dev));
    return TRUE;
}


void initFirehoseProtocol()
{

#ifdef FEATURE_FIREHOSE_VALIDATION_ENABLED
    fh.validation_enabled = TRUE;
#else
    fh.validation_enabled = FALSE;
#endif

    fh.tx_buffer = transmit_buffer;
    // Channel variables
    fh.channel_buffer[0] = main_channel_buffer_A;
    fh.channel_buffer[1] = main_channel_buffer_B;
    fh.channel_error_code = 0;
    fh.channel_bytes_read = 0;
    fh.channel_read_completed = FALSE;
    //fh.channel_total_bytes_read = 0;
    fh.channel_write_completed = FALSE;
    //fh.channel_bytes_written = 0;
    //fh.channel_total_bytes_written = 0;
    fh.channel_buffer_capacity = FIREHOSE_CHANNEL_BUFFER_SIZE;
    //fh.channel_num_errors = 0;
    fh.channel_buffer_queued = FALSE;
    fh.channel_buffer_to_use = 0;

    fh.debug_log_position = 0;


    //xmlInitReader(&(fh.xml_reader), NULL, 0);
    //xmlInitWriter(&(fh.xml_writer),
    //             fh.tx_buffer,
    //             FIREHOSE_TX_BUFFER_SIZE);


    //fh.skip_storage_writes = FALSE;
    //fh.hash_in_non_secure = FALSE;
    //fh.verbose = FALSE;
    //fh.ack_raw_data_every = 0;

    firehoseResetValidationVariables();
}

void debugMessage(const char* format, ...)
{
    char *temp_log_buffer = (char *) fh.debug_log_buffer[fh.debug_log_position];
    SIZE_T buffer_space = FIREHOSE_DEBUG_LOG_MESSAGE_SIZE;

    va_list args;
    va_start (args, format);

    vsnprintf(temp_log_buffer,
              buffer_space,
              format,
              args);
    va_end (args);
    fh.debug_log_position = (fh.debug_log_position + 1) % FIREHOSE_NUM_DEBUG_LOG_MESSAGES;
}

static void packet_handle_incoming_buf (uint32 bytes_read, uint32 err_code) {
    debugMessage("cback bytes_read=%u err_code=%u", bytes_read, err_code);
    fh.channel_error_code = err_code;
    if (err_code != BULK_SUCCESS) {
        fh.channel_bytes_read = 0;
        //fh.channel_num_errors += 1;
        //qhsusb_al_bulk_cancel_rx();
    }
    else {
        fh.channel_bytes_read = bytes_read;
        fh.num_packets_received += 1;
    }
    //fh.channel_total_bytes_read += bytes_read;
    fh.channel_read_completed = TRUE;
    return;
}

static firehose_error_t readChannel(byte** packet_ptr, SIZE_T bytes_to_read, SIZE_T *bytes_read, boolean queue_only) {
    // Since the 'channel' variables are directly manipulated here, they must not be used by clients such
    // as handleProgram directly. Only the copies made by this function (packet_ptr, bytes_read) must
    // be used by those client functions

    if (fh.channel_buffer_queued == FALSE)
    {
        debugMessage("queue %lld", bytes_to_read);
        //qhsusb_al_bulk_receive(fh.channel_buffer[fh.channel_buffer_to_use], bytes_to_read, packet_handle_incoming_buf, &fh.channel_error_code);
		qusb_al_bulk_receive(fh.channel_buffer[fh.channel_buffer_to_use], bytes_to_read, packet_handle_incoming_buf, &fh.channel_error_code);
        if (fh.channel_error_code != BULK_SUCCESS)
        {
            logMessage("USB read failed - qhsusb_al_bulk_receive() gave channel error code %u",fh.channel_error_code);
            MyErrorMessage(USB_READ_FAILURE);
            return FIREHOSE_TRANSPORT_ERROR;
        }
        fh.channel_read_completed = FALSE;
        fh.channel_bytes_read = 0;
        fh.channel_buffer_queued = TRUE;
    }
    if (queue_only == TRUE)
        return FIREHOSE_SUCCESS;

    while (fh.channel_read_completed == FALSE)
    {
        //qhsusb_al_bulk_poll();
		qusb_al_bulk_poll();
    }

    if (fh.channel_bytes_read > fh.channel_buffer_capacity)
    {
        debugMessage("read fh.channel_bytes_read=%i fh.channel_buffer_capacity=%i", fh.channel_bytes_read, fh.channel_buffer_capacity);
        return FIREHOSE_TRANSPORT_ERROR;
    }

    *bytes_read = fh.channel_bytes_read;
    *packet_ptr = fh.channel_buffer[fh.channel_buffer_to_use];
    fh.channel_buffer_queued = FALSE;
    fh.channel_buffer_to_use = 1 - fh.channel_buffer_to_use;

    if (fh.channel_error_code != BULK_SUCCESS)
    {
        logMessage("USB read failed - qhsusb_al_bulk_receive() gave channel error code %u",fh.channel_error_code);
        MyErrorMessage(USB_READ_FAILURE);
        return FIREHOSE_TRANSPORT_ERROR;
    }

    return FIREHOSE_SUCCESS;
}

static void packet_handle_outgoing_buf(uint32 bytes_written, uint32 err_code) {
    //fh.channel_bytes_written = bytes_written;
    //fh.channel_total_bytes_written += bytes_written;
    fh.channel_error_code = err_code;
    fh.channel_write_completed = TRUE;
    return;
}

static firehose_error_t writeChannel(byte* buffer, SIZE_T length)
{
    fh.channel_write_completed = FALSE;

    //qhsusb_al_bulk_transmit(buffer, length, packet_handle_outgoing_buf, &fh.channel_error_code);
    debugMessage("bulk_tx() buffer at 0x%X", buffer);
    debugMessage("bulk_tx() length %lld", length);

	qusb_al_bulk_transmit(buffer, length, packet_handle_outgoing_buf, &fh.channel_error_code);

    if (fh.channel_error_code != BULK_SUCCESS)
    {
        logMessage("USB write failed - qhsusb_al_bulk_transmit() gave channel error code %u",fh.channel_error_code);
        MyErrorMessage(USB_WRITE_FAILURE);
        return FIREHOSE_TRANSPORT_ERROR;
    }

    while (fh.channel_write_completed == FALSE)
    {
        //qhsusb_al_bulk_poll();
		qusb_al_bulk_poll();
    }

    return FIREHOSE_SUCCESS;
}

static firehose_error_t sendTransmitBuffer()
{
	firehose_error_t retval;
    debugMessage("sendTransmitBuffer() fh.tx_buffer at 0x%X", fh.tx_buffer);
    retval = writeChannel(fh.tx_buffer, strlen((const char *)fh.tx_buffer));
    return retval;
}
/*
static firehose_error_t sendXMLBuffer() {
    firehose_error_t retval = writeChannel(fh.xml_writer.buffer, fh.xml_writer.write_position);
    xmlWriterReset(&fh.xml_writer);
    return retval;
}
*/
// format: C string that contains a format string that follows the same specifications as format in printf

#ifdef _MSC_VER
#define dbg(log_level, fmt, ...) MyLog(log_level, __FUNCTION__, __LINE__, fmt, __VA_ARGS__)
#else
#define dbg(log_level, fmt ...) logMessage(fmt)
#endif


void logMessage(const char* format, ...) {
    int retval = 0;
    char temp_log_buffer[FIREHOSE_TEMP_LOG_BUFFER_SIZE] = {0};  // no single message > 256 bytes
    SIZE_T buffer_space = sizeof(temp_log_buffer);

    va_list args;
    va_start (args, format);

    retval = vsnprintf(temp_log_buffer,
                       buffer_space,
                       format,
                       args);
    va_end (args);


    InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
    AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,"<log value=\"", FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,temp_log_buffer, FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,"\"/>\n", FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,"</data>", FIREHOSE_TX_BUFFER_SIZE);
    sendTransmitBuffer();

}

void ErrorMessage(unsigned int LineNumber, firehose_error_code_t ErrorCode)
{
    unsigned int i = 0, found = 0;

    for(i=0;i<FH_ERR_MAX;i++)
    {
        if(ErrorCode == AllErrorsStruct[i].ErrorNum)
        {
            found = 1;
            break;
        }
    }

    if(found)
        logMessage("ERROR %d: Line %d: %s", ErrorCode, LineNumber, AllErrorsStruct[i].pErrorMessage );
    else
        logMessage("ERROR %d: Line %d: Unknown error is *not* in AllErrorsStruct", ErrorCode, LineNumber);

}

static firehose_error_t sendResponse(response_t response)
{

        InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
        AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
        if(response==ACK)
                AppendToBuffer(fh.tx_buffer,"<response value=\"ACK\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);
        else
                AppendToBuffer(fh.tx_buffer,"<response value=\"NAK\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);

        sendTransmitBuffer();

        if(response==ACK)
                return FIREHOSE_SUCCESS;
        else
                return FIREHOSE_ERROR;


    //return sendResponseFields(response, 0);
}


static void logDigest(char* prefix, byte* digest, SIZE_T length) {
    int i = 0;
    int written;
    char log_string[FIREHOSE_TEMP_BUFFER_SIZE] = { 0 };

    if (sizeof(log_string) < ((length * 2) + strlen(prefix) + 1)) {
        return;
    }

    written = snprintf(log_string,
                       sizeof(log_string),
                       "%s",
                       prefix);
    while (written < sizeof(log_string) && i < length) {
        written += snprintf(log_string + written,
                            sizeof(log_string) - written,
                            "%02X",
                            digest[i]);
        i++;
    }

    logMessage(log_string);
}


static void firehoseResetValidation() {
    firehoseResetValidationVariables();
    logMessage("Reset validation state. Expecting Digital signature");
}


static firehose_error_t recvNextPacket(byte** packet_ptr, SIZE_T bytes_to_read,SIZE_T *bytes_read, boolean queue_only)
{
    boolean packet_validated = FALSE;
    byte* hash_location;
    SIZE_T signed_payload_size;
    SIZE_T len_copied;
    firehose_error_t read_retval = FIREHOSE_SUCCESS;

    volatile SIZE_T THIS_bytes_to_read = bytes_to_read;
    volatile SIZE_T THIS_bytes_read    = *bytes_read;


    if(fh.validation_enabled == TRUE)
    {

        // This code section handles Validated programming
        // if a failure occurs call the function to reset
        // all validation related variables to their initial
        // states

            while(packet_validated == FALSE)
            {
               if (fh.validation_signed_hash_received == FALSE)
               {
                  // To be here means we are recieving the FIRST SIGNED HASH TABLE
                  // It will be in channel A, i.e. fh.channel_buffer[0], or fh.channel_buffer[ fh.channel_buffer_to_use ]

                  logMessage("VIP - Validated Image Programming is enabled - Validation is enabled.");


                  // Signed Digest Table will be in main_channel_buffer_A
                  read_retval = readChannel(packet_ptr, FIREHOSE_SIGNED_HASH_PACKET_SIZE, bytes_read, queue_only);
                  if (read_retval != FIREHOSE_SUCCESS)
                  {
                    firehoseResetValidation();
                    return read_retval;
                  }

                  if (queue_only == TRUE)
                    return FIREHOSE_SUCCESS;

                // Verify the data in the receive buffer, then copy the data
                // into validation_hash_buffer
                if (authenticateSignedHash(*packet_ptr, *bytes_read, &hash_location, &signed_payload_size) == FALSE)
                {
                    logMessage("Failed to authenticate Digital Signature, resetting validation state");
                    MyErrorMessage(DIGITAL_SIGNATURE_DID_NOT_PASS);
                    sendResponse(NAK);

                    firehoseResetValidation();
                    return FIREHOSE_VALIDATION_ERROR;
                }

                  // To be this far means the SIGNED DIGEST TABLE passed
                  fh.validation_signed_hash_received = TRUE;

                  // Resetting num_pacets to 0, we don't count the first signed digest table
                  fh.num_packets_received = 0;

                  fh.validation_hash_buffer_num_hashes = signed_payload_size / sizeof(fh.validation_hash_value);  // if this is > 54, can't be true assert(validation_hash_buffer_num_hashes>54)

                  if (fh.validation_hash_buffer_num_hashes>54)
                  {
                      logMessage("It appears your First Hash Table has more than 54 hashes, which should be impossible.");
                      logMessage("Your first hash table has %d hashes. Is it DIGITALLY SIGNED??",fh.validation_hash_buffer_num_hashes);
                      sendResponse(NAK);
                      firehoseResetValidation();
                      return FIREHOSE_VALIDATION_ERROR;
                  }

                  // Ex. Our hash_buffer can hold 256 hashes. Therefore assuming we got 54 hashes in the first signed table,
                  // we want to load them as the LAST 54 hashes in our table, meaning starting at location 202
                  memscpy( &fh.validation_hash_buffer[fh.validation_hash_buffer_capacity - fh.validation_hash_buffer_num_hashes],
                           sizeof(fh.validation_hash_buffer),
                           hash_location,
                           signed_payload_size);

                  fh.validation_hash_buffer_index = fh.validation_hash_buffer_capacity - fh.validation_hash_buffer_num_hashes;
                  sendResponse(ACK);  // set breakpoint here to inspect validation_hash_buffer
                  continue;
           }
           else
           {
               if (fh.validation_hash_buffer_index == fh.validation_hash_buffer_capacity - 1)
               {
                   read_retval = readChannel(packet_ptr, fh.validation_hash_buffer_new_capacity * sizeof(fh.validation_hash_value), bytes_read, queue_only);
               }
               else
               {
                    // This is the *real* XML read now. Since above we discovered we had to read the digest table
                    read_retval = readChannel(packet_ptr, bytes_to_read, bytes_read, queue_only);
               }

               if (read_retval != FIREHOSE_SUCCESS)
               {
                   firehoseResetValidation();
                   return read_retval;
               }

               if (queue_only == TRUE)
                   return FIREHOSE_SUCCESS;

               if (fh.validation_hash_buffer_num_hashes == 0)
               {
                   logMessage("No more hashes to validate against, resetting validation state.");
                   sendResponse(NAK);

                   firehoseResetValidation();
                   return FIREHOSE_VALIDATION_ERROR;
               }

               PerformSHA256(*packet_ptr, *bytes_read, fh.validation_hash_value);
               //PerformSHA256HW(*packet_ptr, *bytes_read, fh.validation_hash_value);

                if ( memcmp( fh.validation_hash_value, fh.validation_hash_buffer[fh.validation_hash_buffer_index], sizeof(fh.validation_hash_value)) != 0)
                {
                    logMessage("Hash of packet of size %lld bytes that target sent does not match hash in table. Rejecting this packet. See log",*bytes_read);

                    // this is what was rejected - fh.channel_buffer[ fh.channel_buffer_to_use ]); //main_channel_buffer_B
                    logDigest("Expected:      ", fh.validation_hash_buffer[fh.validation_hash_buffer_index], sizeof(fh.validation_hash_value));
                    logDigest("Found instead: ", fh.validation_hash_value, sizeof(fh.validation_hash_value));
                    logMessage("(P%04d) (H%04d) Using Table %lld", (int)fh.num_packets_received - 1, (int)fh.validation_hash_buffer_index, fh.validation_table_count);
                    logMessage("Make sure that you are sending the same command used when generating the hash with --createdigests");
                    logMessage("Resetting validation state.");


                    MyErrorMessage(PACKET_HASH_MISMATCH);
                    sendResponse(NAK);

                    firehoseResetValidation();
                    return FIREHOSE_VALIDATION_ERROR;
                }


                if(fh.attrs.Verbose == TRUE || ConfigureCommandNotReceivedYet)
                {
                    logMessage("(P%04d) (H%04d) Using Table %lld", (int)fh.num_packets_received - 1, (int)fh.validation_hash_buffer_index, fh.validation_table_count);
                    logMessage("VIP - HASH of packet ACCEPTED");
                }

               fh.validation_hash_buffer_num_hashes--;

               if (fh.validation_hash_buffer_index == fh.validation_hash_buffer_capacity - 1)
               {
                   // we're at the end of current hash buffer; this packet is the new one, so store it
                   len_copied = MIN( sizeof(fh.validation_hash_buffer), *bytes_read);

                   memscpy(fh.validation_hash_buffer, sizeof(fh.validation_hash_buffer), *packet_ptr, len_copied);

                   fh.validation_hash_buffer_index       = 0;
                   fh.validation_hash_buffer_num_hashes  = len_copied / sizeof(fh.validation_hash_value);

                   if (fh.validation_hash_buffer_capacity != fh.validation_hash_buffer_new_capacity)
                   {
                       fh.validation_hash_buffer_capacity = fh.validation_hash_buffer_new_capacity;
                   }

                   if (fh.validation_hash_buffer_num_hashes < 2)
                   {
                       debugMessage("read hashes %lld", fh.validation_hash_buffer_num_hashes);
                   }

                   fh.validation_table_count++;
                   sendResponse(ACK);  // set breakpoint here to inspect validation_hash_buffer

                   continue;
               }
               else
               {
                   fh.validation_hash_buffer_index++;
                   packet_validated = TRUE;
               } // end if (fh.validation_hash_buffer_index == fh.validation_hash_buffer_capacity - 1)
           } // end if (fh.validation_signed_hash_received == FALSE)
        } // end while(packet_validated == FALSE)
    }
    else
    {
        read_retval = readChannel(packet_ptr, bytes_to_read, bytes_read, queue_only);
        if (read_retval != FIREHOSE_SUCCESS)
        {
            return read_retval;
        }

        if (queue_only == TRUE)
            return FIREHOSE_SUCCESS;

        if (fh.attrs.AlwaysValidate == TRUE)    // hash in non secure mode to see speed impact
        {
            //PerformSHA256HW(*packet_ptr, *bytes_read, fh.validation_hash_value);
            PerformSHA256(*packet_ptr, *bytes_read, fh.validation_hash_value);
        }
    } // end if (fh.validation_enabled == TRUE)
    return FIREHOSE_SUCCESS;
}

static firehose_error_t queueNextPacket(SIZE_T bytes_to_read) {
    return recvNextPacket(NULL, bytes_to_read, NULL, TRUE);
}

static firehose_error_t getNextPacket(byte** packet_ptr, SIZE_T bytes_to_read, SIZE_T *bytes_read) {
    return recvNextPacket(packet_ptr, bytes_to_read, bytes_read, FALSE);
}

// Parse a string sector value in valueArray and store in parsedValue.
// attrName is name of XML attribute with this value, used in error message.
//
// Returns:
//      FALSE if sector value is non-numerical, if it exceeds the number of
//      sectors in specified partition, or if partition is invalid
//      TRUE if sector value is valid
static boolean parseSectorValue(char* valueArray,
                          SIZE_T value_array_size,
                          SIZE_T *parsedValue,
                          SIZE_T partition,
                          char *attrName) {
    boolean num_conversion;
    SIZE_T num_partition_sectors;

    memset(temp_buffer,0,sizeof(temp_buffer));	// clear this out


  
	#if TARGET_HAS_UFS || TARGET_HAS_EMMC
  // Skip for NAND deviceprogrammer

 	if (fh.attrs.SkipStorageInit == FALSE)
    {

        if (FALSE == storage_device_get_num_partition_sectors(&fh.store_dev, partition, &num_partition_sectors)) 
            return FALSE;

    }
	#endif

    simpleStrReplace(valueArray,
                         ".",
                         "");

	#if TARGET_HAS_UFS || TARGET_HAS_EMMC
    // Skip for NAND deviceprogrammer
	    if (strstr(valueArray, "NUM_DISK_SECTORS") != NULL) {
	        snprintf((char *)temp_buffer, sizeof(temp_buffer), SIZE_T_FORMAT, num_partition_sectors);
	        simpleStrReplace(valueArray,
	                         "NUM_DISK_SECTORS",
	                         (const char *) temp_buffer);
	        //num_conversion = parseExpression(valueArray, parsedValue);
		num_conversion = MyParseExpression(valueArray, strlen(valueArray), parsedValue);
	    }
	    else
	    {
	        //num_conversion = parseExpression(valueArray, parsedValue);
		    num_conversion = MyParseExpression(valueArray, strlen(valueArray), parsedValue);
	    }
	#else
	    num_conversion = MyParseExpression(valueArray, strlen(valueArray), parsedValue);
	#endif

    if (FALSE == num_conversion)
    {
        logMessage("Can't convert attribute '%s'='%s' to number", attrName, valueArray);    // conversion to number failed
        return FALSE;
    }

    if (fh.attrs.SkipStorageInit == FALSE)
    {

       if (*parsedValue > num_partition_sectors)
       {
           logMessage("XML attribute '%s'=%lld exceeds total size of partition %lld in sectors: %lld", attrName, *parsedValue, partition, num_partition_sectors);
           return FALSE;
       }
    }
    return TRUE;
}

static firehose_error_t handleConfigure()

{

    volatile SIZE_T BreakPoint = 0;

    response_t response = ACK;

    char *memory_name;

	memset(temp_buffer,0,sizeof(temp_buffer));	// clear this out

    // Let's first clear the variables that the <configure> can

    // set, by assigning default values
    //fh.skip_storage_writes = FALSE;
    //fh.ack_raw_data_every = 0;
    //fh.hash_in_non_secure = FALSE;
    //fh.verbose = FALSE;

    // set defaults if not provided
    if (fh.attrs.MaxPayloadSizeToTargetInBytes == 0)
    {
        //logMessage("Host's payload to target size not provided or 0; using %lld", (SIZE_T)FIREHOSE_CHANNEL_BUFFER_SIZE);
        fh.attrs.MaxPayloadSizeToTargetInBytes = FIREHOSE_CHANNEL_BUFFER_SIZE;
    }

    if (fh.attrs.MaxDigestTableSizeInBytes == 0)
    {
        //logMessage("Host's hash buffer size not provided or 0; using %lld", (SIZE_T)sizeof(fh.validation_hash_buffer));
        fh.attrs.MaxDigestTableSizeInBytes = sizeof(fh.validation_hash_buffer);
    }

    if (fh.attrs.MaxPayloadSizeToTargetInBytes > FIREHOSE_CHANNEL_BUFFER_SIZE)
    {
        //logMessage("fh.attrs.MaxPayloadSizeToTargetInBytes > FIREHOSE_CHANNEL_BUFFER_SIZE");
        fh.attrs.MaxPayloadSizeToTargetInBytes = FIREHOSE_CHANNEL_BUFFER_SIZE; // correct this
        response = NAK;
    }
    else
    {
        fh.channel_buffer_capacity = fh.attrs.MaxPayloadSizeToTargetInBytes;
    }

    if (fh.attrs.MaxDigestTableSizeInBytes > sizeof(fh.validation_hash_buffer))
    {
        logMessage("Attribute '%s'=%lld cannot exceed %lld", "MaxDigestTableSizeInBytes", fh.attrs.MaxDigestTableSizeInBytes, (SIZE_T)sizeof(fh.validation_hash_buffer));
        MyErrorMessage(HANDLE_CONFIGURE_FAILURE);
        fh.attrs.MaxDigestTableSizeInBytes = sizeof(fh.validation_hash_buffer);
        response = NAK;
    }
    else {
        // TODO: MAYBE: there might be a more elegant way to handle
        // this but at the moment this is the simplest, i.e. keep a
        // separate variable and when the time comes to fetch a new
        // hash table, grab this size instead of the original size
        fh.validation_hash_buffer_new_capacity = fh.attrs.MaxDigestTableSizeInBytes / sizeof(fh.validation_hash_value);
    }

    if(fh.attrs.SkipStorageInit == TRUE) 		{        logMessage("skipping storage init requested by user");    }
    if(fh.attrs.SkipWrite == TRUE) 				{        logMessage("skipping write requested by user");    }
#ifdef USE_FIRMWARE_BUFFER
    if(fh.attrs.BufferWrites == TRUE) 		    {        logMessage("BufferWrites in the BigFWBuffer enabled");    }
#endif
    //if(fh.attrs.AckRawData == TRUE) 			{        fh.ack_raw_data_every = 1;											    }
    //if(fh.attrs.AckRawDataEveryNumPackets > 0) 	{        fh.ack_raw_data_every = fh.attrs.AckRawDataEveryNumPackets;		    }
    //if(fh.attrs.AlwaysValidate == TRUE) 		{        fh.hash_in_non_secure = TRUE;										    }
    //if(fh.attrs.Verbose == TRUE) 				{        fh.verbose = TRUE;													    }


#if TARGET_HAS_UFS || TARGET_HAS_EMMC

    if(fh.attrs.ZlpAwareHost == FALSE)
    {
        if(fh.attrs.Verbose == TRUE)
            logMessage("Calling qhsusb_al_bulk_set_zlp_mode(FALSE) since ZlpAwareHost='0'");

        qhsusb_al_bulk_set_zlp_mode(FALSE);
    }




/*
#ifndef FEATURE_FIREHOSE_SKIP_CLOCK

    // Lowering clock frequencies because otherwise eMMC card initialization sometimes fails
    // if the clock '' is set too high
    if (fh.attrs.SkipSettingMinClocks == 0)
    {
        if(fh.attrs.Verbose == TRUE)
            logMessage("Calling Clock_Init(CLOCK_BOOT_PERF_MIN, CLOCK_BOOT_PERF_MIN) - If this hangs use SkipSettingMinClocks='1' for configure");

        if (FALSE == Clock_Init(CLOCK_BOOT_PERF_MIN, CLOCK_BOOT_PERF_MIN)) {
            logMessage("FAILED Clock_Init(CLOCK_BOOT_PERF_MIN, CLOCK_BOOT_PERF_MIN) returned FALSE");
            sendResponse(NAK);

            return FIREHOSE_ERROR;
        }
    }
    else if(fh.attrs.Verbose == TRUE)
            logMessage("SKIPPING Clock_Init(CLOCK_BOOT_PERF_MIN, CLOCK_BOOT_PERF_MIN) at users request");

#endif
*/

    if(fh.attrs.SkipStorageInit == FALSE)
    {
        if(fh.attrs.Verbose == TRUE)
            logMessage("Calling storage_device_open(0x%X) - If this hangs use SkipStorageInit='1' for configure",fh.attrs.storage_type);

        if(storage_device_open(&fh.store_dev, fh.attrs.storage_type) == FALSE)
        {
            logMessage("storage_device_open() returned FALSE");
            MyErrorMessage(HANDLE_CONFIGURE_FAILURE);
            sendResponse(NAK);
            return FIREHOSE_ERROR;
        }
    }
    else
    {
        if(fh.attrs.Verbose == TRUE)
            logMessage("SkipStorageInit is TRUE, Therefore assigning fh.store_dev.current_storage_type=0x%X",fh.attrs.storage_type);

        // set anyway so we can do storage extras
        fh.store_dev.current_storage_type = fh.attrs.storage_type;

    } // end of if(fh.attrs.SkipStorageInit == FALSE)

#endif
/*
    if(fh.store_dev.current_storage_type == HOTPLUG_TYPE_UFS )
    {
        if(fh.attrs.Verbose == TRUE)
            logMessage("In handleConfigure() Calling init_ufs_params() since fh.store_dev.current_storage_type=HOTPLUG_TYPE_UFS");

        if(init_ufs_params(&fh.store_dev)==FALSE)
        {
            if(fh.attrs.Verbose == TRUE)
                logMessage("In handleConfigure() init_ufs_params() returned FALSE");
        } // end if(
    }  // end if(fh.store_dev.current_storage_type == HOTPLUG_TYPE_UFS )
*/

/*
#ifndef FEATURE_FIREHOSE_SKIP_CLOCK
    // This calls the Clock API to bump up clocks.
    // Before doing this, we need support for it in the Clock SCons
    // env.AddLibsToImage(['CLOCK_BOOT_DRIVER', 'EMMCBLD_IMAGE'],
    // ClockChipsetSBL_lib)
    // in file core\systemdrivers\clock\hw\msm8974\build\clock_sbl.scons

    if (fh.attrs.SkipSettingMaxClocks == 0)
    {
        if(fh.attrs.Verbose == TRUE)
            logMessage("Calling Clock_Init(CLOCK_BOOT_PERF_MAX, CLOCK_BOOT_PERF_MAX) - If this hangs use SkipSettingMaxClocks='1' for configure");

        if (FALSE == Clock_Init(CLOCK_BOOT_PERF_MAX, CLOCK_BOOT_PERF_MAX))
        {
            logMessage("FAILED - Clock_Init(CLOCK_BOOT_PERF_MAX, CLOCK_BOOT_PERF_MAX) returned FALSE");
            sendResponse(NAK);
            return FIREHOSE_ERROR;
        }
    }
    else if(fh.attrs.Verbose == TRUE)
        logMessage("SKIPPING Clock_Init(CLOCK_BOOT_PERF_MAX, CLOCK_BOOT_PERF_MAX) at users request");

#endif
*/

	#if TARGET_HAS_UFS || TARGET_HAS_EMMC

    switch (fh.store_dev.current_storage_type)
    {
        case HOTPLUG_TYPE_MMC:
            memory_name = "eMMC";
            break;
        case HOTPLUG_TYPE_UFS:
            memory_name = "UFS";
            break;
        default:
            memory_name = "None";
    }
	    if(fh.attrs.Verbose == TRUE)
        logMessage("memory_name set to '%s' and fh.store_dev.sector_size = %lld", memory_name,(SIZE_T)fh.store_dev.sector_size);
	#else
			memory_name = "NAND";
	#endif

    InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only

    AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
    if(response==ACK)
        AppendToBuffer(fh.tx_buffer,"<response value=\"ACK\" ", FIREHOSE_TX_BUFFER_SIZE);
    else
        AppendToBuffer(fh.tx_buffer,"<response value=\"NAK\" ", FIREHOSE_TX_BUFFER_SIZE);



    snprintf(temp_buffer,sizeof(temp_buffer),"MemoryName=\"%s\" ", memory_name);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

    snprintf(temp_buffer,sizeof(temp_buffer),"MaxPayloadSizeFromTargetInBytes=\"%d\" ", FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

    snprintf(temp_buffer,sizeof(temp_buffer),"MaxPayloadSizeToTargetInBytes=\"%llu\" ", fh.channel_buffer_capacity);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

    snprintf(temp_buffer,sizeof(temp_buffer),"MaxPayloadSizeToTargetInBytesSupported=\"%d\" ", FIREHOSE_CHANNEL_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

    snprintf(temp_buffer,sizeof(temp_buffer),"TargetName=\"%s\" ", DEVICEPROGRAMMER_TARGET_NAME);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

#ifdef DEVICEPROGRAMMER_BUILD_ID

	AppendToBuffer(fh.tx_buffer,"MinVersionSupported=\"1\" ", FIREHOSE_TX_BUFFER_SIZE);

	snprintf(temp_buffer,sizeof(temp_buffer),"Version=\"%d\" ", 1);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

    snprintf(temp_buffer,sizeof(temp_buffer),"BuildId=\"%s\" ",DEVICEPROGRAMMER_BUILD_ID);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

	snprintf(temp_buffer,sizeof(temp_buffer),"DateTime=\"%s\" ",__DATE__ " - " __TIME__);
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);

    snprintf(temp_buffer,sizeof(temp_buffer),"MaxXMLSizeInBytes=\"%lu\" ", sizeof(fh.xml_buffer));
    AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);
#endif


    AppendToBuffer(fh.tx_buffer,"/>\n</data>", FIREHOSE_TX_BUFFER_SIZE);
    sendTransmitBuffer();

    return FIREHOSE_SUCCESS;

} // end of handleConfigure


static firehose_error_t handleGetStorageInfo() {


	if (FALSE == storageDeviceGetStorageInfo(&fh.store_dev))
    {
        logMessage("getstorageinfo failed - storageDeviceGetStorageInfo() returned FALSE");
        MyErrorMessage(HANDLE_STORAGE_INFO_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }
    else {
        sendResponse(ACK);
        return FIREHOSE_SUCCESS;
    }

}

static firehose_error_t handlePower()
{
    SIZE_T  delay_time = 0;
    typedef enum {POWER_NONE, POWER_RESET, POWER_OFF, POWER_RESET_TO_EDL} power_action_t;


	/*
    if (strncasecmp((char *)fh.attrs.value, "reset_to_edl", strlen("reset_to_edl")) == 0)
    {
        power_action = POWER_RESET_TO_EDL;
        logMessage("Inside handlePower() - Requested POWER_RESET_TO_EDL - Will set PBL cookies before reset");
    }*/

    delay_time = fh.attrs.delayinseconds;
    if (delay_time < 1) {
        delay_time = 1; // At least 1 second to give time for USB messages to be sent back to PC
    }

    if (strncasecmp((char *)fh.attrs.value, "reset", strlen("reset")) == 0)
    {

        logMessage("Inside handlePower() - Requested POWER_RESET");
        sendResponse(ACK);
        delaySeconds(delay_time);
        bsp_target_reset();
    }
    else if (strncasecmp((char *)fh.attrs.value, "off", strlen("off")) == 0)
    {

        logMessage("Inside handlePower() - Requested POWER_OFF");
        sendResponse(ACK);
        delaySeconds(delay_time);
        bsp_target_poweroff();
    }

	/*
	//EDL not supported currently
	else if (power_action == POWER_RESET_TO_EDL)
    {
        logMessage("Issuing bsp_target_reset_edl() after %ld seconds, if this hangs, do you have WATCHDOG enabled?",delay_time);
        sendResponse(ACK);
        delaySeconds(delay_time);
        debugMessage("bsp_target_reset_edl()");
        //bsp_target_reset_edl();
        while(1);
    }
	*/
    logMessage("To be here means power_action was not understood with power tag. Target is *not* being reset or powered off");


    sendResponse(NAK);
    return FIREHOSE_ERROR;
    while(1);
}

#if TARGET_HAS_UFS || TARGET_HAS_EMMC

static firehose_error_t handlePeek()
{

    byte temp_buffer[FIREHOSE_TEMP_BUFFER_SIZE] = {0};
    byte another_temp_buffer[FIREHOSE_TEMP_BUFFER_SIZE] = {0};
    byte* address = (byte *) (uintptr_t) fh.attrs.address64;
    SIZE_T i,
           // Each byte will take 5 characters [0 x 0 0 space]
           bytes_per_log_message = FIREHOSE_TEMP_LOG_BUFFER_SIZE / 5;


   memset(temp_buffer,0,sizeof(temp_buffer));	// clear this out

    if (NULL == address || 0 == fh.attrs.size_in_bytes)
    {
        if (NULL == address)
            logMessage("Attribute '%s' can't equal %lld", "address", fh.attrs.address64);
        else
            logMessage("Attribute '%s' can't equal %lld", "size_in_bytes", fh.attrs.size_in_bytes);

        MyErrorMessage(HANDLE_PEEK_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }
    logMessage("Using address %p", address);
    for (i = 0; i < fh.attrs.size_in_bytes; ++i)
    {
        snprintf((char *) temp_buffer, sizeof(temp_buffer), "0x%02X ", *(address + i));
        strlcat((char *) another_temp_buffer, (const char *) temp_buffer, sizeof(another_temp_buffer));
        if ((i + 1) % bytes_per_log_message == 0 || i == fh.attrs.size_in_bytes - 1) {
            logMessage("%s", another_temp_buffer);
            another_temp_buffer[0] = NULL; //'\0';
        }
    }

    sendResponse(ACK);
    return FIREHOSE_SUCCESS;
}

static firehose_error_t handlePoke() {

    byte* address = (byte *) (uintptr_t) fh.attrs.address64;
    SIZE_T i;

    if (NULL == address || 0 == fh.attrs.size_in_bytes)
    {
        if (NULL == address)
            logMessage("Attribute '%s' can't equal %lld", "address", fh.attrs.address64);
        else
            logMessage("Attribute '%s' can't equal %lld", "size_in_bytes", fh.attrs.size_in_bytes);

        MyErrorMessage(HANDLE_POKE_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }
    if (fh.attrs.size_in_bytes > sizeof(fh.attrs.value64))
    {
        logMessage("Attribute '%s'=%lld cannot exceed %lld", "size_in_bytes", fh.attrs.size_in_bytes, sizeof(fh.attrs.value64));
        MyErrorMessage(HANDLE_POKE_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }
    logMessage("Using address %p", address);
    for (i = 0; i < fh.attrs.size_in_bytes; ++i)
    {
        *address = fh.attrs.value64 & 0xFF;
        address++;
        fh.attrs.value64 = fh.attrs.value64 >> 8;
    }

    sendResponse(ACK);
    return FIREHOSE_SUCCESS;
}

static firehose_error_t WriteSector(SIZE_T SectorNumber)
{

    SIZE_T i = 0;
    boolean retval = TRUE;
    byte* buffer = fh.channel_buffer[0];
    SIZE_T sector_size = fh.store_dev.sector_size;


    // First load the buffer with 0xAA
    for(i=0;i<sector_size;i++)
        buffer[i] = 0xAA;

    logMessage("Filling sector %lld with 0xAA",SectorNumber);
    retval = storage_device_write(&fh.store_dev, 0, buffer, SectorNumber, 1);  // start sector, num sectors
    if (retval == FALSE)
    {
        logMessage("storage_device_write() FAILED with retval=0x%X",retval);
        return FIREHOSE_ERROR;
    }

    return FIREHOSE_SUCCESS;
}

static firehose_error_t ReadSector(SIZE_T SectorNumber, byte ValueToTestFor)
{
	SIZE_T i = 0, AllIsWell = 1;
    boolean retval = TRUE;
    byte* buffer = fh.channel_buffer[0];
    SIZE_T sector_size = fh.store_dev.sector_size;
    //char temp_buffer[FIREHOSE_TEMP_BUFFER_SIZE] = {0};

	memset(temp_buffer,0,sizeof(temp_buffer));	// clear this out

    // First load the buffer with 0xFE
    for(i=0;i<sector_size;i++)
        buffer[i] = 0xFE;

    //logMessage("Reading sector %lld",SectorNumber);
    retval = storage_device_read(&fh.store_dev, 0, buffer, SectorNumber, 1);    // 1 sector
    if (retval == FALSE)
    {
        logMessage("storage_device_read() FAILED with retval=0x%X",retval);
        return FIREHOSE_ERROR;
    }

/*
    InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
    AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,"<log value=\"", FIREHOSE_TX_BUFFER_SIZE);
*/

    for(i=0;i<sector_size;i++)
    {
/*
        snprintf(temp_buffer,sizeof(temp_buffer),"0x%.2X ", buffer[i]);
        AppendToBuffer(fh.tx_buffer,temp_buffer, FIREHOSE_TX_BUFFER_SIZE);
*/
        if(buffer[i] != ValueToTestFor)
        {
            AllIsWell = 0;
            break;
        }
    }
/*
    AppendToBuffer(fh.tx_buffer,"\"/>\n", FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,"</data>", FIREHOSE_TX_BUFFER_SIZE);
    sendTransmitBuffer();
*/
    if(!AllIsWell)
    {
        logMessage("ERROR: Value read back from sector %lld at offset %d was 0x%X, which is NOT 0x%X",SectorNumber,i,buffer[i],ValueToTestFor);
        return FIREHOSE_ERROR;
    }

    logMessage("All values read back from sector %lld had the value 0x%X",SectorNumber,ValueToTestFor);

    return FIREHOSE_SUCCESS;
}



static firehose_error_t handleSetBootableStorageDrive()
{



    boolean num_conversion;

    // Declare the variables we care about
    SIZE_T bootable_drive = stringToNumber((const char *) fh.attrs.value, &num_conversion); // fh.attrs.value parsed as string
    if (FALSE == num_conversion)
    {
        logMessage("Can't convert attribute '%s'='%s' to number", "value", fh.attrs.value); // conversion to number failed
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    if(fh.attrs.Verbose == TRUE)
    {
        if(bootable_drive<(MAX_PARTITIONS_PER_DEVICE-1))
            logMessage("Calling storage_device_set_bootable_partition(%d) of size %lld sectors",bootable_drive,fh.store_dev.partition_sizes[bootable_drive]);
        else
            logMessage("Calling storage_device_set_bootable_partition(%d) - WARNING: MAX_PARTITIONS_PER_DEVICE is %d",bootable_drive,MAX_PARTITIONS_PER_DEVICE);
    }

    if (storage_device_set_bootable_partition(&fh.store_dev, bootable_drive) == TRUE)
    {
        sendResponse(ACK);
        return FIREHOSE_SUCCESS;
    }
    else
    {
        sendResponse(NAK);
        return FIREHOSE_STORAGE_ERROR;
    }

	return FIREHOSE_SUCCESS;
}

#endif

static firehose_error_t handleErase()
{

    SIZE_T start_sector = 0;
	SIZE_T num_partition_sectors = 0;
	SIZE_T start_block=0;
	SIZE_T num_blocks=0;
	SIZE_T total_block_count =0;
    int pages_per_block = 0 ;
    response_t response = NAK;


	//Validate start_sector and num_partition_sectors
	if (fh.attrs.start_sector == ATTR_INVALID_VAL)
	{
            logMessage("Attribute '%s' not provided (or -1)", "start_sector", ATTR_INVALID_VAL);    // not provided or invalid
			sendResponse(NAK);
        	return FIREHOSE_ERROR;
	}
	else
	{
		start_sector = fh.attrs.start_sector;
    }

	if (fh.attrs.num_partition_sectors == ATTR_INVALID_VAL)
	{
		logMessage("Attribute '%s' not provided (or -1)", "num_partition_sectors");   // not provided or invalid
        sendResponse(NAK);
        return FIREHOSE_ERROR;

	}
	else
	{
		num_partition_sectors = fh.attrs.num_partition_sectors;
	}

	logMessage("start_sector = %lld and num_partition_sectors =0x%x)", start_sector,num_partition_sectors);

	kick_watchdog();

	/* If both start_sector is 0 and num_partition_sectors is 0xFFFFFFFF then
	  * tag for entire chip erase*/

	if (num_partition_sectors == 0xFFFFFFFF) {

		if(start_sector == 0)
		{

			logMessage("Erasing entire FLASH chip");
			total_block_count = storageDeviceGetTotalBlockCount(&fh.store_dev);
			// erasing complete flash starting from 0 to total_block_count
			if(!(storageDeviceErase(0,total_block_count)))
			{
				MyErrorMessage(STORAGE_DEVICE_ERASE_FAILURE);
				sendResponse(NAK);
				return FIREHOSE_ERROR;

			}
			else
			{
				sendResponse(ACK);
	        	return FIREHOSE_SUCCESS;
			}
		}
		else
		{
			logMessage("num_partition_sectors =0x%x too high and start_sector:%lld not equal to zero",num_partition_sectors,start_sector);
			sendResponse(NAK);
	        return FIREHOSE_ERROR;
		}

	}

	pages_per_block =storageDeviceGetPagesInBlock(&fh.store_dev);
	// Calculate the physical_start_block and block_count based on start_sector and num_partition_sectors
	if(pages_per_block != 0)
	{
		if(start_sector % pages_per_block !=0)
		{
			logMessage("start_sector unaligned");   // not provided or invalid
	        sendResponse(NAK);
	        return FIREHOSE_ERROR;
		}
		else
		{
			start_block = start_sector/pages_per_block;
		}
		if(num_partition_sectors % pages_per_block !=0)
		{
			logMessage("num_partition_sectors unaligned");   // not provided or invalid
	        sendResponse(NAK);
	        return FIREHOSE_ERROR;
		}
		else
		{
			num_blocks = num_partition_sectors/pages_per_block;
			if(num_blocks ==0)
			{
				logMessage("num_blocks to erase are ZERO");
				sendResponse(ACK);
				return FIREHOSE_SUCCESS;
			}
		}
	}
	else
	{
		logMessage("Invalid pages_per_block:%d",pages_per_block);
		sendResponse(NAK);
	    return FIREHOSE_ERROR;
	}

	//Calling erase on blocks starting from start_block till  num_blocks

	if(storageDeviceErase(start_block,(start_block+num_blocks)))
		response = ACK;
	else
	{
		MyErrorMessage(STORAGE_DEVICE_ERASE_FAILURE);
		response = NAK;
	}

	sendResponse((response == TRUE) ? ACK : NAK);
	return (response == TRUE) ? FIREHOSE_SUCCESS : FIREHOSE_ERROR;

}

static firehose_error_t handleNop()
{
    logMessage("Binary build date: %s @ %s\n", __DATE__, __TIME__);
    logMessage("fh.attrs.Verbose is set to %i", fh.attrs.Verbose);

    //sendAndAuthSerialNum();
    sendSupportedFunctions();
    sendResponse(ACK);
    return FIREHOSE_SUCCESS;
}


int ReturnNumAttributes(void)
{
	return (int)(sizeof(AllAttributes)/sizeof(struct Attributes_Struct));
}

int ReturnAttributeLocation(char *NewAttrName)
{
    volatile SIZE_T i;
	SIZE_T StringLength1=0,StringLength2=0;

	StringLength1 = strlen((const char *)NewAttrName);

    for(i=0;i<(SIZE_T)ReturnNumAttributes();i++)
    {
		StringLength2 = strlen((const char *)AllAttributes[i].Name);

		if(StringLength1<StringLength2)
			StringLength1 = StringLength2;	// want the biggest number

        if ( strncasecmp(AllAttributes[i].Name, NewAttrName, StringLength1) == 0)
        {
			return i;
		}
	}

	return -1;
}
#ifdef TARGET_HAS_UFS

void Display_storage_extras_UFS(void)
{

	int i;
	// test if attribute was set here
	i = ReturnAttributeLocation("bNumberLU");
	if(i==-1) { return; }

	if(AllAttributes[i].Assigned == 1)
	{
		InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);
		AppendToBuffer(fh.tx_buffer,"<data>\n",FIREHOSE_TX_BUFFER_SIZE);
		AppendToBuffer(fh.tx_buffer,"<log value=\"",FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bNumberLU=%i ",storage_extras.ufs_extras.bNumberLU);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bBootEnable=%i ",storage_extras.ufs_extras.bBootEnable);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bDescrAccessEn=%i ",storage_extras.ufs_extras.bDescrAccessEn);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bInitPowerMode=%i ",storage_extras.ufs_extras.bInitPowerMode);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bHighPriorityLUN=%i ",storage_extras.ufs_extras.bHighPriorityLUN);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bSecureRemovalType=%i ",storage_extras.ufs_extras.bSecureRemovalType);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bInitActiveICCLevel=%i ",storage_extras.ufs_extras.bInitActiveICCLevel);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"wPeriodicRTCUpdate=%i ",storage_extras.ufs_extras.wPeriodicRTCUpdate);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bConfigDescrLock=%i ",storage_extras.ufs_extras.bConfigDescrLock);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		AppendToBuffer(fh.tx_buffer,"\" />\n</data>",FIREHOSE_TX_BUFFER_SIZE);
		sendTransmitBuffer();
	}

	i = ReturnAttributeLocation("LUNum");
	if(i==-1) { return; }

	if(AllAttributes[i].Assigned == 1)
	{
		// show variables now. NOTE, can't use    i = UFS_LUN_Var_Struct.LUNum    since I memset this struct
			 if(AllAttributes[i].Raw[0] == '1') { i = 1; }
		else if(AllAttributes[i].Raw[0] == '2') { i = 2; }
		else if(AllAttributes[i].Raw[0] == '3') { i = 3; }
		else if(AllAttributes[i].Raw[0] == '4') { i = 4; }
		else if(AllAttributes[i].Raw[0] == '5') { i = 5; }
		else if(AllAttributes[i].Raw[0] == '6') { i = 6; }
		else if(AllAttributes[i].Raw[0] == '7') { i = 7; }
		else 							        { i = 0; }

		InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);
		AppendToBuffer(fh.tx_buffer,"<data>\n",FIREHOSE_TX_BUFFER_SIZE);
		AppendToBuffer(fh.tx_buffer,"<log value=\"",FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"LUNum=%i ",i);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bLUEnable=%i ",storage_extras.ufs_extras.unit[i].bLUEnable);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bBootLunID=%i ",storage_extras.ufs_extras.unit[i].bBootLunID);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bLUWriteProtect=%i ",storage_extras.ufs_extras.unit[i].bLUWriteProtect);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bMemoryType=%i ",storage_extras.ufs_extras.unit[i].bMemoryType);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"size_in_KB=%i ",storage_extras.ufs_extras.unit[i].dNumAllocUnits);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bDataReliability=%i ",storage_extras.ufs_extras.unit[i].bDataReliability);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bLogicalBlockSize=%i ",storage_extras.ufs_extras.unit[i].bLogicalBlockSize);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"bProvisioningType=%i ",storage_extras.ufs_extras.unit[i].bProvisioningType);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		snprintf(temp_buffer,sizeof(temp_buffer),"wContextCapabilities=%i ",storage_extras.ufs_extras.unit[i].wContextCapabilities);
		AppendToBuffer(fh.tx_buffer,temp_buffer,FIREHOSE_TX_BUFFER_SIZE);
		AppendToBuffer(fh.tx_buffer,"\" />\n</data>",FIREHOSE_TX_BUFFER_SIZE);
		sendTransmitBuffer();
	}

}

#endif

#if TARGET_HAS_UFS || TARGET_HAS_EMMC

static firehose_error_t handleStorageExtras()
{
     //SIZE_T i = 0;
#ifndef FEATURE_FIREHOSE_ENABLE_STORAGE_EXTRAS
    logMessage("handleStorageExtras() is not supported in this image");
    return sendResponse(NAK);
#endif

    if (fh.attrs.commit == FALSE)
    {
        //storage_device_get_extras(&fh.store_dev, &storage_extras);
        //logMessage("In handleStorageExtras() but doing nothing since commit==FALSE");
        return sendResponse(ACK);
    }

    // To be this far means we're going through with committing these changes

    if (FALSE == storage_device_commit_extras(&fh.store_dev, &storage_extras))
    {
        logMessage("Failed to set storage extra parameters - storage_device_commit_extras() returned FALSE");  // Failed to set storage extra parameters
        return sendResponse(NAK);
    }


    logMessage("Set storage parameters successfully");

    // Clear these for next run
    fh.attrs.commit = 0;


    memset(&storage_extras.emmc_extras,0,sizeof(sdcc_emmc_gpp_enh_desc_type));	// clear this out for next run
    #ifdef TARGET_HAS_UFS
	memset(&storage_extras.ufs_extras, 0,sizeof(struct ufs_config_descr));		// clear this out for next run
	#endif


    return sendResponse(ACK);

}

firehose_error_t handleFirmwareProgram() {
    SIZE_T sector_size = 0;
    SIZE_T num_partition_sectors = 0;
    SIZE_T bytes_to_read = 0;
    SIZE_T bytes_read_in_layer = 0;
    firehose_error_t channel_read_retval = FIREHOSE_SUCCESS;
    byte* raw_data_buffer;
    byte temp_buffer[FIREHOSE_TEMP_BUFFER_SIZE] = {0};
    response_t response = ACK;
    boolean num_conversion;
    int errno;

    while (xmlGetToken(&fh.xml_reader) == XML_TOKEN_ATTRIBUTE) {
        if (xmlIsAttribute(&fh.xml_reader, "SECTOR_SIZE_IN_BYTES")) {
            xmlGetAttributeValue(&fh.xml_reader, temp_buffer,
                                 sizeof(temp_buffer));
            sector_size = stringToNumber((const char *) temp_buffer,
                                          &num_conversion);
            if (FALSE == num_conversion) {
                logMessage("Failed to get Sector size value");
                response = NAK;
            }
        }
        if (xmlIsAttribute(&fh.xml_reader, "num_partition_sectors")) {
            xmlGetAttributeValue(&fh.xml_reader, temp_buffer,
                                 sizeof(temp_buffer));
            num_partition_sectors = stringToNumber((const char *) temp_buffer,
                                                    &num_conversion);
            if (FALSE == num_conversion) {
                logMessage("Failed to get Number of sectors to write");
                response = NAK;
            }
        }
    }

    if (response == NAK) {
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    logMessage ("firmwarewrite cmd: Sector size "SIZE_T_FORMAT, sector_size);
    logMessage ("firmwarewrite cmd: Number of Sectors "SIZE_T_FORMAT,
                 num_partition_sectors);

    if (fh.emmc_storage.sector_size != sector_size) {
        logMessage ("Disk sector size does not match xml\n");
        logMessage ("Disk sector size :"SIZE_T_FORMAT" XML gave:"SIZE_T_FORMAT,
                    fh.emmc_storage.sector_size, sector_size);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    bytes_to_read = sector_size * num_partition_sectors;
    logMessage("Bytes to read from channel: "SIZE_T_FORMAT, bytes_to_read);

    if (bytes_to_read == 0) {
        logMessage ("Firmware Binary must be non-zero in size. Check binary");
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    if (bytes_to_read > fh.channel_buffer_capacity) {
        logMessage("Bytes to read > buffer capacity of "SIZE_T_FORMAT"bytes",
                    fh.channel_buffer_capacity);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    /* Switch to raw mode */
    sendResponseFields(
       ACK,
       1,
       "rawmode" ,'s', "true");

    channel_read_retval = getNextPacket(&raw_data_buffer, bytes_to_read,
                                        &bytes_read_in_layer);
    if (channel_read_retval != FIREHOSE_SUCCESS) {
        logMessage("Failed to read full FW binary. Read "SIZE_T_FORMAT" Bytes",
                    channel_read_retval);
        response = NAK;
        goto end;
    }

    if (bytes_to_read != bytes_read_in_layer) {
        logMessage("Read Error.Bytes expected:"SIZE_T_FORMAT",read:"SIZE_T_FORMAT,
                   bytes_to_read, bytes_read_in_layer);
        response = NAK;
        goto end;
    }

    if (response == ACK) {
        logMessage("Channel read "SIZE_T_FORMAT" bytes", bytes_read_in_layer);
    }

    if (FALSE == storageDeviceFWUpdate (&fh.emmc_storage, raw_data_buffer,
                                        num_partition_sectors, &errno))  {
        response = NAK;
        goto end;
    }

    response = ACK;

end:
    sendResponseFields(
        response,
        1,
        "rawmode" ,'s', "false");

    if (response == NAK)
        return FIREHOSE_ERROR;

    return FIREHOSE_SUCCESS;
}

static firehose_error_t handlePatch()
{

	boolean num_conversion;

    // Let's declare the variables we care about
    byte temp_buffer[FIREHOSE_TEMP_BUFFER_SIZE] = {0};
    SIZE_T patch_result = 0;
    byte * raw_data_buffer;
    SIZE_T num_partition_sectors;

    // Declare vars used in the CRC patch value parsing
    SIZE_T crc_start_sector, crc_over_num_bytes;
    char *comma_pos;
    char *end_crc_pos;
    SIZE_T patch_value_len;

	memset(temp_buffer,0,sizeof(temp_buffer));	// clear this out

    if (fh.attrs.start_sector == ATTR_INVALID_VAL)
    {
        logMessage("Attribute '%s' not provided (or -1)", "start_sector", ATTR_INVALID_VAL);    // not provided or invalid
        MyErrorMessage(HANDLE_PATCH_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    if (FALSE == storage_device_get_num_partition_sectors(&fh.store_dev, fh.attrs.physical_partition_number, &num_partition_sectors)) {
        return FIREHOSE_ERROR;
    }

    if (fh.attrs.byte_offset >= fh.channel_buffer_capacity) {
        return FIREHOSE_ERROR;
    }
    if (strncasecmp("DISK", fh.attrs.filename, sizeof(fh.attrs.filename)) != 0) {
        // Nothing to be done if it is not a DISK patch
        return FIREHOSE_SUCCESS;
    }
    if (fh.store_dev.sector_size != fh.attrs.SECTOR_SIZE_IN_BYTES)
    {
        logMessage("Attribute 'SECTOR_SIZE_IN_BYTES'=%lld must be equal to disk sector size %lld", fh.attrs.SECTOR_SIZE_IN_BYTES, fh.store_dev.sector_size);
        MyErrorMessage(HANDLE_PATCH_FAILURE);

        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    // TODO: Clean this up. This functionality should not know so much
    // about the buffers available
    raw_data_buffer = fh.channel_buffer[1 - fh.channel_buffer_to_use];

    snprintf((char *)temp_buffer, sizeof(temp_buffer), SIZE_T_FORMAT, num_partition_sectors);
    simpleStrReplace((char *)fh.attrs.value,
                     "NUM_DISK_SECTORS",
                     (const char *) temp_buffer);
    simpleStrReplace((char *)fh.attrs.value,
                     ".",
                     "");

    if (strstr((char *)fh.attrs.value, "CRC32")) {
        simpleStrReplace((char *)fh.attrs.value,
                         "CRC32",
                         "");

        patch_value_len = strlen((char *)fh.attrs.value);
        comma_pos = strchr((char *)fh.attrs.value, ',');
        end_crc_pos = strrchr((char *)fh.attrs.value, ')');
        if (NULL == comma_pos || NULL == end_crc_pos)
        {
            logMessage("Invalid CRC patch value");
            MyErrorMessage(HANDLE_PATCH_FAILURE);
            return FIREHOSE_ERROR;
        }
        if (end_crc_pos < comma_pos) {
            return FIREHOSE_ERROR;
        }
        memscpy(temp_buffer,
                    sizeof(temp_buffer),
                    comma_pos + 1,
                    end_crc_pos - (comma_pos + 1));
        temp_buffer[end_crc_pos - (comma_pos + 1)] = NULL; //'\0';
        //crc_start_sector
        crc_over_num_bytes = stringToNumber((const char *) temp_buffer, &num_conversion);
        if (FALSE == num_conversion)
        {
            logMessage("Failed to get crc_over_num_bytes");
            MyErrorMessage(HANDLE_PATCH_FAILURE);
            sendResponse(NAK);
            return FIREHOSE_ERROR;
        }
        memsmove(comma_pos, sizeof(temp_buffer),
                end_crc_pos,
                1 + fh.attrs.value + patch_value_len - (byte *)end_crc_pos);
        //parseExpression((char *)fh.attrs.value, &crc_start_sector);
	StringLength = sizeof(fh.attrs.value);
	MyParseExpression((char *)fh.attrs.value, StringLength, &crc_start_sector);
        logMessage("crc start sector %lld, over bytes %lld", crc_start_sector, crc_over_num_bytes);

        storage_device_read(
            &fh.store_dev,
            fh.attrs.physical_partition_number,
            raw_data_buffer,
            crc_start_sector,
            (crc_over_num_bytes / fh.store_dev.sector_size)
            + ((crc_over_num_bytes % fh.store_dev.sector_size == 0) ? 0 : 1));
        patch_result = calc_crc32(raw_data_buffer, crc_over_num_bytes);
    }
    else {
        //parseExpression((char *)fh.attrs.value, &patch_result);
	StringLength = sizeof(fh.attrs.value);
	MyParseExpression((char *)fh.attrs.value, StringLength, &patch_result);
    }

    storage_device_read(&fh.store_dev,
                      fh.attrs.physical_partition_number,
                      raw_data_buffer,
                      fh.attrs.start_sector,
                      1);

    // TODO: clean this up a bit
    if (4 == fh.attrs.size_in_bytes)
        patch_result &= 0xFFFFFFFF;
    memscpy(raw_data_buffer + fh.attrs.byte_offset,
                fh.channel_buffer_capacity-fh.attrs.byte_offset,
                &patch_result,
                sizeof(SIZE_T));
    /*
    if (sizeof(patch_result) < fh.attrs.size_in_bytes)
    {
        if ((fh.attrs.byte_offset + fh.attrs.size_in_bytes) < sizeof(temp_buffer)) {
            memset(temp_buffer + fh.attrs.byte_offset + sizeof(patch_result),
                   0,
                   fh.attrs.size_in_bytes - sizeof(patch_result));
        }
    }
    */
    storage_device_write(&fh.store_dev,
                       fh.attrs.physical_partition_number,
                       raw_data_buffer,
                       fh.attrs.start_sector,
                       1);

    logMessage("Patched sector %lld with %08X", fh.attrs.start_sector, patch_result);

    return sendResponse(ACK);
}





static firehose_error_t handleGetDigest(void)
{


    // Variables to deal with raw data
    boolean retval = FALSE;
    SIZE_T sectors_to_send,
           bytes_to_send_to_layer;
    byte* raw_data_buffer;
    SIZE_T raw_data_buffer_sector_capacity;
    //int errno;
    struct __sechsh_ctx_s   context;
    //SHA256_CTX sha2_ctx;
    uint8 data_digest[32] = {0};
    // The log string size is currently based on
    // sizeof(data_digest) * 2 + strlen("SHA256 ") + 1
    // and some extra space
    char log_string[72] = {0};
    int written;
    int i = 0;
    SIZE_T sectors_done = 0;
    SIZE_T log_msg_every_sectors = 2048;
    SIZE_T log_start_sector, log_num_sectors;
    word crc_value = (word) CRC_16_STEP_SEED;


    if (fh.attrs.start_sector == ATTR_INVALID_VAL || fh.attrs.num_partition_sectors == ATTR_INVALID_VAL)
    {
        if (fh.attrs.start_sector == ATTR_INVALID_VAL)
            logMessage("Attribute '%s' not provided (or -1)", "start_sector", ATTR_INVALID_VAL);    // not provided or invalid
        else
            logMessage("Attribute '%s' not provided (or -1)", "num_partition_sectors", ATTR_INVALID_VAL);   // not provided or invalid

        MyErrorMessage(HANDLE_GET_DIGEST_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    if (fh.store_dev.sector_size != fh.attrs.SECTOR_SIZE_IN_BYTES)
    {
        logMessage("Attribute 'SECTOR_SIZE_IN_BYTES'=%lld must be equal to disk sector size %lld", fh.attrs.SECTOR_SIZE_IN_BYTES, fh.store_dev.sector_size);
        MyErrorMessage(HANDLE_GET_DIGEST_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

    raw_data_buffer_sector_capacity = fh.channel_buffer_capacity / fh.attrs.SECTOR_SIZE_IN_BYTES;

    sechsharm_sha256_init (&context);

    //SHA256_Init(&sha2_ctx );


    // TODO: Clean this up. Read functionality should not know so much
    // about the buffers available
    raw_data_buffer = fh.channel_buffer[1 - fh.channel_buffer_to_use];

    log_start_sector = fh.attrs.start_sector;
    log_num_sectors = fh.attrs.num_partition_sectors;

    logMessage("Beginning HASHING disk data. This can take a while!!");

    while (fh.attrs.num_partition_sectors > 0) {
        sectors_to_send = MIN(fh.attrs.num_partition_sectors, raw_data_buffer_sector_capacity);
        bytes_to_send_to_layer = sectors_to_send * fh.attrs.SECTOR_SIZE_IN_BYTES;

        retval = storageDeviceRead(&fh.store_dev,
                              fh.attrs.physical_partition_number,
                              raw_data_buffer,
                              fh.attrs.start_sector,
                              sectors_to_send);

        if (retval == FALSE) {
            break;
        }
        else {
            fh.attrs.start_sector += sectors_to_send;
        }

        sechsharm_sha256_update(&context,
                        context.leftover,
                        &(context.leftover_size),
                        raw_data_buffer,
                        bytes_to_send_to_layer);
        //SHA256_Update(&sha2_ctx, raw_data_buffer, bytes_to_send_to_layer);


        fh.attrs.num_partition_sectors -= sectors_to_send;

        sectors_done += sectors_to_send;
        if (sectors_done >= log_msg_every_sectors) {
            sectors_done = 0;
            if (fh.attrs.num_partition_sectors > 0)
                logMessage("%lld sectors more to hash", fh.attrs.num_partition_sectors);
        }
    }
    if (retval == TRUE)
    {
        sechsharm_sha256_final (&context,
                        context.leftover,
                        &(context.leftover_size),
                        data_digest);
        //SHA256_Final(data_digest, &sha2_ctx);

        written = snprintf(log_string,
                       sizeof(log_string),
                       "%s",
                       "Digest ");

        while (written < sizeof(log_string) && i < sizeof(data_digest))
        {
            written += snprintf(log_string + written,
                                sizeof(log_string) - written,
                                "%02X",
                                data_digest[i]);
            i++;
        }

        logMessage("Hash start sector %lld num sectors %lld", log_start_sector, log_num_sectors);
        logMessage(log_string);
    }

    sendResponse(ACK);
    return FIREHOSE_SUCCESS;

}

static firehose_error_t handleGetDigestSHA256() {
    return handleGetDigest();
}
#else
firehose_error_t handleStorageExtras() {
return FIREHOSE_SUCCESS;
}
firehose_error_t handleFirmwareProgram() {
	return FIREHOSE_SUCCESS;
}
#endif


static firehose_error_t handleRead()
{

#ifndef FEATURE_FIREHOSE_ENABLE_READ
    logMessage("Read operation not allowed");
    // ACK-ing here since Read is (usually) not
    // a critical operation
    return sendResponse(ACK);
#else

    // Let's declare the variables we care about
    SIZE_T read_fail_sector = 0;

    // Variables to deal with raw data
    boolean retval = FALSE;
	boolean do_send_read_data;
    response_t raw_data_status;
    SIZE_T sectors_to_send,
           bytes_to_send_to_layer,
           total_bad_sectors;
	byte* current_sector;
    SIZE_T raw_data_buffer_sector_capacity;
	SIZE_T sector_size,pages_per_block,total_block_count;
	unsigned int bad_block_count =0;
	unsigned int bad_block_page_count =0;
	int32 current_block;
	int32 current_bad_block = -1;
	uint32 read_type;
	enum flash_block_state block_state;


	//TODO: Clean this up. Read functionality should not know so much
    // about the buffers available
    byte* const raw_data_buffer = fh.channel_buffer[1 - fh.channel_buffer_to_use];


	//validation for input parameters such as start_sector and num_partition_sectors
    if (fh.attrs.start_sector == ATTR_INVALID_VAL || fh.attrs.num_partition_sectors == ATTR_INVALID_VAL)
    {
        if (fh.attrs.start_sector == ATTR_INVALID_VAL)
            logMessage("Attribute '%s' not provided (or -1)", "start_sector", ATTR_INVALID_VAL);    // not provided or invalid
        else
            logMessage("Attribute '%s' not provided (or -1)", "num_partition_sectors", ATTR_INVALID_VAL);   // not provided or invalid

        MyErrorMessage(STORAGE_READ_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

	pages_per_block = storageDeviceGetPagesInBlock(&fh.store_dev);
	total_block_count = storageDeviceGetTotalBlockCount(&fh.store_dev);

	//make sure that we are not trying to read more than total nand size
	if((fh.attrs.start_sector + fh.attrs.num_partition_sectors)/pages_per_block > total_block_count)
	{
		logMessage("Trying to read beyond total sectors");
		MyErrorMessage(STORAGE_READ_FAILURE);
		sendResponse(NAK);
        return FIREHOSE_ERROR;

	}

	// Assign sector size based on the attributes
	if(fh.attrs.ecc_enabled == TRUE || fh.attrs.get_spare == TRUE)
	{
		sector_size = storageDeviceGetTotalPageSize();
		if(fh.attrs.ecc_enabled == TRUE)
			read_type = FLASH_READ_RAW;
		else
			read_type = FLASH_READ_MAIN_SPARE;
	}
	else
	{
		read_type = FLASH_READ_MAIN;
		sector_size = storageDeviceGetPageSize(&fh.store_dev);
	}

	// check sector_size with attribute SECTOR_SIZE_IN_BYTES for consistency
  // SECTOR_SIZE_IN_BYTES is same as PAGE SIZE in NAND
  
    if (sector_size != fh.attrs.SECTOR_SIZE_IN_BYTES)
    {
        logMessage("Attribute 'SECTOR_SIZE_IN_BYTES'=%lld must be equal to disk sector size %lld", fh.attrs.SECTOR_SIZE_IN_BYTES, sector_size);
        MyErrorMessage(STORAGE_READ_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

	//calculate total number of sectors which can be accomodated in channel buffer
    raw_data_buffer_sector_capacity = fh.channel_buffer_capacity / sector_size;

	logMessage("raw_data_buffer_sector_capacity %lld", raw_data_buffer_sector_capacity);
	logMessage("start_sector %lld and num_partition_sectors%lld", fh.attrs.start_sector, fh.attrs.num_partition_sectors);

	//Send ack to start rawdata transfer
        InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
		AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
        AppendToBuffer(fh.tx_buffer,"<response value=\"ACK\" rawmode=\"true\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);
        sendTransmitBuffer();

    raw_data_status = ACK;


	// iterate over all num_partition_sectors to read
    while (fh.attrs.num_partition_sectors > 0)
	{

		sectors_to_send = MIN(fh.attrs.num_partition_sectors, raw_data_buffer_sector_capacity);
        bytes_to_send_to_layer = sectors_to_send * sector_size;

		current_sector = (byte *) raw_data_buffer;
		do_send_read_data = TRUE;

		while(sectors_to_send > 0)
		{

	        if (raw_data_status == ACK)
			{

				if(fh.attrs.ecc_enabled == FALSE)
				{

					//check the status of the block based on start_sector address
					current_block = fh.attrs.start_sector / pages_per_block;

					if(current_bad_block !=	current_block)
						storageDeviceGetBlockState(current_block, &block_state);
					else
						block_state = FLASH_BLOCK_BAD;

					if(block_state == FLASH_BLOCK_BAD)
					{
						current_bad_block = current_block;
						if(fh.attrs.bad_block_at_end == FALSE)
						{
							memset(current_sector,0xBB,sector_size);
							current_sector = (byte *)(current_sector + sector_size);
							sectors_to_send -= 1;
							fh.attrs.start_sector += 1;
							fh.attrs.num_partition_sectors -= 1;
							continue;
						}
						else
						{

							if(fh.attrs.num_partition_sectors >= pages_per_block && (fh.attrs.start_sector % pages_per_block) == 0)
							{
								bad_block_count += 1;
								fh.attrs.start_sector += pages_per_block;
								fh.attrs.num_partition_sectors -= pages_per_block;

							}
							else
							{
								bad_block_page_count += 1;
 								fh.attrs.start_sector += 1;
								fh.attrs.num_partition_sectors -= 1;

							}

							do_send_read_data = FALSE;
							break;


						}

					}
				}

				// reading from flash storage

				retval = storageDeviceRead(&fh.store_dev,
	                              //fh.attrs.physical_partition_number,
	                              current_sector,
	                              read_type,
	                              fh.attrs.start_sector,
	                              1);

	            if (retval == FALSE)
				{
					// probably the page is bad so fill it with bad page pattern
					memset(current_sector,0xDD,sector_size);
	            }
            	current_sector = (byte *)(current_sector + sector_size);



			}

			sectors_to_send -= 1;
			fh.attrs.start_sector += 1;
			fh.attrs.num_partition_sectors -= 1;

		}

		if(do_send_read_data == TRUE && raw_data_status == ACK)
		{
			//we are good to send the data to host
			writeChannel(raw_data_buffer, bytes_to_send_to_layer);
		}
	}

	if(((bad_block_count != 0) || bad_block_page_count != 0) && (fh.attrs.bad_block_at_end == TRUE))
	{
		// selected bad blocks towards the end
		// getting total_bad_sectors in order to send to host
		total_bad_sectors = bad_block_count * pages_per_block + bad_block_page_count ;

		while(total_bad_sectors > 0)
		{
			sectors_to_send = MIN(total_bad_sectors, raw_data_buffer_sector_capacity);
        	bytes_to_send_to_layer = sectors_to_send * sector_size;
			memset(raw_data_buffer,0xFF,bytes_to_send_to_layer);
			writeChannel(raw_data_buffer, bytes_to_send_to_layer);
			total_bad_sectors -= sectors_to_send;
		}

	}
	// Complete with raw data transfer
	//Sending reponse packet to host
	InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
    AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);


    if (NAK == raw_data_status)
    {
    	AppendToBuffer(fh.tx_buffer,"<response value=\"NAK\" rawmode=\"false\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);
		sendTransmitBuffer();
		logMessage("Read failed at sector %lld", read_fail_sector);
        MyErrorMessage(STORAGE_READ_FAILURE);
    }
	else
	{
		AppendToBuffer(fh.tx_buffer,"<response value=\"ACK\" rawmode=\"false\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);
		sendTransmitBuffer();
	    debugMessage("Finished sector address %lld", fh.attrs.start_sector);

	}

    return (raw_data_status == ACK) ? FIREHOSE_SUCCESS : FIREHOSE_ERROR;

#endif

}


static firehose_error_t  handleProgram()
{
	response_t raw_data_status;
	boolean retval                        = FALSE;
    firehose_error_t channel_read_retval  = FIREHOSE_SUCCESS;
	int errno;
	SIZE_T current_sector_address;
	SIZE_T last_sector_address;
	SIZE_T new_sector_address;
	//SIZE_T num_sectors_to_write;
	SIZE_T sectors_to_read,
           bytes_to_read_from_layer,
           bytes_read_in_layer;
    byte* raw_data_buffer;
	byte* current_sector;
    SIZE_T raw_data_buffer_sector_capacity,sector_size_in_bytes;
	SIZE_T num_partition_sectors;
	SIZE_T total_block_count = 0;
	int32 current_block;
	enum flash_block_state block_state;


	// Variables to deal with raw data

    SIZE_T rx_length_sectors;


    volatile SIZE_T  i=0,j=0;
	logMessage("INSIDE HANDLE PROGRAM");

	// valdiate start_sector and num_partition_sectors

	if (fh.attrs.start_sector == ATTR_INVALID_VAL || fh.attrs.num_partition_sectors == ATTR_INVALID_VAL)
    {
        if (fh.attrs.start_sector == ATTR_INVALID_VAL)
            logMessage("Attribute '%s' not provided (or -1)", "start_sector", ATTR_INVALID_VAL);    // not provided or invalid
        else
            logMessage("Attribute '%s' not provided (or -1)", "num_partition_sectors", ATTR_INVALID_VAL);   // not provided or invalid

        MyErrorMessage(HANDLE_PROGRAM_FAILURE);
        sendResponse(NAK);
		return FIREHOSE_ERROR;

	}


	//validate SECTOR_SIZE_IN_BYTES and PAGES_PER_BLOCK with actual nand configuration
  // SECTOR_SIZE_IN_BYTES is same as PAGE SIZE in NAND
	if (storageDeviceGetPageSize(&fh.store_dev) != fh.attrs.SECTOR_SIZE_IN_BYTES)
    {
        i = j; // for breakpoint
        logMessage("Attribute 'SECTOR_SIZE_IN_BYTES'=%lld must be equal to disk sector size %lld", fh.attrs.SECTOR_SIZE_IN_BYTES, storageDeviceGetPageSize(&fh.store_dev));
        MyErrorMessage(HANDLE_PROGRAM_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }
	else
		sector_size_in_bytes = fh.attrs.SECTOR_SIZE_IN_BYTES;

  	if (storageDeviceGetPagesInBlock(&fh.store_dev) != fh.attrs.PAGES_PER_BLOCK)
    {
        i = j; // for breakpoint
        logMessage("Attribute 'PAGES_PER_BLOCK'=%lld must be equal to disk pages per block %lld", fh.attrs.SECTOR_SIZE_IN_BYTES, storageDeviceGetPagesInBlock(&fh.store_dev));
        MyErrorMessage(HANDLE_PROGRAM_FAILURE);
        sendResponse(NAK);
        return FIREHOSE_ERROR;
    }

	num_partition_sectors = fh.attrs.num_partition_sectors;
	current_sector_address= fh.attrs.start_sector;

	//Calculating the number of sectors
	raw_data_buffer_sector_capacity = fh.channel_buffer_capacity / fh.attrs.SECTOR_SIZE_IN_BYTES;

	// Validate if start_sector and num_partition_sectors are within total block limits
	total_block_count = storageDeviceGetTotalBlockCount(&fh.store_dev);
	last_sector_address = fh.attrs.start_sector + fh.attrs.num_partition_sectors;

	if (last_sector_address > (total_block_count*fh.attrs.PAGES_PER_BLOCK))
	{
		logMessage("Programming region exceeds total block count");
		MyErrorMessage(HANDLE_PROGRAM_FAILURE);
        sendResponse(NAK);
		return FIREHOSE_ERROR;
	}


	logMessage("start_sector %lld, last_sector_address %lld", fh.attrs.start_sector, last_sector_address);
	kick_watchdog();

	//If attributes are valid then  sendResponseFields:   ACK:  rawmode
	InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
    AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
    AppendToBuffer(fh.tx_buffer,"<response value=\"ACK\" rawmode=\"true\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);
    sendTransmitBuffer();

	raw_data_status = ACK;

	while (num_partition_sectors > 0 ) {

		//calculate sectors_to_read and bytes_to_read_from_layer
		sectors_to_read = MIN(num_partition_sectors, raw_data_buffer_sector_capacity);
	    bytes_to_read_from_layer = sectors_to_read * fh.attrs.SECTOR_SIZE_IN_BYTES;

		debugMessage("sectors_to_read=%lld bytes_to_read_from_layer=%lld", sectors_to_read, bytes_to_read_from_layer);

		//Call getNextPacket based on bytes_to_read_from_layer
		channel_read_retval = getNextPacket(&raw_data_buffer, bytes_to_read_from_layer, &bytes_read_in_layer);

		if (channel_read_retval != FIREHOSE_SUCCESS)
		{
			MyErrorMessage(HANDLE_PROGRAM_FAILURE);

			if (fh.validation_enabled == TRUE)
			{
				logMessage("Encountered RAW data transport error in validation mode.");
			}
			else
			{
				delaySeconds(10);

				InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
				AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
				AppendToBuffer(fh.tx_buffer,"<response value=\"NAK\" rawmode=\"false\" AttemptRetry=\"1\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);
				sendTransmitBuffer();
			}
			return channel_read_retval;
		}

		if (bytes_read_in_layer > bytes_to_read_from_layer || bytes_read_in_layer % fh.attrs.SECTOR_SIZE_IN_BYTES != 0)
		{
			logMessage("bytes_read_in_layer=%lld", bytes_read_in_layer);
			continue;
		}
		//logMessage("raw_data_buffer_address=%lld", raw_data_buffer);

	     rx_length_sectors = bytes_read_in_layer / fh.attrs.SECTOR_SIZE_IN_BYTES;

	     //logMessage("rx_length_sectors=%lld fh.attrs.start_sector=%lld", rx_length_sectors, fh.attrs.start_sector);
		 debugMessage("rx_length_sectors=%lld fh.attrs.start_sector=%lld", rx_length_sectors, fh.attrs.start_sector);

		 current_sector = (byte *) raw_data_buffer;

		while ( rx_length_sectors > 0)
		{

			if (raw_data_status == ACK)
			{

				// now we need to write the received data
				//Need to write data in raw_data_buffer starting from current_sector till rx_length_sectors
				//bad block management will be carried out within  flash_prog_write_current_page

				i=j; // for break point


				debugMessage("writing to current_sector_address %lld from buffer address%lld",current_sector_address, current_sector);

				if(!fh.attrs.SkipWrite)
				{
					if(current_sector_address%fh.attrs.PAGES_PER_BLOCK == 0)
					{
						do
						{
							current_block = current_sector_address/fh.attrs.PAGES_PER_BLOCK;
							storageDeviceGetBlockState(current_block, &block_state);
							if(block_state == FLASH_BLOCK_BAD)
								current_sector_address += fh.attrs.PAGES_PER_BLOCK;
							else
								break;

						}while(block_state == FLASH_BLOCK_BAD);


					}
					//if(current_sector_address <= last_sector_address)
						retval = storageDeviceWrite(&fh.store_dev,
			                                        current_sector,
			                                        current_sector_address,
			                                        &new_sector_address,
			                                        1,
			                                        &errno);
					/*else
						retval = FALSE;*/
				}
				else
				{
					retval = TRUE;
					new_sector_address = current_sector_address + 1;

				}

	           	if (retval == FALSE)
				{
		           logMessage("Write failed errno %d", errno);
					raw_data_status = NAK;
	            }
				else
				{

					debugMessage("Confirmed write at sector address%lld",new_sector_address);
					if((current_sector_address + 1) != new_sector_address)
					{
						logMessage("current_sector_address %lld mismatch with new_sector_address %lld",current_sector_address,new_sector_address);
					}
					current_sector_address = new_sector_address;
				}

            }

			rx_length_sectors -= 1;

			// check if we have more to write
			if(rx_length_sectors > 0 && raw_data_status == ACK)
					current_sector = (byte *)(current_sector + sector_size_in_bytes);

			num_partition_sectors -=1;
		}

		//num_partition_sectors -= num_sectors_to_write;

	}


    logMessage("Finished sector address %lld", fh.attrs.start_sector);

    InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
    AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
    if(raw_data_status==ACK)
      AppendToBuffer(fh.tx_buffer,"<response value=\"ACK\" rawmode=\"false\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);
    else
      AppendToBuffer(fh.tx_buffer,"<response value=\"NAK\" rawmode=\"false\" />\n</data>", FIREHOSE_TX_BUFFER_SIZE);

    sendTransmitBuffer();

    return (raw_data_status == ACK) ? FIREHOSE_SUCCESS : FIREHOSE_ERROR;


}


static firehose_error_t handleBenchmark()
{


#ifndef FEATURE_FIREHOSE_ENABLE_BENCHMARK
    logMessage("Benchmark operation is not allowed");
    // ACK-ing here since benchmark is (usually) not
    // a critical operation
  return sendResponse(ACK);
#else

	SIZE_T i, j,k, trials = 10;
  SIZE_T  start_time, end_time, average_time;
  uint8 temp_hash_value[32] = {0};
  boolean retval = TRUE;
  byte* buffer = fh.channel_buffer[0];
  SIZE_T raw_data_buffer_sector_capacity;
  SIZE_T buffer_size = fh.channel_buffer_capacity;
	SIZE_T temp_start_sector = 0;
	SIZE_T new_start_sector;
	enum flash_block_state block_state;
	int errno;

	SIZE_T sector_size = storageDeviceGetPageSize(&fh.store_dev);


	raw_data_buffer_sector_capacity = fh.channel_buffer_capacity / sector_size;

    // TODO: Change reference to 512 to get the sector size from the storage device
    // TODO: Do not reference channel_buffer[0] directly. This func should not have any knowledge
    // of how many buffers are in use

	if (fh.attrs.TestWritePerformance == TRUE)
    {
        logMessage("Going to test writes for lengths %lld to %lld for %lld trials. This can take a while.", sector_size, buffer_size, trials);

        memset(buffer,0xAA,sector_size);
		logMessage ("Block0 would be erased for write test starting from sector0");

		storageDeviceGetBlockState(0, &block_state);
		if (block_state!= FLASH_BLOCK_BAD)
		{
			new_start_sector =0;
			storageDeviceErase(0,1);
	        for (i = sector_size; i <= buffer_size; i = i * 2)
	        {
	            average_time = 0;
	            start_time = get_time();
	            for (j = 0; j < trials; j++)
	            {
	              	for (k = 0; k < (i/sector_size); k++)
	            	{
		                retval = storageDeviceWrite(&fh.store_dev,
			                                        buffer,
			                                        new_start_sector,
			                                        &new_start_sector,
			                                        1,
			                                        &errno);
						new_start_sector += 1;
	              	}
	            }
	            end_time = get_time();
	            average_time += (end_time - start_time);
	            average_time = average_time / j;
	            logMessage("Writing %lld bytes %ld us", i, average_time);
	        }
		}
		else
			logMessage (" Skipping write performance test as block 0 is bad");
    }

	if (fh.attrs.TestDigestPerformance == TRUE)
    {
        for (i = sector_size; i <= buffer_size; i = i * 2)
        {
            average_time = 0;
            for (j = 0; j < trials; j++)
            {
                start_time = get_time();
                PerformSHA256(buffer, i, temp_hash_value);
                //PerformSHA256HW(buffer, i, temp_hash_value);
                end_time = get_time();
                average_time += (end_time - start_time);
            }
            average_time = average_time / j;
            logMessage("Hashing %lld bytes %lld times took %ld us on average", i, trials, average_time);
        }
    }


	fh.attrs.TestWritePerformance  = FALSE;
	fh.attrs.TestReadPerformance   = FALSE;
	fh.attrs.TestDigestPerformance = FALSE;


    return sendResponse(ACK);

#endif

}



firehose_tag_data_t firehose_tag_data[] = {
    {"program", handleProgram},
    {"configure", handleConfigure},
#ifndef DEVICEPROGRAMMER_TINY
	#if TARGET_HAS_UFS || TARGET_HAS_EMMC
    {"firmwarewrite", handleFirmwareProgram},
    {"patch", handlePatch},
    {"setbootablestoragedrive", handleSetBootableStorageDrive},
    {"ufs", handleStorageExtras},
    {"emmc", handleStorageExtras},
    {"getsha256digest", handleGetDigestSHA256},
    #endif
    {"power", handlePower},
    {"benchmark", handleBenchmark},
    {"read", handleRead},
    {"getstorageinfo", handleGetStorageInfo},
    {"erase", handleErase},
    #if TARGET_HAS_UFS || TARGET_HAS_EMMC
    {"peek", handlePeek},
    {"poke", handlePoke},
    #endif
    {"nop", handleNop}
#endif
};

// This reads the next packet sent over USB and initializes the XML
// reader fh.xml_reader with it.
//
// Returns: FIREHOSE_SUCCESS if valid XML was received
//          FIREHOSE_ERROR on read error, invalid XML, or XML too large
//
// NOTE: How 'we' choose to validate the XML right now is not very generic.
// Hence this should not be put under the xml parser code
static firehose_error_t getXMLPacket() {
    SIZE_T bytes_read = 0;
    byte* packet;
    firehose_error_t read_retval;
    volatile int i = 0;

    while (bytes_read == 0)
        read_retval = getNextPacket(&packet, MIN(sizeof(fh.xml_buffer), fh.channel_buffer_capacity), &bytes_read);


    i = 1; // for breakpoint

    if (FIREHOSE_SUCCESS != read_retval)
        return read_retval;

    i = 2; // for breakpoint

    if (sizeof(fh.xml_buffer) < bytes_read)
    {
        i = bytes_read; // for breakpoint

        logMessage("XML (%lld bytes) is too big for buffer (max %lld bytes)", bytes_read, sizeof(fh.xml_buffer));
        MyErrorMessage(XML_PACKET_TOO_LARGE);
        return FIREHOSE_ERROR;
    }

    i = 3; // for breakpoint

    memscpy(fh.xml_buffer, sizeof(fh.xml_buffer), packet, bytes_read);
    //xmlInitReader(&fh.xml_reader, fh.xml_buffer, bytes_read);

    i = 4; // for breakpoint

    return FIREHOSE_SUCCESS;
}

void initFirehoseTransport()
{
    //qhsusb_al_bulk_init(0x0, QHSUSB_MODE__SER_ONLY);
	qusb_al_bulk_init(QUSB_MAX_SPEED_SUPER);
}

// Send all the functions in the function table in separate log messages.
//
// This gives the user information as well as partially serving to identify the
// Firehose version.
void sendSupportedFunctions(void)
{
    int i;

        InitBufferWithXMLHeader(fh.tx_buffer, FIREHOSE_TX_BUFFER_SIZE);            // adds XML header only
        AppendToBuffer(fh.tx_buffer,"<data>\n", FIREHOSE_TX_BUFFER_SIZE);
        AppendToBuffer(fh.tx_buffer,"<log value=\"Supported Functions: ", FIREHOSE_TX_BUFFER_SIZE);


    for (i = 0; i < sizeof(firehose_tag_data) / sizeof(firehose_tag_data[0]); i++)
    {
        //logMessage("supported function: '%s'", firehose_tag_data[i].tag_name);
        AppendToBuffer(fh.tx_buffer,firehose_tag_data[i].tag_name, FIREHOSE_TX_BUFFER_SIZE);
        AppendToBuffer(fh.tx_buffer," ", FIREHOSE_TX_BUFFER_SIZE);

    }

        AppendToBuffer(fh.tx_buffer,"\"/>\n", FIREHOSE_TX_BUFFER_SIZE);
        AppendToBuffer(fh.tx_buffer,"</data>", FIREHOSE_TX_BUFFER_SIZE);

        sendTransmitBuffer();

} // end void sendSupportedFunctions()

// Send the chip's serial number. This gives the user information as well as
// serving as a signal that USB is initialized and Firehose is ready to
// receive commands.
//
// Also, if DEVICEPROGRAMMER_SERIAL_NUM is specified in build, Firehose will
// halt if actual serial num does not match.
void sendAndAuthSerialNum(void)
{
    uint32 chip_serial_num = getChipSerialNum();

#ifdef DEVICEPROGRAMMER_SERIAL_NUM
    if (chip_serial_num != DEVICEPROGRAMMER_SERIAL_NUM)
    {
        for (;;)
        {
            logMessage("Serial number specified in build does not match actual serial number: %u (0x%x).", chip_serial_num, chip_serial_num);
            logMessage("Build serial num: %u (0x%x)", DEVICEPROGRAMMER_SERIAL_NUM, DEVICEPROGRAMMER_SERIAL_NUM);
            MyErrorMessage(SERIAL_NUM_OF_DEVICE_INCORRECT);
            delaySeconds(2);
        }
    }
#endif

    logMessage("Chip serial num: %u (0x%x)", chip_serial_num, chip_serial_num);
}


char OPENING_DATA_TAG[] = "<data>";
char CLOSING_DATA_TAG[] = "</data>";
char OPENING_PATCHES_TAG[] = "<patches>";
char CLOSING_PATCHES_TAG[] = "</patches>";

tag_handler_t CurrentHandlerFunction;   // this will always point to latest TAG function, i.e. handleConfigure()

SIZE_T CopyString(char *Dest, char *Source, SIZE_T  Dstart, SIZE_T  Sstart, SIZE_T  length, SIZE_T DestSize, SIZE_T SourceSize)
{
        SIZE_T  i = 0;
        char Temp;

	if(Dest=='\0')				 { return 0; }	// Dest is null
	if(Source=='\0')			 { return 0; }	// Source is null
	if(Dstart+length-1>DestSize) { return 0; }	// string to copy over is too big for destination
	if(Sstart+length>SourceSize) { return 0; }	// range to copy is beyond source string
	if(length==0)				 { return 0; }	// nothing to copy

	//logMessage("CopyString(0x%X, 0x%X, %ld, %ld, %ld, %ld, %ld)",Dest,Source,Dstart,Sstart,length,DestSize,SourceSize);

        for(i=0;i<length;i++)
        {
           Temp = *(Source+Sstart+i);

            *(Dest+Dstart+i) = Temp;
        } // end i

        *(Dest+Dstart+i) = '\0';    // NULL

		return length;
}

void ResetAllAttributeAssignFlags(void)
{
        SIZE_T  i;

		for(i=0;i<(SIZE_T)ReturnNumAttributes();i++)
			AllAttributes[i].Assigned = 0;
}


int AssignAttribute(char *NewAttrName, char *NewAttrValue, SIZE_T NewAttrValueLen)
{
        volatile SIZE_T  i,j=0,Matched=0;
        SIZE_T TempValue;
        unsigned int uTempValue;
        int nTempValue;
        char cTempValue;
        //printf("\n\nIn AssignAttribute(%s,%s)\n",NewAttrName,NewAttrValue);
        //logMessage("In AssignAttribute(%s,%s) and fh.attrs.Verbose=0x%X",NewAttrName,NewAttrValue,fh.attrs.Verbose);

        for(i=0;i<sizeof(AllAttributes)/sizeof(struct Attributes_Struct);i++)
        {
                if (strncasecmp(NewAttrName, AllAttributes[i].Name, strlen((const char *)AllAttributes[i].Name)) == 0)
                {
                        Matched = 1;

                        if(fh.attrs.Verbose == TRUE)
                            logMessage("Recognized Attribute Number %lld ('%s') with value '%s' type is '%c'",i,NewAttrName,NewAttrValue,AllAttributes[i].Type);

                        //printf("MATCHED - '%s'\n",AllAttributes[i].Name);
			if( CopyString(AllAttributes[i].Raw, NewAttrValue, 0, 0, strlen(NewAttrValue), sizeof(AllAttributes[i].Raw), NewAttrValueLen) == 0)
			{
				dbg(LOG_ERROR, "1 Failed to copy string '%s' of length %ld bytes into AllAttributes[%ld].Raw of size %ld bytes for '%s'",NewAttrValue,strlen(NewAttrValue),i,sizeof(AllAttributes[i].Raw),NewAttrName);
				return 1;
			}
                        //strncpy( AllAttributes[i].Raw, NewAttrValue,sizeof(AllAttributes[i].Raw) );
                        j = i; // for breakpoint
                        if( AllAttributes[i].Type == 'i' || AllAttributes[i].Type == 'w' || AllAttributes[i].Type == 'n' || AllAttributes[i].Type == 'b')
                        {
                            boolean num_conversion;

                            TempValue = stringToNumber((const char *) AllAttributes[i].Raw, &num_conversion);
                            if (FALSE == num_conversion)
                            {
                                dbg(LOG_INFO,"Call to stringToNumber failed on attribute '%s' with value '%s'",NewAttrName,AllAttributes[i].Raw);
                                return 1;	// error
                            }

                            //if(fh.attrs.Verbose == TRUE)
                            //    logMessage("Converted to TempValue = %lld",TempValue);

                            if(CurrentHandlerFunction!=handleFirmwareProgram && CurrentHandlerFunction!=handleRead)
                            {
                                // When it's handleFirmwareProgram we allow SECTOR_SIZE_IN_BYTES=1
                                // handleRead can allow page size to be a non multiple of 512
                                if((TempValue % AllAttributes[i].MultipleOf == 0))
                                {
                                   // AllIsWell = 1;
                                }
                                else
                                {
                                   dbg(LOG_INFO,"Attribute '%s' is not a multiple of %i",NewAttrName,AllAttributes[i].MultipleOf);
                                   return 1;	// error
                                }
                            }

                            if( AllAttributes[i].Max != 0 )
                            {
                               // Need to check against max value
                               if( TempValue <= AllAttributes[i].Max )
                               {
                                  //AllIsWell = 1;
                               }
                               else
                               {
                                  dbg(LOG_INFO,"Attribute '%s' is larger than %i",NewAttrName,AllAttributes[i].Max);
                                  return 1;	// error
                               }
                            }

                            if(AllAttributes[i].Type == 'w')
                            {
                                //if(fh.attrs.Verbose == TRUE)
                                //    logMessage("Assigning Var %d ('%s') as UNSIGNED INT %lld",i,NewAttrName,TempValue);
                                uTempValue = (unsigned int)TempValue;

                                *((unsigned int *)AllAttributes[i].pValue) = (unsigned int)uTempValue;
                            }
                            else if(AllAttributes[i].Type == 'n')
                            {
                                //if(fh.attrs.Verbose == TRUE)
                                //    logMessage("Assigning Var %lld ('%s') as BYTE as %lld",i,NewAttrName,TempValue);
                                nTempValue = (short)TempValue;
                                *((short *)AllAttributes[i].pValue) = (short)nTempValue;
                            }
                            else if(AllAttributes[i].Type == 'b')
                            {
                                //if(fh.attrs.Verbose == TRUE)
                                //    logMessage("Assigning Var %lld ('%s') as BYTE as %lld",i,NewAttrName,TempValue);
                                cTempValue = (char)TempValue;
                                *((char *)AllAttributes[i].pValue) = (byte)cTempValue;
                            }
                            else
                            {
                                //if(fh.attrs.Verbose == TRUE)
                                //    logMessage("Assigning Var %lld ('%s') as SIZE_T as %lld",i,NewAttrName,TempValue);
                                *((SIZE_T *)AllAttributes[i].pValue) = (SIZE_T)TempValue;
                            }

                        }
                        else if( AllAttributes[i].Type == 's' )
                        {
                           j = i; // for breakpoint
                           //AllIsWell = 1;

			if( CopyString(AllAttributes[i].pStr, NewAttrValue, 0, 0, strlen(NewAttrValue), AllAttributes[i].SizeOfpStr, NewAttrValueLen)  == 0)
			{
				dbg(LOG_ERROR, "2 Failed to copy string '%s' into AllAttributes[%ld].pStr",NewAttrValue,i);
				return 1;
			}

                           //strncpy( AllAttributes[i].pStr,NewAttrValue,sizeof(AllAttributes[i].Raw) );
                           j = i; // for breakpoint
                        }
                        // else we have the special 'x' case, handled later if Assigned has been set
                        j = i; // for breakpoint
                        AllAttributes[i].Assigned = 1;

                        break;
                }       // end of comparing attribute names
        } // end of looping through all attributes

        if(Matched==0)
        {
            if(fh.attrs.Verbose == TRUE)
                dbg(LOG_INFO,"IGNORING UNRECOGNIZED Attribute '%s' with value '%s'",NewAttrName,NewAttrValue);

            j = i;	// for breakpoint
        }

        return 0;
}


SIZE_T IsEmptySpace(char c)
{
	if( c == 0xA ) { return 1; }
	if( c == 0xD ) { return 1; }
	if( c == 0x9 ) { return 1; }
	if( c == 0x20) { return 1; }

	return 0;
}


char * RemoveEverythingButTags(char *Packet, SIZE_T  CurrentPacketLoc, SIZE_T MaxPacketSize)
{
	SIZE_T  PacketLength,PacketLoc=0,i;
	char *pch;
	long FoundLeftBrace=-1,FoundRightBrace=-1,FoundForwardSlash=-1,Found=0;

	if(CurrentPacketLoc>=MaxPacketSize)
		return Packet; // nothing to do

    PacketLength= strlen((const char *)Packet);

	if(PacketLength>=MaxPacketSize)
		return Packet; // should be impossible

	for(i=0;i<PacketLength;i++)
	{
		if(Found==0)
		{
			if(i+3<PacketLength)
			{
				if(Packet[i]=='<' && Packet[i+1]=='!' && Packet[i+2]=='-' && Packet[i+3]=='-')	// protected by if(i+3<PacketLength) above
				{
					Found = 1;
					Packet[i] = ' '; Packet[i+1] = ' '; Packet[i+2] = ' '; Packet[i+3] = ' ';
					i+=3;
				}
			}
		} // end of if(Found==0)
		else
		{
			// we are inside of a comment
			if(i+2<PacketLength)
			{
				if(Packet[i]=='-' && Packet[i+1]=='-' && Packet[i+2]=='>')	// protected by if(i+2<PacketLength) above
				{
					Found = 0;
					Packet[i] = ' '; Packet[i+1] = ' '; Packet[i+2] = ' ';
					i+=2;
					continue;
				}
			} // end if(i+2<PacketLength)
			Packet[i] = ' '; // remove since this is a comment
		}

		i = i;
	}

	// At this point, XML file has all <!-- comments --> replaced by spaces


	// Now nuke the first <?xml version="1.0" ?>

	do
	{
		pch = strstr(Packet, "xml version");
		if(pch==NULL) { break; }

		// to be this far we found "xml version"
		// Now look slightly beyond that

		pch = strstr(pch, ">");				// is now pointing to the beginning of the file
		if(pch!=NULL) //'\0')					// pch = "<configuration> <options> DOWNLOAD_PROTOCOL       = FIREHOSE etc etc
		{
			memset(Packet,0x20,pch-&Packet[PacketLoc]+1);	// this removes <?xml version="1.0" ?>
		}

		// We could have more than 1 XML file here
		pch = strstr(Packet, "xml version");
		if(pch!=NULL)
		{
			PacketLength = pch-Packet; // now length updated to start of next XML
		}


		// find last tag name
		// find last tag name
		for(i=PacketLength-1;i>0;i--)
		{
			if( Packet[i] == '>' ) { FoundRightBrace = i; }

			if(FoundRightBrace>0)
				if( Packet[i] == '/' ) { FoundForwardSlash = i; }

			if(FoundRightBrace>0 && FoundForwardSlash>0)
			{
				if( Packet[i] == '<' )
				{
					FoundLeftBrace = i;
					break;
				}
			} // end if(FoundRightBrace>0)
		} // end for

		if( (FoundRightBrace-FoundForwardSlash+2) > MaxPacketSize-1 )
		{
			logMessage("Either closing tag is bigger than %d bytes, or the XML file is not formed correctly",MaxPacketSize);
			return Packet; // something is wrong
		}

		memset(CurrentTagName,0,sizeof(CurrentTagName));

		if( CopyString(CurrentTagName, Packet, 0, FoundForwardSlash, FoundRightBrace-FoundForwardSlash+1, sizeof(CurrentTagName), MaxPacketSize)  == 0)
		{
			logMessage("3 Failed to copy string of length %ld bytes into CurrentTagName",FoundRightBrace-FoundForwardSlash+1);
			return Packet; // something is wrong
		}
		//strncpy(CurrentTagName,&Packet[FoundForwardSlash],FoundRightBrace-FoundForwardSlash+1);	// CurrentTagName = "/data>" OR "/configuration>" etc etc

		//CurrentTagName[FoundRightBrace-FoundForwardSlash+1] = '\0';

		memset(&Packet[FoundForwardSlash-1],0x20,strlen(CurrentTagName)+1);	// this takes out </configuration> OR </data> at the end of the file

		CurrentTagName[0] = '<';							// CurrentTagName = "<data>" OR "<configuration>" etc etc

		pch = strstr(Packet, CurrentTagName);				// is now pointing to the beginning of the file
		if(pch!=NULL) //'\0')					// pch = "<configuration> <options> DOWNLOAD_PROTOCOL       = FIREHOSE etc etc
		{
			memset(Packet,0x20,strlen(CurrentTagName)+(pch-Packet)); // nukes everything up to <data>
		}
		else
		{
			logMessage("ERROR: Either closing tag is bigger than %d bytes, or the XML file is not formed correctly",MaxPacketSize);
			logMessage("ERROR: Could not find '%s' tag",CurrentTagName);
			return Packet; // something is wrong
		}

		break; // breaking the do loop

	}while(1); // end of looking for "xml version"

	return Packet;
}

SIZE_T  DetermineTag(char *Packet, SIZE_T  CurrentPacketLoc, SIZE_T MaxPacketSize)
{
    volatile SIZE_T  i=0;
	SIZE_T  PacketLength;
    int CurrentTag = -1;
    char *pch;
	long FoundLeftBrace=-1,FoundRightBrace=-1,FoundForwardSlash=-1,Found=0;

	if(CurrentPacketLoc>=MaxPacketSize)
		return 0;	// out of packet

	Packet = RemoveEverythingButTags(Packet,CurrentPacketLoc, MaxPacketSize);
    // Step 1. String away header
    // Step 2. Strip away <data> tags
    // step 3. Get tag_name
    // step 4. Get attributes
    PacketLength= strlen((const char *)Packet);

	if(PacketLength>=MaxPacketSize)
		return 0;	// should be impossible


	ResetAllAttributeAssignFlags();

	// This chomps up empty space till we hit a tag
    while( IsEmptySpace( Packet[CurrentPacketLoc] ) )
    {
        CurrentPacketLoc++;

        if(CurrentPacketLoc>=PacketLength)
        {
             logMessage("ERROR: XML packet not formed correctly. Ran out of room looking for TAG");

             return 0;
        }
    }

    if(Packet[CurrentPacketLoc]!='<')
    {
        logMessage("ERROR: XML not formed correctly. Expected a &lt; character at loc %d",CurrentPacketLoc);
        return 0;	// not formed correctly
    }

    CurrentPacketLoc++;    // move past the above opening <

	// Could be one solid tag like <options>, test by looking for spaces *before* seeing a '>'
	FoundRightBrace = -1;
	for(i=CurrentPacketLoc;i<PacketLength;i++)
	{
		if( Packet[i] == '>' ) { FoundRightBrace = i; break;}
		if( Packet[i] == ' ' ) { break;}
	}

	if(FoundRightBrace>0)
	{
		// this is something like <options> some text </options>
		ParseAttributes = 0;	// need to parse the strings

		CopyString(NewTagName, Packet, 0, CurrentPacketLoc,   FoundRightBrace-CurrentPacketLoc, sizeof(NewTagName), MaxPacketSize );   // NewTagName has the TAG now
		RemoveBannedChars(NewTagName); // chars like " < > are replaced by _

		CurrentPacketLoc = FoundRightBrace + 1; // The +1 to get past the >

	}
	else
	{
		// or could be tag with attributes like <program filename
		ParseAttributes = 1;

		pch = strstr(&Packet[CurrentPacketLoc], " ");          // Find a space after the TAG name

		if(pch==NULL) //'\0')   // if null, XML is not formed correctly
		{
			logMessage("ERROR: XML not formed correctly. Expected one SPACE character at loc %d",CurrentPacketLoc);
			return 0;	// not formed correctly
		}

		if( pch-&Packet[CurrentPacketLoc] > MAX_TAG_NAME_LENGTH )
		{
			logMessage("ERROR: The XML TAG is too long (%d chars) only %d chars allowed",(pch-&Packet[CurrentPacketLoc]),MAX_TAG_NAME_LENGTH);
			return 0;	// not formed correctly
		}


		CopyString(NewTagName, Packet, 0, CurrentPacketLoc,   pch-&Packet[CurrentPacketLoc], sizeof(NewTagName), MaxPacketSize );   // NewTagName has the TAG now
		RemoveBannedChars(NewTagName); // chars like " < > are replaced by _

		CurrentPacketLoc += strlen((const char *)NewTagName);
		CurrentPacketLoc++;    // move past the above opening space we confirmed exists above

	}

	for (i = 0; i < sizeof(firehose_tag_data) / sizeof(firehose_tag_data_t); i++)
	{
		if (strncasecmp(firehose_tag_data[i].tag_name, NewTagName,strlen((const char *)NewTagName)) == 0)
		{
				CurrentTag             = i;
				CurrentHandlerFunction = firehose_tag_data[i].handler;
				break;
		}
	} // end i

	if(CurrentTag==-1)
	{
		logMessage("**WARNING Ignoring Unrecognized tag '%s'", NewTagName);
		return 0;
	}

    // The above got the <TAG>, accessible like this firehose_tag_data[CurrentTag].handler and firehose_tag_data[CurrentTag].tag_name

    return CurrentPacketLoc;

} // end DetermineTag(char *Packet, SIZE_T  PacketLoc)

SIZE_T  DetermineAttributes(char *Packet, SIZE_T  CurrentPacketLoc, SIZE_T MaxPacketSize)
{
    SIZE_T  i=0, AttributesFound=0;
    SIZE_T  PacketLength;

    char NewAttrName[MAX_TAG_ATTR_LENGTH];
    char NewAttrValue[MAX_TAG_ATTR_LENGTH];
    char *pch;

	if(CurrentPacketLoc>=MaxPacketSize)
		return 0;	// ran out of packet

    // step 4. Get attributes
    PacketLength    = strlen((const char *)Packet);
    // Packet[CurrentPacketLoc] should be at the first letter of the attribute now
    // They all look like this attribute1="value1" attribute2="value2"
    // Meaning only spaces seperate them

	if(PacketLength>=MaxPacketSize)
		return 0;	// should be impossible

    AttributesFound = 0;

	while(CurrentPacketLoc < PacketLength)
    {
        pch = strstr(&Packet[CurrentPacketLoc], "=");          // Find an equals sign
        if(pch==NULL) //'\0')   // if null, we didn't find it
        {
            dbg(LOG_ERROR,"XML not formed correctly. Could not find '=' character");
            return 0;	// not formed correctly
        }

        if( pch-&Packet[CurrentPacketLoc] > MAX_TAG_ATTR_LENGTH )
        {
            dbg(LOG_ERROR,"The value for XML attribute is too long (%d chars) only %d chars allowed",(pch-&Packet[CurrentPacketLoc]),MAX_TAG_ATTR_LENGTH);
            return 0;	// not formed correctly
        }

        CopyString(NewAttrName, Packet, 0, CurrentPacketLoc,   pch-&Packet[CurrentPacketLoc], sizeof(NewAttrName), MaxPacketSize );  // NewAttrName has the ATTR now

        RemoveBannedChars(NewAttrName); // chars like " < > are replaced by _

        CurrentPacketLoc += strlen((const char *)NewAttrName);
        CurrentPacketLoc++;    // move past the = sign

        if(Packet[CurrentPacketLoc]!='"')
        {
            dbg(LOG_ERROR,"XML not formed correctly. Expected one &quot; character at loc %d",CurrentPacketLoc);
            return 0;	// not formed correctly
        }

        CurrentPacketLoc++;    // Before "value" and now we move past the " sign, all that is left now is the actual value"

        pch = strstr(&Packet[CurrentPacketLoc], "\"");         // Find closing "

        if(pch==NULL) //'\0')   // if null, we didn't find it
        {
            dbg(LOG_ERROR,"XML not formed correctly. Expected one &quot; character at loc %d",CurrentPacketLoc);
            return 0;	// not formed correctly
        }

        if( pch-&Packet[CurrentPacketLoc] > MAX_TAG_ATTR_LENGTH )
        {
            dbg(LOG_ERROR,"The value for XML attribute '%s' is too long (%d chars) only %d chars allowed",NewAttrName,(pch-&Packet[CurrentPacketLoc]),MAX_TAG_ATTR_LENGTH);
            return 0;	// not formed correctly
        }

        CopyString(NewAttrValue, Packet, 0, CurrentPacketLoc,   pch-&Packet[CurrentPacketLoc], sizeof(NewAttrValue), MaxPacketSize ); // NewAttrValue has the ATTR value now
        RemoveBannedChars(NewAttrValue); // chars like " < > are replaced by _

        AttributesFound++;

        // FIGURE OUT WHICH ATTRIBUTE AND ASSIGN VALUE

        if( AssignAttribute(NewAttrName, NewAttrValue, sizeof(NewAttrValue)) != 0 )
        {
            dbg(LOG_ERROR,"AssignAttribute failed");
            return 0;	// not formed correctly
        }

        CurrentPacketLoc += strlen((const char *)NewAttrValue);
        CurrentPacketLoc++;    // move past the closing quote " sign

        while( IsEmptySpace( Packet[CurrentPacketLoc] ) )
        {
            CurrentPacketLoc++;

            if(CurrentPacketLoc>=PacketLength)
            {
                dbg(LOG_ERROR,"XML packet not formed correctly. Ran out of room looking for ATTRIBUTES");

                return 0;
            }
        }


        if(Packet[CurrentPacketLoc]=='/')
        {
           // This is the END of the packet
           return CurrentPacketLoc+2; // +2 gets us past the />
        }
    } // end of while(CurrentPacketLoc < PacketLength)

    return 0;       // to be here means we ran out of packet

} // end DetermineAttributes(char *Packet, SIZE_T CurrentPacketLoc)

#define BYTES_PER_KB 1024

SIZE_T  ParseComplicatedAttributes(void)
{
        volatile SIZE_T  i,j;

		for(i=0;i<(SIZE_T)ReturnNumAttributes();i++)
		{
            j = i;    // for breakpoint

            if(AllAttributes[i].Assigned==0)
                continue;	// variable wasn't even assigned, so no point checking


            if(CurrentHandlerFunction==handleStorageExtras)
            {
                // This is a special case, where the <ufs> or <emmc> tags are used and variables are sent
                // over multiple packets. In this case the struct UFS_LUN_Var is used as for temporary holding
                // and these values need to be moved to storage_extras.ufs_extras.unit[ 0 ].bLUEnable
                j = i; // for breakpoint
            }
            else if(AllAttributes[i].Type == 'i' && AllAttributes[i].Type == 'b' && AllAttributes[i].Type == 'w')
                continue;	// integer attributes are not complicated, Only want 'x' or 's'


            j = i+1;    // for breakpoint

            if (strncasecmp(AllAttributes[i].Name, "start_sector",strlen("start_sector")) == 0)
            {
                //printf("MATCHED - '%s'\n",AllAttributes[i].Name);

                j = i;    // for breakpoint

                if (parseSectorValue(AllAttributes[i].Raw, sizeof(AllAttributes[i].Raw), &fh.attrs.start_sector, fh.attrs.physical_partition_number, "start_sector") == FALSE)
                {
                    logMessage("parseSectorValue could not handle start_sector value");
                    return FIREHOSE_ERROR;
                }

                j = i;    // for breakpoint

            }  // end of looking for start_sector
// =================================================================

            if (strncasecmp(AllAttributes[i].Name, "MemoryName", strlen("MemoryName")) == 0)
            {
                //printf("MATCHED - '%s'\n",AllAttributes[i].Name);

                j = i;    // for breakpoint


				#if TARGET_HAS_EMMC || TARGET_HAS_UFS
               // convert memory name to enum value
               if (strncasecmp( AllAttributes[i].Raw, "emmc", strlen("eMMC") ) == 0)
               {
                   fh.attrs.storage_type = HOTPLUG_TYPE_MMC;
                   fh.store_dev.sector_size = 512; // for eMMC

                   i = j;
               }
               else if (strncasecmp( AllAttributes[i].Raw, "ufs", strlen("UFS") ) == 0)
               {
                   fh.attrs.storage_type = HOTPLUG_TYPE_UFS;
                   fh.store_dev.sector_size = 4096; // for UFS
                   i = j;
               }
               else
               {
                   logMessage("Invalid storage type: %s", (char *)AllAttributes[i].Raw);
                   return FIREHOSE_ERROR;
               }
			   #endif

                j = i;    // for breakpoint
            }  // end of looking for MemoryName
// ==================================================================
#ifdef TARGET_HAS_UFS
            if (strncasecmp(AllAttributes[i].Name, "LUNum",strlen("LUNum")) == 0)
            {
                volatile SIZE_T  Temp1 = 0;
                volatile SIZE_T  Temp2 = 0;

                if(CurrentHandlerFunction!=handleStorageExtras) { continue; }

                j = i;    // for breakpoint

                Temp1 = UFS_LUN_Var_Struct.LUNum;

                // All attributes for this LUN would have also been assigned
                Temp2 = UFS_LUN_Var_Struct.bLUEnable;				storage_extras.ufs_extras.unit[ Temp1 ].bLUEnable           = Temp2;
                Temp2 = UFS_LUN_Var_Struct.bBootLunID;				storage_extras.ufs_extras.unit[ Temp1 ].bBootLunID          = Temp2;
                Temp2 = UFS_LUN_Var_Struct.bLUWriteProtect;			storage_extras.ufs_extras.unit[ Temp1 ].bLUWriteProtect     = Temp2;
                Temp2 = UFS_LUN_Var_Struct.bMemoryType;				storage_extras.ufs_extras.unit[ Temp1 ].bMemoryType         = Temp2;
                Temp2 = UFS_LUN_Var_Struct.bDataReliability;		storage_extras.ufs_extras.unit[ Temp1 ].bDataReliability    = Temp2;
                Temp2 = UFS_LUN_Var_Struct.bLogicalBlockSize;		storage_extras.ufs_extras.unit[ Temp1 ].bLogicalBlockSize   = Temp2;
                Temp2 = UFS_LUN_Var_Struct.bProvisioningType;		storage_extras.ufs_extras.unit[ Temp1 ].bProvisioningType   = Temp2;
                Temp2 = UFS_LUN_Var_Struct.wContextCapabilities;	storage_extras.ufs_extras.unit[ Temp1 ].wContextCapabilities= Temp2;

                // We allow user to enter size_in_KB but the real attribute is dNumAllocUnits
                Temp2 = UFS_LUN_Var_Struct.size_in_KB;

                storage_extras.ufs_extras.unit[ Temp1 ].dNumAllocUnits = Temp2;	// for now, dNumAllocUnits *is* size_in_KB until we call ufs_commit_extras()

/*
                if(fh.store_dev.blocks_per_alloc_unit==0)
                    OpenUFSforFWvalues(&fh.store_dev);

                if(fh.store_dev.blocks_per_alloc_unit==0)
                {
                    logMessage("ERROR: handleStorageExtras and ParseComplicatedAttributes() fh.store_dev.blocks_per_alloc_unit is 0. Was MemoryName='ufs' specified in the configure tag?");
                    return FIREHOSE_ERROR;
                }

                if (Temp2 % fh.store_dev.blocks_per_alloc_unit != 0)
                {
                    logMessage("ERROR: For UFS, %d is not a multiple of blocks_per_alloc_unit %d",Temp2,fh.store_dev.blocks_per_alloc_unit );
                    return FIREHOSE_ERROR;
                }

                storage_extras.ufs_extras.unit[ Temp1 ].dNumAllocUnits = Temp2/fh.store_dev.blocks_per_alloc_unit;

                logMessage("dNumAllocUnits=%d since size_in_KB=%d and blocks_per_alloc_unit=%d",storage_extras.ufs_extras.unit[ Temp1 ].dNumAllocUnits,Temp2,fh.store_dev.blocks_per_alloc_unit);
*/
                memset(&UFS_LUN_Var_Struct,0,sizeof(UFS_LUN_Var_Struct));	// clear this out for next run

                j = i;    // for breakpoint

            }  // end of looking for start_sector
// =================================================================
// ==================================================================
#endif

            if (strncasecmp(AllAttributes[i].Name, "commit",strlen("commit")) == 0)
            {
                //printf("MATCHED - '%s'\n",AllAttributes[i].Name);

                // Need to update this value

                j = i;    // for breakpoint

                if (strncasecmp(AllAttributes[i].Raw, "true",strlen("true")) == 0)
                    fh.attrs.commit = 1;
                else if (strncasecmp(AllAttributes[i].Raw, "1",strlen("1")) == 0)
                    fh.attrs.commit = 1;
                else
                    fh.attrs.commit = 0;

                j = i;    // for breakpoint

            }  // end of looking for start_sector
// =================================================================

        } // end for i

        return FIREHOSE_SUCCESS;

} // end SIZE_T  ParseComplicatedAttributes(void)

void handleResettingAttributesBasedOnTag(void)
{
    if(CurrentHandlerFunction == handleConfigure)
    {
        //fh.skip_storage_writes  = FALSE;
        //fh.ack_raw_data_every   = 0;
        //fh.hash_in_non_secure   = FALSE;


        fh.attrs.SkipWrite                  = FALSE;
        fh.attrs.BufferWrites               = FALSE;
        //fh.attrs.AckRawData                 = FALSE;
        fh.attrs.AckRawDataEveryNumPackets  = 0;
        fh.attrs.AlwaysValidate             = FALSE;    // fh.hash_in_non_secure
        //fh.attrs.Verbose                    = FALSE;
        //fh.attrs.read_back_verify           = FALSE;
        fh.attrs.SkipStorageInit            = FALSE;
        fh.attrs.SkipSettingMinClocks       = FALSE;
        fh.attrs.SkipSettingMaxClocks       = FALSE;
        fh.attrs.actual_size_in_bytes       = 0;
    }
	else if(CurrentHandlerFunction == handleStorageExtras)
	{
		fh.attrs.commit = 0;	// user sent <ufs or <emmc, so need to ensure they set the commit themselves
	}
    //else if(CurrentHandlerFunction == handleNop)
    //{
    //    etc etc
    //}



} // end of void handleResettingAttributesBasedOnTag(void);

/*
 * The main entry point after initialization in deviceprogrammer_initialize.c.
 * It is called by deviceprogrammer_entry().
 *
 * To add a new command to Firehose, define it above and add it to the function
 * table: firehose_tag_data.
 */

//#include "CeTL_Comdef.h"
//#include "CeML.h"
//#include "CeTL_Hash.h"
//#include "CeTL_Env.h"
void InitAttributes(void);

void InitAttributes(void)
{
	fh.attrs.MaxPayloadSizeToTargetInBytes 			= 131072; //ONE_MEGABYTE;
	fh.attrs.MaxPayloadSizeToTargetInBytesSupported = 32768; //ONE_MEGABYTE;
	fh.attrs.MaxPayloadSizeFromTargetInBytes		= 8192; //ONE_MEGABYTE;
	fh.attrs.Verbose								= 0;
	fh.attrs.MaxDigestTableSizeInBytes				= 8192;
	fh.attrs.AckRawDataEveryNumPackets				= 0;
	fh.attrs.delayinseconds							= 1;
	fh.attrs.address64								= 0;
	fh.attrs.value64								= 0;
	fh.attrs.storagedrive							= 0;
	fh.attrs.physical_partition_number				= 0;
	fh.attrs.SECTOR_SIZE_IN_BYTES					= 512;
	fh.attrs.byte_offset							= 0;
	fh.attrs.physical_partition_number				= 0;
	fh.attrs.size_in_bytes							= 0;
	fh.attrs.num_partition_sectors					= 0;
	fh.attrs.file_sector_offset						= 0;

	fh.attrs.ZlpAwareHost							= 1;
	fh.attrs.SkipWrite								= 0;
	fh.attrs.BufferWrites							= 0;
	//fh.attrs.AckRawData								= 0;
	fh.attrs.AlwaysValidate							= 0;

	//fh.attrs.display								= 0;
	//fh.attrs.read_back_verify						= 0;
	fh.attrs.TestWritePerformance					= 0;
	fh.attrs.TestReadPerformance					= 0;
	fh.attrs.TestDigestPerformance					= 0;
	fh.attrs.SkipStorageInit						= 0;
	fh.attrs.SkipSettingMinClocks					= 0;
	fh.attrs.SkipSettingMaxClocks					= 0;
	fh.attrs.actual_size_in_bytes					= 0;

	fh.attrs.start_sector							= 0;

	if( CopyString(fh.attrs.MemoryName, "eMMC", 0, 0, sizeof("eMMC"),sizeof(fh.attrs.MemoryName),sizeof("eMMC")) == 0)
	{
		dbg(LOG_ERROR, "Failed to copy '%s' of length %"SIZE_T_FORMAT" bytes into fh.attrs.MemoryName","eMMC",strlen("eMMC"));
		//ExitAndShowLog(1);
	}

}

void main_firehose(void)
{
    volatile SIZE_T  PacketLoc = 0, BreakPoint = 0;

    dbg(LOG_INFO,"Binary build date: %s @ %s", __DATE__, __TIME__);

	InitAttributes();

//
//    CeTLHashTests();
//
    //sendAndAuthSerialNum();     // sent again in handleNop
    sendSupportedFunctions();   // sent again in handleNop

    for (;;)
    {
        PacketLoc = 0;

        // Get XML packet over USB and initialize XML reader.
        if (getXMLPacket() != FIREHOSE_SUCCESS)
        {
            // on any errors send NAK and get next packet, getXMLPacket() would have sent the error
            sendResponse(NAK);
            continue;
        }

        // To be this far fh.xml_buffer has the data

        PacketLoc = DetermineTag((char *)fh.xml_buffer, PacketLoc, FIREHOSE_XML_BUFFER_SIZE);		// This sets CurrentHandlerFunction()

        // PacketLoc should be past the xml and data tags, pointing at the 1st attribute
        // So if PacketLoc is still it 0, something went wrong

        if(PacketLoc==0) {  sendResponse(NAK);          continue;        }


        // Based on the TAG above, some variables need to be reset
        handleResettingAttributesBasedOnTag();


       // To be this far fh.xml_buffer[PacketLoc] is pointing to the first char of the first attribute
        PacketLoc = DetermineAttributes((char *)fh.xml_buffer, PacketLoc, FIREHOSE_XML_BUFFER_SIZE);

        // PacketLoc should now be past all attributes and pointing at the />
        // So if PacketLoc is still it 0, something went wrong

        if(PacketLoc==0) {  sendResponse(NAK);          continue;        }

        // At this point some attributes will need additional processing before
        // we call the Tag Handler function
        if(ParseComplicatedAttributes()==FIREHOSE_ERROR)    // i.e. start_sector="NUM_DISKSECTORS-33."
        {  sendResponse(NAK);          continue;        }

        BreakPoint = 2;
		kick_watchdog();
        // Below is the function pointer, i.e. tag_handler_t CurrentHandlerFunction;
        CurrentHandlerFunction();
    }
}

void AppendToBuffer(byte *MyBuffer, char *buf, SIZE_T MaxBufferSize)
{
   size_t SpaceLeft, CharsToAdd = 0;
   size_t Length;

   Length       = strlen((const char *)MyBuffer);
   CharsToAdd   = strlen((const char *)buf);    // size of string to append

   //SpaceLeft = FIREHOSE_TX_BUFFER_SIZE - Length - XML_TAIL_LENGTH;      // tx_buffer is transmit_buffer of size FIREHOSE_TX_BUFFER_SIZE
   SpaceLeft = MaxBufferSize - Length - XML_TAIL_LENGTH;      // tx_buffer is transmit_buffer of size FIREHOSE_TX_BUFFER_SIZE


   if(CharsToAdd > SpaceLeft) { return; } // too big to add this

   // NOTE: If you're *not* seeing your messages, increase the size of transmit_buffer[FIREHOSE_TX_BUFFER_SIZE]
   //       or break up your logging

   memscpy((MyBuffer+Length), MaxBufferSize, buf, CharsToAdd);
   MyBuffer[Length+CharsToAdd] = '\0';

} // end void AppendToBuffer(byte *MyBuffer, char *buf)


void InitBufferWithXMLHeader(byte *MyBuffer, SIZE_T Length)
{
   memset(MyBuffer, 0x0, Length);
   memscpy(MyBuffer, Length, xml_header, XML_HEADER_LENGTH);
   //MyBuffer[XML_HEADER_LENGTH] = '\0';
} // end void InitBufferWithXMLHeader(void)

/*
void AppendToTXBuffer(char *buf)
{
   size_t SpaceLeft, CharsToAdd = 0;
   size_t Length;

   Length       = strlen((const char *)fh.tx_buffer);
   CharsToAdd   = strlen((const char *)buf);    // size of string to append

   SpaceLeft = FIREHOSE_TX_BUFFER_SIZE - Length - XML_TAIL_LENGTH;      // fh.tx_buffer is transmit_buffer of size FIREHOSE_TX_BUFFER_SIZE

   if(CharsToAdd > SpaceLeft) { return; } // too big to add this

   // NOTE: If you're *not* seeing your messages, increase the size of transmit_buffer[FIREHOSE_TX_BUFFER_SIZE]
   //       or break up your logging

   memscpy((fh.tx_buffer+Length), SpaceLeft, buf, CharsToAdd);

} // end void AppendToTXBuffer(char *buf)
*/

char * RemoveBannedChars(char *p)
{
    char *pOrig = p;

    while(*p!=NULL) //'\0')
    {
        if( *p=='"' || *p=='<' || *p=='>')
            *p = '_';

         p++;
    }

    return pOrig;
}

