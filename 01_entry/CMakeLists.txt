# CMake Minimum Required Version
# Specifies the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Project Name
# Sets the name of the project
project(entry_project)

# Set C++ Standard
# Specifies the C++ standard to use (C++11 in this case)
set(CMAKE_CXX_STANDARD 11)
# Ensures the standard is enforced
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Executable
# Creates an executable target named "entry_app" from the source file "main.cpp"
add_executable(entry_app main.cpp)
