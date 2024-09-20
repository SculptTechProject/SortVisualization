cmake_minimum_required(VERSION 3.5)

project(SortingVisualization)

set(CMAKE_CXX_STANDARD 11)

# Include raylib
find_package(raylib REQUIRED)

add_executable(SortingVisualization main.cpp)

# Link raylib
target_link_libraries(SortingVisualization raylib)