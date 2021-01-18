#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const &snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  //SDL_Window *sdl_window;
  std::shared_ptr<SDL_Window> sdl_window; /*Memory Mngt : feature no .2*/
  //SDL_Renderer *sdl_renderer;
  std::shared_ptr<SDL_Renderer> sdl_renderer; /*Memory Mngt : feature no .2*/

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif