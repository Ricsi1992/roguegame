#pragma once
#include "gameObjects/InputComponent.hpp"

namespace game
{

class MonsterInputComponent: public InputComponent
{
public:
    virtual void update();
};

}