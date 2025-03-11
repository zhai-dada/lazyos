#ifndef __VBE_H__
#define __VBE_H__

#include <stdint.h>

typedef struct vbe_info
{
    s32 x_resolution;
    s32 y_resolution;

    s32 x_position;
    s32 y_position;

    s32 x_charsize;
    s32 y_charsize;

    u32 *vbe_base_addr;
    u64 vbe_buffer_length;
} vbe_info_t;

#endif