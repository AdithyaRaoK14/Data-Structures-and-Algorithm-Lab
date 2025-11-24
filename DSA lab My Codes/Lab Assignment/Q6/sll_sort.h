#ifndef _INCLUDED_SLL_SORT_
#define _INCLUDED_SLL_SORT_
#include <stdint.h>
 #include <stddef.h>
// Node structure
typedef struct _snode_ {
    int32_t data;
    struct _snode_ *next;
} SNode;
 
// List structure
typedef struct _slist_ {
    SNode *head;
} SList;
 
// Functions
SList slist_new();
SList* slist_insert(SList *list, int32_t data);
void slist_sort(SList *list);
void slist_free(SList *list);
 
#endif