//
// Created by eal on 08/08-2025.
//

#include "SimpFighter.hpp"
#include <iostream>
#include <thread>
#include "TextureLocations.h"

SimpFighter::SimpFighter() : engineBase_(std::make_unique<EngineBase>()), player_(std::make_unique<Player>())
{
  std::cout << "EngineBase initialized!\n";
  engineBase_->registerUpdateFunction([&](double deltaTime)
  {
    this->update(deltaTime);
  });
  engineBase_->getGraphicsLibrary()->setTargetFPS(60);

  engineBase_->registerDrawAble(player_->drawAble_);

  engineBase_->launch();
}

void SimpFighter::update(double deltaTime)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}


