#include "list.h"
#include <stdio.h>

void bubble_sort(list_type* list_ptr);
int swap(list_type* list_ptr, size_t first, size_t second);

int main(){
    
    list_type* list_ptr = list_create();

    for (int i = 0; i < 10; i++) {
        int val;
        int err = scanf("%d", &val);
        if (err <= 0) 
            return -1;
        list_push_back(list_ptr, val);
    }

    printf("\n Unsorted:\n");
    list_dump(list_ptr);
    bubble_sort(list_ptr);

    printf("\n Sorted:\n");
    list_dump(list_ptr);

    return 0;
}

int swap(list_type* list_ptr, size_t first, size_t second){
    int err = 0;

    if ((first > list_get_size(list_ptr)) || (second > list_get_size(list_ptr)))
            return -1;

    if (first == second) 
        return 0;

    Type buf = list_get_i_th(list_ptr, first, &err);
    list_set_i_th(list_ptr, list_get_i_th(list_ptr, second, &err), first);
    list_set_i_th(list_ptr, buf, second);
    return 0;
}

void bubble_sort(list_type* list_ptr){
    int err;
    while(1){
        int sort_done = 0;
        
        for(size_t i = 0; i < (list_ptr -> size) - 1; i++){
            if (list_get_i_th(list_ptr, i + 1, &err) < list_get_i_th(list_ptr, i, &err)) {
                sort_done = 1;
                swap(list_ptr, i, i + 1);
            }
        }

        if (!sort_done) 
            break;
    }
}

