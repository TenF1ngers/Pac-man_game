#include <../Headers/Blinky.h>
#include <../Headers/Global.h>

void Blinky::Update(Map& map, double& current_frame, double& time) {
}

sf::Sprite Blinky::GetSprite() const {
  return this->picture.sprite;
}