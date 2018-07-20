/**********************************************************************
* ufs_bsp_8084.c
*
* Board support file for MSM8084
*
* Copyright (c) 2013 Qualcomm Technologies, Inc.  All Rights Reserved.
* Qualcomm Technologies Proprietary and Confidential.
* 
*
**********************************************************************/

/*=======================================================================
                        Edit History

$Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/bsp/ufs_bsp_8084.c#1 $
$DateTime: 2016/12/12 23:35:46 $

YYYY-MM-DD   who     what, where, why
---------------------------------------------------------------------- 
2013-06-19   rh      Initial creation
===========================================================================*/

#include "stdint.h"
#include "hwio_clkgcc_v1.h"
#include "ufs_bsp.h"
#include "HALhwio.h"


/* Clock regime clock offset mapping */
#define HWIO_GCC_UFS_TX_SYMBOL_0_CBCR_OUT(v)       \
        out_dword(HWIO_GCC_UFS_TX_SYMBOL_0_CBCR_ADDR,v)
#define HWIO_GCC_UFS_TX_SYMBOL_1_CBCR_OUT(v)       \
        out_dword(HWIO_GCC_UFS_TX_SYMBOL_1_CBCR_ADDR,v)
#define HWIO_GCC_UFS_RX_SYMBOL_0_CBCR_OUT(v)       \
        out_dword(HWIO_GCC_UFS_RX_SYMBOL_0_CBCR_ADDR,v)
#define HWIO_GCC_UFS_RX_SYMBOL_1_CBCR_OUT(v)       \
        out_dword(HWIO_GCC_UFS_RX_SYMBOL_1_CBCR_ADDR,v)

#define HWIO_GCC_UFS_RX_CFG_CBCR_OUT(v)         \
        out_dword(HWIO_GCC_UFS_RX_CFG_CBCR_ADDR,v)
#define HWIO_GCC_UFS_TX_CFG_CBCR_OUT(v)         \
        out_dword(HWIO_GCC_UFS_TX_CFG_CBCR_ADDR,v)

#define HWIO_GCC_UFS_AXI_CMD_RCGR_OUT(v)        \
        out_dword(HWIO_GCC_UFS_AXI_CMD_RCGR_ADDR,v)
#define HWIO_GCC_UFS_AXI_CFG_RCGR_OUT(v)        \
        out_dword(HWIO_GCC_UFS_AXI_CFG_RCGR_ADDR,v)
#define HWIO_GCC_SYS_NOC_UFS_AXI_CBCR_OUT(v)        \
        out_dword(HWIO_GCC_SYS_NOC_UFS_AXI_CBCR_ADDR,v)
#define HWIO_GCC_UFS_AXI_CBCR_OUT(v)        \
        out_dword(HWIO_GCC_UFS_AXI_CBCR_ADDR,v)
#define HWIO_GCC_UFS_AHB_CBCR_OUT(v)        \
        out_dword(HWIO_GCC_UFS_AHB_CBCR_ADDR,v)


#define RCGR_DIVBYPASS                      0
#define RCGR_DIV2                           3
#define RCGR_DIV3                           5
#define RCGR_DIV4                           7

#define RCGR_MODE_BYPASS                    0
#define RCGR_MODE_DUAL_EDGE                 2
#define RCGR_MODE_SINGLE_EDGE               3

void ufs_bsp_clk_set (uint8_t hostid, uint32_t mode)
{
   (void) hostid;
   if (mode == UFS_CLOCK_MODE_OFF)
   {
      // Turn everything off
      HWIO_GCC_UFS_TX_SYMBOL_0_CBCR_OUT (0);
      HWIO_GCC_UFS_TX_SYMBOL_1_CBCR_OUT (0);
      HWIO_GCC_UFS_RX_SYMBOL_0_CBCR_OUT (0);
      HWIO_GCC_UFS_RX_SYMBOL_1_CBCR_OUT (0);

      HWIO_GCC_UFS_RX_CFG_CBCR_OUT (0);
      HWIO_GCC_UFS_TX_CFG_CBCR_OUT (0);
      HWIO_GCC_SYS_NOC_UFS_AXI_CBCR_OUT (0);
      HWIO_GCC_UFS_AHB_CBCR_OUT (0);
      HWIO_GCC_UFS_AXI_CBCR_OUT (0);
   }
   else if (mode == UFS_CLOCK_MODE_ON)
   {
 /*
      HWIO_GCC_SYS_NOC_UFS_AXI_CBCR_OUT (1);
      // Configure for 200MHz operation from GPLL0: 600MHz / 3 = 200MHz
      HWIO_GCC_UFS_AXI_CBCR_OUT (0);
      HWIO_GCC_UFS_AXI_CFG_RCGR_OUT ((RCGR_MODE_SINGLE_EDGE << HWIO_GCC_UFS_AXI_CFG_RCGR_MODE_SHFT) |
                                     (0 << HWIO_GCC_UFS_AXI_CFG_RCGR_SRC_SEL_SHFT) |
                                     (RCGR_DIV3 << HWIO_GCC_UFS_AXI_CFG_RCGR_SRC_DIV_SHFT));
      HWIO_GCC_UFS_AXI_CBCR_OUT (1);
      HWIO_GCC_UFS_AXI_CMD_RCGR_OUT (HWIO_GCC_UFS_AXI_CMD_RCGR_ROOT_EN_BMSK | 
                                     HWIO_GCC_UFS_AXI_CMD_RCGR_UPDATE_BMSK );
      HWIO_GCC_UFS_AHB_CBCR_OUT (1);
      HWIO_GCC_UFS_TX_CFG_CBCR_OUT (1);
      HWIO_GCC_UFS_RX_CFG_CBCR_OUT (1);
      // Simple - Just turn on the clock
      HWIO_GCC_UFS_TX_SYMBOL_0_CBCR_OUT (1);
      HWIO_GCC_UFS_TX_SYMBOL_1_CBCR_OUT (1);
      HWIO_GCC_UFS_RX_SYMBOL_0_CBCR_OUT (1);
      HWIO_GCC_UFS_RX_SYMBOL_1_CBCR_OUT (1);

*/              

      // Simple - Just turn on the clock
     // move this HWIO_GCC_UFS_TX_SYMBOL_0_CBCR_OUT (1);
     // HWIO_GCC_UFS_TX_SYMBOL_1_CBCR_OUT (1);
     // HWIO_GCC_UFS_RX_SYMBOL_0_CBCR_OUT (1);
     // HWIO_GCC_UFS_RX_SYMBOL_1_CBCR_OUT (1);

      HWIO_OUTF(GCC_UFS_TX_CFG_CBCR, CLK_DIV, 1); // Div2 for 100 MHz
      HWIO_OUTF(GCC_UFS_RX_CFG_CBCR, CLK_DIV, 1); // Div2 for 100 MHz

      HWIO_GCC_SYS_NOC_UFS_AXI_CBCR_OUT (1);

      // Configure for 200MHz operation from GPLL0: 600MHz / 3 = 200MHz
      HWIO_GCC_UFS_AXI_CBCR_OUT (0);
      while(HWIO_INF(GCC_UFS_AXI_CBCR, CLK_OFF) == 0);

      HWIO_GCC_UFS_AXI_CFG_RCGR_OUT ((0 << HWIO_GCC_UFS_AXI_CFG_RCGR_MODE_SHFT) |
                                     (1 << HWIO_GCC_UFS_AXI_CFG_RCGR_SRC_SEL_SHFT) |
                                     (RCGR_DIV3 << HWIO_GCC_UFS_AXI_CFG_RCGR_SRC_DIV_SHFT));
      HWIO_GCC_UFS_AXI_CMD_RCGR_OUT (HWIO_GCC_UFS_AXI_CMD_RCGR_UPDATE_BMSK );
      while(HWIO_INF(GCC_UFS_AXI_CMD_RCGR, UPDATE) == 1);
      HWIO_GCC_UFS_AXI_CBCR_OUT (1);
      while(HWIO_INF(GCC_UFS_AXI_CBCR, CLK_OFF) == 1);
     
      /* UFS AHB is derived from CNOC. Configuring CNOC to give 75MHz */
      *((uint32_t*) 0xFC400154)=0x10F;
      *((uint32_t*) 0xFC400150)=0x1;
      ufs_bsp_busy_wait(1000);
     
      HWIO_GCC_UFS_AHB_CBCR_OUT (1);
      
      while(HWIO_INF(GCC_UFS_AHB_CBCR, CLK_OFF) == 1);
    
      /* Matching with VI config -    #ifndef UFS_SYMBOL_CLK_TEMP_FIX */      
      *((uint32_t*) 0xFC401D54)=0x6FF0;
      *((uint32_t*) 0xFC401D5C)=0x6FF0;
     
      HWIO_OUTF(GCC_UFS_TX_CFG_CBCR, CLK_DIV, 1); // Div2 for 100 MHz
      HWIO_OUTF(GCC_UFS_RX_CFG_CBCR, CLK_DIV, 1); // Div2 for 100 MHz

      HWIO_OUTF(GCC_UFS_TX_CFG_CBCR, CLK_ENABLE, 1); // Enable the clock
      HWIO_OUTF(GCC_UFS_RX_CFG_CBCR, CLK_ENABLE, 1); // Enable the clock
      ufs_bsp_busy_wait(100);
#if 0
   //aseem
      HWIO_GCC_SYS_NOC_UFS_AXI_CBCR_OUT (1);
      HWIO_GCC_UFS_AXI_CBCR_OUT (1);
      HWIO_GCC_UFS_AHB_CBCR_OUT (1);
      HWIO_GCC_UFS_TX_CFG_CBCR_OUT (1);
      HWIO_GCC_UFS_RX_CFG_CBCR_OUT (1);
      HWIO_GCC_UFS_AXI_CMD_RCGR_OUT (HWIO_GCC_UFS_AXI_CMD_RCGR_ROOT_EN_BMSK | 
                                     HWIO_GCC_UFS_AXI_CMD_RCGR_UPDATE_BMSK );
      HWIO_GCC_UFS_TX_SYMBOL_0_CBCR_OUT (1);
      HWIO_GCC_UFS_TX_SYMBOL_1_CBCR_OUT (1);
      HWIO_GCC_UFS_RX_SYMBOL_0_CBCR_OUT (1);
      HWIO_GCC_UFS_RX_SYMBOL_1_CBCR_OUT (1);
#endif
   }
}

void ufs_bsp_enable_symbol_clk (void)
{
//    HWIO_GCC_UFS_TX_SYMBOL_0_CBCR_OUT (1);
     *((uint32_t*) 0xFC401D54)=0x6FF1;
      *((uint32_t*) 0xFC401D5C)=0x6FF1;
//    HWIO_GCC_UFS_RX_SYMBOL_0_CBCR_OUT (1);
    HWIO_GCC_UFS_TX_SYMBOL_1_CBCR_OUT (1);
    HWIO_GCC_UFS_RX_SYMBOL_1_CBCR_OUT (1);   
}

void ufs_bsp_busy_wait(uint32_t us)
{
   // Use dummy FOR loop for delay
   uint32_t pause_cycle = 0;
   uint32_t i = 0;
   
   /* Each penalty of write is 13 cycles */
   for (pause_cycle = 0; pause_cycle < us; pause_cycle++)
   {
      for(i = 0; i < 1000; i++);
   }
}


