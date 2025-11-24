#include <stdlib.h>
#include <assert.h>
#include "sll_reverse_nth.h"
#include <stddef.h>
// New list
RList rlist_new() {
    RList l = {NULL};
    return l;
}

// Insert at head
RList* rlist_insert(RList *list, int32_t data) {
    assert(list != NULL);
    RNode *node = (RNode*) malloc(sizeof(RNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
    return list;
}

// Reverse linked list
void rlist_reverse(RList *list) {
    assert(list != NULL);
    RNode *prev = NULL, *cur = list->head, *next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    list->head = prev;
}

// Find nth node from end
int32_t rlist_nth_from_end(RList *list, int32_t n) {
    assert(list != NULL);
    RNode *fast = list->head, *slow = list->head;
    for (int i = 0; i < n; i++) {
        if (!fast) return -1;
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow ? slow->data : -1;
}

// Free memory
void rlist_free(RList *list) {
    assert(list != NULL);
    RNode *cur = list->head;
    while (cur) {
        RNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}
