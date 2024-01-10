#pragma once
#include <vector>
#include <memory>
#include <cstdint>
#include "gameObjects/GameObject.hpp"

namespace game
{

class GameObjectManager
{
public:
    void createPlayer(Position const& t_position);
    void createMonster(Position const& t_position);
    void prepareCleanUp();
    void cleanUp();
public:
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    std::shared_ptr<GameObject> playerObject;
    std::uint32_t nextIndex = 0;
    std::vector<int> indicesToDelete;
};

}