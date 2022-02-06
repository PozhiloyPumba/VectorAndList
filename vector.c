#include "vector.h"

struct vector{
    vecType *arr_;
    int size_;
};

//-----------------------------------------------------------------------------------------------------

struct vector *vector_construct (int size)
{
    struct vector * vec = (struct vector *) malloc (sizeof (struct vector) * 1);

    vec->arr_ = (vecType *) malloc (sizeof (vecType) * size);
    vec->size_ = size;

    return vec;
}

//-----------------------------------------------------------------------------------------------------

void vector_init (struct vector *vec)
{
    int err;
    for (int i = 0; i < vec->size_; ++i){
        err = scanf ("%d", (vec->arr_) + i);
        assert (err);
    }
}

//-----------------------------------------------------------------------------------------------------

void vector_print (const struct vector *vec)
{
    for (int i = 0; i < vec->size_; ++i)
        printf ("%d ", vec->arr_[i]);
}

//-----------------------------------------------------------------------------------------------------

vecType vector_get_i_th (const struct vector *vec, int i)
{
    return vec->arr_[i];
}

//-----------------------------------------------------------------------------------------------------

void vector_destruct (struct vector *vec)
{
    free (vec->arr_);
    free (vec);
}

