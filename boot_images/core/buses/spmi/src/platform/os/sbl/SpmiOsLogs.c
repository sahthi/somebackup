/**
 * @file:  SpmiOsLogs.c
 * 
 * Copyright (c) 2013 by Qualcomm Technologies Incorporated. All Rights Reserved.
 * 
 * $DateTime: 2016/12/12 23:35:46 $
 * $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/buses/spmi/src/platform/os/sbl/SpmiOsLogs.c#1 $
 * $Change: 11981336 $
 * 
 *                              Edit History
 * Date     Description
 * -------  -------------------------------------------------------------------
 * 10/1/13  Initial Version
 */

#include "SpmiLogs.h"

//******************************************************************************
// Global Data
//******************************************************************************

char spmiLogBuf[SPMI_MAX_LOG_LEN];
