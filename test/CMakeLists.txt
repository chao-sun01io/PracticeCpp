add_executable(test_unique_ptr "test_unique_ptr.cpp")
target_include_directories(test_unique_ptr PRIVATE "${CMAKE_SOURCE_DIR}")

add_executable(all_catch2_tests
    "test_segment_tree.cpp"
    "test_disjoint_set.cpp"
    "test_sort.cpp")
target_include_directories(all_catch2_tests PRIVATE "${CMAKE_SOURCE_DIR}")
target_link_libraries(all_catch2_tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
set_property(TARGET all_catch2_tests PROPERTY CXX_STANDARD 17)
catch_discover_tests(all_catch2_tests)