cmake_minimum_required(VERSION 3.21)

project(Mini3DRender)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES main.cpp dqcg/bmpimage.h dqcg/bmpimage.cpp geometry.h model.h)

add_executable(Mini3DRender ${SOURCES})
add_executable(test_geometry test_geometry.cpp geometry.h )
add_executable(test_model test_model.cpp geometry.h model.h dqcg/bmpimage.h dqcg/bmpimage.cpp)