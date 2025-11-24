#include <stdio.h>
#include "selection.h"

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
