cmake_minimum_required(VERSION 3.7)

project(asteroids CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Project Sources
add_subdirectory(src)

# Tests
enable_testing()
add_subdirectory(tests)