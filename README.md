# VectorAndList project

## How to build our project:
```
$ mkdir build && cd build
$ cmake ..
$ make
```

| функция | прототип |
| :---: | :---: |
| конструктор | struct **_name_** * **_name_**_create () |
| добавление элемента в конец | int **_name_**_push_back (struct **_name_** *p, Type value) |
| печать | void **_name_**_dump (const struct **_name_** *p) |
| получить i_ый элемент | Type **_name_**_get_i_th (const struct **_name_** *p, size_t i, int *err) |
| установить i_ый элемент | int **_name_**_set_i_th (const struct **_name_** *p, Type value, size_t i) |
| получить размер | size_t **_name_**_get_size (const struct **_name_** *p) |
| деструктор | void **_name_**_destroy (struct **_name_** *p) |

| coming soon... | |
| :---: | :---: |
| добавить элемент на i_ую позицию | int **_name_**_push_i_th (const struct **_name_** *p, Type value, size_t i) |
| удалить i_ый элемент | void **_name_**_remove_i_th (struct **_name_** *p, size_t i);|
| добавление элемента в начало | int **_name_**_push_front (struct **_name_** *p, Type value) |
