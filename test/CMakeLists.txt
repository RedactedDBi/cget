cmake_minimum_required(VERSION 3.3)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest-1.7.0/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
message(STATUS ${gtest_BINARY_DIR})
add_executable(tests inputparsertests.cpp tests.cpp initmodeltests.cpp)

target_link_libraries(tests gtest gtest_main)
target_link_libraries(tests cget-core)
