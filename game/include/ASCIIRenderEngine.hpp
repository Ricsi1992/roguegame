#pragma once
#include <memory>
#include "GameState.hpp"

namespace game
{

class ASCIIRenderEngine
{
public:
    void render(std::shared_ptr<GameState> t_currentState);
};

}