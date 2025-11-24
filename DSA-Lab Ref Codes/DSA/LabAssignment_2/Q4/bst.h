#ifndef EMPLOYEE_BST_H
#define EMPLOYEE_BST_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
    int emp_id;
    char name[50];
    float salary;
} Employee;

typedef struct _node_ {
    Employee emp;
    struct _node_ *left;
    struct _node_ *right;
} Node;

typedef struct {
    Node *root;
} BST;

BST* bst_new();
Node* bst_insert(BST *tree, Employee emp);
Node* bst_search(Node *root, int emp_id);
void bst_display_salary_range(Node *root, float min_salary, float max_salary);
void bst_display_inorder(Node *root);
void bst_free(Node *root);

#endif
