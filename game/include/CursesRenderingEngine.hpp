#pragma once
#include <memory>
#include "GameState.hpp"

namespace game
{

class CursesRenderingEngine
{
public:
    CursesRenderingEngine();
    ~CursesRenderingEngine();
    void render(std::shared_ptr<GameState> t_currentState);
};


}