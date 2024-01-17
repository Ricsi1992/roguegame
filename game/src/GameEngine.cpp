#include <random>
#include <windows.h>
#undef MOUSE_MOVED
#include "GameEngine.hpp"
#include "RandomGenerator.hpp"
#include "level/LevelGenerator.hpp"

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
            cleanUp();
        }
    }
}

void GameEngine::handleInput()
{
    if (gameState.getCurrentGameState()->currentGameState == GameStateEnum::START 
    && GetKeyState(VK_SPACE) & IS_PRESSED)
    {
        gameState.setCurrentGameStateEnum(GameStateEnum::PLAY);

        auto&& currentGameState = gameState.getCurrentGameState();
        currentGameState->level = LevelGenerator::generateLevel(currentGameState->difficultyLevel);
        currentGameState->level.visitedRooms[currentGameState->level.currentRoomIndex] = true;
        renderEngine.initGamePlay(gameState.getCurrentGameState());

        auto&& currentRoom = currentGameState->level.rooms[currentGameState->level.currentRoomIndex];
        gameObjectManager.loadRoomObjects(currentRoom.roomLayout, currentGameState);
    }

    if (GetKeyState('Q') & IS_PRESSED)
    {
        gameState.setPlayerQuit(true);
    }

    if (GetKeyState('Z') & IS_PRESSED)
    {
        gameObjectManager.gameObjects.clear();
    }
}

void GameEngine::update()
{
    auto&& currentGameState = gameState.getCurrentGameState();

    if (currentGameState->currentGameState == GameStateEnum::PLAY)
    {
        gameObjectManager.playerObject->inputComponent->update();

        for (auto&& gameObject : gameObjectManager.gameObjects)
        {
            gameObject->inputComponent->update();
        }
        
        bool playerMovesNextRoom = movementEngine.updatePlayer(gameObjectManager, gameState.getCurrentGameState());

        if (playerMovesNextRoom)
        {
            currentGameState->level.moveToRoom(gameObjectManager.playerObject->inputComponent->facing);
            gameObjectManager.playerMovesToNextRoom(currentGameState);
            auto&& currentRoom = currentGameState->level.rooms[currentGameState->level.currentRoomIndex];
            if (!currentRoom.isEnemiesCleared)
            {
                gameObjectManager.loadRoomObjects(currentRoom.roomLayout, currentGameState);
            }
            return;
        }
        

        combatEngine.updatePlayer(gameObjectManager, gameState.getCurrentGameState(), movementEngine.positions);
        movementEngine.update(gameObjectManager, gameState.getCurrentGameState());

        auto&& currentRoom = currentGameState->level.rooms[currentGameState->level.currentRoomIndex];
        currentRoom.isEnemiesCleared = gameObjectManager.gameObjects.size() == 0;

        gameObjectManager.prepareCleanUp();

        if (currentGameState->level.roomCount - 1 <= currentGameState->level.clearedRoomCount
        && currentRoom.isEnemiesCleared)
        {
            gameState.setCurrentGameStateEnum(GameStateEnum::WIN);
        }
    }
}

void GameEngine::render()
{
    renderEngine.render(gameState.getPreviousGameState(), gameState.getCurrentGameState(), gameObjectManager, combatEngine);

    gameState.currentStateHandled();
}

int GameEngine::finish()
{
    return 0;
}

void GameEngine::cleanUp()
{
    gameObjectManager.cleanUp();
}

}