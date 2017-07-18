cmake_minimum_required(VERSION 3.7)
project(commandline_videostore_cpp)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(test)

enable_testing()
add_test(MainTest Test)


set(PROJ_SOURCES run.h run.cpp)
add_library(StoreLib ${PROJ_SOURCES})

add_executable(commandline_videostore_cpp main.cpp)
target_link_libraries(commandline_videostore_cpp StoreLib)