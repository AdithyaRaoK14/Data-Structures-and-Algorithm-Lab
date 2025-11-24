#include <assert.h>
#include <stdio.h>
#include "sll.h"

// Test the sorting functionality of the linked list
void test_sll_sort() {
    List list = list_create();  // Create an empty list

    // Insert some elements (changed numbers)
    list_add_node(&list, 50);
    list_add_node(&list, 10);
    list_add_node(&list, 20);
    list_add_node(&list, 30);
    list_add_node(&list, 40);
    list_add_node(&list, 60);  // Added new insert
    list_add_node(&list, 5);    // Added new insert

    // Print the list before sorting
    printf("Before sorting:\n");
    list_print(&list);

    // Sort the list
    list_sort(&list); // The list should become 5 -> 10 -> 20 -> 30 -> 40 -> 50 -> 60

    // Print the list after sorting
    printf("After sorting:\n");
    list_print(&list);

    // Verify the sorting by checking the order of elements
    int expected[] = {5, 10, 20, 30, 40, 50, 60};
    int i = 0;
    for (Node *cur = list.head; cur; cur = cur->next) {
        assert(cur->data == expected[i]);
        i++;
    }

    // Free the list memory
    list_free(&list);
    assert(list.head == NULL);  // Ensure the list is empty after destruction
}

int main() {
    test_sll_sort();  // Run the test
    return 0;
}
