#include <stdio.h>
#include <assert.h>

#include "common.h"


void insertion_sort (container *obj);

void swap (container *obj, size_t first, size_t second);

void dump(container* obj);


int main ()
{
    #ifdef VECTOR
        container *obj = vector_create ();
    #else
        container *obj = list_create ();
    #endif
 
    size_t size;
    int err = scanf ("%ld", &size);
    assert (err);

    Type value;
    for (size_t i = 0; i < size; ++i) {
        err = scanf ("%d", &value);
        assert (err);
        obj->m->push_back (obj, value);
    }

    printf("Unsorted:\n");
    dump(obj);
    insertion_sort (obj);

    printf("Sorted:\n");
    dump(obj);

    obj->m->destroy (obj);

    return 0;
}

void insertion_sort (container *obj)
{
    size_t size = obj->m->get_size (obj);
    int err;

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i; j > 0; --j) {
            if (obj->m->get_i_th (obj, j - 1, &err) <= obj->m->get_i_th (obj, j, &err))
                break;

            swap (obj, j - 1, j);
        }
    }
}

void swap (container *obj, size_t first, size_t second)
{
    int err;
    Type tmp = obj->m->get_i_th (obj, first, &err);
    obj->m->set_i_th (obj, obj->m->get_i_th (obj, second, &err), first);
    obj->m->set_i_th (obj, tmp, second);
}

void dump(container* obj)
{
    int err = 0;
    for(size_t i = 0; i < (obj->m->get_size(obj)); i++) {
        printf("%d ", obj->m->get_i_th(obj, i, &err));
        if (err)
            return;
    }
    printf ("\n");
}