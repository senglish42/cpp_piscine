cmake_minimum_required(VERSION 3.22)
project(cpp03)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp03 ex01/main.cpp ex01/ClapTrap.cpp ex01/ClapTrap.hpp
                ex01/ScavTrap.cpp ex01/ScavTrap.hpp)
