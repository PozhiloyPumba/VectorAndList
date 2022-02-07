#include "list.h"
#include <stdio.h>

int main(){
    list_type* list_ptr = list_create();
    if (list_ptr == NULL) {
        printf("create error\n");
        return -1;
    }
    printf("created\n");
    for(int i = 0; i < 10; i++){
        list_push_back(list_ptr, 5 + 4 * i);
    }
    list_dump(list_ptr);
    int err;
    printf("[%d]\n", list_get_i_th(list_ptr, 5, &err));
    list_set_i_th(list_ptr, 0, 5);
    list_dump(list_ptr);
    list_destroy(list_ptr);
    return 0;
}
