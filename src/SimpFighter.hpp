//
// Created by eal on 08/08-2025.
//

#ifndef SIMPFIGHTER_HPP
#define SIMPFIGHTER_HPP
#include <memory>
#include "Entities/Character.hpp"
#include "GameState.hpp"
#include "EngineBase/EngineBase.h"


class SimpFighter
{
public:
  SimpFighter();
  void update(double deltaTime);

private:
  std::unique_ptr<EngineBase> engineBase_;
  std::unique_ptr<GameState> gameState_;
};


#endif //SIMPFIGHTER_HPP
