#include "level/LevelGenerator.hpp"
#include "Position.hpp"
#include "RandomGenerator.hpp"
#include "level/RoomGenerator.hpp"

namespace game
{
    
Level LevelGenerator::generateLevel(int t_difficulty, float t_maxRoomVariability)
{
    Level newLevel;
    int targetDimension = 3;
    int targetMaxRooms = 5;
    int targetWalkerCount = 2;

    auto&& randomGenerator = RandomGenerator::getInstance();
    int maxRooms = randomGenerator->getRandomInt(targetMaxRooms * t_maxRoomVariability,
    targetMaxRooms * (1 + t_maxRoomVariability));
    newLevel.dimensions = targetDimension;
    newLevel.roomCount = maxRooms;
    newLevel.layout = generateLevelLayout(targetDimension, maxRooms, targetWalkerCount);

    for (int i = 0; i < static_cast<int>(newLevel.layout.size()); ++i)
    {
        if (!newLevel.layout[i])
        {
            newLevel.rooms.emplace_back(Room());
            continue;
        }

        newLevel.currentRoomIndex = i;

        int width = randomGenerator->getRandomInt(40, 60);
        int height = randomGenerator->getRandomInt(10, 15);
        newLevel.rooms.emplace_back(Room{
            width,
            height,
            RoomGenerator::generateRoomLayout(width, height, t_difficulty),
            {
                {Direction::UP, (i - targetDimension) > 0 && newLevel.layout[i - targetDimension] == true},
                {Direction::RIGHT, (i + 1) < static_cast<int>(newLevel.layout.size()) 
                && (i + 1) % targetDimension != 0 && newLevel.layout[i + 1] == true},
                {Direction::DOWN, (i + targetDimension) < static_cast<int>(newLevel.layout.size()) 
                && newLevel.layout[i + targetDimension] == true},
                {Direction::LEFT, (i - 1) > 0 && i % targetDimension != 0 && newLevel.layout[i - 1] == true},
            },
            true,
            false
        });
    }
    newLevel.visitedRooms = std::vector<bool>(newLevel.rooms.size(), false);
    return newLevel;
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



