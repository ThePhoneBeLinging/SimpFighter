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
  static void connect(GameState* gameState);
  static void send(GameState* gameState);
  static std::set<Action> receive(GameState* gameState);

private:
  static inline int socket_ = 0;
  static inline sockaddr_in serverAddr{};
  static inline std::string lastSentString;
};


#endif //MULTIPLAYERUTIL_HPP
