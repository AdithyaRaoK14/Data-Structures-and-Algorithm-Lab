#include <stddef.h>
#include <string.h>
#include "heap.h"

static void _swap_(int32_t *a, int32_t *b) {
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

static void _heapify(int32_t data[], uint32_t len, uint32_t i) {
    uint32_t largest = i;
    uint32_t left = 2 * i;
    uint32_t right = 2 * i + 1;

    if (left <= len && data[left] > data[largest]) {
        largest = left;
    }
    if (right <= len && data[right] > data[largest]) {
        largest = right;
    }
    if (largest != i) {
        _swap_(&data[i], &data[largest]);
        _heapify(data, len, largest);
    }
}

Heap heap_new(int32_t data[], uint32_t len) {
    Heap heap = {0};
    // Copy data into heap
    memcpy(heap.data + 1, data, len * sizeof(int32_t));

    // Build heap
    for (int i = len / 2; i > 0; --i) {
        _heapify(heap.data, len, i);
    }

    heap.size = len;
    return heap;
}

uint32_t heap_size(Heap *heap) {
    return heap->size;
}

Heap *heap_sort(Heap *heap) {
    for (uint32_t i = heap->size; i > 1; --i) {
        _swap_(&heap->data[1], &heap->data[i]);
        _heapify(heap->data, i - 1, 1);
    }
    return heap;
}

int32_t heap_get_max(Heap *heap) {
    return heap->size > 0 ? heap->data[1] : -1;
}

int32_t heap_extract_max(Heap *heap) {
    if (heap->size == 0) return -1;

    int32_t max = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    --heap->size;
    _heapify(heap->data, heap->size, 1);
    return max;
}

Heap *heap_insert(Heap *heap, int32_t key) {
    if (heap->size == MAX_HEAP_SIZE) return NULL;

    ++heap->size;
    uint32_t i = heap->size;
    while (i > 1 && heap->data[i / 2] < key) {
        heap->data[i] = heap->data[i / 2];
        i /= 2;
    }
    heap->data[i] = key;
    return heap;
}

void heap_delete(Heap *heap) {
    heap->size = 0;
    memset(heap->data, 0, sizeof(heap->data));
}
