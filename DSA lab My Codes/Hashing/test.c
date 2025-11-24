#include "hashing.h"
#include <stdio.h>

void print_test_result(const char *test_name, int condition) {
    if (condition) {
        printf("%s: PASSED\n", test_name);
    } else {
        printf("%s: FAILED\n", test_name);
    }
}

int main() {
    // Create a new hash table with 10 buckets
    HashTable htb = hashtable_new(10);

    // Insert elements into the hash table
    printf("Inserting 'apple' into hash table.\n");
    hashtable_insert_element(&htb, "apple");
    printf("Inserting 'banana' into hash table.\n");
    hashtable_insert_element(&htb, "banana");
    printf("Inserting 'cherry' into hash table.\n");
    hashtable_insert_element(&htb, "cherry");

    // Search for elements in the hash table
    print_test_result("Find 'apple'", hashtable_find(&htb, "apple"));
    print_test_result("Find 'banana'", hashtable_find(&htb, "banana"));
    print_test_result("Find 'cherry'", hashtable_find(&htb, "cherry"));
    print_test_result("Find 'grape' (should not exist)", !hashtable_find(&htb, "grape"));

    // Delete an element
    printf("Deleting 'banana' from hash table.\n");
    hashtable_delete_element(&htb, "banana");

    // Search again after deletion
    print_test_result("Find 'banana' after deletion", !hashtable_find(&htb, "banana"));
    print_test_result("Find 'apple' after deletion", hashtable_find(&htb, "apple"));
    print_test_result("Find 'cherry' after deletion", hashtable_find(&htb, "cherry"));

    // Insert a new element and check
    printf("Inserting 'grape' into hash table.\n");
    hashtable_insert_element(&htb, "grape");
    print_test_result("Find 'grape' after insertion", hashtable_find(&htb, "grape"));

    // Cleanup (destroy the hash table)
    printf("Destroying hash table...\n");
    hashtable_destroy(&htb);

    return 0;
}
