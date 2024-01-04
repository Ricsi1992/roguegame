#pragma once
#include <memory>
#include "GameState.hpp"
#include "gameObjects/Direction.hpp"

namespace game
{

class GameObject;

class InputComponent
{
public:
    virtual ~InputComponent() {}
    virtual void update() = 0;

public:
    Direction facing;
    bool needsUpdate = false;
};

}