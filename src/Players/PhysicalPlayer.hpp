//:
// Created by eal on 08/08-2025.
//

#ifndef PHYSICALPLAYER_HPP
#define PHYSICALPLAYER_HPP
#include "IPlayer.hpp"
#include "EngineBase/EngineBase.h"

class PhysicalPlayer : public IPlayer
{
public:
  PhysicalPlayer(int id, IGraphicsLibrary* graphicsLibrary);
  std::set<Action> update(GameState* state) override;

private:
  IGraphicsLibrary* graphicsLibrary_;
};


#endif //PHYSICALPLAYER_HPP
