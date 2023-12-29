#pragma once
#include <memory>
#include <curses.h>
#include "GameState.hpp"

namespace game
{

class CursesRenderingEngine
{
public:
    CursesRenderingEngine();
    ~CursesRenderingEngine();
    void render(std::shared_ptr<GameState> t_currentState);
private:
    void drawUI();
private:
    std::unique_ptr<WINDOW> playWindow;
    std::unique_ptr<WINDOW> mapWindow;
    std::unique_ptr<WINDOW> infoWindow;
};


}