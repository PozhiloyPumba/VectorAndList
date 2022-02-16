#include "vector.h"

const Type poison = 0xDEADBEEF;

//-----------------------------------------------------------------------------------------------------

container *vector_create ()
{
    container *cont = malloc (sizeof (container) + sizeof (struct vector));
    if (!cont)
        return NULL;
    cont->m = malloc (sizeof (base));

    struct vector *vec = (struct vector *)((container *)cont + 1);

    vec->size_ = 0;
    vec->capacity_ = 1;
    vec->arr_ = malloc (sizeof (Type) * vec->capacity_);
    
    if (!vec->arr_) {
        free (vec);
        return NULL;
    }
    cont->m->push_back  = &vector_push_back;
    cont->m->get_i_th   = &vector_get_i_th;
    cont->m->get_size   = &vector_get_size;
    cont->m->set_i_th   = &vector_set_i_th;
    cont->m->destroy    = &vector_destruct;

    return cont;
}

//-----------------------------------------------------------------------------------------------------

int extention_vec (struct vector *vec)
{
    Type *tmp = malloc (sizeof (Type) * vec->capacity_ * 2);
    if (!tmp)
        return 1;

    for (size_t i = 0; i < vec->size_; ++i)
        tmp[i] = vec->arr_[i];

    free (vec->arr_);
    vec->arr_ = tmp;
    vec->capacity_ *= 2;

    return 0;
}

//-----------------------------------------------------------------------------------------------------

int vector_push_back (container *cont, Type value)
{
    struct vector *vec = (struct vector *)((container *)cont + 1);

    if (vec->size_ >= vec->capacity_)
        if (extention_vec (vec))
            return 1;

    vec->arr_[vec->size_++] = value;

    return 0;
}

//-----------------------------------------------------------------------------------------------------

Type vector_get_i_th (const container *cont, size_t i, int *err)
{
    struct vector *vec = (struct vector *)((container *)cont + 1);
    if (i >= vec->size_) {
        *err = 1;
        return poison;
    }

    return vec->arr_[i];
}

//-----------------------------------------------------------------------------------------------------

int vector_set_i_th (const container *cont, Type value, size_t i)
{
    struct vector *vec = (struct vector *)((container *)cont + 1);
    if (i >= vec->size_)
        return 1;

    vec->arr_[i] = value;

    return 0;
}

//-----------------------------------------------------------------------------------------------------

size_t vector_get_size (const container *cont)
{
    struct vector *vec = (struct vector *)((container *)cont + 1);
    return vec->size_;
}

//-----------------------------------------------------------------------------------------------------

void vector_destruct (container *cont)
{
    struct vector *vec = (struct vector *)((container *)cont + 1);
    free (vec->arr_);
    free (cont->m);
    free (cont);
}