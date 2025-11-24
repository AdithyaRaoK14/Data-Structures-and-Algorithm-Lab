// Given a stack[] = {40,55,75,65,25,33,50} with top pointing to 50. Write a function to display the key 65

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stack.h"


Stack* stack_init() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1; 
    return stack;
}

void stack_push(Stack* stack, int32_t value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->top++;
        stack->data[stack->top] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

int32_t stack_pop(Stack* stack) {
    if (stack_is_empty(stack)) {
        printf("Stack underflow!\n");
        return -1; 
    }
    return stack->data[stack->top--];
}


int stack_is_empty(const Stack* stack) {
    return stack->top == -1;
}

int stack_is_full(const Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

int display_key(Stack* stack, int32_t key) {
    Stack* temp = stack_init();
    int count = 0;
    int found = -1;

    while (!stack_is_empty(stack)) {
        int val = stack_pop(stack);
        count++;
        stack_push(temp, val);

        if (val == key) {
            found = count;
            break;
        }
    }

    while (!stack_is_empty(temp)) {
        stack_push(stack, stack_pop(temp));
    }
    if(found!=-1){
        printf("%d found in %d index from top.",key,found);
    }else{
        printf("Key not found");
    }
    free(temp);
    return found;
}

void display_stack(const Stack* stack) {
    printf("Current Stack elements:\n");
    for(int i = stack->top;i>=0;i--) {
        printf("|%d|\n",stack->data[i]);
    }
}