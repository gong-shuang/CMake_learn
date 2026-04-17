# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(conditional_compilation)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Option for conditional compilation
option(USE_FEATURE_X "Use Feature X" ON)
option(USE_FEATURE_Y "Use Feature Y" OFF)

# Add executable
add_executable(conditional_app main.cpp)

# Conditional compilation based on options
if(USE_FEATURE_X)
    target_compile_definitions(conditional_app PRIVATE USE_FEATURE_X)
    message(STATUS "Feature X is enabled")
else()
    message(STATUS "Feature X is disabled")
endif()

if(USE_FEATURE_Y)
    target_compile_definitions(conditional_app PRIVATE USE_FEATURE_Y)
    message(STATUS "Feature Y is enabled")
else()
    message(STATUS "Feature Y is disabled")
endif()
