// #include <assert.h>
// #include "stack.h"

// int main() {
//     Stack *s = stack_create(2);
//     stack_push(&s, 10);
//     stack_push(&s, 20);
//     stack_push(&s, 30);

//     assert(stack_peek(s) == 30);
//     assert(stack_pop(s) == 30);
//     assert(stack_pop(s) == 20);
//     assert(stack_pop(s) == 10);
//     assert(stack_is_empty(s) == 1);

//     stack_free(s);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack *s = stack_create(2);

    printf(" Stack created with initial capacity: %d\n\n", s->capacity);

    printf("Pushing 10...\n");
    stack_push(&s, 10);
    printf("Pushing 20...\n");
    stack_push(&s, 20);
    printf("Pushing 30 (should trigger resize)...\n");
    stack_push(&s, 30);

    printf("\n Current top element: %d\n", stack_peek(s));

    printf("\n--- Popping Elements ---\n");
    printf("Popped: %d\n", stack_pop(s));
    printf("Popped: %d\n", stack_pop(s));
    printf("Popped: %d\n", stack_pop(s));

    if (stack_is_empty(s))
        printf(" Stack is now empty.\n");
    else
        printf(" Stack is not empty (error)\n");

    stack_free(s);
    printf(" Stack memory freed successfully.\n");

    return 0;
}
