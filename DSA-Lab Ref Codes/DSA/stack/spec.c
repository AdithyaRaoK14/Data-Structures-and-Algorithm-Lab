#include <assert.h>
#include "stack.h"

void test_capacity_one_stack() {
    Stack stk_instance = stack_new(1);
    Stack *stk = &stk_instance;
    StackResult result;
    
    assert(stack_empty(stk));
    assert(!stack_full(stk));

    stack_peek(stk, &result);
    assert(result.status == STACK_EMPTY);
    
    stack_pop(stk, &result);
    assert(result.status == STACK_EMPTY);
    
    stack_push(stk, 99, &result);
    assert(result.status == STACK_OK);
    
    assert(stack_full(stk));
    
    stack_push(stk, 111, &result);
    assert(result.status == STACK_FULL);
    
    stack_peek(stk, &result);
    assert(result.data == 99 && result.status == STACK_OK);
    
    stack_pop(stk, &result);
    assert(result.data == 99 && result.status == STACK_OK);
    
    assert(stack_empty(stk));
}

void test_arbitrary_stack() {
    Stack stk_instance = stack_new(MAX_DEPTH);
    Stack *stk = &stk_instance;
    StackResult result = {0, RESULT_INVALID};
    int i;
    
    for (i = 0; i < MAX_DEPTH; i++) {
        stack_push(stk, i, &result);
        assert(result.status == STACK_OK);
        result.status = RESULT_INVALID;
    }
    
    stack_push(stk, i, &result);
    assert(result.status == STACK_FULL);
    
    for (i = MAX_DEPTH - 1; i >= 0; i--) {
        stack_pop(stk, &result);
        assert(result.data == i && result.status == STACK_OK);
    }
    
    assert(stack_empty(stk));
}

int main() {
    test_capacity_one_stack();
    test_arbitrary_stack();
    return 0;
}
