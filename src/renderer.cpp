#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) 
 {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

        
  // Create Window
  /*Memory Mngt : feature no .2*/
  sdl_window = std::shared_ptr<SDL_Window> ( SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN), SDL_DestroyWindow );

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  
  /*Memory Mngt : feature no .2*/
  sdl_renderer = std::shared_ptr<SDL_Renderer> (SDL_CreateRenderer(sdl_window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_Quit();
}
/*This function is used to render te food and the snake*/
void Renderer::Render(std::shared_ptr<Snake> const snake, SDL_Point const &food) {
  
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer.get(), 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer.get());

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer.get(), 0xFF, 0xCC, 0x00, 0xFF);
  std::unique_lock<std::mutex> lockFood(_mtxRenderFood); //make lock before using the shared object food
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  lockFood.unlock(); //Unlock the mutex
  SDL_RenderFillRect(sdl_renderer.get(), &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
  std::unique_lock<std::mutex> lockSnake(_mtxRenderSnake); //make lock before using the shared object Snake
  for (SDL_Point const &point : snake->getBody()) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer.get(), &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake->getHead_x()) * block.w;
  block.y = static_cast<int>(snake->getHead_y()) * block.h;
  if (snake->getAlive()) {
    SDL_SetRenderDrawColor(sdl_renderer.get(), 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer.get(), 0xFF, 0x00, 0x00, 0xFF);
  }
  lockSnake.unlock(); //Unlock the mutex  
  SDL_RenderFillRect(sdl_renderer.get(), &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer.get());
}

/*This function is used to update the window title with the user score and the frames per second */
void Renderer::UpdateWindowTitle(int score, int fps) {

   std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
   SDL_SetWindowTitle(sdl_window.get(), title.c_str());
}
