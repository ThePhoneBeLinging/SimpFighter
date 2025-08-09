//
// Created by eal on 08/08-2025.
//

#include "Wall.hpp"

#include "TextureLocations.h"

Wall::Wall(int width, int height)
{
  drawAble_->setSize(width, height);
  drawAble_->setTextureLocation(&TextureLocation::wall);
}
