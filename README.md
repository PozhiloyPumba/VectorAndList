# VectorAndList project

## How to build our project:
```
$ mkdir build && cd build
$ cmake ..
$ make
```

## After build you will get 4 exec files:
- vector_on_test_vector
- list_on_test_list
- list_on_test_vector
- vector_on_test_list

## and it is all combinations of build two realization and two sort with our vector and list.

## This is table of our methods:

| function | prototype |
| :---: | :---: |
| constructor | struct container * **_name_**_create () |
| put the element at the end of the container | int push_back (struct container *p, Type value) |
| get i_th element | Type get_i_th (const struct container *p, size_t i, int *err) |
| set i th element | int set_i_th (const struct container *p, Type value, size_t i) |
| get size of container | size_t get_size (const struct container *p) |
| destructor | void destroy (struct container *p) |
