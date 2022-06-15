cmake_minimum_required(VERSION 3.22)
project(cpp05)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp05 ex03/main.cpp ex03/Bureaucrat.cpp ex03/Form.cpp
        ex03/ShrubberyCreationForm.cpp ex03/PresidentialPardonForm.cpp
        ex03/RobotomyRequestForm.cpp ex03/Intern.cpp)
