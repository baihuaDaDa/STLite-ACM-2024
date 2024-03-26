cmake_minimum_required(VERSION 3.22)
project(map)

set(CMAKE_CXX_STANDARD 20)

include_directories(data)
include_directories(src)

add_executable(map
        data/two/code.cpp
        data/class-bint.hpp
        data/class-integer.hpp
        data/class-matrix.hpp
        src/exceptions.hpp
        src/map.hpp
        src/utility.hpp)
