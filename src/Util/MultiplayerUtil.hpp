//
// Created by eal on 10/08-2025.
//

#ifndef MULTIPLAYERUTIL_HPP
#define MULTIPLAYERUTIL_HPP
#include <set>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "Model/GameState.hpp"
#include "Players/Actions.hpp"


class MultiplayerUtil
{
public:
  static void connect(Character* onlineCharacter);
  static void send(const std::set<Action>& actions);
  static std::set<Action> receive(Character* onlineCharacter);

private:
  static inline int socket_ = 0;
  static inline sockaddr_in serverAddr{};
};


#endif //MULTIPLAYERUTIL_HPP
