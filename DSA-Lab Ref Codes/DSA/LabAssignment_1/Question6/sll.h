#ifndef _INCLUDED_SLL_SORT_
#define _INCLUDED_SLL_SORT_
#include <stdint.h>
#include <stddef.h>

// Node structure
typedef struct _node_ {
    int32_t data;
    struct _node_ *next;
} Node;

// List structure
typedef struct _list_ {
    Node *head;
} List;

// Functions
List list_create();
List* list_add_node(List *list, int32_t data);
void list_sort(List *list);
void list_free(List *list);
void list_print(List *list);

#endif
