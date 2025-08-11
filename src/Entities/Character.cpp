//
// Created by eal on 08/08-2025.
//

#include "Character.hpp"

#include "TextureLocations.h"
#include "EngineBase/EngineBase.h"
#include "Model/Vector.hpp"
#include "Utility/ConfigController.h"


bool Character::canShoot() {
    const std::chrono::high_resolution_clock::time_point timerEnd = std::chrono::high_resolution_clock::now();
    const auto totalDuration = std::chrono::duration_cast<std::chrono::milliseconds>(timerEnd - lastShootingTime_);

    return totalDuration.count() > ConfigController::getConfigInt("ShootingDelayMS");
}

Character::Character() : health_(50), lastVelocityVector_(std::make_unique<Vector>())
{
  lastVelocityVector_->x_ = 1;
  drawAble_->setSize(100, 100);
  drawAble_->setTextureLocation(&TextureLocation::player);
  lastShootingTime_ = std::chrono::high_resolution_clock::now();
}

void Character::handleAction(const double deltaTime, const std::set<Action>& actions, GameState* gameState,
                             EngineBase* engineBase)
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
  lastMovementVector_ = vector;

  auto shootingVector = std::make_shared<Vector>();

  if (vector.x_ == 0 && vector.y_ == 0)
  {
    shootingVector->x_ = lastVelocityVector_->x_;
    shootingVector->y_ = lastVelocityVector_->y_;
  }

  if (vector.x_ != 0)
  {
    shootingVector->x_ = vector.x_ > 0 ? 1 : -1;
    lastVelocityVector_->x_ = shootingVector->x_;
    lastVelocityVector_->y_ = 0;
  }
  if (vector.y_ != 0)
  {
    shootingVector->y_ = vector.y_ > 0 ? 1 : -1;
    lastVelocityVector_->y_ = shootingVector->y_;
    if (vector.x_ == 0)
    {
      lastVelocityVector_->x_ = 0;
    }
  }

  if (actions.contains(Action::SHOOT) && canShoot())
  {
    auto currentPos = std::make_shared<Vector>();
    currentPos->x_ = drawAble_->getX() + (drawAble_->getWidth() / 2);
    currentPos->y_ = drawAble_->getY() + (drawAble_->getHeight() / 2);
    currentPos->x_ += (drawAble_->getWidth() / 2) * shootingVector->x_;
    currentPos->y_ += (drawAble_->getHeight() / 2) * shootingVector->y_;
    gameState->projectiles_.push_back(std::make_unique<Projectile>(engineBase, shootingVector, currentPos));
    lastShootingTime_ = std::chrono::high_resolution_clock::now();
  }
}
