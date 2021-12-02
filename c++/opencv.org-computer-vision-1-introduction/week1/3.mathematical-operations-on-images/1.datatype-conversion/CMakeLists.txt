cmake_minimum_required(VERSION 3.20)
project(1_datatype_conversion)

set(CMAKE_CXX_STANDARD 14)
#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(1_datatype_conversion main.cpp)
target_link_libraries(1_datatype_conversion ${OpenCV_LIBS})
