// Reverse first k elements of queue

#include <assert.h>
#include <stddef.h>
#include "queue.h"

Queue queue_new(uint32_t size){
    size = (size > 0 && size < MAX_QUEUE_LEN)?size:MAX_QUEUE_LEN;
    Queue q = {size, 0, 0, 0, {0}};
    return q;
}

Queue *queue_add(Queue *q, int32_t data, QueueResult *result){
    assert(q != NULL && q->count <= q->size);
    if(q->count < q->size){
        q->q[q->tail] = data;
        q->tail = (q->tail + 1) % q->size;
        ++q->count;
        result->status = QUEUE_OK;
    }else{
        result->status = QUEUE_FULL;
    }
    assert(result->status == QUEUE_OK || q->count == q->size);
    return q;
}

Queue *queue_remove(Queue *q, QueueResult *result){
    assert(q != NULL && q->count <= q->size);
    if(q->count > 0){
        result->data = q->q[q->head];
        q->head = (q->head + 1) % q->size;
        --q->count;
        result->status = QUEUE_OK;
    }else{
        result->status = QUEUE_EMPTY;
    }
    assert(result->status == QUEUE_OK || q->count == q->size);
    return q;
}

uint32_t queue_full(Queue *q) {
    assert(q != NULL);
    return (q->count == q->size);
}

uint32_t queue_empty(Queue *q) {
    assert(q != NULL);
    return (q->count == 0);
}


void reverse_first_k_elements(Queue *q, uint32_t k, QueueResult *result) {
    if (k > q->count || k == 0) {
        result->status = QUEUE_EMPTY;
        return;  
    }

    int32_t arr[k];
    uint32_t i;

    for (i = 0; i < k; i++) {
        queue_remove(q, result);
        arr[i] = result->data;
    }

    for (i = k; i > 0; i--) {
        queue_add(q, arr[i-1], result);
    }

    for (i = 0; i < q->count - k; i++) {
        queue_remove(q, result);
        queue_add(q, result->data, result);
    }

    result->status = QUEUE_OK;
}
