//
// Created by eal on 08/08-2025.
//

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "Entity.hpp"
#include "EngineBase/EngineBase.h"
#include "Model/Vector.hpp"


class Projectile : public Entity
{
public:
  Projectile(EngineBase* engineBase, const std::shared_ptr<Vector>& movementVector,
             const std::shared_ptr<Vector>& startPos);
  Projectile();
  int id = 0;
  static inline std::atomic_int nextID_ = 0;
  void update(double deltaTime);
  std::shared_ptr<Vector> movementVector_;
  static constexpr int movementSpeed_ = 500;
  static constexpr int damage_ = 10;
  bool createdByThisClient = true;
  bool addedToEngine = false;
};


#endif //PROJECTILE_HPP
