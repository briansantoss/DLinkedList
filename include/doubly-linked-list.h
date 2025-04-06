#ifndef DOUBLY_LINKED_LIST_H

#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

// Definindo os tipos possíveis de um nó da lista
typedef enum {
    BOOL_VALUE,
    CHAR_VALUE,
    INT_VALUE,
    FLOAT_VALUE,
    DOUBLE_VALUE,
    STRING_VALUE,
} NodeValueType;

typedef union NodeValue {
    bool bool_value;
    char char_value;
    int int_value;
    float float_value;
    double double_value;
    char* string_value;
} NodeValue;

typedef struct Node {
    NodeValue value;
    NodeValueType value_type;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DLinkedList;

DLinkedList* init_list(void);
void free_list(DLinkedList* list);

// Funções para inserção no início
void push_bool(DLinkedList* list, bool value);
void push_char(DLinkedList* list, char value);
void push_int(DLinkedList* list, int value);
void push_float(DLinkedList* list, float value);
void push_double(DLinkedList* list, double value);
void push_string(DLinkedList* list, char* value);

// Funções para inserção no final
void push_end_bool(DLinkedList* list, bool value);
void push_end_char(DLinkedList* list, char value);
void push_end_int(DLinkedList* list, int value);
void push_end_float(DLinkedList* list, float value);
void push_end_double(DLinkedList* list, double value);
void push_end_string(DLinkedList* list, char* value);

// Funções para impressão da lista
void from_start(DLinkedList* list);
void from_end(DLinkedList* list);

#endif