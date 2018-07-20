#ifndef UFS_BSP_H
#define UFS_BSP_H
 /**********************************************************************
 * ufs_bsp.h
 *
 * UFS driver BSP.
 *
 * Copyright (c) 2008-2012
 * Qualcomm Technologies Incorporated.
 * All Rights Reserved.
 * Qualcomm Confidential and Proprietary
 *
 **********************************************************************

                             Edit History

$Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/bsp/ufs_bsp.h#1 $
$DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $

when         who    what, where, why
----------   ---    --------------------------------------------------------------  
2013-06-20   rh     Initial version.
-----------------------------------------------------------------------------*/

#define UFS_CLOCK_MODE_OFF    0
#define UFS_CLOCK_MODE_ON     1

/* Configuration of all clock sources */
void ufs_bsp_clk_set (uint8_t hostid, uint32_t mode);

/* Cock busy wait function, unit in uS*/
void ufs_bsp_busy_wait(uint32_t us);

void ufs_bsp_enable_symbol_clk (void);

#endif /* #ifndef UFS_BSP_H */

