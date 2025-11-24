#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

Node *create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_sorted(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL || (*head)->data >= data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

Node *merge_sorted(Node *a, Node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node *result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = merge_sorted(a->next, b);
    } else {
        result = b;
        result->next = merge_sorted(a, b->next);
    }
    return result;
}

void display_list(Node *head) {
    Node *temp = head;
    printf("List: [");
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf("]\n");
}

void free_list(Node *head) {
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
