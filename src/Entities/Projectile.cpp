//
// Created by eal on 08/08-2025.
//

#include "Projectile.hpp"

#include "TextureLocations.h"

Projectile::Projectile(EngineBase* engineBase, const std::shared_ptr<Vector>& movementVector,
                       const std::shared_ptr<Vector>& startPos) : movementVector_(
  movementVector)
{
  drawAble_->setSize(50, 50);
  drawAble_->setPosition(startPos->x_ - (drawAble_->getWidth() / 2), startPos->y_ - (drawAble_->getHeight() / 2));
  drawAble_->updatePosition(movementVector_->x_ * drawAble_->getWidth() / 2,
                            movementVector_->y_ * drawAble_->getHeight() / 2);
  drawAble_->setTextureLocation(&TextureLocation::bullet);
  engineBase->registerDrawAble(drawAble_);
  addedToEngine = true;
  movementVector_->normalizeDirection();
  id = nextID_++;
}

Projectile::Projectile() : movementVector_(std::make_shared<Vector>()), createdByThisClient(false)
{
  drawAble_->setSize(50, 50);
  drawAble_->setTextureLocation(&TextureLocation::bullet);
}

void Projectile::update(const double deltaTime)
{
  double deltaX = movementVector_->x_ * movementSpeed_ * deltaTime;
  double deltaY = movementVector_->y_ * movementSpeed_ * deltaTime;
  drawAble_->updatePosition(deltaX, deltaY);
}
