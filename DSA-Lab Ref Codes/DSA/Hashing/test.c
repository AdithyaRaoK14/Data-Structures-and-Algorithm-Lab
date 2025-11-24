#include <stdio.h>
#include "hashing.h"

int main() {
    // Create a hash table with 10 buckets
    HASHTABLE ht = HT_new(10);

    printf("\n=== INSERTING ELEMENTS ===\n");
    HT_insert(&ht, "apple");
    HT_insert(&ht, "banana");
    HT_insert(&ht, "cherry");
    HT_insert(&ht, "grape");

    // Display the table
    HT_display(&ht);

    printf("\n=== SEARCHING ===\n");
    printf("Find 'apple'  : %s\n", HT_find(&ht, "apple") ? "FOUND" : "NOT FOUND");
    printf("Find 'banana' : %s\n", HT_find(&ht, "banana") ? "FOUND" : "NOT FOUND");
    printf("Find 'grape'  : %s\n", HT_find(&ht, "grape") ? "FOUND" : "NOT FOUND");
    printf("Find 'orange' : %s\n", HT_find(&ht, "orange") ? "FOUND" : "NOT FOUND");

    printf("\n=== DELETING 'banana' ===\n");
    HT_delete(&ht, "banana");

    // Display after deletion
    HT_display(&ht);

    printf("\nFind 'banana' after deletion: %s\n",
            HT_find(&ht, "banana") ? "FOUND" : "NOT FOUND");

    printf("\n=== INSERTING NEW ELEMENT ===\n");
    HT_insert(&ht, "melon");
    HT_display(&ht);

    printf("\n=== DESTROYING HASH TABLE ===\n");
    HT_destroy(&ht);

    printf("\nHash table successfully destroyed.\n");

    return 0;
}
