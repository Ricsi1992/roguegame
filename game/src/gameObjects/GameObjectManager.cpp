#include "gameObjects/GameObjectManager.hpp"
#include "gameObjects/PlayerInputComponent.hpp"

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

}