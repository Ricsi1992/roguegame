#include "MovementEngine.hpp"

namespace game
{

void MovementEngine::update(GameObjectManager& t_gameObjectManager, std::shared_ptr<GameState> t_currentGameState)
{
    t_gameObjectManager.playerObject->inputComponent->update();
    if (t_gameObjectManager.playerObject->inputComponent->needsUpdate)
    {
        if(!wouldBeOutOfBounds(
            t_gameObjectManager.playerObject->movementComponent->position, 
            t_gameObjectManager.playerObject->inputComponent->facing,
            t_currentGameState->map.width, 
            t_currentGameState->map.height))
        {
        t_gameObjectManager.playerObject->movementComponent->move(t_gameObjectManager.playerObject->inputComponent->facing);
        }
    }    
}

bool  MovementEngine::wouldBeOutOfBounds(Position const& t_position, Direction const t_facing, int const t_maxWidth, int const t_maxHeight)
{
    if ((t_position.y == 0 && t_facing == Direction::UP)
        || (t_position.y == t_maxHeight - 1 && t_facing == Direction::DOWN)
        || (t_position.x == 0 && t_facing == Direction::LEFT)
        || (t_position.x == t_maxWidth - 1 && t_facing == Direction::RIGHT))
    {
        return true;
    }
    return false;
}

}