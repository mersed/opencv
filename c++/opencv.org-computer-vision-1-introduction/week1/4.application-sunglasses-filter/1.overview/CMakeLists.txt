cmake_minimum_required(VERSION 3.20)
project(1_overview)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(1_overview main.cpp)
target_link_libraries(1_overview ${OpenCV_LIBS})
