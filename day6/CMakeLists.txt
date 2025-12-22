# Advent of Code CMakeFiles
cmake_minimum_required(VERSION 4.1)

project(aoc-2025-6 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
#set(CMAKE_BUILD_TYPE Debug)

include_directories (src)

add_executable(aoc-2025-6 src/main.cpp src/FileHandler/FileHandler.cpp src/TrashCompactor/TrashCompactor.cpp)
