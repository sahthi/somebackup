#ifndef __UFS_PHY_HWIO_H__
#define __UFS_PHY_HWIO_H__
/*
===========================================================================
*/
/**
  @file ufs_phy_hwio.h
  @brief Auto-generated HWIO interface include file.

  This file contains HWIO register definitions for the following modules:
    UFS_UFS_PHY_UFS_PHY_UFS_PCS
    UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON
    UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX
    UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX
    UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX
    UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX
    UFS

  'Include' filters applied: 
  'Exclude' filters applied: RESERVED DUMMY 
*/
/*
  ===========================================================================

  Copyright (c) 2013 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ===========================================================================

  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/bsp/ufs_phy_hwio.h#1 $
  $DateTime: 2016/12/12 23:35:46 $
  $Author: pwbldsvc $

  ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: UFS_UFS_PHY_UFS_PHY_UFS_PCS
 *--------------------------------------------------------------------------*/

#define UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE                                                                             (UFS_UFS_REGS_BASE      + 0x00007700)

#define HWIO_UFS_UFS_PHY_PHY_START_ADDR                                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000000)
#define HWIO_UFS_UFS_PHY_PHY_START_RMSK                                                                                         0x1
#define HWIO_UFS_UFS_PHY_PHY_START_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_PHY_START_ADDR, HWIO_UFS_UFS_PHY_PHY_START_RMSK)
#define HWIO_UFS_UFS_PHY_PHY_START_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_PHY_START_ADDR, m)
#define HWIO_UFS_UFS_PHY_PHY_START_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_PHY_START_ADDR,v)
#define HWIO_UFS_UFS_PHY_PHY_START_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_PHY_START_ADDR,m,v,HWIO_UFS_UFS_PHY_PHY_START_IN)
#define HWIO_UFS_UFS_PHY_PHY_START_SERDES_START_BMSK                                                                            0x1
#define HWIO_UFS_UFS_PHY_PHY_START_SERDES_START_SHFT                                                                            0x0

#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000004)
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_RMSK                                                                                0x1
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_ADDR, HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_RMSK)
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_ADDR, m)
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_ADDR,v)
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_ADDR,m,v,HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_IN)
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_PWRDN_B_BMSK                                                                        0x1
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_PWRDN_B_SHFT                                                                        0x0

#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000008)
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_PWM_G1_NDIV_BMSK                                                                   0xff
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_PWM_G1_NDIV_SHFT                                                                    0x0

#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000000c)
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_RMSK                                                                               0x7f
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_PWM_G2_NDIV_BMSK                                                                   0x7f
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_PWM_G2_NDIV_SHFT                                                                    0x0

#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000010)
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_RMSK                                                                               0x3f
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_PWM_G3_NDIV_BMSK                                                                   0x3f
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_PWM_G3_NDIV_SHFT                                                                    0x0

#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000014)
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_RMSK                                                                               0x1f
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_PWM_G4_NDIV_BMSK                                                                   0x1f
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_PWM_G4_NDIV_SHFT                                                                    0x0

#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000018)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_RMSK                                                                      0xf
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_ADDR, HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_RMSK)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_ADDR, m)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_ADDR,v)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_ADDR,m,v,HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_IN)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_TIMER_100US_SYSCLK_STEPS_MSB_BMSK                                         0xf
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_TIMER_100US_SYSCLK_STEPS_MSB_SHFT                                         0x0

#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000001c)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_RMSK                                                                     0xff
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_ADDR, HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_RMSK)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_ADDR, m)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_ADDR,v)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_ADDR,m,v,HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_IN)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_TIMER_100US_SYSCLK_STEPS_LSB_BMSK                                        0xff
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_TIMER_100US_SYSCLK_STEPS_LSB_SHFT                                         0x0

#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000020)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_RMSK                                                                     0x3f
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_ADDR, HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_RMSK)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_ADDR, m)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_ADDR,v)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_ADDR,m,v,HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_IN)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_TIMER_20US_CORECLK_STEPS_MSB_BMSK                                        0x3f
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_TIMER_20US_CORECLK_STEPS_MSB_SHFT                                         0x0

#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000024)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_RMSK                                                                     0xff
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_ADDR, HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_RMSK)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_ADDR, m)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_ADDR,v)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_ADDR,m,v,HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_IN)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_TIMER_20US_CORECLK_STEPS_LSB_BMSK                                        0xff
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_TIMER_20US_CORECLK_STEPS_LSB_SHFT                                         0x0

#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000028)
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_RMSK                                                                                  0x7f
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_LINE_RESET_TIME_ADDR, HWIO_UFS_UFS_PHY_LINE_RESET_TIME_RMSK)
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_LINE_RESET_TIME_ADDR, m)
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_LINE_RESET_TIME_ADDR,v)
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_LINE_RESET_TIME_ADDR,m,v,HWIO_UFS_UFS_PHY_LINE_RESET_TIME_IN)
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_LINE_RESET_TIME_BMSK                                                                  0x7f
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_LINE_RESET_TIME_SHFT                                                                   0x0

#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000002c)
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_RMSK                                                                            0x1
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_ADDR, HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_RMSK)
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_ADDR,m,v,HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_IN)
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_LINE_RESET_GRANULARITY_BMSK                                                     0x1
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_LINE_RESET_GRANULARITY_SHFT                                                     0x0

#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000030)
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_RMSK                                                                        0x1
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_ADDR, HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_RMSK)
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_ADDR, m)
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_ADDR,v)
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_ADDR,m,v,HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_IN)
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_CONTROLSYM_ONE_HOT_DISABLE_BMSK                                             0x1
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_CONTROLSYM_ONE_HOT_DISABLE_SHFT                                             0x0

#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000034)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_RMSK                                                                       0xff
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_CORECLK_PWM_G1_NDIV_BMSK                                                   0xff
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_CORECLK_PWM_G1_NDIV_SHFT                                                    0x0

#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000038)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_RMSK                                                                       0x7f
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_CORECLK_PWM_G2_NDIV_BMSK                                                   0x7f
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_CORECLK_PWM_G2_NDIV_SHFT                                                    0x0

#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000003c)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_RMSK                                                                       0x3f
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_CORECLK_PWM_G3_NDIV_BMSK                                                   0x3f
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_CORECLK_PWM_G3_NDIV_SHFT                                                    0x0

#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000040)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_RMSK                                                                       0x1f
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_ADDR, HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_RMSK)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_ADDR, m)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_ADDR,v)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_ADDR,m,v,HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_IN)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_CORECLK_PWM_G4_NDIV_BMSK                                                   0x1f
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_CORECLK_PWM_G4_NDIV_SHFT                                                    0x0

#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_ADDR                                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000044)
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_RMSK                                                                                    0x3
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_ADDR, HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_RMSK)
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_IN)
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_TX_L1_EN_BMSK                                                                           0x2
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_TX_L1_EN_SHFT                                                                           0x1
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_TX_L0_EN_BMSK                                                                           0x1
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_TX_L0_EN_SHFT                                                                           0x0

#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_ADDR                                                                           (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000048)
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_RMSK                                                                                  0x3
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_ADDR, HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_RMSK)
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_ADDR, m)
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_ADDR,v)
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_ADDR,m,v,HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_IN)
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_RSYNC_EN_BMSK                                                                         0x2
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_RSYNC_EN_SHFT                                                                         0x1
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_TSYNC_EN_BMSK                                                                         0x1
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_TSYNC_EN_SHFT                                                                         0x0

#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_ADDR                                                                           (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000004c)
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_RMSK                                                                                  0x1
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_ADDR, HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_RMSK)
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_ADDR, m)
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_ADDR,v)
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_ADDR,m,v,HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_IN)
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_RETIME_BUFFER_EN_BMSK                                                                 0x1
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_RETIME_BUFFER_EN_SHFT                                                                 0x0

#define HWIO_UFS_UFS_PHY_PLL_CNTL_ADDR                                                                                   (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000050)
#define HWIO_UFS_UFS_PHY_PLL_CNTL_RMSK                                                                                          0x1
#define HWIO_UFS_UFS_PHY_PLL_CNTL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_PLL_CNTL_ADDR, HWIO_UFS_UFS_PHY_PLL_CNTL_RMSK)
#define HWIO_UFS_UFS_PHY_PLL_CNTL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_PLL_CNTL_ADDR, m)
#define HWIO_UFS_UFS_PHY_PLL_CNTL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_PLL_CNTL_ADDR,v)
#define HWIO_UFS_UFS_PHY_PLL_CNTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_PLL_CNTL_ADDR,m,v,HWIO_UFS_UFS_PHY_PLL_CNTL_IN)
#define HWIO_UFS_UFS_PHY_PLL_CNTL_PLL_SHUTOFF_EN_BMSK                                                                           0x1
#define HWIO_UFS_UFS_PHY_PLL_CNTL_PLL_SHUTOFF_EN_SHFT                                                                           0x0

#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000054)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_RMSK                                                                             0x1f
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_ADDR, HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_RMSK)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_IN)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_TX_LARGE_DRV_LVL_BMSK                                                            0x1f
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_TX_LARGE_DRV_LVL_SHFT                                                             0x0

#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000058)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_RMSK                                                                        0x1f
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_ADDR, HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_RMSK)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_IN)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_TX_LARGE_EMP_POST1_LVL_BMSK                                                 0x1f
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_TX_LARGE_EMP_POST1_LVL_SHFT                                                  0x0

#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000005c)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_RMSK                                                                             0x1f
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_ADDR, HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_RMSK)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_IN)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_TX_SMALL_DRV_LVL_BMSK                                                            0x1f
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_TX_SMALL_DRV_LVL_SHFT                                                             0x0

#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000060)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_RMSK                                                                        0x1f
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_ADDR, HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_RMSK)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_IN)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_TX_SMALL_EMP_POST1_LVL_BMSK                                                 0x1f
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_TX_SMALL_EMP_POST1_LVL_SHFT                                                  0x0

#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000064)
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_ADDR, HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_RMSK)
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_ADDR, m)
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_ADDR,v)
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_ADDR,m,v,HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_IN)
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_CFGCHANGE_CNT_VAL_BMSK                                                             0xff
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_CFGCHANGE_CNT_VAL_SHFT                                                              0x0

#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_ADDR                                                                           (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000068)
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_RMSK                                                                                 0xff
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_ADDR, HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_RMSK)
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_ADDR, m)
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_ADDR,v)
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_ADDR,m,v,HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_IN)
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_OMC_STATUS_RDVAL_BMSK                                                                0xff
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_OMC_STATUS_RDVAL_SHFT                                                                 0x0

#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_ADDR                                                                          (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000006c)
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_RMSK                                                                                0x3f
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_ADDR, HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_RMSK)
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_IN)
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_RX_SYNC_WAIT_TIME_BMSK                                                              0x3f
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_RX_SYNC_WAIT_TIME_SHFT                                                               0x0

#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_ADDR                                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000070)
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_RMSK                                                                                     0x7f
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CTRL_ADDR, HWIO_UFS_UFS_PHY_L0_BIST_CTRL_RMSK)
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CTRL_ADDR, m)
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_L0_BIST_CTRL_ADDR,v)
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_L0_BIST_CTRL_ADDR,m,v,HWIO_UFS_UFS_PHY_L0_BIST_CTRL_IN)
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_CHK_ERR_CNT_CLR_BMSK                                                             0x40
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_CHK_ERR_CNT_CLR_SHFT                                                              0x6
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_RX_ERR_EN_BMSK                                                                   0x20
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_RX_ERR_EN_SHFT                                                                    0x5
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_GEN_SHORT_PATTERN_BMSK                                                           0x10
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_GEN_SHORT_PATTERN_SHFT                                                            0x4
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_PAT_SEL_BMSK                                                                      0x8
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_PAT_SEL_SHFT                                                                      0x3
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_TXRX_EN_BMSK                                                                      0x4
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_TXRX_EN_SHFT                                                                      0x2
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_TX_EN_BMSK                                                                        0x2
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_TX_EN_SHFT                                                                        0x1
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_MODE_BMSK                                                                         0x1
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_L0_BIST_MODE_SHFT                                                                         0x0

#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_ADDR                                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000074)
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_RMSK                                                                                     0x7f
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CTRL_ADDR, HWIO_UFS_UFS_PHY_L1_BIST_CTRL_RMSK)
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CTRL_ADDR, m)
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_L1_BIST_CTRL_ADDR,v)
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_L1_BIST_CTRL_ADDR,m,v,HWIO_UFS_UFS_PHY_L1_BIST_CTRL_IN)
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_CHK_ERR_CNT_CLR_BMSK                                                             0x40
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_CHK_ERR_CNT_CLR_SHFT                                                              0x6
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_RX_ERR_EN_BMSK                                                                   0x20
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_RX_ERR_EN_SHFT                                                                    0x5
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_GEN_SHORT_PATTERN_BMSK                                                           0x10
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_GEN_SHORT_PATTERN_SHFT                                                            0x4
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_PAT_SEL_BMSK                                                                      0x8
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_PAT_SEL_SHFT                                                                      0x3
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_TXRX_EN_BMSK                                                                      0x4
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_TXRX_EN_SHFT                                                                      0x2
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_TX_EN_BMSK                                                                        0x2
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_TX_EN_SHFT                                                                        0x1
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_MODE_BMSK                                                                         0x1
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_L1_BIST_MODE_SHFT                                                                         0x0

#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000078)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_RMSK                                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_ADDR, HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_IN)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_PRBS_POLY0_BMSK                                                                       0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_PRBS_POLY0_SHFT                                                                        0x0

#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000007c)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_RMSK                                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_ADDR, HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_IN)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_PRBS_POLY1_BMSK                                                                       0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_PRBS_POLY1_SHFT                                                                        0x0

#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000080)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_RMSK                                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_ADDR, HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_IN)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_PRBS_SEED0_BMSK                                                                       0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_PRBS_SEED0_SHFT                                                                        0x0

#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000084)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_RMSK                                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_ADDR, HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_IN)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_PRBS_SEED1_BMSK                                                                       0xff
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_PRBS_SEED1_SHFT                                                                        0x0

#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_ADDR                                                                        (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000088)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_RMSK                                                                               0xf
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_ADDR, HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_IN)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT0_K_BMSK                                                                  0x8
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT0_K_SHFT                                                                  0x3
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT1_K_BMSK                                                                  0x4
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT1_K_SHFT                                                                  0x2
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT2_K_BMSK                                                                  0x2
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT2_K_SHFT                                                                  0x1
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT3_K_BMSK                                                                  0x1
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_FIXED_PAT3_K_SHFT                                                                  0x0

#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000008c)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_RMSK                                                                             0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_ADDR, HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_IN)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_FIXED_PAT0_BMSK                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_FIXED_PAT0_SHFT                                                                   0x0

#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000090)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_RMSK                                                                             0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_ADDR, HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_IN)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_FIXED_PAT1_BMSK                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_FIXED_PAT1_SHFT                                                                   0x0

#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000094)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_RMSK                                                                             0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_ADDR, HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_IN)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_FIXED_PAT2_BMSK                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_FIXED_PAT2_SHFT                                                                   0x0

#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000098)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_RMSK                                                                             0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_ADDR, HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_RMSK)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_ADDR, m)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_ADDR,v)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_ADDR,m,v,HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_IN)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_FIXED_PAT3_BMSK                                                                  0xff
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_FIXED_PAT3_SHFT                                                                   0x0

#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000009c)
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_RMSK                                                                              0x3
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_TX_HSGEAR_CAPABILITY_BMSK                                                         0x3
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_TX_HSGEAR_CAPABILITY_SHFT                                                         0x0

#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_ADDR                                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000a0)
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_RMSK                                                                             0x7
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_TX_PWMGEAR_CAPABILITY_BMSK                                                       0x7
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_TX_PWMGEAR_CAPABILITY_SHFT                                                       0x0

#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_ADDR                                                                    (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000a4)
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_RMSK                                                                           0x3
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_TX_AMPLITUDE_CAPABILITY_BMSK                                                   0x3
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_TX_AMPLITUDE_CAPABILITY_SHFT                                                   0x0

#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000a8)
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_RMSK                                                                        0x1
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_TX_EXTERNALSYNC_CAPABILITY_BMSK                                             0x1
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_TX_EXTERNALSYNC_CAPABILITY_SHFT                                             0x0

#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_ADDR                                                   (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000ac)
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_RMSK                                                          0x1
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_BMSK                 0x1
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_SHFT                 0x0

#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_ADDR                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000b0)
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_RMSK                                                            0x1
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_BMSK                     0x1
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_SHFT                     0x0

#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000b4)
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_RMSK                                                             0xf
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_BMSK                       0xf
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_SHFT                       0x0

#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000b8)
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_RMSK                                                            0xff
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_BMSK                      0xff
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_SHFT                       0x0

#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000bc)
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_RMSK                                                               0xff
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_BMSK                            0xff
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_SHFT                             0x0

#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_ADDR                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000c0)
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_RMSK                                                                    0x1
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_TX_REF_CLOCK_SHARED_CAPABILITY_BMSK                                     0x1
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_TX_REF_CLOCK_SHARED_CAPABILITY_SHFT                                     0x0

#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000c4)
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RMSK                                                             0xff
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_TX_PHY_MAJOR_RELEASE_CAPABILITY_BMSK                             0xf0
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_TX_PHY_MAJOR_RELEASE_CAPABILITY_SHFT                              0x4
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_TX_PHY_MINOR_RELEASE_CAPABILITY_BMSK                              0xf
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_TX_PHY_MINOR_RELEASE_CAPABILITY_SHFT                              0x0

#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR                                                        (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000c8)
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_RMSK                                                              0xff
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_BMSK                          0xff
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_SHFT                           0x0

#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000cc)
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_RMSK                                                                        0xff
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_TX_HIBERN8TIME_CAPABILITY_BMSK                                              0xff
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_TX_HIBERN8TIME_CAPABILITY_SHFT                                               0x0

#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000d0)
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_RMSK                                                                              0x3
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_RX_HSGEAR_CAPABILITY_BMSK                                                         0x3
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_RX_HSGEAR_CAPABILITY_SHFT                                                         0x0

#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_ADDR                                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000d4)
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_RMSK                                                                             0x7
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_RX_PWMGEAR_CAPABILITY_BMSK                                                       0x7
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_RX_PWMGEAR_CAPABILITY_SHFT                                                       0x0

#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_ADDR                                                              (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000d8)
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_RMSK                                                                     0x1
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_RX_HS_UNTERMINATED_CAPABILITY_BMSK                                       0x1
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_RX_HS_UNTERMINATED_CAPABILITY_SHFT                                       0x0

#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_ADDR                                                                (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000dc)
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_RMSK                                                                       0x1
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_RX_LS_TERMINATED_CAPABILITY_BMSK                                           0x1
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_RX_LS_TERMINATED_CAPABILITY_SHFT                                           0x0

#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000e0)
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_RMSK                                                             0xf
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_BMSK                       0xf
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_SHFT                       0x0

#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000e4)
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_RMSK                                                            0xff
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_BMSK                      0xff
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_SHFT                       0x0

#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000e8)
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_RMSK                                                               0xff
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_BMSK                            0xff
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_SHFT                             0x0

#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_ADDR                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000ec)
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_RMSK                                                                    0x1
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_RX_REF_CLOCK_SHARED_CAPABILITY_BMSK                                     0x1
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_RX_REF_CLOCK_SHARED_CAPABILITY_SHFT                                     0x0

#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000f0)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_RMSK                                                                  0xff
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_RX_HS_G1_SYNC_RANGE_CAPABILITY_BMSK                                   0xc0
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_RX_HS_G1_SYNC_RANGE_CAPABILITY_SHFT                                    0x6
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_BMSK                                  0x3f
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_SHFT                                   0x0

#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000f4)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_RMSK                                                                0xf
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_BMSK                             0xf
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_SHFT                             0x0

#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000f8)
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_RMSK                                                                   0xf
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_RX_LS_PREPARE_LENGTH_CAPABILITY_BMSK                                   0xf
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_RX_LS_PREPARE_LENGTH_CAPABILITY_SHFT                                   0x0

#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_ADDR                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000fc)
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_RMSK                                                           0x1f
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_BMSK                    0x1f
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_SHFT                     0x0

#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_ADDR                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000100)
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_RMSK                                                                    0xf
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_RX_MIN_ACTIVATETIME_CAPABILITY_BMSK                                     0xf
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_RX_MIN_ACTIVATETIME_CAPABILITY_SHFT                                     0x0

#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000104)
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RMSK                                                             0xff
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RX_PHY_MAJOR_RELEASE_CAPABILITY_BMSK                             0xf0
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RX_PHY_MAJOR_RELEASE_CAPABILITY_SHFT                              0x4
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RX_PHY_MINOR_RELEASE_CAPABILITY_BMSK                              0xf
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_RX_PHY_MINOR_RELEASE_CAPABILITY_SHFT                              0x0

#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR                                                        (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000108)
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_RMSK                                                              0xff
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_BMSK                          0xff
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_SHFT                           0x0

#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000010c)
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_RMSK                                                                        0xff
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_RX_HIBERN8TIME_CAPABILITY_BMSK                                              0xff
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_RX_HIBERN8TIME_CAPABILITY_SHFT                                               0x0

#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000110)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_RMSK                                                                  0xff
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_RX_HS_G2_SYNC_RANGE_CAPABILITY_BMSK                                   0xc0
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_RX_HS_G2_SYNC_RANGE_CAPABILITY_SHFT                                    0x6
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_BMSK                                  0x3f
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_SHFT                                   0x0

#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000114)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_RMSK                                                                  0xff
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_RX_HS_G3_SYNC_RANGE_CAPABILITY_BMSK                                   0xc0
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_RX_HS_G3_SYNC_RANGE_CAPABILITY_SHFT                                    0x6
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_BMSK                                  0x3f
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_SHFT                                   0x0

#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000118)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_RMSK                                                                0xf
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_BMSK                             0xf
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_SHFT                             0x0

#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000011c)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_RMSK                                                                0xf
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_ADDR, HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_RMSK)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_ADDR, m)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_ADDR,v)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_ADDR,m,v,HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_IN)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_BMSK                             0xf
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_SHFT                             0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_ADDR                                                                              (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000120)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_RMSK                                                                                     0xf
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_ADDR,v)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_ADDR,m,v,HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_IN)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_DEBUG_BUS_SEL_BMSK                                                                       0xf
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_DEBUG_BUS_SEL_SHFT                                                                       0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000124)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_RMSK                                                                           0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_ADDR,v)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_ADDR,m,v,HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_IN)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_DEBUG_BUS_0_STATUS_CHK_BMSK                                                    0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_DEBUG_BUS_0_STATUS_CHK_SHFT                                                     0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000128)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_RMSK                                                                           0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_ADDR,v)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_ADDR,m,v,HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_IN)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_DEBUG_BUS_1_STATUS_CHK_BMSK                                                    0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_DEBUG_BUS_1_STATUS_CHK_SHFT                                                     0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000012c)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_RMSK                                                                           0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_ADDR,v)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_ADDR,m,v,HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_IN)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_DEBUG_BUS_2_STATUS_CHK_BMSK                                                    0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_DEBUG_BUS_2_STATUS_CHK_SHFT                                                     0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000130)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_RMSK                                                                           0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_OUT(v)      \
        out_dword(HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_ADDR,v)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_ADDR,m,v,HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_IN)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_DEBUG_BUS_3_STATUS_CHK_BMSK                                                    0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_DEBUG_BUS_3_STATUS_CHK_SHFT                                                     0x0

#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000134)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_RMSK                                                                     0xff
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_ADDR, HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_BIST_CHK_ERR_CNT_L_BMSK                                                  0xff
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_BIST_CHK_ERR_CNT_L_SHFT                                                   0x0

#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000138)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_RMSK                                                                     0xff
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_ADDR, HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_BIST_CHK_ERR_CNT_H_BMSK                                                  0xff
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_BIST_CHK_ERR_CNT_H_SHFT                                                   0x0

#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000013c)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_RMSK                                                                     0xff
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_ADDR, HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_BIST_CHK_ERR_CNT_L_BMSK                                                  0xff
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_BIST_CHK_ERR_CNT_L_SHFT                                                   0x0

#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000140)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_RMSK                                                                     0xff
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_ADDR, HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_BIST_CHK_ERR_CNT_H_BMSK                                                  0xff
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_BIST_CHK_ERR_CNT_H_SHFT                                                   0x0

#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000144)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_ADDR, HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_RSVD_STATUS_BMSK                                                                   0xf0
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_RSVD_STATUS_SHFT                                                                    0x4
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_CHK_HEADER_SEL_BMSK                                                            0x8
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_CHK_HEADER_SEL_SHFT                                                            0x3
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_HEADER_NOT_FOUND_BMSK                                                          0x4
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_HEADER_NOT_FOUND_SHFT                                                          0x2
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_PAT_DATA_NOT_FOUND_BMSK                                                        0x2
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_PAT_DATA_NOT_FOUND_SHFT                                                        0x1
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_CHECK_DONE_BMSK                                                                0x1
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_BIST_CHECK_DONE_SHFT                                                                0x0

#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000148)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_ADDR, HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_RSVD_STATUS_BMSK                                                                   0xf0
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_RSVD_STATUS_SHFT                                                                    0x4
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_CHK_HEADER_SEL_BMSK                                                            0x8
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_CHK_HEADER_SEL_SHFT                                                            0x3
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_HEADER_NOT_FOUND_BMSK                                                          0x4
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_HEADER_NOT_FOUND_SHFT                                                          0x2
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_PAT_DATA_NOT_FOUND_BMSK                                                        0x2
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_PAT_DATA_NOT_FOUND_SHFT                                                        0x1
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_CHECK_DONE_BMSK                                                                0x1
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_BIST_CHECK_DONE_SHFT                                                                0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000014c)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_DEBUG_BUS_0_STATUS_BMSK                                                            0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_DEBUG_BUS_0_STATUS_SHFT                                                             0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000150)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_DEBUG_BUS_1_STATUS_BMSK                                                            0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_DEBUG_BUS_1_STATUS_SHFT                                                             0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000154)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_DEBUG_BUS_2_STATUS_BMSK                                                            0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_DEBUG_BUS_2_STATUS_SHFT                                                             0x0

#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000158)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_RMSK                                                                               0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_IN          \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_ADDR, HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_RMSK)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_ADDR, m)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_DEBUG_BUS_3_STATUS_BMSK                                                            0xff
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_DEBUG_BUS_3_STATUS_SHFT                                                             0x0

/*----------------------------------------------------------------------------
 * MODULE: UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON
 *--------------------------------------------------------------------------*/

#define UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE                             (UFS_UFS_REGS_BASE      + 0x00007000)

#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_RMSK                                            0x7f
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_ADDR, HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_RMSK)
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_ADDR,m,v,HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_IN)
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_RBLDO_EN_MUX_BMSK                        0x40
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_RBLDO_EN_MUX_SHFT                         0x6
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_RBLDO_EN_BMSK                            0x20
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_RBLDO_EN_SHFT                             0x5
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_CM_BMSK                                  0x10
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_CM_SHFT                                   0x4
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_AC_COUPLE_BMSK                            0x8
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_AC_COUPLE_SHFT                            0x3
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_GNDTERM_BMSK                              0x4
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_GNDTERM_SHFT                              0x2
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_TERM_SEL_BMSK                             0x2
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_TERM_SEL_SHFT                             0x1
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_BUF_EN_BMSK                               0x1
#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_SYSCLK_BUF_EN_SHFT                               0x0

#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_RMSK                                          0xff
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_ADDR, HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_IN)
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_VCO_TAIL_MUX_BMSK                         0x80
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_VCO_TAIL_MUX_SHFT                          0x7
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_VCO_TAIL_BMSK                             0x7c
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_VCO_TAIL_SHFT                              0x2
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_EN_MUX_BMSK                                0x2
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_EN_MUX_SHFT                                0x1
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_EN_BMSK                                    0x1
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_PLL_EN_SHFT                                    0x0

#define HWIO_UFS_QSERDES_COM_CMN_MODE_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_COM_CMN_MODE_RMSK                                                 0xf
#define HWIO_UFS_QSERDES_COM_CMN_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_CMN_MODE_ADDR, HWIO_UFS_QSERDES_COM_CMN_MODE_RMSK)
#define HWIO_UFS_QSERDES_COM_CMN_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_CMN_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_COM_CMN_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_CMN_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_COM_CMN_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_CMN_MODE_ADDR,m,v,HWIO_UFS_QSERDES_COM_CMN_MODE_IN)
#define HWIO_UFS_QSERDES_COM_CMN_MODE_CMN_MODE_BMSK                                        0xf
#define HWIO_UFS_QSERDES_COM_CMN_MODE_CMN_MODE_SHFT                                        0x0

#define HWIO_UFS_QSERDES_COM_IE_TRIM_ADDR                                           (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_COM_IE_TRIM_RMSK                                                 0xff
#define HWIO_UFS_QSERDES_COM_IE_TRIM_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_IE_TRIM_ADDR, HWIO_UFS_QSERDES_COM_IE_TRIM_RMSK)
#define HWIO_UFS_QSERDES_COM_IE_TRIM_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_IE_TRIM_ADDR, m)
#define HWIO_UFS_QSERDES_COM_IE_TRIM_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_IE_TRIM_ADDR,v)
#define HWIO_UFS_QSERDES_COM_IE_TRIM_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_IE_TRIM_ADDR,m,v,HWIO_UFS_QSERDES_COM_IE_TRIM_IN)
#define HWIO_UFS_QSERDES_COM_IE_TRIM_IETRIM_BMSK                                          0xff
#define HWIO_UFS_QSERDES_COM_IE_TRIM_IETRIM_SHFT                                           0x0

#define HWIO_UFS_QSERDES_COM_IP_TRIM_ADDR                                           (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_COM_IP_TRIM_RMSK                                                 0xff
#define HWIO_UFS_QSERDES_COM_IP_TRIM_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_IP_TRIM_ADDR, HWIO_UFS_QSERDES_COM_IP_TRIM_RMSK)
#define HWIO_UFS_QSERDES_COM_IP_TRIM_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_IP_TRIM_ADDR, m)
#define HWIO_UFS_QSERDES_COM_IP_TRIM_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_IP_TRIM_ADDR,v)
#define HWIO_UFS_QSERDES_COM_IP_TRIM_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_IP_TRIM_ADDR,m,v,HWIO_UFS_QSERDES_COM_IP_TRIM_IN)
#define HWIO_UFS_QSERDES_COM_IP_TRIM_IPTRIM_BMSK                                          0xff
#define HWIO_UFS_QSERDES_COM_IP_TRIM_IPTRIM_SHFT                                           0x0

#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_ADDR                                         (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_RMSK                                               0x7f
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CNTRL_ADDR, HWIO_UFS_QSERDES_COM_PLL_CNTRL_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CNTRL_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_CNTRL_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_CNTRL_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_CNTRL_IN)
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_IBOOST_BMSK                                    0x40
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_IBOOST_SHFT                                     0x6
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_OCP_EN_BMSK                                        0x20
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_OCP_EN_SHFT                                         0x5
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_SYSCLKD2_BMSK                                  0x10
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_SYSCLKD2_SHFT                                   0x4
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_CPLIN_BMSK                                      0x8
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_CPLIN_SHFT                                      0x3
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_DIV_FFEN_BMSK                                   0x4
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_DIV_FFEN_SHFT                                   0x2
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_DIV_ORD_BMSK                                    0x2
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_PLL_DIV_ORD_SHFT                                    0x1
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_VCO_SEL_BMSK                                        0x1
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_VCO_SEL_SHFT                                        0x0

#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_RMSK                                             0x3f
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_IP_SETI_ADDR, HWIO_UFS_QSERDES_COM_PLL_IP_SETI_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_IP_SETI_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_IP_SETI_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_IP_SETI_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_IP_SETI_IN)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_PLL_IPSETI_BMSK                                  0x3f
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_PLL_IPSETI_SHFT                                   0x0

#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_ADDR                              (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_RMSK                                     0x1
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_ADDR, HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_RMSK)
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_ADDR, m)
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_ADDR,v)
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_ADDR,m,v,HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_IN)
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_CORECLK_IN_SYNC_SEL_BMSK                 0x1
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_CORECLK_IN_SYNC_SEL_SHFT                 0x0

#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR                               (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_RMSK                                     0x3f
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR, HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_RMSK)
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR, m)
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR,v)
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR,m,v,HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_IN)
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_L_EN_MUX_BMSK                     0x20
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_L_EN_MUX_SHFT                      0x5
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_L_EN_BMSK                         0x10
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_L_EN_SHFT                          0x4
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_R_EN_MUX_BMSK                      0x8
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_R_EN_MUX_SHFT                      0x3
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_R_EN_BMSK                          0x4
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_CLKBUF_R_EN_SHFT                          0x2
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_BIAS_EN_MUX_BMSK                          0x2
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_BIAS_EN_MUX_SHFT                          0x1
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_BIAS_EN_BMSK                              0x1
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_BIAS_EN_SHFT                              0x0

#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_RMSK                                             0xff
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CP_SETI_ADDR, HWIO_UFS_QSERDES_COM_PLL_CP_SETI_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CP_SETI_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_CP_SETI_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_CP_SETI_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_CP_SETI_IN)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_PLL_CPSETI_BMSK                                  0xff
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_PLL_CPSETI_SHFT                                   0x0

#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_RMSK                                             0x3f
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_IP_SETP_ADDR, HWIO_UFS_QSERDES_COM_PLL_IP_SETP_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_IP_SETP_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_IP_SETP_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_IP_SETP_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_IP_SETP_IN)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_PLL_IPSETP_BMSK                                  0x3f
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_PLL_IPSETP_SHFT                                   0x0

#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_RMSK                                             0x1f
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CP_SETP_ADDR, HWIO_UFS_QSERDES_COM_PLL_CP_SETP_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CP_SETP_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_CP_SETP_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_CP_SETP_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_CP_SETP_IN)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_PLL_CPSETP_BMSK                                  0x1f
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_PLL_CPSETP_SHFT                                   0x0

#define HWIO_UFS_QSERDES_COM_ATB_SEL1_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_RMSK                                                0xff
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_ATB_SEL1_ADDR, HWIO_UFS_QSERDES_COM_ATB_SEL1_RMSK)
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_ATB_SEL1_ADDR, m)
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_ATB_SEL1_ADDR,v)
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_ATB_SEL1_ADDR,m,v,HWIO_UFS_QSERDES_COM_ATB_SEL1_IN)
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_ATB_SEL1_BMSK                                       0xff
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_ATB_SEL1_SHFT                                        0x0

#define HWIO_UFS_QSERDES_COM_ATB_SEL2_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_RMSK                                                0xff
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_ATB_SEL2_ADDR, HWIO_UFS_QSERDES_COM_ATB_SEL2_RMSK)
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_ATB_SEL2_ADDR, m)
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_ATB_SEL2_ADDR,v)
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_ATB_SEL2_ADDR,m,v,HWIO_UFS_QSERDES_COM_ATB_SEL2_IN)
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_DEBUGBUS_SEL_BMSK                                   0xf0
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_DEBUGBUS_SEL_SHFT                                    0x4
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_ATB_SEL2_BMSK                                        0xf
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_ATB_SEL2_SHFT                                        0x0

#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_ADDR                                     (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_RMSK                                            0xf
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_ADDR, HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_RMSK)
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_ADDR,m,v,HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_IN)
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_SYSCLK_SEL_BMSK                                 0xc
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_SYSCLK_SEL_SHFT                                 0x2
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_SYSCLK_EN_MUX_BMSK                              0x2
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_SYSCLK_EN_MUX_SHFT                              0x1
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_SYSCLK_EN_BMSK                                  0x1
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_SYSCLK_EN_SHFT                                  0x0

#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_RMSK                                         0xff
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_ADDR, HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_RMSK)
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_ADDR, m)
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_ADDR,v)
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_ADDR,m,v,HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_IN)
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_TX_BAND_MUX_BMSK                             0x80
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_TX_BAND_MUX_SHFT                              0x7
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_TX_BAND_BMSK                                 0x60
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_TX_BAND_SHFT                                  0x5
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_RESCODE_MUX_BMSK                             0x10
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_RESCODE_MUX_SHFT                              0x4
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_RESCODE_BMSK                                  0xf
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_RESCODE_SHFT                                  0x0

#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_ADDR                                     (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_RMSK                                           0x7f
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_ADDR, HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_RMSK)
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_ADDR, m)
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_ADDR,v)
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_ADDR,m,v,HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_IN)
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_DISABLE_CLKGATE_BMSK                           0x40
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_DISABLE_CLKGATE_SHFT                            0x6
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_PLL_UNLOCK_DET_BMSK                            0x20
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_PLL_UNLOCK_DET_SHFT                             0x5
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_FRQ_TUNE_MODE_BMSK                             0x10
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_FRQ_TUNE_MODE_SHFT                              0x4
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_BYPASS_VCOCAL_BMSK                              0x8
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_BYPASS_VCOCAL_SHFT                              0x3
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_BYPASS_RESTRIM_BMSK                             0x4
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_BYPASS_RESTRIM_SHFT                             0x2
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_BYPASS_PLLLOCK_BMSK                             0x2
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_BYPASS_PLLLOCK_SHFT                             0x1
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_FORCE_PLLLOCK_BMSK                              0x1
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_FORCE_PLLLOCK_SHFT                              0x0

#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_RMSK                                            0xff
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_ADDR, HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_RMSK)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_IN)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_PLLLOCK_CMP1_BMSK                               0xff
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_PLLLOCK_CMP1_SHFT                                0x0

#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_RMSK                                            0xff
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_ADDR, HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_RMSK)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_IN)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_PLLLOCK_CMP2_BMSK                               0xff
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_PLLLOCK_CMP2_SHFT                                0x0

#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_RMSK                                            0xff
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_ADDR, HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_RMSK)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_IN)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_PLLLOCK_CMP3_BMSK                               0xff
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_PLLLOCK_CMP3_SHFT                                0x0

#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_RMSK                                          0x1f
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_ADDR, HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_RMSK)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_IN)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_PLLLOCK_RNG_BMSK                              0x18
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_PLLLOCK_RNG_SHFT                               0x3
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_PLLLOCK_CNT_BMSK                               0x6
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_PLLLOCK_CNT_SHFT                               0x1
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_PLLLOCK_CMP_EN_BMSK                            0x1
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_PLLLOCK_CMP_EN_SHFT                            0x0

#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_RMSK                                          0xf
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_ADDR, HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_RMSK)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_ADDR, m)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_ADDR,v)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_ADDR,m,v,HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_IN)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_RESTRIM_OFFSET_BMSK                           0xf
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_RESTRIM_OFFSET_SHFT                           0x0

#define HWIO_UFS_QSERDES_COM_BGTC_ADDR                                              (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_COM_BGTC_RMSK                                                    0xff
#define HWIO_UFS_QSERDES_COM_BGTC_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_BGTC_ADDR, HWIO_UFS_QSERDES_COM_BGTC_RMSK)
#define HWIO_UFS_QSERDES_COM_BGTC_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_BGTC_ADDR, m)
#define HWIO_UFS_QSERDES_COM_BGTC_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_BGTC_ADDR,v)
#define HWIO_UFS_QSERDES_COM_BGTC_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_BGTC_ADDR,m,v,HWIO_UFS_QSERDES_COM_BGTC_IN)
#define HWIO_UFS_QSERDES_COM_BGTC_BGTC_BMSK                                               0xff
#define HWIO_UFS_QSERDES_COM_BGTC_BGTC_SHFT                                                0x0

#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_ADDR                         (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_RMSK                                0x7
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_ADDR, HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_IN)
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_RESTRIM_STEP_BMSK                   0x4
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_RESTRIM_STEP_SHFT                   0x2
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_PLL_TESTDN_BMSK                     0x2
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_PLL_TESTDN_SHFT                     0x1
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_PLL_TESTUP_BMSK                     0x1
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_PLL_TESTUP_SHFT                     0x0

#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_RMSK                                            0xff
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_ADDR, HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_IN)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_PLL_VCO_TUNE_MUX_BMSK                           0x80
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_PLL_VCO_TUNE_MUX_SHFT                            0x7
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_PLL_VCO_TUNE_BMSK                               0x7f
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_PLL_VCO_TUNE_SHFT                                0x0

#define HWIO_UFS_QSERDES_COM_DEC_START1_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_COM_DEC_START1_RMSK                                              0xff
#define HWIO_UFS_QSERDES_COM_DEC_START1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DEC_START1_ADDR, HWIO_UFS_QSERDES_COM_DEC_START1_RMSK)
#define HWIO_UFS_QSERDES_COM_DEC_START1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DEC_START1_ADDR, m)
#define HWIO_UFS_QSERDES_COM_DEC_START1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_DEC_START1_ADDR,v)
#define HWIO_UFS_QSERDES_COM_DEC_START1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_DEC_START1_ADDR,m,v,HWIO_UFS_QSERDES_COM_DEC_START1_IN)
#define HWIO_UFS_QSERDES_COM_DEC_START1_DEC_START1_MUX_BMSK                               0x80
#define HWIO_UFS_QSERDES_COM_DEC_START1_DEC_START1_MUX_SHFT                                0x7
#define HWIO_UFS_QSERDES_COM_DEC_START1_DEC_START1_BMSK                                   0x7f
#define HWIO_UFS_QSERDES_COM_DEC_START1_DEC_START1_SHFT                                    0x0

#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_RMSK                                              0x1f
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_AMP_OS_ADDR, HWIO_UFS_QSERDES_COM_PLL_AMP_OS_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_AMP_OS_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_AMP_OS_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_AMP_OS_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_AMP_OS_IN)
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_PLL_AMP_OS_BMSK                                   0x1f
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_PLL_AMP_OS_SHFT                                    0x0

#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_ADDR                                     (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_RMSK                                            0x3
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_ADDR, HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_RMSK)
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_ADDR,m,v,HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_IN)
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_SSCCENTER_BMSK                                  0x2
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_SSCCENTER_SHFT                                  0x1
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_SSCEN_BMSK                                      0x1
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_SSCEN_SHFT                                      0x0

#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_RMSK                                            0xff
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_ADDR, HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_RMSK)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_ADDR,m,v,HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_IN)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_SSC_ADJPER1_BMSK                                0xff
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_SSC_ADJPER1_SHFT                                 0x0

#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_RMSK                                             0x3
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_ADDR, HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_RMSK)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_ADDR,m,v,HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_IN)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_SSC_ADJPER2_BMSK                                 0x3
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_SSC_ADJPER2_SHFT                                 0x0

#define HWIO_UFS_QSERDES_COM_SSC_PER1_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_COM_SSC_PER1_RMSK                                                0xff
#define HWIO_UFS_QSERDES_COM_SSC_PER1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_PER1_ADDR, HWIO_UFS_QSERDES_COM_SSC_PER1_RMSK)
#define HWIO_UFS_QSERDES_COM_SSC_PER1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_PER1_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SSC_PER1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SSC_PER1_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SSC_PER1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SSC_PER1_ADDR,m,v,HWIO_UFS_QSERDES_COM_SSC_PER1_IN)
#define HWIO_UFS_QSERDES_COM_SSC_PER1_SSC_PER1_BMSK                                       0xff
#define HWIO_UFS_QSERDES_COM_SSC_PER1_SSC_PER1_SHFT                                        0x0

#define HWIO_UFS_QSERDES_COM_SSC_PER2_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_COM_SSC_PER2_RMSK                                                0xff
#define HWIO_UFS_QSERDES_COM_SSC_PER2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_PER2_ADDR, HWIO_UFS_QSERDES_COM_SSC_PER2_RMSK)
#define HWIO_UFS_QSERDES_COM_SSC_PER2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_PER2_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SSC_PER2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SSC_PER2_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SSC_PER2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SSC_PER2_ADDR,m,v,HWIO_UFS_QSERDES_COM_SSC_PER2_IN)
#define HWIO_UFS_QSERDES_COM_SSC_PER2_SSC_PER2_BMSK                                       0xff
#define HWIO_UFS_QSERDES_COM_SSC_PER2_SSC_PER2_SHFT                                        0x0

#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_RMSK                                          0xff
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_ADDR, HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_RMSK)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_ADDR,m,v,HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_IN)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_SSC_STEPSIZE1_BMSK                            0xff
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_SSC_STEPSIZE1_SHFT                             0x0

#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000084)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_RMSK                                          0xff
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_ADDR, HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_RMSK)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_ADDR, m)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_ADDR,v)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_ADDR,m,v,HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_IN)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_SSC_STEPSIZE2_BMSK                            0xff
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_SSC_STEPSIZE2_SHFT                             0x0

#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000088)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_RMSK                                          0x1
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_ADDR, HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_RMSK)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_ADDR, m)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_ADDR,v)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_ADDR,m,v,HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_IN)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_RESTRIM_SEARCH_BMSK                           0x1
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_RESTRIM_SEARCH_SHFT                           0x0

#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000008c)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_RMSK                                          0x1
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_ADDR, HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_RMSK)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_ADDR, m)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_ADDR,v)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_ADDR,m,v,HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_IN)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_RESTRIM_FREEZE_BMSK                           0x1
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_RESTRIM_FREEZE_SHFT                           0x0

#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_ADDR                            (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000090)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_RMSK                                   0xf
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_ADDR, HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_RMSK)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_ADDR, m)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_ADDR,v)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_ADDR,m,v,HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_IN)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_VCO_CAL_DONE_MUX_BMSK                  0x8
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_VCO_CAL_DONE_MUX_SHFT                  0x3
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_VCO_CAL_DONE_BMSK                      0x4
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_VCO_CAL_DONE_SHFT                      0x2
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_RESTRIM_EN_MUX_BMSK                    0x2
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_RESTRIM_EN_MUX_SHFT                    0x1
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_RESTRIM_EN_BMSK                        0x1
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_RESTRIM_EN_SHFT                        0x0

#define HWIO_UFS_QSERDES_COM_FAUX_EN_ADDR                                           (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000094)
#define HWIO_UFS_QSERDES_COM_FAUX_EN_RMSK                                                  0x3
#define HWIO_UFS_QSERDES_COM_FAUX_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_FAUX_EN_ADDR, HWIO_UFS_QSERDES_COM_FAUX_EN_RMSK)
#define HWIO_UFS_QSERDES_COM_FAUX_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_FAUX_EN_ADDR, m)
#define HWIO_UFS_QSERDES_COM_FAUX_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_FAUX_EN_ADDR,v)
#define HWIO_UFS_QSERDES_COM_FAUX_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_FAUX_EN_ADDR,m,v,HWIO_UFS_QSERDES_COM_FAUX_EN_IN)
#define HWIO_UFS_QSERDES_COM_FAUX_EN_FAUX_SEL_BMSK                                         0x2
#define HWIO_UFS_QSERDES_COM_FAUX_EN_FAUX_SEL_SHFT                                         0x1
#define HWIO_UFS_QSERDES_COM_FAUX_EN_FAUX_EN_BMSK                                          0x1
#define HWIO_UFS_QSERDES_COM_FAUX_EN_FAUX_EN_SHFT                                          0x0

#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000098)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_RMSK                                         0xff
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_ADDR, HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_RMSK)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_ADDR, m)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_ADDR,v)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_ADDR,m,v,HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_IN)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_DIV_FRAC_START1_MUX_BMSK                     0x80
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_DIV_FRAC_START1_MUX_SHFT                      0x7
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_DIV_FRAC_START1_BMSK                         0x7f
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_DIV_FRAC_START1_SHFT                          0x0

#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000009c)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_RMSK                                         0xff
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_ADDR, HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_RMSK)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_ADDR, m)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_ADDR,v)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_ADDR,m,v,HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_IN)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_DIV_FRAC_START2_MUX_BMSK                     0x80
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_DIV_FRAC_START2_MUX_SHFT                      0x7
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_DIV_FRAC_START2_BMSK                         0x7f
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_DIV_FRAC_START2_SHFT                          0x0

#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000a0)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_RMSK                                         0x1f
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_ADDR, HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_RMSK)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_ADDR, m)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_ADDR,v)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_ADDR,m,v,HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_IN)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_DIV_FRAC_START3_MUX_BMSK                     0x10
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_DIV_FRAC_START3_MUX_SHFT                      0x4
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_DIV_FRAC_START3_BMSK                          0xf
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_DIV_FRAC_START3_SHFT                          0x0

#define HWIO_UFS_QSERDES_COM_DEC_START2_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000a4)
#define HWIO_UFS_QSERDES_COM_DEC_START2_RMSK                                               0x3
#define HWIO_UFS_QSERDES_COM_DEC_START2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DEC_START2_ADDR, HWIO_UFS_QSERDES_COM_DEC_START2_RMSK)
#define HWIO_UFS_QSERDES_COM_DEC_START2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_DEC_START2_ADDR, m)
#define HWIO_UFS_QSERDES_COM_DEC_START2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_DEC_START2_ADDR,v)
#define HWIO_UFS_QSERDES_COM_DEC_START2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_DEC_START2_ADDR,m,v,HWIO_UFS_QSERDES_COM_DEC_START2_IN)
#define HWIO_UFS_QSERDES_COM_DEC_START2_DEC_START2_MUX_BMSK                                0x2
#define HWIO_UFS_QSERDES_COM_DEC_START2_DEC_START2_MUX_SHFT                                0x1
#define HWIO_UFS_QSERDES_COM_DEC_START2_DEC_START2_BMSK                                    0x1
#define HWIO_UFS_QSERDES_COM_DEC_START2_DEC_START2_SHFT                                    0x0

#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_ADDR                                  (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000a8)
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_RMSK                                        0x3f
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_ADDR, HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_IN)
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_CLK_EP_EN_FORCE_BMSK                        0x20
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_CLK_EP_EN_FORCE_SHFT                         0x5
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_CLK_EP_EN_BMSK                              0x10
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_CLK_EP_EN_SHFT                               0x4
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_TXCLK_EN_MUX_BMSK                        0x8
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_TXCLK_EN_MUX_SHFT                        0x3
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_TXCLK_EN_BMSK                            0x4
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_TXCLK_EN_SHFT                            0x2
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_RXCLK_EN_MUX_BMSK                        0x2
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_RXCLK_EN_MUX_SHFT                        0x1
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_RXCLK_EN_BMSK                            0x1
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_PLL_RXCLK_EN_SHFT                            0x0

#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000ac)
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_RMSK                                              0xff
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CRCTRL_ADDR, HWIO_UFS_QSERDES_COM_PLL_CRCTRL_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CRCTRL_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_CRCTRL_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_CRCTRL_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_CRCTRL_IN)
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_PLL_RCTRL_BMSK                                    0xf0
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_PLL_RCTRL_SHFT                                     0x4
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_PLL_CCTRL_BMSK                                     0xf
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_PLL_CCTRL_SHFT                                     0x0

#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000b0)
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_RMSK                                            0xff
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_ADDR, HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_IN)
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_PLL_CLK_EP_DIV_BMSK                             0xff
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_PLL_CLK_EP_DIV_SHFT                              0x0

#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000b4)
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_RMSK                                           0x1
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_ADDR, HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_ADDR,v)
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_ADDR,m,v,HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_IN)
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_FREQ_UPDATE_BMSK                               0x1
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_FREQ_UPDATE_SHFT                               0x0

#define HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000b8)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_RMSK                                             0x1
#define HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_ADDR, HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_RMSK)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_ADDR, m)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_PLL_VCOHIGH_BMSK                                 0x1
#define HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_PLL_VCOHIGH_SHFT                                 0x0

#define HWIO_UFS_QSERDES_COM_RESET_SM_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000bc)
#define HWIO_UFS_QSERDES_COM_RESET_SM_RMSK                                                0x7f
#define HWIO_UFS_QSERDES_COM_RESET_SM_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RESET_SM_ADDR, HWIO_UFS_QSERDES_COM_RESET_SM_RMSK)
#define HWIO_UFS_QSERDES_COM_RESET_SM_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_COM_RESET_SM_ADDR, m)
#define HWIO_UFS_QSERDES_COM_RESET_SM_RESTRIM_BMSK                                        0x40
#define HWIO_UFS_QSERDES_COM_RESET_SM_RESTRIM_SHFT                                         0x6
#define HWIO_UFS_QSERDES_COM_RESET_SM_READY_BMSK                                          0x20
#define HWIO_UFS_QSERDES_COM_RESET_SM_READY_SHFT                                           0x5
#define HWIO_UFS_QSERDES_COM_RESET_SM_PLLLOCK_BMSK                                        0x10
#define HWIO_UFS_QSERDES_COM_RESET_SM_PLLLOCK_SHFT                                         0x4
#define HWIO_UFS_QSERDES_COM_RESET_SM_RESTRIMDONE_BMSK                                     0x8
#define HWIO_UFS_QSERDES_COM_RESET_SM_RESTRIMDONE_SHFT                                     0x3
#define HWIO_UFS_QSERDES_COM_RESET_SM_RESETSM_BMSK                                         0x7
#define HWIO_UFS_QSERDES_COM_RESET_SM_RESETSM_SHFT                                         0x0

/*----------------------------------------------------------------------------
 * MODULE: UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX
 *--------------------------------------------------------------------------*/

#define UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE                                         (UFS_UFS_REGS_BASE      + 0x00007200)

#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_ADDR, HWIO_UFS_QSERDES_RX0_CDR_CONTROL_RMSK)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_ADDR,m,v,HWIO_UFS_QSERDES_RX0_CDR_CONTROL_IN)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HBW_PD_EN_BMSK                                           0x80
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HBW_PD_EN_SHFT                                            0x7
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_SECONDORDERENABLE_BMSK                                   0x40
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_SECONDORDERENABLE_SHFT                                    0x6
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_FIRSTORDER_THRESH_BMSK                                   0x38
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_FIRSTORDER_THRESH_SHFT                                    0x3
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_SECONDORDERGAIN_BMSK                                      0x7
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_SECONDORDERGAIN_SHFT                                      0x0

#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_CONTROL_ADDR, HWIO_UFS_QSERDES_RX0_AUX_CONTROL_RMSK)
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_CONTROL_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_AUX_CONTROL_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_AUX_CONTROL_ADDR,m,v,HWIO_UFS_QSERDES_RX0_AUX_CONTROL_IN)
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_AUXDATA_EN_BMSK                                          0x80
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_AUXDATA_EN_SHFT                                           0x7
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_AUXCLK_EN_BMSK                                           0x40
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_AUXCLK_EN_SHFT                                            0x6
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_AUX_OFFSET_BMSK                                          0x3f
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_AUX_OFFSET_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_ADDR, HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_RMSK)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_ADDR,m,v,HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_IN)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_AUXDATA_TCODE_BMSK                                    0xff
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_AUXDATA_TCODE_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_RMSK                                                 0x3
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_ADDR, HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_RMSK)
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_ADDR,m,v,HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_IN)
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_AUXDATA_SEL_BMSK                                     0x2
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_AUXDATA_SEL_SHFT                                     0x1
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_RCLK_SEL_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_RCLK_SEL_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_EQ_CONTROL_ADDR, HWIO_UFS_QSERDES_RX0_EQ_CONTROL_RMSK)
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_EQ_CONTROL_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_EQ_CONTROL_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_EQ_CONTROL_ADDR,m,v,HWIO_UFS_QSERDES_RX0_EQ_CONTROL_IN)
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_KEQ_BMSK                                                  0xe0
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_KEQ_SHFT                                                   0x5
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQADP_FLIP_SIGN_BMSK                                      0x10
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQADP_FLIP_SIGN_SHFT                                       0x4
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQADP_EN_BMSK                                              0x8
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQADP_EN_SHFT                                              0x3
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQADP_MODE_BMSK                                            0x4
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQADP_MODE_SHFT                                            0x2
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQCODE_SEL_BMSK                                            0x2
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQCODE_SEL_SHFT                                            0x1
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQCODE_MSB_BMSK                                            0x1
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_EQCODE_MSB_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_RMSK                                                     0x1f
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_ADDR, HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_RMSK)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_IN)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_RX_EQ_GAIN2_MUX_BMSK                                     0x10
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_RX_EQ_GAIN2_MUX_SHFT                                      0x4
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_RX_EQ_GAIN2_BMSK                                          0xf
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_RX_EQ_GAIN2_SHFT                                          0x0

#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_RMSK                                                     0xf
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_ADDR, HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_RMSK)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_ADDR,m,v,HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_IN)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITP_MUX_BMSK                                   0x8
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITP_MUX_SHFT                                   0x3
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITP_BMSK                                       0x4
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITP_SHFT                                       0x2
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITN_MUX_BMSK                                   0x2
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITN_MUX_SHFT                                   0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITN_BMSK                                       0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_AC_JTAG_INITN_SHFT                                       0x0

#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_RMSK                                                   0x3
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_ADDR, HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_RMSK)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_ADDR,m,v,HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_IN)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_AC_JTAG_LVL_BMSK                                       0x2
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_AC_JTAG_LVL_SHFT                                       0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_AC_JTAG_EN_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_AC_JTAG_EN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_RMSK                                                     0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_ADDR, HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_RMSK)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_ADDR,m,v,HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_IN)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_AC_JTAG_MODE_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_AC_JTAG_MODE_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_ADDR                                             (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_RMSK                                                    0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_ADDR, HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_RMSK)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_ADDR,m,v,HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_IN)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_AC_JTAG_RESET_BMSK                                      0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_AC_JTAG_RESET_SHFT                                      0x0

#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_ADDR, HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RMSK)
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_ADDR,m,v,HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_IN)
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_Q_EN_MUX_BMSK                                      0x80
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_Q_EN_MUX_SHFT                                       0x7
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_Q_EN_BMSK                                          0x40
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_Q_EN_SHFT                                           0x6
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_I_EN_MUX_BMSK                                      0x20
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_I_EN_MUX_SHFT                                       0x5
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_I_EN_BMSK                                          0x10
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RX_I_EN_SHFT                                           0x4
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RXDET_EN_MUX_BMSK                                      0x8
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RXDET_EN_MUX_SHFT                                      0x3
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RXDET_EN_BMSK                                          0x4
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RXDET_EN_SHFT                                          0x2
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RCVR_EN_MUX_BMSK                                       0x2
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RCVR_EN_MUX_SHFT                                       0x1
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RCVR_EN_BMSK                                           0x1
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_RCVR_EN_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RMSK                                      0xff
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR, HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RMSK)
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR,m,v,HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_IN)
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_MUX_BMSK                          0x80
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_MUX_SHFT                           0x7
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_BMSK                              0x40
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_SHFT                               0x6
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_MUX_BMSK                         0x20
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_MUX_SHFT                          0x5
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_BMSK                             0x10
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_SHFT                              0x4
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_MUX_BMSK                             0x8
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_MUX_SHFT                             0x3
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_BMSK                                 0x4
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_SHFT                                 0x2
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_MUX_BMSK                      0x2
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_MUX_SHFT                      0x1
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_BMSK                          0x1
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_SHFT                          0x0

#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_RMSK                                                     0x1f
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_ADDR, HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_RMSK)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_IN)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_RX_EQ_GAIN1_MUX_BMSK                                     0x10
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_RX_EQ_GAIN1_MUX_SHFT                                      0x4
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_RX_EQ_GAIN1_BMSK                                          0xf
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_RX_EQ_GAIN1_SHFT                                          0x0

#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_RMSK                                                    0xff
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_ADDR, HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_RMSK)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_IN)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LFEN_BMSK                                        0x80
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LFEN_SHFT                                         0x7
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LVL_BMSK                                         0x70
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LVL_SHFT                                          0x4
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LP_EN_MUX_BMSK                                    0x8
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LP_EN_MUX_SHFT                                    0x3
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LP_EN_BMSK                                        0x4
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_LP_EN_SHFT                                        0x2
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_EN_MUX_BMSK                                       0x2
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_EN_MUX_SHFT                                       0x1
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_EN_BMSK                                           0x1
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_SIGDET_EN_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX0_RX_BAND_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_RX0_RX_BAND_RMSK                                                          0x7
#define HWIO_UFS_QSERDES_RX0_RX_BAND_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_BAND_ADDR, HWIO_UFS_QSERDES_RX0_RX_BAND_RMSK)
#define HWIO_UFS_QSERDES_RX0_RX_BAND_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_BAND_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RX_BAND_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_RX_BAND_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_RX_BAND_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_RX_BAND_ADDR,m,v,HWIO_UFS_QSERDES_RX0_RX_BAND_IN)
#define HWIO_UFS_QSERDES_RX0_RX_BAND_RX_BAND_MUX_BMSK                                              0x4
#define HWIO_UFS_QSERDES_RX0_RX_BAND_RX_BAND_MUX_SHFT                                              0x2
#define HWIO_UFS_QSERDES_RX0_RX_BAND_RX_BAND_BMSK                                                  0x3
#define HWIO_UFS_QSERDES_RX0_RX_BAND_RX_BAND_SHFT                                                  0x0

#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_RMSK                                                 0x7
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_ADDR, HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_RMSK)
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_ADDR,m,v,HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_IN)
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_CDR_DN_BMSK                                          0x4
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_CDR_DN_SHFT                                          0x2
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_CDR_UP_BMSK                                          0x2
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_CDR_UP_SHFT                                          0x1
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_CDR_FREEZE_BMSK                                      0x1
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_CDR_FREEZE_SHFT                                      0x0

#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_ADDR                                         (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_RMSK                                                0xf
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_ADDR, HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_RMSK)
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_ADDR,m,v,HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_IN)
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_RXINTERFACE_MODE_BMSK                               0xf
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_RXINTERFACE_MODE_SHFT                               0x0

#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_ADDR                                           (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_RMSK                                                 0xff
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_ADDR, HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_RMSK)
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_ADDR,m,v,HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_IN)
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_JITTERGENMODE_BMSK                                   0xff
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_JITTERGENMODE_SHFT                                    0x0

#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_RMSK                                                         0x1f
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_BUJ_AMP_ADDR, HWIO_UFS_QSERDES_RX0_BUJ_AMP_RMSK)
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_BUJ_AMP_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_BUJ_AMP_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_BUJ_AMP_ADDR,m,v,HWIO_UFS_QSERDES_RX0_BUJ_AMP_IN)
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_BUJ_AMPLITUDE_BMSK                                           0x1f
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_BUJ_AMPLITUDE_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_AMP1_ADDR, HWIO_UFS_QSERDES_RX0_SJ_AMP1_RMSK)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_AMP1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SJ_AMP1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SJ_AMP1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SJ_AMP1_IN)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_SJ_AMPLITUDE1_BMSK                                           0xff
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_SJ_AMPLITUDE1_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_AMP2_ADDR, HWIO_UFS_QSERDES_RX0_SJ_AMP2_RMSK)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_AMP2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SJ_AMP2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SJ_AMP2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SJ_AMP2_IN)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_SJ_AMPLITUDE2_BMSK                                           0xff
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_SJ_AMPLITUDE2_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX0_SJ_PER1_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_PER1_ADDR, HWIO_UFS_QSERDES_RX0_SJ_PER1_RMSK)
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_PER1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SJ_PER1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SJ_PER1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SJ_PER1_IN)
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_SJ_PERIOD1_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_SJ_PERIOD1_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX0_SJ_PER2_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_PER2_ADDR, HWIO_UFS_QSERDES_RX0_SJ_PER2_RMSK)
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SJ_PER2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SJ_PER2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SJ_PER2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SJ_PER2_IN)
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_SJ_PERIOD2_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_SJ_PERIOD2_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_ADDR, HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_RMSK)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_IN)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_BUJ_STEPFREQ1_BMSK                                    0xff
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_BUJ_STEPFREQ1_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_ADDR, HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_RMSK)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_IN)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_BUJ_STEPFREQ2_BMSK                                    0xff
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_BUJ_STEPFREQ2_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_ADDR, HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_RMSK)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_IN)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_PPMOFFSET1_BMSK                                          0xff
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_PPMOFFSET1_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_ADDR, HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_RMSK)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_IN)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_PPMOFFSET2_BMSK                                          0xff
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_PPMOFFSET2_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_RMSK                                                0xff
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_ADDR, HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_RMSK)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_IN)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_SIGN_PPM_PERIOD1_BMSK                               0xff
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_SIGN_PPM_PERIOD1_SHFT                                0x0

#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_RMSK                                                0xff
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_ADDR, HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_RMSK)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_IN)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_SIGN_PPM_PERIOD2_BMSK                               0xff
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_SIGN_PPM_PERIOD2_SHFT                                0x0

#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_RMSK                                                         0x3
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SSC_CTRL_ADDR, HWIO_UFS_QSERDES_RX0_SSC_CTRL_RMSK)
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SSC_CTRL_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SSC_CTRL_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SSC_CTRL_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SSC_CTRL_IN)
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_SSCDIRECTION_BMSK                                            0x2
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_SSCDIRECTION_SHFT                                            0x1
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_SSCON_BMSK                                                   0x1
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_SSCON_SHFT                                                   0x0

#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SSC_COUNT1_ADDR, HWIO_UFS_QSERDES_RX0_SSC_COUNT1_RMSK)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SSC_COUNT1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SSC_COUNT1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SSC_COUNT1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SSC_COUNT1_IN)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_SSCCOUNT1_BMSK                                            0xff
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_SSCCOUNT1_SHFT                                             0x0

#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SSC_COUNT2_ADDR, HWIO_UFS_QSERDES_RX0_SSC_COUNT2_RMSK)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SSC_COUNT2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SSC_COUNT2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SSC_COUNT2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SSC_COUNT2_IN)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_SSCCOUNT2_BMSK                                            0xff
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_SSCCOUNT2_SHFT                                             0x0

#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_ADDR, HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_RMSK)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_ADDR,m,v,HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_IN)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_RCLKADJ_BMSK                                              0xf0
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_RCLKADJ_SHFT                                               0x4
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMRXEN_MUX_BMSK                                           0x8
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMRXEN_MUX_SHFT                                           0x3
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMRXEN_BMSK                                               0x4
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMRXEN_SHFT                                               0x2
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMDECEN_BMSK                                              0x2
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMDECEN_SHFT                                              0x1
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMENCEN_BMSK                                              0x1
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_PWMENCEN_SHFT                                              0x0

#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000084)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_RMSK                                                      0x7f
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_ADDR, HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_RMSK)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_IN)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_PWMTXEN_MUX_BMSK                                          0x40
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_PWMTXEN_MUX_SHFT                                           0x6
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_PWMTXEN_BMSK                                              0x20
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_PWMTXEN_SHFT                                               0x5
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_DIN_BMSK                                                  0x1c
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_DIN_SHFT                                                   0x2
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_DIN_MUX_BMSK                                               0x2
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_DIN_MUX_SHFT                                               0x1
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_NDIV_MUX_BMSK                                              0x1
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_NDIV_MUX_SHFT                                              0x0

#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000088)
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_RMSK                                                        0xff
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PWM_NDIV_ADDR, HWIO_UFS_QSERDES_RX0_PWM_NDIV_RMSK)
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PWM_NDIV_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_PWM_NDIV_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_PWM_NDIV_ADDR,m,v,HWIO_UFS_QSERDES_RX0_PWM_NDIV_IN)
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_NDIV_BMSK                                                   0xff
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_NDIV_SHFT                                                    0x0

#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_ADDR                                             (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000008c)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_RMSK                                                   0x3f
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_ADDR, HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_RMSK)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_ADDR,m,v,HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_IN)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_EN_MUX_BMSK                                 0x20
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_EN_MUX_SHFT                                  0x5
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_EN_BMSK                                     0x10
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_EN_SHFT                                      0x4
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_FALL_SEL_BMSK                                0x8
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_FALL_SEL_SHFT                                0x3
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_BW_BMSK                                      0x6
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DEG_BW_SHFT                                      0x1
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DIFP_EN_BMSK                                     0x1
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_SIGDET_DIFP_EN_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_ADDR                                                 (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000090)
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RMSK                                                       0x1f
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UFS_CNTRL_ADDR, HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RMSK)
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UFS_CNTRL_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_UFS_CNTRL_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_UFS_CNTRL_ADDR,m,v,HWIO_UFS_QSERDES_RX0_UFS_CNTRL_IN)
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSEN_MUX_BMSK                                      0x10
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSEN_MUX_SHFT                                       0x4
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSEN_BMSK                                           0x8
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSEN_SHFT                                           0x3
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSCTRL_MUX_BMSK                                     0x4
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSCTRL_MUX_SHFT                                     0x2
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSCTRL_BMSK                                         0x3
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_RXTERM_UFSCTRL_SHFT                                         0x0

#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000094)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_RMSK                                                    0x7f
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ADDR, HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_RMSK)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ADDR,m,v,HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_IN)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_NEW_FEATURE_ENABLE_CE_BMSK                              0x40
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_NEW_FEATURE_ENABLE_CE_SHFT                               0x6
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_NEW_FEATURE_ENABLE_SO_BMSK                              0x20
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_NEW_FEATURE_ENABLE_SO_SHFT                               0x5
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ALOG_FIRSTORDER_CARRY_EN_BMSK                           0x10
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ALOG_FIRSTORDER_CARRY_EN_SHFT                            0x4
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_DIG_FIRSTORDER_CARRY_EN_BMSK                             0x8
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_DIG_FIRSTORDER_CARRY_EN_SHFT                             0x3
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_SECONDORDER_STEP_BY_THREE_BMSK                           0x4
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_SECONDORDER_STEP_BY_THREE_SHFT                           0x2
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_SECONDORDER_STEP_BY_TWO_BMSK                             0x2
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_SECONDORDER_STEP_BY_TWO_SHFT                             0x1
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_SECONDORDER_STEP_BY_ONE_BMSK                             0x1
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_SECONDORDER_STEP_BY_ONE_SHFT                             0x0

#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000098)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_RMSK                                                0x3f
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_ADDR, HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_RMSK)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_ADDR,m,v,HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_IN)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_FIRSTORDER_THRESH_HALF_BMSK                         0x38
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_FIRSTORDER_THRESH_HALF_SHFT                          0x3
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_SECONDORDERGAIN_HALF_BMSK                            0x7
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_SECONDORDERGAIN_HALF_SHFT                            0x0

#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_ADDR                                       (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000009c)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_RMSK                                             0x3f
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_ADDR, HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_RMSK)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_ADDR,m,v,HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_IN)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_FIRSTORDER_THRESH_QUARTER_BMSK                   0x38
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_FIRSTORDER_THRESH_QUARTER_SHFT                    0x3
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_SECONDORDERGAIN_QUARTER_BMSK                      0x7
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_SECONDORDERGAIN_QUARTER_SHFT                      0x0

#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_ADDR                                        (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000a0)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_RMSK                                              0x3f
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_ADDR, HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_RMSK)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_ADDR,m,v,HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_IN)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_FIRSTORDER_THRESH_EIGHTH_BMSK                     0x38
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_FIRSTORDER_THRESH_EIGHTH_SHFT                      0x3
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_SECONDORDERGAIN_EIGHTH_BMSK                        0x7
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_SECONDORDERGAIN_EIGHTH_SHFT                        0x0

#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000a4)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_RMSK                                                    0x7f
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_ADDR, HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_RMSK)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_ADDR,m,v,HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_IN)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_UCDR_FO_GAIN_BMSK                                       0x7f
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_UCDR_FO_GAIN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000a8)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_RMSK                                                    0x7f
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_ADDR, HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_RMSK)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_ADDR,m,v,HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_IN)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_UCDR_SO_GAIN_BMSK                                       0x7f
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_UCDR_SO_GAIN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_ADDR                             (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000ac)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_RMSK                                   0xff
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_ADDR, HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_RMSK)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_ADDR,m,v,HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_IN)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_UCDR_CONTROL_PI_BMSK                   0x80
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_UCDR_CONTROL_PI_SHFT                    0x7
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_UCDR_ENABLE_BMSK                       0x40
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_UCDR_ENABLE_SHFT                        0x6
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_UCDR_SO_SATURATION_BMSK                0x3f
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_UCDR_SO_SATURATION_SHFT                 0x0

#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_ADDR                                       (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000b0)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_RMSK                                             0xff
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_ADDR, HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_RMSK)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_ADDR,v)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_ADDR,m,v,HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_IN)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_UCDR_FO_TO_SO_DELAY_BMSK                         0xff
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_UCDR_FO_TO_SO_DELAY_SHFT                          0x0

#define HWIO_UFS_QSERDES_RX0_PI_CTRL1_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000b4)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL1_RMSK                                                        0xff
#define HWIO_UFS_QSERDES_RX0_PI_CTRL1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PI_CTRL1_ADDR, HWIO_UFS_QSERDES_RX0_PI_CTRL1_RMSK)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PI_CTRL1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL1_PI_CTRL1_BMSK                                               0xff
#define HWIO_UFS_QSERDES_RX0_PI_CTRL1_PI_CTRL1_SHFT                                                0x0

#define HWIO_UFS_QSERDES_RX0_PI_CTRL2_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000b8)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL2_RMSK                                                        0xff
#define HWIO_UFS_QSERDES_RX0_PI_CTRL2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PI_CTRL2_ADDR, HWIO_UFS_QSERDES_RX0_PI_CTRL2_RMSK)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PI_CTRL2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL2_PI_CTRL2_BMSK                                               0xff
#define HWIO_UFS_QSERDES_RX0_PI_CTRL2_PI_CTRL2_SHFT                                                0x0

#define HWIO_UFS_QSERDES_RX0_PI_QUAD_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000bc)
#define HWIO_UFS_QSERDES_RX0_PI_QUAD_RMSK                                                          0x3
#define HWIO_UFS_QSERDES_RX0_PI_QUAD_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PI_QUAD_ADDR, HWIO_UFS_QSERDES_RX0_PI_QUAD_RMSK)
#define HWIO_UFS_QSERDES_RX0_PI_QUAD_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_PI_QUAD_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_PI_QUAD_PI_QUAD_BMSK                                                  0x3
#define HWIO_UFS_QSERDES_RX0_PI_QUAD_PI_QUAD_SHFT                                                  0x0

#define HWIO_UFS_QSERDES_RX0_IDATA1_ADDR                                                    (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000c0)
#define HWIO_UFS_QSERDES_RX0_IDATA1_RMSK                                                          0xff
#define HWIO_UFS_QSERDES_RX0_IDATA1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_IDATA1_ADDR, HWIO_UFS_QSERDES_RX0_IDATA1_RMSK)
#define HWIO_UFS_QSERDES_RX0_IDATA1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_IDATA1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_IDATA1_IDATA1_BMSK                                                   0xff
#define HWIO_UFS_QSERDES_RX0_IDATA1_IDATA1_SHFT                                                    0x0

#define HWIO_UFS_QSERDES_RX0_IDATA2_ADDR                                                    (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000c4)
#define HWIO_UFS_QSERDES_RX0_IDATA2_RMSK                                                          0xff
#define HWIO_UFS_QSERDES_RX0_IDATA2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_IDATA2_ADDR, HWIO_UFS_QSERDES_RX0_IDATA2_RMSK)
#define HWIO_UFS_QSERDES_RX0_IDATA2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_IDATA2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_IDATA2_IDATA2_BMSK                                                   0xff
#define HWIO_UFS_QSERDES_RX0_IDATA2_IDATA2_SHFT                                                    0x0

#define HWIO_UFS_QSERDES_RX0_AUX_DATA1_ADDR                                                 (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000c8)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA1_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_RX0_AUX_DATA1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_DATA1_ADDR, HWIO_UFS_QSERDES_RX0_AUX_DATA1_RMSK)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_DATA1_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA1_AUXDATA1_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX0_AUX_DATA1_AUXDATA1_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX0_AUX_DATA2_ADDR                                                 (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000cc)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA2_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_RX0_AUX_DATA2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_DATA2_ADDR, HWIO_UFS_QSERDES_RX0_AUX_DATA2_RMSK)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AUX_DATA2_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA2_AUXDATA2_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX0_AUX_DATA2_AUXDATA2_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000d0)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_RMSK                                                     0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_ADDR, HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_RMSK)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_AC_JTAG_OUTP_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_AC_JTAG_OUTP_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000d4)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_RMSK                                                     0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_ADDR, HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_RMSK)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_AC_JTAG_OUTN_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_AC_JTAG_OUTN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_ADDR                                    (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000d8)
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_RMSK                                           0xf
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_ADDR, HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_RMSK)
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_ADDR, m)
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_DEC_STATUS_BMSK                                0xc
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_DEC_STATUS_SHFT                                0x2
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_LF_BMSK                              0x2
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_LF_SHFT                              0x1
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_BMSK                                 0x1
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_SHFT                                 0x0

/*----------------------------------------------------------------------------
 * MODULE: UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX
 *--------------------------------------------------------------------------*/

#define UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE                                         (UFS_UFS_REGS_BASE      + 0x00007600)

#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_ADDR, HWIO_UFS_QSERDES_RX1_CDR_CONTROL_RMSK)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_ADDR,m,v,HWIO_UFS_QSERDES_RX1_CDR_CONTROL_IN)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HBW_PD_EN_BMSK                                           0x80
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HBW_PD_EN_SHFT                                            0x7
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_SECONDORDERENABLE_BMSK                                   0x40
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_SECONDORDERENABLE_SHFT                                    0x6
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_FIRSTORDER_THRESH_BMSK                                   0x38
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_FIRSTORDER_THRESH_SHFT                                    0x3
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_SECONDORDERGAIN_BMSK                                      0x7
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_SECONDORDERGAIN_SHFT                                      0x0

#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_CONTROL_ADDR, HWIO_UFS_QSERDES_RX1_AUX_CONTROL_RMSK)
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_CONTROL_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_AUX_CONTROL_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_AUX_CONTROL_ADDR,m,v,HWIO_UFS_QSERDES_RX1_AUX_CONTROL_IN)
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_AUXDATA_EN_BMSK                                          0x80
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_AUXDATA_EN_SHFT                                           0x7
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_AUXCLK_EN_BMSK                                           0x40
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_AUXCLK_EN_SHFT                                            0x6
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_AUX_OFFSET_BMSK                                          0x3f
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_AUX_OFFSET_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_ADDR, HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_RMSK)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_ADDR,m,v,HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_IN)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_AUXDATA_TCODE_BMSK                                    0xff
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_AUXDATA_TCODE_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_RMSK                                                 0x3
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_ADDR, HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_RMSK)
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_ADDR,m,v,HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_IN)
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_AUXDATA_SEL_BMSK                                     0x2
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_AUXDATA_SEL_SHFT                                     0x1
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_RCLK_SEL_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_RCLK_SEL_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_EQ_CONTROL_ADDR, HWIO_UFS_QSERDES_RX1_EQ_CONTROL_RMSK)
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_EQ_CONTROL_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_EQ_CONTROL_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_EQ_CONTROL_ADDR,m,v,HWIO_UFS_QSERDES_RX1_EQ_CONTROL_IN)
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_KEQ_BMSK                                                  0xe0
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_KEQ_SHFT                                                   0x5
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQADP_FLIP_SIGN_BMSK                                      0x10
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQADP_FLIP_SIGN_SHFT                                       0x4
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQADP_EN_BMSK                                              0x8
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQADP_EN_SHFT                                              0x3
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQADP_MODE_BMSK                                            0x4
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQADP_MODE_SHFT                                            0x2
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQCODE_SEL_BMSK                                            0x2
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQCODE_SEL_SHFT                                            0x1
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQCODE_MSB_BMSK                                            0x1
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_EQCODE_MSB_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_RMSK                                                     0x1f
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_ADDR, HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_RMSK)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_IN)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_RX_EQ_GAIN2_MUX_BMSK                                     0x10
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_RX_EQ_GAIN2_MUX_SHFT                                      0x4
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_RX_EQ_GAIN2_BMSK                                          0xf
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_RX_EQ_GAIN2_SHFT                                          0x0

#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_RMSK                                                     0xf
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_ADDR, HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_RMSK)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_ADDR,m,v,HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_IN)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITP_MUX_BMSK                                   0x8
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITP_MUX_SHFT                                   0x3
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITP_BMSK                                       0x4
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITP_SHFT                                       0x2
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITN_MUX_BMSK                                   0x2
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITN_MUX_SHFT                                   0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITN_BMSK                                       0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_AC_JTAG_INITN_SHFT                                       0x0

#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_RMSK                                                   0x3
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_ADDR, HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_RMSK)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_ADDR,m,v,HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_IN)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_AC_JTAG_LVL_BMSK                                       0x2
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_AC_JTAG_LVL_SHFT                                       0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_AC_JTAG_EN_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_AC_JTAG_EN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_RMSK                                                     0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_ADDR, HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_RMSK)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_ADDR,m,v,HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_IN)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_AC_JTAG_MODE_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_AC_JTAG_MODE_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_ADDR                                             (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_RMSK                                                    0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_ADDR, HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_RMSK)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_ADDR,m,v,HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_IN)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_AC_JTAG_RESET_BMSK                                      0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_AC_JTAG_RESET_SHFT                                      0x0

#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_ADDR, HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RMSK)
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_ADDR,m,v,HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_IN)
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_Q_EN_MUX_BMSK                                      0x80
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_Q_EN_MUX_SHFT                                       0x7
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_Q_EN_BMSK                                          0x40
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_Q_EN_SHFT                                           0x6
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_I_EN_MUX_BMSK                                      0x20
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_I_EN_MUX_SHFT                                       0x5
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_I_EN_BMSK                                          0x10
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RX_I_EN_SHFT                                           0x4
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RXDET_EN_MUX_BMSK                                      0x8
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RXDET_EN_MUX_SHFT                                      0x3
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RXDET_EN_BMSK                                          0x4
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RXDET_EN_SHFT                                          0x2
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RCVR_EN_MUX_BMSK                                       0x2
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RCVR_EN_MUX_SHFT                                       0x1
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RCVR_EN_BMSK                                           0x1
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_RCVR_EN_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RMSK                                      0xff
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR, HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RMSK)
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR,m,v,HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_IN)
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_MUX_BMSK                          0x80
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_MUX_SHFT                           0x7
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_BMSK                              0x40
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_TERM_SHFT                               0x6
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_MUX_BMSK                         0x20
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_MUX_SHFT                          0x5
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_BMSK                             0x10
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_HIGHZ_SHFT                              0x4
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_MUX_BMSK                             0x8
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_MUX_SHFT                             0x3
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_BMSK                                 0x4
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_CM_SHFT                                 0x2
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_MUX_BMSK                      0x2
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_MUX_SHFT                      0x1
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_BMSK                          0x1
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_RX_AC_COUPLE_SHFT                          0x0

#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_RMSK                                                     0x1f
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_ADDR, HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_RMSK)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_IN)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_RX_EQ_GAIN1_MUX_BMSK                                     0x10
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_RX_EQ_GAIN1_MUX_SHFT                                      0x4
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_RX_EQ_GAIN1_BMSK                                          0xf
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_RX_EQ_GAIN1_SHFT                                          0x0

#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_RMSK                                                    0xff
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_ADDR, HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_RMSK)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_IN)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LFEN_BMSK                                        0x80
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LFEN_SHFT                                         0x7
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LVL_BMSK                                         0x70
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LVL_SHFT                                          0x4
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LP_EN_MUX_BMSK                                    0x8
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LP_EN_MUX_SHFT                                    0x3
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LP_EN_BMSK                                        0x4
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_LP_EN_SHFT                                        0x2
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_EN_MUX_BMSK                                       0x2
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_EN_MUX_SHFT                                       0x1
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_EN_BMSK                                           0x1
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_SIGDET_EN_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX1_RX_BAND_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_RX1_RX_BAND_RMSK                                                          0x7
#define HWIO_UFS_QSERDES_RX1_RX_BAND_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_BAND_ADDR, HWIO_UFS_QSERDES_RX1_RX_BAND_RMSK)
#define HWIO_UFS_QSERDES_RX1_RX_BAND_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_BAND_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RX_BAND_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_RX_BAND_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_RX_BAND_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_RX_BAND_ADDR,m,v,HWIO_UFS_QSERDES_RX1_RX_BAND_IN)
#define HWIO_UFS_QSERDES_RX1_RX_BAND_RX_BAND_MUX_BMSK                                              0x4
#define HWIO_UFS_QSERDES_RX1_RX_BAND_RX_BAND_MUX_SHFT                                              0x2
#define HWIO_UFS_QSERDES_RX1_RX_BAND_RX_BAND_BMSK                                                  0x3
#define HWIO_UFS_QSERDES_RX1_RX_BAND_RX_BAND_SHFT                                                  0x0

#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_RMSK                                                 0x7
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_ADDR, HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_RMSK)
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_ADDR,m,v,HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_IN)
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_CDR_DN_BMSK                                          0x4
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_CDR_DN_SHFT                                          0x2
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_CDR_UP_BMSK                                          0x2
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_CDR_UP_SHFT                                          0x1
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_CDR_FREEZE_BMSK                                      0x1
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_CDR_FREEZE_SHFT                                      0x0

#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_ADDR                                         (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_RMSK                                                0xf
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_ADDR, HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_RMSK)
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_ADDR,m,v,HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_IN)
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_RXINTERFACE_MODE_BMSK                               0xf
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_RXINTERFACE_MODE_SHFT                               0x0

#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_ADDR                                           (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_RMSK                                                 0xff
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_ADDR, HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_RMSK)
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_ADDR,m,v,HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_IN)
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_JITTERGENMODE_BMSK                                   0xff
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_JITTERGENMODE_SHFT                                    0x0

#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_RMSK                                                         0x1f
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_BUJ_AMP_ADDR, HWIO_UFS_QSERDES_RX1_BUJ_AMP_RMSK)
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_BUJ_AMP_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_BUJ_AMP_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_BUJ_AMP_ADDR,m,v,HWIO_UFS_QSERDES_RX1_BUJ_AMP_IN)
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_BUJ_AMPLITUDE_BMSK                                           0x1f
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_BUJ_AMPLITUDE_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_AMP1_ADDR, HWIO_UFS_QSERDES_RX1_SJ_AMP1_RMSK)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_AMP1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SJ_AMP1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SJ_AMP1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SJ_AMP1_IN)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_SJ_AMPLITUDE1_BMSK                                           0xff
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_SJ_AMPLITUDE1_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_AMP2_ADDR, HWIO_UFS_QSERDES_RX1_SJ_AMP2_RMSK)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_AMP2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SJ_AMP2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SJ_AMP2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SJ_AMP2_IN)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_SJ_AMPLITUDE2_BMSK                                           0xff
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_SJ_AMPLITUDE2_SHFT                                            0x0

#define HWIO_UFS_QSERDES_RX1_SJ_PER1_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_PER1_ADDR, HWIO_UFS_QSERDES_RX1_SJ_PER1_RMSK)
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_PER1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SJ_PER1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SJ_PER1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SJ_PER1_IN)
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_SJ_PERIOD1_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_SJ_PERIOD1_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX1_SJ_PER2_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_PER2_ADDR, HWIO_UFS_QSERDES_RX1_SJ_PER2_RMSK)
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SJ_PER2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SJ_PER2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SJ_PER2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SJ_PER2_IN)
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_SJ_PERIOD2_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_SJ_PERIOD2_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_ADDR, HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_RMSK)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_IN)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_BUJ_STEPFREQ1_BMSK                                    0xff
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_BUJ_STEPFREQ1_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_ADDR, HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_RMSK)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_IN)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_BUJ_STEPFREQ2_BMSK                                    0xff
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_BUJ_STEPFREQ2_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_ADDR, HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_RMSK)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_IN)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_PPMOFFSET1_BMSK                                          0xff
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_PPMOFFSET1_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_RMSK                                                     0xff
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_ADDR, HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_RMSK)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_IN)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_PPMOFFSET2_BMSK                                          0xff
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_PPMOFFSET2_SHFT                                           0x0

#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_RMSK                                                0xff
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_ADDR, HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_RMSK)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_IN)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_SIGN_PPM_PERIOD1_BMSK                               0xff
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_SIGN_PPM_PERIOD1_SHFT                                0x0

#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_RMSK                                                0xff
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_ADDR, HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_RMSK)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_IN)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_SIGN_PPM_PERIOD2_BMSK                               0xff
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_SIGN_PPM_PERIOD2_SHFT                                0x0

#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_RMSK                                                         0x3
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SSC_CTRL_ADDR, HWIO_UFS_QSERDES_RX1_SSC_CTRL_RMSK)
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SSC_CTRL_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SSC_CTRL_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SSC_CTRL_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SSC_CTRL_IN)
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_SSCDIRECTION_BMSK                                            0x2
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_SSCDIRECTION_SHFT                                            0x1
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_SSCON_BMSK                                                   0x1
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_SSCON_SHFT                                                   0x0

#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SSC_COUNT1_ADDR, HWIO_UFS_QSERDES_RX1_SSC_COUNT1_RMSK)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SSC_COUNT1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SSC_COUNT1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SSC_COUNT1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SSC_COUNT1_IN)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_SSCCOUNT1_BMSK                                            0xff
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_SSCCOUNT1_SHFT                                             0x0

#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SSC_COUNT2_ADDR, HWIO_UFS_QSERDES_RX1_SSC_COUNT2_RMSK)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SSC_COUNT2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SSC_COUNT2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SSC_COUNT2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SSC_COUNT2_IN)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_SSCCOUNT2_BMSK                                            0xff
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_SSCCOUNT2_SHFT                                             0x0

#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_ADDR, HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_RMSK)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_ADDR,m,v,HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_IN)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_RCLKADJ_BMSK                                              0xf0
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_RCLKADJ_SHFT                                               0x4
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMRXEN_MUX_BMSK                                           0x8
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMRXEN_MUX_SHFT                                           0x3
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMRXEN_BMSK                                               0x4
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMRXEN_SHFT                                               0x2
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMDECEN_BMSK                                              0x2
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMDECEN_SHFT                                              0x1
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMENCEN_BMSK                                              0x1
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_PWMENCEN_SHFT                                              0x0

#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000084)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_RMSK                                                      0x7f
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_ADDR, HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_RMSK)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_IN)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_PWMTXEN_MUX_BMSK                                          0x40
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_PWMTXEN_MUX_SHFT                                           0x6
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_PWMTXEN_BMSK                                              0x20
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_PWMTXEN_SHFT                                               0x5
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_DIN_BMSK                                                  0x1c
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_DIN_SHFT                                                   0x2
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_DIN_MUX_BMSK                                               0x2
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_DIN_MUX_SHFT                                               0x1
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_NDIV_MUX_BMSK                                              0x1
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_NDIV_MUX_SHFT                                              0x0

#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000088)
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_RMSK                                                        0xff
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PWM_NDIV_ADDR, HWIO_UFS_QSERDES_RX1_PWM_NDIV_RMSK)
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PWM_NDIV_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_PWM_NDIV_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_PWM_NDIV_ADDR,m,v,HWIO_UFS_QSERDES_RX1_PWM_NDIV_IN)
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_NDIV_BMSK                                                   0xff
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_NDIV_SHFT                                                    0x0

#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_ADDR                                             (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000008c)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_RMSK                                                   0x3f
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_ADDR, HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_RMSK)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_ADDR,m,v,HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_IN)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_EN_MUX_BMSK                                 0x20
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_EN_MUX_SHFT                                  0x5
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_EN_BMSK                                     0x10
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_EN_SHFT                                      0x4
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_FALL_SEL_BMSK                                0x8
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_FALL_SEL_SHFT                                0x3
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_BW_BMSK                                      0x6
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DEG_BW_SHFT                                      0x1
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DIFP_EN_BMSK                                     0x1
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_SIGDET_DIFP_EN_SHFT                                     0x0

#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_ADDR                                                 (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000090)
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RMSK                                                       0x1f
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UFS_CNTRL_ADDR, HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RMSK)
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UFS_CNTRL_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_UFS_CNTRL_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_UFS_CNTRL_ADDR,m,v,HWIO_UFS_QSERDES_RX1_UFS_CNTRL_IN)
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSEN_MUX_BMSK                                      0x10
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSEN_MUX_SHFT                                       0x4
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSEN_BMSK                                           0x8
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSEN_SHFT                                           0x3
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSCTRL_MUX_BMSK                                     0x4
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSCTRL_MUX_SHFT                                     0x2
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSCTRL_BMSK                                         0x3
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_RXTERM_UFSCTRL_SHFT                                         0x0

#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000094)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_RMSK                                                    0x7f
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ADDR, HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_RMSK)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ADDR,m,v,HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_IN)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_NEW_FEATURE_ENABLE_CE_BMSK                              0x40
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_NEW_FEATURE_ENABLE_CE_SHFT                               0x6
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_NEW_FEATURE_ENABLE_SO_BMSK                              0x20
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_NEW_FEATURE_ENABLE_SO_SHFT                               0x5
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ALOG_FIRSTORDER_CARRY_EN_BMSK                           0x10
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ALOG_FIRSTORDER_CARRY_EN_SHFT                            0x4
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_DIG_FIRSTORDER_CARRY_EN_BMSK                             0x8
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_DIG_FIRSTORDER_CARRY_EN_SHFT                             0x3
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_SECONDORDER_STEP_BY_THREE_BMSK                           0x4
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_SECONDORDER_STEP_BY_THREE_SHFT                           0x2
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_SECONDORDER_STEP_BY_TWO_BMSK                             0x2
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_SECONDORDER_STEP_BY_TWO_SHFT                             0x1
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_SECONDORDER_STEP_BY_ONE_BMSK                             0x1
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_SECONDORDER_STEP_BY_ONE_SHFT                             0x0

#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000098)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_RMSK                                                0x3f
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_ADDR, HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_RMSK)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_ADDR,m,v,HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_IN)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_FIRSTORDER_THRESH_HALF_BMSK                         0x38
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_FIRSTORDER_THRESH_HALF_SHFT                          0x3
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_SECONDORDERGAIN_HALF_BMSK                            0x7
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_SECONDORDERGAIN_HALF_SHFT                            0x0

#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_ADDR                                       (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000009c)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_RMSK                                             0x3f
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_ADDR, HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_RMSK)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_ADDR,m,v,HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_IN)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_FIRSTORDER_THRESH_QUARTER_BMSK                   0x38
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_FIRSTORDER_THRESH_QUARTER_SHFT                    0x3
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_SECONDORDERGAIN_QUARTER_BMSK                      0x7
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_SECONDORDERGAIN_QUARTER_SHFT                      0x0

#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_ADDR                                        (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000a0)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_RMSK                                              0x3f
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_ADDR, HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_RMSK)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_ADDR,m,v,HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_IN)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_FIRSTORDER_THRESH_EIGHTH_BMSK                     0x38
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_FIRSTORDER_THRESH_EIGHTH_SHFT                      0x3
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_SECONDORDERGAIN_EIGHTH_BMSK                        0x7
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_SECONDORDERGAIN_EIGHTH_SHFT                        0x0

#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000a4)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_RMSK                                                    0x7f
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_ADDR, HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_RMSK)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_ADDR,m,v,HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_IN)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_UCDR_FO_GAIN_BMSK                                       0x7f
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_UCDR_FO_GAIN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000a8)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_RMSK                                                    0x7f
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_ADDR, HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_RMSK)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_ADDR,m,v,HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_IN)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_UCDR_SO_GAIN_BMSK                                       0x7f
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_UCDR_SO_GAIN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_ADDR                             (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000ac)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_RMSK                                   0xff
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_ADDR, HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_RMSK)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_ADDR,m,v,HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_IN)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_UCDR_CONTROL_PI_BMSK                   0x80
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_UCDR_CONTROL_PI_SHFT                    0x7
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_UCDR_ENABLE_BMSK                       0x40
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_UCDR_ENABLE_SHFT                        0x6
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_UCDR_SO_SATURATION_BMSK                0x3f
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_UCDR_SO_SATURATION_SHFT                 0x0

#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_ADDR                                       (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000b0)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_RMSK                                             0xff
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_ADDR, HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_RMSK)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_ADDR,v)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_ADDR,m,v,HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_IN)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_UCDR_FO_TO_SO_DELAY_BMSK                         0xff
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_UCDR_FO_TO_SO_DELAY_SHFT                          0x0

#define HWIO_UFS_QSERDES_RX1_PI_CTRL1_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000b4)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL1_RMSK                                                        0xff
#define HWIO_UFS_QSERDES_RX1_PI_CTRL1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PI_CTRL1_ADDR, HWIO_UFS_QSERDES_RX1_PI_CTRL1_RMSK)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PI_CTRL1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL1_PI_CTRL1_BMSK                                               0xff
#define HWIO_UFS_QSERDES_RX1_PI_CTRL1_PI_CTRL1_SHFT                                                0x0

#define HWIO_UFS_QSERDES_RX1_PI_CTRL2_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000b8)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL2_RMSK                                                        0xff
#define HWIO_UFS_QSERDES_RX1_PI_CTRL2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PI_CTRL2_ADDR, HWIO_UFS_QSERDES_RX1_PI_CTRL2_RMSK)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PI_CTRL2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL2_PI_CTRL2_BMSK                                               0xff
#define HWIO_UFS_QSERDES_RX1_PI_CTRL2_PI_CTRL2_SHFT                                                0x0

#define HWIO_UFS_QSERDES_RX1_PI_QUAD_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000bc)
#define HWIO_UFS_QSERDES_RX1_PI_QUAD_RMSK                                                          0x3
#define HWIO_UFS_QSERDES_RX1_PI_QUAD_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PI_QUAD_ADDR, HWIO_UFS_QSERDES_RX1_PI_QUAD_RMSK)
#define HWIO_UFS_QSERDES_RX1_PI_QUAD_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_PI_QUAD_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_PI_QUAD_PI_QUAD_BMSK                                                  0x3
#define HWIO_UFS_QSERDES_RX1_PI_QUAD_PI_QUAD_SHFT                                                  0x0

#define HWIO_UFS_QSERDES_RX1_IDATA1_ADDR                                                    (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000c0)
#define HWIO_UFS_QSERDES_RX1_IDATA1_RMSK                                                          0xff
#define HWIO_UFS_QSERDES_RX1_IDATA1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_IDATA1_ADDR, HWIO_UFS_QSERDES_RX1_IDATA1_RMSK)
#define HWIO_UFS_QSERDES_RX1_IDATA1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_IDATA1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_IDATA1_IDATA1_BMSK                                                   0xff
#define HWIO_UFS_QSERDES_RX1_IDATA1_IDATA1_SHFT                                                    0x0

#define HWIO_UFS_QSERDES_RX1_IDATA2_ADDR                                                    (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000c4)
#define HWIO_UFS_QSERDES_RX1_IDATA2_RMSK                                                          0xff
#define HWIO_UFS_QSERDES_RX1_IDATA2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_IDATA2_ADDR, HWIO_UFS_QSERDES_RX1_IDATA2_RMSK)
#define HWIO_UFS_QSERDES_RX1_IDATA2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_IDATA2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_IDATA2_IDATA2_BMSK                                                   0xff
#define HWIO_UFS_QSERDES_RX1_IDATA2_IDATA2_SHFT                                                    0x0

#define HWIO_UFS_QSERDES_RX1_AUX_DATA1_ADDR                                                 (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000c8)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA1_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_RX1_AUX_DATA1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_DATA1_ADDR, HWIO_UFS_QSERDES_RX1_AUX_DATA1_RMSK)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_DATA1_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA1_AUXDATA1_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX1_AUX_DATA1_AUXDATA1_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX1_AUX_DATA2_ADDR                                                 (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000cc)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA2_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_RX1_AUX_DATA2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_DATA2_ADDR, HWIO_UFS_QSERDES_RX1_AUX_DATA2_RMSK)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AUX_DATA2_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA2_AUXDATA2_BMSK                                              0xff
#define HWIO_UFS_QSERDES_RX1_AUX_DATA2_AUXDATA2_SHFT                                               0x0

#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000d0)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_RMSK                                                     0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_ADDR, HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_RMSK)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_AC_JTAG_OUTP_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_AC_JTAG_OUTP_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000d4)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_RMSK                                                     0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_ADDR, HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_RMSK)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_AC_JTAG_OUTN_BMSK                                        0x1
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_AC_JTAG_OUTN_SHFT                                        0x0

#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_ADDR                                    (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000d8)
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_RMSK                                           0xf
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_ADDR, HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_RMSK)
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_ADDR, m)
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_DEC_STATUS_BMSK                                0xc
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_DEC_STATUS_SHFT                                0x2
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_LF_BMSK                              0x2
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_LF_SHFT                              0x1
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_BMSK                                 0x1
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_RX_SIGDET_SHFT                                 0x0

/*----------------------------------------------------------------------------
 * MODULE: UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX
 *--------------------------------------------------------------------------*/

#define UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE                                            (UFS_UFS_REGS_BASE      + 0x00007100)

#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_ADDR                                             (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_RMSK                                                   0x7f
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_ADDR, HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_BIST_LANE_NUMBER_BMSK                                  0x60
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_BIST_LANE_NUMBER_SHFT                                   0x5
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_BISTMODE_BMSK                                          0x1f
#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_BISTMODE_SHFT                                           0x0

#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_RMSK                                                       0x3
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_ADDR, HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_RMSK)
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_ADDR,m,v,HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_IN)
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_CLKBUF_EN_MUX_BMSK                                         0x2
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_CLKBUF_EN_MUX_SHFT                                         0x1
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_CLKBUF_EN_BMSK                                             0x1
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_CLKBUF_EN_SHFT                                             0x0

#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR                                             (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_RMSK                                                   0x3f
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR, HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_RMSK)
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR,m,v,HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_IN)
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_MUX_BMSK                              0x20
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_MUX_SHFT                               0x5
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_BMSK                                  0x1f
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_SHFT                                   0x0

#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_RMSK                                                         0x1f
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_ADDR, HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_RMSK)
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_ADDR,m,v,HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_IN)
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_TX_DRV_LVL_MUX_BMSK                                          0x10
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_TX_DRV_LVL_MUX_SHFT                                           0x4
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_TX_DRV_LVL_BMSK                                               0xf
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_TX_DRV_LVL_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_ADDR                                               (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_RMSK                                                      0x3
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_ADDR, HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_RMSK)
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_IN)
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_RESET_TSYNC_EN_MUX_BMSK                                   0x2
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_RESET_TSYNC_EN_MUX_SHFT                                   0x1
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_RESET_TSYNC_EN_BMSK                                       0x1
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_RESET_TSYNC_EN_SHFT                                       0x0

#define HWIO_UFS_QSERDES_TX0_LPB_EN_ADDR                                                       (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_TX0_LPB_EN_RMSK                                                             0x7f
#define HWIO_UFS_QSERDES_TX0_LPB_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_LPB_EN_ADDR, HWIO_UFS_QSERDES_TX0_LPB_EN_RMSK)
#define HWIO_UFS_QSERDES_TX0_LPB_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_LPB_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_LPB_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_LPB_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_LPB_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_LPB_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX0_LPB_EN_IN)
#define HWIO_UFS_QSERDES_TX0_LPB_EN_LINE_LPB_EN_MUX_BMSK                                             0x40
#define HWIO_UFS_QSERDES_TX0_LPB_EN_LINE_LPB_EN_MUX_SHFT                                              0x6
#define HWIO_UFS_QSERDES_TX0_LPB_EN_LINE_LPB_EN_BMSK                                                 0x20
#define HWIO_UFS_QSERDES_TX0_LPB_EN_LINE_LPB_EN_SHFT                                                  0x5
#define HWIO_UFS_QSERDES_TX0_LPB_EN_TX_RCLK_LPB_EN_BMSK                                              0x10
#define HWIO_UFS_QSERDES_TX0_LPB_EN_TX_RCLK_LPB_EN_SHFT                                               0x4
#define HWIO_UFS_QSERDES_TX0_LPB_EN_SER_LPB_EN_MUX_BMSK                                               0x8
#define HWIO_UFS_QSERDES_TX0_LPB_EN_SER_LPB_EN_MUX_SHFT                                               0x3
#define HWIO_UFS_QSERDES_TX0_LPB_EN_SER_LPB_EN_BMSK                                                   0x4
#define HWIO_UFS_QSERDES_TX0_LPB_EN_SER_LPB_EN_SHFT                                                   0x2
#define HWIO_UFS_QSERDES_TX0_LPB_EN_PAR_LPB_EN_BMSK                                                   0x2
#define HWIO_UFS_QSERDES_TX0_LPB_EN_PAR_LPB_EN_SHFT                                                   0x1
#define HWIO_UFS_QSERDES_TX0_LPB_EN_RCLK_LPB_EN_BMSK                                                  0x1
#define HWIO_UFS_QSERDES_TX0_LPB_EN_RCLK_LPB_EN_SHFT                                                  0x0

#define HWIO_UFS_QSERDES_TX0_RES_CODE_ADDR                                                     (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_TX0_RES_CODE_RMSK                                                           0x1f
#define HWIO_UFS_QSERDES_TX0_RES_CODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_RES_CODE_ADDR, HWIO_UFS_QSERDES_TX0_RES_CODE_RMSK)
#define HWIO_UFS_QSERDES_TX0_RES_CODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_RES_CODE_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_RES_CODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_RES_CODE_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_RES_CODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_RES_CODE_ADDR,m,v,HWIO_UFS_QSERDES_TX0_RES_CODE_IN)
#define HWIO_UFS_QSERDES_TX0_RES_CODE_RES_CODE_MUX_BMSK                                              0x10
#define HWIO_UFS_QSERDES_TX0_RES_CODE_RES_CODE_MUX_SHFT                                               0x4
#define HWIO_UFS_QSERDES_TX0_RES_CODE_RES_CODE_BMSK                                                   0xf
#define HWIO_UFS_QSERDES_TX0_RES_CODE_RES_CODE_SHFT                                                   0x0

#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_ADDR                                                 (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_ADDR, HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_RMSK)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_ADDR,m,v,HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_IN)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_PERL_LENGTH1_BMSK                                          0xff
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_PERL_LENGTH1_SHFT                                           0x0

#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_ADDR                                                 (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_ADDR, HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_RMSK)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_ADDR,m,v,HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_IN)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_PERL_LENGTH2_BMSK                                          0xff
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_PERL_LENGTH2_SHFT                                           0x0

#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_ADDR, HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_RMSK)
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_ADDR,m,v,HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_IN)
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_DEBUGBUS_SEL_BMSK                                     0xf0
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_DEBUGBUS_SEL_SHFT                                      0x4
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_MUX_BMSK                                0x8
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_MUX_SHFT                                0x3
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_BMSK                                    0x4
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_SHFT                                    0x2
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_EN_MUX_BMSK                                 0x2
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_EN_MUX_SHFT                                 0x1
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_EN_BMSK                                     0x1
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_SERDES_BYP_EN_SHFT                                     0x0

#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR                                  (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_RMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR, HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_RMSK)
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_IN)
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_MUX_BMSK                        0x80
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_MUX_SHFT                         0x7
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_BMSK                            0x40
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_SHFT                             0x6
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_MUX_BMSK                           0x20
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_MUX_SHFT                            0x5
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_BMSK                               0x10
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_SHFT                                0x4
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_MUX_BMSK                 0x8
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_MUX_SHFT                 0x3
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_BMSK                     0x4
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_SHFT                     0x2
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_MUX_BMSK                               0x2
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_MUX_SHFT                               0x1
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_BMSK                                   0x1
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_SHFT                                   0x0

#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_RMSK                                         0x3f
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR, HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_RMSK)
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_IN)
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_MUX_BMSK                            0x20
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_MUX_SHFT                             0x5
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_BMSK                                0x10
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_SHFT                                 0x4
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_MUX_BMSK                              0x8
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_MUX_SHFT                              0x3
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_BMSK                                  0x4
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_SHFT                                  0x2
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_MUX_BMSK                        0x2
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_MUX_SHFT                        0x1
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_BMSK                            0x1
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_SHFT                            0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_BIST_PATTERN1_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_BIST_PATTERN1_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_BIST_PATTERN2_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_BIST_PATTERN2_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_BIST_PATTERN3_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_BIST_PATTERN3_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_BIST_PATTERN4_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_BIST_PATTERN4_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_BIST_PATTERN5_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_BIST_PATTERN5_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_BIST_PATTERN6_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_BIST_PATTERN6_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_BIST_PATTERN7_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_BIST_PATTERN7_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_ADDR, HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_ADDR,m,v,HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_IN)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_BIST_PATTERN8_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_BIST_PATTERN8_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX0_LANE_MODE_ADDR                                                    (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_RMSK                                                          0xff
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_LANE_MODE_ADDR, HWIO_UFS_QSERDES_TX0_LANE_MODE_RMSK)
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_LANE_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_LANE_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_LANE_MODE_ADDR,m,v,HWIO_UFS_QSERDES_TX0_LANE_MODE_IN)
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_LANE_MODE_BMSK                                                0xff
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_LANE_MODE_SHFT                                                 0x0

#define HWIO_UFS_QSERDES_TX0_ATB_SEL_ADDR                                                      (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_RMSK                                                            0x3f
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_ATB_SEL_ADDR, HWIO_UFS_QSERDES_TX0_ATB_SEL_RMSK)
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_ATB_SEL_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_ATB_SEL_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_ATB_SEL_ADDR,m,v,HWIO_UFS_QSERDES_TX0_ATB_SEL_IN)
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_ATB_SEL_BMSK                                                    0x3f
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_ATB_SEL_SHFT                                                     0x0

#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_ADDR                                               (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_RMSK                                                      0x7
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_ADDR, HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_RMSK)
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_ADDR,m,v,HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_IN)
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_REC_DETECT_LVL_BMSK                                       0x7
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_REC_DETECT_LVL_SHFT                                       0x0

#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED1_ADDR, HWIO_UFS_QSERDES_TX0_PRBS_SEED1_RMSK)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED1_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_PRBS_SEED1_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_PRBS_SEED1_ADDR,m,v,HWIO_UFS_QSERDES_TX0_PRBS_SEED1_IN)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_PRBS_SEED1_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_PRBS_SEED1_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED2_ADDR, HWIO_UFS_QSERDES_TX0_PRBS_SEED2_RMSK)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED2_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_PRBS_SEED2_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_PRBS_SEED2_ADDR,m,v,HWIO_UFS_QSERDES_TX0_PRBS_SEED2_IN)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_PRBS_SEED2_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_PRBS_SEED2_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED3_ADDR, HWIO_UFS_QSERDES_TX0_PRBS_SEED3_RMSK)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED3_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_PRBS_SEED3_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_PRBS_SEED3_ADDR,m,v,HWIO_UFS_QSERDES_TX0_PRBS_SEED3_IN)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_PRBS_SEED3_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_PRBS_SEED3_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED4_ADDR, HWIO_UFS_QSERDES_TX0_PRBS_SEED4_RMSK)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_PRBS_SEED4_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_PRBS_SEED4_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_PRBS_SEED4_ADDR,m,v,HWIO_UFS_QSERDES_TX0_PRBS_SEED4_IN)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_PRBS_SEED4_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_PRBS_SEED4_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX0_RESET_GEN_ADDR                                                    (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_RMSK                                                          0x7f
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_RESET_GEN_ADDR, HWIO_UFS_QSERDES_TX0_RESET_GEN_RMSK)
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_RESET_GEN_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_RESET_GEN_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_RESET_GEN_ADDR,m,v,HWIO_UFS_QSERDES_TX0_RESET_GEN_IN)
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_RESET_GEN_BMSK                                                0x7f
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_RESET_GEN_SHFT                                                 0x0

#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR                                             (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_RMSK                                                    0x3
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR, HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_RMSK)
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_IN)
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_EMP_EN_MUX_BMSK                                         0x2
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_EMP_EN_MUX_SHFT                                         0x1
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_EMP_EN_BMSK                                             0x1
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_EMP_EN_SHFT                                             0x0

#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_RMSK                                                   0x7
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_ADDR, HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_RMSK)
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_ADDR,m,v,HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_IN)
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_TXINTERFACE_MODE_BMSK                                  0x7
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_TXINTERFACE_MODE_SHFT                                  0x0

#define HWIO_UFS_QSERDES_TX0_BIST_STATUS_ADDR                                                  (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_TX0_BIST_STATUS_RMSK                                                         0x7
#define HWIO_UFS_QSERDES_TX0_BIST_STATUS_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_STATUS_ADDR, HWIO_UFS_QSERDES_TX0_BIST_STATUS_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_STATUS_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_STATUS_BIST_STATUS_BMSK                                             0x7
#define HWIO_UFS_QSERDES_TX0_BIST_STATUS_BIST_STATUS_SHFT                                             0x0

#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_ADDR, HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_BIST_ERROR_COUNT1_BMSK                                0xff
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_BIST_ERROR_COUNT1_SHFT                                 0x0

#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_ADDR, HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_RMSK)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_ADDR, m)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_BIST_ERROR_COUNT2_BMSK                                0xff
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_BIST_ERROR_COUNT2_SHFT                                 0x0

/*----------------------------------------------------------------------------
 * MODULE: UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX
 *--------------------------------------------------------------------------*/

#define UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE                                            (UFS_UFS_REGS_BASE      + 0x00007500)

#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_ADDR                                             (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_RMSK                                                   0x7f
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_ADDR, HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_BIST_LANE_NUMBER_BMSK                                  0x60
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_BIST_LANE_NUMBER_SHFT                                   0x5
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_BISTMODE_BMSK                                          0x1f
#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_BISTMODE_SHFT                                           0x0

#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_RMSK                                                       0x3
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_ADDR, HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_RMSK)
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_ADDR,m,v,HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_IN)
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_CLKBUF_EN_MUX_BMSK                                         0x2
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_CLKBUF_EN_MUX_SHFT                                         0x1
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_CLKBUF_EN_BMSK                                             0x1
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_CLKBUF_EN_SHFT                                             0x0

#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR                                             (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_RMSK                                                   0x3f
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR, HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_RMSK)
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR,m,v,HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_IN)
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_MUX_BMSK                              0x20
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_MUX_SHFT                               0x5
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_BMSK                                  0x1f
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_TX_EMP_POST1_LVL_SHFT                                   0x0

#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_RMSK                                                         0x1f
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_ADDR, HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_RMSK)
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_ADDR,m,v,HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_IN)
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_TX_DRV_LVL_MUX_BMSK                                          0x10
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_TX_DRV_LVL_MUX_SHFT                                           0x4
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_TX_DRV_LVL_BMSK                                               0xf
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_TX_DRV_LVL_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_ADDR                                               (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_RMSK                                                      0x3
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_ADDR, HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_RMSK)
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_IN)
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_RESET_TSYNC_EN_MUX_BMSK                                   0x2
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_RESET_TSYNC_EN_MUX_SHFT                                   0x1
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_RESET_TSYNC_EN_BMSK                                       0x1
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_RESET_TSYNC_EN_SHFT                                       0x0

#define HWIO_UFS_QSERDES_TX1_LPB_EN_ADDR                                                       (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_TX1_LPB_EN_RMSK                                                             0x7f
#define HWIO_UFS_QSERDES_TX1_LPB_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_LPB_EN_ADDR, HWIO_UFS_QSERDES_TX1_LPB_EN_RMSK)
#define HWIO_UFS_QSERDES_TX1_LPB_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_LPB_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_LPB_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_LPB_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_LPB_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_LPB_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX1_LPB_EN_IN)
#define HWIO_UFS_QSERDES_TX1_LPB_EN_LINE_LPB_EN_MUX_BMSK                                             0x40
#define HWIO_UFS_QSERDES_TX1_LPB_EN_LINE_LPB_EN_MUX_SHFT                                              0x6
#define HWIO_UFS_QSERDES_TX1_LPB_EN_LINE_LPB_EN_BMSK                                                 0x20
#define HWIO_UFS_QSERDES_TX1_LPB_EN_LINE_LPB_EN_SHFT                                                  0x5
#define HWIO_UFS_QSERDES_TX1_LPB_EN_TX_RCLK_LPB_EN_BMSK                                              0x10
#define HWIO_UFS_QSERDES_TX1_LPB_EN_TX_RCLK_LPB_EN_SHFT                                               0x4
#define HWIO_UFS_QSERDES_TX1_LPB_EN_SER_LPB_EN_MUX_BMSK                                               0x8
#define HWIO_UFS_QSERDES_TX1_LPB_EN_SER_LPB_EN_MUX_SHFT                                               0x3
#define HWIO_UFS_QSERDES_TX1_LPB_EN_SER_LPB_EN_BMSK                                                   0x4
#define HWIO_UFS_QSERDES_TX1_LPB_EN_SER_LPB_EN_SHFT                                                   0x2
#define HWIO_UFS_QSERDES_TX1_LPB_EN_PAR_LPB_EN_BMSK                                                   0x2
#define HWIO_UFS_QSERDES_TX1_LPB_EN_PAR_LPB_EN_SHFT                                                   0x1
#define HWIO_UFS_QSERDES_TX1_LPB_EN_RCLK_LPB_EN_BMSK                                                  0x1
#define HWIO_UFS_QSERDES_TX1_LPB_EN_RCLK_LPB_EN_SHFT                                                  0x0

#define HWIO_UFS_QSERDES_TX1_RES_CODE_ADDR                                                     (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_TX1_RES_CODE_RMSK                                                           0x1f
#define HWIO_UFS_QSERDES_TX1_RES_CODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_RES_CODE_ADDR, HWIO_UFS_QSERDES_TX1_RES_CODE_RMSK)
#define HWIO_UFS_QSERDES_TX1_RES_CODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_RES_CODE_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_RES_CODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_RES_CODE_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_RES_CODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_RES_CODE_ADDR,m,v,HWIO_UFS_QSERDES_TX1_RES_CODE_IN)
#define HWIO_UFS_QSERDES_TX1_RES_CODE_RES_CODE_MUX_BMSK                                              0x10
#define HWIO_UFS_QSERDES_TX1_RES_CODE_RES_CODE_MUX_SHFT                                               0x4
#define HWIO_UFS_QSERDES_TX1_RES_CODE_RES_CODE_BMSK                                                   0xf
#define HWIO_UFS_QSERDES_TX1_RES_CODE_RES_CODE_SHFT                                                   0x0

#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_ADDR                                                 (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_ADDR, HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_RMSK)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_ADDR,m,v,HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_IN)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_PERL_LENGTH1_BMSK                                          0xff
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_PERL_LENGTH1_SHFT                                           0x0

#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_ADDR                                                 (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_RMSK                                                       0xff
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_ADDR, HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_RMSK)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_ADDR,m,v,HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_IN)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_PERL_LENGTH2_BMSK                                          0xff
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_PERL_LENGTH2_SHFT                                           0x0

#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_ADDR, HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_RMSK)
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_ADDR,m,v,HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_IN)
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_DEBUGBUS_SEL_BMSK                                     0xf0
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_DEBUGBUS_SEL_SHFT                                      0x4
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_MUX_BMSK                                0x8
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_MUX_SHFT                                0x3
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_BMSK                                    0x4
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_OUT_SHFT                                    0x2
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_EN_MUX_BMSK                                 0x2
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_EN_MUX_SHFT                                 0x1
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_EN_BMSK                                     0x1
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_SERDES_BYP_EN_SHFT                                     0x0

#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR                                  (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_RMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR, HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_RMSK)
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_IN)
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_MUX_BMSK                        0x80
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_MUX_SHFT                         0x7
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_BMSK                            0x40
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_DATA_INV_SHFT                             0x6
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_MUX_BMSK                           0x20
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_MUX_SHFT                            0x5
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_BMSK                               0x10
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_HIGHZ_SHFT                                0x4
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_MUX_BMSK                 0x8
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_MUX_SHFT                 0x3
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_BMSK                     0x4
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TRANSCEIVER_BIAS_EN_SHFT                     0x2
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_MUX_BMSK                               0x2
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_MUX_SHFT                               0x1
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_BMSK                                   0x1
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_TX_EN_SHFT                                   0x0

#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_RMSK                                         0x3f
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR, HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_RMSK)
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_IN)
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_MUX_BMSK                            0x20
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_MUX_SHFT                             0x5
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_BMSK                                0x10
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_PAR_RATE_SHFT                                 0x4
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_MUX_BMSK                              0x8
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_MUX_SHFT                              0x3
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_BMSK                                  0x4
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_IDLE_EN_SHFT                                  0x2
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_MUX_BMSK                        0x2
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_MUX_SHFT                        0x1
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_BMSK                            0x1
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_REC_DETECT_EN_SHFT                            0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_BIST_PATTERN1_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_BIST_PATTERN1_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_BIST_PATTERN2_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_BIST_PATTERN2_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_BIST_PATTERN3_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_BIST_PATTERN3_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_BIST_PATTERN4_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_BIST_PATTERN4_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_BIST_PATTERN5_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_BIST_PATTERN5_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_BIST_PATTERN6_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_BIST_PATTERN6_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_BIST_PATTERN7_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_BIST_PATTERN7_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_RMSK                                                      0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_ADDR, HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_ADDR,m,v,HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_IN)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_BIST_PATTERN8_BMSK                                        0xff
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_BIST_PATTERN8_SHFT                                         0x0

#define HWIO_UFS_QSERDES_TX1_LANE_MODE_ADDR                                                    (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_RMSK                                                          0xff
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_LANE_MODE_ADDR, HWIO_UFS_QSERDES_TX1_LANE_MODE_RMSK)
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_LANE_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_LANE_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_LANE_MODE_ADDR,m,v,HWIO_UFS_QSERDES_TX1_LANE_MODE_IN)
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_LANE_MODE_BMSK                                                0xff
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_LANE_MODE_SHFT                                                 0x0

#define HWIO_UFS_QSERDES_TX1_ATB_SEL_ADDR                                                      (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_RMSK                                                            0x3f
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_ATB_SEL_ADDR, HWIO_UFS_QSERDES_TX1_ATB_SEL_RMSK)
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_ATB_SEL_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_ATB_SEL_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_ATB_SEL_ADDR,m,v,HWIO_UFS_QSERDES_TX1_ATB_SEL_IN)
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_ATB_SEL_BMSK                                                    0x3f
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_ATB_SEL_SHFT                                                     0x0

#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_ADDR                                               (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_RMSK                                                      0x7
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_ADDR, HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_RMSK)
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_ADDR,m,v,HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_IN)
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_REC_DETECT_LVL_BMSK                                       0x7
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_REC_DETECT_LVL_SHFT                                       0x0

#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED1_ADDR, HWIO_UFS_QSERDES_TX1_PRBS_SEED1_RMSK)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED1_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_PRBS_SEED1_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_PRBS_SEED1_ADDR,m,v,HWIO_UFS_QSERDES_TX1_PRBS_SEED1_IN)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_PRBS_SEED1_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_PRBS_SEED1_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED2_ADDR, HWIO_UFS_QSERDES_TX1_PRBS_SEED2_RMSK)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED2_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_PRBS_SEED2_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_PRBS_SEED2_ADDR,m,v,HWIO_UFS_QSERDES_TX1_PRBS_SEED2_IN)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_PRBS_SEED2_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_PRBS_SEED2_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED3_ADDR, HWIO_UFS_QSERDES_TX1_PRBS_SEED3_RMSK)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED3_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_PRBS_SEED3_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_PRBS_SEED3_ADDR,m,v,HWIO_UFS_QSERDES_TX1_PRBS_SEED3_IN)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_PRBS_SEED3_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_PRBS_SEED3_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_RMSK                                                         0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED4_ADDR, HWIO_UFS_QSERDES_TX1_PRBS_SEED4_RMSK)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_PRBS_SEED4_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_PRBS_SEED4_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_PRBS_SEED4_ADDR,m,v,HWIO_UFS_QSERDES_TX1_PRBS_SEED4_IN)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_PRBS_SEED4_BMSK                                              0xff
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_PRBS_SEED4_SHFT                                               0x0

#define HWIO_UFS_QSERDES_TX1_RESET_GEN_ADDR                                                    (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_RMSK                                                          0x7f
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_RESET_GEN_ADDR, HWIO_UFS_QSERDES_TX1_RESET_GEN_RMSK)
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_RESET_GEN_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_RESET_GEN_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_RESET_GEN_ADDR,m,v,HWIO_UFS_QSERDES_TX1_RESET_GEN_IN)
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_RESET_GEN_BMSK                                                0x7f
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_RESET_GEN_SHFT                                                 0x0

#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR                                             (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_RMSK                                                    0x3
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR, HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_RMSK)
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR,m,v,HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_IN)
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_EMP_EN_MUX_BMSK                                         0x2
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_EMP_EN_MUX_SHFT                                         0x1
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_EMP_EN_BMSK                                             0x1
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_EMP_EN_SHFT                                             0x0

#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_RMSK                                                   0x7
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_ADDR, HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_RMSK)
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_OUT(v)      \
        out_dword(HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_ADDR,v)
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_ADDR,m,v,HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_IN)
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_TXINTERFACE_MODE_BMSK                                  0x7
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_TXINTERFACE_MODE_SHFT                                  0x0

#define HWIO_UFS_QSERDES_TX1_BIST_STATUS_ADDR                                                  (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_TX1_BIST_STATUS_RMSK                                                         0x7
#define HWIO_UFS_QSERDES_TX1_BIST_STATUS_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_STATUS_ADDR, HWIO_UFS_QSERDES_TX1_BIST_STATUS_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_STATUS_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_STATUS_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_STATUS_BIST_STATUS_BMSK                                             0x7
#define HWIO_UFS_QSERDES_TX1_BIST_STATUS_BIST_STATUS_SHFT                                             0x0

#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_ADDR, HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_BIST_ERROR_COUNT1_BMSK                                0xff
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_BIST_ERROR_COUNT1_SHFT                                 0x0

#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_RMSK                                                  0xff
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_IN          \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_ADDR, HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_RMSK)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_INM(m)      \
        in_dword_masked(HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_ADDR, m)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_BIST_ERROR_COUNT2_BMSK                                0xff
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_BIST_ERROR_COUNT2_SHFT                                 0x0

/*----------------------------------------------------------------------------
 * MODULE: UFS
 *--------------------------------------------------------------------------*/

#define UFS_REG_BASE                                                                   (UFS_UFS_REGS_BASE      + 0x00004000)

#define HWIO_UFS_CAP_ADDR                                                              (UFS_REG_BASE      + 0x00000000)
#define HWIO_UFS_CAP_RMSK                                                               0x707001f
#define HWIO_UFS_CAP_IN          \
        in_dword_masked(HWIO_UFS_CAP_ADDR, HWIO_UFS_CAP_RMSK)
#define HWIO_UFS_CAP_INM(m)      \
        in_dword_masked(HWIO_UFS_CAP_ADDR, m)
#define HWIO_UFS_CAP_UICDMETMS_BMSK                                                     0x4000000
#define HWIO_UFS_CAP_UICDMETMS_SHFT                                                          0x1a
#define HWIO_UFS_CAP_OODDS_BMSK                                                         0x2000000
#define HWIO_UFS_CAP_OODDS_SHFT                                                              0x19
#define HWIO_UFS_CAP_CAP_64AS_BMSK                                                      0x1000000
#define HWIO_UFS_CAP_CAP_64AS_SHFT                                                           0x18
#define HWIO_UFS_CAP_NUTMRS_BMSK                                                          0x70000
#define HWIO_UFS_CAP_NUTMRS_SHFT                                                             0x10
#define HWIO_UFS_CAP_NUTRS_BMSK                                                              0x1f
#define HWIO_UFS_CAP_NUTRS_SHFT                                                               0x0

#define HWIO_UFS_VER_ADDR                                                              (UFS_REG_BASE      + 0x00000008)
#define HWIO_UFS_VER_RMSK                                                              0xffffffff
#define HWIO_UFS_VER_IN          \
        in_dword_masked(HWIO_UFS_VER_ADDR, HWIO_UFS_VER_RMSK)
#define HWIO_UFS_VER_INM(m)      \
        in_dword_masked(HWIO_UFS_VER_ADDR, m)
#define HWIO_UFS_VER_MJR_BMSK                                                          0xffff0000
#define HWIO_UFS_VER_MJR_SHFT                                                                0x10
#define HWIO_UFS_VER_MNR_BMSK                                                              0xffff
#define HWIO_UFS_VER_MNR_SHFT                                                                 0x0

#define HWIO_UFS_HCDDID_ADDR                                                           (UFS_REG_BASE      + 0x00000010)
#define HWIO_UFS_HCDDID_RMSK                                                           0xff00ffff
#define HWIO_UFS_HCDDID_IN          \
        in_dword_masked(HWIO_UFS_HCDDID_ADDR, HWIO_UFS_HCDDID_RMSK)
#define HWIO_UFS_HCDDID_INM(m)      \
        in_dword_masked(HWIO_UFS_HCDDID_ADDR, m)
#define HWIO_UFS_HCDDID_HCDID_BMSK                                                     0xff000000
#define HWIO_UFS_HCDDID_HCDID_SHFT                                                           0x18
#define HWIO_UFS_HCDDID_DC_BMSK                                                            0xffff
#define HWIO_UFS_HCDDID_DC_SHFT                                                               0x0

#define HWIO_UFS_HCPMID_ADDR                                                           (UFS_REG_BASE      + 0x00000014)
#define HWIO_UFS_HCPMID_RMSK                                                           0xffffffff
#define HWIO_UFS_HCPMID_IN          \
        in_dword_masked(HWIO_UFS_HCPMID_ADDR, HWIO_UFS_HCPMID_RMSK)
#define HWIO_UFS_HCPMID_INM(m)      \
        in_dword_masked(HWIO_UFS_HCPMID_ADDR, m)
#define HWIO_UFS_HCPMID_PID_BMSK                                                       0xffff0000
#define HWIO_UFS_HCPMID_PID_SHFT                                                             0x10
#define HWIO_UFS_HCPMID_MID_BMSK                                                           0xffff
#define HWIO_UFS_HCPMID_MID_SHFT                                                              0x0

#define HWIO_UFS_IS_ADDR                                                               (UFS_REG_BASE      + 0x00000020)
#define HWIO_UFS_IS_RMSK                                                               0xe0031fff
#define HWIO_UFS_IS_IN          \
        in_dword_masked(HWIO_UFS_IS_ADDR, HWIO_UFS_IS_RMSK)
#define HWIO_UFS_IS_INM(m)      \
        in_dword_masked(HWIO_UFS_IS_ADDR, m)
#define HWIO_UFS_IS_OUT(v)      \
        out_dword(HWIO_UFS_IS_ADDR,v)
#define HWIO_UFS_IS_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_IS_ADDR,m,v,HWIO_UFS_IS_IN)
#define HWIO_UFS_IS_TFRD_BMSK                                                          0x80000000
#define HWIO_UFS_IS_TFRD_SHFT                                                                0x1f
#define HWIO_UFS_IS_TFTD_BMSK                                                          0x40000000
#define HWIO_UFS_IS_TFTD_SHFT                                                                0x1e
#define HWIO_UFS_IS_TFEI_BMSK                                                          0x20000000
#define HWIO_UFS_IS_TFEI_SHFT                                                                0x1d
#define HWIO_UFS_IS_SBFES_BMSK                                                            0x20000
#define HWIO_UFS_IS_SBFES_SHFT                                                               0x11
#define HWIO_UFS_IS_HCFES_BMSK                                                            0x10000
#define HWIO_UFS_IS_HCFES_SHFT                                                               0x10
#define HWIO_UFS_IS_UTPES_BMSK                                                             0x1000
#define HWIO_UFS_IS_UTPES_SHFT                                                                0xc
#define HWIO_UFS_IS_DFES_BMSK                                                               0x800
#define HWIO_UFS_IS_DFES_SHFT                                                                 0xb
#define HWIO_UFS_IS_UCCS_BMSK                                                               0x400
#define HWIO_UFS_IS_UCCS_SHFT                                                                 0xa
#define HWIO_UFS_IS_UTMRCS_BMSK                                                             0x200
#define HWIO_UFS_IS_UTMRCS_SHFT                                                               0x9
#define HWIO_UFS_IS_ULSS_BMSK                                                               0x100
#define HWIO_UFS_IS_ULSS_SHFT                                                                 0x8
#define HWIO_UFS_IS_ULLS_BMSK                                                                0x80
#define HWIO_UFS_IS_ULLS_SHFT                                                                 0x7
#define HWIO_UFS_IS_UHES_BMSK                                                                0x40
#define HWIO_UFS_IS_UHES_SHFT                                                                 0x6
#define HWIO_UFS_IS_UHXS_BMSK                                                                0x20
#define HWIO_UFS_IS_UHXS_SHFT                                                                 0x5
#define HWIO_UFS_IS_UPMS_BMSK                                                                0x10
#define HWIO_UFS_IS_UPMS_SHFT                                                                 0x4
#define HWIO_UFS_IS_UTMS_BMSK                                                                 0x8
#define HWIO_UFS_IS_UTMS_SHFT                                                                 0x3
#define HWIO_UFS_IS_UE_BMSK                                                                   0x4
#define HWIO_UFS_IS_UE_SHFT                                                                   0x2
#define HWIO_UFS_IS_UDEPRI_BMSK                                                               0x2
#define HWIO_UFS_IS_UDEPRI_SHFT                                                               0x1
#define HWIO_UFS_IS_UTRCS_BMSK                                                                0x1
#define HWIO_UFS_IS_UTRCS_SHFT                                                                0x0

#define HWIO_UFS_IE_ADDR                                                               (UFS_REG_BASE      + 0x00000024)
#define HWIO_UFS_IE_RMSK                                                               0xe0031fff
#define HWIO_UFS_IE_IN          \
        in_dword_masked(HWIO_UFS_IE_ADDR, HWIO_UFS_IE_RMSK)
#define HWIO_UFS_IE_INM(m)      \
        in_dword_masked(HWIO_UFS_IE_ADDR, m)
#define HWIO_UFS_IE_OUT(v)      \
        out_dword(HWIO_UFS_IE_ADDR,v)
#define HWIO_UFS_IE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_IE_ADDR,m,v,HWIO_UFS_IE_IN)
#define HWIO_UFS_IE_TFRDE_BMSK                                                         0x80000000
#define HWIO_UFS_IE_TFRDE_SHFT                                                               0x1f
#define HWIO_UFS_IE_TFTDE_BMSK                                                         0x40000000
#define HWIO_UFS_IE_TFTDE_SHFT                                                               0x1e
#define HWIO_UFS_IE_TFEIE_BMSK                                                         0x20000000
#define HWIO_UFS_IE_TFEIE_SHFT                                                               0x1d
#define HWIO_UFS_IE_SBFEE_BMSK                                                            0x20000
#define HWIO_UFS_IE_SBFEE_SHFT                                                               0x11
#define HWIO_UFS_IE_HCFEE_BMSK                                                            0x10000
#define HWIO_UFS_IE_HCFEE_SHFT                                                               0x10
#define HWIO_UFS_IE_UTPEE_BMSK                                                             0x1000
#define HWIO_UFS_IE_UTPEE_SHFT                                                                0xc
#define HWIO_UFS_IE_DFEE_BMSK                                                               0x800
#define HWIO_UFS_IE_DFEE_SHFT                                                                 0xb
#define HWIO_UFS_IE_UCCE_BMSK                                                               0x400
#define HWIO_UFS_IE_UCCE_SHFT                                                                 0xa
#define HWIO_UFS_IE_UTMRCE_BMSK                                                             0x200
#define HWIO_UFS_IE_UTMRCE_SHFT                                                               0x9
#define HWIO_UFS_IE_ULSSE_BMSK                                                              0x100
#define HWIO_UFS_IE_ULSSE_SHFT                                                                0x8
#define HWIO_UFS_IE_ULLSE_BMSK                                                               0x80
#define HWIO_UFS_IE_ULLSE_SHFT                                                                0x7
#define HWIO_UFS_IE_UHESE_BMSK                                                               0x40
#define HWIO_UFS_IE_UHESE_SHFT                                                                0x6
#define HWIO_UFS_IE_UHXSE_BMSK                                                               0x20
#define HWIO_UFS_IE_UHXSE_SHFT                                                                0x5
#define HWIO_UFS_IE_UPMSE_BMSK                                                               0x10
#define HWIO_UFS_IE_UPMSE_SHFT                                                                0x4
#define HWIO_UFS_IE_UTMSE_BMSK                                                                0x8
#define HWIO_UFS_IE_UTMSE_SHFT                                                                0x3
#define HWIO_UFS_IE_UEE_BMSK                                                                  0x4
#define HWIO_UFS_IE_UEE_SHFT                                                                  0x2
#define HWIO_UFS_IE_UDEPRIU_BMSK                                                              0x2
#define HWIO_UFS_IE_UDEPRIU_SHFT                                                              0x1
#define HWIO_UFS_IE_UTRCE_BMSK                                                                0x1
#define HWIO_UFS_IE_UTRCE_SHFT                                                                0x0

#define HWIO_UFS_HCS_ADDR                                                              (UFS_REG_BASE      + 0x00000030)
#define HWIO_UFS_HCS_RMSK                                                              0xfffff70f
#define HWIO_UFS_HCS_IN          \
        in_dword_masked(HWIO_UFS_HCS_ADDR, HWIO_UFS_HCS_RMSK)
#define HWIO_UFS_HCS_INM(m)      \
        in_dword_masked(HWIO_UFS_HCS_ADDR, m)
#define HWIO_UFS_HCS_TLUNUTPE_BMSK                                                     0xff000000
#define HWIO_UFS_HCS_TLUNUTPE_SHFT                                                           0x18
#define HWIO_UFS_HCS_TTAGUTPE_BMSK                                                       0xff0000
#define HWIO_UFS_HCS_TTAGUTPE_SHFT                                                           0x10
#define HWIO_UFS_HCS_UTPEC_BMSK                                                            0xf000
#define HWIO_UFS_HCS_UTPEC_SHFT                                                               0xc
#define HWIO_UFS_HCS_UPMCRS_BMSK                                                            0x700
#define HWIO_UFS_HCS_UPMCRS_SHFT                                                              0x8
#define HWIO_UFS_HCS_UCRDY_BMSK                                                               0x8
#define HWIO_UFS_HCS_UCRDY_SHFT                                                               0x3
#define HWIO_UFS_HCS_UTMRLRDY_BMSK                                                            0x4
#define HWIO_UFS_HCS_UTMRLRDY_SHFT                                                            0x2
#define HWIO_UFS_HCS_UTRLRDY_BMSK                                                             0x2
#define HWIO_UFS_HCS_UTRLRDY_SHFT                                                             0x1
#define HWIO_UFS_HCS_DP_BMSK                                                                  0x1
#define HWIO_UFS_HCS_DP_SHFT                                                                  0x0

#define HWIO_UFS_HCE_ADDR                                                              (UFS_REG_BASE      + 0x00000034)
#define HWIO_UFS_HCE_RMSK                                                                     0x1
#define HWIO_UFS_HCE_IN          \
        in_dword_masked(HWIO_UFS_HCE_ADDR, HWIO_UFS_HCE_RMSK)
#define HWIO_UFS_HCE_INM(m)      \
        in_dword_masked(HWIO_UFS_HCE_ADDR, m)
#define HWIO_UFS_HCE_OUT(v)      \
        out_dword(HWIO_UFS_HCE_ADDR,v)
#define HWIO_UFS_HCE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_HCE_ADDR,m,v,HWIO_UFS_HCE_IN)
#define HWIO_UFS_HCE_HCE_BMSK                                                                 0x1
#define HWIO_UFS_HCE_HCE_SHFT                                                                 0x0

#define HWIO_UFS_UECPA_ADDR                                                            (UFS_REG_BASE      + 0x00000038)
#define HWIO_UFS_UECPA_RMSK                                                            0x8000001f
#define HWIO_UFS_UECPA_IN          \
        in_dword_masked(HWIO_UFS_UECPA_ADDR, HWIO_UFS_UECPA_RMSK)
#define HWIO_UFS_UECPA_INM(m)      \
        in_dword_masked(HWIO_UFS_UECPA_ADDR, m)
#define HWIO_UFS_UECPA_ERR_BMSK                                                        0x80000000
#define HWIO_UFS_UECPA_ERR_SHFT                                                              0x1f
#define HWIO_UFS_UECPA_EC_BMSK                                                               0x1f
#define HWIO_UFS_UECPA_EC_SHFT                                                                0x0

#define HWIO_UFS_UECDL_ADDR                                                            (UFS_REG_BASE      + 0x0000003c)
#define HWIO_UFS_UECDL_RMSK                                                            0x80007fff
#define HWIO_UFS_UECDL_IN          \
        in_dword_masked(HWIO_UFS_UECDL_ADDR, HWIO_UFS_UECDL_RMSK)
#define HWIO_UFS_UECDL_INM(m)      \
        in_dword_masked(HWIO_UFS_UECDL_ADDR, m)
#define HWIO_UFS_UECDL_ERR_BMSK                                                        0x80000000
#define HWIO_UFS_UECDL_ERR_SHFT                                                              0x1f
#define HWIO_UFS_UECDL_EC_BMSK                                                             0x7fff
#define HWIO_UFS_UECDL_EC_SHFT                                                                0x0

#define HWIO_UFS_UECN_ADDR                                                             (UFS_REG_BASE      + 0x00000040)
#define HWIO_UFS_UECN_RMSK                                                             0x80000007
#define HWIO_UFS_UECN_IN          \
        in_dword_masked(HWIO_UFS_UECN_ADDR, HWIO_UFS_UECN_RMSK)
#define HWIO_UFS_UECN_INM(m)      \
        in_dword_masked(HWIO_UFS_UECN_ADDR, m)
#define HWIO_UFS_UECN_ERR_BMSK                                                         0x80000000
#define HWIO_UFS_UECN_ERR_SHFT                                                               0x1f
#define HWIO_UFS_UECN_EC_BMSK                                                                 0x7
#define HWIO_UFS_UECN_EC_SHFT                                                                 0x0

#define HWIO_UFS_UECT_ADDR                                                             (UFS_REG_BASE      + 0x00000044)
#define HWIO_UFS_UECT_RMSK                                                             0x8000007f
#define HWIO_UFS_UECT_IN          \
        in_dword_masked(HWIO_UFS_UECT_ADDR, HWIO_UFS_UECT_RMSK)
#define HWIO_UFS_UECT_INM(m)      \
        in_dword_masked(HWIO_UFS_UECT_ADDR, m)
#define HWIO_UFS_UECT_ERR_BMSK                                                         0x80000000
#define HWIO_UFS_UECT_ERR_SHFT                                                               0x1f
#define HWIO_UFS_UECT_EC_BMSK                                                                0x7f
#define HWIO_UFS_UECT_EC_SHFT                                                                 0x0

#define HWIO_UFS_UECDME_ADDR                                                           (UFS_REG_BASE      + 0x00000048)
#define HWIO_UFS_UECDME_RMSK                                                           0x80000001
#define HWIO_UFS_UECDME_IN          \
        in_dword_masked(HWIO_UFS_UECDME_ADDR, HWIO_UFS_UECDME_RMSK)
#define HWIO_UFS_UECDME_INM(m)      \
        in_dword_masked(HWIO_UFS_UECDME_ADDR, m)
#define HWIO_UFS_UECDME_ERR_BMSK                                                       0x80000000
#define HWIO_UFS_UECDME_ERR_SHFT                                                             0x1f
#define HWIO_UFS_UECDME_EC_BMSK                                                               0x1
#define HWIO_UFS_UECDME_EC_SHFT                                                               0x0

#define HWIO_UFS_UTRIACR_ADDR                                                          (UFS_REG_BASE      + 0x0000004c)
#define HWIO_UFS_UTRIACR_RMSK                                                          0x81111fff
#define HWIO_UFS_UTRIACR_IN          \
        in_dword_masked(HWIO_UFS_UTRIACR_ADDR, HWIO_UFS_UTRIACR_RMSK)
#define HWIO_UFS_UTRIACR_INM(m)      \
        in_dword_masked(HWIO_UFS_UTRIACR_ADDR, m)
#define HWIO_UFS_UTRIACR_OUT(v)      \
        out_dword(HWIO_UFS_UTRIACR_ADDR,v)
#define HWIO_UFS_UTRIACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTRIACR_ADDR,m,v,HWIO_UFS_UTRIACR_IN)
#define HWIO_UFS_UTRIACR_IAEN_BMSK                                                     0x80000000
#define HWIO_UFS_UTRIACR_IAEN_SHFT                                                           0x1f
#define HWIO_UFS_UTRIACR_IAPWEN_BMSK                                                    0x1000000
#define HWIO_UFS_UTRIACR_IAPWEN_SHFT                                                         0x18
#define HWIO_UFS_UTRIACR_IASB_BMSK                                                       0x100000
#define HWIO_UFS_UTRIACR_IASB_SHFT                                                           0x14
#define HWIO_UFS_UTRIACR_CTR_BMSK                                                         0x10000
#define HWIO_UFS_UTRIACR_CTR_SHFT                                                            0x10
#define HWIO_UFS_UTRIACR_IACTH_BMSK                                                        0x1f00
#define HWIO_UFS_UTRIACR_IACTH_SHFT                                                           0x8
#define HWIO_UFS_UTRIACR_IATOVAL_BMSK                                                        0xff
#define HWIO_UFS_UTRIACR_IATOVAL_SHFT                                                         0x0

#define HWIO_UFS_UTRLBA_ADDR                                                           (UFS_REG_BASE      + 0x00000050)
#define HWIO_UFS_UTRLBA_RMSK                                                           0xfffffc00
#define HWIO_UFS_UTRLBA_IN          \
        in_dword_masked(HWIO_UFS_UTRLBA_ADDR, HWIO_UFS_UTRLBA_RMSK)
#define HWIO_UFS_UTRLBA_INM(m)      \
        in_dword_masked(HWIO_UFS_UTRLBA_ADDR, m)
#define HWIO_UFS_UTRLBA_OUT(v)      \
        out_dword(HWIO_UFS_UTRLBA_ADDR,v)
#define HWIO_UFS_UTRLBA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTRLBA_ADDR,m,v,HWIO_UFS_UTRLBA_IN)
#define HWIO_UFS_UTRLBA_UTRLBA_BMSK                                                    0xfffffc00
#define HWIO_UFS_UTRLBA_UTRLBA_SHFT                                                           0xa

#define HWIO_UFS_UTRLBAU_ADDR                                                          (UFS_REG_BASE      + 0x00000054)
#define HWIO_UFS_UTRLBAU_RMSK                                                          0xffffffff
#define HWIO_UFS_UTRLBAU_IN          \
        in_dword_masked(HWIO_UFS_UTRLBAU_ADDR, HWIO_UFS_UTRLBAU_RMSK)
#define HWIO_UFS_UTRLBAU_INM(m)      \
        in_dword_masked(HWIO_UFS_UTRLBAU_ADDR, m)
#define HWIO_UFS_UTRLBAU_OUT(v)      \
        out_dword(HWIO_UFS_UTRLBAU_ADDR,v)
#define HWIO_UFS_UTRLBAU_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTRLBAU_ADDR,m,v,HWIO_UFS_UTRLBAU_IN)
#define HWIO_UFS_UTRLBAU_UTRLBAU_BMSK                                                  0xffffffff
#define HWIO_UFS_UTRLBAU_UTRLBAU_SHFT                                                         0x0

#define HWIO_UFS_UTRLDBR_ADDR                                                          (UFS_REG_BASE      + 0x00000058)
#define HWIO_UFS_UTRLDBR_RMSK                                                          0xffffffff
#define HWIO_UFS_UTRLDBR_IN          \
        in_dword_masked(HWIO_UFS_UTRLDBR_ADDR, HWIO_UFS_UTRLDBR_RMSK)
#define HWIO_UFS_UTRLDBR_INM(m)      \
        in_dword_masked(HWIO_UFS_UTRLDBR_ADDR, m)
#define HWIO_UFS_UTRLDBR_OUT(v)      \
        out_dword(HWIO_UFS_UTRLDBR_ADDR,v)
#define HWIO_UFS_UTRLDBR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTRLDBR_ADDR,m,v,HWIO_UFS_UTRLDBR_IN)
#define HWIO_UFS_UTRLDBR_UTRLDBR_BMSK                                                  0xffffffff
#define HWIO_UFS_UTRLDBR_UTRLDBR_SHFT                                                         0x0

#define HWIO_UFS_UTRLCLR_ADDR                                                          (UFS_REG_BASE      + 0x0000005c)
#define HWIO_UFS_UTRLCLR_RMSK                                                          0xffffffff
#define HWIO_UFS_UTRLCLR_OUT(v)      \
        out_dword(HWIO_UFS_UTRLCLR_ADDR,v)
#define HWIO_UFS_UTRLCLR_UTRLCLR_BMSK                                                  0xffffffff
#define HWIO_UFS_UTRLCLR_UTRLCLR_SHFT                                                         0x0

#define HWIO_UFS_UTRLRSR_ADDR                                                          (UFS_REG_BASE      + 0x00000060)
#define HWIO_UFS_UTRLRSR_RMSK                                                                 0x1
#define HWIO_UFS_UTRLRSR_IN          \
        in_dword_masked(HWIO_UFS_UTRLRSR_ADDR, HWIO_UFS_UTRLRSR_RMSK)
#define HWIO_UFS_UTRLRSR_INM(m)      \
        in_dword_masked(HWIO_UFS_UTRLRSR_ADDR, m)
#define HWIO_UFS_UTRLRSR_OUT(v)      \
        out_dword(HWIO_UFS_UTRLRSR_ADDR,v)
#define HWIO_UFS_UTRLRSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTRLRSR_ADDR,m,v,HWIO_UFS_UTRLRSR_IN)
#define HWIO_UFS_UTRLRSR_UTRLRSR_BMSK                                                         0x1
#define HWIO_UFS_UTRLRSR_UTRLRSR_SHFT                                                         0x0

#define HWIO_UFS_UTMRLBA_ADDR                                                          (UFS_REG_BASE      + 0x00000070)
#define HWIO_UFS_UTMRLBA_RMSK                                                          0xfffffc00
#define HWIO_UFS_UTMRLBA_IN          \
        in_dword_masked(HWIO_UFS_UTMRLBA_ADDR, HWIO_UFS_UTMRLBA_RMSK)
#define HWIO_UFS_UTMRLBA_INM(m)      \
        in_dword_masked(HWIO_UFS_UTMRLBA_ADDR, m)
#define HWIO_UFS_UTMRLBA_OUT(v)      \
        out_dword(HWIO_UFS_UTMRLBA_ADDR,v)
#define HWIO_UFS_UTMRLBA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTMRLBA_ADDR,m,v,HWIO_UFS_UTMRLBA_IN)
#define HWIO_UFS_UTMRLBA_UTMRLBA_BMSK                                                  0xfffffc00
#define HWIO_UFS_UTMRLBA_UTMRLBA_SHFT                                                         0xa

#define HWIO_UFS_UTMRLBAU_ADDR                                                         (UFS_REG_BASE      + 0x00000074)
#define HWIO_UFS_UTMRLBAU_RMSK                                                         0xffffffff
#define HWIO_UFS_UTMRLBAU_IN          \
        in_dword_masked(HWIO_UFS_UTMRLBAU_ADDR, HWIO_UFS_UTMRLBAU_RMSK)
#define HWIO_UFS_UTMRLBAU_INM(m)      \
        in_dword_masked(HWIO_UFS_UTMRLBAU_ADDR, m)
#define HWIO_UFS_UTMRLBAU_OUT(v)      \
        out_dword(HWIO_UFS_UTMRLBAU_ADDR,v)
#define HWIO_UFS_UTMRLBAU_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTMRLBAU_ADDR,m,v,HWIO_UFS_UTMRLBAU_IN)
#define HWIO_UFS_UTMRLBAU_UTMRLBAU_BMSK                                                0xffffffff
#define HWIO_UFS_UTMRLBAU_UTMRLBAU_SHFT                                                       0x0

#define HWIO_UFS_UTMRLDBR_ADDR                                                         (UFS_REG_BASE      + 0x00000078)
#define HWIO_UFS_UTMRLDBR_RMSK                                                               0xff
#define HWIO_UFS_UTMRLDBR_IN          \
        in_dword_masked(HWIO_UFS_UTMRLDBR_ADDR, HWIO_UFS_UTMRLDBR_RMSK)
#define HWIO_UFS_UTMRLDBR_INM(m)      \
        in_dword_masked(HWIO_UFS_UTMRLDBR_ADDR, m)
#define HWIO_UFS_UTMRLDBR_OUT(v)      \
        out_dword(HWIO_UFS_UTMRLDBR_ADDR,v)
#define HWIO_UFS_UTMRLDBR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTMRLDBR_ADDR,m,v,HWIO_UFS_UTMRLDBR_IN)
#define HWIO_UFS_UTMRLDBR_UTMRLDBR_BMSK                                                      0xff
#define HWIO_UFS_UTMRLDBR_UTMRLDBR_SHFT                                                       0x0

#define HWIO_UFS_UTMRLCLR_ADDR                                                         (UFS_REG_BASE      + 0x0000007c)
#define HWIO_UFS_UTMRLCLR_RMSK                                                               0xff
#define HWIO_UFS_UTMRLCLR_OUT(v)      \
        out_dword(HWIO_UFS_UTMRLCLR_ADDR,v)
#define HWIO_UFS_UTMRLCLR_UTMRLCLR_BMSK                                                      0xff
#define HWIO_UFS_UTMRLCLR_UTMRLCLR_SHFT                                                       0x0

#define HWIO_UFS_UTMRLRSR_ADDR                                                         (UFS_REG_BASE      + 0x00000080)
#define HWIO_UFS_UTMRLRSR_RMSK                                                                0x1
#define HWIO_UFS_UTMRLRSR_IN          \
        in_dword_masked(HWIO_UFS_UTMRLRSR_ADDR, HWIO_UFS_UTMRLRSR_RMSK)
#define HWIO_UFS_UTMRLRSR_INM(m)      \
        in_dword_masked(HWIO_UFS_UTMRLRSR_ADDR, m)
#define HWIO_UFS_UTMRLRSR_OUT(v)      \
        out_dword(HWIO_UFS_UTMRLRSR_ADDR,v)
#define HWIO_UFS_UTMRLRSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UTMRLRSR_ADDR,m,v,HWIO_UFS_UTMRLRSR_IN)
#define HWIO_UFS_UTMRLRSR_UTMRLRSR_BMSK                                                       0x1
#define HWIO_UFS_UTMRLRSR_UTMRLRSR_SHFT                                                       0x0

#define HWIO_UFS_UICCMD_ADDR                                                           (UFS_REG_BASE      + 0x00000090)
#define HWIO_UFS_UICCMD_RMSK                                                                 0xff
#define HWIO_UFS_UICCMD_IN          \
        in_dword_masked(HWIO_UFS_UICCMD_ADDR, HWIO_UFS_UICCMD_RMSK)
#define HWIO_UFS_UICCMD_INM(m)      \
        in_dword_masked(HWIO_UFS_UICCMD_ADDR, m)
#define HWIO_UFS_UICCMD_OUT(v)      \
        out_dword(HWIO_UFS_UICCMD_ADDR,v)
#define HWIO_UFS_UICCMD_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UICCMD_ADDR,m,v,HWIO_UFS_UICCMD_IN)
#define HWIO_UFS_UICCMD_CMDOP_BMSK                                                           0xff
#define HWIO_UFS_UICCMD_CMDOP_SHFT                                                            0x0

#define HWIO_UFS_UICCMDARG1_ADDR                                                       (UFS_REG_BASE      + 0x00000094)
#define HWIO_UFS_UICCMDARG1_RMSK                                                       0xffffffff
#define HWIO_UFS_UICCMDARG1_IN          \
        in_dword_masked(HWIO_UFS_UICCMDARG1_ADDR, HWIO_UFS_UICCMDARG1_RMSK)
#define HWIO_UFS_UICCMDARG1_INM(m)      \
        in_dword_masked(HWIO_UFS_UICCMDARG1_ADDR, m)
#define HWIO_UFS_UICCMDARG1_OUT(v)      \
        out_dword(HWIO_UFS_UICCMDARG1_ADDR,v)
#define HWIO_UFS_UICCMDARG1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UICCMDARG1_ADDR,m,v,HWIO_UFS_UICCMDARG1_IN)
#define HWIO_UFS_UICCMDARG1_ARG1_BMSK                                                  0xffffffff
#define HWIO_UFS_UICCMDARG1_ARG1_SHFT                                                         0x0

#define HWIO_UFS_UICCMDARG2_ADDR                                                       (UFS_REG_BASE      + 0x00000098)
#define HWIO_UFS_UICCMDARG2_RMSK                                                         0xff00ff
#define HWIO_UFS_UICCMDARG2_IN          \
        in_dword_masked(HWIO_UFS_UICCMDARG2_ADDR, HWIO_UFS_UICCMDARG2_RMSK)
#define HWIO_UFS_UICCMDARG2_INM(m)      \
        in_dword_masked(HWIO_UFS_UICCMDARG2_ADDR, m)
#define HWIO_UFS_UICCMDARG2_OUT(v)      \
        out_dword(HWIO_UFS_UICCMDARG2_ADDR,v)
#define HWIO_UFS_UICCMDARG2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UICCMDARG2_ADDR,m,v,HWIO_UFS_UICCMDARG2_IN)
#define HWIO_UFS_UICCMDARG2_ARG2_ATTR_SET_TYPE_BMSK                                      0xff0000
#define HWIO_UFS_UICCMDARG2_ARG2_ATTR_SET_TYPE_SHFT                                          0x10
#define HWIO_UFS_UICCMDARG2_ARG2_RSP_BMSK                                                    0xff
#define HWIO_UFS_UICCMDARG2_ARG2_RSP_SHFT                                                     0x0

#define HWIO_UFS_UICCMDARG3_ADDR                                                       (UFS_REG_BASE      + 0x0000009c)
#define HWIO_UFS_UICCMDARG3_RMSK                                                       0xffffffff
#define HWIO_UFS_UICCMDARG3_IN          \
        in_dword_masked(HWIO_UFS_UICCMDARG3_ADDR, HWIO_UFS_UICCMDARG3_RMSK)
#define HWIO_UFS_UICCMDARG3_INM(m)      \
        in_dword_masked(HWIO_UFS_UICCMDARG3_ADDR, m)
#define HWIO_UFS_UICCMDARG3_OUT(v)      \
        out_dword(HWIO_UFS_UICCMDARG3_ADDR,v)
#define HWIO_UFS_UICCMDARG3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UICCMDARG3_ADDR,m,v,HWIO_UFS_UICCMDARG3_IN)
#define HWIO_UFS_UICCMDARG3_ARG3_BMSK                                                  0xffffffff
#define HWIO_UFS_UICCMDARG3_ARG3_SHFT                                                         0x0

#define HWIO_UFS_SYS1CLK_1US_ADDR                                                      (UFS_REG_BASE      + 0x000000c0)
#define HWIO_UFS_SYS1CLK_1US_RMSK                                                           0x1ff
#define HWIO_UFS_SYS1CLK_1US_IN          \
        in_dword_masked(HWIO_UFS_SYS1CLK_1US_ADDR, HWIO_UFS_SYS1CLK_1US_RMSK)
#define HWIO_UFS_SYS1CLK_1US_INM(m)      \
        in_dword_masked(HWIO_UFS_SYS1CLK_1US_ADDR, m)
#define HWIO_UFS_SYS1CLK_1US_OUT(v)      \
        out_dword(HWIO_UFS_SYS1CLK_1US_ADDR,v)
#define HWIO_UFS_SYS1CLK_1US_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_SYS1CLK_1US_ADDR,m,v,HWIO_UFS_SYS1CLK_1US_IN)
#define HWIO_UFS_SYS1CLK_1US_SYS1CLK_1US_REG_BMSK                                           0x1ff
#define HWIO_UFS_SYS1CLK_1US_SYS1CLK_1US_REG_SHFT                                             0x0

#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_ADDR                                              (UFS_REG_BASE      + 0x000000c4)
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_RMSK                                                0xffffff
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_IN          \
        in_dword_masked(HWIO_UFS_TX_SYMBOL_CLK_NS_US_ADDR, HWIO_UFS_TX_SYMBOL_CLK_NS_US_RMSK)
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_INM(m)      \
        in_dword_masked(HWIO_UFS_TX_SYMBOL_CLK_NS_US_ADDR, m)
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_OUT(v)      \
        out_dword(HWIO_UFS_TX_SYMBOL_CLK_NS_US_ADDR,v)
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_TX_SYMBOL_CLK_NS_US_ADDR,m,v,HWIO_UFS_TX_SYMBOL_CLK_NS_US_IN)
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_CLK_NS_REG_BMSK                                     0xfffc00
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_CLK_NS_REG_SHFT                                          0xa
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_TX_SYMBOL_CLK_1US_REG_BMSK                             0x3ff
#define HWIO_UFS_TX_SYMBOL_CLK_NS_US_TX_SYMBOL_CLK_1US_REG_SHFT                               0x0

#define HWIO_UFS_LOCAL_PORT_ID_REG_ADDR                                                (UFS_REG_BASE      + 0x000000c8)
#define HWIO_UFS_LOCAL_PORT_ID_REG_RMSK                                                     0x7ff
#define HWIO_UFS_LOCAL_PORT_ID_REG_IN          \
        in_dword_masked(HWIO_UFS_LOCAL_PORT_ID_REG_ADDR, HWIO_UFS_LOCAL_PORT_ID_REG_RMSK)
#define HWIO_UFS_LOCAL_PORT_ID_REG_INM(m)      \
        in_dword_masked(HWIO_UFS_LOCAL_PORT_ID_REG_ADDR, m)
#define HWIO_UFS_LOCAL_PORT_ID_REG_OUT(v)      \
        out_dword(HWIO_UFS_LOCAL_PORT_ID_REG_ADDR,v)
#define HWIO_UFS_LOCAL_PORT_ID_REG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_LOCAL_PORT_ID_REG_ADDR,m,v,HWIO_UFS_LOCAL_PORT_ID_REG_IN)
#define HWIO_UFS_LOCAL_PORT_ID_REG_LOCAL_CPORT_ID_BMSK                                      0x7ff
#define HWIO_UFS_LOCAL_PORT_ID_REG_LOCAL_CPORT_ID_SHFT                                        0x0

#define HWIO_UFS_REG_PA_ERR_CODE_ADDR                                                  (UFS_REG_BASE      + 0x000000cc)
#define HWIO_UFS_REG_PA_ERR_CODE_RMSK                                                         0xf
#define HWIO_UFS_REG_PA_ERR_CODE_IN          \
        in_dword_masked(HWIO_UFS_REG_PA_ERR_CODE_ADDR, HWIO_UFS_REG_PA_ERR_CODE_RMSK)
#define HWIO_UFS_REG_PA_ERR_CODE_INM(m)      \
        in_dword_masked(HWIO_UFS_REG_PA_ERR_CODE_ADDR, m)
#define HWIO_UFS_REG_PA_ERR_CODE_PA_ERR_CODE_REG_BMSK                                         0xf
#define HWIO_UFS_REG_PA_ERR_CODE_PA_ERR_CODE_REG_SHFT                                         0x0

#define HWIO_UFS_RETRY_TIMER_REG_ADDR                                                  (UFS_REG_BASE      + 0x000000d0)
#define HWIO_UFS_RETRY_TIMER_REG_RMSK                                                  0xffffffff
#define HWIO_UFS_RETRY_TIMER_REG_IN          \
        in_dword_masked(HWIO_UFS_RETRY_TIMER_REG_ADDR, HWIO_UFS_RETRY_TIMER_REG_RMSK)
#define HWIO_UFS_RETRY_TIMER_REG_INM(m)      \
        in_dword_masked(HWIO_UFS_RETRY_TIMER_REG_ADDR, m)
#define HWIO_UFS_RETRY_TIMER_REG_OUT(v)      \
        out_dword(HWIO_UFS_RETRY_TIMER_REG_ADDR,v)
#define HWIO_UFS_RETRY_TIMER_REG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_RETRY_TIMER_REG_ADDR,m,v,HWIO_UFS_RETRY_TIMER_REG_IN)
#define HWIO_UFS_RETRY_TIMER_REG_RETRY_TIMER_REG_BMSK                                  0xffffffff
#define HWIO_UFS_RETRY_TIMER_REG_RETRY_TIMER_REG_SHFT                                         0x0

#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_ADDR                                        (UFS_REG_BASE      + 0x000000d8)
#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_RMSK                                         0xfffffff
#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_IN          \
        in_dword_masked(HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_ADDR, HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_RMSK)
#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_INM(m)      \
        in_dword_masked(HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_ADDR, m)
#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_OUT(v)      \
        out_dword(HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_ADDR,v)
#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_ADDR,m,v,HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_IN)
#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_PA_LINKSTARTUP_TIMER_REGISTER_BMSK           0xfffffff
#define HWIO_UFS_REG_PA_LINK_STARTUP_TIMER_PA_LINKSTARTUP_TIMER_REGISTER_SHFT                 0x0

#define HWIO_UFS_CFG1_ADDR                                                             (UFS_REG_BASE      + 0x000000dc)
#define HWIO_UFS_CFG1_RMSK                                                               0x7ffffe
#define HWIO_UFS_CFG1_IN          \
        in_dword_masked(HWIO_UFS_CFG1_ADDR, HWIO_UFS_CFG1_RMSK)
#define HWIO_UFS_CFG1_INM(m)      \
        in_dword_masked(HWIO_UFS_CFG1_ADDR, m)
#define HWIO_UFS_CFG1_OUT(v)      \
        out_dword(HWIO_UFS_CFG1_ADDR,v)
#define HWIO_UFS_CFG1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_CFG1_ADDR,m,v,HWIO_UFS_CFG1_IN)
#define HWIO_UFS_CFG1_UTP_TEST_BUS_SEL_BMSK                                              0x780000
#define HWIO_UFS_CFG1_UTP_TEST_BUS_SEL_SHFT                                                  0x13
#define HWIO_UFS_CFG1_UTP_TEST_BUS_EN_BMSK                                                0x40000
#define HWIO_UFS_CFG1_UTP_TEST_BUS_EN_SHFT                                                   0x12
#define HWIO_UFS_CFG1_UTP_DBG_RAMS_EN_BMSK                                                0x20000
#define HWIO_UFS_CFG1_UTP_DBG_RAMS_EN_SHFT                                                   0x11
#define HWIO_UFS_CFG1_HCI_EDTL_RAM_RD_FORCE_BMSK                                          0x10000
#define HWIO_UFS_CFG1_HCI_EDTL_RAM_RD_FORCE_SHFT                                             0x10
#define HWIO_UFS_CFG1_HCI_TX_RAM_RD_FORCE_BMSK                                             0x8000
#define HWIO_UFS_CFG1_HCI_TX_RAM_RD_FORCE_SHFT                                                0xf
#define HWIO_UFS_CFG1_HCI_RX_RAM_RD_FORCE_BMSK                                             0x4000
#define HWIO_UFS_CFG1_HCI_RX_RAM_RD_FORCE_SHFT                                                0xe
#define HWIO_UFS_CFG1_HCI_DESC_RAM_RD_FORCE_BMSK                                           0x2000
#define HWIO_UFS_CFG1_HCI_DESC_RAM_RD_FORCE_SHFT                                              0xd
#define HWIO_UFS_CFG1_HCI_PRDT_RAM_RD_FORCE_BMSK                                           0x1000
#define HWIO_UFS_CFG1_HCI_PRDT_RAM_RD_FORCE_SHFT                                              0xc
#define HWIO_UFS_CFG1_HCI_RESP_RAM_RD_FORCE_BMSK                                            0x800
#define HWIO_UFS_CFG1_HCI_RESP_RAM_RD_FORCE_SHFT                                              0xb
#define HWIO_UFS_CFG1_UFS_AHB2PHY_SIZE_ERROR_EN_BMSK                                        0x400
#define HWIO_UFS_CFG1_UFS_AHB2PHY_SIZE_ERROR_EN_SHFT                                          0xa
#define HWIO_UFS_CFG1_UFS_AWMEMTYPE_BMSK                                                    0x380
#define HWIO_UFS_CFG1_UFS_AWMEMTYPE_SHFT                                                      0x7
#define HWIO_UFS_CFG1_UFS_ARMEMTYPE_BMSK                                                     0x70
#define HWIO_UFS_CFG1_UFS_ARMEMTYPE_SHFT                                                      0x4
#define HWIO_UFS_CFG1_UFS_AWNOALLOCATE_BMSK                                                   0x8
#define HWIO_UFS_CFG1_UFS_AWNOALLOCATE_SHFT                                                   0x3
#define HWIO_UFS_CFG1_UFS_ARNOALLOCATE_BMSK                                                   0x4
#define HWIO_UFS_CFG1_UFS_ARNOALLOCATE_SHFT                                                   0x2
#define HWIO_UFS_CFG1_UFS_PHY_SOFT_RESET_BMSK                                                 0x2
#define HWIO_UFS_CFG1_UFS_PHY_SOFT_RESET_SHFT                                                 0x1

#define HWIO_UFS_CFG2_ADDR                                                             (UFS_REG_BASE      + 0x000000e0)
#define HWIO_UFS_CFG2_RMSK                                                               0xffffff
#define HWIO_UFS_CFG2_IN          \
        in_dword_masked(HWIO_UFS_CFG2_ADDR, HWIO_UFS_CFG2_RMSK)
#define HWIO_UFS_CFG2_INM(m)      \
        in_dword_masked(HWIO_UFS_CFG2_ADDR, m)
#define HWIO_UFS_CFG2_OUT(v)      \
        out_dword(HWIO_UFS_CFG2_ADDR,v)
#define HWIO_UFS_CFG2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_CFG2_ADDR,m,v,HWIO_UFS_CFG2_IN)
#define HWIO_UFS_CFG2_RXUC_PRDT_EMPTY_DIS_BMSK                                           0x800000
#define HWIO_UFS_CFG2_RXUC_PRDT_EMPTY_DIS_SHFT                                               0x17
#define HWIO_UFS_CFG2_UAWM_WADDR_FIX_DIS_BMSK                                            0x400000
#define HWIO_UFS_CFG2_UAWM_WADDR_FIX_DIS_SHFT                                                0x16
#define HWIO_UFS_CFG2_TXUC_PRDT_EMPTY_DIS_BMSK                                           0x200000
#define HWIO_UFS_CFG2_TXUC_PRDT_EMPTY_DIS_SHFT                                               0x15
#define HWIO_UFS_CFG2_SBFE_UAWM_DIS_BMSK                                                 0x100000
#define HWIO_UFS_CFG2_SBFE_UAWM_DIS_SHFT                                                     0x14
#define HWIO_UFS_CFG2_SBFE_UARM_DIS_BMSK                                                  0x80000
#define HWIO_UFS_CFG2_SBFE_UARM_DIS_SHFT                                                     0x13
#define HWIO_UFS_CFG2_HCI_AWCACHE_BMSK                                                    0x78000
#define HWIO_UFS_CFG2_HCI_AWCACHE_SHFT                                                        0xf
#define HWIO_UFS_CFG2_HCI_ARCACHE_BMSK                                                     0x7800
#define HWIO_UFS_CFG2_HCI_ARCACHE_SHFT                                                        0xb
#define HWIO_UFS_CFG2_HCI_UARM_PRIORITY_MODE_BMSK                                           0x700
#define HWIO_UFS_CFG2_HCI_UARM_PRIORITY_MODE_SHFT                                             0x8
#define HWIO_UFS_CFG2_OCSC_HW_CGC_EN_BMSK                                                    0x80
#define HWIO_UFS_CFG2_OCSC_HW_CGC_EN_SHFT                                                     0x7
#define HWIO_UFS_CFG2_TMRLUT_HW_CGC_EN_BMSK                                                  0x40
#define HWIO_UFS_CFG2_TMRLUT_HW_CGC_EN_SHFT                                                   0x6
#define HWIO_UFS_CFG2_TRLUT_HW_CGC_EN_BMSK                                                   0x20
#define HWIO_UFS_CFG2_TRLUT_HW_CGC_EN_SHFT                                                    0x5
#define HWIO_UFS_CFG2_DFC_HW_CGC_EN_BMSK                                                     0x10
#define HWIO_UFS_CFG2_DFC_HW_CGC_EN_SHFT                                                      0x4
#define HWIO_UFS_CFG2_RXUC_HW_CGC_EN_BMSK                                                     0x8
#define HWIO_UFS_CFG2_RXUC_HW_CGC_EN_SHFT                                                     0x3
#define HWIO_UFS_CFG2_TXUC_HW_CGC_EN_BMSK                                                     0x4
#define HWIO_UFS_CFG2_TXUC_HW_CGC_EN_SHFT                                                     0x2
#define HWIO_UFS_CFG2_UARM_HW_CGC_EN_BMSK                                                     0x2
#define HWIO_UFS_CFG2_UARM_HW_CGC_EN_SHFT                                                     0x1
#define HWIO_UFS_CFG2_UAWM_HW_CGC_EN_BMSK                                                     0x1
#define HWIO_UFS_CFG2_UAWM_HW_CGC_EN_SHFT                                                     0x0

#define HWIO_UFS_HW_VERSION_ADDR                                                       (UFS_REG_BASE      + 0x000000e4)
#define HWIO_UFS_HW_VERSION_RMSK                                                       0xffffffff
#define HWIO_UFS_HW_VERSION_IN          \
        in_dword_masked(HWIO_UFS_HW_VERSION_ADDR, HWIO_UFS_HW_VERSION_RMSK)
#define HWIO_UFS_HW_VERSION_INM(m)      \
        in_dword_masked(HWIO_UFS_HW_VERSION_ADDR, m)
#define HWIO_UFS_HW_VERSION_MAJOR_BMSK                                                 0xf0000000
#define HWIO_UFS_HW_VERSION_MAJOR_SHFT                                                       0x1c
#define HWIO_UFS_HW_VERSION_MINOR_BMSK                                                  0xfff0000
#define HWIO_UFS_HW_VERSION_MINOR_SHFT                                                       0x10
#define HWIO_UFS_HW_VERSION_STEP_BMSK                                                      0xffff
#define HWIO_UFS_HW_VERSION_STEP_SHFT                                                         0x0

#define HWIO_UFS_TEST_BUS_ADDR                                                         (UFS_REG_BASE      + 0x000000e8)
#define HWIO_UFS_TEST_BUS_RMSK                                                         0xffffffff
#define HWIO_UFS_TEST_BUS_IN          \
        in_dword_masked(HWIO_UFS_TEST_BUS_ADDR, HWIO_UFS_TEST_BUS_RMSK)
#define HWIO_UFS_TEST_BUS_INM(m)      \
        in_dword_masked(HWIO_UFS_TEST_BUS_ADDR, m)
#define HWIO_UFS_TEST_BUS_TEST_BUS_BMSK                                                0xffffffff
#define HWIO_UFS_TEST_BUS_TEST_BUS_SHFT                                                       0x0

#define HWIO_UFS_TEST_BUS_CTRL_0_ADDR                                                  (UFS_REG_BASE      + 0x000000ec)
#define HWIO_UFS_TEST_BUS_CTRL_0_RMSK                                                  0x1f1f1f1f
#define HWIO_UFS_TEST_BUS_CTRL_0_IN          \
        in_dword_masked(HWIO_UFS_TEST_BUS_CTRL_0_ADDR, HWIO_UFS_TEST_BUS_CTRL_0_RMSK)
#define HWIO_UFS_TEST_BUS_CTRL_0_INM(m)      \
        in_dword_masked(HWIO_UFS_TEST_BUS_CTRL_0_ADDR, m)
#define HWIO_UFS_TEST_BUS_CTRL_0_OUT(v)      \
        out_dword(HWIO_UFS_TEST_BUS_CTRL_0_ADDR,v)
#define HWIO_UFS_TEST_BUS_CTRL_0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_TEST_BUS_CTRL_0_ADDR,m,v,HWIO_UFS_TEST_BUS_CTRL_0_IN)
#define HWIO_UFS_TEST_BUS_CTRL_0_UAWM_SEL_BMSK                                         0x1f000000
#define HWIO_UFS_TEST_BUS_CTRL_0_UAWM_SEL_SHFT                                               0x18
#define HWIO_UFS_TEST_BUS_CTRL_0_UARM_SEL_BMSK                                           0x1f0000
#define HWIO_UFS_TEST_BUS_CTRL_0_UARM_SEL_SHFT                                               0x10
#define HWIO_UFS_TEST_BUS_CTRL_0_TXUC_SEL_BMSK                                             0x1f00
#define HWIO_UFS_TEST_BUS_CTRL_0_TXUC_SEL_SHFT                                                0x8
#define HWIO_UFS_TEST_BUS_CTRL_0_RXUC_SEL_BMSK                                               0x1f
#define HWIO_UFS_TEST_BUS_CTRL_0_RXUC_SEL_SHFT                                                0x0

#define HWIO_UFS_TEST_BUS_CTRL_1_ADDR                                                  (UFS_REG_BASE      + 0x000000f0)
#define HWIO_UFS_TEST_BUS_CTRL_1_RMSK                                                  0x1f1f1f1f
#define HWIO_UFS_TEST_BUS_CTRL_1_IN          \
        in_dword_masked(HWIO_UFS_TEST_BUS_CTRL_1_ADDR, HWIO_UFS_TEST_BUS_CTRL_1_RMSK)
#define HWIO_UFS_TEST_BUS_CTRL_1_INM(m)      \
        in_dword_masked(HWIO_UFS_TEST_BUS_CTRL_1_ADDR, m)
#define HWIO_UFS_TEST_BUS_CTRL_1_OUT(v)      \
        out_dword(HWIO_UFS_TEST_BUS_CTRL_1_ADDR,v)
#define HWIO_UFS_TEST_BUS_CTRL_1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_TEST_BUS_CTRL_1_ADDR,m,v,HWIO_UFS_TEST_BUS_CTRL_1_IN)
#define HWIO_UFS_TEST_BUS_CTRL_1_DFC_SEL_BMSK                                          0x1f000000
#define HWIO_UFS_TEST_BUS_CTRL_1_DFC_SEL_SHFT                                                0x18
#define HWIO_UFS_TEST_BUS_CTRL_1_TRLUT_SEL_BMSK                                          0x1f0000
#define HWIO_UFS_TEST_BUS_CTRL_1_TRLUT_SEL_SHFT                                              0x10
#define HWIO_UFS_TEST_BUS_CTRL_1_TMRLUT_SEL_BMSK                                           0x1f00
#define HWIO_UFS_TEST_BUS_CTRL_1_TMRLUT_SEL_SHFT                                              0x8
#define HWIO_UFS_TEST_BUS_CTRL_1_OCSC_SEL_BMSK                                               0x1f
#define HWIO_UFS_TEST_BUS_CTRL_1_OCSC_SEL_SHFT                                                0x0

#define HWIO_UFS_TEST_BUS_CTRL_2_ADDR                                                  (UFS_REG_BASE      + 0x000000f4)
#define HWIO_UFS_TEST_BUS_CTRL_2_RMSK                                                      0x1f1f
#define HWIO_UFS_TEST_BUS_CTRL_2_IN          \
        in_dword_masked(HWIO_UFS_TEST_BUS_CTRL_2_ADDR, HWIO_UFS_TEST_BUS_CTRL_2_RMSK)
#define HWIO_UFS_TEST_BUS_CTRL_2_INM(m)      \
        in_dword_masked(HWIO_UFS_TEST_BUS_CTRL_2_ADDR, m)
#define HWIO_UFS_TEST_BUS_CTRL_2_OUT(v)      \
        out_dword(HWIO_UFS_TEST_BUS_CTRL_2_ADDR,v)
#define HWIO_UFS_TEST_BUS_CTRL_2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_TEST_BUS_CTRL_2_ADDR,m,v,HWIO_UFS_TEST_BUS_CTRL_2_IN)
#define HWIO_UFS_TEST_BUS_CTRL_2_COMBINED_SEL_BMSK                                         0x1f00
#define HWIO_UFS_TEST_BUS_CTRL_2_COMBINED_SEL_SHFT                                            0x8
#define HWIO_UFS_TEST_BUS_CTRL_2_HCI_SEL_BMSK                                                0x1f
#define HWIO_UFS_TEST_BUS_CTRL_2_HCI_SEL_SHFT                                                 0x0

#define HWIO_UFS_UNIPRO_CFG_ADDR                                                       (UFS_REG_BASE      + 0x000000f8)
#define HWIO_UFS_UNIPRO_CFG_RMSK                                                              0x1
#define HWIO_UFS_UNIPRO_CFG_IN          \
        in_dword_masked(HWIO_UFS_UNIPRO_CFG_ADDR, HWIO_UFS_UNIPRO_CFG_RMSK)
#define HWIO_UFS_UNIPRO_CFG_INM(m)      \
        in_dword_masked(HWIO_UFS_UNIPRO_CFG_ADDR, m)
#define HWIO_UFS_UNIPRO_CFG_OUT(v)      \
        out_dword(HWIO_UFS_UNIPRO_CFG_ADDR,v)
#define HWIO_UFS_UNIPRO_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_UFS_UNIPRO_CFG_ADDR,m,v,HWIO_UFS_UNIPRO_CFG_IN)
#define HWIO_UFS_UNIPRO_CFG_UNIPRO_CDC_FIX_DIS_BMSK                                           0x1
#define HWIO_UFS_UNIPRO_CFG_UNIPRO_CDC_FIX_DIS_SHFT                                           0x0

#define HWIO_UFS_DBG_RD_REG_UAWMn_ADDR(n)                                              (UFS_REG_BASE      + 0x00000100 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_UAWMn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_REG_UAWMn_MAXn                                                         63
#define HWIO_UFS_DBG_RD_REG_UAWMn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_UAWMn_ADDR(n), HWIO_UFS_DBG_RD_REG_UAWMn_RMSK)
#define HWIO_UFS_DBG_RD_REG_UAWMn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_UAWMn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_UAWMn_UFS_DBG_RD_REG_UAWM_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_REG_UAWMn_UFS_DBG_RD_REG_UAWM_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_REG_UARMn_ADDR(n)                                              (UFS_REG_BASE      + 0x00000200 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_UARMn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_REG_UARMn_MAXn                                                         63
#define HWIO_UFS_DBG_RD_REG_UARMn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_UARMn_ADDR(n), HWIO_UFS_DBG_RD_REG_UARMn_RMSK)
#define HWIO_UFS_DBG_RD_REG_UARMn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_UARMn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_UARMn_UFS_DBG_RD_REG_UARM_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_REG_UARMn_UFS_DBG_RD_REG_UARM_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_REG_TXUCn_ADDR(n)                                              (UFS_REG_BASE      + 0x00000300 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_TXUCn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_REG_TXUCn_MAXn                                                         63
#define HWIO_UFS_DBG_RD_REG_TXUCn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_TXUCn_ADDR(n), HWIO_UFS_DBG_RD_REG_TXUCn_RMSK)
#define HWIO_UFS_DBG_RD_REG_TXUCn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_TXUCn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_TXUCn_UFS_DBG_RD_REG_TXUC_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_REG_TXUCn_UFS_DBG_RD_REG_TXUC_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_REG_RXUCn_ADDR(n)                                              (UFS_REG_BASE      + 0x00000400 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_RXUCn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_REG_RXUCn_MAXn                                                         63
#define HWIO_UFS_DBG_RD_REG_RXUCn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_RXUCn_ADDR(n), HWIO_UFS_DBG_RD_REG_RXUCn_RMSK)
#define HWIO_UFS_DBG_RD_REG_RXUCn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_RXUCn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_RXUCn_UFS_DBG_RD_REG_RXUC_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_REG_RXUCn_UFS_DBG_RD_REG_RXUC_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_REG_DFCn_ADDR(n)                                               (UFS_REG_BASE      + 0x00000500 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_DFCn_RMSK                                                  0xffffffff
#define HWIO_UFS_DBG_RD_REG_DFCn_MAXn                                                          63
#define HWIO_UFS_DBG_RD_REG_DFCn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_DFCn_ADDR(n), HWIO_UFS_DBG_RD_REG_DFCn_RMSK)
#define HWIO_UFS_DBG_RD_REG_DFCn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_DFCn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_DFCn_UFS_DBG_RD_REG_DFC_BMSK                               0xffffffff
#define HWIO_UFS_DBG_RD_REG_DFCn_UFS_DBG_RD_REG_DFC_SHFT                                      0x0

#define HWIO_UFS_DBG_RD_REG_TRLUTn_ADDR(n)                                             (UFS_REG_BASE      + 0x00000600 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_TRLUTn_RMSK                                                0xffffffff
#define HWIO_UFS_DBG_RD_REG_TRLUTn_MAXn                                                        63
#define HWIO_UFS_DBG_RD_REG_TRLUTn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_TRLUTn_ADDR(n), HWIO_UFS_DBG_RD_REG_TRLUTn_RMSK)
#define HWIO_UFS_DBG_RD_REG_TRLUTn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_TRLUTn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_TRLUTn_UFS_DBG_RD_REG_TRLUT_BMSK                           0xffffffff
#define HWIO_UFS_DBG_RD_REG_TRLUTn_UFS_DBG_RD_REG_TRLUT_SHFT                                  0x0

#define HWIO_UFS_DBG_RD_REG_TMRLUTn_ADDR(n)                                            (UFS_REG_BASE      + 0x00000700 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_TMRLUTn_RMSK                                               0xffffffff
#define HWIO_UFS_DBG_RD_REG_TMRLUTn_MAXn                                                       63
#define HWIO_UFS_DBG_RD_REG_TMRLUTn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_TMRLUTn_ADDR(n), HWIO_UFS_DBG_RD_REG_TMRLUTn_RMSK)
#define HWIO_UFS_DBG_RD_REG_TMRLUTn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_TMRLUTn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_TMRLUTn_UFS_DBG_RD_REG_TMRLUT_BMSK                         0xffffffff
#define HWIO_UFS_DBG_RD_REG_TMRLUTn_UFS_DBG_RD_REG_TMRLUT_SHFT                                0x0

#define HWIO_UFS_DBG_RD_REG_OCSCn_ADDR(n)                                              (UFS_REG_BASE      + 0x00000800 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_REG_OCSCn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_REG_OCSCn_MAXn                                                         63
#define HWIO_UFS_DBG_RD_REG_OCSCn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_OCSCn_ADDR(n), HWIO_UFS_DBG_RD_REG_OCSCn_RMSK)
#define HWIO_UFS_DBG_RD_REG_OCSCn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_REG_OCSCn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_REG_OCSCn_UFS_DBG_RD_REG_OCSC_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_REG_OCSCn_UFS_DBG_RD_REG_OCSC_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_TX_BUFFn_ADDR(n)                                               (UFS_REG_BASE      + 0x00000900 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_TX_BUFFn_RMSK                                                  0xffffffff
#define HWIO_UFS_DBG_RD_TX_BUFFn_MAXn                                                         511
#define HWIO_UFS_DBG_RD_TX_BUFFn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_TX_BUFFn_ADDR(n), HWIO_UFS_DBG_RD_TX_BUFFn_RMSK)
#define HWIO_UFS_DBG_RD_TX_BUFFn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_TX_BUFFn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_TX_BUFFn_UFS_DBG_RD_TX_BUFF_BMSK                               0xffffffff
#define HWIO_UFS_DBG_RD_TX_BUFFn_UFS_DBG_RD_TX_BUFF_SHFT                                      0x0

#define HWIO_UFS_DBG_RD_RX_BUFFn_ADDR(n)                                               (UFS_REG_BASE      + 0x00001100 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_RX_BUFFn_RMSK                                                  0xffffffff
#define HWIO_UFS_DBG_RD_RX_BUFFn_MAXn                                                         255
#define HWIO_UFS_DBG_RD_RX_BUFFn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_RX_BUFFn_ADDR(n), HWIO_UFS_DBG_RD_RX_BUFFn_RMSK)
#define HWIO_UFS_DBG_RD_RX_BUFFn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_RX_BUFFn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_RX_BUFFn_UFS_DBG_RD_RX_BUFF_BMSK                               0xffffffff
#define HWIO_UFS_DBG_RD_RX_BUFFn_UFS_DBG_RD_RX_BUFF_SHFT                                      0x0

#define HWIO_UFS_DBG_RD_DESC_RAMn_ADDR(n)                                              (UFS_REG_BASE      + 0x00001500 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_DESC_RAMn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_DESC_RAMn_MAXn                                                        127
#define HWIO_UFS_DBG_RD_DESC_RAMn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_DESC_RAMn_ADDR(n), HWIO_UFS_DBG_RD_DESC_RAMn_RMSK)
#define HWIO_UFS_DBG_RD_DESC_RAMn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_DESC_RAMn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_DESC_RAMn_UFS_DBG_RD_DESC_RAM_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_DESC_RAMn_UFS_DBG_RD_DESC_RAM_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_PRDT_RAMn_ADDR(n)                                              (UFS_REG_BASE      + 0x00001700 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_PRDT_RAMn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_PRDT_RAMn_MAXn                                                         63
#define HWIO_UFS_DBG_RD_PRDT_RAMn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_PRDT_RAMn_ADDR(n), HWIO_UFS_DBG_RD_PRDT_RAMn_RMSK)
#define HWIO_UFS_DBG_RD_PRDT_RAMn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_PRDT_RAMn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_PRDT_RAMn_UFS_DBG_RD_PRDT_RAM_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_PRDT_RAMn_UFS_DBG_RD_PRDT_RAM_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_RESP_RAMn_ADDR(n)                                              (UFS_REG_BASE      + 0x00001800 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_RESP_RAMn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_RESP_RAMn_MAXn                                                         63
#define HWIO_UFS_DBG_RD_RESP_RAMn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_RESP_RAMn_ADDR(n), HWIO_UFS_DBG_RD_RESP_RAMn_RMSK)
#define HWIO_UFS_DBG_RD_RESP_RAMn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_RESP_RAMn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_RESP_RAMn_UFS_DBG_RD_RESP_RAM_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_RESP_RAMn_UFS_DBG_RD_RESP_RAM_SHFT                                    0x0

#define HWIO_UFS_DBG_RD_EDTL_RAMn_ADDR(n)                                              (UFS_REG_BASE      + 0x00001900 + 0x4 * (n))
#define HWIO_UFS_DBG_RD_EDTL_RAMn_RMSK                                                 0xffffffff
#define HWIO_UFS_DBG_RD_EDTL_RAMn_MAXn                                                         31
#define HWIO_UFS_DBG_RD_EDTL_RAMn_INI(n)        \
        in_dword_masked(HWIO_UFS_DBG_RD_EDTL_RAMn_ADDR(n), HWIO_UFS_DBG_RD_EDTL_RAMn_RMSK)
#define HWIO_UFS_DBG_RD_EDTL_RAMn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_DBG_RD_EDTL_RAMn_ADDR(n), mask)
#define HWIO_UFS_DBG_RD_EDTL_RAMn_UFS_DBG_RD_EDTL_RAM_BMSK                             0xffffffff
#define HWIO_UFS_DBG_RD_EDTL_RAMn_UFS_DBG_RD_EDTL_RAM_SHFT                                    0x0

#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_ADDR(n)                                      (UFS_REG_BASE      + 0x00002000 + 0x4 * (n))
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_RMSK                                         0x80000003
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_MAXn                                                 31
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_INI(n)        \
        in_dword_masked(HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_ADDR(n), HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_RMSK)
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_INMI(n,mask)    \
        in_dword_masked(HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_ADDR(n), mask)
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_OUTI(n,val)    \
        out_dword(HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_ADDR(n),val)
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_ADDR(n),mask,val,HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_INI(n))
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_HW_EVENT_EN_BMSK                             0x80000000
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_HW_EVENT_EN_SHFT                                   0x1f
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_HW_EVENT_SEL_BMSK                                   0x3
#define HWIO_UFS_HW_EVENT_MUX_SELECT_REGn_HW_EVENT_SEL_SHFT                                   0x0


#endif /* __UFS_PHY_HWIO_H__ */
