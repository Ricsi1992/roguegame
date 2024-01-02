#include "gameObjects/MovementComponent.hpp"

namespace game
{

Position MovementComponent::move(Direction const t_direction)
{
    if(movementPerTick != 1 && waitingTicks < movementPerTick)
    {
        ++waitingTicks;
        return position;
    }

    waitingTicks = 0;
    switch (t_direction)
    {
        case Direction::UP:
            move(position.x, position.y - 1);
            break;
        case Direction::RIGHT:
            move(position.x + 1, position.y);
            break;
        case Direction::DOWN:
            move(position.x, position.y + 1);
            break;
        case Direction::LEFT:
            move(position.x - 1, position.y);
            break;
        case Direction::NUMBER_OF_ELEMENTS:
            break;
    }
    return position;
}

Position MovementComponent::move(int const t_x, int const t_y)
{
    Position newPos(t_x, t_y);
    previousPosition = position;
    position = newPos;
    return position;
}

}