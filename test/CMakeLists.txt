cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(external/googletest)

add_executable(Test test.cpp)

target_include_directories(Test PUBLIC ../include)
target_link_libraries(Test PRIVATE gtest gtest_main)
