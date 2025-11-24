#ifndef STACK_H
#define STACK_H
#include <stdint.h>

#define MAX_DEPTH 3  

typedef struct {
    uint32_t size;   
    int32_t top;     
    int *data;       
} Stack;

typedef struct {
    int data;
    uint32_t status;
} StackResult;

#define RESULT_INVALID 0
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 4
#define STACK_ALLOC_FAIL 8

Stack stack_new(uint32_t size);
uint32_t stack_full(const Stack *stk);
uint32_t stack_empty(const Stack *stk);
Stack *stack_push(Stack *stk, int data, StackResult *result);
Stack *stack_pop(Stack *stk, StackResult *result);
Stack *stack_peek(const Stack *stk, StackResult *result);
void display(const Stack *stk);
void stack_free(Stack *stk);

#endif
