cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(tests ft_map.h ft_vector.h ft_stack.h ft_list.h ft_queue.h main.cpp)

add_library(testlib INTERFACE)
add_subdirectory(unit_tests)