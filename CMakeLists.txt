cmake_minimum_required(VERSION 3.31)
project(SimpFighter)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(SimpFighter main.cpp)
include(FetchContent)

FetchContent_Declare(
        EngineBase
        GIT_REPOSITORY https://github.com/ThePhoneBeLinging/EngineBase
        GIT_TAG v4.2.4
)
FetchContent_MakeAvailable(EngineBase)


FetchContent_Declare(
        Utility
        GIT_REPOSITORY https://github.com/ThePhoneBeLinging/Utility
        GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(Utility)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory(src)

target_link_libraries(SimpFighter PUBLIC LibSimpFighter)
target_link_libraries(SimpFighter PUBLIC EngineBase)
target_link_libraries(SimpFighter PUBLIC Utility)
target_link_libraries(SimpFighter PUBLIC nlohmann_json)
