#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee *left, *right;
} Employee;

// Function declarations
Employee* insert_employee(Employee *root, int id, const char *name, float salary);
Employee* search_employee(Employee *root, int id);
void display_salary_range(Employee *root, float low, float high);
void display_inorder(Employee *root);
void free_tree(Employee *root);

#endif
