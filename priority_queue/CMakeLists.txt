cmake_minimum_required(VERSION 3.22)
project(STLite-priority_queue-ACM-2024)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(src)

add_executable(code
        data/one/code.cpp
        src/exceptions.hpp
        src/priority_queue.hpp
        src/utility.hpp)
