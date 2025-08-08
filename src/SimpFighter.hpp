//
// Created by eal on 08/08-2025.
//

#ifndef SIMPFIGHTER_HPP
#define SIMPFIGHTER_HPP
#include <memory>

#include "Player.hpp"
#include "EngineBase/EngineBase.h"


class SimpFighter
{
public:
  SimpFighter();
  void update(double deltaTime);

private:
  std::unique_ptr<EngineBase> engineBase_;
  std::unique_ptr<Player> player_;
};


#endif //SIMPFIGHTER_HPP
