#pragma once

#include <../Headers/CharactersManager.h>
#include <../Headers/Blinky.h>

class BlinkyCreator : public ICreator {
 public:
  Blinky* CharactersManager() override;
  virtual ~BlinkyCreator() = default;
};
