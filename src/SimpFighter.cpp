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
#include "Util/MultiplayerUtil.hpp"
#include "Utility/ConfigController.h"
#include "Utility/Timer.h"

SimpFighter::SimpFighter() : engineBase_(std::make_unique<EngineBase>()), gameState_(std::make_unique<GameState>()),
                             player_(std::make_unique<PhysicalPlayer>(0, engineBase_->getGraphicsLibrary().get()))
{
  ConfigController::loadConfig("../config.json");

  std::cout << "EngineBase initialized!\n";
  engineBase_->registerUpdateFunction([&](double deltaTime)
  {
    this->update(deltaTime);
  });
  LevelCreator::addPlayer(engineBase_.get(), gameState_.get());
  LevelCreator::addPlayer(engineBase_.get(), gameState_.get());
  LevelCreator::createLevel(engineBase_.get(), gameState_.get());
  waitingDrawable_ = std::make_shared<DrawAble>();
  waitingDrawable_->setTextureLocation(&TextureLocation::waiting);
  waitingDrawable_->setSize(500, 500);
  waitingDrawable_->setPosition(350, 800 - 750);
  engineBase_->registerDrawAble(waitingDrawable_);

  MultiplayerUtil::connect(gameState_.get());


  engineBase_->getGraphicsLibrary()->setTargetFPS(300);
  engineBase_->launch();
}

void SimpFighter::update(const double deltaTime)
{
  if (not gameState_->bothConnected)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return;
  }
  else if (gameState_->firstUpdate)
  {
    startPoint_ = std::chrono::high_resolution_clock::now();
    player_ = std::make_unique<PhysicalPlayer>(gameState_->playerID_, engineBase_->getGraphicsLibrary().get());
    waitingDrawable_ = nullptr;
    gameState_->firstUpdate = false;
  }
  auto actions = player_->update(gameState_.get());
  gameState_->characters_[player_->getID()]->handleAction(deltaTime, actions, gameState_.get(), engineBase_.get());
  MultiplayerUtil::send(gameState_.get());

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


