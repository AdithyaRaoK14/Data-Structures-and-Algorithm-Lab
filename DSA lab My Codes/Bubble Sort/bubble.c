#include <stdio.h>
#include "bubble.h"

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Flag to detect if any swapping happens
        int swapped = 0;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        // If no two elements were swapped, the array is sorted
        if (!swapped) break;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
