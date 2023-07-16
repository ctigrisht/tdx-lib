cmake_minimum_required(VERSION 3.22.1)
project(tdx-lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_BINARY_DIR}/lib/imports)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

add_library(tdx SHARED main.cpp)
# add_library(tdx MODULE main.cpp)