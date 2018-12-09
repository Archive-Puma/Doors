[bits 32]                                 ; NASM will run in 32bit mode

MAGIC_NUMBER  equ 0x1BADB002              ; Magic Number to Boot
FLAGS         equ 0x0                     ; Multiboot flags
CHECKSUM      equ -(MAGIC_NUMBER+FLAGS)   ; Checksum + Magic Number + Flags = 0

STACK_SIZE    equ 4096                    ; Size of the Stack

section .bss                              ; Static variables section
  align 4                                 ; Must be 4 byte align
  stack:
    resb STACK_SIZE                       ; Reserve stack size

section .text                             ; Instructions section
  align 4                                 ; Must be 4 byte align
  dd MAGIC_NUMBER                         ; Store Magic Number, Flags and Checksum
  dd FLAGS
  dd CHECKSUM

global start                              ; Entrypoint
extern kmain                              ; Load C Entrypoint (kernel.c)
start:
  cli                                     ; Clear interruption flags
  mov esp, stack + STACK_SIZE             ; Point ESP to the bottom of the Stack

  call kmain                              ; Run C Entrypoint
  hlt                                     ; Stop the OS
