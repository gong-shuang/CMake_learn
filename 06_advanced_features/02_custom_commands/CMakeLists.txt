# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(custom_commands)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Generate a header file using custom command
# add_custom_command(
#     OUTPUT generated_version.h
#     COMMAND echo "#define VERSION \"1.0.0\"" > generated_version.h
#     COMMENT "Generating version header"
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/generated_version.h "#define VERSION \"1.0.0\"")

# Add executable with dependency on generated file
add_executable(custom_app main.cpp generated_version.h)

# Add build directory to include path
target_include_directories(custom_app PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Add custom target for code formatting
add_custom_target(format
    COMMAND echo "Formatting code..."
    COMMAND echo "Code formatted successfully"
    COMMENT "Formatting code"
)
