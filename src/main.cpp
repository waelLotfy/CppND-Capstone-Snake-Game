#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  /*The Game parameters*/
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight); /*Creating an object for rendering the game screen*/
  Controller controller;/*Creating an object for controlling the input */
  Game game(kGridWidth, kGridHeight); /*Creating an object for running the game loop, start all the threads. */
  game.Run(controller, renderer, kMsPerFrame);/*Start Game running*/
  std::cout << "Game has terminated successfully!\n";/*Display Game is over*/
  std::cout << "Score: " << game.GetScore() << "\n"; /*Display the user score*/
  std::cout << "Size: " << game.GetSize() << "\n";  /*Display the Snake size*/
  return 0;
}