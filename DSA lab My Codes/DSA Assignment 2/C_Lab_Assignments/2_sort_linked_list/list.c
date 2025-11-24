#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

List *list_create() {
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void list_insert(List *list, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
}

void list_sort(List *list) {
    assert(list);
    if (!list->head) return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void list_display(const List *list) {
    const Node *current = list->head;
    printf("List: [");
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(" -> ");
        current = current->next;
    }
    printf("]\n");
}

void list_free(List *list) {
    Node *temp;
    while (list->head) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}
