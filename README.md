# VectorAndList project

## How to build our project:
```
$ mkdir build && cd build
$ cmake ..
$ make
```

## After build you will get 4 exec files:
- vector_on_insertion_sort
- list_on_bubble_sort
- list_on_insertion_sort
- vector_on_bubble_sort

## and it is all combinations of build two realizations and two sorts with our vector and list.

## This is table of our methods:

| function | prototype |
| :---: | :---: |
| constructor | struct container * **_name_**_create () |
| put the element at the end of the container | int push_back (struct container *p, Type value) |
| get i_th element | Type get_i_th (const struct container *p, size_t i, int *err) |
| set i th element | int set_i_th (const struct container *p, Type value, size_t i) |
| get size of container | size_t get_size (const struct container *p) |
| destructor | void destroy (struct container *p) |
