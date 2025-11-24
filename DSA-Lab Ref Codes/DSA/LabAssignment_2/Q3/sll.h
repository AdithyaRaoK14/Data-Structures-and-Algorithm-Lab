#ifndef INCLUDED_SLIST_
#define INCLUDED_SLIST_
#include <stdio.h>
#include <stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ List;

struct _node_ {
    int32_t data;
    Node* next;
};

struct _slist_ {
    Node* head;
    Node* tail;
    uint32_t length;
};

List* slist_new();
List* slist_free(List* list);
uint32_t slist_length(const List* list);
List* slist_add_tail(List* list, int32_t data);
List* slist_swap(List* list, int32_t key1, int32_t key2);
List* slist_sort(List* list);
void slist_print(const List* list);
List* slist_merge_sorted(const List* list1, const List* list2);
List* slist_link(List* list1, List* list2);

#endif 