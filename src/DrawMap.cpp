#include <array>

#include <../Headers/DrawMap.h>

void DrawMap(Map& map, sf::RenderWindow& window) {
  PictureOfCell cell_picture;
  cell_picture.image.loadFromFile("../Images/Map16.png");
  cell_picture.texture.loadFromImage(cell_picture.image);
  cell_picture.sprite.setTexture(cell_picture.texture);
  for (int32_t i = 0; i < kMapHeight; ++i) {
    for (int32_t j = 1; j < kMapWidth - 1; ++j) {
      cell_picture.sprite.setPosition(static_cast<float>((j - 1) * kCellSize * kMultiplier),
                                      static_cast<float>(i * kCellSize * kMultiplier));
      switch (map[i][j]) {
        case Cell::Door: {
          cell_picture.sprite.setTextureRect(sf::IntRect(kCellSize * 2, kCellSize, kCellSize, kCellSize));
          cell_picture.sprite.setScale(kMultiplier, kMultiplier);
          window.draw(cell_picture.sprite);
          break;
        }
        case Cell::Pellet: {
          cell_picture.sprite.setTextureRect(sf::IntRect(0, kCellSize, kCellSize, kCellSize));
          cell_picture.sprite.setScale(kMultiplier, kMultiplier);
          window.draw(cell_picture.sprite);
          break;
        }
        case Cell::Energizer: {
          cell_picture.sprite.setTextureRect(sf::IntRect(kCellSize, kCellSize, kCellSize, kCellSize));
          cell_picture.sprite.setScale(kMultiplier, kMultiplier);
          window.draw(cell_picture.sprite);
          break;
        }
        case Cell::Wall: {
          bool left = false;
          bool down = false;
          bool right = false;
          bool up = false;
          if (j > 0) {
            if (map[i][j - 1] == Cell::Wall) {
              left = true;
            }
          } else {
            left = true;
          }
          if (j < kMapWidth - 1) {
            if (map[i][j + 1] == Cell::Wall) {
              right = true;
            }
          } else {
            right = true;
          }
          if (i > 0) {
            if (map[i - 1][j] == Cell::Wall) {
              up = true;
            }
          } else {
            up = true;
          }
          if (i < kMapHeight) {
            if (map[i + 1][j] == Cell::Wall) {
              down = true;
            }
          } else {
            down = true;
          }
          cell_picture.sprite.setTextureRect(sf::IntRect(kCellSize * (down + 2 * (left + 2 * (right + 2 * up))), 0, kCellSize, kCellSize));
          cell_picture.sprite.setScale(kMultiplier, kMultiplier);
          window.draw(cell_picture.sprite);
          break;
        }
        case Cell::Empty: {
          break;
        }
      }
    }
  }
}