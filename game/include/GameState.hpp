#pragma once
#include "GameStateEnum.hpp"
#include "Position.hpp"
#include "level/Level.hpp"

namespace game 
{

struct GameState
{
    Level level;
    bool quit = false;
    GameStateEnum currentGameState = GameStateEnum::START;
    int difficultyLevel = 1;
};

    
}