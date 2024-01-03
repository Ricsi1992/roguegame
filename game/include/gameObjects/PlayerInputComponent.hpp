#pragma once
#include "gameObjects/InputComponent.hpp"

namespace game
{

class PlayerInputComponent: public InputComponent
{
public:
    virtual void update(GameObject& t_gameObject, std::shared_ptr<GameState> t_gameState);

};

}