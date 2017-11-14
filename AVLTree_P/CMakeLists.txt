cmake_minimum_required(VERSION 3.5.2)
project(AVLTree_P)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AVLTree.hpp)
add_executable(AVLTree_P ${SOURCE_FILES})