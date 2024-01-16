#pragma once
#include <vector>
#include "level/Room.hpp"

namespace game
{

struct Level
{
public:
    typedef std::vector<bool> LevelLayout;

public:
    void moveToRoom(Direction const t_direction)
    {
        switch (t_direction)
        {
        case Direction::UP:
            currentRoomIndex -= dimensions;
            break;
        case Direction::RIGHT:
            currentRoomIndex += 1;
            break;
        case Direction::DOWN:
            currentRoomIndex += dimensions;
            break;
        case Direction::LEFT:
            currentRoomIndex -= 1;
            break;
        case Direction::NUMBER_OF_ELEMENTS:
        default:
            break;
        }

        if (!visitedRooms[currentRoomIndex])
        {
           visitedRooms[currentRoomIndex] = true;
           ++clearedRoomCount;
        }
        
    }

public:   
    LevelLayout layout;
    LevelLayout visitedRooms;
    std::vector<Room> rooms;
    int dimensions = -1;
    int currentRoomIndex = -1;
    int roomCount = 0;
    int clearedRoomCount = 0;
};


}