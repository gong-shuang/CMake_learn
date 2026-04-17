# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(advanced_find)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Advanced package finding

# Find OpenGL
find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    message(STATUS "OpenGL found: ${OPENGL_VERSION}")
    include_directories(${OPENGL_INCLUDE_DIRS})
endif()

# Find OpenMP
find_package(OpenMP)
if(OpenMP_FOUND)
    message(STATUS "OpenMP found")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# Find Python
find_package(Python3 COMPONENTS Interpreter Development)
if(Python3_FOUND)
    message(STATUS "Python found: ${Python3_VERSION}")
endif()

# Add executable
add_executable(advanced_find_app main.cpp)

# Link libraries
if(OpenGL_FOUND)
    target_link_libraries(advanced_find_app PRIVATE ${OPENGL_LIBRARIES})
    target_compile_definitions(advanced_find_app PRIVATE OPENGL_FOUND=1)  # 添加这行
endif()
if(OpenMP_FOUND)
    target_link_libraries(advanced_find_app PRIVATE OpenMP::OpenMP_CXX)
endif()
