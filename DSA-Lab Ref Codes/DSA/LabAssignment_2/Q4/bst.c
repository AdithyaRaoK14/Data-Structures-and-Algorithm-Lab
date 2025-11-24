#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

BST* bst_new() {
    BST *tree = (BST*)malloc(sizeof(BST));
    if (tree != NULL) {
        tree->root = NULL;
    }
    return tree;
}

static Node* _create_node(Employee emp) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node != NULL) {
        node->emp = emp;
        node->left = node->right = NULL;
    }
    return node;
}

Node* bst_insert(BST *tree, Employee emp) {
    Node *new_node = _create_node(emp);
    if (!tree->root) {
        tree->root = new_node;
        return new_node;
    }

    Node *current = tree->root;
    Node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (emp.emp_id < current->emp.emp_id)
            current = current->left;
        else if (emp.emp_id > current->emp.emp_id)
            current = current->right;
        else {
            printf("Employee with ID %d already exists!\n", emp.emp_id);
            free(new_node);
            return NULL;
        }
    }

    if (emp.emp_id < parent->emp.emp_id)
        parent->left = new_node;
    else
        parent->right = new_node;

    return new_node;
}

Node* bst_search(Node *root, int emp_id) {
    if (!root)
        return NULL;

    if (emp_id == root->emp.emp_id)
        return root;
    else if (emp_id < root->emp.emp_id)
        return bst_search(root->left, emp_id);
    else
        return bst_search(root->right, emp_id);
}

void bst_display_salary_range(Node *root, float min_salary, float max_salary) {
    if (!root)
        return;

    bst_display_salary_range(root->left, min_salary, max_salary);

    if (root->emp.salary >= min_salary && root->emp.salary <= max_salary) {
        printf("ID: %d, Name: %s, Salary: %.2f\n",
               root->emp.emp_id, root->emp.name, root->emp.salary);
    }

    bst_display_salary_range(root->right, min_salary, max_salary);
}

void bst_display_inorder(Node *root) {
    if (!root)
        return;

    bst_display_inorder(root->left);
    printf("ID: %d, Name: %s, Salary: %.2f\n",
           root->emp.emp_id, root->emp.name, root->emp.salary);
    bst_display_inorder(root->right);
}

void bst_free(Node *root) {
    if (!root)
        return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}
