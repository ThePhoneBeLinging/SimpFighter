//
// Created by eal on 09/08-2025.
//

#include "LevelCreator.hpp"
#include "Utility/ConfigController.h"

void LevelCreator::createLevel(EngineBase* engineBase, GameState* gameState)
{
  int edgeWallWidth = 25;

  auto topWall = std::make_shared<Wall>(1200, edgeWallWidth);
  gameState->walls_.push_back(topWall);
  engineBase->registerDrawAble(topWall->drawAble_);
  topWall->drawAble_->setPosition(0, 0);

  auto bottomWall = std::make_shared<Wall>(1200, edgeWallWidth);
  gameState->walls_.push_back(bottomWall);
  engineBase->registerDrawAble(bottomWall->drawAble_);
  bottomWall->drawAble_->setPosition(0, 800 - edgeWallWidth);

  auto leftWall = std::make_shared<Wall>(edgeWallWidth, 800);
  gameState->walls_.push_back(leftWall);
  engineBase->registerDrawAble(leftWall->drawAble_);
  leftWall->drawAble_->setPosition(0, 0);

  auto rightWall = std::make_shared<Wall>(edgeWallWidth, 800);
  gameState->walls_.push_back(rightWall);
  engineBase->registerDrawAble(rightWall->drawAble_);
  rightWall->drawAble_->setPosition(1200 - edgeWallWidth, 0);
}

void LevelCreator::addPlayer(EngineBase* engineBase, GameState* gameState)
{
  auto character = std::make_shared<Character>();
  gameState->characters_.push_back(character);
  character->drawAble_->setPosition(200, 200);
  engineBase->registerDrawAble(character->drawAble_);
  if (playerCount_ == 0)
  {
    character->drawAble_->setPosition(100, 350);
  }
  else if (playerCount_ == 1)
  {
    character->drawAble_->setPosition(800, 350);
  }
  playerCount_++;
}
