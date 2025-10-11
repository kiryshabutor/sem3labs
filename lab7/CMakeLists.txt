cmake_minimum_required(VERSION 4.0)
project(lab7)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab7 src/main.cpp
        src/app.cpp
        includes/app.h
        includes/input_utils.h
        src/input_utils.cpp
        src/file_reader.cpp
        includes/file_reader.h)
