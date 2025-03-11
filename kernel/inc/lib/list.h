#ifndef __LIB_LIST_H__
#define __LIB_LIST_H__

typedef struct list
{
    struct list* prev;
    struct list* next;
}list_t;

#endif