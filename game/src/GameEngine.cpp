#include "GameEngine.hpp"
#include <iostream>
#include <sstream>
#include <random>
#include <windows.h>

namespace game
{
using namespace std::chrono_literals;
constexpr std::chrono::nanoseconds timeStep(50ms);
#define IS_PRESSED 0x8000

int GameEngine::run() 
{
    init();
    gameLoop();
    return finish();
}

void GameEngine::init()
{
    currentTime = std::chrono::high_resolution_clock::now();

    std::default_random_engine generator(currentTime.time_since_epoch().count());
    std::uniform_int_distribution<int> distWidth(1, gameState.getCurrentGameState()->map.width - 1);
    std::uniform_int_distribution<int> distHeight(1, gameState.getCurrentGameState()->map.height - 1);

    gameState.getCurrentGameState()->map.end.x = distWidth(generator);
    gameState.getCurrentGameState()->map.end.y = distHeight(generator);
}

void GameEngine::gameLoop()
{
    std::chrono::nanoseconds lag(0ns);
    while (!gameState.getCurrentGameState()->quit)
    {
        auto deltaTime = std::chrono::high_resolution_clock::now() - currentTime;
        currentTime = std::chrono::high_resolution_clock::now();
        lag += std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime);

        while (lag >= timeStep)
        {
            lag -= timeStep;
            handleInput();
            update();
            render();
        }
    }
}

void GameEngine::handleInput()
{
    if (GetKeyState('W') & IS_PRESSED)
    {
        gameState.setPlayerPositionY(gameState.getPlayerPosition().y - 1);
    }
    else if (GetKeyState('S') & IS_PRESSED)
    {
        gameState.setPlayerPositionY(gameState.getPlayerPosition().y + 1);
    }
    else if (GetKeyState('A') & IS_PRESSED)
    {
        gameState.setPlayerPositionX(gameState.getPlayerPosition().x - 1);
    }
    else if (GetKeyState('D') & IS_PRESSED)
    {
        gameState.setPlayerPositionX(gameState.getPlayerPosition().x + 1);
    }
    else if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::START 
    && GetKeyState(VK_SPACE) & IS_PRESSED)
    {
        gameState.setCurrentGameStateEnum(GameStateEnum::PLAY);
    }
    
}

void GameEngine::update()
{
    if (gameState.getCurrentGameState()->playerPosition.x == 0)
    {
        gameState.setPlayerPositionX(1);
    }
    else if (gameState.getCurrentGameState()->playerPosition.x == gameState.getCurrentGameState()->map.width - 1)
    {
        gameState.setPlayerPositionX(gameState.getCurrentGameState()->map.width - 2);
    }

    if (gameState.getCurrentGameState()->playerPosition.y == 0)
    {
        gameState.setPlayerPositionY(1);
    }
    else if (gameState.getCurrentGameState()->playerPosition.y == gameState.getCurrentGameState()->map.height - 1)
    {
        gameState.setPlayerPositionY(gameState.getCurrentGameState()->map.height - 2);
    }

    if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::PLAY 
        && gameState.getCurrentGameState()->playerPosition == gameState.getCurrentGameState()->map.end)
    {
        gameState.setCurrentGameStateEnum(GameStateEnum::WIN);
    }
    
    
    
}

void GameEngine::render()
{
    if (!gameState.isChanged())
    {
        return;
    }

    if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::PLAY)
    {
        system("cls");
        std::stringstream ss;

        for(int height = 0; height < gameState.getCurrentGameState()->map.height; ++height) 
        {
            for(int width = 0; width < gameState.getCurrentGameState()->map.width; ++width) 
            {
                if (height == 0 || height == gameState.getCurrentGameState()->map.height - 1 
                    || width == 0 || width == gameState.getCurrentGameState()->map.width - 1)
                {
                    ss << "#";
                }
                else if (height == gameState.getCurrentGameState()->playerPosition.y 
                    && width == gameState.getCurrentGameState()->playerPosition.x)
                {
                    ss << "@";
                }
                else if (height == gameState.getCurrentGameState()->map.end.y && width == gameState.getCurrentGameState()->map.end.x)
                {
                    ss << "X";
                }
                else
                {
                    ss << " ";
                }
            }
            ss << std::endl;
        }
        std::cout << ss.str();
    }
    
    else if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::START)
    {
        system("cls");
        std::cout << "Press SPACE to play" << std::endl;
    }
    
    else if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::WIN)
    {
        system("cls");
        std::cout << "YOU WON THE GAME!!!" << std::endl;
    }
}

int GameEngine::finish()
{
    return 0;
} 

}