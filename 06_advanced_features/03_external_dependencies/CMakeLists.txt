# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(external_dependencies)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Try to find Boost library (example of external dependency)
find_package(Boost COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    message(STATUS "Boost found: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(WARNING "Boost not found, using stub implementation")
endif()

# Add executable
add_executable(external_app main.cpp)

# Link against Boost if found
if(Boost_FOUND)
    target_link_libraries(external_app PRIVATE ${Boost_LIBRARIES})
endif()
