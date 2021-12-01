cmake_minimum_required(VERSION 3.20)
project(5_creating_an_image_mask)

set(CMAKE_CXX_STANDARD 14)
#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(5_creating_an_image_mask main.cpp)
target_link_libraries(5_creating_an_image_mask ${OpenCV_LIBS})
