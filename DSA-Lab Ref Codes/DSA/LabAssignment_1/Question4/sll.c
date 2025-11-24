#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "sll.h"

MList mlist_new() {
    MList l = {NULL, __INT_MAX__, -__INT_MAX__};
    return l;
}


MList* mlist_add_head(MList *list, int32_t data) {
    assert(list != NULL);
    MNode *node = (MNode*) malloc(sizeof(MNode));
    node->data = data;
    node->next = list->head;
    list->head = node;

    // Update min and max values
    if (data < list->min_val) list->min_val = data;
    if (data > list->max_val) list->max_val = data;

    return list;
}

void mlist_print(MList *list) {
    assert(list != NULL);
    MNode *cur = list->head;
    if (cur == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// Get the minimum value from the list
int32_t mlist_get_min(MList *list) {
    return list->min_val;
}

// Get the maximum value from the list
int32_t mlist_get_max(MList *list) {
    return list->max_val;
}

// Free all nodes in the list
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
