#include "gameObjects/Direction.hpp"

namespace game
{

Direction invertDirection(Direction const t_direction)
{
    switch (t_direction)
    {
    case Direction::UP:
        return Direction::DOWN;
    case Direction::DOWN:
        return Direction::UP;
    case Direction::LEFT:
        return Direction::RIGHT;
    case Direction::RIGHT:
        return Direction::LEFT;
    default:
        return Direction::NUMBER_OF_ELEMENTS;
    }
}

}