#ifndef SORT
#define SORT

typedef struct{
	int data[10];
	int size;
}Array;

int partition(Array *arr, int low, int high);
void sort(Array *arr, int low, int high);
void display(Array arr);
#endif