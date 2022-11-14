#pragma once

#include <memory>

#include <../Headers/BlinkyCreator.h>
#include <../Headers/CharactersManager.h>
#include <../Headers/ClydeCreator.h>
#include <../Headers/InkyCreator.h>
#include <../Headers/PacmanCreator.h>
#include <../Headers/PinkyCreator.h>

class ListOfCreators {
 public:
  PacmanCreator* pacman_create;
  BlinkyCreator* blinky_create;
  PinkyCreator* pinky_create;
  InkyCreator* inky_create;
  ClydeCreator* clyde_create;

  ListOfCreators() : pacman_create(new PacmanCreator), blinky_create(new BlinkyCreator), pinky_create(new PinkyCreator),
                             inky_create(new InkyCreator), clyde_create(new ClydeCreator) {
  }

  ~ListOfCreators() = default;
};