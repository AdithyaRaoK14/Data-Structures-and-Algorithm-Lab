#include <assert.h>
#include "sll_sort.h"
 #include <stddef.h>
void test_sll_sort() {
    SList l = slist_new();
    slist_insert(&l, 40);
    slist_insert(&l, 10);
    slist_insert(&l, 30);
    slist_insert(&l, 20);
 
    slist_sort(&l); // Should become 10 -> 20 -> 30 -> 40
 
    int expected[] = {10, 20, 30, 40};
    int i = 0;
    for (SNode *cur = l.head; cur; cur = cur->next) {
        assert(cur->data == expected[i]);
        i++;
    }
 
    slist_free(&l);
    assert(l.head == NULL);
}
 
int main() {
    test_sll_sort();
    return 0;
}