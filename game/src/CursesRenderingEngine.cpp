#include <curses.h>
#include "CursesRenderingEngine.hpp"

namespace game
{

CursesRenderingEngine::CursesRenderingEngine() 
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
}

CursesRenderingEngine::~CursesRenderingEngine()
{
    endwin();
}

void CursesRenderingEngine::render(std::shared_ptr<GameState> t_currentState)
{

}

}