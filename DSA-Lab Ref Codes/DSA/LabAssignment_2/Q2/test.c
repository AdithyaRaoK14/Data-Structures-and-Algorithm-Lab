#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "sll.h"

void test_slist_sort() {
    List* list = slist_new();
    slist_add_tail(list, 50);
    slist_add_tail(list, 10);
    slist_add_tail(list, 30);
    slist_add_tail(list, 20);
    slist_add_tail(list, 40);

    printf("Before sorting:\n");
    slist_print(list);

    slist_sort(list);

    printf("After sorting:\n");
    slist_print(list);

    slist_free(list);
}


int main() {
    test_slist_sort();
    return 0;
}
