#include <assert.h>
#include <stddef.h>
#include "queue.h"

// Create a new queue with a specified size
Queue queue_new(uint32_t size) {
    size = (size > 0 && size < MAX_QUEUE_LEN) ? size : MAX_QUEUE_LEN;
    Queue q = {size, 0, 0, 0, {0}};
    return q;
}

// Add an element to the queue
Queue *queue_add(Queue *q, int32_t data, QueueResult *result) {
    assert(q != NULL);
    
    if (q->count < q->size) {
        q->q[q->tail] = data;
        q->tail = (q->tail + 1) % q->size;  // Circular increment
        ++q->count;
        result->status = QUEUE_OK;
    } else {
        result->status = QUEUE_FULL;
    }

    return q;
}

// Remove an element from the queue
Queue *queue_remove(Queue *q, QueueResult *result) {
    assert(q != NULL);

    if (q->count > 0) {
        result->data = q->q[q->head];
        q->head = (q->head + 1) % q->size;  // Circular increment
        --q->count;
        result->status = QUEUE_OK;
    } else {
        result->status = QUEUE_EMPTY;
    }

    return q;
}

// Check if the queue is full
uint32_t queue_full(Queue *q) {
    assert(q != NULL);
    return q->count == q->size;
}

// Check if the queue is empty
uint32_t queue_empty(Queue *q) {
    assert(q != NULL);
    return q->count == 0;
}
