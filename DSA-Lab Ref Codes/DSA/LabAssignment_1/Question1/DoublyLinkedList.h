#ifndef INCLUDED_DLIST_
#define INCLUDED_DLIST_

#include <stdint.h>

typedef struct _node_ Node;
typedef struct _dlist_ List;

struct _node_ {
    int32_t data;
    Node* prev;
    Node* next;
};

struct _dlist_ {
    Node* head;
    Node* tail;
    uint32_t length;
};

List* dlist_new();
List* dlist_free(List* list);
uint32_t dlist_length(const List* list);
List* dlist_add_head(List* list, int32_t data);
List* dlist_add_tail(List* list, int32_t data);
List* dlist_delete_head(List* list);
List* dlist_delete_tail(List* list);


#endif 
