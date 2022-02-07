#include "list.h"
#include <stdio.h>

int main(){
    list_type* list_ptr = list_create();
    if (list_ptr == NULL) {
        printf("create error\n");
        return -1;
    }
    list_destroy(list_ptr);
    return 0;
}
