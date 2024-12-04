cmake_minimum_required(VERSION 3.27)
project(Project_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project_3 main.cpp
        AdjacencyList.cpp
        AdjacencyList.h
        AdjacencyMatrix.cpp
        AdjacencyMatrix.h)
