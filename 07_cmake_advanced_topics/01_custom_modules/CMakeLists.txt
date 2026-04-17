# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(custom_modules)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add custom module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Include custom module
include(MyCustomModule)

# Add executable
add_executable(custom_modules_app main.cpp)

# Use custom function from module
custom_function()
my_custom_function("Hello from custom module!")
my_custom_macro(CUSTOM_VAR "11111111!")
