cmake_minimum_required(VERSION 3.22)
project(cpp04)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp04 ex02/main.cpp ex02/AAnimal.cpp ex02/Cat.cpp ex02/Dog.cpp
        ex02/Brain.cpp)
