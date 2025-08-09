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

  auto leftTargetWall = std::make_shared<Wall>(edgeWallWidth, 200);
  leftTargetWall->drawAble_->setPosition(250, 300);
  engineBase->registerDrawAble(leftTargetWall->drawAble_);
  gameState->walls_.push_back(leftTargetWall);

  auto rightTargetWall = std::make_shared<Wall>(edgeWallWidth, 200);
  rightTargetWall->drawAble_->setPosition(1200 - 250 - edgeWallWidth, 300);
  engineBase->registerDrawAble(rightTargetWall->drawAble_);
  gameState->walls_.push_back(rightTargetWall);

  auto middleWall = std::make_shared<Wall>(300, edgeWallWidth);
  middleWall->drawAble_->setPosition(600 - (middleWall->drawAble_->getWidth() / 2), 400 - edgeWallWidth / 2);
  engineBase->registerDrawAble(middleWall->drawAble_);
  gameState->walls_.push_back(middleWall);
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
    character->drawAble_->setPosition(1000, 350);
  }
  playerCount_++;
}
