cmake_minimum_required(VERSION 3.22.1)
project(tdx-lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_MODULE_PATH "~/Dev/CppLibraries/json/;")

#set(nlohmann_json_DIR ~/Dev/CppLibraries/json/)

#find_package(nlohmann_json 3.2.0 REQUIRED)
#add_library(nlohmann_json_lib ...)
#target_link_libraries(nlohmann_json_lib PRIVATE nlohmann_json::nlohmann_json)

#add_subdirectory(${CMAKE_BINARY_DIR}/lib/imports/json)

include_directories(${CMAKE_BINARY_DIR}/lib/imports)
# set(CMAKE_LIBRARY_PATH ${CMAKE_BINARY_DIR}/lib/imports)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

add_library(tdx SHARED main.cpp)
# add_library(tdx MODULE main.cpp)