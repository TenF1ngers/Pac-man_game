#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <../Headers/Global.h>

class GameText {
 public:
  sf::Font font;
  sf::Text text;
  int32_t size = static_cast<float>(kCellSize * kMultiplier) / kFactorOfInteraction * 1.3;

  explicit GameText(const std::string& font_str) {
    font.loadFromFile(font_str);
    text.setFont(font);
    text.setCharacterSize(size);
  }
};