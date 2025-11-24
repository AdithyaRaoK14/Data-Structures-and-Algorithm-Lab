// #include <assert.h>
// #include "stack_key.h"

// void test_stack_key() {
//     int stack[] = {20, 45, 65, 75, 33, 50};
//     int top = 5; // points to 50

//     assert(stack_display_key(stack, top, 65) == 1);
//     assert(stack_display_key(stack, top, 99) == 0);
// }

// int main() {
//     test_stack_key();
//     return 0;
// }

#include <assert.h>
#include "stack_key.h"

void test_stack_key() {
    int stack[MAX_STACK_SIZE];
    int top = -1;

    push(stack, &top, 20);
    push(stack, &top, 45);
    push(stack, &top, 65);
    push(stack, &top, 75);
    push(stack, &top, 33);
    push(stack, &top, 50);

    assert(stack_display_key(stack, &top, 65) == 1);
    assert(stack_display_key(stack, &top, 99) == 0);

    pop(stack, &top);  // Pop the top (50)
    assert(stack_display_key(stack, &top, 50) == 1);  // 50 should not be found

    pop(stack, &top);  // Pop 33
    pop(stack, &top);  // Pop 75
    pop(stack, &top);  // Pop 65
    pop(stack, &top);  // Pop 45
    pop(stack, &top);  // Pop 20

    assert(stack_display_key(stack, &top, 65) == 1);  // Stack is empty, key not found
}

int main() {
    test_stack_key();
    return 0;
}


