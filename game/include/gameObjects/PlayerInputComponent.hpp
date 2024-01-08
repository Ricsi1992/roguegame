#pragma once
#include "gameObjects/InputComponent.hpp"

namespace game
{

class PlayerInputComponent: public InputComponent
{
public:
    virtual void update();
};

}