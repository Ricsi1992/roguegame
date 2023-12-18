#include "GameEngine.hpp"
#include <iostream>

namespace game
{

int GameEngine::run() 
{
    init();
    gameLoop();
    return finish();
}

void GameEngine::init()
{

}

void GameEngine::gameLoop()
{
    std::cout << "Hello world" << std::endl;
}

void GameEngine::handleInput()
{

}

void GameEngine::update()
{

}

void GameEngine::render()
{

}

int GameEngine::finish()
{
    return 0;
} 

}