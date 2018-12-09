[bits 32]                                 ; NASM will run in 32bit mode

MAGIC_NUMBER  equ 0x1BADB002              ; Magic Number to Boot
FLAGS         equ 0x0                     ; Multiboot flags
CHECKSUM      equ -(MAGIC_NUMBER+FLAGS)   ; Checksum + Magic Number + Flags = 0

section .text                             ; Instructions section
  align 4                                 ; Must be 4 byte align
  dd MAGIC_NUMBER                         ; Store Magic Number, Flags and Checksum
  dd FLAGS
  dd CHECKSUM

global start                              ; Entrypoint
extern kmain                              ; Load C Entrypoint (kernel.c)
start:
  cli                                     ; Clear interruption flags
  call kmain                              ; Run C Entrypoint
  hlt                                     ; Stop the OS
