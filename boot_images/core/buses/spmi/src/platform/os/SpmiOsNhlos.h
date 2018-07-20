/**
 * @file:  SpmiOsNhlos.h
 * @brief: Implements platform specific functionality
 * 
 * Copyright (c) 2013 by Qualcomm Technologies Incorporated. All Rights Reserved.
 * 
 * $DateTime: 2016/12/12 23:35:46 $
 * $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/buses/spmi/src/platform/os/SpmiOsNhlos.h#1 $
 * $Change: 11981336 $ 
 * 
 *                              Edit History
 * Date     Description
 * -------  -------------------------------------------------------------------
 * 10/1/13  Initial Version
 */
#ifndef SPMIOSNHLOS_H
#define	SPMIOSNHLOS_H

#include "SpmiTypes.h"
#include "DALSysTypes.h"

Spmi_Result SpmiOsNhlos_GetDalProp(char* propId, DALSYSPropertyVar* val);

#endif
