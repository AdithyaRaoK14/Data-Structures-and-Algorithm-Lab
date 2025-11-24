#include "bubble.h"
#include <stdio.h>

int main(){
	Array arr;
	printf("Enter the number of elements: ");
	scanf("%d",&arr.size);
	printf("Enter the array elements: ");
	for(int i = 0; i < arr.size; i++){
		scanf("%d",&arr.data[i]);
	}
	printf("Original array: ");
	display(arr);
	bubbleSort(&arr);
	printf("\nSorted array: ");
	display(arr);
}