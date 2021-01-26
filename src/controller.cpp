#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::setSnake(std::shared_ptr<Snake> const &s) /*To get the sanke from the controller*/
{
  snake = s;
}

void Controller::setTargetFrameDuration(std::size_t const &t) /*To get the target_frame_duration from the controller*/
{
  target_frame_duration = t ;
}
/*The following function is used by the class game to get the running flag status from the cotroller*/
bool Controller::getRunning() const
{
  std::lock_guard<std::mutex> lock(_mtxRunning);//make lock before reading the flag running
  return running;
}

void Controller::runThread()
{
  // launch control input function in a thread
  threads.emplace_back(std::thread(&Controller::controlInput, this));
}
/*This is a thread function that is reposible for handling the snake input control*/
void Controller::controlInput() 
{
  
  Uint32 title_timestamp = SDL_GetTicks(); /*Record the start time for input control*/
  
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
   
  while (running) {  /*while the SDL Quit is not pressed, the running flag is always true*/
    
    // sleep at every iteration to reduce CPU usage
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    frame_start = SDL_GetTicks(); /*Record the start time before the controller input*/
    Controller::HandleInput(running); /*Call the input control function*/
    frame_end = SDL_GetTicks(); /*Record the end time before the controller input*/

    frame_duration = frame_end - frame_start; /*Calculate the duration for handling the input control*/

    
    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate. to be removed .
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }

}


void Controller::ChangeDirection(Snake::Direction input,
                                 Snake::Direction opposite) const {
  
  std::unique_lock<std::mutex> lockSnake(_mtxSnake); //make lock before using the Snake as it is shared resource with the objects game and render
  if (snake->getDirection() != opposite || snake->getSize() == 1) 
  {
    snake->setDirection(input);
    
  }
  lockSnake.unlock();
  return;
}

/*This function is responsible checking the SDL Event to decide if the window should be quited or there is a new change for the snake position*/
/*The input parameter running flag is set to false when the game is terminted by the user*/
void Controller::HandleInput(bool &running) const {  
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) { /*The user press quit in the game screen*/
      
      std::unique_lock<std::mutex> lock(_mtxRunning);//make lock on the running flag because it is shared with the object game that gets the runnning flag through the function Controller::getRunning().
      running = false;
      lock.unlock();
      
      std::unique_lock<std::mutex> lck(_mtxCout); //make lock before using the shared cout
      std::cout<< "running flag due to SDL_QUIT is " << running << std::endl;
      lck.unlock();
  
    } else if (e.type == SDL_KEYDOWN) { /*otherwise check if the user has changed the snake position with the four arrows on the keynoard*/
      switch (e.key.keysym.sym) {
          /*in case any arrow is pressed, then the pressed direction and its oppsite direction is sent to the function ChangeDirection*/
        case SDLK_UP:
          ChangeDirection(Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
  

}