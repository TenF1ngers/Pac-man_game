#pragma once

#include <iostream>
#include <string>
#include <array>

const int32_t kCellSize = 16;
const float kMultiplier = 3.5;
const float kPacmanMultiplier = 2.4375;
const float kFrameMultiplier = 0.01;
const int32_t kWindowWidth = 1176;
const int32_t kWindowHeight = 1232;
const int32_t kSmoothnessFactor = 800;
const int32_t kMapHeight = 21;
const int32_t kMapWidth = 23;

using Map = std::array<std::string, kMapHeight>;

const Map kMapSketch = {
        "  ###################  ",
        "  #........#........#  ",
        "  #o##.###.#.###.##o#  ",
        "  #.................#  ",
        "  #.##.#.#####.#.##.#  ",
        "  #....#...#...#....#  ",
        "  ####.### # ###.####  ",
        "     #.#   0   #.#     ",
        " #####.# ##=## #.##### ",
        "      .  #123#  .      ",
        " #####.# ##### #.##### ",
        "     #.#       #.#     ",
        "  ####.# ##### #.####  ",
        "  #........#........#  ",
        "  #.##.###.#.###.##.#  ",
        "  #o.#.....P.....#.o#  ",
        "  ##.#.#.#####.#.#.##  ",
        "  #....#...#...#....#  ",
        "  #.######.#.######.#  ",
        "  #.................#  ",
        "  ###################  "
};

const float kSpeedOfPacman = 0.3;
const int32_t kMultiXPacman = 10;
const int32_t kMultiYPacman = 15;
const float kFactorOfInteraction = 1.6;

enum Cell {
  Door, Empty, Energizer, Pellet, Wall
};
