// #include <assert.h>
// #include "list.h"

// int main() {
//     List *list = list_create();
//     list_insert(list, 3);
//     list_insert(list, 1);
//     list_insert(list, 2);

//     list_sort(list);

//     assert(list->head->data == 1);
//     assert(list->head->next->data == 2);
//     assert(list->head->next->next->data == 3);

//     list_free(list);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    List *list = list_create();
    printf("Empty list created successfully.\n\n");

    printf("Inserting 3...\n");
    list_insert(list, 3);
    list_display(list);

    printf("Inserting 1...\n");
    list_insert(list, 1);
    list_display(list);

    printf("Inserting 2...\n");
    list_insert(list, 2);
    list_display(list);

    printf("\n--- Sorting List ---\n");
    list_sort(list);
    list_display(list);

    if (list->head &&
        list->head->data == 1 &&
        list->head->next &&
        list->head->next->data == 2 &&
        list->head->next->next &&
        list->head->next->next->data == 3) {
        printf("List sorted correctly (1 -> 2 -> 3)\n");
    } else {
        printf("List not sorted correctly!\n");
    }

    list_free(list);
    printf("\nList memory freed successfully.\n");
    return 0;
}

