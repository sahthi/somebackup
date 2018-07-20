#ifndef __DDR_PHY_H__
#define __DDR_PHY_H__


/**
 * @file DDR_PHY.h
 * @brief
 * Header file of DDR PHY drivers.
 */
/*==============================================================================
                                EDIT HISTORY

$Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/boot/ddr/hw/phy/v1/DDR_PHY.h#1 $
$DateTime: 2016/12/12 23:35:46 $
$Author: pwbldsvc $
================================================================================
when       who     what, where, why
--------   ---     -------------------------------------------------------------
03/21/16   sk      Updated Slew and ROut values through CDT
04/21/15   yps     added support each byte cdc delay setting function
02/09/14   tw      added support for common ddr library
08/15/13   sl      Added functions for updating drive strength and CDC delay.
04/10/13   sl      Updated HAL_SDRAM_PHY_Update_CDC_Config().
09/26/12   sl      Initial version.
================================================================================
                   Copyright 2012-2013,2016 Qualcomm Technologies Incorporated
                              All Rights Reserved
                     Qualcomm Confidential and Proprietary
==============================================================================*/
/*==============================================================================
                                  INCLUDES
==============================================================================*/
#include "ddr_common.h"
#include "ddr_func_tbl.h"

struct ddr_cdc_delay_values
{
 uint16 cdc_cdt_feature;
 uint16 svs_ca_cdc;
 uint16 svs_dq_read_cdc[4];
 uint16 svs_dq_write_cdc[4];
 uint16 nom_ca_cdc;
 uint16 nom_dq_read_cdc[4];
 uint16 nom_dq_write_cdc[4];
 uint16 turbo_ca_cdc;
 uint16 turbo_dq_read_cdc[4];
 uint16 turbo_dq_write_cdc[4];
};

struct ddr_slew_rout_values
{
 uint16 cdc_cdt_feature; 
 uint16 ca_nslew[2];
 uint16 ca_pslew[2];
 uint16 ca_rout[2];
 uint16 dq_nslew[2];
 uint16 dq_pslew[2];
 uint16 dq_rout[2];
};
/*==============================================================================
                                  FUNCTIONS
==============================================================================*/

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Init
** =============================================================================
*/
/**
*   @brief
*   Initialize DDR PHY.
*
*   @param[in]  interface  Interface to initialize for
*   @param[in]  clk_speed  Clock speed (in KHz) to initialize for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Init(uint32 base, SDRAM_INTERFACE interface, uint32 clk_speed);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Enable_IO_Cal
** =============================================================================
*/
/**
*   @brief
*   Enable auto IOCAL.
*
*   @param[in]  interface  Interface to enable auto IOCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Enable_IO_Cal(uint32 base, SDRAM_INTERFACE interface);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Disable_IO_Cal
** =============================================================================
*/
/**
*   @brief
*   Disable auto IOCAL.
*
*   @param[in]  interface  Interface to disable auto IOCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Disable_IO_Cal(uint32 base, SDRAM_INTERFACE interface, ddr_wait wait);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Manual_IO_Cal
** =============================================================================
*/
/**
*   @brief
*   Issue manual IOCAL.
*
*   @param[in]  interface  Interface to issue manual IOCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Manual_IO_Cal(uint32 base, SDRAM_INTERFACE interface, ddr_wait wait);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Enable_CDC_Cal
** =============================================================================
*/
/**
*   @brief
*   Enable auto CDCCAL.
*
*   @param[in]  interface  Interface to enable auto CDCCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Enable_CDC_Cal(uint32 base, SDRAM_INTERFACE interface);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Disable_CDC_Cal
** =============================================================================
*/
/**
*   @brief
*   Disable auto CDCCAL.
*
*   @param[in]  interface  Interface to disable auto CDCCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Disable_CDC_Cal(uint32 base, SDRAM_INTERFACE interface);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Manual_CDC_Cal
** =============================================================================
*/
/**
*   @brief
*   Issue manual CDCCAL.
*
*   @param[in]  interface  Interface to issue manual CDCCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Manual_CDC_Cal(uint32 base, SDRAM_INTERFACE interface);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Enable_Rapid_CDC_Cal
** =============================================================================
*/
/**
*   @brief
*   Enable rapid CDCCAL.
*
*   @param[in]  interface  Interface to enable rapid CDCCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Enable_Rapid_CDC_Cal(uint32 base, SDRAM_INTERFACE interface);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Disable_Rapid_CDC_Cal
** =============================================================================
*/
/**
*   @brief
*   Disable rapid CDCCAL.
*
*   @param[in]  interface  Interface to disable rapid CDCCAL for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Disable_Rapid_CDC_Cal(uint32 base, SDRAM_INTERFACE interface);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Update_CDC_Config
** =============================================================================
*/
/**
*   @brief
*   Update CDC configuration according to voltage.
*
*   @param[in]  interface  Interface to update CDC configuration for
*   @param[in]  config     Configuration to update with
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Update_CDC_Config(uint32 base, SDRAM_INTERFACE interface, uint32 config);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Update_Drive_Strength
** =============================================================================
*/
/**
*   @brief
*   Update DDR PHY drive strength.
*
*   @param[in]  interface  Interface to update drive strength for
*   @param[in]  rout       rout of drive strength
*   @param[in]  pslew      pslew of drive strength
*   @param[in]  nslew      nslew of drive strength
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Update_Drive_Strength
(
  uint32 base,
  SDRAM_INTERFACE interface,
  uint32 rout,
  uint32 pslew,
  uint32 nslew
);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Update_CDC_Delay
** =============================================================================
*/
/**
*   @brief
*   Update CDC delay.
*
*   @param[in]  interface  Interface to update CDC delay for
*   @param[in]  read       TRUE for read CDC and FALSE for write CDC
*   @param[in]  cdc_delay  CDC delay value
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Update_CDC_Delay
(
  uint32 base, 
  SDRAM_INTERFACE interface,
  boolean read,
  uint32 cdc_delay
);

/* =============================================================================
**  Function : HAL_SDRAM_PHY_Update_Per_Byte_CDC_Delay
** =============================================================================
*/
/**
*   @brief
*   Update each byte CDC delay.
*
*   @param[in]  interface  Interface to update each byte CDC delay for
*   @param[in]  read       TRUE for read CDC and FALSE for write CDC
*   @param[in]  each_byte_cdc_delay  CDC settings pointer for each byte
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_PHY_Update_Per_Byte_CDC_Delay(uint32 base, SDRAM_INTERFACE interface, boolean read,uint32 *each_byte_cdc_delay );
#endif /* __DDR_PHY_H__ */
