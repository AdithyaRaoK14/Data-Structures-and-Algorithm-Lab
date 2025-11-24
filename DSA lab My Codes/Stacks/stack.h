#ifndef _INCLUDED_STACK_H_
#define _INCLUDED_STACK_H_
#include <stdint.h>

#define MAX_DEPTH 32

// Define the stack structure
struct stack_ {
    uint32_t size;
    int32_t top;
    float data[MAX_DEPTH];
};
typedef struct stack_ Stack;

// Define result status codes
#define RESULT_INVALID 0
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 4

// Define the result structure for stack operations
struct _stack_result {
    float data;
    uint32_t status;
};
typedef struct _stack_result StackResult;

// Function prototypes
Stack stack_new(uint32_t size);
uint32_t stack_full(const Stack *stk);
uint32_t stack_empty(const Stack *stk);
const Stack *stack_push(Stack *stk, float data, StackResult *result);
const Stack *stack_pop(Stack *stk, StackResult *result);
const Stack *stack_peek(const Stack *stk, StackResult *result);

#endif // _INCLUDED_STACK_H_
