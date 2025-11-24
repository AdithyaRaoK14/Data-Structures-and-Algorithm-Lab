#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "student_list.h"
#include <stddef.h>
// Create new student list
StudentList student_list_new() {
    StudentList sl = {NULL};
    return sl;
}

// Insert student
StudentList* student_insert(StudentList *list, int32_t roll, const char *name) {
    assert(list != NULL);
    Student *new_stu = (Student*) malloc(sizeof(Student));
    new_stu->rollno = roll;
    strncpy(new_stu->name, name, 29);
    new_stu->name[29] = '\0';
    new_stu->next = list->head;
    list->head = new_stu;
    return list;
}

// Delete student by roll number
StudentList* student_delete(StudentList *list, int32_t roll) {
    assert(list != NULL);
    Student *cur = list->head, *prev = NULL;
    while (cur) {
        if (cur->rollno == roll) {
            if (prev) prev->next = cur->next;
            else list->head = cur->next;
            free(cur);
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    return list;
}

// Free memory
void student_list_free(StudentList *list) {
    assert(list != NULL);
    Student *cur = list->head;
    while (cur) {
        Student *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}
