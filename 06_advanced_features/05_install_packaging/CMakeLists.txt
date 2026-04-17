# CMake Minimum Required Version
cmake_minimum_required(VERSION 3.10)

# Project Name and Version
project(install_packaging VERSION 1.0.0)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(install_app main.cpp)

# Add include directory
target_include_directories(install_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Install rules
install(TARGETS install_app
    RUNTIME DESTINATION bin
)

# Install header files
install(FILES include/config.h
    DESTINATION include/${PROJECT_NAME}
)

# CPack configuration for packaging
set(CPACK_PACKAGE_NAME "install_packaging")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "CMake Install and Packaging Example")
set(CPACK_PACKAGE_CONTACT "example@example.com")

# Use CPack
include(CPack)
