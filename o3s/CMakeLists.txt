cmake_minimum_required(VERSION 3.5)
project(o3s)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -std=c++14")

include_directories(include)

file(GLOB SOURCES src/*/*.cpp)
file(GLOB HEADERS include/*/*.hpp)

if (${MSVC})
	add_library(o3s SHARED ${SOURCES} ${HEADERS})
else()
	add_library(o3s SHARED ${SOURCES})
endif(${MSVC})

# TODO:
# install
