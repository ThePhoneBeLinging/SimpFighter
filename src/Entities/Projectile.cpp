//
// Created by eal on 08/08-2025.
//

#include "Projectile.hpp"

Projectile::Projectile(const std::shared_ptr<Vector>& movementVector) : movementVector_(movementVector)
{
  drawAble_->setSize(200, 200);
}

void Projectile::update(const double deltaTime)
{
  movementVector_->normalizeDirection();
  double deltaX = movementVector_->x_ * movementSpeed_ * deltaTime;
  double deltaY = movementVector_->y_ * movementSpeed_ * deltaTime;
  drawAble_->updatePosition(deltaX, deltaY);
}
