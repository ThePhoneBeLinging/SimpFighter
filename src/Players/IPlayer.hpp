//
// Created by eal on 08/08-2025.
//

#ifndef IPLAYER_HPP
#define IPLAYER_HPP
#include <set>
#include "Actions.hpp"
#include "../GameState.hpp"

class IPlayer
{
public:
  explicit IPlayer(const int id) : id_(id)
  {
  }

  virtual ~IPlayer() = default;
  virtual std::set<Action> update(GameState* state) = 0;
  int getID() { return id_; }

protected:
  int id_;
};


#endif //IPLAYER_HPP


// Game -> PhysicalPlayer -> Game -> CharacterPlayer
