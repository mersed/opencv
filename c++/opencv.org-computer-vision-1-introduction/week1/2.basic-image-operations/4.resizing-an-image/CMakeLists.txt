cmake_minimum_required(VERSION 3.20)
project(4_resizing_an_image)

set(CMAKE_CXX_STANDARD 14)
#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(4_resizing_an_image main.cpp)
target_link_libraries(4_resizing_an_image ${OpenCV_LIBS})
