#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <thread>
#include <mutex>

/*This is an abstract class to be inheirted by all the game objects like the game and controller that have to launch threads*/
class GameObject {
 public:
    //  desctructor
    ~GameObject();
    
    // typical behaviour methods
    virtual void runThread()=0;
  
 protected: 
  
    std::vector<std::thread> threads;  // holds all threads that have been launched within this object
    static std::mutex _mtxSnake;       // mutex shared by all game objects for protecting the shared snake
    static std::mutex _mtxFood;        // mutex shared by all game objects for protecting the shared food
    static std::mutex _mtxCout;        // mutex shared by all game objects for protecting the shared cout
    static std::mutex _mtxRunning;     // mutex shared by all game objects for protecting the shared running Flag
  
 private:
  
};

#endif