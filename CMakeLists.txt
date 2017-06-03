
cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(PACKAGE_NAME "cpp-training")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

project(${PACKAGE_NAME})

add_subdirectory(src/boost)
add_subdirectory(src/cpp)
