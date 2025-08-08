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

void Character::handleAction(std::set<Action> actions, GameState* gameState)
{
}
