#include "bubble.h"
#include <stdio.h>

void bubbleSort(Array *arr){
	for(int i = 0;i<arr->size;i++){
		for(int j=0;j<arr->size-i-1;j++){
			if(arr->data[j]>arr->data[j+1]){
				int temp = arr->data[j];
				arr->data[j]=arr->data[j+1];
				arr->data[j+1] = temp;
			}
		}
	}
}

void display(Array arr){
	for(int i = 0; i< arr.size; i++){
		printf("%d\n",arr.data[i]);
	}
}