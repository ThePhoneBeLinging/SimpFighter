//
// Created by eal on 08/08-2025.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "EngineBase/DrawAble.h"

class Entity
{
public:
  Entity();
  virtual ~Entity() = default;
  std::shared_ptr<DrawAble> drawAble_;
};


#endif //ENTITY_HPP
