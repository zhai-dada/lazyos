#include <lib/libio.h>

u8 min8(u64 addr)
{
    return *((volatile u8 *)addr);
}

u16 min16(u64 addr)
{
    return *((volatile u16 *)addr);
}

u32 min32(u64 addr)
{
    return *((volatile u32 *)addr);
}

u64 min64(u64 addr)
{
    return *((volatile u64 *)addr);
}

void mout8(u64 addr, u8 value)
{
    *((volatile u8 *)addr) = value;
}

void mout16(u64 addr, u16 value)
{
    *((volatile u16 *)addr) = value;
}

void mout32(u64 addr, u32 value)
{
    *((volatile u32 *)addr) = value;
}

void mout64(u64 addr, u64 value)
{
    *((volatile u64 *)addr) = value;
}