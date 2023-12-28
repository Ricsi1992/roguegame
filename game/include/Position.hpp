#pragma once

namespace game 
{

struct Position
{
public:
    int x = 0;
    int y = 0;
public:
    constexpr Position(int const t_x, int const t_y) : x(t_x), y(t_y) {}
    constexpr Position() {};
public:
    bool operator==(Position const& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(Position const& rhs) const
    {
        return !(*this == rhs);
    }
};


}