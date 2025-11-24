#ifndef INCLUDED_HEAP_H
#define INCLUDED_HEAP_H
 
#include <stdint.h>
#include <stddef.h>
 
#define MAX_HEAP_SIZE 1024
 
typedef struct Heap {
    uint32_t size;               /* number of elements currently in heap */
    int32_t data[MAX_HEAP_SIZE + 1]; /* 1-based indexing: data[1] is root */
} Heap;
 
/* Create a heap from an existing array (len must be <= MAX_HEAP_SIZE).
   The input array is ordinary 0-based; values are copied. Returns pointer or NULL on error. */
Heap *heap_new(const int32_t data[], uint32_t len);
 
/* Free a heap created by heap_new */
void heap_delete(Heap *h);
 
/* Insert a key into heap. Returns 0 on success, -1 on overflow. */
int heap_insert(Heap *h, int32_t key);
 
/* Extract the maximum element. Behavior undefined if heap is empty. */
int32_t heap_extract_max(Heap *h);
 
/* Current number of elements in heap */
uint32_t heap_size(const Heap *h);
 
/* In-place heapsort using the heap's internal buffer.
   After call, h->data[1..orig_size] contains ascending-sorted values (1-based). */
void heap_sort(Heap *h);
 
#endif /* INCLUDED_HEAP_H */