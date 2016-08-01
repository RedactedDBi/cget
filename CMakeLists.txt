cmake_minimum_required(VERSION 3.3)

project(cget)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# This will do for now, but we could probably set up some nice parsing
# with git-describe or similar further down the road
set(cget_MAJOR 0)
set(cget_MINOR 0)
set(cget_PATCH 1)

configure_file (
        "${PROJECT_SOURCE_DIR}/VERSION.h.in"
        "${PROJECT_BINARY_DIR}/VERSION.h"
)

include_directories("${PROJECT_BINARY_DIR}")

# Main library for cget
include_directories(${CMAKE_SOURCE_DIR}/include/)
set(SOURCE_FILES
        include/cget.h
        include/inputparser.h src/inputparser.cpp
        include/commandfactory.h src/commandfactory.cpp
        include/command/command.h src/command/command.cpp
        include/command/install.h src/command/install.cpp)

add_library(cget-core STATIC ${SOURCE_FILES})

# The main executable will only contain the main.cpp, and will
# statically link to the main library
add_executable(cget main.cpp)
target_link_libraries(cget cget-core)

# Add test project
add_subdirectory(${CMAKE_SOURCE_DIR}/test)

# Generate installation rules
install(TARGETS cget RUNTIME DESTINATION bin)