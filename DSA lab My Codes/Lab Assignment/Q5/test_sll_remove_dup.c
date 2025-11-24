#include <assert.h>
#include "sll_remove_dup.h"
#include <stddef.h> 
void test_sll_remove_dup() {
    DList l = dlist_new();
    dlist_insert(&l, 10);
    dlist_insert(&l, 20);
    dlist_insert(&l, 10);
    dlist_insert(&l, 30);
    dlist_insert(&l, 20);

    dlist_remove_duplicates(&l);

    // Verify no duplicates
    for (DNodeSLL *c1 = l.head; c1; c1 = c1->next) {
        for (DNodeSLL *c2 = c1->next; c2; c2 = c2->next) {
            assert(c1->data != c2->data);
        }
    }

    dlist_free(&l);
    assert(l.head == NULL);
}

int main() {
    test_sll_remove_dup();
    return 0;
}
