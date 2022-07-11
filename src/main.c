#include <stdio.h>
#include <stdlib.h>


#include "stacks/stack.h"
void test_static_stack() {
    t_stack* s = create_stack(2);
    push(s, 1);
    push(s, 2);
    int two = pop(s);
    int one = peek(s);

    printf("%d\n", two);
    printf("%d\n", one);

    pop(s);
    stack_is_empty(s);

    free(s);
}

#include "stacks/dynamic_stack.h"
void test_dynamic_stack() {
    t_stack* s = create_stack(1);
    push_dynamic(s, 1);
    push_dynamic(s, 2);
    int two = pop(s);
    int one = peek(s);

    printf("%d\n", two);
    printf("%d\n", one);

    pop(s);
    stack_is_empty(s);

    free(s);
}

#include "queues/stack_queue.h"
void test_stack_queue() {
    t_stack_queue* s = create_stack_queue(2);
    enqueue(s, 1);
    enqueue(s, 2);
    int one = dequeue(s);
    int two = dequeue(s);

    printf("%d\n", one);
    printf("%d\n", two);

    stack_queue_is_empty(s);

    free(s);
}

#include "queues/dynamic_stack_queue.h"
void test_dynamic_stack_queue() {
    t_stack_queue* s = create_stack_queue(1);
    enqueue_dynamic(s, 1);
    enqueue_dynamic(s, 2);
    int one = dequeue(s);
    int two = dequeue(s);

    printf("%d\n", one);
    printf("%d\n", two);

    stack_queue_is_empty(s);

    free(s);
}

int main () {
    //test_static_stack();
    //test_dynamic_stack();
    //test_stack_queue();
    //test_dynamic_stack_queue();

    return 0;
}