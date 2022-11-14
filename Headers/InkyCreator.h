#pragma once

#include <../Headers/CharactersManager.h>
#include <../Headers/Inky.h>

class InkyCreator : public ICreator {
 public:
  Inky* CharactersManager() override;
  virtual ~InkyCreator() = default;
};
