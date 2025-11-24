#ifndef STACK_H
#define STACK_H

#include <stdint.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack *stack_create(int size);
void stack_push(Stack **stk, int value);
int stack_pop(Stack *stk);
int stack_peek(Stack *stk);
int stack_is_empty(Stack *stk);
void stack_free(Stack *stk);

#endif
