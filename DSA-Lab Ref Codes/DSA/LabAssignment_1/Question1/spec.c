#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "LinkedList.h"

// Function to print the list (Optional for testing)
void print_list(const List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void test_dlist_genetic() {
    // Create a new list
    List* list = dlist_new();
    assert(dlist_length(list) == 0);
    printf("Initial list:\n");
    print_list(list);  //

    // Add elements at the head
    dlist_add_head(list, 10);
    dlist_add_head(list, 20);
    assert(dlist_length(list) == 2);
    printf("After adding 20 and 10 at head:\n");
    print_list(list);

    // Add elements at the tail
    dlist_add_tail(list, 30);
    dlist_add_tail(list, 40);
    assert(dlist_length(list) == 4);
    printf("After adding 30 and 40 at tail:\n");
    print_list(list);

    // Delete element at head
    dlist_delete_head(list);
    assert(dlist_length(list) == 3);
    printf("After deleting head:\n");
    print_list(list);

    // Delete element at tail
    dlist_delete_tail(list);
    assert(dlist_length(list) == 2);
    printf("After deleting tail:\n");
    print_list(list);

    dlist_free(list);
}

int main() {
    test_dlist_genetic();
    return 0;
}
