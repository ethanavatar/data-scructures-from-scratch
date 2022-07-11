#ifndef DYNAMICSTACKQUEUE_H
#define DYNAMICSTACKQUEUE_H

#include "../stacks/dynamic_stack.h"
#include "stack_queue.h"

static void enqueue_dynamic(t_stack_queue* queue, const int value) {
    while (!stack_is_empty(queue->s1)) {
        push_dynamic(queue->s2, pop(queue->s1));
    }

    push_dynamic(queue->s1, value);

    while (!stack_is_empty(queue->s2)) {
        push_dynamic(queue->s1, pop(queue->s2));
    }
}

#endif // DYNAMICSTACKQUEUE_H