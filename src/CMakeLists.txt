cmake_minimum_required(VERSION 3.31)
project(LibSimpFighter)

set(CMAKE_CXX_STANDARD 23)

add_library(LibSimpFighter
        SimpFighter.cpp
        Players/IPlayer.hpp
        Players/Actions.hpp
        GameState.cpp
        Players/PhysicalPlayer.cpp
        Entities/Entity.cpp
        Entities/Character.cpp
)

target_link_libraries(LibSimpFighter PUBLIC EngineBase)
