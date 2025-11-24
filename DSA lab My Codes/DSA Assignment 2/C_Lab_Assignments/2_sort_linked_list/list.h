#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

List *list_create();
void list_insert(List *list, int data);
void list_sort(List *list);
void list_display(const List *list);
void list_free(List *list);

#endif
