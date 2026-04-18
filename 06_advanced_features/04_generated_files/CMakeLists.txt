# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(generated_files)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

# 也可以在使用cmake命令的时候，设置变量，如下：
# cmake -DCMAKE_BUILD_TYPE=Release

# Generate source code from template
configure_file(
    config.h.in
    ${CMAKE_BINARY_DIR}/config.h
    @ONLY
)

# Add executable
add_executable(generated_app main.cpp)

# Include generated header
target_include_directories(generated_app PRIVATE ${CMAKE_BINARY_DIR})
