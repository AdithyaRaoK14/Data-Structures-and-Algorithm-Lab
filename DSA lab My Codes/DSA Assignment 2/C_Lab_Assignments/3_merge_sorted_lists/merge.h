#ifndef MERGE_H
#define MERGE_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create new node
Node *create_node(int data);

// Insert node at end (for building sorted lists)
void insert_sorted(Node **head, int data);

// Merge two sorted linked lists into one sorted list
Node *merge_sorted(Node *a, Node *b);

// Display the linked list
void display_list(Node *head);

// Free the linked list
void free_list(Node *head);

#endif
