# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(testing_coverage)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Add library
add_library(mylib src/mylib.cpp)

# Add executable
add_executable(test_app src/main.cpp)
target_link_libraries(test_app PRIVATE mylib)

# Add test
add_test(NAME MyTest COMMAND test_app)

# Enable coverage (if supported)
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()
