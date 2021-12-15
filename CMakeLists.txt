cmake_minimum_required(VERSION 3.5)

project(myContainer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
include_directories(src)
add_executable(myContainer src/ice.cpp include/ice.h src/print_container.cpp include/print_container.h main.cpp)
