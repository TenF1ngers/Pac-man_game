#pragma once

#include <../Headers/CharactersManager.h>
#include <../Headers/Pinky.h>

class PinkyCreator : public ICreator {
 public:
  Pinky* CharactersManager() override;
  virtual ~PinkyCreator() = default;
};
