#include "common.h"
#include <stdio.h>

void bubble_sort(container* list_ptr);
int swap(container* list_ptr, size_t first, size_t second);
void dump(container* cont);

int main(){
    #ifdef VECTOR
        container *cont_ptr = vector_create ();
    #else
        container *cont_ptr = list_create ();
    #endif

    size_t size;
    int err = scanf ("%ld", &size);
    if (err <= 0) 
        return -1;
    
    for (size_t i = 0; i < size; i++) {
        int val;
        err = scanf("%d", &val);
        if (err <= 0) 
            return -1;
        cont_ptr -> m -> push_back(cont_ptr, val);
    }

    printf("\n Unsorted:\n");
    dump(cont_ptr);
    bubble_sort(cont_ptr);

    printf("\n Sorted:\n");
    dump(cont_ptr);

    cont_ptr -> m -> destroy(cont_ptr);

    return 0;
}

int swap(container* cont_ptr, size_t first, size_t second){
    int err = 0;

    if ((first > cont_ptr -> m -> get_size(cont_ptr)) || (second > cont_ptr -> m -> get_size(cont_ptr)))
            return -1;

    if (first == second) 
        return 0;

    Type buf = cont_ptr -> m -> get_i_th(cont_ptr, first, &err);
    cont_ptr -> m -> set_i_th(cont_ptr, cont_ptr -> m -> get_i_th(cont_ptr, second, &err), first);
    cont_ptr -> m -> set_i_th(cont_ptr, buf, second);
    return 0;
}

void bubble_sort(container* cont_ptr){
    int err;
    while(1){
        int sort_done = 0;
        
        for(size_t i = 0; i < (cont_ptr -> m -> get_size(cont_ptr)) - 1; i++){
            if (cont_ptr -> m -> get_i_th(cont_ptr, i + 1, &err) < cont_ptr -> m -> get_i_th(cont_ptr, i, &err)) {
                sort_done = 1;
                swap(cont_ptr, i, i + 1);
            }
        }

        if (!sort_done) 
            break;
    }
}

void dump(container* cont){
    int err = 0;
    for(size_t i = 0; i < (cont -> m -> get_size(cont)); i++){
        printf("[%ld] %d\n", i, cont -> m -> get_i_th(cont, i, &err));
    }
}

