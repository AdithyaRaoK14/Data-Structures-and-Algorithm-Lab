#include <stdlib.h>
#include <assert.h>
#include "sll_minmax.h"

// Create new list
MList mlist_new() {
    MList l = {NULL, __INT_MAX__, -__INT_MAX__};
    return l;
}

// Insert at head
MList* mlist_insert(MList *list, int32_t data) {
    assert(list != NULL);
    MNode *node = (MNode*) malloc(sizeof(MNode));
    node->data = data;
    node->next = list->head;
    list->head = node;

    if (data < list->min_val) list->min_val = data;
    if (data > list->max_val) list->max_val = data;
    return list;
}

int32_t mlist_min(MList *list) {
    return list->min_val;
}

int32_t mlist_max(MList *list) {
    return list->max_val;
}

void mlist_free(MList *list) {
    assert(list != NULL);
    MNode *cur = list->head;
    while (cur) {
        MNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}
