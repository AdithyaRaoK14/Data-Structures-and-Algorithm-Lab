#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "LinkedList.h"

// Function to print the list (Optional for testing)
void print_list(const List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Test function for the singly linked list
void test_slist_genetic() {
    // Create new list
    List* list = slist_new();
    assert(slist_length(list) == 0);  // Initial list should be empty

    // Add elements at the head
    slist_add_head(list, 10);
    slist_add_head(list, 20);
    assert(slist_length(list) == 2);  // List should have 2 elements now
    print_list(list);  // Optional: print to check the list

    // Test lookup
    assert(slist_lookup(list, 20));  // 20 should be in the list
    assert(!slist_lookup(list, 30)); // 30 should NOT be in the list

    // Add elements at the tail
    slist_add_tail(list, 30);
    slist_add_tail(list, 40);
    assert(slist_length(list) == 4);  // List should now have 4 elements
    print_list(list);  // Optional: print to check the list

    // Test swap operation
    printf("Before swapping 20 and 40:\n");
    print_list(list);
    slist_swap(list, 20, 40);
    printf("After swapping 20 and 40:\n");
    print_list(list);  // Check the result of swap

    // Test swapping adjacent nodes (10 and 30)
    printf("Before swapping 10 and 30:\n");
    print_list(list);
    slist_swap(list, 10, 30);
    printf("After swapping 10 and 30:\n");
    print_list(list);  // Check the result of swap

    // Cleanup
    slist_free(list);
}

int main() {
    test_slist_genetic();
    return 0;
}