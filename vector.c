#include "vector.h"

struct vector{
    Type *arr_;
    size_t capacity_;
    size_t size_;
};

//-----------------------------------------------------------------------------------------------------

struct vector *vector_create ()
{
    struct vector * vec = (struct vector *) malloc (sizeof (struct vector) * 1);

    vec->size_ = 0;
    vec->capacity_ = 1;
    vec->arr_ = (Type *) malloc (sizeof (Type) * vec->capacity_);;

    return vec;
}

//-----------------------------------------------------------------------------------------------------

void extention_vec (struct vector *vec)
{
    Type *tmp = (Type *) malloc (sizeof (Type) * vec->capacity_ * 2);

    for (size_t i = 0; i < vec->size_; ++i)
        tmp[i] = vec->arr_[i];

    free (vec->arr_);
    vec->arr_ = tmp;
    vec->capacity_ = vec->capacity_ * 2;
}

//-----------------------------------------------------------------------------------------------------

int vector_push_back (struct vector *vec, Type value)
{
    if (vec->size_ >= vec->capacity_)
        extention_vec (vec);

    vec->arr_[vec->size_++] = value;

    return 0;
}

//-----------------------------------------------------------------------------------------------------

void vector_dump (const struct vector *vec)
{
    for (size_t i = 0; i < vec->size_; ++i)
        printf ("%d ", vec->arr_[i]);
}

//-----------------------------------------------------------------------------------------------------

Type vector_get_i_th (const struct vector *vec, size_t i)
{
    return vec->arr_[i];
}

//-----------------------------------------------------------------------------------------------------

void vector_set_i_th (const struct vector *vec, Type value, size_t i)
{
    vec->arr_[i] = value;
}

//-----------------------------------------------------------------------------------------------------

size_t vector_get_size (const struct vector *vec)
{
    return vec->size_;
}

//-----------------------------------------------------------------------------------------------------

void vector_destruct (struct vector *vec)
{
    free (vec->arr_);
    free (vec);
}

