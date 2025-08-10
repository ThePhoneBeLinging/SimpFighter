cmake_minimum_required(VERSION 3.31)
project(LibSimpFighter)

set(CMAKE_CXX_STANDARD 23)

add_library(LibSimpFighter
        SimpFighter.cpp

        Util/LevelCreator.cpp
        Util/CollisionController.cpp

        Players/IPlayer.hpp
        Players/Actions.hpp
        Players/PhysicalPlayer.cpp

        Model/GameState.cpp
        Model/Vector.cpp

        Entities/Entity.cpp
        Entities/Character.cpp
        Entities/Projectile.cpp
        Entities/Wall.cpp
        Players/SimpAI.cpp
        Players/SimpAI.hpp
        Util/MultiplayerUtil.cpp
        Util/MultiplayerUtil.hpp
)

target_link_libraries(LibSimpFighter PUBLIC
        EngineBase Utility nlohmann_json)
target_include_directories(LibSimpFighter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})