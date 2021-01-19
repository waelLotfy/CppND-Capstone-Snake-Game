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

  void Update();

  void GrowBody();
  bool SnakeCell(int const &x, int const &y);

  //Direction direction = Direction::kUp;
  Direction getDirection() const;  /*Object oriented :Feature 1 */
  void setDirection(Direction d) ; /*Object oriented :Feature 1 */
  
  void incrementSpeed(float s); /*Object oriented :Feature 1 */
  int getSize() const;          /*Object oriented :Feature 1 */
  bool getAlive() const ;       /*Object oriented :Feature 1 */
  std::vector<SDL_Point> getBody() const;/*Object oriented :Feature 1 */
  float getHead_x() const;/*Object oriented :Feature 1 */
  float getHead_y() const;/*Object oriented :Feature 1 */
  //float speed{0.1f};
  //int size{1};
  //bool alive{true};
  //float head_x;
  //float head_y;
  //std::vector<SDL_Point> body;
  
  
 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
  
  Direction direction = Direction::kUp; /*Object oriented :Feature 1 */
  float speed{0.1f};/*Object oriented :Feature 1 */
  int size{1};      /*Object oriented :Feature 1*/
  bool alive{true}; /*Object oriented :Feature 1*/
  std::vector<SDL_Point> body;/*Object oriented :Feature 1*/
  
  float head_x;
  float head_y;

};

#endif