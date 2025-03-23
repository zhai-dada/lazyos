#ifndef __LIB_LIST_H__
#define __LIB_LIST_H__

#include <stdint.h>

typedef struct list
{
    struct list* prev;
    struct list* next;
}list_t;


#endif