#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

// Function to swap two elements
void swap(int *a, int *b);

// Function to find the index of the minimum element in the unsorted part
int findMinIndex(int arr[], int start, int size);

// Function to perform selection sort
void selectionSort(int arr[], int size);

// Function to print the array
void printArray(int arr[], int size);

#endif
