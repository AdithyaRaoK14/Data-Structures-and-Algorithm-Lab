#ifndef _INCLUDED_SLL_REMOVE_DUP_
#define _INCLUDED_SLL_REMOVE_DUP_
#include <stdint.h>
#include <stddef.h> 
typedef struct _dnode_ {
    int32_t data;
    struct _dnode_ *next;
} DNodeSLL;

typedef struct _dlist_ {
    DNodeSLL *head;
} DList;

DList dlist_new();
DList* dlist_insert(DList *list, int32_t data);
void dlist_remove_duplicates(DList *list);
void dlist_free(DList *list);

#endif
