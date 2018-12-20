cmake_minimum_required(VERSION 3.13)
project(stereomatching)

set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(OpenCV 4.0 REQUIRED)
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )



add_executable(stereomatching main.cpp)

TARGET_LINK_LIBRARIES(stereomatching ${OpenCV_LIBS})