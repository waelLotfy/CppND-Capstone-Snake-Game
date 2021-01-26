#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "gameObject.h"
#include <memory>

class Renderer 
{
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  /*This function is used to render te food and the snake*/
  void Render(std::shared_ptr<Snake> const snake, SDL_Point const &food);
  /*This function is used to update the window title with the user score and the frames per second */
  void UpdateWindowTitle(int score, int fps);
  
  
 private:
  
  std::shared_ptr<SDL_Window> sdl_window;     /*Memory Mngt : feature no .2*/
  
  std::shared_ptr<SDL_Renderer> sdl_renderer; /*Memory Mngt : feature no .2*/

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  
  std::mutex _mtxRenderFood; /*It is used to lock on the food shared resource between renderer object and game object*/
  std::mutex _mtxRenderSnake;/*It is used to lock on the snake shared resource between renderer object, controller and game object*/

  
};

#endif