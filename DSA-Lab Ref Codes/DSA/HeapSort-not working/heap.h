#ifndef _HEAP_
#define _HEAP_
#include <stdint.h>
#define MAX_HEAP_SIZE 16

typedef struct _heap_ Heap;

struct _heap_ {
    uint32_t size;
    int32_t data[MAX_HEAP_SIZE + 1];  // Adjust for 1-based index
};

Heap heap_new(int32_t data[], uint32_t len);
void heap_delete(Heap *heap);
Heap *heap_sort(Heap *heap);
Heap *heap_insert(Heap *heap, int32_t key);
int32_t heap_get_max(Heap *heap);
int32_t heap_extract_max(Heap *heap);
uint32_t heap_size(Heap *heap);

#endif
