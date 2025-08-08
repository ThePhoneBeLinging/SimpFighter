//
// Created by eal on 08/08-2025.
//

#include "SimpFighter.hpp"
#include <iostream>
#include <thread>
#include "TextureLocations.h"
#include "Utility/ConfigController.h"

SimpFighter::SimpFighter() : engineBase_(std::make_unique<EngineBase>()), gameState_(std::make_unique<GameState>())
{
  ConfigController::loadConfig("../config.json");

  std::cout << "EngineBase initialized!\n";
  engineBase_->registerUpdateFunction([&](double deltaTime)
  {
    this->update(deltaTime);
  });
  engineBase_->getGraphicsLibrary()->setTargetFPS(300);
  for (int i = 0; i < ConfigController::getConfigInt("AmountOfPlayers"); i++)
  {
    playerVector_.push_back(std::make_unique<PhysicalPlayer>(i, engineBase_->getGraphicsLibrary().get()));
    gameState_->characters_.push_back(std::make_unique<Character>());
    engineBase_->registerDrawAble(gameState_->characters_.back()->drawAble_);
  }

  engineBase_->launch();
}

void SimpFighter::update(const double deltaTime)
{
  // Target 200 ticks

  auto timeLeft_microsec = (int)((0.01 - deltaTime) * 1000000);

  if (timeLeft_microsec > 0)
  {
    std::this_thread::sleep_for(std::chrono::microseconds(timeLeft_microsec));
  }

  for (const auto& player : playerVector_)
  {
    auto actions = player->update(gameState_.get());
    gameState_->characters_[player->getID()]->handleAction(deltaTime, actions, gameState_.get());
  }
}


