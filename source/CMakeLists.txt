cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(BST main.cpp)

target_include_directories(BST PUBLIC ../include)

