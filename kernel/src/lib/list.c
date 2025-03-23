#include <lib/list.h>

/**
 * 根据结构体变量内的某个成员变量基地址推导出所在结构的地址
 * ptr是结构体内某个变量的地址
 * ptr_member是成员的变量名
 * struct_type是这个ptr所在结构体的类型
*/
#define container_of(ptr, ptr_member, struct_type)                         \
({                                                                          \
    typeof(((struct_type *)0)->ptr_member) *p = (ptr);                     \
    (struct_type *)((u64)p - (u64)&(((struct_type *)0)->ptr_member));      \
})

// list初始化
void list_init(list_t* list)
{
    list->prev = list;
    list->next = list;
    return;
}

// 添加到 list 后面
void list_add_behind(list_t* list, list_t* newn)
{
    newn->next = list->next;
    newn->prev = list;
    newn->next->prev = newn;
    list->next = newn;
    return;
}

// 添加到 list 前面
void list_add_before(list_t* list, list_t* newn)
{
    list->prev->next = newn;
    newn->prev = list->prev;
    list->prev = newn;
    newn->next = list;
    return;
}

// 删除 list 节点
void list_delete(list_t* list)
{
    list->next->prev = list->prev;
    list->prev->next = list->next;
    return;
}

// 是否为空 空则返回 1 ，否则返回0
s64 list_is_empty(list_t* list)
{
    if(list->next == list && list->prev == list)
    {
        return YES;
    }
    return NO;
}

// 获取前一个
list_t* list_prev(list_t* list)
{
    if(list->prev != NULL)
    {
        return list->prev;
    }
    return NULL;
}

// 获取后一个
list_t* list_next(list_t* list)
{
    if(list->next != NULL)
    {
        return list->next;
    }
    return NULL;
}

// 获取list长度
u64 list_size(list_t* list)
{
    u64 i = 0;
    list_t* node = list;
    for(node = list->next; node != list; node = node->next)
    {
        i++;
    }
    return i;
}
