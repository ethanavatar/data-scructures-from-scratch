#ifndef DYNAMICSTACK_H_INCLUDED
#define DYNAMICSTACK_H_INCLUDED

#include <stdlib.h>
#include "stack.h"

static t_stack* stack_resize(t_stack* stack, const int new_capacity) {
    stack->capacity = new_capacity;
    stack->data = (int*) realloc(stack->data, new_capacity * sizeof(int));
    
    return stack;
}

static t_stack* stack_push_dynamic(t_stack* stack, const int value) {
    if (stack->top == stack->capacity) {
        stack_resize(stack, stack->capacity * 2);
    }
    stack->data[stack->top++] = value;
    return stack;
}

#endif // DYNAMICSTACK_H_INCLUDED