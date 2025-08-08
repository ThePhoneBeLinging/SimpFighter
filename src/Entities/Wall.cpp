//
// Created by eal on 08/08-2025.
//

#include "Wall.hpp"

#include "../TextureLocations.h"

Wall::Wall()
{
  drawAble_->setSize(200, 200);
  drawAble_->setTextureLocation(&TextureLocation::wall);
}
