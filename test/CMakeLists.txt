include_directories (${CMAKE_SOURCE_DIR})
add_executable (Test singleTest.cpp testMain.cpp)

target_link_libraries(Test StoreLib)

