/**
 * @file:  SpmiCfg.h
 * @brief: This module provides configuration options for the SPMI controller
 * 
 * Copyright (c) 2015 by Qualcomm Technologies Incorporated. All Rights Reserved.
 * 
 * $DateTime: 2016/12/12 23:35:46 $
 * $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/buses/spmi/src/core/SpmiCfgInternal.h#1 $
 * $Change: 11981336 $ 
 * 
 *                              Edit History
 * Date      Description
 * --------  -------------------------------------------------------------------
 * 11/14/14  Initial Version
 */
#ifndef SPMICFGINTERNAL_H
#define	SPMICFGINTERNAL_H

#include "SpmiCfg.h"

//******************************************************************************
// Public API Functions
//******************************************************************************

boolean SpmiCfg_InDynamicChannelMode(void);
Spmi_Result SpmiCfg_ConfigureChannel(SpmiCfg_ChannelCfg* chanCfg, boolean autoAssignChan);

#endif
