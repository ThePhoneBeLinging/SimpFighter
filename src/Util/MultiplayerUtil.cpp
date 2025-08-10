//
// Created by eal on 10/08-2025.
//

#include "MultiplayerUtil.hpp"

#include <cstring>
#include <iostream>
#include <thread>
#include <unistd.h>

void MultiplayerUtil::connect(GameState* gameState)
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
  inet_pton(AF_INET, "158.179.205.63", &serverAddr.sin_addr);

  // Start receiving in a separate thread
  std::thread receiver(receive, gameState);
  receiver.detach();
}

void MultiplayerUtil::send(GameState* gameState)
{
  auto jsonObject = nlohmann::json::object();
  jsonObject["playerID"] = gameState->playerID_;
  jsonObject["playerX"] = static_cast<int>(gameState->characters_[gameState->playerID_]->drawAble_->getX());
  jsonObject["playerY"] = static_cast<int>(gameState->characters_[gameState->playerID_]->drawAble_->getY());

  std::string message = jsonObject.dump();
  if (lastSentString == message) { return; }
  lastSentString = message;

  sendto(socket_, message.c_str(), message.size(), 0,
         (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

std::set<Action> MultiplayerUtil::receive(GameState* gameState)
{
  auto jsonObject = nlohmann::json::object();
  jsonObject["playerID"] = gameState->playerID_;
  jsonObject["init"] = true;
  auto message = jsonObject.dump();
  sendto(socket_, message.c_str(), message.size(), 0,
         (struct sockaddr*)&serverAddr, sizeof(serverAddr));


  char buffer[1024];
  sockaddr_in fromAddr{};
  socklen_t fromLen = sizeof(fromAddr);
  std::chrono::time_point<std::chrono::high_resolution_clock> lastReceived = std::chrono::high_resolution_clock::now();

  while (true)
  {
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes = recvfrom(socket_, buffer, sizeof(buffer), 0,
                             (struct sockaddr*)&fromAddr, &fromLen);
    if (bytes > 0)
    {
      std::string bufferString = std::string(buffer);
      auto jsonObject = nlohmann::json::parse(bufferString);
      int playerID = jsonObject["playerID"].get<int>();
      if (jsonObject.contains("init") && not gameState->bothConnected)
      {
        auto sendJSONObject = nlohmann::json::object();
        gameState->playerID_ = playerID + 1;
        sendJSONObject["playerID"] = gameState->playerID_;
        sendJSONObject["response"] = true;
        message = sendJSONObject.dump();
        sendto(socket_, message.c_str(), message.size(), 0,
               (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        gameState->bothConnected = true;
        continue;
      }
      if (jsonObject.contains("response"))
      {
        gameState->bothConnected = true;
        continue;
      }
      if (jsonObject.contains("playerX") && jsonObject.contains("playerY"))
      {
        int playerX = jsonObject["playerX"].get<int>();
        int playerY = jsonObject["playerY"].get<int>();
        gameState->characters_[playerID]->drawAble_->setX(playerX);
        gameState->characters_[playerID]->drawAble_->setY(playerY);
      }
    }
  }
}
