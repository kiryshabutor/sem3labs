cmake_minimum_required(VERSION 3.31.6)
project(lab8)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab8 main.cpp
        includes/app.h
        src/input_utils.cpp
        includes/input_utils.h
        includes/doubly_linked_list.h
        includes/list_algorithm.h)
