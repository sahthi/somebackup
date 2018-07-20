;*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
;
;        HW init/PMIC support - EMERGENCY DOWNLOADER IN RPM PROCESSOR
;
; GENERAL DESCRIPTION
;   This file contain PMIC related function that is used by the startup 
;   script to enable Scorpion processor
;   
;
; EXTERNALIZED SYMBOLS
;   __main
;   _main
;
; INITIALIZATION AND SEQUENCING REQUIREMENTS
;
;
; Copyright 2010    by Qualcomm Technologies, Incorporated.All Rights Reserved.
;*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

;*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
;
;                           EDIT HISTORY FOR FILE
;
; This section contains comments describing changes made to the module.
; Notice that changes are listed in reverse chronological order.
;
; $Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/emmcbld/src/emmcbld_hw_init_8960.s#1 $
;
; when         who     what, where, why
; ----------   ---     --------------------------------------------------------
; 2012-03-05   ah      changes for 8930 and 8064
; 2011-06-15   ah      8960 bringup
;*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*


SVC_Stack_Size  EQU     0x4000

;============================================================================
;
;                            MODULE INCLUDES
;
;============================================================================

#include "msmhwioreg.h"

; Include header for ssbi hwio defines.
#include "HALhwioSBI.h"

; Header inclusion for SCSS addresses like SCSS_START_ADDR
#include "msm.h"



;============================================================================
;
;                             MODULE DEFINES
;
;============================================================================
;
Mode_SVC                EQU    0x13
Mode_ABT                EQU    0x17
Mode_UND                EQU    0x1b
Mode_USR                EQU    0x10
Mode_FIQ                EQU    0x11
Mode_IRQ                EQU    0x12

I_Bit                   EQU    0x80
F_Bit                   EQU    0x40


;============================================================================
;
;                             MODULE IMPORTS
;
;============================================================================
    IMPORT return_from_scorpion_init
    IMPORT pm_device_init
	IMPORT sbi_mini_init 
    IMPORT svc_stack
    IMPORT clk_regime_rpm_init_boot_rpmsbl
  
;============================================================================
;
;                             MODULE EXPORTS
;
;============================================================================
    ; Export the external symbols that are referenced in this module.
    EXPORT scorpion_init_module
	 EXPORT apps_ss_start_in_ram
    EXPORT apps_ss_start_in_ram_end

;============================================================================
;
;                             MODULE DATA AREA
;
;============================================================================

    ;-------------------------------------------------------------------------
    ; Area code
    ;-------------------------------------------------------------------------
    PRESERVE8
    AREA    PMIC_CODE, CODE, READONLY
    CODE32

;------------------ Code to power up scorpion ----------------------------
;  This code is copied into a different memory region and run there
apps_ss_start_in_ram

    ldr r1, HW_INIT_APCS_START_ADDR
    mov r0, #0x2A000000
    str r0, [r1]

    ldr r1, HW_INIT_CPU0_APCS_CPU_PWR_CTL
    ldr r0, HW_INIT_CPU_PUP_STEP1
    str r0, [r1]

    ldr r0, HW_INIT_CPU_PUP_STEP2
    str r0, [r1]

    ldr r0, HW_INIT_CPU_PUP_STEP3
    str r0, [r1]

    ldr r0, HW_INIT_CPU_PUP_STEP4
    str r0, [r1]

    ldr r0, HW_INIT_CPU_PUP_STEP5
    str r0, [r1]

   ; Rpm stays in code ram forever after releasing scorpion out of reset
rpm_loop_here
   b rpm_loop_here

	; Duplicate a set of the HWIO defines into the local memory location
HW_INIT_APCS_START_ADDR 	     DCD   HWIO_APCS_START_ADDR_ADDR
HW_INIT_SCL_SBL2_CODE_BASE       DCD   0x2A000000
HW_INIT_CPU0_APCS_CPU_PWR_CTL    DCD   HWIO_CPU0_APCS_CPU_PWR_CTL_ADDR

HW_INIT_CPU_PUP_STEP1            DCD   0x00000109
HW_INIT_CPU_PUP_STEP2            DCD   0x00000101
HW_INIT_CPU_PUP_STEP3            DCD   0x00000121
HW_INIT_CPU_PUP_STEP4            DCD   0x00000020
HW_INIT_CPU_PUP_STEP5            DCD   0x00000080

apps_ss_start_in_ram_end       

;------------------ Code to initialize scorpion ----------------------------
scorpion_init_module
    ldr     r13, =svc_stack+SVC_Stack_Size

    ; Turn on the AFAB clock branch
    ;ldr r1, =HWIO_AFAB_CORE_CLK_CTL_ADDR
    ;mov r0, #0x10
    ;str r0, [r1]

    ldr     a1, =clk_regime_rpm_init_boot_rpmsbl
	 ldr     r14, =return_herek
    bx      a1
return_herek

    ldr r1, =HWIO_AFAB_M2VMT_M2VMRv_0_ADDR(0)
    mov r0, #0x0
    str r0, [r1]

    ldr r1, =HWIO_AFAB_M2VMT_M2VMRv_1_ADDR(0)
    mov r0, #0x0
    str r0, [r1]
	 
    ldr r1, =HWIO_AFAB_M2VMT_M2VMRv_0_ADDR(1)
    mov r0, #0x0
    str r0, [r1]

    ldr r1, =HWIO_AFAB_M2VMT_M2VMRv_1_ADDR(1)
    mov r0, #0x0
    str r0, [r1]

    ldr r1, =HWIO_RPM_2X3_SFPB_M2VMT_M2VMRn_ADDR(0)
    mov r0, #0x0
    str r0, [r1]

    ldr r1, =HWIO_RPM_2X3_SFPB_M2VMT_M2VMRn_ADDR(1)
    mov r0, #0x0
    str r0, [r1]

    ldr     a1, =pm_device_init
	 ldr     r14, =return_here
    bx      a1
return_here

	 ; Keep the Krait 1 core in reset
    ;ldr r1, =HWIO_VDD_SC1_ARRAY_CLAMP_GFS_CTL_ADDR
    ;mov r0, #0x0
    ;str r0, [r1]

    ;ldr r1, =HWIO_CPU1_APCS_CPU_PWR_CTL_ADDR
    ;mov r0, #0x31
    ;str r0, [r1]

	 ; Krait SS system wide warm reset
    ;;ldr r1, =HWIO_SCSS_RESET_ADDR
    ;;ldr r0, =HWIO_SCSS_RESET_SCSS_SYS_BMSK
	;;mov r0, #0x2
    ;;str r0, [r1]

    ;;ldr r1, =HWIO_SCSS_RESET_ADDR
    ;;ldr r0, =HWIO_SCSS_RESET_SCSS_SYS_POR_BMSK
    ;;str r0, [r1]

    ; POR and SYS area at RPM
    ;;ldr r1, =HWIO_SCSS_RESET_ADDR
    ;;mov r0, #0x0
    ;;str r0, [r1]

	 ; Initialize L2 ----------------------------------------------------------------------------------

    ;PLL_CLAMP, and L2_HS_CLAMP is ON and L2_HS_EN is OFF 
    ldr r1, =HWIO_APCS_L2_PWR_CTL_ADDR
    mov r0, #0x00008100
    str r0, [r1]
	
    ;Sets the PLL_CLAMP, SYS_RESET, L2_HS_RST, L2_HS_EN, and leaves the L2_HS_CLAMP 
    ;RPM should remain on this step for L2_HS_CNT AHB cycles + 32 of
    ;the slowest of the QSB, AHB, debug, and L2 clocks. This provides
    ;time for the HS logic to be enabled, and perhaps for the array
    ;headswitches to charge the arrays if they were previously collapsed,
    ;plus 32 more clocks for the reset.
    
    ldr r1, =HWIO_APCS_L2_PWR_CTL_ADDR
    ldr r0, =APCS_L2_PWR_CTL_RESET_STATE
    str r0, [r1]

    ;wait 40 micro sec. 
    bl dumb_busy_wait

    ; turns off the L2_HS_CLAMP and PLL_CLAMP, and waiting for the clamp
    ; to settle (~300 ns), and then for 32 of the slowest of the QSB, AHB,
    ; debug, and L2 clocks. 
    ldr r1, =HWIO_APCS_L2_PWR_CTL_ADDR
    mov r0, #0x00001600
    str r0, [r1]

    ; wait 300 micro sec. 
    bl dumb_busy_wait

    ; Releases the L2 logic from reset.  The L2 initialization is complete 
    ; and the RPM can proceed to bring up any or all CPUs.
    ldr r1, =HWIO_APCS_L2_PWR_CTL_ADDR
    mov r0, #0x00000200
    str r0, [r1]

    bl dumb_busy_wait

	 b       return_from_scorpion_init

APCS_L2_PWR_CTL_RESET_STATE
    DCD                0x0FFF9700

;----------------------------------------------------------------------------
;Dummy delay wait
dumb_busy_wait
    ; arbitrary delay [loop 1000000 times]
	 mov r0, #0x03D000
	 orr r0, r0, #0x90
    mov r10, r0
dumbloop
    sub r10,r10, #0x1
    cmp r10, #0x0
    bne dumbloop
    mov pc, r14 ; jump back

    ; Loop count for busy wait, set to 250000
loop_count
    DCD                 0x03D090

    END
    
