# CMake Minimum Required Version
# Specifies the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Project Name and Version
# Sets the name of the project and its version
project(advanced_project VERSION 1.0.0)

# Set C++ Standard
# Specifies the C++ standard to use (C++11 in this case)
set(CMAKE_CXX_STANDARD 11)
# Ensures the standard is enforced
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Build Type
# Sets the build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set Compiler Flags
# Adds compiler flags based on build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O2")
endif()

# Define Variables
# Creates variables for better organization
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(BUILD_DIR ${PROJECT_BINARY_DIR})

# Configure File
# Generates a header file from a template with CMake variables
configure_file(
    ${INCLUDE_DIR}/config/config.h.in
    ${BUILD_DIR}/include/config/config.h
)

# Include Directories
# Adds include directories for the entire project
include_directories(
    ${INCLUDE_DIR}
    ${BUILD_DIR}/include
)

# Add Library
# Creates a static library named "core" from the source files
add_library(core STATIC
    ${SRC_DIR}/core/greeter.cpp
)

# Library Include Directories
# Specifies include directories for the library
target_include_directories(core PUBLIC
    ${INCLUDE_DIR}
    ${BUILD_DIR}/include
)

# Add Executable
# Creates an executable target named "advanced_app" from the source file "main.cpp"
add_executable(advanced_app ${SRC_DIR}/main.cpp)

# Target Include Directories
# Specifies include directories for the executable
target_include_directories(advanced_app PRIVATE
    ${INCLUDE_DIR}
    ${BUILD_DIR}/include
)

# Link Libraries
# Links the library to the executable
target_link_libraries(advanced_app PRIVATE core)

# Install Targets
# Specifies installation rules for the executable
install(TARGETS advanced_app
    RUNTIME DESTINATION bin
)

# Install Library
# Specifies installation rules for the library
install(TARGETS core
    ARCHIVE DESTINATION lib
)

# Install Headers
# Specifies installation rules for the header files
install(DIRECTORY ${INCLUDE_DIR}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# Add Custom Target
# Creates a custom target for printing build information
add_custom_target(print_info
    COMMAND echo "Project: ${PROJECT_NAME}"
    COMMAND echo "Version: ${PROJECT_VERSION}"
    COMMAND echo "Build Type: ${CMAKE_BUILD_TYPE}"
    COMMAND echo "Compiler: ${CMAKE_CXX_COMPILER_ID}"
)
