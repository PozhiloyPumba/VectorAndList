cmake_minimum_required (VERSION 3.0)

project (listAndVector VERSION 1.0)

set (VECTOR_TEST "vector_on_insertion_sort")
set (LIST_TEST "list_on_bubble_sort")
set (CROSS_LIST_TEST "list_on_insertion_sort")
set (CROSS_VECTOR_TEST "vector_on_bubble_sort")

set (HEADERS
    include/list.h
    include/common.h
)

set (LIST_SOURCES
    src/list.c
)

set (VECTOR_SOURCES
    src/vector.c
)

set (LIST_SORT
    src/test_list.c
)

set (VECTOR_SORT
    src/test_vector.c
)

add_executable(${VECTOR_TEST} ${VECTOR_SORT} ${VECTOR_SOURCES})
add_executable(${LIST_TEST} ${LIST_SORT} ${LIST_SOURCES})
add_executable(${CROSS_VECTOR_TEST} ${LIST_SORT} ${VECTOR_SOURCES})
add_executable(${CROSS_LIST_TEST} ${VECTOR_SORT} ${LIST_SOURCES})

target_include_directories(${VECTOR_TEST} PRIVATE include)
target_include_directories(${LIST_TEST} PRIVATE include)
target_include_directories(${CROSS_VECTOR_TEST} PRIVATE include)
target_include_directories(${CROSS_LIST_TEST} PRIVATE include)

set (COMPILER_SETTINGS
    -Wall
    -Wextra

    -O2
)

set (VECTOR_DEF
    -DVECTOR
)

target_compile_options(${VECTOR_TEST} PRIVATE ${COMPILER_SETTINGS} ${VECTOR_DEF})
target_compile_options(${LIST_TEST} PRIVATE ${COMPILER_SETTINGS})
target_compile_options(${CROSS_VECTOR_TEST} PRIVATE ${COMPILER_SETTINGS} ${VECTOR_DEF})
target_compile_options(${CROSS_LIST_TEST} PRIVATE ${COMPILER_SETTINGS})
