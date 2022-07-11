#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node {
    int value;
    struct linked_list_node* next;
} t_linked_list_node;

static t_linked_list_node* create_linked_list_node(const int value) {
    t_linked_list_node* node = (t_linked_list_node*) malloc(sizeof(t_linked_list_node));
    node->value = value;
    node->next = NULL;

    return node;
}

static void linked_list_append(t_linked_list_node* head, const int value) {
    t_linked_list_node* new_node = create_linked_list_node(value);
    t_linked_list_node* current = head;

    if (current == NULL) {
        head->next = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

static t_linked_list_node* linked_list_prepend(t_linked_list_node* head, const int value) {
    t_linked_list_node* new_node = create_linked_list_node(value);
    new_node->next = head->next;
    
    return new_node;
}


#endif // SINGLELINKEDLIST_H