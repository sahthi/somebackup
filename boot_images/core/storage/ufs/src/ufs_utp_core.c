/**********************************************************************
 *
 *    UFS UTP layer - 
 *    Communicate with the UFS HCI register and generate the
 *    command/data packet structures 
 *    This layer is for interfacing with the hardware registers 
 *    exposed by the UFS host controller
 *
 * Copyright (c) 2012-2013 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 *
 **********************************************************************/

/*======================================================================

                        EDIT HISTORY FOR MODULE

  $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/ufs/src/ufs_utp_core.c#1 $
  $DateTime: 2016/12/12 23:35:46 $ $Author: pwbldsvc $

when         who     what, where, why
----------   ---     ---------------------------------------------------
2013-09-04   rh      Integrate the gear switch code
2013-08-27   rh      PRDT base address is not incrementing correctly
2013-08-12   rh      DWARD length conversion for UTRD is not correct
2012-12-18   rh      Initial creation
=======================================================================*/

#include "HALhwio.h"

#include "stdint.h"
#include "ufs_core.h"
#include "ufs_utp_core.h"
#include "hwio_ufs_v1.h"
#include "ufs_errno.h"
#include "ufs_bsp.h"

#include <string.h>

#define HCI_ENABLE_TIMEOUT             100000
#define HCI_UIC_TIMEOUT                100000
#define HCI_UTRD_POLL_TIMEOUT          100000
#define HCI_UTMRD_POLL_TIMEOUT         100000
#define HCI_LINK_STARTUP_TIMEOUT       100000
#define UFS_PHY_PCS_READY_TIMEOUT      0xffffff
#define UFS_TX_FSM_STATE_TIMEOUT       100000
#define UFS_HCI_UPMS_POLL_TIMEOUT      100000

#define REQUEST_LIST_BUFFER_SIZE       4096
#define UTRD_ARRAY_SIZE                1024
#define PRDT_DBC_MAX                   0x40000
#define MAX_PRDT_ENTRIES               1024

#ifdef RUMI
#define UFS_SYS1CLK_1US_VAL            0x20
#else
#define UFS_SYS1CLK_1US_VAL            100
#endif

#define UFS_TX_SYMBOL_CLK_1US_VAL      1
#define UFS_CLK_NS_REG_VAL             10
#define UFS_PA_LINK_STARTUP_TIMER_VAL  20000000
#define UFS_LINK_STARTUP_RETRY         10

#define UFS_UTRD_DOORBELL_CH           (0x01 << 0)

#define TX_FSM_State                            0x41
#define TX_FSM_State_HIBERN8                    0x01

#define GET_PHY_ADDR_L(x)  ((uint32_t)((uint64_t)x))
#define GET_PHY_ADDR_H(x)  ((uint32_t)(((uint64_t)x) >> 32))
#define GET_PHY_ADDR(x)    ((uint64_t)x)

//Select the endian adjustment macro if needed
//#define ENDIAN_ADJ_32(x)   (((x & 0xff) << 24) | ((x & 0xff000000) >> 24) | ((x & 0xff00) << 8) | ((x & 0xff0000) >> 8))
#define ENDIAN_ADJ_32(x)   (x)

//#define MEMORY_BARRIER()   sdcc_bsp_cache_operation (SDCC_BSP_MEM_BARRIER, NULL, 0)
#define MEMORY_BARRIER()   

#define RUMI_PHY_BASE_ADDRESS 0xFC590000

#ifdef RUMI
static void ufs_phy_init(uint32 baseAddr);
static void ufs_serdes_bypass_on(uint32 baseAddr);
#endif

//#define UFS_SKIP_PHY_INIT

#define UFS_DEFAULT_GEAR         0x01        // GEAR-1
#define UFS_DEFAULT_HS_SERIES    0x01        // SERIES-A
#define UFS_DEFAULT_PWR_MODE     0x11        // FAST mode

// Data structure used to initialize the phy
struct ufs_mphy_init_item {
   uint32_t reg;
   uint16_t dly;
   uint8_t  val;
};


// Create two buffers -
// Task management request list buffer
// The Transfer request is 8 x 32 = 256 bytes total, follow
// by undetermined number of command descriptors
// Memory will be allocated this way
//  -----------------------
//  | UTRD * n            |      (UTP Transfer Reqeust Descriptor)
//  -----------------------
//  | UCD (3 parts)       |      (UTP Command Descriptor )
//  | - Transfer Request  |
//  | - Transfer Response |
//  | - PRD table         |
//  -----------------------
//  For this implementation, n = 1, max is 32
// NOTE: These buffer need to be 1k aligned
//
uint8_t transfer_request_list_buf[REQUEST_LIST_BUFFER_SIZE];      

#ifndef UFS_SKIP_PHY_INIT
static int32_t ufs_preinit_mphy_configure (ufs_host_t *hba);
#endif
// Need to define MBR command

// Simple version, no arguments
// Sent a UIC command and wait for completition flag 
int32_t ufs_utp_send_uic (ufs_host_t *hba, uint32_t uic)
{
   uint32_t tout;
   uint32_t re;
   hba->ufs_last_uic_cmd = uic;

   // Check to make sure hardware to ready to accept a UIC command
   tout = HCI_UIC_TIMEOUT;
   while (--tout) {
      if (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_HCS) & BMSK_UCRDY) {
         break;
      }
   }
   if (tout == 0) {
      ufs_error_log(hba, 0x0010);
      return -EIO;
   }

   // Clear the UCCS bit in IS register
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_IS, BMSK_UCCS);

   // Set UIC COMMAND Argument field
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UCMDARG1, 0x0);
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UCMDARG2, 0x0);
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UCMDARG3, 0x0);

   // Send the UICC command 
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UICCMDR, uic);
   // Poll the IS register for UCCS bit

   tout = HCI_ENABLE_TIMEOUT;
   while (--tout) {
      if (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_IS) & BMSK_UCCS) {
         break;
      }
   }

   if (tout == 0) {
      ufs_error_log(hba, 0x0001);
      return -EIO;
   }

   // Check the result code
   re = HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_UCMDARG2);
   if ((re & 0xff) != 0x00) {
      ufs_error_log(hba, 0x0011);
      return -EIO;
   }

   return EOK;
}

// Use for UIC get/set command, 
// MIBattrIndex[31:16] = AttributeID
// MIBattrIndex[15:0] = GenSelectorIndex
// MIBval = Set the attribute value to
// Sent a UIC command and wait for completition flag 
int32_t ufs_utp_uic_getset (ufs_host_t *hba, uint32_t uic, uint32_t MIBattrIndex, uint32_t *MIBval)
{
   uint32_t tout;
   uint32_t re;
   hba->ufs_last_uic_cmd = uic;

   // Check to make sure hardware to ready to accept a UIC command
   tout = HCI_UIC_TIMEOUT;
   while (--tout) {
      if (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_HCS) & BMSK_UCRDY) {
         break;
      }
   }
   if (tout == 0) {
      ufs_error_log(hba, 0x0010);
      return -EIO;
   }

   // Clear the UCCS bit in IS register
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_IS, BMSK_UCCS);

   // Set UIC COMMAND Argument field
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UCMDARG1, MIBattrIndex);
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UCMDARG2, 0x0);
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UCMDARG3, *MIBval);

   // Send the UICC command 
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UICCMDR, uic);

   // Poll the IS register for UCCS bit
   tout = HCI_UIC_TIMEOUT;
   while (--tout) {
      if (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_IS) & BMSK_UCCS) {
         break;
      }
   }
   if (tout == 0) {
      ufs_error_log(hba, 0x0010);
      return -EIO;
   }

   // Check the result code
   re = HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_UCMDARG2);
   if ((re & 0xff) != 0x00) {
      ufs_error_log(hba, 0x0011);
      return -EIO;
   }

   *MIBval = HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_UCMDARG3);
   return EOK;
}

#ifdef UFS_SWITCH_TO_HS_GEAR
int32_t ufs_utp_gear_sw (ufs_host_t *hba)
{
   int32_t rc = EOK;
   uint32_t val;
   uint32_t tout;

   // Clear the UPMS bit in IS register
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_IS, BMSK_UPMS);

   // Set the TX and RX gear in L1.5, Set the HOST PWM RX GEAR
   val = UFS_DEFAULT_GEAR; 
   rc = ufs_utp_uic_getset (hba, UICCMDR_DME_SET, PA_RxGear, &val);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0030);
      return rc;
   }

   // Set the HOST PWM TX GEAR 
   val = UFS_DEFAULT_GEAR; 
   rc = ufs_utp_uic_getset (hba, UICCMDR_DME_SET, PA_TxGear, &val);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0031);
      return rc;
   }

   // Set the HS Series
   val = UFS_DEFAULT_HS_SERIES; 
   rc = ufs_utp_uic_getset (hba, UICCMDR_DME_SET, PA_HSSeries, &val);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0032);
      return rc;
   }

   // Set the HOST PowerState
   val = UFS_DEFAULT_PWR_MODE;
   rc = ufs_utp_uic_getset (hba, UICCMDR_DME_SET, PA_PWRMode, &val);
   if (rc != EOK) {
      ufs_error_log(hba, 0x0033);
      return rc;
   }

   // Wait until IS.UPMS is set to 1
   //
   //
   tout = UFS_HCI_UPMS_POLL_TIMEOUT;
   while (!(HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_IS) & BMSK_UPMS)) {
      if (--tout == 0) {
         ufs_error_log(hba, 0x0034);
         return rc;
      }
   }

   // Check the result of the power mode change request
   val = HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_HCS);
   if ((val & (0x07 << 8)) != 0) {
      ufs_error_log(hba, 0x0035);
      return -EIO;
   }
   return rc;
}
#endif


// Build the UPIU data structure in memory
void ufs_utp_build_upiu (uint32_t *dest_in, upiu_item_t *pupiu)
{
   uint8_t *dest = (uint8_t *)dest_in;
   *dest++ = pupiu->type;
   *dest++ = pupiu->flags;
   *dest++ = pupiu->lun;
   *dest++ = pupiu->task_tag;
   *dest++ = pupiu->cmd_set_type & 0x03;
   *dest++ = pupiu->query_fnc;            // Query Function
   *dest++ = 0;                           // Response
   *dest++ = 0;                           // Status
   *dest++ = 0;                           // Total EHS Length, must be 0
   *dest++ = 0;                           // Device information
   *dest++ = pupiu->data_segment_len >> 8;
   *dest++ = pupiu->data_segment_len & 0xff;

   if (pupiu->type == UPIU_TYPE_COMMAND) {
      *dest++ = pupiu->data_expected_len >> 24;
      *dest++ = pupiu->data_expected_len >> 16;
      *dest++ = pupiu->data_expected_len >> 8;
      *dest++ = pupiu->data_expected_len & 0xff;
   }

   memcpy (dest, pupiu->param, 16);       // Op Specific field -
                                          // CDB for command, 
                                          // Parameter for management
                                          
   // Need to pad a reserved DWORD
   if (pupiu->type != UPIU_TYPE_COMMAND) {
      dest += 4;
   }

   // If there are more data atached to UPIU header, copy it in
   if ((pupiu->aux_data_len > 0) && (pupiu->aux_data_buf != NULL)) {
      memcpy (dest+16, pupiu->aux_data_buf, pupiu->aux_data_len);
   }
}


// Decode the response UPIU
void ufs_utp_decode_upiu (uint32_t *dest_in, upiu_item_t *pupiu)
{
   uint8_t *dest = (uint8_t *)dest_in;
   pupiu->type = *dest++;
   pupiu->flags = *dest++;
   pupiu->lun = *dest++;
   pupiu->task_tag = *dest++;
   pupiu->cmd_set_type = *dest++ & 0x03;
   pupiu->query_fnc = *dest++;
   pupiu->response = *dest++;
   pupiu->status = *dest++;
   dest += 2;
   pupiu->data_segment_len = *dest++ << 8;
   pupiu->data_segment_len |= *dest++;

   if (pupiu->type == UPIU_TYPE_RESPONSE) {
      *dest++ = pupiu->data_residual_len << 24;
      *dest++ |= pupiu->data_residual_len << 16;
      *dest++ |= pupiu->data_residual_len << 8;
      *dest++ |= pupiu->data_residual_len;
   }

   memcpy (pupiu->param, dest, 16);       // Op Specific field -
                                          // CDB for command, 
                                          // Parameter for management

   if (pupiu->type != UPIU_TYPE_RESPONSE) {
      dest += 4;        // Reserved address is after Transaction specific field
   }
   // If there are more data atached to UPIU header, copy it 
   if ((pupiu->aux_data_len > 0) && (pupiu->aux_data_buf != NULL)) {
      memcpy (pupiu->aux_data_buf, dest + 16, pupiu->aux_data_len);
   }
}


// Assembly of the transfer request
int32_t ufs_utp_submit_utrd (ufs_host_t *hba, utrd_item_t *pinfo)
{
   // Build UTRD into the memory first
   uint32_t *pt;
   uint32_t prdt_len;
   uint32_t prdt_doffset;
   uint32_t prdt_ents;
   uint32_t i;

   // Calculate number of entries required
   prdt_ents = pinfo->data_xfer_len / PRDT_DBC_MAX;
   if (pinfo->data_xfer_len % PRDT_DBC_MAX) {
      prdt_ents++;
   }
   
   // Transfer size check
   if (prdt_ents > MAX_PRDT_ENTRIES) {
      ufs_error_log(hba, 0x0007);
      return -EINVAL;
   }

   pt = pinfo->utp_xfr_desc_ptr;

   *pt++ = ENDIAN_ADJ_32(((pinfo->cmd_type & 0xf) << 28) | 
                         ((pinfo->data_dir & 0x3) << 25) |
                         ((pinfo->interrupt & 0x1) << 24));
   *pt++ = 0;        // Reserved field
   *pt++ = 0xf;      // Overall command status, set to 0 at the start
   *pt++ = 0;        // Reserved field
   *pt++ = ENDIAN_ADJ_32(pinfo->utp_cmd_desc_phy & 0xffffffff);            
                     // Lower 32 bits
   *pt++ = ENDIAN_ADJ_32((pinfo->utp_cmd_desc_phy >> 32) & 0xffffffff);    
                     // Upper 32 bits
   *pt++ = ENDIAN_ADJ_32((((pinfo->resp_upiu_offset / 4) << 16) & 0xffff0000) |
                          ((pinfo->resp_upiu_len / 4 + 
                                (pinfo->resp_upiu_len & 0x03 ? 1 : 0)) & 0x0000ffff));
   *pt++ = ENDIAN_ADJ_32((((pinfo->prdt_offset / 4) << 16) & 0xffff0000) | 
                          (prdt_ents & 0x0000ffff));

   // Build a command descriptor
   pt = pinfo->utp_cmd_desc_ptr;
   ufs_utp_build_upiu (pt, &pinfo->req_upiu);

   // Build the Physical Region Description Table 
   prdt_len = pinfo->data_xfer_len;
   pt = pinfo->utp_cmd_desc_ptr + pinfo->prdt_offset / 4;
   i = 0;
   prdt_doffset = 0;

   if (pinfo->data_dir != UTRD_DIR_NODATA)
   {
      while(1) {
         *pt++ = (pinfo->data_buf_phy + prdt_doffset) & 0xffffffff;
         *pt++ = ((pinfo->data_buf_phy + prdt_doffset) >> 32) & 0xffffffff;
         *pt++ = 0;        // Reserved field
         *pt++ = prdt_len > PRDT_DBC_MAX ? PRDT_DBC_MAX - 1 : (prdt_len - 1);
         if (prdt_len <= PRDT_DBC_MAX) {
            break;
         }
         prdt_len -= PRDT_DBC_MAX;
         prdt_doffset += PRDT_DBC_MAX;
         if (i++ > MAX_PRDT_ENTRIES) {
            ufs_error_log(hba, 0x0006);
            return -EINVAL;
         }
      } 
   }

   MEMORY_BARRIER();

   // Trigger the transfer by write to doorbell register
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTRLDBR, pinfo->utp_doorbell_bit);

   MEMORY_BARRIER();
   return EOK;
}


// Wait for a UTRD to complete using polling method
int32_t ufs_utp_poll_utrd_complete (ufs_host_t *hba, utrd_item_t *pinfo)
{
   // Poll the doorbell register until the corresponding bit is 0
   uint32_t cnt = HCI_UTRD_POLL_TIMEOUT;

   while (cnt != 0) {
      if (! (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_UTRLDBR) & 
             pinfo->utp_doorbell_bit)) {
         return EOK;
      }
      cnt--;
   }

   // Timeout has occurred
   ufs_error_log(hba, 0x0004);
   return -ETIME;
}


// Decode of the transfer request response
void ufs_utp_decode_utrd_resp (ufs_host_t *hba, utrd_item_t *pinfo)
{
   // Build UTRD into the memory first
   uint32_t *pt;
   uint8_t cmd_status;

   pt = pinfo->utp_cmd_desc_ptr;

   // Read out the overall command status field
   cmd_status = pt[2] & 0xff;

   if (cmd_status == OCS_SUCCESS) 
   {
      // Decode the Response UPIU
      pt += pinfo->resp_upiu_offset;
   }
}


// Abort a transfer by clearing a UTRD doorbell register
void ufs_utp_abort_utrd (ufs_host_t *hba, utrd_item_t *pinfo)
{
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTRLCLR, pinfo->utp_doorbell_bit);
}


// Wait for a UTMRD to complete using polling method
int32_t ufs_utp_poll_utmrd_complete (ufs_host_t *hba, utmrd_item_t *pinfo)
{
   // Poll the doorbell register until the corresponding bit is 0
   uint32_t cnt = HCI_UTMRD_POLL_TIMEOUT;

   while (cnt != 0) {
      if (! (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_UTMRLDBR) & 
             pinfo->utp_doorbell_bit)) {
         return EOK;
      }
   }

   // Timeout has occurred
   ufs_error_log(hba, 0x0005);
   return -ETIME;
}


// Abort a transfer by clearing a UTMRD doorbell register
void ufs_utp_abort_utmrd (ufs_host_t *hba, utmrd_item_t *pinfo)
{
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTMRLCLR, pinfo->utp_doorbell_bit);
}


// Making an assumption that the controller ID
// and is programmed into the device data structure
int32_t ufs_utp_init (ufs_host_t *hba)
{
   uint32_t tout;
   int32_t rc = EOK;
   // Look up the base address for the controller and program it
   hba->ufs_hci_addr = HWIO_UFSHCI_BASE_ADDR;

   // Clear the debug register
   hba->last_failure = 0;
   hba->failure_cnt = 0;

   // Start the task counter at 0
   hba->ufs_task_cnt = 0;

   // Call the BSP to enable the clock
   ufs_bsp_clk_set (hba->ufs_core_id, UFS_CLOCK_MODE_ON);

   // Detect to see if the UFS link is already established, if so, skip the 
   // init routine
   // First, check to see if HCE bit is 1, than see if Device Present bit is 1
   /*
   if ((HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_HCE) & 0x01) == 0x01 &&
       (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_HCS) & 0x01) == 0x01) {
      goto SKIP_PHY_INIT_LINK_STARTUP;
   }
   */

#ifndef UFS_SKIP_PHY_INIT
#ifndef RUMI

   ufs_bsp_enable_symbol_clk ();
   // Vendor specific configuration
   // Set the PHY softreset bit
   //HWIO_REG_OUTM (hba->ufs_hci_addr, VENSPEC_UFS_CFG1, 
   //   BMSK_UTP_PHY_SOFT_RESET, BMSK_UTP_PHY_SOFT_RESET); -> Wrong usage, needs HWIO_REG_OUTF
                  
   *(uint32_t*)0xFC5940DC= 0x52E;   
   
   ufs_bsp_busy_wait(1000);               
   // Enable Sata PHY LDO_EN
   // HWIO_OUTF(GCC_SATA_PHY_LDO_EN, LDO_ENABLE, 1);                 
   *(uint32_t*)0xFC401E08= 0x1; 
   
   // Disable the M-PHY config routine becuse there are no MPHY today
   rc = ufs_preinit_mphy_configure (hba);
   if (rc < 0) {
      ufs_error_log(hba, 0x001d);
      return rc;
   }

   // Clear the PHY softreset bit
   //HWIO_REG_OUTM(hba->ufs_hci_addr, VENSPEC_UFS_CFG1, BMSK_UTP_PHY_SOFT_RESET, 0); -> Wrong usage, needs HWIO_REG_OUTF
   *(uint32_t*)0xFC5940DC= 0x52C;   

   ufs_bsp_busy_wait(1000);

   // Set the SERDES_START
   HWIO_REG_OUTM (hba->ufs_hci_addr, PHY_PHY_START, 1, 1);
   ufs_bsp_busy_wait(100);
   
   // Wait until PCS_READY is set
   tout = UFS_PHY_PCS_READY_TIMEOUT;
   while (!(HWIO_REG_IN(hba->ufs_hci_addr, PHY_PCS_READY_STATUS) & 0x01)) {
      if (tout-- == 0) {
         ufs_error_log(hba, 0x01e);
         return -EIO;
      }
   }

   // Reset the controller by setting HCE register to 0
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_HCE, 0);
   
#else 
   ufs_phy_init(RUMI_PHY_BASE_ADDRESS);
   ufs_serdes_bypass_on(RUMI_PHY_BASE_ADDRESS);
#endif
#endif

   // End of vandor specific config

   // Enable the host controller
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_HCE, BMSK_HCE);

   // Wait until controller is enabled
   tout = HCI_ENABLE_TIMEOUT;
   while (--tout) {
      if (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_HCE) & BMSK_HCE) {
         break;
      }
   }
   if (tout == 0) {
      ufs_error_log(hba, 0x0002);
      return -EIO;
   }

#ifndef UFS_SKIP_PHY_INIT
   // Post setting of the HCE register, update the sys clock frequency
   
#ifndef RUMI
   // Wait until TX_FSM_State attribute is in HIBERN8
   tout = UFS_TX_FSM_STATE_TIMEOUT;
   while (1) {
      uint32_t val;
      // Read the TX_FSM_Sate
      rc = ufs_utp_uic_getset (hba, UICCMDR_DME_GET, (TX_FSM_State<<16), &val);   //Changed
      if (rc < 0) {
         ufs_error_log(hba, 0x0018);
         return -EIO;
      }
      if (tout-- == 0) {
         ufs_error_log(hba, 0x0019);
         return -EIO;
      }

      if (val == TX_FSM_State_HIBERN8) {
         break;
      }
   }
#endif

   // Update this value according to the cc_ufs_sys_clk frequency
   HWIO_REG_OUT (hba->ufs_hci_addr, VENSPEC_UFS_SYS1CLK_1US, UFS_SYS1CLK_1US_VAL);

   // Update this value according to the symble clock frequency
   HWIO_REG_OUT (hba->ufs_hci_addr, VENSPEC_TX_SYMBOL_CLK_NS_US, 0x4001);        // RUMI setup
//   HWIO_REG_OUTM (hba->ufs_hci_addr, VENSPEC_TX_SYMBOL_CLK_NS_US, 
//                  BMSK_TX_SYMBOL_CLK_1US_REG, 
//                  UFS_TX_SYMBOL_CLK_1US_VAL << SHFT_TX_SYMBOL_CLK_1US_REG);

//   HWIO_REG_OUTM (hba->ufs_hci_addr, VENSPEC_TX_SYMBOL_CLK_NS_US, 
//                  BMSK_CLK_NS_REG, UFS_CLK_NS_REG_VAL << SHFT_CLK_NS_REG);

   HWIO_REG_OUT (hba->ufs_hci_addr, VENSPEC_REG_PA_LINK_STARTUP_TIMER, 
                 UFS_PA_LINK_STARTUP_TIMER_VAL);
#endif

   // Not using interrupt, so not setting the IE register
   // Retry number of times for link startup
   tout = UFS_LINK_STARTUP_RETRY;
   do {
      // Send DME_LINKSTARTUP command
      rc = ufs_utp_send_uic (hba, UICCMDR_DME_LINKSTARTUP);
      if (rc == 0) {
         // First linkstartup ok, continue
         break;
      }
      ufs_error_log(hba, 0x0003);
      // Check IS.ULSS bit to see if UFS device has sent the startup sequence
      while (!(HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_IS) & BMSK_ULSS)) {
         if (tout-- == 0) {
            ufs_error_log(hba, 0x000a);
            return -EIO;
         }
      }
      // Send DME_LINKSTARTUP command again
      rc = ufs_utp_send_uic (hba, UICCMDR_DME_LINKSTARTUP);
      if (rc < 0) {
         // Failure here is a LinkStartup Fail
         ufs_error_log(hba, 0x000b);
         return -EIO;
      }
   } while(0);
   
   

//SKIP_PHY_INIT_LINK_STARTUP:
   // May need to setup the UTRIACR register with timeout/threshold
   // value if aggregation of interrupt bits are used
   
   // Fill in the task management list and transfer list address
   // For the environment in use, the physical address is 1:1 mapping
   hba->ufs_req_list_phy = GET_PHY_ADDR(&transfer_request_list_buf);

   // The array is allocated for double amount of space, find the 
   // 1k aligned location 
   hba->ufs_req_list_phy = (hba->ufs_req_list_phy + 1023) & (~1023);
   // Do the same for logical address
   //hba->ufs_req_list_ptr = &transfer_request_list_buf[0];
   hba->ufs_req_list_ptr = (uint8_t *)(uint32_t)hba->ufs_req_list_phy;
   //hba->ufs_req_list_ptr = (((uint32_t)&transfer_request_list_buf) + 1023) & ~1023;

   // The management request buffer is just 1k after the 
   // transfer request buffer
   hba->ufs_mgr_list_phy = hba->ufs_req_list_phy + 1024;
   hba->ufs_mgr_list_ptr = hba->ufs_req_list_ptr + 1024;


   // Program the physical address into the register, in this case
   // both the physical address and logical address is identical
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTRLBA, GET_PHY_ADDR_L(hba->ufs_req_list_phy));
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTRLBAU, GET_PHY_ADDR_H(hba->ufs_req_list_phy));

   // Managment list 
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTMRLBA, GET_PHY_ADDR_L(hba->ufs_mgr_list_phy));
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTMRLBAU, GET_PHY_ADDR_H(hba->ufs_mgr_list_phy));

   // More UIC command required?
   
   // Check to make sure the device is detected, wait until it is
   tout = HCI_LINK_STARTUP_TIMEOUT;
   while (--tout) {
      if (HWIO_REG_IN (hba->ufs_hci_addr, UFSHCI_HCS) & BMSK_DP) {
         break;
      }
   }

   // Enable the UTP transfer request list
   HWIO_REG_OUT (hba->ufs_hci_addr, UFSHCI_UTRLRSR, UFS_UTRD_DOORBELL_CH);

   // Switch to HS gear
#ifdef UFS_SWITCH_TO_HS_GEAR
   rc = ufs_utp_gear_sw (hba);
#endif

   return rc;
}


// Fill in an UTRD with default values
int32_t ufs_utp_build_std_utrd (ufs_host_t *hba, utrd_item_t *pinfo,
                            uint32_t req_dlen, uint32_t resp_dlen)
{
   // Empty UTRD structure first
   memset (pinfo, 0, sizeof (utrd_item_t));

   pinfo->utrd_desc_ptr = hba->ufs_req_list_ptr;

   // Minimal alignment requirement is 64 bytes
   // Request descriptor is at the base address of the request list 
   pinfo->utp_xfr_desc_phy = hba->ufs_req_list_phy;
   pinfo->utp_xfr_desc_ptr = (uint32_t *)(uint32_t)(pinfo->utrd_desc_ptr);
   // Offset the first command descriptor 256 bytes from the request descriptor
   pinfo->utp_cmd_desc_phy = hba->ufs_req_list_phy + 256;
   pinfo->utp_cmd_desc_ptr = (uint32_t *)(uint32_t)(pinfo->utrd_desc_ptr + 256);

   pinfo->req_upiu_len = UPIU_STD_HDR_LEN + req_dlen;
   pinfo->resp_upiu_len = UPIU_STD_HDR_LEN + resp_dlen;

   // Make sure the RESP UPIU is adjusted to DWORD boundary
   pinfo->resp_upiu_offset = (pinfo->req_upiu_len & (~0x03)) + 
                             ((pinfo->req_upiu_len & 0x03) ? 4 : 0);
   pinfo->prdt_offset = pinfo->resp_upiu_offset + pinfo->resp_upiu_len;

   // Adjust PRDT offset to DWORD boundary
   pinfo->prdt_offset = (pinfo->prdt_offset & ~0x03) + 
                        ((pinfo->prdt_offset & 0x03) ? 4 : 0);

   pinfo->prdt_len = 16;                  // Single entry
   pinfo->utp_doorbell_bit = UFS_UTRD_DOORBELL_CH;

   return EOK;
}


#ifndef UFS_SKIP_PHY_INIT
// QCOM UFS MPHY spcific configurations
static int32_t ufs_preinit_mphy_configure (ufs_host_t *hba)
{
   int i;
   uint32_t reg;
   
   // Mphy init table
   const struct ufs_mphy_init_item ufs_mphy_init_table[] = {
   { HWIO_UFS_UFS_PHY_POWER_DOWN_CONTROL_ADDR,                           0x00,   0x01},
   { HWIO_UFS_QSERDES_COM_PLL_CRCTRL_ADDR,                               0x00,   0xFF},
   { HWIO_UFS_QSERDES_COM_PLL_CNTRL_ADDR,                                0x00,   0x24},
   { HWIO_UFS_QSERDES_COM_SYSCLK_EN_SEL_ADDR,                            0x00,   0x08},
   { HWIO_UFS_QSERDES_COM_SYS_CLK_CTRL_ADDR,                             0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_PLL_CLKEPDIV_ADDR,                             0x00,   0x03},
   { HWIO_UFS_QSERDES_COM_DEC_START1_ADDR,                               0x00,   0x82},
   { HWIO_UFS_QSERDES_COM_DEC_START2_ADDR,                               0x00,   0x03},
   { HWIO_UFS_QSERDES_COM_DIV_FRAC_START1_ADDR,                          0x00,   0x80},
   { HWIO_UFS_QSERDES_COM_DIV_FRAC_START2_ADDR,                          0x00,   0x80},
   { HWIO_UFS_QSERDES_COM_DIV_FRAC_START3_ADDR,                          0x00,   0x10},
   { HWIO_UFS_QSERDES_COM_PLLLOCK_CMP1_ADDR,                             0x00,   0xff},
   { HWIO_UFS_QSERDES_COM_PLLLOCK_CMP2_ADDR,                             0x00,   0x67},
   { HWIO_UFS_QSERDES_COM_PLLLOCK_CMP3_ADDR,                             0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_PLLLOCK_CMP_EN_ADDR,                           0x00,   0x01},
   { HWIO_UFS_QSERDES_COM_RESETSM_CNTRL_ADDR,                            0x00,   0x10},
   { HWIO_UFS_QSERDES_COM_PLL_RXTXEPCLK_EN_ADDR,                         0x00,   0x10},
   { HWIO_UFS_QSERDES_RX0_PWM_CNTRL1_ADDR,                               0x00,   0x43},
   { HWIO_UFS_QSERDES_RX1_PWM_CNTRL1_ADDR,                               0x00,   0x43},
   { HWIO_UFS_QSERDES_RX0_CDR_CONTROL_ADDR,                              0x00,   0xf2},
   { HWIO_UFS_QSERDES_RX0_CDR_CONTROL_HALF_ADDR,                         0x00,   0x2a},
   { HWIO_UFS_QSERDES_RX0_CDR_CONTROL_QUARTER_ADDR,                      0x00,   0x2a},
   { HWIO_UFS_QSERDES_RX1_CDR_CONTROL_ADDR,                              0x00,   0xf2},
   { HWIO_UFS_QSERDES_RX1_CDR_CONTROL_HALF_ADDR,                         0x00,   0x2a},
   { HWIO_UFS_QSERDES_RX1_CDR_CONTROL_QUARTER_ADDR,                      0x00,   0x2a},
   { HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL_ADDR,                             0x00,   0xC0},
   { HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL_ADDR,                             0x00,   0xC0},
   { HWIO_UFS_QSERDES_RX0_SIGDET_CNTRL2_ADDR,                            0x00,   0x07},
   { HWIO_UFS_QSERDES_RX1_SIGDET_CNTRL2_ADDR,                            0x00,   0x07},
   { HWIO_UFS_UFS_PHY_PWM_G1_CLK_DIVIDER_ADDR,                           0x00,   0x50},
   { HWIO_UFS_UFS_PHY_PWM_G2_CLK_DIVIDER_ADDR,                           0x00,   0x28},
   { HWIO_UFS_UFS_PHY_PWM_G3_CLK_DIVIDER_ADDR,                           0x00,   0x10},
   { HWIO_UFS_UFS_PHY_PWM_G4_CLK_DIVIDER_ADDR,                           0x00,   0x08},
   { HWIO_UFS_UFS_PHY_CORECLK_PWM_G1_CLK_DIVIDER_ADDR,                   0x00,   0xa8},
   { HWIO_UFS_UFS_PHY_CORECLK_PWM_G2_CLK_DIVIDER_ADDR,                   0x00,   0x54},
   { HWIO_UFS_UFS_PHY_CORECLK_PWM_G3_CLK_DIVIDER_ADDR,                   0x00,   0x2a},
   { HWIO_UFS_UFS_PHY_CORECLK_PWM_G4_CLK_DIVIDER_ADDR,                   0x00,   0x15},
   { HWIO_UFS_UFS_PHY_OMC_STATUS_RDVAL_ADDR,                             0x00,   0xff},
   { HWIO_UFS_UFS_PHY_LINE_RESET_TIME_ADDR,                              0x00,   0x1f},
   { HWIO_UFS_UFS_PHY_LINE_RESET_GRANULARITY_ADDR,                       0x00,   0x00},
   { HWIO_UFS_UFS_PHY_TSYNC_RSYNC_CNTL_ADDR,                             0x00,   0x03},
   { HWIO_UFS_UFS_PHY_PLL_CNTL_ADDR,                                     0x00,   0x01},
   { HWIO_UFS_UFS_PHY_TX_LARGE_AMP_DRV_LVL_ADDR,                         0x00,   0x0f},
   { HWIO_UFS_UFS_PHY_TX_SMALL_AMP_DRV_LVL_ADDR,                         0x00,   0x1a},
   { HWIO_UFS_UFS_PHY_TX_LARGE_AMP_POST_EMP_LVL_ADDR,                    0x00,   0x00},
   { HWIO_UFS_UFS_PHY_TX_SMALL_AMP_POST_EMP_LVL_ADDR,                    0x00,   0x00},
   { HWIO_UFS_UFS_PHY_CFG_CHANGE_CNT_VAL_ADDR,                           0x00,   0x09},
   { HWIO_UFS_UFS_PHY_RX_SYNC_WAIT_TIME_ADDR,                            0x00,   0x30},
   { HWIO_UFS_UFS_PHY_TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR,        0x00,   0x01},
   { HWIO_UFS_UFS_PHY_RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY_ADDR,        0x00,   0x08},
   { HWIO_UFS_UFS_PHY_TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR,        0x00,   0x01},
   { HWIO_UFS_UFS_PHY_RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY_ADDR,        0x00,   0x0f},
   { HWIO_UFS_UFS_PHY_TX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR,           0x00,   0x04},
   { HWIO_UFS_UFS_PHY_RX_MIN_SAVE_CONFIG_TIME_CAPABILITY_ADDR,           0x00,   0xc8},
   { HWIO_UFS_UFS_PHY_RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY_ADDR,       0x00,   0x10},
   { HWIO_UFS_UFS_PHY_RX_MIN_ACTIVATETIME_CAPABILITY_ADDR,               0x00,   0x01},
   { HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN1_ADDR,                              0x00,   0x07},
   { HWIO_UFS_QSERDES_RX0_RX_EQ_GAIN2_ADDR,                              0x00,   0x07},
   { HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN1_ADDR,                              0x00,   0x07},
   { HWIO_UFS_QSERDES_RX1_RX_EQ_GAIN2_ADDR,                              0x00,   0x07},
   { HWIO_UFS_QSERDES_RX0_CDR_CONTROL3_ADDR,                             0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_CDR_CONTROL3_ADDR,                             0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_PLL_IP_SETI_ADDR,                              0x00,   0x01},
   { HWIO_UFS_QSERDES_COM_PLL_CP_SETI_ADDR,                              0x00,   0x3f},
   { HWIO_UFS_QSERDES_COM_PLL_IP_SETP_ADDR,                              0x00,   0x01},
   { HWIO_UFS_QSERDES_COM_PLL_CP_SETP_ADDR,                              0x00,   0x01},
   { HWIO_UFS_QSERDES_COM_RES_TRIM_OFFSET_ADDR,                          0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_BGTC_ADDR,                                     0x00,   0x0f},
   { HWIO_UFS_QSERDES_COM_PLL_AMP_OS_ADDR,                               0x00,   0x00},
   { HWIO_UFS_QSERDES_TX0_TX_DRV_LVL_ADDR,                               0x00,   0x0f},
   { HWIO_UFS_QSERDES_TX1_TX_DRV_LVL_ADDR,                               0x00,   0x0f},
   { HWIO_UFS_QSERDES_TX0_BIST_MODE_LANENO_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_TX1_BIST_MODE_LANENO_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR,                         0x00,   0x04},
   { HWIO_UFS_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR,                         0x00,   0x04},
   { HWIO_UFS_QSERDES_TX0_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR,              0x00,   0x05},
   { HWIO_UFS_QSERDES_TX1_HIGHZ_TRANSCEIVEREN_BIAS_EN_ADDR,              0x00,   0x05},
   { HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_MSB_ADDR,                 0x00,   0x07},
   { HWIO_UFS_UFS_PHY_TIMER_100US_SYSCLK_STEPS_LSB_ADDR,                 0x00,   0x80},
   { HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_MSB_ADDR,                 0x00,   0x27},
   { HWIO_UFS_UFS_PHY_TIMER_20US_CORECLK_STEPS_LSB_ADDR,                 0x00,   0x00},
   { HWIO_UFS_UFS_PHY_CONTROLSYM_ONE_HOT_DISABLE_ADDR,                   0x00,   0x00},
   { HWIO_UFS_UFS_PHY_RETIME_BUFFER_EN_ADDR,                             0x00,   0x01},
   { HWIO_UFS_UFS_PHY_TX_HSGEAR_CAPABILITY_ADDR,                         0x00,   0x03},
   { HWIO_UFS_UFS_PHY_TX_PWMGEAR_CAPABILITY_ADDR,                        0x00,   0x04},
   { HWIO_UFS_UFS_PHY_TX_AMPLITUDE_CAPABILITY_ADDR,                      0x00,   0x03},
   { HWIO_UFS_UFS_PHY_TX_EXTERNALSYNC_CAPABILITY_ADDR,                   0x00,   0x01},
   { HWIO_UFS_UFS_PHY_TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY_ADDR,     0x00,   0x01},
   { HWIO_UFS_UFS_PHY_TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY_ADDR,       0x00,   0x01},
   { HWIO_UFS_UFS_PHY_TX_REF_CLOCK_SHARED_CAPABILITY_ADDR,               0x00,   0x01},
   { HWIO_UFS_UFS_PHY_TX_HIBERN8TIME_CAPABILITY_ADDR,                    0x00,   0x01},
   { HWIO_UFS_UFS_PHY_RX_HSGEAR_CAPABILITY_ADDR,                         0x00,   0x03},
   { HWIO_UFS_UFS_PHY_RX_PWMGEAR_CAPABILITY_ADDR,                        0x00,   0x04},
   { HWIO_UFS_UFS_PHY_RX_HS_UNTERMINATED_CAPABILITY_ADDR,                0x00,   0x01},
   { HWIO_UFS_UFS_PHY_RX_LS_TERMINATED_CAPABILITY_ADDR,                  0x00,   0x01},
   { HWIO_UFS_UFS_PHY_RX_REF_CLOCK_SHARED_CAPABILITY_ADDR,               0x00,   0x01},
   { HWIO_UFS_UFS_PHY_RX_HS_G1_SYNC_LENGTH_CAPABILITY_ADDR,              0x00,   0x48},
   { HWIO_UFS_UFS_PHY_RX_HS_G1_PREPARE_LENGTH_CAPABILITY_ADDR,           0x00,   0x0f},
   { HWIO_UFS_UFS_PHY_RX_LS_PREPARE_LENGTH_CAPABILITY_ADDR,              0x00,   0x09},
   { HWIO_UFS_UFS_PHY_RX_HIBERN8TIME_CAPABILITY_ADDR,                    0x00,   0x01},
   { HWIO_UFS_UFS_PHY_RX_HS_G2_SYNC_LENGTH_CAPABILITY_ADDR,              0x00,   0x48},
   { HWIO_UFS_UFS_PHY_RX_HS_G3_SYNC_LENGTH_CAPABILITY_ADDR,              0x00,   0x48},
   { HWIO_UFS_UFS_PHY_RX_HS_G2_PREPARE_LENGTH_CAPABILITY_ADDR,           0x00,   0x0f},
   { HWIO_UFS_UFS_PHY_RX_HS_G3_PREPARE_LENGTH_CAPABILITY_ADDR,           0x00,   0x0f},
   { HWIO_UFS_QSERDES_TX0_CLKBUF_ENABLE_ADDR,                            0x00,   0x09},
   { HWIO_UFS_QSERDES_TX0_RESET_TSYNC_EN_ADDR,                           0x00,   0x01},
   { HWIO_UFS_QSERDES_TX0_RES_CODE_ADDR,                                 0x00,   0x00},
   { HWIO_UFS_QSERDES_TX0_SERDES_BYP_EN_OUT_ADDR,                        0x00,   0x00},
   { HWIO_UFS_QSERDES_TX0_REC_DETECT_LVL_ADDR,                           0x00,   0x00},
   { HWIO_UFS_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR,               0x00,   0x00},
   { HWIO_UFS_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_RX0_AUX_CONTROL_ADDR,                              0x00,   0x00},
   { HWIO_UFS_QSERDES_RX0_AUX_DATA_TCODE_ADDR,                           0x00,   0x00},
   { HWIO_UFS_QSERDES_RX0_RCLK_AUXDATA_SEL_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_RX0_EQ_CONTROL_ADDR,                               0x00,   0x00},
   { HWIO_UFS_QSERDES_RX0_RX_IQ_RXDET_EN_ADDR,                           0x00,   0x73},
   { HWIO_UFS_QSERDES_RX0_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR,               0x00,   0x05},
   { HWIO_UFS_QSERDES_RX0_CDR_FREEZE_UP_DN_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_RX0_UFS_CNTRL_ADDR,                                0x00,   0x00},
   { HWIO_UFS_QSERDES_RX0_CDR_CONTROL_EIGHTH_ADDR,                       0x00,   0x22},
   { HWIO_UFS_QSERDES_RX0_UCDR_FO_GAIN_ADDR,                             0x00,   0x0a},
   { HWIO_UFS_QSERDES_RX0_UCDR_SO_GAIN_ADDR,                             0x00,   0x06},
   { HWIO_UFS_QSERDES_RX0_UCDR_SO_SATURATION_AND_ENABLE_ADDR,            0x00,   0x35},
   { HWIO_UFS_QSERDES_RX0_UCDR_FO_TO_SO_DELAY_ADDR,                      0x00,   0x00},
   { HWIO_UFS_QSERDES_TX1_CLKBUF_ENABLE_ADDR,                            0x00,   0x09},
   { HWIO_UFS_QSERDES_TX1_RESET_TSYNC_EN_ADDR,                           0x00,   0x01},
   { HWIO_UFS_QSERDES_TX1_RES_CODE_ADDR,                                 0x00,   0x00},
   { HWIO_UFS_QSERDES_TX1_SERDES_BYP_EN_OUT_ADDR,                        0x00,   0x00},
   { HWIO_UFS_QSERDES_TX1_REC_DETECT_LVL_ADDR,                           0x00,   0x00},
   { HWIO_UFS_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR,               0x00,   0x00},
   { HWIO_UFS_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_AUX_CONTROL_ADDR,                              0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_AUX_DATA_TCODE_ADDR,                           0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_RCLK_AUXDATA_SEL_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_EQ_CONTROL_ADDR,                               0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_RX_IQ_RXDET_EN_ADDR,                           0x00,   0x73},
   { HWIO_UFS_QSERDES_RX1_RX_TERM_HIGHZ_CM_AC_COUPLE_ADDR,               0x00,   0x05},
   { HWIO_UFS_QSERDES_RX1_CDR_FREEZE_UP_DN_ADDR,                         0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_UFS_CNTRL_ADDR,                                0x00,   0x00},
   { HWIO_UFS_QSERDES_RX1_CDR_CONTROL_EIGHTH_ADDR,                       0x00,   0x22},
   { HWIO_UFS_QSERDES_RX1_UCDR_FO_GAIN_ADDR,                             0x00,   0x0a},
   { HWIO_UFS_QSERDES_RX1_UCDR_SO_GAIN_ADDR,                             0x00,   0x06},
   { HWIO_UFS_QSERDES_RX1_UCDR_SO_SATURATION_AND_ENABLE_ADDR,            0x00,   0x35},
   { HWIO_UFS_QSERDES_RX1_UCDR_FO_TO_SO_DELAY_ADDR,                      0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_CMN_MODE_ADDR,                                 0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_IE_TRIM_ADDR,                                  0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_IP_TRIM_ADDR,                                  0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_CORE_CLK_IN_SYNC_SEL_ADDR,                     0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR,                      0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_PLL_TEST_UPDN_RESTRIMSTEP_ADDR,                0x00,   0x00},
   { HWIO_UFS_QSERDES_COM_FAUX_EN_ADDR,                                  0x00,   0x00},
      {0,0,0}};

   // Load all the items from the ufs_mphy_init_table into mphy registers

   for (i = 0; i < (sizeof(ufs_mphy_init_table)/sizeof(struct ufs_mphy_init_item)); i++){
         reg = ufs_mphy_init_table[i].val;
         out_dword((ufs_mphy_init_table[i].reg + hba->ufs_hci_addr), reg);
         //tout = ufs_mphy_init_table[i].dly;
   }
   return EOK;
}
#endif 

#ifdef RUMI
void RUMI_UFS_HCI_Set(uint32 baseAddr, uint32 offset, int32 value)
{
   out_dword(baseAddr + offset, value);
}


int32 RUMI_UFS_HCI_Get(uint32 baseAddr, uint32 offset)
{
   return in_dword(baseAddr + offset);
}

static void ufs_phy_init(uint32 baseAddr)
{
   // QMP PCIE PHY 28nm Power UP Sequences 100MHz Power-up Sequence QRBTC
    
    //sb_remap(barNum, R3PC_UFS_WRAPPER);
    // d.s PCIE_PHY_SW_RESET                     %LONG 0x01
    RUMI_UFS_HCI_Set(baseAddr, 0x7600, 0x00000001);
    
    // d.s QRBTC_COM_BIASEN                      %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7434, 0x00000003);
    // d.s QRBTC_COM_CMNMODE                     %LONG 0x08
    RUMI_UFS_HCI_Set(baseAddr, 0x7414, 0x00000008);
    // d.s QRBTC_COM_BYPASSPLLLOCK               %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7480, 0x00000000);
    // d.s QRBTC_COM_FORCEPLLLOCK                %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7468, 0x00000000);
    // d.s QRBTC_COM_BYPASSRESTRIM               %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7484, 0x00000000);
    // d.s QRBTC_COM_VCOSEL                      %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7420, 0x00000000);
    // d.s QRBTC_COM_PLLIPSETI                   %LONG 0x3F
    RUMI_UFS_HCI_Set(baseAddr, 0x742c, 0x0000003f);
    // d.s QRBTC_COM_PLLCPSETI                   %LONG 0x0F
    RUMI_UFS_HCI_Set(baseAddr, 0x7438, 0x0000000f);
    // d.s QRBTC_COM_PLLIPSETP                   %LONG 0x3F
    RUMI_UFS_HCI_Set(baseAddr, 0x7444, 0x0000003f);
    // d.s QRBTC_COM_PLLCPSETP                   %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7448, 0x00000000);
    // d.s QRBTC_COM_PLL_IBOOST                  %LONG 0x00  ;change to 0 once bandgap ext res fix
    RUMI_UFS_HCI_Set(baseAddr, 0x747c, 0x00000000);
    // d.s QRBTC_COM_PLLCPLIN                    %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7518, 0x00000000);
    // d.s QRBTC_COM_SYSCLKHSTEN                 %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x744c, 0x00000000);
    // d.s QRBTC_COM_SYSCLKSEL                   %LONG 0x02
    RUMI_UFS_HCI_Set(baseAddr, 0x7450, 0x00000002);
    
    
    // d.s QRBTC_COM_SYSCLKEN                    %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7460, 0x00000003);
    // d.s QRBTC_COM_SYSCLKBUFEN                 %LONG 0x01
    RUMI_UFS_HCI_Set(baseAddr, 0x7404, 0x00000001);
    // d.s QRBTC_COM_CLKBUFREN                   %LONG 0x03  ; was 3
    RUMI_UFS_HCI_Set(baseAddr, 0x743c, 0x00000003);
    // d.s QRBTC_COM_CLKBUFLEN                   %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7440, 0x00000003);
    // d.s QRBTC_COM_PLLDIV2SEL                  %LONG 0x02
    RUMI_UFS_HCI_Set(baseAddr, 0x745c, 0x00000002);
    // d.s QRBTC_COM_PLLSYSCLKD2                 %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x751c, 0x00000000);
    // d.s QRBTC_COM_PLLLOCK_CMPEN               %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7478, 0x00000000);
    // d.s QRBTC_COM_BYPASSVCOCAL                %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7488, 0x00000000);
    
    // d.s QRBTC_COM_SYSCLKTERMSEL               %LONG 0x01 
    RUMI_UFS_HCI_Set(baseAddr, 0x740c, 0x00000001);
    // d.s QRBTC_COM_DECSTART1                   %LONG 0x99
    RUMI_UFS_HCI_Set(baseAddr, 0x74a4, 0x00000099);
    // d.s QRBTC_COM_DECSTART2                   %LONG 0x02 
    RUMI_UFS_HCI_Set(baseAddr, 0x750c, 0x00000002);
    // d.s QRBTC_COM_DIVFRACSTART1               %LONG 0x80 
    RUMI_UFS_HCI_Set(baseAddr, 0x74ec, 0x00000080);
    // d.s QRBTC_COM_DIVFRACSTART2               %LONG 0x80 
    RUMI_UFS_HCI_Set(baseAddr, 0x74f0, 0x00000080);
    // d.s QRBTC_COM_DIVFRACSTART3               %LONG 0x04 
    RUMI_UFS_HCI_Set(baseAddr, 0x74fc, 0x00000004);
    // d.s QRBTC_COM_PLLDIV                      %LONG 0x06 
    RUMI_UFS_HCI_Set(baseAddr, 0x7424, 0x00000006);
    // d.s QRBTC_COM_PLLEN                       %LONG 0x03 
    RUMI_UFS_HCI_Set(baseAddr, 0x7408, 0x00000003);
    // d.s QRBTC_COM_PLLLOCK_CMP1                %LONG 0xff 
    RUMI_UFS_HCI_Set(baseAddr, 0x746c, 0x000000ff);
    // d.s QRBTC_COM_PLLLOCK_CMP2                %LONG 0x7f   ; was 7f
    RUMI_UFS_HCI_Set(baseAddr, 0x7470, 0x0000007f);
    // d.s QRBTC_COM_PLLLOCK_CMP3                %LONG 0x02 ; Try 05 ; was 02
    RUMI_UFS_HCI_Set(baseAddr, 0x7474, 0x00000002);
    // d.s QRBTC_COM_PLLLOCK_CMPEN               %LONG 0x01 
    RUMI_UFS_HCI_Set(baseAddr, 0x7478, 0x00000001);
    // d.s QRBTC_COM_FREQTUNEMODE                %LONG 0x01 
    RUMI_UFS_HCI_Set(baseAddr, 0x7500, 0x00000001);
    // d.s QRBTC_TXRX_PARRATE_LN1                %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x70bc, 0x00000003);
    // d.s QRBTC_TXRX_TXEN_LN1                   %LONG 0x03 
    RUMI_UFS_HCI_Set(baseAddr, 0x709c, 0x00000003);
    // d.s QRBTC_TXRX_TXHIGHZ_LN1            %LONG 0x0
    RUMI_UFS_HCI_Set(baseAddr, 0x70a0, 0x00000000);
    
    
    // d.s QRBTC_TXRX_TXDRVLVL_LN1               %LONG 0x3f 
    RUMI_UFS_HCI_Set(baseAddr, 0x70c4, 0x0000003f);
    // d.s QRBTC_TXRX_TRANDRVREN_LN1        %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x71a8, 0x00000003);
    // d.s QRBTC_TXRX_BISTMODE_LN1               %LONG 0x00
    RUMI_UFS_HCI_Set(baseAddr, 0x7010, 0x00000000);
    // d.s QRBTC_TXRX_IDLEEN_LN1                 %LONG 0x02 
    RUMI_UFS_HCI_Set(baseAddr, 0x70b0, 0x00000002);
    // d.s QRBTC_TXRX_HBWPDENABLE_LN1            %LONG 0x00 
    RUMI_UFS_HCI_Set(baseAddr, 0x7030, 0x00000000);
    // d.s QRBTC_TXRX_SECONDORDERGAIN_LN1        %LONG 0x04 
    RUMI_UFS_HCI_Set(baseAddr, 0x7000, 0x00000004);
    
    // d.s PCIE_PHY_POWER_DOWN_CONTROL           %LONG 0x01 
    RUMI_UFS_HCI_Set(baseAddr, 0x7604, 0x00000001);
    // ;d.s PCIE_PHY_POWER_STATE_CONFIG1          %LONG 0x0f ; Causes the PHY to die
    
    //; Additional Programming Needed to work around to get continuous PCLK after P1->P0 transition
    // d.s QRBTC_TXRX_RESETTSYNCEN_LN1       %LONG 0x02 
    RUMI_UFS_HCI_Set(baseAddr, 0x7044, 0x00000002);
    // d.s QRBTC_COM_PLLRXCLKEN              %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7510, 0x00000003);
    // d.s QRBTC_COM_PLLTXCLKEN              %LONG 0x01 ; Originally 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7514, 0x00000001);
    // d.s QRBTC_TXRX_CLKBUF_EN_LN1          %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x703c, 0x00000003);
    
    // d.s PCIE_PHY_SW_RESET                     %LONG 0x00 
    RUMI_UFS_HCI_Set(baseAddr, 0x7600, 0x00000000);
    
    // d.s PCIE_PHY_START                        %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7608, 0x00000003);
    
    while (0 == (RUMI_UFS_HCI_Get(baseAddr, 0x74b0) & 0x0020) ) {}
    //; If can't fix the loop - add 150us delay
    
    //; Additional Programming Needed to work around to get continuous PCLK after P1->P0 transition
    // d.s QRBTC_TXRX_RESETTSYNCEN_LN1       %LONG 0x02 
    RUMI_UFS_HCI_Set(baseAddr, 0x7044, 0x00000002);
    // d.s QRBTC_COM_PLLRXCLKEN              %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7510, 0x00000003);
    // d.s QRBTC_COM_PLLTXCLKEN              %LONG 0x01 ; Originally 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7514, 0x00000001);
    // d.s QRBTC_TXRX_CLKBUF_EN_LN1          %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x703c, 0x00000003);
}


static void ufs_serdes_bypass_on(uint32 baseAddr)
{
    //sb_remap(barNum, R3PC_UFS_WRAPPER);
    // d.s QRBTC_TXRX_SERDESBYPEN_LN1      %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7080, 0x00000003);
    // d.s QRBTC_TXRX_RXHIGHZ_LN1          %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x706c, 0x00000003);
    // d.s QRBTC_TXRX_RXCM_LN1             %LONG 0x03
    RUMI_UFS_HCI_Set(baseAddr, 0x7058, 0x00000003);
    // d.s QRBTC_TXRX_RXACCOUPLE_LN1       %LONG 0x02
    RUMI_UFS_HCI_Set(baseAddr, 0x7054, 0x00000002);
    // d.s QRBTC_TXRX_RXTERM_LN1           %LONG 0x02
    RUMI_UFS_HCI_Set(baseAddr, 0x7078, 0x00000002);

    /*
    sb_remap(barNum, 0xEF800000);
    // d.s QRBTC_CONTROL                   %LONG 0x040   ; PWM mode on
    RUMI_UFS_HCI_Set(baseAddr, 0x0018, 0x00000040);
    */
}

#endif

