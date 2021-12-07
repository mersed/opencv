cmake_minimum_required(VERSION 3.20)
project(4_pitfalls_of_using_uint8)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(4_pitfalls_of_using_uint8 main.cpp)
target_link_libraries(4_pitfalls_of_using_uint8 ${OpenCV_LIBS})
