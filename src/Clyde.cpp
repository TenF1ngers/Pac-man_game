#include <../Headers/Clyde.h>

void Clyde::Update(std::array<std::array<Cell, kMapWidth>, kMapHeight>& map, double& current_frame, double& time) {
}

sf::Sprite Clyde::GetSprite() const {
  return this->picture.sprite;
}