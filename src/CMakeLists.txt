set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# -----------------------------------------------------
# SDL Library

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

find_library(SDL2TTF_LIBRARIES SDL_ttf)
find_library(SDL2IMAGE_LIBRARIES SDL_image)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# -----------------------------------------------------
# Library

# Gather library headers
FILE(GLOB ASTEROIDS_HEADERS 
     ${SRC_DIR}/*.h
     ${SRC_DIR}/medialayer/*.h
     ${SRC_DIR}/gameobjects/*.h
     ${SRC_DIR}/components/*.h
     )
# Gather library sources
FILE(GLOB ASTEROIDS_SOURCES
     ${SRC_DIR}/*.cpp
     ${SRC_DIR}/medialayer/*.cpp
     ${SRC_DIR}/gameobjects/*.cpp
     ${SRC_DIR}/components/*.cpp
     )
LIST(REMOVE_ITEM ASTEROIDS_SOURCES ${SRC_DIR}/main.cpp) # Remove main.cpp

#Add library
add_library(lib-asteroids ${ASTEROIDS_SOURCES} ${ASTEROIDS_HEADERS})

# -----------------------------------------------------
# Executable

add_executable(asteroids WIN32 ${SRC_DIR}/main.cpp)

# Link dependencies to executable
target_link_libraries(asteroids lib-asteroids)
target_link_libraries(asteroids ${SDL2_LIBRARIES})
target_link_libraries(asteroids ${SDL2_TTF_LIBRARIES})
target_link_libraries(asteroids ${SDL2_IMAGE_LIBRARIES})