cmake_minimum_required(VERSION 3.17)

project(graph_plotter)

set(CMAKE_CXX_STANDARD 20)

add_executable(graph_plotter main.cpp)

target_link_libraries(graph_plotter -lOpenGL32 -lfreeGLUT)
