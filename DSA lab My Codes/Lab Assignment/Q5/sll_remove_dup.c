#include <stdlib.h>
#include <assert.h>
#include "sll_remove_dup.h"
#include <stddef.h> 
// New list
DList dlist_new() {
    DList l = {NULL};
    return l;
}

// Insert at head
DList* dlist_insert(DList *list, int32_t data) {
    assert(list != NULL);
    DNodeSLL *node = (DNodeSLL*) malloc(sizeof(DNodeSLL));
    node->data = data;
    node->next = list->head;
    list->head = node;
    return list;
}

// Remove duplicates
void dlist_remove_duplicates(DList *list) {
    assert(list != NULL);
    for (DNodeSLL *cur = list->head; cur; cur = cur->next) {
        DNodeSLL *prev = cur;
        DNodeSLL *check = cur->next;
        while (check) {
            if (check->data == cur->data) {
                prev->next = check->next;
                free(check);
                check = prev->next;
            } else {
                prev = check;
                check = check->next;
            }
        }
    }
}

// Free memory
void dlist_free(DList *list) {
    assert(list != NULL);
    DNodeSLL *cur = list->head;
    while (cur) {
        DNodeSLL *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}
