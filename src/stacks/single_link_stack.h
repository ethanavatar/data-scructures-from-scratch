#ifndef SINGLELINKSTACK_H
#define SINGLELINKSTACK_H

#include <stdio.h>
#include <stdlib.h>

#include "../lists/single_link_list.h"


typedef struct single_link_stack {
    t_single_link_node* head;
    t_single_link_node* top;
    int size;
} t_single_link_stack;

static t_single_link_stack* create_single_link_stack() {
    t_single_link_stack* stack = (t_single_link_stack*) malloc(sizeof(t_single_link_stack));
    stack->head = NULL;
    stack->top = NULL;
    stack->size = 0;

    return stack;
}

static void single_link_stack_push(t_single_link_stack* stack, const int value) {
    printf("single_link_stack_push: %d\n", value);
    if (stack->head == NULL) {
        stack->head = create_single_link_node(value);
        stack->top = stack->head;
    } else {
        single_link_append(stack->top, value);
        stack->top = stack->top->next;
    }

    stack->size++;
}

static int single_link_stack_pop(t_single_link_stack* stack) {
    int value = stack->top->value;

    printf("single_link_stack_pop: %d\n", value);

    single_link_remove(stack->head, single_link_length(stack->head) - 1);

    if (stack->head == NULL) {
        return -1;
    }

    stack->top = stack->head;
    
    while (stack->top->next != NULL) {
        stack->top = stack->top->next;
    }

    stack->size--;

    return value;
}

static int single_link_stack_peek(t_single_link_stack* stack) {
    return stack->top->value;
}

static int single_link_stack_is_empty(t_single_link_stack* stack) {
    return stack->size <= 0;
}

static void single_link_stack_free(t_single_link_stack* stack) {
    single_link_free(stack->head);
}

#endif // SINGLELINKSTACK_H