#ifndef _INCLUDED_SLL_UNION_INTERSECTION_
#define _INCLUDED_SLL_UNION_INTERSECTION_
#include <stdint.h>

// Node structure
typedef struct _node_ {
    int32_t data;
    struct _node_ *next;
} Node;

// List structure
typedef struct _list_ {
    Node *head;
} List;

// Function prototypes
List list_new();
List* list_insert_unique(List *list, int32_t data);
List list_union(List *l1, List *l2);
List list_intersection(List *l1, List *l2);
void list_free(List *list);

#endif
