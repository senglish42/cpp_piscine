cmake_minimum_required(VERSION 3.22)
project(cpp04)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp04 ex01/main.cpp ex01/Animal.cpp ex01/Cat.cpp ex01/Dog.cpp
        ex01/Brain.cpp)
