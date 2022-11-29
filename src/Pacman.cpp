#include <array>
#include <cmath>

#include <../Headers/Pacman.h>

void ProcessClick(Pacman& unit, double& current_frame, double& time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    unit.direction = 1;
    unit.moving.speed = kSpeedOfPacman;
    current_frame += kFrameMultiplier * time;
    if (current_frame > 6) {
      current_frame -= 6;
    }
    unit.picture.sprite.setTextureRect(sf::IntRect(kCellSize * int(current_frame), 0, kCellSize, kCellSize));
    unit.picture.sprite.setScale(kPacmanMultiplier, kPacmanMultiplier);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    unit.direction = 2;
    unit.moving.speed = kSpeedOfPacman;
    current_frame += kFrameMultiplier * time;
    if (current_frame > 6) {
      current_frame -= 6;
    }
    unit.picture.sprite.setTextureRect(sf::IntRect(kCellSize * int(current_frame), kCellSize, kCellSize, kCellSize));
    unit.picture.sprite.setScale(kPacmanMultiplier, kPacmanMultiplier);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    unit.direction = 3;
    unit.moving.speed = kSpeedOfPacman;
    current_frame += kFrameMultiplier * time;
    if (current_frame > 6) {
      current_frame -= 6;
    }
    unit.picture.sprite.setTextureRect(sf::IntRect(kCellSize * int(current_frame), kCellSize * 2, kCellSize, kCellSize));
    unit.picture.sprite.setScale(kPacmanMultiplier, kPacmanMultiplier);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    unit.direction = 4;
    unit.moving.speed = kSpeedOfPacman;
    current_frame += kFrameMultiplier * time;
    if (current_frame > 6) {
      current_frame -= 6;
    }
    unit.picture.sprite.setTextureRect(sf::IntRect(kCellSize * int(current_frame), kCellSize * 3, kCellSize, kCellSize));
    unit.picture.sprite.setScale(kPacmanMultiplier, kPacmanMultiplier);
  }
}

void IntersectionWithWalls(Pacman& pacman, std::array<std::array<Cell, kMapWidth>, kMapHeight>& map, float cur_x, float cur_y) {
  switch (pacman.direction) {
    case 1: {
      if ((cur_y == floor(cur_y)) || ((pacman.position.y + kCellSize * kPacmanMultiplier) / (kCellSize * kMultiplier) == ceil(cur_y)) ||
          ((cur_y > floor(cur_y)) && (pacman.position.y + kCellSize * kPacmanMultiplier < ceil(cur_y) * kCellSize * kMultiplier))) {
        if (pacman.position.x + kCellSize * kPacmanMultiplier > ceil(cur_x) * kCellSize * kMultiplier) {
          if (map[floor(cur_y)][ceil(cur_x) + 1.] == Cell::Wall) {
            pacman.position.x = ceil(cur_x) * kCellSize * kMultiplier - kCellSize * kPacmanMultiplier;
          }
        }
      } else {
        if (pacman.position.x + kCellSize * kPacmanMultiplier > ceil(cur_x) * kCellSize * kMultiplier) {
          if ((map[floor(cur_y)][ceil(cur_x) + 1.] == Cell::Wall) || (map[ceil(cur_y)][ceil(cur_x) + 1.] == Cell::Wall)) {
            pacman.position.x = ceil(cur_x) * kCellSize * kMultiplier - kCellSize * kPacmanMultiplier;
          }
        }
      }
      break;
    }
    case 2: {
      if ((cur_x == floor(cur_x)) || ((pacman.position.x + kCellSize * kPacmanMultiplier) / (kCellSize * kMultiplier) == ceil(cur_x)) ||
          ((cur_x > floor(cur_x)) && (pacman.position.x + kCellSize * kPacmanMultiplier < ceil(cur_x) * kCellSize * kMultiplier))) {
        if (pacman.position.y + kCellSize * kPacmanMultiplier > ceil(cur_y) * kCellSize * kMultiplier) {
          if (map[floor(cur_y)][floor(cur_x) + 1] == Cell::Wall) {
            pacman.position.y = ceil(cur_y) * kCellSize * kMultiplier;
          }
        }
      } else {
        if (pacman.position.y + kCellSize * kPacmanMultiplier > ceil(cur_y) * kCellSize * kMultiplier) {
          if ((map[floor(cur_y)][floor(cur_x) + 1] == Cell::Wall) || (map[floor(cur_y)][ceil(cur_x) + 1] == Cell::Wall)) {
            pacman.position.y = ceil(cur_y) * kCellSize * kMultiplier;
          }
        }
      }
      break;
    }
    case 3: {
      if ((cur_y == floor(cur_y)) || ((pacman.position.y + kCellSize * kPacmanMultiplier) / (kCellSize * kMultiplier) == ceil(cur_y)) ||
          ((cur_y > floor(cur_y)) && (pacman.position.y + kCellSize * kPacmanMultiplier < ceil(cur_y) * kCellSize * kMultiplier))) {
        if (pacman.position.x + kCellSize * kPacmanMultiplier > ceil(cur_x) * kCellSize * kMultiplier) {
          if (map[floor(cur_y)][floor(cur_x) + 1.] == Cell::Wall) {
            pacman.position.x = ceil(cur_x) * kCellSize * kMultiplier;
          }
        }
      } else {
        if (pacman.position.x + kCellSize * kPacmanMultiplier > ceil(cur_x) * kCellSize * kMultiplier) {
          if ((map[floor(cur_y)][floor(cur_x) + 1.] == Cell::Wall) || (map[ceil(cur_y)][floor(cur_x) + 1.] == Cell::Wall)) {
            pacman.position.x = ceil(cur_x) * kCellSize * kMultiplier;
          }
        }
      }
      break;
    }
    case 4: {
      if ((cur_x == floor(cur_x)) || ((pacman.position.x + kCellSize * kPacmanMultiplier) / (kCellSize * kMultiplier) == ceil(cur_x)) ||
          ((cur_x > floor(cur_x)) && (pacman.position.x + kCellSize * kPacmanMultiplier < ceil(cur_x) * kCellSize * kMultiplier))) {
        if (pacman.position.y + kCellSize * kPacmanMultiplier > ceil(cur_y) * kCellSize * kMultiplier) {
          if ((map[ceil(cur_y)][floor(cur_x) + 1] == Cell::Wall) || (map[ceil(cur_y)][floor(cur_x) + 1] == Cell::Door)) {
            pacman.position.y = ceil(cur_y) * kCellSize * kMultiplier - kCellSize * kPacmanMultiplier;
          }
        }
      } else {
        if (pacman.position.y + kCellSize * kPacmanMultiplier > ceil(cur_y) * kCellSize * kMultiplier) {
          if ((map[ceil(cur_y)][floor(cur_x) + 1] == Cell::Wall) || (map[ceil(cur_y)][ceil(cur_x) + 1] == Cell::Wall) ||
              (map[ceil(cur_y)][floor(cur_x) + 1] == Cell::Door) || (map[ceil(cur_y)][ceil(cur_x) + 1] == Cell::Door)) {
            pacman.position.y = ceil(cur_y) * kCellSize * kMultiplier - kCellSize * kPacmanMultiplier;
          }
        }
      }
      break;
    }
    default: {
      break;
    }
  }
}

void Tunnel(Pacman& pacman, float cur_y) {
  switch (pacman.direction) {
    case 1: {
      if (((cur_y >= 9) && (cur_y < 10)) && (pacman.position.x >= kWindowWidth + 1)) {
        pacman.position.x = -(kCellSize * kPacmanMultiplier);
      }
      break;
    }
    case 3: {
      if (((cur_y >= 9) && (cur_y < 10)) && (pacman.position.x <= -(kCellSize * kPacmanMultiplier))) {
        pacman.position.x = kWindowWidth + 1;
      }
      break;
    }
  }
}

void CollectingOfEat(Pacman& pacman, std::array<std::array<Cell, kMapWidth>, kMapHeight>& map, float cur_x, float cur_y) {
  switch (pacman.direction) {
    case 1: {
      if (pacman.position.x + kCellSize * kPacmanMultiplier >= ceil(cur_x) * kCellSize * kMultiplier + kCellSize * kFactorOfInteraction) {
        if (map[floor(cur_y)][ceil(cur_x) + 1] == Cell::Pellet) {
          map[floor(cur_y)][ceil(cur_x) + 1] = Cell::Empty;
          ++pacman.score;
        }
      }
      break;
    }
    case 2: {
      if (pacman.position.y <= ceil(cur_y) * kCellSize * kMultiplier - kCellSize * kFactorOfInteraction) {
        if (map[floor(cur_y)][floor(cur_x) + 1] == Cell::Pellet) {
          map[floor(cur_y)][floor(cur_x) + 1] = Cell::Empty;
          ++pacman.score;
        }
      }
      break;
    }
    case 3: {
      if (pacman.position.x <= ceil(cur_x) * kCellSize * kMultiplier - kCellSize * kFactorOfInteraction) {
        if (map[floor(cur_y)][floor(cur_x) + 1] == Cell::Pellet) {
          map[floor(cur_y)][floor(cur_x) + 1] = Cell::Empty;
          ++pacman.score;
        }
      }
      break;
    }
    case 4: {
      if (pacman.position.y + kCellSize * kPacmanMultiplier >= ceil(cur_y) * kCellSize * kMultiplier + kCellSize * kFactorOfInteraction) {
        if (map[ceil(cur_y)][floor(cur_x) + 1] == Cell::Pellet) {
          map[ceil(cur_y)][floor(cur_x) + 1] = Cell::Empty;
          ++pacman.score;
        }
      }
      break;
    }
    default: {
      break;
    }
  }
}

void InteractionWithMap(Pacman& pacman, std::array<std::array<Cell, kMapWidth>, kMapHeight>& map) {
  float cur_x = pacman.position.x / (kCellSize * kMultiplier);
  float cur_y = pacman.position.y / (kCellSize * kMultiplier);
  IntersectionWithWalls(pacman, map, cur_x, cur_y);
  Tunnel(pacman, cur_y);
  CollectingOfEat(pacman, map, cur_x, cur_y);
  pacman.picture.sprite.setPosition(pacman.position.x, pacman.position.y);
}

void Pacman::Update(Map& map, double& current_frame, double& time) {
  ProcessClick(*this, current_frame, time);
  if (this->direction == 1) {
    this->moving.dx = this->moving.speed;
    this->moving.dy = 0.;
  }
  if (this->direction == 2) {
    this->moving.dy = -this->moving.speed;
    this->moving.dx = 0.;
  }
  if (this->direction == 3) {
    this->moving.dx = -this->moving.speed;
    this->moving.dy = 0.;
  }
  if (this->direction == 4) {
    this->moving.dy = this->moving.speed;
    this->moving.dx = 0.;
  }
  this->position.x += time * this->moving.dx;
  this->position.y += time * this->moving.dy;
  this->moving.speed = 0;
  this->picture.sprite.setPosition(this->position.x, this->position.y);
  InteractionWithMap(*this, map);
}

sf::Sprite Pacman::GetSprite() const {
  return this->picture.sprite;
}