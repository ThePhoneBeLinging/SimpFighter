//
// Created by eal on 08/08-2025.
//

#include "Character.hpp"

#include "TextureLocations.h"
#include "Model/Vector.hpp"


Character::Character() : health_(50), lastVelocityVector_(std::make_unique<Vector>())
{
  drawAble_->setSize(100, 100);
  drawAble_->setTextureLocation(&TextureLocation::player);
}

void Character::handleAction(const double deltaTime, const std::set<Action>& actions, GameState* gameState)
{
  Vector vector = Vector();
  if (actions.contains(Action::MOVE_UP))
  {
    vector.y_ -= 1;
  }
  if (actions.contains(Action::MOVE_DOWN))
  {
    vector.y_ += 1;
  }
  if (actions.contains(Action::MOVE_LEFT))
  {
    vector.x_ -= 1;
  }
  if (actions.contains(Action::MOVE_RIGHT))
  {
    vector.x_ += 1;
  }
  vector.normalizeDirection();
  vector *= movementSpeed_ * deltaTime;

  drawAble_->updatePosition(vector.x_, vector.y_);

  auto shootingVector = std::make_shared<Vector>();

  if (vector.x_ == 0 && vector.y_ == 0)
  {
    shootingVector->x_ = lastVelocityVector_->x_;
    shootingVector->y_ = lastVelocityVector_->y_;
    lastVelocityVector_->x_ = 0;
    lastVelocityVector_->y_ = 0;
  }

  if (vector.x_ != 0)
  {
    shootingVector->x_ = vector.x_ > 0 ? 1 : -1;
    lastVelocityVector_->x_ = shootingVector->x_;
  }
  if (vector.y_ != 0)
  {
    shootingVector->y_ = vector.y_ > 0 ? 1 : -1;
    lastVelocityVector_->y_ = shootingVector->y_;
  }

  if (actions.contains(Action::SHOOT))
  {
  }
}
