#pragma once
#include<cstdint>
#include <memory>
#include "gameObjects/MovementComponent.hpp"

namespace game
{

class GameObject
{
public:
    GameObject(std::uint32_t const t_index, std::shared_ptr<MovementComponent> t_movementComponent) :
        index(t_index), movementComponent(t_movementComponent) {}
private:
        std::uint32_t index;
        std::shared_ptr<MovementComponent> movementComponent;
};

} 
