#pragma once

#include <../Headers/CharactersManager.h>

class Inky : public Character {
 public:
  void Update(Map& map, double& current_frame, double& time) override;
  sf::Sprite GetSprite() const override;
  virtual ~Inky() = default;
};
