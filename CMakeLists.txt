cmake_minimum_required(VERSION 3.14)
project(lab2_Jail)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

add_executable(
    jail
    jail.cpp
    strategy_class.cpp
    jail.hpp
)