#include "heap.h"
#include <assert.h>
#include <stdio.h>
 
int main(void) {
    /* Test data */
    int32_t a[] = { 5, 3, 17, 10, 84, 19, 6, 22, 9 };
    uint32_t n = sizeof(a) / sizeof(a[0]);
 
    /* Build heap */
    Heap *h = heap_new(a, n);
    assert(h != NULL);
    assert(heap_size(h) == n);
 
    /* Test heap_extract_max repeatedly: should produce non-increasing sequence */
    int32_t prev = heap_extract_max(h);
    for (uint32_t i = 1; i < n; ++i) {
        int32_t cur = heap_extract_max(h);
        assert(prev >= cur); /* max-heap ensures non-increasing sequence */
        prev = cur;
    }
    assert(heap_size(h) == 0);
 
    /* Test inserts */
    int32_t b[] = { 2, 7, 1, 8, 2, 8, 1 };
    Heap *h2 = heap_new(NULL, 0);
    assert(h2 != NULL);
    for (uint32_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
        int rc = heap_insert(h2, b[i]);
        assert(rc == 0);
    }
    assert(heap_size(h2) == 7);
 
    /* Extract max check */
    prev = heap_extract_max(h2);
    while (heap_size(h2) > 0) {
        int32_t cur = heap_extract_max(h2);
        assert(prev >= cur);
        prev = cur;
    }
 
    /* Test heapsort */
    int32_t c[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8 };
    uint32_t m = sizeof(c)/sizeof(c[0]);
    Heap *h3 = heap_new(c, m);
    assert(h3 != NULL);
    heap_sort(h3);
    /* After sort: data[1..m] ascending */
    for (uint32_t i = 1; i + 1 <= m; ++i) {
        assert(h3->data[i] <= h3->data[i + 1]);
    }
 
    printf("All heap tests passed.\n");
 
    heap_delete(h);
    heap_delete(h2);
    heap_delete(h3);
    return 0;
}