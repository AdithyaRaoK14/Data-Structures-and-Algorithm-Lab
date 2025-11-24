#include <assert.h>
#include "student_list.h"
#include <stddef.h>
void test_student_list() {
    StudentList sl = student_list_new();

    student_insert(&sl, 1, "Alice");
    student_insert(&sl, 2, "Bob");
    student_insert(&sl, 3, "Charlie");

    assert(sl.head != NULL);

    // Delete Bob
    student_delete(&sl, 2);

    // Ensure Bob not present
    for (Student *cur = sl.head; cur; cur = cur->next) {
        assert(cur->rollno != 2);
    }

    student_list_free(&sl);
    assert(sl.head == NULL);
}

int main() {
    test_student_list();
    return 0;
}
