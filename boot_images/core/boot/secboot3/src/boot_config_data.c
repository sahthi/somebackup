/*===========================================================================

                    BOOT CONFIG DATA TABLE FUNCTIONS

DESCRIPTION
  Contains definition of the config data table which is stored in eeprom

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  
Copyright 2014-2015 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
============================================================================*/

/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.
    
$Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/boot/secboot3/src/boot_config_data.c#1 $
$DateTime: 2016/12/12 23:35:46 $
$Author: pwbldsvc $
    
when       who     what, where, why
--------   ---     ----------------------------------------------------------
03/10/15   aus     Added missing integer overflow check
01/22/15   aus     Added boundary checks for reading CDB from a CDT
06/03/14   ck      Added size of CDT loaded to boot log
12/05/12   jz      Moved common code here from boot_cdt_util.c (removed)
08/06/12   dh      Add a check for EEPROM read failure based on feature flag
05/02/12   dh      Change page_buf as static variable
10/24/11   dh      Add logic to only update default cdt array's platform id block
                   if eeprom cdt has no DDR data block. Move EEPROM_DEVICE_ID to
                   boot_target.h
09/09/11   dh      Map all dal and flash driver calls to boot extern interface.
                   Change flash_device_close to DalDevice_Close,
                          flash_device_attach to DAL_DeviceAttach,
                          flash_device_detach to DAL_DeviceDetach,
                   since those are mapped in macros from flash.h
08/04/11   aus     Fixed the warning due to wrong use of the escape character
07/29/11   aus     Updated Flash Device ID and added support for requirement to 
                   error fatal in case on unprogrammed EEPROM
01/21/10   dh      fixed klocwork warning
10/18/10   dh      Added boot logger
09/21/10   dh      switched to flash driver API instead of DALI2C
09/16/10   dh      Change read size to 1, eeprom offset to 0
09/10/10   dh      Initialize CDT to default value
09/08/10   dh      Add logic to read EEPROM
08/19/10   dh      Initial Creation.

===========================================================================*/

/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include <stdio.h>
#include "boot_config_data.h"
#include "boot_error_if.h"
#include "boot_sbl_if.h"
#include "boot_logger.h"
#include "boot_target.h"
#include "boot_util.h"
#include "boot_statistics.h"

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/

/**
* structure that holds the cdt table's address and its size
*/
struct cdt_info config_data_table_info;

/**
* array that holds the cdt table
*/
extern uint8 config_data_table[CONFIG_DATA_TABLE_MAX_SIZE];

/**
* actual size of cdt table
*/
extern uint32 config_data_table_size;

/**
* array that holds the cdt table
*/
extern uint8 config_data_table_lpddr3[CONFIG_DATA_TABLE_MAX_SIZE];

/**
* actual size of cdt table
*/
extern uint32 config_data_table_size_lpddr3;

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define REG32(addr) ((volatile uint32_t *)(addr))
#define REG32(addr) ((volatile uint32_t *)(addr))

#define writel(v, a) (*REG32(a) = (v))
#define readl(a) (*REG32(a))
/* GPIO TLMM: Direction */
#define GPIO_INPUT      0
#define GPIO_OUTPUT     1

/* GPIO TLMM: Pullup/Pulldown */
#define GPIO_NO_PULL    0
#define GPIO_PULL_DOWN  1
#define GPIO_KEEPER     2
#define GPIO_PULL_UP    3

/* GPIO TLMM: Drive Strength */
#define GPIO_2MA        0
#define GPIO_4MA        1
#define GPIO_6MA        2
#define GPIO_8MA        3
#define GPIO_10MA       4
#define GPIO_12MA       5
#define GPIO_14MA       6
#define GPIO_16MA       7

/* GPIO TLMM: Status */
#define GPIO_ENABLE     0
#define GPIO_DISABLE    1

#define BIT(n) (1 << (n))


/* GPIO_IN_OUT register shifts. */
#define GPIO_IN         BIT(0)
#define GPIO_OUT        BIT(1)

#define TLMM_BASE_ADDR              0x1000000
#define GPIO_CONFIG_ADDR(x)         (TLMM_BASE_ADDR + (x)*0x1000)
#define GPIO_IN_OUT_ADDR(x)         (TLMM_BASE_ADDR + 0x00000004 + (x)*0x1000)

void gpio_tlmm_config(uint32_t gpio, uint8_t func,
			uint8_t dir, uint8_t pull,
			uint8_t drvstr, uint32_t enable)
{
	uint32_t val = 0;
	val |= pull;
	val |= func << 2;
	val |= drvstr << 6;
	val |= enable << 9;
	writel(val, (uint32_t *)GPIO_CONFIG_ADDR(gpio));
	return;
}
void gpio_set(uint32_t gpio, uint32_t dir)
{
	writel(dir, (uint32_t *)GPIO_IN_OUT_ADDR(gpio));
	return;
}
uint32_t gpio_status(uint32_t gpio)
{
	return readl(GPIO_IN_OUT_ADDR(gpio)) & GPIO_IN;
}

/*===========================================================================

**  Function :  boot_config_data_table_init

** ==========================================================================
*/
/*!
* 
* @brief
*     Initialize the configuration data table. If CDT in EEPROM/eMMC is present,
*     update the predefined table which is linked in
*     at compile time.
*
* @param[in] bl_shared_data_type* shared data between sbl
*
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   None
*/
extern void busywait (uint32 pause_time_us);
void boot_config_data_table_init(bl_shared_data_type* bl_shared_data)
{
  char bootlog_buffer[BOOT_LOG_TEMP_BUFFER_SIZE];
  uint32 bytes_read = 0;
#define LPDDR3_DETECT_PIN 17
  uint32 	status = 0;

  /* Reset the flash byte counter so the number of bytes read from flash
     can be retreived later. */
  boot_statistics_reset_flash_byte_counter();

  boot_log_message("boot_config_data_table_init, Start");
  boot_log_start_timer();


  
  /*populate configuration data table's info*/
  config_data_table_info.size = config_data_table_size;
  config_data_table_info.cdt_ptr = config_data_table;
  gpio_tlmm_config(LPDDR3_DETECT_PIN, 0, GPIO_INPUT, GPIO_PULL_UP, GPIO_2MA, GPIO_ENABLE);
  busywait(1000);
  status = gpio_status(LPDDR3_DETECT_PIN);
  if(status == 0){
		config_data_table_info.size = config_data_table_size_lpddr3;
		config_data_table_info.cdt_ptr = config_data_table_lpddr3;
		boot_log_message("USE LPDDR3 parameter");
		boot_log_message("PULL UP: L");
  }
  else
  {
		boot_log_message("PULL UP: H");
  }
  
  gpio_tlmm_config(LPDDR3_DETECT_PIN, 0, GPIO_INPUT, GPIO_PULL_DOWN, GPIO_2MA, GPIO_ENABLE);
  busywait(1000);
  status = gpio_status(LPDDR3_DETECT_PIN);
  if(status == 0){
		boot_log_message("PULL DOWN: L");
  }
  else
  {
		boot_log_message("PULL DOWN: H");
  }

  boot_update_config_data_table(&config_data_table_info);
  
  /*put a pointer to the table info into sbl shared data so next sbl can access it*/
  bl_shared_data->sbl_shared_data->config_data_table_info = &config_data_table_info;

  
  /* Retreive the number of bytes read from flash via boot statistics. */
  bytes_read = boot_statistics_get_flash_byte_counter();
  

  /* Convert CDT size to string for boot logger. */
  snprintf(bootlog_buffer,
           BOOT_LOG_TEMP_BUFFER_SIZE,
           "(%d Bytes)",
           bytes_read);


  boot_log_stop_timer_optional_data("boot_config_data_table_init, Delta",
                                    bootlog_buffer);
}


/*===========================================================================

**  Function :  get_config_data_block

** ==========================================================================
*/
/*!
* 
* @brief
*    given a pointer to the start of cdt and an configuration data block index,
*    return a pointer to beginning of that configuration data block.
* 
* @param[in] uint8* pointer to the start of cdt table
*
* @param[in] uint32 Index of the configuration data block.
*
* @param[out] uint32* length of the configuration data block   
* 
* @return   pointer to the beginning of request cdb. 
*           Null if error or cdb doesn't exist 
*
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   None
*/
uint8* boot_get_config_data_block(const uint8 *raw_cdt, uint32 index, uint32 *length)
{
  uint8 *cdb_data_ptr = NULL;
  struct cdb_meta *cdb_meta_ptr;
  uint8 *cdb_ptr;
  
  *length = 0;
  
  if(raw_cdt != NULL)
  {
    cdb_meta_ptr = (struct cdb_meta*)((uint32)raw_cdt + sizeof(struct cdt_header));

    /* Integer overflow check */
    BL_VERIFY(( (uint32)raw_cdt <= ( (uint32)raw_cdt + (uint32)cdb_meta_ptr->offset )), BL_ERR_IMG_SIZE_INVALID);    
    cdb_ptr = (uint8*)((uint32)raw_cdt + (uint32)cdb_meta_ptr->offset);
    
    /*get the meta data of request block*/      
    cdb_meta_ptr += index;
                 
    if(
    /*first check if cdt has valid magic number*/
      (((struct cdt_header*)raw_cdt)->magic == CONFIG_DATA_MAGIC)                                          &&
    /*then check if meta data pointer of requested block is in valid range*/
      ((uint32)cdb_meta_ptr < (uint32)cdb_ptr)                                                             &&
      (((uint32)raw_cdt + (uint32)cdb_meta_ptr->offset) >= (uint32)cdb_ptr)                                &&
      ((uint32)cdb_meta_ptr->offset < CONFIG_DATA_TABLE_MAX_SIZE)                                          &&
    /*at last check if requested block has valid size*/
      (cdb_meta_ptr->size > 0)                                                                             &&
      (((uint32)cdb_meta_ptr->offset + (uint32)cdb_meta_ptr->size) > (uint32)cdb_meta_ptr->offset)         &&
      (((uint32)cdb_meta_ptr->offset + (uint32)cdb_meta_ptr->size) < CONFIG_DATA_TABLE_MAX_SIZE))
    {
      *length = cdb_meta_ptr->size;
      cdb_data_ptr = (uint8*)((uint32)raw_cdt + (uint32)cdb_meta_ptr->offset); 
    }
  }
  
  BL_VERIFY ((cdb_data_ptr != NULL), BL_ERR_NULL_PTR);
  
  return cdb_data_ptr;
}


/*===========================================================================

**  Function :  boot_copy_config_data_block

** ==========================================================================
*/
/*!
* 
* @brief
*   Copy a CDB data into a CDT table to the given CDB index. The source CDB data
*   size must match the target CDB size in the CDT.
* 
* @param[in] uint8* pointer to the destination CDT
*
* @param[in] uint32 index of the destination CDB
* 
* @param[in] uint8* pointer to source CDB
*
* @param[in] uint32 size of the source CDB
* 
* @return   TRUE if copy is successful, FALSE if not
*
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   None
*/
boot_boolean boot_copy_config_data_block
(
  uint8 *dst_cdt, 
  uint32 cdb_index, 
  const uint8 *src_cdb_data, 
  uint32 src_cdb_size
)
{ 
  boot_boolean result = FALSE;
  uint32 dst_cdb_size;
  uint8 *dst_cdb_data;
  
  if(dst_cdt != NULL && src_cdb_data != NULL && src_cdb_size != 0)
  {
    /*Get pointers to the source CDB and destination CDB*/
    dst_cdb_data =  boot_get_config_data_block(dst_cdt, cdb_index, &dst_cdb_size);
    
    if(dst_cdb_data != NULL && 
       /*Both CDB size must match*/
       src_cdb_size == dst_cdb_size)
    {
      qmemcpy(dst_cdb_data, src_cdb_data, dst_cdb_size);
      result = TRUE;
    }
  }
  
  return result;
}
