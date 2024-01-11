#pragma once
#include <vector>
#include "level/Room.hpp"

namespace game
{

struct Level
{
    std::vector<bool> layout;
    std::vector<bool> visitedRooms;
    std::vector<Room> rooms;
    int dimensions = -1;
    int currentRoomIndex = -1;
    int roomCount = 0;
    int clearedRoomCount = 0;
};


}