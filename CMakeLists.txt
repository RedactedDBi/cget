cmake_minimum_required(VERSION 3.3)
project(cget)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Main library for cget
include_directories(${CMAKE_SOURCE_DIR}/include/)
set(SOURCE_FILES src/temp.cpp)
add_library(cget-core STATIC ${SOURCE_FILES})

# The main executable will only contain the main.cpp, and will
# statically link to the main library
add_executable(cget main.cpp)

# Add test project
add_subdirectory(${CMAKE_SOURCE_DIR}/test)

# Generate installation rules
install(TARGETS cget RUNTIME DESTINATION bin)