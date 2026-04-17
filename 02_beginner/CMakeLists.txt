# CMake Minimum Required Version
# Specifies the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Project Name
# Sets the name of the project
project(beginner_project)

# Set C++ Standard
# Specifies the C++ standard to use (C++11 in this case)
set(CMAKE_CXX_STANDARD 11)
# Ensures the standard is enforced
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Compiler Flags
# Adds compiler flags for better error checking
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Add Executable
# Creates an executable target named "beginner_app" from the source file "main.cpp"
add_executable(beginner_app main.cpp)

# Target Include Directories
# Specifies include directories for the target
# Even though we don't have external includes, this demonstrates the command
# target_include_directories(beginner_app PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Target Compile Options
# Adds specific compile options to the target
# target_compile_options(beginner_app PRIVATE -O2)
