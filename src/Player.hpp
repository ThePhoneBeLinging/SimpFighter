//
// Created by eal on 08/08-2025.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "EngineBase/DrawAble.h"


class Player
{
public:
  Player();
  int health_;
  std::shared_ptr<DrawAble> drawAble_;
};


#endif //PLAYER_HPP
