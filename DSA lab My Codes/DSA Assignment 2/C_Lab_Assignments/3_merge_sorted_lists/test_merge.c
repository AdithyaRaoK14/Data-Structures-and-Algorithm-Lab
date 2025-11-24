#include <stdio.h>
#include "merge.h"

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;

    insert_sorted(&list1, 1);
    insert_sorted(&list1, 3);
    insert_sorted(&list1, 5);

    insert_sorted(&list2, 2);
    insert_sorted(&list2, 4);
    insert_sorted(&list2, 6);

    printf("List 1 before merge:\n");
    display_list(list1);

    printf("List 2 before merge:\n");
    display_list(list2);

    Node *merged = merge_sorted(list1, list2);
    printf("\nMerged List:\n");
    display_list(merged);

    free_list(merged);
    return 0;
}
