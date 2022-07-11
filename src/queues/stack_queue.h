#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include "../stacks/stack.h"

typedef struct stack_queue {
    t_stack *s1;
    t_stack *s2;
} t_stack_queue;

static t_stack_queue* create_stack_queue(const int capacity) {
    t_stack_queue* stack_queue = (t_stack_queue*) malloc(sizeof(t_stack_queue));
    stack_queue->s1 = create_stack(capacity);
    stack_queue->s2 = create_stack(capacity);

    return stack_queue;
}

static void enqueue(t_stack_queue* queue, const int value) {
    while (!stack_is_empty(queue->s1)) {
        stack_push(queue->s2, stack_pop(queue->s1));
    }

    stack_push(queue->s1, value);

    while (!stack_is_empty(queue->s2)) {
        stack_push(queue->s1, stack_pop(queue->s2));
    }
}

static int dequeue(t_stack_queue* queue) {
    return stack_pop(queue->s1);
}

static int queue_is_empty(t_stack_queue* queue) {
    return stack_is_empty(queue->s1);
}

#endif // STACKQUEUE_H