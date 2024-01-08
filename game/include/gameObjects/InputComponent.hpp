#pragma once
#include <memory>
#include "GameState.hpp"
#include "gameObjects/Direction.hpp"
#include "gameObjects/combat/CombatAction.hpp"

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
    CombatAction nextCombatAction = CombatAction::NONE;
    bool needsUpdate = false;
};

}