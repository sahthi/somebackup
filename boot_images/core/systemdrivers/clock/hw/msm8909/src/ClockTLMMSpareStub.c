/** @file ClockTlmmSpare.c
   
  This is a stub file to avoid compilation for EMMC.

  Copyright (c) 2014, Qualcomm Technologies Inc. All rights reserved.
  
**/
/*=============================================================================
                              EDIT HISTORY

  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/systemdrivers/clock/hw/msm8909/src/ClockTLMMSpareStub.c#1 $ 
  $DateTime: 2016/12/12 23:35:46 $ 
  $Author: pwbldsvc $ 

 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 18/02/14   mkumari     Initial version

=============================================================================*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "com_dtypes.h"
#include "DDIChipInfo.h"

/* ========================================================================
**  Function : Clock_GetChipId()
** ======================================================================*/
/*
    Description: Get chip id type stub API

    @param   None
    @return
    TRUE  -- Configuration was success.
    FALSE -- Configuration failed.

    @dependencies
    None.

    @sa None
*/

DalChipInfoIdType Clock_GetChipId(void)
{
    return DALCHIPINFO_ID_UNKNOWN;
}
/* ========================================================================
**  Function : Clock_ExtBuck_GPIO_Misc
** ======================================================================*/
/*
    Description: This is a stub API to avoid compilation for EMMC.

    @param NONE
    @return
    TRUE  -- Configuration was success.
    FALSE -- Configuration failed.

    @dependencies
    None.

    @sa None
*/

boolean Clock_ExtBuckGPIOMisc(void)
{
  
    return TRUE;

}
