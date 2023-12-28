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
    playWindow = std::unique_ptr<WINDOW>(newwin(GameUI::playArewaHeight, GameUI::playArewaWidth, GameUI::topLeft.y, GameUI::topLeft.x));
    box(playWindow.get(), '#', '#');
    wrefresh(playWindow.get());
}

CursesRenderingEngine::~CursesRenderingEngine()
{
    endwin();
}

void CursesRenderingEngine::render(std::shared_ptr<GameState> t_currentState)
{

    // if (t_currentState->currentGameState == GameStateEnum::PLAY)
    // {
       
    // }
    
    // else if (t_currentState->currentGameState == GameStateEnum::START)
    // {
        
    // }
    
    // else if (t_currentState->currentGameState == GameStateEnum::WIN)
    // {
        
    // }
    
}

}