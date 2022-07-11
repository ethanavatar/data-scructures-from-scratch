#include <stdio.h>
#include <stdlib.h>


#include "stacks/stack.h"
void test_static_stack() {
    t_stack* s = create_stack(2);
    stack_push(s, 1);
    stack_push(s, 2);
    int two = stack_pop(s);
    int one = stack_peek(s);

    printf("%d\n", two);
    printf("%d\n", one);

    stack_pop(s);
    stack_is_empty(s);

    free(s);
}

#include "stacks/dynamic_stack.h"
void test_dynamic_stack() {
    t_stack* s = create_stack(1);
    stack_push_dynamic(s, 1);
    stack_push_dynamic(s, 2);
    int two = stack_pop(s);
    int one = stack_peek(s);

    printf("%d\n", two);
    printf("%d\n", one);

    stack_pop(s);
    stack_is_empty(s);

    free(s);
}

#include "queues/stack_queue.h"
void test_stack_queue() {
    t_stack_queue* s = create_stack_queue(2);
    stack_queue_enqueue(s, 1);
    stack_queue_enqueue(s, 2);
    int one = stack_queue_dequeue(s);
    int two = stack_queue_dequeue(s);

    printf("%d\n", one);
    printf("%d\n", two);

    stack_queue_is_empty(s);

    free(s);
}

#include "queues/dynamic_stack_queue.h"
void test_dynamic_stack_queue() {
    t_stack_queue* s = create_stack_queue(1);
    stack_queue_enqueue_dynamic(s, 1);
    stack_queue_enqueue_dynamic(s, 2);
    int one = stack_queue_dequeue(s);
    int two = stack_queue_dequeue(s);

    printf("%d\n", one);
    printf("%d\n", two);

    stack_queue_is_empty(s);

    free(s);
}

#include "lists/single_link_list.h"
void test_single_linked_list() {
    t_single_link_node* list = create_single_link_node(1);
    single_link_append(list, 2);
    single_link_append(list, 3);
    list = single_link_prepend(list, 0);
    single_link_remove(list, 2);
    single_link_insert(list, 2, 2);

    int list_length = single_link_length(list);
    for (int i = 0; i < list_length; i++) {
        printf("%d\n", single_link_get(list, i));
    }

    single_link_free(list);
}

#include "stacks/single_link_stack.h"
void test_single_linked_stack() {
    t_single_link_stack* s = create_single_link_stack();
    single_link_stack_push(s, 1);
    single_link_stack_push(s, 2);
    int two = single_link_stack_pop(s);
    int one = single_link_stack_peek(s);

    printf("%d\n", two);
    printf("%d\n", one);

    single_link_stack_pop(s);
    single_link_stack_is_empty(s);

    single_link_stack_free(s);
}

int main () {
    //test_static_stack();
    //test_dynamic_stack();
    //test_stack_queue();
    //test_dynamic_stack_queue();
    //test_single_linked_list();
    test_single_linked_stack();

    return 0;
}