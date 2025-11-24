#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Stack stack_new(uint32_t size) {
    if (size == 0)
        size = 1;

    Stack s;
    s.size = size;
    s.top = -1;
    s.data = (int *)malloc(size * sizeof(int));

    if (s.data == NULL) {
        printf("Memory allocation failed!\n");
    }

    return s;
}

uint32_t stack_full(const Stack *stk) {
    return ((stk->top + 1) == stk->size);
}

uint32_t stack_empty(const Stack *stk) {
    return (stk->top == -1);
}

Stack *stack_push(Stack *stk, int value, StackResult *result) {
    
    if (stack_full(stk)) {
        uint32_t new_size = stk->size + 1;
        printf("Stack capacity increased, new size: %d\n", new_size);
        int *new_data = (int *)realloc(stk->data, new_size * sizeof(int));
        if (new_data == NULL) {
            result->status = STACK_ALLOC_FAIL;
            printf("Reallocation failed.\n");
            return stk;
        }
        stk->data = new_data;
        stk->size = new_size;
    }

    stk->data[++stk->top] = value;
    result->data = value;
    result->status = STACK_OK;
    return stk;
}

Stack *stack_pop(Stack *stk, StackResult *result) {
    if (stack_empty(stk)) {
        result->status = STACK_EMPTY;
        return stk;
    }

    printf("Popped: %d\n",stk->data[stk->top]);
    result->data = stk->data[stk->top--];
    result->status = STACK_OK;

    if (stk->size > 1 && stk->top + 1 <= stk->size - 1) {
        uint32_t new_size = stk->size - 1;
        if (new_size < 1)
            new_size = 1;

        int *data = (int *)realloc(stk->data, new_size * sizeof(int));
        if (data != NULL) {
            stk->data = data;
            stk->size = new_size;
            printf("Stack capacity shrunk to %u\n", new_size);
        }
    }

    return stk;
}

Stack *stack_peek(const Stack *stk, StackResult *result) {
    assert(stk != NULL);
    assert(result != NULL);

    if (stack_empty(stk)) {
        result->status = STACK_EMPTY;
    } else {
        result->data = stk->data[stk->top];
        result->status = STACK_OK;
    }
    return (Stack *)stk;
}

void display(const Stack *stk){
    if(stack_empty(stk)){
        printf("Stack empty");
    }else{
        for(int i=stk->top;i>=0;i--){
            printf("| %d |\n",stk->data[i]);
        }
    }
}

void stack_free(Stack *stk) {
    if (stk && stk->data) {
        free(stk->data);
        stk->data = NULL;
        stk->size = 0;
        stk->top = -1;
    }
}
