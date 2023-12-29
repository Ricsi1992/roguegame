#include <curses.h>
#include "CursesRenderingEngine.hpp"
#include "GameUI.hpp"

namespace game
{

CursesRenderingEngine::CursesRenderingEngine() 
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    resize_term(GameUI::windowHeight, GameUI::windowWidth);
}

CursesRenderingEngine::~CursesRenderingEngine()
{
    endwin();
}

void CursesRenderingEngine::render(std::shared_ptr<GameState> t_currentState)
{

    if (t_currentState->currentGameState == GameStateEnum::PLAY)
    {
       drawUI();
    }
    
    else if (t_currentState->currentGameState == GameStateEnum::START)
    {
        
    }
    
    else if (t_currentState->currentGameState == GameStateEnum::WIN)
    {
        
    }
    
}

void CursesRenderingEngine::drawUI() 
{
    playWindow = std::unique_ptr<WINDOW>(newwin(GameUI::playAreaHeight, GameUI::playAreaWidth, GameUI::topLeft.y, GameUI::topLeft.x));
    box(playWindow.get(), '#', '#');
    wrefresh(playWindow.get());

    mapWindow = std::unique_ptr<WINDOW>(newwin(GameUI::mapAreaHeight, GameUI::mapAreaWidth, 
    GameUI::topLeft.y + GameUI::playAreaHeight, GameUI::topLeft.x));
    box(mapWindow.get(), '1', '1');
    wrefresh(mapWindow.get());

    infoWindow = std::unique_ptr<WINDOW>(newwin(GameUI::infoAreaHeight, GameUI::infoAreaWidth, 
    GameUI::topLeft.y + GameUI::playAreaHeight, GameUI::topLeft.x + GameUI::mapAreaWidth));
    box(infoWindow.get(), '2', '2');
    wrefresh(infoWindow.get());
}

}