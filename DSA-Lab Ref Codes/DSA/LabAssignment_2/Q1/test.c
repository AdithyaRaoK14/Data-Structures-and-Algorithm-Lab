#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack s = stack_new(2);
    StackResult result;
    printf("Initial stack size: %u\n", s.size);

    for (int i = 1; i <= 5; i++) {
        printf("Pushing : %d\n",i);
        stack_push(&s, i, &result);
        display(&s);
    }

    // stack_peek(&s, &result);
    printf("\nFinal Stack after pushing:\n");
    display(&s);
    printf("\n");

    for (int i = 0; i < 6; i++) {
        stack_pop(&s, &result);
        display(&s);
    }

    printf("\nFinal Stack after popping:\n");
    display(&s);
    printf("\n");

    stack_free(&s);
    printf("\nStack memory freed.\n");
    return 0;
}
