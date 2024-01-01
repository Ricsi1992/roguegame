#include "GameStateHandler.hpp"

namespace game
{

GameStateHandler::GameStateHandler()
{
    currentGameState = std::make_shared<GameState>();
    previousGameState = nullptr;
}

std::shared_ptr<GameState> GameStateHandler::getCurrentGameState() const
{
    return currentGameState;
}
std::shared_ptr<GameState> GameStateHandler::getPreviousGameState() const
{
    return previousGameState;
}
Position GameStateHandler::getPlayerPosition() const
{
    return currentGameState->playerPosition;
}
bool GameStateHandler::isChanged() const
{
    return isStateChanged;
}

void GameStateHandler::setPlayerPosition(Position const& t_newPosition)
{
    currentGameState->playerPosition = t_newPosition;
    isStateChanged = true;
}
void GameStateHandler::setPlayerPositionX(int const t_x)
{
    currentGameState->playerPosition.x = t_x;
    isStateChanged = true;
}
void GameStateHandler::setPlayerPositionY(int const t_y)
{
    currentGameState->playerPosition.y = t_y;
    isStateChanged = true;
}
void GameStateHandler::setPlayerQuit(bool const t_quit)
{
    currentGameState->quit = t_quit;
    isStateChanged = true;
}
void  GameStateHandler::setCurrentGameStateEnum(GameStateEnum const t_next)
{
    currentGameState->currentGameState = t_next;
    isStateChanged = true;
}
    
void GameStateHandler::currentStateHandled()
{
    isStateChanged = false;
    previousGameState = std::make_shared<GameState>(*currentGameState);
}
    
} 
