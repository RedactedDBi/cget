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
include_directories(${CMAKE_SOURCE_DIR}/src/)
set(SOURCE_FILES
        src/cget.h
        src/constants.h
        src/inputparser.h src/inputparser.cpp
        src/commandfactory.h src/commandfactory.cpp
        src/command/command.h src/command/command.cpp
        src/command/install.h src/command/install.cpp
        src/command/init.h src/command/init.cpp
        src/registry_api/registry.h
        src/registry_api/localregistry.h src/registry_api/localregistry.cpp src/dependency_resolution/dr.h src/dependency_resolution/dependencystorage.h src/dependency_resolution/packagefile.h src/dependency_resolution/dependencystorage.cpp src/dependency_resolution/packagefolder.h src/dependency_resolution/resolver.h src/dependency_resolution/socketfactory.h src/dependency_resolution/defaultsocketfactory.h src/dependency_resolution/defaultsocketfactory.cpp src/dependency_resolution/resolver.cpp src/network/socket.h src/arch/unix/bsdsocket.h src/arch/unix/bsdsocket.cpp)

add_library(cget-core STATIC ${SOURCE_FILES})

# The main executable will only contain the main.cpp, and will
# statically link to the main library
add_executable(cget main.cpp)
target_link_libraries(cget cget-core)

# External libraries
include_directories(${CMAKE_SOURCE_DIR}/lib/json-develop/src)

# Add test project
add_subdirectory(${CMAKE_SOURCE_DIR}/test)

# Generate installation rules
install(TARGETS cget RUNTIME DESTINATION bin)