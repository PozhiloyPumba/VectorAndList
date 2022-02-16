#pragma once

#include <stdio.h>

typedef int Type;

struct base {
    int (*push_back) (void *, Type);
    Type (*get_i_th) (void *, size_t, int *);
    int (*set_i_th) (const void *, Type, size_t);
    size_t (*get_size) (const void *);
    void (*destroy) (void *);
};