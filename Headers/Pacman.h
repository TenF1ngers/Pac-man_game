#pragma once

#include <array>

#include <../Headers/CharactersManager.h>
#include <../Headers/Global.h>

class Pacman : public Character {
 public:
  int32_t score;
  int32_t level;

  Pacman() {
    this->picture.image.loadFromFile("../Images/Pacman16.png");
    this->picture.texture.loadFromImage(this->picture.image);
    this->picture.sprite.setTexture(this->picture.texture);
    this->picture.sprite.setTextureRect(sf::IntRect(kCellSize, 0, kCellSize, kCellSize));
    this->picture.sprite.setScale(kPacmanMultiplier, kPacmanMultiplier);
    this->position.x = kCellSize * kMultiplier * kMultiXPacman + ((kCellSize * (kMultiplier - kPacmanMultiplier)) / 2 + 1);
    this->position.y = kCellSize * kMultiplier * kMultiYPacman + ((kCellSize * (kMultiplier - kPacmanMultiplier)) / 2 + 1);
    score = 0;
    level = 1;
  }

  void Update(Map& map, double& current_frame, double& time) override;
  sf::Sprite GetSprite() const override;
  virtual ~Pacman() = default;
};