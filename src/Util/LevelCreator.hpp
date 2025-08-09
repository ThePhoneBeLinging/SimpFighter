//
// Created by eal on 09/08-2025.
//

#ifndef LEVELCREATOR_HPP
#define LEVELCREATOR_HPP
#include "Model/GameState.hpp"

class LevelCreator
{
public:
  static void createLevel(EngineBase* engineBase, GameState* gameState);


  static void addPlayer(EngineBase* engineBase, GameState* gameState);

private:
  static inline int playerCount_ = 0;
};


#endif //LEVELCREATOR_HPP
