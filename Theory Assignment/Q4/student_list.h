#ifndef _INCLUDED_STUDENT_LIST_
#define _INCLUDED_STUDENT_LIST_
#include <stdint.h>
#include <stddef.h>
// Student structure
typedef struct _student_ {
    int32_t rollno;
    char name[30];
    struct _student_ *next;
} Student;

// Student List
typedef struct _student_list_ {
    Student *head;
} StudentList;

// Function prototypes
StudentList student_list_new();
StudentList* student_insert(StudentList *list, int32_t roll, const char *name);
StudentList* student_delete(StudentList *list, int32_t roll);
void student_list_free(StudentList *list);

#endif
