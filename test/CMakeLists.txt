include_directories (${CMAKE_SOURCE_DIR})
add_executable (SingleTest singleTest.cpp testMain.cpp)

target_link_libraries(SingleTest StoreLib)

