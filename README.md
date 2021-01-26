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
  * Object Oriented Programming
  * Memory Management
  * Concurrency

## Project Class Structure
* Src : Contains the all the source files 
  * Controller.h : The header file defines all the class controller attributes, and methods which are responsible for getting the input from the user and update the position of the snake.
  * Controller.cpp : The source file that implements the defined methods in the Controller header file.
  * Game.h : The header file defines all the class game attributes, and methods which are resposible for starting the the threads for the input control and game status update and for rendering the game.
  * Game.cpp : The source file that implements the defined methods in the Game header file.
  * GameObject.h : The header file contains an abstract class used as base class for the classes that need to run threads and deines its attributes and methods.
  * GameObject.cpp : The source file contains the implementation for the methods defined in the GameObject header file.
  * main.cpp : The source file contains the main used to compile the file.
  * Renderer.h : The header file contains the class renderer with its attributes and methods used for rendering the screen.
  * Renderer.cpp : The source file contains the implementations for the defined methods in the Renderer header file.
  * Snake.h : The header file contains the Class Snake with its attributes and methods.
  * Snake.cpp : The source file contains the implementations for the defined methods in the Snake header file.
 * Build : It is used to build the project and run the game.
 * Cmake 
 * CMAKELists.txt : 
   * The new files (e.g. gameObject.cpp) should be added to this text.
   * For running the threads , this line should be added " set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread") "
 * README.md
 
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

## Project Specification

## README (All Rubric Points REQUIRED)

| Criteria                                                | Meets Specifications | Status | Address |
| ------------------------------------------------------- | -------------------- |--------|---------|
| A README with instructions is included with the project | The README is included with the project and has instructions for building/running the project.If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions.You can submit your writeup as markdown or pdf.|Done|README.md
| The README indicates which project is chosen.| The README describes the project you have built.The README also indicates the file and class structure, along with the expected behavior or output of the program.|Done|README.md
|The README includes information about each rubric point addressed.|The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.|Done|README.md

## Compiling and Testing (All Rubric Points REQUIRED)
| Criteria                                                | Meets Specifications | Status | Address |
| ------------------------------------------------------- | -------------------- |--------|---------|
| The submission must compile and run. | The project code must compile and run without errors.We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must compile on any reviewer platform.|Done|README.md

## Object Oriented Programming
| Criteria                                                | Meets Specifications | Status | Address |
| ------------------------------------------------------- | -------------------- |--------|---------|
| Classes abstract implementation details from their interfaces.| All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.|Done| 1. I have added commments for all the original and new added code. 2. I have selected the appropriate function names. 3. Example : UpdateGame in file gameh.h at line 42
| Classes encapsulate behavior. | Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions. | Done | In Class Snake, I modified all the data varaibales to have the access modifier private and implemented the setters and getters for every attribute under the public access modifier. For example, there are setters and getters functions from lines 23 to 31 in the file snake.h.
|Classes follow an appropriate inheritance hierarchy.|Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.|Done|The class GameObject is an abstract class that inherited by the classes Controller and Game. It contains one pure function runThread at line 15 in gameObject.h.
|Derived class functions override virtual base class functions.|One member function in an inherited class overrides a virtual base class member function.|Done|The class Controller and class Game overrides the pure function runThread at lines 22 and 79 in the files controller.cpp and game.cpp respectively.

## Memory Management
| Criteria                                                | Meets Specifications | Status | Address |
| ------------------------------------------------------- | -------------------- |--------|---------|
| The project makes use of references in function declarations.| At least two variables are defined as references, or two functions use pass-by-reference in the project code.|Done|1.The function SnakeCell at line 20 in file snake.h has been modified to have the two input parameters passed by reference. 2.The function setSnake in file controller.h at line 21 has input parameter passed by reference. 3.The function setTargetFrameDuration in file controller.h at line 23 has input parameter passed by reference.
| The project uses smart pointers instead of raw pointers.|The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.|Done| The attributes sdl_window and sdl_renderer at lines 25 and 27 respectively in the header file renderer.h are modified from raw pointers to shared pointers.

## Concurrency
| Criteria                                                | Meets Specifications | Status | Address |
| ------------------------------------------------------- | -------------------- |--------|---------|
|The project uses multithreading.|The project uses multiple threads in the execution.|Done|1. There is a thread for handling the input control that is launched inside the function Controller::runThread at line 25 in the file controller.cpp. 2. There is another thread for updating the game status that is launched inside the function Game::runThread at line 79 in the file game.cpp.
|A mutex or lock is used in the project.|A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.|Done|1.There are mutex _mtxSnake, _mtxFood, _mtxCout, _mtxRunning defined in class GameObject. 2. The _mtxSnake is used to make lock for the snake object when it is accessed in the classes Controller (e.g. in Controller::ChangeDirection at line 60) and Game (e.g. Game::UpdateGame at line 79). Besides that, the private _mtxRenderSnake in class Renderer is used to make the lock for the snake object in the class Renderer (e.g. Renderer::Render at line 65 in renderer.cpp). 3. The _mtxFood is used to make lock for the food object when it is accessed in the classe Game (e.g. Game::UpdateGame at line 108 in game.cpp) while the private _mtxRenderFood in class Renderer is used to make the lock for the food object in the class Renderer (e.g. Renderer::Render at line 45 in renderer.cpp). 3.The _mtxRunning is used to make lock on the running flag before it is accessed in the function Controller::HandleInput in the file Controller.cpp at line 80 (this function is called by a thread) and in the function Controller::getRunning in the file Controller.cpp at line 18 (this function is called by Game::Run to read the running flag status from the class controller). 4. The _mtxCout is used to make lock before using the standard cout in the function Controller::HandleInput at line 84 in the file Controller.cpp. 






   



