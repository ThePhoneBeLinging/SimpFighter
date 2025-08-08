//
// Created by eal on 08/08-2025.
//

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <vector>
#include "GameState.hpp"
#include "Entities/Projectile.hpp"
#include "Entities/Character.hpp"
#include "Entities/Wall.hpp"

class Character;
class Projectile;

class GameState
{
public:
  GameState() = default;

  std::vector<std::shared_ptr<Character>> characters_;
  std::vector<std::shared_ptr<Wall>> walls_;
  std::vector<std::shared_ptr<Projectile>> projectiles_;
};


#endif //GAMESTATE_HPP
