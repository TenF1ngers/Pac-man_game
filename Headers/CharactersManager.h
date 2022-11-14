#pragma once

#include <iostream>
#include <array>

#include <SFML/Graphics.hpp>
#include <../Headers/Global.h>
#include <../Headers/Picture.h>

class Position {
 public:
  float x = 0.;
  float y = 0.;
};

class Moving {
 public:
  double dx = 0.;
  double dy = 0.;
  double speed = 0.;
};

class Character {
 public:
  Position position;
  Moving moving;
  int direction = 0;
  Picture picture;

  virtual void Update(Map& map, double& current_frame, double& time) = 0;
  virtual sf::Sprite GetSprite() const = 0;
  virtual ~Character() = default;
};

class ICreator {
 public:
  virtual Character* CharactersManager() = 0;
  virtual ~ICreator() = default;
};
