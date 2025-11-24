// #include <stdio.h>
// #include <stdlib.h>
// #include "employee.h"

// int main() {
//     Employee *root = NULL;
//     int n, id, choice;
//     char name[50];
//     float salary;

//     printf("Enter number of employees to insert: ");
//     scanf("%d", &n);

//     // Insert N employees
//     for (int i = 0; i < n; i++) {
//         printf("\nEnter details for Employee %d:\n", i + 1);
//         printf("Employee ID: ");
//         scanf("%d", &id);
//         printf("Name: ");
//         scanf("%s", name);
//         printf("Salary: ");
//         scanf("%f", &salary);

//         root = insert_employee(root, id, name, salary);
//     }

//     do {
//         printf("\n\n---- MENU ----\n");
//         printf("1. Search Employee by ID\n");
//         printf("2. Display Employees with Salary between 50k - 70k\n");
//         printf("3. Display All Employees (Ascending by ID)\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1: {
//                 printf("Enter Employee ID to search: ");
//                 scanf("%d", &id);
//                 Employee *found = search_employee(root, id);
//                 if (found)
//                     printf("Found: ID: %d | Name: %s | Salary: %.2f\n", found->id, found->name, found->salary);
//                 else
//                     printf("Employee with ID %d not found.\n", id);
//                 break;
//             }

//             case 2:
//                 printf("\nEmployees with salary between 50000 - 70000:\n");
//                 display_salary_range(root, 50000, 70000);
//                 break;

//             case 3:
//                 printf("\nAll Employees (sorted by ID):\n");
//                 display_inorder(root);
//                 break;

//             case 4:
//                 printf("Exiting program...\n");
//                 break;

//             default:
//                 printf("Invalid choice. Try again.\n");
//         }

//     } while (choice != 4);

//     free_tree(root);
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main() {
    Employee *root = NULL;

    // Hardcoded employee details
    root = insert_employee(root, 3, "Alice", 60000);
    root = insert_employee(root, 1, "Bob", 52000);
    root = insert_employee(root, 5, "Charlie", 70000);
    root = insert_employee(root, 2, "David", 55000);
    root = insert_employee(root, 4, "Eve", 65000);

    printf("Employee records inserted successfully.\n\n");

    // (a) Search for a specific employee
    int search_id = 2;
    printf("Searching for Employee with ID %d:\n", search_id);
    Employee *found = search_employee(root, search_id);
    if (found)
        printf("Found: ID: %d | Name: %s | Salary: %.2f\n\n",
               found->id, found->name, found->salary);
    else
        printf("Employee with ID %d not found.\n\n", search_id);

    // (b) Display employees with salary in range 50K–70K
    printf("Employees with salary between 50000 - 70000:\n");
    display_salary_range(root, 50000, 70000);
    printf("\n");

    // (c) Display all employees sorted by ID
    printf("All Employees (sorted by ID):\n");
    display_inorder(root);

    // Free memory
    free_tree(root);
    return 0;
}
