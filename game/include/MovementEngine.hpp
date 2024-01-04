#pragma once
#include "gameObjects/GameObjectManager.hpp"

namespace game
{
class MovementEngine
{
public:
    void update(GameObjectManager& t_gameObjectManager, std::shared_ptr<GameState> currentGameState);

private:
    bool wouldBeOutOfBounds(Position const& t_position, Direction const t_facing, int const t_maxWidth, int const t_maxHeight);
};

}