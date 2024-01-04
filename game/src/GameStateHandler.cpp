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

bool GameStateHandler::isChanged() const
{
    return isStateChanged;
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
