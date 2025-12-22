cmake_minimum_required(VERSION 4.1)

project(aoc-2025-5 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories (src)

add_executable(aoc-2025-5 src/main.cpp src/FileHandler/FileHandler.cpp src/Cafeteria/Cafeteria.cpp)
