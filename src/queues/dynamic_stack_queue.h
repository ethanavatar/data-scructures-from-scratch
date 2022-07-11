#ifndef DYNAMICSTACKQUEUE_H
#define DYNAMICSTACKQUEUE_H

#include "../stacks/dynamic_stack.h"
#include "stack_queue.h"

static void stack_queue_enqueue_dynamic(t_stack_queue* queue, const int value) {
    while (!stack_is_empty(queue->s1)) {
        stack_push_dynamic(queue->s2, stack_pop(queue->s1));
    }

    stack_push_dynamic(queue->s1, value);

    while (!stack_is_empty(queue->s2)) {
        stack_push_dynamic(queue->s1, stack_pop(queue->s2));
    }
}

#endif // DYNAMICSTACKQUEUE_H