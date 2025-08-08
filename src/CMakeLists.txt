cmake_minimum_required(VERSION 3.31)
project(LibSimpFighter)

set(CMAKE_CXX_STANDARD 23)

add_library(LibSimpFighter
        SimpFighter.cpp
)

target_link_libraries(LibSimpFighter PUBLIC EngineBase)
