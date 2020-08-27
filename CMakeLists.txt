cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(Tutorial)

include_directories(./include)

add_subdirectory(./chapiter1)

add_executable(Tutorial main.cpp)