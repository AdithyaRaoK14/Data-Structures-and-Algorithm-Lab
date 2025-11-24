#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

// Insert a new employee into the binary search tree
Employee* insert_employee(Employee *root, int id, const char *name, float salary) {
    if (!root) {
        Employee *new = (Employee*)malloc(sizeof(Employee));
        new->id = id;
        strcpy(new->name, name);
        new->salary = salary;
        new->left = new->right = NULL;
        return new;
    }

    if (id < root->id)
        root->left = insert_employee(root->left, id, name, salary);
    else if (id > root->id)
        root->right = insert_employee(root->right, id, name, salary);
    else
        printf("Duplicate Employee ID %d ignored.\n", id);

    return root;
}

// Search an employee by ID
Employee* search_employee(Employee *root, int id) {
    if (!root || root->id == id)
        return root;

    if (id < root->id)
        return search_employee(root->left, id);
    else
        return search_employee(root->right, id);
}

// Display employees whose salary is between low and high
void display_salary_range(Employee *root, float low, float high) {
    if (!root) return;

    display_salary_range(root->left, low, high);

    if (root->salary >= low && root->salary <= high)
        printf("ID: %d | Name: %s | Salary: %.2f\n", root->id, root->name, root->salary);

    display_salary_range(root->right, low, high);
}

// Display all employees in ascending order of ID (inorder traversal)
void display_inorder(Employee *root) {
    if (!root) return;

    display_inorder(root->left);
    printf("ID: %d | Name: %s | Salary: %.2f\n", root->id, root->name, root->salary);
    display_inorder(root->right);
}

// Free the allocated memory
void free_tree(Employee *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
