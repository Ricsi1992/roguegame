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
    while (!quit)
    {
        handleInput();
        render();
    }
}

void GameEngine::handleInput()
{
    char input;
    std::cin >> input;

    switch (input)
    {
    case 'w':
        --y;
        break;
    case 's':
        ++y;
        break;
    case 'a':
        --x;
        break;
    case 'd':
        ++x;
        break;
    case 'q':
        quit = true;
        break;
    default:
        break;
    }
}

void GameEngine::update()
{

}

void GameEngine::render()
{
    for(int height = 0; height < y - 1; ++height) {
        std::cout << std::endl;
    }

    for(int width = 0; width < x - 1; ++width) {
        std::cout << " ";
    }
    std::cout << "@";
    std::cout << std::endl;
}

int GameEngine::finish()
{
    return 0;
} 

}