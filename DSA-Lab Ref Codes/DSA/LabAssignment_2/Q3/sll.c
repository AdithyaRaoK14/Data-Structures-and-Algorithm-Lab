#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "sll.h"

static Node* _list_node_new_(int32_t data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

List* slist_new() {
    List* list = (List*)malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->length = 0;
    return list;
}

List* slist_free(List* list) {
    if (!list) return NULL;
    Node* cur = list->head;
    Node* temp;
    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    list->head = list->tail = NULL;
    list->length = 0;
    return list;
}

List* slist_add_tail(List* list, int32_t data) {
    Node* node = _list_node_new_(data);
    if (list->tail != NULL) {
        list->tail->next = node;
        list->tail = node;
    } else {
        list->head = list->tail = node;
    }
    ++list->length;
    return list;
}

uint32_t slist_length(const List* list) {
    return list ? list->length : 0;
}

void slist_print(const List* list) {
    if (list == NULL || list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf(" -> NULL\n");
}

List* slist_sort(List* list) {
    if (!list || !list->head || !list->head->next)
        return list;

    Node* i;
    Node* j;
    int temp;
    uint8_t swapped;

    do {
        swapped = 0;
        i = list->head;
        j = i->next;

        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
                swapped = 1;
            }
            i = j;
            j = j->next;
        }
    } while (swapped);

    return list;
}

List* slist_merge_sorted(const List* list1, const List* list2) {
    List* merged = slist_new();

    if (!list1 && !list2)
        return merged;
    if (!list1)
        return (List*)list2;
    if (!list2)
        return (List*)list1;

    Node* a = list1->head;
    Node* b = list2->head;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            slist_add_tail(merged, a->data);
            a = a->next;
        } else {
            slist_add_tail(merged, b->data);
            b = b->next;
        }
    }

    while (a != NULL) {
        slist_add_tail(merged, a->data);
        a = a->next;
    }
    while (b != NULL) {
        slist_add_tail(merged, b->data);
        b = b->next;
    }

    return merged;
}


List* slist_link(List* list1, List* list2) {
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }

    if (list1 == NULL || list1->head == NULL) {
        return list2;
    }

    if (list2 == NULL || list2->head == NULL) {
        return list1;
    }

    list1->tail->next = list2->head;
    list1->tail = list2->tail;
    list1->length += list2->length;

    return list1;
}

