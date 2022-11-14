cmake_minimum_required(VERSION 3.20)
project(Pac-man)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(Pac-man
        Main.cpp
        src/Blinky.cpp
        src/BlinkyCreator.cpp
        src/Clyde.cpp
        src/ClydeCreator.cpp
        src/ConvertSketch.cpp
        src/GameProcess.cpp
        src/DrawMap.cpp
        src/DrawGameText.cpp
        src/Inky.cpp
        src/InkyCreator.cpp
        src/Menu.cpp
        src/Pacman.cpp
        src/PacmanCreator.cpp
        src/Pinky.cpp
        src/PinkyCreator.cpp
        src/RestartGame.cpp
        )

include_directories(Headers)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Pac-man sfml-system sfml-window sfml-graphics sfml-audio sfml-network)