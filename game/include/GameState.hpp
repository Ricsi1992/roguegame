#pragma once
#include "GameStateEnum.hpp"
#include "Map.hpp"
#include "Position.hpp"

namespace game 
{

struct GameState
{
    Position playerPosition{3,3};
    bool quit = false;
    GameStateEnum currentGameState = GameStateEnum::START;
    Map map;
};

    
}