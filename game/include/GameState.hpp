#pragma once
#include "GameStateEnum.hpp"
#include "Map.hpp"
#include "Position.hpp"

namespace game 
{

struct GameState
{
    bool quit = false;
    GameStateEnum currentGameState = GameStateEnum::START;
    Map map;
    int difficulty = 0;
};

    
}