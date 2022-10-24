cmake_minimum_required(VERSION 3.20)
project(hot100)

set(CMAKE_CXX_STANDARD 14)
include_directories(./daily ./useful . ./sorts ./others)
add_executable(hot100 main.cpp)


add_executable(treeShortestPath acmMode/treeShortestPath.cpp)