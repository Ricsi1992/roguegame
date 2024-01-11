#pragma once
#include <vector>
#include "level/Level.hpp"

namespace game
{

class LevelGenerator
{
public:
    static Level generateLevel(int const t_difficulty, float const t_maxRoomVariability = 0.3);
private:
    static Level::LevelLayout generateLevelLayout(int const t_dimensions, int const t_maxRooms, int const t_walkerCount);    
};

}