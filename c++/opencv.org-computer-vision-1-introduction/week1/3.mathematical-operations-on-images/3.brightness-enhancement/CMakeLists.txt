cmake_minimum_required(VERSION 3.20)
project(3_brightness_enhancement)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(3_brightness_enhancement main.cpp)
target_link_libraries(3_brightness_enhancement ${OpenCV_LIBS})
