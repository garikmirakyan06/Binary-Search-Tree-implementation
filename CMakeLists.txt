cmake_minimum_required(VERSION 3.10)

project(BST)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(source)
add_subdirectory(test)


