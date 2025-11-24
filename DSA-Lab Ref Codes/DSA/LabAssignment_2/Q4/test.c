#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    BST *tree = bst_new();

    Employee employees[] = {
        {105, "Alice Johnson", 55000},
        {101, "Bob Smith", 48000},
        {110, "Charlie Adams", 69000},
        {103, "Diana King", 72000},
        {107, "Eve Miller", 52000},
        {115, "Frank Turner", 83000},
        {104, "Grace Lee", 67000}
    };

    int n = sizeof(employees) / sizeof(employees[0]);

    for (int i = 0; i < n; i++) {
        bst_insert(tree, employees[i]);
    }

    printf("All Employees (Ascending by Employee ID):\n");
    bst_display_inorder(tree->root);

    int search_id = 110;
    printf("\nSearching for Employee with ID %d:\n", search_id);
    Node *found = bst_search(tree->root, search_id);
    if (found) {
        printf("Employee found:\n");
        printf("ID: %d, Name: %s, Salary: %.2f\n",
               found->emp.emp_id, found->emp.name, found->emp.salary);
    } else {
        printf("Employee with ID %d not found.\n", search_id);
    }

    printf("\nEmployees with salary between 50,000 and 70,000:\n");
    bst_display_salary_range(tree->root, 50000.0f, 70000.0f);

    bst_free(tree->root);
    free(tree);
    return 0;
}
