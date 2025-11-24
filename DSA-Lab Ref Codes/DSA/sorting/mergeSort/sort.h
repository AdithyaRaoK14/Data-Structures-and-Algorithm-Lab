#ifndef SORT
#define SORT

typedef struct{
	int data[10];
	int size;
}Array;

void merge(Array *arr, int left, int mid, int right);
void mergeSort(Array *arr, int left, int right);
void display(Array arr);
#endif