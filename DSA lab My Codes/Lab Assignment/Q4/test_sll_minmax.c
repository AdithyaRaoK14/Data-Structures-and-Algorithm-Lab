#include <assert.h>
#include "sll_minmax.h"

void test_sll_minmax() {
    MList l = mlist_new();
    mlist_insert(&l, 10);
    mlist_insert(&l, 30);
    mlist_insert(&l, 5);

    assert(mlist_min(&l) == 5);
    assert(mlist_max(&l) == 30);

    mlist_free(&l);
}

int main() {
    test_sll_minmax();
    return 0;
}
