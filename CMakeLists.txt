cmake_minimum_required(VERSION 3.28)
project(Cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(Cpp main.cpp
        "datastructures/arraylist.h"
        "datastructures/linkedlist.h"
        "datastructures/optional.h"
        "datastructures/hashmap.h"
        math/vectors.h
        math/functions.h
        IO/io.h
        IO/io.cpp
        math/random.h
        string/string.h
        math/matrix.h
        functional.h
        datastructures/queue.h
        datastructures/orderedmap.h)
