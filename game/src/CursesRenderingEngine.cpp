#include <curses.h>
#include "CursesRenderingEngine.hpp"
#include "GameUI.hpp"
#include "utils.hpp"

namespace game
{

namespace
{

void switchColor(bool t_isOn, ObjectColor const t_color, WINDOW* t_window)
{
    if (t_isOn)
    {
        wattron(t_window, COLOR_PAIR(static_cast<int>(t_color)));
    }
    else
    {
        wattroff(t_window, COLOR_PAIR(static_cast<int>(t_color)));
    }
}
}

CursesRenderingEngine::CursesRenderingEngine() 
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    resize_term(GameUI::windowHeight, GameUI::windowWidth);
    start_color();
    
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
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

    else if (t_currentState->currentGameState == GameStateEnum::LOSS)
    {
        erase();
        int x = 0, y = 0;
        getmaxyx(stdscr, y, x);
        std::string wonText = "You lost!";
        std::string quitText = "Press Q to quit!";

        int centerY = y / 2;
        mvwprintw(stdscr, centerY, (x - wonText.size()) / 2, wonText.c_str());
        mvwprintw(stdscr, centerY + 1, (x - quitText.size()) / 2, quitText.c_str());
    }

    refresh();
}

void CursesRenderingEngine::initGamePlay(std::shared_ptr<GameState> t_currentState)
{
    int playTopLeftX = (GameUI::playAreaWidth - t_currentState->map.width) / 2;
    int playTopLeftY = (GameUI::playAreaHeight - t_currentState->map.height) / 2;
    playAreaWindow = std::unique_ptr<WINDOW>(newwin(t_currentState->map.height, t_currentState->map.width,
    playTopLeftY, playTopLeftX));
    playWindow = std::unique_ptr<WINDOW>(newwin(GameUI::playAreaHeight, GameUI::playAreaWidth, GameUI::topLeft.y, GameUI::topLeft.x));

    mapWindow = std::unique_ptr<WINDOW>(newwin(GameUI::mapAreaHeight, GameUI::mapAreaWidth, 
    GameUI::topLeft.y + GameUI::playAreaHeight, GameUI::topLeft.x));

    infoWindow = std::unique_ptr<WINDOW>(newwin(GameUI::infoAreaHeight, GameUI::infoAreaWidth, 
    GameUI::topLeft.y + GameUI::playAreaHeight, GameUI::topLeft.x + GameUI::mapAreaWidth));
}

void CursesRenderingEngine::drawUI() 
{
    box(playWindow.get(), '#', '#');
    wrefresh(playWindow.get());

    box(mapWindow.get(), '1', '1');
    wrefresh(mapWindow.get());

    box(infoWindow.get(), '2', '2');
    wrefresh(infoWindow.get());
}

void CursesRenderingEngine::drawMap(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState)
{
    int playTopLeftX = (GameUI::playAreaWidth - t_currentState->map.width) / 2 - 1;
    int playTopLeftY = (GameUI::playAreaHeight - t_currentState->map.height) / 2 - 1;
    int playBottomRightX = playTopLeftX + 1 + t_currentState->map.width;
    int playBottomRightY = playTopLeftY + 1 + t_currentState->map.height;
    
    mvwhline(playWindow.get(), playTopLeftY, playTopLeftX, 0, playBottomRightX - playTopLeftX);
    mvwhline(playWindow.get(), playBottomRightY, playTopLeftX, 0, playBottomRightX - playTopLeftX);
    mvwvline(playWindow.get(), playTopLeftY, playTopLeftX, 0 , playBottomRightY - playTopLeftY);
    mvwvline(playWindow.get(), playTopLeftY, playBottomRightX, 0 , playBottomRightY - playTopLeftY);
    mvwaddch(playWindow.get(), playTopLeftY, playTopLeftX, ACS_ULCORNER);
    mvwaddch(playWindow.get(), playBottomRightY, playTopLeftX, ACS_LLCORNER);
    mvwaddch(playWindow.get(), playTopLeftY, playBottomRightX, ACS_URCORNER);
    mvwaddch(playWindow.get(), playBottomRightY, playBottomRightX, ACS_LRCORNER);
    wrefresh(playWindow.get());
}

void CursesRenderingEngine::drawCurrentState(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager)
{
     if (t_previousState)
    {
        mvwaddch(playAreaWindow.get(), t_objectManager.playerObject->movementComponent->previousPosition.y, 
        t_objectManager.playerObject->movementComponent->previousPosition.x, GameUI::emptyCharacter);
        for (auto&& gameObject : t_objectManager.gameObjects)
        {
            mvwaddch(playAreaWindow.get(), gameObject->movementComponent->previousPosition.y, 
            gameObject->movementComponent->previousPosition.x, GameUI::emptyCharacter);
        }
    }

    mvwaddch(playAreaWindow.get(), t_currentState->map.end.y, t_currentState->map.end.x, GameUI::exitCharacter);
    
    drawObject(t_objectManager.playerObject);
    
    for (auto&& gameObject : t_objectManager.gameObjects)
    {
        drawObject(gameObject);
    }
    
    wrefresh(playAreaWindow.get()); 
}

void CursesRenderingEngine::drawObject(std::shared_ptr<GameObject> t_gameObject)
{
    switchColor(true, t_gameObject->renderComponent->color, playAreaWindow.get());
    mvwaddch(playAreaWindow.get(),  t_gameObject->movementComponent->position.y, 
    t_gameObject->movementComponent->position.x, t_gameObject->renderComponent->renderChar);
    switchColor(false, t_gameObject->renderComponent->color, playAreaWindow.get());
}

}