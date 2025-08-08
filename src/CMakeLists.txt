cmake_minimum_required(VERSION 3.31)
project(LibSimpFighter)

set(CMAKE_CXX_STANDARD 23)

add_library(LibSimpFighter
        SimpFighter.cpp

        Players/IPlayer.hpp
        Players/Actions.hpp
        Players/PhysicalPlayer.cpp

        Model/GameState.cpp
        Model/Vector.cpp

        Entities/Entity.cpp
        Entities/Character.cpp
        Entities/Projectile.cpp
)

target_link_libraries(LibSimpFighter PUBLIC
        EngineBase Utility)
target_include_directories(LibSimpFighter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})