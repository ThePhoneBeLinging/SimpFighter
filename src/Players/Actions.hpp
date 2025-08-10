//
// Created by eal on 08/08-2025.
//

#ifndef ACTIONS_HPP
#define ACTIONS_HPP
#include <string>
#include "nlohmann/json.hpp"

enum Action
{
  MOVE_UP = 0,
  MOVE_DOWN,
  MOVE_LEFT,
  MOVE_RIGHT,
  SHOOT
};

class ActionsHelper
{
public:
  static Action fromString(const std::string& str)
  {
    if (str == "MOVE_UP") return MOVE_UP;
    if (str == "MOVE_DOWN") return MOVE_DOWN;
    if (str == "MOVE_LEFT") return MOVE_LEFT;
    if (str == "MOVE_RIGHT") return MOVE_RIGHT;
    if (str == "SHOOT") return SHOOT;
    return SHOOT;
  }

  static std::string toString(const std::set<Action>& actions)
  {
    auto jsonObject = nlohmann::json::object();
    jsonObject["MOVE_UP"] = actions.contains(MOVE_UP);
    jsonObject["MOVE_DOWN"] = actions.contains(MOVE_DOWN);
    jsonObject["MOVE_LEFT"] = actions.contains(MOVE_LEFT);
    jsonObject["MOVE_RIGHT"] = actions.contains(MOVE_RIGHT);
    jsonObject["SHOOT"] = actions.contains(SHOOT);

    return jsonObject.dump();
  }

  static std::set<Action> actionsFromString(const std::string& jsonString)
  {
    std::set<Action> actions;
    auto jsonObject = nlohmann::json::parse(jsonString);
    for (const auto& item : jsonObject.items())
    {
      if (item.value())
      {
        actions.insert(ActionsHelper::fromString(item.key()));
      }
    }
    return actions;
  }
};

#endif //ACTIONS_HPP
