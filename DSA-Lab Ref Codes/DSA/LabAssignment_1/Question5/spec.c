#include <assert.h>
#include <stdio.h>
#include "sll.h"

// Test the functionality of removing duplicates from the linked list
void test_sll_remove_duplicates() {
    SLLList list = sll_create();  // Create an empty list

    // Insert some elements
    sll_add_node(&list, 10);
    sll_add_node(&list, 20);
    sll_add_node(&list, 10);
    sll_add_node(&list, 30);
    sll_add_node(&list, 20);

    // Print the list before removing duplicates
    printf("Before removing duplicates:\n");
    sll_print(&list);

    // Remove duplicates
    sll_delete_duplicates(&list);

    // Print the list after removing duplicates
    printf("After removing duplicates:\n");
    sll_print(&list);

    // Verify no duplicates
    for (SLLNode *c1 = list.head; c1; c1 = c1->next) {
        for (SLLNode *c2 = c1->next; c2; c2 = c2->next) {
            assert(c1->data != c2->data);  // Ensure no duplicates
        }
    }

    // Free the list memory
    sll_destroy(&list);
    assert(list.head == NULL);  // Ensure the list is empty after destruction
}

int main() {
    test_sll_remove_duplicates();  // Run the test
    return 0;
}
