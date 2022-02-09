#pragma once

#include <stdlib.h>

typedef int Type;

typedef struct node_struct node_type;

typedef struct list_struct list_type;

list_type* list_create();
int list_push_back(list_type* list_ptr, Type value);
void list_dump(const list_type* list_ptr);
Type list_get_i_th(const list_type* list_ptr, size_t i, int* err);
int list_set_i_th(const list_type* list_ptr, Type value, size_t i);
size_t list_get_size(const list_type* list_ptr);
void list_destroy(list_type* list_ptr);

