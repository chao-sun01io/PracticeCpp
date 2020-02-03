cmake_minimum_required(VERSION 2.8)
project(PracticeCpp)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(singleton)
add_subdirectory(chrono_timer)
add_subdirectory(pimpl)
add_executable(callback_ex callback_function/callback_function_example.cpp)
add_executable(callback_bind_class_func_ex callback_function/callback_bind_class_member_function.cpp)
add_executable(lambda_ex lambda/lambda_example.cpp)

