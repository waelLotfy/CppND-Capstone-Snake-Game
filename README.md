# Udacity C++ Nanodegree Program: Capstone 

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

In this project, I have improved the original classes, optimized the memory management and converted it from linear programming to multithreading programming.

## Contents
* Project Class Structure
* Dependencies for Running Locally
* Basic Build Insturctions
* Project Specification
  * README (All Rubric Points REQUIRED)
  * Compiling and Testing (All Rubric Points REQUIRED)
  * Loops, Functions, I/O
  * Object Oriented Programming
  * Memory Management
  * Concurrency

## Project Class Structure
* Src : Contains the all the source files 
  *
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`

## Added New Features 

## Memory Management

1. Pass the input parameters to the function "Snake::SnakeCell" by reference.
2. Convert the raw pointers for SDL_Window and SDL_Renderer to shared pointers.

## Object Oriented Programming

1. Convert all the data members of the class Snake from public to private and add the setters and getters for these data members.




