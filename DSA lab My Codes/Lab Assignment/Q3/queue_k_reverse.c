#include <assert.h>
#include "queue_k_reverse.h"

// New queue
Queue queue_new() {
    Queue q = {{0}, 0, -1, 0};
    return q;
}

// Enqueue
Queue* queue_enqueue(Queue *q, int32_t val) {
    assert(q->size < 50);
    q->rear++;
    q->data[q->rear] = val;
    q->size++;
    return q;
}

// Dequeue
int32_t queue_dequeue(Queue *q) {
    assert(q->size > 0);
    int32_t val = q->data[q->front];
    q->front++;
    q->size--;
    return val;
}

// Reverse first k elements
void queue_reverse_k(Queue *q, int32_t k) {
    assert(k <= q->size);
    int temp[50];
    for (int i = 0; i < k; i++) {
        temp[i] = queue_dequeue(q);
    }
    // put reversed back
    for (int i = k - 1; i >= 0; i--) {
        queue_enqueue(q, temp[i]);
    }
    // move remaining elements
    int rem = q->size - k;
    for (int i = 0; i < rem; i++) {
        int val = queue_dequeue(q);
        queue_enqueue(q, val);
    }
}


// #include <assert.h>
// #include <stdio.h>
// #include "queue_k_reverse.h"

// // Create a new queue (empty)
// Queue queue_new() {
//     Queue q = {{0}, 0, -1, 0};  // Initialize front to 0, rear to -1, size to 0
//     return q;
// }

// // Enqueue: Add an element to the rear of the queue
// Queue* queue_enqueue(Queue *q, int32_t val) {
//     assert(q->size < MAX_QUEUE_SIZE);  // Ensure there is space in the queue
//     q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;  // Circular increment of rear
//     q->data[q->rear] = val;
//     q->size++;
//     return q;
// }

// // Dequeue: Remove and return the element from the front of the queue
// int32_t queue_dequeue(Queue *q) {
//     assert(q->size > 0);  // Ensure there are elements to dequeue
//     int32_t val = q->data[q->front];
//     q->front = (q->front + 1) % MAX_QUEUE_SIZE;  // Circular increment of front
//     q->size--;
//     return val;
// }

// // Reverse the first k elements in the queue using only enqueue and dequeue
// void queue_reverse_k(Queue *q, int32_t k) {
//     assert(k <= q->size);  // Ensure k is valid (not greater than queue size)

//     // Step 1: Dequeue first k elements
//     for (int i = 0; i < k; i++) {
//         int val = queue_dequeue(q);  // Dequeue the front element
//         queue_enqueue(q, val);       // Enqueue it back (this is just temporarily moving it to rear)
//     }

//     // Step 2: Reverse the first k elements by rotating them to the front again
//     for (int i = 0; i < k - 1; i++) {
//         // Dequeue the front element (this is the last inserted element)
//         int val = queue_dequeue(q); 
//         // Enqueue it again to the rear of the queue
//         queue_enqueue(q, val); 
//     }

//     // Step 3: The remaining elements (if any) should stay in order
//     int rem = q->size - k;
//     for (int i = 0; i < rem; i++) {
//         int val = queue_dequeue(q);  // Dequeue the next element
//         queue_enqueue(q, val);  // Enqueue it back to the rear (same order)
//     }
// }

// // Display the current state of the queue
// void queue_display(Queue *q) {
//     if (q->size == 0) {
//         printf("Queue is empty.\n");
//         return;
//     }

//     printf("Queue (front -> rear): ");
//     for (int i = 0; i < q->size; i++) {
//         int index = (q->front + i) % MAX_QUEUE_SIZE;
//         printf("%d ", q->data[index]);
//     }
//     printf("\n");
// }
