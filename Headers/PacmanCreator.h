#pragma once

#include <../Headers/CharactersManager.h>
#include <../Headers/Pacman.h>

class PacmanCreator : public ICreator {
 public:
  Pacman* CharactersManager() override;
  virtual ~PacmanCreator() = default;
};