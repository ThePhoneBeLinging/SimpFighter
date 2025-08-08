//
// Created by eal on 08/08-2025.
//

#include "SimpFighter.hpp"
#include <iostream>
#include <thread>

SimpFighter::SimpFighter() : engineBase_(std::make_unique<EngineBase>())
{
  std::cout << "EngineBase initialized!\n";
  engineBase_->registerUpdateFunction([&](double deltaTime)
  {
    this->update(deltaTime);
  });
  engineBase_->getGraphicsLibrary()->setTargetFPS(60);
  engineBase_->launch();
}

void SimpFighter::update(double deltaTime)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << "Hello from Update" << std::endl;
}


