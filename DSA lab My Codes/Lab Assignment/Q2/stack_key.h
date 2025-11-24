// #ifndef _INCLUDED_STACK_KEY_
// #define _INCLUDED_STACK_KEY_
// #include <stdint.h>

// int stack_display_key(int stack[], int top, int key);

// #endif



#ifndef _INCLUDED_STACK_KEY_
#define _INCLUDED_STACK_KEY_
#include <stdint.h>

#define MAX_STACK_SIZE 100

int push(int stack[], int* top, int value);
int pop(int stack[], int* top);
int stack_display_key(int stack[], int* top, int key);

#endif
