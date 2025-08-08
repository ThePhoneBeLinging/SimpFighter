cmake_minimum_required(VERSION 3.31)
project(SimpFighter)

set(CMAKE_CXX_STANDARD 23)

add_executable(SimpFighter main.cpp)
include(FetchContent)

FetchContent_Declare(
        EngineBase
        GIT_REPOSITORY https://github.com/ThePhoneBeLinging/EngineBase
        GIT_TAG v4.2.2
)
FetchContent_MakeAvailable(EngineBase)

add_subdirectory(src)

target_link_libraries(SimpFighter PUBLIC LibSimpFighter)
target_link_libraries(SimpFighter PUBLIC EngineBase)
