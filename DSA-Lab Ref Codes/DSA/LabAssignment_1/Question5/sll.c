// write a function to delete all duplicate elements from sll

#include <stdlib.h>
#include <assert.h>
#include "sll.h"
#include <stdio.h>


SLLList sll_create() {
    SLLList list = {NULL};
    return list;
}

SLLList* sll_add_node(SLLList *list, int32_t data) {
    assert(list != NULL);
    SLLNode *node = (SLLNode*) malloc(sizeof(SLLNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
    return list;
}


void sll_delete_duplicates(SLLList *list) {
    SLLNode *cur = list->head;

    while (cur != NULL) {
        SLLNode *node = cur;
        while (node->next != NULL) {
            if (node->next->data == cur->data) {
                SLLNode *dup = node->next;
                node->next = dup->next;
                free(dup);
            } else {
                node = node->next;
            }
        }
        cur = cur->next;
    }
}


void sll_destroy(SLLList *list) {
    assert(list != NULL);
    SLLNode *cur = list->head;
    while (cur) {
        SLLNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}

// Print the list elements
void sll_print(SLLList *list) {
    assert(list != NULL);
    SLLNode *cur = list->head;
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
