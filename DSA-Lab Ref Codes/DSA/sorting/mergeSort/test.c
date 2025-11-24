#include "sort.h"
#include <stdio.h>

int main() {
    Array arr;
    arr.size = 6;
    arr.data[0] = 38;
    arr.data[1] = 27;
    arr.data[2] = 43;
    arr.data[3] = 3;
    arr.data[4] = 9;
    arr.data[5] = 82;

    printf("Original array: ");
    display(arr);

    mergeSort(&arr, 0, arr.size - 1);

    printf("\nSorted array: ");
    display(arr);

    return 0;
}
