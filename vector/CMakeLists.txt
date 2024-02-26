cmake_minimum_required(VERSION 3.22)
project(STLite-vector-ACM-2024)

set(CMAKE_CXX_STANDARD 20)

add_executable(code
        src/vector.hpp
        src/utility.hpp
        src/exceptions.hpp
        data/one/code.cpp)
#cmake_minimum_required(VERSION 3.22)
#project(STLite-vector-ACM-2024)
#
## Set the C++ standard to use
#set(CMAKE_CXX_STANDARD 14)
#
## Function to create an executable for each project
#function(create_project_executable project_dir)
#    file(GLOB_RECURSE src_files ${project_dir}/*.cpp ${project_dir}/*.h)
#    get_filename_component(project_name ${project_dir} NAME)
#    add_executable(${project_name} ${src_files}
#            src/vector.hpp
#            src/utility.hpp
#            src/exceptions.hpp
#            data/class-bint.hpp
#            data/class-integer.hpp
#            data/class-matrix.hpp)
#endfunction()
#
## Iterate through subdirectories and create an executable for each one with a main.cpp file
#file(GLOB children RELATIVE ${CMAKE_SOURCE_DIR}/data ${CMAKE_SOURCE_DIR}/data/*)
#foreach (child ${children})
#    if (IS_DIRECTORY ${CMAKE_SOURCE_DIR}/data/${child})
#        file(GLOB main_cpp_files ${CMAKE_SOURCE_DIR}/data/${child}/code.cpp)
#        if (main_cpp_files)
#            create_project_executable(${CMAKE_SOURCE_DIR}/data/${child})
#        endif ()
#    endif ()
#endforeach ()
