cmake_minimum_required(VERSION 3.20)
project(images_with_alpha_channel)

set(CMAKE_CXX_STANDARD 14)

#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(images_with_alpha_channel main.cpp)
target_link_libraries(images_with_alpha_channel ${OpenCV_LIBS})
