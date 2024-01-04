#include <random>
#include <windows.h>
#undef MOUSE_MOVED
#include "GameEngine.hpp"
#include "RandomGenerator.hpp"

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

    RandomGenerator* randomGenerator = RandomGenerator::getInstance();
    randomGenerator->setSeed(currentTime.time_since_epoch().count());

    gameState.getCurrentGameState()->map.end.x = randomGenerator->getRandomInt(1, gameState.getCurrentGameState()->map.width-2);
    gameState.getCurrentGameState()->map.end.y = randomGenerator->getRandomInt(1, gameState.getCurrentGameState()->map.height-2);
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
    if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::START 
    && GetKeyState(VK_SPACE) & IS_PRESSED)
    {
        gameState.setCurrentGameStateEnum(GameStateEnum::PLAY);
        gameObjectManager.createPlayer(Position{3,3});
    }

    if (GetKeyState('Q') & IS_PRESSED)
    {
        gameState.setPlayerQuit(true);
    }
    
}

void GameEngine::update()
{
    if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::PLAY)
    {
        gameObjectManager.playerObject->inputComponent->update();
        if (gameObjectManager.playerObject->inputComponent->needsUpdate)
        {
            gameObjectManager.playerObject->movementComponent->move(gameObjectManager.playerObject->inputComponent->facing);
        }    
    }
    /* if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::PLAY 
        && gameState.getCurrentGameState()->playerPosition == gameState.getCurrentGameState()->map.end)
    {
        gameState.setCurrentGameStateEnum(GameStateEnum::WIN);
    } */
}

void GameEngine::render()
{
    renderEngine.render(gameState.getPreviousGameState(), gameState.getCurrentGameState(), gameObjectManager);

    gameState.currentStateHandled();
}

int GameEngine::finish()
{
    return 0;
} 

}