cmake_minimum_required(VERSION 4.0)
project(lab5)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab5 main.cpp
        src/app.cpp
        includes/app.h
        includes/node.h
        src/singly_linked_list.tpp
        includes/singly_linked_list.h
        src/input_utils.cpp
        includes/input_utils.h)
