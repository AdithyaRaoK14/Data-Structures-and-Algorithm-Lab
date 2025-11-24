#include <assert.h>
#include <stdio.h>
#include "sll.h"

// Test the functionality of the singly linked list with min and max tracking
void test_sll_minmax() {
    MList l = mlist_new();   // Create an empty list

    // Insert elements
    mlist_add_head(&l, 10);
    mlist_add_head(&l, 30);
    mlist_add_head(&l, 5);

    // Print all elements of the list
    mlist_print(&l);

    // Print the min and max values
    printf("Min value: %d\n", mlist_get_min(&l));  // Expected: 5
    printf("Max value: %d\n", mlist_get_max(&l));  // Expected: 30

    // Assertions to validate the min and max values
    assert(mlist_get_min(&l) == 5);
    assert(mlist_get_max(&l) == 30);

    // Free the list after use
    mlist_free(&l);
}

int main() {
    test_sll_minmax();  // Run the test
    return 0;
}
