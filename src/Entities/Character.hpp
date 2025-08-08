//
// Created by eal on 08/08-2025.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <set>

#include "Entity.hpp"
#include "../GameState.hpp"
#include "../Players/Actions.hpp"

class GameState;

class Character : public Entity
{
public:
  Character();
  void handleAction(double deltaTime, const std::set<Action>& actions, GameState* gameState);
  int health_;
  static constexpr int movementSpeed_ = 250;
};


#endif //CHARACTER_HPP
