#include "gameObject.h"
#include <iostream>
#include <algorithm>


//std::mutex GameObject::_mtx;
std::mutex GameObject::_mtxSnake;       // mutex shared by all game objects for protecting the shared snake
std::mutex GameObject::_mtxFood;        // mutex shared by all game objects for protecting the shared food
std::mutex GameObject::_mtxCout;        // mutex shared by all game objects for protecting the shared cout
std::mutex GameObject::_mtxRunning;     // mutex shared by all game objects for protecting the shared SDL


GameObject::~GameObject()
{
    // set up thread barrier before this object is destroyed
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
}
