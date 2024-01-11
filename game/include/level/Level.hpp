#pragma once
#include <vector>
#include "level/Room.hpp"

namespace game
{

struct Level
{
    typedef std::vector<bool> LevelLayout;
    
    LevelLayout layout;
    LevelLayout visitedRooms;
    std::vector<Room> rooms;
    int dimensions = -1;
    int currentRoomIndex = -1;
    int roomCount = 0;
    int clearedRoomCount = 0;
};


}