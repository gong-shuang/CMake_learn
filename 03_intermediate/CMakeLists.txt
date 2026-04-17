# CMake Minimum Required Version
# Specifies the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Project Name
# Sets the name of the project
project(intermediate_project)

# Set C++ Standard
# Specifies the C++ standard to use (C++11 in this case)
set(CMAKE_CXX_STANDARD 11)
# Ensures the standard is enforced
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Compiler Flags
# Adds compiler flags for better error checking
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Define Variables
# Creates variables for better organization
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Add Library
# Creates a static library named "greeter" from the source files
add_library(greeter STATIC
    ${SRC_DIR}/greeter.cpp
)

# Library Include Directories
# Specifies include directories for the library
target_include_directories(greeter PUBLIC ${INCLUDE_DIR})

# Add Executable
# Creates an executable target named "intermediate_app" from the source file "main.cpp"
add_executable(intermediate_app ${SRC_DIR}/main.cpp)

# Target Include Directories
# Specifies include directories for the executable
target_include_directories(intermediate_app PRIVATE ${INCLUDE_DIR})

# Link Libraries
# Links the library to the executable
target_link_libraries(intermediate_app PRIVATE greeter)
