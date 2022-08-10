cmake_minimum_required(VERSION 3.21)
project(hello)

set(CMAKE_CXX_STANDARD 98)

add_executable(hello ex01/ClassContact.cpp ex01/ClassPhoneBook.cpp ex01/ex01.cpp)
