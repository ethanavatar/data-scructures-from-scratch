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
        push(queue->s2, pop(queue->s1));
    }

    push(queue->s1, value);

    while (!stack_is_empty(queue->s2)) {
        push(queue->s1, pop(queue->s2));
    }
}

static int dequeue(t_stack_queue* queue) {
    return pop(queue->s1);
}

static int stack_queue_is_empty(t_stack_queue* queue) {
    return stack_is_empty(queue->s1);
}

#endif // STACKQUEUE_H