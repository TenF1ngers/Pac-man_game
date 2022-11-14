#include <Pinky.h>

void Pinky::Update(std::array<std::array<Cell, kMapWidth>, kMapHeight>& map, double& current_frame, double& time) {
}

sf::Sprite Pinky::GetSprite() const {
  return this->picture.sprite;
}