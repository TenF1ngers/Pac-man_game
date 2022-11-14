#include <sstream>

#include <SFML/Graphics.hpp>
#include <../Headers/DrawGameText.h>

void DrawGameText(sf::RenderWindow& window, Pacman& pacman, GameText& g_text, GameText& level_text) {
  std::ostringstream score_str;
  score_str << pacman.score;
  g_text.text.setString("Score : " + score_str.str());
  g_text.text.setPosition(window.getView().getCenter().x - level_text.size * 2.5, kMapHeight * kCellSize * kMultiplier + 2);
  window.draw(g_text.text);

  std::ostringstream level_str;
  level_str << pacman.level;
  level_text.text.setString("Level : " + level_str.str());
  level_text.text.setPosition(kCellSize * kMultiplier + 5, kMapHeight * kCellSize * kMultiplier + 2);
  window.draw(level_text.text);
}