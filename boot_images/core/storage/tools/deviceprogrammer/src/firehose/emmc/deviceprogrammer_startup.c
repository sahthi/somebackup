/*==================================================================
 *
 * FILE:        deviceprogrammer_initialize.c
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
 *   $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/deviceprogrammer/src/firehose/emmc/deviceprogrammer_startup.c#1 $ 
 *   $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $
 *
 * YYYY-MM-DD   who     what, where, why
 * ----------   ---     ----------------------------------------------
 * 2013-06-03   ah      Added legal header
 * 2013-05-31   ab      Initial checkin
 */

#include "deviceprogrammer_utils.h"
#include "deviceprogrammer_scatter_load.h"
#include "deviceprogrammer_initialize.h"

void DALSYS_BusyWait(uint32 pause_time_us)
{
	int i;
        for (i=0;i<1000;i++);
}

/* Stub code required to compile USB driver in HOSTDL environment */
uint32 rex_int_lock ( void )
{
   return 0;
} 

uint32 rex_int_free ( void )
{
   return 0;
} 

void deviceprogrammer_main_ctl(boot_pbl_shared_data_type *pbl_shared)
{
    deviceprogrammer_scatter_load();
    deviceprogrammer_imem_main(pbl_shared);
}

