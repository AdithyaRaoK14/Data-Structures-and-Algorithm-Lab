#include <stdio.h>
#include <assert.h>
#include "heap.h"

void test_heap_operations() {
    // Test data
    int32_t data[] = {10, 20, 15, 30, 40, 50};
    uint32_t len = sizeof(data) / sizeof(data[0]);

    // Create a new heap
    Heap heap = heap_new(data, len);

    // Test heap size
    assert(heap_size(&heap) == len);
    printf("Heap size: %u\n", heap_size(&heap));

    // Test get max
    assert(heap_get_max(&heap) == 50);
    printf("Max value: %d\n", heap_get_max(&heap));

    // Test extract max
    int32_t max = heap_extract_max(&heap);
    assert(max == 50);
    printf("Extracted max: %d\n", max);
    assert(heap_size(&heap) == len - 1);
    printf("Heap size after extract: %u\n", heap_size(&heap));

    // Test insert
    heap_insert(&heap, 60);
    assert(heap_size(&heap) == len);
    assert(heap_get_max(&heap) == 60);
    printf("Max after insert: %d\n", heap_get_max(&heap));

    // Test heap sort
    heap_sort(&heap);
    printf("Heap after sort: ");
    for (uint32_t i = 1; i <= heap_size(&heap); i++) {
        printf("%d ", heap.data[i]);
    }
    printf("\n");

    // Test heap delete
    heap_delete(&heap);
    assert(heap_size(&heap) == 0);
    printf("Heap size after delete: %u\n", heap_size(&heap));
}

int main() {
    test_heap_operations();
    printf("All tests passed!\n");
    return 0;
}
