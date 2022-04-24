cmake_minimum_required(VERSION 3.22)
project(data_proj_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_proj_cpp main.cpp employee.cpp employee.h register_context.cpp register_context.h)
