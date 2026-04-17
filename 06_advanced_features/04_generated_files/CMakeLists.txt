# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(generated_files)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
