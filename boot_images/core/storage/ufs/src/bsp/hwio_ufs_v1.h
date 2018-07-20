#ifndef HWIO_UFS_V1_H
#define HWIO_UFS_V1_H

/**********************************************************************
 *
 * Copyright (c) 2012 Qualcomm Technologies Incorporated. All Rights Reserved.
 * Qualcomm Confidential and Proprietary
 *
 **********************************************************************/

/*======================================================================

                        EDIT HISTORY FOR MODULE

  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/bsp/hwio_ufs_v1.h#1 $
  $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $

when         who     what, where, why
----------   ---     ---------------------------------------------------
2012-12-18   rh      Initial creation
=======================================================================*/

#define HWIO_UFSHCI_BASE_ADDR                            0xfc590000

#define UFSHCI_OFFSET_ADDR                               0x4000

/* Define the required HWIO address mapping function */
#define HWIO_UFSHCI_CAP                                  (0x0000 + UFSHCI_OFFSET_ADDR)  
#define HWIO_UFSHCI_VER                                  (0x0008 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_HCDDID                               (0x0010 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_HCPMID                               (0x0014 + UFSHCI_OFFSET_ADDR)

#define HWIO_UFSHCI_IS                                   (0x0020 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_IE                                   (0x0024 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_HCS                                  (0x0030 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_HCE                                  (0x0034 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UECPA                                (0x0038 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UECDL                                (0x003C + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UECN                                 (0x0040 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UECT                                 (0x0044 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UECDME                               (0x0048 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTRIACR                              (0x004C + UFSHCI_OFFSET_ADDR)

#define HWIO_UFSHCI_UTRLBA                               (0x0050 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTRLBAU                              (0x0054 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTRLDBR                              (0x0058 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTRLCLR                              (0x005C + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTRLRSR                              (0x0060 + UFSHCI_OFFSET_ADDR)

#define HWIO_UFSHCI_UTMRLBA                              (0x0070 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTMRLBAU                             (0x0074 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTMRLDBR                             (0x0078 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTMRLCLR                             (0x007C + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UTMRLRSR                             (0x0080 + UFSHCI_OFFSET_ADDR)

#define HWIO_UFSHCI_UICCMDR                              (0x0090 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UCMDARG1                             (0x0094 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UCMDARG2                             (0x0098 + UFSHCI_OFFSET_ADDR)
#define HWIO_UFSHCI_UCMDARG3                             (0x009C + UFSHCI_OFFSET_ADDR)

#define HWIO_VENSPEC_UFS_CFG1                            (0x00DC + UFSHCI_OFFSET_ADDR)
#define HWIO_VENSPEC_UFS_CFG2                            (0x00E0 + UFSHCI_OFFSET_ADDR)
#define HWIO_VENSPEC_UFS_SYS1CLK_1US                     (0x00C0 + UFSHCI_OFFSET_ADDR)
#define HWIO_VENSPEC_TX_SYMBOL_CLK_NS_US                 (0x00C4 + UFSHCI_OFFSET_ADDR)
#define HWIO_VENSPEC_REG_PA_LINK_STARTUP_TIMER           (0x00d8 + UFSHCI_OFFSET_ADDR)



/* Bit field of UFSHCI_CAP register */
#define BMSK_NUTRS                                       (0x1f << 0)
#define BMSK_NUTMRS                                      (0x07 << 16)
#define BMSK_64AS                                        (0x01 << 24)
#define BMSK_OODDS                                       (0x01 << 25)
#define BMSK_UICDMETMS                                   (0x01 << 26)

/* Bit field of UFSHCI_IS register */
#define BMSK_UTRCS                                       (0x01 << 0)
#define BMSK_UDEPRI                                      (0x01 << 1)
#define BMSK_UE                                          (0x01 << 2)
#define BMSK_UTMS                                        (0x01 << 3)
#define BMSK_UPMS                                        (0x01 << 4)
#define BMSK_UHXS                                        (0x01 << 5)
#define BMSK_UHES                                        (0x01 << 6)
#define BMSK_ULLS                                        (0x01 << 7)
#define BMSK_ULSS                                        (0x01 << 8)
#define BMSK_UTMRCS                                      (0x01 << 9)
#define BMSK_UCCS                                        (0x01 << 10)
#define BMSK_DFES                                        (0x01 << 11)
#define BMSK_UTPES                                       (0x01 << 12)
#define BMSK_HCFES                                       (0x01 << 16)
#define BMSK_SBFES                                       (0x01 << 17)

/* Bit field of UFSHCI_HCS register */
#define BMSK_UPMCRS                                      (0x03 << 8)
#define UPMCRS_PWR_OK                                    (0)
#define UPMCRS_PWR_LOCAL                                 (1)
#define UPMCRS_PWR_REMOTE                                (2)
#define UPMCRS_PWR_BUSY                                  (3)
#define UPMCRS_PWR_ERROR_CAP                             (4)
#define UPMCRS_PWR_FATAL_ERROR                           (5)
#define BMSK_UCRDY                                       (0x01 << 3)
#define BMSK_UTMRLRDY                                    (0x01 << 2)
#define BMSK_UTRLRDY                                     (0x01 << 1)
#define BMSK_DP                                          (0x01 << 0)

/* Bit field of UFSHCI_HCE register */
#define BMSK_HCE                                         (0x01 << 0)

/* Bit field of UFSHCI_UTRIACR register */
#define BMSK_IAEN                                        (0x01 << 31)
#define BMSK_IAPWEN                                      (0x01 << 24)
#define BMSK_IASB                                        (0x01 << 20)
#define BMSK_CTR                                         (0x01 << 16)
#define BMSK_IACTH                                       (0x3f << 8)
#define BMSK_IATOVAL                                     (0xff << 0)

/* Bit field of UFSHCI_UTRLRSR register */
#define BMSK_UTRLRSR                                     (0x01 << 0)

/* Bit field of UFSHCI_UTMRLRSR register */
#define BMSK_UTMRLRSR                                    (0x01 << 0)

/* Bit field of UFSHCI_UICCMDR register */
#define UICCMDR_DME_GET                                  0x01
#define UICCMDR_DME_SET                                  0x02
#define UICCMDR_DME_PEER_GET                             0x03
#define UICCMDR_DME_PEER_SET                             0x04
#define UICCMDR_DME_POWERON                              0x10
#define UICCMDR_DME_POWEROFF                             0x11
#define UICCMDR_DME_ENABLE                               0x12
#define UICCMDR_DME_RESET                                0x14
#define UICCMDR_DME_ENDPOINTRESET                        0x15
#define UICCMDR_DME_LINKSTARTUP                          0x16
#define UICCMDR_DME_HIBERNATE_ENTER                      0x17
#define UICCMDR_DME_HIBERNATE_EXIT                       0x18
#define UICCMDR_DME_TEST_MODE                            0x1a
       
/* Bit field of QC_UFS_CFG1 register */
#define BMSK_UTP_PHY_SOFT_RESET                          0x02

/* Bit field of QC_UFS_SYS1CLK_1US register */
#define BMSK_SYS1CLK_1US_REG                             0x1ff
#define SHFT_SYS1CLK_1US_REG                             0

/* Bit field of QC_UFS_TX_SYMBOL_CLK_NS_US register */
#define BMSK_TX_SYMBOL_CLK_1US_REG                       0x1ff
#define SHFT_TX_SYMBOL_CLK_1US_REG                       0
#define BMSK_CLK_NS_REG                                  (0xfff << 10)
#define SHFT_CLK_NS_REG                                  (10)

/* UFS PHY initialization registers */
#define UFS_PCS_REG_BASE                                 0x00007700

#define HWIO_PHY_PHY_START                               (UFS_PCS_REG_BASE      + 0x00000000)
#define HWIO_PHY_PCS_READY_STATUS                        (UFS_PCS_REG_BASE      + 0x00000134)
#define UFS_UFS_REGS_BASE                                0


#define UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE                                                 (UFS_UFS_REGS_BASE      + 0x00007700)

#define HWIO_UFS_UFS_PHY_PHY_START_ADDR                                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000000)
#define HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000004)
#define HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000008)
#define HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000000c)
#define HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000010)
#define HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000014)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000018)
#define HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000001c)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000020)
#define HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000024)
#define HWIO_UFS_UFS_PHY_LINE_RESET_TIME_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000028)
#define HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000002c)
#define HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000030)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000034)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000038)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000003c)
#define HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000040)
#define HWIO_UFS_UFS_PHY_TX_LANE_ENABLE_ADDR                                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000044)
#define HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_ADDR                                                                           (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000048)
#define HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_ADDR                                                                           (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000004c)
#define HWIO_UFS_UFS_PHY_PLL_CNTL_ADDR                                                                                   (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000050)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000054)
#define HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000058)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000005c)
#define HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000060)
#define HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000064)
#define HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_ADDR                                                                           (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000068)
#define HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_ADDR                                                                          (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000006c)
#define HWIO_UFS_UFS_PHY_L0_BIST_CTRL_ADDR                                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000070)
#define HWIO_UFS_UFS_PHY_L1_BIST_CTRL_ADDR                                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000074)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY0_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000078)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_POLY1_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000007c)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED0_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000080)
#define HWIO_UFS_UFS_PHY_BIST_PRBS_SEED1_ADDR                                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000084)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT_CTRL_ADDR                                                                        (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000088)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT0_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000008c)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT1_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000090)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT2_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000094)
#define HWIO_UFS_UFS_PHY_BIST_FIXED_PAT3_DATA_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000098)
#define HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000009c)
#define HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_ADDR                                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000a0)
#define HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_ADDR                                                                    (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000a4)
#define HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_ADDR                                                                 (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000a8)
#define HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_ADDR                                                   (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000ac)
#define HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_ADDR                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000b0)
#define HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000b4)
#define HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000b8)
#define HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000bc)
#define HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_ADDR                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000c0)
#define HWIO_UFS_UFS_PHY_TX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000c4)
#define HWIO_UFS_UFS_PHY_TX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR                                                        (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000c8)
#define HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000cc)
#define HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_ADDR                                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000d0)
#define HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_ADDR                                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000d4)
#define HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_ADDR                                                              (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000d8)
#define HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_ADDR                                                                (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000dc)
#define HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000e0)
#define HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR                                                      (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000e4)
#define HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000e8)
#define HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_ADDR                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000ec)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000f0)
#define HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000f4)
#define HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000f8)
#define HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_ADDR                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x000000fc)
#define HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_ADDR                                                             (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000100)
#define HWIO_UFS_UFS_PHY_RX_PHY_MAJORMINOR_RELEASE_CAPABILITY_ADDR                                                       (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000104)
#define HWIO_UFS_UFS_PHY_RX_PHY_EDITORIAL_RELEASE_CAPABILITY_ADDR                                                        (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000108)
#define HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_ADDR                                                                  (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000010c)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000110)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_ADDR                                                            (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000114)
#define HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000118)
#define HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_ADDR                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000011c)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_SEL_ADDR                                                                              (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000120)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000124)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000128)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000012c)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_CHK_ADDR                                                                     (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000130)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_L_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000134)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_ERR_CNT_H_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000138)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_L_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000013c)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_ERR_CNT_H_STATUS_ADDR                                                               (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000140)
#define HWIO_UFS_UFS_PHY_L0_BIST_CHK_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000144)
#define HWIO_UFS_UFS_PHY_L1_BIST_CHK_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000148)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_0_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x0000014c)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_1_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000150)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_2_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000154)
#define HWIO_UFS_UFS_PHY_DEBUG_BUS_3_STATUS_ADDR                                                                         (UFS_UFS_PHY_UFS_PHY_UFS_PCS_REG_BASE      + 0x00000158)

#define UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE                                         (UFS_UFS_REGS_BASE      + 0x00007200)

#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_RX0_AUX_CONTROL_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_RX0_EQ_CONTROL_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_INIT_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_LVL_EN_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_MODE_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_RESET_ADDR                                             (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_RX0_RX_BAND_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_RX0_RX_INTERFACE_MODE_ADDR                                         (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_RX0_JITTER_GEN_MODE_ADDR                                           (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_RX0_BUJ_AMP_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP1_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_RX0_SJ_AMP2_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_RX0_SJ_PER1_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_RX0_SJ_PER2_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ1_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_RX0_BUJ_STEP_FREQ2_ADDR                                            (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET1_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_RX0_PPM_OFFSET2_ADDR                                               (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD1_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_RX0_SIGN_PPM_PERIOD2_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_RX0_SSC_CTRL_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT1_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_RX0_SSC_COUNT2_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_RX0_PWM_CNTRL2_ADDR                                                (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000084)
#define HWIO_UFS_QSERDES_RX0_PWM_NDIV_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000088)
#define HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_ADDR                                             (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000008c)
#define HWIO_UFS_QSERDES_RX0_UFS_CNTRL_ADDR                                                 (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000090)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000094)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_ADDR                                          (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x00000098)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_ADDR                                       (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x0000009c)
#define HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_ADDR                                        (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000a0)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000a4)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000a8)
#define HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_ADDR                             (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000ac)
#define HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_ADDR                                       (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000b0)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL1_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000b4)
#define HWIO_UFS_QSERDES_RX0_PI_CTRL2_ADDR                                                  (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000b8)
#define HWIO_UFS_QSERDES_RX0_PI_QUAD_ADDR                                                   (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000bc)
#define HWIO_UFS_QSERDES_RX0_IDATA1_ADDR                                                    (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000c0)
#define HWIO_UFS_QSERDES_RX0_IDATA2_ADDR                                                    (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000c4)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA1_ADDR                                                 (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000c8)
#define HWIO_UFS_QSERDES_RX0_AUX_DATA2_ADDR                                                 (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000cc)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTP_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000d0)
#define HWIO_UFS_QSERDES_RX0_AC_JTAG_OUTN_ADDR                                              (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000d4)
#define HWIO_UFS_QSERDES_RX0_RX_SIGDET_PWMDECSTATUS_ADDR                                    (UFS_QSERDES_RX0_QSERDES_RX0_QMP_RX_REG_BASE      + 0x000000d8)

#define UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE                                         (UFS_UFS_REGS_BASE      + 0x00007600)

#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_RX1_AUX_CONTROL_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_RX1_EQ_CONTROL_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_INIT_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_LVL_EN_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_MODE_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_RESET_ADDR                                             (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_RX1_RX_BAND_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_RX1_RX_INTERFACE_MODE_ADDR                                         (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_RX1_JITTER_GEN_MODE_ADDR                                           (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_RX1_BUJ_AMP_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP1_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_RX1_SJ_AMP2_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_RX1_SJ_PER1_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_RX1_SJ_PER2_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ1_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_RX1_BUJ_STEP_FREQ2_ADDR                                            (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET1_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_RX1_PPM_OFFSET2_ADDR                                               (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD1_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_RX1_SIGN_PPM_PERIOD2_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_RX1_SSC_CTRL_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT1_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_RX1_SSC_COUNT2_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_RX1_PWM_CNTRL2_ADDR                                                (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000084)
#define HWIO_UFS_QSERDES_RX1_PWM_NDIV_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000088)
#define HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_ADDR                                             (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000008c)
#define HWIO_UFS_QSERDES_RX1_UFS_CNTRL_ADDR                                                 (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000090)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000094)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_ADDR                                          (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x00000098)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_ADDR                                       (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x0000009c)
#define HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_ADDR                                        (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000a0)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000a4)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000a8)
#define HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_ADDR                             (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000ac)
#define HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_ADDR                                       (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000b0)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL1_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000b4)
#define HWIO_UFS_QSERDES_RX1_PI_CTRL2_ADDR                                                  (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000b8)
#define HWIO_UFS_QSERDES_RX1_PI_QUAD_ADDR                                                   (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000bc)
#define HWIO_UFS_QSERDES_RX1_IDATA1_ADDR                                                    (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000c0)
#define HWIO_UFS_QSERDES_RX1_IDATA2_ADDR                                                    (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000c4)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA1_ADDR                                                 (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000c8)
#define HWIO_UFS_QSERDES_RX1_AUX_DATA2_ADDR                                                 (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000cc)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTP_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000d0)
#define HWIO_UFS_QSERDES_RX1_AC_JTAG_OUTN_ADDR                                              (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000d4)
#define HWIO_UFS_QSERDES_RX1_RX_SIGDET_PWMDECSTATUS_ADDR                                    (UFS_QSERDES_RX1_QSERDES_RX1_QMP_RX_REG_BASE      + 0x000000d8)

#define UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE                                            (UFS_UFS_REGS_BASE      + 0x00007100)

#define HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_ADDR                                             (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR                                             (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_ADDR                                               (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_TX0_LPB_EN_ADDR                                                       (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_TX0_RES_CODE_ADDR                                                     (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH1_ADDR                                                 (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_TX0_PERL_LENGTH2_ADDR                                                 (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR                                  (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN1_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN2_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN3_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN4_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN5_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN6_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN7_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_TX0_BIST_PATTERN8_ADDR                                                (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_TX0_LANE_MODE_ADDR                                                    (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_TX0_ATB_SEL_ADDR                                                      (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_ADDR                                               (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED1_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED2_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED3_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_TX0_PRBS_SEED4_ADDR                                                   (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_TX0_RESET_GEN_ADDR                                                    (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR                                             (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_TX0_TX_INTERFACE_MODE_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_TX0_BIST_STATUS_ADDR                                                  (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT1_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_TX0_BIST_ERROR_COUNT2_ADDR                                            (UFS_QSERDES_TX0_QSERDES_TX0_QMP_TX_REG_BASE      + 0x00000080)

#define UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE                                            (UFS_UFS_REGS_BASE      + 0x00007500)

#define HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_ADDR                                             (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR                                             (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_ADDR                                               (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_TX1_LPB_EN_ADDR                                                       (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_TX1_RES_CODE_ADDR                                                     (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH1_ADDR                                                 (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_TX1_PERL_LENGTH2_ADDR                                                 (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR                                  (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN1_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN2_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN3_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN4_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN5_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN6_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN7_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_TX1_BIST_PATTERN8_ADDR                                                (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_TX1_LANE_MODE_ADDR                                                    (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_TX1_ATB_SEL_ADDR                                                      (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_ADDR                                               (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED1_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED2_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED3_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_TX1_PRBS_SEED4_ADDR                                                   (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_TX1_RESET_GEN_ADDR                                                    (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR                                             (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_TX1_TX_INTERFACE_MODE_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_TX1_BIST_STATUS_ADDR                                                  (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT1_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_TX1_BIST_ERROR_COUNT2_ADDR                                            (UFS_QSERDES_TX1_QSERDES_TX1_QMP_TX_REG_BASE      + 0x00000080)

#define UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE                             (UFS_UFS_REGS_BASE      + 0x00007000)

#define HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000000)
#define HWIO_UFS_QSERDES_COM_PLL_VCOTAIL_EN_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000004)
#define HWIO_UFS_QSERDES_COM_CMN_MODE_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000008)
#define HWIO_UFS_QSERDES_COM_IE_TRIM_ADDR                                           (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000000c)
#define HWIO_UFS_QSERDES_COM_IP_TRIM_ADDR                                           (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000010)
#define HWIO_UFS_QSERDES_COM_PLL_CNTRL_ADDR                                         (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000014)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETI_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000018)
#define HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_ADDR                              (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000001c)
#define HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR                               (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000020)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETI_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000024)
#define HWIO_UFS_QSERDES_COM_PLL_IP_SETP_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000028)
#define HWIO_UFS_QSERDES_COM_PLL_CP_SETP_ADDR                                       (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000002c)
#define HWIO_UFS_QSERDES_COM_ATB_SEL1_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000030)
#define HWIO_UFS_QSERDES_COM_ATB_SEL2_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000034)
#define HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_ADDR                                     (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000038)
#define HWIO_UFS_QSERDES_COM_RES_CODE_TXBAND_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000003c)
#define HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_ADDR                                     (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000040)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000044)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000048)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000004c)
#define HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000050)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000054)
#define HWIO_UFS_QSERDES_COM_BGTC_ADDR                                              (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000058)
#define HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_ADDR                         (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000005c)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_TUNE_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000060)
#define HWIO_UFS_QSERDES_COM_DEC_START1_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000064)
#define HWIO_UFS_QSERDES_COM_PLL_AMP_OS_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000068)
#define HWIO_UFS_QSERDES_COM_SSC_EN_CENTER_ADDR                                     (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000006c)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER1_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000070)
#define HWIO_UFS_QSERDES_COM_SSC_ADJ_PER2_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000074)
#define HWIO_UFS_QSERDES_COM_SSC_PER1_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000078)
#define HWIO_UFS_QSERDES_COM_SSC_PER2_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000007c)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE1_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000080)
#define HWIO_UFS_QSERDES_COM_SSC_STEP_SIZE2_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000084)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_SEARCH_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000088)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_FREEZE_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000008c)
#define HWIO_UFS_QSERDES_COM_RES_TRIM_EN_VCOCALDONE_ADDR                            (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000090)
#define HWIO_UFS_QSERDES_COM_FAUX_EN_ADDR                                           (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000094)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x00000098)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x0000009c)
#define HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_ADDR                                   (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000a0)
#define HWIO_UFS_QSERDES_COM_DEC_START2_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000a4)
#define HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_ADDR                                  (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000a8)
#define HWIO_UFS_QSERDES_COM_PLL_CRCTRL_ADDR                                        (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000ac)
#define HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000b0)
#define HWIO_UFS_QSERDES_COM_PLL_FREQUPDATE_ADDR                                    (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000b4)
#define HWIO_UFS_QSERDES_COM_PLL_VCO_HIGH_ADDR                                      (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000b8)
#define HWIO_UFS_QSERDES_COM_RESET_SM_ADDR                                          (UFS_QSERDES_COM_QSERDES_COM_QMP_COMMON_REG_BASE      + 0x000000bc)



/* Define the required HWIO input/out macro mapping */

#define HWIO_REG_IN(base, reg)                           \
        (in_dword((base + HWIO_##reg)))
#define HWIO_REG_OUT(base, reg, v)                       \
        (out_dword((base + HWIO_##reg),v))
#define HWIO_REG_OUTM(base, reg, m, v)                   \
        (out_dword((base + HWIO_##reg),  \
        (in_dword((base + HWIO_##reg)) & m | v)))

/* Concept - Caller must supply a register base addree, register name
 * and value  */

#endif /* HWIO_UFS_V1_H */

