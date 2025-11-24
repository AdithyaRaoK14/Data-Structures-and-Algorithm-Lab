#ifndef _INCLUDED_QUEUE_
#define _INCLUDED_QUEUE_
#include <stdint.h>

#define MAX_QUEUE_LEN 32

// Define the queue structure
struct _queue_ {
    uint32_t size;
    uint32_t count;
    uint32_t head;
    uint32_t tail;
    int32_t q[MAX_QUEUE_LEN];  // Queue data
};

typedef struct _queue_ Queue;

// Define the result structure for queue operations
struct _queue_result_ {
    int32_t data;
    uint32_t status;
};

typedef struct _queue_result_ QueueResult;

// Define the status codes for queue operations
#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 4

// Function prototypes for queue operations
Queue queue_new(uint32_t size);
Queue *queue_add(Queue *q, int32_t data, QueueResult *result);
Queue *queue_remove(Queue *q, QueueResult *result);
uint32_t queue_full(Queue *q);
uint32_t queue_empty(Queue *q);

#endif
