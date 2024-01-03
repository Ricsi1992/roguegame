#pragma once
#include<cstdint>
#include <memory>
#include "gameObjects/MovementComponent.hpp"
#include "gameObjects/InputComponent.hpp"
#include "gameObjects/RenderComponent.hpp"

namespace game
{

class GameObject
{
public:
    GameObject(
        std::uint32_t const t_index, 
        std::shared_ptr<MovementComponent> t_movementComponent,
        std::shared_ptr<InputComponent> t_inputComponent, 
        std::shared_ptr<RenderComponent> t_renderComponent) :
        index(t_index), 
        movementComponent(t_movementComponent),
        inputComponent(t_inputComponent),
        renderComponent(t_renderComponent) {}
private:
        std::uint32_t index;
        std::shared_ptr<MovementComponent> movementComponent;
        std::shared_ptr<InputComponent> inputComponent;
        std::shared_ptr<RenderComponent> renderComponent;
};

} 
