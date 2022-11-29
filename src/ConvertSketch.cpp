#include <../Headers/ConvertSketch.h>

void ConvertSketch(const kMap& map_sketch, Map& map) {
  for (int32_t i = 0; i < kMapHeight; ++i) {
    for (int32_t j = 0; j < kMapWidth; ++j) {
      map[i][j] = Cell::Empty;
      switch (map_sketch[i][j]) {
        case '#': {
          map[i][j] = Cell::Wall;
          break;
        }
        case '=': {
          map[i][j] = Cell::Door;
          break;
        }
        case '.': {
          map[i][j] = Cell::Pellet;
          break;
        }
        case '0': {
          break;
        }
        case '1': {
          break;
        }
        case '2': {
          break;
        }
        case '3': {
          break;
        }
        case 'P': {
          break;
        }
        case 'o': {
          map[i][j] = Cell::Energizer;
          break;
        }
      }
    }
  }
}