#include <stdlib.h>
#include <assert.h>
#include "dll.h"
#include <stddef.h> 
// Create new empty DLL
DLL dll_new() {
    DLL l = {NULL, NULL};
    return l;
}

// Add element at end
DLL* dll_add(DLL *list, int32_t data) {
    assert(list != NULL);
    DNode *node = (DNode*) malloc(sizeof(DNode));
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail) list->tail->next = node;
    else list->head = node;
    list->tail = node;
    return list;
}

// Delete first occurrence
DLL* dll_delete(DLL *list, int32_t data) {
    assert(list != NULL);
    DNode *cur = list->head;
    while (cur) {
        if (cur->data == data) {
            if (cur->prev) 
                cur->prev->next = cur->next;
            else list->head = cur->next;
            if (cur->next)
                cur->next->prev = cur->prev;
            else list->tail = cur->prev;
            free(cur);
            break;
        }
        cur = cur->next;
    }
    return list;
}

// Free DLL
void dll_free(DLL *list) {
    assert(list != NULL);
    DNode *cur = list->head;
    while (cur) {
        DNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = list->tail = NULL;
}
