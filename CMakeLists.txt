cmake_minimum_required(VERSION 3.22.1)
project(tdx-lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 20)

#set(FLAG "-fmodules-ts")

include_directories(${CMAKE_BINARY_DIR}/lib/imports)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

#if (UNIX)
#    set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")
#endif()

file(GLOB_RECURSE MODELS models/*.cpp )
file(GLOB_RECURSE LIB lib/internal/*.cpp )

add_library(tdx_static SHARED main.cpp ${MODELS} ${LIB})
add_library(tdx STATIC main.cpp ${MODELS} ${LIB})
add_executable(tdxsd main.cpp ${MODELS} ${LIB})
add_executable(tdxsd_tests tests.cpp ${MODELS} ${LIB})
# add_library(tdx MODULE main.cpp)