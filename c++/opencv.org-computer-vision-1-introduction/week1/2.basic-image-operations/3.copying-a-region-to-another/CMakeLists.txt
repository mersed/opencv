cmake_minimum_required(VERSION 3.20)
project(3_copying_a_region_to_another)

set(CMAKE_CXX_STANDARD 14)

#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(3_copying_a_region_to_another main.cpp)
target_link_libraries(3_copying_a_region_to_another ${OpenCV_LIBS})
