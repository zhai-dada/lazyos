#include <lib/string.h>

void* memcpy(void* dest, void* srcs, s64 num)
{
    asm volatile
    (
        "cld            \n"
        "rep movsq      \n"
        "testb $4, %b1  \n"
        "jz 1f          \n"
        "movsl          \n"
        "1:             \n"
        "testb $2, %b1  \n"
        "jz 2f          \n"
        "movsw          \n"
        "2:             \n"  
        "testb $1, %b1  \n"
        "jz 3f          \n"
        "movsb          \n"
        "3:             \n"
        :
        : "c"(num / 8), "q"(num), "D"(dest), "S"(srcs)
        : "memory"
    );
    return dest;
}