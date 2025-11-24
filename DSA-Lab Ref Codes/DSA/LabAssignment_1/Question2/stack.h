#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#define STACK_SIZE 6


typedef struct {
    int32_t data[STACK_SIZE];
    int top;
} Stack;

Stack* stack_init();
void stack_push(Stack* stack, int32_t value);
int32_t stack_pop(Stack* stack);
int stack_is_empty(const Stack* stack);
int stack_is_full(const Stack* stack);
int display_key(Stack* stack, int32_t key);
void display_stack(const Stack* stack);

#endif 
