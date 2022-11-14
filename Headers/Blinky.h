#pragma once

#include <../Headers/CharactersManager.h>
#include <../Headers/Global.h>
#include <iostream>

class Blinky : public Character {
 public:
  void Update(Map& map, double& current_frame, double& time) override;
  sf::Sprite GetSprite() const override;
  virtual ~Blinky() = default;
};
