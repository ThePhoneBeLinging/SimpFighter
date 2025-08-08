//
// Created by eal on 08/08-2025.
//

#include "Player.hpp"

#include "TextureLocations.h"

Player::Player() : health_(50), drawAble_(std::make_shared<DrawAble>())
{
  drawAble_->setSize(50, 50);
  drawAble_->setTextureLocation(&TextureLocation::player);
}
