#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <memory>
#include <future>
#include "gameObject.h"

/*New Feature Added : A thread for handling the game update*/
/*Class Game inherits the abstract class Gameobject and overrides its pure virtual function */
class Game : public GameObject
{
 public:
  Game(std::size_t grid_width, std::size_t grid_height); /*Constructor*/
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration); /*Start the game running*/
  int GetScore() const;/*Get the user score*/
  int GetSize() const; /*Get the Snake size*/

  // typical behaviour methods
  /*Launch a thread for updating the game status*/
  void runThread() override; /*New Feature Added : A thread for handling the Game update.*/

 private:
  std::shared_ptr<Snake> snake;
  SDL_Point food;
  std::size_t game_target_frame_duration;/*New Feature Added : A thread for handling the update*/
  bool running{true}; /*The flag for running the game*/

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0}; /*The user score*/

  void PlaceFood(); /*Place food when the game is started and during the game update*/
  void UpdateGame(); /*Updating the game status*/
};

#endif