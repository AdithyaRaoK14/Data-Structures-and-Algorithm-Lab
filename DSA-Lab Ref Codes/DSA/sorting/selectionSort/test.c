#include "sort.h"
#include <stdio.h>

int main(){
	Array arr;
	int temp[] = {24,12,2,4,1};
	arr.size = sizeof(temp)/sizeof(temp[0]);
	for(int i=0;i<arr.size;i++){
		arr.data[i] = temp[i];
	}
	display(arr);
	sort(&arr);
	display(arr);
	return 0;
}