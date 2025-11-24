#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(Array *arr,int low,int high){
	int pivot = arr->data[high];
	int i = low-1;
	for(int j = low; j < high; j++){
		if(arr->data[j]<pivot){
			i++;
			swap(&arr->data[i],&arr->data[j]);
		}
	}
	swap(&arr->data[i+1],&arr->data[high]);
	return i+1;
}

void sort(Array *arr,int low,int high){
	if(low<high){
		int pi = partition(arr,low,high);
		sort(arr,low,pi-1);
		sort(arr,pi+1,high);
	}
}

void display(Array arr){
	printf("\n");
	for(int i = 0; i < arr.size; i++){
		printf("%d ", arr.data[i]);
	}
}