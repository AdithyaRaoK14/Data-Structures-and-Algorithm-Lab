#ifndef SORT
#define SORT

typedef struct{
	int data[10];
	int size;
}Array;

void sort(Array *arr);
void display(Array arr);
#endif