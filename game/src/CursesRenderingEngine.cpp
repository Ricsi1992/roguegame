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
    init_pair(5, COLOR_BLACK, COLOR_YELLOW);
}

CursesRenderingEngine::~CursesRenderingEngine()
{
    endwin();
}

void CursesRenderingEngine::render(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager,
CombatEngine const& t_combatEngine)
{
    if(t_currentState->currentGameState == GameStateEnum::PLAY)
    {
        if(t_previousState->level.currentRoomIndex != t_currentState->level.currentRoomIndex)
        {
            werase(playWindow.get());
            drawUI(t_currentState);
            drawMap(t_previousState, t_currentState);
            auto&& currentRoom = t_currentState->level.rooms[t_currentState->level.currentRoomIndex];
            int playTopLeftX = (GameUI::playAreaWidth - currentRoom.width) / 2;
            int playTopLeftY = (GameUI::playAreaHeight - currentRoom.height) / 2;
            playAreaWindow = std::unique_ptr<WINDOW>(newwin(currentRoom.height, currentRoom.width, playTopLeftY, playTopLeftX));
        }
        drawCurrentState(t_previousState, t_currentState, t_objectManager, t_combatEngine);
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
    auto&& currentRoom = t_currentState->level.rooms[t_currentState->level.currentRoomIndex];
    int playTopLeftX = (GameUI::playAreaWidth - currentRoom.width) / 2;
    int playTopLeftY = (GameUI::playAreaHeight - currentRoom.height) / 2;
    playAreaWindow = std::unique_ptr<WINDOW>(newwin(currentRoom.height, currentRoom.width,
    playTopLeftY, playTopLeftX));
    playWindow = std::unique_ptr<WINDOW>(newwin(GameUI::playAreaHeight, GameUI::playAreaWidth, GameUI::topLeft.y, GameUI::topLeft.x));

    mapWindow = std::unique_ptr<WINDOW>(newwin(GameUI::mapAreaHeight, GameUI::mapAreaWidth, 
    GameUI::topLeft.y + GameUI::playAreaHeight, GameUI::topLeft.x));

    infoWindow = std::unique_ptr<WINDOW>(newwin(GameUI::infoAreaHeight, GameUI::infoAreaWidth, 
    GameUI::topLeft.y + GameUI::playAreaHeight, GameUI::topLeft.x + GameUI::mapAreaWidth));
}

void CursesRenderingEngine::drawUI(std::shared_ptr<GameState> t_currentState) 
{
    box(playWindow.get(), '#', '#');
    wrefresh(playWindow.get());

    int roomSizeWidth = 3;
    int roomSizeHeight = 3;

    int const& dimensions = t_currentState->level.dimensions;
    int const& currentRoomIndex = t_currentState->level.currentRoomIndex;
    Level::LevelLayout rooms = t_currentState->level.layout;
    Level::LevelLayout visitedRooms = t_currentState->level.visitedRooms;

    int centerX = GameUI::mapAreaWidth / 2;
    int centerY = GameUI::mapAreaHeight / 2;

    int currentRoomY = currentRoomIndex / dimensions;
    int currentRoomX = currentRoomIndex % dimensions;

    int topLeftMapGridX = centerX - currentRoomX * roomSizeHeight;
    int topLeftMapGridY = centerY - currentRoomY * roomSizeWidth;

    int roomIndex = 0;
    for (int y = topLeftMapGridY; y < topLeftMapGridY + dimensions * roomSizeWidth; y += roomSizeWidth)
    {
        for (int x = topLeftMapGridX; x < topLeftMapGridX + dimensions * roomSizeHeight; x += roomSizeHeight)
        {
            if (y <= roomSizeWidth / 2 || x <= roomSizeHeight / 2 || y >= GameUI::mapAreaWidth - roomSizeWidth / 2
            || x >= GameUI::mapAreaHeight - roomSizeHeight / 2)
            {
                ++roomIndex;
                continue;
            }
            
            if (rooms[roomIndex])
            {
                //TODO draw room rectangle
            }
            ++roomIndex;
        }
    }
    
    
    box(mapWindow.get(), '1', '1');
    wrefresh(mapWindow.get());

    box(infoWindow.get(), '2', '2');
    wrefresh(infoWindow.get());
}

void CursesRenderingEngine::drawMap(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState)
{
    auto&& currentRoom = t_currentState->level.rooms[t_currentState->level.currentRoomIndex];
    int playTopLeftX = (GameUI::playAreaWidth - currentRoom.width) / 2 - 1;
    int playTopLeftY = (GameUI::playAreaHeight - currentRoom.height) / 2 - 1;
    int playBottomRightX = playTopLeftX + 1 + currentRoom.width;
    int playBottomRightY = playTopLeftY + 1 + currentRoom.height;
    
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

void CursesRenderingEngine::drawCurrentState(std::shared_ptr<GameState> t_previousState, std::shared_ptr<GameState> t_currentState, GameObjectManager const& t_objectManager,
CombatEngine const& t_combatEngine)
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

    for (auto&& meleeTarget : t_combatEngine.previousTargetPositions)
    {
        switchColor(true, ObjectColor::DEFAULT, playAreaWindow.get());
        mvwaddch(playAreaWindow.get(), meleeTarget.y, meleeTarget.x, GameUI::emptyCharacter);
        switchColor(false, ObjectColor::DEFAULT, playAreaWindow.get());
    }

    for (auto&& meleeTarget : t_combatEngine.targetPositions)
    {
        switchColor(true, ObjectColor::YELLOW_BG, playAreaWindow.get());
        mvwaddch(playAreaWindow.get(), meleeTarget.y, meleeTarget.x, ' ');
        switchColor(false, ObjectColor::YELLOW_BG, playAreaWindow.get());
    }
    

    //mvwaddch(playAreaWindow.get(), t_currentState->map.end.y, t_currentState->map.end.x, GameUI::exitCharacter);
    
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