/*==================================================================
 *
 * FILE:        deviceprogrammer_scatter_load.c
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
 *   $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/deviceprogrammer/src/firehose/emmc/deviceprogrammer_scatter_load.c#1 $ 
 *   $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $
 *
 * YYYY-MM-DD   who     what, where, why
 * ----------   ---     ----------------------------------------------
 * 2013-06-03   ah      Added legal header
 * 2013-05-31   ab      Initial checkin
 */

#include "deviceprogrammer_scatter_load.h"
#include "stringl.h"

/* RAM Data Initialization structure */
typedef struct{  
  uint8  *load_rw_base;
  uint8  *image_rw_base;
  uint32 *image_rw_len;
} scatter_rw_t;

typedef struct {
  uint8  *image_zi_base;
  uint32 *image_zi_len;
} scatter_zi_t;

/* Scatterload Region Initialization structure */
typedef struct {
  uint8  *load_region_base;
  uint8  *image_region_base;
  uint32 *image_region_len;
} scatter_ro_t;

extern uint32  Load$$APP_RAM_RO$$Base;
extern uint32  Image$$APP_RAM_RO$$Base;
extern uint32  Image$$APP_RAM_RO$$Length;
extern uint32  Load$$APP_RAM_RW$$Base;
extern uint32  Image$$APP_RAM_RW$$Base;
extern uint32  Image$$APP_RAM_RW$$Length;
extern uint32  Image$$APP_RAM_ZI$$Base;
extern uint32  Image$$APP_RAM_ZI$$ZI$$Length;
extern uint32  Image$$APP_RAM_ZI$$ZI$$Limit;
extern uint32  Image$$USB_ZI$$Base;
extern uint32  Image$$USB_ZI$$ZI$$Length;
extern uint32  Image$$USB_ZI$$ZI$$Limit;
extern uint32  Image$$CHANNEL_BUFFER_A_ZI$$Base;
extern uint32  Image$$CHANNEL_BUFFER_A_ZI$$ZI$$Length;
extern uint32  Image$$CHANNEL_BUFFER_A_ZI$$ZI$$Limit;
extern uint32  Image$$CHANNEL_BUFFER_B_ZI$$Base;
extern uint32  Image$$CHANNEL_BUFFER_B_ZI$$ZI$$Length;
extern uint32  Image$$CHANNEL_BUFFER_B_ZI$$ZI$$Limit;
extern uint32  Image$$TRANSMIT_BUFFER_ZI$$Base;
extern uint32  Image$$TRANSMIT_BUFFER_ZI$$ZI$$Length;
extern uint32  Image$$TRANSMIT_BUFFER_ZI$$ZI$$Limit;

scatter_rw_t rw_data[] =
{
    {
        (uint8*)&Load$$APP_RAM_RW$$Base,   // load_rw_base
        (uint8*)&Image$$APP_RAM_RW$$Base,  // image_rw_base
        &Image$$APP_RAM_RW$$Length,        // image_rw_len
    },
    {NULL, NULL, NULL}
};

scatter_ro_t ro_data[] =
{
    {
        (uint8*)&Load$$APP_RAM_RO$$Base,   // load_region_base
        (uint8*)&Image$$APP_RAM_RO$$Base,  // image_region_base
        &Image$$APP_RAM_RO$$Length         // image_region_len
    },
    {NULL, NULL, NULL}
};

scatter_zi_t zi_data[] =
{
    {
        (uint8*)&Image$$APP_RAM_ZI$$Base,  // image_zi_base
        &Image$$APP_RAM_ZI$$ZI$$Length     // image_zi_len
    },
    {
        (uint8*)&Image$$CHANNEL_BUFFER_A_ZI$$Base,  // image_zi_base
        &Image$$CHANNEL_BUFFER_A_ZI$$ZI$$Length     // image_zi_len
    },
    {
        (uint8*)&Image$$CHANNEL_BUFFER_B_ZI$$Base,  // image_zi_base
        &Image$$CHANNEL_BUFFER_B_ZI$$ZI$$Length     // image_zi_len
    },
    {
        (uint8*)&Image$$TRANSMIT_BUFFER_ZI$$Base,  // image_zi_base
        &Image$$TRANSMIT_BUFFER_ZI$$ZI$$Length     // image_zi_len
    },
    {
        (uint8*)&Image$$USB_ZI$$Base,  // image_zi_base
        &Image$$USB_ZI$$ZI$$Length     // image_zi_len
    },
    {NULL, NULL}
};

void deviceprogrammer_scatter_load()
{
    int i = 0;

    i = 0;
    while (ro_data[i].load_region_base  != NULL
        || ro_data[i].image_region_base != NULL
        || ro_data[i].image_region_len  != NULL) {
        if (ro_data[i].load_region_base != ro_data[i].image_region_base) {
            memsmove(ro_data[i].image_region_base,
            (uint32) ro_data[i].image_region_len,
                     ro_data[i].load_region_base,
            (uint32) ro_data[i].image_region_len);
        }
        i++;
    }

    i = 0;
    while (rw_data[i].load_rw_base != NULL
        || rw_data[i].image_rw_base != NULL
        || rw_data[i].image_rw_len != NULL) {
        if (rw_data[i].load_rw_base != rw_data[i].image_rw_base) {
            // This is a hack to get around the fact that the linker was
            // generating the Load and Image sections just 4 bytes apart
            // Even though the symobls were already matched up with their
            // values, so no relocation was needed
            // Haven't yet investigated why.
            if (rw_data[i].load_rw_base < rw_data[i].image_rw_base
                && rw_data[i].image_rw_base - rw_data[i].load_rw_base <= 8)
                break;
            /* Copy RW data from the load region to the execute region .*/
            memsmove(rw_data[i].image_rw_base,
            (uint32) rw_data[i].image_rw_len,
                    rw_data[i].load_rw_base,
           (uint32) rw_data[i].image_rw_len);
        }
        i++;
    }

    i = 0;
    while (zi_data[i].image_zi_base != NULL
        || zi_data[i].image_zi_len  != NULL) {
        memset(zi_data[i].image_zi_base, 
                0, 
                (uint32)zi_data[i].image_zi_len);
        i++;
    }
}

