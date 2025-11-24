#include "sort.h"
#include <stdio.h>

int main(){
	int temp[] = {24,12,3,5,17,1};
	Array arr;
	arr.size = sizeof(temp)/sizeof(temp[0]);
	for(int i = 0; i < arr.size; i++){
		arr.data[i] = temp[i];
	}

	display(arr);
	sort(&arr,0,arr.size-1);
	display(arr);
}