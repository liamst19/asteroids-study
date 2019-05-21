cmake_minimum_required(VERSION 3.7)
project(asteroids CXX)

# Toggle compilation of test framework (cmake .. -Dadd_test=ON)
option(add_test "add test" OFF)

# Create .exe file in the directory where cmake --build is executed
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Project Sources
add_subdirectory(src)

# Project Tests
if(add_test)
    enable_testing()
    add_subdirectory(tests)
endif()