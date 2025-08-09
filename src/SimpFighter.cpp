//
// Created by eal on 08/08-2025.
//

#include "SimpFighter.hpp"
#include <iostream>
#include <thread>

#include "Util/LevelCreator.hpp"
#include "TextureLocations.h"
#include "Players/SimpAI.hpp"
#include "Util/CollisionController.hpp"
#include "Utility/ConfigController.h"

SimpFighter::SimpFighter() : engineBase_(std::make_unique<EngineBase>()), gameState_(std::make_unique<GameState>())
{
  ConfigController::loadConfig("../config.json");

  std::cout << "EngineBase initialized!\n";
  engineBase_->registerUpdateFunction([&](double deltaTime)
  {
    this->update(deltaTime);
  });

  playerVector_.push_back(std::make_unique<PhysicalPlayer>(0, engineBase_->getGraphicsLibrary().get()));
  LevelCreator::addPlayer(engineBase_.get(), gameState_.get());

  playerVector_.push_back(std::make_unique<SimpAI>(1));
  LevelCreator::addPlayer(engineBase_.get(), gameState_.get());

  LevelCreator::createLevel(engineBase_.get(), gameState_.get());

  engineBase_->getGraphicsLibrary()->setTargetFPS(300);
  startPoint_ = std::chrono::high_resolution_clock::now();
  engineBase_->launch();
}

void SimpFighter::update(const double deltaTime)
{
  for (const auto& player : playerVector_)
  {
    auto actions = player->update(gameState_.get());
    gameState_->characters_[player->getID()]->handleAction(deltaTime, actions, gameState_.get(), engineBase_.get());
  }

  for (const auto& projectile : gameState_->projectiles_)
  {
    projectile->update(deltaTime);
  }

  CollisionController::handleCollisions(gameState_.get());

  if (gameState_->characters_[0]->health_ <= 0)
  {
    result = -1;
    engineBase_->getGraphicsLibrary()->closeWindow();
  }
  else if (gameState_->characters_[1]->health_ <= 0)
  {
    result = 1;
    engineBase_->getGraphicsLibrary()->closeWindow();
  }

  const std::chrono::high_resolution_clock::time_point timerEnd = std::chrono::high_resolution_clock::now();
  const auto totalDuration = std::chrono::duration_cast<std::chrono::seconds>(timerEnd - startPoint_);
  if (totalDuration.count() > ConfigController::getConfigInt("MaxGameTime"))
  {
    engineBase_->getGraphicsLibrary()->closeWindow();
  }

  // Target 200 ticks
  auto timeLeft_microsec = (int)((0.01 - deltaTime) * 1000000);

  if (timeLeft_microsec > 0)
  {
    std::this_thread::sleep_for(std::chrono::microseconds(timeLeft_microsec));
  }
}


