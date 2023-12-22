#pragma once
#include <memory>
#include "GameState.hpp"

namespace game
{

class GameStateHandler
{
public:
    GameStateHandler();
    std::shared_ptr<GameState> getCurrentGameState() const;
    std::shared_ptr<GameState> getPreviousGameState() const;
    Position getPlayerPosition() const;
    bool isChanged() const;

    void setPlayerPosition(Position const& t_newPosition);
    void setPlayerPositionX(int const t_x);
    void setPlayerPositionY(int const t_y);
    void setPlayerQuit(bool const t_quit);
    void setCurrentGameStateEnum(GameStateEnum const t_next);
    
    void currentStateHandled();

private:
    bool isStateChanged = true;
    std::shared_ptr<GameState> currentGameState;
    std::shared_ptr<GameState> previousGameState;
};

}