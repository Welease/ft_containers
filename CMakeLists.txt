cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_list
        listMain.cpp ft_map.h)
add_executable(ft_vector ft_vector.h vectorMain.cpp)

add_executable(test queueMain.cpp)

add_executable(ft_stack ft_stack.h stackMain.cpp)

add_library(testlib INTERFACE)
add_subdirectory(unit_tests)