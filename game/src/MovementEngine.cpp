#include "MovementEngine.hpp"

namespace game
{

void MovementEngine::update(GameObjectManager& t_gameObjectManager, std::shared_ptr<GameState> t_currentGameState)
{
    Position& currentPlayerPosition = t_gameObjectManager.playerObject->movementComponent->position;
    auto&& currentRoom = t_currentGameState->level.rooms[t_currentGameState->level.currentRoomIndex];
    int encodedPlayerPosition = currentPlayerPosition.y * currentRoom.width + currentPlayerPosition.x;

    for (auto&& collidingEntities : nextPositions)
    {
        if (collidingEntities.first == encodedPlayerPosition)
        {
            t_currentGameState.get()->currentGameState = GameStateEnum::LOSS;
            return;
        }
        
        if (collidingEntities.second.size() <= 1)
        {
            continue;
        }

        for (size_t i = 1; i < collidingEntities.second.size(); ++i)
        {
            collidingEntities.second[i]->inputComponent->facing = invertDirection(collidingEntities.second[i]->inputComponent->facing);
            collidingEntities.second[i]->movementComponent->move(collidingEntities.second[i]->inputComponent->facing);
        }
    }
}

void MovementEngine::updatePlayer(GameObjectManager& t_gameObjectManager, std::shared_ptr<GameState> t_currentGameState)
{
    positions.clear();
    nextPositions.clear();

    Position currentPlayerPosition = t_gameObjectManager.playerObject->movementComponent->position;
    auto&& currentRoom = t_currentGameState->level.rooms[t_currentGameState->level.currentRoomIndex];
    if (t_gameObjectManager.playerObject->inputComponent->needsUpdate)
    {
        if(!wouldBeOutOfBounds(
            t_gameObjectManager.playerObject->movementComponent->position, 
            t_gameObjectManager.playerObject->inputComponent->facing,
            currentRoom.width, 
            currentRoom.height))
        {
        t_gameObjectManager.playerObject->movementComponent->move(t_gameObjectManager.playerObject->inputComponent->facing);
        }
    }
    int encodedPlayerPosition = currentPlayerPosition.y * currentRoom.width + currentPlayerPosition.x;

    for (auto&& gameObject : t_gameObjectManager.gameObjects)
    {
        if (gameObject->markedForDeletion)
        {
            continue;
        }
        
        Position currentPosition = gameObject->movementComponent->position;
        if (gameObject->inputComponent->needsUpdate)
        {
            if(wouldBeOutOfBounds(
            gameObject->movementComponent->position, 
            gameObject->inputComponent->facing,
            currentRoom.width, 
            currentRoom.height))
            {
                continue;
            }
            Position nextPosition = gameObject->movementComponent->move(gameObject->inputComponent->facing);
            positions[currentPosition.y * currentRoom.width + currentPosition.x].emplace_back(gameObject);
            nextPositions[nextPosition.y * currentRoom.width + nextPosition.x].emplace_back(gameObject);
        }
    }

    if (positions.count(encodedPlayerPosition) != 0)
    {
        t_currentGameState.get()->currentGameState = GameStateEnum::LOSS;
        return;
    }
}

bool MovementEngine::wouldBeOutOfBounds(Position const& t_position, Direction const t_facing, int const t_maxWidth, int const t_maxHeight)
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
