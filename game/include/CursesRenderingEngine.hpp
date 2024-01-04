#pragma once
#include <memory>
#include <curses.h>
#include "GameState.hpp"
#include "gameObjects/GameObjectManager.hpp"

namespace game
{

class CursesRenderingEngine
{
public:
    CursesRenderingEngine();
    ~CursesRenderingEngine();
    void render(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager);
private:
    void drawUI();
    void drawMap(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState);
    void drawCurrentState(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager);
private:
    std::unique_ptr<WINDOW> playWindow;
    std::unique_ptr<WINDOW> playAreaWindow;
    std::unique_ptr<WINDOW> mapWindow;
    std::unique_ptr<WINDOW> infoWindow;
};


}