cmake_minimum_required(VERSION 3.7)
project(commandline_videostore_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(test)

enable_testing()
add_test(MainTest SingleTest)


set(PROJ_SOURCES run.h run.cpp Rental.cpp Rental.h Movie.h MovieRepository.cpp MovieRepository.h SplitString.h)
add_library(StoreLib ${PROJ_SOURCES})

add_executable(commandline_videostore_cpp main.cpp)
target_link_libraries(commandline_videostore_cpp StoreLib)