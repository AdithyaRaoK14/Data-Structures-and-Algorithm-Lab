#include <assert.h>
#include <stdio.h>
#include "queue.h"

void test_queue_capacity_one() {
    Queue q = queue_new(1);
    QueueResult result;

    assert(queue_empty(&q));
    assert(!queue_full(&q));

    queue_remove(&q, &result);
    assert(result.status == QUEUE_EMPTY);

    queue_add(&q, 10, &result);
    assert(result.status == QUEUE_OK);
    assert(!queue_empty(&q));
    assert(queue_full(&q));

    queue_add(&q, 20, &result);
    assert(result.status == QUEUE_FULL);

    queue_remove(&q, &result);
    assert(result.data == 10 && result.status == QUEUE_OK);
    assert(queue_empty(&q));
}

void test_queue_capacity_arbitrary() {
    Queue q = queue_new(MAX_QUEUE_LEN);
    QueueResult result;
    int i;

    for (i = 0; i < MAX_QUEUE_LEN; i++) {
        queue_add(&q, i, &result);
        assert(result.status == QUEUE_OK);
    }

    assert(queue_full(&q));

    queue_add(&q, 100, &result);
    assert(result.status == QUEUE_FULL);

    for (i = 0; i < MAX_QUEUE_LEN; i++) {
        queue_remove(&q, &result);
        assert(result.data == i && result.status == QUEUE_OK);
    }

    assert(queue_empty(&q));

    queue_remove(&q, &result);
    assert(result.status == QUEUE_EMPTY);
}

void test_queue_partial() {
    Queue q = queue_new(5);
    QueueResult result;

    queue_add(&q, 1, &result);
    queue_add(&q, 2, &result);
    queue_add(&q, 3, &result);
    assert(result.status == QUEUE_OK);

    queue_remove(&q, &result);
    assert(result.data == 1 && result.status == QUEUE_OK);
    queue_remove(&q, &result);
    assert(result.data == 2 && result.status == QUEUE_OK);

    queue_add(&q, 4, &result);
    queue_add(&q, 5, &result);
    assert(result.status == QUEUE_OK);

    queue_remove(&q, &result);
    assert(result.data == 3 && result.status == QUEUE_OK);
    queue_remove(&q, &result);
    assert(result.data == 4 && result.status == QUEUE_OK);
    queue_remove(&q, &result);
    assert(result.data == 5 && result.status == QUEUE_OK);

    assert(queue_empty(&q));
}

int main() {
    printf("Starting queue tests...\n");

    test_queue_capacity_one();
    printf("Test 1: Queue with capacity 1 passed!\n");

    test_queue_capacity_arbitrary();
    printf("Test 2: Queue with arbitrary capacity passed!\n");

    test_queue_partial();
    printf("Test 3: Partial queue operations passed!\n");

    printf("All tests passed!\n");

    return 0;
}
