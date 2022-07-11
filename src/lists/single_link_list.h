#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct single_link_node {
    int value;
    struct single_link_node* next;
} t_single_link_node;

static t_single_link_node* create_single_link_node(const int value) {
    t_single_link_node* node = (t_single_link_node*) malloc(sizeof(t_single_link_node));
    node->value = value;
    node->next = NULL;

    return node;
}

static int single_link_length(t_single_link_node* head) {
    t_single_link_node* current = head;
    int i = 0;
    
    while (current != NULL) {
        current = current->next;
        i++;
    }
    return i;
}

static void single_link_append(t_single_link_node* head, const int value) {
    t_single_link_node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = create_single_link_node(value);
}

static t_single_link_node* single_link_prepend(t_single_link_node* head, const int value) {
    t_single_link_node* new_node = create_single_link_node(value);
    new_node->next = head;
    
    return new_node;
}

static void single_link_insert(t_single_link_node* head, int index, const int value) {
    t_single_link_node* new_node = create_single_link_node(value);
    t_single_link_node* current = head;
    int i = 0;
    
    if (index == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        while (i < index - 1) {
            current = current->next;
            i++;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

static void single_link_remove(t_single_link_node* head, const int index) {
    t_single_link_node* current = head;
    t_single_link_node* previous = NULL;
    int i = 0;
    
    while (current != NULL) {
        if (i == index) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
        i++;
    }
}

static int single_link_get(t_single_link_node* head, const int index) {
    t_single_link_node* current = head;
    int i = 0;
    
    while (current != NULL) {
        if (i == index) {
            return current->value;
        }
        current = current->next;
        i++;
    }
    return -1;
}

static void single_link_free(t_single_link_node* head) {
    t_single_link_node* current = head;
    t_single_link_node* next;

    while (current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

typedef struct single_link_list {
    t_single_link_node* head;
} t_single_link_list;

static t_single_link_list* create_single_link_list() {
    t_single_link_list* list = (t_single_link_list*) malloc(sizeof(t_single_link_list));
    list->head = NULL;

    return list;
}

static void single_link_list_append(t_single_link_list* list, const int value) {
    if (list->head == NULL) {
        list->head = create_single_link_node(value);
    } else {
        single_link_append(list->head, value);
    }
}

static void single_link_list_prepend(t_single_link_list* list, const int value) {
    if (list->head == NULL) {
        list->head = create_single_link_node(value);
    } else {
        list->head = single_link_prepend(list->head, value);
    }
}

static void single_link_list_insert(t_single_link_list* list, int index, const int value) {
    if (list->head == NULL) {
        list->head = create_single_link_node(value);
    } else {
        single_link_insert(list->head, index, value);
    }
}

static void single_link_list_remove(t_single_link_list* list, const int index) {
    if (list->head != NULL) {
        single_link_remove(list->head, index);
    }
}

static int single_link_list_get(t_single_link_list* list, const int index) {
    if (list->head != NULL) {
        return single_link_get(list->head, index);
    }
    return -1;
}

static int single_link_list_length(t_single_link_list* list) {
    if (list->head != NULL) {
        return single_link_length(list->head);
    }
    return 0;
}

static void single_link_list_free(t_single_link_list* list) {
    if (list->head != NULL) {
        single_link_free(list->head);
    }
    free(list);
}

#endif // SINGLELINKLIST_H