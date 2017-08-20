cmake_minimum_required(VERSION 3.9)
project(Property)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp PropertyClass.h)
add_executable(Property ${SOURCE_FILES})