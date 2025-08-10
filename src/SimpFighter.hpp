//
// Created by eal on 08/08-2025.
//

#ifndef SIMPFIGHTER_HPP
#define SIMPFIGHTER_HPP
#include <memory>
#include "Entities/Character.hpp"
#include "Model/GameState.hpp"
#include "EngineBase/EngineBase.h"
#include "Players/PhysicalPlayer.hpp"
#include <vector>


class SimpFighter
{
public:
  SimpFighter();
  void update(double deltaTime);

  int result = 0;

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> startPoint_;
  std::unique_ptr<EngineBase> engineBase_;
  std::unique_ptr<GameState> gameState_;
  std::unique_ptr<IPlayer> player_;
  std::unique_ptr<IPlayer> player2_;
  std::shared_ptr<DrawAble> waitingDrawable_;
};


#endif //SIMPFIGHTER_HPP
