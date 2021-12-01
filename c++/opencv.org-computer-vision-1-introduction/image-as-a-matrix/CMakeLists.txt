cmake_minimum_required(VERSION 3.20)
project(image-as-a-matrix)

set(CMAKE_CXX_STANDARD 14)

#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(image-as-a-matrix main.cpp)
target_link_libraries(image-as-a-matrix ${OpenCV_LIBS})
