cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0076 NEW)
project(PracticeCpp VERSION 0.0.1)

set(CMAKE_CXX_FLAGS "-std=c++17")

Include(FetchContent)
# Catch2 Unitestt Framework
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

enable_testing()
include(CTest)
include(Catch)

add_subdirectory(singleton)
add_subdirectory(chrono_timer)
add_subdirectory(pimpl)
add_subdirectory(test)
add_executable(callback_ex callback_function/callback_function_example.cpp)
add_executable(callback_bind_class_func_ex callback_function/callback_bind_class_member_function.cpp)
add_executable(lambda_ex lambda/lambda_example.cpp)