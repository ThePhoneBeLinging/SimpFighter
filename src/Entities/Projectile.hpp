//
// Created by eal on 08/08-2025.
//

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "Entity.hpp"
#include "Model/Vector.hpp"


class Projectile : public Entity
{
public:
  Projectile(const std::shared_ptr<Vector>& movementVector);
  void update(double deltaTime);
  std::shared_ptr<Vector> movementVector_;
  static constexpr int movementSpeed_ = 500;
};


#endif //PROJECTILE_HPP
