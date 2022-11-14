#pragma once

#include <../Headers/CharactersManager.h>
#include <../Headers/Clyde.h>

class ClydeCreator : public ICreator {
 public:
  Clyde* CharactersManager() override;
  virtual ~ClydeCreator() = default;
};
