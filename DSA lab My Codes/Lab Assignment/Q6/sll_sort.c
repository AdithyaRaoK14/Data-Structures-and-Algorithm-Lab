#include <stdlib.h>
#include <assert.h>
#include "sll_sort.h"
 #include <stddef.h>
// Create new empty list
SList slist_new() {
    SList l = {NULL};
    return l;
}
 
// Insert at head
SList* slist_insert(SList *list, int32_t data) {
    assert(list != NULL);
    SNode *node = (SNode*) malloc(sizeof(SNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
    return list;
}
 
// Helper: merge two sorted lists
static SNode* merge(SNode *a, SNode *b) {
    if (!a) return b;
    if (!b) return a;
 
    if (a->data <= b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}
 
// Helper: split list into two halves
static void split(SNode *source, SNode **front, SNode **back) {
    SNode *slow = source;
    SNode *fast = source->next;
 
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}
 
// Recursive merge sort
static void merge_sort(SNode **headRef) {
    if (!(*headRef) || !(*headRef)->next) return;
 
    SNode *a, *b;
    split(*headRef, &a, &b);
 
    merge_sort(&a);
    merge_sort(&b);
 
    *headRef = merge(a, b);
}
 
// Public sort function
void slist_sort(SList *list) {
    assert(list != NULL);
    merge_sort(&list->head);
}
 
// Free memory
void slist_free(SList *list) {
    assert(list != NULL);
    SNode *cur = list->head;
    while (cur) {
        SNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}