cmake_minimum_required(VERSION 3.22)

project(STLite-vector-ACM-2024)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(vector)

add_subdirectory(map)

add_subdirectory(priority_queue)