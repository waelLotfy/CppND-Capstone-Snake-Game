#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : engine(dev()),
      random_w(2, static_cast<int>(grid_width) - 2 ),
      random_h(2, static_cast<int>(grid_height)- 2 ),
      snake ( std::make_shared<Snake> (grid_width, grid_height) )
      
{
    PlaceFood();/*Put the food*/
}
void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  
  /*New Feature Added : A thread for handling the input control for the snake*/
  controller.setSnake(snake); /*The controller takes a shared pointer to the snake*/
  controller.setTargetFrameDuration(target_frame_duration); /*The controller takes the target frame duration*/
  controller.runThread();/*Start running the input control thread for the snake*/
  
  
  /*New Feature Added : A thread for handling the update*/
  game_target_frame_duration = target_frame_duration;/*save the target frame duration*/
  runThread();/*Start running the thread for updating the snake and the food*/
  
  while (running) { /*if the flag running is true and the user is not terminted the game yet*/
    frame_start = SDL_GetTicks();

    
    renderer.Render(snake, food);
    
    frame_end = SDL_GetTicks();
    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
    
    running = controller.getRunning(); /*Get the running flag status from the controller*/
    /*when the user termintes the game, the controller sets the running flag to false*/
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}
/*Start the thread for updating the food and snake positions */
void Game::runThread()
{
  // launch control input function in a thread
  threads.emplace_back(std::thread(&Game::UpdateGame, this));
  
}
/*Updates the whole game status like the snake, food and score.*/
void Game::UpdateGame() {
  
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  
  while (running){ /*if the flag running is true and the user is not terminted the game yet*/
  // sleep at every iteration to reduce CPU usage
  std::this_thread::sleep_for(std::chrono::milliseconds(1));

  frame_start = SDL_GetTicks();
    
  std::unique_lock<std::mutex> lck(_mtxSnake); //make lock before using the shared object snake
  if (!snake->getAlive()) return;

  snake->Update(); /*Update the snake head and body */

  int new_x = static_cast<int>(snake->getHead_x());
  int new_y = static_cast<int>(snake->getHead_y());

  
  std::unique_lock<std::mutex> lckfood(_mtxFood); //make lock before using the shared objects food 
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();/*Place new food*/
    // Grow snake and increase speed.
    snake->GrowBody();
    snake->incrementSpeed(0.02) ;
  }
  lckfood.unlock();
  lck.unlock();  
  frame_end = SDL_GetTicks();
    
  frame_duration = frame_end - frame_start;

    
    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
  if (frame_duration < game_target_frame_duration) {
      SDL_Delay(game_target_frame_duration - frame_duration);
    }
    
  }//end while loop
}
/*Get the game score*/
int Game::GetScore() const { return score; }

/*Get the snake length*/
int Game::GetSize() const { return snake->getSize(); }