#ifndef _INCLUDED_QUEUE_K_REVERSE_
#define _INCLUDED_QUEUE_K_REVERSE_
#include <stdint.h>

typedef struct _queue_ {
    int32_t data[50];
    int32_t front, rear, size;
} Queue;

Queue queue_new();
Queue* queue_enqueue(Queue *q, int32_t val);
int32_t queue_dequeue(Queue *q);
void queue_reverse_k(Queue *q, int32_t k);

#endif


// #ifndef _INCLUDED_QUEUE_K_REVERSE_
// #define _INCLUDED_QUEUE_K_REVERSE_

// #include <stdint.h>

// #define MAX_QUEUE_SIZE 50

// typedef struct _queue_ {
//     int32_t data[MAX_QUEUE_SIZE];
//     int32_t front, rear, size;
// } Queue;

// Queue queue_new();
// Queue* queue_enqueue(Queue *q, int32_t val);
// int32_t queue_dequeue(Queue *q);
// void queue_reverse_k(Queue *q, int32_t k);
// void queue_display(Queue *q);

// #endif
