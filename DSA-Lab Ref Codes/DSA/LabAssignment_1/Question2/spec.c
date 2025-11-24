#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int main() {
    Stack* stack = stack_init();

    stack_push(stack, 20);
    stack_push(stack, 45);
    stack_push(stack, 65);
    stack_push(stack, 75);
    stack_push(stack, 33);
    stack_push(stack, 50);
    display_stack(stack);
    display_key(stack, 65);

    free(stack);
    return 0;
}
