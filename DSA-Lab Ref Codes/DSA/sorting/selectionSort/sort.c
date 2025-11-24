#include "sort.h"
#include <stdio.h>

void sort(Array *arr){
	for(int i = 0;i<arr->size-1; i++){
		int min = i;
		for(int j = i+1; j < arr->size; j++){
			if(arr->data[j]<arr->data[min]){
				min = j;
			}
		}
		if(min != i){
			int temp = arr->data[i];
			arr->data[i] = arr->data[min];
			arr->data[min] = temp;
		}	
	}
}

void display(Array arr){
	printf("\n");
	for(int i=0;i<arr.size;i++){
		printf("%d ", arr.data[i]);
	}
}