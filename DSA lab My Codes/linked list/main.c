#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "slist.h"

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

uint32_t slist_lookup(const List* list, int32_t key) {
    Node* node = list->head;
    while (node != NULL) {
        if (node->data == key) return 1; // Found
        node = node->next;
    }
    return 0; // Not found
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
List* slist_delete_duplicates(List* list) {
    if (list == NULL || list->head == NULL) {
        return list;  // Return if list is empty or NULL
    }

    Node* current = list->head;
    
    while (current != NULL) {
        Node* runner = current;
        
        // Check if any subsequent node has the same value as the current node
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Found a duplicate, remove it
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);  // Free the memory for the duplicate node
                --list->length;
            } else {
                runner = runner->next;  // Move to next node
            }
        }
        current = current->next;  // Move to next node
    }

    return list;
}

List* slist_swap(List* list, int32_t key1, int32_t key2) {
    if (list == NULL || list->head == NULL || key1 == key2) {
        return list;  // No swap needed
    }

    Node *prev1 = NULL, *curr1 = list->head;
    Node *prev2 = NULL, *curr2 = list->head;

    // Find the nodes with key1 and key2
    while (curr1 != NULL && curr1->data != key1) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    while (curr2 != NULL && curr2->data != key2) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    // If either node is not found, return the list unchanged
    if (curr1 == NULL || curr2 == NULL) {
        return list;
    }

    // If key1 is the head
    if (prev1 == NULL) {
        list->head = curr2;
    } else {
        prev1->next = curr2;
    }

    // If key2 is the head
    if (prev2 == NULL) {
        list->head = curr1;
    } else {
        prev2->next = curr1;
    }

    // Swap the next pointers of curr1 and curr2
    Node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;

    // If one of the swapped nodes was the tail, update the tail pointer
    if (curr1->next == NULL) {
        list->tail = curr1;
    }
    if (curr2->next == NULL) {
        list->tail = curr2;
    }

    return list;
}

