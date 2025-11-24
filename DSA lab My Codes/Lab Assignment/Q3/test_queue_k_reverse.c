#include <assert.h>
#include "queue_k_reverse.h"

void test_queue_k_reverse() {
    Queue q = queue_new();
    queue_enqueue(&q, 10);
    queue_enqueue(&q, 20);
    queue_enqueue(&q, 30);
    queue_enqueue(&q, 40);
    queue_enqueue(&q, 50);

    queue_reverse_k(&q, 3); // Expected: 30,20,10,40,50

    assert(q.data[q.front] == 30);
}

int main() {
    test_queue_k_reverse();
    return 0;
}


// #include <assert.h>
// #include <stdio.h>
// #include "queue_k_reverse.h"

// // Test the queue reverse function
// void test_queue_k_reverse() {
//     Queue q = queue_new();

//     // Enqueue some elements
//     queue_enqueue(&q, 10);
//     queue_enqueue(&q, 20);
//     queue_enqueue(&q, 30);
//     queue_enqueue(&q, 40);
//     queue_enqueue(&q, 50);

//     // Display the queue before reversing
//     printf("Before reversing:\n");
//     queue_display(&q);  // Expected: 10 20 30 40 50

//     // Reverse the first 3 elements
//     queue_reverse_k(&q, 3);  // Expected: 30, 20, 10, 40, 50

//     // Display the queue after reversing
//     printf("After reversing first 3 elements:\n");
//     queue_display(&q);  // Expected: 30 20 10 40 50

//     // Check the front element of the queue
//     assert(q.data[q.front] == 30);  // First element should be 30
//     assert(q.data[(q.front + 1) % MAX_QUEUE_SIZE] == 20);  // Second element should be 20
//     assert(q.data[(q.front + 2) % MAX_QUEUE_SIZE] == 10);  // Third element should be 10
//     assert(q.data[(q.front + 3) % MAX_QUEUE_SIZE] == 40);  // Fourth element should be 40
//     assert(q.data[(q.front + 4) % MAX_QUEUE_SIZE] == 50);  // Fifth element should be 50
// }

// int main() {
//     test_queue_k_reverse();  // Run the test
//     return 0;
// }
