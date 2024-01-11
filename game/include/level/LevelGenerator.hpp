#pragma once
#include <vector>
#include <bitset>
#include "level/Level.hpp"

namespace game
{

class LevelGenerator
{
public:
    static Level generateLevel(int t_difficulty, float t_maxRoomVariability = 0.3);
    static Level::LevelLayout generateLevelLayout(int const t_dimensions, int const t_maxRooms, int const t_walkerCount);    
};

}