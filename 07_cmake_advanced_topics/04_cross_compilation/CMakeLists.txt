# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(cross_compilation)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Platform-specific configurations
if(WIN32)
    message(STATUS "Building for Windows")
    add_definitions(-DWINDOWS)
elseif(UNIX)
    if(APPLE)
        message(STATUS "Building for macOS")
        add_definitions(-DMACOS)
    else()
        message(STATUS "Building for Linux")
        add_definitions(-DLINUX)
    endif()
elseif(ANDROID)
    message(STATUS "Building for Android")
    add_definitions(-DANDROID)
elseif(IOS)
    message(STATUS "Building for iOS")
    add_definitions(-DIOS)
else()
    message(STATUS "Building for unknown platform")
endif()

# Cross-compilation example
if(CMAKE_CROSSCOMPILING)
    message(STATUS "Cross-compiling for ${CMAKE_SYSTEM_NAME}")
endif()

# Add executable
add_executable(cross_compile_app main.cpp)

# Platform-specific linking
if(WIN32)
    target_link_libraries(cross_compile_app PRIVATE ws2_32)
elseif(UNIX AND NOT APPLE)
    target_link_libraries(cross_compile_app PRIVATE pthread)
endif()
