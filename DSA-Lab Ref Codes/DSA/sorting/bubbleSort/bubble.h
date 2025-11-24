#ifndef BUBBLE
#define BUBBLE

typedef struct{
	int data[100];
	int size;
}Array;

void bubbleSort(Array *arr);
void display(Array arr);
#endif