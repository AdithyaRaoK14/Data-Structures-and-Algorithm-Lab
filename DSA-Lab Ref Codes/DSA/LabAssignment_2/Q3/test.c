#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

int main() {
    List* list1 = slist_new();
    slist_add_tail(list1, 1);
    slist_add_tail(list1, 3);
    slist_add_tail(list1, 5);
    slist_add_tail(list1, 7);

    printf("List 1:\n");
    slist_print(list1);

    List* list2 = slist_new();
    slist_add_tail(list2, 2);
    slist_add_tail(list2, 4);
    slist_add_tail(list2, 6);
    slist_add_tail(list2, 8);

    printf("List 2:\n");
    slist_print(list2);

    List* merged = slist_merge_sorted(list1, list2);

    printf("\nMerged Sorted List:\n");
    slist_print(merged);

    printf("\nMerged List:\n");
    slist_link(list1,list2);
    slist_print(list1);

    slist_free(list1);
    slist_free(list2);
    slist_free(merged);

    return 0;
}
