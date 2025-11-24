// #include "stack_key.h"

// // Return 1 if key found, 0 otherwise
// int stack_display_key(int stack[], int top, int key) {
//     for (int i = top; i >= 0; i--) {
//         if (stack[i] == key) {
//             return 1;
//         }
//     }
//     return 0;
// }


#include "stack_key.h"
#include<stdio.h>

int push(int stack[], int* top, int value) {
    if (*top < MAX_STACK_SIZE - 1) {
        stack[++(*top)] = value;
        return 1;
    }
    return 0;
}

int pop(int stack[], int* top) {
    if (*top >= 0) {
        (*top)--;  // Properly decrement top
        return 1;
    }
    return 0;
}

int stack_display_key(int stack[], int* top, int key) {
    if (*top < 0) return 0;

    int temp_stack[MAX_STACK_SIZE];
    int temp_top = -1;
    int found = 0;

    for (int i = *top; i >= 0; i--) {
        int current = stack[i];
        if (current == key) {
            found = 1;
            break;
        }
        push(temp_stack, &temp_top, current);
    }

    while (temp_top >= 0) {
        push(stack, top, temp_stack[temp_top--]);
    }

    return found;
}
