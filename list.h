#pragma once

struct node_struct {
    int val;
    struct node_struct* prev;
    struct node_struct* next;
};

typedef struct node_struct node_type;

struct list_struct {
    node_type* head;
    node_type* tail;
    unsigned int size;
};

typedef struct list_struct list_type;

list_type* list_create();
list_type* list_create_size(unsigned int size);
int list_destroy(list_type* list_ptr);

