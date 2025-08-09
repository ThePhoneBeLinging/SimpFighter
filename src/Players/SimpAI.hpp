//
// Created by eal on 09/08-2025.
//

#ifndef SIMPAI_HPP
#define SIMPAI_HPP
#include <random>

#include "IPlayer.hpp"


class SimpAI : public IPlayer
{
public:
  explicit SimpAI(int id);
  std::set<Action> update(GameState* state) override;
};


#endif //SIMPAI_HPP
