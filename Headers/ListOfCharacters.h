#pragma once

#include <memory>

#include <../Headers/CharactersManager.h>
#include <../Headers/ListOfCreators.h>

class ListOfCharacters {
 public:
  Pacman* pacman;
  Blinky* blinky;
  Pinky* pinky;
  Inky* inky;
  Clyde* clyde;

  explicit ListOfCharacters(ListOfCreators& creators) :
              pacman(creators.pacman_create->CharactersManager()), blinky(creators.blinky_create->CharactersManager()), pinky(creators.pinky_create->CharactersManager()),
              inky(creators.inky_create->CharactersManager()), clyde(creators.clyde_create->CharactersManager()) {
  }

  void Update(Map& map, double& current_frame, double& time) {
    pacman->Update(map, current_frame, time);
    blinky->Update(map, current_frame, time);
    pinky->Update(map, current_frame, time);
    inky->Update(map, current_frame, time);
    clyde->Update(map, current_frame, time);
  }

  ~ListOfCharacters() = default;
};