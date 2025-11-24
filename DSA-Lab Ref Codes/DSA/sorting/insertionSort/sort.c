#include "sort.h"
#include <stdio.h>

void sort(Array *arr){
	for(int i=1;i<arr->size;i++){
		int key = arr->data[i];
		int j = i-1;
		while(j>=0 && arr->data[j]>key){
			arr->data[j+1] = arr->data[j];
			j--;
		}
		arr->data[j+1]=key;
	}
}

void display(Array arr){
	printf("\n");
	for(int i =0 ; i < arr.size;i++){
		printf("%d ",arr.data[i]);
	}
}