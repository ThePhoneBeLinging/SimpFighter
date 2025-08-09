//
// Created by eal on 09/08-2025.
//

#include "SimpAI.hpp"

#include <iostream>

SimpAI::SimpAI(int id) : IPlayer(id)
{
  srand((unsigned)time(0));
}

std::set<Action> SimpAI::update(GameState* state)
{
  std::set<Action> actions;
  for (int i = 0; i < 5; i++)
  {
    actions.insert(Action(rand() % 6));
  }
  return actions;
}
