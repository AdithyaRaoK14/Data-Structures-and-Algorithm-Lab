#include <stdio.h>
#include "insertion.h"

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

    insertionSort(arr, size);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
