#include <stdlib.h>
#include <assert.h>
#include "sll_union_intersection.h"

// Create new empty list
List list_new() {
    List l = {NULL};
    return l;
}

// Insert unique element
List* list_insert_unique(List *list, int32_t data) {
    assert(list != NULL);
    Node *cur = list->head;
    while (cur) {
        if (cur->data == data) return list; // already exists
        cur = cur->next;
    }
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    return list;
}

// Union of two lists
List list_union(List *l1, List *l2) {
    assert(l1 != NULL && l2 != NULL);
    List result = list_new();
    Node *cur = l1->head;
    while (cur) {
        list_insert_unique(&result, cur->data);
        cur = cur->next;
    }
    cur = l2->head;
    while (cur) {
        list_insert_unique(&result, cur->data);
        cur = cur->next;
    }
    return result;
}

// Intersection of two lists
List list_intersection(List *l1, List *l2) {
    assert(l1 != NULL && l2 != NULL);
    List result = list_new();
    for (Node *c1 = l1->head; c1; c1 = c1->next) {
        for (Node *c2 = l2->head; c2; c2 = c2->next) {
            if (c1->data == c2->data) {
                list_insert_unique(&result, c1->data);
                break;
            }
        }
    }
    return result;
}

// Free memory
void list_free(List *list) {
    assert(list != NULL);
    Node *cur = list->head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}
