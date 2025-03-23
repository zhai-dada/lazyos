#ifndef __TASK_H__
#define __TASK_H__

#include <stdint.h>
#include <cpu.h>

typedef struct tss_struct
{
    u32 reserved0;
    u64 rsp0;
    u64 rsp1;;
    u64 rsp2;
    u64 reserved1;
    u64 ist1;
    u64 ist2;
    u64 ist3;
    u64 ist4;
    u64 ist5;
    u64 ist6;
    u64 ist7;
    u64 reserved2;
    u16 reserved3;
    u16 iomapbaseaddr;
}__attribute__((packed)) tss_t;

#define INIT_TSS                     \
{                                    \
    .reserved0 = (u32)0,             \
    .rsp0 = (u64)0xffff800000007c00, \
    .rsp1 = (u64)0xffff800000007c00, \
    .rsp2 = (u64)0xffff800000007c00, \
    .reserved1 = (u64)0,             \
    .ist1 = (u64)0xffff800000007c00, \
    .ist2 = (u64)0xffff800000007c00, \
    .ist3 = (u64)0xffff800000007c00, \
    .ist4 = (u64)0xffff800000007c00, \
    .ist5 = (u64)0xffff800000007c00, \
    .ist6 = (u64)0xffff800000007c00, \
    .ist7 = (u64)0xffff800000007c00, \
    .reserved2 = (u64)0,             \
    .reserved3 = (u16)0,             \
    .iomapbaseaddr = (u16)0          \
}

extern tss_t tss[CPUNUM];


#endif