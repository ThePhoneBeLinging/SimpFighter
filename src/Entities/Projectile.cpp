//
// Created by eal on 08/08-2025.
//

#include "Projectile.hpp"

#include "TextureLocations.h"

Projectile::Projectile(EngineBase* engineBase, const std::shared_ptr<Vector>& movementVector,
                       const std::shared_ptr<Vector>& startPos) : movementVector_(
  movementVector)
{
  drawAble_->setPosition(startPos->x_, startPos->y_);
  drawAble_->setSize(200, 200);
  drawAble_->setTextureLocation(&TextureLocation::bullet);
  engineBase->registerDrawAble(drawAble_);
  movementVector_->normalizeDirection();
}

void Projectile::update(const double deltaTime)
{
  double deltaX = movementVector_->x_ * movementSpeed_ * deltaTime;
  double deltaY = movementVector_->y_ * movementSpeed_ * deltaTime;
  drawAble_->updatePosition(deltaX, deltaY);
}
