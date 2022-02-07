#include <stdio.h>
#include <assert.h>

#include "vector.h"

void insertion_sort (struct vector *vec);

void swap (struct vector *vec, size_t first, size_t second);

int main ()
{
    size_t size;
    int err = scanf ("%ld", &size);
    assert (err);

    struct vector *vec = vector_create ();

    Type value;
    for (size_t i = 0; i < size; ++i) {
        err = scanf ("%d", &value);
        assert (err);
        vector_push_back (vec, value);
    }

    insertion_sort (vec);

    vector_dump (vec);
    printf ("\n");

    vector_destruct (vec);

    return 0;
}

void insertion_sort (struct vector *vec)
{
    size_t size = vector_get_size (vec);

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i; j > 0; --j) {
            if (vector_get_i_th (vec, j - 1) <= vector_get_i_th (vec, j))
                break;

            swap (vec, j - 1, j);
        }
    }
}

void swap (struct vector *vec, size_t first, size_t second)
{
    Type tmp = vector_get_i_th (vec, first);
    vector_set_i_th (vec, vector_get_i_th (vec, second), first);
    vector_set_i_th (vec, tmp, second);
}