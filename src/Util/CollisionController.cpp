//
// Created by eal on 09/08-2025.
//

#include "CollisionController.hpp"

#include <chrono>
#include <iostream>

#include "TextureLocations.h"
#include "EngineBase/CollisionChecker.h"

void CollisionController::handleCollisions(GameState* gameState)
{
  for (const auto& player : gameState->characters_)
  {
    std::vector<std::shared_ptr<Wall>> wallsWithCollision;
    for (const auto& wall : gameState->walls_)
    {
      if (not CollisionChecker::checkSquareCollision(player->drawAble_, wall->drawAble_))
      {
        continue;
      }
      player->drawAble_->updatePosition(-player->lastMovementVector_.x_, 0);
      if (CollisionChecker::checkSquareCollision(player->drawAble_, wall->drawAble_))
      {
        player->drawAble_->updatePosition(player->lastMovementVector_.x_, -player->lastMovementVector_.y_);
        if (CollisionChecker::checkSquareCollision(player->drawAble_, wall->drawAble_))
        {
          player->drawAble_->updatePosition(0, player->lastMovementVector_.y_);
        }
      }
    }
  }

  std::vector<std::shared_ptr<Projectile>> projectiles;
  for (const auto& projectile : gameState->projectiles_)
  {
    bool projectileSurvived = true;
    for (const auto& player : gameState->characters_)
    {
      if (CollisionChecker::checkSquareCollision(projectile->drawAble_, player->drawAble_))
      {
        player->health_ -= projectile->damage_;
        projectileSurvived = false;
        break;
      }
    }

    for (const auto& wall : gameState->walls_)
    {
      if (CollisionChecker::checkSquareCollision(projectile->drawAble_, wall->drawAble_))
      {
        projectileSurvived = false;
        break;
      }
    }

    if (projectileSurvived)
    {
      projectiles.push_back(projectile);
    }
  }
  gameState->projectiles_ = projectiles;
}

