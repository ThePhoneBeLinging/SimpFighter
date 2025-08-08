//
// Created by eal on 08/08-2025.
//

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "Entities/Character.hpp"
#include "Entities/Wall.hpp"
#include <vector>

#include "GameState.hpp"

class Character;
class Wall;
class Projectile;

class GameState
{
public:
  GameState() = default;

private:
  std::vector<Character> characters_;
  std::vector<Wall> walls_;
};


#endif //GAMESTATE_HPP
