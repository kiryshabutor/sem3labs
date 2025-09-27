cmake_minimum_required(VERSION 4.0)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp
        src/date.cpp
        src/person.cpp
        src/entrepreneur.cpp
        src/tourist.cpp
        src/shuttler.cpp
        includes/date.h
        includes/person.h
        includes/entrepreneur.h
        includes/tourist.h
        includes/shuttler.h
        includes/input_utils.h
        src/input_utils.cpp
        src/app.cpp
        includes/app.h)
