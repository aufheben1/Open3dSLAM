cmake_minimum_required(VERSION 3.5)
project(o3s)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -03 -std=c++14")

include_directories(include)

file(GLOB LIB_SOURCES src/*/*.cpp)
add_library(o3s SHARED ${LIB_SOURCES})

# TODO:
# install