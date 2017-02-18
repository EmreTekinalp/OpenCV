cmake_minimum_required(VERSION 2.6)
project(ColorTracking)

# IMPORTANT environmentVariable OPENCV_DIR needs to be set to make this works
set(OPENCV_LOCATION $ENV{OPENCV_DIR})

add_subdirectory(src)
