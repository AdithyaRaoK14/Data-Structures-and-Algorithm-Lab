#include "sort.h"
#include <stdio.h>

void merge(Array *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) L[i] = arr->data[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr->data[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        arr->data[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while(i < n1) arr->data[k++] = L[i++];
    while(j < n2) arr->data[k++] = R[j++];
}

void mergeSort(Array *arr, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void display(Array arr) {
    for(int i = 0; i < arr.size; i++)
        printf("%d ", arr.data[i]);
    printf("\n");
}
