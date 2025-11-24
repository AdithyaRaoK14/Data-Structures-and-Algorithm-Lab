#include <assert.h>
#include "stack.h"

// Test case for a stack with capacity 1
void test_capacity_one_stack() {
    Stack stk_instance = stack_new(1);
    Stack *stk = &stk_instance;
    StackResult result;

    // Ensure stack is empty initially
    assert(stack_empty(stk));
    assert(!stack_full(stk));

    // Peek the stack when it's empty
    stack_peek(stk, &result);
    assert(result.status == STACK_EMPTY);

    // Pop from the stack when it's empty
    stack_pop(stk, &result);
    assert(result.status == STACK_EMPTY);

    // Push a value and check the stack's status
    stack_push(stk, 99, &result);
    assert(result.status == STACK_OK);
    assert(stack_full(stk));

    // Try to push another value into a full stack
    stack_push(stk, 111, &result);
    assert(result.status == STACK_FULL);

    // Peek the top value
    stack_peek(stk, &result);
    assert(result.data == 99 && result.status == STACK_OK);

    // Pop the top value
    stack_pop(stk, &result);
    assert(result.data == 99 && result.status == STACK_OK);
    assert(stack_empty(stk));  // The stack should be empty now
}

// Test case for an arbitrary size stack (max depth)
void test_arbitrary_stack() {
    Stack stk_instance = stack_new(MAX_DEPTH);
    Stack *stk = &stk_instance;
    StackResult result = {0, RESULT_INVALID};

    // Push elements to fill the stack
    for (int i = 0; i < MAX_DEPTH; i++) {
        stack_push(stk, (float)i, &result);
        assert(result.status == STACK_OK);
        result.status = RESULT_INVALID;
    }

    // Try to push beyond max depth
    stack_push(stk, (float)MAX_DEPTH, &result);
    assert(result.status == STACK_FULL);

    // Peek and validate the elements in LIFO order
    for (int i = 0; i < MAX_DEPTH; i++) {
        result.status = RESULT_INVALID;  // Reset status for each iteration
        stack_peek(stk, &result);
        assert(result.status == STACK_OK);  // Peek should succeed
        assert(result.data == MAX_DEPTH - i - 1);  // LIFO order should be maintained
        stack_pop(stk, &result);  // Pop to move down to the next element
    }

    // Ensure the stack is empty at the end
    assert(stack_empty(stk));
}

int main() {
    test_capacity_one_stack();   // Test stack with capacity 1
    test_arbitrary_stack();      // Test stack with arbitrary size (max depth)
    return 0;
}
