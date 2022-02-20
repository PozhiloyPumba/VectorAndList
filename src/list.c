#include "common.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct node_type;

typedef struct list_struct list_type;

int list_push_back(container* cont_ptr, Type value);
Type list_get_i_th(const container* cont_ptr, size_t i, int* err);
int list_set_i_th(const container* cont_ptr, Type value, size_t i);
size_t list_get_size(const container* cont_ptr);
void list_destroy(container* cont_ptr);


struct node_struct {
    Type val;
    struct node_struct* prev;
    struct node_struct* next;
};

struct list_struct {
    struct base m;
    node_type* head;
    node_type* tail;
    size_t size;
};

container* list_create(){
    container* cont = malloc(sizeof(container) + sizeof(list_type));
    if (cont == NULL) 
        return NULL;
    cont -> m = malloc(sizeof(base));
    list_type* list_ptr = (list_type*) (cont + 1);

    list_ptr -> head = NULL;
    list_ptr -> tail = NULL;
    list_ptr -> size = 0;

    cont->m->push_back  = &list_push_back;
    cont->m->get_i_th   = &list_get_i_th;
    cont->m->get_size   = &list_get_size;
    cont->m->set_i_th   = &list_set_i_th;
    cont->m->destroy    = &list_destroy;

    return cont;
}

void list_destroy(container* cont_ptr){
    list_type* list_ptr = (list_type*) (cont_ptr + 1);
    node_type* node_ptr = list_ptr -> head;
    if (list_ptr -> size == 0) {
        free(cont_ptr -> m);
        free(cont_ptr);
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

    free(cont_ptr -> m);
    free(cont_ptr);
}

int list_push_back(container* cont_ptr, Type value){
    list_type* list_ptr = (list_type*) (cont_ptr + 1);
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

Type list_get_i_th(const container* cont_ptr, size_t i, int* err){
    list_type* list_ptr = (list_type*) (cont_ptr + 1);
    if (i > list_ptr -> size) {
        *err = 0xDEDBEEF;
        return 0;
    }   
    node_type* node_ptr = list_ptr -> head;
    for(size_t k = 0; k < i; k++)
        node_ptr = node_ptr -> next;

    return (node_ptr -> val);
}

int list_set_i_th(const container* cont_ptr, Type value, size_t i){
    list_type* list_ptr = (list_type*) (cont_ptr + 1);
    if (i > list_ptr -> size) {
        return -1;
    }   
    node_type* node_ptr = list_ptr -> head;
    for(size_t k = 0; k < i; k++)
        node_ptr = node_ptr -> next;

    node_ptr -> val = value;
    return 0;
}

size_t list_get_size(const container* cont_ptr){
    list_type* list_ptr = (list_type*) (cont_ptr + 1);
    return (list_ptr -> size);    
}

