#include <assert.h>
#include <stdio.h>
#include "queue.h"

void test_reverse_first_k_elements() {
    Queue q = queue_new(5);
    QueueResult result;

    // Adding some data to the queue
    queue_add(&q, 10, &result);
    queue_add(&q, 20, &result);
    queue_add(&q, 30, &result);
    queue_add(&q, 40, &result);
    queue_add(&q, 50, &result);

    printf("Queue before reversing first 3 elements:\n");
    for (int i = 0; i < 5; i++) {
        queue_remove(&q, &result);
        printf("%d ", result.data);
    }
    printf("\n");

    // Re-enqueue to restore queue to initial state
    queue_add(&q, 10, &result);
    queue_add(&q, 20, &result);
    queue_add(&q, 30, &result);
    queue_add(&q, 40, &result);
    queue_add(&q, 50, &result);

    // Reverse first 3 elements
    reverse_first_k_elements(&q, 4, &result);

    printf("Queue after reversing first 3 elements:\n");
    for (int i = 0; i < 5; i++) {
        queue_remove(&q, &result);
        printf("%d ", result.data);
    }
    printf("\n");
}

int main() {
    printf("Testing reversing first k elements...\n");
    test_reverse_first_k_elements();
    return 0;
}
