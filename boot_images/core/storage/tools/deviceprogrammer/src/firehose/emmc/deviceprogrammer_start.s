;/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
;
;                      S T A R T U P   C O D E
;
; GENERAL DESCRIPTION
;   This module contains the entry point for our Flash Programming Plug-In 
;   for Lauterbach JTAG/ICD TRACE32. All it does is setups stack and calls
;   our main 'C' function "main_c".
;
;   The C function does return and expects a breakpoint there. This is the
;   case because the FLASH programming plug-in specification requires it.
;   The break-point is used to give control back to TRACE32 Debugger so 
;   that it may fill up the buffer and call our plug-in again. This cycle
;   continues until FLASH programming is complete.
;
; EXTERNALIZED FUNCTIONS
;   None.  
;
; INITIALIZATION AND SEQUENCING REQUIREMENTS
;
;   This module must be linked first, specifically the AREA "StartHere", 
;   since this is our entry point. This is done in our scatter load file.
;
;  Copyright (c) 1998-2011 Qualcomm Technologies, Incorporated.  All Rights Reserved.
;*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/*======================================================================

                           EDIT HISTORY FOR FILE
  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

$Header: //components/rel/boot.bf/3.1.2.c2.2/boot_images/core/storage/tools/deviceprogrammer/src/firehose/emmc/deviceprogrammer_start.s#1 $

when         who     what, where, why
----------   ---     -----------------------------------------------------
2014-07-02   sb      Updated to support 8909
2013-06-03   ah      Added legal header
2013-05-31   ab      Initial checkin
===========================================================================*/

#include DEVPROG_HWIO_INCLUDE_H

; CPSR mode and bit definitions
Mode_SVC                EQU    0x13
Mode_ABT                EQU    0x17
Mode_UND                EQU    0x1b
Mode_SYS                EQU    0x1f
Mode_FIQ                EQU    0x11
Mode_IRQ                EQU    0x12
I_Bit                   EQU    0x80
F_Bit                   EQU    0x40

; CPSR Control Masks 
PSR_Fiq_Mask    EQU     0x40
PSR_Irq_Mask    EQU     0x80

; Processor mode definitions 
PSR_Supervisor  EQU     0x13



;============================================================================
;
;                             MODULE IMPORTS
;
;============================================================================

    ; Import the external symbols that are referenced in this module.
    IMPORT   deviceprogrammer_main_ctl
    IMPORT   main_firehose

;============================================================================
;
;                             MODULE EXPORTS
;
;============================================================================

    ; Export the symbols __main and _main to prevent the linker from
    ; including the standard runtime library and startup routine.

    EXPORT  _main
    EXPORT  __main

;============================================================================
; BOOT LOADER ENTRY POINT
;
; Execution of boot rom begins here.
;============================================================================

    AREA    DEVICEPROGRAMMER_ENTRY_POINT, CODE, READONLY
    CODE32
    PRESERVE8
    ENTRY

_main
__main

;============================================================================
; The mARM exception vector table located in boot ROM contains four bytes
; for each vector.  The boot ROM vector table will contain long branches that
; allow branching anywhere within the 32 bit address space.  Long branches
; will be used for all vectors except the reset vector.  Each long branch
; consists of a 32 bit LDR instruction using the PC relative 12 bit immediate
; offset address mode (ARM address mode 2).
;============================================================================
    b       deviceprogrammer_reset_handler              ; reset vector
    b       deviceprogrammer_reset_handler              ; undef_instr_vect vector
    b       deviceprogrammer_reset_handler              ; swi_vector
    b       deviceprogrammer_reset_handler              ; prefetch_abort_vector
    b       deviceprogrammer_reset_handler              ; data_abort_vector
    b       deviceprogrammer_reset_handler              ; reserved_vector
    b       deviceprogrammer_reset_handler              ; irq_vector
    b       deviceprogrammer_reset_handler              ; fiq_vector

;============================================================================
; The following initializes the relevant MSM circuits for IMEM operation
; then transfers control to the main control code in "C" which continues the
; boot strap process.
;============================================================================
deviceprogrammer_reset_handler

    ;Change to Supervisor Mode
    msr     CPSR_c, #Mode_SVC:OR:I_Bit:OR:F_Bit

    ; Save the passing parameter from PBL
    mov     r7, r0

    ; Setup the supervisor mode stack
    ldr     r0, =DEVICEPROGRAMMER_STACK_BASE_ADDR
    mov     r13, r0

    ; Switch to undefined mode and setup the undefined mode stack
    msr     CPSR_c, #Mode_UND:OR:I_Bit:OR:F_Bit
    mov     r13, r0

    ; Switch to abort mode and setup the abort mode stack
    msr     CPSR_c, #Mode_ABT:OR:I_Bit:OR:F_Bit
    mov     r13, r0

    ; Return to supervisor mode
    msr     CPSR_c, #Mode_SVC:OR:I_Bit:OR:F_Bit

    ; Restore the passing parameter
    mov     r0, r7
    ; ------------------------------------------------------------------
    ; This function never returns.
    ; deviceprogrammer_main_ctl();
    ; ------------------------------------------------------------------
    b       deviceprogrammer_main_ctl

deviceprogrammer_self_loop
    b deviceprogrammer_self_loop

    END
