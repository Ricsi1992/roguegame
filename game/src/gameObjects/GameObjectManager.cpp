#include "gameObjects/GameObjectManager.hpp"
#include "gameObjects/PlayerInputComponent.hpp"
#include "gameObjects/MonsterInputComponent.hpp"
#include "utils.hpp"

namespace game
{

void GameObjectManager::createPlayer(Position const& t_position)
{
    playerObject = std::make_shared<GameObject>(
        nextIndex++,
        std::make_shared<MovementComponent>(t_position, 1),
        std::make_shared<PlayerInputComponent>(),
        std::make_shared<RenderComponent>('@', ObjectColor::YELLOW),
        std::make_shared<CombatComponent>(100, 0, std::make_shared<MeleeAttack>("Sword", 100, 0.2, 3))
    );
}

void GameObjectManager::createMonster(Position const& t_position)
{
    gameObjects.emplace_back(std::make_shared<GameObject>(
        nextIndex++,
        std::make_shared<MovementComponent>(t_position, 8),
        std::make_shared<MonsterInputComponent>(),
        std::make_shared<RenderComponent>('Z', ObjectColor::RED),
        std::make_shared<CombatComponent>(20, 0)
    ));
}

void GameObjectManager::prepareCleanUp()
{
    indicesToDelete.clear();
    for (size_t i = 0; i < gameObjects.size(); ++i)
    {
        if (gameObjects[i]->markedForDeletion)
        {
            indicesToDelete.push_back(i);
        }
        
    }
    
}

void GameObjectManager::cleanUp()
{
    if (indicesToDelete.size() == 0)
    {
        return;
    }

    utils::remove_index(gameObjects, indicesToDelete);
}

void GameObjectManager::loadRoomObjects(std::vector<int> const& t_room, std::shared_ptr<GameState> t_gameState)
{
    auto&& currentRoom = t_gameState->level.rooms[t_gameState->level.currentRoomIndex];
    if (!playerObject)
    {
        createPlayer(Position{currentRoom.width / 2, currentRoom.height - 1});
    }

    gameObjects.clear();

    for (int y = 0; y < currentRoom.height; ++y)
    {
        for (int x = 0; x < currentRoom.width; ++x)
        {
            auto&& currentCoordinate = t_room[y * currentRoom.width + x];
            switch (currentCoordinate)
            {
            case 1:
                createMonster(Position{x, y});
                break;
            default:
                break;
            }
        }
        
    }
    
}

void GameObjectManager::playerMovesToNextRoom(std::shared_ptr<GameState> t_gameState) 
{
    auto&& curentRoom = t_gameState->level.rooms[t_gameState->level.currentRoomIndex];
    Position playerPos;

    switch (playerObject->inputComponent->facing)
    {
    case Direction::UP:
        playerPos.x = curentRoom.width / 2;
        playerPos.y = curentRoom.height - 1;
        break;
    case Direction::RIGHT:
        playerPos.x = 0;
        playerPos.y = curentRoom.height / 2;
        break;
    case Direction::DOWN:
        playerPos.x = curentRoom.width / 2;
        playerPos.y = 0;
        break;
    case Direction::LEFT:
        playerPos.x = curentRoom.width - 1;
        playerPos.y = curentRoom.height / 2;
        break;
    case Direction::NUMBER_OF_ELEMENTS:
    default:
        break;
    }
    playerObject->movementComponent->position = playerPos;
}

}