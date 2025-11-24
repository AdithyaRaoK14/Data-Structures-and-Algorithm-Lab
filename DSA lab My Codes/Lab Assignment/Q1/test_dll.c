#include <assert.h>
#include "dll.h"
#include <stddef.h> 
void test_dll() {
    DLL l = dll_new();
    dll_add(&l, 10);
    dll_add(&l, 20);
    dll_add(&l, 30);

    assert(l.head->data == 10);
    assert(l.tail->data == 30);

    dll_delete(&l, 20);
    assert(l.head->next->data == 30);

    dll_free(&l);
    assert(l.head == NULL && l.tail == NULL);
}

int main() {
    test_dll();
    return 0;
}
