#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

struct vector{
    Type *arr_;
    size_t capacity_;
    size_t size_;
};

container *vector_create ();
int vector_push_back (container *cont, Type value);
Type vector_get_i_th (const container *cont, size_t i, int *err);
int vector_set_i_th (const container *cont, Type value, size_t i);
size_t vector_get_size (const container *cont);
void vector_destruct (container *cont);

#endif