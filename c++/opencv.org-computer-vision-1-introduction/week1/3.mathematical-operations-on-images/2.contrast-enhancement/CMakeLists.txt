cmake_minimum_required(VERSION 3.20)
project(2_contrast_enhancement)

set(CMAKE_CXX_STANDARD 14)
#find_library(OpenCV)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(2_contrast_enhancement main.cpp)
target_link_libraries(2_contrast_enhancement ${OpenCV_LIBS})
