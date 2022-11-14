#include <../Headers/RestartGame.h>

void RestartGame(std::array<std::array<Cell, kMapWidth>, kMapHeight>& map, ListOfCharacters& characters) {
  ConvertSketch(kMapSketch, map);
  characters.pacman->picture.sprite.setTextureRect(sf::IntRect(kCellSize, 0, kCellSize, kCellSize));
  characters.pacman->position.x = kCellSize * kMultiplier * kMultiXPacman + ((kCellSize * (kMultiplier - kPacmanMultiplier)) / 2 + 1);
  characters.pacman->position.y = kCellSize * kMultiplier * kMultiYPacman + ((kCellSize * (kMultiplier - kPacmanMultiplier)) / 2 + 1);
  characters.pacman->score = 0;
  characters.pacman->level = 1;
}