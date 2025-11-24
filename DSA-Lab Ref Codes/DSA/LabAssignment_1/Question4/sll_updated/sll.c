#include "sll.h"

Stack *create_stack(){
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	stack->length = 0;
	return stack;
}

void push_stack(Stack *stack, int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
	stack->length++;
}

int pop_stack(Stack *stack){
	Node *node = stack->top;
	int popped = node->data;
	stack->top = node->next;
	free(node);
	stack->length--;
	return popped;
}

int peek_stack(Stack *stack){
	return stack->top->data;
}

int is_empty(Stack *stack){
	return stack->length == 0;
}

void free_stack(Stack* stack) {
    Node* current = stack->top;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

minmaxStack *create_minmax_stack(){
	minmaxStack *s = (minmaxStack*)malloc(sizeof(minmaxStack));
	s->mainStack = create_stack();
	s->minStack = create_stack();
	s->maxStack = create_stack();
	return s;
}

void push(minmaxStack *s, int data){
    push_stack(s->mainStack, data);

    if (is_empty(s->minStack)) {
        push_stack(s->minStack, data);
    } else {
        int min_peek = peek_stack(s->minStack);
        push_stack(s->minStack, (data < min_peek) ? data : min_peek);
    }

    if (is_empty(s->maxStack)) {
        push_stack(s->maxStack, data);
    } else {
        int max_peek = peek_stack(s->maxStack);
        push_stack(s->maxStack, (data > max_peek) ? data : max_peek);
    }
}


void pop(minmaxStack* s) {
    if (is_empty(s->mainStack)) {
        printf("Stack underflow. Nothing to pop.\n");
        return;
    }
    pop_stack(s->mainStack);
    pop_stack(s->minStack);
    pop_stack(s->maxStack);
}

int get_min(minmaxStack *s){
	return peek_stack(s->minStack);
}

int get_max(minmaxStack *s){
	return peek_stack(s->maxStack);
}

void display(minmaxStack* s) {
    printf("\nStack (top at top):\n");

    if (is_empty(s->mainStack)) {
        printf("  [empty stack]\n");
        return;
    }

    Node* current = s->mainStack->top;
    while (current != NULL) {
        printf(" -----\n");
        printf("| %3d |\n", current->data);
        current = current->next;
    }
    printf(" -----\n\n");
}

void free_minmax_stack(minmaxStack* s) {
    free_stack(s->mainStack);
    free_stack(s->minStack);
    free_stack(s->maxStack);
    free(s);
}