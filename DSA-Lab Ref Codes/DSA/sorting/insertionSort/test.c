#include "sort.h"

int main(){
	Array arr;
	int temp[] = {24,25,3,1,5};
	arr.size = sizeof(temp)/sizeof(temp[0]);
	for(int i=0;i<arr.size;i++){
		arr.data[i] = temp[i];
	}
	display(arr);
	sort(&arr);
	display(arr);
}