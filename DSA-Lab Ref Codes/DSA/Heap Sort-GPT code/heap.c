#include "heap.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
static void swap(int32_t *a, int32_t *b) {
    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}
 
/* Sift-down (heapify) on 1-based index 'parent' for length 'len' */
static void sift_down(int32_t data[], uint32_t len, uint32_t parent) {
    assert(parent >= 1 && parent <= len);
    uint32_t child = parent * 2;
    while (child <= len) {
        if (child + 1 <= len && data[child + 1] > data[child]) {
            ++child;
        }
        if (data[parent] >= data[child]) break;
        swap(&data[parent], &data[child]);
        parent = child;
        child = parent * 2;
    }
}
 
/* Sift-up for index i (1-based) */
static void sift_up(int32_t data[], uint32_t i) {
    while (i > 1) {
        uint32_t parent = i / 2;
        if (data[parent] >= data[i]) break;
        swap(&data[parent], &data[i]);
        i = parent;
    }
}
 
Heap *heap_new(const int32_t data[], uint32_t len) {
    if (len > MAX_HEAP_SIZE) return NULL;
    Heap *h = (Heap *)malloc(sizeof(Heap));
    if (!h) return NULL;
    h->size = len;
    /* Copy input into 1-based storage */
    for (uint32_t i = 0; i < len; ++i) {
        h->data[i + 1] = data[i];
    }
    /* Build heap: sift-down from len/2 down to 1 */
    if (len > 0) {
        for (int32_t i = (int32_t)len / 2; i >= 1; --i) {
            sift_down(h->data, h->size, (uint32_t)i);
        }
    }
    return h;
}
 
void heap_delete(Heap *h) {
    if (!h) return;
    /* zero out sensitive data (optional) */
    memset(h->data, 0, sizeof(h->data));
    free(h);
}
 
int heap_insert(Heap *h, int32_t key) {
    if (!h) return -1;
    if (h->size >= MAX_HEAP_SIZE) return -1;
    ++h->size;
    h->data[h->size] = key;
    sift_up(h->data, h->size);
    return 0;
}
 
int32_t heap_extract_max(Heap *h) {
    assert(h != NULL);
    assert(h->size > 0);
    int32_t max = h->data[1];
    h->data[1] = h->data[h->size];
    --h->size;
    if (h->size >= 1) sift_down(h->data, h->size, 1);
    return max;
}
 
uint32_t heap_size(const Heap *h) {
    if (!h) return 0;
    return h->size;
}
 
void heap_sort(Heap *h) {
    assert(h != NULL);
    uint32_t orig_size = h->size;
    /* Build max-heap in case it's not already a heap */
    if (orig_size > 0) {
        for (int32_t i = (int32_t)orig_size / 2; i >= 1; --i) {
            sift_down(h->data, orig_size, (uint32_t)i);
        }
    }
    /* Heapsort: repeatedly swap root with last, reduce len, sift_down root */
    uint32_t len = orig_size;
    while (len > 1) {
        swap(&h->data[1], &h->data[len]);
        --len;
        if (len >= 1) sift_down(h->data, len, 1);
    }
    /* After this, data[1..orig_size] is ascending (lowest at data[1], highest at data[orig_size]) */
    /* restore size (already orig_size) */
    h->size = orig_size;
}