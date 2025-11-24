#ifndef SLL_H
#define SLL_H
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	Node* top;
	int length;
}Stack;

typedef struct minmaxStack{
	Stack *mainStack;
	Stack *minStack;
	Stack *maxStack;
}minmaxStack;

Stack* create_stack();
void push_stack(Stack* stack, int data);
int pop_stack(Stack* stack);
int peek_stack(Stack* stack);
int is_empty(Stack* stack);
void free_stack(Stack* stack);

// MinMaxStack API
minmaxStack* create_minmax_stack();
void push(minmaxStack* s, int data);
void pop(minmaxStack* s);
int get_min(minmaxStack* s);
int get_max(minmaxStack* s);
void display(minmaxStack* s);
void free_minmax_stack(minmaxStack* s);

#endif