#ifndef __LIB_IO_H__
#define __LIB_IO_H__

#include <stdint.h>

// in 读取
u8 min8(u64 addr);
u16 min16(u64 addr);
u32 min32(u64 addr);
u64 min64(u64 addr);

// out 写入
void mout8(u64 addr, u8 value);
void mout16(u64 addr, u16 value);
void mout32(u64 addr, u32 value);
void mout64(u64 addr, u64 value);

#endif