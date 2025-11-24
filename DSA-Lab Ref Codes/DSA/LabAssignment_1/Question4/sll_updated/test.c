#include "sll.h"

int main() {
    // Create a MinMaxStack
    minmaxStack* stack = create_minmax_stack();

    // Push elements
    printf("Pushing: 10, 20, 5, 30\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 5);
    push(stack, 30);

    // Display stack
    display(stack);

    // Show min and max
    printf("Current Min: %d\n", get_min(stack));
    printf("Current Max: %d\n", get_max(stack));

    // Pop an element
    printf("\nPopping top element...\n");
    pop(stack);

    // Display updated stack
    display(stack);

    // Show updated min and max
    printf("Current Min: %d\n", get_min(stack));
    printf("Current Max: %d\n", get_max(stack));

    // Pop all elements
    printf("\nPopping all remaining elements...\n");
    while (!is_empty(stack->mainStack)) {
        printf("Popped: %d\n", peek_stack(stack->mainStack));
        pop(stack);
    }

    display(stack);

    // Clean up memory
    free_minmax_stack(stack);

    return 0;
}
