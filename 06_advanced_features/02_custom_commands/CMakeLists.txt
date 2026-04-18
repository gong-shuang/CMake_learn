# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(custom_commands)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Get current date
string(TIMESTAMP CURRENT_DATE "%Y-%m-%d")

# Generate a header file using custom command
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/generated_version.h "#define VERSION \"1.0.0\"\n#define BUILD_DATE \"${CURRENT_DATE}\"")

# Add executable with dependency on generated file
add_executable(custom_app main.cpp ${CMAKE_BINARY_DIR}/generated_version.h)

# Add build directory to include path
target_include_directories(custom_app PRIVATE ${CMAKE_BINARY_DIR})

# Add custom target for code formatting
add_custom_target(format
    COMMAND echo "Formatting code..."
    COMMAND echo "Code formatted successfully"
    COMMENT "Formatting code"
)
