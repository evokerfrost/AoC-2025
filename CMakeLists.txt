cmake_minimum_required(VERSION 4.1)

project(aoc-2025-1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories (src)

add_executable(aoc-2025-1 src/main.cpp src/FileHandler/FileHandler.cpp src/CodeSolver/CodeSolver.cpp)
