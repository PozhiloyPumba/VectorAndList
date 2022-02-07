#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Type;

struct vector;

struct vector *vector_create ();
int vector_push_back (struct vector *vec, Type value);
void vector_dump (const struct vector *vec);
Type vector_get_i_th (const struct vector *vec, size_t i);
void vector_set_i_th (const struct vector *vec, Type value, size_t i);
size_t vector_get_size (const struct vector *vec);
void vector_destruct (struct vector *vec);

#endif