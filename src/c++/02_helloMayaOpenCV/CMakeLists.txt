cmake_minimum_required(VERSION 2.6)
project(HelloMayaOpenCV)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/module)
set(OPENCV_LOCATION $ENV{OPENCV_DIR})

add_subdirectory(src)