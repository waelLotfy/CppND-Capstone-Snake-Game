#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "gameObject.h"

/*New Feature Added : A thread for handling the input control for the snake*/
/*Class controller inherits the abstract class Gameobject and overrides its pure virtual function */
class Controller : public GameObject
{
 
 public:
      
  // typical behaviour methods
  void runThread() override;   // launch control input function in a thread
  
  /*New Feature Added : A thread for handling the inpit control for the snake*/
  /* This method is used as a thread for checking if there is input for controlling the snake. */
  void controlInput() ; 

  void setSnake(std::shared_ptr<Snake> const &s); /*To get the snake from the controller*/ /*New Feature Added : A thread for handling the input control for the snake*/
  
  void setTargetFrameDuration(std::size_t const &t); /*To get the target_frame_duration from the controller*/ /*New Feature Added : A thread for handling the inpit control for the snake*/
  
  
  bool getRunning() const;
 
  
 private:
  void HandleInput(bool &running) const;/*This function is responsible checking the SDL Event to decide if the window should be quited or there is a new change for the snake position*/
 
  void ChangeDirection(Snake::Direction input,
                       Snake::Direction opposite) const;
                       
  std::shared_ptr<Snake> snake;/*Shared pointer to the snake*/
  
  std::size_t target_frame_duration;/*It is used in the calculation the frame time control duration*/
  
  bool running{true} ; /*It is a flag indicates the user is still playing or terminating the game */
  
};

#endif