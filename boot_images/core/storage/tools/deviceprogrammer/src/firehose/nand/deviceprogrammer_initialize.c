/*==================================================================
 *
 * FILE:        deviceprogrammer_initialize.c
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
 *   $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/deviceprogrammer/src/firehose/nand/deviceprogrammer_initialize.c#1 $
 *   $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $
 *
 * YYYY-MM-DD   who     what, where, why
 * ----------   ---     ----------------------------------------------
 * 2014-10-15   sb      Updated for 8909
 * 2013-06-03   ah      Added legal header
 * 2013-05-31   ab      Initial checkin
 */

#include <locale.h>
#include "deviceprogrammer_utils.h"
#include "deviceprogrammer_initialize.h"
#include "msm.h"
#include "ClockBoot.h"
#include "pm.h"
#include "SpmiBus.h"
#include "SpmiCfg.h"
#include "ddr_drivers.h"
#include "deviceprogrammer_firehose.h"
#include "deviceprogrammer_security.h"
#include "deviceprogrammer_bsp.h"
#include "HALhwio.h"

//#include "deviceprogrammer_storage.h"

#include "pm_rgb.h"

extern void main_firehose(void);
extern boolean Clock_PreDDRInitEx(uint32 ddr_type);

extern firehose_protocol_t fh;

boot_pbl_shared_data_type *pbl_shared_global;

// NOTE: Storage device is initialized later when handling <configure> tag,
// since it specifies which storage device to use
static void deviceprogrammer_init_hw()
{
    char err_log[2048] = {0};
    int i;

	
    //Change config to NAND
    HWIO_OUT(TLMM_EBI2_EMMC_GPIO_CFG, 0x2);
	 	/* Enable QPIC clocks.*/
  	Clock_EnableQPICForDownloadMode();
  
    initFirehoseProtocol(); // initializes default values for fh structure

    #ifndef FEATURE_FIREHOSE_SKIP_CLOCK
    #ifndef FEATURE_BOOT_EXTERN_DEVICEPROGRAMMER_DDR_COMPLETED
        // This needs to be called before calling Clock_Init()
        if (TRUE != Clock_PreDDRInitEx(DDR_TYPE_LPDDR2))                     { strlcat(err_log, "Clock_PreDDRInitEx(DDR_TYPE_LPDDR2) clock pre ddr:fail ", sizeof(err_log)); }
    #endif
        // Lower clocks for HW init
        if (FALSE == Clock_Init(CLOCK_BOOT_PERF_MIN, CLOCK_BOOT_PERF_MIN)) { strlcat(err_log, "init clock:fail ", sizeof(err_log)); }
    #endif

    // Call setlocale to set the locale to the default values
    // for string functions such as strncasecmp to work properly
    setlocale(LC_ALL, "C");

    if (SPMI_CFG_SUCCESS != SpmiCfg_Init(TRUE))                        { strlcat(err_log, "init spmi_cfg:fail ", sizeof(err_log)); }
    delaySeconds(1);
    if (SPMI_BUS_SUCCESS != SpmiBus_Init())                            { strlcat(err_log, "init spmi_bus:fail ", sizeof(err_log)); }
//    if (PM_ERR_FLAG__SUCCESS != pm_pon_wdog_enable(
//                                    0,
//                                    PM_OFF))                           { strlcat(err_log, "init wdog:fail ", sizeof(err_log)); }


/*
    fh.validation_enabled = FALSE;

#ifndef SKIP_SECBOOT_CHECK_NOT_RECOMMENDED_BY_QUALCOMM
    // This check below is to ensure that only VIP programmer is run on secure boot devices
    // In otherwords, signing the non VIP programmer is highly not recommended
    if( isSecureBootEnabled()==TRUE )
    {
        // To be here means Secure Boot Fuses are blown, therefore must use VIP
        fh.validation_enabled = TRUE;
    }
#endif*/

    // These PMIC calls were added to have long key power off to be
    // working from flash programmer so that device can be powered off in
    // factory for devices that do not have removable battery
    pm_pon_reset_source_cfg(0,PM_PON_RESET_SOURCE_KPDPWR,904,500,
    PM_PON_RESET_CFG_NORMAL_SHUTDOWN);
    pm_pon_reset_source_ctl(0, PM_PON_RESET_SOURCE_KPDPWR,PM_ON);

    initFirehoseTransport();    // Initialize USB transport

	//Initialize nand_device_params struct
	if (FALSE == initFirehoseStorage()) 							   { strlcat(err_log, "init storage:fail ", sizeof(err_log)); }


#ifndef FEATURE_FIREHOSE_SKIP_CLOCK
    // This calls the Clock API to bump up clocks. USB hangs if clock is not set to max.
    //
    // Before doing this, we need support for it in the Clock SCons
    // env.AddLibsToImage(['CLOCK_BOOT_DRIVER', 'EMMCBLD_IMAGE'],
    // ClockChipsetSBL_lib)
    // in file core\systemdrivers\clock\hw\msm8974\build\clock_sbl.scons
    if (FALSE == Clock_Init(CLOCK_BOOT_PERF_MAX, CLOCK_BOOT_PERF_MAX)) { strlcat(err_log, "Clock_Init(CLOCK_BOOT_PERF_MAX):fail ", sizeof(err_log)); }
#endif

    if (strlen((const char *)err_log) > 0) {
        for (i = 0; i < 20; i++) {
            logMessage(err_log);
            delaySeconds(2);
        }
        logMessage("Now resetting to EDL...");
		
        delaySeconds(2);
        //bsp_target_reset_edl();
    }

    // Everything is wonderful, call main_firehose() next.
}

void deviceprogrammer_common_main() {    
	deviceprogrammer_init_hw();    
	main_firehose();
	}



void deviceprogrammer_imem_main(boot_pbl_shared_data_type *pbl_shared) {
	pbl_shared_global = pbl_shared;    
	deviceprogrammer_common_main();
	}


