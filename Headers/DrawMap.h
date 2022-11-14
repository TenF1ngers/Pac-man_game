#pragma once

#include <../Headers/CharactersManager.h>
#include <../Headers/Global.h>

class PictureOfCell {
 public:
  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;
};

void DrawMap(Map& map, sf::RenderWindow& window);