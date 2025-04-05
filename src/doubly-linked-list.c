#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doubly-linked-list.h"

DLinkedList* init_list(void) {
    DLinkedList* new_list = (DLinkedList*) malloc(sizeof (DLinkedList));
    if (!new_list) {
        return NULL;
    }

    // Inicializa a cabeça e a cauda com NULL;
    new_list->head = new_list->tail = NULL;
    return new_list;
}

bool is_list_empty(DLinkedList* list) {
    return !list || (!list->head && !list->tail);
}

Node* create_node(NodeValue value, NodeValueType value_type) {
    Node* new_node = (Node*) malloc(sizeof (Node));
    if (!new_node) {
        return NULL;
    }

    switch (value_type) {
        case BOOL_VALUE:
            new_node->value.bool_value = value.bool_value;
            break;

        case CHAR_VALUE:
            new_node->value.char_value = value.char_value;
            break;

        case INT_VALUE:
            new_node->value.int_value = value.int_value;
            break;

        case FLOAT_VALUE:
            new_node->value.float_value = value.float_value;
            break;
        
        case DOUBLE_VALUE:
            new_node->value.double_value = value.double_value;
            break;
        
        case STRING_VALUE:
            char* string_val_copy = (char*) malloc(strlen(value.string_value) + 1);
            if (!string_val_copy) {
                return NULL;
            }
            strcpy(string_val_copy, value.string_value);

            new_node->value.string_value = string_val_copy;
    }

    new_node->value_type = value_type;

    return new_node;
}

void push(DLinkedList* list,  NodeValue value, NodeValueType value_type) {
    if (!list) {
        return;
    }

    Node* new_node = create_node(value, value_type);
    if (!new_node) {
        return;
    }

    new_node->prev = NULL;
    new_node->next = list->head;

    list->head = new_node;
}

void push_bool(DLinkedList* list, bool value) {
    push(list, (NodeValue) value, BOOL_VALUE);
}

void push_char(DLinkedList* list, char value) {
    push(list, (NodeValue) value, CHAR_VALUE);
}

void push_int(DLinkedList* list, int value) {
    push(list, (NodeValue) value, INT_VALUE);
}

void push_float(DLinkedList* list, float value) {
    push(list, (NodeValue) value, FLOAT_VALUE);
}

void push_double(DLinkedList* list, double value) {
    push(list, (NodeValue) value, DOUBLE_VALUE);
}

void push_string(DLinkedList* list, char* value) {
    push(list, (NodeValue) value, STRING_VALUE);
}

void from_start(DLinkedList* list) {
    printf("From the start: ");

    Node* curr = list->head;
    while (curr) {
        switch (curr->value_type) {
            case BOOL_VALUE:
                printf("%s", curr->value.bool_value ? "true" : "false");
                break;

            case CHAR_VALUE:
                printf("%c", curr->value.char_value);
                break;
                
            case INT_VALUE:
                printf("%d", curr->value.int_value);
                break;
            
            case FLOAT_VALUE:
                printf("%f", curr->value.float_value);
                break;
            
            case DOUBLE_VALUE:
                printf("%lf", curr->value.double_value);
                break;
            
            case STRING_VALUE:
                printf("%s", curr->value.string_value);
                break;
        }
        printf(" -> ");
        
        curr = curr->next;
    }
    puts("NULL");
}

void from_end(DLinkedList* list) {
    printf("From the end: ");

    Node* curr = list->tail;
    while (curr) {
        switch (curr->value_type) {
            case BOOL_VALUE:
            case INT_VALUE:
                printf("%d", curr->value.int_value);
                break;

            case CHAR_VALUE:
                printf("%c", curr->value.char_value);
                break;

            case FLOAT_VALUE:
                printf("%f", curr->value.float_value);
                break;
            
            case DOUBLE_VALUE:
                printf("%lf", curr->value.double_value);
                break;
            
            case STRING_VALUE:
                printf("%s", curr->value.string_value);
                break;
        }
        printf(" -> ");
        
        curr = curr->next;
    }
    puts("NULL");
}