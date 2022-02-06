#include <stdio.h>
#include <assert.h>

#include "vector.h"

void sort (struct vector *vec);

int main ()
{
    int size;
    int err = scanf ("%d", &size);
    assert(err);

    struct vector *vec = vector_construct (size);
    vector_init (vec);
    vector_destruct (vec);

    return 0;
}