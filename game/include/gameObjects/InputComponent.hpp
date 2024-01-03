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
    virtual void update(GameObject& t_gameObject, std::shared_ptr<GameState> t_gameState) = 0;

public:
    Direction facing;
    bool needsUpdate = false;
};

}