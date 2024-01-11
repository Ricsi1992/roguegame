#include "level/LevelGenerator.hpp"
#include "Position.hpp"
#include "RandomGenerator.hpp"

namespace game
{
    
Level LevelGenerator::generateLevel(int const t_difficulty, float const t_maxRoomVariability = 0.3)
{
    Level newLevel;
    int targetDimension = 3;
    int targetMaxRooms = 5;
    int targetWalkerCount = 2;
}

Level::LevelLayout LevelGenerator::generateLevelLayout(int const t_dimensions, int const t_maxRooms, int const t_walkerCount)
{
    Level::LevelLayout rooms(t_dimensions * t_dimensions);

    int centerPosition = t_dimensions * t_dimensions / 2;
    rooms[centerPosition] = true;

    std::vector<int> walkers(t_walkerCount, centerPosition);

    auto&& random = RandomGenerator::getInstance();
    int currentRoomCount = 1;

    while (true)
    {
        for (auto&& walker : walkers)
        {
            if (currentRoomCount == t_maxRooms)
            {
                return rooms;
            }

            Direction randomDirection = static_cast<Direction>(random->getRandomInt(0, static_cast<int>
            (Direction::NUMBER_OF_ELEMENTS) - 1));
            
            int nextPos = -1;

            switch (randomDirection)
            {
            case Direction::UP:
                nextPos = walker - t_dimensions;
                if (nextPos < 0)
                {
                    nextPos = -1;
                }
                break;
            case Direction::RIGHT:
                nextPos = walker + 1;
                if (nextPos % t_dimensions == 0)
                {
                    nextPos = -1;
                }
                break;
            case Direction::DOWN:
                nextPos = walker + t_dimensions;
                if (nextPos >= static_cast<int>(rooms.size()))
                {
                    nextPos = -1;
                }
                break;
            case Direction::LEFT:
                nextPos = walker - 1;
                if (nextPos % t_dimensions == t_dimensions - 1)
                {
                    nextPos = -1;
                }
                break;
            case Direction::NUMBER_OF_ELEMENTS:
            default:
                break;
            }
            
            if (nextPos == -1)
            {
                continue;
            }

            if (!rooms[nextPos])
            {
                rooms[nextPos] = true;
                ++currentRoomCount;
            }
            walker = nextPos;
        }
    }
}

} 



