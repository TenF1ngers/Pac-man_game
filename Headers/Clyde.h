#pragma once

#include <../Headers/CharactersManager.h>


class Clyde : public Character {
 public:
  void Update(Map& map, double& current_frame, double& time) override;
  sf::Sprite GetSprite() const override;
  virtual ~Clyde() = default;
};
