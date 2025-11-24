#include <stdio.h>
#include "selection.h"

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the index of the minimum element in the unsorted portion of the array
int findMinIndex(int arr[], int start, int size) {
    int minIndex = start;
    for (int i = start + 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to perform the selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the index of the minimum element in the remaining unsorted part
        int minIndex = findMinIndex(arr, i, size);
        
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
