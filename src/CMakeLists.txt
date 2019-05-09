set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# SDL Library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Gather library sources and headers
FILE(GLOB ASTEROIDS_HEADERS ${SRC_DIR}/*.h)
FILE(GLOB ASTEROIDS_SOURCES ${SRC_DIR}/*.cpp)
LIST(REMOVE_ITEM ASTEROIDS_SOURCES ${SRC_DIR}/main.cpp) # Remove main.cpp

#Add library
add_library(lib-asteroids ${ASTEROIDS_SOURCES} ${ASTEROIDS_HEADERS})

# Executable
add_executable(asteroids WIN32 ${SRC_DIR}/main.cpp)

# Link dependencies
target_link_libraries(asteroids lib-asteroids)
target_link_libraries(asteroids ${SDL2_LIBRARIES})