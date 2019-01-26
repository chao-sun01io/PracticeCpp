cmake_minimum_required(VERSION 2.8)
project(AdvancedCpp)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

add_executable(callback_ex callback_function/callback_function_example.cpp)
add_executable(lambda_ex lambda/lambda_example.cpp)
add_executable(inherit_singleton_ex singleton/inherit_singleton_example.cpp)
