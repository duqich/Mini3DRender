cmake_minimum_required(VERSION 3.21)

project(Mini3DRender)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES main.cpp dqcg/bmpimage.h dqcg/bmpimage.cpp)

add_executable(Mini3DRender ${SOURCES})