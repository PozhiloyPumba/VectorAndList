cmake_minimum_required (VERSION 3.0)

project (listAndVector VERSION 1.0)

set (VECTOR_TEST "vector_test")
set (LIST_TEST "list_test")

set (LIST_HEADERS
    list/list.h
)
    
set (VECTOR_HEADERS
    vector/vector.h
)
    
set (LIST_SOURCES
    list/list.c
)

set (VECTOR_SOURCES
    vector/vector.c
)

set (LIST_SORT
    sortings/test_list.c
)

set (VECTOR_SORT
    sortings/test_vector.c
)

add_executable(${VECTOR_TEST} ${VECTOR_SORT} ${VECTOR_SOURCES})
add_executable(${LIST_TEST} ${LIST_SORT} ${LIST_SOURCES})

target_include_directories(${VECTOR_TEST} PRIVATE vector)
target_include_directories(${LIST_TEST} PRIVATE list)

set (COMPILER_SETTINGS
    -Wall
    -Wextra

    -O2
)

target_compile_options(${VECTOR_TEST} PRIVATE ${COMPILER_SETTINGS})
target_compile_options(${LIST_TEST} PRIVATE ${COMPILER_SETTINGS})
