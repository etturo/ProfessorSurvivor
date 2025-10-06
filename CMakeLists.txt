cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/Entities/Player.cpp
        includes/Entities/Player.h
        src/Core/Entity.cpp
        includes/Core/Entity.h
        src/Entities/Enemy.cpp
        includes/Entities/Enemy.h
        src/Core/Application.cpp
        includes/Core/Application.h
        src/GUI/FPSCounter.cpp
        includes/GUI/FPSCounter.h
        src/GUI/GameTimer.cpp
        includes/GUI/GameTimer.h)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
