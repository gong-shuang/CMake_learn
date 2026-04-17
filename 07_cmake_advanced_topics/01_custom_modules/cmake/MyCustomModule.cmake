# Custom CMake module

function(custom_function)
  message(STATUS "This is a custom function!")
endfunction()

# Custom function
function(my_custom_function message)
    message(STATUS "Custom Module: ${message}")
endfunction()

# Custom macro
macro(my_custom_macro name value)
    set(${name} "${value}" CACHE STRING "Custom macro variable")
    message(STATUS "Set ${name} to ${value}")
endmacro()

# Function to check compiler features
function(check_compiler_features)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(STATUS "GCC compiler detected")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(STATUS "Clang compiler detected")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        message(STATUS "MSVC compiler detected")
    else()
        message(STATUS "Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
    endif()
endfunction()

# Call the compiler check
check_compiler_features()
