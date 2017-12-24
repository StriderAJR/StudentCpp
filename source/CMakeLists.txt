cmake_minimum_required(VERSION 3.6)
project(source)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Basics_06.2_ReferenceParam.h)
add_executable(source ${SOURCE_FILES})