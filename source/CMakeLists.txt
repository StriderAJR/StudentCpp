cmake_minimum_required(VERSION 3.6)
project(source)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(source ${SOURCE_FILES})

set(CMAKE_EXE_LINKER_FLAGS  "-static")