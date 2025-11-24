#include <stdlib.h>
#include <assert.h>
#include "sll.h"
#include <stdio.h>

// Create a new empty list
List list_create() {
    List l = {NULL};
    return l;
}

// Insert at the head
List* list_add_node(List *list, int32_t data) {
    assert(list != NULL);
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    return list;
}

// Helper: merge two sorted lists
static Node* merge(Node *a, Node *b) {
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

// Helper: split the list into two halves
static void split(Node *source, Node **front, Node **back) {
    Node *slow = source;
    Node *fast = source->next;

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
static void merge_sort(Node **headRef) {
    if (!(*headRef) || !(*headRef)->next) return;

    Node *a, *b;
    split(*headRef, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *headRef = merge(a, b);
}

// Public sort function
void list_sort(List *list) {
    assert(list != NULL);
    merge_sort(&list->head);
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

// Print the list elements
void list_print(List *list) {
    assert(list != NULL);
    Node *cur = list->head;
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
