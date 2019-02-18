cmake_minimum_required(VERSION 3.1)

project(datastruct_demo)

set(CMAKE_CXX_STANDARD 11)

FILE(GLOB HEADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/../header/*/*.h")
FILE(GLOB SOURCE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/../src/*/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../header/graph)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../header/sort)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../header/tree)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../header/string)

add_executable(datastruct_demo ${SOURCE_LIST} ../entrance.cpp)

