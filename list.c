#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list_type* list_create(){
    list_type* list_ptr = malloc(sizeof(list_type));

    if (list_ptr == NULL) 
        return NULL;

    list_ptr -> head = NULL;
    list_ptr -> tail = NULL;
    list_ptr -> size = 0;

    return list_ptr;
}

int list_destroy(list_type* list_ptr){
    node_type* node_ptr = list_ptr -> head;
    if (list_ptr -> size == 0) 
        return 0;
    while(1){
        if (node_ptr -> next == NULL) {
            free(node_ptr);
            break;
        }
        node_ptr = node_ptr -> next;
        free(node_ptr -> prev);
    }
    return 0;
}
