#pragma once

#include <stdio.h>

typedef int Type;

struct container;

typedef struct base {
    int (*push_back) (struct container *, Type);
    Type (*get_i_th) (const struct container *, size_t, int *);
    int (*set_i_th) (const struct container *, Type, size_t);
    size_t (*get_size) (const struct container *);
    void (*destroy) (struct container *);
} base;

typedef struct container {
    base *m;
} container;