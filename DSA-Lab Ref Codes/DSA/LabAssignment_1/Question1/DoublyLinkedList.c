#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "DoublyLinkedList.h"

List* dlist_new() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

List* dlist_free(List* list) {
    Node* cur, * p;
    if (dlist_length(list) > 0) {
        assert(list->head && list->tail);
        cur = list->head;
        list->head = NULL;
        list->tail = NULL;
        while (cur != NULL) {
            p = cur;
            cur = cur->next;
            free(p);
            --list->length;
        }
    }
    return list;
}

static Node* _list_node_new_(int32_t data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

List* dlist_add_head(List* list, int32_t data) {
    Node* node = _list_node_new_(data);
    node->next = list->head;
    if(list->head != NULL) {
        list->head->prev = node;
    }
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
    }
    ++list->length;
    return list;
}

List* dlist_add_tail(List* list, int32_t data) {
    Node* node = _list_node_new_(data);
    if (list->tail != NULL) {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    } else {
        list->head = list->tail = node;
    }
    ++list->length;
    return list;
}

uint32_t dlist_length(const List* list) {
    return list->length;
}


List* dlist_delete_head(List* list) {
    if (list->head != NULL) {
        Node* node = list->head;
        list->head = list->head->next;
        if(list->head != NULL) {
            list->head->prev = NULL;
        } else{
            list->tail = NULL;
        }
        free(node);
        --list->length;
    }
    return list;
}


List* dlist_delete_tail(List* list) {
    if (list->tail != NULL) {
        Node* node = list->tail;
        list->tail = list->tail->prev;
        if (list->tail != NULL) {
            list->tail->next = NULL;
        } else {
            list->head = NULL; // If the list becomes empty
        }
        free(node);
        --list->length;
    }
    return list;
}
