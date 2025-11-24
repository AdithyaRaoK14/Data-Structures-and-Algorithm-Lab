#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

Stack *stack_create(int size) {
    Stack *stk = (Stack*)malloc(sizeof(Stack));
    stk->data = (int*)malloc(size * sizeof(int));
    stk->top = -1;
    stk->capacity = size;
    return stk;
}

void stack_push(Stack **stk, int value) {
    assert(stk && *stk);
    if ((*stk)->top == (*stk)->capacity - 1) {
        (*stk)->capacity *= 2;
        (*stk)->data = (int*)realloc((*stk)->data, (*stk)->capacity * sizeof(int));
    }
    (*stk)->data[++((*stk)->top)] = value;
}

int stack_pop(Stack *stk) {
    assert(stk && stk->top >= 0);
    return stk->data[stk->top--];
}

int stack_peek(Stack *stk) {
    assert(stk && stk->top >= 0);
    return stk->data[stk->top];
}

int stack_is_empty(Stack *stk) {
    return stk->top == -1;
}

void stack_free(Stack *stk) {
    free(stk->data);
    free(stk);
}
