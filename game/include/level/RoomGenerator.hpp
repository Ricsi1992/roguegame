#pragma once
#include <vector>

namespace game
{

class RoomGenerator
{

public:
    static std::vector<int> generateRoomLayout(int const t_width, int const t_height, int const t_difficulty);
};

}