cmake_minimum_required(VERSION 3.20)
project(2_cropping_an_image_section)

set(CMAKE_CXX_STANDARD 14)

#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(2_cropping_an_image_section main.cpp)
target_link_libraries(2_cropping_an_image_section ${OpenCV_LIBS})
