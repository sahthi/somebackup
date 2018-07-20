/*=============================================================================
 *
 * FILE:      flash_nand_dal_reduced.c
 *
 * DESCRIPTION: Functions specific to the NAND DAL reduced mode driver
 *
 * PUBLIC CLASSES:  Not Applicable
 *
 * INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A
 *
 * Copyright (c) 2012 Qualcomm Technologies Incorporated.
 * All Rights Reserved.
 * QUALCOMM Confidential and Proprietary
 *===========================================================================*/

/*===================================================================
 *
 *                       EDIT HISTORY FOR FILE
 *
 *   This section contains comments describing changes made to the
 *   module. Notice that changes are listed in reverse chronological
 *   order.
 *
 *  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/flash/src/dal/flash_dal_nand_reduced.c#1 $ $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $
 *
 *
 * when         who     what, where, why
 * ----------   ---     ----------------------------------------------
 * 08/31/12     sv      Initial Revision
 *==================================================================*/

/*===================================================================
 *
 *                     Include Files
 *
 ====================================================================*/

#include "flash_nand_entry.h"

flash_vtbl* nand_get_entry_vtbl(void)
{
  return nand_get_entry_vtbl_reduced();
}
