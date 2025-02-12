#pragma once
#include <chrono>
#include "GameStateHandler.hpp"
#include "CursesRenderingEngine.hpp"
#include "MovementEngine.hpp"
#include "CombatEngine.hpp"
#include "gameObjects/GameObjectManager.hpp"

namespace game {
   
class GameEngine {
        
    public:
        int run();

    private:
        void init();

        void gameLoop();
        void handleInput();
        void update();
        void render();
        void cleanUp();

        int finish();
    
    private:
        std::chrono::time_point<std::chrono::system_clock> currentTime;
        GameStateHandler gameState;
        CursesRenderingEngine renderEngine;
        GameObjectManager gameObjectManager;
        MovementEngine movementEngine;
        CombatEngine combatEngine;
};

}