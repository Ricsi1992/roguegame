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

void CursesRenderingEngine::render(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager)
{
    if (t_previousState && t_previousState->currentGameState == GameStateEnum::START && 
    t_currentState->currentGameState == GameStateEnum::PLAY)
    {
        drawUI();
        drawMap(t_previousState, t_currentState);
    }
    
    if (t_currentState->currentGameState == GameStateEnum::PLAY)
    {
        drawCurrentState(t_previousState, t_currentState, t_objectManager);
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
    }
    
    else if (t_currentState->currentGameState == GameStateEnum::WIN)
    {
        erase();
        int x = 0, y = 0;
        getmaxyx(stdscr, y, x);
        std::string wonText = "You have won the game!";
        std::string quitText = "Press Q to quit!";

        int centerY = y / 2;
        mvwprintw(stdscr, centerY, (x - wonText.size()) / 2, wonText.c_str());
        mvwprintw(stdscr, centerY + 1, (x - quitText.size()) / 2, quitText.c_str());
    }

    refresh();
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

void CursesRenderingEngine::drawMap(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState)
{
    int centerX = (GameUI::playAreaWidth - t_currentState->map.width) / 2;
    int centerY = (GameUI::playAreaHeight - t_currentState->map.height) / 2;
    playAreaWindow = std::unique_ptr<WINDOW>(newwin(t_currentState->map.height, t_currentState->map.width, 
    centerY, centerX));
    box(playAreaWindow.get(), 0, 0);
    mvwaddch(playAreaWindow.get(), t_currentState->map.end.y, t_currentState->map.end.x, GameUI::exitCharacter);
    wrefresh(playAreaWindow.get());
}

void CursesRenderingEngine::drawCurrentState(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager)
{
     if (t_previousState)
    {
        mvwaddch(playAreaWindow.get(), t_objectManager.playerObject->movementComponent->previousPosition.y, 
            t_objectManager.playerObject->movementComponent->previousPosition.x, GameUI::emptyCharacter);
    }
    
    mvwaddch(playAreaWindow.get(),  t_objectManager.playerObject->movementComponent->position.y, 
        t_objectManager.playerObject->movementComponent->position.x, t_objectManager.playerObject->renderComponent->renderChar);
    wrefresh(playAreaWindow.get()); 
}

}