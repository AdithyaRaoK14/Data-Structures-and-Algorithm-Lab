#ifndef _INCLUDED_SLL_REMOVE_DUP_
#define _INCLUDED_SLL_REMOVE_DUP_
#include <stdint.h>
#include <stddef.h>

typedef struct _sll_node_ {
    int32_t data;
    struct _sll_node_ *next;
} SLLNode;

typedef struct _sll_list_ {
    SLLNode *head;
} SLLList;

SLLList sll_create();
SLLList* sll_add_node(SLLList *list, int32_t data);
void sll_delete_duplicates(SLLList *list);
void sll_destroy(SLLList *list);
void sll_print(SLLList *list);

#endif
