//
// Created by eal on 10/08-2025.
//

#include "MultiplayerUtil.hpp"

#include <cstring>
#include <iostream>
#include <thread>
#include <unistd.h>

void MultiplayerUtil::connect(Character* onlineCharacter)
{
  socket_ = socket(AF_INET, SOCK_DGRAM, 0);
  if (socket_ < 0)
  {
    perror("socket");
  }

  // Bind to any available port (needed to receive broadcasts from server)
  sockaddr_in localAddr{};
  localAddr.sin_family = AF_INET;
  localAddr.sin_addr.s_addr = INADDR_ANY;
  localAddr.sin_port = 0; // let OS choose
  if (bind(socket_, (struct sockaddr*)&localAddr, sizeof(localAddr)) < 0)
  {
    perror("bind");
    close(socket_);
  }

  // Server address
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(19999);
  inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

  // Start receiving in a separate thread
  std::thread receiver(receive, onlineCharacter);
  receiver.detach();
}

void MultiplayerUtil::send(const std::set<Action>& actions)
{
  std::string message = ActionsHelper::toString(actions);
  sendto(socket_, message.c_str(), message.size(), 0,
         (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

std::set<Action> MultiplayerUtil::receive(Character* onlineCharacter)
{
  char buffer[1024];
  sockaddr_in fromAddr{};
  socklen_t fromLen = sizeof(fromAddr);

  while (true)
  {
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes = recvfrom(socket_, buffer, sizeof(buffer), 0,
                             (struct sockaddr*)&fromAddr, &fromLen);
    if (bytes > 0)
    {
      std::string bufferString = std::string(buffer);
      if (bufferString.size() < 150)
      {
        auto action = ActionsHelper::actionsFromString(buffer);
        onlineCharacter->handleAction(0.01, action, nullptr, nullptr);
      }
    }
  }
}
