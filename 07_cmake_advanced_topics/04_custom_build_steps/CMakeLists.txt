# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(custom_build_steps)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Get current date
string(TIMESTAMP CURRENT_DATE "%Y-%m-%d")

# Generate a version file
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/version.h "#define VERSION \"1.0.0\"\n#define BUILD_DATE \"${CURRENT_DATE}\"")

# Add executable
add_executable(custom_build_app main.cpp)

# Add build directory to include path
target_include_directories(custom_build_app PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Add custom target for documentation
add_custom_target(documentation
    COMMAND echo "Generating documentation..."
    COMMAND echo "Documentation generated successfully"
    COMMENT "Generating documentation"
)

# Add custom target for cleaning
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMENT "Cleaning all build files"
)

# Add custom target that depends on other targets
add_custom_target(build_and_doc
    DEPENDS custom_build_app documentation
    COMMENT "Building app and documentation"
)
