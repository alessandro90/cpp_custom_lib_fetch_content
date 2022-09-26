cmake_minimum_required(VERSION 3.10.0)
project(test_exercise)
 
set(SOURCES
    src/main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
