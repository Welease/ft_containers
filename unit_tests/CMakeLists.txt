cmake_minimum_required(VERSION 3.17)
project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_FILES list.cpp queue.cpp stack.cpp vector.cpp
        map.cpp)

add_executable(Google_Tests_run ${TEST_FILES})

target_link_libraries(Google_Tests_run gtest gtest_main testlib)