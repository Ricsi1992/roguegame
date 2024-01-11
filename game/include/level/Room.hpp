#pragma once
#include <vector>
#include<map>
#include "Direction.hpp"

namespace game
{

struct Room
{
    int width;
    int height;
    std::vector<int> roomLayout;
    std::map<Direction, bool> exits;
    bool isValid = false;
    bool isEnemiesCleared = false;
};

}