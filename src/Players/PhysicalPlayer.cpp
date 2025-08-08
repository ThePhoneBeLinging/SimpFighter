//
// Created by eal on 08/08-2025.
//

#include "PhysicalPlayer.hpp"

PhysicalPlayer::PhysicalPlayer(const int id, IGraphicsLibrary* graphicsLibrary) : IPlayer(id),
  graphicsLibrary_(graphicsLibrary)
{
}

std::set<Action> PhysicalPlayer::update(GameState* state)
{
  std::set<Action> actions = std::set<Action>();
  if (graphicsLibrary_->isKeyDown(ENGINEBASE_KEY_W))
  {
    actions.insert(Action::MOVE_UP);
  }

  if (graphicsLibrary_->isKeyDown(ENGINEBASE_KEY_S))
  {
    actions.insert(Action::MOVE_DOWN);
  }

  if (graphicsLibrary_->isKeyDown(ENGINEBASE_KEY_A))
  {
    actions.insert(Action::MOVE_LEFT);
  }

  if (graphicsLibrary_->isKeyDown(ENGINEBASE_KEY_D))
  {
    actions.insert(Action::MOVE_RIGHT);
  }

  if (graphicsLibrary_->isKeyDown(ENGINEBASE_KEY_SPACE))
  {
    actions.insert(Action::SHOOT);
  }

  return actions;
}
