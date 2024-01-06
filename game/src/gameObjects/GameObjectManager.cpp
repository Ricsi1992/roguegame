#include "gameObjects/GameObjectManager.hpp"
#include "gameObjects/PlayerInputComponent.hpp"
#include "gameObjects/MonsterInputComponent.hpp"

namespace game
{

void GameObjectManager::createPlayer(Position const& t_position)
{
    playerObject = std::make_shared<GameObject>(
        nextIndex++,
        std::make_shared<MovementComponent>(t_position, 1),
        std::make_shared<PlayerInputComponent>(),
        std::make_shared<RenderComponent>('@', ObjectColor::YELLOW)
    );
}

void GameObjectManager::createMonster(Position const& t_position)
{
    gameObjects.emplace_back(std::make_shared<GameObject>(
        nextIndex++,
        std::make_shared<MovementComponent>(t_position, 2),
        std::make_shared<MonsterInputComponent>(),
        std::make_shared<RenderComponent>('Z', ObjectColor::RED)
    ));
}

}