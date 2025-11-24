#include <assert.h>
#include "sll_reverse_nth.h"
#include <stddef.h>
void test_reverse_and_nth() {
    RList l = rlist_new();

    rlist_insert(&l, 10);
    rlist_insert(&l, 20);
    rlist_insert(&l, 30); // List = 30->20->10

    rlist_reverse(&l);    // Reversed = 10->20->30

    // Check Nth from end
    assert(rlist_nth_from_end(&l, 1) == 30); // last
    assert(rlist_nth_from_end(&l, 2) == 20); // 2nd last
    assert(rlist_nth_from_end(&l, 3) == 10); // 3rd last

    rlist_free(&l);
    assert(l.head == NULL);
}

int main() {
    test_reverse_and_nth();
    return 0;
}
