cmake_minimum_required(VERSION 3.8)
project(math)

add_library(math INTERFACE)
target_include_directories(math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
