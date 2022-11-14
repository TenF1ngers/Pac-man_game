#include <../Headers/Inky.h>

void Inky::Update(std::array<std::array<Cell, kMapWidth>, kMapHeight>& map, double& current_frame, double& time) {
}

sf::Sprite Inky::GetSprite() const {
  return this->picture.sprite;
}