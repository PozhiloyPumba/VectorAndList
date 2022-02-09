#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node_struct {
    Type val;
    struct node_struct* prev;
    struct node_struct* next;
};

struct list_struct {
    node_type* head;
    node_type* tail;
    size_t size;
};

list_type* list_create(){
    list_type* list_ptr = malloc(sizeof(list_type));

    if (list_ptr == NULL) 
        return NULL;

    list_ptr -> head = NULL;
    list_ptr -> tail = NULL;
    list_ptr -> size = 0;

    return list_ptr;
}

void list_destroy(list_type* list_ptr){
    node_type* node_ptr = list_ptr -> head;
    if (list_ptr -> size == 0) {
        free(list_ptr);
        return;
    }
    while(1){
        if (node_ptr -> next == NULL) {
            free(node_ptr);
            break;
        }
        node_ptr = node_ptr -> next;
        free(node_ptr -> prev);
    }
    free(list_ptr);
}

int list_push_back(list_type* list_ptr, Type value){
    node_type* new_node = malloc(sizeof(node_type));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        return -1;
    }
    new_node -> prev = list_ptr -> tail;
    new_node -> next = NULL;
    new_node -> val = value;
    if (list_ptr -> size == 0) 
        list_ptr -> head = new_node;    
    if (list_ptr -> size != 0)
        list_ptr -> tail -> next = new_node;
    list_ptr -> tail = new_node;
    list_ptr -> size += 1;
    return 0;
}

void list_dump(const list_type* list_ptr){
    node_type* node_ptr = list_ptr -> head;
    for(size_t i = 0; i < (list_ptr -> size); i++){
        printf("[%ld] %d\n", i, node_ptr -> val);
        node_ptr = node_ptr -> next;
    }
}

Type list_get_i_th(const list_type* list_ptr, size_t i, int* err){
    if (i > list_ptr -> size) {
        *err = 0xDEDBEEF;
        return 0;
    }   
    node_type* node_ptr = list_ptr -> head;
    for(size_t k = 0; k < i; k++)
        node_ptr = node_ptr -> next;

    return (node_ptr -> val);
}

int list_set_i_th(const list_type* list_ptr, Type value, size_t i){
    if (i > list_ptr -> size) {
        return -1;
    }   
    node_type* node_ptr = list_ptr -> head;
    for(size_t k = 0; k < i; k++)
        node_ptr = node_ptr -> next;

    node_ptr -> val = value;
    return 0;
}

size_t list_get_size(const list_type* list_ptr){
    return (list_ptr -> size);    
}

