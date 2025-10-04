cmake_minimum_required(VERSION 3.31.6)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4
        main.cpp
        src/app.cpp
        src/worker.cpp
        src/hourly_employee.cpp
        src/salaried_employee.cpp
        src/commission_employee.cpp
        main.cpp
        src/app.cpp
        includes/app.h
        src/commission_employee.cpp
        includes/commission_employee.h
        src/salaried_employee.cpp
        includes/salaried_employee.h
        src/hourly_employee.cpp
        includes/hourly_employee.h
        src/worker.cpp
        includes/worker.h
        src/input_utils.cpp
        includes/input_utils.h)
