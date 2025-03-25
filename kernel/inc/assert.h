#ifndef __ASSERT_H__
#define __ASSERT_H__

#include <stdint.h>

void assert_failure(s8* exp, s8* file, s8* base, const s8* func, s32 line);

#define assert(exp)                                                             \
    if(exp)                                                                     \
    {                                                                           \
        ;                                                                       \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        assert_failure(#exp, __FILE__, __BASE_FILE__, __func__, __LINE__);      \
    }                       

#endif