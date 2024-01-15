#pragma once
#include <memory>
#include <curses.h>
#include "GameState.hpp"
#include "gameObjects/GameObjectManager.hpp"
#include "CombatEngine.hpp"

namespace game
{

class CursesRenderingEngine
{
public:
    CursesRenderingEngine();
    ~CursesRenderingEngine();
    void render(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager,
    CombatEngine const& t_combatEngine);
    void initGamePlay(std::shared_ptr<GameState> t_currentState);
private:
    void drawUI(std::shared_ptr<GameState> t_currentState);
    void drawMap(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState);
    void drawCurrentState(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager,
    CombatEngine const& t_combatEngine);
    void drawObject(std::shared_ptr<GameObject> t_gameObject);
private:
    std::unique_ptr<WINDOW> playWindow;
    std::unique_ptr<WINDOW> playAreaWindow;
    std::unique_ptr<WINDOW> mapWindow;
    std::unique_ptr<WINDOW> infoWindow;
};


}