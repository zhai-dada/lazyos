#include <linkage.h>

.section .text

ENTRY(_start)
_start:
    mov %ss, %ax
    mov %ax, %ds
    mov %ax, %cx
    jmp kernel