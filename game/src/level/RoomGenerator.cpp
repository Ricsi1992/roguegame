#include <algorithm>
#include "level/RoomGenerator.hpp"
#include "RandomGenerator.hpp"

namespace game
{

std::vector<int> RoomGenerator::generateRoomLayout(int const t_width, int const t_height, int const t_difficulty)
{
    auto&& random = RandomGenerator::getInstance();
    int extraEnemies = random->getRandomInt(1, 3);
    int numberOfEnemies = 2 + t_difficulty * 2.6 + extraEnemies;

    std::vector<int> roomLayout(numberOfEnemies, 1);
    roomLayout.resize(t_width * t_height, 0);
    std::random_shuffle(roomLayout.begin(), roomLayout.end(), [&](int i) {
        return random->getRandomInt(i);
    });

    return roomLayout;
}

}