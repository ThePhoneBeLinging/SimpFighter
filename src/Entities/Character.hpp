//
// Created by eal on 08/08-2025.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <set>

#include "Entity.hpp"
#include "Model/GameState.hpp"
#include "Players/Actions.hpp"

class GameState;

class Character : public Entity
{
public:
  Character();
  void handleAction(double deltaTime, const std::set<Action>& actions, GameState* gameState, EngineBase* engineBase);
  int health_;
  Vector lastMovementVector_;
  static constexpr int movementSpeed_ = 250;

private:
  std::unique_ptr<Vector> lastVelocityVector_;
  std::chrono::time_point<std::chrono::high_resolution_clock> lastShootingTime_;
};


#endif //CHARACTER_HPP
