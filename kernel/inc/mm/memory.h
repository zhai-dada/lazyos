#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

extern u64* cr3;

#define BUFFER_1M_SIZE  0x100000
#define COUNT_PER_PAGE  512

#define PAGE_OFFSET         ((u64)0xffff800000000000)

#define PAGE_GDT_SHIFT  39
#define PAGE_1G_SHIFT   30
#define PAGE_2M_SHIFT	21
#define PAGE_4K_SHIFT	12

#define PAGE_1G_SIZE        (1UL << PAGE_1G_SHIFT)
#define PAGE_2M_SIZE        (1UL << PAGE_2M_SHIFT)
#define PAGE_4K_SIZE        (1UL << PAGE_4K_SHIFT)

#define PAGE_1G_MASK        (~(PAGE_1G_SIZE - 1))
#define PAGE_2M_MASK        (~(PAGE_2M_SIZE - 1))
#define PAGE_4K_MASK        (~(PAGE_4K_SIZE - 1))

#define PAGE_1G_ALIGN(addr) (((u64)(addr) + PAGE_1G_SIZE - 1) & PAGE_1G_MASK)
#define PAGE_2M_ALIGN(addr) (((u64)(addr) + PAGE_2M_SIZE - 1) & PAGE_2M_MASK)
#define PAGE_4K_ALIGN(addr) (((u64)(addr) + PAGE_4K_SIZE - 1) & PAGE_4K_MASK)

#define V_TO_P(addr)        ((u64)(addr) - PAGE_OFFSET)
#define P_TO_V(addr)        ((u64)(addr) + PAGE_OFFSET)

// 内存分布区域结构体
typedef struct mm_e820
{
    u64 address;       // 区域起始地址
    u64 length;        // 区域长度
    u32 type;          // 区域类型
}__attribute__((packed)) mm_e820_t;

#endif
