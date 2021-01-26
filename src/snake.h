#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();/*Update the snake head and body positions */

  void GrowBody();/*increase the snake size*/
  bool SnakeCell(int const &x, int const &y);/*check the current snake cell is the same like the input parameters*/

  
  Direction getDirection() const;  // get the snake direction /*Object oriented :Feature 1 */
  void setDirection(Direction d) ; // set the snake direction /*Object oriented :Feature 1 */
  
  void incrementSpeed(float s); // increment the snake speed /*Object oriented :Feature 1 */
  int getSize() const;          // get the snake size /*Object oriented :Feature 1 */
  bool getAlive() const ;       //Check if the snake is still alive/*Object oriented :Feature 1 */
  std::vector<SDL_Point> getBody() const; //get the Snake body points/*Object oriented :Feature 1 */
  float getHead_x() const;//get the snake head x coordinate /*Object oriented :Feature 1 */
  float getHead_y() const;//get the snake head y coordinate /*Object oriented :Feature 1 */
  
 private:
  void UpdateHead();//update the snake head position
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);//update the snake body position

  bool growing{false}; //flag that indicates the growing status for the snake.
  int grid_width;
  int grid_height;
  
  Direction direction = Direction::kUp; //initial snake direction /*Object oriented :Feature 1 */
  float speed{0.1f}; //Snake Speed /*Object oriented :Feature 1 */
  int size{1};      //Snake Size /*Object oriented :Feature 1*/
  bool alive{true}; //flag indicates if the snake is still alive/*Object oriented :Feature 1*/
  std::vector<SDL_Point> body;//Snake body coordinates /*Object oriented :Feature 1*/
  
  float head_x; //Snake head x coordinate
  float head_y; //Snake head x coordinate
  

};

#endif