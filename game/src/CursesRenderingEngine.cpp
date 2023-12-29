#include <curses.h>
#include "CursesRenderingEngine.hpp"
#include "GameUI.hpp"
#include "utils.hpp"

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
        int x = 0, y = 0;
        getmaxyx(stdscr, y, x);

        start_color();
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        utils::mvprintw_vector((y - GameUI::title.size()) / 2 - 1, (x - GameUI::title[0].size()) / 2, GameUI::title);
        attroff(COLOR_PAIR(1));
        
        
        std::string start ="Press SPACE to start!";
        mvwprintw(stdscr, (y - GameUI::title.size()) / 2 + GameUI::title.size(), (x - start.size()) / 2, start.c_str());
        refresh();
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