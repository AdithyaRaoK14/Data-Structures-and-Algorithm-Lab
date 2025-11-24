#include <assert.h>
#include <stddef.h>
#include "stack.h"

// Initialize a new stack with the given size
Stack stack_new(uint32_t size) {
    size = (size > 0 && size < MAX_DEPTH) ? size : MAX_DEPTH;
    Stack s = {size, -1, {0}};
    return s;
}

// Check if the stack is full
uint32_t stack_full(const Stack *stk) {
    assert(stk != NULL);
    return (stk->top + 1) == stk->size;
}

// Check if the stack is empty
uint32_t stack_empty(const Stack *stk) {
    assert(stk != NULL);
    return stk->top == -1;
}

// Push a value onto the stack
const Stack *stack_push(Stack *stk, float data, StackResult *result) {
    assert(stk != NULL);
    if (stk->top + 1 < stk->size) {
        stk->data[++stk->top] = data;
        result->data = data;
        result->status = STACK_OK;
    } else {
        result->data = data;
        result->status = STACK_FULL;
    }
    return stk;
}

// Pop a value from the stack
const Stack *stack_pop(Stack *stk, StackResult *result) {
    assert(stk != NULL);
    if (stk->top > -1) {
        result->data = stk->data[stk->top];
        result->status = STACK_OK;
        --stk->top;
    } else {
        result->status = STACK_EMPTY;
    }
    return stk;
}

// Peek at the top value of the stack
const Stack *stack_peek(const Stack *stk, StackResult *result) {
    assert(stk != NULL);
    if (stk->top != -1) {
        result->data = stk->data[stk->top];
        result->status = STACK_OK;
    } else {
        result->status = STACK_EMPTY;
    }
    return stk;  // Return a const pointer
}
