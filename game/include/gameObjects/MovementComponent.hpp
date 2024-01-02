#pragma once
#include "Position.hpp"
#include "gameObjects/Direction.hpp"

namespace game
{
class MovementComponent
{
public:
    virtual ~MovementComponent() {}
    MovementComponent(Position const& t_pos, int const t_movementPerTick) : 
        position(t_pos), movementPerTick(t_movementPerTick) {}
    virtual Position move(Direction const t_direction);
    virtual Position move(int const t_x, int const t_y);
public:
    Position position;
    Position previousPosition;
    int movementPerTick = 1;
private:
    int waitingTicks = 0;
};

}