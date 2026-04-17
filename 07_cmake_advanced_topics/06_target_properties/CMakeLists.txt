# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(target_properties)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add library
add_library(mylib src/mylib.cpp)

# Set library properties
set_target_properties(mylib PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
    PUBLIC_HEADER include/mylib.h
    OUTPUT_NAME "mylib"
)

# Add executable
add_executable(target_properties_app main.cpp)

# Set executable properties
set_target_properties(target_properties_app PROPERTIES
    OUTPUT_NAME "properties_app"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

# Set compiler options for specific targets
target_compile_options(mylib PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_compile_options(target_properties_app PRIVATE
    -O2
)

# Set include directories
target_include_directories(mylib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(target_properties_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link libraries
target_link_libraries(target_properties_app PRIVATE mylib)
