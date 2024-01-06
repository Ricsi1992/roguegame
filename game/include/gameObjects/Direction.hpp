#pragma once

namespace game
{

enum class Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NUMBER_OF_ELEMENTS
};

Direction invertDirection(Direction const t_direction);

}