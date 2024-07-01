cmake_minimum_required(VERSION 3.28)
project(Cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(Cpp main.cpp
        "datastructures/arraylist.cpp"
        "datastructures/arraylist.h"
        "datastructures/linkedlist.cpp"
        "datastructures/linkedlist.h"
        "datastructures/optional.cpp"
        "datastructures/optional.h"
        "datastructures/hashmap.cpp"
        "datastructures/hashmap.h"
        math/vectors.cpp
        math/vectors.h
        math/functions.cpp
        math/functions.h
        IO/io.h
        IO/io.cpp
        math/random.cpp
        math/random.h)
