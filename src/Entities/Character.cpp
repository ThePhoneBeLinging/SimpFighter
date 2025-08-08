//
// Created by eal on 08/08-2025.
//

#include "Character.hpp"

#include "../TextureLocations.h"


Character::Character() : health_(50)
{
  drawAble_->setSize(100, 100);
  drawAble_->setTextureLocation(&TextureLocation::player);
}

void Character::handleAction(double deltaTime, const std::set<Action>& actions, GameState* gameState)
{
  double deltaX = 0;
  double deltaY = 0;
  if (actions.contains(Action::MOVE_UP))
  {
    deltaY -= deltaTime * movementSpeed_;
  }
  if (actions.contains(Action::MOVE_DOWN))
  {
    deltaY += deltaTime * movementSpeed_;
  }
  if (actions.contains(Action::MOVE_LEFT))
  {
    deltaX -= deltaTime * movementSpeed_;
  }
  if (actions.contains(Action::MOVE_RIGHT))
  {
    deltaX += deltaTime * movementSpeed_;
  }
  drawAble_->updatePosition(deltaX, deltaY);
}
