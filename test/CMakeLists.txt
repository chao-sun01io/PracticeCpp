add_executable(test_unique_ptr "test_unique_ptr.cpp")
target_include_directories(test_unique_ptr PRIVATE "${CMAKE_SOURCE_DIR}")

add_executable(test_segment_tree "test_segment_tree.cpp")
target_include_directories(test_segment_tree PRIVATE "${CMAKE_SOURCE_DIR}")
target_link_libraries(test_segment_tree PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
set_property(TARGET test_segment_tree PROPERTY CXX_STANDARD 17)
catch_discover_tests(test_segment_tree)