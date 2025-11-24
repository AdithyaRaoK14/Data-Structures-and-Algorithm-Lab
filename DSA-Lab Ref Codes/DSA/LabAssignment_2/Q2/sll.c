#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "sll.h"

List* slist_new() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

List* slist_free(List* list) {
    Node* cur, * p;
    if (slist_length(list) > 0) {
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
    node->next = NULL;
    return node;
}

List* slist_add_head(List* list, int32_t data) {
    Node* node = _list_node_new_(data);
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
    }
    ++list->length;
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
    return list->length;
}

List* slist_sort(List* list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return list;
    }

    Node *i, *j;
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

List* slist_delete_head(List* list) {
    if (list->head != NULL) {
        Node* node = list->head;
        list->head = list->head->next;
        free(node);
        --list->length;
        if (list->head == NULL) {
            list->tail = NULL;
        }
    }
    return list;
}

List* slist_delete_tail(List* list) {
    if (list->tail != NULL) {
        if (list->head == list->tail) {
            free(list->tail);
            list->head = list->tail = NULL;
        } else {
            Node* node = list->head;
            while (node->next != list->tail) {
                node = node->next;
            }
            free(list->tail);
            list->tail = node;
            list->tail->next = NULL;
        }
        --list->length;
    }
    return list;
}

List* slist_add_on_data(List* list, int32_t key, int32_t data) {
    Node* cur = list->head;
    Node* node = _list_node_new_(data);
    while (cur != NULL && cur->data != key) {
        cur = cur->next;
    }
    if (cur != NULL) {
        node->next = cur->next;
        cur->next = node;
        if (node->next == NULL) {
            list->tail = node;
        }
        ++list->length;
    }
    return list;
}

List* slist_delete_on_data(List* list, int32_t data) {
    if (list->head != NULL) {
        Node* cur = list->head;
        Node* p = NULL;

        if (cur->data == data) {
            list->head = cur->next;
            if (list->head == NULL) {
                list->tail = NULL;
            }
            free(cur);
            --list->length;
        } else {
            while (cur != NULL && cur->data != data) {
                p = cur;
                cur = cur->next;
            }

            if (cur != NULL) {
                p->next = cur->next;
                if (cur == list->tail) {
                    list->tail = p;
                }
                free(cur);
                --list->length;
            }
        }
    }
    return list;
}
