# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(build_configs)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add multiple build targets

# Debug build
add_executable(debug_app main.cpp)
target_compile_definitions(debug_app PRIVATE DEBUG=1 CONFIG="Debug")
target_compile_options(debug_app PRIVATE -g -O0)

add_executable(release_app main.cpp)
target_compile_definitions(release_app PRIVATE CONFIG="Release")
target_compile_options(release_app PRIVATE -O3)

# Add custom configuration
add_executable(optimized_app main.cpp)
target_compile_definitions(optimized_app PRIVATE CONFIG="Optimized")
target_compile_options(optimized_app PRIVATE -O2 -march=native)

