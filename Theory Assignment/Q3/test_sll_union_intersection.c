#include <assert.h>
#include "sll_union_intersection.h"

void test_union_and_intersection() {
    List l1 = list_new();
    List l2 = list_new();

    list_insert_unique(&l1, 10);
    list_insert_unique(&l1, 20);
    list_insert_unique(&l1, 30);

    list_insert_unique(&l2, 20);
    list_insert_unique(&l2, 40);
    list_insert_unique(&l2, 50);

    List uni = list_union(&l1, &l2);
    List inter = list_intersection(&l1, &l2);

    // Check union (10,20,30,40,50)
    int union_count = 0;
    for (Node *cur = uni.head; cur; cur = cur->next) union_count++;
    assert(union_count == 5);

    // Check intersection (20)
    int inter_count = 0;
    for (Node *cur = inter.head; cur; cur = cur->next) inter_count++;
    assert(inter_count == 1);

    list_free(&l1);
    list_free(&l2);
    list_free(&uni);
    list_free(&inter);
}

int main() {
    test_union_and_intersection();
    return 0;
}
