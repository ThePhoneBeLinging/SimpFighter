#include <iostream>

#include "src/SimpFighter.hpp"

int main()
{
  auto game = SimpFighter();

  if (game.result > 0)
  {
    std::cout << "Player 1 Won" << std::endl;
  }
  else if (game.result < 0)
  {
    std::cout << "Player 2 Won" << std::endl;
  }
  else
  {
    std::cout << "Draw" << std::endl;
  }

  return 0;
}
