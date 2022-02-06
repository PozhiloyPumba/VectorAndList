#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int vecType;

struct vector;

struct vector *vector_construct (int size);
void vector_init (struct vector *vec);
void vector_print (const struct vector *vec);
vecType vector_get_i_th (const struct vector *vec, int i);
vecType vector_remove_i_th (const struct vector *vec, int i);
void vector_destruct (struct vector *vec);

#endif