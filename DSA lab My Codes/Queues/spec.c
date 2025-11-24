#include <stdio.h>
#include "queue.h"

int main() {
    Queue q = queue_new(5);  // Create a queue of size 5
    QueueResult result;

    // Add elements to the queue
    queue_add(&q, 10, &result);
    queue_add(&q, 20, &result);
    queue_add(&q, 30, &result);
    queue_add(&q, 40, &result);
    queue_add(&q, 50, &result);

    // Try adding more elements (will fail if full)
    queue_add(&q, 60, &result);  // Should return QUEUE_FULL

    // Remove elements from the queue
    queue_remove(&q, &result);
    printf("Removed: %d\n", result.data);
    
    queue_remove(&q, &result);
    printf("Removed: %d\n", result.data);

    // Add more elements
    queue_add(&q, 60, &result);
    queue_add(&q, 70, &result);

    // Remove all elements
    while (!queue_empty(&q)) {
        queue_remove(&q, &result);
        printf("Removed: %d\n", result.data);
    }

    return 0;
}
