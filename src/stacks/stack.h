#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack {
    int* data;
    int top;
    int capacity;
} t_stack;

static t_stack* create_stack(const int capacity) {
    t_stack* stack = (t_stack*) malloc(sizeof(t_stack));
    stack->data = (int*) malloc(capacity * sizeof(int));
    stack->top = 0;
    stack->capacity = capacity;

    return stack;
}

static t_stack* stack_push(t_stack* stack, const int value) {
    stack->data[stack->top++] = value;
    return stack;
}

static int stack_pop(t_stack* stack) {
    return stack->data[--stack->top];
}

static int stack_peek(t_stack* stack) {
    return stack->data[stack->top - 1];
}

static int stack_is_empty(t_stack* stack) {
    return stack->top == 0;
}

#endif // STACK_H